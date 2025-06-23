/**
 * Original filename: ai.c
 */

#include "ai.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "animate.h"
#include "animate2d.h"
#include "animate3d.h"
#include "animation.h"
#include "pause.h"
#include "sfxlimit.h"
#include "sound.h"

s32 AIChainGarbage2(struct tetWell *well, struct ai_t *brain, BlockType below, s32 col);

void InitAI(tetWell *well, cursor_t *cursor, ai_t *brain) {
    s32 count;

    brain->unk_01C = 1;
    brain->unk_020 = 0;
    brain->unk_024 = -1;
    brain->unk_038 = 0;
    brain->unk_010 = brain->unk_00C;
    AIClearCommand(brain);
    AIFinishMove(brain);

    for (count = 0; count < AI_MOVE_COUNT; count++) {
        brain->move[count] = 0;
    }

    brain->cursor_x = 2;
    brain->cursor_y = 5;
    AISetCursor(well, cursor, brain);
    AIChangeVision(brain);

    if (gSelection == 0x96) {
        if (AnimationRandom(0x13D) % 2 == 0) {
            AIAddCommand(brain, 1, 2, 0);
            AIAddCommand(brain, 0xA, 0, 0);
        } else if (AnimationRandom(0x42) % 2 == 0) {
            AIAddCommand(brain, 1, 3, 0);
            AIAddCommand(brain, 0xA, 0, 0);
        }
    }
}

INLINE void AISetEasy(ai_t *brain, s32 stage) {
    DATA_INLINE_CONST2 u8 characteristic[] = { 0, 1, 3, 3, 3, 3, 3, 3, 7, 7, 7 };

    brain->unk_014 = characteristic[stage - 1];
    AISetCharacter(brain, stage);
    brain->unk_00C = 35 - (stage - 1) / 2;
    brain->unk_008 = -1;
}

INLINE void AISetNormal(ai_t *brain, s32 stage) {
    DATA_INLINE_CONST2 u8 characteristic[] = {
        1, 3, 3, 3, 3, 7, 7, 7, 7, 15, 15, 15, 15, 15,
    };

    brain->unk_014 = characteristic[stage - 1];
    AISetCharacter(brain, stage);
    brain->unk_00C = 20 - (stage - 1) / 2;
    if (brain->unk_018 < -3) {
        brain->unk_018 = -3;
    }
    brain->unk_008 = 0;
}

INLINE void AISetHard(ai_t *brain, s32 stage) {
    DATA_INLINE_CONST2 u8 characteristic[] = {
        0x23, 0x27, 0x27, 0x2F, 0x2F, 0xAF, 0xAF, 0xBF, 0xBF, 0xEF, 0xBF, 0xFF, 0xBF, 0xBF, 0xBF,
    };

    brain->unk_014 = characteristic[stage - 1];
    AISetCharacter(brain, stage);
    brain->unk_00C = 16 - (stage - 1) / 2;
    if ((brain->unk_018 != -0x63) && (brain->unk_018 != 0)) {
        brain->unk_018--;
    }
    brain->unk_008 = 0;
}

INLINE void AISetSHard(ai_t *brain, s32 stage) {
    DATA_INLINE_CONST2 u8 characteristic[] = {
        0x27, 0x2F, 0x2F, 0xAF, 0xAF, 0xAF, 0xEF, 0xFF, 0xAF, 0xEF, 0xFF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF,
    };

    brain->unk_014 = characteristic[stage - 1];
    AISetCharacter(brain, stage);

#if VERSION_USA
    if (stage < 3) {
        brain->unk_00C = 0xB;
    } else if (stage < 5) {
        brain->unk_00C = 0xA;
    } else if (stage < 7) {
        brain->unk_00C = 9;
    } else if (stage < 9) {
        brain->unk_00C = 8;
    } else {
        brain->unk_00C = 7;
    }
#else
    if (stage < 3) {
        brain->unk_00C = 0xD;
    } else if (stage < 5) {
        brain->unk_00C = 0xC;
    } else if (stage < 8) {
        brain->unk_00C = 0xB;
    } else if (stage < 0xB) {
        brain->unk_00C = 0xA;
    } else if (stage < 0xE) {
        brain->unk_00C = 9;
    } else {
        brain->unk_00C = 8;
    }
#endif

    if ((brain->unk_018 != -0x63) && (brain->unk_018 != 0)) {
        brain->unk_018 -= 2;
    }

    if (stage < 9) {
        brain->unk_008 = 0;
    } else {
        brain->unk_008 = -1;
    }
}

INLINE void AISetUltra(ai_t *brain, s32 stage) {
    DATA_INLINE_CONST2 u8 characteristic[] = {
        0x27, 0x2F, 0x2F, 0xAF, 0xAF, 0xAF, 0xEF, 0xFF, 0xAF, 0xEF, 0xFF, 0xBF, 0xBF, 0xBF, 0xBF, 0xBF,
    };

    brain->unk_014 = characteristic[stage - 1];
    AISetCharacter(brain, stage);

#if VERSION_USA
    if (stage < 5) {
        brain->unk_00C = 7;
    } else if (stage < 9) {
        brain->unk_00C = 6;
    } else if (stage < 0xD) {
        brain->unk_00C = 5;
    } else {
        brain->unk_00C = 4;
    }
#else
    if (stage < 3) {
        brain->unk_00C = 0xB;
    } else if (stage < 5) {
        brain->unk_00C = 0xA;
    } else if (stage < 7) {
        brain->unk_00C = 9;
    } else if (stage < 9) {
        brain->unk_00C = 8;
    } else {
        brain->unk_00C = 7;
    }
#endif

    brain->unk_018 = -0x63;
    brain->unk_008 = -1;
}

void AISetCharacter(ai_t *brain, s32 stage) {
    switch (stage) {
        case 0x1:
            brain->unk_018 = -1;
            break;

        case 0x2:
            brain->unk_018 = -2;
            break;

        case 0x3:
            brain->unk_018 = -3;
            break;

        case 0x4:
            brain->unk_018 = -4;
            break;

        case 0x6:
            brain->unk_018 = -5;
            break;

        case 0x7:
            brain->unk_018 = -6;
            break;

        case 0x8:
            brain->unk_018 = -7;
            break;

        case 0xA:
            brain->unk_018 = -8;
            break;

        case 0x5:
        case 0x9:
        case 0xB:
            brain->unk_018 = 0;
            break;

        case 0xC:
            brain->unk_018 = -9;
            break;

        case 0xD:
            brain->unk_018 = -10;
            break;

        case 0xE:
        case 0xF:
#if REGION_PAL
        case 0x10:
        default:
#endif
            brain->unk_018 = -0x63;
            break;
    }
}

void AISetLevel(ai_t *brain, s32 game, s32 stage) {
    switch (game) {
        case 1:
            AISetEasy(brain, stage);
            break;

        case 2:
            AISetNormal(brain, stage);
            break;

        case 3:
            AISetHard(brain, stage);
            break;

        case 4:
            AISetSHard(brain, stage);
            break;

        case 5:
        default:
            AISetUltra(brain, stage);
            break;
    }

#if REGION_PAL
    brain->unk_00C = ADJUST_FRAMERATE(brain->unk_00C);
#endif
}

void AISetCursor(tetWell *well UNUSED, cursor_t *cursor, ai_t *brain) {
    brain->cursor_x = cursor->x;
    brain->cursor_y = cursor->y;
}

INLINE void AIChangeVision(ai_t *brain) {
    s32 temp;

    brain->unk_030 = 0;
    brain->unk_034 = 5;
    temp = brain->cursor_y + 2;
    if (temp > 0xB) {
        brain->unk_028 = 0xB;
    } else {
        brain->unk_028 = temp;
    }

    temp = brain->cursor_y - 2;
    if (temp < 0) {
        brain->unk_02C = 0;
    } else {
        brain->unk_02C = temp;
    }
}

INLINE void AISetGarbage(tetWell *well, cursor_t *cursor, ai_t *brain) {
    s32 lowest;

    if (cursor->unk_00 == 2 || cursor->unk_00 == 3) {
        return;
    }

    for (lowest = 1; lowest < BLOCK_LEN_ROWS; lowest++) {
        block_t *block = well->block[lowest];

        if (block[2].type == BLOCKTYPE_9) {
            break;
        }
        if (block[3].type == BLOCKTYPE_9) {
            break;
        }
    }

    if (lowest >= BLOCK_LEN_ROWS) {
        lowest = -1;
    }
    brain->unk_024 = lowest;
}

INLINE void AIAddCommand(ai_t *brain, s32 func, s32 para1, s32 para2) {
    command_t *command = &brain->unk_048[brain->unk_100];

    command->function = func;
    command->para1 = para1;
    command->para2 = para2;
    brain->unk_104++;
    brain->unk_100++;
}

void AIDelCommand(ai_t *brain, s32 total) {
    brain->unk_104 -= total;
    brain->unk_100 -= total;
}

INLINE void AISetMove(ai_t *brain, s32 move) {
    brain->move[brain->unk_128] = move;
    brain->unk_128++;
}

void AIFinishMove(ai_t *brain) {
    brain->unk_124 = 0;
    brain->unk_128 = 0;
}

void AIClearCommand(ai_t *brain) {
    brain->unk_104 = 0;
    brain->unk_0FC = 0;
    brain->unk_100 = 0;
    brain->unk_124 = 0;
    brain->unk_128 = 0;
}

#if VERSION_USA
#ifdef NON_MATCHING
s32 AIRowPack(ai_t *arg0, s32 arg1, s32 arg2) {
    s32 temp_t2;
    s32 var_a3;
    s32 var_t0;
    s32 var_v1; // count
    s32 var_t1; // move?

#if 0
    int left; // r1+0x8
    int right; // r1+0x8
    int temp; // r26
#endif

    temp_t2 = arg2 - arg1;
    if (temp_t2 < 2) {
        return 0;
    }

    var_t0 = arg0->cursor_x - arg1;
    if (var_t0 < 0) {
        var_t0 = -var_t0;
    }

    var_a3 = arg0->cursor_x - arg2 + 1;
    if (var_a3 < 0) {
        var_a3 = -var_a3;
    }

    temp_t2 = temp_t2 - 2;
    if (var_t0 < var_a3) {
        if (arg0->cursor_x < arg1) {
            var_t1 = 2;
        } else {
            var_t1 = 1;
        }

        for (var_v1 = 0; var_v1 < var_t0; var_v1++) {
            AISetMove(arg0, var_t1);
        }
        var_t1 = 2;
    } else {
        if ((arg0->cursor_x + 1) < arg2) {
            var_t1 = 2;
        } else {
            var_t1 = 1;
        }

        for (var_v1 = 0; var_v1 < var_a3; var_v1++) {
            AISetMove(arg0, var_t1);
        }
        var_t1 = 1;
    }

    AISetMove(arg0, 5);
    for (var_v1 = 0; var_v1 < temp_t2; var_v1++) {
        AISetMove(arg0, var_t1);
        AISetMove(arg0, 5);
    }
    return -1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIRowPack);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIRowPack);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIRowPack);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIRowPack);
