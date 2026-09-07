/**
 * Original filename: update.c
 */

#include "update.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "libc/assert.h"

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

/**
 * Original name: rotate_cos
 */
f32 rotate_cos[4] = {
    0.939693f,
    0.965926f,
    0.984808f,
    0.996195f,
};

/**
 * Original name: rotate_sin
 */
f32 rotate_sin[4] = {
    0.34202f,
    0.258819f,
    0.173648f,
    0.087156f,
};

/**
 * Original name: switch_cos
 */
f32 switch_cos[3] = {
    0.087156f,
    0.0f,
    -0.087156f,
};

/**
 * Original name: switch_sin
 */
f32 switch_sin[3] = {
    0.996195f,
    1.0f,
    0.996195f,
};

char D_800B7508_usa[] = {
    3, 4, 3, 2, 1, 2, 3, 5, 6, 7, 8, 9, 4, 2, 1, 2, 10, 11, 12, 13,
};

/**
 * Original name: TetrisBlockFrame
 */
char TetrisBlockFrame[] = {
    3, 4, 3, 2, 1, 2, 3, 5, 6, 4, 2, 1, 2, 6, 7, 8, 9, 0, 0, 0,
};

static_assert(ARRAY_COUNT(D_800B7508_usa) == ARRAY_COUNT(TetrisBlockFrame), "");

/**
 * Original name: UpdateBlockFrame
 */
void UpdateBlockFrame(block_t *block) {
    s32 temp_a1 = (gGameStatus & GAME_STATUS_FLAG_40) ? 3 : 0;

    if (block->frame_n == 0) {
        return;
    }

    block->frame_d--;
    if (block->frame_d != 0) {
        return;
    }

    block->frame_n++;
    if (block->frame_n >= (0xC - temp_a1)) {
        if (block->frame_n >= (0x10 - temp_a1)) {
            block->frame_n = 0;
            return;
        }
    } else {
        if (block->frame_n >= 7) {
            block->frame_n = 0;
            return;
        }
    }

    if (gGameStatus & GAME_STATUS_FLAG_40) {
        switch (block->frame_n) {
            case 0x1:
            case 0x4:
                block->frame_d = 4;
                break;

            case 0x2:
            case 0x3:
            case 0x5:
            case 0x6:
            case 0x9:
            case 0xA:
            case 0xB:
                block->frame_d = 2;
                break;

            case 0xC:
                block->frame_d = 1;
                break;
        }
    } else {
        switch (block->frame_n) {
            case 0x1:
            case 0x4:
                block->frame_d = 4;
                break;

            case 0x2:
            case 0x3:
            case 0x5:
            case 0x6:
            case 0xC:
            case 0xD:
            case 0xE:
                block->frame_d = 2;
                break;

            case 0xF:
                block->frame_d = 1;
                break;
        }
    }
}

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

/**
 * Original name: UpdateNextLevel
 */
