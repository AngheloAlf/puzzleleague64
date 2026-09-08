/**
 * Original filename: update2d.c
 */

#include "update2d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "cursor.h"
#include "explode2d.h"
#include "init2d.h"
#include "sfxlimit.h"
#include "tetwell.h"
#include "the_game.h"
#include "update.h"

void Update2DDistance(tetWell *well, cursor_t *cursor) {
    s32 row;
    s32 count;
    s32 temp;
    s32 distance;
    attack_t *attack;
    uObjSprite *s;

    distance = well->raise;

    if (distance == 0) {
        return;
    }

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        // TODO: fake match?
        do {
            for (count = 0; count < TETWELL_OBJSPRITE_LEN_B; count++) {
                s = &well->block_rect[row][count];

                temp = s->s.objY >> 2;
                s->s.objY = (temp - distance) << 2;
            }
        } while (0);
    }

    for (count = 0; count < TETWELL_UNK_3EF0_LEN_6; count++) {
        s = &well->new_block_rect[count];

        temp = s->s.objY >> 2;
        s->s.objY = (temp - distance) << 2;
    }

    for (row = 0; row < ATTACK_COUNT; row++) {
        if (well->attack[row].state == ATTACKSTATE_0) {
            break;
        }

        attack = &well->attack[row];
        if (attack->state >= ATTACKSTATE_7) {
            if ((attack->expression != 0) && (attack->disappear == -1)) {
                temp = attack->rect.s.objY >> 2;
                attack->rect.s.objY = (temp - distance) << 2;
            }
        }
    }

    temp = well->left2D.s.objY >> 2;
    well->left2D.s.objY = (temp - distance) << 2;

    temp = well->right2D.s.objY >> 2;
    well->right2D.s.objY = (temp - distance) << 2;

    temp = cursor->rect.s.objY >> 2;
    cursor->rect.s.objY = (temp - distance) << 2;

    if ((gSelection == SELECTION_AA) || (gSelection == SELECTION_B4)) {
        Update2DClearLine(well, cursor, distance);
    }
}

void Update2DClearLine(tetWell *well, cursor_t *cursor, s32 distance) {
    s32 row;
    s32 temp;
    attack_t *attack;

    if (cursor->target[0] > 0) {
        return;
    }

    for (row = 0; row < 6; row++) {
        attack = &well->attack[row];
        temp = attack->rect.s.objY >> 2;
        attack->rect.s.objY = (temp - distance) << 2;
    }

    temp = well->attack[row].rect.s.objY >> 2;
    well->attack[row].rect.s.objY = (temp - distance) << 2;
}

