/**
 * Original name: file.c
 */

#include "file.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "segment_symbols.h"
#include "libc/stddef.h"

// Not actually used, keept as a reference
typedef struct BinfileEntry {
    /* 0x00 */ u32 size;            // size of the file
    /* 0x04 */ u32 offset;          // offset relative to the binfile segment
    /* 0x10 */ char filename[0x10]; // uppercase filename, including nul terminator
} BinfileEntry;                     // size = 0x18

#define FILE_BINFILE_MAX_COUNT (0x255)

#define FILE_BINFILE_ENTRIES_BUFSIZE ((s32)ALIGN16(FILE_BINFILE_MAX_COUNT * sizeof(BinfileEntry)))

typedef union GacBuffer {
    u8 buffer[sizeof(s32) + FILE_BINFILE_ENTRIES_BUFSIZE];
    struct {
        s32 count;
        BinfileEntry entries[FILE_BINFILE_MAX_COUNT];
    } data;
    u64 force_structure_alignment;
} GacBuffer; // size = 0x3808

extern GacBuffer gacBuffer;
extern s32 giFileBuffer;
extern s32 gnOffsetBuffer;
extern u32 gnFileCount;

#if VERSION_USA
STATIC_INLINE s32 inlinedfunc(void) {
    if (gnFileCount != -1) {
        return (gnFileCount * sizeof(BinfileEntry)) + sizeof(s32);
    } else {
        return FILE_BINFILE_ENTRIES_BUFSIZE;
    }
}

STATIC_INLINE s32 fileBuffer(File *arg0, s32 arg1) {
    s32 __n;

    if (arg0 == FILE_NULL) {
        __n = inlinedfunc();

        func_80001CAC_usa(SEGMENT_ROM_START(bin_file), &gacBuffer.buffer, __n);
        giFileBuffer = -1;
        return __n;
    }

    if (giFileBuffer == arg0->index) {
        if (gnOffsetBuffer <= arg0->unk_0C) {
            __n = MIN(arg0->unk_04, FILE_BINFILE_ENTRIES_BUFSIZE);

            if (__n > ((arg0->unk_0C - gnOffsetBuffer) + arg1)) {
                return arg1;
            }
        }
    }

    __n = arg0->unk_04 - (arg0->unk_0C & ~1);
    __n = MIN(__n, FILE_BINFILE_ENTRIES_BUFSIZE);
    giFileBuffer = arg0->index;
    gnOffsetBuffer = arg0->unk_0C & ~1;
    func_80001CAC_usa(arg0->unk_08 + gnOffsetBuffer, &gacBuffer.buffer, ALIGN2(__n));

    return ((__n) > (arg1) ? (arg1) : (__n));
}
#endif

#define READ_WORD_FROM_BYTEBUF(buf, index) \
    (((buf)[(index) + 0] << 0x18) | ((buf)[(index) + 1] << 0x10) | ((buf)[(index) + 2] << 8) | ((buf)[(index) + 3]))

#if VERSION_USA
s32 fileFind(File *file, char *filename) {
    char processedName[0x10];
    s32 j;
    s32 nameLength;
    s32 i;

    for (j = 0; filename[j] != 0; j++) {
        // Copy and capitalize filenames
        if (filename[j] >= 'a' && filename[j] <= 'z') {
            processedName[j] = filename[j] - ('a' - 'A');
        } else {
            processedName[j] = filename[j];
        }
    }

    nameLength = j;
    fileBuffer(FILE_NULL, FILE_BINFILE_ENTRIES_BUFSIZE);

    for (i = 0; i < gnFileCount; i++) {
        s32 index = sizeof(s32) + (i * sizeof(BinfileEntry));

        for (j = 0; j < nameLength; j++) {
            if (gacBuffer.buffer[index + offsetof(BinfileEntry, filename) + j] != processedName[j]) {
                break;
            }
        }

        if (j == nameLength) {
            int size = READ_WORD_FROM_BYTEBUF(gacBuffer.buffer, index + offsetof(BinfileEntry, size));
            int offset = READ_WORD_FROM_BYTEBUF(gacBuffer.buffer, index + offsetof(BinfileEntry, offset));

            file->index = i;
            file->unk_04 = size;
            file->unk_08 = (RomOffset)(offset + SEGMENT_ROM_START(bin_file));

            return size;
        }
    }

    return 0;
}
#endif

#if VERSION_USA
s32 func_8001CA94_usa(char *filename) {
    File sp10;

    if (fileFind(&sp10, filename) != 0) {
        return sp10.unk_04;
    }
    return 0;
}
#endif

#if VERSION_USA
INLINE bool fileTest(File *arg0) {
    return arg0->index < FILE_BINFILE_MAX_COUNT;
}
#endif

#if VERSION_USA
bool fileGetAddress(File *arg0, RomOffset *arg1) {
    File sp10;

    if (fileTest(arg0)) {
        *arg1 = arg0->unk_08 + arg0->unk_0C;
        return true;
    }
    if (fileFind(&sp10, (void *)arg0) != 0) {
        *arg1 = sp10.unk_08;
        return true;
    }
    return false;
}
#endif

