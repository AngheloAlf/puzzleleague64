/**
 * Original filename: update.c
 */

#include "update.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "animate.h"
#include "animation.h"
#include "attack.h"
#include "combo.h"
#include "combo3d.h"
#include "dlist.h"
#include "fade.h"
#include "info.h"
#include "sfxlimit.h"
#include "the_game.h"
#include "update2d.h"
#include "update3d.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057650_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_800578F0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_80056060_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_800561E0_ger);
#endif

/**
 * Original name: UpdateTime
 */
void UpdateTime(s32 second) {
    if (gSelection >= SELECTION_BE) {
        gTheGame.second = gTheGame.second - second;
        if (gTheGame.second < 0) {
            gTheGame.second = 59;
            gTheGame.minute--;
        }
        if (gTheGame.minute < 0) {
            gTheGame.minute = 0;
        }

        if (second == 1) {
            if (gTheGame.minute == second) {
                if (gTheGame.second == 0) {
                    PlaySE(SFX_INIT_TABLE, SFX_099);
                    return;
                }
            }

            if (gTheGame.minute == 0) {
                switch (gTheGame.second) {
                    case 0xF:
                        PlaySE(SFX_INIT_TABLE, SFX_091);
                        TenSecond = 1;
                        break;

                    case 0x3:
                    case 0x4:
                    case 0x5:
                        PlaySE(SFX_INIT_TABLE, SFX_09A);
                        break;

                    case 0x2:
                        PlaySE(SFX_INIT_TABLE, SFX_09B);
                        break;

                    case 0x1:
                        PlaySE(SFX_INIT_TABLE, SFX_09C);
                        break;

                    case 0x0:
                        PlaySE(SFX_INIT_TABLE, SFX_0A1);
                        break;
                }
            }
        }
    } else {
        gTheGame.second += second;

        if (gTheGame.second >= 60) {
            gTheGame.second = 0;
            gTheGame.minute++;
        }

        if (gTheGame.minute >= 60) {
            gTheGame.hour = gTheGame.hour + 1;
            if (gTheGame.hour >= 24) {
                gTheGame.hour = 23;
                gTheGame.minute = 59;
                gTheGame.second = 59;
            } else {
                gTheGame.minute = 0;
            }
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateNextLevel);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdateNextLevel);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", UpdateNextLevel);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", UpdateNextLevel);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057D1C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80057FBC_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_8005672C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_800568AC_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057D68_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058030_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_800567A0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_80056920_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057E10_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_800580D8_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_80056848_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_800569C8_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057EB8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058180_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_800568F0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_80056A70_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057F84_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_8005824C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_800569BC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_80056B3C_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_8005806C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058334_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_80056AA4_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_80056C24_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058168_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058430_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_80056BA0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_80056D20_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_8005825C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058524_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_80056C94_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_80056E14_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_8005834C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058614_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_80056D84_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_80056F04_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058458_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058458_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_80058458_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_80058458_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdatePlayerPuzzle);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdatePlayerPuzzle);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", UpdatePlayerPuzzle);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", UpdatePlayerPuzzle);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_800587CC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_800587CC_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_800587CC_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_800587CC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058934_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058934_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_80058934_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_80058934_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdatePlayerStageClear);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdatePlayerStageClear);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", UpdatePlayerStageClear);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", UpdatePlayerStageClear);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdatePlayerStageClearTimeScore);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdatePlayerStageClearTimeScore);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", UpdatePlayerStageClearTimeScore);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", UpdatePlayerStageClearTimeScore);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058D68_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058D68_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", func_80058D68_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", func_80058D68_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateComboChainCount);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdateComboChainCount);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", UpdateComboChainCount);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", UpdateComboChainCount);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateWell);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdateWell);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update", UpdateWell);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update", UpdateWell);
#endif

/**
 * Original name: UpdateCursor
 */
void UpdateCursor(tetWell *well, cursor_t *cursor) {
    if (cursor->state != 2) {
        if (cursor->waiting > 0) {
            cursor->waiting--;
        }
    }

    if (gTheGame.dimension == DIMENSION_3D) {
        Update3DCursor(well, cursor);
    }
}

/**
 * Original name: UpdateIcon
 */
void UpdateIcon(tetWell *well, cursor_t *cursor, s32 num) {
    if (gTheGame.dimension == DIMENSION_2D) {
        Update2DIcon(well, cursor, num);
    } else {
        Update3DIcon(well, cursor, num);
    }
}

/**
 * Original name: UpdateDistance
 */
void UpdateDistance(tetWell *well, cursor_t *cursor) {
    if (gTheGame.dimension == DIMENSION_2D) {
        Update2DDistance(well, cursor);
    } else {
        Update3DDistance(well, cursor);
    }
}

