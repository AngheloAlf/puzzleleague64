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
#include "image.h"
#include "alignment.h"
#include "peel.h"

extern struct_imageLoad_arg0 *gpImageNo;
extern struct_imageLoad_arg0 *gpImageYes;

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/screen", RO_STR_800C4070_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800222F0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenCenterText);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80022AF4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenUpdateArea);
#endif

#if VERSION_USA
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
s32 screenSet(const char *arg0, s32 arg1) {
    s32 sp10;
    s32 var_a0;
    s32 var_s0;

    if ((arg1 & 0x200) && !(arg1 & 0x100) && (peelActive() != 0)) {
        return B_8018E520_usa;
    }

    if ((arg1 & 0x7F000) == 0x7F000) {
        var_s0 = -1;
    } else if (arg1 & 0x80000) {
        var_s0 = (arg1 & 0x7F000) >> 0xC;
    } else {
        var_s0 = 0;
    }

    if (screenFind(&sp10, arg0) != 0) {
        s32 temp;

        if ((geModeFade == 1) || (geModeFade == 3)) {
            return B_8018E520_usa;
        }

        // ?
        if ((u32)(geModeFade - 2) < 2U) {
            if (sp10 == B_8018E520_usa) {
                if (geModeFade == 2) {
                    geModeFade = 1;
                } else if (geModeFade == 3) {
                    geModeFade = 0;
                }
                B_8018E524_usa = -1;
                return sp10;
            }

            return B_8018E520_usa;
        }

        B_8018E53C_usa = var_s0;
        if (B_8018E53C_usa != -1) {
            geModeFade = 3;
        } else {
            var_a0 = 1;
            if (gnAlphaFade == 0xFF) {
                var_a0 = 2;
            }
            geModeFade = var_a0;
        }

        B_8018E52C_usa = arg1 & 3;
        B_8018E524_usa = sp10;

        temp = B_8018E504_usa - 4;
        B_8018E504_usa = temp - B_801C7060_usa;

        if (arg1 & 0x400) {
            B_8018E530_usa = -1;
        } else {
            B_8018E530_usa = 0;
        }

        return sp10;
    }

    return -1;
}
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
#ifdef NON_MATCHING
s32 screenFind(s32 *arg0, const char *arg1) {
    s32 var_t1;
    s32 var_t2;
    s32 var_v0;
    char *var_a3;
    s32 var_a2;
    s32 var_v1;

    for (var_t2 = 0; var_t2 < gnScreenCount; var_t2++) {
        var_a3 = gaScreen[var_t2].unk_00;

        var_t1 = 0;
        while (var_a3[var_t1] != '\0') {
            var_a2 = var_a3[var_t1];
            if (var_a2 >= 'a' && var_a2 <= 'z') {
                var_a2 -= ('a' - 'A');
            }
            var_v1 = arg1[var_t1];
            if (var_v1 >= 'a' && var_v1 <= 'z') {
                var_v1 -= ('a' - 'A');
            }
            if (var_a2 != var_v1) {
                var_v0 = 0;
                goto label;
            }
            var_t1 += 1;
        }

        if (arg1[var_t1] == '\0') {
            var_v0 = -1;
        } else {
            var_v0 = 0;
        }

    label:
        if (var_v0 != 0) {
            *arg0 = var_t2;
            return -1;
        }
    }

    return 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenFind);
#endif
#endif