void UpdateNextLevel(tetWell *well) {
    s32 next = well->nextLevel;
    s32 level = well->currLevel;

    switch (gSelection) {
        case SELECTION_8C:
            if (gGameStatus & GAME_STATUS_FLAG_20) {
                break;
            }
            FALLTHROUGH;

        case SELECTION_BE:
            if ((level == 1) & (next >= 9)) {
                level += 1;
                next -= 9;
            } else if ((level >= 2) && (level <= 6) && (next >= 0xC)) {
                level += 1;
                next -= 0xC;
            } else if ((level >= 7) && (level <= 8) && (next >= 0xE)) {
                level += 1;
                next -= 0xE;
            } else if (((level >= 9) && (level <= 10) && (next >= 0x10))) {
                level += 1;
                next -= 0x10;
            } else if ((level >= 0xB) && (level <= 0xF) && (next >= 0x18)) {
                level += 1;
                next -= 0x18;
            } else if ((level == 0x10) & (next >= 0x16)) {
                level += 1;
                next -= 0x16;
            } else if ((level == 0x11) & (next >= 0x14)) {
                level += 1;
                next -= 0x14;
            } else if ((level == 0x12) & (next >= 0x12)) {
                level += 1;
                next -= 0x12;
            } else if ((level >= 0x13) && (level <= 0x14) && (next >= 0x10)) {
                level += 1;
                next -= 0x10;
            } else if ((level >= 0x15) && (level <= 0x1E) && (next >= 0x24)) {
                level += 1;
                next -= 0x24;
            } else if ((level >= 0x1F) && (level <= 0x28) && (next >= 0x27)) {
                level += 1;
                next -= 0x27;
            } else if ((level >= 0x29) && (level <= 0x62) && (next >= 0x2D)) {
                level += 1;
                next -= 0x2D;
            }

            if (level != well->currLevel) {
                if (((gGameStatus ^ GAME_STATUS_FLAG_1) & GAME_STATUS_FLAG_1) && (level > 0x32)) {
                    level = 0x32;
                } else {
                    StartFlash(0x78);
                }

                well->nextLevel = next;
                well->currLevel = level;
                UpdateRaiseTimer(well);
            }
            break;

        case SELECTION_AA:
            next--;
            if (next <= 0) {
                level++;
                if (level > 0x63) {
                    level = 0x63;
                } else {
                    StartFlash(0x78);
                }

                next = level - st_kClearStage[well->level][0];
                if ((next >= 1) && (next <= 3)) {
                    well->nextLevel = 0x384;
                } else if ((next >= 4) && (next <= 0x13)) {
                    well->nextLevel = 0x258;
                } else {
                    well->nextLevel = 0x12C;
                }

                well->currLevel = level;
                UpdateRaiseTimer(well);
            } else {
                well->nextLevel = next;
            }
            break;

        case SELECTION_96:
        case SELECTION_A0:
        case SELECTION_B4:
        case SELECTION_C8:
            next--;
            if (next <= 0) {
                level++;
                if (level > 0x63) {
                    level = 0x63;
                }
                next = level - st_Player2State[well->level][5];
                if (next > 0x27) {
                    next = 0x27;
                }
                well->nextLevel = st_AdvanceLevel[next];
                well->currLevel = level;
                UpdateRaiseTimer(well);
            } else {
                well->nextLevel = next;
            }
            break;

        default:
            break;
    }

    if ((gSelection == SELECTION_96) || (gSelection == SELECTION_A0)) {
        if (well->clearGarbage <= 0) {
            if (well->maxGarbage-- <= 0) {
                return;
            }

            well->queueGarbage++;
            well->clearGarbage += st_Player2State[well->level][8];
        }
    }
}

/**
 * Original name: UpdateRaiseTimer
 */
void UpdateRaiseTimer(tetWell *well) {
    s32 level = well->currLevel - 1;

    if (level > 0x62) {
        level = 0x62;
    }

    well->speed = ADJUST_FRAMERATE_INV(0x01000000 / st_RaiseTimer[level]);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateComboScore);
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
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateChainScore);
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
#ifdef NON_MATCHING
// regalloc
void UpdatePlayerPuzzle(s32 *arg0, s32 arg1, s32 arg2) {
    s8 temp_v0;
    char *var_a3;

    if (arg1 == 0) {
        return;
    }

    gPlayer[0]->unk_0B4 = gTheGame.hour;
    gPlayer[0]->unk_0B5 = gTheGame.minute;
    gPlayer[0]->unk_0B6 = gTheGame.second;

    if (gDemo != GDEMO_2C) {
        return;
    }
    if (gMain == GMAIN_388) {
        return;
    }

    if (*arg0 == 8) {
        return;
    }

    arg2--;
    temp_v0 = arg2 / 8;
    arg2 -= arg2 / 8 * 8;

    switch (arg1) {
        case 0x1:
            var_a3 = &gPlayer[0]->kPLAYER1P_easy1[temp_v0];
            break;
        case 0x2:
            var_a3 = &gPlayer[0]->kPLAYER1P_easy2[temp_v0];
            break;
        case 0x3:
            var_a3 = &gPlayer[0]->kPLAYER1P_hard1[temp_v0];
            break;
        case 0x4:
            var_a3 = &gPlayer[0]->kPLAYER1P_hard2[temp_v0];
            break;
        case 0x5:
            var_a3 = &gPlayer[0]->kPLAYER1P_special1[temp_v0];
            break;
        case 0x6:
            var_a3 = &gPlayer[0]->kPLAYER1P_special2[temp_v0];
            break;
    }

    *var_a3 |= 1 << arg2;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdatePlayerPuzzle);
