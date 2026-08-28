/**
 * Original filename: mimic.c
 */

#include "mimic.h"

#include "include_asm.h"
#include "macros_defines.h"
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
#include "puzzle.h"
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
void LoadMimic1(s32 kind, s32 level, s32 number, s32 play) {
    s32 temp_s0;
    s32 temp_v0;
    s32 var_v0;
    ai_t *var_s5;
    cursor_t *cursor;
    tetWell *well;

#if 0
    // Local variables
    int base; // r1+0x8
    int index; // r20
    struct tetWell * well; // r27
    struct cursor_t * cursor; // r24
    struct ai_t * brain; // r23
    char * pHeap; // r30
#endif

    gCounter = 0;
    gMax = 6;
    InitGameStateVar();
    well = gTheGame.tetrisWell;
    cursor = gTheGame.cursorBlock;
    gTheGame.unk_9B48 = 0;
    gTheGame.unk_9B50[0].b.frameH = 0;
    gTheGame.unk_9B50[1].b.frameH = 0;
    chain_check[0] = 0;
    chain_check[1] = 0;
    anim_bg = 0;
    anim_sp = 0;
    gTheGame.tetrisWell[0].unk_43B0 = 0;
    gTheGame.tetrisWell[0].unk_43A8 = 0;
    gTheGame.tetrisWell[0].unk_43A4 = 0;
    gTheGame.tetrisWell[0].unk_43B4 = 0;
    gTheGame.tetrisWell[0].unk_43B8 = 0;
    gTheGame.tetrisWell[0].unk_43BC = 0;
    gTheGame.tetrisWell[0].unk_43C0 = 0;
    gTheGame.tetrisWell[0].unk_43C4 = 0;
    gTheGame.tetrisWell[0].unk_43F4 = 0;
    gTheGame.tetrisWell[0].unk_441C = 0xDF;
    gTheGame.tetrisWell[0].unk_43F8 = 0;
    gTheGame.tetrisWell[0].unk_43FC = 0;
    gTheGame.totalPlayer = 2;

    InitCursor(cursor);
    Init2DCursor(cursor, 0);
    Init2DTetrisBlocks(well, 0);
    Init2DNewRow(well);
    Init2DIcons(well);
    Init2DAttackBlocks(well);
    Init2DExplosion(well);
    var_s5 = brainbrain;

    if (level == 1) {
        var_v0 = 0;
    } else if (level == 2) {
        var_v0 = 5;
    } else if (level == 3) {
        var_v0 = 0xA;
    } else {
        var_v0 = 0xE;
    }
    temp_s0 = var_v0 + number;

    if (play == 0) { // play == demo
        // FAKE?
        do {
            switch (kind) {
                case MIMIC_COMBO:
                    Init2DPuzzle(well, cursor, demo_data_combo, temp_s0);
                    temp_s0--;
                    break;
                case MIMIC_CHAIN:
                    Init2DPuzzle(well, cursor, demo_data_chain, temp_s0);
                    temp_s0--;
                    break;
                case MIMIC_SKILL_CHAIN:
                    Init2DPuzzle(well, cursor, demo_data_schain, temp_s0);
                    temp_s0--;
                    break;
                case MIMIC_TIMELAG:
                    Init2DPuzzle(well, cursor, demo_data_timelag, temp_s0);
                    temp_s0--;
                    break;
                default:
                    temp_s0--;
                    break;
            }
        } while (0);
    } else {
        switch (kind) {
            case MIMIC_COMBO:
                Init2DPuzzle(well, cursor, play_data_combo, temp_s0);
                temp_s0--;
                break;
            case MIMIC_CHAIN:
                Init2DPuzzle(well, cursor, play_data_chain, temp_s0);
                temp_s0--;
                break;
            case MIMIC_SKILL_CHAIN:
                Init2DPuzzle(well, cursor, play_data_schain, temp_s0);
                temp_s0--;
                break;
            case MIMIC_TIMELAG:
                Init2DPuzzle(well, cursor, play_data_timelag, temp_s0);
                temp_s0--;
                break;
            default:
                temp_s0--;
                break;
        }
    }

    gTheGame.totalPlayer = 1;
    var_s5->speed = 0xA;
    InitAI(well, cursor, var_s5);
    if (play == 0) {
        var_s5->unk_03C = kind;
    } else {
        var_s5->unk_03C = kind + 4;
    }
    temp_v0 = cursor[0].target[0];
    var_s5->unk_040 = temp_s0;
    var_s5->unk_044 = 0;
    cursor[0].target[0] = 0;
    cursor[0].target[1] = 0;
    cursor[0].target[2] = temp_v0;
}

