#include "043D10.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "libc/assert.h"

#include "ai.h"
#include "image.h"
#include "peel.h"
#include "screen.h"
#include "segment_symbols.h"
#include "sfxlimit.h"
#include "sound.h"
#include "the_game.h"

#define STRUCT_80192FA0_UNK_64 3

typedef struct struct_80192FA0_unk_0C {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} struct_80192FA0_unk_0C; // size = 0x10

typedef struct struct_80192FA0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ struct_80192FA0_unk_0C unk_0C;
    /* 0x0C */ struct_80192FA0_unk_0C unk_1C;
    /* 0x0C */ struct_80192FA0_unk_0C unk_2C;
    /* 0x3C */ s32 unk_3C[STRUCT_80192FA0_UNK_64];
    /* 0x48 */ s32 unk_48[STRUCT_80192FA0_UNK_64];
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s32 unk_58;
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ s32 unk_60;
    /* 0x64 */ struct_imageLoad_arg0 *unk_64[STRUCT_80192FA0_UNK_64];
    /* 0x70 */ struct_imageLoad_arg0 *unk_70[STRUCT_80192FA0_UNK_64];
    /* 0x7C */ struct_imageLoad_arg0 *unk_7C[STRUCT_80192FA0_UNK_64];
    /* 0x88 */ struct_imageLoad_arg0 *unk_88[STRUCT_80192FA0_UNK_64];
    /* 0x94 */ s32 unk_94[STRUCT_80192FA0_UNK_64];
    /* 0xA0 */ s32 unk_A0[STRUCT_80192FA0_UNK_64];
    /* 0xAC */ s32 unk_AC;
    /* 0xB0 */ s32 unk_B0;
} struct_80192FA0; // size = 0xB4

extern struct_80192FA0 *B_80192FA0_usa;
extern u32 B_80192FA4_usa;

void func_8004360C_usa(s32 arg0);

RomOffset D_800B6840_usa[] = {
    SEGMENT_ROM_START(segment_background_35C3F0), SEGMENT_ROM_START(segment_background_3807F0),
    SEGMENT_ROM_START(segment_background_3A4BF0), SEGMENT_ROM_START(segment_background_3C8FF0),
    SEGMENT_ROM_START(segment_background_3ED3F0), SEGMENT_ROM_START(segment_background_4117F0),
    SEGMENT_ROM_START(segment_background_435BF0), SEGMENT_ROM_START(segment_background_459FF0),
    SEGMENT_ROM_START(segment_background_47E3F0), SEGMENT_ROM_START(segment_background_4A27F0),
    SEGMENT_ROM_START(segment_background_4C6BF0), SEGMENT_ROM_START(segment_background_4EAFF0),
};

struct_imageLoad_arg0 *D_800B6870_usa = NULL;

char *D_800B6874_usa[] = {
    "pikachu.bif",   "squirtle.bif",   "bulbasr.bif",    "nidoran.bif",   "growlith.bif",   "krabby.bif",
    "geodude.bif",   "vulpix.bif",     "zubat.bif",      "horsea.bif",    "psyduck.bif",    "staryu.bif",
    "raichu.bif",    "jolteon.bif",    "magneton.bif",   "tangela.bif",   "weepinbell.bif", "gloom.bif",
    "venomoth.bif",  "voltorb.bif",    "golbat.bif",     "abra.bif",      "hypno.bif",      "alakazam.bif",
    "arcanineb.bif", "charmeleon.bif", "magmar.bif",     "marrill.bif",   "venonat.bif",    "scyther.bif",
    "weezing.bif",   "arbok.bif",      "golbatr.bif",    "persian.bif",   "sandslash.bif",  "nidoking.bif",
    "sparky.bif",    "charmander.bif", "butterfree.bif", "cloyster.bif",  "polywirl.bif",   "dewgong.bif",
    "onix.bif",      "hitmonchan.bif", "primape.bif",    "nidoqueen.bif", "arcanineg.bif",  "kingler.bif",
    "pikachu.bif",   "squirtle.bif",   "bulbasr.bif",
};

