#include "043000.h"

#include "macros_defines.h"
#include "main_variables.h"

#include "image.h"
#include "peel.h"
#include "screen.h"
#include "segment_symbols.h"
#include "sfxlimit.h"
#include "sound.h"
#include "story.h"
#include "the_game.h"

typedef struct struct_80192F90_unk_04 {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ s32 unk_8;
    /* 0xC */ s32 unk_C;
} struct_80192F90_unk_04; // size = 0x10

typedef struct struct_80192F90 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ struct_80192F90_unk_04 unk_04;
    /* 0x14 */ struct_80192F90_unk_04 unk_14;
    /* 0x24 */ struct_80192F90_unk_04 unk_24;
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ s32 unk_40;
} struct_80192F90; // size = 0x44

extern struct_80192F90 *B_80192F90_usa;

struct_imageLoad_arg0 *D_800B6800_usa = NULL;

s32 D_800B6804_usa = 0;

RomOffset D_800B6808_usa[] = {
    SEGMENT_ROM_START(segment_background_35C3F0), SEGMENT_ROM_START(segment_background_3807F0),
    SEGMENT_ROM_START(segment_background_3A4BF0), SEGMENT_ROM_START(segment_background_3C8FF0),
    SEGMENT_ROM_START(segment_background_3ED3F0), SEGMENT_ROM_START(segment_background_4117F0),
    SEGMENT_ROM_START(segment_background_435BF0), SEGMENT_ROM_START(segment_background_459FF0),
    SEGMENT_ROM_START(segment_background_47E3F0), SEGMENT_ROM_START(segment_background_4A27F0),
    SEGMENT_ROM_START(segment_background_4C6BF0), SEGMENT_ROM_START(segment_background_4EAFF0),
};

void func_80042FD4_usa(Gfx **gfxP, s32 arg1, s32 arg2);

void func_80042400_usa(Gfx **gfxP) {
    screenDraw(gfxP, func_80042FD4_usa);
}

void func_80042428_usa(struct_80192F90_unk_04 *arg0) {
    if (arg0->unk_8 == 0) {
        switch (arg0->unk_C) {
            case 0x0:
                if (arg0->unk_0 == -0x8C) {
                    PlaySE(SFX_INIT_TABLE, 0xA4);
                }
                arg0->unk_0 += 0xA;
                break;
            case 0x1:
                if (B_80192F90_usa->unk_04.unk_0 < -0x64) {

                } else {
                    arg0->unk_0 += 0xA;
                }
                break;
            case 0x2:
                if (B_80192F90_usa->unk_04.unk_0 >= -0x32) {
                    if (arg0->unk_0 == -0x96) {
                        PlaySE(SFX_INIT_TABLE, 0xA4);
                    }
                    arg0->unk_0 += 0xA;
                }
                break;
        }
        if (arg0->unk_0 >= 0) {
            arg0->unk_0 = 0;
            arg0->unk_4 = 0;
            arg0->unk_8 = 1;
            if ((arg0->unk_C == 1) && (B_80192F90_usa->unk_40 < 2)) {
                func_80005608_usa(gTheGame.menu[0].unk_4, 2);
            }
        }
    } else if (arg0->unk_8 == 1) {
        arg0->unk_4++;
        if (arg0->unk_4 % 2 == 0) {
            arg0->unk_0 = 2;
        } else {
            arg0->unk_0 = -2;
        }
        if (arg0->unk_4 >= 0xD) {
            arg0->unk_0 = 0;
            arg0->unk_4 = 0;
            arg0->unk_8 = 2;
            if (arg0->unk_C == 0) {
                if (B_80192F90_usa->unk_40 >= 2) {
                    if (B_80192F90_usa->unk_40 == 5) {
                        func_80005608_usa(0xF, 2);
                    } else {
                        func_80005780_usa(gTheGame.menu[0].unk_4);
                    }
                }
            }
        }
    } else if (arg0->unk_8 == 3) {
        arg0->unk_4++;
        if (arg0->unk_4 >= 0xD) {
            arg0->unk_4 = 0;
            arg0->unk_8 = 4;
            if (arg0->unk_C == 0) {
                PlaySE(SFX_INIT_TABLE, 0xA3);
            }
        }
    } else if (arg0->unk_8 == 4) {
        if (B_80192F90_usa->unk_40 >= 2) {
            arg0->unk_0 -= 0xC;
            if (arg0->unk_0 < -0x95) {
                arg0->unk_0 = -0x96;
                arg0->unk_8 = 5;
            }
        } else {
            arg0->unk_8 = 5;
        }
    }
}

