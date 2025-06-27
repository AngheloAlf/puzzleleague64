/**
 * Original filename: update3d.c
 */

#include "update3d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "cursor.h"
#include "tetwell.h"

void Update3DDistance(tetWell *well, cursor_t *cursor) {
    s32 temp_a3;
    attack_t *attack;

    if (well->unk_43FC == 0) {
        return;
    }

    temp_a3 = well->unk_43FC / 2;
    well->translation += (f32)well->unk_43FC / DOUBLE_LITERAL(250.0);
    cursor->rect.s.objY -= temp_a3;
    if (((gSelection == 0xAA) || (gSelection == 0xB4)) && (cursor->unk_28[0] <= 0)) {
        attack = &well->attack[0];

        attack->unk_24++;
        if (attack->unk_24 != ((attack->unk_24 / 12) * 12)) {
            attack->rect.s.objY -= temp_a3;
        }
    }
}

void Update3DPosition(tetWell *well, cursor_t *cursor UNUSED, s32 flag) {
    block_t last[BLOCK_LEN_ROWS];
    explode_t *explode;
    attack_t *attack;
    s32 row;
    s32 count;

    if (flag == 0) {
        for (row = 0; row < BLOCK_LEN_ROWS; row++) {
            bcopy(&well->block[row][BLOCK_LEN_B - 1], &last[row], sizeof(block_t));
        }

        for (row = 0; row < BLOCK_LEN_ROWS; row++) {
            bcopy(&well->block[row][0], &well->block[row][1], sizeof(block_t) * (BLOCK_LEN_B - 1));
        }

        for (row = 0; row < BLOCK_LEN_ROWS; row++) {
            bcopy(&last[row], &well->block[row][0], sizeof(block_t));
        }

        bcopy(&well->new_block[BLOCK_LEN_B - 1], &last, sizeof(block_t));
        bcopy(well->new_block, &well->new_block[1], sizeof(block_t) * (BLOCK_LEN_B - 1));
        bcopy(&last[0], &well->new_block[0], sizeof(block_t));

        for (count = 0; count < ICON_COUNT; count++) {
            well->icon[count].from_x++;
            well->icon[count].to_x++;
        }

        for (count = 0; count < ATTACK_COUNT; count++) {
            if (well->attack[count].state >= ATTACKSTATE_5) {
                attack = &well->attack[count];

                if (attack->start == 0x11) {
                    attack->start = 0;
                } else {
                    attack->start++;
                }

                if (attack->unk_1C == 0x11) {
                    attack->unk_1C = 0;
                } else {
                    attack->unk_1C++;
                }
            }
        }

        for (count = 0; count < EXPLOSION_COUNT; count++) {
            if (well->explosion[count].type != -1) {
                explode = &well->explosion[count];

                if (explode->rect.s.scaleW == 0x11) {
                    explode->rect.s.scaleW = 0;
                } else {
                    explode->rect.s.scaleW++;
                }
            }
        }

        return;
    }

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        bcopy(&well->block[row][0], &last[row], sizeof(block_t));
    }

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        bcopy(&well->block[row][1], &well->block[row][0], sizeof(block_t) * (BLOCK_LEN_B - 1));
    }

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        bcopy(&last[row], &well->block[row][0x11], sizeof(block_t));
    }

    bcopy(&well->new_block[0], &last[0], sizeof(block_t));
    bcopy(&well->new_block[1], &well->new_block[0], sizeof(block_t) * (BLOCK_LEN_B - 1));
    bcopy(&last[0], &well->new_block[0x11], sizeof(block_t));

    for (count = 0; count < ICON_COUNT; count++) {
        well->icon[count].from_x -= 1;
        well->icon[count].to_x -= 1;
    }

    for (count = 0; count < ATTACK_COUNT; count++) {
        if (well->attack[count].state >= ATTACKSTATE_5) {
            attack = &well->attack[count];

            if (attack->start == 0) {
                attack->start = 0x11;
            } else {
                attack->start--;
            }

            if (attack->unk_1C == 0) {
                attack->unk_1C = 0x11;
            } else {
                attack->unk_1C--;
            }
        }
    }

    for (count = 0; count < EXPLOSION_COUNT; count++) {
        if (well->explosion[count].type != -1) {
            explode = &well->explosion[count];

            if (explode->rect.s.scaleW == 0) {
                explode->rect.s.scaleW = 0x11;
            } else {
                explode->rect.s.scaleW--;
            }
        }
    }
}

void Update3DCursor(tetWell *well, cursor_t *cursor) {
    if (cursor->unk_18 < 0) {
        cursor->unk_18++;
        if (cursor->unk_18 == 0) {
            Update3DPosition(well, cursor, -1);
        }
    } else if (cursor->unk_18 > 0) {
        cursor->unk_18--;
        if (cursor->unk_18 == 0) {
            Update3DPosition(well, cursor, 0);
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update3d", func_80067860_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update3d", func_80067B30_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update3d", func_80066270_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update3d", func_80066420_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update3d", Check3DVisibleBlocks);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update3d", Check3DVisibleBlocks);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update3d", Check3DVisibleBlocks);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update3d", Check3DVisibleBlocks);
#endif