s32 D_800B6940_usa[] = {
    0x00000056,
    0x00000048,
    0x00000048,
};
static_assert(ARRAY_COUNT(D_800B6940_usa) == STRUCT_80192FA0_UNK_64, "");

void func_80043110_usa(s32 arg0) {
    DATA_INLINE_CONST2 char *sp20[51] = {
        "pikatext.bif", "squitext.bif", "bulbtext.bif", "nidotext.bif", "growtext.bif", "krabtext.bif", "geodtext.bif",
        "vulptext.bif", "zubatext.bif", "horstext.bif", "psydtext.bif", "startext.bif", "raictext.bif", "jolttext.bif",
        "magntext.bif", "tangtext.bif", "weeptext.bif", "glootext.bif", "vemotext.bif", "volttext.bif", "golbtext.bif",
        "abratext.bif", "hypntext.bif", "alaktext.bif", "arcatext.bif", "cha2text.bif", "magmtext.bif", "marrtext.bif",
        "venatext.bif", "scyttext.bif", "weeztext.bif", "arbotext.bif", "golbtext.bif", "perstext.bif", "sandtext.bif",
        "nikitext.bif", "spartext.bif", "chartext.bif", "pufftext.bif", "cloytext.bif", "polytext.bif", "dewgtext.bif",
        "onixtext.bif", "hitmtext.bif", "primtext.bif", "niqutext.bif", "arcatext.bif", "kingtext.bif", "pikatext.bif",
        "squitext.bif", "bulbtext.bif",
    };
    void *spF0;
    s32 var_s1;
    int temp;

    if (func_80024C14_usa() || screenFlushing()) {
        return;
    }

    func_80024BF4_usa(&spF0);

    func_8001FD0C_usa(&D_800B6870_usa, D_800B6840_usa[B_8019CF98_usa], 0, 0x800054, 0x140, 0xE8, &spF0);

    for (var_s1 = 0; var_s1 < STRUCT_80192FA0_UNK_64; var_s1++) {
        imageLoad(&B_80192FA0_usa->unk_64[var_s1], D_800B6874_usa[var_s1], &spF0);
        imageLoad(&B_80192FA0_usa->unk_7C[var_s1], sp20[var_s1], &spF0);

#if VERSION_FRA || VERSION_GER
        {
            struct_bitmapLoad_arg0 *temp_a3 = *B_80192FA0_usa->unk_7C[var_s1]->unk_2C;
            s32 var_t1 = 0;
            s32 var_a2_2;

            for (var_a2_2 = 0; var_a2_2 < temp_a3->unk_10; var_a2_2++) {
                s32 var_a0;

                for (var_a0 = temp_a3->unk_0C - 1; var_a0 != 0; var_a0--) {
                    u8 *temp = temp_a3->unk_08;

                    if (temp[temp_a3->unk_04 * var_a2_2 + var_a0] != ((s32)(temp_a3->unk_00 & 0xFF000) >> 0xC)) {
                        break;
                    }
                }

                if (var_t1 < var_a0) {
                    var_t1 = var_a0;
                }
            }
            D_800B6940_usa[var_s1] = 0x90 - var_t1;
        }
#endif

        B_80192FA0_usa->unk_94[var_s1] = var_s1;

        imageLoad(&B_80192FA0_usa->unk_70[var_s1], D_800B6874_usa[gTheGame.menu[0].unk_4 * 3 + var_s1], &spF0);
        //! FAKE
        imageLoad(&B_80192FA0_usa->unk_88[var_s1], sp20[gTheGame.menu[0].unk_4 * (temp = 3) + var_s1], &spF0);
        B_80192FA0_usa->unk_A0[var_s1] = gTheGame.menu[0].unk_4 * 3 + var_s1;
    }

    B_80192FA0_usa->unk_48[0] = 0;
    B_80192FA0_usa->unk_3C[0] = 0x23;
    B_80192FA0_usa->unk_48[1] = 0x46;
    B_80192FA0_usa->unk_3C[1] = 0x69;
    B_80192FA0_usa->unk_48[2] = 0x46;
    B_80192FA0_usa->unk_3C[2] = 0x69;
    func_8004360C_usa(arg0);
}

