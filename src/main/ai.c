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

extern UNK_TYPE B_801C70D4_usa[];

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

#if VERSION_USA
s32 AIVertMove(ai_t *brain, s32 row) {
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
#endif

#if VERSION_USA
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
#endif

#if VERSION_USA
s32 AIHoriMoveBlock(ai_t *brain, s32 from, s32 to) {
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
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIHoriMoveCheckCheck);
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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80076F84_usa);
#endif

#if VERSION_USA
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
#endif

// 12 => BLOCK_LEN_ROWS ?
#if VERSION_USA
INLINE void AISortRows(s32 row, s32 total, s32 array[12]) {
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
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80077338_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007737C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80077670_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIBoundaryCheck);
#endif

#if VERSION_USA
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
            if ((well->block[row][var_a2].type == type) && (well->block[row][var_a2].state == 0)) {
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
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIPossibleCol);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIComboCheck);
#endif

#if VERSION_USA
#if 0
s32 AICombo3a(ai_t *brain) {
    s32 sp0[12];
    s32 *var_v1;
    s32 temp_a0;
    s32 temp_t1;
    s32 var_a2;

    s32 t6 = B_801C70D4_usa[0];
    s32 v1;
    s32 *a0;

    if (t6 == 0x12) {
        return 0;
    }

    v1 = AItotCheck[t6] - 3;
    a0 = AIrowCheck[t6];
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

#if VERSION_USA
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
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AICombo45);
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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIFlashCheck);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_800794C8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIVolumeCheck);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80079D64_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainVert1);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainVert2);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007ACAC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainVert4);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainVert5);
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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainHori2);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChainHori3);
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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80080504_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80080724_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80080AF0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_800812A4_usa);
#endif

#if VERSION_USA
s32 AIStupidMove(tetWell *well, ai_t *brain) {
    s32 row;
    s32 highest;

    for (row = 0; row < 0xC; row++) {
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
            if (well->block[highest][2].type != 0 || (well->block[highest][3].type != 0)) {
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
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075E08_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075F50_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075FF0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800760BC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800761D0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800772E4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077314_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800774A0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077610_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800776C8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007770C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077A00_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077A8C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077CB0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077E90_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800788EC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80078CEC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80078F08_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80079108_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80079424_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007961C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80079858_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007992C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007A0F4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007A17C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007A958_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007B03C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007B384_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007C2D0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007D1B0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007D814_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007E51C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007F028_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007F93C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80080244_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80080894_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80080AB4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80080E80_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80081634_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8008185C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80074538_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80074680_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80074720_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800747EC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80074900_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075A14_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075A44_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075BD0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075D40_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075DF8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075E3C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80076130_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800761BC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800763E0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800765C0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007701C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007741C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80077638_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80077838_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80077B54_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80077D4C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80077F88_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007805C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80078824_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800788AC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80079088_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007976C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80079AB4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007AA00_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007B8E0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007BF44_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007CC4C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007D758_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007E06C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007E974_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007EFC4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007F1E4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007F5B0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007FD64_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007FF8C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800746E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80074830_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800748D0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007499C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80074AB0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075BC4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075BF4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075D80_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075EF0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075FA8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075FEC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800762E0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007636C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80076590_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80076770_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800771CC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800775CC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800777E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800779E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80077D04_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80077EFC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80078138_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007820C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800789D4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80078A5C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80079238_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007991C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80079C64_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007ABB0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007BA90_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007C0F4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007CDFC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007D908_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007E21C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007EB24_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007F174_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007F394_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007F760_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007FF14_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8008013C_ger);
#endif

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
                        if (func_80080AF0_usa(well, cursor, brain) != 0) {
                            brain->unk_01C = 0x1E;
                        } else {
                            goto block_47;
                        }
                    } else {
                    block_47:
                        if (func_80080724_usa(well, cursor, brain) != 0) {
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
