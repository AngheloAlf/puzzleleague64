/**
 * Original filename: init3d.c
 */

#include "init3d.h"

#include "macros_defines.h"
#include "main_variables.h"

#include "libc/assert.h"

#include "001F10.h"
#include "dlist.h"
#include "draw3d.h"
#include "init2d.h"
#include "tetris.h"
#include "the_game.h"

/**
 * Original name: Init3DNewRow
 */
void Init3DNewRow(tetWell *well) {
    s32 col;
    s32 old;
    s32 target = -1;
    s32 check = 0;
    nbool flag = nfalse;
    BlockType type;
    block_t *block;
    extra_t *extra = &well->extra;

    if ((extra->wellGarbage <= 4) && (extra->queueGarbage >= 2)) {
        extra->queueGarbage -= 2;
        extra->wellGarbage += 2;
        check = 3;
        flag = ntrue;
    } else if ((extra->wellGarbage <= 8) && (extra->queueGarbage >= 1)) {
        extra->queueGarbage--;
        extra->wellGarbage++;
        check = 2;
        flag = ntrue;
    } else if (well->state.newBlock < 2) {
        check = 1;
        flag = ntrue;
    }

    if (flag) {
        old = well->state.rand;
        well->state.rand = -1;
        target = RandomBlock(well);
        well->state.rand = old;
    }

    if (well->state.newBlock == 1) {
        well->state.newBlock = 2;
    } else if (well->state.newBlock == 2) {
        well->state.newBlock = 1;
    }

    for (col = BLOCK_COLS_3D - 1; col >= 0; col--) {
        block = &well->new_block[col];

        InitTetrisState(block);

        block->currRow = 0;
        if (col == target) {
            switch (check) {
                case 1:
                    type = well->new_block[col + 1].type;
                    if (type == well->block[0][col].type) {
                        col += 2;
                        continue;
                    }
                    break;

                case 2:
                    type = BLOCKTYPE_7;
                    break;

                case 3:
                    type = BLOCKTYPE_7;
                    well->new_block[col + 1].type = BLOCKTYPE_7;
                    break;
            }
        } else {
            if (col == 0) {
                do {
                    type = RandomBlock(well);
                } while ((type == well->new_block[BLOCK_COLS_3D - 1].type) || (type == well->new_block[col + 1].type) ||
                         (type == well->block[0][col].type));
            } else {
                do {
                    type = RandomBlock(well);
                } while ((type == well->new_block[col + 1].type) || (type == well->block[0][col].type));
            }
        }

        block->type = type;
    }
}

/**
 * Original name: Init3DCursor
 */
void Init3DCursor(cursor_t *cursor, s32 num) {
    cursor->sy = -1;
    cursor->sx = 0;
    cursor->x = 4;

    if (gTheGame.totalPlayer == 1) {
        cursor->rect.s.objX = (35 << 2) + 2;
    } else if (num == 0) {
        cursor->rect.s.objX = (12 << 2) + 3;
    } else {
        cursor->rect.s.objX = (53 << 2) + 2;
    }

    cursor->rect.s.objY = ((50 << 2) + 3) - (cursor->y * 0x10);
}

/**
 * Original name: Init3DTetrisBlocks
 */
void Init3DTetrisBlocks(tetWell *well, s32 num UNUSED) {
    block_t *block;
    s32 i;
    s32 j;

    well->translation = 0.0f;

    for (i = 0; i < BLOCK_LEN_ROWS; i++) {
        for (j = 0; j < BLOCK_COLS_3D; j++) {
            block = &well->block[i][j];
            InitTetrisState(block);
            block->currRow = i;
            well->visible[i][j] = 0;
        }
    }

    for (j = 0; j < BLOCK_COLS_3D; j++) {
        block = &well->new_block[j];
        InitTetrisState(block);
        block->currRow = 0;
    }
}

/**
 * Original name: Init3DTetrisBlocksState
 */
void Init3DTetrisBlocksState(tetWell *well) {
    s32 i;
    s32 j;

    for (i = 0; i < BLOCK_LEN_ROWS; i++) {
        for (j = 0; j < BLOCK_COLS_3D; j++) {
            block_t *block = &well->block[i][j];
            BlockType temp_s1 = block->type;

            if (temp_s1 != BLOCKTYPE_0) {
                InitTetrisState(block);
                block->type = temp_s1;
            } else {
                InitTetrisState(block);
            }
        }
    }
}