void func_80043380_usa(struct_80192FA0_unk_0C *arg0) {
    if (arg0->unk_08 == 0) {
        switch (arg0->unk_0C) {
            case 0x0:
                if (arg0->unk_00 == -0x8C) {
                    PlaySE(SFX_INIT_TABLE, 0xA4);
                }

                arg0->unk_00 += 0xA;
                break;

            case 0x1:
                if (B_80192FA0_usa->unk_0C.unk_00 >= -0x64) {
                    arg0->unk_00 += 0xA;
                }
                break;

            case 0x2:
                if (B_80192FA0_usa->unk_0C.unk_00 >= -0x32) {
                    arg0->unk_00 += 0xA;
                }
                break;
        }

        if (arg0->unk_00 >= 0) {
            arg0->unk_00 = 0;
            arg0->unk_04 = 0;
            arg0->unk_08 = 1;
        }
    } else if (arg0->unk_08 == 1) {
        arg0->unk_04++;

        if (arg0->unk_04 % 2 == 0) {
            arg0->unk_00 = 2;
        } else {
            arg0->unk_00 = -2;
        }

        if (arg0->unk_04 >= 0xD) {
            arg0->unk_00 = 0;
            arg0->unk_04 = 0;
            arg0->unk_08 = 2;
            screenShowImage(B_80192FA0_usa->unk_00, 0x258);
            screenShowImage(B_80192FA0_usa->unk_00, 0x259);
        }
    } else if (arg0->unk_08 == 3) {
        arg0->unk_04++;
        if (((B_80192FA0_usa->unk_60 + 1) * 0x14 < arg0->unk_04) && (arg0->unk_04 >= 0x2E)) {
            arg0->unk_04 = 0;
            arg0->unk_08 = 4;
            func_80005270_usa(gTheGame.menu[0].unk_4, B_80192FA0_usa->unk_54, 2);
        }
    } else if (arg0->unk_08 == 4) {
        arg0->unk_04++;
        if (arg0->unk_04 >= 0x2E) {
            arg0->unk_04 = 0;
            arg0->unk_08 = 5;
            if (arg0->unk_0C == 0) {
                PlaySE(SFX_INIT_TABLE, 0xA3);
            }
        }
    } else if (arg0->unk_08 == 5) {
        switch (arg0->unk_0C) {
            case 0x0:
                if (B_80192FA0_usa->unk_2C.unk_00 < -0x46) {
                    arg0->unk_00 -= 0xC;
                }
                break;
            case 0x1:
                if (B_80192FA0_usa->unk_2C.unk_00 < -0x63) {
                    arg0->unk_00 -= 0xC;
                }
                break;
            case 0x2:
                arg0->unk_00 -= 0xC;
                break;
        }

        if (arg0->unk_00 < -0xA9) {
            arg0->unk_08 = 6;
        }
    }
}