/**
 * Original name: UpdateMainState
 */
void UpdateMainState(void) {
    s32 num;
    s32 row;
    s32 col;
    s32 score1;
    s32 score2;
    s32 var_a1_3; // DrawRankingFlag?
    tetWell *well;
    cursor_t *cursor;
    s32 temp;
    s32 temp2;

#if 0
    // Local variables
    int num; // r21
    int row; // r7
    int col; // r1+0x8
    int score1; // r1+0x8
    int score2; // r1+0x8
    int result; // r17
    struct tetWell * well; // r24
    struct cursor_t * cursor; // r31
    int DrawRankingFlag; // r20
    int i; // r7
    int Timer[4]; // r1+0x4C
    int SortTimer[4]; // r1+0x3C
    int Score[4]; // r1+0x2C
    int SortScore[4]; // r1+0x1C
#endif

    if (gMain != GMAIN_387) {
        return;
    }

    for (num = 0; num < gTheGame.totalPlayer; num++) {
        well = &gTheGame.tetrisWell[num];
        cursor = &gTheGame.cursorBlock[num];
        var_a1_3 = CheckGameOver(well, cursor);

        if (gGameStatus & GAME_STATUS_FLAG_80) {
            if (var_a1_3 != 0) {
                gDemo = GDEMO_16;
            }
            var_a1_3 = 0;
        }

        if ((var_a1_3 != 0) && (gSelection >= SELECTION_83)) {
            gMain = GMAIN_38E;
            cursor->state = 8;
            continue;
        }

        switch (gSelection) {
            case SELECTION_BE:
                if ((gTheGame.minute <= 0) && (gTheGame.second == 0)) {
                    gMain = GMAIN_38E;
                    cursor->state = 7;
                }
                break;

            case SELECTION_78:
            case SELECTION_82:
                if (!CheckFieldActive(well)) {
                    if (cursor->target[1] == 0) {
                        var_a1_3 = -1;

                        for (row = 0; row < BLOCK_LEN_ROWS; row++) {
                            for (col = 0; col < gMax; col++) {
                                var_a1_3 &= (well->block[row][col].type == BLOCKTYPE_0) ? -1 : 0;
                            }

                            if (var_a1_3 == 0) {
                                break;
                            }
                        }

                        gMain = GMAIN_38E;
                        if (var_a1_3 != 0) {
                            cursor->state = 7;
                        } else {
                            cursor->state = 8;
                        }
                    } else {
                        temp2 = 0;

                        for (row = 0; row < BLOCK_LEN_ROWS; row++) {
                            for (col = 0; col < gMax; col++) {
                                temp2 += (well->block[row][col].type != BLOCKTYPE_0);
                            }

                            if (temp2 != 0) {
                                break;
                            }
                        }

                        if (temp2 == 0) {
                            gMain = GMAIN_38E;
                            cursor->state = 7;
                        }
                    }
                }
                break;

            case SELECTION_C8:
                if ((gTheGame.minute <= 0) && (gTheGame.second == 0)) {
                    score1 = gTheGame.tetrisWell[0].score;
                    score2 = gTheGame.tetrisWell[1].score;
                    gMain = GMAIN_38E;
                    if (score2 < score1) {
                        gTheGame.cursorBlock[0].state = 7;
                        gTheGame.cursorBlock[1].state = 8;
                    } else if (score1 < score2) {
                        gTheGame.cursorBlock[0].state = 8;
                        gTheGame.cursorBlock[1].state = 7;
                    } else {
                        gTheGame.cursorBlock[0].state = 7;
                        gTheGame.cursorBlock[1].state = 7;
                    }
                }
                break;

            case SELECTION_AA:
                if ((gTheGame.menu[0].game == 5) && (anim_sp <= 0)) {
                    gMain = GMAIN_38E;
                    cursor->state = 7;
                    break;
                }
                FALLTHROUGH;

            case SELECTION_B4:
                if (cursor->target[0] <= 0) {
                    temp = cursor->target[0];
                    if (temp <= -1) {
                        row = -temp;
                    } else {
                        row = temp;
                    }

                    var_a1_3 = -1;
                    for (; row < BLOCK_LEN_ROWS; row++) {
                        for (col = 0; col < gMax; col++) {
                            var_a1_3 &= (well->block[row][col].type == BLOCKTYPE_0) ? -1 : 0;
                        }
                        if (var_a1_3 == 0) {
                            break;
                        }
                    }

                    if ((var_a1_3 != 0) && !CheckFieldActive(well)) {
                        gMain = GMAIN_38E;
                        cursor->state = 7;
                        if (gSelection == SELECTION_B4) {
                            if (num == 0) {
                                gTheGame.cursorBlock[1].state = 8;
                            } else {
                                gTheGame.cursorBlock[0].state = 8;
                            }
                        }
                    }
                }

                break;

            default:
                break;
        }
    }

    if (gMain == GMAIN_38E) {
        gTheGame.cursorBlock[0].unk_0C = 0;
        gTheGame.cursorBlock[1].unk_0C = 0;

        gMain = GMAIN_387;
        UpdateComboChainCount(0, 0, -gTheGame.tetrisWell[0].unk_43A8);
        UpdateComboChainCount(1, 0, -gTheGame.tetrisWell[1].unk_43A8);
        gMain = GMAIN_38E;

        if ((gTheGame.totalPlayer == 1) && (gSelection >= SELECTION_83)) {
            gTheGame.miscToggle = 0;
        }

        CheckChainCounter(&gTheGame.tetrisWell[0], &gTheGame.cursorBlock[0]);
        UpdateAnimation(&gTheGame.tetrisWell[0], 0, 0);
        CheckChainCounter(&gTheGame.tetrisWell[1], &gTheGame.cursorBlock[1]);
        UpdateAnimation(&gTheGame.tetrisWell[1], 1, 0);
    }
}

