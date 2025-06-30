#include "041780.h"

#include "macros_defines.h"
#include "main_variables.h"

#include "buffers.h"
#include "hvqm2util.h"
#include "image.h"
#include "screen.h"
#include "segment_symbols.h"
#include "sfxlimit.h"
#include "sound.h"
#include "story.h"
#include "the_game.h"

typedef struct struct_80192F80_usa {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ struct_imageLoad_arg0 *unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
} struct_80192F80_usa; // size = 0x38

extern struct_80192F80_usa *B_80192F80_usa;
extern s32 B_801C6EF0_usa;

struct_imageLoad_arg0 *D_800B6790_usa = NULL;

u16 D_800B6794_usa[] = {
    0x1E09, //
    0x1709, //
    0x1D09, //
#if VERSION_FRA || VERSION_GER
    0x1E09, //
    0x1E09, //
#else
    0x1509, //
    0x1C09, //
#endif
    0x1809, //
#if VERSION_FRA || VERSION_GER
    0x1E09, //
#else
    0x1609, //
#endif
    0x1C08, //
    0x1C08, //
    0x1C05, //
    0x220A, //
    0x1A09, //
#if VERSION_FRA || VERSION_GER
    0x1E03, //
#else
    0x1603, //
#endif
    0x2209, //
    0x1709, //
    0x0000, //
};

RomOffset D_800B67B4_usa[] = {
    SEGMENT_ROM_START(segment_background_35C3F0), SEGMENT_ROM_START(segment_background_3807F0),
    SEGMENT_ROM_START(segment_background_3A4BF0), SEGMENT_ROM_START(segment_background_3C8FF0),
    SEGMENT_ROM_START(segment_background_3ED3F0), SEGMENT_ROM_START(segment_background_4117F0),
    SEGMENT_ROM_START(segment_background_435BF0), SEGMENT_ROM_START(segment_background_459FF0),
    SEGMENT_ROM_START(segment_background_47E3F0), SEGMENT_ROM_START(segment_background_4A27F0),
    SEGMENT_ROM_START(segment_background_4C6BF0), SEGMENT_ROM_START(segment_background_4EAFF0),
};

s16 D_800B67E4_usa[] = { 0, 5, 6, 7, 1, 0xA, 2, 9, 0, 3, 4, 2, 8, 0xB };

void func_80040B80_usa(Gfx **gfxP, s32 arg1 UNUSED, s32 arg2) {
    if (arg2 == 0x1F4) {
        Gfx *gfx = *gfxP;

        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gSPClearGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_SHADING_SMOOTH);
        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH, 20);
        *gfxP = gfx;

        imageDraw(D_800B6790_usa, gfxP, 0, 0, NULL);
    } else if (arg2 == 0x1FE) {
        if (B_80192F80_usa->unk_20 != NULL) {
            struct_func_8002156C_usa_arg4 sp18;

            sp18.unk_00 = B_80192F80_usa->unk_24;
            sp18.unk_04 = B_80192F80_usa->unk_28;
            sp18.unk_08 = 0x5A;
            sp18.unk_0C = 0x5F;
            imageDraw(B_80192F80_usa->unk_20, gfxP, 0x73, 0x20, &sp18);
        }
    } else if (arg2 == 0x208) {
        Gfx *gfx = *gfxP;

        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gSPClearGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_SHADING_SMOOTH);
        gDPSetFillColor(gfx++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, 31);
        *gfxP = gfx;
    }
}

void func_80040DE4_usa(Gfx **gfxP) {
    if (B_80192F80_usa->unk_04 != 0) {
        u32 *var_a0 = osViGetCurrentFramebuffer();
        u32 *var_v1;
        s32 var_a1;

        if (var_a0 != (void *)gFramebuffers[0]) {
            if (var_a0 != (void *)gFramebuffers[1]) {
                var_a0 = (void *)gFramebuffers[0];
            }
        }

        var_v1 = (void *)gFramebuffers[0];
        if (var_a0 == var_v1) {
            var_v1 = (void *)gFramebuffers[1];
        }

        FRAMEBUFFERS_COPY(var_a1, var_v1, var_a0);

        B_80192F80_usa->unk_04 = 0;
    }

    screenDraw(gfxP, func_80040B80_usa);
}