void func_8004360C_usa(s32 arg0) {
    struct_imageLoad_arg0 *sp10;
    s32 sp14;
    s32 sp18;
    struct_imageLoad_arg0 *sp1C;

    func_80043380_usa(&B_80192FA0_usa->unk_0C);
    func_80043380_usa(&B_80192FA0_usa->unk_1C);
    func_80043380_usa(&B_80192FA0_usa->unk_2C);

    if (B_80192FA0_usa->unk_2C.unk_08 == 3) {
        if (B_80192FA0_usa->unk_54 < B_80192FA0_usa->unk_60) {
            B_80192FA0_usa->unk_5C++;
            if (B_80192FA0_usa->unk_5C >= 0x15) {
                B_80192FA0_usa->unk_5C = 0;
                B_80192FA0_usa->unk_54 += 1;
            }
        }

        screenShowImage(arg0, 0x259);
        func_800288D8_usa(arg0, 0x259, 0xAA, (B_80192FA0_usa->unk_54 * 0x2B) + 0x35);
        if (func_8002864C_usa(arg0, 0x258, &sp10)) {
            sp10->unk_14 = 0xFF;
        }
        if (func_8002864C_usa(arg0, 0x259, &sp10)) {
            sp10->unk_14 = 0xFF;
        }

        screenShowImage(arg0, 0x258);
    } else if ((B_80192FA0_usa->unk_0C.unk_08 >= 5) && (B_80192FA0_usa->unk_0C.unk_00 < 0)) {
        screenHideImage(arg0, 0x258);
        screenHideImage(arg0, 0x259);
    } else if (B_80192FA0_usa->unk_0C.unk_08 == 2) {
        B_80192FA0_usa->unk_08 = (B_80192FA0_usa->unk_08 + 1) & 0xF;
        func_8002A2E8_usa(arg0, 0x64, &sp14, &sp18);
        func_800288D8_usa(arg0, 0x258, 0x69, sp18 * 0x2B + 0x35);
        func_800288D8_usa(arg0, 0x259, 0xAA, B_80192FA0_usa->unk_54 * 0x2B + 0x35);

        if (func_8002864C_usa(arg0, 0x258, &sp1C)) {
            if (B_80192FA0_usa->unk_B0 != 0) {
                sp1C->unk_14 += 8;
                if (sp1C->unk_14 >= 0xFF) {
                    sp1C->unk_14 = 0xFF;
                    B_80192FA0_usa->unk_B0 = 0;
                }
            } else {
                sp1C->unk_14 -= 8;
                if (sp1C->unk_14 < 0x81) {
                    sp1C->unk_14 = 0x80;
                    B_80192FA0_usa->unk_B0 = 1;
                }
            }
        }

        if (func_8002864C_usa(arg0, 0x259, &sp1C)) {
            if (B_80192FA0_usa->unk_B0 != 0) {
                sp1C->unk_14 += 8;
                if (sp1C->unk_14 >= 0xFF) {
                    sp1C->unk_14 = 0xFF;
                }
            } else {
                sp1C->unk_14 -= 8;
                if (sp1C->unk_14 <= 0x80) {
                    sp1C->unk_14 = 0x80;
                }
            }
        }
    }

    func_800288D8_usa(arg0, 0x12E, B_80192FA0_usa->unk_0C.unk_00, 0x32);
    func_800288D8_usa(arg0, 0x12F, 0xA6 - B_80192FA0_usa->unk_1C.unk_00, 0x32);
    func_800288D8_usa(arg0, 0x190, 0x36, B_80192FA0_usa->unk_2C.unk_00 + 0xF);

    if (B_80192FA0_usa->unk_1C.unk_08 == 5) {
        func_800288D8_usa(arg0, 0x12C, B_80192FA0_usa->unk_0C.unk_00, 0x2E);
        func_800288D8_usa(arg0, 0x12D, 0xD9 - B_80192FA0_usa->unk_1C.unk_00, 0x2E);
        func_800288D8_usa(arg0, 0xC8, B_80192FA0_usa->unk_0C.unk_00, 0x32);
        func_800288D8_usa(arg0, gTheGame.menu[0].unk_4 + 0xC8, 0xDD - B_80192FA0_usa->unk_1C.unk_00, 0x32);
    } else {
        func_800288D8_usa(arg0, 0x12C, 0, 0x2E);
        func_800288D8_usa(arg0, 0x12D, 0xD9, 0x2E);
        func_800288D8_usa(arg0, 0xC8, 0, 0x32);
        func_800288D8_usa(arg0, gTheGame.menu[0].unk_4 + 0xC8, 0xDD, 0x32);
    }
}

