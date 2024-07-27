/**
 * Original filename: screen.c
 */

#include "screen.h"
#include "ultra64.h"
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

extern struct_imageLoad_arg0 *B_8018E564_usa;
extern struct_imageLoad_arg0 *B_8018E568_usa;
extern struct_imageLoad_arg0 *B_8018E56C_usa;

#if VERSION_USA
#ifdef NON_MATCHING
extern char RO_STR_800C4050_usa[];
extern char RO_STR_800C4060_usa[];
extern char RO_STR_800C4070_usa[];

// regalloc
s32 screenGetTextData(struct_gaScreen_unk_1C *arg0, s32 arg1, struct_800222F0_usa_arg2 *arg2,
                      struct_imageLoad_arg0 **arg3, s32 *arg4, s32 arg5 UNUSED) {
    s32 sp10;
    s32 sp14;
    s32 temp_s2;
    s32 var_s0;
    s32 var_s4;
    struct_imageLoad_arg0 *var_s1;
    u32 temp_v0;
    s32 s7;
    s32 s6;

    *arg4 = 0;
    *arg3 = NULL;
    arg2->unk_04 = 0;
    arg2->unk_08 = 0;
    arg2->unk_0C = 0;
    arg2->unk_10 = 0;
    temp_v0 = arg0->unk_50[arg1];
    var_s4 = 0;
    if (temp_v0 == 0) {
        return 0;
    }
    var_s1 = NULL;
    var_s0 = -1;
    s6 = -1;
    s7 = -1;

    temp_s2 = temp_v0 & 0x3FF;
    sp14 = 0;
    sp10 = 0;
    switch (temp_v0 >> 0xA) {

        case 0x0:
            if (temp_s2 == 1) {
                if (!(arg0->unk_44 & 0x800)) {
                    if ((arg0->unk_44 & 0x02000000)) {
                        var_s4 = 6;
                    } else if (arg0->unk_44 & 0x80000) {
                        var_s4 = 8;
                    } else {
                        var_s4 = 0xA;
                    }
                }
            }
            break;

        case 0x1:
        case 0x2:
        case 0x3:
        case 0x8:
        case 0x9:
        case 0xA:
        case 0xB:
        case 0xC:
        case 0xD:
        case 0xE:
        case 0xF:
        case 0x10:
        case 0x11:
            break;

        case 0x4:
            if (arg0->unk_44 & 0x02000000) {
                if (B_8018E564_usa == NULL) {
                    imageLoad(&B_8018E564_usa, RO_STR_800C4050_usa, &B_8018E4F8_usa);
                }
                var_s1 = B_8018E564_usa;
                var_s0 = temp_s2 + 0x23;
                func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
            } else if (arg0->unk_44 & 0x80000) {
                if (B_8018E568_usa == NULL) {
                    imageLoad(&B_8018E568_usa, RO_STR_800C4060_usa, &B_8018E4F8_usa);
                }
                var_s1 = B_8018E568_usa;
                var_s0 = temp_s2 + 0x23;
                func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
            } else {
                if (B_8018E56C_usa == NULL) {
                    imageLoad(&B_8018E56C_usa, RO_STR_800C4070_usa, &B_8018E4F8_usa);
                }
                var_s1 = B_8018E56C_usa;
                var_s0 = temp_s2 + 0x23;
                func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
            }

            break;

        case 0x5:
            if (temp_s2 > 0) {
                if (arg0->unk_44 & 0x02000000) {
                    if (B_8018E564_usa == NULL) {
                        imageLoad(&B_8018E564_usa, RO_STR_800C4050_usa, &B_8018E4F8_usa);
                    }
                    var_s1 = B_8018E564_usa;
                    var_s0 = 0x1A;
                    if (temp_s2 != 0xA) {
                        var_s0 = temp_s2 + 0x1A;
                    }
                    func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
                } else if (arg0->unk_44 & 0x80000) {
                    if (B_8018E568_usa == NULL) {
                        imageLoad(&B_8018E568_usa, RO_STR_800C4060_usa, &B_8018E4F8_usa);
                    }
                    var_s1 = B_8018E568_usa;
                    var_s0 = 0x1A;
                    if (temp_s2 != 0xA) {
                        var_s0 = temp_s2 + 0x1A;
                    }
                    func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
                } else {
                    if (B_8018E56C_usa == NULL) {
                        imageLoad(&B_8018E56C_usa, RO_STR_800C4070_usa, &B_8018E4F8_usa);
                    }
                    var_s1 = B_8018E56C_usa;
                    var_s0 = 0x1A;
                    if (temp_s2 != 0xA) {
                        var_s0 = temp_s2 + 0x1A;
                    }
                    func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
                }
            } else {
                var_s4 = 0xA;
                if (arg0->unk_44 & 0x800) {
                    var_s4 = arg0->unk_3C;
                } else {
                }
            }
            break;

        case 0x6:
            if (arg0->unk_44 & 0x02000000) {
                if (B_8018E564_usa == NULL) {
                    imageLoad(&B_8018E564_usa, RO_STR_800C4050_usa, &B_8018E4F8_usa);
                }
                var_s1 = B_8018E564_usa;
                var_s0 = temp_s2 - 1;
                func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
            } else if (arg0->unk_44 & 0x80000) {
                if (B_8018E568_usa == NULL) {
                    imageLoad(&B_8018E568_usa, RO_STR_800C4060_usa, &B_8018E4F8_usa);
                }
                var_s1 = B_8018E568_usa;
                var_s0 = temp_s2 - 1;
                func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
            } else {
                if (B_8018E56C_usa == NULL) {
                    imageLoad(&B_8018E56C_usa, RO_STR_800C4070_usa, &B_8018E4F8_usa);
                }
                var_s1 = B_8018E56C_usa;
                var_s0 = temp_s2 - 1;
                func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
            }
            break;

        case 0x7:
            if (arg0->unk_44 & 0x02000000) {
                if (B_8018E564_usa == NULL) {
                    imageLoad(&B_8018E564_usa, RO_STR_800C4050_usa, &B_8018E4F8_usa);
                }
                var_s1 = B_8018E564_usa;
                var_s0 = temp_s2 - 1;
                func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
            } else if (arg0->unk_44 & 0x80000) {
                if (B_8018E568_usa == NULL) {
                    imageLoad(&B_8018E568_usa, RO_STR_800C4060_usa, &B_8018E4F8_usa);
                }
                var_s1 = B_8018E568_usa;
                var_s0 = temp_s2 - 1;
                func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
            } else {
                if (B_8018E56C_usa == NULL) {
                    imageLoad(&B_8018E56C_usa, RO_STR_800C4070_usa, &B_8018E4F8_usa);
                }
                var_s1 = B_8018E56C_usa;
                var_s0 = temp_s2 - 1;
                func_8001E110_usa(*var_s1->unk_2C, var_s0, &sp10, &sp14);
            }
            break;

        default:
        case 0x12:
        case 0x13:
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
        case 0x18:
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
        case 0x1F:
        case 0x20:
        case 0x21:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x25:
        case 0x26:
        case 0x27:
        case 0x28:
            return 0;
    }

    *arg4 = var_s4;
    *arg3 = var_s1;
    arg2->unk_0C = sp10;
    arg2->unk_10 = sp14;
    if (var_s0 != -1) {
        arg2->unk_00 = var_s0;
        arg2->unk_08 = 0;
        arg2->unk_04 = 0;
    } else if (s7 != -1 && s6 != -1) {
        arg2->unk_00 = var_s0;
        arg2->unk_04 = s7 * sp10;
        arg2->unk_08 = s6 * sp14;
    }

    return 1;
}
#else
const char RO_STR_800C4050_usa[] = "fPPLTINY.BIF";
const char RO_STR_800C4060_usa[] = "fPPLNORM.BIF";
const char RO_STR_800C4070_usa[] = "fPPLHUGE.BIF";

s32 screenGetTextData(struct_gaScreen_unk_1C *arg0, s32 arg1, struct_800222F0_usa_arg2 *arg2,
                      struct_imageLoad_arg0 **arg3, s32 *arg4, s32 arg5);
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenGetTextData);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80022400_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80022410_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80022480_ger);
#endif

#if VERSION_USA
#if 0

#define M2C_ERROR(x) 0

s32 screenCenterText(struct_gaScreen_unk_1C *arg0) {
    ? sp18;
    ? sp30;
    s32 sp34;
    s32 sp38;
    s32 *var_a0_3;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a1;
    s32 var_a0_2;
    s32 var_fp;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 var_s7;
    s32 var_v0;
    s32 var_v1;
    u16 var_s0;
    u32 temp_v1;
    u32 var_a0;

    var_fp = saved_reg_fp;
    var_s4 = 0;
    var_s2 = 0;
    var_s3 = 0;
    var_s7 = -1;
    var_s0 = *arg0->unk_50;
    var_s5 = -1;
    var_s6 = 0;
    if (var_s0 != 0) {
        var_a0 = var_s0 >> 0xA;
loop_2:
        if ((var_a0 != 0) || ((var_s0 & 0x3FF) == 3)) {
            if (var_a0 < 0x20U) {
                var_s6 = 0;
            } else {
                goto block_7;
            }
        } else {
block_7:
            if (var_s6 == 0) {
                var_s6 = -1;
                var_s5 = var_s3;
                var_s7 = var_s4;
            }
        }
        sp38 = -1;
        screenGetTextData(arg0, var_s3, &sp18, &sp30, &sp34, 0);
        temp_v1 = var_s0 >> 0xA;
        var_a0_2 = 0;
        if (temp_v1 == 0) {
            var_a0_2 = -((var_s0 & 0x3FF) == 2);
        }
        if ((temp_v1 != 0) & (temp_v1 < 0x20U)) {
            var_fp = sp28;
            if (arg0->unk_44 & 0x40000000) {
                var_fp += arg0->unk_40;
            }
        }
        temp_a1 = arg0->unk_5C;
        var_s4 += sp24 + sp34;
        if ((var_s4 >= temp_a1) || (var_a0_2 != 0)) {
            if (var_s5 == -1) {
                temp_a0 = var_s2 * 4;
                var_s2 += 1;
                *(temp_a0 + arg0->unk_2C) = (temp_a1 >> 1) - (var_s4 >> 1);
            } else {
                temp_a0_2 = var_s2 * 4;
                var_s2 += 1;
                var_s3 = var_s5;
                arg0->unk_50[var_s3] = 2;
                var_s5 = -1;
                *(temp_a0_2 + arg0->unk_2C) = ((s32) arg0->unk_5C >> 1) - (var_s7 >> 1);
            }
            var_s4 = 0;
            if (var_s2 != 0x10) {
                goto block_21;
            }
            return 0;
        }
block_21:
        var_s3 += 1;
        var_s0 = arg0->unk_50[var_s3];
        var_a0 = var_s0 >> 0xA;
        if (var_s0 == 0) {
            goto block_22;
        }
        goto loop_2;
    }
block_22:
    if (var_s6 == 0) {
        var_s5 = var_s3;
        var_s7 = var_s4;
    }
    if (M2C_ERROR(Read from unset register $t0) != 0) {
        temp_a0_3 = var_s2 * 4;
        if (var_s5 == -1) {
            var_s2 += 1;
            var_a0_3 = temp_a0_3 + arg0->unk_2C;
            var_v0 = (s32) arg0->unk_5C >> 1;
            var_v1 = var_s4 >> 1;
        } else {
            var_s2 += 1;
            var_a0_3 = temp_a0_3 + arg0->unk_2C;
            var_v0 = (s32) arg0->unk_5C >> 1;
            var_v1 = var_s7 >> 1;
        }
        *var_a0_3 = var_v0 - var_v1;
    }
    if (!(arg0->unk_44 & 0x8000)) {
        arg0->unk_1C = 0;
    } else {
        arg0->unk_1C = ((s32) arg0->unk_60 >> 1) - ((s32) (var_s2 * var_fp) >> 1);
    }
    return -1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenCenterText);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenCenterText);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", screenCenterText);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", screenCenterText);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80022AF4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80022C04_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80022B74_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80022BFC_ger);
