/**
 * Original filename: init2d.c
 */

#include "init2d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "animation.h"
#include "character.h"
#include "dlist.h"
#include "tetris.h"
#include "the_game.h"

/**
 * Original name: Init2DNewRow
 */
void Init2DNewRow(tetWell *well) {
    s32 col;
    s32 old;
    s32 target = -1;
    s32 check = 0;
    s32 flag = nfalse;
    BlockType type;
    block_t *block;
    extra_t *extra = &well->extra;
    uObjSprite *rect;

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
        do {
            target = RandomBlock(well) - 1;
        } while ((well->block[0][target].type == BLOCKTYPE_7) || (well->block[0][target + 1].type == BLOCKTYPE_7));
        well->state.rand = old;
    }

    if (well->state.newBlock == 1) {
        well->state.newBlock = 2;
    } else if (well->state.newBlock == 2) {
        well->state.newBlock = 1;
    }

    for (col = TETWELL_UNK_3EF0_LEN_6 - 1; col >= 0; col--) {
        block = &well->new_block[col];
        rect = &well->new_block_rect[col];

        InitTetrisState(block);
        block->currRow = 0;
        if (col == target) {
            switch (check) {
                case 0x1:
                    type = well->new_block[col + 1].type;
                    if (type == well->block[0][col].type) {
                        col += 2;
                        continue;
                    }
                    break;

                case 0x2:
                    type = BLOCKTYPE_7;
                    break;

                case 0x3:
                    type = BLOCKTYPE_7;
                    well->new_block[col + 1].type = BLOCKTYPE_7;
                    Init2DTetrisTMEM(&well->new_block[col + 1], &well->new_block_rect[col + 1]);
                    break;
            }
        } else {
            do {
                type = RandomBlock(well);
            } while ((type == well->new_block[col + 1].type) || (type == well->block[0][col].type));
        }

        rect->s.objY = 223 << 2;
        block->type = type;
        Init2DTetrisTMEM(block, rect);
    }
}

/**
 * Original name: Init2DCursor
 */
void Init2DCursor(cursor_t *cursor, s32 num) {
    uObjSprite_t *s = &cursor->rect.s;

    if (gTheGame.totalPlayer == 1) {
        s->objX = (cursor->x * 18 + 110) << 2;
    } else if (num == 0) {
        s->objX = (cursor->x * 18 + 20) << 2;
    } else {
        s->objX = (cursor->x * 18 + 184) << 2;
    }

    s->scaleW = 1 << 10;
    s->imageW = 44 << 5;
    s->paddingX = 0;

    s->objY = (203 - cursor->y * 16) << 2;
    s->scaleH = 1 << 10;
    s->imageH = 24 << 5;
    s->paddingY = 0;

    s->imageStride = 8;
    s->imageAdrs = 0;
    s->imageFmt = G_IM_FMT_CI;
    s->imageSiz = G_IM_SIZ_8b;
    s->imagePal = 0;
    s->imageFlags = 0;
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
void Init2DTetrisBlocks(tetWell *well, s32 num) {
    s32 var_a2;
    s32 var_s4;
    s32 var_s6;
    block_t *var_s1;
    uObjSprite_t *var_s0;

    for (var_s6 = 0; var_s6 < 0xC; var_s6++) {
        for (var_s4 = 0; var_s4 < 6; var_s4++) {
            var_s1 = &well->block[var_s6][var_s4];
            var_s0 = &well->block_rect[var_s6][var_s4];
            var_a2 = (0xCF - var_s6 * 0x10) << 2;

            InitTetrisState(var_s1);
            var_s1->currRow = var_s6;

            if (gTheGame.totalPlayer == 1) {
                var_s0->objX = var_s4 * 0x48 + 0x1C8;
            } else if (num == 0) {
                var_s0->objX = var_s4 * 0x48 + 0x60;
            } else {
                var_s0->objX = var_s4 * 0x48 + 0x2F0;
            }

            var_s0->scaleW = 911;
            var_s0->imageW = 16 << 5;
            var_s0->paddingX = 0;

            var_s0->objY = var_a2;
            var_s0->scaleH = 1 << 10;
            var_s0->imageH = 16 << 5;
            var_s0->paddingY = 0;

            var_s0->imageStride = 8;
            var_s0->imageAdrs = 0;
            var_s0->imageFmt = G_IM_FMT_CI;
            var_s0->imageSiz = G_IM_SIZ_8b;
            var_s0->imagePal = 0;
            var_s0->imageFlags = 0;
        }
    }

    for (var_s4 = 0; var_s4 < 6; var_s4++) {
        var_s1 = &well->new_block[var_s4];

        InitTetrisState(var_s1);
        var_s1->currRow = 0;

        var_s0 = &well->new_block_rect[var_s4];
        if (gTheGame.totalPlayer == 1) {
            var_s0->objX = var_s4 * 0x48 + 0x1C8;
        } else if (num == 0) {
            var_s0->objX = var_s4 * 0x48 + 0x60;
        } else {
            var_s0->objX = var_s4 * 0x48 + 0x2F0;
        }

        var_s0->scaleW = 911;
        var_s0->imageW = 16 << 5;
        var_s0->paddingX = 0;

        var_s0->objY = 223 << 2;
        var_s0->scaleH = 1 << 10;
        var_s0->imageH = 16 << 5;
        var_s0->paddingY = 0;

        var_s0->imageStride = 8;
        var_s0->imageAdrs = 0;
        var_s0->imageFmt = G_IM_FMT_CI;
        var_s0->imageSiz = G_IM_SIZ_8b;
        var_s0->imagePal = 0;
        var_s0->imageFlags = 0;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DTetrisBlocks);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", Init2DTetrisBlocks);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", Init2DTetrisBlocks);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", Init2DTetrisBlocks);
#endif

/**
 * Original name: Init2DTetrisBlocksTMEM
 */
void Init2DTetrisBlocksTMEM(tetWell *well, s32 clear) {
    s32 row;
    s32 col;
    BlockType type;
    block_t *block;

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        for (col = 0; col < TETWELL_OBJSPRITE_LEN_B; col++) {
            block = &well->block[row][col];
            type = block->type;
            if (type != BLOCKTYPE_0) {
                if (clear != 0) {
                    InitTetrisState(block);
                }
                block->type = type;
                Init2DTetrisTMEM(block, &well->block_rect[row][col]);
            } else {
                InitTetrisState(block);
            }
        }
    }
}