#endif
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

/**
 * Original name: CheckPlayerPuzzleRound
 */
nbool CheckPlayerPuzzleRound(s32 game, s32 stage) {
    char *ptr;
    s32 group; // enum?

    if (game == 0) {
        return nfalse;
    }

    if (stage < 0x1F) {
        group = 1;
    } else if (stage < 0x29) {
        group = 2;
    } else {
        group = 3;
    }

    switch (game) {
        case 0x1:
            ptr = gPlayer[0]->kPLAYER1P_easy1;
            break;

        case 0x2:
            ptr = gPlayer[0]->kPLAYER1P_easy2;
            break;

        case 0x3:
            ptr = gPlayer[0]->kPLAYER1P_hard1;
            break;

        case 0x4:
            ptr = gPlayer[0]->kPLAYER1P_hard2;
            break;

        case 0x5:
            ptr = gPlayer[0]->kPLAYER1P_special1;
            break;

        case 0x6:
            ptr = gPlayer[0]->kPLAYER1P_special2;
            break;
    }

    switch (group) {
        case 1:
            if (CHECK_FLAG_ALL(ptr[0], 0xFF) && CHECK_FLAG_ALL(ptr[1], 0xFF) && CHECK_FLAG_ALL(ptr[2], 0xFF) &&
                CHECK_FLAG_ALL(ptr[3], 0x3F)) {
                return ntrue;
            }
            break;

        case 2:
            if (CHECK_FLAG_ALL(ptr[3], 0xC0) && CHECK_FLAG_ALL(ptr[4], 0xFF)) {
                return ntrue;
            }
            break;

        case 3:
            if (CHECK_FLAG_ALL(ptr[5], 0xFF) && CHECK_FLAG_ALL(ptr[6], 3)) {
                return ntrue;
            }
            break;
    }

    return nfalse;
}

/**
 * Original name: PlayPlayerPuzzleEnding
 */
nbool PlayPlayerPuzzleEnding(s32 game, s32 stage) {
    char *ptr;

    switch (game) {
        case 0x1:
            ptr = &gPlayer[0]->kPLAYER1P_easy1[ARRAY_COUNT(gPlayer[0]->kPLAYER1P_easy1) - 1];
            break;

        case 0x2:
            ptr = &gPlayer[0]->kPLAYER1P_easy2[ARRAY_COUNT(gPlayer[0]->kPLAYER1P_easy2) - 1];
            break;

        case 0x3:
            ptr = &gPlayer[0]->kPLAYER1P_hard1[ARRAY_COUNT(gPlayer[0]->kPLAYER1P_hard1) - 1];
            break;

        case 0x4:
            ptr = &gPlayer[0]->kPLAYER1P_hard2[ARRAY_COUNT(gPlayer[0]->kPLAYER1P_hard2) - 1];
            break;

        case 0x5:
            ptr = &gPlayer[0]->kPLAYER1P_special1[ARRAY_COUNT(gPlayer[0]->kPLAYER1P_special1) - 1];
            break;

        case 0x6:
            ptr = &gPlayer[0]->kPLAYER1P_special2[ARRAY_COUNT(gPlayer[0]->kPLAYER1P_special2) - 1];
            break;
    }

    if (!(*ptr & 0x80)) {
        *ptr |= 0x80;
        return ntrue;
    }

    if (((game == 1) || (game == 4))) {
        if (stage == 0x1E) {
            return ntrue;
        }
    } else {
        if (stage == 0x32) {
            return ntrue;
        }
    }

    return nfalse;
}