#endif

INLINE s32 AIVertMove(ai_t *brain, s32 row) {
    s32 temp = row - brain->cursor_y;
    s32 count;

    if (temp == 0) {
        return 0;
    }

    if (temp > 0) {
        for (count = 0; count < temp; count++) {
            AISetMove(brain, 3);
        }
    } else {
        for (count = 0; count > temp; count--) {
            AISetMove(brain, 4);
        }
    }

    return -1;
}

s32 AIHoriMove(ai_t *brain, s32 column) {
    s32 temp;
    s32 count;

    if ((column == 5) && (gTheGame.unk_9C0C != 2)) {
        temp = 4;
    } else {
        temp = MAX(column, 0);
    }

    temp -= brain->cursor_x;
    if (temp == 0) {
        return 0;
    }

    if (temp > 0) {
        for (count = 0; count < temp; count++) {
            AISetMove(brain, 2);
        }
    } else {
        for (count = 0; count > temp; count--) {
            AISetMove(brain, 1);
        }
    }

    return -1;
}

INLINE s32 AIHoriMoveBlock(ai_t *brain, s32 from, s32 to) {
    s32 var_v1;
    s32 var_v1_2;
    s32 var_a3;
    s32 var_t0;

    if (from < to) {
        var_v1 = brain->cursor_x;
        to = (to - from) - 1;
        var_t0 = 2;
    } else if (to < from) {
        var_v1 = brain->cursor_x + 1;
        to = (from - to) - 1;
        var_t0 = 1;
    } else {
        return 0;
    }

    if (var_v1 < from) {
        var_a3 = 2;
        from = from - var_v1;
    } else if (from < var_v1) {
        var_a3 = 1;
        from = var_v1 - from;
    } else {
        //! @bug: var_a3 not set
        from = -1;
    }

    for (var_v1_2 = 0; var_v1_2 < from; var_v1_2++) {
        AISetMove(brain, var_a3);
    }

    AISetMove(brain, 5);

    for (var_v1_2 = 0; var_v1_2 < to; var_v1_2++) {
        AISetMove(brain, var_t0);
        AISetMove(brain, 5);
    }

    return -1;
}

#if VERSION_USA
#if 0
s32 AIHoriMoveCheckCheck(tetWell *well, ai_t *brain, s32 from, s32 to) {
    u32 var_a0_2;

    s32 temp_t0;

    s32 var_t1;

    s32 temp_t2;

    s32 temp_t3;

    s32 temp_t5;

    s32 var_v1;
    u32 var_v1_27;

    temp_t2 = brain->cursor_y;
    temp_t3 = well->block[temp_t2][from].type;
    if ((temp_t3 == 0) || (temp_t3 >= 8)) {
        return 0;
    }

    if (from < to) {
        to = to - from;
        from = from + 1;

        if (temp_t2 >= 2) {
            temp_t0 = temp_t2 - 2;

            for (var_t1 = 0; var_t1 < to; var_t1++) {
                var_v1 = from + var_t1;
                if ((well->block[temp_t2 - 1][var_v1].type == temp_t3) && (well->block[temp_t2 - 1][var_v1].state != 8)) {

                    if ((well->block[temp_t0][var_v1].type == temp_t3) && (well->block[temp_t0][var_v1].state != 8)) {
                        AIVertMove(brain, temp_t0);

                        AIHoriMoveBlock(brain, var_v1, var_v1 - 1);

                        AIVertMove(brain, temp_t2 + 2);

                        brain->cursor_x = var_v1 - 1;
                        return -1;
                    }
                }

            }
        }

        if (temp_t2 < 0xA) {
            temp_t0 = temp_t2 + 1;
            var_v1 = from;

            for (var_t1 = 0; var_t1 < to; var_t1++) {
                var_v1 = from + var_t1;
                if ((well->block[temp_t0][var_v1].type == temp_t3) && (well->block[temp_t0][var_v1].state != 8)) {
                    if ((well->block[temp_t2 + 2][var_v1].type == temp_t3) && (well->block[temp_t2 + 2][var_v1].state != 8)) {
                        AIVertMove(brain, temp_t0);

                        AIHoriMoveBlock(brain, var_v1, var_v1-1);

                        AIVertMove(brain, temp_t2 - 1);

                        brain->cursor_x = var_v1 - 1;
                        return -1;
                    }
                }

            }
        }

        var_a0_2 = temp_t2 - 1;
        if (var_a0_2 < 0xAU) {
            temp_t0 = temp_t2 + 1;

            for (var_t1 = 0; var_t1 < to; var_t1++) {
                var_v1 = from + var_t1;
                if ((well->block[temp_t0][var_v1].type == temp_t3) && (well->block[temp_t0][var_v1].state != 8)) {
                    if ((well->block[var_a0_2][var_v1].type == temp_t3) && (well->block[var_a0_2][var_v1].state != 8)) {
                        AIVertMove(brain, temp_t0);

                        AIHoriMoveBlock(brain, var_v1, var_v1-1);

                        AIVertMove(brain, var_a0_2);

                        brain->cursor_x = var_v1 - 1;
                        return -1;
                    }
                }
            }
        }
    } else if (to < from) {
        to = from - to;
        from = from - 1;

        if (temp_t2 >= 2) {
            temp_t5 = temp_t2 - 2;
            temp_t0 = from;

            for (var_t1 = 0; var_t1 < to; var_t1++, temp_t0--) {
                if ((well->block[temp_t2 - 1][temp_t0].type == temp_t3) && (well->block[temp_t2 - 1][temp_t0].state != 8)) {
                    if ((well->block[temp_t5][temp_t0].type == temp_t3) && (well->block[temp_t5][temp_t0].state != 8)) {
                        AIVertMove(brain, temp_t5);

                        AIHoriMoveBlock(brain, temp_t0, temp_t0 + 1);

                        AIVertMove(brain, temp_t2 + 2);

                        brain->cursor_x = temp_t0;
                        return -1;
                    }
                }
            }
        }

        if (temp_t2 < 0xA) {

            temp_t5 = temp_t2 + 1;
            temp_t0 = from;

            for (var_t1 = 0; var_t1 < to; var_t1++, temp_t0--) {
                if ((well->block[temp_t5][temp_t0].type == temp_t3) && (well->block[temp_t5][temp_t0].state != 8)) {
                    if ((well->block[temp_t2 + 2][temp_t0].type == temp_t3) && (well->block[temp_t2 + 2][temp_t0].state != 8)) {
                        AIVertMove(brain, temp_t5);

                        AIHoriMoveBlock(brain, temp_t0, temp_t0 + 1);

                        AIVertMove(brain, temp_t2 - 1);

                        brain->cursor_x = temp_t0;
                        return -1;
                    }
                }
            }
        }

        var_v1_27 = temp_t2 - 1;
        if (var_v1_27 < 0xAU) {
            temp_t0 = temp_t2 + 1;

            for (var_t1 = 0; var_t1 < to; var_t1++, from--) {
                if ((well->block[var_v1_27][from].type == temp_t3) && (well->block[var_v1_27][from].state != 8)) {
                    if ((well->block[temp_t0][from].type == temp_t3) && (well->block[temp_t0][from].state != 8)) {
                        AIVertMove(brain, temp_t0);

                        AIHoriMoveBlock(brain, from, from + 1);

                        AIVertMove(brain, var_v1_27);

                        brain->cursor_x = from;
                        return -1;
                    }
                }
            }
        }

    }

    return 0;
}
#else
s32 AIHoriMoveCheckCheck(struct tetWell *well, struct ai_t *brain, s32 from, s32 to);
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIHoriMoveCheckCheck);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIHoriMoveCheckCheck);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIHoriMoveCheckCheck);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIHoriMoveCheckCheck);
#endif

#if VERSION_USA
#if 0
s32 func_80076F54_usa(ai_t * brain, s32 arg1, s32 arg2) {
    s32 var_a1;
    s32 var_v0;

    var_a1 = brain->cursor_x - arg1;
    if (var_a1 < 0) {
        var_a1 = -var_a1;
    }
    var_v0 = brain->cursor_x - (arg2 - 1);
    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }
    if (var_v0 >= var_a1) {
        return -1;
    }
    return 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80076F54_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80076F54_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80076F54_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80076F54_usa);
#endif

s32 AIMoveAcross(tetWell *well, s32 row, s32 from, s32 to) {
    nbool flag = (row != 0) ? ntrue : nfalse;

    if (from != to) {
        s32 below = row - 1;
        s32 col;

        if (from < to) {
            for (col = from + 1; col < to; col++) {
                if ((well->block[row][col].type != BLOCKTYPE_0) && (well->block[row][col].state != BLOCKSTATE_0)) {
                    return 0;
                }
                if (flag && (well->block[below][col].type == BLOCKTYPE_0)) {
                    return 0;
                }
            }
        } else if (to < from) {
            for (col = from - 1; col > to; col--) {
                if ((well->block[row][col].type != BLOCKTYPE_0) && (well->block[row][col].state != BLOCKSTATE_0)) {
                    return 0;
                }
                if (flag && (well->block[below][col].type == BLOCKTYPE_0)) {
                    return 0;
                }
            }
        }
    }

    return -1;
}

s32 AIShortestD(tetWell *well, ai_t *brain, s32 from, s32 to) {
    s32 temp_t4 = brain->cursor_y;
    BlockType type = well->block[temp_t4][from].type;
    s32 var_t2 = -1;
    s32 var_t5 = -1;
    s32 col;

#if 0
    int left; // r31
    int right; // r30
#endif

    if (well->block[temp_t4][to].type == type) {
        return to;
    }

    for (col = to - 1; brain->unk_030 <= col; col--) {
        if (well->block[temp_t4][col].type == type && (well->block[temp_t4][col].state == BLOCKSTATE_0)) {
            var_t2 = col;
            break;
        }
    }

    for (col = to + 1; col <= brain->unk_034; col++) {
        if (well->block[temp_t4][col].type == type && (well->block[temp_t4][col].state == BLOCKSTATE_0)) {
            var_t5 = col;
            break;
        }
    }

    if (var_t2 == -1) {
        return var_t5;
    }
    if (var_t5 == -1) {
        return var_t2;
    }

    if ((to - var_t2) > (var_t5 - to)) {
        return var_t5;
    } else {
        return var_t2;
    }
}

