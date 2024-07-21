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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", func_80022AF4_usa);
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
s32 screenFlushing(void) {
    if ((B_8018E504_usa != 0) || (B_8018E524_usa != -1)) {
        return -1;
    }
    return 0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenDraw);
#endif

#if VERSION_USA
INLINE s32 screenFindImage(s32 arg0, s32 arg1, struct_gaScreen_unk_1C **arg2) {
    s32 var_t0;

    if ((arg1 != -1) && (arg0 >= 0) && (arg0 < gnScreenCount)) {
        for (var_t0 = 0; var_t0 < gaScreen[arg0].unk_0C; var_t0++) {
            if (gaScreen[arg0].unk_1C[var_t0].unk_00 == arg1) {
                *arg2 = &gaScreen[arg0].unk_1C[var_t0];
                return -1;
            }
        }
    }
    return 0;
}
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
INCLUDE_ASM("asm/usa/nonmatchings/main/screen", screenTick);
#endif

#if VERSION_USA
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

    if (screenFind(&sp10, arg0) != 0) {
        s32 temp;

        if ((geModeFade == 1) || (geModeFade == 3)) {
            return giScreen;
        }

        // ?
        if ((u32)(geModeFade - 2) < 2U) {
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
#endif

#if VERSION_USA
s32 screenGet(void) {
    return giScreen;
}
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
// screenGetArea?
INLINE s32 func_800276CC_usa(s32 arg0, UNK_TYPE4 *arg1, s32 arg2) {
    if (arg2 < GASCREEN_UNK_28_LEN) {
        if ((arg0 >= 0) && (arg0 < gnScreenCount)) {
            s32 var_a0 = gaScreen[arg0].unk_28[arg2];

            if (var_a0 == -1) {
                var_a0 = gaScreen[arg0].unk_30[arg2];
            }

            if ((var_a0 >= 0) && (var_a0 < gaScreen[arg0].unk_08)) {
                *arg1 = gaScreen[arg0].unk_18[var_a0].unk_1C;
                return -1;
            }
        }
    }

    return 0;
}
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
s32 screenHideText(s32 arg0, s32 arg1) {
    s32 var_a1;
    s32 var_s1;
    s32 i;
    s32 var_s4;

    if ((arg1 != -1) && ((arg1 & 0xC0000000) == 0xC0000000)) {
        var_s4 = arg1 & 0x3FFFFFFF;
        var_s1 = 0x10000;
    } else if ((arg1 != -1) && ((arg1 & 0x80008000) == 0x80008000)) {
        var_s4 = arg1 & 0x7FFF;
        var_s1 = (arg1 >> 0x10) & 0x7FFF;
    } else {
        var_s1 = arg1;
        var_s4 = arg1;
    }

    var_a1 = 0;
    if ((arg0 >= 0) && (arg0 < gnScreenCount)) {
        for (i = 0; i < gaScreen[arg0].unk_0C; i++) {
            struct_gaScreen_unk_1C *temp_a0_2 = &gaScreen[arg0].unk_1C[i];

            if ((temp_a0_2->unk_00 >= var_s4) && (var_s1 >= temp_a0_2->unk_00)) {
                temp_a0_2->unk_44 |= 0x400;
                if (temp_a0_2->unk_44 & 0x100000) {
                    screenHideImage(arg0, temp_a0_2->unk_1A);
                }

                var_a1 = -1;
                if (var_s4 == var_s1) {
                    break;
                }
            }
        }
    }

    return var_a1;
}
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
s32 screenHideImage(s32 arg0, s32 arg1) {
    s32 var_a1;
    s32 var_s1;
    s32 i;
    s32 var_s4;

    if ((arg1 != -1) && ((arg1 & 0xC0000000) == 0xC0000000)) {
        var_s4 = arg1 & 0x3FFFFFFF;
        var_s1 = 0x10000;
    } else if ((arg1 != -1) && ((arg1 & 0x80008000) == 0x80008000)) {
        var_s4 = arg1 & 0x7FFF;
        var_s1 = (arg1 >> 0x10) & 0x7FFF;
    } else {
        var_s1 = arg1;
        var_s4 = arg1;
    }

    var_a1 = 0;
    if ((arg0 >= 0) && (arg0 < gnScreenCount)) {
        for (i = 0; i < gaScreen[arg0].unk_10; i++) {
            struct_gaScreen_unk_20 *temp_v1 = &gaScreen[arg0].unk_20[i];

            if ((temp_v1->unk_1C >= var_s4) && (var_s1 >= temp_v1->unk_1C)) {
                temp_v1->unk_24 |= 4;

                if (temp_v1->unk_20 != -1) {
                    screenHideImage(arg0, temp_v1->unk_20);
                }
                var_a1 = -1;
                if (var_s4 == var_s1) {
                    break;
                }
            }
        }
    }

    return var_a1;
}
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
char D_800B6410_usa[] = {
    '!', '&', '(', ')', '_', '-', '+', '=', '\\', ';', ':', '"', '\'', '.', ',', '?', '/',
};

void func_800296B0_usa(u16 *dst, const char *src, s32 dstLen) {
    s32 i;

    for (i = 0; (src[i] != '\0') && (i < dstLen); i++) {
        if (src[i] == '0') {
            dst[i] = 0xA | 0x1400;
        } else if ((src[i] >= '1') && (src[i] <= '9')) {
            dst[i] = ((src[i] - '1' + 1) & 0x3FF) | 0x1400;
        } else if ((src[i] >= 'A') && (src[i] <= 'Z')) {
            dst[i] = ((src[i] - 'A' + 1) & 0x3FF) | 0x1800;
        } else if ((src[i] >= 'a') && (src[i] <= 'z')) {
            dst[i] = ((src[i] - 'a' + 1) & 0x3FF) | 0x1800;
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
s32 screenFind(s32 *dst, const char *arg1) {
    s32 i;

    for (i = 0; i < gnScreenCount; i++) {
        struct_gaScreen *var = &gaScreen[i];
        char *var_a3 = var->unk_00;
        s32 j;
        s32 var_v0;

        j = 0;
        while (var_a3[j] != '\0') {
            s32 var_a2;
            s32 var_v1;

            var_a2 = var_a3[j];
            if (var_a2 >= 'a' && var_a2 <= 'z') {
                var_a2 -= ('a' - 'A');
            }
            var_v1 = arg1[j];
            if (var_v1 >= 'a' && var_v1 <= 'z') {
                var_v1 -= ('a' - 'A');
            }

            if (var_a2 != var_v1) {
                var_v0 = 0;
                goto label;
            }
            j++;
        }

        if (arg1[j] == '\0') {
            var_v0 = -1;
        } else {
            var_v0 = 0;
        }

    label:
        if (var_v0 != 0) {
            *dst = i;
            return -1;
        }
    }

    return 0;
}
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
    giScreen = -1;
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
    giScreen = -1;
}
#endif

#if VERSION_USA
void func_8002B5C4_usa(void) {
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80022400_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80022964_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80022C04_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80023978_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80023FDC_eur);
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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80024D3C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80024D5C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenFlushing);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenDraw);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80025674_eur);
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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenTick);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenSet);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenGet);
#endif