/**
 * Original name: Init2DIcons
 */
void Init2DIcons(tetWell *well) {
    s32 i;
    icon_t *icon;
    uObjSprite_t *s;

    for (i = 0; i < ICON_COUNT; i++) {
        icon = &well->icon[i];
        s = &icon->thing.rect.s;

        icon->flag = 0;
        icon->type = -1;
        icon->count = 0;
        icon->distance = 0;

        // ??
        s->scaleW = (0 << 10) + 0x38F;
        s->imageW = 16 << 5;
        s->paddingX = 0;

        s->scaleH = 1 << 10;
        s->imageH = 16 << 5;
        s->paddingY = 0;

        s->imageStride = 8;
        s->imageAdrs = 0;
        s->imageFmt = G_IM_FMT_CI;
        s->imageSiz = G_IM_SIZ_8b;
        s->imagePal = 0;
        s->imageFlags = 0;
    }
}

/**
 * Original name: Init2DAttackBlocks
 */
void Init2DAttackBlocks(tetWell *well) {
    s32 i;
    attack_t *attack;
    uObjSprite_t *s;

    for (i = 0; i < ATTACK_COUNT; i++) {
        attack = &well->attack[i];
        s = &attack->rect.s;

        attack->state = ATTACKSTATE_0;
        attack->type = ATTACKTYPE_0;
        attack->disappear = -1;
        attack->delay = 0;
        attack->counter = 0;
        attack->expression = 0;
        attack->currRow = -1;
        attack->slot = -1;

        s->scaleW = 1 << 10;
        s->imageW = 32 << 5;
        s->paddingX = 0;

        s->scaleH = 1 << 10;
        s->imageH = 16 << 5;
        s->paddingY = 0;

        s->imageStride = 0;
        s->imageAdrs = 0;
        s->imageFmt = G_IM_FMT_CI;
        s->imageSiz = G_IM_SIZ_8b;
        s->imagePal = 0;
        s->imageFlags = 0;
    }
}

/**
 * Original name: Init2DExplosion
 */
void Init2DExplosion(tetWell *well) {
    s32 i;
    explode_t *explode;
    uObjSprite_t *s;

    for (i = 0; i < EXPLOSION_COUNT; i++) {
        explode = &well->explosion[i];
        s = &explode->rect.s;

        explode->type = -1;
        explode->frame = -1;

        s->scaleW = 1 << 10;
        s->paddingX = 0;
        s->scaleH = 1 << 10;
        s->paddingY = 0;

        s->imageStride = 8;
        s->imageAdrs = 0;
        s->imageFmt = G_IM_FMT_CI;
        s->imageSiz = G_IM_SIZ_8b;
        s->imagePal = 0;
        s->imageFlags = 0;
    }
}

/**
 * Original name: Init2DText
 */
