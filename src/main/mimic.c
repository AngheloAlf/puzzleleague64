/**
 * Original filename: mimic.c
 */

#include "mimic.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "segment_symbols.h"

#include "ai.h"
#include "animate.h"
#include "animate2d.h"
#include "animate3d.h"
#include "animation.h"
#include "buffers.h"
#include "character.h"
#include "combo.h"
#include "dlist.h"
#include "info.h"
#include "init2d.h"
#include "other.h"
#include "peel.h"
#include "screen.h"
#include "sfxlimit.h"
#include "sound.h"
#include "tetsound.h"
#include "the_game.h"
#include "tutorial.h"
#include "update.h"
#include "update3d.h"

INLINE void SetupMimic(void **heapP) {
    s32 temp_a0;

    B_801C6EE8_usa = 1;
    B_801C6E58_usa = 1;
    Pon_Image_Heap = &gBufferHeap[SEGMENT_ROM_SIZE(segment_0CA4A0)];

    temp_a0 = gGameStatus & 0x40;
    gGameStatus = gGameStatus << 0x10;
    if (temp_a0 != 0) {
        gGameStatus |= 0x40;
    }

    func_80054624_usa();
    InitCharacter(0x385, -1);
    LoadFairySoundData(0x19, 9, 9);

    *heapP = Pon_Image_Heap;
}

INLINE void QuitMimic(void) {
    gGameStatus = gGameStatus >> 0x10;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80083050_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_8008336C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_800833B0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_800833E0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_800836FC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80083740_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80081B00_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80081E1C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80081E60_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80081CC0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80081FDC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80082020_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", UpdateMT);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", UpdateMT);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", UpdateMT);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", UpdateMT);
#endif

void UpdateMTController(tetWell *well, cursor_t *cursor, s32 num) {
    gamepad_t *gamepad = &gTheGame.controller[num];
    u16 t_button = gamepad->touch_button;
    u16 h_button = gamepad->hold_button;
    s32 sound = 0;

    if (gTheGame.unk_9C0C == 1) {
        if (brainbrain[num].unk_00C == -1) {
            if (h_button & U_JPAD) {
                sound = Move2DCursorUp(well, cursor, gamepad->unk_08);
            } else if (h_button & D_JPAD) {
                sound = Move2DCursorDown(cursor, gamepad->unk_08);
            } else if (h_button & L_JPAD) {
                sound = Move2DCursorLeft(cursor, gamepad->unk_08);
            } else if (h_button & R_JPAD) {
                sound = Move2DCursorRight(cursor, gamepad->unk_08);
            }

            if (t_button & (A_BUTTON | B_BUTTON)) {
                Switch2DBlocks(well, cursor, num);
            }
        } else {
            UpdateMT(well, cursor, &brainbrain[num]);
        }

        Update2DSwitching(well, cursor);
    } else {
        if (brainbrain[num].unk_00C == -1) {
            if (h_button & U_JPAD) {
                sound = Move3DCursorUp(well, cursor, gamepad->unk_08);
            } else if (h_button & D_JPAD) {
                sound = Move3DCursorDown(cursor, gamepad->unk_08);
            } else if (h_button & L_JPAD) {
                sound = Move3DCursorLeft(cursor, gamepad->unk_08);
            } else if (h_button & R_JPAD) {
                sound = Move3DCursorRight(cursor, gamepad->unk_08);
            }

            if (t_button & (A_BUTTON | B_BUTTON)) {
                Switch3DBlocks(well, cursor, num);
            }
        } else {
            UpdateMT(well, cursor, &brainbrain[num]);
        }

        Update3DSwitching(well, cursor);
    }

    if (sound != 0) {
        PlaySE(SFX_INIT_TABLE, 0x96);
    }

    cursor->unk_24--;
    if (cursor->unk_24 == 0) {
// TODO: REGION_NTSC?
#if VERSION_USA
        cursor->unk_24 = 0xF;
#else
        cursor->unk_24 = 0xD;
#endif
        cursor->unk_20 ^= 1;
    }
}