#if VERSION_USA
#if 0
void Update2DIcon(tetWell *well, cursor_t *cursor, s32 num) {
    s32 sp1C;
    s32 sp24;
    s32 temp_a0;
    s32 temp_a0_3;
    s32 temp_s2;
    s32 temp_s3;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_s4;
    s32 var_s5;
    s32 var_v0;
    s32 var_v0_2;
    icon_t *temp_s0;

    var_s4 = 0;

    sp1C = 0;
    sp24 = 0;
    temp_s3 = well->block_rect[0][0].s.objX >> 2;
    temp_s2 = well->block_rect[0][0].s.objY >> 2;

    for (var_s5 = 0; var_s5 < 0xA; var_s5++) {
        temp_s0 = &well->icon[var_s5];
        if (!((temp_s0->flag != -1) || (temp_s0->count >= 0) || (temp_s0->type < 0xC))) {
            sp1C = -1;
            break;
        }
    }

    for (var_s5 = 0; var_s5 < 0xA; var_s5++) {
        if (well->icon[var_s5].flag != -1) {
            continue;
        }

        temp_s0 = &well->icon[var_s5];
        if (temp_s0->count < 0) {
            temp_s0->total = -temp_s0->count;

            if (temp_s0->type == ICONTYPE_12) {
                if (var_s4 == 0) {
                    var_s4 = 1;
                }
                UpdateComboScore(well, cursor, temp_s0->total);
                if (gGameStatus & 4) {
                    temp_s0->flag = 0;
                } else {
                    Start2DIconSplash(well, temp_s3 + ((temp_s0->from_x * 0x12) + 5), temp_s2 - ((temp_s0->to_y * 0x10) + 6));
                    Init2DComboTMEM(temp_s0);
                    temp_s0->thing.rect.s.imageW = 0x200;
                    var_v0 = temp_s0->from_x * 0x12;
                    temp_s0->thing.rect.s.objX = (temp_s3 + var_v0) * 4;
                    temp_s0->unk_20 = temp_s2 - (temp_s0->to_y * 0x10);
                    temp_s0->thing.rect.s.objY = temp_s0->unk_20 * 4;
                    temp_s0->count = 0x28;
                }
            } else if (temp_s0->type == ICONTYPE_10) {
                UpdateChainScore(well, cursor, temp_s0->total);
                var_s4 = 2;
                if (gGameStatus & 4) {
                    temp_s0->flag = 0;
                } else {
                    Init2DChainTMEM(temp_s0);
                    temp_s0->thing.rect.s.imageW = 0x200;
                    temp_s0->thing.rect.s.objX = (temp_s3 + (temp_s0->from_x * 0x12)) * 4;
                    if (sp1C == 0) {
                        var_a1 = temp_s3 + ((temp_s0->from_x * 0x12) + 5);
                        var_a2 = temp_s2 - ((temp_s0->to_y * 0x10) + 6);
                        var_v0_2 = temp_s0->to_y * 0x10;
                        temp_s0->unk_20 = temp_s2 - var_v0_2;
                        temp_s0->thing.rect.s.objY = temp_s0->unk_20 * 4;
                    } else {
                        var_a1 = temp_s3 + ((temp_s0->from_x * 0x12) + 5);
                        var_a2 = temp_s2 - ((temp_s0->to_y * 0x10) + 0x16);
                        var_v0_2 = (temp_s0->to_y * 0x10) + 0x10;
                        temp_s0->unk_20 = temp_s2 - var_v0_2;
                        temp_s0->thing.rect.s.objY = temp_s0->unk_20 * 4;
                    }
                    Start2DIconSplash(well, var_a1, var_a2);
                    temp_s0->count = 0x28;
                }
            } else if (temp_s0->type == ICONTYPE_13) {
                if (var_s4 == 0) {
                    var_s4 = 1;
                }
                UpdateComboScore(well, cursor, temp_s0->total);
                if (gGameStatus & 4) {
                    temp_s0->flag = 0;
                } else {
                    Start2DIconSplash(well, temp_s3 + ((temp_s0->from_x * 0x12) + 0xD), temp_s2 - ((temp_s0->to_y * 0x10) + 6));
                    temp_s0->thing.rect.s.imageAdrs = 0x80;
                    temp_s0->thing.rect.s.imageW = 0x400;
                    var_v0 = temp_s0->from_x * 0x12;
                    temp_s0->thing.rect.s.objX = (temp_s3 + var_v0) * 4;
                    temp_s0->unk_20 = temp_s2 - (temp_s0->to_y * 0x10);
                    temp_s0->thing.rect.s.objY = temp_s0->unk_20 * 4;
                    temp_s0->count = 0x28;
                }
            } else {
                sp24 = -1;
                temp_s0->thing.rect.s.imageAdrs = 0x84;
                temp_s0->thing.rect.s.imageW = 0x400;
                var_v0 = (temp_s0->from_x * 0x12) + 0x15;
                temp_s0->thing.rect.s.objX = (temp_s3 + var_v0) * 4;
                temp_s0->unk_20 = temp_s2 - (temp_s0->to_y * 0x10);
                temp_s0->thing.rect.s.objY = temp_s0->unk_20 * 4;
                temp_s0->count = 0x28;
            }

        } else {
            temp_s0->count--;
            if (temp_s0->count == 0) {
                temp_s0->flag = 0;
            } else {
                switch (temp_s0->count+1) {              /* switch 2 */
                    case 0x6:                   /* switch 2 */
                    case 0x14:                  /* switch 2 */
                    case 0x19:                  /* switch 2 */
                    case 0x1C:                  /* switch 2 */
                    case 0x1E:                  /* switch 2 */
                    case 0x21:                  /* switch 2 */
                    case 0x23:                  /* switch 2 */
                    case 0x25:                  /* switch 2 */
                    case 0x26:                  /* switch 2 */
                    case 0x27:                  /* switch 2 */
                    case 0x28:                  /* switch 2 */
                        temp_s0->unk_20 -= 1;
                        break;
                }
                temp_s0->thing.rect.s.objY = temp_s0->unk_20 * 4;
            }
        }
    }

    if (sp24 != 0) {
        PlaySE(SFX_INIT_TABLE, SFX_07C);
    }

    if ((var_s4 == 0) || (well->unk_43A4 != 0)) {
        return;
    }

    if (gTheGame.totalPlayer == 1) {
        if (var_s4 == 1) {
            func_80005888_usa(B_801C6EE8_usa, 0, 0);
        } else if (well->unk_43A8 >= -2) {
            func_80005888_usa(B_801C6EE8_usa, 0, 0xB);
        } else if (well->unk_43A8 == -3) {
            func_80005888_usa(B_801C6EE8_usa, 0, 0xC);
        } else if (well->unk_43A8 == -4) {
            func_80005888_usa(B_801C6EE8_usa, 0, 0xD);
        } else {
            func_80005888_usa(B_801C6EE8_usa, 0, 0xE);
        }
    } else if (num == 0) {
        if (var_s4 == 1) {
            func_80005888_usa(B_801C6EE8_usa, 1, 0);
        } else if (well->unk_43A8 >= -2) {
            func_80005888_usa(B_801C6EE8_usa, 1, 0xB);
        } else if (well->unk_43A8 == -3) {
            func_80005888_usa(B_801C6EE8_usa, 1, 0xC);
        } else if (well->unk_43A8 == -4) {
            func_80005888_usa(B_801C6EE8_usa, 1, 0xD);
        } else {
            func_80005888_usa(B_801C6EE8_usa, 1, 0xE);
        }
    } else {
        if (var_s4 == 1) {
            func_80005888_usa(B_801C6E58_usa, 2, 0);
        } else if (well->unk_43A8 >= -2) {
            func_80005888_usa(B_801C6E58_usa, 2, 0xB);
        } else if (well->unk_43A8 == -3) {
            func_80005888_usa(B_801C6E58_usa, 2, 0xC);
        } else if (well->unk_43A8 == -4) {
            func_80005888_usa(B_801C6E58_usa, 2, 0xD);
        } else {
            func_80005888_usa(B_801C6E58_usa, 2, 0xE);
        }
    }

}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/update2d", Update2DIcon);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update2d", Update2DIcon);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update2d", Update2DIcon);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update2d", Update2DIcon);
#endif