void Init2DText(void) {
    s32 i;
    s32 temp;
    uObjSprite_t *s;

    gTheGame.currentText = 6;

    for (i = 0; i < DRAWTEXT_COUNT; i++) {
        gTheGame.drawText[i].texture = -1;
        s = &gTheGame.drawText[i].word.s;
        s->scaleW = 1 << 10;
        s->imageW = 16 << 5;
        s->paddingX = 0;

        s->scaleH = 1 << 10;
        s->imageH = 16 << 5;
        s->paddingY = 0;

        s->imageStride = 8;
        s->imageAdrs = 0;
        s->imageFmt = G_IM_FMT_CI;
        s->imageSiz = G_IM_SIZ_8b;
        s->imagePal = 0;
        s->imageFlags = 0;
    }

    switch (gSelection) {
        case SELECTION_8C:
        case SELECTION_BE:
            if (gTheGame.tetrisWell[0].menu.game != 0) {
                s = &gTheGame.drawText[0].word.s;

                gTheGame.drawText[0].texture = 0;
                s->objX = 228 << 2;
                s->objY = 33 << 2;
                s->imageW = 64 << 5;
                s->imageH = 8 << 5;
                s->imageAdrs = 0;
            }

            s = &gTheGame.drawText[1].word.s;
            gTheGame.drawText[1].texture = 0;
            s->objX = 228 << 2;
            s->objY = 54 << 2;
            s->imageW = 64 << 5;
            s->imageH = 8 << 5;
            s->imageAdrs = 0x40;

            s = &gTheGame.drawText[2].word.s;
            gTheGame.drawText[2].texture = 0;
            s->objX = 228 << 2;
            s->objY = 82 << 2;
            s->imageW = 64 << 5;
            s->imageH = 8 << 5;
            s->imageAdrs = 0x80;

            s = &gTheGame.drawText[3].word.s;
            gTheGame.drawText[3].texture = 0;
            s->objX = 228 << 2;
            s->objY = 111 << 2;
            s->imageW = 64 << 5;
            s->imageH = 8 << 5;
            s->imageAdrs = 0xC0;

            s = &gTheGame.drawText[4].word.s;
            s->objX = 232 << 2;
            s->objY = 121 << 2;
            s->imageW = 64 << 5;
            s->imageH = 16 << 5;

            switch (gTheGame.tetrisWell[0].menu.game) {
                case 0x0:
                    gTheGame.drawText[4].texture = 1;
                    s->imageAdrs = 0;
                    break;

                case 0x1:
                    gTheGame.drawText[4].texture = 1;
                    s->imageAdrs = 0x80;
                    break;

                case 0x2:
                    gTheGame.drawText[4].texture = 2;
                    s->imageAdrs = 0;
                    break;

                case 0x3:
                    gTheGame.drawText[4].texture = 2;
                    s->imageAdrs = 0x80;
                    break;
            }
            break;

        case SELECTION_AA:
            gTheGame.drawText[0].texture = 4;
            s = &gTheGame.drawText[0].word.s;
            s->objX = 228 << 2;
            s->objY = 31 << 2;
            s->imageW = 64 << 5;
            s->imageH = 8 << 5;
            s->imageAdrs = 0x80;

            if (gTheGame.tetrisWell[0].menu.game == 5) {
                gTheGame.drawText[4].texture = 7;
                s = &gTheGame.drawText[4].word.s;
                s->objX = 232 << 2;
                s->objY = 40 << 2;
                s->imageW = 64 << 5;
                s->imageH = 16 << 5;
                if (gTheGame.tetrisWell[0].menu.stage == 3) {
                    s->imageAdrs = 0;
                } else {
                    s->imageAdrs = 0x80;
                }
            }

            gTheGame.drawText[1].texture = 0;
            s = &gTheGame.drawText[1].word.s;
            s->objX = 228 << 2;
            s->objY = 54 << 2;
            s->imageW = 64 << 5;
            s->imageH = 8 << 5;
            s->imageAdrs = 0x40;

            gTheGame.drawText[2].texture = 0;
            s = &gTheGame.drawText[2].word.s;
            s->objX = 228 << 2;
            s->objY = 82 << 2;
            s->imageW = 64 << 5;
            s->imageH = 8 << 5;
            s->imageAdrs = 0x80;

            if (gTheGame.tetrisWell[0].menu.game != 5) {
                gTheGame.drawText[3].texture = 0;
                s = &gTheGame.drawText[3].word.s;
                s->objX = 228 << 2;
                s->objY = 111 << 2;
                s->imageW = 64 << 5;
                s->imageH = 8 << 5;
                s->imageAdrs = 0xC0;
            }
            break;

        case SELECTION_82:
            if (gTheGame.tetrisWell[0].menu.game != 0) {
                gTheGame.drawText[0].texture = 4;
                s = &gTheGame.drawText[0].word.s;
                s->objX = 228 << 2;
                s->objY = 33 << 2;
                s->imageW = 64 << 5;
                s->imageH = 8 << 5;
                if (gTheGame.tetrisWell[0].menu.game < 4) {
                    s->imageAdrs = 0;
                } else {
                    s->imageAdrs = 0x40;
                }
            }

            gTheGame.drawText[1].texture = 4;
            s = &gTheGame.drawText[1].word.s;
            s->objX = 228 << 2;
            s->objY = 55 << 2;
            s->imageW = 64 << 5;
            s->imageH = 8 << 5;
            s->imageAdrs = 0x80;

            if (gTheGame.tetrisWell[0].menu.game == 0) {
                gTheGame.drawText[2].texture = 8;
                s = &gTheGame.drawText[2].word.s;
                s->objX = 230 << 2;
                s->objY = 33 << 2;
                s->imageW = 64 << 5;
                s->imageH = 16 << 5;
                s->imageAdrs = 0;
            }

            s = &gTheGame.drawText[3].word.s;
            gTheGame.drawText[3].word.s.imageStride = 6;
            s->objX = 245 << 2;
            s->objY = 80 << 2;
            s->imageW = 24 << 5;
            s->imageH = 24 << 5;
            break;

        case SELECTION_96:
            gTheGame.drawText[0].texture = -1;
            s = &gTheGame.drawText[0].word.s;
            s->objX = 141 << 2;
            s->objY = 195 << 2;
            s->imageW = 16 << 5;
            s->imageH = 16 << 5;
            s->imageAdrs = 0;

            gTheGame.drawText[1].texture = -1;
            s = &gTheGame.drawText[1].word.s;
            s->objX = 163 << 2;
            s->objY = 195 << 2;
            s->imageW = 16 << 5;
            s->imageH = 16 << 5;
            s->imageAdrs = 0x80;

            gTheGame.drawText[2].texture = 5;
            s = &gTheGame.drawText[2].word.s;
#if VERSION_GER
            s->objX = 138 << 2;
#else
            s->objX = 140 << 2;
#endif
            s->objY = 93 << 2;
            s->imageW = 41 << 5;
            s->imageH = 16 << 5;
            s->imageAdrs = 0;

            temp = gTheGame.menu[0].stage;
            if (temp < 5) {
                gTheGame.drawText[3].texture = 5;
                s = &gTheGame.drawText[3].word.s;
                s->imageW = 16 << 5;
                s->imageH = 16 << 5;
                s->objX = 150 << 2;
                s->objY = 107 << 2;
                temp = (temp - 1) * 0x10;
                s->imageAdrs = ((temp + 0x400)) >> 3;
            } else if (temp < 13) {
                gTheGame.drawText[3].texture = 6;
                s = &gTheGame.drawText[3].word.s;
                s->imageW = 16 << 5;
                s->imageH = 16 << 5;
                if (temp < 0xA) {
                    s->objX = 150 << 2;
                } else {
                    s->objX = 154 << 2;
                }
                s->objY = 107 << 2;
                if (temp < 9) {
                    temp = (temp - 5) * 0x10;
                    s->imageAdrs = (temp) >> 3;
                } else {
                    temp = (temp - 9) * 0x10;
                    s->imageAdrs = (temp + 0x400) >> 3;
                }
            } else if (temp < 15) {
                gTheGame.drawText[3].texture = 5;
                s = &gTheGame.drawText[3].word.s;
                s->imageW = 16 << 5;
                s->imageH = 16 << 5;
                s->objX = 154 << 2;
                s->objY = 107 << 2;
                s->imageAdrs = 6;

                gTheGame.drawText[4].texture = 5;
                s = &gTheGame.drawText[4].word.s;
                s->imageW = 16 << 5;
                s->imageH = 16 << 5;
                s->objX = 154 << 2;
                s->objY = 107 << 2;
                if (temp == 0xD) {
                    s->imageAdrs = 0x84;
                } else {
                    s->imageAdrs = 0x86;
                }
            } else if (temp < 19) {
                gTheGame.drawText[3].texture = 5;
                s = &gTheGame.drawText[3].word.s;
                s->imageW = 16 << 5;
                s->imageH = 16 << 5;
                s->objX = 154 << 2;
                s->objY = 107 << 2;
                s->imageAdrs = 6;

                gTheGame.drawText[4].texture = 6;
                s = &gTheGame.drawText[4].word.s;
                s->imageW = 16 << 5;
                s->imageH = 16 << 5;
                s->objX = 154 << 2;
                s->objY = 107 << 2;
                temp = (temp - 0xF) * 0x10;
                s->imageAdrs = temp >> 3;
            }

            s = &gTheGame.drawText[5].word.s;
            s->imageW = 64 << 5;
            s->imageH = 16 << 5;
            s->objY = 141 << 2;

            switch (gTheGame.tetrisWell[0].menu.game) {
                case 0x1:
                    gTheGame.drawText[5].texture = 1;
#if VERSION_GER
                    s->objX = 126 << 2;
#else
                    s->objX = 125 << 2;
#endif
                    s->imageAdrs = 0x80;
                    break;

                case 0x2:
                    gTheGame.drawText[5].texture = 2;
#if VERSION_FRA
                    s->objX = 132 << 2;
#elif VERSION_GER
                    s->objX = 130 << 2;
#else
                    s->objX = 133 << 2;
#endif
                    s->imageAdrs = 0;
                    break;

                case 0x3:
                    gTheGame.drawText[5].texture = 2;
#if VERSION_FRA
                    s->objX = 121 << 2;
#elif VERSION_GER
                    s->objX = 126 << 2;
#else
                    s->objX = 125 << 2;
#endif
                    s->imageAdrs = 0x80;
                    break;

                case 0x4:
                    gTheGame.drawText[5].texture = 3;
#if VERSION_FRA
                    s->objX = 126 << 2;
#elif VERSION_GER
                    s->objX = 132 << 2;
#else
                    s->objX = 133 << 2;
#endif
                    s->imageAdrs = 0x80;
                    break;

                case 0x5:
                    gTheGame.drawText[5].texture = 3;
#if VERSION_FRA
                    s->objX = 127 << 2;
#else
                    s->objX = 132 << 2;
#endif
                    s->imageAdrs = 0;
                    break;
            }
            break;

        case SELECTION_A0:
        case SELECTION_B4:
        case SELECTION_C8:
            func_8006C204_usa();

            s = &gTheGame.drawText[0].word.s;
            s->objX = 141 << 2;
            s->objY = 177 << 2;
            s->imageW = 16 << 5;
            s->imageH = 16 << 5;

            s = &gTheGame.drawText[1].word.s;
            s->objX = 141 << 2;
            s->objY = 194 << 2;
            s->imageW = 16 << 5;
            s->imageH = 16 << 5;

            s = &gTheGame.drawText[2].word.s;
            s->objX = 141 << 2;
            s->objY = 211 << 2;
            s->imageW = 16 << 5;
            s->imageH = 16 << 5;

            s = &gTheGame.drawText[3].word.s;
            s->objX = 163 << 2;
            s->objY = 177 << 2;
            s->imageW = 16 << 5;
            s->imageH = 16 << 5;

            s = &gTheGame.drawText[4].word.s;
            s->objX = 163 << 2;
            s->objY = 194 << 2;
            s->imageW = 16 << 5;
            s->imageH = 16 << 5;

            s = &gTheGame.drawText[5].word.s;
            s->objX = 163 << 2;
            s->objY = 211 << 2;
            s->imageW = 16 << 5;
            s->imageH = 16 << 5;
            break;

        default:
            break;
    }
}