/**
 * Original name: UpdateBuffer
 */
void UpdateBuffer(struct_gInfo *info) {
    if (gTheGame.dimension == DIMENSION_2D) {
        Update2DBuffer(info);
    } else {
        Update3DBuffer(info);
    }
}

/**
 * Original name: Update2DBuffer
 */
void Update2DBuffer(struct_gInfo *info) {
    struct_gInfo_unk_00068 *dynamicp = &info->dp;
    char *sp14;
    s32 var_s6;

    dynamicp->overflow = gOverflow;

    sp14 = D_800B7508_usa;
    if (gGameStatus & GAME_STATUS_FLAG_40) {
        sp14 = TetrisBlockFrame;
    }

    for (var_s6 = 0; var_s6 < gTheGame.totalPlayer; var_s6++) {
        tetWell *well = &gTheGame.tetrisWell[var_s6];
        cursor_t *cursor = &gTheGame.cursorBlock[var_s6];
        block_t(*var_s0)[BLOCK_LEN_B];
        s32 var_a1;

        bcopy(cursor, &dynamicp->cursorBlock[var_s6], sizeof(cursor_t));
        bcopy(well->block, dynamicp->block[var_s6], sizeof(well->block));
        // Why only the first 4 bytes? Could this be a bug or is it intentional?
        bzero(&dynamicp->frontTexture[var_s6], 4);

        var_s0 = dynamicp->block[var_s6];
        for (var_a1 = 0; var_a1 < BLOCK_LEN_ROWS; var_a1++) {
            s32 var_a0;

            for (var_a0 = 0; var_a0 < BLOCK_LEN_B / 3; var_a0++) {
                block_t *var = &var_s0[var_a1][var_a0];

                var->frame_n = sp14[var->frame_n];
                dynamicp->frontTexture[var_s6][var->frame_n] = 1;
            }
        }

        bcopy(&well->block_rect, &dynamicp->block_rect[var_s6],
              sizeof(uObjSprite) * BLOCK_LEN_ROWS * TETWELL_OBJSPRITE_LEN_B);
        bcopy(&well->new_block_rect, &dynamicp->new_block_rect[var_s6], sizeof(uObjSprite) * TETWELL_UNK_3EF0_LEN_6);

        if (cursor->sy != -1) {
            bcopy(&well->left2D, &dynamicp->left2D[var_s6], sizeof(uObjSprite));
            bcopy(&well->right2D, &dynamicp->right2D[var_s6], sizeof(uObjSprite));
        }

        bcopy(&well->icon, &dynamicp->icon[var_s6], sizeof(icon_t) * ICON_COUNT);
        bcopy(&well->attack, &dynamicp->attack[var_s6], sizeof(attack_t) * ATTACK_COUNT);
        bcopy(&well->explosion, &dynamicp->explosion[var_s6], sizeof(explode_t) * EXPLOSION_COUNT);
    }

    bcopy(&gTheGame.drawText, &dynamicp->drawText, sizeof(text_t) * DRAWTEXT_COUNT);
}

#define ABS(x) (((x) < 0) ? -(x) : (x))

/**
 * Original name: Update3DBuffer
 */