nbool func_80040F04_usa(void) {
    u32 var_a1 = 0x20 | 0x10 | 0x8 | 0x4 | 0x2 | 0x1;
    s32 var_a0;

    // TODO: macros for counts
    for (var_a0 = 0; var_a0 < 0x1E; var_a0++) {
        if (!((gPlayer[0]->unk_0B7[var_a0 >> 3] >> (var_a0 & 7)) & 1)) {
            var_a1 &= ~1;
        }
    }

    for (var_a0 = 0; var_a0 < 0x32; var_a0++) {
        if (!((gPlayer[0]->unk_0BB[var_a0 >> 3] >> (var_a0 & 7)) & 1)) {
            var_a1 &= ~2;
        }
    }

    for (var_a0 = 0; var_a0 < 0x32; var_a0++) {
        if (!(((*gPlayer)->unk_0C2[var_a0 >> 3] >> (var_a0 & 7)) & 1)) {
            var_a1 &= ~4;
        }
    }

    for (var_a0 = 0; var_a0 < 0x1E; var_a0++) {
        if (!((gPlayer[0]->unk_0C9[var_a0 >> 3] >> (var_a0 & 7)) & 1)) {
            var_a1 &= ~8;
        }
    }

    for (var_a0 = 0; var_a0 < 0x32; var_a0++) {
        if (!((gPlayer[0]->unk_0CD[var_a0 >> 3] >> (var_a0 & 7)) & 1)) {
            var_a1 &= ~0x10;
        }
    }

    for (var_a0 = 0; var_a0 < 0x32; var_a0++) {
        if (!((gPlayer[0]->unk_0D4[(var_a0 >> 3)] >> (var_a0 & 7)) & 1)) {
            var_a1 &= ~0x20;
        }
    }

    if ((var_a1 == (0x4 | 0x2 | 0x1)) || (var_a1 == (0x20 | 0x10 | 0x8 | 0x4 | 0x2 | 0x1))) {
        return ntrue;
    }
    return nfalse;
}

// ShowWinner?
void func_800410A4_usa(void) {
    struct struct_imageLoad_arg0 *sp10;
    s32 var_s1;
    u32 var_s0;

    if (gTheGame.cursorBlock[1].unk_00 == 8) {
        var_s1 = 0;
    } else if (gTheGame.cursorBlock[0].unk_00 == 8) {
        var_s1 = 1;
    } else {
        var_s1 = 0;
#if VERSION_USA
        osSyncPrintf("ShowWinner: Internal error: No clear winner? (%d,%d)\n", gTheGame.cursorBlock[0].unk_00,
                     gTheGame.cursorBlock[1].unk_00);
#endif
    }

    B_80192F80_usa->unk_34 = var_s1;
    if (B_80192F80_usa->unk_08 != 0) {
        var_s0 = (var_s1 != 0) ? 15 : 0;
    } else {
        var_s0 = gTheGame.menu[var_s1].unk_4 / 100;
    }

    if (var_s0 >= ARRAY_COUNT(D_800B6794_usa)) {
        var_s0 = 0;
#if VERSION_USA
        osSyncPrintf("ShowWinner: Internal error: Character out-of-range! (%d)\n", var_s0);
#endif
    }

    B_80192F80_usa->unk_30 = 0;
    B_80192F80_usa->unk_2C = var_s0;
    screenShowText(B_80192F80_usa->unk_0C, var_s0 + 0xC8);

    B_80192F80_usa->unk_24 = D_800B6794_usa[var_s0] & 0xFF;
    B_80192F80_usa->unk_28 = D_800B6794_usa[var_s0] >> 8;
    screenShowImage(B_80192F80_usa->unk_0C, (var_s1 != 1) ? 0xC9 : 0xC8);

    screenShowImage(B_80192F80_usa->unk_0C, 0x820781F4);
    screenShowText(B_80192F80_usa->unk_0C, 0x80EF80DC);

    if (func_8002864C_usa(B_80192F80_usa->unk_0C, B_80192F80_usa->unk_2C + 0x12C, &sp10)) {
        B_80192F80_usa->unk_20 = sp10;
    }
}