#endif

#if VERSION_USA
#if 0
void screenUpdateArea(struct_gaScreen_unk_18 *arg0) {
    struct_800222F0_usa_arg2 sp18;
    struct_imageLoad_arg0 *sp30;
    s32 sp34;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv1;
    f32 var_fv1_2;
    f32 var_fv1_3;
    f32 var_fv1_4;
    f32 var_fv1_5;
    f32 var_fv1_6;
    f32 var_fv1_7;
    f32 var_fv1_8;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_s1;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_s5_2;
    s32 var_s7;
    s32 var_t0;
    s8 *temp_s6;
    struct_gaScreen_unk_18_unk_5C *var_a0;
    struct_gaScreen_unk_1C *temp_s2;
    u16 var_v0_3;
    u32 temp_a0_6;
    u32 temp_a0_7;
    u32 temp_v1_6;

    temp_a0 = arg0->unk_2C;
    temp_v1 = temp_a0 & 0x30;
    if (temp_a0 & 0x80080) {
        if (temp_v1 == 0x10) {
            if (temp_a0 & 0x40) {
                if (arg0->unk_30 >= 2) {
                    var_fv1 = (f32)((arg0->unk_58 - arg0->unk_50) + 1) / (f32)(arg0->unk_30 - 1);
                } else {
                    var_fv1 = 0.0f;
                }
                var_fv0 = var_fv1 * (f32)arg0->unk_40;
                arg0->unk_44 = arg0->unk_4C;
                arg0->unk_48 = (s32)(arg0->unk_50 + (s32)var_fv0);
            } else {
                temp_v1_2 = arg0->unk_30;
                if (temp_v1_2 >= 2) {
                    var_fv1_2 = (f32)arg0->unk_28 / (f32)(temp_v1_2 - 1);
                } else {
                    var_fv1_2 = 0.0f;
                }
                var_fv0 = var_fv1_2 * (f32)arg0->unk_40;
                arg0->unk_44 = arg0->unk_00;
                arg0->unk_48 = (s32)(arg0->unk_04 + (s32)var_fv0);
            }
        } else if (temp_v1 == 0x20) {
            if (temp_a0 & 0x40) {
                temp_a0_3 = arg0->unk_34;
                if (temp_a0_3 >= 2) {
                    var_fv1_3 = (f32)((arg0->unk_54 - arg0->unk_4C) + 1) / (f32)(temp_a0_3 - 1);
                } else {
                    var_fv1_3 = 0.0f;
                }
                var_fv0_2 = var_fv1_3 * (f32)arg0->unk_3C;
                arg0->unk_48 = (s32)arg0->unk_50;
                arg0->unk_44 = (s32)(arg0->unk_4C + (s32)var_fv0_2);
            } else {
                temp_v1_3 = arg0->unk_34;
                if (temp_v1_3 >= 2) {
                    var_fv1_4 = (f32)arg0->unk_24 / (f32)(temp_v1_3 - 1);
                } else {
                    var_fv1_4 = 0.0f;
                }
                var_fv0_2 = var_fv1_4 * (f32)arg0->unk_3C;
                arg0->unk_48 = (s32)arg0->unk_04;
                arg0->unk_44 = (s32)(arg0->unk_00 + (s32)var_fv0_2);
            }
        } else if (temp_v1 == 0x30) {

            if (temp_a0 & 0x40) {
                temp_a0_4 = arg0->unk_30;
                if (temp_a0_4 >= 2) {
                    var_fv1_5 = (f32)((arg0->unk_58 - arg0->unk_50) + 1) / (f32)(temp_a0_4 - 1);
                } else {
                    var_fv1_5 = 0.0f;
                }

                arg0->unk_48 = (s32)(arg0->unk_50 + (s32)(var_fv1_5 * (f32)arg0->unk_40));
                if (arg0->unk_34 >= 2) {
                    var_fv1_6 = (f32)((arg0->unk_54 - arg0->unk_4C) + 1) / (f32)(arg0->unk_34 - 1);
                } else {
                    var_fv1_6 = 0.0f;
                }
                var_fv0_2 = var_fv1_6 * (f32)arg0->unk_3C;
                arg0->unk_44 = (s32)(arg0->unk_4C + (s32)var_fv0_2);
            } else {
                temp_v1_4 = arg0->unk_30;
                if (temp_v1_4 >= 2) {
                    var_fv1_7 = (f32)arg0->unk_28 / (f32)(temp_v1_4 - 1);
                } else {
                    var_fv1_7 = 0.0f;
                }

                arg0->unk_48 = (s32)(arg0->unk_04 + (s32)(var_fv1_7 * (f32)arg0->unk_40));
                if (arg0->unk_34 >= 2) {
                    var_fv1_8 = (f32)arg0->unk_24 / (f32)(arg0->unk_34 - 1);
                } else {
                    var_fv1_8 = 0.0f;
                }
                var_fv0_2 = var_fv1_8 * (f32)arg0->unk_3C;
                arg0->unk_44 = (s32)(arg0->unk_00 + (s32)var_fv0_2);
            }
        }
    }

    if (arg0->unk_2C & 0x4000) {
        temp_v1_5 = giScreen;
        if ((temp_v1_5 >= 0) && (temp_v1_5 < gnScreenCount)) {
            var_t0 = 0;
            var_s5 = 0;
            while (var_t0 < gaScreen[giScreen].unk_0C) {
                temp_s2 = &gaScreen[temp_v1_5].unk_1C[var_t0];
                if ((temp_s2->unk_44 & 0x01000400) == 0x01000000) {
                    temp_a0_7 = temp_s2->unk_44 & 0xFFFEFFEF;
                    temp_s2->unk_44 = temp_a0_7;
                    if ((var_s5 % (s32)arg0->unk_30) == arg0->unk_40) {
                        if ((temp_s2->unk_04 + (temp_a0_7 & 0x800000)) != 0) {
                            arg0->unk_44 = (s32)*temp_s2->unk_2C;
                        } else {
                            arg0->unk_44 = 0;
                        }
                        var_s7 = 0;
                        arg0->unk_48 = (s32)(temp_s2->unk_08 + temp_s2->unk_1C + (-((temp_a0_7 >> 0x19) & 1) & ~1));
                        var_s4 = 0;
                        var_s1 = 0;
                        var_v0_3 = *temp_s2->unk_50;
                        var_s3 = 0;
                        temp_s6 = arg0->unk_18;
                        while (var_v0_3 != 0) {
                            temp_v1_6 = var_v0_3 >> 0xA;
                            if ((temp_v1_6 != 0) || ((var_v0_3 & 0x3FF) == 3)) {
                                if (temp_v1_6 < 0x20U) {
                                    var_s3 = 0;
                                } else {
                                    goto block_56;
                                }
                            } else {
                            block_56:
                                if (var_s3 == 0) {
                                    var_s3 = -1;
                                    var_s7 = var_s4;
                                }
                            }
                            screenGetTextData(temp_s2, var_s1, &sp18, &sp30, &sp34, 0);
                            var_s1 += 1;
                            var_v0_3 = temp_s2->unk_50[var_s1];
                            var_s4 += sp18.unk_0C + sp34;
                        }
                        if (var_s3 != 0) {
                            *temp_s6 = var_s7;
                        } else {
                            *temp_s6 = var_s4;
                        }
                        arg0->unk_18 = (s32)(arg0->unk_18 + 3);
                        if (geModeFade == 0) {
                            temp_s2->unk_44 |= 0x10000;
                        }
                    }
                    var_s5 += 1;
                }
                var_t0 += 1;
            }
        }
    }

    var_s5_2 = 0;
    while (var_s5_2 < arg0->unk_14) {
        if ((arg0->unk_5C[var_s5_2].unk_0 == arg0->unk_3C) && (arg0->unk_5C[var_s5_2].unk_2 == arg0->unk_40)) {
            arg0->unk_44 = arg0->unk_5C[var_s5_2].unk_4;
            arg0->unk_48 = arg0->unk_5C[var_s5_2].unk_6;
            break;
        }
        var_s5_2 += 1;
    }

end:;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenUpdateArea);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenUpdateArea);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", screenUpdateArea);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", screenUpdateArea);
#endif

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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002400C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80024534_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_8002496C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002411C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80024644_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80024A7C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002408C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800245B4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800249EC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80024114_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002463C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80024A74_ger);
#endif

//! RENAME TODO: func_80024BF4_usa -> screenGetHeap?
//! RENAME TODO: B_8018E4F8_usa -> gpHeapNext?
nbool func_80024BF4_usa(void **heapP) {
    *heapP = ALIGN_PTR(B_8018E4F8_usa);

    return ntrue;
}

//! RENAME TODO: func_80024C14_usa -> screenChangePending?
//! RENAME TODO: B_8018E524_usa -> giScreenNext?
nbool func_80024C14_usa(void) {
    if (B_8018E524_usa != -1) {
        return ntrue;
    }
    return nfalse;
}

nbool screenFlushing(void) {
    //! RENAME TODO: B_8018E504_usa -> gnFrameSkip?
    if ((B_8018E504_usa != 0) || (B_8018E524_usa != -1)) {
        return ntrue;
    }
    return nfalse;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenDraw);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenDraw);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", screenDraw);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", screenDraw);
#endif

INLINE nbool screenFindImage(s32 arg0, s32 arg1, struct_gaScreen_unk_1C **arg2) {
    s32 i;

    if ((arg1 != -1) && (arg0 >= 0) && (arg0 < gnScreenCount)) {
        for (i = 0; i < gaScreen[arg0].unk_0C; i++) {
            if (gaScreen[arg0].unk_1C[i].unk_00 == arg1) {
                *arg2 = &gaScreen[arg0].unk_1C[i];
                return ntrue;
            }
        }
    }
    return nfalse;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800255D8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80025850_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80025CC4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80025720_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80025998_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80025E0C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80025690_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80025908_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80025D7C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80025718_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80025990_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80025E04_ger);
#endif