void func_80043A60_usa(Gfx **gfxP, s32 arg1, s32 arg2);
#if VERSION_USA
#ifdef NON_MATCHING
void func_80043A60_usa(Gfx **gfxP, s32 arg1 UNUSED, s32 arg2) {
    struct_func_8002156C_usa_arg4 sp18;
    Gfx *gfx;
    s32 var_s7;

    if (arg2 == 0x1F4) {

        gfx = *gfxP;
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gSPClearGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_SHADING_SMOOTH);
        gDPFillRectangle(gfx++, 0, 0, 320, 20);
        *gfxP = gfx;

        imageDraw(D_800B6870_usa, gfxP, 0, 0, NULL);

        sp18.unk_04 = 0;
        sp18.unk_08 = 0x23;
        sp18.unk_0C = 0x23;

        for (var_s7 = 0; var_s7 < STRUCT_80192FA0_UNK_64; var_s7++) {
            sp18.unk_00 = B_80192FA0_usa->unk_48[var_s7];
            imageDraw(B_80192FA0_usa->unk_64[var_s7], gfxP, B_80192FA0_usa->unk_0C.unk_00 + 0x6E, 0x3A + var_s7 * 0x2B,
                      &sp18);
        }

        for (var_s7 = 0; var_s7 < STRUCT_80192FA0_UNK_64; var_s7++) {
            sp18.unk_00 = B_80192FA0_usa->unk_3C[var_s7];
            imageDraw(B_80192FA0_usa->unk_70[var_s7], gfxP, 0xAF - B_80192FA0_usa->unk_1C.unk_00, 0x3A + var_s7 * 0x2B,
                      &sp18);
        }

        if ((B_80192FA0_usa->unk_2C.unk_08 == 2) || (B_80192FA0_usa->unk_2C.unk_08 == 3) ||
            (B_80192FA0_usa->unk_2C.unk_08 == 4)) {
            imageDraw(B_80192FA0_usa->unk_7C[B_80192FA0_usa->unk_AC], gfxP,
                      D_800B6940_usa[B_80192FA0_usa->unk_94[B_80192FA0_usa->unk_AC]], 0xB9, NULL);
            imageDraw(B_80192FA0_usa->unk_88[B_80192FA0_usa->unk_54], gfxP, 0xAE, 0xB9, NULL);
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/043D10", func_80043A60_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/043D10", func_80043A60_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/043D10", func_80043A60_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/043D10", func_80043A60_usa);
#endif

void func_80043CFC_usa(Gfx **gfxP) {
    screenDraw(gfxP, func_80043A60_usa);
}

void func_80043D24_usa(s32 arg0) {
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 temp_s0;
    s32 var_a0;

    if (!screenFind(&sp10, "1PPK-PICK")) {
        return;
    }

    if (B_80192FA0_usa->unk_64[0] == NULL) {
        func_80043110_usa(sp10);
    }

    if (B_80192FA0_usa->unk_04-- > 0) {
        return;
    }

    B_80192FA0_usa->unk_04 = 0;
    if ((peelActive() == 0) && !func_80024C14_usa()) {
        func_8004360C_usa(sp10);
    }

    func_80027618_usa(sp10, 0x64, 0U);
    func_8002A2E8_usa(sp10, 0x64, &sp14, &sp18);

    if (B_80192FA0_usa->unk_2C.unk_08 == 2) {
        B_80192FA0_usa->unk_AC = sp18;
    }

    if (B_80192FA0_usa->unk_2C.unk_08 >= 3) {
        func_8002A1F4_usa(sp10, 0x64, sp14, B_80192FA0_usa->unk_58);
        sp18 = B_80192FA0_usa->unk_58;
    }

    if (B_80192FA0_usa->unk_1C.unk_08 == 6) {
        FadeOutAllSFXs(0x1E);
        func_80002D8C_usa(0x1E);
        gTheGame.unk_9C0C = 1;
        gTheGame.unk_9C08 = 2;
        brainbrain->unk_00C = -1;
        gTheGame.menu[0].unk_C = sp18 + 1;
        gMain = GMAIN_384;
        gReset = -1;
        gSelection = 0x96;
        gTheGame.menu[1].unk_C = B_80192FA0_usa->unk_54 + 1;
    }

    for (var_a0 = 0; var_a0 < 3; var_a0++) {
        B_80192FA0_usa->unk_48[var_a0] = 0x46;
        B_80192FA0_usa->unk_3C[var_a0] = 0x69;
    }

    B_80192FA0_usa->unk_48[sp18] = 0;
    B_80192FA0_usa->unk_3C[B_80192FA0_usa->unk_54] = 0x23;
    temp_s0 = B_80192FA0_usa->unk_2C.unk_08;
    if ((temp_s0 == 2) && (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON))) {
        screenShowImage(sp10, 0x258);
        func_800288D8_usa(sp10, 0x258, 0x69, (sp18 * 0x2B) + 0x35);
        func_80005270_usa(0, sp18, 1);

        B_80192FA0_usa->unk_60 = 3 - gTheGame.menu[0].unk_0;
        if (B_80192FA0_usa->unk_60 >= 3) {
            B_80192FA0_usa->unk_60 = temp_s0;
        } else if (B_80192FA0_usa->unk_60 < 0) {
            B_80192FA4_usa += (sp18 + gTheGame.menu[0].unk_8 + gTheGame.menu[0].unk_4 + arg0 + gTheGame.menu[0].unk_C +
                               gTheGame.menu[0].unk_0 + 7) *
                              5;

            B_80192FA0_usa->unk_60 = B_80192FA4_usa % 3;
        }

        B_80192FA0_usa->unk_58 = sp18;
        B_80192FA0_usa->unk_1C.unk_08 = 3;
        B_80192FA0_usa->unk_0C.unk_08 = 3;
        B_80192FA0_usa->unk_2C.unk_08 = 3;
    }
}