#if VERSION_USA
s32 screenLoad(char *arg0, void **arg1) {
    File sp10;
    s32 sp20[6] UNUSED;
    s32 sp38;
    s32 sp3C;
    s32 sp40;
    s32 var_a0;
    s32 var_a2;
    s32 var_fp;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s4;
    s32 var_s7;
    struct_gaScreen_unk_20 *temp_s0;
    struct_gaScreen_unk_24 *temp_s0_2;
    struct_gaScreen_unk_18 *temp_s1;
    struct_gaScreen *temp_s3;
    u32 temp_a1;
    struct_gaScreen_unk_1C *temp_s1_2;

    B_8018E528_usa = 1;
    B_8018E524_usa = -1;
    B_8018E520_usa = -1;
    gnImageCount = 0;
    gnScreenCount = 0;
    var_s7 = 0;
    screenWipeImages();
    B_8018E558_usa = 8;
    geModeFade = 0;
    gnAlphaFade = -(~gnAlphaFade != 0) & 0xFF;

    if (fileOpen(&sp10, arg0) == 0) {
        return 0;
    }

    fileGet(&sp10, &sp38, 4);
    if (sp38 != 'SBF1') {
        return 0;
    }

    fileGet(&sp10, &gnImageCount, 4);
    *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
    gapImage = *arg1;
    *arg1 = (void *)ALIGN((uintptr_t)*arg1 + (gnImageCount * 4), 4);

    gapNameImage = *arg1;
    *arg1 = (void *)((uintptr_t)*arg1 + (gnImageCount * 4));
    var_s1 = 0;

    while (var_s1 < gnImageCount) {
        fileGet(&sp10, *arg1, 0x10);
        sp40 = 0;
        while (*((u8 *)*arg1 + sp40) != 0) {
            sp40 = sp40 + 1;
        }
        gapNameImage[var_s1] = *arg1;
        gapNameImage[var_s1][sp40] = 0;
        *arg1 = (void *)((uintptr_t)*arg1 + ALIGN(sp40 + 1, 4));
        var_s1 += 1;
    }

    fileGet(&sp10, &sp3C, 4);
    *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
    gaScreen = *arg1;
    *arg1 = (void *)((uintptr_t)*arg1 + (sp3C * 0x38));

    for (var_fp = 0; var_fp < sp3C; var_fp++) {
        uintptr_t temp;

        temp_s3 = &gaScreen[var_fp];

        fileGet(&sp10, &temp_s3->unk_04, 4);
        fileGet(&sp10, &sp40, 4);
        *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
        temp_s3->unk_00 = *arg1;

        temp = (u32)*arg1;
        temp += 1 + sp40;
        *arg1 = (void *)temp;

        fileGet(&sp10, temp_s3->unk_00, sp40);
        temp_s3->unk_00[sp40] = 0;

        var_a0 = 1;
        while (var_a0 >= 0) {
            temp_s3->unk_28[var_a0] = -1;
            var_a0 -= 1;
        }

        fileGet(&sp10, &temp_s3->unk_08, 4);
        *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
        temp_s3->unk_18 = (struct_gaScreen_unk_18 *)*arg1;
        *arg1 = (void *)((uintptr_t)*arg1 + (temp_s3->unk_08 * 0x60));

        for (var_s4 = 0; var_s4 < temp_s3->unk_08; var_s4++) {
            temp_s1 = &temp_s3->unk_18[var_s4];
            temp_s1->unk_20 = -1;
            temp_s1->unk_30 = 0;
            temp_s1->unk_34 = 0;
            temp_s1->unk_3C = 0;
            temp_s1->unk_40 = 0;
            temp_s1->unk_0C = 0;
            fileGet(&sp10, &temp_s1->unk_2C, 4);
            fileGet(&sp10, &temp_s1->unk_00, 4);
            fileGet(&sp10, &temp_s1->unk_04, 4);
            fileGet(&sp10, &temp_s1->unk_1C, 4);
            fileGet(&sp10, &temp_s1->unk_24, 4);
            fileGet(&sp10, &temp_s1->unk_28, 4);
            fileGet(&sp10, &temp_s1->unk_14, 4);
            if (temp_s1->unk_14 > 0) {
                *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
                temp_s1->unk_5C = *arg1;
                *arg1 = (void *)((uintptr_t)*arg1 + (temp_s1->unk_14 * 8));
                fileGet(&sp10, temp_s1->unk_5C, temp_s1->unk_14 * 8);
            } else {
                temp_s1->unk_5C = 0;
            }

            if (temp_s1->unk_2C & 0x2000) {
                fileGet(&sp10, &temp_s1->unk_10, 4);
            }

            if (temp_s1->unk_2C & 0x10) {
                fileGet(&sp10, &temp_s1->unk_30, 4);
            } else if (temp_s1->unk_2C & 0x20) {
                temp_s1->unk_30 = 1;
            }

            if (temp_s1->unk_2C & 0x20) {
                fileGet(&sp10, &temp_s1->unk_34, 4);
            } else if (temp_s1->unk_2C & 0x10) {
                temp_s1->unk_34 = 1;
            }

            if (temp_s1->unk_2C & 0x80) {
                fileGet(&sp10, (&temp_s1->unk_08), 4);
            }

            if (temp_s1->unk_2C & 0x40) {
                fileGet(&sp10, &temp_s1->unk_4C, 4);
                fileGet(&sp10, &temp_s1->unk_50, 4);
                fileGet(&sp10, &temp_s1->unk_54, 4);
                fileGet(&sp10, &temp_s1->unk_58, 4);
            }

            if ((temp_s1->unk_2C & 0x1000)) {
                *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
                temp_s1->unk_38 = *arg1;
                *arg1 = (void *)((uintptr_t)*arg1 + (((temp_s1->unk_30 * temp_s1->unk_34) + 7) >> 3));
                var_s0_2 = 0;
                while (var_s0_2 < ((s32)((temp_s1->unk_30 * temp_s1->unk_34) + 7) >> 3)) {
                    temp_s1->unk_38[var_s0_2] = 0xFF;
                    var_s0_2 += 1;
                }
            } else {
                temp_s1->unk_38 = 0;
            }

            screenUpdateArea(temp_s1);
        }

        fileGet(&sp10, &temp_s3->unk_0C, 4);
        *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
        temp_s3->unk_1C = *arg1;
        *arg1 = (void *)((uintptr_t)*arg1 + (temp_s3->unk_0C * 0x6C));

        for (var_s4 = 0; var_s4 < temp_s3->unk_0C; var_s4++) {
            temp_s1_2 = &temp_s3->unk_1C[var_s4];
            temp_s1_2->unk_10 = 0;
            temp_s1_2->unk_0C = 0;
            temp_s1_2->unk_54 = -1;
            temp_s1_2->unk_1C = 0;
            fileGet(&sp10, &temp_s1_2->unk_44, 4);
            fileGet(&sp10, &temp_s1_2->unk_04, 4);
            fileGet(&sp10, &temp_s1_2->unk_08, 4);
            fileGet(&sp10, &temp_s1_2->unk_00, 4);
            fileGet(&sp10, &temp_s1_2->unk_18, 4);

            if (temp_s1_2->unk_44 & 0x40000800) {
                fileGet(&sp10, &temp_s1_2->unk_3C, 4);
                fileGet(&sp10, &temp_s1_2->unk_40, 4);
            } else {
                temp_s1_2->unk_40 = 0;
                temp_s1_2->unk_3C = 0;
            }
            if (temp_s1_2->unk_44 & 0x4000) {
                fileGet(&sp10, &temp_s1_2->unk_5C, 4);
                fileGet(&sp10, &temp_s1_2->unk_60, 4);
            } else {
                temp_s1_2->unk_60 = 0;
                temp_s1_2->unk_5C = 0;
            }

            fileGet(&sp10, &sp40, 4);
            *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
            temp_s1_2->unk_64 = *arg1;
            *arg1 = (void *)((uintptr_t)*arg1 + (sp40 * 4));
            fileGet(&sp10, temp_s1_2->unk_64, sp40 * 4);
            *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
            temp_s1_2->unk_68 = *arg1;
            *arg1 = (void *)((uintptr_t)*arg1 + (sp40 * 4));
            fileGet(&sp10, temp_s1_2->unk_68, sp40 * 4);
            fileGet(&sp10, &temp_s1_2->unk_28, 4);
            fileGet(&sp10, &temp_s1_2->unk_48, 4);
            fileGet(&sp10, &temp_s1_2->unk_24, 4);

            if (temp_s1_2->unk_24 > 0) {
                *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
                temp_s1_2->unk_14 = *arg1;
                *arg1 = (void *)((uintptr_t)*arg1 + (temp_s1_2->unk_24 * 4));
                fileGet(&sp10, temp_s1_2->unk_14, temp_s1_2->unk_24 * 4);
            } else {
                temp_s1_2->unk_14 = 0;
            }

            fileGet(&sp10, &sp40, 4);
            temp_s1_2->unk_20 = sp40;
            *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
            temp_s1_2->unk_50 = *arg1;
            *arg1 = (void *)((uintptr_t)*arg1 + ((sp40 + 1) * 2));
            fileGet(&sp10, temp_s1_2->unk_50, sp40 * 2);
            temp_s1_2->unk_50[sp40] = 0;
            var_s0_2 = 0;
            while (var_s0_2 < temp_s1_2->unk_20) {
                if (temp_s1_2->unk_50[var_s0_2] == 0) {
                    osSyncPrintf("screenLoad: TEXT has internal NULL-character (offset=%d)\n", var_s0_2);
                }
                var_s0_2 += 1;
            }

            if (temp_s1_2->unk_44 & 0x808000) {
                *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
                temp_s1_2->unk_2C = *arg1;
                *arg1 = *arg1 + 0x40;
                B_8018E4F8_usa = *arg1;

                if (screenCenterText(temp_s1_2) == 0) {
                    temp_s1_2->unk_44 &= ~(0x800000 | 0x8000);
                }
                *arg1 = B_8018E4F8_usa;
            }

            for (var_s0_2 = 0; var_s0_2 < sp40; var_s0_2++) {
                var_a2 = 3;
                if (temp_s1_2->unk_44 & 0x20000000) {
                    var_a2 = 5;
                }

                temp_a1 = temp_s1_2->unk_50[var_s0_2] >> 0xA;
                if (temp_a1 == 4) {
                    if ((temp_s1_2->unk_50[var_s0_2] & 0x3FF) == var_a2) {
                        temp_s1_2->unk_54 = var_s0_2;
                        sp40 = 0;
                        while ((temp_s1_2->unk_50[var_s0_2] >> 0xA) == 4) {
                            if ((temp_s1_2->unk_50[var_s0_2] & 0x3FF) != var_a2) {
                                break;
                            }

                            var_s0_2++;
                            sp40 += 1;
                        }
                        temp_s1_2->unk_58 = sp40;
                        break;
                    }
                }
            }
        }

        fileGet(&sp10, &temp_s3->unk_10, 4);
        *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
        temp_s3->unk_20 = *arg1;
        *arg1 = (void *)((uintptr_t)*arg1 + (temp_s3->unk_10 * 0x30));
        var_s1 = 0;
        while (var_s1 < temp_s3->unk_10) {
            temp_s0 = &temp_s3->unk_20[var_s1];
            temp_s0->unk_10 = 1.0f;
            temp_s0->unk_14 = 0;
            fileGet(&sp10, (&temp_s0->unk_24), 4);
            fileGet(&sp10, &temp_s0->unk_00, 4);
            fileGet(&sp10, (&temp_s0->unk_04), 4);
            fileGet(&sp10, (&temp_s0->unk_08), 4);
            fileGet(&sp10, (&temp_s0->unk_1C), 4);
            fileGet(&sp10, (&temp_s0->unk_20), 4);
            fileGet(&sp10, (&temp_s0->unk_0C), 4);

            if (temp_s0->unk_24 & 1) {
                var_s7 |= 0x200;
            }
            if (temp_s0->unk_24 & 0x400) {
                fileGet(&sp10, (&temp_s0->unk_18), 4);
            }
            if (temp_s0->unk_24 & 0x40) {
                fileGet(&sp10, (&temp_s0->unk_28), 4);
                fileGet(&sp10, (&temp_s0->unk_2C), 4);
            }
            var_s1 += 1;
        }

        fileGet(&sp10, &temp_s3->unk_14, 4);
        *arg1 = (void *)ALIGN((uintptr_t)*arg1, 4);
        temp_s3->unk_24 = *arg1;
        *arg1 = (void *)((uintptr_t)*arg1 + (temp_s3->unk_14 * 0x30));
        var_s1 = 0;
        while (var_s1 < temp_s3->unk_14) {
            temp_s0_2 = &temp_s3->unk_24[var_s1];
            temp_s0_2->unk_20 = 0;
            temp_s0_2->unk_14 = 0;
            fileGet(&sp10, (&temp_s0_2->unk_2C), 4);
            fileGet(&sp10, (&temp_s0_2->unk_04), 4);
            fileGet(&sp10, (&temp_s0_2->unk_08), 4);
            fileGet(&sp10, &temp_s0_2->unk_00, 4);
            if (temp_s0_2->unk_2C & 1) {
                fileGet(&sp10, (&temp_s0_2->unk_0C), 4);
            }
            if (temp_s0_2->unk_2C & 0x10) {
                fileGet(&sp10, (&temp_s0_2->unk_1C), 4);
            }
            if (temp_s0_2->unk_2C & 0x20) {
                fileGet(&sp10, (&temp_s0_2->unk_18), 4);
            }
            if (temp_s0_2->unk_2C & 4) {
                fileGet(&sp10, (&temp_s0_2->unk_24), 4);
                fileGet(&sp10, (&temp_s0_2->unk_28), 4);
            }
            fileGet(&sp10, (&temp_s0_2->unk_10), 4);
            if (temp_s0_2->unk_2C & 0x80) {
                var_s7 |= 0x1000;
            }
            var_s1 += 1;
        }
    }

    if (var_s7 & 0x1000) {
        imageLoad(&gpImageNo, "dNo.BIF", arg1);
        imageLoad(&gpImageYes, "dYes.BIF", arg1);
    }

    B_8018E4F8_usa = (void *)ALIGN((uintptr_t)*arg1, 16);
    B_8018E4F4_usa = B_8018E4F8_usa;
    gnScreenCount = sp3C;
    B_8018E504_usa += B_801C7060_usa;
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON);
    screenWipeImages();

    return sp3C;
}
#endif

#if VERSION_USA
void screenSetup(void) {
    B_8018E504_usa = 0;
    gnImageCount = 0;
    gnScreenCount = 0;
    B_8018E540_usa = 0;
    B_8018E530_usa = 0;
    geModeFade = 0;
    gnAlphaFade = -1;
    B_8018E524_usa = -1;
    B_8018E520_usa = -1;
}
#endif

#if VERSION_USA
void func_8002B5C4_usa(void) {
}
#endif