/**
 * Original name: Init2DClearLine
 */
void Init2DClearLine(tetWell *well, cursor_t *cursor UNUSED, s32 num) {
    s32 count;
    uObjSprite_t *s;

    for (count = 0; count < 6; count++) {
        s = &well->attack[count].rect.s;

        if (gTheGame.totalPlayer == 1) {
            s->objX = (count * 18 + 114) << 2;
        } else if (num == 0) {
            s->objX = (count * 18 + 24) << 2;
        } else {
            s->objX = (count * 18 + 188) << 2;
        }
        s->objY = 208 << 2;

        s->scaleW = 911;
        s->scaleH = 1 << 10;

        s->imageW = 16 << 5;
        s->imageH = 16 << 5;

        s->imageStride = 8;
        s->imageAdrs = 0;
    }

    s = &well->attack[count].rect.s;
    if (gTheGame.totalPlayer == 1) {
        s->objX = 222 << 2;
        s->imageAdrs = 2;
    } else if (num == 0) {
        s->objX = 132 << 2;
        s->imageAdrs = 2;
    } else {
        s->objX = 140 << 2;
        s->imageAdrs = 0x82;
    }

    s->objY = 208 << 2;
    s->imageW = 48 << 5;
    s->imageH = 16 << 5;
    s->imageStride = 8;
}

