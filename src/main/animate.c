/**
 * Original filename: animate.c
 */

#include "animate.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "ai.h"
#include "animate2d.h"
#include "animate3d.h"
#include "the_game.h"

void CheckGameInput(tetWell *well, cursor_t *cursor, s32 num) {
    if (gTheGame.dimension == DIMENSION_2D) {
        if (brainbrain[num].speed == -1) {
            Input2D(well, cursor, num);
        } else {
            AIMove(well, cursor, &brainbrain[num], num);
        }
        Update2DSwitching(well, cursor);
    } else {
        if (brainbrain[num].speed == -1) {
            Input3D(well, cursor, num);
        } else {
            AIMove(well, cursor, &brainbrain[num], num);
        }
        Update3DSwitching(well, cursor);
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

void AddNewRow(tetWell *well, cursor_t *cursor, s32 num) {
    if (gTheGame.dimension == DIMENSION_2D) {
        Add2DNewRow(well, cursor, num);
    } else {
        Add3DNewRow(well, cursor, num);
    }
}

void RaiseBlocks(tetWell *well, cursor_t *cursor) {
    s32 var_a0 = gTheGame.dimension;
    s32 temp_v0;

#if 0
    // Local variables
    int rate; // r6
    int blockHSize; // r7
#endif

    if (cursor->unk_00 != 0) {
        well->unk_43B0 = 0;
        return;
    }
    if (cursor->unk_08 > 0) {
        well->unk_43B0 = 0;
        return;
    }
    if (cursor->extra_wait != 0) {
        well->unk_43B0 = 0;
        return;
    }
    if (well->unk_43F4 != 0) {
        cursor->unk_0C = 0;
        return;
    }

    if ((well->unk_43B0 == 1) && (cursor->unk_0C > 0)) {
        well->unk_43B0 = 2;
    }
    cursor->unk_0C = 0;
    if (well->unk_43F0 < 0 || well->unk_43F0 > 0x10000) {
        var_a0 *= 2;
    }
    well->unk_43FC += var_a0;
    well->unk_43F8 = well->unk_43F8 + var_a0;

    temp_v0 = gTheGame.dimension * 0x10;
    if (well->unk_43F8 == temp_v0) {
        if (well->unk_43B0 == 1) {
            well->unk_43AC += 1;
        }
        well->unk_43B0 = -4;
        return;
    } else if (temp_v0 < well->unk_43F8) {
        if (well->unk_43B0 == 1) {
            well->unk_43AC += 1;
        }
        well->unk_43B0 = -4;
        well->unk_43FC = (gTheGame.dimension * 0x10) - (well->unk_43F8 - well->unk_43FC);
        well->unk_43F8 = gTheGame.dimension * 0x10;
    }
}

STATIC_INLINE void inlined_func_AfterSwitch(block_t *block2, tetWell *well, cursor_t *cursor, s32 sy, s32 col, s32 temp_t4) {
    block_t *block;
    s32 var_t1;
    s32 var_t0;

    if (block2->state >= BLOCKSTATE_7) {
        return;
    }

    if (sy == 0) {
        block2->state = BLOCKSTATE_0;
    } else {
        block = &well->block[sy - 1][col];

        if ((block->type == 0) || (block->state == BLOCKSTATE_5)) {
            var_t1 = 1;
            block2->state = BLOCKSTATE_5;
            block2->delay = temp_t4;

            for (var_t0 = sy - 1; var_t0 >= 0; var_t0--) {
                if (well->block[var_t0][col].type == BLOCKTYPE_0) {
                    var_t1++;
                } else {
                    var_t0 = 0;
                }
            }

            if (cursor->unk_08 < temp_t4 + var_t1) {
                cursor->unk_08 = temp_t4 + var_t1;
            }
        } else if (block->state == BLOCKSTATE_6) {
            block2->state = BLOCKSTATE_5;
            block2->chain_flag = -1;
        } else {
            block2->state = BLOCKSTATE_0;
        }
    }
}

void AfterSwitch(tetWell *well, cursor_t *cursor, block_t *block1, block_t *block2, Dimension dimen) {
    s32 temp_t4 = well->blockDropDelay;
    s32 row;
    s32 col;
    s32 var_t2;
    block_t *block;
    s32 v0;

    #if 0
    // Local variables
    int wait; // r8
    int check; // r30
    int row; // r11
    int col; // r12
    int temp; // r1+0x8
    int space; // r30
    struct block_t * block; // r1+0x8
    #endif

    if (block1->type != BLOCKTYPE_0) {
        if (dimen == DIMENSION_2D) {
            col = cursor->sx;
        } else {
            col = 4;
        }

        inlined_func_AfterSwitch(block1, well, cursor, cursor->sy, col, temp_t4);

        if (block2->type == BLOCKTYPE_0) {
            var_t2 = -1;

            for (row = cursor->sy + 1; row < BLOCK_LEN_ROWS; row++) {
                block = &well->block[row][col + 1];
                if (block->type == BLOCKTYPE_0) {
                    break;
                }

                if (block->type != BLOCKTYPE_9) {
                    if (block->state < BLOCKSTATE_6) {
                        block->delay = temp_t4;
                        block->state = BLOCKSTATE_5;
                    }

                    var_t2 = 0;
                } else {
                    v0 = -var_t2;
                    if (v0) {
                        block->delay = temp_t4 - 1;
                        break;
                    }
                }
            }
        }
    } else {
        block1->state = BLOCKSTATE_0;
    }

    if (block2->type != BLOCKTYPE_0) {
        if (dimen == DIMENSION_2D) {
            col = cursor->sx + 1;
        } else {
            col = 5;
        }

        inlined_func_AfterSwitch(block2, well, cursor, cursor->sy, col, temp_t4);

        if (block1->type == BLOCKTYPE_0) {
            var_t2 = -1;

            for (row = cursor->sy + 1; row < BLOCK_LEN_ROWS; row++) {
                block = &well->block[row][col - 1];
                if (block->type == BLOCKTYPE_0) {
                    break;
                }

                if (block->type != BLOCKTYPE_9) {
                    if (block->state < BLOCKSTATE_6) {
                        block->delay = temp_t4;
                        block->state = BLOCKSTATE_5;
                    }
                    var_t2 = 0;
                } else {
                    v0 = -var_t2;
                    if (v0) {
                        block->delay = temp_t4 - 1;
                        break;
                    }
                }
            }
        }
    } else {
        block2->state = BLOCKSTATE_0;
    }

    well->collision = -1;
    cursor->extra_wait = 0;
    cursor->sy = -1;
    gOverflow += 0xF0;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate", CheckShake);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate", CheckShake);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate", CheckShake);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate", CheckShake);
#endif

nbool CheckFieldActive(tetWell *well) {
    s32 row;
    s32 col;

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        for (col = 0; col < gMax; col++) {
            if (well->block[row][col].state != BLOCKSTATE_0) {
                return ntrue;
            }
        }
    }

    return nfalse;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate", func_8005731C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate", func_800575BC_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate", func_80055D2C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate", func_80055EAC_ger);
#endif