void func_80042660_usa(void) {
    func_80042428_usa(&B_80192F90_usa->unk_04);
    func_80042428_usa(&B_80192F90_usa->unk_14);
    func_80042428_usa(&B_80192F90_usa->unk_24);

    if ((D_800B6804_usa < 2) && ((B_80192F90_usa->unk_40 == 1) || (B_80192F90_usa->unk_04.unk_8 < 2))) {
        screenSetImagePosition(B_80192F90_usa->unk_00, 0xC8, B_80192F90_usa->unk_04.unk_0, 0x32);
        screenSetImagePosition(B_80192F90_usa->unk_00, 0x190, B_80192F90_usa->unk_04.unk_0, 0x2E);
    } else {
        screenSetImagePosition(B_80192F90_usa->unk_00, 0xC8, 0, 0x32);
        screenSetImagePosition(B_80192F90_usa->unk_00, 0x190, 0, 0x2E);
    }

    if ((B_80192F90_usa->unk_40 == 5) && (B_80192F90_usa->unk_04.unk_8 >= 3)) {
        screenSetImagePosition(B_80192F90_usa->unk_00, 0xC9, 0xDD, 0x32);
        screenSetImagePosition(B_80192F90_usa->unk_00, 0x191, 0xD9, 0x2E);
    } else {
        screenSetImagePosition(B_80192F90_usa->unk_00, 0xC9, 0xDD - B_80192F90_usa->unk_14.unk_0, 0x32);
        screenSetImagePosition(B_80192F90_usa->unk_00, 0x191, 0xD9 - B_80192F90_usa->unk_14.unk_0, 0x2E);
    }
}

s32 func_800427E4_usa(void) {
    u32 sp10;
    struct_gaScreen_unk_1C *sp14;

    if (screenTextDone(B_80192F90_usa->unk_00, B_80192F90_usa->unk_3C + 0x64)) {
        screenHideText(B_80192F90_usa->unk_00, B_80192F90_usa->unk_3C + 0x64);
        B_80192F90_usa->unk_3C++;

        if (screenGetTextType(B_80192F90_usa->unk_00, B_80192F90_usa->unk_3C + 0x64, &sp10)) {
            screenShowText(B_80192F90_usa->unk_00, B_80192F90_usa->unk_3C + 0x64);
            return 0;
        }

        return 1;
    } else if (screenFindImage(B_80192F90_usa->unk_00, B_80192F90_usa->unk_3C + 0x64, &sp14)) {
        sp14->unk_44 &= ~0x1000;
    }
    return 0;
}

