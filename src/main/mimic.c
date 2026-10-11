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
#include "attack2d.h"
#include "buffers.h"
#include "character.h"
#include "combo.h"
#include "dlist.h"
#include "image.h"
#include "info.h"
#include "init2d.h"
#include "init3d.h"
#include "menu.h"
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

    temp_a0 = gGameStatus & GAME_STATUS_FLAG_40;
    GAME_STATUS_SHIFT_LEFT(gGameStatus);
    if (temp_a0 != 0) {
        gGameStatus |= GAME_STATUS_FLAG_40;
    }

    func_80054624_usa();
    InitCharacter(0x385, -1);
    LoadFairySoundData(0x19, 9, 9);

    *heapP = Pon_Image_Heap;
}

INLINE void QuitMimic(void) {
    GAME_STATUS_SHIFT_RIGHT(gGameStatus);
}

/**
 * Original name: LoadMimic1
 */
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
    gTheGame.miscToggle = 0;
    gTheGame.unk_9B50[0].b.frameH = 0;
    gTheGame.unk_9B50[1].b.frameH = 0;
    chain_check[0] = 0;
    chain_check[1] = 0;
    anim_bg = 0;
    anim_sp = 0;
    gTheGame.tetrisWell[0].unk_43B0 = 0;
    gTheGame.tetrisWell[0].unk_43A8 = 0;
    gTheGame.tetrisWell[0].unk_43A4 = 0;
    gTheGame.tetrisWell[0].danger = 0;
    gTheGame.tetrisWell[0].alert = 0;
    gTheGame.tetrisWell[0].unk_43BC = 0;
    gTheGame.tetrisWell[0].chain_garbage = 0;
    gTheGame.tetrisWell[0].collision = 0;
    gTheGame.tetrisWell[0].state.death = 0;
    gTheGame.tetrisWell[0].bot_height = 0xDF;
    gTheGame.tetrisWell[0].state.current_raise = 0;
    gTheGame.tetrisWell[0].state.raise = 0;
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
    var_s5->speed = ADJUST_FRAMERATE(10);
    InitAI(well, cursor, var_s5);
    if (play == 0) {
        var_s5->where = kind;
    } else {
        var_s5->where = kind + 4;
    }
    temp_v0 = cursor[0].target[0];
    var_s5->unk_040 = temp_s0;
    var_s5->unk_044 = 0;
    cursor[0].target[0] = 0;
    cursor[0].target[1] = 0;
    cursor[0].target[2] = temp_v0;
}

/**
 * Original name: LoadMimic2
 */
INLINE void LoadMimic2(s32 kind, s32 level, s32 number, s32 play) {
    LoadMimic1(kind, level, number, play);
    PlaySE(SFX_INIT_TABLE, SFX_095);
    brainbrain[0].speed = -1;
    brainbrain[0].total_command = 0;
}

/**
 * Original name: MTMove
 */
INLINE void MTMove(ai_t *brain, u8 *ptr) {
    s32 temp_v0;
    s32 var_a0;
    s32 temp_s3;

#if 0
    // Local variables
    int count; // r4
#endif

    for (var_a0 = 0; var_a0 < brain->unk_040; var_a0++) {
        temp_v0 = *ptr;
        ptr += (temp_v0 * 3) + 1;
    }

    temp_v0 = *ptr;
    if (brain->unk_044 < temp_v0) {
        ptr += brain->unk_044 * 3;
        ptr = ptr + 1;
        for (temp_s3 = 0; true; temp_s3 += 3) {
            AIAddCommand(brain, ptr[temp_s3], ptr[temp_s3 + 1], ptr[temp_s3 + 2]);
            brain->unk_044 += 1;
            if (ptr[temp_s3] != 0x14) {
                break;
            }
        }
    } else {
        AIAddCommand(brain, 0x1F, 0, 0);
    }
}

/**
 * Original name: UpdateMT
 */
