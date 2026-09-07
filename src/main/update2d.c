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
    s32 sp14;
    s32 sp1C;
    s32 sp24;
    enum IconType temp_v1;
    icon_t *temp_s0_2;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_s4;
    s32 var_s5;
    s32 var_s5_2;
    s32 var_s7;
    s32 var_v0;
    s32 var_v0_2;
    tetWell *var_s6;
    icon_t *temp_s0;

    var_s4 = 0;
    var_s5 = 0;
    sp14 = num;
    sp1C = 0;
    sp24 = 0;
    var_a0 = 0;
    temp_s3 = (s32) ((u16) well->block_rect[0][0].s.objX << 0x10) >> 0x12;
    temp_s2 = (s32) ((u16) well->block_rect[0][0].s.objY << 0x10) >> 0x12;
loop_1:
    temp_s0 = well->icon + var_a0;
    var_s5 += 1;
    if ((temp_s0->flag != -1) || (temp_s0->count >= 0) || (temp_s0->type < 0xC)) {
        var_a0 += 0x68;
        if (var_s5 < 0xA) {
            goto loop_1;
        }
    } else {
        sp1C = -1;
    }
    var_s5_2 = 0;
    var_s7 = 0x2AC0;
    var_s6 = well;
    do {
        if (var_s6->icon[0].flag == -1) {
            temp_s0_2 = well + var_s7;
            temp_a2 = temp_s0_2->count;
            temp_v0 = temp_a2 - 1;
            if (temp_a2 < 0) {
                temp_v1 = temp_s0_2->type;
                temp_a2_2 = -temp_a2;
                temp_s0_2->total = temp_a2_2;
                switch (temp_v1) {                  /* switch 1; irregular */
                    case 0xC:                       /* switch 1 */
                        if (var_s4 == 0) {
                            var_s4 = 1;
                        }
                        UpdateComboScore(well, cursor, temp_a2_2);
                        if (gGameStatus & 4) {
                            temp_s0_2->flag = 0;
                        } else {
                            Start2DIconSplash(well, temp_s3 + ((temp_s0_2->from_x * 0x12) + 5), temp_s2 - ((temp_s0_2->to_y * 0x10) + 6));
                            Init2DComboTMEM(temp_s0_2);
                            temp_s0_2->thing.rect.s.imageW = 0x200;
                            var_v0 = temp_s0_2->from_x * 0x12;
block_29:
                            temp_s0_2->thing.rect.s.objX = (temp_s3 + var_v0) * 4;
                            temp_v1_2 = temp_s2 - (temp_s0_2->to_y * 0x10);
                            temp_s0_2->unk_20 = temp_v1_2;
                            temp_s0_2->thing.rect.s.objY = temp_v1_2 * 4;
block_30:
                            temp_s0_2->count = 0x28;
                        }
                        break;
                    case 0xA:                       /* switch 1 */
                        UpdateChainScore(well, cursor, temp_a2_2);
                        var_s4 = 2;
                        if (!(gGameStatus & 4)) {
                            Init2DChainTMEM(temp_s0_2);
                            temp_s0_2->thing.rect.s.imageW = 0x200;
                            temp_s0_2->thing.rect.s.objX = (temp_s3 + (temp_s0_2->from_x * 0x12)) * 4;
                            if (sp1C == 0) {
                                var_a1 = temp_s3 + ((temp_s0_2->from_x * 0x12) + 5);
                                var_a2 = temp_s2 - ((temp_s0_2->to_y * 0x10) + 6);
                                var_v0_2 = temp_s0_2->to_y * 0x10;
                            } else {
                                var_a1 = temp_s3 + ((temp_s0_2->from_x * 0x12) + 5);
                                var_a2 = temp_s2 - ((temp_s0_2->to_y * 0x10) + 0x16);
                                var_v0_2 = (temp_s0_2->to_y * 0x10) + 0x10;
                            }
                            temp_v0_2 = temp_s2 - var_v0_2;
                            temp_s0_2->unk_20 = temp_v0_2;
                            temp_s0_2->thing.rect.s.objY = temp_v0_2 * 4;
                            Start2DIconSplash(well, var_a1, var_a2);
                            goto block_30;
                        }
                        goto block_32;
                    case 0xD:                       /* switch 1 */
                        if (var_s4 == 0) {
                            var_s4 = 1;
                        }
                        UpdateComboScore(well, cursor, temp_a2_2);
                        if (gGameStatus & 4) {
                            temp_s0_2->flag = 0;
                        } else {
                            Start2DIconSplash(well, temp_s3 + ((temp_s0_2->from_x * 0x12) + 0xD), temp_s2 - ((temp_s0_2->to_y * 0x10) + 6));
                            temp_s0_2->thing.rect.s.imageAdrs = 0x80;
                            temp_s0_2->thing.rect.s.imageW = 0x400;
                            var_v0 = temp_s0_2->from_x * 0x12;
                            goto block_29;
                        }
                        break;
                    default:                        /* switch 1 */
                        sp24 = -1;
                        temp_s0_2->thing.rect.s.imageAdrs = 0x84;
                        temp_s0_2->thing.rect.s.imageW = 0x400;
                        var_v0 = (temp_s0_2->from_x * 0x12) + 0x15;
                        goto block_29;
                }
            } else {
                temp_s0_2->count = temp_v0;
                if (temp_v0 == 0) {
block_32:
                    temp_s0_2->flag = 0;
                } else {
                    switch (temp_a2) {              /* switch 2 */
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
                            temp_s0_2->unk_20 -= 1;
                            break;
                    }
                    temp_s0_2->thing.rect.s.objY = temp_s0_2->unk_20 * 4;
                }
            }
        }
        var_s7 += 0x68;
        var_s5_2 += 1;
        var_s6 += 0x68;
    } while (var_s5_2 < 0xA);

    if (sp24 != 0) {
        PlaySE(SFX_INIT_TABLE, SFX_07C);
    }

    if ((var_s4 == 0) || (well->unk_43A4 != 0)) {
        return;
    }

    if (gTheGame.totalPlayer == 1) {
        var_a1_2 = 0;
        if (var_s4 == 1) {
            var_a0_2 = B_801C6EE8_usa;
            var_a2_2 = 0;
        } else {
            temp_a0 = well->unk_43A8;
            if (temp_a0 >= -2) {
                var_a0_2 = B_801C6EE8_usa;
                var_a1_2 = 0;
                var_a2_2 = 0xB;
            } else if (temp_a0 == -3) {
                var_a0_2 = B_801C6EE8_usa;
                var_a1_2 = 0;
                var_a2_2 = 0xC;
            } else {
                var_a1_2 = 0;
                if (temp_a0 == -4) {
                    var_a0_2 = B_801C6EE8_usa;
                    var_a2_2 = 0xD;
                } else {
                    var_a0_2 = B_801C6EE8_usa;
                    var_a2_2 = 0xE;
                }
            }
        }
    } else if (sp14 == 0) {
        var_a1_2 = 1;
        if (var_s4 == 1) {
            var_a0_2 = B_801C6EE8_usa;
            var_a2_2 = 0;
        } else {
            temp_a0_2 = well->unk_43A8;
            if (temp_a0_2 >= -2) {
                var_a0_2 = B_801C6EE8_usa;
                var_a1_2 = 1;
                var_a2_2 = 0xB;
            } else if (temp_a0_2 == -3) {
                var_a0_2 = B_801C6EE8_usa;
                var_a1_2 = 1;
                var_a2_2 = 0xC;
            } else {
                var_a1_2 = 1;
                if (temp_a0_2 == -4) {
                    var_a0_2 = B_801C6EE8_usa;
                    var_a2_2 = 0xD;
                } else {
                    var_a0_2 = B_801C6EE8_usa;
                    var_a2_2 = 0xE;
                }
            }
        }
    } else {
        var_a1_2 = 2;
        if (var_s4 == 1) {
            var_a0_2 = B_801C6E58_usa;
            var_a2_2 = 0;
        } else {
            temp_a0_3 = well->unk_43A8;
            if (temp_a0_3 >= -2) {
                var_a0_2 = B_801C6E58_usa;
                var_a1_2 = 2;
                var_a2_2 = 0xB;
            } else if (temp_a0_3 == -3) {
                var_a0_2 = B_801C6E58_usa;
                var_a1_2 = 2;
                var_a2_2 = 0xC;
            } else {
                var_a1_2 = 2;
                if (temp_a0_3 == -4) {
                    var_a0_2 = B_801C6E58_usa;
                    var_a2_2 = 0xD;
                } else {
                    var_a0_2 = B_801C6E58_usa;
                    var_a2_2 = 0xE;
                }
            }
        }
    }

    func_80005888_usa(var_a0_2, var_a1_2, var_a2_2);
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
