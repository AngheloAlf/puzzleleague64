/**
 * Original name: file.c
 */

#include "file.h"

#include "libc/stddef.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"
#include "segment_symbols.h"
#include "sound.h"

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

static GacBuffer gacBuffer;
static s32 giFileBuffer;
static s32 gnOffsetBuffer;
static u32 gnFileCount;

STATIC_INLINE s32 inlinedfunc(void) {
    if (gnFileCount != -1) {
        return (gnFileCount * sizeof(BinfileEntry)) + sizeof(s32);
    } else {
        return FILE_BINFILE_ENTRIES_BUFSIZE;
    }
}

/**
 * Original name: fileBuffer
 */
STATIC_INLINE s32 fileBuffer(File *file, s32 size) {
    s32 __n;

    if (file == FILE_NULL) {
        __n = inlinedfunc();

        DmaRomToRam(SEGMENT_ROM_START(bin_file), &gacBuffer.buffer, __n);
        giFileBuffer = -1;
        return __n;
    }

    if (giFileBuffer == file->index) {
        if (gnOffsetBuffer <= file->inFileOffset) {
            __n = MIN(file->fileSize, FILE_BINFILE_ENTRIES_BUFSIZE);

            if (__n > ((file->inFileOffset - gnOffsetBuffer) + size)) {
                return size;
            }
        }
    }

    __n = file->fileSize - (file->inFileOffset & ~1);
    __n = MIN(__n, FILE_BINFILE_ENTRIES_BUFSIZE);
    giFileBuffer = file->index;
    gnOffsetBuffer = file->inFileOffset & ~1;
    DmaRomToRam(file->romAddress + gnOffsetBuffer, &gacBuffer.buffer, ALIGN2(__n));

    return ((__n) > (size) ? (size) : (__n));
}

#define READ_WORD_FROM_BYTEBUF(buf, index) \
    (((buf)[(index) + 0] << 0x18) | ((buf)[(index) + 1] << 0x10) | ((buf)[(index) + 2] << 8) | ((buf)[(index) + 3]))

/**
 * Original name: fileFind
 */
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
            file->fileSize = size;
            file->romAddress = (RomOffset)(offset + SEGMENT_ROM_START(bin_file));

            return size;
        }
    }
    return 0;
}

s32 func_8001CA94_usa(char *filename) {
    File sp10;

    if (fileFind(&sp10, filename) != 0) {
        return sp10.fileSize;
    }
    return 0;
}

/**
 * Original name: fileTest
 */
INLINE bool fileTest(File *file) {
    return file->index < FILE_BINFILE_MAX_COUNT;
}

/**
 * Original name: fileGetAddress
 */
bool fileGetAddress(File *file, RomOffset *dst) {
    File sp10;

    if (fileTest(file)) {
        *dst = file->romAddress + file->inFileOffset;
        return true;
    }

    // idk why this is passing file as second arg, @bug?
    if (fileFind(&sp10, (void *)file) != 0) {
        *dst = sp10.romAddress;
        return true;
    }

    return false;
}

/**
 * Original name: fileOpen
 */
s32 fileOpen(File *file, const char *filename) {
    if (fileFind(file, (void *)filename) != 0) {
        file->inFileOffset = 0;

        fileBuffer(file, file->fileSize);
        return file->index + 1;
    }

    file->index = -1;
    return 0;
}

/**
 * Original name: fileClose
 */
s32 fileClose(File *file UNUSED) {
    return 0;
}

#define COPY_TYPE(dst, src, type)        \
    *((type *)(dst)) = *((type *)(src)); \
    (dst) += sizeof(type);               \
    (src) += sizeof(type)

// expects word aligned pointers
#define COPY_WORD(dst, src) COPY_TYPE(dst, src, u32)

// expects pointers
#define COPY_BYTE(dst, src) COPY_TYPE(dst, src, u8)

/**
 * Original name: fileGet
 */
s32 fileGet(File *file, void *dst, s32 totalSize) {
    s32 var_s1;

    if (file->fileSize < (file->inFileOffset + totalSize)) {
        totalSize = file->fileSize - file->inFileOffset;
    }
    if (totalSize <= 0) {
        return 0;
    }

    if (!fileTest(file)) {
        return 0;
    }

    for (; totalSize != 0; totalSize -= var_s1, file->inFileOffset += var_s1) {
        s32 var_a0;
        void *currentSrc;

        if ((totalSize >= 0x20) && (totalSize % 2 == 0) && (((uintptr_t)dst % 16) == 0)) {
            RomOffset temp_a0_2 = file->romAddress + file->inFileOffset;

            if (temp_a0_2 % 2 == 0) {
                var_s1 = totalSize;
                DmaRomToRam(temp_a0_2, dst, var_s1);
                continue;
            }
        }

        var_s1 = fileBuffer(file, totalSize);
        currentSrc = &gacBuffer.buffer[file->inFileOffset - gnOffsetBuffer];

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

/**
 * Original name: fileSeek
 */
s32 fileSeek(File *file, s32 mode, s32 offset) {
    char new_var = 1;

    if (!fileTest(file)) {
        return 0;
    }

    switch (mode) {
        case FILE_SEEK_SET:
            break;

        case FILE_SEEK_CUR:
            offset += file->inFileOffset;
            break;

        case FILE_SEEK_END:
            offset = file->fileSize - (offset + new_var);
            break;
    }

    if (offset < 0) {
        file->inFileOffset = 0;
    } else if (offset >= file->fileSize) {
        file->inFileOffset = file->fileSize - 1;
    } else {
        file->inFileOffset = offset;
    }

    return file->inFileOffset;
}

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

// hack to ensure correct alignment of rodata
static const f64 sFileBumpRodataAlignment UNUSED = 0;

s32 func_8001D304_usa(void) {
    return 0;
}