void func_8006C204_usa(void) {
    s32 temp_v1 = GAME_STATUS_GET_WIN_RECORD(gGameStatus);

    switch (temp_v1) {
        case 0x3:
            if (gTheGame.tetrisWell[1].extra.win == 0) {
                gTheGame.drawText[0].texture = 0xC8;
                gTheGame.drawText[0].word.s.imageAdrs = 0;
            } else {
                gTheGame.drawText[0].texture = 8;
                gTheGame.drawText[0].word.s.imageAdrs = 0x80;
            }

            if (gTheGame.tetrisWell[1].extra.win < 2) {
                gTheGame.drawText[1].texture = 0xC8;
                gTheGame.drawText[1].word.s.imageAdrs = 0;
            } else {
                gTheGame.drawText[1].texture = 8;
                gTheGame.drawText[1].word.s.imageAdrs = 0x80;
            }

            gTheGame.drawText[2].texture = 0xC8;
            gTheGame.drawText[2].word.s.imageAdrs = 0;

            if (gTheGame.tetrisWell[0].extra.win == 0) {
                gTheGame.drawText[3].texture = 0xC8;
                gTheGame.drawText[3].word.s.imageAdrs = 0x80;
            } else {
                gTheGame.drawText[3].texture = 8;
                gTheGame.drawText[3].word.s.imageAdrs = 0x82;
            }

            if (gTheGame.tetrisWell[0].extra.win < 2) {
                gTheGame.drawText[4].texture = 0xC8;
                gTheGame.drawText[4].word.s.imageAdrs = 0x80;
            } else {
                gTheGame.drawText[4].texture = 8;
                gTheGame.drawText[4].word.s.imageAdrs = 0x82;
            }

            gTheGame.drawText[5].texture = 0xC8;
            gTheGame.drawText[5].word.s.imageAdrs = 0x80;
            break;

        case 0x2:
            if (gTheGame.tetrisWell[1].extra.win == 0) {
                gTheGame.drawText[0].texture = 0xC8;
                gTheGame.drawText[0].word.s.imageAdrs = 0;
            } else {
                gTheGame.drawText[0].texture = 8;
                gTheGame.drawText[0].word.s.imageAdrs = 0x80;
            }

            gTheGame.drawText[1].texture = 0xC8;
            gTheGame.drawText[1].word.s.imageAdrs = 0;

            gTheGame.drawText[2].texture = 8;
            gTheGame.drawText[2].word.s.imageAdrs = 0x84;

            if (gTheGame.tetrisWell[0].extra.win == 0) {
                gTheGame.drawText[3].texture = 0xC8;
                gTheGame.drawText[3].word.s.imageAdrs = 0x80;
            } else {
                gTheGame.drawText[3].texture = 8;
                gTheGame.drawText[3].word.s.imageAdrs = 0x82;
            }

            gTheGame.drawText[4].texture = 0xC8;
            gTheGame.drawText[4].word.s.imageAdrs = 0x80;

            gTheGame.drawText[5].texture = 8;
            gTheGame.drawText[5].word.s.imageAdrs = 0x86;
            break;

        case 0x1:
            gTheGame.drawText[0].texture = 0xC8;
            gTheGame.drawText[0].word.s.imageAdrs = 0;

            gTheGame.drawText[1].texture = 8;
            gTheGame.drawText[1].word.s.imageAdrs = 0x84;

            gTheGame.drawText[2].texture = 8;
            gTheGame.drawText[2].word.s.imageAdrs = 0x84;

            gTheGame.drawText[3].word.s.imageAdrs = 0x80;
            gTheGame.drawText[3].texture = 0xC8;

            gTheGame.drawText[4].texture = 8;
            gTheGame.drawText[4].word.s.imageAdrs = 0x86;

            gTheGame.drawText[5].texture = 8;
            gTheGame.drawText[5].word.s.imageAdrs = 0x86;
            break;
    }
}