void func_8004123C_usa(s32 arg0) {
    void *sp10;
    s32 sp14;
    s32 sp18;
    struct_imageLoad_arg0 *sp1C;
    s32 sp20;
    enum_gMain var_v1;
    s32 var_a1;
    s32 var_a2;
    s32 var_s0;
    s32 var_s2;

    var_s2 = 0;
    if (func_80024C14_usa() || screenFlushing()) {
        return;
    }

    if ((B_80192F80_usa->unk_1C == 9) && func_80024BF4_usa(&sp10)) {
        HVQM2Util_Play((void *)"spaGIO.HVQM", 0x1000U, sp10);
        var_s2 = -1;
    } else if (((gSelection != 0xA0) & (gSelection != 0xB4)) && (gSelection != 0xC8)) {
        var_s2 = (gTheGame.controller[0].touch_button & START_BUTTON) ? -1 : 0;
    }

    switch (B_80192F80_usa->unk_18 + 1) {
        case 0x0:
            break;

        case 0x1:
            if ((gTheGame.controller[0].touch_button & A_BUTTON) || (arg0 >= 0x3D)) {
                var_s2 = -1;
            }
            break;

        case 0x2:
            if (gSelection == 0x82) {
                if ((B_80192F80_usa->unk_1C >= 2) && (B_80192F80_usa->unk_1C < 8)) {
                    func_80028DC0_usa(B_80192F80_usa->unk_0C, 0x8C, 0);
                }
            }

            if (!(arg0 & 7)) {
                if (B_80192F80_usa->unk_00 == 0) {
                    PlaySE(SFX_INIT_TABLE, 0xA3);
                }

                if (B_80192F80_usa->unk_00 < 0xC) {
                    B_80192F80_usa->unk_00++;
                }
            }
            var_s0 = 0;
            if (func_800289C0_usa(B_80192F80_usa->unk_0C, 0x78, &sp14, &sp18) && (sp18 < 0)) {
                var_s0 = -1;
                sp18 += B_80192F80_usa->unk_00 * 5 / 2;
                if (sp18 >= 0) {
                    sp18 = 0;
                }
                screenSetImagePosition(B_80192F80_usa->unk_0C, 0x78, sp14, sp18);
            }
            if (func_800289C0_usa(B_80192F80_usa->unk_0C, 0x79, &sp14, &sp18) && (sp18 >= 0x99)) {
                var_s0 = -1;

                if (sp18 - B_80192F80_usa->unk_00 * 5 / 2 < 0x99) {
                    PlaySE(SFX_INIT_TABLE, 0x17B);
                }

                sp18 -= B_80192F80_usa->unk_00 * 5 / 2;
                if (sp18 < 0x99) {
                    sp18 = 0x98;
                }
                screenSetImagePosition(B_80192F80_usa->unk_0C, 0x79, sp14, sp18);
            }
            if (var_s0 == 0) {
                B_80192F80_usa->unk_00 = 0;
                B_80192F80_usa->unk_18 = 2;
                B_80192F80_usa->unk_10 = arg0;
                screenShowImage(B_80192F80_usa->unk_0C, 0x208);
                if ((gSelection == 0xA0) || (gSelection == 0xB4) || (gSelection == 0xC8)) {
                    func_800410A4_usa();
                }
            }
            break;
        case 0x3:
            if ((arg0 - B_80192F80_usa->unk_10) >= 0x3D) {
                PlaySE(SFX_INIT_TABLE, 0xA4);
                B_80192F80_usa->unk_18 = 3;
                screenShowText(B_80192F80_usa->unk_0C, 0x64);
                screenShowImage(B_80192F80_usa->unk_0C, 0x82);
                screenShowImage(B_80192F80_usa->unk_0C, 0x8C);
            }
            break;
        case 0x4:
            if (!(arg0 & 7)) {
                if (B_80192F80_usa->unk_00 < 0xC) {
                    B_80192F80_usa->unk_00++;
                }
            }
            var_s0 = 0;
            if (func_800289C0_usa(B_80192F80_usa->unk_0C, 0x78, &sp14, &sp18) && (sp18 >= -0x98)) {
                sp18 -= ((s32)(B_80192F80_usa->unk_00 * 5) / 2);
                var_s0 = -1;
                if (sp18 < -0x98) {
                    sp18 = -0x99;
                }
                screenSetImagePosition(B_80192F80_usa->unk_0C, 0x78, sp14, sp18);
            }
            if (((gSelection == 0xA0) || (gSelection == 0xB4) || (gSelection == 0xC8)) &&
                func_800289C0_usa(B_80192F80_usa->unk_0C, 0x79, &sp14, &sp18) && (sp18 < 0xDC)) {
                sp18 += B_80192F80_usa->unk_00;
                var_s0 = -1;
                if (sp18 >= 0xDC) {
                    sp18 = 0xDC;
                }
                screenSetImagePosition(B_80192F80_usa->unk_0C, 0x79, sp14, sp18);
            }
            if (var_s0 == 0) {
                B_80192F80_usa->unk_18 = 4;
                B_80192F80_usa->unk_00 = 0;
                if (gSelection == 0x96) {
                    if (B_80192F80_usa->unk_1C == 0) {
                        PlaySE(SFX_INIT_TABLE, 0);
                        func_80005780_usa(gTheGame.menu[0].unk_4);
                    } else if (B_80192F80_usa->unk_1C == 8) {
                        PlaySE(SFX_INIT_TABLE, 0);
                        func_80005780_usa(0x11);
                    }
                }
                if ((gSelection == 0x82) && ((u32)(B_80192F80_usa->unk_1C - 2) < 6U)) {
                    PlaySE(SFX_INIT_TABLE, 0);
                    func_80005888_usa(0, 2, 0xA);
                }
            }
            break;
        case 0x5:
            if (!(arg0 & 7)) {
                if (B_80192F80_usa->unk_00 < 0xC) {
                    B_80192F80_usa->unk_00++;
                }
            }

            if (func_800289C0_usa(B_80192F80_usa->unk_0C, 0x64, &sp14, &sp18) && (sp14 < B_80192F80_usa->unk_14)) {
                sp14 += B_80192F80_usa->unk_00;
                if (sp14 >= B_80192F80_usa->unk_14) {
                    sp14 = B_80192F80_usa->unk_14;
                    B_80192F80_usa->unk_00 = 0;
                }
                screenSetImagePosition(B_80192F80_usa->unk_0C, 0x64, sp14, sp18);
            } else if (func_800289C0_usa(B_80192F80_usa->unk_0C, 0x6E, &sp14, &sp18) && (sp14 >= 0xC3)) {
                sp14 -= B_80192F80_usa->unk_00;
                if (sp14 < 0xC3) {
                    sp14 = 0xC2;
                    B_80192F80_usa->unk_00 = 0;
                }
                screenSetImagePosition(B_80192F80_usa->unk_0C, 0x6E, sp14, sp18);
            } else if ((gSelection == 0xA0) || (gSelection == 0xB4) || (gSelection == 0xC8)) {
                B_80192F80_usa->unk_00 = 0;
                B_80192F80_usa->unk_18 = 5;
                if (gTheGame.cursorBlock[0].unk_00 == 8) {
                    var_a1 = 2;
                } else {
                    var_a1 = 1;
                }
                func_80005888_usa(0, var_a1, 4);
            } else {
                B_80192F80_usa->unk_18 = 6;
            }
            break;
        case 0x6:
            if (!(arg0 & 7)) {
                if (B_80192F80_usa->unk_00 < 0xC) {
                    B_80192F80_usa->unk_00++;
                }
            }

            screenShowImage(B_80192F80_usa->unk_0C, 0xD2);
            if (B_80192F80_usa->unk_30 != 0) {
#if VERSION_GER
                var_a2 = 0x95;
#elif VERSION_FRA
                var_a2 = 0xA0;
#else
                var_a2 = 0xA8;
#endif
            } else {
#if VERSION_GER
                var_a2 = 0x73;
#else
                var_a2 = 0x70;
#endif
            }
            screenSetImagePosition(B_80192F80_usa->unk_0C, 0xD2, var_a2, 0xCA);

            if ((gTheGame.controller[B_80192F80_usa->unk_34].touch_button & L_JPAD) && (B_80192F80_usa->unk_30 == 1)) {
                B_80192F80_usa->unk_30 = 0;
                PlaySE(SFX_INIT_TABLE, 1);
            }

            if ((gTheGame.controller[B_80192F80_usa->unk_34].touch_button & R_JPAD) && (B_80192F80_usa->unk_30 == 0)) {
                B_80192F80_usa->unk_30 = 1;
                PlaySE(SFX_INIT_TABLE, 1);
            }
            if (gTheGame.controller[B_80192F80_usa->unk_34].touch_button & A_BUTTON) {
                gReset = -1;
                if (B_80192F80_usa->unk_30 == 0) {
                    var_v1 = GMAIN_2BC;
                } else {
                    var_v1 = GMAIN_258;
                }
                gMain = var_v1;

                PlaySE(SFX_INIT_TABLE, (gMain == GMAIN_258) ? 6 : 2);
                if ((B_80192F80_usa->unk_08 != 0) && (B_80192F80_usa->unk_30 == 0)) {
                    gMain = GMAIN_384;
                    B_8019CF98_usa = 0x10;
                    gTheGame.menu[0].unk_4 = 1;
                    gReset = -1;
                    D_800B5A1C_usa = 0;
                    gTheGame.menu[1].unk_4 = 0x641;
                    gTheGame.tetrisWell[0].unk_4404 = 0;
                    gTheGame.tetrisWell[1].unk_4404 = 0;
                    gTheGame.unk_9C0C = B_801C6EF0_usa;
                }
            }
            break;
        case 0x7:
            if (gTheGame.controller[0].touch_button & A_BUTTON) {
                var_s2 = -1;
            }
            if ((gSelection == 0x82) && (B_80192F80_usa->unk_1C >= 2) && (B_80192F80_usa->unk_1C < 8) &&
                func_8002864C_usa(B_80192F80_usa->unk_0C, 0x8C, &sp1C)) {
                func_80028E80_usa(B_80192F80_usa->unk_0C, 0x8C, &sp20);
                if ((sp20 < (sp1C->unk_18 - 1)) && !(arg0 & 7)) {
                    sp20 += 1;
                }
                func_80028DC0_usa(B_80192F80_usa->unk_0C, 0x8C, sp20);
            }
            break;
    }

    if (var_s2 == 0) {
        return;
    }

    FadeOutAllSFXs(0x1E);
    if ((B_80192F80_usa->unk_18 != 0) || (gTheGame.controller[0].touch_button & A_BUTTON)) {
        PlaySE(SFX_INIT_TABLE, 2);
    }

    if ((gSelection == 0xA0) || (gSelection == 0xB4) || (gSelection == 0xC8)) {
        gReset = -1;
        gMain = GMAIN_2BC;
    } else if (gSelection == 0x8C) {
        if (gTheGame.tetrisWell[0].unk_43AC > 0xC34F) {
            func_8002B85C_usa(5, 1);
        } else {
            gMain = GMAIN_2BC;
            gReset = -1;
        }
    } else if (gSelection == 0xAA) {
        if (B_80192F80_usa->unk_1C == 9) {
            func_8002B85C_usa(2, 0);
        } else {
            func_8002B85C_usa(5, 4);
        }
    } else if (gSelection == 0xBE) {
        if (gTheGame.tetrisWell[0].unk_43AC >= 0x7530) {
            func_8002B85C_usa(5, 0);
        } else {
            gMain = GMAIN_2BC;
            gReset = -1;
        }
    } else if (gSelection == 0x82) {
        if (func_80040F04_usa()) {
            func_8002B85C_usa(5, 5);
        } else {
            gMain = GMAIN_2BC;
            gReset = -1;
        }
    } else {
        var_s0 = -1;

        if (B_80192F80_usa->unk_1C == 8) {
            if (gTheGame.menu[0].unk_0 == 4) {
                func_8002B85C_usa(5, 3);
            } else if (gTheGame.menu[0].unk_0 == 5) {
                func_8002B85C_usa(5, 6);
            }
        } else if (B_80192F80_usa->unk_1C == 1) {
            func_8002B85C_usa(3, 0);
        } else if (gTheGame.menu[0].unk_4 == 0xC) {
            if (gTheGame.menu[0].unk_0 == 1) {
                func_8002B85C_usa(5, 0xA);
                var_s0 = 0;
            } else {
                func_8002B85C_usa(2, 1);
            }
        } else if ((gTheGame.menu[0].unk_4 == 0xF) && (gTheGame.menu[0].unk_0 == 2)) {
            func_8002B85C_usa(5, 0xB);
            var_s0 = 0;
        } else if (gTheGame.menu[0].unk_4 == 0x10) {
            func_8002B85C_usa(5, 7);
        } else {
            func_8002B85C_usa(3, 0);
        }

        if ((gTheGame.menu[0].unk_4 >= 2) && (B_80192F80_usa->unk_1C != 1) && var_s0) {
            func_80002D8C_usa(0x1E);
            PlayMIDI(BGM_INIT_TABLE, 0x3D, 0, 1);
        }
    }
}