#if VERSION_USA
s32 fileOpen(File *arg0, char *arg1) {
    if (fileFind(arg0, arg1) != 0) {
        arg0->unk_0C = 0;

        fileBuffer(arg0, arg0->unk_04);
        return arg0->index + 1;
    }

    arg0->index = -1;
    return 0;
}
#endif

#if VERSION_USA
s32 fileClose(File *arg0 UNUSED) {
    return 0;
}
#endif

#define COPY_TYPE(dst, src, type)        \
    *((type *)(dst)) = *((type *)(src)); \
    (dst) += sizeof(type);               \
    (src) += sizeof(type)

// expects word aligned pointers
#define COPY_WORD(dst, src) COPY_TYPE(dst, src, u32)

// expects pointers
#define COPY_BYTE(dst, src) COPY_TYPE(dst, src, u8)

#if VERSION_USA
s32 fileGet(File *file, void *dst, s32 totalSize) {
    s32 var_s1;

    if (file->unk_04 < (file->unk_0C + totalSize)) {
        totalSize = file->unk_04 - file->unk_0C;
    }
    if (totalSize <= 0) {
        return 0;
    }

    if (!fileTest(file)) {
        return 0;
    }

    for (; totalSize != 0; totalSize -= var_s1, file->unk_0C += var_s1) {
        s32 var_a0;
        void *currentSrc;

        if ((totalSize >= 0x20) && (totalSize % 2 == 0) && (((uintptr_t)dst % 16) == 0)) {
            RomOffset temp_a0_2 = file->unk_08 + file->unk_0C;

            if (temp_a0_2 % 2 == 0) {
                var_s1 = totalSize;
                func_80001CAC_usa(temp_a0_2, dst, var_s1);
                continue;
            }
        }

        var_s1 = fileBuffer(file, totalSize);
        currentSrc = &gacBuffer.buffer[file->unk_0C - gnOffsetBuffer];

        var_a0 = var_s1;
        if ((var_s1 % 4 == 0) && ((uintptr_t)dst % 4 == 0) && ((uintptr_t)currentSrc % 4 == 0)) {
            var_a0 = var_a0 >> 2;

            while (var_a0 >= 8) {
                COPY_WORD(dst, currentSrc);
                COPY_WORD(dst, currentSrc);
                COPY_WORD(dst, currentSrc);
                COPY_WORD(dst, currentSrc);
                COPY_WORD(dst, currentSrc);
                COPY_WORD(dst, currentSrc);
                COPY_WORD(dst, currentSrc);
                COPY_WORD(dst, currentSrc);

                var_a0 -= 8;
            }

            while (var_a0 >= 4) {
                COPY_WORD(dst, currentSrc);
                COPY_WORD(dst, currentSrc);
                COPY_WORD(dst, currentSrc);
                COPY_WORD(dst, currentSrc);
                var_a0 -= 4;
            }

            var_a0--;
            while (var_a0 != -1) {
                COPY_WORD(dst, currentSrc);

                var_a0--;
            }
        } else {
            while (var_a0 >= 0x10) {
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                var_a0 -= 0x10;
            }

            while (var_a0 >= 8) {
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                var_a0 -= 8;
            }

            while (var_a0 >= 4) {
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                COPY_BYTE(dst, currentSrc);
                var_a0 -= 4;
            }

            var_a0--;
            while (var_a0 != -1) {
                COPY_BYTE(dst, currentSrc);
                var_a0--;
            }
        }
    }

    return var_s1;
}
#endif

#if VERSION_USA
s32 fileSeek(File *arg0, s32 mode, s32 offset) {
    char new_var = 1;

    if (!fileTest(arg0)) {
        return 0;
    }

    switch (mode) {
        case 0: // SEEK_SET
            break;

        case 1: // SEEK_CUR
            offset += arg0->unk_0C;
            break;

        case 2: // SEEK_END
            offset = arg0->unk_04 - (offset + new_var);
            break;
    }

    if (offset < 0) {
        arg0->unk_0C = 0;
    } else if (offset >= arg0->unk_04) {
        arg0->unk_0C = arg0->unk_04 - 1;
    } else {
        arg0->unk_0C = offset;
    }

    return arg0->unk_0C;
}
#endif

#if VERSION_USA
/**
 * Original name: fileSetup
 */
s32 fileSetup(void) {
    gnFileCount = -1U;
    giFileBuffer = -1U;
    gnOffsetBuffer = -1U;

    fileBuffer(FILE_NULL, FILE_BINFILE_ENTRIES_BUFSIZE);
    gnFileCount = gacBuffer.data.count;
    if (gnFileCount > FILE_BINFILE_MAX_COUNT) {
        osSyncPrintf("fileSetup: Too many files for existing buffersize!");
    }

    return 0;
}
#endif

// hack to ensure correct alignment of rodata
const f64 sFileBumpRodataAlignment = 0;

#if VERSION_USA
s32 func_8001D304_usa(void) {
    return 0;
}
#endif