/**
 * Original name: Init2DSmallStars
 */
void Init2DSmallStars(s32 num) {
    s32 var_s3 = 0;
    u8 stars_POS[21][3] = {
        { 0x10, 0xA0, 0x18 }, { 0x28, 0xB8, 0x18 }, { 0x18, 0xA8, 0x12 }, { 0x62, 0xF2, 0x20 }, { 0x30, 0xC0, 0x2D },
        { 0x4A, 0xDA, 0x1E }, { 0x25, 0xB5, 0x25 }, { 0x5A, 0xEA, 0x29 }, { 0x38, 0xC8, 0x18 }, { 0x5B, 0xEB, 0x30 },
        { 0x40, 0xD0, 0x50 }, { 0x10, 0xA0, 0x55 }, { 0x48, 0xD8, 0x68 }, { 0x2A, 0xBA, 0x70 }, { 0x19, 0xA9, 0x78 },
        { 0x37, 0xC7, 0x78 }, { 0x25, 0xB5, 0x26 }, { 0x3A, 0xCA, 0x80 }, { 0x40, 0xD0, 0x6D }, { 0x58, 0xE8, 0x77 },
        { 8, 0x98, 0x77 },
    };
    u8 stars_DROP[10] = {
        3, 6, 4, 6, 5, 2, 3, 2, 4, 1,
    };
    u8 stars_TMEM[4][4] = { { 0, 2, 4, 6 }, { 0x80, 0x82, 0x84, 0x86 }, { 0, 2, 4, 6 }, { 0x80, 0x82, 0x84, 0x86 } };

    s32 i;
    s32 j;
    tetWell *tetWell;
    block_t *block;
    uObjSprite_t *s;

    gTheGame.unk_9C10 = osGetTime();
    tetWell = &gTheGame.tetrisWell[0];

    for (i = 0; i < BLOCK_LEN_ROWS; i++) {
        for (j = 0; j < TETWELL_OBJSPRITE_LEN_B; j++) {
            block = &tetWell->block[i][j];
            s = &tetWell->block_rect[i][j].s;

            if (num == 0) {
                s->objX = (stars_POS[var_s3][num] + 0x16) << 2;
            } else {
                s->objX = (stars_POS[var_s3][num] + 0x2A) << 2;
            }

            s->objY = (stars_POS[var_s3][2] + 0x1C) << 2;

            block->currRow = AnimationRandom(4);
            block->frame_n = AnimationRandom(4);
            block->frame_d = 0;
            block->drop = stars_DROP[AnimationRandom(ARRAY_COUNT(stars_DROP))];

            if (var_s3 % 2 == 0) {
                block->bomb = 1;
            } else {
                block->bomb = 2;
            }

            s->scaleW = 1 << 10;
            s->imageW = 16 << 5;
            s->imageH = 16 << 5;
            s->scaleH = 1 << 10;
            s->imageStride = 8;
            s->imageAdrs = stars_TMEM[block->currRow][block->frame_n];

            var_s3++;
            if (var_s3 >= ARRAY_COUNT(stars_POS)) {
                return;
            }
        }
    }
}