// 12 => BLOCK_LEN_ROWS ?
INLINE void AISortRows(s32 row, s32 total, s32 array[]) {
    s32 index[12];
    s32 i;
    s32 j;
    s32 var_t2;
    s32 var_t4;
    s32 var_v1;

#if 0
    int dist; // r6
    int temp; // r1+0x8
    int save; // r31
#endif

    for (i = 0; i < total; i++) {
        var_t2 = 12;

        for (j = 0; j < total; j++) {
            if (array[j] != 12) {
                var_v1 = array[j] - row;
                if (var_v1 < 0) {
                    var_v1 = -var_v1;
                }
                if (var_v1 < var_t2) {
                    var_t2 = var_v1;
                    var_t4 = j;
                }
            }
        }

        index[i] = var_t4;
        row = array[var_t4];
        array[var_t4] = 12;
    }

    for (i = 0; i < total; i++) {
        array[i] = index[i];
    }
}

#if VERSION_USA
#ifdef NON_MATCHING
s32 AIDistance(ai_t *brain, s32 row, s32 col) {
    s32 temp_a0;
    s32 var_a3;
    s32 var_v1;

    temp_a0 = brain->cursor_x;
    var_v1 = brain->cursor_y - row;
    if (var_v1 < 0) {
        var_v1 = -var_v1;
    }
    var_a3 = 0;
    if (col < temp_a0) {
        var_a3 = temp_a0 - col;
    } else if (temp_a0 < col) {
        var_a3 = (col - 1) - temp_a0;
    }
    return var_v1 + var_a3;
}
#else
// AIDistance
s32 AIDistance(struct ai_t *brain /* r28 */, s32 row /* r29 */, s32 col /* r30 */);
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIDistance);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIDistance);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIDistance);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIDistance);
#endif

s32 AILowerRow(tetWell *well, ai_t *brain, s32 row, s32 col) {
    s32 temp_t4;
    s32 var_t0;

    if (AItotCheck[col] == -1) {
        return 0;
    }

    if (row == 0) {
        return 0;
    }

    temp_t4 = row - 1;

    for (var_t0 = col - 1; var_t0 >= 0; var_t0--) {
        if ((well->block[row][var_t0].type != BLOCKTYPE_0) && (AItotCheck[var_t0] == -1)) {
            break;
        }

        if (well->block[temp_t4][var_t0].type == BLOCKTYPE_0) {
            if (AItotCheck[var_t0] != -1) {
                if (var_t0 == col - 1) {
                    AIAddCommand(brain, 1, temp_t4, 0);
                    AIAddCommand(brain, 3, col, var_t0);
                    return -1;
                } else {
                    AIAddCommand(brain, 1, row, 0);
                    AIAddCommand(brain, 3, col, var_t0);
                    return -1;
                }
            }
            break;
        }
    }

    for (var_t0 = col + 1; var_t0 < TETWELL_OBJSPRITE_LEN_B; var_t0++) {
        if ((well->block[row][var_t0].type != BLOCKTYPE_0) && (AItotCheck[var_t0] == -1)) {
            break;
        }

        if (well->block[temp_t4][var_t0].type == BLOCKTYPE_0) {
            if (AItotCheck[var_t0] != -1) {
                if (var_t0 == col + 1) {
                    AIAddCommand(brain, 1, temp_t4, 0);
                    AIAddCommand(brain, 3, col, var_t0);
                    return -1;
                } else {
                    AIAddCommand(brain, 1, row, 0);
                    AIAddCommand(brain, 3, col, var_t0);
                    return -1;
                }
            }
            break;
        }
    }

    return 0;
}

void AIVisionCheck(tetWell *well, ai_t *brain) {
    s32 i;

    bzero(AIrowCheck, sizeof(AIrowCheck));
    bzero(AIcolCheck, sizeof(AIcolCheck));
    bzero(AItotCheck, sizeof(AItotCheck));

    for (i = 0; i < ARRAY_COUNT(AIdistance); i++) {
        // TODO: use BLOCK_LEN_B?
        AIdistance[i] = 18;
    }

    AIBoundaryCheck(well, brain);
}

void AIBoundaryCheck(tetWell *well, ai_t *brain) {
    s32 *total;
    s32 temp_a2;
    BlockType type;
    s32 var_a0;
    s32 var_a3;
    s32 var_t1;
    s32 var_t3;
    s32 var_t5;

#if 0
    int i; // r9
    int j; // r25
    int row; // r10
    int col; // r11
    int limit; // r1+0x8
    int index; // r8
#endif

    if (brain->unk_024 != -1) {
        var_a0 = brain->unk_024 - 1;
    } else {
        var_a0 = brain->unk_028;
    }

    if (var_a0 - brain->unk_02C < 2) {
        return;
    }

    for (var_t5 = brain->unk_02C; var_t5 <= var_a0; var_t5++) {
        for (var_t3 = brain->unk_030; var_t3 <= brain->unk_034; var_t3++) {
            type = well->block[var_t5][var_t3].type;
            if ((type == 0) || (well->block[var_t5][var_t3].state != BLOCKSTATE_0)) {
                continue;
            }

            temp_a2 = type - 1;
            total = &AItotCheck[temp_a2];
            if (*total >= 3) {
                continue;
            }

            AIrowCheck[temp_a2][0] = var_t5;
            AIcolCheck[temp_a2][0] = var_t3;
            *total = 1;

            for (var_t1 = var_t5 + 1; var_t1 <= var_a0; var_t1++) {
                for (var_a3 = brain->unk_030; var_a3 <= brain->unk_034; var_a3++) {
                    if ((well->block[var_t1][var_a3].type == type) &&
                        (well->block[var_t1][var_a3].state == BLOCKSTATE_0)) {
                        AIrowCheck[temp_a2][*total] = var_t1;
                        AIcolCheck[temp_a2][*total] = var_a3;
                        *total += 1;
                        break;
                    }
                }

                if ((var_a3 > brain->unk_034)) {
                    break;
                }
                if (*total > 4) {
                    break;
                }
            }
        }
    }
}

s32 AIPossibleRow(tetWell *well, ai_t *brain, s32 row) {
    s32 var_a2;
    s32 var_t0;
    s32 type;
    s32 first;
    s32 second;
    s32 third;

#if 0
    int count; // r6
    int pos; // r7
#endif

    if ((well->block[row][2].type == BLOCKTYPE_9) || (well->block[row][3].type == BLOCKTYPE_9)) {
        return 0;
    }

    for (type = BLOCKTYPE_1; type < BLOCKTYPE_8; type++) {
        var_t0 = 0;
        third = -1;
        second = -1;
        first = -1;
        for (var_a2 = brain->unk_030; var_a2 <= brain->unk_034; var_a2++) {
            if ((well->block[row][var_a2].type == type) && (well->block[row][var_a2].state == BLOCKSTATE_0)) {
                var_t0++;
                if (first < 0) {
                    first = var_a2;
                } else if (second < 0) {
                    second = var_a2;
                } else if (third < 0) {
                    third = var_a2;
                }
            }
        }

        if (var_t0 >= 3) {
            goto end;
        }
    }

    return 0;

end:
    if (second - first == 1) {
        AIAddCommand(brain, 3, third, second + 1);
    } else if (third - second == 1) {
        AIAddCommand(brain, 3, first, second - 1);
    } else if (gCounter % 2 == 0) {
        AIAddCommand(brain, 8, first, second);
    } else {
        AIAddCommand(brain, 8, second, third);
    }
    return -1;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIPossibleCol);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIPossibleCol);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIPossibleCol);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIPossibleCol);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIComboCheck);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIComboCheck);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIComboCheck);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIComboCheck);
#endif

#if VERSION_USA
#if 0
s32 AICombo3a(ai_t *brain) {
    s32 sp0[12];
    s32 *var_v1;
    s32 temp_a0;
    s32 temp_t1;
    s32 var_a2;
    s32 (*new_var)[5];

    s32 t6 = AIdistance[7];
    s32 v1;
    s32 *a0;

    if (t6 == 0x12) {
        return 0;
    }

    v1 = AItotCheck[t6] - 3;
    //a0 = AIrowCheck[t6];
    new_var = AIrowCheck;
    a0 = new_var[t6];

    var_v1 = &a0[v1];
    for (var_a2 = 0; var_a2 < 3; var_a2++) {
        sp0[var_a2] = var_v1[var_a2];
    }

    AISortRows(brain->cursor_y, 3, sp0);

    temp_t1 = AIcolCheck[t6][sp0[2]];
    for (var_a2 = 0; var_a2 < 3; var_a2++) {
        temp_a0 = sp0[var_a2];
        if (temp_t1 != AIcolCheck[t6][temp_a0]) {
            AIAddCommand(brain, 1, AIrowCheck[t6][temp_a0], 0);
            AIAddCommand(brain, 3, AIcolCheck[t6][temp_a0], temp_t1);
        }
    }

    return -1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AICombo3a);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AICombo3a);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AICombo3a);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AICombo3a);
#endif

s32 AICombo3b(ai_t *brain) {
    s32 array[12];
    s32 temp_t1;
    s32 temp_v0;
    s32 var_a1;
    s32 i;

#if 0
    int row; // r1+0x8
    int col; // r27
    int temp; // r26
    int type; // r4
#endif

    for (i = 0; i < AI_CHECK_COUNT; i++) {
        if (AItotCheck[i] == 3) {
            for (var_a1 = 0; var_a1 < 3; var_a1++) {
                array[var_a1] = AIrowCheck[i][var_a1];
            }

            AISortRows(brain->cursor_y, 3, array);

            temp_t1 = AIcolCheck[i][array[2]];
            for (var_a1 = 0; var_a1 < 3; var_a1++) {
                temp_v0 = array[var_a1];
                if (temp_t1 != AIcolCheck[i][temp_v0]) {
                    AIAddCommand(brain, 1, AIrowCheck[i][temp_v0], 0);
                    AIAddCommand(brain, 4, AIcolCheck[i][temp_v0], temp_t1);
                }
            }

            return -1;
        }
    }

    return 0;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AICombo45);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AICombo45);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AICombo45);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AICombo45);
#endif

#if VERSION_USA
#ifdef NON_MATCHING
s32 AIComboX(ai_t *brain) {
    s32 sp0[12];
    s32 temp_t1;
    s32 var_a1;
    s32 t7;

    if (AItotCheck[6] == 3) {
        t7 = 6;

        for (var_a1 = 0; var_a1 < 3; var_a1++) {
            sp0[var_a1] = AIrowCheck[6][var_a1];
        }

        AISortRows(brain->cursor_y, 3, sp0);

        temp_t1 = AIcolCheck[t7][sp0[2]];
        for (var_a1 = 0; var_a1 < 3; var_a1++) {
            s32 temp3 = sp0[var_a1];
            if (temp_t1 != AIcolCheck[t7][temp3]) {
                AIAddCommand(brain, 1, AIrowCheck[t7][temp3], 0);
                AIAddCommand(brain, 4, AIcolCheck[t7][temp3], temp_t1);
            }
        }

        return -1;
    }

    return 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIComboX);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIComboX);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIComboX);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIComboX);
