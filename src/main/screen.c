/**
 * Original filename: screen.c
 */

#include "screen.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "file.h"

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/screen", RO_STR_800C4070_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800222F0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80022854_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80022AF4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80023868_usa);
#endif

#if VERSION_USA
#if 1
// regalloc
void screenWipeImages(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 l;

    for (k = 0; k < gnImageCount; k++) {
        gapImage[k] = 0;
    }

    B_8018E550_usa = 0;
    B_8018E564_usa = 0;
    B_8018E568_usa = 0;
    B_8018E56C_usa = 0;

    for (i = 0; i < gnScreenCount; i++) {
        for (j = 0; j < gaScreen[i].unk_08; j++) {
            gaScreen[i].unk_18[j].unk_0C = 0;
        }

        for (k = 0; k < gaScreen[i].unk_10; k++) {
            gaScreen[i].unk_20[k].unk_14 = 0;
        }

        for (l = 0; l < gaScreen[i].unk_14; l++) {
            gaScreen[i].unk_24[l].unk_20 = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenWipeImages);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002400C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80024534_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002496C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80024BF4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80024C14_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80024C2C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80024C54_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002552C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800255D8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80025850_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80025CC4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002629C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800273BC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002758C_usa);
#endif

#if VERSION_USA
void func_8002759C_usa(void) {
}
#endif

#if VERSION_USA
void func_800275A4_usa(void) {
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800275AC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80027618_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800276CC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002776C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80027838_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80027914_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800279D8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80027AB0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80027AD4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80027AF4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80027C04_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80027D0C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80027E80_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002801C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80028034_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800282AC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80028378_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800284E4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002864C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80028718_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002880C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800288D8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800289C0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80028A98_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80028BAC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80028CBC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80028DC0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80028E80_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80028F44_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80029130_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80029244_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002931C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800293FC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800294C8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80029594_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800296B0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800297C8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80029980_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80029A44_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80029B10_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80029C4C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80029D24_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80029EC4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002A074_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002A1F4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002A2E8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002A3B8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002A488_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002A4FC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002A574_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002A638_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002A708_usa);
#endif

#if VERSION_USA
#if 0
//? imageLoad(? *, ? *, s32 *);               /* extern */
//s32 func_80022854_usa(s32 *);                       /* extern */
//? func_80023868_usa(s32 *);                         /* extern */
//? screenWipeImages();                              /* extern */

s32 screenLoad(s8 *arg0, s32 **arg1) {
    File sp10;
    s32 sp38;
    s32 sp3C;
    s32 sp40;
    s32 *temp_s0;
    s32 *temp_s0_2;
    s32 *temp_s1;
    s32 *temp_s1_2;
    s32 *var_s0;
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v0_11;
    s32 temp_v0_12;
    s32 temp_v0_13;
    s32 temp_v0_14;
    s32 temp_v0_16;
    s32 temp_v0_17;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 *temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_fp;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s4;
    s32 var_s4_2;
    s32 var_s4_3;
    s32 var_s4_4;
    s32 var_s5;
    s32 var_s5_2;
    s32 var_s7;
    s32 var_v1;
    u16 temp_v0_15;
    u32 temp_a1;
    void *temp_s3;

    B_8018E528_usa = 1;
    B_8018E524_usa = -1;
    B_8018E520_usa = -1;
    gnImageCount = 0;
    gnScreenCount = 0;
    var_s7 = 0;
    screenWipeImages();
    B_8018E558_usa = 8;
    B_8018E538_usa = 0;
    B_8018E534_usa = -(~B_8018E534_usa != 0) & 0xFF;
    if ((fileOpen(&sp10, arg0) == 0) || (fileGet(&sp10, &sp38, 4), (sp38 != 0x53424631))) {
        return 0;
    }
    fileGet(&sp10, &gnImageCount, 4);
    temp_v0 = ((u32)*arg1 + 3) & ~3;
    *arg1 = temp_v0;
    gapImage = temp_v0;
    temp_v0_2 = ((u32)*arg1 + (gnImageCount * 4) + 3) & ~3;
    *arg1 = temp_v0_2;
    B_8018E510_usa = temp_v0_2;
    *arg1 += gnImageCount * 4;
    var_s1 = 0;
    if (gnImageCount > 0) {
        do {
            fileGet(&sp10, (s32 *) (u32)*arg1, 0x10);
            sp40 = 0;
            if (**arg1 != 0) {
                do {
                    temp_v0_3 = sp40 + 1;
                    sp40 = temp_v0_3;
                } while (*(*arg1 + temp_v0_3) != 0);
            }
            temp_v1 = *arg1;
            *((var_s1 * 4) + B_8018E510_usa) = temp_v1;
            *(temp_v1 + sp40) = 0;
            *arg1 += (sp40 + 4) & ~3;
            var_s1 += 1;
        } while (var_s1 < gnImageCount);
    }
    fileGet(&sp10, &sp3C, 4);
    temp_v0_4 = ((u32)*arg1 + 3) & ~3;
    *arg1 = temp_v0_4;
    gaScreen = temp_v0_4;
    *arg1 += sp3C * 0x38;
    var_fp = 0;
    if (sp3C > 0) {
        do {
            temp_s3 = gaScreen + (var_fp * 0x38);
            var_s0 = temp_s3 + 4;
            fileGet(&sp10, var_s0, 4);
            fileGet(&sp10, &sp40, 4);
            temp_v0_5 = ((u32)*arg1 + 3) & ~3;
            *arg1 = temp_v0_5;
            temp_s3->unk_0 = temp_v0_5;
            *arg1 = *arg1 + 1 + sp40;
            fileGet(&sp10, (s32 *) temp_s3->unk_0, sp40);
            var_a0 = 1;
            *(temp_s3->unk_0 + sp40) = 0;
loop_11:
            var_s0->unk_28 = -1;
            var_a0 -= 1;
            var_s0 -= 4;
            if (var_a0 >= 0) {
                goto loop_11;
            }
            fileGet(&sp10, temp_s3 + 8, 4);
            temp_v0_6 = ((u32)*arg1 + 3) & ~3;
            *arg1 = temp_v0_6;
            temp_s3->unk_18 = temp_v0_6;
            *arg1 += temp_s3->unk_8 * 0x60;
            var_s4 = 0;
            if (temp_s3->unk_8 > 0) {
                var_s5 = 0;
                do {
                    temp_s1 = temp_s3->unk_18 + var_s5;
                    temp_s1->unk_20 = -1;
                    temp_s1->unk_30 = 0;
                    temp_s1->unk_34 = 0;
                    temp_s1->unk_3C = 0;
                    temp_s1->unk_40 = 0;
                    temp_s1->unk_C = 0;
                    fileGet(&sp10, temp_s1 + 0x2C, 4);
                    fileGet(&sp10, temp_s1, 4);
                    fileGet(&sp10, temp_s1 + 4, 4);
                    fileGet(&sp10, temp_s1 + 0x1C, 4);
                    fileGet(&sp10, temp_s1 + 0x24, 4);
                    fileGet(&sp10, temp_s1 + 0x28, 4);
                    fileGet(&sp10, temp_s1 + 0x14, 4);
                    if (temp_s1->unk_14 > 0) {
                        temp_v0_7 = ((u32)*arg1 + 3) & ~3;
                        *arg1 = temp_v0_7;
                        temp_s1->unk_5C = temp_v0_7;
                        *arg1 += temp_s1->unk_14 * 8;
                        fileGet(&sp10, (s32 *) temp_s1->unk_5C, temp_s1->unk_14 * 8);
                    } else {
                        temp_s1->unk_5C = 0;
                    }
                    if (temp_s1->unk_2C & 0x2000) {
                        fileGet(&sp10, temp_s1 + 0x10, 4);
                    }
                    temp_v1_2 = temp_s1->unk_2C;
                    if (temp_v1_2 & 0x10) {
                        fileGet(&sp10, temp_s1 + 0x30, 4);
                        goto block_23;
                    }
                    if (temp_v1_2 & 0x20) {
                        temp_s1->unk_30 = 1;
block_23:
                        if (temp_s1->unk_2C & 0x20) {
                            fileGet(&sp10, temp_s1 + 0x34, 4);
                        } else {
                            goto block_25;
                        }
                    } else {
block_25:
                        if (temp_s1->unk_2C & 0x10) {
                            temp_s1->unk_34 = 1;
                        }
                    }
                    if (temp_s1->unk_2C & 0x80) {
                        fileGet(&sp10, temp_s1 + 8, 4);
                    }
                    if (temp_s1->unk_2C & 0x40) {
                        fileGet(&sp10, temp_s1 + 0x4C, 4);
                        fileGet(&sp10, temp_s1 + 0x50, 4);
                        fileGet(&sp10, temp_s1 + 0x54, 4);
                        fileGet(&sp10, temp_s1 + 0x58, 4);
                    }
                    if (!(temp_s1->unk_2C & 0x1000)) {
                        temp_s1->unk_38 = 0;
                    } else {
                        temp_v1_3 = ((u32)*arg1 + 3) & ~3;
                        *arg1 = temp_v1_3;
                        temp_s1->unk_38 = temp_v1_3;
                        *arg1 += (s32) ((temp_s1->unk_30 * temp_s1->unk_34) + 7) >> 3;
                        var_s0_2 = 0;
                        if (((s32) ((temp_s1->unk_30 * temp_s1->unk_34) + 7) >> 3) > 0) {
                            do {
                                *(temp_s1->unk_38 + var_s0_2) = 0xFF;
                                var_s0_2 += 1;
                            } while (var_s0_2 < ((s32) ((temp_s1->unk_30 * temp_s1->unk_34) + 7) >> 3));
                        }
                    }
                    func_80023868_usa(temp_s1);
                    var_s4 += 1;
                    var_s5 += 0x60;
                } while (var_s4 < temp_s3->unk_8);
            }
            fileGet(&sp10, temp_s3 + 0xC, 4);
            temp_v0_8 = ((u32)*arg1 + 3) & ~3;
            *arg1 = temp_v0_8;
            temp_s3->unk_1C = temp_v0_8;
            *arg1 += temp_s3->unk_C * 0x6C;
            var_s4_2 = 0;
            if (temp_s3->unk_C > 0) {
                var_s5_2 = 0;
                do {
                    temp_s1_2 = temp_s3->unk_1C + var_s5_2;
                    temp_s1_2->unk_10 = 0;
                    temp_s1_2->unk_C = 0;
                    temp_s1_2->unk_54 = -1;
                    temp_s1_2->unk_1C = 0;
                    fileGet(&sp10, temp_s1_2 + 0x44, 4);
                    fileGet(&sp10, temp_s1_2 + 4, 4);
                    fileGet(&sp10, temp_s1_2 + 8, 4);
                    fileGet(&sp10, temp_s1_2, 4);
                    fileGet(&sp10, temp_s1_2 + 0x18, 4);
                    if (temp_s1_2->unk_44 & 0x40000800) {
                        fileGet(&sp10, temp_s1_2 + 0x3C, 4);
                        fileGet(&sp10, temp_s1_2 + 0x40, 4);
                    } else {
                        temp_s1_2->unk_40 = 0;
                        temp_s1_2->unk_3C = 0;
                    }
                    if (temp_s1_2->unk_44 & 0x4000) {
                        fileGet(&sp10, temp_s1_2 + 0x5C, 4);
                        fileGet(&sp10, temp_s1_2 + 0x60, 4);
                    } else {
                        temp_s1_2->unk_60 = 0;
                        temp_s1_2->unk_5C = 0;
                    }
                    fileGet(&sp10, &sp40, 4);
                    temp_v0_9 = ((u32)*arg1 + 3) & ~3;
                    *arg1 = temp_v0_9;
                    temp_s1_2->unk_64 = temp_v0_9;
                    *arg1 += sp40 * 4;
                    fileGet(&sp10, (s32 *) temp_s1_2->unk_64, sp40 * 4);
                    temp_v0_10 = ((u32)*arg1 + 3) & ~3;
                    *arg1 = temp_v0_10;
                    temp_s1_2->unk_68 = temp_v0_10;
                    *arg1 += sp40 * 4;
                    fileGet(&sp10, (s32 *) temp_s1_2->unk_68, sp40 * 4);
                    fileGet(&sp10, temp_s1_2 + 0x28, 4);
                    fileGet(&sp10, temp_s1_2 + 0x48, 4);
                    fileGet(&sp10, temp_s1_2 + 0x24, 4);
                    if (temp_s1_2->unk_24 > 0) {
                        temp_v0_11 = ((u32)*arg1 + 3) & ~3;
                        *arg1 = temp_v0_11;
                        temp_s1_2->unk_14 = temp_v0_11;
                        *arg1 += temp_s1_2->unk_24 * 4;
                        fileGet(&sp10, (s32 *) temp_s1_2->unk_14, temp_s1_2->unk_24 * 4);
                    } else {
                        temp_s1_2->unk_14 = 0;
                    }
                    fileGet(&sp10, &sp40, 4);
                    temp_s1_2->unk_20 = sp40;
                    temp_v0_12 = ((u32)*arg1 + 3) & ~3;
                    *arg1 = temp_v0_12;
                    temp_s1_2->unk_50 = temp_v0_12;
                    *arg1 += (sp40 + 1) * 2;
                    fileGet(&sp10, (s32 *) temp_s1_2->unk_50, sp40 * 2);
                    *((sp40 * 2) + temp_s1_2->unk_50) = 0;
                    var_s0_3 = 0;
                    if (temp_s1_2->unk_20 > 0) {
                        do {
                            if (*((var_s0_3 * 2) + temp_s1_2->unk_50) == 0) {
                                osSyncPrintf("screenLoad: TEXT has internal NULL-character (offset=%d)\n", var_s0_3);
                            }
                            var_s0_3 += 1;
                        } while (var_s0_3 < temp_s1_2->unk_20);
                    }
                    if (temp_s1_2->unk_44 & 0x808000) {
                        temp_v0_13 = ((u32)*arg1 + 3) & ~3;
                        *arg1 = temp_v0_13;
                        temp_s1_2->unk_2C = temp_v0_13;
                        temp_v0_14 = *arg1 + 0x40;
                        *arg1 = temp_v0_14;
                        B_8018E4F8_usa = temp_v0_14;
                        if (func_80022854_usa(temp_s1_2) == 0) {
                            temp_s1_2->unk_44 = (s32) (temp_s1_2->unk_44 & 0xFF7F7FFF);
                        }
                        *arg1 = B_8018E4F8_usa;
                    }
                    var_s0_4 = 0;
                    if (sp40 > 0) {
                        var_v1 = 0;
loop_58:
                        var_a2 = 3;
                        if (temp_s1_2->unk_44 & 0x20000000) {
                            var_a2 = 5;
                        }
                        temp_v0_15 = *(var_v1 + temp_s1_2->unk_50);
                        temp_a1 = temp_v0_15 >> 0xA;
                        if ((temp_a1 == 4) && ((temp_v0_15 & 0x3FF) == var_a2)) {
                            temp_s1_2->unk_54 = var_s0_4;
                            sp40 = 0;
                            if (((u16) *(var_v1 + temp_s1_2->unk_50) >> 0xA) == temp_a1) {
                                var_a1 = var_s0_4 * 2;
loop_64:
                                var_a1 += 2;
                                if ((*(var_a1 + temp_s1_2->unk_50) & 0x3FF) == var_a2) {
                                    sp40 += 1;
                                    if (((u16) *(var_a1 + temp_s1_2->unk_50) >> 0xA) == 4) {
                                        goto loop_64;
                                    }
                                }
                            }
                            temp_s1_2->unk_58 = sp40;
                        } else {
                            var_s0_4 += 1;
                            var_v1 += 2;
                            if (var_s0_4 < sp40) {
                                goto loop_58;
                            }
                        }
                    }
                    var_s4_2 += 1;
                    var_s5_2 += 0x6C;
                } while (var_s4_2 < temp_s3->unk_C);
            }
            fileGet(&sp10, temp_s3 + 0x10, 4);
            temp_v0_16 = ((u32)*arg1 + 3) & ~3;
            *arg1 = temp_v0_16;
            temp_s3->unk_20 = temp_v0_16;
            *arg1 += temp_s3->unk_10 * 0x30;
            var_s1_2 = 0;
            if (temp_s3->unk_10 > 0) {
                var_s4_3 = 0;
                do {
                    temp_s0 = temp_s3->unk_20 + var_s4_3;
                    temp_s0->unk_10 = 1.0f;
                    temp_s0->unk_14 = 0;
                    fileGet(&sp10, temp_s0 + 0x24, 4);
                    fileGet(&sp10, temp_s0, 4);
                    fileGet(&sp10, temp_s0 + 4, 4);
                    fileGet(&sp10, temp_s0 + 8, 4);
                    fileGet(&sp10, temp_s0 + 0x1C, 4);
                    fileGet(&sp10, temp_s0 + 0x20, 4);
                    fileGet(&sp10, temp_s0 + 0xC, 4);
                    temp_v1_4 = temp_s0->unk_24;
                    if (temp_v1_4 & 1) {
                        var_s7 |= 0x200;
                    }
                    if (temp_v1_4 & 0x400) {
                        fileGet(&sp10, temp_s0 + 0x18, 4);
                    }
                    if (temp_s0->unk_24 & 0x40) {
                        fileGet(&sp10, temp_s0 + 0x28, 4);
                        fileGet(&sp10, temp_s0 + 0x2C, 4);
                    }
                    var_s1_2 += 1;
                    var_s4_3 += 0x30;
                } while (var_s1_2 < temp_s3->unk_10);
            }
            fileGet(&sp10, temp_s3 + 0x14, 4);
            temp_v0_17 = ((u32)*arg1 + 3) & ~3;
            *arg1 = temp_v0_17;
            temp_s3->unk_24 = temp_v0_17;
            *arg1 += temp_s3->unk_14 * 0x30;
            var_s1_3 = 0;
            if (temp_s3->unk_14 > 0) {
                var_s4_4 = 0;
                do {
                    temp_s0_2 = temp_s3->unk_24 + var_s4_4;
                    temp_s0_2->unk_20 = 0;
                    temp_s0_2->unk_14 = 0;
                    fileGet(&sp10, temp_s0_2 + 0x2C, 4);
                    fileGet(&sp10, temp_s0_2 + 4, 4);
                    fileGet(&sp10, temp_s0_2 + 8, 4);
                    fileGet(&sp10, temp_s0_2, 4);
                    if (temp_s0_2->unk_2C & 1) {
                        fileGet(&sp10, temp_s0_2 + 0xC, 4);
                    }
                    if (temp_s0_2->unk_2C & 0x10) {
                        fileGet(&sp10, temp_s0_2 + 0x1C, 4);
                    }
                    if (temp_s0_2->unk_2C & 0x20) {
                        fileGet(&sp10, temp_s0_2 + 0x18, 4);
                    }
                    if (temp_s0_2->unk_2C & 4) {
                        fileGet(&sp10, temp_s0_2 + 0x24, 4);
                        fileGet(&sp10, temp_s0_2 + 0x28, 4);
                    }
                    fileGet(&sp10, temp_s0_2 + 0x10, 4);
                    if (temp_s0_2->unk_2C & 0x80) {
                        var_s7 |= 0x1000;
                    }
                    var_s1_3 += 1;
                    var_s4_4 += 0x30;
                } while (var_s1_3 < temp_s3->unk_14);
            }
            var_fp += 1;
        } while (var_fp < sp3C);
    }
    if (var_s7 & 0x1000) {
        imageLoad(&gpImageNo, "dNo.BIF", arg1);
        imageLoad(&gpImageYes, "dYes.BIF", arg1);
    }
    temp_v1_5 = (*arg1 + 0xF) & ~0xF;
    B_8018E4F8_usa = temp_v1_5;
    B_8018E4F4_usa = temp_v1_5;
    gnScreenCount = sp3C;
    B_8018E504_usa += B_801C7060_usa;
    osViSetSpecialFeatures(0x40U);
    screenWipeImages();
    return sp3C;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenLoad);
#endif
#endif

#if VERSION_USA
void screenSetup(void) {
    B_8018E504_usa = 0;
    gnImageCount = 0;
    gnScreenCount = 0;
    B_8018E540_usa = 0;
    B_8018E530_usa = 0;
    B_8018E538_usa = 0;
    B_8018E534_usa = -1;
    B_8018E524_usa = -1;
    B_8018E520_usa = -1;
}
#endif

#if VERSION_USA
void func_8002B5C4_usa(void) {
}
#endif
