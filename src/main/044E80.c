#include "044E80.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "hvqm2util.h"
#include "image.h"
#include "screen.h"
#include "sfxlimit.h"
#include "sound.h"
#include "story.h"
#include "the_game.h"
#include "update.h"

typedef struct struct_80192FB0_unk_0028 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
} struct_80192FB0_unk_0028; // size = 0x28

#define STRUCT_80192FB0_UNK_0028_COUNT 0x80

typedef struct struct_80192FB0 {
    /* 0x0000 */ s32 unk_0000;
    /* 0x0004 */ u32 unk_0004;
    /* 0x0008 */ struct_imageLoad_arg0 *unk_0008[2];
    /* 0x0010 */ s32 unk_0010;
    /* 0x0014 */ s32 unk_0014;
    /* 0x0018 */ s32 unk_0018;
    /* 0x001C */ s32 unk_001C;
    /* 0x0020 */ s32 unk_0020;
    /* 0x0024 */ s32 unk_0024;
    /* 0x0028 */ struct_80192FB0_unk_0028 unk_0028[STRUCT_80192FB0_UNK_0028_COUNT];
    /* 0x1428 */ s32 unk_1428; // accessed indirectly
} struct_80192FB0; // size = 0x142C

extern RomOffset D_800B6950_usa[];
extern struct_80192FB0 *B_80192FB0_usa;
extern s32 D_800B6990_usa[];

#if VERSION_USA || VERSION_EUR
#define UNKNOWN_VALUE 0x1F4
#elif VERSION_FRA || VERSION_GER
#define UNKNOWN_VALUE 0xBB8
#endif

void func_80044280_usa(s32 arg0, struct_80192FB0_unk_0028 *arg1) {
    s32 var_s2;
    struct_80192FB0_unk_0028 *var_s0;

    if (arg0 % 8 == 0) {
        if (osGetCount() & 1) {
            if (osGetCount() & 4) {
                if (arg1->unk_00 < 8) {
                    arg1->unk_00++;
                }
            } else {
                if (arg1->unk_00 > -8) {
                    arg1->unk_00--;
                }
            }
        }
    }

    for (var_s2 = 0; var_s2 < STRUCT_80192FB0_UNK_0028_COUNT; var_s2++) {
        var_s0 = &arg1[var_s2];

        if (var_s0->unk_14 != 0) {
            var_s0->unk_14--;
        } else {
            var_s0->unk_0C += var_s0->unk_10;
            var_s0->unk_08 += var_s0->unk_10;
            if (var_s0->unk_08 >= 0x3C1) {
                var_s0->unk_04 = var_s0->unk_18;
                var_s0->unk_08 = var_s0->unk_1C;
                var_s0->unk_10 = var_s0->unk_20;
                var_s0->unk_14 = var_s0->unk_24;
            }

            if (arg0 % 4 == 0) {
                var_s0->unk_04 += arg1->unk_00;
            }

            if ((arg0 % 8 == 0) && (osGetCount() & 1)) {
                if (osGetCount() & 2) {
                    if (var_s0->unk_10 < 8) {
                        var_s0->unk_10++;
                    }
                } else {
                    if (var_s0->unk_10 >= 2) {
                        var_s0->unk_10--;
                    }
                }
            }
        }
    }
}

void func_8004441C_usa(struct_80192FB0_unk_0028 *arg0) {
    u8 sp10[0x10];
    s32 var_s0;
    s32 var_s2;
    s32 var_s3;
    u32 temp_v0;

    arg0->unk_00 = 0;

    for (var_s3 = 0; var_s3 < ARRAY_COUNT(sp10); var_s3++) {
        sp10[var_s3] = 0;
    }

    for (var_s3 = 0; var_s3 < STRUCT_80192FB0_UNK_0028_COUNT; var_s3++) {
        for (var_s2 = 0; var_s2 < 0x40; var_s2++) {
            temp_v0 = osGetCount();
            var_s0 = temp_v0 & 0x7F;
            if (!((sp10[var_s0 >> 3] >> (temp_v0 & 7)) & 1)) {
                break;
            }
        }

        if (var_s2 == 0x40) {
            var_s0 = 0;

            while (var_s0 < 0x80) {
                if (!(((s32) * (sp10 + (var_s0 >> 3)) >> (var_s0 & 7)) & 1)) {
                    break;
                }
                var_s0 += 1;
            }
        }

        var_s2 = var_s0 & 7;
        sp10[var_s0 >> 3] |= 1 << var_s2;

        arg0[var_s3].unk_18 = (var_s0 * 2.5f) * DOUBLE_LITERAL(4.0);
        arg0[var_s3].unk_1C = -0x10 - (osGetCount() & 0xF);
        arg0[var_s3].unk_24 = osGetCount() & 0x7F;

        arg0[var_s3].unk_20 = var_s0 & 3;
        if (arg0[var_s3].unk_20 == 0) {
            arg0[var_s3].unk_20 = 1;
        }
        arg0[var_s3].unk_0C = 0;
        arg0[var_s3 + 1].unk_00 = D_800B6990_usa[var_s2];
        arg0[var_s3].unk_04 = arg0[var_s3].unk_18;
        arg0[var_s3].unk_08 = arg0[var_s3].unk_1C;
        arg0[var_s3].unk_10 = arg0[var_s3].unk_20;
        arg0[var_s3].unk_14 = arg0[var_s3].unk_24;
    }
}