#if VERSION_USA
#if 0
void screenTick(screenTick_arg0 *arg0) {
    screenTick_arg0 *sp14;
    ? var_a2_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s1_2;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v1;
    s32 temp_v1_10;
    s32 temp_v1_11;
    s32 temp_v1_12;
    s32 temp_v1_13;
    s32 temp_v1_14;
    s32 temp_v1_15;
    s32 temp_v1_16;
    s32 temp_v1_17;
    s32 temp_v1_18;
    s32 temp_v1_19;
    s32 temp_v1_23;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 temp_v1_9;
    s32 var_a1;
    s32 var_a2;
    s32 var_a2_3;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_a3_3;
    s32 var_a3_4;
    s32 var_a3_5;
    s32 var_fp;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s4;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_12;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_v0_9;
    s32 var_v1;
    screenTick_arg0 *var_s6;
    struct_gaScreen *temp_s3;
    struct_gaScreen *temp_t0;
    struct_gaScreen *temp_v1_25;
    struct_gaScreen *var_a0;
    struct_gaScreen_unk_18 *temp_a0_10;
    struct_gaScreen_unk_18 *temp_a0_2;
    struct_gaScreen_unk_18 *temp_a0_7;
    struct_gaScreen_unk_18 *temp_a0_8;
    struct_gaScreen_unk_18 *temp_a0_9;
    struct_gaScreen_unk_18 *temp_v1_21;
    u16 temp_v1_20;
    u32 temp_a2;
    void *temp_a0;
    void *temp_v1_22;
    void *temp_v1_24;
    void *var_v0_10;
    void *var_v0_11;

    sp14 = arg0;
    B_8018E540_usa += 1;
    if (giScreen >= 0) {
        var_s5 = 0;
        if (giScreen < gnScreenCount) {
            temp_s3 = &gaScreen[giScreen];
            if (B_8018E528_usa > 0) {
                var_s6 = sp14;
                var_fp = 0;
                do {
                    var_s0 = 0;
                    if (geModeFade != 0) {
                        var_s6->unk_0 = 0;
                    } else {
                        var_a3 = 0;
                        if (temp_s3->unk_14 > 0) {
                            var_a2 = 0;
                            do {
                                temp_a0 = temp_s3->unk_24 + var_a2;
                                temp_v1 = temp_a0->unk_2C;
                                if (temp_v1 & 0x40) {
                                    var_a3 = -1;
                                    if (temp_v1 & 0x80) {
                                        if (temp_a0->unk_14 == 1) {
                                            if (var_s6->unk_0 == 4) {
                                                temp_a0->unk_14 = 0;
                                            } else {
                                                goto block_14;
                                            }
                                        } else {
block_14:
                                            if ((temp_a0->unk_14 == 0) && (var_s6->unk_0 == 3)) {
                                                temp_a0->unk_14 = 1;
                                            } else {
                                                goto block_17;
                                            }
                                        }
                                    } else {
block_17:
                                        var_s6->unk_0 = 0;
                                    }
                                }
                                var_s0 += 1;
                                var_a2 += 0x30;
                            } while (var_s0 < temp_s3->unk_14);
                        }
                        if (var_a3 == 0) {
                            temp_s2 = (var_fp + temp_s3)->unk_28;
                            if ((temp_s2 == -1) || (temp_a0_2 = &temp_s3->unk_18[temp_s2], var_s2 = -1, ((temp_a0_2->unk_2C & 0x800) != 0))) {
                                *(var_fp + sp14) = 0;
                            } else {
                                temp_a2 = *(var_fp + sp14);
                                var_s4 = 0;
                                switch (temp_a2) {
                                    case 0x1:
                                        if (temp_a0_2->unk_50 < temp_a0_2->unk_58) {
                                            temp_v1_2 = temp_a0_2->unk_40;
                                            var_v0 = 0;
                                            if (temp_v1_2 > 0) {
                                                if (temp_a0_2->unk_2C & 0x1000) {
loop_28:
                                                    temp_v0 = temp_a0_2->unk_40 - 1;
                                                    temp_a0_2->unk_40 = temp_v0;
                                                    if (temp_v0 != -1) {
                                                        temp_v1_3 = (temp_v0 * temp_a0_2->unk_34) + temp_a0_2->unk_3C;
                                                        if (((s32) temp_a0_2->unk_38[temp_v1_3 >> 3] >> (temp_v1_3 & 7)) & 1) {
                                                            goto block_32;
                                                        }
                                                        goto loop_28;
                                                    }
                                                    temp_a0_2->unk_40 = temp_v1_2;
                                                    var_v0 = 0;
                                                } else {
                                                    temp_a0_2->unk_40 = temp_v1_2 - 1;
block_32:
                                                    screenUpdateArea(temp_a0_2);
                                                    var_v0 = -1;
                                                }
                                            }
                                            if (var_v0 != 0) {
                                                var_s4 = 1;
                                                goto block_176;
                                            }
                                            if (temp_a0_2->unk_2C & 0x20000) {
                                                if (func_800255D8_usa(temp_a0_2, temp_a0_2->unk_3C - 1, temp_a0_2->unk_30 - 1, 1) != 0) {
                                                    var_s4 = 1;
                                                    goto block_176;
                                                }
                                                temp_s1 = var_s5 | 0x10000;
                                                var_s2 = func_80025850_usa(temp_s3, temp_a0_2, 3, temp_s1);
                                                var_v0_2 = var_s5 * 0x10;
                                                if (var_s2 == -1) {
                                                    if (temp_a0_2->unk_2C & 0x200000) {
                                                        var_s2 = func_80025850_usa(temp_s3, temp_a0_2, 1, temp_s1);
                                                    }
                                                    var_v0_2 = var_s5 * 0x10;
                                                    if (var_s2 == -1) {
                                                        if (temp_a0_2->unk_2C & 0x40000) {
                                                            var_v0_2 = var_s5 * 0x10;
                                                            if (func_800255D8_usa(temp_a0_2, temp_a0_2->unk_34 - 1, temp_a0_2->unk_30 - 1, 1) != 0) {
                                                                var_s4 = 1;
                                                            }
                                                        } else {
                                                            goto block_176;
                                                        }
                                                    }
                                                }
                                            } else {
                                                var_a2_2 = 3;
                                                var_a3_2 = var_s5 | 0x10000;
                                                goto block_175;
                                            }
                                        } else {
                                            temp_a0_3 = temp_a0_2->unk_30;
                                            temp_v1_4 = temp_a0_2->unk_40;
                                            var_v0_3 = 0;
                                            if (temp_v1_4 < (temp_a0_3 - 1)) {
                                                if (temp_a0_2->unk_2C & 0x1000) {
loop_52:
                                                    temp_v0_2 = temp_a0_2->unk_40 + 1;
                                                    temp_a0_2->unk_40 = temp_v0_2;
                                                    if (temp_v0_2 != temp_a0_3) {
                                                        temp_v1_5 = (temp_v0_2 * temp_a0_2->unk_34) + temp_a0_2->unk_3C;
                                                        if (((s32) temp_a0_2->unk_38[temp_v1_5 >> 3] >> (temp_v1_5 & 7)) & 1) {
                                                            goto block_56;
                                                        }
                                                        goto loop_52;
                                                    }
                                                    temp_a0_2->unk_40 = temp_v1_4;
                                                    var_v0_3 = 0;
                                                } else {
                                                    temp_a0_2->unk_40 = temp_v1_4 + 1;
block_56:
                                                    screenUpdateArea(temp_a0_2);
                                                    var_v0_3 = -1;
                                                }
                                            }
                                            if (var_v0_3 != 0) {
                                                var_s4 = 1;
                                            } else {
                                                var_a2_2 = 3;
block_174:
                                                var_a3_2 = var_s5;
block_175:
                                                var_s2 = func_80025850_usa(temp_s3, temp_a0_2, var_a2_2, var_a3_2);
                                            }
                                        default:
block_176:
                                            var_v0_2 = var_s5 * 0x10;
                                        }
                                        break;
                                    case 0x2:
                                        if (temp_a0_2->unk_50 < temp_a0_2->unk_58) {
                                            temp_a0_4 = temp_a0_2->unk_30;
                                            temp_v1_6 = temp_a0_2->unk_40;
                                            var_v0_4 = 0;
                                            if (temp_v1_6 < (temp_a0_4 - 1)) {
                                                if (temp_a0_2->unk_2C & 0x1000) {
loop_66:
                                                    temp_v0_3 = temp_a0_2->unk_40 + 1;
                                                    temp_a0_2->unk_40 = temp_v0_3;
                                                    if (temp_v0_3 != temp_a0_4) {
                                                        temp_v1_7 = (temp_v0_3 * temp_a0_2->unk_34) + temp_a0_2->unk_3C;
                                                        if (((s32) temp_a0_2->unk_38[temp_v1_7 >> 3] >> (temp_v1_7 & 7)) & 1) {
                                                            goto block_70;
                                                        }
                                                        goto loop_66;
                                                    }
                                                    temp_a0_2->unk_40 = temp_v1_6;
                                                    var_v0_4 = 0;
                                                } else {
                                                    temp_a0_2->unk_40 = temp_v1_6 + 1;
block_70:
                                                    screenUpdateArea(temp_a0_2);
                                                    var_v0_4 = -1;
                                                }
                                            }
                                            if (var_v0_4 != 0) {
                                                var_s4 = 2;
                                                goto block_176;
                                            }
                                            if (temp_a0_2->unk_2C & 0x20000) {
                                                if (func_800255D8_usa(temp_a0_2, temp_a0_2->unk_3C + 1, 0, 2) != 0) {
                                                    var_s4 = 2;
                                                    goto block_176;
                                                }
                                                temp_s1_2 = var_s5 | 0x10000;
                                                var_s2 = func_80025850_usa(temp_s3, temp_a0_2, 4, temp_s1_2);
                                                var_v0_2 = var_s5 * 0x10;
                                                if (var_s2 == -1) {
                                                    if (temp_a0_2->unk_2C & 0x200000) {
                                                        var_s2 = func_80025850_usa(temp_s3, temp_a0_2, 2, temp_s1_2);
                                                    }
                                                    var_v0_2 = var_s5 * 0x10;
                                                    if (var_s2 == -1) {
                                                        if (temp_a0_2->unk_2C & 0x40000) {
                                                            var_v0_2 = var_s5 * 0x10;
                                                            if (func_800255D8_usa(temp_a0_2, 0, 0, 2) != 0) {
                                                                var_s4 = 2;
                                                            }
                                                        } else {
                                                            goto block_176;
                                                        }
                                                    }
                                                }
                                            } else {
                                                var_a2_2 = 4;
                                                var_a3_2 = var_s5 | 0x10000;
                                                goto block_175;
                                            }
                                        } else {
                                            temp_v1_8 = temp_a0_2->unk_40;
                                            var_v0_5 = 0;
                                            if (temp_v1_8 > 0) {
                                                if (temp_a0_2->unk_2C & 0x1000) {
loop_89:
                                                    temp_v0_4 = temp_a0_2->unk_40 - 1;
                                                    temp_a0_2->unk_40 = temp_v0_4;
                                                    if (temp_v0_4 != -1) {
                                                        temp_v1_9 = (temp_v0_4 * temp_a0_2->unk_34) + temp_a0_2->unk_3C;
                                                        if (((s32) temp_a0_2->unk_38[temp_v1_9 >> 3] >> (temp_v1_9 & 7)) & 1) {
                                                            goto block_93;
                                                        }
                                                        goto loop_89;
                                                    }
                                                    temp_a0_2->unk_40 = temp_v1_8;
                                                    var_v0_5 = 0;
                                                } else {
                                                    temp_a0_2->unk_40 = temp_v1_8 - 1;
block_93:
                                                    screenUpdateArea(temp_a0_2);
                                                    var_v0_5 = -1;
                                                }
                                            }
                                            if (var_v0_5 != 0) {
                                                var_s4 = 2;
                                            } else {
block_173:
                                                var_a2_2 = 4;
                                                goto block_174;
                                            }
                                            goto block_176;
                                        }
                                        break;
                                    case 0x3:
                                        if (temp_a0_2->unk_54 >= temp_a0_2->unk_4C) {
                                            temp_v1_10 = temp_a0_2->unk_3C;
                                            var_v0_6 = 0;
                                            if (temp_v1_10 > 0) {
                                                if (temp_a0_2->unk_2C & 0x1000) {
loop_102:
                                                    temp_a1 = temp_a0_2->unk_3C - 1;
                                                    temp_a0_2->unk_3C = temp_a1;
                                                    if (temp_a1 != -1) {
                                                        temp_v1_11 = (temp_a0_2->unk_40 * temp_a0_2->unk_34) + temp_a1;
                                                        if (((s32) temp_a0_2->unk_38[temp_v1_11 >> 3] >> (temp_v1_11 & 7)) & 1) {
                                                            goto block_106;
                                                        }
                                                        goto loop_102;
                                                    }
                                                    temp_a0_2->unk_3C = temp_v1_10;
                                                    var_v0_6 = 0;
                                                } else {
                                                    temp_a0_2->unk_3C = temp_v1_10 - 1;
block_106:
                                                    screenUpdateArea(temp_a0_2);
                                                    var_v0_6 = -1;
                                                }
                                            }
                                            if (var_v0_6 != 0) {
                                                var_s4 = 3;
                                                goto block_176;
                                            }
                                            temp_v1_12 = temp_a0_2->unk_2C;
                                            if (temp_v1_12 & 0x400) {
                                                if (func_800255D8_usa(temp_a0_2, temp_a0_2->unk_34 - 1, temp_a0_2->unk_40 - 1, 3) != 0) {
                                                    var_s4 = 3;
                                                    goto block_176;
                                                }
                                                var_a3_3 = var_s5;
                                                if (!(temp_a0_2->unk_2C & 0x200000)) {
                                                    var_a3_3 = var_s5 | 0x10000;
                                                }
                                                var_s2 = func_80025850_usa(temp_s3, temp_a0_2, 1, var_a3_3);
                                                var_v0_2 = var_s5 * 0x10;
                                                if (var_s2 == -1) {
                                                    if (temp_a0_2->unk_2C & 0x40000) {
                                                        var_v0_7 = func_800255D8_usa(temp_a0_2, temp_a0_2->unk_34 - 1, temp_a0_2->unk_30 - 1, 3);
                                                        goto block_132;
                                                    }
                                                    goto block_176;
                                                }
                                            } else {
                                                var_a3_2 = var_s5;
                                                if (!(temp_v1_12 & 0x200000)) {
                                                    var_a3_2 = var_s5 | 0x10000;
                                                }
                                                var_a2_2 = 1;
                                                goto block_175;
                                            }
                                        } else {
                                            temp_a0_5 = temp_a0_2->unk_34;
                                            temp_v1_13 = temp_a0_2->unk_3C;
                                            var_v0_7 = 0;
                                            if (temp_v1_13 < (temp_a0_5 - 1)) {
                                                if (temp_a0_2->unk_2C & 0x1000) {
loop_126:
                                                    temp_v0_5 = temp_a0_2->unk_3C + 1;
                                                    temp_a0_2->unk_3C = temp_v0_5;
                                                    if (temp_v0_5 != temp_a0_5) {
                                                        temp_v1_14 = (temp_a0_2->unk_40 * temp_a0_5) + temp_v0_5;
                                                        if (((s32) temp_a0_2->unk_38[temp_v1_14 >> 3] >> (temp_v1_14 & 7)) & 1) {
                                                            goto block_130;
                                                        }
                                                        goto loop_126;
                                                    }
                                                    temp_a0_2->unk_3C = temp_v1_13;
                                                    var_v0_7 = 0;
                                                } else {
                                                    temp_a0_2->unk_3C = temp_v1_13 + 1;
block_130:
                                                    screenUpdateArea(temp_a0_2);
                                                    var_v0_7 = -1;
                                                }
                                            }
block_132:
                                            var_v0_2 = var_s5 * 0x10;
                                            if (var_v0_7 != 0) {
                                                var_s4 = 3;
                                            }
                                        }
                                        break;
                                    case 0x4:
                                        if (temp_a0_2->unk_54 >= temp_a0_2->unk_4C) {
                                            temp_a0_6 = temp_a0_2->unk_34;
                                            temp_v1_15 = temp_a0_2->unk_3C;
                                            var_v0_8 = 0;
                                            if (temp_v1_15 < (temp_a0_6 - 1)) {
                                                if (temp_a0_2->unk_2C & 0x1000) {
loop_138:
                                                    temp_v0_6 = temp_a0_2->unk_3C + 1;
                                                    temp_a0_2->unk_3C = temp_v0_6;
                                                    if (temp_v0_6 != temp_a0_6) {
                                                        temp_v1_16 = (temp_a0_2->unk_40 * temp_a0_6) + temp_v0_6;
                                                        if (((s32) temp_a0_2->unk_38[temp_v1_16 >> 3] >> (temp_v1_16 & 7)) & 1) {
                                                            goto block_142;
                                                        }
                                                        goto loop_138;
                                                    }
                                                    temp_a0_2->unk_3C = temp_v1_15;
                                                    var_v0_8 = 0;
                                                } else {
                                                    temp_a0_2->unk_3C = temp_v1_15 + 1;
block_142:
                                                    screenUpdateArea(temp_a0_2);
                                                    var_v0_8 = -1;
                                                }
                                            }
                                            if (var_v0_8 != 0) {
                                                var_s4 = 4;
                                                goto block_176;
                                            }
                                            temp_v1_17 = temp_a0_2->unk_2C;
                                            if (temp_v1_17 & 0x400) {
                                                if (func_800255D8_usa(temp_a0_2, 0, temp_a0_2->unk_40 + 1, 4) != 0) {
                                                    var_s4 = 4;
                                                    goto block_176;
                                                }
                                                var_a3_4 = var_s5;
                                                if (!(temp_a0_2->unk_2C & 0x200000)) {
                                                    var_a3_4 = var_s5 | 0x10000;
                                                }
                                                var_s2 = func_80025850_usa(temp_s3, temp_a0_2, 2, var_a3_4);
                                                var_v0_2 = var_s5 * 0x10;
                                                if (var_s2 == -1) {
                                                    if (temp_a0_2->unk_2C & 0x40000) {
                                                        var_v0_9 = func_800255D8_usa(temp_a0_2, 0, 0, 4);
                                                        goto block_167;
                                                    }
                                                    goto block_176;
                                                }
                                            } else {
                                                var_a3_2 = var_s5;
                                                if (!(temp_v1_17 & 0x200000)) {
                                                    var_a3_2 = var_s5 | 0x10000;
                                                }
                                                var_a2_2 = 2;
                                                goto block_175;
                                            }
                                        } else {
                                            temp_v1_18 = temp_a0_2->unk_3C;
                                            var_v0_9 = 0;
                                            if (temp_v1_18 > 0) {
                                                if (temp_a0_2->unk_2C & 0x1000) {
loop_161:
                                                    temp_a1_2 = temp_a0_2->unk_3C - 1;
                                                    temp_a0_2->unk_3C = temp_a1_2;
                                                    if (temp_a1_2 != -1) {
                                                        temp_v1_19 = (temp_a0_2->unk_40 * temp_a0_2->unk_34) + temp_a1_2;
                                                        if (((s32) temp_a0_2->unk_38[temp_v1_19 >> 3] >> (temp_v1_19 & 7)) & 1) {
                                                            goto block_165;
                                                        }
                                                        goto loop_161;
                                                    }
                                                    temp_a0_2->unk_3C = temp_v1_18;
                                                    var_v0_9 = 0;
                                                } else {
                                                    temp_a0_2->unk_3C = temp_v1_18 - 1;
block_165:
                                                    screenUpdateArea(temp_a0_2);
                                                    var_v0_9 = -1;
                                                }
                                            }
block_167:
                                            var_v0_2 = var_s5 * 0x10;
                                            if (var_v0_9 != 0) {
                                                var_s4 = 4;
                                            }
                                        }
                                        break;
                                    case 0x13:
                                        var_s6->unk_0 = 3;
                                        var_a2_2 = 1;
                                        goto block_174;
                                    case 0x14:
                                        var_s6->unk_0 = 4;
                                        var_a2_2 = 2;
                                        goto block_174;
                                    case 0x11:
                                        var_s6->unk_0 = 1;
                                        var_a2_2 = 3;
                                        goto block_174;
                                    case 0x12:
                                        var_s6->unk_0 = 2;
                                        goto block_173;
                                }
                                temp_v1_20 = *(&gTheGame.unk_89C4[0].unk_0A + var_v0_2);
                                if ((temp_v1_20 & 0x800) || (temp_v1_20 & 0x400) || (temp_v1_20 & 0x200) || (temp_v1_20 & 0x100)) {
                                    B_8018E558_usa = 8;
                                    temp_a0_2->unk_2C &= 0xFFFBFFFF;
                                } else if (B_8018E558_usa > 0) {
                                    B_8018E558_usa -= 1;
                                } else {
                                    temp_a0_2->unk_2C |= 0x40000;
                                }
                                if ((var_s2 != -1) && ((((var_s5 ^ 1) * 4) + temp_s3)->unk_28 != var_s2)) {
                                    if ((temp_a0_2->unk_2C & 0x200) && (var_a1 = var_s2 * 0x60, temp_a0_7 = &temp_s3->unk_18[var_s2], ((temp_a0_7->unk_2C & 0x200) != 0))) {
                                        if (var_s6->unk_0 == 3) {
                                            if (temp_a0_2->unk_30 == temp_a0_7->unk_30) {
                                                temp_a0_7->unk_3C = temp_a0_7->unk_34 - 1;
                                                goto block_196;
                                            }
                                            goto block_193;
                                        }
block_193:
                                        if ((var_s6->unk_0 == 4) && (var_a1 = var_s2 * 0x60, temp_a0_8 = &temp_s3->unk_18[var_s2], (temp_a0_2->unk_30 == temp_a0_8->unk_30))) {
                                            temp_a0_8->unk_3C = 0;
block_196:
                                            (var_a1 + temp_s3->unk_18)->unk_40 = (s32) temp_a0_2->unk_40;
                                        } else if ((var_s6->unk_0 == 1) && (temp_a0_9 = &temp_s3->unk_18[var_s2], (temp_a0_2->unk_34 == temp_a0_9->unk_34))) {
                                            temp_a0_9->unk_3C = temp_a0_2->unk_3C;
                                            temp_v1_21 = &temp_s3->unk_18[var_s2];
                                            temp_v1_21->unk_40 = temp_v1_21->unk_30 - 1;
                                        } else if (var_s6->unk_0 == 2) {
                                            temp_a0_10 = &temp_s3->unk_18[var_s2];
                                            if (temp_a0_2->unk_34 == temp_a0_10->unk_34) {
                                                temp_a0_10->unk_3C = temp_a0_2->unk_3C;
                                                temp_s3->unk_18[var_s2].unk_40 = 0;
                                            }
                                        }
                                    }
                                    if (var_s6->unk_0 != 2) {
                                        if (var_s6->unk_0 < 3) {
                                            if (var_s6->unk_0 == 1) {
                                                var_s4 = 0x11;
                                                goto block_217;
                                            }
                                            var_v0_10 = var_fp + temp_s3;
                                        } else {
                                            switch (var_s6->unk_0) { /* switch 1; irregular */
                                                case 0x4: /* switch 1 */
                                                    var_s4 = 0x14;
                                                    goto block_217;
                                                default: /* switch 1 */
                                                    var_v0_10 = var_fp + temp_s3;
                                                    break;
                                                case 0x3: /* switch 1 */
                                                    var_s4 = 0x13;
                                                    goto block_217;
                                            }
                                        }
                                    } else {
                                        var_s4 = 0x12;
block_217:
                                        var_v0_10 = var_fp + temp_s3;
                                    }
                                    var_v0_10->unk_28 = var_s2;
                                    screenUpdateArea(&temp_s3->unk_18[var_s2]);
                                }
                                if (var_s4 != 0) {
                                    screenUpdateArea(temp_a0_2);
                                }
                                var_s6->unk_0 = var_s4;
                            }
                        }
                    }
                    var_s6 += 4;
                    var_s5 += 1;
                    var_fp += 4;
                } while (var_s5 < B_8018E528_usa);
            }
            if (var_s5 == 1) {
                sp14->unk_4 = 0;
            }
            var_s0_2 = 0;
            func_8002496C_usa();
            if (temp_s3->unk_10 > 0) {
                var_s1 = 0;
                do {
                    temp_v1_22 = var_s1 + temp_s3->unk_20;
                    if (!(temp_v1_22->unk_24 & 0x1008)) {
                        func_800207FC_usa(temp_v1_22->unk_14, B_8018E540_usa);
                    }
                    var_s0_2 += 1;
                    var_s1 += 0x30;
                } while (var_s0_2 < temp_s3->unk_10);
            }
            var_s2_2 = 0;
            if (temp_s3->unk_08 > 0) {
                var_s0_3 = 0;
                do {
                    temp_v1_23 = (var_s0_3 + temp_s3->unk_18)->unk_2C;
                    if ((temp_v1_23 & 0x80) && (((var_s2_2 == temp_s3->unk_28) && (temp_v1_23 & 1)) || ((var_s2_2 == temp_s3->unk_2C) && (temp_v1_23 & 2)))) {
                        func_800207FC_usa((var_s0_3 + temp_s3->unk_18)->unk_C, B_8018E540_usa);
                        if ((var_s0_3 + temp_s3->unk_18)->unk_2C & 0x4000) {
                            func_800207FC_usa(B_8018E550_usa, B_8018E540_usa);
                        }
                    }
                    var_s2_2 += 1;
                    var_s0_3 += 0x60;
                } while (var_s2_2 < temp_s3->unk_08);
            }
            var_s0_4 = 0;
            if (temp_s3->unk_14 > 0) {
                var_s1_2 = 0;
                do {
                    temp_v1_24 = var_s1_2 + temp_s3->unk_24;
                    if (temp_v1_24->unk_2C & 1) {
                        func_800207FC_usa(temp_v1_24->unk_20, B_8018E540_usa);
                    }
                    var_s0_4 += 1;
                    var_s1_2 += 0x30;
                } while (var_s0_4 < temp_s3->unk_14);
            }
            if (gnScreenCount > 0) {
                var_a2_3 = 0;
                var_a0 = gaScreen;
                temp_t0 = &var_a0[gnScreenCount];
                do {
                    var_v1 = 0;
                    if (var_a0->unk_C > 0) {
                        var_v0_11 = var_a2_3 + gaScreen;
                        do {
                            var_v1 += 1;
                            var_v0_11 = var_a2_3 + gaScreen;
                        } while (var_v1 < var_v0_11->unk_C);
                    }
                    var_a0 += 0x38;
                    var_a2_3 += 0x38;
                } while ((s32) var_a0 < (s32) temp_t0);
            }
            if (geModeFade == 0) {
                func_80025CC4_usa(temp_s3);
            }
        }
    }
    temp_s0 = geModeFade;
    var_a3_5 = 0;
    switch (temp_s0) {                              /* switch 2; irregular */
        case 0x3:                                   /* switch 2 */
            if (B_8018E504_usa == 0) {
                var_a3_5 = -1;
block_256:
                geModeFade = 0;
            }
            break;
        case 0x2:                                   /* switch 2 */
            if (B_8018E504_usa == 0) {
                temp_v0_7 = gnAlphaFade - 0x10;
                gnAlphaFade = temp_v0_7;
                if (temp_v0_7 <= 0) {
                    gnAlphaFade = 0;
                    if (B_8018E524_usa != -1) {
                        geModeFade = 1;
                    } else {
                        goto block_256;
                    }
                }
            }
            break;
        case 0x1:                                   /* switch 2 */
            if (B_8018E504_usa == 0) {
                var_v0_12 = gnAlphaFade + 0x10;
                if (gnAlphaFade == 0) {
                    if (B_8018E524_usa != -1) {
                        var_a3_5 = -1;
                    }
                    var_v0_12 = gnAlphaFade + 0x10;
                }
                gnAlphaFade = var_v0_12;
                if (var_v0_12 >= 0xFF) {
                    geModeFade = 0;
                    gnAlphaFade = 0xFF;
                }
            }
            break;
    }
    if (var_a3_5 != 0) {
        func_8002400C_usa(B_8018E524_usa);
        B_8018E524_usa = -1;
        B_8018E528_usa = B_8018E52C_usa;
    }
    if ((geModeFade != temp_s0) && (giScreen >= 0) && (giScreen < gnScreenCount)) {
        temp_v1_25 = &gaScreen[giScreen];
        if (temp_v1_25->unk_08 > 0) {
            screenUpdateArea(temp_v1_25->unk_18);
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenTick);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenTick);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", screenTick);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", screenTick);
#endif