#endif

#if VERSION_USA
// Maybe inlined in DoMimic() or otherwise duplicated there?
// ?? static void LoadMimic2(int kind /* r3 */, int level /* r4 */, int number /* r5 */, int play /* r6 */)
void func_8008336C_usa(s32 kind, s32 level, s32 number, s32 play) {
    LoadMimic1(kind, level, number, play);
    PlaySE(SFX_INIT_TABLE, 0x95);
    brainbrain[0].speed = -1;
    brainbrain[0].unk_104 = 0;
}
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

    if (gTheGame.dimension == DIMENSION_2D) {
        if (brainbrain[num].speed == -1) {
            if (h_button & U_JPAD) {
                sound = Move2DCursorUp(well, cursor, gamepad->hold);
            } else if (h_button & D_JPAD) {
                sound = Move2DCursorDown(cursor, gamepad->hold);
            } else if (h_button & L_JPAD) {
                sound = Move2DCursorLeft(cursor, gamepad->hold);
            } else if (h_button & R_JPAD) {
                sound = Move2DCursorRight(cursor, gamepad->hold);
            }

            if (t_button & (A_BUTTON | B_BUTTON)) {
                Switch2DBlocks(well, cursor, num);
            }
        } else {
            UpdateMT(well, cursor, &brainbrain[num]);
        }

        Update2DSwitching(well, cursor);
    } else {
        if (brainbrain[num].speed == -1) {
            if (h_button & U_JPAD) {
                sound = Move3DCursorUp(well, cursor, gamepad->hold);
            } else if (h_button & D_JPAD) {
                sound = Move3DCursorDown(cursor, gamepad->hold);
            } else if (h_button & L_JPAD) {
                sound = Move3DCursorLeft(cursor, gamepad->hold);
            } else if (h_button & R_JPAD) {
                sound = Move3DCursorRight(cursor, gamepad->hold);
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

    cursor->frame_d--;
    if (cursor->frame_d == 0) {
// TODO: REGION_NTSC?
#if VERSION_USA
        cursor->frame_d = 0xF;
#else
        cursor->frame_d = 0xD;
#endif
        cursor->frame_n ^= 1;
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

    if ((gSelection == 0x64) && (gTheGame.menu[0].game == 3)) {
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
            if (cursor->unk_00 <= 0) {
                s32 temp = gTheGame.dimension;

                if (well->unk_43F8 >= temp * 0x10) {
                    well->unk_43C4 = -1;

                    AddNewRow(well, cursor, num);
                    well->unk_43F8 = 0;
                }
            }

            if (gTheGame.dimension == DIMENSION_3D) {
                Check3DVisibleBlocks(well, cursor);
            }

            well->unk_43FC = 0;
            well->unk_43A4 = 0;
        }
    }
}

void MimicCheckState(tetWell *well, cursor_t *cursor) {
    s32 result;

    if (well->unk_43A8 < cursor->target[0]) {
        cursor->target[0] = well->unk_43A8;
    }

    if (!CheckFieldActive(well)) {
        if ((brainbrain[0].speed == -1) && (well->unk_43A8 == 0)) {
            if (brainbrain[0].unk_03C == 5) {
                if (cursor->target[1] == 0) {
                    return;
                }
                result = (cursor->target[1] == cursor->target[2]) ? -1 : 0;
            } else if (cursor->target[0] != 0) {
                result = ((-cursor->target[2] >= cursor->target[0])) ? -1 : 0;
            } else if (cursor->target[1] != 0) {
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
            brainbrain[0].speed = -1;
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
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", mimicTickText);
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
        if (gTheGame.dimension == DIMENSION_2D) {
            Draw2DMT(dynamicp);
        } else {
            Draw3DMT(dynamicp);
        }

        if (!screenFlushing()) {
            pon_DrawLoadingMessage(&glistp);
        }
    }

    pon_DrawLoadingMessage(&glistp);
}

#if VERSION_USA
#if 0
? func_80083050_usa(s32, s32, s32, s32);            /* extern */
? mimicTickText(s32);                           /* extern */
? menuTickFairy(s32, s32, s32, ?);                  /* extern */
extern u16 B_8019300E_usa;

// unattempted
void DoMimic(void) {
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    u32 sp30;
    s32 sp34;
    s32 sp38;
    s32 sp3C;
    s32 sp40;
    enum MimicMode var_s3;
    s32 temp_a0;
    s32 temp_a2;
    s32 temp_s0;
    s32 temp_s0_10;
    s32 temp_s0_11;
    s32 temp_s0_12;
    s32 temp_s0_13;
    s32 temp_s0_14;
    s32 temp_s0_15;
    s32 temp_s0_16;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s0_7;
    s32 temp_s0_8;
    s32 temp_s0_9;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_a2;
    s32 var_s0;
    s32 var_s4;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;

    if (screenFlushing() == nfalse) {
        peelTick();
    }
    var_s4 = 0;
    temp_s2 = giScreenMimic;
    B_80192FF0_usa += 1;
    screenSetBackLayers(1);
    var_a2 = gnTagTextMimic;
    var_s5 = 0;
    if ((var_a2 != -1) && (var_a2 < 0)) {
        var_a2 = -var_a2;
    }
    if (geModeMimic != MM_GIRLTEXT) {

    }
    menuTickFairy(temp_s2, B_80192FF0_usa, var_a2, 0x4FFFC);
    sp24 = 0;
    sp20 = 0;
    if (gTheGame.controller[0].hold_button & 0x800) {
        sp20 = 1;
    }
    if (gTheGame.controller[0].hold_button & 0x400) {
        sp20 = 2;
    }
    if (gTheGame.controller[0].hold_button & 0x200) {
        sp20 = 3;
    }
    if (gTheGame.controller[0].hold_button & 0x100) {
        sp20 = 4;
    }
    screenTick((screenTick_arg0 *) &sp20);
    if (sp20 == 0) {
        if (gTheGame.controller[0].touch_button & 0x8000) {
            sp20 = 0x20;
        }
        if (gTheGame.controller[0].touch_button & 0x4000) {
            sp20 = 0x21;
        }
        if (gTheGame.controller[0].touch_button & 0x1000) {
            sp20 = 0x22;
        }
    } else {
        PlaySE(SFX_INIT_TABLE, 1);
    }
    screenGetCursor(temp_s2, 0x64, &sp28, &sp2C);
    gTheGame.menu[0].stage = sp2C + 1;
    if ((u32) (sp20 - 1) < 2U) {
        screenSetCursor(temp_s2, 0x65, (&giScreenMimic)[gTheGame.menu[0].stage], 0);
    }
    screenGetCursor(temp_s2, 0x65, &sp28, &sp2C);
    gTheGame.menu[0].misc = sp28 + 1;
    (&giScreenMimic)[gTheGame.menu[0].stage] = sp28;
    var_s3 = MM_NONE;
    switch (geModeMimic) {                          /* switch 1 */
        case MM_NONE:                               /* switch 1 */
            var_s3 = MM_GIRLTEXT;
            break;
        case MM_GIRLTEXT:                           /* switch 1 */
            temp_s0 = (-((B_8019300C_usa & 0xFFFF) == 0x258) & 0x259) | 0x258;
            if ((B_8019300C_usa == 0) || (((s32) B_8019300C_usa >> 0x10) != 0)) {
                B_8019300C_usa = temp_s0;
                func_80028DC0_usa(giScreenMimic, temp_s0, 0);
                screenSetImagePosition(giScreenMimic, temp_s0, 0x9E, 0x48);
            }
            if (sp20 == 0x21) {
                var_s5 = -1;
            }
            if (-((~gnTagTextMimic == 0) | ((u32) gnTagTextMimic >> 0x1F)) == 0) {
                if (sp20 == 0x22) {
                    var_s3 = MM_LEVEL;
                }
            } else {
block_178:
                var_s3 = MM_LEVEL;
            }
            break;
        case MM_LEVEL:                              /* switch 1 */
            temp_s0_2 = (-((B_8019300C_usa & 0xFFFF) == 0x258) & 0x259) | 0x258;
            if ((B_8019300C_usa == 0) || (((s32) B_8019300C_usa >> 0x10) != 0)) {
                B_8019300C_usa = temp_s0_2;
                func_80028DC0_usa(giScreenMimic, temp_s0_2, 0);
                screenSetImagePosition(giScreenMimic, temp_s0_2, 0x9E, 0x48);
            }
            if ((u32) (sp20 - 1) < 2U) {
                temp_s0_3 = gnTagTextMimic;
                if (geModeMimic == MM_NONE) {
                    gnTagTextMimic = 0x1F4;
                } else {
                    gnTagTextMimic = (gTheGame.menu[0].speed * 0x2710) + (gTheGame.menu[0].stage * 0x3E8);
                }
                B_80193014_usa = 0;
                if (screenGetTextType(giScreenMimic, gnTagTextMimic, &sp30) != nfalse) {
                    screenHideText(giScreenMimic, -0x3FFFFE0C);
                    screenShowText(giScreenMimic, gnTagTextMimic);
                } else {
                    gnTagTextMimic = temp_s0_3;
                }
            }
            if (sp20 == 0x21) {
                var_s5 = -1;
            }
            var_v0 = 0x20;
block_101:
            if (sp20 == var_v0) {
                var_s3 = MM_STAGE;
            }
            break;
        case MM_STAGE:                              /* switch 1 */
            temp_s0_4 = (-((B_8019300C_usa & 0xFFFF) == 0x258) & 0x259) | 0x258;
            if ((B_8019300C_usa == 0) || (((s32) B_8019300C_usa >> 0x10) != 0)) {
                B_8019300C_usa = temp_s0_4;
                func_80028DC0_usa(giScreenMimic, temp_s0_4, 0);
                screenSetImagePosition(giScreenMimic, temp_s0_4, 0x9E, 0x48);
            }
            if ((u32) (sp20 - 3) < 2U) {
                temp_s0_5 = gnTagTextMimic;
                if (geModeMimic == MM_NONE) {
                    gnTagTextMimic = 0x1FE;
                } else {
                    temp_v1 = (gTheGame.menu[0].speed * 0x2710) + (gTheGame.menu[0].stage * 0x3E8);
                    gnTagTextMimic = temp_v1;
                    gnTagTextMimic = temp_v1 + ((gTheGame.menu[0].misc * 0x64) + 0xA);
                }
                B_80193014_usa = 0;
                if (screenGetTextType(giScreenMimic, gnTagTextMimic, &sp30) != nfalse) {
                    screenHideText(giScreenMimic, -0x3FFFFE0C);
                    screenShowText(giScreenMimic, gnTagTextMimic);
                } else {
                    gnTagTextMimic = temp_s0_5;
                }
            }
            if (sp20 != 0) {
                var_s4 = 1;
            }
            if (sp20 == 0x21) {
                var_s3 = MM_LEVEL;
            }
            if (sp20 == 0x20) {
                if (geModeMimic == MM_NONE) {
                    gnTagTextMimic = 0x208;
                } else {
                    temp_v1_2 = (gTheGame.menu[0].speed * 0x2710) + (gTheGame.menu[0].stage * 0x3E8);
                    gnTagTextMimic = temp_v1_2;
                    gnTagTextMimic = temp_v1_2 + ((gTheGame.menu[0].misc * 0x64) + 0x14);
                }
                B_80193014_usa = 0;
                if (screenGetTextType(giScreenMimic, gnTagTextMimic, &sp30) != nfalse) {
block_145:
                    screenHideText(giScreenMimic, -0x3FFFFE0C);
                    var_s3 = MM_VIEWTEXT1;
                    screenShowText(giScreenMimic, gnTagTextMimic);
                } else {
block_146:
                    gnTagTextMimic = gnTagTextMimic;
                    var_s3 = MM_VIEWTEXT1;
                }
            }
            break;
        case MM_VIEWTEXT1:                          /* switch 1 */
            temp_s0_6 = (-((B_8019300C_usa & 0xFFFF) == 0x258) & 0x259) | 0x258;
            if ((B_8019300C_usa == 0) || (((s32) B_8019300C_usa >> 0x10) != 1)) {
                B_8019300C_usa = temp_s0_6 | 0x10000;
                func_80028DC0_usa(giScreenMimic, temp_s0_6, 1);
                screenSetImagePosition(giScreenMimic, temp_s0_6, 0x90, 0x49);
            }
            if (-((~gnTagTextMimic == 0) | ((u32) gnTagTextMimic >> 0x1F)) != 0) {
                var_s3 = MM_VIEW;
            } else {
block_100:
                var_v0 = 0x21;
                goto block_101;
            }
            break;
        case MM_VIEW:                               /* switch 1 */
            temp_s0_7 = (-((B_8019300C_usa & 0xFFFF) == 0x258) & 0x259) | 0x258;
            if ((B_8019300C_usa == 0) || (((s32) B_8019300C_usa >> 0x10) != 1)) {
                B_8019300C_usa = temp_s0_7 | 0x10000;
                func_80028DC0_usa(giScreenMimic, temp_s0_7, 1);
                screenSetImagePosition(giScreenMimic, temp_s0_7, 0x90, 0x49);
            }
            if (gTheGame.controller[0].touch_button & 0x4000) {
                PlaySE(SFX_INIT_TABLE, 6);
                var_v0_2 = -1;
            } else {
                DoMT();
                if (gMain != GMAIN_2BC) {
                    var_v0_2 = 0;
                } else {
                    gMain = GMAIN_MIMIC;
                    var_v0_2 = -1;
                }
            }
            if (var_v0_2 != 0) {
                if ((gTheGame.menu[0].game != 3) && (gTheGame.menu[0].misc < 3)) {
                    screenGetCursor(giScreenMimic, 0x65, &sp38, &sp3C);
                    var_v0_3 = sp38 < 5;
                    if (gTheGame.menu[0].speed != 4) {
                        var_v0_3 = sp38 < 4;
                        if (gTheGame.menu[0].stage >= 3) {
                            var_v0_3 = sp38 < 3;
                        }
                    }
                    if (var_v0_3 != 0) {
                        sp38 += 1;
                    }
                    screenSetCursor(giScreenMimic, 0x65, sp38, 0);
                    gTheGame.menu[0].misc = sp38 + 1;
                    var_s3 = MM_STAGE;
                } else {
                    temp_s0_8 = gnTagTextMimic;
                    if (geModeMimic == MM_NONE) {
                        gnTagTextMimic = 0x212;
                    } else {
                        temp_v1_3 = (gTheGame.menu[0].speed * 0x2710) + (gTheGame.menu[0].stage * 0x3E8);
                        gnTagTextMimic = temp_v1_3;
                        gnTagTextMimic = temp_v1_3 + ((gTheGame.menu[0].misc * 0x64) + 0x1E);
                    }
                    B_80193014_usa = 0;
                    if (screenGetTextType(giScreenMimic, gnTagTextMimic, &sp30) != nfalse) {
                        screenHideText(giScreenMimic, -0x3FFFFE0C);
                        var_s3 = MM_VIEWTEXT2;
                        screenShowText(giScreenMimic, gnTagTextMimic);
                    } else {
                        gnTagTextMimic = temp_s0_8;
                        var_s3 = MM_VIEWTEXT2;
                    }
                }
            }
            goto block_100;
        case MM_VIEWTEXT2:                          /* switch 1 */
            temp_s0_9 = (-((B_8019300C_usa & 0xFFFF) == 0x258) & 0x259) | 0x258;
            if ((B_8019300C_usa == 0) || (((s32) B_8019300C_usa >> 0x10) != 1)) {
                B_8019300C_usa = temp_s0_9 | 0x10000;
                func_80028DC0_usa(giScreenMimic, temp_s0_9, 1);
                screenSetImagePosition(giScreenMimic, temp_s0_9, 0x90, 0x49);
            }
            if (-((~gnTagTextMimic == 0) | ((u32) gnTagTextMimic >> 0x1F)) != 0) {
                if (gTheGame.menu[0].game == 3) {
                    temp_s0_10 = gnTagTextMimic;
                    if (geModeMimic == MM_NONE) {
                        gnTagTextMimic = 0x21C;
                    } else {
                        temp_v1_4 = (gTheGame.menu[0].speed * 0x2710) + (gTheGame.menu[0].stage * 0x3E8);
                        gnTagTextMimic = temp_v1_4;
                        gnTagTextMimic = temp_v1_4 + ((gTheGame.menu[0].misc * 0x64) + 0x28);
                    }
                    B_80193014_usa = 0;
                    if (screenGetTextType(giScreenMimic, gnTagTextMimic, &sp30) != nfalse) {
                        screenHideText(giScreenMimic, -0x3FFFFE0C);
                        var_s3 = MM_PLAYTEXT1;
                        screenShowText(giScreenMimic, gnTagTextMimic);
                    } else {
                        gnTagTextMimic = temp_s0_10;
                        var_s3 = MM_PLAYTEXT1;
                    }
                } else {
                    screenGetCursor(giScreenMimic, 0x65, (s32 *) &sp30, &sp34);
                    var_v0_4 = (s32) sp30 < 5;
                    if (gTheGame.menu[0].speed != 4) {
                        var_v0_4 = (s32) sp30 < 4;
                        if (gTheGame.menu[0].stage >= 3) {
                            var_v0_4 = (s32) sp30 < 3;
                        }
                    }
                    if (var_v0_4 != 0) {
                        sp30 += 1;
                    }
                    screenSetCursor(giScreenMimic, 0x65, (s32) sp30, 0);
                    gTheGame.menu[0].misc = sp30 + 1;
                    var_s3 = MM_STAGE;
                    if (sp30 == sp30) {
                        screenGetCursor(giScreenMimic, 0x64, (s32 *) &sp30, &sp34);
                        if (gTheGame.menu[0].speed != 4) {
                            if (sp34 < 3) {
                                sp34 += 1;
                            } else {
                                sp34 = 0;
                            }
                        }
                        var_s3 = MM_LEVEL;
block_165:
                        screenSetCursor(giScreenMimic, 0x64, (s32) sp30, sp34);
                        gTheGame.menu[0].stage = sp34 + 1;
                        screenSetCursor(giScreenMimic, 0x65, 0, 0);
                        gTheGame.menu[0].misc = 1;
                    }
                }
            }
            break;
        case MM_PLAYTEXT1:                          /* switch 1 */
            var_s3 = MM_PLAY;
            break;
        case MM_PLAY:                               /* switch 1 */
            temp_s0_11 = (-((B_8019300C_usa & 0xFFFF) == 0x258) & 0x259) | 0x258;
            if ((B_8019300C_usa == 0) || (((s32) B_8019300C_usa >> 0x10) != 0)) {
                B_8019300C_usa = temp_s0_11;
                func_80028DC0_usa(giScreenMimic, temp_s0_11, 0);
                screenSetImagePosition(giScreenMimic, temp_s0_11, 0x9E, 0x48);
            }
            sp40 = 0xABCD;
            if (gTheGame.controller[0].touch_button & 0x4000) {
                PlaySE(SFX_INIT_TABLE, 6);
                var_v0_5 = -1;
            } else {
                DoMT();
                var_v0_5 = 0;
                if (gMain == GMAIN_2BC) {
                    switch (gTheGame.cursorBlock[0].unk_00) { /* switch 2; irregular */
                        case 0x7:                   /* switch 2 */
                            sp40 = -1;
                            break;
                        case 0x8:                   /* switch 2 */
                            sp40 = 0;
                            break;
                    }
                    gMain = GMAIN_MIMIC;
                    var_v0_5 = -1;
                }
            }
            if (var_v0_5 != 0) {
                if (sp40 == 0xABCD) {
                    var_s4 = 1;
                    if (geModeMimic == MM_NONE) {
                        gnTagTextMimic = 0x208;
                    } else {
                        temp_v1_5 = (gTheGame.menu[0].speed * 0x2710) + (gTheGame.menu[0].stage * 0x3E8);
                        gnTagTextMimic = temp_v1_5;
                        gnTagTextMimic = temp_v1_5 + ((gTheGame.menu[0].misc * 0x64) + 0x14);
                    }
                    B_80193014_usa = 0;
                    if (screenGetTextType(giScreenMimic, gnTagTextMimic, &sp30) != nfalse) {
                        goto block_145;
                    }
                    goto block_146;
                }
                var_s3 = MM_PLAYTEXT2;
                if (sp40 != 0) {
                    temp_s0_12 = gnTagTextMimic;
                    if (geModeMimic == MM_NONE) {
                        gnTagTextMimic = 0x226;
                    } else {
                        temp_v1_6 = (gTheGame.menu[0].speed * 0x2710) + (gTheGame.menu[0].stage * 0x3E8);
                        gnTagTextMimic = temp_v1_6;
                        gnTagTextMimic = temp_v1_6 + ((gTheGame.menu[0].misc * 0x64) + 0x32);
                    }
                    B_80193014_usa = 0;
                    if (screenGetTextType(giScreenMimic, gnTagTextMimic, &sp30) != nfalse) {
                        screenHideText(giScreenMimic, -0x3FFFFE0C);
                        screenShowText(giScreenMimic, gnTagTextMimic);
                    } else {
                        gnTagTextMimic = temp_s0_12;
                    }
                    screenGetCursor(giScreenMimic, 0x65, (s32 *) &sp30, &sp34);
                    var_v0_6 = (s32) sp30 < 5;
                    if (gTheGame.menu[0].speed != 4) {
                        var_v0_6 = (s32) sp30 < 4;
                        if (gTheGame.menu[0].stage >= 3) {
                            var_v0_6 = (s32) sp30 < 3;
                        }
                    }
                    if (var_v0_6 != 0) {
                        sp30 += 1;
                    }
                    screenSetCursor(giScreenMimic, 0x65, (s32) sp30, 0);
                    gTheGame.menu[0].misc = sp30 + 1;
                    if (sp30 == sp30) {
                        screenGetCursor(giScreenMimic, 0x64, (s32 *) &sp30, &sp34);
                        if (gTheGame.menu[0].speed != 4) {
                            if (sp34 < 3) {
                                sp34 += 1;
                            } else {
                                sp34 = 0;
                            }
                        }
                        var_s3 = MM_PLAYTEXT3;
                        goto block_165;
                    }
                } else {
                    temp_s0_13 = gnTagTextMimic;
                    if (geModeMimic == MM_NONE) {
                        gnTagTextMimic = 0x230;
                    } else {
                        temp_v1_7 = (gTheGame.menu[0].speed * 0x2710) + (gTheGame.menu[0].stage * 0x3E8);
                        gnTagTextMimic = temp_v1_7;
                        gnTagTextMimic = temp_v1_7 + ((gTheGame.menu[0].misc * 0x64) + 0x3C);
                    }
                    B_80193014_usa = 0;
                    if (screenGetTextType(giScreenMimic, gnTagTextMimic, &sp30) != nfalse) {
                        screenHideText(giScreenMimic, -0x3FFFFE0C);
                        screenShowText(giScreenMimic, gnTagTextMimic);
                    } else {
                        gnTagTextMimic = temp_s0_13;
                    }
                    temp_s0_14 = (-((B_8019300C_usa & 0xFFFF) == 0x258) & 0x259) | 0x258;
                    if ((B_8019300C_usa == 0) || (((s32) B_8019300C_usa >> 0x10) != 2)) {
                        B_8019300C_usa = temp_s0_14 | 0x20000;
                        func_80028DC0_usa(giScreenMimic, temp_s0_14, 2);
                        screenSetImagePosition(giScreenMimic, temp_s0_14, 0xB1, 0x4A);
                    }
                }
            }
            break;
        case MM_PLAYTEXT2:                          /* switch 1 */
            if (-((~gnTagTextMimic == 0) | ((u32) gnTagTextMimic >> 0x1F)) != 0) {
                var_s3 = MM_STAGE;
            }
            break;
        case MM_PLAYTEXT3:                          /* switch 1 */
            if (-((~gnTagTextMimic == 0) | ((u32) gnTagTextMimic >> 0x1F)) != 0) {
                goto block_178;
            }
            break;
    }

    if (var_s3 != MM_NONE) {
        if (geModeMimic == MM_VIEWTEXT1) {
            var_a1 = 4;
            goto block_184;
        }
        if ((u32) geModeMimic >= 2U) {
            var_a1 = (-(sp20 == 0x21) & 6) | 2;
block_184:
            PlaySE(SFX_INIT_TABLE, var_a1);
        }
        screenHideArea(temp_s2, 0x64);
        screenHideArea(temp_s2, 0x65);
        screenHideImage(temp_s2, 0x64);
        screenHideImage(temp_s2, 0x65);
        screenHideText(temp_s2, 0x80778064);
        if ((gTheGame.menu[0].speed == 4) & (var_s3 == MM_LEVEL)) {
            if (geModeMimic == MM_STAGE) {
                var_s5 = -1;
            } else {
                gTheGame.menu[0].stage = 1;
                var_s3 = MM_STAGE;
            }
        }
        if (var_s3 == MM_STAGE) {
            var_s4 = 1;
        }
        if (var_s3 == MM_PLAY) {
            var_s4 = 2;
        }
        switch (var_s3) {                           /* switch 3; irregular */
            case MM_LEVEL:                          /* switch 3 */
                temp_s0_15 = gnTagTextMimic;
                if (geModeMimic == MM_NONE) {
                    gnTagTextMimic = 0x1F4;
                } else {
                    gnTagTextMimic = (gTheGame.menu[0].speed * 0x2710) + (gTheGame.menu[0].stage * 0x3E8);
                }
                B_80193014_usa = 0;
                if (screenGetTextType(giScreenMimic, gnTagTextMimic, &sp30) != nfalse) {
                    screenHideText(giScreenMimic, -0x3FFFFE0C);
                    screenShowText(giScreenMimic, gnTagTextMimic);
                } else {
                    gnTagTextMimic = temp_s0_15;
                }
                screenShowImage(temp_s2, 0x64);
                screenHideImage(temp_s2, 0x65);
                if (gTheGame.menu[0].speed != 2) {
                    var_a1_2 = 0x80688064;
                } else {
                    var_a1_2 = 0x806D8069;
                }
                screenShowText(temp_s2, var_a1_2);
                func_80027838_usa(temp_s2, 0x64);
                var_a1_3 = 0x64;
block_222:
                func_80027618_usa(temp_s2, var_a1_3, 0U);
                break;
            case MM_STAGE:                          /* switch 3 */
                temp_s0_16 = gnTagTextMimic;
                if (geModeMimic == MM_NONE) {
                    gnTagTextMimic = 0x1FE;
                } else {
                    temp_v1_8 = (gTheGame.menu[0].speed * 0x2710) + (gTheGame.menu[0].stage * 0x3E8);
                    gnTagTextMimic = temp_v1_8;
                    gnTagTextMimic = temp_v1_8 + ((gTheGame.menu[0].misc * 0x64) + 0xA);
                }
                B_80193014_usa = 0;
                if (screenGetTextType(giScreenMimic, gnTagTextMimic, &sp30) != nfalse) {
                    screenHideText(giScreenMimic, -0x3FFFFE0C);
                    screenShowText(giScreenMimic, gnTagTextMimic);
                } else {
                    gnTagTextMimic = temp_s0_16;
                }
                screenHideImage(temp_s2, 0x64);
                screenShowImage(temp_s2, 0x65);
                func_80028BAC_usa(temp_s2, 0x65, 0, 0);
                func_80028BAC_usa(temp_s2, 0x65, 1, 0);
                func_80028BAC_usa(temp_s2, 0x65, 2, 0);
                func_80028BAC_usa(temp_s2, 0x65, 3, 0);
                func_80028BAC_usa(temp_s2, 0x65, 4, 0);
                func_80028BAC_usa(temp_s2, 0x65, 5, 0);
                screenGetCursor(giScreenMimic, 0x65, &sp28, &sp2C);
                if (gTheGame.menu[0].speed != 4) {
                    func_80028A98_usa(temp_s2, 0x65, 5, 0);
                    if (gTheGame.menu[0].stage >= 3) {
                        if (sp28 >= 4) {
                            sp28 = 3;
                        }
                        func_80028A98_usa(temp_s2, 0x65, 4, 0);
                        var_a1_4 = 0x6E;
                    } else {
                        if (sp28 >= 5) {
                            sp28 = 4;
                        }
                        var_a1_4 = 0x6F;
                    }
                } else {
                    var_a1_4 = 0x70;
                }
                screenShowText(temp_s2, var_a1_4);
                screenSetCursor(giScreenMimic, 0x65, sp28, 0);
                func_80027838_usa(temp_s2, 0x65);
                var_a1_3 = 0x65;
                goto block_222;
        }
        geModeMimic = var_s3;
    }
    if (var_s4 != 0) {
        screenGetCursor(temp_s2, 0x64, &sp28, &sp2C);
        gTheGame.menu[0].stage = sp2C + 1;
        screenGetCursor(temp_s2, 0x65, &sp28, &sp2C);
        temp_a2 = sp28 + 1;
        gTheGame.menu[0].misc = temp_a2;
        if (var_s4 == 1) {
            func_80083050_usa(gTheGame.menu[0].speed, gTheGame.menu[0].stage, temp_a2, -(gTheGame.menu[0].game == 3));
        } else {
            func_80083050_usa(gTheGame.menu[0].speed, gTheGame.menu[0].stage, temp_a2, -(gTheGame.menu[0].game == 3));
            PlaySE(SFX_INIT_TABLE, 0x95);
            brainbrain->speed = -1;
            brainbrain->unk_104 = 0;
        }
    }
    if (var_s5 != 0) {
        gMain = GMAIN_2BC;
        gReset = -1;
        gGameStatus = (u32) gGameStatus;
        PlaySE(SFX_INIT_TABLE, 6);
    }
    var_a0 = 0;
    if (var_s3 == MM_NONE) {
        var_a0 = -(sp20 == 0x20);
    }
    mimicTickText(var_a0);
    if (B_8019300E_usa == 0x258) {
        var_s0 = 0x259;
        goto block_235;
    }
    var_s0 = 0x258;
    if (B_8019300E_usa == 0x259) {
block_235:
        if (func_8002864C_usa(giScreenMimic, (s32) B_8019300E_usa, (struct struct_imageLoad_arg0 **) &sp30) != nfalse) {
            temp_a0 = sp30->unk_14;
            temp_v0 = temp_a0 + 8;
            if (temp_a0 < 0xFF) {
                sp30->unk_14 = temp_v0;
                if (temp_v0 >= 0x100) {
                    sp30->unk_14 = 0xFF;
                }
            }
        }
        if (func_8002864C_usa(giScreenMimic, var_s0, (struct struct_imageLoad_arg0 **) &sp30) != nfalse) {
            temp_v0_2 = sp30->unk_14;
            temp_v0_3 = temp_v0_2 - 8;
            if (temp_v0_2 > 0) {
                sp30->unk_14 = temp_v0_3;
                if (temp_v0_3 < 0) {
                    sp30->unk_14 = 0;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", DoMimic);
#endif
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
    gnTagTextMimic = (gTheGame.menu[0].speed * 0xA) + 0x1EA;
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
        screenSetImagePosition(giScreenMimic, temp_s0_2, 0x9E, 0x48);
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
    temp[5] = gTheGame.menu[0].speed + '0';

    if (screenLoad(temp, &sp10) != 0) {
        inlined_function();
    }

    if (B_8021B960_usa != 0x40) {
        func_80002D8C_usa(0x1E);
        PlayMIDI(BGM_INIT_TABLE, 0x40, 0, 1);
    }
}