void func_800445D8_usa(Gfx **gfxP, s32 arg1 UNUSED, s32 arg2) {
    DATA_INLINE_CONST2 s32 sp18[] = {
        0x3F, 0x39, 0x4C, 0x42, 0x47, 0x46, 0x51, 0x55, 0x5B, 0x51, 0x91, 0x51, 0x4C, 0x5B, 0xC0, 0x63,
    };
    struct_func_8002156C_usa_arg4 sp58;

    if ((arg2 == UNKNOWN_VALUE) && (B_80192FB0_usa->unk_0014 < 0xF)) {
        sp58.unk_00 = 0;
        sp58.unk_04 = 0xC0 - sp18[B_80192FB0_usa->unk_0014 % 0x10];

        sp58.unk_08 = 0x6C;
        sp58.unk_0C = sp18[B_80192FB0_usa->unk_0014 % 0x10];

        imageDraw(B_80192FB0_usa->unk_0008[B_80192FB0_usa->unk_0010], gfxP, (B_80192FB0_usa->unk_0010 * 0x96) + 0x1F,
                  0x15, &sp58);

        sp58.unk_00 = 0;
        sp58.unk_04 = 0;
        sp58.unk_08 = 0x6C;
        sp58.unk_0C = 0xC0 - sp18[B_80192FB0_usa->unk_0014 % 0x10];

        imageDraw(B_80192FB0_usa->unk_0008[B_80192FB0_usa->unk_0010], gfxP, (B_80192FB0_usa->unk_0010 * 0x96) + 0x1F,
                  sp18[B_80192FB0_usa->unk_0014 % 0x10] + 0x15, &sp58);
    }
}

void func_800447C4_usa(Gfx **gfxP, s32 arg1, s32 arg2);
#if VERSION_USA
#if 0
void func_800447C4_usa(Gfx **gfxP, s32 arg1, s32 arg2) {
    Gfx *temp_a1;
    Gfx *temp_a2;
    Gfx *temp_t0;
    Gfx *temp_t2;
    Gfx *temp_t3;
    Gfx *temp_t8;
    Gfx *temp_t8_2;
    Gfx *temp_t8_3;
    Gfx *temp_t8_4;
    Gfx *temp_t8_5;
    Gfx *temp_v1;
    Gfx *gfx;
    s32 temp_a0_2;
    s32 temp_a1_2;
    s32 temp_a2_2;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_s1;
    struct_80192FB0_unk_0028 *var_t0;
    u32 temp_a0;
    void *temp_t9;
    void *var_t9;

    gfx = *gfxP;
    if (arg2 == 0xC8) {

        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetRenderMode(gfx++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gSPClearGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_SHADING_SMOOTH);

        var_s1 = 0;
        var_t0 = B_80192FB0_usa->unk_0028;
        while (var_s1 < 0x80) {
            var_a1 = var_t0[var_s1].unk_04;
            if (var_a1 < 0) {
                var_a1 += 0x500;
            }
            if (var_a1 >= 0x500) {
                var_a1 -= 0x500;
            }
            var_a3 = var_t0[var_s1].unk_08;
            if (var_a3 < 0) {
                var_a3 += 0x3C0;
            }
            if (var_a3 >= 0x3C0) {
                var_a3 -= 0x3C0;
            }
            var_a2 = ((s32) var_t0[var_s1].unk_0C >> 3) & 7;
            if (var_a2 >= 4) {
                var_a2 = 8 - var_a2;
            }
            temp_a0 = var_t0[var_s1+1].unk_00;

            temp_a1_2 = var_a1 >> 2;
            temp_a2_2 = var_a2 >> 1;
#if 0
            temp_t9 = var_t9 + 8;
            temp_t9->unk_-4 = 0xFA000000;
            temp_t9->unk_0 = (s32) (((temp_a0 >> 0x18) << 0x18) | (temp_a0 & 0xFF0000) | (temp_a0 & 0xFF00) | (temp_a0 & 0xFF));
#endif
            temp_a0_2 = var_a3 >> 2;
#if 0
            var_t9 = temp_t9 + 8;
            var_t9->unk_-4 = (s32) ((((temp_a1_2 + 3) & 0x3FF) << 0xE) | ((((temp_a0_2 + temp_a2_2 + 1) & 0x3FF) * 4) | 0xF6000000));
            var_t9->unk_0 = (s32) ((((temp_a1_2 - 2) & 0x3FF) << 0xE) | (((temp_a0_2 - temp_a2_2) & 0x3FF) * 4));
#endif

            gDPSetPrimColor(gfx++, 0, 0, temp_a0, temp_a0, temp_a0, temp_a0);
            gDPFillRectangle(gfx++, temp_a1_2 - 2, temp_a0_2 - temp_a2_2, temp_a1_2 + 3, temp_a0_2 + temp_a2_2 + 1);


            var_s1 += 1;
        }
    }

    *gfxP = gfx;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/044E80", func_800447C4_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/044E80", func_800447C4_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/044E80", func_800447C4_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/044E80", func_800447C4_usa);
#endif

void func_800449C4_usa(Gfx **gfxP) {
    if (B_80192FB0_usa->unk_0004 == 0xB) {
        screenDraw(gfxP, func_800447C4_usa);
    } else if (B_80192FB0_usa->unk_0004 < 7) {
        screenDraw(gfxP, func_800445D8_usa);
    } else {
        screenDraw(gfxP, NULL);
    }
}