/**
 * Original name: UpdatePlayerStageClear
 */
void UpdatePlayerStageClear(cursor_t *cursor, s32 round, s32 stage) {
    char bit;
    char index;
    char *ptr;

    if (gDemo != GDEMO_2C) {
        return;
    }

    UpdatePlayerStageClearTimeScore(cursor, 0, round, stage);

    if (gMain == GMAIN_388) {
        return;
    }

    if (gTheGame.menu[0].game == 5) {
        if (round != 3) {
            return;
        }
        index = 2;
        bit = 5;
    } else {
        if (cursor->state == 8) {
            return;
        }
        index = round - 1;
        bit = stage - 1;
    }

    ptr = &gPlayer[0]->kPLAYER1C_2Dround[index];
    *ptr |= 1 << bit;
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
void UpdatePlayerStageClearTimeScore(cursor_t *cursor, s32 loadsave, s32 round, s32 stage) {
    s32 *temp_v1_2;
    s32 *temp_v1_3;
    s32 temp_v1;
    s32 temp_v1_4;
    s32 var_a3;
    s32 var_t1;
    s32 var_v0;

    if (gTheGame.menu[0].game == 5) {
        var_a3 = (round != 3) ? 0x1F : 0xF;
    } else {
        temp_v1 = round - 1;
        if (round < 4) {
            var_v0 = (temp_v1 * 5) - 1;
        } else {
            var_v0 = temp_v1 * 5;
        }
        var_a3 = var_v0 + stage;
    }

    if (loadsave != 0) {
        if (var_a3 != 0) {
            if (gDemo != GDEMO_2C) {
                return;
            }
        } else {
            if (gPlayer[0]->unk_034[0] == 0) {
                gTheGame.second = 0;
                gTheGame.minute = 0;
                gTheGame.hour = 0;
                gTheGame.tetrisWell[0].score = 0;
                return;
            }
        }
    }

    if (loadsave != 0) {
        gTheGame.tetrisWell[0].score = gPlayer[0]->kPLAYER1C_2Dscore;

        temp_v1_2 = &gPlayer[0]->unk_034[var_a3 - ((gPlayer[0]->unk_034[var_a3] == 0) ? 1 : 0)];
        gTheGame.hour = (s8)((temp_v1_2[0] >> 16) & 0xFF);
        gTheGame.minute = (s8)((temp_v1_2[0] >> 8) & 0xFF);
        gTheGame.second = (s8)((temp_v1_2[0] >> 0) & 0xFF);
        return;
    }

    if (var_a3 == 0x1F) {
        var_t1 = gTheGame.second + (gTheGame.minute * 0x3C) + (gTheGame.hour * 0xE10);
    }
    temp_v1_3 = &gPlayer[0]->unk_034[var_a3];
    *temp_v1_3 = gTheGame.hour << 0x10;
    *temp_v1_3 |= gTheGame.minute << 8;
    *temp_v1_3 |= gTheGame.second;
    if ((cursor->state == 7) || ((var_a3 == 0xF) && (cursor->state == 8))) {
        if (var_a3 < 0x1F) {
            gPlayer[0]->kPLAYER1C_2Dscore = gTheGame.tetrisWell[0].score;
            return;
        }

        if (var_a3 != 0x1F) {
            return;
        }

        temp_v1_4 = gPlayer[0]->unk_02A + (gPlayer[0]->unk_029 * 0x3C) + (gPlayer[0]->unk_028 * 0xE10);
        if ((temp_v1_4 == 0) || (var_t1 < temp_v1_4)) {
            gPlayer[0]->unk_028 = gTheGame.hour;
            gPlayer[0]->unk_029 = gTheGame.minute;
            gPlayer[0]->unk_02A = gTheGame.second;
        }
    }

    gPlayer[0]->kPLAYER1C_2Dscore = 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdatePlayerStageClearTimeScore);
#endif
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

/**
 * Original name: UpdatePlayerCPU
 */
void UpdatePlayerCPU(s32 game, s32 stage) {
    if (gDemo != GDEMO_2C) {
        return;
    }

    switch (game) {
        case 0x1:
            gPlayer[0]->kPLAYER1V_kEASY = stage;
            break;

        case 0x2:
            gPlayer[0]->kPLAYER1V_kNORMAL = stage;
            break;

        case 0x3:
            gPlayer[0]->kPLAYER1V_kHARD = stage;
            break;

        case 0x4:
            gPlayer[0]->kPLAYER1V_kSHARD = stage;
            break;

        case 0x5:
            gPlayer[0]->kPLAYER1V_kULTRA = stage;
            break;
    }
}

#if VERSION_USA
extern u16 st_Combo1[];
extern u8 st_Chain2[];
extern u8 st_Combo2[];
extern u16 st_Chain1[];

#ifdef NON_MATCHING
// extra instruction
void UpdateComboChainCount(s32 num, s32 combo, s32 total) {
    s32 var_a2;
    s8 temp_a0;
    s8 *var_t0;
    s8 *var_t1;

    if (gDemo != GDEMO_2C) {
        return;
    }
    if (total == 0) {
        return;
    }
    if ((combo != 0) && (total == 3)) {
        return;
    }
    if (gSelection < SELECTION_83) {
        return;
    }
    if ((gSelection == SELECTION_A0) || (gSelection == SELECTION_C8)) {
        return;
    }
    if (gSelection == SELECTION_B4) {
        return;
    }
    if (gMain != GMAIN_387) {
        return;
    }

    // TODO: Remove (void *) cast and fix types
    switch (gSelection) {
        case SELECTION_96:
            var_t1 = (void *)&gPlayer[num]->unk_0EF;
            var_t0 = (void *)&gPlayer[num]->unk_0F0;
            break;

        case SELECTION_AA:
            var_t1 = (void *)&gPlayer[num]->unk_0ED;
            var_t0 = (void *)&gPlayer[num]->unk_0EE;
            break;

        case SELECTION_8C:
            if (gTheGame.dimension == DIMENSION_2D) {
                var_t1 = (void *)&gPlayer[num]->unk_0E5;
                var_t0 = (void *)&gPlayer[num]->unk_0E6;
            } else {
                var_t1 = (void *)&gPlayer[num]->unk_0E7;
                var_t0 = (void *)&gPlayer[num]->unk_0E8;
            }
            break;

        case SELECTION_BE:
            if (gTheGame.dimension == DIMENSION_2D) {
                var_t1 = (void *)&gPlayer[num]->unk_0E9;
                var_t0 = (void *)&gPlayer[num]->unk_0EA;
            } else {
                var_t1 = (void *)&gPlayer[num]->unk_0EB;
                var_t0 = (void *)&gPlayer[num]->unk_0EC;
            }
            break;

        default:
            break;
    }

    if (combo != 0) {
        if (*var_t1 < temp_a0) {
            *var_t1 = temp_a0;
        }
        if (total < 0xB) {
            var_a2 = total - 4;
            st_Combo1[var_a2]++;
        } else {
            var_a2 = total - 0xB;
            if (total >= 0x46) {
                var_a2 = 0x46 - 0xB;
            }

            st_Combo2[var_a2]++;
        }
    } else {
        temp_a0 = total + 1;
        if (*var_t0 < temp_a0) {
            *var_t0 = temp_a0;
        }

        if (total < 0xA) {
            var_a2 = total - 1;
            st_Chain1[var_a2]++;
        } else {
            var_a2 = total - 0xA;
            if (total >= 0x63) {
                var_a2 = 0x63 - 0xA;
            }
            st_Chain2[var_a2]++;
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateComboChainCount);
#endif
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
#ifdef NON_MATCHING
// branch likelies issues
void UpdateWell(tetWell *well, cursor_t *cursor, s32 num, s32 total) {
    s32 var_s2;       // row
    s32 sp18;         // col
    BlockType var_s7; // type
    s32 sp34;
    s32 sp3C;
    s32 sp44; // explode?
    s32 sp4C;
    s32 sp54;
    s32 sp5C;
    s32 sp64;
    s32 sp6C;
    s32 temp_a2;
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_a1_6;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_s5;
    s32 var_s6;
    block_t *temp_s0;   // block
    block_t *temp_v1_2; // blk

#if 0
    // Local variables
    int row; // r28
    int col; // r1+0x18
    int type; // r23
    int accum; // r21
    int explode; // r1+0x8
    int wait; // r1+0x28
    int up; // r4
    int down; // r5
    int count; // r1+0x8
    int try; // r20
    int space; // r17
    int check1; // r1+0x24
    int check2; // r1+0x20
    int sound; // r22
    int connect; // r25
    int temp; // r4
    struct block_t * block; // r31
    struct block_t * blk; // r1+0x8
#endif

    var_s6 = 0;
    sp54 = 0;
    sp5C = 0;
    sp64 = 0;
    sp6C = 0;

    sp3C = well->comboFace;
    sp44 = well->comboExplode;
    sp34 = (gGameStatus & GAME_STATUS_FLAG_40) ? 3 : 0;
    sp4C = well->blockDropDelay;

    for (var_s2 = BLOCK_LEN_ROWS - 1; var_s2 >= 0; var_s2--) {
        var_s5 = 0;

        for (sp18 = 0; sp18 < gMax; sp18++) {
            temp_s0 = &well->block[var_s2][sp18];
            var_s7 = temp_s0->type;

            if (var_s7 != BLOCKTYPE_0) {
                if (temp_s0->state == BLOCKSTATE_7) {
                    if ((sp18 == 0) && (gMax == BLOCK_LEN_B)) {
                        var_s5 = UpdateWell3DRowConnect(well, var_s2, &sp18);
                        if (var_s5 != 0) {
                            if (sp18 != 0) {
                                continue;
                            }
                            var_s5 = 0;
                        }
                    }

                    temp_s0->state = BLOCKSTATE_8;
                    temp_s0->disappear = sp3C;
                    sp3C += sp44;
                    temp_s0->drop = well->comboFace + (total - 1) * sp44 + 1;
                    if ((total >= 6) && (temp_s0->bomb == 0x1E)) {
                        temp_s0->bomb = 0x1F;
                    }
                    temp_s0->sound += sp6C;
                    sp6C += 1;

                    temp_a2 = var_s2 + 1;
                    if (temp_a2 < BLOCK_LEN_ROWS) {
                        if (well->block[temp_a2][sp18].type == BLOCKTYPE_9) {
                            temp_v0_3 = ReturnAttackSlot(well, temp_a2, sp18);

                            if (temp_v0_3 != -1) {
                                var_s6 = -1;

                                for (var_a0 = 0; var_a0 < CURSOR_UNK_28_COUNT; var_a0++) {
                                    if (cursor->target[var_a0] == 0) {
                                        cursor->target[var_a0] = temp_v0_3 + 1;
                                        break;
                                    }
                                }

                                CheckSameAttack(well, cursor, temp_v0_3, temp_s0->bomb);
                                if (temp_s0->chain_flag != 0) {
                                    well->chain_garbage = -1;
                                }
                            }
                        }
                    }

                    var_a2 = sp18 - 1;
                    if (((gMax == 6) && (var_a2 < 0)) == 0) {
                        if (var_a2 < 0) {
                            var_a2 = BLOCK_LEN_B - 1;
                        }

                        if (well->block[var_s2][var_a2].type == BLOCKTYPE_9) {
                            temp_v0_3 = ReturnAttackSlot(well, var_s2, var_a2);

                            if (temp_v0_3 != -1) {
                                var_s6 = -1;

                                for (var_a0 = 0; var_a0 < CURSOR_UNK_28_COUNT; var_a0++) {
                                    if (cursor->target[var_a0] == 0) {
                                        cursor->target[var_a0] = temp_v0_3 + 1;
                                        break;
                                    }
                                }

                                CheckSameAttack(well, cursor, temp_v0_3, temp_s0->bomb);
                                if (temp_s0->chain_flag != 0) {
                                    well->chain_garbage = -1;
                                }
                            }
                        }
                    }

                    temp_a2 = sp18 + 1;
                    if (((gMax == 6) && (temp_a2 >= 6)) == 0) {
                        temp_a2 = (temp_a2 == BLOCK_LEN_B) ? 0 : temp_a2;

                        if (well->block[var_s2][temp_a2].type == BLOCKTYPE_9) {
                            temp_v0_3 = ReturnAttackSlot(well, var_s2, temp_a2);

                            if (temp_v0_3 != -1) {
                                var_s6 = -1;

                                for (var_a0 = 0; var_a0 < CURSOR_UNK_28_COUNT; var_a0++) {
                                    if (cursor->target[var_a0] == 0) {
                                        cursor->target[var_a0] = temp_v0_3 + 1;
                                        break;
                                    }
                                }

                                CheckSameAttack(well, cursor, temp_v0_3, temp_s0->bomb);
                                if (temp_s0->chain_flag != 0) {
                                    well->chain_garbage = -1;
                                }
                            }
                        }
                    }

                    temp_a2 = var_s2 - 1;
                    if (temp_a2 >= 0) {
                        if (well->block[temp_a2][sp18].type == BLOCKTYPE_9) {
                            temp_v0_3 = ReturnAttackSlot(well, temp_a2, sp18);
                            if (temp_v0_3 != -1) {
                                var_s6 = -1;

                                for (var_a0 = 0; var_a0 < CURSOR_UNK_28_COUNT; var_a0++) {
                                    if (cursor->target[var_a0] == 0) {
                                        cursor->target[var_a0] = temp_v0_3 + 1;
                                        break;
                                    }
                                }

                                CheckSameAttack(well, cursor, temp_v0_3, temp_s0->bomb);
                                if (temp_s0->chain_flag != 0) {
                                    well->chain_garbage = -1;
                                }
                            }
                        }
                    }

                    if (var_s6 != 0) {
                        if (num == 0) {
                            func_80005888_usa(B_801C6EE8_usa, 1, 3);
                        } else {
                            func_80005888_usa(B_801C6E58_usa, 2, 3);
                        }
                    }
                }

                if (temp_s0->state == BLOCKSTATE_8) {
                    if (temp_s0->delay > 0) {
                        gOverflow += 0x23;
                    } else if (temp_s0->delay == 0) {
                        temp_s0->delay = -1;
                    } else if (temp_s0->drop != 0) {
                        if (temp_s0->disappear > 0) {
                            temp_s0->disappear--;
                        } else {
                            var_s7 = BLOCKTYPE_0;
                            if (temp_s0->delay == -1) {
                                temp_s0->delay = -2;
                                well->score += 10;

                                PlayExplosionSound(num, temp_s0->sound);
                                if (temp_s0->type == BLOCKTYPE_7) {
                                    well->wellGarbage--;
                                }
                                StartExplosion(well, num, var_s2, sp18, temp_s0->bomb);

                                switch (gSelection) {
                                    case SELECTION_BE:
                                    case SELECTION_8C:
                                        well->nextLevel++;
                                        break;

                                    case SELECTION_96:
                                    case SELECTION_A0:
                                        well->clearGarbage--;
                                        break;

                                    default:
                                        break;
                                }
                            }
                        }

                        temp_s0->drop--;
                        if (temp_s0->drop == 0) {
                            temp_s0->delay = 0;
                        }
                    }

                    if (temp_s0->delay == 0) {
                        InitTetrisState(temp_s0);
                        var_s7 = BLOCKTYPE_0;

                        var_a2_2 = 2;
                        if (var_s2 + 1 < BLOCK_LEN_ROWS) {
                            if (well->block[var_s2 + 1][sp18].type != 0) {
                                sp64 = -1;
                                for (var_a1_6 = var_s2 - 1; var_a1_6 >= 0; var_a1_6--) {
                                    if ((well->block[var_a1_6][sp18].type != BLOCKTYPE_0) &&
                                        (well->block[var_a1_6][sp18].delay < 0)) {
                                        var_a2_2++;
                                    } else {
                                        var_a1_6 = 0;
                                    }
                                }
                            }
                        }

                        if (sp54 < var_a2_2) {
                            sp54 = var_a2_2;
                        }

                        for (var_a1_6 = var_s2 + 1; var_a1_6 < BLOCK_LEN_ROWS; var_a1_6++) {
                            temp_v1_2 = &well->block[var_a1_6][sp18];

                            // can't get to match these cheks
                            if (temp_v1_2->type != BLOCKTYPE_9) {
                                if (temp_v1_2->type != BLOCKTYPE_0) {
                                    if (temp_v1_2->state == BLOCKSTATE_4) {
                                        temp_v1_2->chain_flag = -1;
                                    } else if (temp_v1_2->state == BLOCKSTATE_0) {
                                        temp_v1_2->delay = sp4C - 1;
                                        temp_v1_2->state = BLOCKSTATE_5;
                                        temp_v1_2->chain_flag = -1;
                                    }
                                }
                            } else {
                                var_a1_6 = BLOCK_LEN_ROWS;
                            }
                        }
                    } else {
                        sp5C = -1;
                    }
                }

                if (var_s7 != BLOCKTYPE_0) {
                    UpdateBlockFrame(temp_s0);
                    if ((temp_s0->currRow != var_s2) && (temp_s0->state != BLOCKSTATE_1)) {
                        temp_s0->frame_n = 0xC - sp34;
                        temp_s0->frame_d = 2;
                        temp_s0->currRow = var_s2;
                    }

                    if (temp_s0->delay == -1) {
                        if (gGameStatus & GAME_STATUS_FLAG_40) {
                            temp_s0->frame_n = 8;
                        } else {
                            switch (temp_s0->disappear) {
                                case 0x4:
                                case 0x5:
                                case 0x6:
                                    temp_s0->frame_n = 9;
                                    break;

                                case 0x2:
                                case 0x3:
                                    temp_s0->frame_n = 0xA;
                                    break;

                                case 0x0:
                                case 0x1:
                                    temp_s0->frame_n = 0xB;
                                    break;

                                default:
                                    temp_s0->frame_n = 8;
                                    break;
                            }
                        }
                    } else if ((temp_s0->type != BLOCKTYPE_9) && (temp_s0->state == BLOCKSTATE_8)) {
                        if (temp_s0->delay % 2 != 0) {
                            temp_s0->frame_n = 7;
                        } else {
                            temp_s0->frame_n = 0;
                        }
                    }
                }
            }

            if ((var_s5 != 0) && (sp18 == BLOCK_LEN_B - 1)) {
                sp18 = -1;
            }
        }
    }

    if (sp5C != 0) {
        if (cursor->state < 2) {
            cursor->state = 1;
        }
    } else {
        if (cursor->state < 2) {
            cursor->state = 0;
        }
        if (cursor->unk_0C != 0) {
            cursor->unk_0C--;
        }
    }

    sp4C += sp54;
    if (sp64 != 0) {
        if (cursor->waiting < sp4C) {
            cursor->waiting = sp4C;
        }
        gOverflow += 0x3C;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateWell);
#endif
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
