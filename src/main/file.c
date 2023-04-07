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
extern u32 D_9BDB40[]; // bin_file

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

        func_80001CAC_usa((RomOffset)D_9BDB40, gacBuffer, __n);
        giFileBuffer = -1;
        return __n;
    }

    if (giFileBuffer == arg0->unk_00) {
        if (gnOffsetBuffer <= arg0->unk_0C) {
            __n = MIN(arg1, 0x3800);

            if (__n > (arg1 + (arg0->unk_0C - gnOffsetBuffer))) {
                return __n;
            }
        }
    }

    __n = arg0->unk_04 - (arg0->unk_0C & ~1);
    __n = MIN(__n, 0x3800);
    giFileBuffer = arg0->unk_00;
    gnOffsetBuffer = arg0->unk_0C & ~1;
    func_80001CAC_usa(arg0->unk_08 + gnOffsetBuffer, gacBuffer, (__n + 1) & ~1);

    return MIN(arg1, __n);
}

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
            arg0->unk_00 = var_t2;
            arg0->unk_04 = new_var1;
            arg0->unk_08 = (u32)(new_var + (u32)D_9BDB40);
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
    return arg0->unk_00 < 0x255;
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
        return arg0->unk_00 + 1;
    }

    arg0->unk_00 = -1;
    return 0;
}
#endif

#if VERSION_USA
s32 fileClose(File *arg0 UNUSED) {
    return 0;
}
#endif