#if VERSION_FRA || VERSION_GER
STATIC_INLINE
#endif
void func_80044A1C_usa(void) {
    if (B_80192FB0_usa->unk_0014 < 0xF) {
        if (B_80192FB0_usa->unk_0010 != 0) {
            func_800288D8_usa(B_80192FB0_usa->unk_0000, UNKNOWN_VALUE + 1, 0xB0, 0x12);
        } else {
            func_800288D8_usa(B_80192FB0_usa->unk_0000, UNKNOWN_VALUE + 1, 0x1A, 0x12);
        }
    } else {
        screenHideImage(B_80192FB0_usa->unk_0000, UNKNOWN_VALUE + 1);
    }

#if VERSION_FRA || VERSION_GER
    {
        s32 temp_s0;
        int new_var2;
        int new_var3;

        temp_s0 = B_80192FB0_usa->unk_0014 * 0x64;
        new_var3 = temp_s0 + 0x64;
        new_var2 = 0x80008000;
        screenHideText(B_80192FB0_usa->unk_0000, 0x8BB78064);
        temp_s0 = ((temp_s0 + 0xC7) << 0x10) | (new_var3 | new_var2);
        screenShowText(B_80192FB0_usa->unk_0000, temp_s0);
        screenHideImage(B_80192FB0_usa->unk_0000, 0x8BB78064);
        screenShowImage(B_80192FB0_usa->unk_0000, temp_s0);
    }
#else
    switch (B_80192FB0_usa->unk_0014) {
        case 0x0:
            screenShowText(B_80192FB0_usa->unk_0000, 0x64);
            screenShowText(B_80192FB0_usa->unk_0000, 0x65);
            screenHideText(B_80192FB0_usa->unk_0000, 0xC8);
            screenHideText(B_80192FB0_usa->unk_0000, 0xC9);
            screenHideText(B_80192FB0_usa->unk_0000, 0xCA);
            screenHideText(B_80192FB0_usa->unk_0000, 0xCB);
            screenHideText(B_80192FB0_usa->unk_0000, 0xCC);
            screenHideText(B_80192FB0_usa->unk_0000, 0xCD);
            screenHideText(B_80192FB0_usa->unk_0000, 0xCE);
            screenHideText(B_80192FB0_usa->unk_0000, 0x12C);
            screenHideText(B_80192FB0_usa->unk_0000, 0x12D);
            screenHideText(B_80192FB0_usa->unk_0000, 0x190);
            screenHideText(B_80192FB0_usa->unk_0000, 0x191);
            screenHideText(B_80192FB0_usa->unk_0000, 0x192);
            screenHideText(B_80192FB0_usa->unk_0000, 0x193);
            screenHideText(B_80192FB0_usa->unk_0000, 0x194);
            screenHideText(B_80192FB0_usa->unk_0000, 0x1F4);
            screenHideText(B_80192FB0_usa->unk_0000, 0x1F5);
            screenHideText(B_80192FB0_usa->unk_0000, 0x1F6);
            screenHideText(B_80192FB0_usa->unk_0000, 0x1F7);
            screenHideText(B_80192FB0_usa->unk_0000, 0x1F8);
            screenHideText(B_80192FB0_usa->unk_0000, 0x258);
            screenHideText(B_80192FB0_usa->unk_0000, 0x259);
            screenHideText(B_80192FB0_usa->unk_0000, 0x25A);
            screenHideText(B_80192FB0_usa->unk_0000, 0x25B);
            screenHideText(B_80192FB0_usa->unk_0000, 0x25C);
            screenHideText(B_80192FB0_usa->unk_0000, 0x2BC);
            screenHideText(B_80192FB0_usa->unk_0000, 0x2BD);
            screenHideText(B_80192FB0_usa->unk_0000, 0x2BE);
            screenHideText(B_80192FB0_usa->unk_0000, 0x320);
            screenHideText(B_80192FB0_usa->unk_0000, 0x321);
            screenHideText(B_80192FB0_usa->unk_0000, 0x322);
            screenHideText(B_80192FB0_usa->unk_0000, 0x384);
            screenHideText(B_80192FB0_usa->unk_0000, 0x385);
            screenHideText(B_80192FB0_usa->unk_0000, 0x386);
            screenHideText(B_80192FB0_usa->unk_0000, 0x387);
            screenHideText(B_80192FB0_usa->unk_0000, 0x388);
            screenHideText(B_80192FB0_usa->unk_0000, 0x3E8);
            screenHideText(B_80192FB0_usa->unk_0000, 0x3E9);
            screenHideText(B_80192FB0_usa->unk_0000, 0x3EA);
            screenHideText(B_80192FB0_usa->unk_0000, 0x44C);
            screenHideText(B_80192FB0_usa->unk_0000, 0x44D);
            screenHideText(B_80192FB0_usa->unk_0000, 0x44E);
            screenHideText(B_80192FB0_usa->unk_0000, 0x44F);
            screenHideText(B_80192FB0_usa->unk_0000, 0x450);
            screenHideText(B_80192FB0_usa->unk_0000, 0x451);
            screenHideText(B_80192FB0_usa->unk_0000, 0x452);
            screenHideText(B_80192FB0_usa->unk_0000, 0x4B0);
            screenHideText(B_80192FB0_usa->unk_0000, 0x4B1);
            screenHideText(B_80192FB0_usa->unk_0000, 0x4B2);
            screenHideText(B_80192FB0_usa->unk_0000, 0x514);
            screenHideText(B_80192FB0_usa->unk_0000, 0x515);
            screenHideText(B_80192FB0_usa->unk_0000, 0x516);
            screenHideText(B_80192FB0_usa->unk_0000, 0x517);
            screenHideText(B_80192FB0_usa->unk_0000, 0x518);
            screenHideText(B_80192FB0_usa->unk_0000, 0x519);
            screenHideText(B_80192FB0_usa->unk_0000, 0x51A);
            screenHideText(B_80192FB0_usa->unk_0000, 0x578);
            screenHideText(B_80192FB0_usa->unk_0000, 0x579);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5DC);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5DD);
            screenHideText(B_80192FB0_usa->unk_0000, 0x640);
            screenHideText(B_80192FB0_usa->unk_0000, 0x641);
            screenHideText(B_80192FB0_usa->unk_0000, 0x642);
            screenHideText(B_80192FB0_usa->unk_0000, 0x643);
            screenHideText(B_80192FB0_usa->unk_0000, 0x644);
            screenHideText(B_80192FB0_usa->unk_0000, 0x645);
            screenHideText(B_80192FB0_usa->unk_0000, 0x646);
            screenHideText(B_80192FB0_usa->unk_0000, 0x647);
            screenHideText(B_80192FB0_usa->unk_0000, 0x6A4);
            screenHideText(B_80192FB0_usa->unk_0000, 0x6A5);
            screenHideText(B_80192FB0_usa->unk_0000, 0x6A6);
            screenHideText(B_80192FB0_usa->unk_0000, 0x6A7);
            screenHideText(B_80192FB0_usa->unk_0000, 0x6A8);
            screenHideText(B_80192FB0_usa->unk_0000, 0x6A9);
            screenHideText(B_80192FB0_usa->unk_0000, 0x6AA);
            screenHideText(B_80192FB0_usa->unk_0000, 0x708);
            screenHideText(B_80192FB0_usa->unk_0000, 0x709);
            screenHideText(B_80192FB0_usa->unk_0000, 0x70A);
            screenHideText(B_80192FB0_usa->unk_0000, 0x70B);
            screenHideText(B_80192FB0_usa->unk_0000, 0x70C);
            screenHideText(B_80192FB0_usa->unk_0000, 0x70D);
            screenHideText(B_80192FB0_usa->unk_0000, 0x70E);
            screenHideText(B_80192FB0_usa->unk_0000, 0x76C);
            screenHideText(B_80192FB0_usa->unk_0000, 0x76D);
            screenHideText(B_80192FB0_usa->unk_0000, 0x7D0);
            screenHideText(B_80192FB0_usa->unk_0000, 0x7D1);
            screenHideText(B_80192FB0_usa->unk_0000, 0x834);
            screenHideText(B_80192FB0_usa->unk_0000, 0x835);
            screenHideText(B_80192FB0_usa->unk_0000, 0x836);
            screenHideText(B_80192FB0_usa->unk_0000, 0x837);
            break;

        case 0x1:
            screenHideText(B_80192FB0_usa->unk_0000, 0x64);
            screenHideText(B_80192FB0_usa->unk_0000, 0x65);
            screenShowText(B_80192FB0_usa->unk_0000, 0xC8);
            screenShowText(B_80192FB0_usa->unk_0000, 0xC9);
            screenShowText(B_80192FB0_usa->unk_0000, 0xCA);
            screenShowText(B_80192FB0_usa->unk_0000, 0xCB);
            screenShowText(B_80192FB0_usa->unk_0000, 0xCC);
            screenShowText(B_80192FB0_usa->unk_0000, 0xCD);
            screenShowText(B_80192FB0_usa->unk_0000, 0xCE);
            break;

        case 0x2:
            screenHideText(B_80192FB0_usa->unk_0000, 0xC8);
            screenHideText(B_80192FB0_usa->unk_0000, 0xC9);
            screenHideText(B_80192FB0_usa->unk_0000, 0xCA);
            screenHideText(B_80192FB0_usa->unk_0000, 0xCB);
            screenHideText(B_80192FB0_usa->unk_0000, 0xCC);
            screenHideText(B_80192FB0_usa->unk_0000, 0xCD);
            screenHideText(B_80192FB0_usa->unk_0000, 0xCE);
            screenShowText(B_80192FB0_usa->unk_0000, 0x12C);
            screenShowText(B_80192FB0_usa->unk_0000, 0x12D);
            screenShowText(B_80192FB0_usa->unk_0000, 0x12E);
            break;

        case 0x3:
            screenHideText(B_80192FB0_usa->unk_0000, 0x12C);
            screenHideText(B_80192FB0_usa->unk_0000, 0x12D);
            screenHideText(B_80192FB0_usa->unk_0000, 0x12E);
            screenShowText(B_80192FB0_usa->unk_0000, 0x190);
            screenShowText(B_80192FB0_usa->unk_0000, 0x191);
            screenShowText(B_80192FB0_usa->unk_0000, 0x192);
            screenShowText(B_80192FB0_usa->unk_0000, 0x193);
            screenShowText(B_80192FB0_usa->unk_0000, 0x194);
            screenShowText(B_80192FB0_usa->unk_0000, 0x195);
            screenShowText(B_80192FB0_usa->unk_0000, 0x196);
            break;

        case 0x4:
            screenHideText(B_80192FB0_usa->unk_0000, 0x190);
            screenHideText(B_80192FB0_usa->unk_0000, 0x191);
            screenHideText(B_80192FB0_usa->unk_0000, 0x192);
            screenHideText(B_80192FB0_usa->unk_0000, 0x193);
            screenHideText(B_80192FB0_usa->unk_0000, 0x194);
            screenHideText(B_80192FB0_usa->unk_0000, 0x195);
            screenHideText(B_80192FB0_usa->unk_0000, 0x196);
            screenShowText(B_80192FB0_usa->unk_0000, 0x1F4);
            screenShowText(B_80192FB0_usa->unk_0000, 0x1F5);
            screenShowText(B_80192FB0_usa->unk_0000, 0x1F6);
            screenShowText(B_80192FB0_usa->unk_0000, 0x1F7);
            screenShowText(B_80192FB0_usa->unk_0000, 0x1F8);
            break;

        case 0x5:
            screenHideText(B_80192FB0_usa->unk_0000, 0x1F4);
            screenHideText(B_80192FB0_usa->unk_0000, 0x1F5);
            screenHideText(B_80192FB0_usa->unk_0000, 0x1F6);
            screenHideText(B_80192FB0_usa->unk_0000, 0x1F7);
            screenHideText(B_80192FB0_usa->unk_0000, 0x1F8);
            screenShowText(B_80192FB0_usa->unk_0000, 0x258);
            screenShowText(B_80192FB0_usa->unk_0000, 0x259);
            screenShowText(B_80192FB0_usa->unk_0000, 0x25A);
            screenShowText(B_80192FB0_usa->unk_0000, 0x25B);
            screenShowText(B_80192FB0_usa->unk_0000, 0x25C);
            screenShowText(B_80192FB0_usa->unk_0000, 0x25D);
            screenShowText(B_80192FB0_usa->unk_0000, 0x25E);
            screenShowText(B_80192FB0_usa->unk_0000, 0x25F);
            screenShowText(B_80192FB0_usa->unk_0000, 0x260);
            screenShowText(B_80192FB0_usa->unk_0000, 0x261);
            screenShowText(B_80192FB0_usa->unk_0000, 0x262);
            screenShowText(B_80192FB0_usa->unk_0000, 0x263);
            screenShowText(B_80192FB0_usa->unk_0000, 0x264);
            screenShowText(B_80192FB0_usa->unk_0000, 0x265);
            break;

        case 0x6:
            screenHideText(B_80192FB0_usa->unk_0000, 0x258);
            screenHideText(B_80192FB0_usa->unk_0000, 0x259);
            screenHideText(B_80192FB0_usa->unk_0000, 0x25A);
            screenHideText(B_80192FB0_usa->unk_0000, 0x25B);
            screenHideText(B_80192FB0_usa->unk_0000, 0x25C);
            screenHideText(B_80192FB0_usa->unk_0000, 0x25D);
            screenHideText(B_80192FB0_usa->unk_0000, 0x25E);
            screenHideText(B_80192FB0_usa->unk_0000, 0x25F);
            screenHideText(B_80192FB0_usa->unk_0000, 0x260);
            screenHideText(B_80192FB0_usa->unk_0000, 0x261);
            screenHideText(B_80192FB0_usa->unk_0000, 0x262);
            screenHideText(B_80192FB0_usa->unk_0000, 0x263);
            screenHideText(B_80192FB0_usa->unk_0000, 0x264);
            screenHideText(B_80192FB0_usa->unk_0000, 0x265);
            screenShowText(B_80192FB0_usa->unk_0000, 0x2BC);
            screenShowText(B_80192FB0_usa->unk_0000, 0x2BD);
            screenShowText(B_80192FB0_usa->unk_0000, 0x2BE);
            screenShowText(B_80192FB0_usa->unk_0000, 0x2BF);
            screenShowText(B_80192FB0_usa->unk_0000, 0x2C0);
            break;

        case 0x7:
            screenHideText(B_80192FB0_usa->unk_0000, 0x2BC);
            screenHideText(B_80192FB0_usa->unk_0000, 0x2BD);
            screenHideText(B_80192FB0_usa->unk_0000, 0x2BE);
            screenHideText(B_80192FB0_usa->unk_0000, 0x2BF);
            screenHideText(B_80192FB0_usa->unk_0000, 0x2C0);
            screenShowText(B_80192FB0_usa->unk_0000, 0x320);
            screenShowText(B_80192FB0_usa->unk_0000, 0x321);
            screenShowText(B_80192FB0_usa->unk_0000, 0x322);
            screenShowText(B_80192FB0_usa->unk_0000, 0x323);
            screenShowText(B_80192FB0_usa->unk_0000, 0x324);
            break;

        case 0x8:
            screenHideText(B_80192FB0_usa->unk_0000, 0x320);
            screenHideText(B_80192FB0_usa->unk_0000, 0x321);
            screenHideText(B_80192FB0_usa->unk_0000, 0x322);
            screenHideText(B_80192FB0_usa->unk_0000, 0x323);
            screenHideText(B_80192FB0_usa->unk_0000, 0x324);
            screenShowText(B_80192FB0_usa->unk_0000, 0x384);
            screenShowText(B_80192FB0_usa->unk_0000, 0x385);
            screenShowText(B_80192FB0_usa->unk_0000, 0x386);
            screenShowText(B_80192FB0_usa->unk_0000, 0x387);
            screenShowText(B_80192FB0_usa->unk_0000, 0x388);
            screenShowText(B_80192FB0_usa->unk_0000, 0x389);
            screenShowText(B_80192FB0_usa->unk_0000, 0x38A);
            screenShowText(B_80192FB0_usa->unk_0000, 0x38B);
            screenShowText(B_80192FB0_usa->unk_0000, 0x38C);
            break;

        case 0x9:
            screenHideText(B_80192FB0_usa->unk_0000, 0x384);
            screenHideText(B_80192FB0_usa->unk_0000, 0x385);
            screenHideText(B_80192FB0_usa->unk_0000, 0x386);
            screenHideText(B_80192FB0_usa->unk_0000, 0x387);
            screenHideText(B_80192FB0_usa->unk_0000, 0x388);
            screenHideText(B_80192FB0_usa->unk_0000, 0x389);
            screenHideText(B_80192FB0_usa->unk_0000, 0x38A);
            screenHideText(B_80192FB0_usa->unk_0000, 0x38B);
            screenHideText(B_80192FB0_usa->unk_0000, 0x38C);
            screenShowText(B_80192FB0_usa->unk_0000, 0x3E8);
            screenShowText(B_80192FB0_usa->unk_0000, 0x3E9);
            screenShowText(B_80192FB0_usa->unk_0000, 0x3EA);
            screenShowText(B_80192FB0_usa->unk_0000, 0x3EB);
            screenShowText(B_80192FB0_usa->unk_0000, 0x3EC);
            break;

        case 0xA:
            screenHideText(B_80192FB0_usa->unk_0000, 0x3E8);
            screenHideText(B_80192FB0_usa->unk_0000, 0x3E9);
            screenHideText(B_80192FB0_usa->unk_0000, 0x3EA);
            screenHideText(B_80192FB0_usa->unk_0000, 0x3EB);
            screenHideText(B_80192FB0_usa->unk_0000, 0x3EC);
            screenShowText(B_80192FB0_usa->unk_0000, 0x44C);
            screenShowText(B_80192FB0_usa->unk_0000, 0x44D);
            screenShowText(B_80192FB0_usa->unk_0000, 0x44E);
            screenShowText(B_80192FB0_usa->unk_0000, 0x44F);
            screenShowText(B_80192FB0_usa->unk_0000, 0x450);
            screenShowText(B_80192FB0_usa->unk_0000, 0x451);
            screenShowText(B_80192FB0_usa->unk_0000, 0x452);
            screenShowText(B_80192FB0_usa->unk_0000, 0x453);
            screenShowText(B_80192FB0_usa->unk_0000, 0x454);
            break;

        case 0xB:
            screenHideText(B_80192FB0_usa->unk_0000, 0x44C);
            screenHideText(B_80192FB0_usa->unk_0000, 0x44D);
            screenHideText(B_80192FB0_usa->unk_0000, 0x44E);
            screenHideText(B_80192FB0_usa->unk_0000, 0x44F);
            screenHideText(B_80192FB0_usa->unk_0000, 0x450);
            screenHideText(B_80192FB0_usa->unk_0000, 0x451);
            screenHideText(B_80192FB0_usa->unk_0000, 0x452);
            screenHideText(B_80192FB0_usa->unk_0000, 0x453);
            screenHideText(B_80192FB0_usa->unk_0000, 0x454);
            screenShowText(B_80192FB0_usa->unk_0000, 0x4B0);
            screenShowText(B_80192FB0_usa->unk_0000, 0x4B1);
            screenShowText(B_80192FB0_usa->unk_0000, 0x4B2);
            break;

        case 0xC:
            screenHideText(B_80192FB0_usa->unk_0000, 0x4B0);
            screenHideText(B_80192FB0_usa->unk_0000, 0x4B1);
            screenHideText(B_80192FB0_usa->unk_0000, 0x4B2);
            screenShowText(B_80192FB0_usa->unk_0000, 0x514);
            screenShowText(B_80192FB0_usa->unk_0000, 0x515);
            screenShowText(B_80192FB0_usa->unk_0000, 0x516);
            screenShowText(B_80192FB0_usa->unk_0000, 0x517);
            screenShowText(B_80192FB0_usa->unk_0000, 0x518);
            screenShowText(B_80192FB0_usa->unk_0000, 0x519);
            screenShowText(B_80192FB0_usa->unk_0000, 0x51A);
            break;

        case 0xD:
            screenHideText(B_80192FB0_usa->unk_0000, 0x514);
            screenHideText(B_80192FB0_usa->unk_0000, 0x515);
            screenHideText(B_80192FB0_usa->unk_0000, 0x516);
            screenHideText(B_80192FB0_usa->unk_0000, 0x517);
            screenHideText(B_80192FB0_usa->unk_0000, 0x518);
            screenHideText(B_80192FB0_usa->unk_0000, 0x519);
            screenHideText(B_80192FB0_usa->unk_0000, 0x51A);
            screenShowText(B_80192FB0_usa->unk_0000, 0x578);
            screenShowText(B_80192FB0_usa->unk_0000, 0x579);
            screenShowText(B_80192FB0_usa->unk_0000, 0x57A);
            screenShowText(B_80192FB0_usa->unk_0000, 0x57B);
            screenShowText(B_80192FB0_usa->unk_0000, 0x57C);
            screenShowText(B_80192FB0_usa->unk_0000, 0x57D);
            screenShowText(B_80192FB0_usa->unk_0000, 0x57E);
            screenShowText(B_80192FB0_usa->unk_0000, 0x57F);
            break;

        case 0xE:
            screenHideText(B_80192FB0_usa->unk_0000, 0x578);
            screenHideText(B_80192FB0_usa->unk_0000, 0x579);
            screenHideText(B_80192FB0_usa->unk_0000, 0x57A);
            screenHideText(B_80192FB0_usa->unk_0000, 0x57B);
            screenHideText(B_80192FB0_usa->unk_0000, 0x57C);
            screenHideText(B_80192FB0_usa->unk_0000, 0x57D);
            screenHideText(B_80192FB0_usa->unk_0000, 0x57E);
            screenHideText(B_80192FB0_usa->unk_0000, 0x57F);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5DC);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5DD);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5DE);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5DF);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5E0);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5E1);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5E2);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5E3);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5E4);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5E5);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5E6);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5E7);
            screenShowText(B_80192FB0_usa->unk_0000, 0x5E8);
            break;

        case 0xF:
            screenHideText(B_80192FB0_usa->unk_0000, 0x5DC);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5DD);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5DE);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5DF);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5E0);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5E1);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5E2);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5E3);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5E4);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5E5);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5E6);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5E7);
            screenHideText(B_80192FB0_usa->unk_0000, 0x5E8);
            screenShowText(B_80192FB0_usa->unk_0000, 0x640);
            screenShowText(B_80192FB0_usa->unk_0000, 0x641);
            screenShowText(B_80192FB0_usa->unk_0000, 0x642);
            break;

        case 0x10:
            screenHideText(B_80192FB0_usa->unk_0000, 0x640);
            screenHideText(B_80192FB0_usa->unk_0000, 0x641);
            screenHideText(B_80192FB0_usa->unk_0000, 0x642);
            screenShowText(B_80192FB0_usa->unk_0000, 0x6A4);
            screenShowText(B_80192FB0_usa->unk_0000, 0x6A5);
            screenShowText(B_80192FB0_usa->unk_0000, 0x6A6);
            break;

        case 0x11:
            screenHideText(B_80192FB0_usa->unk_0000, 0x6A4);
            screenHideText(B_80192FB0_usa->unk_0000, 0x6A5);
            screenHideText(B_80192FB0_usa->unk_0000, 0x6A6);
            screenShowText(B_80192FB0_usa->unk_0000, 0x708);
            screenShowText(B_80192FB0_usa->unk_0000, 0x709);
            screenShowText(B_80192FB0_usa->unk_0000, 0x70A);
            break;

        case 0x12:
            screenHideText(B_80192FB0_usa->unk_0000, 0x708);
            screenHideText(B_80192FB0_usa->unk_0000, 0x709);
            screenHideText(B_80192FB0_usa->unk_0000, 0x70A);
            screenShowText(B_80192FB0_usa->unk_0000, 0x76C);
            screenShowText(B_80192FB0_usa->unk_0000, 0x76D);
            screenShowText(B_80192FB0_usa->unk_0000, 0x76E);
            screenShowImage(B_80192FB0_usa->unk_0000, 0x76C);
            break;

        case 0x13:
            screenHideText(B_80192FB0_usa->unk_0000, 0x76C);
            screenHideText(B_80192FB0_usa->unk_0000, 0x76D);
            screenHideText(B_80192FB0_usa->unk_0000, 0x76E);
            screenHideImage(B_80192FB0_usa->unk_0000, 0x76C);
            screenShowText(B_80192FB0_usa->unk_0000, 0x7D0);
            screenShowText(B_80192FB0_usa->unk_0000, 0x7D1);
            screenShowImage(B_80192FB0_usa->unk_0000, 0x7D0);
            break;
    }