void Update3DBuffer(struct_gInfo *info) {
    struct_gInfo_unk_00068 *dynamicp = &info->dp;
    tetWell *well;
    cursor_t *cursor;
    s32 num;
    s32 frame;
    // TODO: which one is row and col?
    s32 var_a2;
    int var_v1;
    block_t(*var_s0)[BLOCK_LEN_B];
    char *var_s7;

    var_s7 = D_800B7508_usa;
    if (gGameStatus & GAME_STATUS_FLAG_40) {
        var_s7 = TetrisBlockFrame;
    }

    for (num = 0; num < gTheGame.totalPlayer; num++) {
        well = &gTheGame.tetrisWell[num];
        cursor = &gTheGame.cursorBlock[num];

        bcopy(cursor, &dynamicp->cursorBlock[num], sizeof(cursor_t));
        bcopy(&well->block, &dynamicp->block[num], sizeof(block_t) * BLOCK_LEN_ROWS * BLOCK_LEN_B);

        // Why only the first 4 bytes? Could this be a bug or is it intentional?
        bzero(&dynamicp->frontTexture[num], 4);
        // Why only the first 4 bytes? Could this be a bug or is it intentional?
        bzero(&dynamicp->backTexture[num], 4);

        var_s0 = dynamicp->block[num];
        for (var_v1 = 0; var_v1 < BLOCK_LEN_ROWS; var_v1++) {
            block_t *something = var_s0[var_v1];

            for (var_a2 = 1; var_a2 < BLOCK_LEN_B / 2; var_a2++) {
                frame = var_s7[something[var_a2].frame_n];
                something[var_a2].frame_n = frame;
                dynamicp->frontTexture[num][frame] = 1;
            }

            for (var_a2 = BLOCK_LEN_B / 2; var_a2 < BLOCK_LEN_B; var_a2++) {
                frame = var_s7[something[var_a2].frame_n];
                something[var_a2].frame_n = frame;
                dynamicp->backTexture[num][frame] = 1;
            }

            frame = var_s7[something[0].frame_n];
            something[0].frame_n = frame;
            dynamicp->backTexture[num][frame] = 1;
        }

        bcopy(&well->icon, &dynamicp->icon[num], sizeof(icon_t) * ICON_COUNT);
        bcopy(&well->attack, &dynamicp->attack[num], sizeof(attack_t) * ATTACK_COUNT);
        bcopy(&well->explosion, &dynamicp->explosion[num], sizeof(explode_t) * EXPLOSION_COUNT);
        bcopy(&well->visible, &dynamicp->visible[num], sizeof(char) * BLOCK_LEN_ROWS * BLOCK_LEN_B);

        if (gSelection == SELECTION_64) {
            gTransMtx[3][0] = -0.51f;
        } else if (gTheGame.totalPlayer == 1) {
            gTransMtx[3][0] = 0.06f;
        } else if (num == 0) {
            gTransMtx[3][0] = -0.51f;
        } else {
            gTransMtx[3][0] = 0.51f;
        }

        gTransMtx[3][1] = well->translation + DOUBLE_LITERAL(0.01);

        guMtxF2L(gTransMtx, &dynamicp->trans[num]);

        if (cursor->sx > 0) {
            var_v1 = ABS(cursor->sx);

            gRotateYMtx[0][0] = rotate_cos[var_v1];
            gRotateYMtx[2][0] = rotate_sin[var_v1];
            gRotateYMtx[0][2] = -rotate_sin[var_v1];
            gRotateYMtx[2][2] = rotate_cos[var_v1];
        } else if (cursor->sx < 0) {
            var_v1 = ABS(cursor->sx);

            gRotateYMtx[0][0] = rotate_cos[var_v1];
            gRotateYMtx[2][0] = -rotate_sin[var_v1];
            gRotateYMtx[0][2] = rotate_sin[var_v1];
            gRotateYMtx[2][2] = rotate_cos[var_v1];
        } else {
            gRotateYMtx[0][0] = 1.0f;
            gRotateYMtx[2][0] = 0.0f;
            gRotateYMtx[0][2] = 0.0f;
            gRotateYMtx[2][2] = 1.0f;
        }

        guMtxF2L(gRotateYMtx, &dynamicp->rotate[num]);

        if (cursor->sy != -1) {
            var_a2 = 3 - cursor->extra_wait;

            gRotateYMtx[0][0] = switch_cos[var_a2];
            gRotateYMtx[2][0] = switch_sin[var_a2];
            gRotateYMtx[0][2] = -switch_sin[var_a2];
            gRotateYMtx[2][2] = switch_cos[var_a2];

            guMtxF2L(gRotateYMtx, &dynamicp->left3D[num]);

            var_a2 = cursor->extra_wait - 1;

            gRotateYMtx[0][0] = switch_cos[var_a2];
            gRotateYMtx[2][0] = switch_sin[var_a2];
            gRotateYMtx[0][2] = -switch_sin[var_a2];
            gRotateYMtx[2][2] = switch_cos[var_a2];

            guMtxF2L(gRotateYMtx, &dynamicp->right3D[num]);
        }
    }

    bcopy(&gTheGame.drawText, &dynamicp->drawText, sizeof(text_t) * DRAWTEXT_COUNT);
}