#if VERSION_USA
// fileGet?
#if 0
s32 func_8001CC7C_usa(File *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a2;
    u8 *var_s0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s3;
    s32 *temp_s0;
    s32 *temp_s0_10;
    s32 *temp_s0_2;
    s32 *temp_s0_3;
    s32 *temp_s0_4;
    s32 *temp_s0_5;
    s32 *temp_s0_6;
    s32 *temp_s0_7;
    s32 *temp_s0_8;
    s32 *temp_s0_9;
    s32 *temp_v1_10;
    s32 *temp_v1_3;
    s32 *temp_v1_4;
    s32 *temp_v1_5;
    s32 *temp_v1_6;
    s32 *temp_v1_7;
    s32 *temp_v1_8;
    s32 *temp_v1_9;
    u32 temp_a0_2;
    u8 *temp_s0_11;
    u8 *temp_s0_12;
    u8 *temp_s0_13;
    u8 *temp_s0_14;
    u8 *temp_s0_15;
    u8 *temp_s0_16;
    u8 *temp_s0_17;
    u8 *temp_s0_18;
    u8 *temp_s0_19;
    u8 *temp_s0_20;
    u8 *temp_s0_21;
    u8 *temp_s0_22;
    u8 *temp_s0_23;
    u8 *temp_s0_24;
    u8 *temp_s0_25;
    u8 *temp_s0_26;
    u8 *temp_s0_27;
    u8 *temp_s0_28;
    u8 *temp_s0_29;
    u8 *temp_s0_30;
    u8 *temp_s0_31;
    u8 *temp_s0_32;
    u8 *temp_s0_33;
    u8 *temp_s0_34;
    u8 *temp_s0_35;
    u8 *temp_v1_11;
    u8 *temp_v1_12;
    u8 *temp_v1_13;
    u8 *temp_v1_14;
    u8 *temp_v1_15;
    u8 *temp_v1_16;
    u8 *temp_v1_17;
    u8 *temp_v1_18;
    u8 *temp_v1_19;
    u8 *temp_v1_20;
    u8 *temp_v1_21;
    u8 *temp_v1_22;
    u8 *temp_v1_23;
    u8 *temp_v1_24;
    u8 *temp_v1_25;
    u8 *temp_v1_26;
    u8 *temp_v1_27;
    u8 *temp_v1_28;
    u8 *temp_v1_29;
    u8 *temp_v1_30;
    u8 *temp_v1_31;
    u8 *temp_v1_32;
    u8 *var_v1;

    temp_a0 = arg0->unk_0C;
    temp_v1 = arg0->unk_04;
    var_s3 = arg2;
    var_s0 = arg1;
    if (temp_v1 < (temp_a0 + var_s3)) {
        var_s3 = temp_v1 - temp_a0;
    }
    if (var_s3 <= 0) {
        return 0;
    }
    if (!fileTest(arg0)) {
        return 0;
    }

    for (; var_s3 != 0; var_s3 -= var_s1, arg0->unk_0C += var_s1) {
        if (!(var_s3 < 0x20)) {
            if (!(var_s3 & 1)) {
                if (!((u32)var_s0 & 0xF)) {
                    temp_a0_2 = arg0->unk_08 + arg0->unk_0C;
                    var_s1 = var_s3;
                    if (!(temp_a0_2 & 1)) {
                        func_80001CAC_usa(temp_a0_2, (void *)(u32)var_s0, (u32)var_s1);
                        continue;
                    }
                }
            }
        }

        var_s1 = fileBuffer(arg0, arg0->unk_04);

        var_v1 = &gacBuffer[arg0->unk_0C - gnOffsetBuffer];

        var_a0 = var_s1;
        if (!(var_s1 & 3)) {

            if (!((u32)var_s0 & 3)) {
                if (!((s32)var_v1 & 3)) {
                    var_a0_2 = var_s1 >> 2;

                    while (var_a0_2 >= 8) {
                        ((u32*)var_s0)[0] = ((u32*)var_v1)[0];
                        ((u32*)var_s0)[1] = ((u32*)var_v1)[1];
                        ((u32*)var_s0)[2] = ((u32*)var_v1)[1];
                        ((u32*)var_s0)[3] = ((u32*)var_v1)[3];
                        ((u32*)var_s0)[4] = ((u32*)var_v1)[4];
                        ((u32*)var_s0)[5] = ((u32*)var_v1)[5];
                        ((u32*)var_s0)[6] = ((u32*)var_v1)[6];
                        ((u32*)var_s0)[7] = ((u32*)var_v1)[7];
                        var_v1 = &((u32*)var_v1)[8];
                        var_s0 = &((u32*)var_s0)[8];
                        var_a0_2 -= 8;
                    }

                    while (var_a0_2 >= 4) {
                        ((u32*)var_s0)[0] = ((u32*)var_v1)[0];
                        ((u32*)var_s0)[1] = ((u32*)var_v1)[1];
                        ((u32*)var_s0)[2] = ((u32*)var_v1)[1];
                        ((u32*)var_s0)[3] = ((u32*)var_v1)[3];
                        var_v1 = &((u32*)var_v1)[4];
                        var_s0 = &((u32*)var_s0)[4];
                        var_a0_2 -= 4;
                    }

                    var_a0_3 = var_a0_2 - 1;

                    while (var_a0_3 != -1) {
                        ((u32*)var_s0)[0] = ((u32*)var_v1)[0];
                        var_v1 = &((u32*)var_v1)[1];
                        var_s0 = &((u32*)var_s0)[1];
                        var_a0_3 -= 1;
                    }
                    continue;
                }
            }
        }

        while (var_a0 >= 0x10) {
            *var_s0 = (u8)*var_v1;
            temp_s0_11 = var_s0 + 1;
            temp_v1_11 = &var_v1[1 + 1];
            *temp_s0_11 = var_v1[1];
            temp_s0_12 = temp_s0_11 + 1;
            temp_v1_12 = temp_v1_11 + 1;
            *temp_s0_12 = *temp_v1_11;
            temp_s0_13 = temp_s0_12 + 1;
            temp_v1_13 = temp_v1_12 + 1;
            *temp_s0_13 = *temp_v1_12;
            temp_s0_14 = temp_s0_13 + 1;
            temp_v1_14 = temp_v1_13 + 1;
            *temp_s0_14 = *temp_v1_13;
            temp_s0_15 = temp_s0_14 + 1;
            temp_v1_15 = temp_v1_14 + 1;
            *temp_s0_15 = *temp_v1_14;
            temp_s0_16 = temp_s0_15 + 1;
            temp_v1_16 = temp_v1_15 + 1;
            *temp_s0_16 = *temp_v1_15;
            temp_s0_17 = temp_s0_16 + 1;
            temp_v1_17 = temp_v1_16 + 1;
            *temp_s0_17 = *temp_v1_16;
            temp_s0_18 = temp_s0_17 + 1;
            temp_v1_18 = temp_v1_17 + 1;
            *temp_s0_18 = *temp_v1_17;
            temp_s0_19 = temp_s0_18 + 1;
            temp_v1_19 = temp_v1_18 + 1;
            *temp_s0_19 = *temp_v1_18;
            temp_s0_20 = temp_s0_19 + 1;
            temp_v1_20 = temp_v1_19 + 1;
            *temp_s0_20 = *temp_v1_19;
            temp_s0_21 = temp_s0_20 + 1;
            temp_v1_21 = temp_v1_20 + 1;
            *temp_s0_21 = *temp_v1_20;
            temp_s0_22 = temp_s0_21 + 1;
            temp_v1_22 = temp_v1_21 + 1;
            *temp_s0_22 = *temp_v1_21;
            temp_s0_23 = temp_s0_22 + 1;
            temp_v1_23 = temp_v1_22 + 1;
            *temp_s0_23 = *temp_v1_22;
            temp_s0_24 = temp_s0_23 + 1;
            temp_v1_24 = temp_v1_23 + 1;
            *temp_s0_24 = *temp_v1_23;
            temp_s0_25 = temp_s0_24 + 1;
            var_v1 = temp_v1_24 + 1;
            *temp_s0_25 = *temp_v1_24;
            var_s0 = (s32)(temp_s0_25 + 1);
            var_a0 -= 0x10;
        }

        while (var_a0 >= 8) {
            var_a0 -= 8;
            *var_s0 = (u8)*var_v1;
            temp_s0_26 = var_s0 + 1;
            temp_v1_25 = &var_v1[1 + 1];
            *temp_s0_26 = var_v1[1];
            temp_s0_27 = temp_s0_26 + 1;
            temp_v1_26 = temp_v1_25 + 1;
            *temp_s0_27 = *temp_v1_25;
            temp_s0_28 = temp_s0_27 + 1;
            temp_v1_27 = temp_v1_26 + 1;
            *temp_s0_28 = *temp_v1_26;
            temp_s0_29 = temp_s0_28 + 1;
            temp_v1_28 = temp_v1_27 + 1;
            *temp_s0_29 = *temp_v1_27;
            temp_s0_30 = temp_s0_29 + 1;
            temp_v1_29 = temp_v1_28 + 1;
            *temp_s0_30 = *temp_v1_28;
            temp_s0_31 = temp_s0_30 + 1;
            temp_v1_30 = temp_v1_29 + 1;
            *temp_s0_31 = *temp_v1_29;
            temp_s0_32 = temp_s0_31 + 1;
            var_v1 = temp_v1_30 + 1;
            *temp_s0_32 = *temp_v1_30;
            var_s0 = (s32)(temp_s0_32 + 1);
        }

        while (var_a0 >= 4) {
            var_s0[0] = var_v1[0];
            var_s0[1] = var_v1[1];
            var_s0[2] = var_v1[2];
            var_s0[3] = var_v1[3];
            var_v1 = &var_v1[4];
            var_s0 = (s32)(var_s0 + 4);
            var_a0 -= 4;
        }

        var_a0_4 = var_a0 - 1;
        while (var_a0_4 != -1) {
            *var_s0++ = *var_v1++;
            var_a0_4 -= 1;
        }
    }

    return var_s1;
}

#else
INCLUDE_ASM("asm/usa/nonmatchings/main/file", func_8001CC7C_usa);
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