#endif
}

s32 func_80046470_usa(void) {
    void *sp20;
    s32 var_s0;
    struct_imageLoad_arg0 *temp_a1;
    RomOffset *new_var;

    var_s0 = 0;

#if VERSION_USA || VERSION_EUR
#define UNKNOWN_OFFSET 0
#elif VERSION_FRA || VERSION_GER
#define UNKNOWN_OFFSET 2
#endif

    temp_a1 = B_80192FB0_usa->unk_0008[B_80192FB0_usa->unk_0010];
    if (temp_a1->unk_14 < 0xFA) {
        temp_a1->unk_14 = (temp_a1->unk_14 + 4) & 0xFF;
    } else {
        B_80192FB0_usa->unk_0018++;
        if (((B_80192FB0_usa->unk_0014 < 0xF) && (B_80192FB0_usa->unk_0018 >= 0x119)) ||
            (((B_80192FB0_usa->unk_0014 >= 0xF) && (B_80192FB0_usa->unk_0014 <= 0x12 + UNKNOWN_OFFSET)) &&
             (B_80192FB0_usa->unk_0018 >= 0x15F)) ||
            (B_80192FB0_usa->unk_0018 >= 0x191) ||
            ((gTheGame.controller[0].touch_button & START_BUTTON) &&
             (B_80192FB0_usa->unk_0014 < 0x13 + UNKNOWN_OFFSET))) {

            B_80192FB0_usa->unk_001C = 0;
            B_80192FB0_usa->unk_0018 = 0;

            B_80192FB0_usa->unk_0010 ^= 1;
            B_80192FB0_usa->unk_0014++;
            if (B_80192FB0_usa->unk_0014 >= 0x14 + UNKNOWN_OFFSET) {
                var_s0 = -1;
            }

            if (B_80192FB0_usa->unk_0010 != 0) {
                sp20 = (char *)B_801AB8E4_usa - 0x1E000;
            } else {
                sp20 = (char *)B_801AB8E4_usa - 0xF000;
            }

            new_var = &D_800B6950_usa[B_80192FB0_usa->unk_0014 % 0x10];
            func_8001FD0C_usa(&B_80192FB0_usa->unk_0008[B_80192FB0_usa->unk_0010], *new_var, 0, 0x54, 0x72, 0xC0,
                              &sp20);

            B_80192FB0_usa->unk_0008[B_80192FB0_usa->unk_0010]->unk_14 = 0;
            func_80044A1C_usa();
        } else {
            B_80192FB0_usa->unk_0008[B_80192FB0_usa->unk_0010]->unk_14 = 0xFA;
        }
    }

    return var_s0;
}