#if VERSION_EUR
void func_800276E4_eur(void) {
}
#endif

#if VERSION_EUR
void func_800276EC_eur(void) {
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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027C1C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027C3C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027D4C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027E54_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80027FC8_eur);
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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_800284E0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002864C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_800287B4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028880_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028974_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028A40_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80028B28_eur);
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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029564_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029630_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_800296FC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_80029818_eur);
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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002A074_usa);
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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", func_8002A870_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenLoad);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/screen", screenSetup);
#endif

#if VERSION_EUR
void func_8002B6E8_eur(void) {
}
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80022410_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800228D4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80022B74_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800238E8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80023F4C_fra);
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

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80024CAC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80024CCC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", screenFlushing);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80024D0C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800255E4_fra);
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

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80026354_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027474_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027644_fra);
#endif

#if VERSION_FRA
void func_80027654_fra(void) {
}
#endif

#if VERSION_FRA
void func_8002765C_fra(void) {
}
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

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027B8C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027BAC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027CBC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027DC4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80027F38_fra);
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

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80028450_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800285BC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80028724_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800287F0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800288E4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800289B0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80028A98_fra);
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

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800294D4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_800295A0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002966C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_80029788_fra);
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

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002A170_fra);
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

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002A804_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002A8D0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", screenSetup);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/screen", func_8002B67C_fra);
#endif
