/**
 * Original filename: init3d.c
 */

#include "init3d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

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

    for (i = 0; i < TETWELL_EXPLOSION_LEN; i++) {
        explode_t *explode = &well->explosion[i];

        explode->type = -1;
        explode->frame = -1;
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005DE28_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005DE58_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005DE94_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005E0E8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005E108_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005E128_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005E2DC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/init3d", RO_800C6DA0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/init3d", RO_800C6DC0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/init3d", RO_800C6DE0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E0F8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E128_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E164_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E3B8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E3D8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E128_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E5AC_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/init3d", RO_800C7050_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/init3d", RO_800C7070_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/init3d", RO_800C7090_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005C838_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005C868_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005C8A4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005CAF8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005CB18_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005E128_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005CCEC_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/init3d", RO_800C56B0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/init3d", RO_800C56D0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/init3d", RO_800C56F0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005C9E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005CA18_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005CA54_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005CCA8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005CCC8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005E128_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005CE9C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/init3d", RO_800BC670_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/init3d", RO_800BC690_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/init3d", RO_800BC6B0_ger);
#endif

#if VERSION_USA
#if 0
// TODO: make a new segment
extern UNK_TYPE D_10375E0;
extern UNK_TYPE D_103EAE0;
extern UNK_TYPE D_12C1B0;
extern UNK_TYPE D_1336B0;

void Init3DMatrixBlocks(void) {
    void *temp_s1;

    temp_s1 = Pon_Image_Heap;
    osInvalDCache(&D_10375E0, (u32)&D_103EAE0 - (u32)&D_10375E0);
    func_80001310_usa(&D_12C1B0, temp_s1, (u32)&D_1336B0 - (u32)&D_12C1B0);
    Pon_Image_Heap += (u32)&D_1336B0 - (u32)&D_12C1B0;
    gAllVertex = (s32) temp_s1;
    guMtxIdent(&gIdent);
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", Init3DMatrixBlocks);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005E3F4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/init3d", func_8005E484_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", Init3DMatrixBlocks);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E6C4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/init3d", func_8005E754_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", Init3DMatrixBlocks);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005CE04_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/init3d", func_8005CE94_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", Init3DMatrixBlocks);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005CFB4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/init3d", func_8005D044_ger);
#endif
