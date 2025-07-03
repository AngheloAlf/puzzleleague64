/**
 * Original filename: init2d.c
 */

#include "init2d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "animation.h"
#include "dlist.h"
#include "the_game.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DNewRow);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", Init2DNewRow);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", Init2DNewRow);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", Init2DNewRow);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DCursor);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", Init2DCursor);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", Init2DCursor);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", Init2DCursor);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DTetrisBlocks);
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
                Init2DTetrisTMEM(block, &well->unk_3830[row][col]);
            } else {
                InitTetrisState(block);
            }
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DIcons);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", Init2DIcons);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", Init2DIcons);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", Init2DIcons);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DAttackBlocks);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", Init2DAttackBlocks);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", Init2DAttackBlocks);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", Init2DAttackBlocks);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DExplosion);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", Init2DExplosion);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", Init2DExplosion);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", Init2DExplosion);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DText);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", func_8006BA68_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", func_8006A1A8_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", func_8006A358_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DClearLine);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", func_8006C3B0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", func_8006AAF0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", func_8006ACA0_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", func_8006C204_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", func_8006C4D4_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", func_8006AC14_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", func_8006ADC4_ger);
#endif

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
            s = &tetWell->unk_3830[i][j].s;

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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", func_8006C7A0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", func_8006CA70_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", func_8006B1B0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", func_8006B360_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DGameOverSmoke);
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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", func_8006CB30_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", func_8006CB30_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", func_8006CB30_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", func_8006CB30_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", func_8006CBEC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", func_8006CBEC_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", func_8006CBEC_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", func_8006CBEC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", Init2DAttackTMEM);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", Init2DAttackTMEM);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", Init2DAttackTMEM);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", Init2DAttackTMEM);
#endif

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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init2d", func_8006CE14_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init2d", func_8006D0E4_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init2d", func_8006B824_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init2d", func_8006B9D4_ger);
#endif