void func_80046648_usa(s32 arg0) {
    void *sp10;
    struct_imageLoad_arg0 *sp14;
    s32 var_s2 = 0;

    switch (B_80192FB0_usa->unk_0004) {
        case 0x0:
            var_s2 = func_80046470_usa();
            break;

        case 0x1:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE1", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x4:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE4", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x5:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
// TODO: REGION_PAL ?
#if VERSION_EUR || VERSION_FRA || VERSION_GER
                        if (func_800587CC_usa(4, 1) && func_800587CC_usa(5, 1) && func_800587CC_usa(5, 0x1F) &&
                            func_800587CC_usa(5, 0x29) && func_800587CC_usa(6, 1) && func_800587CC_usa(6, 0x1F) &&
                            func_800587CC_usa(6, 0x29)) {
                            var_s2 = -1;
                            break;
                        }
#endif

                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE5", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x2:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE2", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x3:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE3", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x6:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE6", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x7:
            if (!screenFlushing() && !func_80024C14_usa()) {
                if (func_80024BF4_usa(&sp10)) {
                    if (gTheGame.unk_9C28 == 3) {
                        HVQM2Util_Play((void *)"GAMEEND.HVQM", 0x1000U, sp10);
                        func_8002B85C_usa(5, 2);
                    } else {
                        HVQM2Util_Play((void *)"MEWINTRO.HVQM", 0x1000U, sp10);
                        gMain = GMAIN_384;
                        gReset = -1;
                        gTheGame.unk_9C0C = 1;
                        gSelection = 0x96;
                        gTheGame.unk_9C08 = 2;
                        gTheGame.unk_9C2C[0][2] = 1;
                    }
                }
            }
            break;

        case 0x8:
            if (!screenFlushing() && !func_80024C14_usa()) {
                if (func_80024BF4_usa(&sp10)) {
                    HVQM2Util_Play((void *)"YOUWIN.HVQM", 0x1000U, sp10);
                    func_8002B85C_usa(2, 8);
                }
            }
            break;

        case 0x9:
            if (!screenFlushing() && !func_80024C14_usa()) {
                if (func_80024BF4_usa(&sp10)) {
                    HVQM2Util_Play((void *)"YOULOSE.HVQM", 0x1000U, sp10);
                    gTheGame.unk_9C0C = 1;
                    gTheGame.unk_9C2C[0][0] = 0x12;
                    gMain = GMAIN_BONUS;
                    gReset = -1;
                }
            }
            break;

        case 0xA:
            if (arg0 == 0xA) {
                PlaySE(SFX_INIT_TABLE, 0x83);
            }

            if (arg0 > 0xF0) {
                if (gTheGame.controller[0].touch_button & START_BUTTON) {
                    var_s2 = -1;
                }
            }
            break;

        case 0xB:
            if (arg0 == 0xA) {
                PlaySE(SFX_INIT_TABLE, 0x80);
            }

            if (arg0 > 0xF0) {
                if (gTheGame.controller[0].touch_button & START_BUTTON) {
                    var_s2 = -1;
                }
            }

            if ((arg0 > 0x78) && (func_8002864C_usa(B_80192FB0_usa->unk_0000, 0x6E, &sp14))) {
                if (sp14->unk_14 < 0xFF) {
                    sp14->unk_14 += 8;
                    if (sp14->unk_14 >= 0x100) {
                        sp14->unk_14 = 0xFF;
                    }
                }

                if (sp14->unk_14 > 0) {
                    func_80044280_usa(arg0, B_80192FB0_usa->unk_0028);
                }
            }
            break;
    }

    if (var_s2 != 0) {
        FadeOutAllSFXs(0x1E);
        func_80002D8C_usa(0x1E);
        gReset = -1;
        gMain = GMAIN_TITLE;
        gTheGame.unk_9C0C = 1;
    }
}