/**
 * Original name: Init3DIcons
 */
void Init3DIcons(tetWell *well) {
    s32 i;

    for (i = 0; i < ICON_COUNT; i++) {
        icon_t *icon = well->icon + i;

        icon->flag = 0;
        icon->type = -1;
        icon->count = 0;
        icon->distance = 0;
        icon->to_x = 0;
        guMtxIdent(&icon->thing.move);
    }
}

/**
 * Original name: Init3DAttackBlocks
 */
void Init3DAttackBlocks(tetWell *well) {
    s32 i;

    for (i = 0; i < ATTACK_COUNT; i++) {
        attack_t *attack = &well->attack[i];

        attack->state = ATTACKSTATE_0;
        attack->type = ATTACKTYPE_0;
        attack->disappear = -1;
        attack->delay = 0;
        attack->counter = 0;
        attack->currRow = -1;
        attack->slot = -1;
    }
}

/**
 * Original name: Init3DExplosion
 */
void Init3DExplosion(tetWell *well) {
    s32 i;

    for (i = 0; i < EXPLOSION_COUNT; i++) {
        explode_t *explode = &well->explosion[i];

        explode->type = -1;
        explode->frame = -1;
    }
}

/**
 * Original name: Init3DText
 */
void Init3DText(void) {
    s32 i;

    gTheGame.currentText = 0;
    for (i = gTheGame.currentText; i < DRAWTEXT_COUNT; i++) {
        gTheGame.drawText[i].texture = -1;
    }
}

/**
 * Original name: Init3DClearLine
 */
void Init3DClearLine(tetWell *well, struct cursor_t *cursor UNUSED, s32 num) {
    uObjSprite_t *s;

    well->attack[0].currRow = 0;

    s = &well->attack[0].rect.s;
    if (gTheGame.totalPlayer == 1) {
        s->objX = (56 << 2) + 1;
    } else if (num == 0) {
        s->objX = (33 << 2) + 3;
    } else {
        s->objX = (34 << 2) + 1;
    }

    s->objY = (49 << 2) + 2;
}

void func_8005DE94_usa(const u16 arg0[], s32 arg1) {
    s32 win = GAME_STATUS_GET_WIN_RECORD(gGameStatus);

    switch (win) {
        case 3:
            if (gTheGame.tetrisWell[1].extra.win == 0) {
                func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_1, arg0, arg1);
            } else {
                func_800643A4_usa(ENUM_FUNC_800643A4_USA_ARG0_1, arg0, arg1);
            }

            if (gTheGame.tetrisWell[1].extra.win < 2) {
                func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_2, arg0, arg1);
            } else {
                func_800643A4_usa(ENUM_FUNC_800643A4_USA_ARG0_2, arg0, arg1);
            }

            func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_3, arg0, arg1);

            if (gTheGame.tetrisWell[0].extra.win == 0) {
                func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_4, arg0, arg1);
            } else {
                func_800643A4_usa(ENUM_FUNC_800643A4_USA_ARG0_4, arg0, arg1);
            }

            if (gTheGame.tetrisWell[0].extra.win < 2) {
                func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_5, arg0, arg1);
            } else {
                func_800643A4_usa(ENUM_FUNC_800643A4_USA_ARG0_5, arg0, arg1);
            }

            func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_6, arg0, arg1);
            break;

        case 2:
            if (gTheGame.tetrisWell[1].extra.win == 0) {
                func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_1, arg0, arg1);
            } else {
                func_800643A4_usa(ENUM_FUNC_800643A4_USA_ARG0_1, arg0, arg1);
            }

            func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_2, arg0, arg1);
            func_80064728_usa(ENUM_FUNC_800643A4_USA_ARG0_3, arg0, arg1);

            if (gTheGame.tetrisWell[0].extra.win == 0) {
                func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_4, arg0, arg1);
            } else {
                func_800643A4_usa(ENUM_FUNC_800643A4_USA_ARG0_4, arg0, arg1);
            }

            func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_5, arg0, arg1);
            func_80064728_usa(ENUM_FUNC_800643A4_USA_ARG0_6, arg0, arg1);
            break;

        case 1:
            func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_1, arg0, arg1);
            func_80064728_usa(ENUM_FUNC_800643A4_USA_ARG0_2, arg0, arg1);
            func_80064728_usa(ENUM_FUNC_800643A4_USA_ARG0_3, arg0, arg1);
            func_80064AAC_usa(ENUM_FUNC_800643A4_USA_ARG0_4, arg0, arg1);
            func_80064728_usa(ENUM_FUNC_800643A4_USA_ARG0_5, arg0, arg1);
            func_80064728_usa(ENUM_FUNC_800643A4_USA_ARG0_6, arg0, arg1);
            break;
    }
}