void UpdateMT(tetWell *well, cursor_t *cursor, ai_t *brain) {
    command_t *command;
    s32 var_v1;

#if 0
    // Local variables
    int count; // r4
    int num; // r29
    struct command_t * command; // r1+0x8
#endif

    if (cursor->delay != 0) {
        return;
    }

    if (well->unk_43B0 > 0) {
        RaiseBlocks(well, cursor);
        return;
    }

    if (well->unk_43B0 < 0) {
        well->unk_43B0++;
    }

    AISetCursor(well, cursor, brain);
    if (brain->move_head == brain->move_tail) {
        if (brain->total_command == 0) {
            AIClearCommand(brain);

            if (gSelection == SELECTION_6E) {
                if (brain->where == 1) {
                    MTMove(brain, demo_mimic_combo);
                } else if (brain->where == 2) {
                    MTMove(brain, demo_mimic_chain);
                } else if (brain->where == 3) {
                    MTMove(brain, demo_mimic_schain);
                } else if (brain->where == 4) {
                    MTMove(brain, demo_mimic_timelag);
                } else if (brain->where == 5) {
                    MTMove(brain, play_mimic_combo);
                } else if (brain->where == 6) {
                    MTMove(brain, play_mimic_chain);
                } else if (brain->where == 7) {
                    MTMove(brain, play_mimic_schain);
                } else if (brain->where == 8) {
                    MTMove(brain, play_mimic_timelag);
                }
            } else {
                if (brain->where == 1) {
                    MTMove(brain, tutorial_move1);
                } else if (brain->where == 2) {
                    MTMove(brain, tutorial_move2);
                } else if (brain->where == 5) {
                    MTMove(brain, tutorial_move3);
                } else if (brain->where == 3) {
                    MTMove(brain, tutorial_move4);
                } else if (brain->where == 4) {
                    MTMove(brain, tutorial_move5);
                }
            }
        }
    }

    if (brain->total_command > 0) {
        AIFinishMove(brain);

        do {
            command = &brain->command[brain->com_head];

            switch (command->function) {
                case 0x1:
                    AIVertMove(brain, command->para1);
                    break;

                case 0x2:
                    AIHoriMove(brain, command->para1);
                    break;

                case 0x5:
                    AIHoriMoveBlock(brain, command->para1, command->para2);
                    if (brain->move_tail != 0) {
                        brain->move[brain->move_tail - 1] = 6;
                    }
                    break;

                case 0x9:
                    AISetMove(brain, 5);
                    break;

                case 0xC:
                    AISetMove(brain, 7);
                    break;

                case 0x14:
                    brain->delay = ADJUST_FRAMERATE(command->para1 * command->para2);
                    break;

                case 0x15:
                    if (gGameStatus & GAME_STATUS_FLAG_80) {
                        if (!screenTextDone(brain->t, brain->direction)) {
                            brain->delay = 1;
                            return;
                        }

                        gWhatever++;
                        if ((gWhatever % 120 == 0) && (cursor->state == 0 || cursor->state == 0x34C) &&
                            (anim_bg == 0x34C || !CheckFieldActive(well))) {
                            cursor->state = 0;
                        } else {
                            brain->delay = 1;
                            return;
                        }
                    } else if ((gTheGame.controller[0].touch_button & A_BUTTON) &&
                               (cursor->state == 0 || cursor->state == 0x34C) &&
                               (anim_bg == 0x34C || !CheckFieldActive(well))) {
                        if (!screenTextDone(brain->t, brain->direction)) {
                            func_80028034_usa(brain->t, brain->direction);
                            brain->unk_024 = -1;
                            brain->delay = 1;
                            return;
                        } else {
                            cursor->state = 0;
                            brain->unk_024 = 0;
                            PlaySE(SFX_INIT_TABLE, SFX_096);
                        }
                    } else {
                        if (anim_bg == 0x34C || !CheckFieldActive(well)) {
                            brain->unk_024 = -1;
                        }
                        brain->delay = 1;
                        return;
                    }
                    break;

                case 0x16:
                    gTheGame.totalPlayer = 2;

                    if (gTheGame.dimension == DIMENSION_2D) {
                        InitCursor(cursor);
                        Init2DCursor(cursor, 0);

                        switch (brain->where) {
                            case 0x1:
                                Init2DPuzzle(well, cursor, tutorial1, command->para1);
                                break;
                            case 0x2:
                                Init2DPuzzle(well, cursor, tutorial2, command->para1);
                                break;
                            case 0x3:
                                Init2DPuzzle(well, cursor, tutorial4, command->para1);
                                break;
                            case 0x4:
                                Init2DPuzzle(well, cursor, tutorial5, command->para1);
                                break;
                        }

                        Init2DTetrisBlocksTMEM(well, -1);
                        Init2DNewRow(well);
                        Init2DIcons(well);
                        Init2DAttackBlocks(well);
                        Init2DExplosion(well);

                        if (gTheGame.menu[0].game == 3) {
                            Init2DTetrisBlocks(&gTheGame.tetrisWell[1], 1);
                            Init2DAttackBlocks(&gTheGame.tetrisWell[1]);
                            gTheGame.tetrisWell[1].bot_height = 0xDF;
                            gTheGame.tetrisWell[1].state.current_raise = 0;
                            gTheGame.tetrisWell[1].state.raise = 0;
                        }

                        gTheGame.unk_9B50[0].b.frameH = 30 << 2;
                        gTheGame.unk_9B50[1].b.frameH = 30 << 2;
                        if (gTheGame.menu[0].game != 3) {
                            gTheGame.unk_9B50[1].b.frameH = 0;
                        }
                    } else {
                        InitCursor(cursor);
                        Init3DCursor(cursor, 0);
                        Init3DPuzzle(well, cursor, tutorial3, command->para1);
                        Init3DNewRow(well);
                        if ((command->para1 % 2) == 1) {
                            well->new_block[0].type = BLOCKTYPE_0;
                        }
                        Init3DIcons(well);
                        Init3DAttackBlocks(well);
                        Init3DExplosion(well);
                    }

                    well->bot_height = 0xDF;
                    well->state.current_raise = 0;
                    well->state.raise = 0;
                    chain_check[0] = 0;
                    chain_check[1] = 0;
                    anim_bg = 0;
                    anim_sp = 0;
                    gTheGame.totalPlayer = 1;
                    break;

                case 0x17:
                    cursor->state = 0x34C;
                    break;

                case 0x18:
                    brain->delay--;
                    if (brain->delay > 0) {
                        return;
                    }

                    well->state.raise = command->para1 * gTheGame.dimension;
                    well->state.current_raise += well->state.raise;
                    break;

                case 0x19:
                    for (var_v1 = 0; var_v1 < ATTACK_COUNT; var_v1++) {
                        if (gTheGame.tetrisWell[command->para2].attack[var_v1].state == ATTACKSTATE_0) {
                            Init2DAttackPosition(&gTheGame.tetrisWell[command->para2].attack[var_v1], command->para1,
                                                 command->para2);
                            Init2DAttackFace(&gTheGame.tetrisWell[command->para2].attack[var_v1]);
                            gTheGame.tetrisWell[command->para2].attack[var_v1].state = ATTACKSTATE_4;
                            gTheGame.tetrisWell[command->para2].attack[var_v1].delay = -1;
                            break;
                        }
                    }
                    break;

                case 0x1A:
                    brain->unk_030 = command->para1;
                    brain->unk_034 = 1;
                    break;

                case 0x1B:
                    screenHideText(brain->t, command->para1 - 1);
                    screenShowText(brain->t, command->para1);
                    brain->direction = command->para1;
                    break;

                case 0x1C:
                    brain->unk_02C = command->para1;
                    break;

                case 0x1D:
                    gTheGame.gSPRITE[9].s.imageAdrs = 6;
                    gTheGame.gSPRITE[9].s.imageW = 16 << 5;
                    gTheGame.gSPRITE[9].s.objX = command->para1 << 2;
                    gTheGame.gSPRITE[9].s.objY = command->para2 << 2;
                    anim_bg = 0x34C;
                    break;

                case 0x1E:
                    anim_bg = 0;
                    break;

                case 0x1F:
                    brain->total_command = 0;
                    if (gGameStatus & GAME_STATUS_FLAG_80) {
                        gMain = GMAIN_TITLE;
                        gReset = -1;
                        gDemo = GDEMO_21;
                        GAME_STATUS_SHIFT_RIGHT(gGameStatus);
                        FadeOutSong(last_song_handle, 0x3C);
                        return;
                    }
                    if (gSelection == SELECTION_64) {
                        gMain = GMAIN_2BC;
                        gReset = -1;
                        GAME_STATUS_SHIFT_RIGHT(gGameStatus);
                        return;
                    }
                    break;
            }

            brain->total_command--;
            brain->com_head++;
            if (brain->total_command <= 0) {
                break;
            }
        } while (brain->move_head == brain->move_tail);
    }

    brain->delay--;
    if ((brain->delay <= 0) && (brain->move_head != brain->move_tail)) {
        brain->delay = brain->speed;
        if (gTheGame.dimension == DIMENSION_2D) {
            AI2DMove(well, cursor, brain, 0);
        } else {
            AI3DMove(well, cursor, brain, 0);
        }
    }
}

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
        PlaySE(SFX_INIT_TABLE, SFX_096);
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

    if (gSelection == SELECTION_6E) {
        MimicCheckState(&gTheGame.tetrisWell[0], &gTheGame.cursorBlock[0]);
    } else {
        TutorialCheckState(&gTheGame.tetrisWell[0], &gTheGame.cursorBlock[0]);
    }

    if (gMain == GMAIN_2BC) {
        return;
    }

    if ((gSelection == SELECTION_64) && (gTheGame.menu[0].game == 3)) {
        total = 2;
    }

    for (num = 0; num < total; num++) {
        well = &gTheGame.tetrisWell[num];
        cursor = &gTheGame.cursorBlock[num];

        if (cursor->state != 0x34C) {
            CompactWell(well, num);
        }

        if (num == 0) {
            UpdateMTController(well, cursor, num);
        }

        if (cursor->state != 0x34C) {
            if (well->collision != 0) {
                CheckCollision(well);
            }

            well->collision = 0;
            CheckChainCounter(well, cursor);
            count = ComboCount(well, cursor);
            well->unk_43BC = 0;

            if (gSelection == SELECTION_64) {
                CheckShake(well, cursor);
            }

            CheckIcon(well, count);
            StartAttack(well, num);
            UpdateWell(well, cursor, num, count);

            if (gSelection == SELECTION_64) {
                ChangeAttack(well, cursor, num, count);
            }
            UpdateCursor(well, cursor);
            UpdateIcon(well, cursor, num);
            if (gSelection == SELECTION_64) {
                UpdateAttack(well, cursor, num);
            }
            UpdateExplosion(well);
            UpdateDistance(well, cursor);
            UpdateAnimation(well, num, 0);
            UpdateMiscStuff(well, cursor, num);
            if (cursor->state <= 0) {
                s32 temp = gTheGame.dimension;

                if (well->state.current_raise >= temp * 0x10) {
                    well->collision = -1;

                    AddNewRow(well, cursor, num);
                    well->state.current_raise = 0;
                }
            }

            if (gTheGame.dimension == DIMENSION_3D) {
                Check3DVisibleBlocks(well, cursor);
            }

            well->state.raise = 0;
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
            if (brainbrain[0].where == 5) {
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
                cursor->state = 7;
                B_801C7348_usa++;
                B_801C7348_usa %= 5;
                func_80005888_usa(0, 2, B_801C7348_usa + 5);
            } else {
                cursor->state = 8;
                PlaySE(SFX_INIT_TABLE, SFX_0A0);
            }

            gMain = GMAIN_2BC;
        } else if (brainbrain[0].total_command < 0) {
            brainbrain[0].speed = -1;
            brainbrain[0].total_command = 0;
            if (well->unk_43A8 == -3) {
                PlaySE(SFX_INIT_TABLE, SFX_12C);
            } else if (well->unk_43A8 == -4) {
                PlaySE(SFX_INIT_TABLE, SFX_12D);
            } else if (well->unk_43A8 < -4) {
                PlaySE(SFX_INIT_TABLE, SFX_12E);
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
INLINE s32 ViewMimic(void) {
    if (gTheGame.controller[0].touch_button & 0x4000) {
        PlaySE(SFX_INIT_TABLE, SFX_006);
        return -1;
    }
    DoMT();
    if (gMain == GMAIN_2BC) {
        gMain = GMAIN_MIMIC;
        return -1;
    }
    return 0;
}
#endif

#if VERSION_USA
INLINE s32 PlayMimic(s32 *arg0) {
    if (gTheGame.controller[0].touch_button & 0x4000) {
        PlaySE(SFX_INIT_TABLE, SFX_006);
        return -1;
    }
    DoMT();
    if (gMain == GMAIN_2BC) {
        if (gTheGame.cursorBlock[0].state == 7) {
                *arg0 = -1;
        } else if (gTheGame.cursorBlock[0].state == 8) {
                *arg0 = 0;
        }
        gMain = GMAIN_MIMIC;
        return -1;
    }
    return 0;
}
#endif

#if VERSION_USA
INLINE void DrawMimic(struct_gInfo_unk_00068 *dynamicp) {
    if (gTheGame.dimension == DIMENSION_2D) {
        Draw2DMT(dynamicp);
    } else {
        Draw3DMT(dynamicp);
    }
    if (screenFlushing() == nfalse) {
        pon_DrawLoadingMessage(&glistp);
    }
}
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

    if (gSelection == SELECTION_64) {
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
    if (gSelection == SELECTION_6E) {
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
        // TODO: Replace with DrawMimic() when mathcing non-USA
        if (gTheGame.dimension == DIMENSION_2D) {
            Draw2DMT(dynamicp);
        } else {
            Draw3DMT(dynamicp);
        }
        if (screenFlushing() == nfalse) {
            pon_DrawLoadingMessage(&glistp);
        }
    }

    pon_DrawLoadingMessage(&glistp);
}

#if VERSION_USA
STATIC_INLINE void DoMimic_inlined_func(s32 temp) {
    u32 sp30;
    s32 temp_s0;
    s32 var_v0;

    temp_s0 = gnTagTextMimic;
    if (geModeMimic == MM_NONE) {
        gnTagTextMimic = 0x1F4 + temp;
    } else {
        gnTagTextMimic = (gTheGame.menu[0].speed * 0x2710) + (gTheGame.menu[0].stage * 0x3E8);

        if (temp) {
            var_v0 = ((gTheGame.menu[0].misc * 0x64)) + temp;
            gnTagTextMimic += var_v0;
        }
    }
    B_80193014_usa = 0;
    if (screenGetTextType(giScreenMimic, gnTagTextMimic, &sp30) != nfalse) {
        screenHideText(giScreenMimic, -0x3FFFFE0C);
        screenShowText(giScreenMimic, gnTagTextMimic);
    } else {
        gnTagTextMimic = temp_s0;
    }
}

STATIC_INLINE void DoMimic_inlined_func_2(void) {
    s32 var_a1_5 = B_8019300E_usa;
    s32 var_s0;
    struct struct_imageLoad_arg0 *sp30;

    if (var_a1_5 == 0x258) {
        var_s0 = 0x259;
    } else if (var_a1_5 == 0x259) {
        var_s0 = 0x258;
    } else {
        return;
    }
    if (func_8002864C_usa(giScreenMimic, var_a1_5, &sp30)) {
        if (sp30->unk_14 < 0xFF) {
            sp30->unk_14 += 8;
            if (sp30->unk_14 >= 0x100) {
                sp30->unk_14 = 0xFF;
            }
        }
    }
    if (func_8002864C_usa(giScreenMimic, var_s0, &sp30)) {
        if (sp30->unk_14 > 0) {
            sp30->unk_14 -= 8;
            if (sp30->unk_14 < 0) {
                sp30->unk_14 = 0;
            }
        }
    }
}

STATIC_INLINE void DoMimic_inlined_func_3(s32 arg0, s32 arg1) {
    s32 temp_s0;
    temp_s0 = ((B_8019300C_usa & 0xFFFF) == 0x258) ? 0x259 : 0x258;
    if ((B_8019300C_usa == 0) || ((B_8019300C_usa >> 0x10) != arg0)) {
        B_8019300C_usa = temp_s0 | (arg0 << 0x10);
        func_80028DC0_usa(giScreenMimic, temp_s0, arg0);
        screenSetImagePosition(giScreenMimic, temp_s0, arg1, 0x48 + arg0);
    }
}

STATIC_INLINE void DoMimic_inlined_func_4(void) {
    s32 sp30;
    s32 sp34;

    screenGetCursor(giScreenMimic, 0x64, &sp30, &sp34);
    if (gTheGame.menu[0].speed != 4) {
        if (sp34 < 3) {
            sp34 += 1;
        } else {
            sp34 = 0;
        }
    }
    screenSetCursor(giScreenMimic, 0x64, sp30, sp34);
    gTheGame.menu[0].stage = sp34 + 1;
    screenSetCursor(giScreenMimic, 0x65, 0, 0);
    gTheGame.menu[0].misc = 1;
}

STATIC_INLINE s32 DoMimic_inlined_func_5(void) {
    s32 sp30;
    s32 sp34;
    s32 var_s0;

    screenGetCursor(giScreenMimic, 0x65, &sp30, &sp34);
    var_s0 = sp30;
    if (gTheGame.menu[0].speed == 4) {
        if (sp30 < 5) {
            sp30 = var_s0 + 1;
        }
    } else if (gTheGame.menu[0].stage < 3) {
        if (sp30 < 4) {
            sp30 = var_s0 + 1;
        }
    } else {
        if (sp30 < 3) {
            sp30 = var_s0 + 1;
        }
    }

    screenSetCursor(giScreenMimic, 0x65, sp30, 0);
    gTheGame.menu[0].misc = sp30 + 1;

    return var_s0 == sp30;
}

void DoMimic(void) {
    screenTick_arg0 sp20;
    s32 sp28;
    s32 sp2C;
    s32 sp40;
    s32 temp_v0;
    s32 var_a2;
    s32 var_s2;
    enum MimicMode eMode;
    s32 var_s4;
    s32 var_s5;

#if 0
    // Local variables
    int nFlag; // r23
    int iScreen; // r27
    int nTagText; // r5
    int nLoad; // r26
    int bBack; // r31
    @enum$635mimic_c eMode; // r30
    int iCursorX; // r1+0x70
    int iCursorY; // r1+0x6C
    int anCommand[4]; // r1+0x5C

#endif

    if (!screenFlushing()) {
        peelTick();
    }
    var_s4 = 0;
    var_s2 = giScreenMimic;
    B_80192FF0_usa += 1;
    screenSetBackLayers(1);
    var_a2 = gnTagTextMimic;
    var_s5 = 0;
    if (var_a2 != -1) {
        if (var_a2 < 0) {
            var_a2 = -var_a2;
        }
    }
    menuTickFairy(var_s2, B_80192FF0_usa, var_a2, 0x4FFFC, 0xFFCAFFE0, 0x520002, 4, (geModeMimic != MM_GIRLTEXT) ? 0 : -1);
    sp20.unk_4 = 0;
    sp20.unk_0 = 0;
    if (gTheGame.controller[0].hold_button & U_JPAD) {
        sp20.unk_0 = 1;
    }
    if (gTheGame.controller[0].hold_button & D_JPAD) {
        sp20.unk_0 = 2;
    }
    if (gTheGame.controller[0].hold_button & L_JPAD) {
        sp20.unk_0 = 3;
    }
    if (gTheGame.controller[0].hold_button & R_JPAD) {
        sp20.unk_0 = 4;
    }
    screenTick(&sp20);
    if (sp20.unk_0 == 0) {
        if (gTheGame.controller[0].touch_button & A_BUTTON) {
            sp20.unk_0 = 0x20;
        }
        if (gTheGame.controller[0].touch_button & B_BUTTON) {
            sp20.unk_0 = 0x21;
        }
        if (gTheGame.controller[0].touch_button & START_BUTTON) {
            sp20.unk_0 = 0x22;
        }
    } else {
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }
    screenGetCursor(var_s2, 0x64, &sp28, &sp2C);
    gTheGame.menu[0].stage = sp2C + 1;
    if (sp20.unk_0 == 1 || sp20.unk_0 == 2) {
        screenSetCursor(var_s2, 0x65, (&giScreenMimic)[gTheGame.menu[0].stage], 0);
    }
    screenGetCursor(var_s2, 0x65, &sp28, &sp2C);
    gTheGame.menu[0].misc = sp28 + 1;
    // TODO: What is this: (&giScreenMimic)[gTheGame.menu[0].stage]?
    (&giScreenMimic)[gTheGame.menu[0].stage] = sp28;
    eMode = MM_NONE;
    switch (geModeMimic) {
        case MM_NONE:
            eMode = MM_GIRLTEXT;
            break;
        case MM_GIRLTEXT:
            DoMimic_inlined_func_3(0, 0x9E);
            if (sp20.unk_0 == 0x21) {
                var_s5 = -1;
            }

            temp_v0 = (gnTagTextMimic == -1 || gnTagTextMimic < 0) ? -1 : 0;
            if (temp_v0 || sp20.unk_0 == 0x22) {
                eMode = MM_LEVEL;
            }
            break;
        case MM_LEVEL:
            DoMimic_inlined_func_3(0, 0x9E);
            if (sp20.unk_0 == 1 || sp20.unk_0 == 2) {
                DoMimic_inlined_func(0);
            }
            if (sp20.unk_0 == 0x21) {
                var_s5 = -1;
            }
            if (sp20.unk_0 == 0x20) {
                eMode = MM_STAGE;
            }
            break;
        case MM_STAGE:
            DoMimic_inlined_func_3(0, 0x9E);
            if (sp20.unk_0 == 3 || sp20.unk_0 == 4) {
                DoMimic_inlined_func(0xA);
            }
            if (sp20.unk_0 != 0) {
                var_s4 = 1;
            }
            if (sp20.unk_0 == 0x21) {
                eMode = MM_LEVEL;
            }
            if (sp20.unk_0 == 0x20) {
                DoMimic_inlined_func(0x14);
                eMode = MM_VIEWTEXT1;
            }
            break;
        case MM_VIEWTEXT1:
            DoMimic_inlined_func_3(1, 0x90);
            temp_v0 = (gnTagTextMimic == -1 || gnTagTextMimic < 0) ? -1 : 0;
            if (temp_v0) {
                eMode = MM_VIEW;
            } else {
                if (sp20.unk_0 == 0x21) {
                    eMode = MM_STAGE;
                }
            }
            break;
        case MM_VIEW:
            DoMimic_inlined_func_3(1, 0x90);
            if (ViewMimic() != 0) {
                if ((gTheGame.menu[0].game != 3) && (gTheGame.menu[0].misc < 3)) {
                    DoMimic_inlined_func_5();
                    eMode = MM_STAGE;
                } else {
                    DoMimic_inlined_func(0x1E);
                    eMode = MM_VIEWTEXT2;
                }
            }
            if (sp20.unk_0 == 0x21) {
                eMode = MM_STAGE;
            }
            break;
        case MM_VIEWTEXT2:
            DoMimic_inlined_func_3(1, 0x90);
            temp_v0 = (gnTagTextMimic == -1 || gnTagTextMimic < 0) ? -1 : 0;
            if (temp_v0) {
                if (gTheGame.menu[0].game == 3) {
                    DoMimic_inlined_func(0x28);
                    eMode = MM_PLAYTEXT1;
                } else {
                    if (DoMimic_inlined_func_5()) {
                        DoMimic_inlined_func_4();
                        eMode = MM_LEVEL;
                    } else {
                        eMode = MM_STAGE;
                    }
                }
            }
            break;
        case MM_PLAYTEXT1:
            eMode = MM_PLAY;
            break;
        case MM_PLAY:
            DoMimic_inlined_func_3(0, 0x9E);
            sp40 = 0xABCD;

            if (PlayMimic(&sp40) != 0) {
                if (sp40 == 0xABCD) {
                    var_s4 = 1;
                    DoMimic_inlined_func(0x14);
                    eMode = MM_VIEWTEXT1;
                    break;
                }
                eMode = MM_PLAYTEXT2;
                if (sp40 != 0) {
                    DoMimic_inlined_func(0x32);

                    if (DoMimic_inlined_func_5()) {
                        DoMimic_inlined_func_4();

                        eMode = MM_PLAYTEXT3;
                    }
                } else {
                    DoMimic_inlined_func(0x3C);

                    DoMimic_inlined_func_3(2, 0xB1);
                }
            }
            break;
        case MM_PLAYTEXT2:
            temp_v0 = (gnTagTextMimic == -1 || gnTagTextMimic < 0) ? -1 : 0;
            if (temp_v0) {
                eMode = MM_STAGE;
            }
            break;
        case MM_PLAYTEXT3:
            temp_v0 = (gnTagTextMimic == -1 || gnTagTextMimic < 0) ? -1 : 0;
            if (temp_v0) {
                eMode = MM_LEVEL;
            }
            break;
    }
    
    if (eMode != MM_NONE) {
        if (geModeMimic == MM_VIEWTEXT1) {
            PlaySE(SFX_INIT_TABLE, SFX_004);
        } else if (geModeMimic >= 2) {
            PlaySE(SFX_INIT_TABLE, (sp20.unk_0 == 0x21) ? 6 : 2);
        }
        screenHideArea(var_s2, 0x64);
        screenHideArea(var_s2, 0x65);
        screenHideImage(var_s2, 0x64);
        screenHideImage(var_s2, 0x65);
        screenHideText(var_s2, 0x80778064);
        if ((gTheGame.menu[0].speed == 4) & (eMode == MM_LEVEL)) {
            if (geModeMimic == MM_STAGE) {
                var_s5 = -1;
            } else {
                gTheGame.menu[0].stage = 1;
                eMode = MM_STAGE;
            }
        }
        if (eMode == MM_STAGE) {
            var_s4 = 1;
        }
        if (eMode == MM_PLAY) {
            var_s4 = 2;
        }
        switch (eMode) {
            case MM_LEVEL:
                DoMimic_inlined_func(0);

                screenShowImage(var_s2, 0x64);
                screenHideImage(var_s2, 0x65);
                if (gTheGame.menu[0].speed != 2) {
                    screenShowText(var_s2, 0x80688064);
                } else {
                    screenShowText(var_s2, 0x806D8069);
                }
                screenShowArea(var_s2, 0x64);
                func_80027618_usa(var_s2, 0x64, 0U);
                break;
            case MM_STAGE:
                DoMimic_inlined_func(0xA);

                screenHideImage(var_s2, 0x64);
                screenShowImage(var_s2, 0x65);
                func_80028BAC_usa(var_s2, 0x65, 0, 0);
                func_80028BAC_usa(var_s2, 0x65, 1, 0);
                func_80028BAC_usa(var_s2, 0x65, 2, 0);
                func_80028BAC_usa(var_s2, 0x65, 3, 0);
                func_80028BAC_usa(var_s2, 0x65, 4, 0);
                func_80028BAC_usa(var_s2, 0x65, 5, 0);
                screenGetCursor(giScreenMimic, 0x65, &sp28, &sp2C);
                if (gTheGame.menu[0].speed != 4) {
                    func_80028A98_usa(var_s2, 0x65, 5, 0);
                    if (gTheGame.menu[0].stage >= 3) {
                        if (sp28 >= 4) {
                            sp28 = 3;
                        }
                        func_80028A98_usa(var_s2, 0x65, 4, 0);
                        screenShowText(var_s2, 0x6E);
                    } else {
                        if (sp28 >= 5) {
                            sp28 = 4;
                        }
                        screenShowText(var_s2, 0x6F);
                    }
                } else {
                    screenShowText(var_s2, 0x70);
                }
                screenSetCursor(giScreenMimic, 0x65, sp28, 0);
                screenShowArea(var_s2, 0x65);
                func_80027618_usa(var_s2, 0x65, 0U);
                break;
        }
        geModeMimic = eMode;
    }
    if (var_s4 != 0) {
        screenGetCursor(var_s2, 0x64, &sp28, &sp2C);
        gTheGame.menu[0].stage = sp2C + 1;
        screenGetCursor(var_s2, 0x65, &sp28, &sp2C);
        gTheGame.menu[0].misc = sp28 + 1;
        if (var_s4 == 1) {
            LoadMimic1(gTheGame.menu[0].speed, gTheGame.menu[0].stage, gTheGame.menu[0].misc, -(gTheGame.menu[0].game == 3));
        } else {
            LoadMimic2(gTheGame.menu[0].speed, gTheGame.menu[0].stage, gTheGame.menu[0].misc, -(gTheGame.menu[0].game == 3));
        }
    }
    if (var_s5 != 0) {
        gMain = GMAIN_2BC;
        gReset = -1;
        GAME_STATUS_SHIFT_RIGHT(gGameStatus);
        PlaySE(SFX_INIT_TABLE, SFX_006);
    }
    mimicTickText((eMode == MM_NONE) ? -(sp20.unk_0 == 0x20) : 0);

    DoMimic_inlined_func_2();
}
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

    // TODO: Replace with DoMimic_inlined_func_3(0, 0x9E); when matching non-USA
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