#endif

#if VERSION_USA
#if 0
s32 AIFlashCheck(tetWell *well, ai_t *brain) {
    s32 var_a2;
    s32 var_a3;
    s32 var_t1;
    s32 var_t3;

    var_t3 = 0;
    var_t1 = 0;
loop_2:
    if (var_t3 < 8) {

        for (var_a3 = var_t3; var_a3 < 8; var_a3++) {
            for (var_a2 = var_t1; var_a2 < 6; var_a2++) {
                if (well->block[var_t3][var_a2].state == 7) {
                    break;
                }
            }

            var_t1 = 0;
            if (var_a2 != 6) {
                break;
            }
        }

        if (var_a3 >= 8) {
            goto block_25;
        }

        if (well->block[var_a3 + 1][var_a2].state == 7) {
            brain->unk_040 = var_a3;
            brain->unk_038 = 0xB;
            brain->unk_03C = var_a2;
            brain->unk_044 = var_a3 + 1;

            for (var_a3 = var_a3 + 2; var_a3 < 0xC; var_a3++) {
                if (well->block[var_a3][var_a2].state != 7) {
                    break;
                }
                brain->unk_044 = var_a3;
            }
        } else {
            if (well->block[var_a3][var_a2 + 1].state != 7) {
                goto block_25;
            }

            brain->unk_040 = var_a2;

            brain->unk_038 = 0x16;
            brain->unk_03C = var_a3;
            brain->unk_044 = var_a2 + 1;

            for (var_a2 = var_a2 + 2; var_a2 < 6; var_a2++) {
                if (well->block[var_a3][var_a2].state != 7) {
                    break;
                }
                brain->unk_044 = var_a2;
            }
        }

        if ((brain->unk_044 - brain->unk_040) >= 2) {
            return -1;
        }

        if (brain->unk_038 == 0xB) {
            var_t3 = brain->unk_044;
            var_t1 = brain->unk_03C + 1;
        } else if (brain->unk_038 == 0x16) {
            var_t3 = brain->unk_03C;
            var_t1 = brain->unk_044 + 1;
        }
        goto loop_2;
    }

block_25:
    brain->unk_038 = 0;
    return 0;
}
#else
s32 AIFlashCheck(struct tetWell *well /* r27 */, struct ai_t *brain /* r28 */);
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIFlashCheck);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIFlashCheck);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIFlashCheck);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIFlashCheck);
#endif

s32 AIScrollCheck(tetWell *well, ai_t *brain, s8 array[]) {
    s32 row;
    s32 col;
    s32 var_t6;
    s32 var_t9;
    s32 var_t2;
    block_t *block;

#if 0
    int count; // r9
    int total; // r31
    int highest; // r30
#endif

    var_t6 = 0;
    var_t9 = BLOCK_LEN_ROWS;
    if (brain->unk_024 != -1) {
        var_t9 = brain->unk_024;
    }

    for (col = brain->unk_030; col <= brain->unk_034; col++) {
        var_t2 = 0;

        for (row = 0; row < var_t9; row++) {
            block = &well->block[row][col];

            if (((block->type != 0) && (block->type < 8)) || ((block->type == 0) && (block->state != 0))) {
                var_t2 += 1;
                var_t6 += 1;
            } else {
                break;
            }
        }
        if (array != NULL) {
            array[col] = var_t2;
        }
    }
    return var_t6;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIVolumeCheck);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIVolumeCheck);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIVolumeCheck);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIVolumeCheck);
#endif

void AIChainFrequency(tetWell *well, ai_t *brain, s32 num) {
    if ((brain->unk_008 > 0) && (well->unk_43A8 != 0)) {
        brain->unk_008 = 0;
        return;
    }

    if ((well->unk_43A8 != chain_check[num]) && (well->unk_43A8 == 0)) {
        if ((chain_check[num] >= -2) && (brain->unk_008 == 0)) {
            brain->unk_008 = AnimationRandom(111) + 333;
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainVert1);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIChainVert1);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIChainVert1);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIChainVert1);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainVert2);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIChainVert2);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIChainVert2);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIChainVert2);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007ACAC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007ACAC_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007ACAC_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007ACAC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainVert4);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIChainVert4);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIChainVert4);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIChainVert4);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainVert5);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIChainVert5);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIChainVert5);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIChainVert5);
#endif

#if VERSION_USA
#if 0
s32 AIChainHori1(tetWell *well, ai_t *brain) {
    s32 sp10[4];
    s32 *temp_a0_2;
    s32 *temp_a3_6;
    s32 *temp_t4;
    s32 *temp_v0_3;
    s32 *var_a0_4;
    s32 *var_a0_6;
    s32 *var_a1_4;
    s32 *var_t0;
    s32 *var_t1_2;
    s32 *var_v1;
    s32 *var_v1_3;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_a3_3;
    s32 temp_a3_4;
    s32 temp_a3_5;
    s32 temp_t0;
    s32 temp_t0_2;
    s32 temp_t5;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 var_a0_3;
    s32 var_a0_5;
    s32 var_a0_7;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_5;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_a2_4;
    s32 var_a2_5;
    s32 var_a3;
    s32 var_s2;
    s32 var_t1;
    s32 var_t2;
    s32 var_t2_2;
    s32 var_v0;
    s32 var_v1_2;
    block_t *temp_a0;
    block_t *temp_v1;
    block_t *temp_v1_2;
    block_t *temp_v1_3;

    if (brain->unk_040 != 0) {
        bzero(AIrowCheck, 0x8C);
        bzero(AIcolCheck, 0x8C);
        bzero(AItotCheck, 0x1C);
        var_t2 = brain->unk_040;
        var_a2 = brain->unk_044;

        if ((var_t2 != brain->unk_030) && (var_t2 -= 1, (var_a2 == brain->unk_034))) {
        } else {
            var_a2 += 1;
        }

        for (var_t1 = var_t2; var_a2 >= var_t1; var_t1++) {
            temp_a1 = brain->unk_03C;
            temp_a3 = temp_a1 - 1;
            temp_a0 = &well->block[temp_a3][var_t1];
            temp_t0 = temp_a0->type;
            if ((temp_t0 == 0) || (temp_t0 >= 8)) {
                continue;
            }
            if (temp_a0->state != 0) {
                continue;
            }
            temp_t5 = temp_t0 - 1;
            temp_t4 = &AItotCheck[temp_t5];
            if (*temp_t4 != 0) {
                continue;
            }

            *AIrowCheck[temp_t5] = temp_a3;
            AIcolCheck[temp_t5][*temp_t4] = var_t1;
            temp_a3_2 = temp_a1 - 2;
            *temp_t4 += 1;
            if (temp_a3_2 >= 0) {
                for (var_a1 = var_t2; var_a1 <= var_a2; var_a1++) {
                    temp_v1 = &well->block[temp_a3_2][var_a1];
                    if ((temp_v1->type == temp_t0) && (temp_v1->state == 0)) {
                        AIrowCheck[temp_t5][*temp_t4] = temp_a3_2;
                        AIcolCheck[temp_t5][*temp_t4] = var_a1;
                        *temp_t4 += 1;
                        break;
                    }
                }
            }

            temp_a3_3 = brain->unk_03C + 1;
            for (var_a1_2 = var_t2; var_a1_2 <= var_a2; var_a1_2++) {
                temp_v1_2 = &well->block[temp_a3_3][var_a1_2];
                if ((temp_v1_2->type == temp_t0) && (temp_v1_2->state == 0)) {
                    AIrowCheck[temp_t5][*temp_t4] = temp_a3_3;
                    AIcolCheck[temp_t5][*temp_t4] = var_a1_2;
                    *temp_t4 += 1;
                    break;
                }
            }

            if ((*temp_t4 < 2) || (var_a2 < var_a1_2)) {
                continue;
            }

            temp_a3_4 = temp_a3_3 + 1;
            for (var_a1_3 = var_t2; var_a1_3 <= var_a2; var_a1_3++) {
                temp_v1_3 = &well->block[temp_a3_4][var_a1_3];
                if ((temp_v1_3->type == temp_t0) && (temp_v1_3->state == 0)) {
                    AIrowCheck[temp_t5][*temp_t4] = temp_a3_4;
                    AIcolCheck[temp_t5][*temp_t4] = var_a1_3;
                    *temp_t4 += 1;
                    break;
                }
            }

            if (*temp_t4 >= 3) {
                for (var_a2_2 = 0; var_a2_2 < *temp_t4; var_a2_2++) {
                    sp10[var_a2_2] = AIrowCheck[temp_t5][var_a2_2];
                }

                AISortRows(brain->cursor_y, *temp_t4, sp10);

                temp_a0_2 = AIcolCheck[temp_t5];
                temp_v1_5 = brain->unk_040;
                var_a1_5 = temp_a0_2[sp10[*temp_t4-1]];
                if (var_a1_5 < temp_v1_5) {
                    var_a1_5 = temp_v1_5;
                } else if (brain->unk_044 < var_a1_5) {
                    var_a1_5 = brain->unk_044;
                } else {
                    temp_v0_5 = brain->cursor_x;
                    temp_a2 = temp_a0_2[sp10[0]];
                    var_a0_7 = temp_v0_5 - var_a1_5;
                    if (var_a0_7 < 0) {
                        var_a0_7 = -var_a0_7;
                    }
                    var_v0 = temp_v0_5 - (temp_a2 - 1);
                    if (var_v0 < 0) {
                        var_v0 = -var_v0;
                    }
                    if (-((var_v0 < var_a0_7) ^ 1) == 0) {
                        var_a1_5 = temp_a2;
                    }
                }

                for (var_a2_5 = 0; var_a2_5 < *temp_t4; var_a2_5++) {
                    temp_a3_5 = sp10[var_a2_5];
                    temp_a3_6 = &AIcolCheck[temp_t5][temp_a3_5];
                    if (var_a1_5 != *temp_a3_6) {
                        AIAddCommand(brain, 1, AIrowCheck[temp_t5][temp_a3_5], 0);
                        AIAddCommand(brain, 4, *temp_a3_6, var_a1_5);
                    }
                }

                AIAddCommand(brain, 0xB, 0, 0);
                brain->unk_020 = 1;
                return -1;
            }
        }

    }
    return 0;
}
#else
s32 AIChainHori1(struct tetWell *well, struct ai_t *brain);
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainHori1);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIChainHori1);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIChainHori1);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIChainHori1);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainHori2);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIChainHori2);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIChainHori2);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIChainHori2);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainHori3);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIChainHori3);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIChainHori3);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIChainHori3);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainHori4);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainHori5);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIClearGarbage);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIChainHori4);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIChainHori5);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIClearGarbage);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIChainHori4);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIChainHori5);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIClearGarbage);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIChainHori4);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIChainHori5);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIClearGarbage);
#endif

