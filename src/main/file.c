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

typedef struct struct_gacBuffer_unk_0004 {
    /* 0x00 */ u8 unk_00;
    /* 0x00 */ u8 unk_01;
    /* 0x00 */ u8 unk_02;
    /* 0x00 */ u8 unk_03;
    /* 0x00 */ u8 unk_04;
    /* 0x00 */ u8 unk_05;
    /* 0x00 */ u8 unk_06;
    /* 0x00 */ u8 unk_07;
    /* 0x10 */ char unk_08[0x10];
} struct_gacBuffer_unk_0004; // size = 0x18

typedef struct struct_gacBuffer {
    /* 0x0000 */ s32 unk_0000;
    /* 0x0004 */ u8 unk_0004[0x3800];
} struct_gacBuffer; // size = 0x3808

// extern struct_gacBuffer gacBuffer;
extern u8 gacBuffer[0x3808];
extern s32 giFileBuffer;
extern s32 gnOffsetBuffer;
extern u32 gnFileCount;

#if VERSION_USA
STATIC_INLINE s32 inlinedfunc(void) {
    if (gnFileCount != -1) {
        return (gnFileCount * 0x18) + 4;
    } else {
        return 0x3800;
    }
}

STATIC_INLINE s32 fileBuffer(File *arg0, s32 arg1) {
    s32 __n;

    if (arg0 == (File *)-1) {
        __n = inlinedfunc();

        func_80001CAC_usa(SEGMENT_ROM_START(bin_file), gacBuffer, __n);
        giFileBuffer = -1;
        return __n;
    }

    if (giFileBuffer == arg0->index) {
        if (gnOffsetBuffer <= arg0->unk_0C) {
            __n = MIN(arg0->unk_04, 0x3800);

            if (__n > ((arg0->unk_0C - gnOffsetBuffer) + arg1)) {
                return arg1;
            }
        }
    }

    __n = arg0->unk_04 - (arg0->unk_0C & ~1);
    __n = MIN(__n, 0x3800);
    giFileBuffer = arg0->index;
    gnOffsetBuffer = arg0->unk_0C & ~1;
    func_80001CAC_usa(arg0->unk_08 + gnOffsetBuffer, gacBuffer, (__n + 1) & ~1);

    return ((arg1) < (__n) ? (arg1) : (__n));
}
#endif

#if VERSION_USA
s32 fileFind(File *arg0, char *arg1) {
    char sp10[0x10];
    s32 var_a2;
    s32 a2;
    u32 var_t2;

    for (var_a2 = 0; arg1[var_a2] != 0; var_a2++) {
        if (arg1[var_a2] >= 'a' && arg1[var_a2] <= 'z') {
            sp10[var_a2] = arg1[var_a2] - ('a' - 'A');
        } else {
            sp10[var_a2] = arg1[var_a2];
        }
    }
    a2 = var_a2;
    fileBuffer((void *)-1, 0x3800);
    var_t2 = 0;
    while (var_t2 < gnFileCount) {
        s32 index = 4 + (var_t2 * 0x18);

        for (var_a2 = 0; var_a2 < a2; var_a2++) {
            if (gacBuffer[8 + index + var_a2] != sp10[var_a2]) {
                break;
            }
        }

        if (var_a2 == a2) {
            int new_var1;
            int new_var;

            new_var1 = (gacBuffer[index + 0] << 0x18) | (gacBuffer[index + 1] << 0x10) | (gacBuffer[index + 2] << 8) |
                       gacBuffer[index + 3];
            new_var = (gacBuffer[index + 0 + 4] << 0x18) | (gacBuffer[index + 1 + 4] << 0x10) |
                      (gacBuffer[index + 2 + 4] << 8) | gacBuffer[index + 3 + 4];
            arg0->index = var_t2;
            arg0->unk_04 = new_var1;
            arg0->unk_08 = (u32)(new_var + SEGMENT_ROM_START(bin_file));
            return new_var1;
        }
        var_t2 += 1;
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
    return arg0->index < 0x255;
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

#if VERSION_USA
#ifdef NON_EQUIVALENT
s32 fileGet(File *arg0, void *arg1, s32 arg2) {
    u8 *a1 = arg1;
    u8 *var_v1;
    s32 var_a0;
    s32 var_s1;
    u32 temp_a0_2;

    if (arg0->unk_04 < (arg0->unk_0C + arg2)) {
        arg2 = arg0->unk_04 - arg0->unk_0C;
    }
    if (arg2 <= 0) {
        return 0;
    }

    if (!fileTest(arg0)) {
        return 0;
    }

    for (; arg2 != 0; arg2 -= var_s1, arg0->unk_0C += var_s1) {
        if ((arg2 > 0x1f)) {
            if (!(arg2 & 1)) {
                if (!((u32)a1 & 0xF)) { // change from GC? (GC = 0x7)
                    temp_a0_2 = arg0->unk_08 + arg0->unk_0C;
                    if (!(temp_a0_2 & 1)) {
                        var_s1 = arg2;
                        func_80001CAC_usa((RomOffset)temp_a0_2, (u8 *)a1, var_s1);
                        continue;
                    }
                }
            }
        }

        var_s1 = fileBuffer(arg0, arg2);
        var_v1 = &gacBuffer[arg0->unk_0C - gnOffsetBuffer];

        var_a0 = var_s1;
        if (!(var_s1 & 3)) {
            if (!((u32)a1 & 3)) {
                if (!((s32)var_v1 & 3)) {
                    var_a0 = var_a0 >> 2;

                    while (var_a0 >= 8) {
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);

                        var_a0 -= 8;
                    }

                    while (var_a0 >= 4) {
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        var_a0 -= 4;
                    }

                    var_a0--;
                    while (var_a0 != -1) {
                        *((u32 *)a1) = *((u32 *)var_v1);
                        a1 += sizeof(u32);
                        var_v1 += sizeof(u32);
                        var_a0--;
                    }
                    continue;
                }
            }
        }

        while (var_a0 >= 0x10) {
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;

            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            var_a0 -= 0x10;
        }

        while (var_a0 >= 8) {
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            var_a0 -= 8;
        }

        while (var_a0 >= 4) {
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            *a1++ = *var_v1++;
            var_a0 -= 4;
        }

        var_a0--;
        while (var_a0 != -1) {
            *a1++ = *var_v1++;
            var_a0--;
        }
    }

    return var_s1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/file", fileGet);
#endif
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

    fileBuffer((void *)-1, 0x3800);
    gnFileCount = *(u32 *)gacBuffer;
    if (gnFileCount >= 0x256U) {
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