void func_800428B4_usa(s32 arg0 UNUSED) {
    u32 sp10;
    u16 temp_v1;

    screenHideImage(B_80192F90_usa->unk_00, 0x12D);

    if (B_80192F90_usa->unk_34-- > 0) {
        return;
    }

    if (B_80192F90_usa->unk_34 < -0x64) {
        B_80192F90_usa->unk_34 = -0x64;
    }
    if (B_80192F90_usa->unk_38 == 1) {
        screenShowImage(B_80192F90_usa->unk_00, 0x12D);
    }

    screenHideImage(B_80192F90_usa->unk_00, 0x3E8);
    if ((peelActive() == 0) && !func_80024C14_usa()) {
        func_80042660_usa();
        if ((B_80192F90_usa->unk_34 < -0x14) && (B_80192F90_usa->unk_38 == 0)) {
            B_80192F90_usa->unk_38 = 1;
            screenShowText(B_80192F90_usa->unk_00, 0x64);
            screenShowText(B_80192F90_usa->unk_00, 0x384);
            screenShowText(B_80192F90_usa->unk_00, 0x385);
            screenShowText(B_80192F90_usa->unk_00, 0x386);
        }
    }

    if (B_80192F90_usa->unk_14.unk_8 == 2) {
        temp_v1 = gTheGame.controller[0].touch_button;
        if (temp_v1 & 0x8000) {
            if ((B_80192F90_usa->unk_38 > 0) && (func_800427E4_usa() != 0)) {
                screenHideText(B_80192F90_usa->unk_00, 0x384);
                screenHideText(B_80192F90_usa->unk_00, 0x385);
                screenHideText(B_80192F90_usa->unk_00, 0x386);
                B_80192F90_usa->unk_14.unk_8 = 3;
                B_80192F90_usa->unk_04.unk_8 = 3;
                B_80192F90_usa->unk_38 = 3;
                PlaySE(SFX_INIT_TABLE, 2);
            }
        } else if (temp_v1 & 0x1000) {
            if (B_80192F90_usa->unk_38 == 3) {
                return;
            }

            B_80192F90_usa->unk_38 = 3;
            B_80192F90_usa->unk_14.unk_8 = 3;
            B_80192F90_usa->unk_04.unk_8 = 3;
            PlaySE(SFX_INIT_TABLE, 2);
            screenHideText(B_80192F90_usa->unk_00, B_80192F90_usa->unk_3C + 0x64);
            screenHideText(B_80192F90_usa->unk_00, 0x384);
            screenHideText(B_80192F90_usa->unk_00, 0x385);
            screenHideText(B_80192F90_usa->unk_00, 0x386);
        } else if (screenTextDone(B_80192F90_usa->unk_00, B_80192F90_usa->unk_3C + 0x64) &&
                   screenGetTextType(B_80192F90_usa->unk_00, B_80192F90_usa->unk_3C + 0x65, &sp10)) {
            screenShowImage(B_80192F90_usa->unk_00, 0x3E8);
        }
    }

    if (B_80192F90_usa->unk_14.unk_8 == 5) {
        D_800B6804_usa = B_80192F90_usa->unk_40;
        if ((B_80192F90_usa->unk_40 >= 2) && (B_80192F90_usa->unk_40 != 5)) {
            func_8002B85C_usa(3, 0);
        } else if ((gTheGame.menu[0].unk_0 >= 4) && (gTheGame.menu[0].unk_4 >= 0x10)) {
            gMain = GMAIN_384;
            gReset = -1;
            gTheGame.unk_9C0C = 1;
            gSelection = 0x96;
            gTheGame.unk_9C08 = 2;
            gTheGame.menu[0].unk_C = 1;
        } else {
            func_8002B85C_usa(4, 0);
        }
    }
}