void func_8004407C_usa(void **heapP, s32 arg1 UNUSED) {
    s32 sp10[3];
    s32 var_a0;
    s32 var_s2;
    s32 s0;
    menu_t *menu;

    *heapP = ALIGN_TO(*heapP, struct_80192FA0);
    B_80192FA0_usa = *heapP;
    *heapP += sizeof(struct_80192FA0);

    if (screenLoad("POKEMON.SBF", heapP) != 0) {
        B_80192FA0_usa->unk_00 = screenSet("1PPK-PICK", 0xFF001);
    }

    for (var_a0 = 0; var_a0 < STRUCT_80192FA0_UNK_64; var_a0++) {
        B_80192FA0_usa->unk_7C[var_a0] = NULL;
        B_80192FA0_usa->unk_88[var_a0] = NULL;
        B_80192FA0_usa->unk_64[var_a0] = NULL;
        B_80192FA0_usa->unk_70[var_a0] = NULL;
    }

    B_80192FA0_usa->unk_5C = 0;
    B_80192FA0_usa->unk_1C.unk_0C = 1;
    B_80192FA0_usa->unk_2C.unk_0C = 2;
    B_80192FA0_usa->unk_2C.unk_00 = -0x96;
    B_80192FA0_usa->unk_1C.unk_00 = -0x96;
    B_80192FA0_usa->unk_0C.unk_00 = -0x96;
    B_80192FA0_usa->unk_54 = 0;
    B_80192FA0_usa->unk_0C.unk_0C = 0;
    B_80192FA0_usa->unk_2C.unk_08 = 0;
    B_80192FA0_usa->unk_1C.unk_08 = 0;
    B_80192FA0_usa->unk_0C.unk_08 = 0;
    B_80192FA0_usa->unk_04 = 0x14;
    B_80192FA0_usa->unk_B0 = 0;
    B_80192FA0_usa->unk_08 = 0;

    if (screenFind(sp10, "1PPK-PICK")) {
        func_8002A2E8_usa(sp10[0], 0x64, &sp10[1], &sp10[2]);
        func_8002A1F4_usa(sp10[0], 0x64, sp10[1], 0);
        func_8002A2E8_usa(sp10[0], 0x65, &sp10[1], &sp10[2]);
        func_8002A1F4_usa(sp10[0], 0x65, sp10[1], 0);

        s0 = sp10[0];
        for (var_s2 = 0; var_s2 < 0x10; var_s2++) {
            screenHideImage(s0, var_s2 + 0xC8);
        }

        screenHideImage(s0, 0x258);
        screenHideImage(s0, 0x259);
        screenShowImage(s0, 0xC8);
        func_80028DC0_usa(s0, 0xC8, 0);

        menu = &gTheGame.menu[0];
        screenShowImage(s0, menu->unk_4 + 0xC8);
        func_80028DC0_usa(s0, menu->unk_4 + 0xC8, 1);
    }
}