/**
 * Original name: Init3DSmallStars
 */
void Init3DSmallStars(s32 num) {
    Init2DSmallStars(num);
}

/**
 * Original name: Init3DCircleStars
 */
void Init3DCircleStars(s32 num, s32 pos) {
    Init2DCircleStars(num, pos);
}

/**
 * Original name: Init3DGameOverSmoke
 */
void Init3DGameOverSmoke(tetWell *well, s32 num) {
    DATA_INLINE_CONST s32 sp0[] = {
        13, 23, 39, 59, 79, 99, 115, 125,
    };
    DATA_INLINE_CONST s32 sp20[] = {
        177, 187, 203, 223, 243, 263, 279, 289,
    };
    DATA_INLINE_CONST s32 sp40[] = {
        105, 115, 131, 151, 171, 191, 207, 217,
    };
    s32 var_t1;
    s32 var_t2;
    explode_t *explode;

    static_assert(ARRAY_COUNT(sp0) == ARRAY_COUNT(sp20), "");

#if 0
    int left[8]; // r1+0x50
    int right[8]; // r1+0x30
    int centre[8]; // r1+0x10
#endif

    var_t2 = 0;

    for (var_t1 = 0; var_t1 < EXPLOSION_COUNT; var_t1++) {
        explode = &well->explosion[var_t1];

        explode->type = -1;
        explode->frame = -1;
        explode->rect.s.imageAdrs = 0;

        if (gTheGame.totalPlayer == 1) {
            //! @bug? shouldn't this be `< 1` instead?
            if ((var_t1 <= 1) || (var_t1 >= ARRAY_COUNT(sp40))) {
                explode->rect.s.objX = -(160 << 2);
            } else {
                explode->rect.s.objX = sp40[var_t1 - 1] << 2;
            }
        } else {
            if ((var_t1 <= 1) || (var_t1 >= ARRAY_COUNT(sp0))) {
                explode->rect.s.objX = -(160 << 2);
            } else if (num == 0) {
                explode->rect.s.objX = sp0[var_t1 - 1] << 2;
            } else {
                explode->rect.s.objX = sp20[var_t1 - 1] << 2;
            }
        }

        explode->rect.s.objY = 15 << 2;

        var_t2++;
        // TODO: macroify
        if (var_t2 >= 18) {
            return;
        }
    }
}

/**
 * Original name: Init3DVertex
 */
INLINE void Init3DVertex(void) {
    void *ptr;

    ptr = Pon_Image_Heap;
    // Original name likely to be just "vertex"
    LOAD_DATA_SEGMENT(ptr, segment_vertex, Pon_Image_Heap);
    gAllVertex = ptr;
}

/**
 * Original name: Init3DMatrixBlocks
 */
void Init3DMatrixBlocks(void) {
    Init3DVertex();
    guMtxIdent(&gIdent);
}

/**
 * Original name: Return3DComboTile
 */
s32 Return3DComboTile(s32 combo) {
    s32 which;

    if (combo < 70) {
        which = (combo + 4) % 8;
    } else {
        which = -1;
    }

    switch (which) {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return 2;
        case 4:
            return 4;
        case 5:
            return 5;
        case 6:
            return 6;
        case 7:
            return 7;
        default:
            return 3;
    }
}

/**
 * Original name: Return3DChainTile
 */
s32 Return3DChainTile(s32 chain) {
    s32 which;

    if (chain < 0x63) {
        which = chain % 8;
    } else {
        return 3;
    }

    switch (which) {
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 3;
        case 5:
            return 4;
        case 6:
            return 5;
        case 7:
            return 6;
        case 0:
            return 7;
    }

    return 7;
}