void func_80046C2C_usa(void **heapP, u32 arg1) {
    *heapP = ALIGN_TO(*heapP, struct_80192FB0);
    B_80192FB0_usa = *heapP;
    *heapP += sizeof(struct_80192FB0);

    if (arg1 < 7U) {
        B_80192FB0_usa->unk_0014 = 0;
        B_80192FB0_usa->unk_001C = 0;
        B_80192FB0_usa->unk_0018 = 0;
        B_80192FB0_usa->unk_0010 = 0;
        func_8001FD0C_usa(B_80192FB0_usa->unk_0008, D_800B6950_usa[B_80192FB0_usa->unk_0014], 0, 0x54, 0x70, 0xC0,
                          heapP);

        B_80192FB0_usa->unk_0008[B_80192FB0_usa->unk_0010]->unk_14 = 0;
        B_80192FB0_usa->unk_0008[1] = 0;
    }

    if (arg1 == 0xB) {
        func_8004441C_usa(B_80192FB0_usa->unk_0028);
    }

    if (screenLoad("CREDITS.SBF", heapP) != 0) {
        B_80192FB0_usa->unk_0004 = arg1;
        switch (arg1) {
            case 0x0:
            case 0x1:
            case 0x2:
            case 0x3:
            case 0x4:
            case 0x5:
            case 0x6:
                B_80192FB0_usa->unk_0000 = screenSet("CREDITS", 0x401);
                func_80044A1C_usa();
                B_80192FB0_usa->unk_0020 = 0;
                break;

            case 0x7:
            case 0x8:
            case 0x9:
                B_80192FB0_usa->unk_0000 = screenSet("EMPTY", 0x401);
                break;

            case 0xA:
                B_80192FB0_usa->unk_0000 = screenSet("ENDING-1", 0x401);
                break;

            case 0xB:
                B_80192FB0_usa->unk_0000 = screenSet("ENDING-2", 0x401);
                break;
        }
    }

    if ((arg1 != 0xA) && (arg1 != 0xB)) {
        func_80002D8C_usa(0x1E);
        FadeOutAllSFXs(0x1E);
        if (B_80192FB0_usa->unk_0020 == 0) {
            PlayMIDI(BGM_INIT_TABLE, 0x47, 0, 1);
        }
    }
}