void func_80042C24_usa(void **heapP, u32 arg1) {
    char sp20[0x20];

    *heapP = ALIGN_TO(*heapP, struct_80192F90);
    B_80192F90_usa = (struct_80192F90 *)*heapP;
    *heapP += sizeof(struct_80192F90);

    B_80192F90_usa->unk_40 = arg1;
    if (arg1 == 0) {
        func_8001FD0C_usa(&D_800B6800_usa, D_800B6808_usa[B_8019CF98_usa], 0, 0x800054, 0x140, 0xE8, heapP);
        if (screenLoad("OPPONENT.SBF", heapP) != 0) {
            sprintf(sp20, "TRANSITION%d", gTheGame.menu[0].unk_4);
            B_80192F90_usa->unk_00 = screenSet(sp20, 0xFF001);
            func_80028DC0_usa(B_80192F90_usa->unk_00, 0xC9, 1);

            B_80192F90_usa->unk_14.unk_C = 1;
            B_80192F90_usa->unk_24.unk_C = 2;
            B_80192F90_usa->unk_04.unk_C = 0;
            B_80192F90_usa->unk_24.unk_0 = -0x96;
            B_80192F90_usa->unk_14.unk_0 = -0x96;
            B_80192F90_usa->unk_04.unk_0 = -0x96;
            B_80192F90_usa->unk_24.unk_8 = 0;
            B_80192F90_usa->unk_14.unk_8 = 0;
            B_80192F90_usa->unk_04.unk_8 = 0;

            func_80042660_usa();
            B_80192F90_usa->unk_34 = 0x32;
            B_80192F90_usa->unk_38 = 0;
            B_80192F90_usa->unk_3C = 0;
        }
    } else {
        DATA_INLINE_CONST2 s16 sp40[] = {
            0x0000, 0x0005, 0x0006, 0x0007, 0x0001, 0x000A, 0x0002,
            0x0009, 0x0000, 0x0003, 0x0004, 0x0002, 0x0008, 0x000B,
        };

        if (gTheGame.menu[0].unk_4 >= 0xF) {
            B_8019CF98_usa = 0;
        } else {
            B_8019CF98_usa = sp40[gTheGame.menu[0].unk_4 - 1];
        }

        func_8001FD0C_usa(&D_800B6800_usa, D_800B6808_usa[B_8019CF98_usa], 0, 0x800054, 0x140, 0xE8, heapP);

        if (screenLoad("OPPONENT.SBF", heapP) != 0) {
            switch (arg1) {
                case 0x2:
                    B_80192F90_usa->unk_00 = screenSet("GARYLOSE", 0xFF001);
                    break;

                case 0x5:
                    B_80192F90_usa->unk_00 = screenSet("GARYWIN", 0xFF001);
                    break;

                case 0x3:
                    B_80192F90_usa->unk_00 = screenSet("TRACEYLOSE", 0xFF001);
                    break;

                case 0x4:
                    B_80192F90_usa->unk_00 = screenSet("TEAMROCKETLOSE", 0xFF001);
                    break;

                default:
                    sprintf(sp20, "TRANSITION%d", gTheGame.menu[0].unk_4);
                    B_80192F90_usa->unk_00 = screenSet(sp20, 0xFF001);
                    break;
            }

            func_80028DC0_usa(B_80192F90_usa->unk_00, 0xC9, 1);
            B_80192F90_usa->unk_14.unk_C = 1;
            B_80192F90_usa->unk_24.unk_C = 2;
            B_80192F90_usa->unk_04.unk_C = 0;
            B_80192F90_usa->unk_24.unk_0 = -0x96;
            B_80192F90_usa->unk_14.unk_0 = -0x96;
            B_80192F90_usa->unk_04.unk_0 = -0x96;
            B_80192F90_usa->unk_24.unk_8 = 0;
            B_80192F90_usa->unk_14.unk_8 = 0;
            B_80192F90_usa->unk_04.unk_8 = 0;

            func_80042660_usa();
            B_80192F90_usa->unk_34 = 0x32;
            B_80192F90_usa->unk_38 = 0;
            B_80192F90_usa->unk_3C = 0;

            func_80002D8C_usa(0x1E);
            PlayMIDI(BGM_INIT_TABLE, 0x3D, 0, 1);
        }
    }
}

void func_80042FD4_usa(Gfx **gfxP, s32 arg1 UNUSED, s32 arg2) {
    Gfx *gfx;

    if (arg2 == 0x1F4) {
        gfx = *gfxP;

        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetAlphaCompare(gfx++, G_AC_NONE);
        gDPSetPrimColor(gfx++, 0, 0, 0, 0, 0, 255);
        gDPSetRenderMode(gfx++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gSPClearGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_SHADING_SMOOTH);
        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH, 20);
        *gfxP = gfx;

        imageDraw(D_800B6800_usa, gfxP, 0, 0, NULL);
    }
}