void DoMT(void) {
    typedef struct Padding {
        s32 unk_0;
        s32 unk_4;
    } Padding;
    cursor_t *cursor;
    tetWell *well;
    s32 count;
    s32 num;
    s32 total = 1;
    Padding pad UNUSED = { 0, 0 };

    if (gSelection == 0x6E) {
        MimicCheckState(&gTheGame.tetrisWell[0], &gTheGame.cursorBlock[0]);
    } else {
        TutorialCheckState(&gTheGame.tetrisWell[0], &gTheGame.cursorBlock[0]);
    }

    if (gMain == GMAIN_2BC) {
        return;
    }

    if ((gSelection == 0x64) && (gTheGame.unk_9C28 == 3)) {
        total = 2;
    }

    for (num = 0; num < total; num++) {
        well = &gTheGame.tetrisWell[num];
        cursor = &gTheGame.cursorBlock[num];

        if (cursor->unk_00 != 0x34C) {
            CompactWell(well, num);
        }

        if (num == 0) {
            UpdateMTController(well, cursor, num);
        }

        if (cursor->unk_00 != 0x34C) {
            if (well->unk_43C4 != 0) {
                CheckCollision(well);
            }

            well->unk_43C4 = 0;
            CheckChainCounter(well, cursor);
            count = ComboCount(well, cursor);
            well->unk_43BC = 0;

            if (gSelection == 0x64) {
                CheckShake(well, cursor);
            }

            CheckIcon(well, count);
            StartAttack(well, num);
            UpdateWell(well, cursor, num, count);

            if (gSelection == 0x64) {
                ChangeAttack(well, cursor, num, count);
            }
            UpdateCursor(well, cursor);
            UpdateIcon(well, cursor, num);
            if (gSelection == 0x64) {
                UpdateAttack(well, cursor, num);
            }
            UpdateExplosion(well);
            UpdateDistance(well, cursor);
            UpdateAnimation(well, num, 0);
            UpdateMiscStuff(well, cursor, num);
            if ((cursor->unk_00 <= 0) && (well->unk_43F8 >= (gTheGame.unk_9C0C * 0x10))) {

                well->unk_43C4 = -1;

                AddNewRow(well, cursor, num);
                well->unk_43F8 = 0;
            }

            if (gTheGame.unk_9C0C == 2) {
                Check3DVisibleBlocks(well, cursor);
            }

            well->unk_43FC = 0;
            well->unk_43A4 = 0;
        }
    }
}

