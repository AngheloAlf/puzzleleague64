/**
 * Original filename: init3d.c
 */

#include "init3d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "libc/assert.h"

#include "001F10.h"
#include "dlist.h"
#include "init2d.h"
#include "tetris.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", Init3DNewRow);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", Init3DNewRow);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", Init3DNewRow);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", Init3DNewRow);
#endif

void Init3DCursor(cursor_t *cursor, s32 num) {
    cursor->unk_1C = -1;
    cursor->unk_18 = 0;
    cursor->x = 4;

    if (gTheGame.unk_9C08 == 1) {
        cursor->rect.s.objX = (35 << 2) + 2;
    } else if (num == 0) {
        cursor->rect.s.objX = (12 << 2) + 3;
    } else {
        cursor->rect.s.objX = (53 << 2) + 2;
    }

    cursor->rect.s.objY = ((50 << 2) + 3) - (cursor->y * 0x10);
}

void Init3DTetrisBlocks(tetWell *well) {
    block_t *block;
    s32 i;
    s32 j;

    well->translation = 0.0f;

    for (i = 0; i < BLOCK_LEN_ROWS; i++) {
        for (j = 0; j < BLOCK_LEN_B; j++) {
            block = &well->block[i][j];
            InitTetrisState(block);
            block->currRow = i;
            well->visible[i][j] = 0;
        }
    }

    for (j = 0; j < BLOCK_LEN_B; j++) {
        block = &well->new_block[j];
        InitTetrisState(block);
        block->currRow = 0;
    }
}

void Init3DTetrisBlocksState(tetWell *well) {
    s32 i;
    s32 j;

    for (i = 0; i < BLOCK_LEN_ROWS; i++) {
        for (j = 0; j < BLOCK_LEN_B; j++) {
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

void Init3DIcons(tetWell *well) {
    s32 i;

    for (i = 0; i < ICON_COUNT; i++) {
        icon_t *icon = well->icon + i;

        icon->flag = 0;
        icon->type = -1;
        icon->count = 0;
        icon->unk_20 = 0;
        icon->to_x = 0;
        guMtxIdent(&icon->thing.move);
    }
}

void Init3DAttackBlocks(tetWell *well) {
    s32 i;

    for (i = 0; i < ATTACK_COUNT; i++) {
        attack_t *attack = &well->attack[i];

        attack->state = ATTACKSTATE_0;
        attack->type = ATTACKTYPE_0;
        attack->disappear = -1;
        attack->delay = 0;
        attack->unk_10 = 0;
        attack->unk_24 = -1;
        attack->unk_28 = -1;
    }
}

void Init3DExplosion(tetWell *well) {
    s32 i;

    for (i = 0; i < EXPLOSION_COUNT; i++) {
        explode_t *explode = &well->explosion[i];

        explode->type = -1;
        explode->frame = -1;
    }
}

void Init3DText(void) {
    s32 i;

    gTheGame.unk_90C0 = 0;

    for (i = 0; i < DRAWTEXT_COUNT; i++) {
        gTheGame.drawText[i].texture = -1;
    }
}

void Init3DClearLine(tetWell *well, struct cursor_t *cursor UNUSED, s32 num) {
    uObjSprite_t *s;

    well->attack[0].unk_24 = 0;

    s = &well->attack[0].rect.s;
    if (gTheGame.unk_9C08 == 1) {
        s->objX = 0xE1;
    } else if (num == 0) {
        s->objX = 0x87;
    } else {
        s->objX = 0x89;
    }

    s->objY = 0xC6;
}

#if VERSION_USA
#if 0
void func_8005DE94_usa(s32 arg0, s32 arg1) {
    s32 temp_v1 = (gGameStatus & 0xF00) >> 8;

    switch (temp_v1) {
        case 3:
            if (gTheGame.tetrisWell[1].unk_4404 == 0) {
                func_80064AAC_usa(1, arg0, arg1);
            } else {
                func_800643A4_usa(1, arg0, arg1);
            }
            if (gTheGame.tetrisWell[1].unk_4404 < 2) {
                func_80064AAC_usa(2, arg0, arg1);
            } else {
                func_800643A4_usa(2, arg0, arg1);
            }
            func_80064AAC_usa(3, arg0, arg1);
            if (gTheGame.tetrisWell[0].unk_4404 == 0) {
                func_80064AAC_usa(4, arg0, arg1);
            } else {
                func_800643A4_usa(4, arg0, arg1);
            }
            if (gTheGame.tetrisWell[0].unk_4404 < 2) {
                func_80064AAC_usa(5, arg0, arg1);
            } else {
                func_800643A4_usa(5, arg0, arg1);
            }
            func_80064AAC_usa(6, arg0, arg1);
            break;

        case 2:
            if (gTheGame.tetrisWell[1].unk_4404 == 0) {
                func_80064AAC_usa(1, arg0, arg1);
            } else {
                func_800643A4_usa(1, arg0, arg1);
            }
            func_80064AAC_usa(2, arg0, arg1);
            func_80064728_usa(3, arg0, arg1);
            if (gTheGame.tetrisWell[0].unk_4404 == 0) {
                func_80064AAC_usa(4, arg0, arg1);
            } else {
                func_800643A4_usa(4, arg0, arg1);
            }
            func_80064AAC_usa(5, arg0, arg1);
            func_80064728_usa(6, arg0, arg1);
            break;

        case 1:
            func_80064AAC_usa(1, arg0, arg1);
            func_80064728_usa(2, arg0, arg1);
            func_80064728_usa(3, arg0, arg1);
            func_80064AAC_usa(4, arg0, arg1);
            func_80064728_usa(5, arg0, arg1);
            func_80064728_usa(6, arg0, arg1);
            break;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005DE94_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E164_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005C8A4_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005CA54_ger);
#endif

void Init3DSmallStars(s32 num) {
    Init2DSmallStars(num);
}

#if VERSION_USA
#if 0
void func_8005E108_usa() {
    func_8006C7A0_usa();
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005E108_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E3D8_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005CB18_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005CCC8_ger);
#endif

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

        if (gTheGame.unk_9C08 == 1) {
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

INLINE void Init3DVertex(void) {
    void *ptr;

    ptr = Pon_Image_Heap;
    // segment_12C1B0 = vertex?
    LOAD_DATA_SEGMENT(ptr, segment_12C1B0, Pon_Image_Heap);
    gAllVertex = ptr;
}

void Init3DMatrixBlocks(void) {
    Init3DVertex();
    guMtxIdent(&gIdent);
}

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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005E484_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E754_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005CE94_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005D044_ger);
#endif