s32 screenSet(const char *arg0, s32 arg1) {
    s32 sp10;
    s32 var_a0;
    s32 var_s0;

    if ((arg1 & 0x200) && !(arg1 & 0x100) && (peelActive() != 0)) {
        return giScreen;
    }

    if ((arg1 & 0x7F000) == 0x7F000) {
        var_s0 = -1;
    } else if (arg1 & 0x80000) {
        var_s0 = (arg1 & 0x7F000) >> 0xC;
    } else {
        var_s0 = 0;
    }

    if (screenFind(&sp10, arg0)) {
        s32 temp;

        if ((geModeFade == 1) || (geModeFade == 3)) {
            return giScreen;
        }

        if ((geModeFade > 1) && (geModeFade < 4)) {
            if (sp10 == giScreen) {
                if (geModeFade == 2) {
                    geModeFade = 1;
                } else if (geModeFade == 3) {
                    geModeFade = 0;
                }
                B_8018E524_usa = -1;
                return sp10;
            }

            return giScreen;
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

s32 screenGet(void) {
    return giScreen;
}

void func_8002759C_usa(void) {
}

void func_800275A4_usa(void) {
}

#define is_lower(c) ((c) >= 'a' && (c) <= 'z')
#define to_upper(c) (is_lower(c) ? ((c) - ('a' - 'A')) : (c))

#if VERSION_USA
#ifdef NON_EQUIVALENT
nbool func_800275AC_usa(const char *arg0, const char *arg1) {
    s32 var_t0;

    for (var_t0 = 0; arg0[var_t0] != 0; var_t0++) {
        s32 var_a2;
        s32 var_v1;

        var_a2 = arg0[var_t0];
        if (is_lower(var_a2)) {
            var_a2 -= 0x20; // ('a' - 'A')
        }

        var_v1 = arg1[var_t0];
        if (is_lower(var_v1)) {
            var_v1 -= 0x20; // ('a' - 'A')
        }

        if (var_a2 != var_v1) {
            return 0;
        }
    }

    if (arg1[var_t0] == 0) {
        return -1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800275AC_usa);
#endif
#endif

#if VERSION_USA
nbool func_80027618_usa(s32 arg0, s32 arg1, u32 arg2) {
    if (arg2 >= GASCREEN_UNK_28_LEN) {
        return nfalse;
    }

    if ((arg0 >= 0) && (arg0 < gnScreenCount)) {
        s32 temp_t1 = gaScreen[arg0].unk_28[arg2];
        s32 i;

        if (arg1 == -1) {
            gaScreen[arg0].unk_28[arg2] = arg1;
            gaScreen[arg0].unk_30[arg2] = temp_t1;
            return ntrue;
        }

        for (i = 0; i < gaScreen[arg0].unk_08; i++) {
            if (gaScreen[arg0].unk_18[i].unk_1C == arg1) {
                gaScreen[arg0].unk_28[arg2] = i;
                gaScreen[arg0].unk_30[arg2] = temp_t1;
                return ntrue;
            }
        }
    }

    return nfalse;
}
#endif

#if VERSION_USA
// screenGetArea?
INLINE nbool func_800276CC_usa(s32 arg0, UNK_TYPE4 *arg1, s32 arg2) {
    if (arg2 < GASCREEN_UNK_28_LEN) {
        if ((arg0 >= 0) && (arg0 < gnScreenCount)) {
            s32 var_a0 = gaScreen[arg0].unk_28[arg2];

            if (var_a0 == -1) {
                var_a0 = gaScreen[arg0].unk_30[arg2];
            }

            if ((var_a0 >= 0) && (var_a0 < gaScreen[arg0].unk_08)) {
                *arg1 = gaScreen[arg0].unk_18[var_a0].unk_1C;
                return ntrue;
            }
        }
    }

    return nfalse;
}
#endif

#if VERSION_USA
// Not present on ROM?
STATIC_INLINE nbool inlined_func(s32 arg0, s32 arg1, struct_gaScreen_unk_18 **arg2) {
    s32 i;

    if ((arg1 != -1) && (arg0 >= 0) && (arg0 < gnScreenCount)) {
        for (i = 0; i < gaScreen[arg0].unk_08; i++) {
            if (gaScreen[arg0].unk_18[i].unk_1C == arg1) {
                *arg2 = &gaScreen[arg0].unk_18[i];
                return ntrue;
            }
        }
    }

    return nfalse;
}
#endif

#if VERSION_USA
nbool func_8002776C_usa(s32 arg0, s32 arg1) {
    struct_gaScreen_unk_18 *sp0;

    if (inlined_func(arg0, arg1, &sp0)) {
        sp0->unk_2C |= 0x800;
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_USA
nbool func_80027838_usa(s32 arg0, s32 arg1) {
    struct_gaScreen_unk_18 *sp10;

    if (inlined_func(arg0, arg1, &sp10)) {
        sp10->unk_2C &= ~0x800;
        screenUpdateArea(sp10);
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_USA
s32 func_80027914_usa(s32 arg0, s32 arg1) {
    struct_gaScreen_unk_18 *sp0;

    if (inlined_func(arg0, arg1, &sp0)) {
        return sp0->unk_2C;
    }
    return 0;
}
#endif

#if VERSION_USA
nbool func_800279D8_usa(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    struct_gaScreen_unk_18 *sp0;

    if (inlined_func(arg0, arg1, &sp0)) {
        *arg2 = sp0->unk_30;
        *arg3 = sp0->unk_34;
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_USA
nbool func_80027AB0_usa(void) {
    if (B_8018E4FC_usa == 0) {
        B_8018E4FC_usa = 1;
    } else {
        B_8018E4FC_usa = 3;
    }

    return ntrue;
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_800276F4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027760_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027814_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_800278B4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027980_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027A5C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027B20_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027BF8_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027664_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800276D0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027784_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027824_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800278F0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800279CC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027A90_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027B68_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_800276EC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80027758_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002780C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_800278AC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80027978_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80027A54_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80027B18_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80027BF0_ger);
#endif

nbool func_80027AD4_usa(void) {
    s32 old = B_8018E4FC_usa;

    B_8018E4FC_usa >>= 1;
    if (old != 0) {
        return ntrue;
    }
    return nfalse;
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
nbool screenTextDone(s32 arg0, s32 arg1) {
    struct_gaScreen_unk_1C *sp0;
    s32 var_v0_2 = screenFindImage(arg0, arg1, &sp0);

    if (var_v0_2 != 0) {
        if (sp0->unk_44 & 0x1000) {
            if (sp0->unk_48 != 0) {
                if (sp0->unk_38 >= sp0->unk_20) {
                    return -1;
                }
                return 0;
            }
            if (sp0->unk_38 >= sp0->unk_20) {
                if (sp0->unk_10 == 0) {
                    return -1;
                }
            }
            return 0;
        }
        return -1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenTextDone);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenTextDone);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", screenTextDone);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", screenTextDone);
#endif

#if VERSION_USA
#ifdef NON_MATCHING
nbool func_80027C04_usa(s32 arg0, s32 arg1) {
    struct_gaScreen_unk_1C *sp0;
    s32 var_v0_2 = screenFindImage(arg0, arg1, &sp0);
    s32 var_v0;

    if (var_v0_2 != 0) {
        var_v0 = -1;
        if (sp0->unk_44 & 0x1000) {
            if (sp0->unk_48 != 0) {
                var_v0 = (sp0->unk_10 != 0) ? -1 : 0;
            } else if (sp0->unk_38 >= sp0->unk_20) {
                var_v0 = (sp0->unk_10 == 0) ? -1 : 0;
            } else {
                var_v0 = 0;
            }
        }
        return var_v0;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80027C04_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027D4C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027CBC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80027D44_ger);
#endif

nbool screenHideText(s32 arg0, s32 arg1) {
    s32 ret;
    s32 var_s1;
    s32 i;
    s32 var_s4;

    if ((arg1 != 0xFFFFFFFF) && (CHECK_FLAG_ALL(arg1, 0xC0000000))) {
        var_s4 = arg1 & 0x3FFFFFFF;
        var_s1 = 0x10000;
    } else if ((arg1 != 0xFFFFFFFF) && (CHECK_FLAG_ALL(arg1, 0x80008000))) {
        var_s4 = arg1 & 0x7FFF;
        var_s1 = (arg1 >> 16) & 0x7FFF;
    } else {
        var_s1 = arg1;
        var_s4 = arg1;
    }

    ret = nfalse;
    if ((arg0 >= 0) && (arg0 < gnScreenCount)) {
        for (i = 0; i < gaScreen[arg0].unk_0C; i++) {
            struct_gaScreen_unk_1C *temp_a0_2 = &gaScreen[arg0].unk_1C[i];

            if ((temp_a0_2->unk_00 >= var_s4) && (var_s1 >= temp_a0_2->unk_00)) {
                temp_a0_2->unk_44 |= 0x400;
                if (temp_a0_2->unk_44 & 0x100000) {
                    screenHideImage(arg0, temp_a0_2->unk_1A);
                }

                ret = ntrue;
                if (var_s4 == var_s1) {
                    break;
                }
            }
        }
    }

    return ret;
}

nbool screenShowText(s32 arg0, s32 arg1) {
    s32 var_s3;
    s32 var_s4;
    s32 ret;

    if ((arg1 != 0xFFFFFFFF) && CHECK_FLAG_ALL(arg1, 0x80008000)) {
        var_s4 = arg1 & 0x7FFF;
        var_s3 = (arg1 >> 16) & 0x7FFF;
    } else {
        var_s4 = var_s3 = arg1;
    }

    ret = nfalse;
    if ((arg0 >= 0) && (arg0 < gnScreenCount)) {
        s32 var_s2;

        for (var_s2 = 0; var_s2 < gaScreen[arg0].unk_0C; var_s2++) {
            struct_gaScreen_unk_1C *temp_a1 = &gaScreen[arg0].unk_1C[var_s2];

            if ((temp_a1->unk_00 >= var_s4) && (var_s3 >= temp_a1->unk_00)) {
                temp_a1->unk_44 &= ~0x400;
                temp_a1->unk_38 = 0;
                temp_a1->unk_10 = 0;
                temp_a1->unk_48 &= ~0xF0000000;

                B_8018E554_usa = 0;
                B_8018E4FC_usa = B_8018E500_usa;
                if (temp_a1->unk_44 & 0x100000) {
                    screenShowImage(arg0, temp_a1->unk_1A);
                }

                ret = ntrue;
                if (var_s4 == var_s3) {
                    break;
                }
            }
        }
    }

    return ret;
}

#if VERSION_USA
s32 func_8002801C_usa(void) {
    s32 old = B_8018E554_usa;

    B_8018E554_usa = 0;
    return old;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80028034_usa);
#endif

// Not present on ROM?
STATIC_INLINE nbool inlined_func2(s32 arg0, s32 arg1, struct_gaScreen_unk_20 **arg2) {
    s32 i;

    if ((arg1 != -1) && (arg0 >= 0) && (arg0 < gnScreenCount)) {
        for (i = 0; i < gaScreen[arg0].unk_10; i++) {
            if (gaScreen[arg0].unk_20[i].unk_1C == arg1) {
                *arg2 = &gaScreen[arg0].unk_20[i];
                return ntrue;
            }
        }
    }

    return nfalse;
}

#if VERSION_USA
nbool func_800282AC_usa(s32 arg0, s32 arg1) {
    struct_gaScreen_unk_20 *sp0;

    if (inlined_func2(arg0, arg1, &sp0)) {
        return (sp0->unk_24 & 4) ? ntrue : nfalse;
    }
    return nfalse;
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028164_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002817C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028414_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800280D4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800280EC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80028384_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002815C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80028174_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002840C_ger);
#endif

nbool screenHideImage(s32 arg0, s32 arg1) {
    nbool ret;
    s32 var_s1;
    s32 i;
    s32 var_s4;

    if ((arg1 != 0xFFFFFFFF) && CHECK_FLAG_ALL(arg1, 0xC0000000)) {
        var_s4 = arg1 & 0x3FFFFFFF;
        var_s1 = 0x10000;
    } else if ((arg1 != 0xFFFFFFFF) && CHECK_FLAG_ALL(arg1, 0x80008000)) {
        var_s4 = arg1 & 0x7FFF;
        var_s1 = (arg1 >> 0x10) & 0x7FFF;
    } else {
        var_s1 = arg1;
        var_s4 = arg1;
    }

    ret = nfalse;
    if ((arg0 >= 0) && (arg0 < gnScreenCount)) {
        for (i = 0; i < gaScreen[arg0].unk_10; i++) {
            struct_gaScreen_unk_20 *temp_v1 = &gaScreen[arg0].unk_20[i];

            if ((temp_v1->unk_1C >= var_s4) && (var_s1 >= temp_v1->unk_1C)) {
                temp_v1->unk_24 |= 4;

                if (temp_v1->unk_20 != -1) {
                    screenHideImage(arg0, temp_v1->unk_20);
                }

                ret = ntrue;
                if (var_s4 == var_s1) {
                    break;
                }
            }
        }
    }

    return ret;
}

nbool screenShowImage(s32 arg2, s32 arg1) {
    nbool ret;
    s32 i;
    s32 var_s3;
    s32 var_s4;

    if ((arg1 != 0xFFFFFFFF) && CHECK_FLAG_ALL(arg1, 0x80008000)) {
        var_s4 = arg1 & 0x7FFF;
        var_s3 = (arg1 >> 0x10) & 0x7FFF;
    } else {
        var_s4 = var_s3 = arg1;
    }

    ret = nfalse;
    if ((arg2 >= 0) && (arg2 < gnScreenCount)) {
        for (i = 0; i < gaScreen[arg2].unk_10; i++) {
            struct_gaScreen_unk_20 *temp_a1 = &gaScreen[arg2].unk_20[i];

            if ((temp_a1->unk_1C >= var_s4) && (var_s3 >= temp_a1->unk_1C)) {
                temp_a1->unk_24 &= ~4;
                if (!(temp_a1->unk_24 & 0x80)) {
                    temp_a1->unk_08 = 0;
                }

                if (temp_a1->unk_20 != -1) {
                    screenShowImage(arg2, temp_a1->unk_20);
                }

                ret = ntrue;
                if (var_s4 == var_s3) {
                    break;
                }
            }
        }
    }

    return ret;
}

nbool func_8002864C_usa(s32 arg0, s32 arg1, struct_gaScreen_unk_20_unk_14 **arg2) {
    struct_gaScreen_unk_20 *sp0;

    if (inlined_func2(arg0, arg1, &sp0)) {
        *arg2 = sp0->unk_14;

        if (*arg2 != NULL) {
            return ntrue;
        }
        return nfalse;
    }
    return nfalse;
}

#if VERSION_USA
nbool func_80028718_usa(s32 arg0, s32 arg1, f32 arg2) {
    struct_gaScreen_unk_20 *sp10;

    if (inlined_func2(arg0, arg1, &sp10)) {
        sp10->unk_10 = arg2;

        if (sp10->unk_20 != -1) {
            func_80028718_usa(arg0, sp10->unk_20, arg2);
        }
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_USA
nbool func_8002880C_usa(s32 arg0, s32 arg1, f32 *arg2) {
    struct_gaScreen_unk_20 *sp0;

    if (inlined_func2(arg0, arg1, &sp0)) {
        *arg2 = sp0->unk_10;

        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028880_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028974_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800287F0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800288E4_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80028878_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002896C_ger);
#endif

nbool func_800288D8_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct_gaScreen_unk_20 *sp10;

    if (inlined_func2(arg0, arg1, &sp10)) {
        sp10->unk_00 = arg2;
        sp10->unk_04 = arg3;

        if (sp10->unk_20 != -1) {
            func_800288D8_usa(arg0, sp10->unk_20, arg2, arg3);
        }
        return ntrue;
    }
    return nfalse;
}

nbool func_800289C0_usa(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    struct_gaScreen_unk_20 *sp0;

    if (inlined_func2(arg0, arg1, &sp0)) {
        *arg2 = sp0->unk_00;
        *arg3 = sp0->unk_04;
        return ntrue;
    }
    return nfalse;
}

#if VERSION_USA
nbool func_80028A98_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct_gaScreen_unk_18 *sp0;

    if (inlined_func(arg0, arg1, &sp0)) {
        if (sp0->unk_2C & 0x1000) {
            s32 temp_a0 = (sp0->unk_34 * arg3) + arg2;

            sp0->unk_38[temp_a0 >> 3] &= ~(1 << (temp_a0 & 7));
            return ntrue;
        }
    }

    return nfalse;
}
#endif

#if VERSION_USA
nbool func_80028BAC_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct_gaScreen_unk_18 *sp0;

    if (inlined_func(arg0, arg1, &sp0)) {
        if (sp0->unk_2C & 0x1000) {
            s32 temp_a0 = (sp0->unk_34 * arg3) + arg2;

            sp0->unk_38[temp_a0 >> 3] |= 1 << (temp_a0 & 7);
            return ntrue;
        }
    }
    return nfalse;
}
#endif

#if VERSION_USA
nbool func_80028CBC_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct_gaScreen_unk_18 *sp0;

    if (inlined_func(arg0, arg1, &sp0)) {
        if ((sp0->unk_2C & 0x1000)) {
            s32 temp_v1 = (sp0->unk_34 * arg3) + arg2;

            if (((sp0->unk_38[temp_v1 >> 3]) >> (temp_v1 & 7)) & 1) {
                return ntrue;
            }
            return nfalse;
        }
    }
    return nfalse;
}
#endif

#if VERSION_USA
void func_80028DC0_usa(s32 arg0, s32 arg1, s32 arg2) {
    struct_gaScreen_unk_20 *sp0;

    if (inlined_func2(arg0, arg1, &sp0)) {
        sp0->unk_08 = arg2;
    }
}
#endif

#if VERSION_USA
void func_80028E80_usa(s32 arg0, s32 arg1, s32 *arg2) {
    struct_gaScreen_unk_20 *sp0;

    if (inlined_func2(arg0, arg1, &sp0)) {
        *arg2 = sp0->unk_08;
    }
}
#endif

#if VERSION_USA
void screenSetText(s32 arg0, s32 arg1, u16 *arg2) {
    struct_gaScreen_unk_1C *sp10;

    if (screenFindImage(arg0, arg1, &sp10) != 0) {
        s32 var_a1 = 0;

        while ((*arg2 != 0) && (var_a1 < sp10->unk_20)) {
            if (((sp10->unk_50[var_a1] >> 0xA) == 0) && ((sp10->unk_50[var_a1] & 0x3FF) == 2)) {
                var_a1++;
            } else {
                sp10->unk_50[var_a1] = *arg2++;
                var_a1++;
            }
        }

        if (((sp10->unk_50[var_a1] >> 0xA) == 0) && (sp10->unk_50[var_a1] & 0x3FF) == 2) {
            var_a1++;
        }

        if (var_a1 < sp10->unk_20) {
            sp10->unk_50[var_a1] = 0;
        }

        if (sp10->unk_44 & 0x808000) {
            screenCenterText(sp10);
            if ((giScreen >= 0) && (giScreen < gnScreenCount)) {
                if (gaScreen[giScreen].unk_08 > 0) {
                    screenUpdateArea(gaScreen[giScreen].unk_18);
                }
            }
        }
    }
}
#endif

#if VERSION_USA
INLINE void func_80029130_usa(s32 arg0, s32 arg1, u16 *arg2, s32 arg3) {
    struct_gaScreen_unk_1C *sp0;

    if (screenFindImage(arg0, arg1, &sp0)) {
        s32 i;

        for (i = 0; (i < sp0->unk_20) && (i < arg3); i++) {
            arg2[i] = sp0->unk_50[i];
        }
        arg2[i] = 0;
    }
}
#endif

#if VERSION_USA
nbool func_80029244_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct_gaScreen_unk_1C *sp0;

    if (screenFindImage(arg0, arg1, &sp0)) {
        *sp0->unk_64 = arg2;
        *sp0->unk_68 = arg3;
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_USA
nbool func_8002931C_usa(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    struct_gaScreen_unk_1C *sp0;

    if (screenFindImage(arg0, arg1, &sp0)) {
        *arg2 = *sp0->unk_64;
        *arg3 = *sp0->unk_68;
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028C00_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028D14_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028E24_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028F28_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028FE8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_800290AC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029298_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_800293AC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029484_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80028B70_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80028C84_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80028D94_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80028E98_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80028F58_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002901C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80029208_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002931C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800293F4_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80028BF8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80028D0C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80028E1C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80028F20_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80028FE0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_800290A4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80029290_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_800293A4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002947C_ger);
#endif

nbool screenGetTextType(s32 arg0, s32 arg1, u32 *arg2) {
    struct_gaScreen_unk_1C *sp0;

    if (screenFindImage(arg0, arg1, &sp0)) {
        *arg2 = sp0->unk_44;
        return ntrue;
    }
    return nfalse;
}

#if VERSION_USA
nbool func_800294C8_usa(s32 arg0, s32 arg1, s32 *arg2) {
    struct_gaScreen_unk_1C *sp0;

    if (screenFindImage(arg0, arg1, &sp0)) {
        *arg2 = sp0->unk_20;
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_USA
void func_80029594_usa(s32 arg0, s32 arg1, s32 arg2) {
    u16 sp10[0x40];

    func_80029130_usa(arg0, arg2, sp10, ARRAY_COUNT(sp10));
    screenSetText(arg0, arg1, sp10);
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029630_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_800296FC_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800295A0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002966C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80029628_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_800296F4_ger);
#endif

char D_800B6410_usa[] = {
    '!', '&', '(', ')', '_', '-', '+', '=', '\\', ';', ':', '"', '\'', '.', ',', '?', '/',
};

void func_800296B0_usa(u16 *dst, char *src, s32 dstLen) {
    s32 i;

    for (i = 0; (src[i] != '\0') && (i < dstLen); i++) {
        if (src[i] == '0') {
            dst[i] = 0xA | 0x1400;
        } else if ((src[i] >= '1') && (src[i] <= '9')) {
            dst[i] = ((src[i] + 1 - '1') & 0x3FF) | 0x1400;
        } else if ((src[i] >= 'A') && (src[i] <= 'Z')) {
            dst[i] = ((src[i] - 'A' + 1) & 0x3FF) | 0x1800;

#if VERSION_FRA
            if (src[i] >= 'D') {
                dst[i]++;
            }
#elif VERSION_GER
            if (src[i] >= 'V') {
                dst[i]++;
            }
            if (src[i] >= 'T') {
                dst[i]++;
            }
            if (src[i] >= 'P') {
                dst[i]++;
            }
            if (src[i] >= 'B') {
                dst[i]++;
            }
#endif
        } else if ((src[i] >= 'a') && (src[i] <= 'z')) {
            dst[i] = ((src[i] - 'a' + 1) & 0x3FF) | 0x1800;

#if VERSION_FRA
            if (src[i] >= 'd') {
                dst[i]++;
            }
#elif VERSION_GER
            if (src[i] >= 'v') {
                dst[i]++;
            }
            if (src[i] >= 't') {
                dst[i]++;
            }
            if (src[i] >= 'p') {
                dst[i]++;
            }
            if (src[i] >= 'b') {
                dst[i]++;
            }
#endif
        } else {
            s32 j;

            for (j = 0; j < ARRAY_COUNTU(D_800B6410_usa); j++) {
                if (src[i] == D_800B6410_usa[j]) {
                    dst[i] = ((j + 1) & 0x3FF) | 0x1000;
                    break;
                }
            }

            if (j == ARRAY_COUNTU(D_800B6410_usa)) {
                dst[i] = 1;
            }
        }
    }

    dst[i] = 0;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_800297C8_usa);
#endif

#if VERSION_USA
nbool func_80029980_usa(s32 arg0, s32 arg1, s32 arg2) {
    struct_gaScreen_unk_1C *sp0;

    if (screenFindImage(arg0, arg1, &sp0)) {
        sp0->unk_0C = arg2;
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_USA
nbool func_80029A44_usa(s32 arg0, s32 arg1, s32 *arg2) {
    struct_gaScreen_unk_1C *sp0;

    if (screenFindImage(arg0, arg1, &sp0)) {
        *arg2 = sp0->unk_0C;
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_USA
nbool func_80029B10_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct_gaScreen_unk_1C *sp10;

    if (screenFindImage(arg0, arg1, &sp10)) {
        sp10->unk_04 = arg2;
        sp10->unk_08 = arg3;
        if (sp10->unk_44 & 0x808000) {
            screenCenterText(sp10);
            if ((giScreen >= 0) && (giScreen < gnScreenCount)) {
                if (gaScreen[giScreen].unk_08 > 0) {
                    screenUpdateArea(gaScreen[giScreen].unk_18);
                }
            }
        }
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_USA
nbool func_80029C4C_usa(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    struct_gaScreen_unk_1C *sp0;

    if (screenFindImage(arg0, arg1, &sp0)) {
        *arg2 = sp0->unk_04;
        *arg3 = sp0->unk_08;
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_USA
void func_80029D24_usa(s32 arg0, s32 arg1) {
    s32 var_s2;
    s32 var_v1;
    struct_gaScreen *temp_s0;
    struct_gaScreen_unk_24 *var_s3;

    if ((arg0 < 0) || (arg0 >= gnScreenCount)) {
        return;
    }

    temp_s0 = &gaScreen[arg0];

    for (var_v1 = 0; var_v1 < temp_s0->unk_14; var_v1++) {
        var_s3 = &temp_s0->unk_24[var_v1];
        if (var_s3->unk_00 == arg1) {
            break;
        }
    }

    if (var_v1 == temp_s0->unk_14) {
        return;
    }

    var_s3->unk_2C &= ~0x40;
    for (var_s2 = 0; var_s2 < temp_s0->unk_08; var_s2++) {
        if ((var_s3->unk_2C & 0x20) && (var_s3->unk_18 == temp_s0->unk_18[var_s2].unk_1C)) {
            temp_s0->unk_18[var_s2].unk_2C |= 0x800;
            temp_s0->unk_28[0] = temp_s0->unk_30[0];
            temp_s0->unk_28[1] = temp_s0->unk_30[1];
            screenUpdateArea(&temp_s0->unk_18[var_s2]);
        } else {
            temp_s0->unk_18[var_s2].unk_2C &= ~0x800;
        }
    }

    if (var_s3->unk_2C & 0x10) {
        s32 var_a1;

        for (var_a1 = 0; var_a1 < temp_s0->unk_0C; var_a1++) {
            if (temp_s0->unk_1C[var_a1].unk_00 == var_s3->unk_1C) {
                temp_s0->unk_1C[var_a1].unk_44 |= 0x400;
            }
        }
    }
}
#endif

#if VERSION_USA
void func_80029EC4_usa(s32 arg0, s32 arg1) {
    s32 var_a1;
    s32 var_s2;
    s32 var_v1;
    struct_gaScreen *temp_s0;
    struct_gaScreen_unk_24 *var_s3;

    if ((arg0 < 0) || (arg0 >= gnScreenCount)) {
        return;
    }

    temp_s0 = &gaScreen[arg0];

    for (var_v1 = 0; var_v1 < temp_s0->unk_14; var_v1++) {
        var_s3 = &temp_s0->unk_24[var_v1];
        if (var_s3->unk_00 == arg1) {
            break;
        }
    }

    if (var_v1 == temp_s0->unk_14) {
        return;
    }

    var_s3->unk_14 = 0;
    var_s3->unk_2C |= 0x40;

    for (var_s2 = 0; var_s2 < temp_s0->unk_08; var_s2++) {
        if ((var_s3->unk_2C & 0x20) && (var_s3->unk_18 == temp_s0->unk_18[var_s2].unk_1C)) {
            temp_s0->unk_18[var_s2].unk_2C &= ~0x800;
            temp_s0->unk_30[0] = temp_s0->unk_28[0];
            temp_s0->unk_30[1] = temp_s0->unk_28[1];
            temp_s0->unk_28[1] = var_s2;
            temp_s0->unk_28[0] = var_s2;
            screenUpdateArea(&temp_s0->unk_18[var_s2]);
        } else {
            ;
            temp_s0->unk_18[var_s2].unk_2C |= 0x800;
        }
    }

    if (var_s3->unk_2C & 0x10) {
        for (var_a1 = 0; var_a1 < temp_s0->unk_0C; var_a1++) {
            if (temp_s0->unk_1C[var_a1].unk_00 == var_s3->unk_1C) {
                temp_s0->unk_1C[var_a1].unk_44 &= ~0x400;
            }
        }
    }
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029930_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029AE8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029BAC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029C78_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029DB4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029E8C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002A02C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800298C4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80029A7C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80029B40_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80029C0C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80029D48_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80029E20_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80029FC0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_800299FC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80029BB4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80029C78_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80029D44_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80029E80_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_80029F58_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002A0F8_ger);
#endif

void screenSetNumber(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char sp10[0x40];
    struct_gaScreen_unk_1C *sp50;

    if (screenFindImage(arg0, arg1, &sp50)) {
        s32 var_a2;
        s32 var_t1_2;
        s32 temp;

        sprintf(sp10, "%d", arg2);

        var_t1_2 = 0;
        while (sp10[var_t1_2] != 0) {
            var_t1_2 += 1;
        }

        temp = 0;
        for (var_a2 = 0; var_a2 < sp50->unk_20; var_a2++) {
            s32 var_a1 = (arg3 != 0) ? 0xA : 0;

            if ((var_t1_2 + var_a2) >= sp50->unk_20) {
                var_a1 = sp10[temp++] - 0x30;
                if (var_a1 == 0) {
                    var_a1 = 0xA;
                }
            }

            sp50->unk_50[var_a2] &= 0xFC00;
            sp50->unk_50[var_a2] |= var_a1 & 0x3FF;
        }
    }
}

#if VERSION_USA
void func_8002A1F4_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    struct_gaScreen_unk_18 *sp10;

    if ((arg2 < 0) || (arg3 < 0)) {
        return;
    }

    if (inlined_func(arg0, arg1, &sp10)) {
        if (func_800255D8_usa(sp10, arg2, arg3, 0)) {
            screenUpdateArea(sp10);
        }
    }
}
#endif

#if VERSION_USA
void func_8002A2E8_usa(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    struct_gaScreen_unk_18 *sp0;

    if (inlined_func(arg0, arg1, &sp0)) {
        *arg2 = sp0->unk_3C;
        *arg3 = sp0->unk_40;
    }
}
#endif

#if VERSION_USA
void func_8002A3B8_usa(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    struct_gaScreen_unk_18 *sp0;

    if (inlined_func(arg0, arg1, &sp0)) {
        *arg2 = sp0->unk_44;
        *arg3 = sp0->unk_48;
    }
}
#endif

#if VERSION_USA
nbool func_8002A488_usa(s32 arg0, s32 arg1) {
    if ((arg0 >= 0) && (arg0 < gnScreenCount)) {
        if (gaScreen[arg0].unk_28[0] != -1) {
            struct_gaScreen_unk_18 *temp_a0 = &gaScreen[arg0].unk_18[gaScreen[arg0].unk_28[0]];

            temp_a0->unk_20 = arg1;
            temp_a0->unk_2C |= 0x2000;
            return ntrue;
        }
    }
    return nfalse;
}
#endif

#if VERSION_USA
nbool func_8002A4FC_usa(s32 arg0, s32 *arg1) {
    *arg1 = -1;

    if ((arg0 >= 0) && (arg0 < gnScreenCount)) {
        if (gaScreen[arg0].unk_28[0] != -1) {
            struct_gaScreen_unk_18 *temp_v1_2 = &gaScreen[arg0].unk_18[gaScreen[arg0].unk_28[0]];

            if (temp_v1_2->unk_2C & 0x2000) {
                *arg1 = temp_v1_2->unk_20;
                return ntrue;
            }
        }
    }
    return nfalse;
}
#endif

#if VERSION_USA
// Not present on ROM?
STATIC_INLINE nbool inlined_func3(s32 arg0, s32 arg1, struct_gaScreen_unk_24 **arg2) {
    s32 i;

    if ((arg1 != -1) && (arg0 >= 0) && (arg0 < gnScreenCount)) {
        for (i = 0; i < gaScreen[arg0].unk_14; i++) {
            if (gaScreen[arg0].unk_24[i].unk_00 == arg1) {
                *arg2 = &gaScreen[arg0].unk_24[i];
                return ntrue;
            }
        }
    }

    return nfalse;
}
#endif

#if VERSION_USA
nbool func_8002A574_usa(s32 arg0, s32 arg1, s32 arg2) {
    struct_gaScreen_unk_24 *sp0;

    if (inlined_func3(arg0, arg1, &sp0)) {
        sp0->unk_14 = arg2;
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_USA
nbool func_8002A638_usa(s32 arg0, s32 arg1, s32 *arg2) {
    struct_gaScreen_unk_24 *sp0;

    if (inlined_func3(arg0, arg1, &sp0)) {
        if (arg2 != NULL) {
            *arg2 = sp0->unk_14;
        }
        return ntrue;
    }
    return nfalse;
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002A35C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002A450_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002A520_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002A5F0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002A664_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002A6DC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002A7A0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002A2F0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002A3E4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002A4B4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002A584_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002A5F8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002A670_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002A734_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002A428_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002A51C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002A5EC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002A6BC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002A730_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002A7A8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/screen", func_8002A86C_ger);
#endif

nbool screenFind(s32 *dst, const char *arg1) {
    s32 i;

    for (i = 0; i < gnScreenCount; i++) {
        struct_gaScreen *var = &gaScreen[i];
        char *var_a3 = var->unk_00;
        s32 j;
        nbool var_v0;

        j = 0;
        while (var_a3[j] != '\0') {
            s32 var_a2;
            s32 var_v1;

            var_a2 = var_a3[j];
            if (is_lower(var_a2)) {
                var_a2 -= ('a' - 'A');
            }
            var_v1 = arg1[j];
            if (is_lower(var_v1)) {
                var_v1 -= ('a' - 'A');
            }

            if (var_a2 != var_v1) {
                var_v0 = nfalse;
                goto label;
            }
            j++;
        }

        if (arg1[j] == '\0') {
            var_v0 = ntrue;
        } else {
            var_v0 = nfalse;
        }

    label:
        if (var_v0) {
            *dst = i;
            return ntrue;
        }
    }

    return nfalse;
}

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
    giScreen = -1;
    gnImageCount = 0;
    gnScreenCount = 0;
    var_s7 = 0;
    screenWipeImages();
#if REGION_NTSC
    B_8018E558_usa = 8;
#else
    B_8018E558_usa = 6;
#endif
    geModeFade = 0;
    gnAlphaFade = (gnAlphaFade != -1) ? 0xFF : 0;

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

                for (var_s0_2 = 0; var_s0_2 < ((temp_s1->unk_30 * temp_s1->unk_34 + 7) >> 3); var_s0_2++) {
                    temp_s1->unk_38[var_s0_2] = 0xFF;
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

#if VERSION_USA
            for (var_s0_2 = 0; var_s0_2 < temp_s1_2->unk_20; var_s0_2++) {
                if (temp_s1_2->unk_50[var_s0_2] == 0) {
                    osSyncPrintf("screenLoad: TEXT has internal NULL-character (offset=%d)\n", var_s0_2);
                }
            }
#endif

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
            fileGet(&sp10, &temp_s0->unk_24, sizeof(temp_s0->unk_24));
            fileGet(&sp10, &temp_s0->unk_00, sizeof(temp_s0->unk_00));
            fileGet(&sp10, &temp_s0->unk_04, sizeof(temp_s0->unk_04));
            fileGet(&sp10, &temp_s0->unk_08, sizeof(temp_s0->unk_08));
            fileGet(&sp10, &temp_s0->unk_1C, sizeof(temp_s0->unk_1C));
            fileGet(&sp10, &temp_s0->unk_20, sizeof(temp_s0->unk_20));
            fileGet(&sp10, &temp_s0->unk_0C, sizeof(temp_s0->unk_0C));

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

#if VERSION_EUR || VERSION_FRA || VERSION_GER
// hack to ensure correct alignment of rodata
static const f64 sFileBumpRodataAlignment UNUSED = 0;
#endif

void screenSetup(void) {
    /*
    The remaining zero'd values should be one of those:

    gbKillPeel = 0;
    gnFrameSkip = 0;
    gnImageCount = 0;
    gnScreenCount = 0;
    gnFrameCount = 0;
    geModeFade = 0;
    */
    B_8018E504_usa = 0;
    gnImageCount = 0;
    gnScreenCount = 0;
    B_8018E540_usa = 0;
    B_8018E530_usa = 0;
    geModeFade = 0;

    gnAlphaFade = -1;
    B_8018E524_usa = -1;
    giScreen = -1;
}

void func_8002B5C4_usa(void) {
}