void MimicCheckState(tetWell *well, cursor_t *cursor) {
    s32 result;

    if (well->unk_43A8 < cursor->unk_28) {
        cursor->unk_28 = well->unk_43A8;
    }

    if (!CheckFieldActive(well)) {
        if ((brainbrain[0].unk_00C == -1) && (well->unk_43A8 == 0)) {
            if (brainbrain[0].unk_03C == 5) {
                if (cursor->unk_2C == 0) {
                    return;
                }
                result = (cursor->unk_2C == cursor->unk_30) ? -1 : 0;
            } else if (cursor->unk_28 != 0) {
                result = ((-cursor->unk_30 >= cursor->unk_28)) ? -1 : 0;
            } else if (cursor->unk_2C != 0) {
                result = 0;
            } else {
                return;
            }

            if (result != 0) {
                cursor->unk_00 = 7;
                B_801C7348_usa++;
                B_801C7348_usa %= 5;
                func_80005888_usa(0, 2, B_801C7348_usa + 5);
            } else {
                cursor->unk_00 = 8;
                PlaySE(SFX_INIT_TABLE, 0xA0);
            }

            gMain = GMAIN_2BC;
        } else if (brainbrain[0].unk_104 < 0) {
            brainbrain[0].unk_00C = -1;
            brainbrain[0].unk_104 = 0;
            if (well->unk_43A8 == -3) {
                PlaySE(SFX_INIT_TABLE, 0x12C);
            } else if (well->unk_43A8 == -4) {
                PlaySE(SFX_INIT_TABLE, 0x12D);
            } else if (well->unk_43A8 < -4) {
                PlaySE(SFX_INIT_TABLE, 0x12E);
            }

            gMain = GMAIN_2BC;
        }
    }

    if (gMain == GMAIN_2BC) {
        Init2DIcons(well);
        Init2DExplosion(well);
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084C18_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084C84_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084D24_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", Draw2DMT);
#endif

#if VERSION_USA
#if 0
// ? Draw3DFrontTetrisWell(s32, ?);                        /* extern */
// ? Draw3DBackTetrisWell(s32, ?);                        /* extern */
// ? Draw3DTetrisNewBlock(s32, f32 *, u16, s32);          /* extern */
// ? Draw3DCursor(s32, ?);                        /* extern */
// ? Draw3DIcon(s32, ?);                        /* extern */
// ? Draw3DExplosion(s32, ?, ?, ?);                  /* extern */
// gIdent?
extern s32 gIdent; // uObjBg?

// shade3d?
extern s32 D_01024CB0_usa;

void Draw3DMT(struct_gInfo_unk_00068 *dynamicp) {
    u16 sp28;
    UNK_TYPE *var_t4;
    Gfx *temp_a2;
    Gfx *temp_t2;
    Gfx *temp_v0;
    Gfx *temp_v0_2;
    Gfx *temp_v1_3;
    Gfx *temp_v1_4;
    Gfx *temp_v1_5;
    Gfx *temp_v1_6;
    Gfx *temp_v1_7;
    Mtx *temp_s0;
    Mtx *temp_s0_2;
    Mtx *temp_s1;
    enum enum_gMain var_v0;
    s32 temp_a3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a3;
    s32 var_t0;
    s32 var_t3;

    gDPPipeSync(glistp++);
    gDPSetTextureFilter(glistp++, G_TF_BILERP);

    if (gSelection == 0x64) {
        var_t4 = &D_01024CB0_usa;
        

        gDPPipeSync(glistp++);
        gDPSetTextureLUT(glistp++, G_TT_NONE);
        gDPSetTexturePersp(glistp++, G_TP_NONE);
        gDPSetCycleType(glistp++, G_CYC_1CYCLE);
        gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_NOOP2);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
        gDPSetPrimColor(glistp++, 0, 0, 50, 50, 50, 255);

        for (var_t3 = 0; var_t3 < 0xBD; var_t3 += 0x20) {
            var_t0 = 0xBD - var_t3;
            if (var_t0 >= 0x21) {
                var_t0 = 0x20;
            }

            temp_v1 = var_t0 << 7;
            var_a3 = (temp_v1 >> 1) - 1;

#if 0
            temp_a2->words.w0 = 0xFD900000;
            temp_a2->words.w1 = (u32) var_t4;
            temp_a2->unk_8 = 0xF5900000;
            temp_a2->unk_C = 0x07000000;
            temp_a2->unk_10 = 0xE6000000;
            temp_a2->unk_14 = 0x00000000;

            temp_a2->unk_18 = 0xF3000000;
#endif
            if (var_a3 >= 0x800) {
                var_a3 = 0x7FF;
            }
            var_t4 += temp_v1;
            temp_v1_2 = var_t3 + var_t0;

#if 0

            temp_a2->unk_1C = (s32) (((var_a3 & 0xFFF) << 0xC) | 0x07000080);

            gDPPipeSync(glistp++);

            temp_a2->unk_28 = 0xF5882000;
            temp_a2->unk_2C = 0x00000000;
            temp_a2->unk_30 = 0xF2000000;
            temp_a2->unk_34 = (s32) ((((var_t0 - 1) * 4) & 0xFFF) | 0x001FC000);
#endif
            gDPLoadTextureBlock(glistp++, var_t4, G_IM_FMT_I, G_IM_SIZ_16b, 128, var_t0, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

#if 0
            temp_a2->unk_38 = (s32) ((((temp_v1_2 + 0x20) * 4) & 0xFFF) | 0xE425C000);
            temp_a2->unk_3C = (s32) (((var_t3 * 4) & 0xFFF) | 0x5C000);
            temp_a2->unk_40 = 0xB4000000;
            temp_a2->unk_44 = 0;
            temp_a2->unk_48 = 0xB3000000;
            temp_a2->unk_4C = 0x04000400;
#endif

            gSPTextureRectangle(glistp++, 0x005C, (var_t3 * 4), 0x025C, ((temp_v1_2 + 0x20) * 4), G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        }
    }

    temp_s0 = &dynamicp->unk_10100;

    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
    gDPSetAlphaCompare(glistp++, G_AC_THRESHOLD);

    gTransMtx[3][0] = -0.51f;
    gTransMtx[3][1] = (f32) ((f64) gTheGame.tetrisWell[0].unk_4088 + 0.01);
    guMtxF2L(gTransMtx, temp_s0);
    temp_s1 = dynamicp + 0x10000;

    gSPBgRect1Cyc(glistp++, temp_s0);

    guPerspective(temp_s1, &sp28, 33.0f, 0.88f, 10.0f, 3000.0f, 1.0f);
    temp_s0_2 = dynamicp + 0x10080;
    guLookAt(temp_s0_2, 0.0f, 0.0f, 900.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    temp_a3 = dynamicp + 0x10180;

    gSPPerspNormalize(glistp++, sp28);
    gSPMatrix(glistp++, temp_s1, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gSPMatrix(glistp++, temp_s0_2, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 31, 320, 221);

    gDPPipeSync(glistp++);

    gDPSetCombineMode(glistp++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);

    gSPBgRect1Cyc(glistp++, &gIdent);
    gSPMatrix(glistp++, temp_a3, G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);


    Draw3DTetrisNewBlock(dynamicp, &gTheGame.tetrisWell[0]);
    if (anim_bg != 0) {
        gMain = GMAIN_38E;
    }
    Draw3DBackTetrisWell(dynamicp, 0);
    Draw3DFrontTetrisWell(dynamicp, 0);

    var_v0 = GMAIN_TUTORIAL;
    if (gSelection == 0x6E) {
        var_v0 = GMAIN_MIMIC;
    }
    gMain = var_v0;

    gDPPipeSync(glistp++);
    gDPSetRenderMode(glistp++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

    Draw3DIcon(dynamicp, 0);

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 7, 320, 239);

    gDPPipeSync(glistp++);
    gDPSetTexturePersp(glistp++, G_TP_NONE);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(glistp++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetAlphaCompare(glistp++, G_AC_THRESHOLD);

    Draw3DExplosion(dynamicp, 0);

    gDPSetTextureLUT(glistp++, G_TT_NONE);

    Draw3DCursor(dynamicp);

    gSPTexture(glistp++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", Draw3DMT);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80085CC8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80084FD0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_8008503C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_800850DC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", Draw2DMT);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", Draw3DMT);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80086080_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_800836F0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_8008375C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_800837FC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", Draw2DMT);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", Draw3DMT);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_800847A0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_800838B0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_8008391C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_800839BC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", Draw2DMT);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", Draw3DMT);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80084960_ger);
#endif

void DrawMT(struct_gInfo_unk_00068 *dynamicp) {
    tut_dynamicp = dynamicp;
    screenDraw(&glistp, DrawTUT);

    if (screenFlushing()) {
        return;
    }

    if ((gMain == GMAIN_MIMIC) && (geModeMimic >= MM_STAGE)) {
        if (gTheGame.unk_9C0C == 1) {
            Draw2DMT(dynamicp);
        } else {
            Draw3DMT(dynamicp);
        }

        if (!screenFlushing()) {
            func_8002C2C0_usa(&glistp);
        }
    }

    func_8002C2C0_usa(&glistp);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", DoMimic);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", DoMimic);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", DoMimic);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", DoMimic);
#endif

const char RO_800C76E4_usa[] = "MIMIC?.SBF";

// maybe mimicShowText?
STATIC_INLINE void inlined_function() {
    u32 nType;
    s32 temp_s0;
    s32 temp_s0_2;

    giScreenMimic = screenSet("MIMIC", 0x401);
    temp_s0 = gnTagTextMimic;
    geModeMimic = MM_NONE;
    B_80193014_usa = 0;
    gnTagTextMimic = (gTheGame.unk_9C2C[0][1] * 0xA) + 0x1EA;
    if (screenGetTextType(giScreenMimic, gnTagTextMimic, &nType)) {
        screenHideText(giScreenMimic, -0x3FFFFE0C);
        screenShowText(giScreenMimic, gnTagTextMimic);
    } else {
        gnTagTextMimic = temp_s0;
    }

    temp_s0_2 = ((B_8019300C_usa & 0xFFFF) == 0x258) ? 0x259 : 0x258;
    if ((B_8019300C_usa == 0) || ((B_8019300C_usa >> 0x10) != 0)) {
        B_8019300C_usa = temp_s0_2;
        func_80028DC0_usa(giScreenMimic, temp_s0_2, 0);
        func_800288D8_usa(giScreenMimic, temp_s0_2, 0x9E, 0x48);
    }
}

void InitMimic(void) {
    void *sp10;
    char *temp;

    gnTagTextMimic = -1;
    B_80192FF0_usa = 0;
    B_8019300C_usa = 0;
    B_80193004_usa = 0;
    B_80193000_usa = 0;
    B_80192FFC_usa = 0;
    B_80192FF8_usa = 0;

    SetupMimic(&sp10);

    //! @bug: Modifies a `const` symbol.
    // cast const away
    temp = (char *)RO_800C76E4_usa;
    temp[5] = gTheGame.unk_9C2C[0][1] + '0';

    if (screenLoad(temp, &sp10) != 0) {
        inlined_function();
    }

    if (B_8021B960_usa != 0x40) {
        func_80002D8C_usa(0x1E);
        PlayMIDI(BGM_INIT_TABLE, 0x40, 0, 1);
    }
}