/**
 * Original name: Init2DCircleStars
 */
void Init2DCircleStars(s32 num, s32 pos) {
    tetWell *well = &gTheGame.tetrisWell[1];
    uObjSprite_t *s;
    block_t *block;
    s32 row;
    s32 col;
    s32 var_a0;
    s32 total = 0;

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        for (col = 0; col < TETWELL_OBJSPRITE_LEN_B; col++) {
            block = &well->block[row][col];
            s = &well->block_rect[row][col].s;

            if (gSelection == SELECTION_96) {
                if (num == 0) {
                    block->drop = 0x91;
                    gTheGame.drawText[0].texture = 0xC8;
                } else {
                    block->drop = 0xA7;
                    gTheGame.drawText[1].texture = 0xC8;
                }
                block->delay = 0xC7;
            } else {
                var_a0 = pos;
                if (num == 1) {
                    var_a0 += 3;
                }

                if (num == 0) {
                    block->drop = 0x91;
                } else {
                    block->drop = 0xA7;
                }

                if (pos == 0) {
                    block->delay = 0xB4;
                } else if (pos == 1) {
                    block->delay = 0xC5;
                } else {
                    block->delay = 0xD6;
                }

                gTheGame.drawText[var_a0].texture = 8;
                if (num == 0) {
                    gTheGame.drawText[var_a0].word.s.imageAdrs = 0x80;
                } else {
                    gTheGame.drawText[var_a0].word.s.imageAdrs = 0x82;
                }
            }

            s->objX = block->drop << 2;
            s->objY = block->delay << 2;
            block->currRow = 0;
            block->frame_n = AnimationRandom(4);
            block->chain_flag = total * 0x1E;
            block->bomb = 2;
            block->frame_d = 0;
            block->sound = 0;
            block->state = BLOCKSTATE_0;

            s->scaleW = 1 << 10;
            s->imageW = 16 << 5;
            s->scaleH = 1 << 10;
            s->imageH = 16 << 5;
            s->imageStride = 8;
            s->imageAdrs = 0;

            total += 1;
            if (total >= 0xC) {
                return;
            }
        }
    }
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
void Init2DGameOverSmoke(tetWell *well, s32 num) {
    s32 var_t3;
    s32 var_t4;
    explode_t *temp_a2;
    uObjSprite_t *temp_v1;

    var_t4 = 0;

    for (var_t3 = 0; var_t3 < 0x32; var_t3++) {
        temp_a2 = &well->explosion[var_t3];

        temp_a2->type = -1;
        temp_a2->frame = -1;

        temp_v1 = &temp_a2->rect.s;

        if (gTheGame.totalPlayer == 1) {
            temp_v1->objX = 0x1C8 + var_t3 * 0x48;
        } else if (num == 0) {
            temp_v1->objX = 0x60 + var_t3 * 0x48;
        } else {
            temp_v1->objX = 0x2F0 + var_t3 * 0x48;
        }

        temp_v1->objY = 15 << 2;
        temp_v1->scaleW = 911;
        temp_v1->imageW = 16 << 5;
        temp_v1->paddingX = 0;
        temp_v1->scaleH = 1 << 10;
        temp_v1->imageH = 16 << 5;
        temp_v1->paddingY = 0;

        temp_v1->imageStride = 8;
        temp_v1->imageAdrs = 6;
        temp_v1->imageFmt = G_IM_FMT_I;
        temp_v1->imageSiz = G_IM_SIZ_8b;
        temp_v1->imagePal = 0;
        temp_v1->imageFlags = 0;

        var_t4 += 1;
        if (var_t4 >= 6) {
            return;
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DGameOverSmoke);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", Init2DGameOverSmoke);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", Init2DGameOverSmoke);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", Init2DGameOverSmoke);
#endif

/**
 * Original name: Init2DTetrisTMEM
 */
void Init2DTetrisTMEM(block_t *block, uObjSprite *rect) {
    switch (block->type) {
        case BLOCKTYPE_1:
            rect->s.imageAdrs = 0;
            break;

        case BLOCKTYPE_2:
            rect->s.imageAdrs = 2;
            break;

        case BLOCKTYPE_3:
            rect->s.imageAdrs = 4;
            break;

        case BLOCKTYPE_4:
            rect->s.imageAdrs = 6;
            break;

        case BLOCKTYPE_5:
            rect->s.imageAdrs = 0x80;
            break;

        case BLOCKTYPE_6:
            rect->s.imageAdrs = 0x82;
            break;

        case BLOCKTYPE_7:
            rect->s.imageAdrs = 0x84;
            break;

        case BLOCKTYPE_8:
            rect->s.imageAdrs = 0x86;
            break;

        default:
            break;
    }
}

/**
 * Original name: Init2DComboTMEM
 */
void Init2DComboTMEM(icon_t *icon) {
    s32 which;
    u16 *addr;

    if (icon->total < 0x46) { // DRAWTEXT_COUNT?
        which = (icon->total + 4) % 8;
    } else {
        which = -1;
    }

    addr = &icon->thing.rect.s.imageAdrs;
    switch (which) {
        case 0x0:
            *addr = 0;
            break;

        case 0x1:
            *addr = 2;
            break;

        case 0x2:
            *addr = 4;
            break;

        case 0x3:
            *addr = 6;
            break;

        case 0x4:
            *addr = 0x80;
            break;

        case 0x5:
            *addr = 0x82;
            break;

        case 0x6:
            *addr = 0x84;
            break;

        case 0x7:
            *addr = 0x86;
            break;

        default:
            *addr = 6;
            break;
    }
}

/**
 * Original name: Init2DChainTMEM
 */
void Init2DChainTMEM(icon_t *icon) {
    s32 which;
    u16 *addr;

    if (icon->total < 0x63) {
        which = icon->total % 8;
    } else {
        which = -1;
    }

    addr = &icon->thing.rect.s.imageAdrs;
    switch (which) {
        case 0x1:
            *addr = 0;
            break;

        case 0x2:
            *addr = 2;
            break;

        case 0x3:
            *addr = 4;
            break;

        case 0x4:
            *addr = 6;
            break;

        case 0x5:
            *addr = 0x80;
            break;

        case 0x6:
            *addr = 0x82;
            break;

        case 0x7:
            *addr = 0x84;
            break;

        case 0x0:
            *addr = 0x86;
            break;

        default:
            *addr = 6;
            break;
    }
}

// TODO: `type` is `AttackType`?
/**
 * Original name: Init2DAttackTMEM
 */
void Init2DAttackTMEM(uObjSprite *rect, s32 type, s32 lev, s32 pos) {
    s32 value = ReturnAttackTexValue(NULL, type, lev, pos) % 10;

    switch (value) {
        case 0x0:
            rect->s.imageAdrs = 0;
            break;

        case 0x1:
            rect->s.imageAdrs = 2;
            break;

        case 0x2:
            rect->s.imageAdrs = 4;
            break;

        case 0x3:
            rect->s.imageAdrs = 6;
            break;

        case 0x4:
            rect->s.imageAdrs = 0x80;
            break;

        case 0x5:
            rect->s.imageAdrs = 0x82;
            break;

        case 0x6:
            rect->s.imageAdrs = 0x84;
            break;

        case 0x7:
            rect->s.imageAdrs = 0x86;
            break;
    }
}

/**
 * Original name: Init2DBrickTMEM
 */
void Init2DBrickTMEM(attack_t *attack) {
    uObjSprite_t *s = &attack->rect.s;

    s->imageW = 20 << 5;
    s->scaleW = 32 << 5;
    s->imageStride = 16;
    s->imageFmt = G_IM_FMT_RGBA;
    s->imageSiz = G_IM_SIZ_16b;

    switch (attack->type) {
        case ATTACKTYPE_1:
            s->imageW = 24 << 5;
            s->imageAdrs = 0;
            break;

        case ATTACKTYPE_12:
        case ATTACKTYPE_18:
            s->imageAdrs = 0;
            break;

        case ATTACKTYPE_2:
            s->imageW = 16 << 5;
            s->imageAdrs = 6;
            break;

        case ATTACKTYPE_3:
            s->imageW = 24 << 5;
            s->imageAdrs = 0xA;
            break;

        case ATTACKTYPE_9:
        case ATTACKTYPE_15:
        case ATTACKTYPE_21:
            s->imageAdrs = 0x100;
            break;

        case ATTACKTYPE_4:
        case ATTACKTYPE_10:
        case ATTACKTYPE_16:
            s->imageAdrs = 0x105;
            break;

        case ATTACKTYPE_13:
        case ATTACKTYPE_19:
            s->imageAdrs = 5;
            break;

        case ATTACKTYPE_14:
        case ATTACKTYPE_20:
            s->imageAdrs = 0xA;
            break;

        default:
            s->imageAdrs = 0x10A;
            break;
    }
}

/**
 * Original name: Init2DFaceTMEM
 */
void Init2DFaceTMEM(attack_t *attack) {
    if (attack->type < ATTACKTYPE_11) {
        attack->expression = 0x1E;
        attack->counter = -0xA;
        attack->rect.s.imageAdrs = 0;
    } else if (AnimationRandom(0x332) % 2 == 0) {
        attack->expression = 0x1F;
        attack->counter = -0xA;
        attack->rect.s.imageAdrs = 2;
    } else {
        attack->expression = 0x20;
        attack->counter = -0x96;
        attack->rect.s.imageAdrs = 4;
    }
}