s32 AIClearPosition(tetWell *well, ai_t *brain, s32 row, s32 col) {
    s32 check;

    if (well->block[row][col].type == BLOCKTYPE_0) {
        return -1;
    }

    if (col == 0) {
        check = col + 1;
        if (well->block[row][check].type == BLOCKTYPE_0) {
            AIAddCommand(brain, 1, row, 0);
            AIAddCommand(brain, 3, col, check);
            return -1;
        }
    } else if (col == 5) {
        check = col - 1;
        if (well->block[row][check].type == BLOCKTYPE_0) {
            AIAddCommand(brain, 1, row, 0);
            AIAddCommand(brain, 3, col, check);
            return -1;
        }
    } else if (well->block[row][col + 1].type == BLOCKTYPE_0) {
        AIAddCommand(brain, 1, row, 0);
        AIAddCommand(brain, 3, col, col + 1);
        return -1;
    } else if (well->block[row][col - 1].type == BLOCKTYPE_0) {
        AIAddCommand(brain, 1, row, 0);
        AIAddCommand(brain, 3, col, col - 1);
        return -1;
    }

    return 0;
}

s32 AIChainPack(tetWell *well, cursor_t *cursor UNUSED, ai_t *brain) {
    s32 row;
    s32 col;
    s32 type;
    s32 var_a0;
    s32 var_s4 = 0;

#if 0
    int start; // r5
    int top; // r30
#endif

    for (col = 0; col < TETWELL_OBJSPRITE_LEN_B; col++) {
        if (AItotCheck[col] == -1) {
            for (row = 0; row < brain->unk_024; row++) {
                if (well->block[row][col].type == BLOCKTYPE_0) {
                    if (var_s4 < row) {
                        var_s4 = row;
                    }
                    break;
                }
            }
        }
    }

    if (var_s4 != 0) {
        for (row = brain->unk_024 - 1; row >= var_s4; row--) {
            for (col = 0; col < TETWELL_OBJSPRITE_LEN_B; col++) {
                if ((well->block[row][col].type != BLOCKTYPE_0) && (well->block[row][col].state == BLOCKSTATE_0)) {
                    if (AILowerRow(well, brain, row, col) != 0) {
                        return -1;
                    }
                }
            }
        }

        return 0;
    }

    for (type = BLOCKTYPE_1; type <= BLOCKTYPE_6; type++) {
        var_a0 = -1;

        for (row = 0; row < brain->unk_024; row++) {
            for (col = 0; col < TETWELL_OBJSPRITE_LEN_B; col++) {
                if (AItotCheck[col] != -1) {
                    if ((well->block[row][col].type == type) && (well->block[row][col].state == BLOCKSTATE_0)) {
                        if (var_a0 == -1) {
                            var_a0 = row;
                            break;
                        }
                        if (var_a0 == row - 1) {
                            var_a0 = row;
                            break;
                        }
                        if (AILowerRow(well, brain, row, col) == 0) {
                            var_a0 = row;
                            break;
                        }
                        return -1;
                    }
                }
            }
        }
    }

    for (row = brain->unk_024 - 1; row > 0; row--) {
        for (type = BLOCKTYPE_1; type <= BLOCKTYPE_6; type++) {
            var_a0 = 0;
            for (col = 0; col < TETWELL_OBJSPRITE_LEN_B; col++) {
                if ((well->block[row][col].type == type) && (well->block[row][col].state == BLOCKSTATE_0)) {
                    if (var_a0 == 0) {
                        var_s4 = col;
                    }
                    var_a0 += 1;
                    if (var_a0 >= 2) {
                        if (AILowerRow(well, brain, row, var_s4) != 0) {
                            return -1;
                        }
                        if ((AILowerRow(well, brain, row, col) != 0)) {
                            return -1;
                        }
                        break;
                    }
                }
            }
        }
    }

    for (row = 0; row < brain->unk_024 - 1; row++) {
        for (col = 0; col < TETWELL_OBJSPRITE_LEN_B - 1; col++) {
            if (well->block[row][col].type == BLOCKTYPE_0) {
                if (well->block[row + 1][col + 1].type != BLOCKTYPE_0) {
                    if (well->block[row + 1][col + 1].state == BLOCKSTATE_0) {
                        if (AItotCheck[col + 1] != -1) {
                            if (AILowerRow(well, brain, row + 1, col + 1) != 0) {
                                return -1;
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}

s32 AIChainGarbage1(tetWell *well, cursor_t *cursor UNUSED, ai_t *brain) {
    s32 array[2];
    s32 sp4C = 0;
    s32 row;
    s32 var_s1; // col?
    s32 var_t4; // col?
    s32 type;
    s32 var_a2;
    s32 var_s5;
    s32 var_s6;

#if 0
    int col; // r8
    int total; // r4
    int align; // r18
    int check; // r31
    int temp; // r1+0x8
    int top; // r14
#endif

    if (brain->unk_024 < 2) {
        return 0;
    }

    if (brain->unk_018 < 0) {
        if (brain->unk_018 >= well->unk_43A8) {
            return 0;
        }
    } else if (brain->unk_018 == 0) {
        if (well->unk_43A8 < -3) {
            return 0;
        }
    }

    bzero(AItotCheck, sizeof(AItotCheck));

    for (var_t4 = TETWELL_OBJSPRITE_LEN_B - 1; var_t4 >= 0; var_t4--) {
        type = well->block[brain->unk_024][var_t4].type;
        if ((type == BLOCKTYPE_9) || (type == BLOCKTYPE_0)) {
            continue;
        }

        AItotCheck[var_t4] = type;

        var_s5 = 0;
        for (row = brain->unk_024 - 1; row >= 0; row--) {
            if (well->block[row][var_t4].type != BLOCKTYPE_0) {
                if (well->block[row][var_t4].type != type) {
                    break;
                }
                var_s5 += 1;
            }

            if (var_s5 == 2) {
                AItotCheck[var_t4] = -1;
                if (sp4C < row + 1) {
                    sp4C = row + 1;
                }
                break;
            }
        }
    }

    for (var_t4 = TETWELL_OBJSPRITE_LEN_B - 1; var_t4 >= 0; var_t4--) {
        if (AItotCheck[var_t4] == -1 || AItotCheck[var_t4] == 0) {
            continue;
        }
        type = AItotCheck[var_t4];

        var_s5 = 0;
        var_s6 = 0;

        for (row = brain->unk_024 - 1; row >= 0; row--) {
            for (var_s1 = 0; var_s1 < TETWELL_OBJSPRITE_LEN_B; var_s1++) {
                if (AItotCheck[var_s1] == -1) {
                    continue;
                }
                if ((well->block[row][var_s1].type == type) && (well->block[row][var_s1].state == BLOCKSTATE_0)) {
                    if (well->block[row][var_t4].type == type) {
                        var_s6 += 1;

                        AIrowCheck[0][var_s5] = row;
                        AIcolCheck[0][var_s5] = var_t4;
                        var_s5 += 1;
                        break;
                    } else if (AIMoveAcross(well, row, var_s1, var_t4) != 0) {
                        AIrowCheck[0][var_s5] = row;
                        AIcolCheck[0][var_s5] = var_s1;
                        var_s5 += 1;
                        break;
                    }
                }
            }

            if (var_s1 == TETWELL_OBJSPRITE_LEN_B) {
                if (var_s5 != 0) {
                    break;
                }
            } else if (var_s5 == 1) {
                if (AIChainGarbage2(well, brain, type, var_t4) != 0) {
                    return -1;
                }
                if (AItotCheck[var_t4] == -1) {
                    break;
                }
            } else if (var_s5 == 2) {
                break;
            }
        }

        if (var_s6 == 2) {
            if (AIClearPosition(well, brain, AIrowCheck[0][0] + 1, var_t4) != 0) {
                AItotCheck[var_t4] = -1;
            }

            if (sp4C < AIrowCheck[0][0]) {
                sp4C = AIrowCheck[0][0];
            }
        } else if ((var_s5 == ARRAY_COUNT(array)) && ((brain->unk_014 & 0x40) || (sp4C < AIrowCheck[0][0]))) {
            var_s6 = 0;
            var_a2 = AIrowCheck[0][0] + 1;

            for (row = var_a2; row < brain->unk_024; row++) {
                if ((well->block[row][var_t4].type != BLOCKTYPE_0) &&
                    (well->block[row][var_t4].state == BLOCKSTATE_0)) {
                    var_s6 += 1;
                    var_a2 = row;
                }
            }

            if (var_s6 < 2) {
                if ((AIrowCheck[0][0] + 1 == brain->unk_024) || (AIClearPosition(well, brain, var_a2, var_t4) != 0)) {
                    var_a2 = AIrowCheck[0][1] - 1;
                    if (well->block[var_a2][var_t4].type == type) {
                        AIAddCommand(brain, 1, var_a2, 0);
                        AIAddCommand(brain, 2, var_t4 - 1, 0);
                        AIAddCommand(brain, 9, 0, 0);
                    }

                    for (var_a2 = 0; var_a2 < var_s5; var_a2++) {
                        array[var_a2] = AIrowCheck[0][var_a2];
                    }

                    AISortRows(brain->cursor_y, var_s5, array);

                    for (var_a2 = 0; var_a2 < var_s5; var_a2++) {
                        row = array[var_a2];

                        if (var_t4 != AIcolCheck[0][row]) {
                            AIAddCommand(brain, 1, AIrowCheck[0][row], 0);
                            AIAddCommand(brain, 4, AIcolCheck[0][row], var_t4);
                        }
                    }
                    AItotCheck[var_t4] = -1;
                    return -1;
                }
            }
        }
    }

    return 0;
}

s32 AIChainGarbage2(tetWell *well, ai_t *brain, BlockType below, s32 col) {
    BlockType type = well->block[brain->unk_024 + 1][col].type;
    s32 row;
    s32 check;

    if ((type != below) || (type == BLOCKTYPE_9)) {
        return 0;
    }

    if ((type == BLOCKTYPE_0) || (AItotCheck[col] == -1)) {
        return 0;
    }

    if (AIMoveAcross(well, AIrowCheck[0][0], AIcolCheck[0][0], col) == 0) {
        return 0;
    }

    check = 0;
    for (row = AIrowCheck[0][0] + 1; row < brain->unk_024; row++) {
        check += well->block[row][col].type != BLOCKTYPE_0;
    }

    if (check < 2) {
        if ((AIrowCheck[0][0] + 1 == brain->unk_024) ||
            (AIClearPosition(well, brain, AIrowCheck[0][0] + 1, col) != 0)) {
            AItotCheck[col] = -1;
            if (AIcolCheck[0][0] != col) {
                AIAddCommand(brain, 1, AIrowCheck[0][0], 0);
                AIAddCommand(brain, 4, AIcolCheck[0][0], col);

                return -1;
            }
        }
    }

    return 0;
}

s32 AIStupidMove(tetWell *well, ai_t *brain) {
    s32 row;
    s32 highest;

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        if (AIPossibleRow(well, brain, row) != 0) {
            brain->unk_100 = 0;
            brain->unk_104 = 0;
            brain->unk_0FC = 0;
            brain->unk_124 = 0;
            brain->unk_128 = 0;
            AIAddCommand(brain, 1, row, 0);
            AIPossibleRow(well, brain, row);
            return -1;
        }
    }

    if (brain->unk_024 != -1) {
        for (highest = BLOCK_LEN_ROWS - 1; highest > brain->unk_024; highest--) {
            if (well->block[highest][2].type != BLOCKTYPE_0 || (well->block[highest][3].type != BLOCKTYPE_0)) {
                break;
            }
        }

        if (highest < BLOCK_LEN_ROWS - 1) {
            AIAddCommand(brain, 0xC, 0, 0);
            AIAddCommand(brain, 1, brain->cursor_y - 1, 0);

            AIAddCommand(brain, 0xA, 0, 0);
            return -1;
        }
    }

    AIAddCommand(brain, 1, AnimationRandom(6), 0);
    AIAddCommand(brain, 0xA, 0, 0);
    return -1;
}

#if VERSION_USA
#if 0
#define subroutine_arg5 idk()
#define subroutine_arg7 idk()

void UpdateAI(tetWell *well, cursor_t *cursor, ai_t *brain, s32 num) {
    block_t *var_v1;
    s32 *var_v0_5;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a0_6;
    s32 temp_a0_7;
    s32 temp_a0_8;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_ret_2;
    s32 temp_ret_3;
    s32 temp_ret_4;
    s32 temp_s1;
    s32 temp_v0_10;
    s32 temp_v0_2;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a0_6;
    s32 var_a0_7;
    s32 var_a0_8;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_a2_4;
    s32 var_s1;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s3;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_6;
    s32 var_v1_10;
    s32 var_v1_11;
    s32 var_v1_12;
    s32 var_v1_13;
    s32 var_v1_14;
    s32 var_v1_15;
    s32 var_v1_16;
    s32 var_v1_17;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;
    s32 var_v1_6;
    s32 var_v1_7;
    s32 var_v1_8;
    s32 var_v1_9;
    s8 var_a3;
    s8 var_a3_2;
    s8 var_a3_3;
    s8 var_a3_4;
    s8 var_fp;
    s8 var_s7;
    command_t *temp_a0_2;
    command_t *temp_s1_2;
    command_t *temp_v0_3;

    // var_s7 = saved_reg_s7;
    // var_fp = saved_reg_fp;
    var_s1 = 0;
    var_s2 = 0;
    if ((brain->unk_008 > 0) && (well->unk_43A8 != 0)) {
        brain->unk_008 = 0;
    } else if ((well->unk_43A8 != chain_check[num]) && (well->unk_43A8 == 0) && (chain_check[num] >= -2)) {
        if (brain->unk_008 == 0) {
            brain->unk_008 = AnimationRandom(0x6F) + 0x14D;
        }
    }

    if (brain->unk_008 > 0) {
        brain->unk_008 -= 1;
    }

    if ((cursor->unk_04 != 0) || (well->unk_43B0 > 0)) {
        return;
    }

    brain->cursor_x = cursor->x;
    brain->cursor_y = cursor->y;
    AISetGarbage(well, cursor, brain);

    temp_v0_2 = AIFlashCheck(well, brain);
    if (temp_v0_2 == 0) {
        if (!((brain->unk_020 != 2) || (cursor->unk_00 == 2) || (brain->unk_104 > 0) ||
              ((cursor->unk_00 != 1) && (cursor->unk_08 == 0)))) {
            return;
        }
        if (temp_v0_2 != 0) {
            //! @bug: unreachable code?
            if (brain->unk_020 != 1) {
                brain->unk_020 = 0;
                brain->unk_104 = 0;
                brain->unk_0FC = 0;
                brain->unk_100 = 0;
                brain->unk_124 = 0;
                brain->unk_128 = 0;
            } else if (AnimationRandom(0x141) % 3 != 0) {
                brain->unk_038 = 0;
            } else {
                brain->unk_020 = 0;
                brain->unk_104 = 0;
                brain->unk_0FC = 0;
                brain->unk_100 = 0;
                brain->unk_124 = 0;
                brain->unk_128 = 0;
            }
        }
    }

    if (brain->unk_124 != brain->unk_128) {
        return;
    }

    if (brain->unk_104 == 0) {
        brain->unk_104 = 0;
        brain->unk_020 = 0;
        brain->unk_0FC = 0;
        brain->unk_100 = 0;
        brain->unk_124 = 0;
        brain->unk_128 = 0;
        if (brain->unk_104 == 0) {
            if (brain->unk_024 != -1) {
                if (cursor->unk_00 == 2) {
                    if (brain->unk_014 & 0x20) {
                        if (AIChainGarbage1(well, cursor, brain) != 0) {
                            brain->unk_01C = 0x1E;
                        } else {
                            goto block_47;
                        }
                    } else {
                    block_47:
                        if (AIChainPack(well, cursor, brain) != 0) {
                            brain->unk_01C = 0x1F;
                        } else {
                            temp_v0_3 = brain + ((brain->unk_100 * 0xC) + 0x48);
                            temp_v0_3->function = 0xE;
                            temp_v0_3->para1 = 0;
                            temp_v0_3->para2 = 0;
                            brain->unk_104 += 1;
                            brain->unk_100 += 1;
                        }
                    }
                    brain->unk_020 = 2;
                } else {
                    var_v0_3 = 0x20;
                    if ((AIClearGarbage(well, &cursor->unk_00, brain) != 0) ||
                        ((temp_ret_2 = AnimationRandom(0x7B4), (temp_ret_2 == ((temp_ret_2 / 3) * 3))) &&
                         (var_v0_3 = 0x32, (AIVolumeCheck(well, &cursor->unk_00, (cursor_t *)brain, 0) != 0)))) {
                        brain->unk_01C = var_v0_3;
                    }
                }
            }

            if (brain->unk_104 == 0) {
                if ((brain->unk_008 <= 0) && (brain->unk_038 != 0)) {
                    temp_v1_3 = brain->unk_024;
                    if (temp_v1_3 != -1) {
                        if (temp_v1_3 < 6) {

                        } else {
                            goto block_65;
                        }
                    } else {
                        temp_v1_4 = brain->unk_018;
                        if (temp_v1_4 < 0) {
                            if (temp_v1_4 < well->unk_43A8) {
                                var_s1 = -1;
                            }
                        } else if (temp_v1_4 == 0) {
                        block_65:
                            if (well->unk_43A8 >= -3) {
                                var_s1 = -1;
                            }
                        }
                    }
                    if (var_s1 != 0) {
                        temp_s1 = brain->unk_038;
                        if (temp_s1 == 0xB) {
                            if (AIChainVert1(well, brain) != 0) {
                                brain->unk_01C = temp_s1;
                            } else {
                                var_v0_4 = 0xC;
                                if ((AIChainVert2(well, brain) == 0) &&
                                    (!(brain->unk_014 & 8) ||
                                     (var_v0_4 = 0xE, (AIChainVert4(well, brain) == 0)))) {
                                    if ((brain->unk_014 & 0x10) && (well->unk_43A8 != 0) &&
                                        (AIChainVert5(well, brain) != 0)) {
                                        brain->unk_01C = 0xF;
                                    }
                                } else {
                                    goto block_85;
                                }
                            }
                        } else {
                            var_v0_4 = 0x15;
                            if ((AIChainHori1(well, brain) != 0) ||
                                (var_v0_4 = 0x16, (AIChainHori2(well, brain) != 0)) ||
                                ((brain->unk_014 & 4) && (var_v0_4 = 0x17, (AIChainHori3(well, brain) != 0))) ||
                                ((brain->unk_014 & 8) && ((var_v0_4 = 0x18, (AIChainHori4(well, brain) != 0)) ||
                                                          (var_v0_4 = 0x19, (AIChainHori5(well, brain) != 0))))) {
                            block_85:
                                brain->unk_01C = var_v0_4;
                            }
                        }
                    }
                }
                if (brain->unk_104 == 0) {
                    if (AIVolumeCheck(well, &cursor->unk_00, (cursor_t *)brain, well->unk_43B8 == 0) != 0) {
                        brain->unk_01C = 0x33;
                    }
                    if (brain->unk_104 == 0) {
                        if (AIPossibleRow(well, brain, brain->cursor_y) != 0) {
                            brain->unk_01C = 1;
                        } else if (AIPossibleCol(well, brain) != 0) {
                            brain->unk_01C = 2;
                        } else {
                            brain->unk_030 = 0;
                            brain->unk_034 = 5;
                            temp_v1_5 = brain->cursor_y + 2;
                            if (temp_v1_5 < 0xC) {
                                brain->unk_028 = temp_v1_5;
                            } else {
                                brain->unk_028 = 0xB;
                            }
                            temp_v1_6 = brain->cursor_y - 2;
                            if (temp_v1_6 >= 0) {
                                brain->unk_02C = temp_v1_6;
                            } else {
                                brain->unk_02C = 0;
                            }
                            bzero(&AIrowCheck, 0x8C);
                            bzero(&AIcolCheck, 0x8C);
                            bzero(&AItotCheck, 0x1C);
                            var_v1_2 = 7;
                            // AIdistance?
                            var_v0_5 = &B_801C70D4_usa;
                            do {
                                *var_v0_5 = 0x12;
                                var_v1_2 -= 1;
                                var_v0_5 -= 4;
                            } while (var_v1_2 >= 0);
                            AIBoundaryCheck(well, brain);
                            AIComboCheck(well, brain);
                            if (brain->unk_018 == 0) {
                                var_s2 = AIComboX(brain);
                                if (var_s2 != 0) {
                                    brain->unk_01C = 9;
                                    goto block_107;
                                }
                                goto block_108;
                            }
                        block_107:
                            if (var_s2 == 0) {
                            block_108:
                                if ((brain->unk_008 <= 0) && (brain->unk_014 & 1)) {
                                    temp_ret_3 = AnimationRandom(0x323);
                                    if (temp_ret_3 == ((temp_ret_3 / 7) * 7)) {
                                        var_s2 = AICombo45(brain, 5);
                                        if (var_s2 != 0) {
                                            brain->unk_01C = 3;
                                            goto block_116;
                                        }
                                        goto block_117;
                                    }
                                    temp_ret_4 = AnimationRandom(0x236);
                                    if (temp_ret_4 == ((temp_ret_4 / 5) * 5)) {
                                        var_s2 = AICombo45(brain, 4);
                                        if (var_s2 != 0) {
                                            brain->unk_01C = 4;
                                            goto block_116;
                                        }
                                        goto block_117;
                                    }
                                    goto block_116;
                                }
                            block_116:
                                if (var_s2 == 0) {
                                block_117:
                                    if (AICombo3a(brain) != 0) {
                                        brain->unk_01C = 5;
                                    } else if (AICombo3b(brain) != 0) {
                                        brain->unk_01C = 6;
                                    } else if (AIVolumeCheck(well, &cursor->unk_00, (cursor_t *)brain, 0) != 0) {
                                        brain->unk_01C = 0x34;
                                    } else {
                                        AIStupidMove(well, brain);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (brain->unk_104 > 0) {
        brain->unk_124 = 0;
        brain->unk_128 = 0;
    loop_127:
        temp_s1_2 = brain + ((brain->unk_0FC * 0xC) + 0x48);
        temp_v0_4 = temp_s1_2->function;
        switch (temp_v0_4) {
            case 0x1:
                temp_a0_2 = brain + ((brain->unk_0FC * 0xC) + 0x54);
                if (((u32)(temp_a0_2->function - 3) >= 3U) || (temp_a0_2->para1 != temp_a0_2->para2)) {
                    temp_v1_7 = temp_s1_2->para1 - brain->cursor_y;
                    if (temp_v1_7 != 0) {
                        if (temp_v1_7 > 0) {
                            var_a0_2 = 0;
                            if (temp_v1_7 > 0) {
                            loop_135:
                                brain->move[brain->unk_128] = 3;
                                var_a0_2 += 1;
                                brain->unk_128 += 1;
                                if (var_a0_2 < temp_v1_7) {
                                    goto loop_135;
                                }
                            }
                        } else {
                            var_a0_3 = 0;
                            if (temp_v1_7 < 0) {
                            loop_139:
                                brain->move[brain->unk_128] = 4;
                                var_a0_3 -= 1;
                                brain->unk_128 += 1;
                                if (temp_v1_7 < var_a0_3) {
                                    goto loop_139;
                                }
                            }
                        }
                    }
                }
            default:
            block_247:
                brain->unk_104 -= 1;
                brain->unk_0FC += 1;
                if ((brain->unk_104 > 0) && (brain->unk_124 == brain->unk_128)) {
                    goto loop_127;
                }
                break;
            case 0x2:
                temp_a0_3 = temp_s1_2->para1;
                var_v0_6 = ~temp_a0_3;
                if ((temp_a0_3 == 5) && (var_v0_6 = ~temp_a0_3, (gTheGame.unk_9C0C != 2))) {
                    var_a0_4 = 4;
                } else {
                    var_a0_4 = temp_a0_3 & (var_v0_6 >> 0x1F);
                }
                temp_a0_4 = var_a0_4 - brain->cursor_x;
                if (temp_a0_4 != 0) {
                    if (temp_a0_4 > 0) {
                        var_v1_3 = 0;
                        if (temp_a0_4 > 0) {
                        loop_149:
                            brain->move[brain->unk_128] = 2;
                            var_v1_3 += 1;
                            brain->unk_128 += 1;
                            if (var_v1_3 < temp_a0_4) {
                                goto loop_149;
                            }
                        }
                    } else {
                        var_v1_4 = 0;
                        if (temp_a0_4 < 0) {
                        loop_153:
                            brain->move[brain->unk_128] = 1;
                            var_v1_4 -= 1;
                            brain->unk_128 += 1;
                            if (temp_a0_4 < var_v1_4) {
                                goto loop_153;
                            }
                        }
                    }
                }
                goto block_247;
            case 0x3:
            case 0x7:
                if ((brain->unk_020 == 1) &&
                    (AIHoriMoveCheckCheck(well, brain, temp_s1_2->para1, temp_s1_2->para2) != 0)) {
                    AISpeedUpMove(brain);
                }

                // inlined AIHoriMoveBlock?
                temp_a1 = temp_s1_2->para1;
                temp_a0_5 = temp_s1_2->para2;
                if (temp_a1 < temp_a0_5) {
                    var_v1_5 = brain->cursor_x;
                    var_a2 = (temp_a0_5 - temp_a1) - 1;
                    var_a3 = 2;
                    goto block_162;
                }
                if (temp_a0_5 < temp_a1) {
                    var_a2 = (temp_a1 - temp_a0_5) - 1;
                    var_a3 = 1;
                    var_v1_5 = brain->cursor_x + 1;
                block_162:
                    var_a0_5 = temp_a1 - var_v1_5;
                    if (var_v1_5 < temp_a1) {
                        var_s7 = 2;
                    } else {
                        var_a0_5 = var_v1_5 - temp_a1;
                        if (temp_a1 < var_v1_5) {
                            var_s7 = 1;
                        } else {
                            var_a0_5 = -1;
                        }
                    }
                    var_v1_6 = 0;
                    if (var_a0_5 > 0) {
                        do {
                            brain->move[brain->unk_128] = var_s7;
                            var_v1_6 += 1;
                            brain->unk_128 += 1;
                        } while (var_v1_6 < var_a0_5);
                    }
                    brain->move[brain->unk_128] = 5;
                    var_v1_7 = 0;
                    brain->unk_128 += 1;
                    if (var_a2 > 0) {
                    loop_171:
                        brain->move[brain->unk_128] = var_a3;
                        temp_v0_5 = brain->unk_128 + 1;
                        brain->unk_128 = temp_v0_5;
                        brain->move[temp_v0_5] = 5;
                        var_v1_7 += 1;
                        brain->unk_128 += 1;
                        if (var_v1_7 < var_a2) {
                            goto loop_171;
                        }
                    }
                }
                goto block_247;
            case 0x6:
                temp_a1_2 = temp_s1_2->para1;
                temp_a0_6 = temp_s1_2->para2;
                if (temp_a1_2 < temp_a0_6) {
                    var_v1_8 = brain->cursor_x;
                    var_a2_2 = (temp_a0_6 - temp_a1_2) - 1;
                    var_a3_2 = 2;
                    goto block_177;
                }
                if (temp_a0_6 < temp_a1_2) {
                    var_a2_2 = (temp_a1_2 - temp_a0_6) - 1;
                    var_a3_2 = 1;
                    var_v1_8 = brain->cursor_x + 1;
                block_177:
                    var_a0_6 = temp_a1_2 - var_v1_8;
                    if (var_v1_8 < temp_a1_2) {
                        var_fp = 2;
                    } else {
                        var_a0_6 = var_v1_8 - temp_a1_2;
                        if (temp_a1_2 < var_v1_8) {
                            var_fp = 1;
                        } else {
                            var_a0_6 = -1;
                        }
                    }
                    var_v1_9 = 0;
                    if (var_a0_6 > 0) {
                        do {
                            brain->move[brain->unk_128] = var_fp;
                            var_v1_9 += 1;
                            brain->unk_128 += 1;
                        } while (var_v1_9 < var_a0_6);
                    }
                    brain->move[brain->unk_128] = 5;
                    var_v1_10 = 0;
                    brain->unk_128 += 1;
                    if (var_a2_2 > 0) {
                        do {
                            brain->move[brain->unk_128] = var_a3_2;
                            temp_v0_6 = brain->unk_128 + 1;
                            brain->unk_128 = temp_v0_6;
                            brain->move[temp_v0_6] = 5;
                            var_v1_10 += 1;
                            brain->unk_128 += 1;
                        } while (var_v1_10 < var_a2_2);
                    }
                }
                AISpeedUpMove(brain);
                goto block_247;
            case 0x4:
                temp_v0_7 = AIShortestD(well, brain, temp_s1_2->para1, temp_s1_2->para2);
                temp_s1_2->para1 = temp_v0_7;
                if ((brain->unk_020 == 1) && (AIHoriMoveCheckCheck(well, brain, temp_v0_7, temp_s1_2->para2) != 0)) {
                    AISpeedUpMove(brain);
                }
                temp_a1_3 = temp_s1_2->para1;
                temp_a0_7 = temp_s1_2->para2;
                if (temp_a1_3 < temp_a0_7) {
                    var_v1_11 = brain->cursor_x;
                    var_a2_3 = (temp_a0_7 - temp_a1_3) - 1;
                    var_a3_3 = 2;
                    goto block_195;
                }
                if (temp_a0_7 < temp_a1_3) {
                    var_a2_3 = (temp_a1_3 - temp_a0_7) - 1;
                    var_a3_3 = 1;
                    var_v1_11 = brain->cursor_x + 1;
                block_195:
                    if (var_v1_11 < temp_a1_3) {
                        var_a0_7 = temp_a1_3 - var_v1_11;
                    } else if (temp_a1_3 < var_v1_11) {
                        var_a0_7 = var_v1_11 - temp_a1_3;
                    } else {
                        var_a0_7 = -1;
                    }
                    var_v1_12 = 0;
                    if (var_a0_7 > 0) {
                        do {
                            brain->move[brain->unk_128] = (s8)subroutine_arg5;
                            var_v1_12 += 1;
                            brain->unk_128 += 1;
                        } while (var_v1_12 < var_a0_7);
                    }
                    brain->move[brain->unk_128] = 5;
                    var_v1_13 = 0;
                    brain->unk_128 += 1;
                    if (var_a2_3 > 0) {
                    loop_204:
                        brain->move[brain->unk_128] = var_a3_3;
                        temp_v0_8 = brain->unk_128 + 1;
                        brain->unk_128 = temp_v0_8;
                        brain->move[temp_v0_8] = 5;
                        var_v1_13 += 1;
                        brain->unk_128 += 1;
                        if (var_v1_13 < var_a2_3) {
                            goto loop_204;
                        }
                    }
                }
                goto block_247;
            case 0x5:
                if ((brain->unk_020 == 1) &&
                    (AIHoriMoveCheckCheck(well, brain, temp_s1_2->para1, temp_s1_2->para2) != 0)) {
                    AISpeedUpMove(brain);
                }
                temp_a1_4 = temp_s1_2->para1;
                temp_a0_8 = temp_s1_2->para2;
                if (temp_a1_4 < temp_a0_8) {
                    var_v1_14 = brain->cursor_x;
                    var_a2_4 = (temp_a0_8 - temp_a1_4) - 1;
                    var_a3_4 = 2;
                    goto block_213;
                }
                if (temp_a0_8 < temp_a1_4) {
                    var_a2_4 = (temp_a1_4 - temp_a0_8) - 1;
                    var_a3_4 = 1;
                    var_v1_14 = brain->cursor_x + 1;
                block_213:
                    if (var_v1_14 < temp_a1_4) {
                        var_a0_8 = temp_a1_4 - var_v1_14;
                    } else if (temp_a1_4 < var_v1_14) {
                        var_a0_8 = var_v1_14 - temp_a1_4;
                    } else {
                        var_a0_8 = -1;
                    }
                    var_v1_15 = 0;
                    if (var_a0_8 > 0) {
                        do {
                            brain->move[brain->unk_128] = (s8)subroutine_arg7;
                            var_v1_15 += 1;
                            brain->unk_128 += 1;
                        } while (var_v1_15 < var_a0_8);
                    }
                    brain->move[brain->unk_128] = 5;
                    var_v1_16 = 0;
                    brain->unk_128 += 1;
                    if (var_a2_4 > 0) {
                        do {
                            brain->move[brain->unk_128] = var_a3_4;
                            temp_v0_9 = brain->unk_128 + 1;
                            brain->unk_128 = temp_v0_9;
                            brain->move[temp_v0_9] = 5;
                            var_v1_16 += 1;
                            brain->unk_128 += 1;
                        } while (var_v1_16 < var_a2_4);
                    }
                }
                temp_v0_10 = brain->unk_128;
                if (temp_v0_10 != 0) {
                    brain->move[temp_v0_10 - 1] = 6;
                }
            case 0xB:
                brain->unk_020 = 2;
                goto block_247;
            case 0x8:
                AIRowPack(brain, temp_s1_2->para1, temp_s1_2->para2);
                goto block_247;
            case 0x9:
                brain->move[brain->unk_128] = 5;
            block_229:
            block_230:
                brain->unk_128 += 1;
                goto block_247;
            case 0xC:
                brain->move[brain->unk_128] = 7;
                brain->unk_010 = 0;
                goto block_230;
            case 0xA:
                brain->move[brain->unk_128] = 8;
                goto block_229;
            case 0xD:
                var_s3 = brain->unk_024;
                if (var_s3 == -1) {
                    var_s3 = 0xC;
                }
                var_s2_2 = temp_s1_2->para1 - 2;
                if (var_s2_2 < var_s3) {
                loop_236:
                    if (well->block[var_s2_2][temp_s1_2->para2].type == 0) {
                        var_s2_2 += 1;
                        if (var_s2_2 < var_s3) {
                            goto loop_236;
                        }
                    }
                }
                if (((CheckFieldActive(well) != nfalse) ||
                     (well->block[temp_s1_2->para1 - 2][temp_s1_2->para2].type == 0)) &&
                    (var_s2_2 != var_s3)) {
                    if (well->block[temp_s1_2->para1][temp_s1_2->para2].state == 1) {
                        goto block_247;
                    }
                } else {
                    goto block_247;
                }
                break;
            case 0x14:
                if (CheckFieldActive(well) != nfalse) {
                    if (well->block[temp_s1_2->para1][temp_s1_2->para2].type != 0) {
                        goto block_247;
                    }
                } else {
                    goto block_247;
                }
                break;
            case 0xE:
                temp_v1_8 = temp_s1_2->para1;
                temp_s1_2->para2 = (s32)(temp_v1_8 - 1);
                if (temp_v1_8 <= 0) {
                    goto block_247;
                }
                break;
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", UpdateAI);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", UpdateAI);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", UpdateAI);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", UpdateAI);
#endif

void AIMove(tetWell *well, cursor_t *cursor, ai_t *brain, s32 num) {
    if (gMain == GMAIN_387) {
        if ((gDemo == GDEMO_0B) && (gTheGame.controller[num].touch_button & START_BUTTON)) {
            gTheGame.cursorBlock[0].unk_20 = 0;
            gMain = GMAIN_388;
            gTheGame.unk_9C20 = num;
            gTheGame.unk_9C24 = 0;
            FadeSong(last_song_handle, 0x28, 0xA, NULL);
            FadeOutAllSFXs(0xF);
            PlaySE(SFX_INIT_TABLE, 0xA5);
            UpdateAnimation(well, num, 0);
            return;
        }
    } else if (gMain == GMAIN_388) {
        DoPauseGame(&gTheGame.controller[num], num, -1);
        if (gMain == GMAIN_388) {
            UpdateAnimation(well, num, 0);
        }
        return;
    }

    if (well->unk_43B0 != 0) {
        if (well->unk_43B0 < 0) {
            well->unk_43B0++;
        }

        if (well->unk_43B0 > 0) {
            RaiseBlocks(well, cursor);
            if (well->unk_43B0 == 0) {
                brain->unk_104 = 0;
                brain->unk_0FC = 0;
                brain->unk_100 = 0;
                brain->unk_124 = 0;
                brain->unk_128 = 0;
            }
            return;
        }
    }

    brain->unk_010--;
    if ((brain->unk_010 <= 0) && (brain->unk_124 != brain->unk_128)) {
        if (AnimationRandom(0x177) % 3 == 0) {
            brain->unk_010 = brain->unk_00C + AnimationRandom(2);
        } else {
            brain->unk_010 = brain->unk_00C - AnimationRandom(2);
        }

        if (well->unk_43F4 != 0) {
            brain->unk_010 = brain->unk_00C - AnimationRandom(3);
        } else if (brain->unk_020 != 0) {
            brain->unk_010 = brain->unk_010 - AnimationRandom(3);
        }

        if (gTheGame.unk_9C0C == 1) {
            AI2DMove(well, cursor, brain, num);
        } else {
            AI3DMove(well, cursor, brain, num);
        }
    }
}

void AI2DMove(tetWell *well, cursor_t *cursor, ai_t *brain, s32 num) {
    nbool sound = nfalse;
    nbool flag = ntrue;

    // TODO: enum for move?
    switch (brain->move[brain->unk_124]) {
        case 1:
            sound = Move2DCursorLeft(cursor, CURSOR_HOLD_VAL_10);
            break;

        case 2:
            sound = Move2DCursorRight(cursor, CURSOR_HOLD_VAL_10);
            break;

        case 3:
            sound = Move2DCursorUp(well, cursor, CURSOR_HOLD_VAL_10);
            break;

        case 4:
            sound = Move2DCursorDown(cursor, CURSOR_HOLD_VAL_10);
            break;

        case 5:
            flag = Switch2DBlocks(well, cursor, num);
            if (!flag) {
                brain->unk_104 = 0;
                brain->unk_0FC = 0;
                brain->unk_100 = 0;
                brain->unk_124 = 0;
                brain->unk_128 = 0;
                return;
            }
            break;

        case 6:
            flag = Switch2DBlocks(well, cursor, num);
            if (well->block[cursor->y][cursor->x].type == BLOCKTYPE_0) {
                if (well->block[cursor->y][cursor->x + 1].type == BLOCKTYPE_0) {
                    flag = ntrue;
                }
            }

            brain->unk_010 = 1;
            break;

        case 7:
            if (well->unk_43B0 == 0) {
                well->unk_43B0 = 1;
            } else {
                flag = nfalse;
            }
            break;

        case 8:
            AIChangeVision(brain);
            break;

        case 11:
            sound = Move2DCursorLeft(cursor, CURSOR_HOLD_VAL_10);
            brain->unk_010 = 1;
            break;

        case 12:
            sound = Move2DCursorRight(cursor, CURSOR_HOLD_VAL_10);
            brain->unk_010 = 1;
            break;

        case 13:
            sound = Move2DCursorUp(well, cursor, CURSOR_HOLD_VAL_10);
            brain->unk_010 = 1;
            break;

        case 14:
            sound = Move2DCursorDown(cursor, CURSOR_HOLD_VAL_10);
            brain->unk_010 = 1;
            break;

        case 15:
            flag = Switch2DBlocks(well, cursor, num);
            if (!flag) {
                brain->unk_104 = 0;
                brain->unk_0FC = 0;
                brain->unk_100 = 0;
                brain->unk_124 = 0;
                brain->unk_128 = 0;
                return;
            }
            brain->unk_010 = 1;
            break;

        default:
            return;
    }

    if (sound) {
        if (gTheGame.unk_9C08 == 1) {
            PlaySE(SFX_INIT_TABLE, 0x96);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, 0x97);
        } else {
            PlaySE(SFX_INIT_TABLE, 0x98);
        }
    }

    if (flag) {
        brain->unk_124++;
    }
}

void AI3DMove(tetWell *well, cursor_t *cursor, ai_t *brain, s32 num) {
    nbool sound = nfalse;
    nbool flag = ntrue;

    switch (brain->move[brain->unk_124]) {
        case 1:
        case 11:
            sound = Move3DCursorLeft(cursor, CURSOR_HOLD_VAL_10);
            break;

        case 2:
        case 12:
            sound = Move3DCursorRight(cursor, CURSOR_HOLD_VAL_10);
            break;

        case 3:
        case 13:
            sound = Move3DCursorUp(well, cursor, CURSOR_HOLD_VAL_10);
            break;

        case 4:
        case 14:
            sound = Move3DCursorDown(cursor, CURSOR_HOLD_VAL_10);
            break;

        case 5:
        case 15:
            flag = Switch3DBlocks(well, cursor, num);
            if (!flag) {
                brain->unk_104 = 0;
                brain->unk_0FC = 0;
                brain->unk_100 = 0;
                brain->unk_124 = 0;
                brain->unk_128 = 0;
                return;
            }
            break;

        case 6:
            flag = Switch3DBlocks(well, cursor, num);
            if (well->block[cursor->y][cursor->x].type == BLOCKTYPE_0) {
                if (well->block[cursor->y][cursor->x + 1].type == BLOCKTYPE_0) {
                    flag = ntrue;
                }
            }
            break;

        case 7:
            if (well->unk_43B0 == 0) {
                well->unk_43B0 = 1;
            } else {
                flag = nfalse;
            }
            break;

        case 8:
            brain->move[brain->unk_124] = AnimationRandom(5) + 1;
            flag = nfalse;
            break;

        default:
            return;
    }

    if (sound) {
        if (gTheGame.unk_9C08 == 1) {
            PlaySE(SFX_INIT_TABLE, 0x96);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, 0x97);
        } else {
            PlaySE(SFX_INIT_TABLE, 0x98);
        }
    }

    if (flag) {
        brain->unk_124++;
    }
}

void AISpeedUpMove(ai_t *brain) {
    s32 count;

    for (count = brain->unk_124; count < brain->unk_128; count++) {
        char *move = &brain->move[count];

        switch (*move) {
            case 3:
                *move = 0xD;
                break;

            case 4:
                *move = 0xE;
                break;

            case 1:
                *move = 0xB;
                break;

            case 2:
                *move = 0xC;
                break;

            case 5:
                *move = 0xF;
                break;
        }
    }
}

// TODO: remove
const s64 force_alignment = 0;