void func_80041F1C_usa(void **heapP, s32 arg1) {
    char sp20[0x20];
    s32 sp40;
    s32 sp44;
    s32 var_v0;
    s32 var_s0;

    *heapP = ALIGN_TO(*heapP, struct_80192F80_usa);
    B_80192F80_usa = *heapP;
    *heapP += sizeof(struct_80192F80_usa);

    B_80192F80_usa->unk_1C = arg1;
    B_80192F80_usa->unk_18 = 6;
    B_80192F80_usa->unk_04 = 0;
    B_80192F80_usa->unk_08 = (B_8019CF98_usa == 0x10) ? -1 : 0;

    if (((gTheGame.menu[0].unk_4 == 1) && (B_80192F80_usa->unk_18 = 0, (gTheGame.menu[0].unk_4 == 1))) ||
        (gSelection == 0x96) || (((gSelection == 0xA0) || (gSelection == 0xB4)) != 0) || (gSelection == 0xC8)) {
        if (gTheGame.menu[0].unk_4 < 0xF) {
            var_v0 = D_800B67E4_usa[gTheGame.menu[0].unk_4 - 1];
        } else {
            var_v0 = 0;
        }
        B_8019CF98_usa = var_v0;

        if (B_8019CF98_usa >= ARRAY_COUNTU(D_800B67B4_usa)) {
            B_8019CF98_usa = 0;
        }
        func_8001FD0C_usa(&D_800B6790_usa, D_800B67B4_usa[B_8019CF98_usa], 0, 0x800054, 0x140, 0xE8, heapP);
    }

    if (screenLoad("RESULT.SBF", heapP) != 0) {
        var_s0 = -1;

        if (gSelection == 0x8C) {
            sprintf(sp20, "REWARD-MARATHON");
        } else if (gSelection == 0xBE) {
            gPlayer[0]->unk_010 |= 1;
            sprintf(sp20, "REWARD-TIMEZONE");
        } else if (gSelection == 0xAA) {
            if (arg1 == 9) {
                var_s0 = 0;
                B_80192F80_usa->unk_18 = -1;
                sprintf(sp20, "MOVIE");
            } else {
                sprintf(sp20, "KEY");
            }
        } else if (gSelection == 0x82) {
            sprintf(sp20, "DIPLOMA-%d", arg1 - 1);
        } else if (gSelection == 0x96) {
            if (arg1 == 8) {
                sprintf(sp20, "RESULT-DONE");
            } else if (arg1 == 1) {
                sprintf(sp20, "ELITEFOUR");
            } else {
                var_s0 = (gTheGame.menu[0].unk_4 > 1) ? -1 : 0;
                sprintf(sp20, "RESULT%d", gTheGame.menu[0].unk_4 - 1);
            }
        } else if ((gSelection == 0xA0) || (gSelection == 0xB4) || (gSelection == 0xC8)) {
            sprintf(sp20, "2P-WINNER");
            B_80192F80_usa->unk_20 = NULL;
        } else {
            osSyncPrintf("resultSetup: INTERNAL ERROR! Unknown 'gSelection' (%d)\n", gSelection);
        }

        B_80192F80_usa->unk_0C = screenSet(sp20, 0xFF401);
        if (var_s0 != 0) {
            B_80192F80_usa->unk_00 = 0;
            B_80192F80_usa->unk_18 = 1;
            screenHideText(B_80192F80_usa->unk_0C, 0x64);
            screenHideImage(B_80192F80_usa->unk_0C, 0x82);
            screenHideImage(B_80192F80_usa->unk_0C, 0x8C);
            screenHideImage(B_80192F80_usa->unk_0C, 0x208);
            func_800289C0_usa(B_80192F80_usa->unk_0C, 0x64, &sp40, &sp44);
            B_80192F80_usa->unk_14 = sp40;
            screenSetImagePosition(B_80192F80_usa->unk_0C, 0x64, -0xBE, sp44);
            screenSetImagePosition(B_80192F80_usa->unk_0C, 0x6E, 0x140, 0xB0);
            screenSetImagePosition(B_80192F80_usa->unk_0C, 0x78, 0, -0x99);
            screenSetImagePosition(B_80192F80_usa->unk_0C, 0x79, 0, 0xF0);
            B_80192F80_usa->unk_04 = -1;
        }
    }

    func_80002D8C_usa(0x1E);

    if (gSelection == 0x96) {
        if ((gTheGame.menu[0].unk_4 < 2) || ((arg1 ^ 1) == 0)) {
            PlayMIDI(BGM_INIT_TABLE, 0x46, 0, 2);
        } else {
            PlayMIDI(BGM_INIT_TABLE, 0x41, 0, 1);
        }
    } else {
        if ((gSelection == 0xA0) || (gSelection == 0xB4) || (gSelection == 0xC8)) {
            PlayMIDI(BGM_INIT_TABLE, 0x46, 0, 2);
        } else {
            PlayMIDI(BGM_INIT_TABLE, 0x41, 0, 1);
        }
    }
}
