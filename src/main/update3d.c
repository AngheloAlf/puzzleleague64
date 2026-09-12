/**
 * Original filename: update3d.c
 */

#include "update3d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "cursor.h"
#include "explode3d.h"
#include "sfxlimit.h"
#include "tetwell.h"
#include "the_game.h"
#include "update.h"

/**
 * Original name: Update3DDistance
 */
void Update3DDistance(tetWell *well, cursor_t *cursor) {
    s32 temp_a3;
    attack_t *attack;

    if (well->raise == 0) {
        return;
    }

    temp_a3 = well->raise / 2;
    well->translation += (f32)well->raise / DOUBLE_LITERAL(250.0);
    cursor->rect.s.objY -= temp_a3;
    if (((gSelection == SELECTION_AA) || (gSelection == SELECTION_B4)) && (cursor->target[0] <= 0)) {
        attack = &well->attack[0];

        attack->currRow++;
        if (attack->currRow % 12 != 0) {
            attack->rect.s.objY -= temp_a3;
        }
    }
}

/**
 * Original name: Update3DPosition
 */
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

/**
 * Original name: Update3DCursor
 */
void Update3DCursor(tetWell *well, cursor_t *cursor) {
    if (cursor->sx < 0) {
        cursor->sx++;
        if (cursor->sx == 0) {
            Update3DPosition(well, cursor, -1);
        }
    } else if (cursor->sx > 0) {
        cursor->sx--;
        if (cursor->sx == 0) {
            Update3DPosition(well, cursor, 0);
        }
    }
}

/**
 * Original name: Update3DIcon
 */
void Update3DIcon(tetWell *well, cursor_t *cursor, s32 num) {
    s32 i;
    nbool sp14;
    s32 var_s3;
    nbool sound;
    nbool var_v1_2;
    icon_t *icon;

#if 0
    // Local variables
    int i; // r5
    int temp; // r4
    int two; // r23
    int sound; // r22
    int stop; // r21
    struct icon_t * icon; // r6
#endif

    var_s3 = 0;
    sp14 = nfalse;
    sound = nfalse;

    for (i = 0; i < ICON_COUNT; i++) {
        icon = &well->icon[i];

        if ((icon->flag == -1) && (icon->count < 0) && (icon->type >= ICONTYPE_12)) {
            sp14 = ntrue;
            break;
        }
    }

    for (i = 0; i < ICON_COUNT; i++) {
        if (well->icon[i].flag != -1) {
            continue;
        }

        icon = &well->icon[i];
        if (icon->count < 0) {
            icon->total = -icon->count;

            if (icon->type == ICONTYPE_12) {
                if (var_s3 == 0) {
                    var_s3 = 1;
                }

                UpdateComboScore(well, cursor, icon->total);
                if (gGameStatus & GAME_STATUS_FLAG_4) {
                    icon->flag = 0;
                    continue;
                }

                Start3DIconSplash(well, num, icon->to_y, icon->from_x);
                icon->distance = 0;
            } else if (icon->type == ICONTYPE_10) {
                UpdateChainScore(well, cursor, icon->total);
                var_s3 = 2;
                if (gGameStatus & GAME_STATUS_FLAG_4) {
                    icon->flag = 0;
                    continue;
                }

                if (sp14) {
                    icon->distance = 0x20;
                    Start3DIconSplash(well, num, icon->to_y + 1, icon->from_x);
                } else {
                    icon->distance = 0;
                    Start3DIconSplash(well, num, icon->to_y, icon->from_x);
                }
            } else if (icon->type == ICONTYPE_13) {
                if (var_s3 == 0) {
                    var_s3 = 1;
                }
                UpdateComboScore(well, cursor, icon->total);
                if (gGameStatus & GAME_STATUS_FLAG_4) {
                    icon->flag = 0;
                    continue;
                }

                Start3DIconSplash(well, num, icon->to_y, icon->from_x);
                icon->distance = 0;
            } else {
                sound = ntrue;
                icon->distance = 0;
                icon->from_x++;
            }

            icon->count = 25;
            gTransMtx[3][0] = 0.0f;
            gTransMtx[3][1] = icon->distance;
            guMtxF2L(gTransMtx, &icon->thing.move);
        } else {
            icon->count--;
            if (icon->count == 0) {
                icon->flag = 0;
                continue;
            }
            var_v1_2 = nfalse;
            switch (icon->count) {
                case 4:
                case 9:
                case 12:
                case 14:
                case 17:
                case 19:
                case 21:
                case 22:
                case 23:
                case 24:
                    var_v1_2 = ntrue;
                    icon->distance += 2;
                    break;
            }
            if (!var_v1_2) {
                continue;
            }
            gTransMtx[3][0] = 0.0f;
            gTransMtx[3][1] = icon->distance;
            guMtxF2L(gTransMtx, &icon->thing.move);
        }
    }

    if (sound) {
        PlaySE(SFX_INIT_TABLE, SFX_07C);
    }

    if ((var_s3 == 0) || (well->unk_43A4 != 0)) {
        return;
    }

    if (gTheGame.totalPlayer == 1) {
        if (var_s3 == 1) {
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
        if (var_s3 == 1) {
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
        if (var_s3 == 1) {
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

#if VERSION_USA
#if 0
extern ? D_800B8030_usa;
extern ? D_800B8048_usa;
extern ? D_800B8060_usa;
extern ? D_800B8078_usa;

void Check3DVisibleBlocks(tetWell *well, cursor_t *cursor) {
    cursor_t *sp14;
    ? *var_a1;
    ? *var_a1_2;
    ? *var_a1_3;
    ? *var_a1_4;
    ? *var_a1_5;
    ? *var_a1_6;
    ? *var_a1_7;
    ? *var_a1_8;
    ? *var_s1;
    ? *var_s1_2;
    ? *var_s2;
    ? *var_s2_2;
    ? *var_t9;
    ? *var_t9_2;
    block_t *var_t5;
    block_t *var_t5_2;
    s32 temp_t3;
    s32 temp_v1_32;
    s32 var_a2;
    s32 var_a2_2;
    s32 var_a2_3;
    s32 var_a2_4;
    s32 var_a2_5;
    s32 var_a2_6;
    s32 var_a2_7;
    s32 var_a2_8;
    s32 var_t1;
    s32 var_t1_2;
    s32 var_t2;
    s32 var_v0;
    s32 var_v0_10;
    s32 var_v0_11;
    s32 var_v0_12;
    s32 var_v0_13;
    s32 var_v0_14;
    s32 var_v0_15;
    s32 var_v0_16;
    s32 var_v0_17;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v0_7;
    s32 var_v0_8;
    s32 var_v0_9;
    s8 *var_s4;
    s8 *var_s4_2;
    s8 temp_a0;
    s8 temp_a0_10;
    s8 temp_a0_11;
    s8 temp_a0_12;
    s8 temp_a0_13;
    s8 temp_a0_14;
    s8 temp_a0_2;
    s8 temp_a0_3;
    s8 temp_a0_4;
    s8 temp_a0_5;
    s8 temp_a0_6;
    s8 temp_a0_7;
    s8 temp_a0_8;
    s8 temp_a0_9;
    tetWell *var_s6;
    tetWell *var_t4;
    void *temp_a0_15;
    void *temp_v1;
    void *temp_v1_10;
    void *temp_v1_11;
    void *temp_v1_12;
    void *temp_v1_13;
    void *temp_v1_14;
    void *temp_v1_15;
    void *temp_v1_16;
    void *temp_v1_17;
    void *temp_v1_18;
    void *temp_v1_19;
    void *temp_v1_20;
    void *temp_v1_21;
    void *temp_v1_22;
    void *temp_v1_23;
    void *temp_v1_24;
    void *temp_v1_25;
    void *temp_v1_26;
    void *temp_v1_27;
    void *temp_v1_28;
    void *temp_v1_29;
    void *temp_v1_2;
    void *temp_v1_30;
    void *temp_v1_31;
    void *temp_v1_33;
    void *temp_v1_3;
    void *temp_v1_4;
    void *temp_v1_5;
    void *temp_v1_6;
    void *temp_v1_7;
    void *temp_v1_8;
    void *temp_v1_9;

    sp14 = cursor;
    bzero(well->visible[0], 0xD8);
    var_t2 = 0;
    var_s6 = well;
    var_t4 = well;
    temp_t3 = sp14->sx;
    do {
        var_t1 = 1;
        var_s4 = &var_s6->visible[0][1];
        var_t5 = &var_t4->block[0][1];
loop_2:
        var_a2 = 0;
        if ((var_t5->type != BLOCKTYPE_0) && (var_t5->delay != -2)) {
            if (var_t5->unk_3C != 0) {
                if (var_t5->unk_30 != -2) {
                    *var_s4 = 1;
                } else {
                    goto block_8;
                }
            } else {
block_8:
                *var_s4 = 3;
            }
            if (var_t1 != 2) {
                if (var_t1 == 3) {
                    var_a2_2 = 0;
                    if (var_t4->block[0][2].type != BLOCKTYPE_0) {
                        if (var_t4->block[0][2].delay == -2) {
                            var_a2_2 = 0;
                            goto block_14;
                        }
                        goto block_100;
                    }
block_14:
                    var_a1 = &D_800B8048_usa;
                    do {
                        temp_a0 = *(var_a1 + var_t2);
                        if (temp_a0 != -1) {
                            temp_v1 = (temp_a0 * 0x318) + well;
                            if ((temp_v1->unk_2D0 != 0) && (temp_v1->unk_2C4 != -2)) {
                                (well + (temp_a0 * 0x12))->unk_3FC0 = 5;
                            }
                        }
                        var_a2_2 += 1;
                        var_a1 += 0xC;
                    } while (var_a2_2 < 2);
                    var_s4 += 1;
                } else {
                    goto block_100;
                }
            } else {
                var_a2_3 = 0;
                if (var_t4->block[0][1].type != BLOCKTYPE_0) {
                    if (var_t4->block[0][1].delay == -2) {
                        var_a2_3 = 0;
                        goto block_24;
                    }
                    goto block_100;
                }
block_24:
                var_a1_2 = &D_800B8060_usa;
                do {
                    temp_a0_2 = *(var_a1_2 + var_t2);
                    if (temp_a0_2 != -1) {
                        temp_v1_2 = (temp_a0_2 * 0x318) + well;
                        if ((temp_v1_2->unk_2FC != 0) && (temp_v1_2->unk_2F0 != -2)) {
                            (well + (temp_a0_2 * 0x12))->unk_3FC1 = 5;
                        }
                    }
                    var_a2_3 += 1;
                    var_a1_2 += 0xC;
                } while (var_a2_3 < 2);
                var_s4 += 1;
            }
        } else {
            var_s2 = &D_800B8078_usa;
            var_s1 = &D_800B8060_usa;
            var_t9 = &D_800B8048_usa;
            var_a1_3 = &D_800B8030_usa;
            do {
                if (var_t1 != 2) {
                    switch (var_t1) {               /* irregular */
                        default:
                            var_s2 += 0xC;
                            break;
                        case 0x4:
                            temp_a0_3 = *(var_a1_3 + var_t2);
                            if (temp_a0_3 != -1) {
                                temp_v1_3 = (temp_a0_3 * 0x318) + well;
                                if ((temp_v1_3->unk_278 != 0) && (temp_v1_3->unk_26C != -2)) {
                                    var_v0 = temp_a0_3 * 8;
                                    if ((temp_v1_3->unk_2A4 == 0) || (var_v0 = temp_a0_3 * 8, (temp_v1_3->unk_298 == -2))) {
                                        (well + ((var_v0 + temp_a0_3) * 2))->unk_3FBE = 3;
                                    } else {
                                        (well + (temp_a0_3 * 0x12))->unk_3FBE = 1;
                                    }
                                }
                                if (temp_t3 > 0) {
                                    temp_v1_4 = (temp_a0_3 * 0x318) + well;
                                    var_v0_2 = temp_a0_3 * 2;
                                    if (temp_v1_4->unk_24C != 0) {
                                        if (temp_v1_4->unk_240 != -2) {
                                            (well + (temp_a0_3 * 0x12))->unk_3FBD = 3;
                                        }
                                        var_v0_2 = temp_a0_3 * 2;
                                    }
                                    temp_v1_5 = ((var_v0_2 + temp_a0_3) * 0x108) + well;
                                    if ((temp_v1_5->unk_220 != 0) && (temp_v1_5->unk_214 != -2)) {
                                        (well + (temp_a0_3 * 0x12))->unk_3FBC = 3;
                                    }
                                } else if (temp_t3 < 0) {
                                    temp_v1_6 = (temp_a0_3 * 0x318) + well;
                                    if ((temp_v1_6->unk_2D0 != 0) && (temp_v1_6->unk_2C4 != -2)) {
                                        (well + (temp_a0_3 * 0x12))->unk_3FC0 = 3;
                                    }
                                }
                            }
                            goto block_98;
                        case 0x3:
                            temp_a0_4 = *(var_t9 + var_t2);
                            if (temp_a0_4 != -1) {
                                temp_v1_7 = (temp_a0_4 * 0x318) + well;
                                if ((temp_v1_7->unk_2D0 != 0) && (temp_v1_7->unk_2C4 != -2)) {
                                    var_v0_3 = temp_a0_4 * 8;
                                    if ((temp_v1_7->unk_2FC == 0) || (var_v0_3 = temp_a0_4 * 8, (temp_v1_7->unk_2F0 == -2))) {
                                        (well + ((var_v0_3 + temp_a0_4) * 2))->unk_3FC0 = 3;
                                    } else {
                                        (well + (temp_a0_4 * 0x12))->unk_3FC0 = 1;
                                    }
                                }
                                if (temp_t3 > 0) {
                                    temp_v1_8 = (temp_a0_4 * 0x318) + well;
                                    var_v0_4 = temp_a0_4 * 2;
                                    if (temp_v1_8->unk_278 != 0) {
                                        if (temp_v1_8->unk_26C != -2) {
                                            (well + (temp_a0_4 * 0x12))->unk_3FBE = 3;
                                        }
                                        var_v0_4 = temp_a0_4 * 2;
                                    }
                                    temp_v1_9 = ((var_v0_4 + temp_a0_4) * 0x108) + well;
                                    if ((temp_v1_9->unk_24C != 0) && (temp_v1_9->unk_240 != -2)) {
                                        (well + (temp_a0_4 * 0x12))->unk_3FBD = 3;
                                    }
                                } else if (temp_t3 < 0) {
                                    temp_v1_10 = (temp_a0_4 * 0x318) + well;
                                    if ((temp_v1_10->unk_2FC != 0) && (temp_v1_10->unk_2F0 != -2)) {
                                        (well + (temp_a0_4 * 0x12))->unk_3FC1 = 3;
                                    }
                                }
                            }
                            goto block_98;
                        case 0x1:
                            temp_a0_5 = *(var_s2 + var_t2);
                            if (temp_a0_5 != -1) {
                                temp_v1_11 = (temp_a0_5 * 0x318) + well;
                                if ((temp_v1_11->unk_10 != 0) && (temp_v1_11->unk_4 != -2)) {
                                    var_v0_5 = temp_a0_5 * 8;
                                    if ((temp_v1_11->unk_3C == 0) || (var_v0_5 = temp_a0_5 * 8, (temp_v1_11->unk_30 == -2))) {
                                        (well + ((var_v0_5 + temp_a0_5) * 2))->unk_3FB0 = 3;
                                    } else {
                                        (well + (temp_a0_5 * 0x12))->unk_3FB0 = 1;
                                    }
                                }
                            }
                            goto block_98;
                    }
                } else {
                    temp_a0_6 = *(var_s1 + var_t2);
                    if (temp_a0_6 != -1) {
                        temp_v1_12 = (temp_a0_6 * 0x318) + well;
                        if ((temp_v1_12->unk_2FC != 0) && (temp_v1_12->unk_2F0 != -2)) {
                            var_v0_6 = temp_a0_6 * 8;
                            if ((temp_v1_12->unk_10 == 0) || (var_v0_6 = temp_a0_6 * 8, (temp_v1_12->unk_4 == -2))) {
                                (well + ((var_v0_6 + temp_a0_6) * 2))->unk_3FC1 = 3;
                            } else {
                                (well + (temp_a0_6 * 0x12))->unk_3FC1 = 1;
                            }
                        }
                        if (temp_t3 > 0) {
                            temp_v1_13 = (temp_a0_6 * 0x318) + well;
                            var_v0_7 = temp_a0_6 * 2;
                            if (temp_v1_13->unk_2D0 != 0) {
                                if (temp_v1_13->unk_2C4 != -2) {
                                    (well + (temp_a0_6 * 0x12))->unk_3FC0 = 3;
                                }
                                var_v0_7 = temp_a0_6 * 2;
                            }
                            temp_v1_14 = ((var_v0_7 + temp_a0_6) * 0x108) + well;
                            if ((temp_v1_14->unk_2A4 != 0) && (temp_v1_14->unk_298 != -2)) {
                                (well + (temp_a0_6 * 0x12))->unk_3FBF = 3;
                            }
                        }
                    }
block_98:
                    var_s2 += 0xC;
                }
                var_s1 += 0xC;
                var_t9 += 0xC;
                var_a2 += 1;
                var_a1_3 += 0xC;
            } while (var_a2 < 2);
block_100:
            var_s4 += 1;
        }
        var_t1 += 1;
        var_t5 += 0x2C;
        if (var_t1 < 5) {
            goto loop_2;
        }
        var_t1_2 = 8;
        var_s4_2 = &var_s6->visible[0][8];
        var_t5_2 = &var_t4->block[0][8];
loop_103:
        if (var_t5_2->type == BLOCKTYPE_0) {
            var_a2_4 = 0;
            goto block_137;
        }
        if (var_t5_2->delay == -2) {
            var_a2_4 = 0;
block_137:
            var_t9_2 = &D_800B8078_usa;
            var_s2_2 = &D_800B8060_usa;
            var_s1_2 = &D_800B8048_usa;
            var_a1_4 = &D_800B8030_usa;
            do {
                if (var_t1_2 != 6) {
                    if (var_t1_2 < 7) {
                        if (var_t1_2 != 5) {
                            var_t9_2 += 0xC;
                        } else {
                            temp_a0_7 = *(var_a1_4 + var_t2);
                            if (temp_a0_7 != -1) {
                                temp_v1_15 = (temp_a0_7 * 0x318) + well;
                                if ((temp_v1_15->unk_24C != 0) && (temp_v1_15->unk_240 != -2)) {
                                    var_v0_8 = temp_a0_7 * 8;
                                    if ((temp_v1_15->unk_220 == 0) || (var_v0_8 = temp_a0_7 * 8, (temp_v1_15->unk_214 == -2))) {
                                        (well + ((var_v0_8 + temp_a0_7) * 2))->unk_3FBD = 2;
                                    } else {
                                        (well + (temp_a0_7 * 0x12))->unk_3FBD = 1;
                                    }
                                }
                                if (temp_t3 > 0) {
                                    temp_v1_16 = (temp_a0_7 * 0x318) + well;
                                    var_v0_9 = temp_a0_7 * 2;
                                    if (temp_v1_16->unk_220 != 0) {
                                        if (temp_v1_16->unk_214 != -2) {
                                            (well + (temp_a0_7 * 0x12))->unk_3FBC = 2;
                                        }
                                        var_v0_9 = temp_a0_7 * 2;
                                    }
                                    temp_v1_17 = ((var_v0_9 + temp_a0_7) * 0x108) + well;
                                    if ((temp_v1_17->unk_1F4 != 0) && (temp_v1_17->unk_1E8 != -2)) {
                                        (well + (temp_a0_7 * 0x12))->unk_3FBB = 2;
                                    }
                                } else if (temp_t3 < 0) {
                                    temp_v1_18 = (temp_a0_7 * 0x318) + well;
                                    var_v0_10 = temp_a0_7 * 2;
                                    if (temp_v1_18->unk_278 != 0) {
                                        if (temp_v1_18->unk_26C != -2) {
                                            (well + (temp_a0_7 * 0x12))->unk_3FBE = 1;
                                        }
                                        var_v0_10 = temp_a0_7 * 2;
                                    }
                                    temp_v1_19 = ((var_v0_10 + temp_a0_7) * 0x108) + well;
                                    if ((temp_v1_19->unk_2A4 != 0) && (temp_v1_19->unk_298 != -2)) {
                                        (well + (temp_a0_7 * 0x12))->unk_3FBF = 2;
                                    }
                                }
                            }
                            goto block_210;
                        }
                    } else if (var_t1_2 != 7) {
                        if (var_t1_2 != 8) {
                            var_t9_2 += 0xC;
                        } else {
                            temp_a0_8 = *(var_t9_2 + var_t2);
                            if (temp_a0_8 != -1) {
                                temp_v1_20 = (temp_a0_8 * 0x318) + well;
                                if ((temp_v1_20->unk_19C != 0) && (temp_v1_20->unk_190 != -2)) {
                                    var_v0_11 = temp_a0_8 * 8;
                                    if ((temp_v1_20->unk_170 == 0) || (var_v0_11 = temp_a0_8 * 8, (temp_v1_20->unk_164 == -2))) {
                                        (well + ((var_v0_11 + temp_a0_8) * 2))->unk_3FB9 = 2;
                                    } else {
                                        (well + (temp_a0_8 * 0x12))->unk_3FB9 = 1;
                                    }
                                }
                            }
                            goto block_210;
                        }
                    } else {
                        temp_a0_9 = *(var_s2_2 + var_t2);
                        if (temp_a0_9 != -1) {
                            temp_v1_21 = (temp_a0_9 * 0x318) + well;
                            if ((temp_v1_21->unk_1C8 != 0) && (temp_v1_21->unk_1BC != -2)) {
                                var_v0_12 = temp_a0_9 * 8;
                                if ((temp_v1_21->unk_19C == 0) || (var_v0_12 = temp_a0_9 * 8, (temp_v1_21->unk_190 == -2))) {
                                    (well + ((var_v0_12 + temp_a0_9) * 2))->unk_3FBA = 2;
                                } else {
                                    (well + (temp_a0_9 * 0x12))->unk_3FBA = 1;
                                }
                            }
                            if ((temp_t3 <= 0) && (temp_t3 < 0)) {
                                temp_v1_22 = (temp_a0_9 * 0x318) + well;
                                var_v0_13 = temp_a0_9 * 2;
                                if (temp_v1_22->unk_1F4 != 0) {
                                    if (temp_v1_22->unk_1E8 != -2) {
                                        (well + (temp_a0_9 * 0x12))->unk_3FBB = 2;
                                    }
                                    var_v0_13 = temp_a0_9 * 2;
                                }
                                temp_v1_23 = ((var_v0_13 + temp_a0_9) * 0x108) + well;
                                if ((temp_v1_23->unk_220 != 0) && (temp_v1_23->unk_214 != -2)) {
                                    (well + (temp_a0_9 * 0x12))->unk_3FBC = 2;
                                }
                            }
                        }
                        goto block_210;
                    }
                } else {
                    temp_a0_10 = *(var_s1_2 + var_t2);
                    if (temp_a0_10 != -1) {
                        temp_v1_24 = (temp_a0_10 * 0x318) + well;
                        if ((temp_v1_24->unk_1F4 != 0) && (temp_v1_24->unk_1E8 != -2)) {
                            var_v0_14 = temp_a0_10 * 8;
                            if ((temp_v1_24->unk_1C8 == 0) || (var_v0_14 = temp_a0_10 * 8, (temp_v1_24->unk_1BC == -2))) {
                                (well + ((var_v0_14 + temp_a0_10) * 2))->unk_3FBB = 2;
                            } else {
                                (well + (temp_a0_10 * 0x12))->unk_3FBB = 1;
                            }
                        }
                        if (temp_t3 > 0) {
                            temp_v1_25 = (temp_a0_10 * 0x318) + well;
                            if ((temp_v1_25->unk_1C8 != 0) && (temp_v1_25->unk_1BC != -2)) {
                                (well + (temp_a0_10 * 0x12))->unk_3FBA = 2;
                            }
                        } else if (temp_t3 < 0) {
                            temp_v1_26 = (temp_a0_10 * 0x318) + well;
                            var_v0_15 = temp_a0_10 * 2;
                            if (temp_v1_26->unk_24C != 0) {
                                if (temp_v1_26->unk_240 != -2) {
                                    (well + (temp_a0_10 * 0x12))->unk_3FBD = 2;
                                }
                                var_v0_15 = temp_a0_10 * 2;
                            }
                            temp_v1_27 = ((var_v0_15 + temp_a0_10) * 0x108) + well;
                            if ((temp_v1_27->unk_278 != 0) && (temp_v1_27->unk_26C != -2)) {
                                (well + (temp_a0_10 * 0x12))->unk_3FBE = 1;
                            }
                        }
                    }
block_210:
                    var_t9_2 += 0xC;
                }
                var_s2_2 += 0xC;
                var_s1_2 += 0xC;
                var_a2_4 += 1;
                var_a1_4 += 0xC;
            } while (var_a2_4 < 2);
            goto block_212;
        }
        if (var_t5_2->unk_-1C != 0) {
            if (var_t5_2->unk_-28 != -2) {
                *var_s4_2 = 1;
            } else {
                goto block_113;
            }
        } else {
block_113:
            *var_s4_2 = 2;
        }
        if (var_t1_2 != 6) {
            if (var_t1_2 != 7) {
                var_s4_2 -= 1;
            } else {
                var_a2_5 = 0;
                if (var_t4->block[0][8].type != BLOCKTYPE_0) {
                    if (var_t4->block[0][8].delay == -2) {
                        var_a2_5 = 0;
                        goto block_130;
                    }
                    goto block_212;
                }
block_130:
                var_a1_5 = &D_800B8060_usa;
                do {
                    temp_a0_11 = *(var_a1_5 + var_t2);
                    if (temp_a0_11 != -1) {
                        temp_v1_28 = (temp_a0_11 * 0x318) + well;
                        if ((temp_v1_28->unk_1C8 != 0) && (temp_v1_28->unk_1BC != -2)) {
                            (well + (temp_a0_11 * 0x12))->unk_3FBA = 4;
                        }
                    }
                    var_a2_5 += 1;
                    var_a1_5 += 0xC;
                } while (var_a2_5 < 2);
                var_s4_2 -= 1;
            }
        } else {
            var_a2_6 = 0;
            if (var_t4->block[0][7].type != BLOCKTYPE_0) {
                if (var_t4->block[0][7].delay == -2) {
                    var_a2_6 = 0;
                    goto block_120;
                }
block_212:
                var_s4_2 -= 1;
            } else {
block_120:
                var_a1_6 = &D_800B8048_usa;
                do {
                    temp_a0_12 = *(var_a1_6 + var_t2);
                    if (temp_a0_12 != -1) {
                        temp_v1_29 = (temp_a0_12 * 0x318) + well;
                        if ((temp_v1_29->unk_1F4 != 0) && (temp_v1_29->unk_1E8 != -2)) {
                            (well + (temp_a0_12 * 0x12))->unk_3FBB = 4;
                        }
                    }
                    var_a2_6 += 1;
                    var_a1_6 += 0xC;
                } while (var_a2_6 < 2);
                var_s4_2 -= 1;
            }
        }
        var_t1_2 -= 1;
        var_t5_2 -= 0x2C;
        if (var_t1_2 >= 5) {
            goto loop_103;
        }
        if ((var_t4->block[0][4].type == BLOCKTYPE_0) || (var_t4->block[0][4].delay == -2) || (var_t4->block[0][3].type == BLOCKTYPE_0) || (var_t4->block[0][3].delay == -2)) {
            var_a2_7 = 0;
            var_a1_7 = &D_800B8030_usa;
            do {
                temp_a0_13 = *(var_a1_7 + var_t2);
                if (temp_a0_13 != -1) {
                    temp_v1_30 = (temp_a0_13 * 0x318) + well;
                    if ((temp_v1_30->unk_2A4 != 0) && (temp_v1_30->unk_298 != -2)) {
                        var_v0_16 = temp_a0_13 * 8;
                        if ((temp_v1_30->unk_2D0 == 0) || (var_v0_16 = temp_a0_13 * 8, (temp_v1_30->unk_2C4 == -2))) {
                            (well + ((var_v0_16 + temp_a0_13) * 2))->unk_3FBF = 3;
                        } else {
                            (well + (temp_a0_13 * 0x12))->unk_3FBF = 1;
                        }
                    }
                }
                var_a2_7 += 1;
                var_a1_7 += 0xC;
            } while (var_a2_7 < 2);
        }
        if ((var_t4->block[0][5].type == BLOCKTYPE_0) || (var_t4->block[0][5].delay == -2) || (var_t4->block[0][6].type == BLOCKTYPE_0) || (var_t4->block[0][6].delay == -2)) {
            var_a2_8 = 0;
            var_a1_8 = &D_800B8030_usa;
            do {
                temp_a0_14 = *(var_a1_8 + var_t2);
                if (temp_a0_14 != -1) {
                    temp_v1_31 = (temp_a0_14 * 0x318) + well;
                    if ((temp_v1_31->unk_220 != 0) && (temp_v1_31->unk_214 != -2)) {
                        var_v0_17 = temp_a0_14 * 8;
                        if ((temp_v1_31->unk_1F4 == 0) || (var_v0_17 = temp_a0_14 * 8, (temp_v1_31->unk_1E8 == -2))) {
                            (well + ((var_v0_17 + temp_a0_14) * 2))->unk_3FBC = 2;
                        } else {
                            (well + (temp_a0_14 * 0x12))->unk_3FBC = 1;
                        }
                    }
                }
                var_a2_8 += 1;
                var_a1_8 += 0xC;
            } while (var_a2_8 < 2);
        }
        if (var_s6->visible[0][4] != 0) {
            var_s6->visible[0][4] = 1;
        }
        if (var_s6->visible[0][5] != 0) {
            var_s6->visible[0][5] = 1;
        }
        var_s6 += 0x12;
        var_t2 += 1;
        var_t4 += 0x318;
    } while (var_t2 < 0xC);
    temp_v1_32 = sp14->sy;
    if (temp_v1_32 != -1) {
        (well + (temp_v1_32 * 0x12))->unk_3FB4 = 0;
        (well + (sp14->sy * 0x12))->unk_3FB5 = 0;
        temp_v1_33 = well + (sp14->sy * 0x12);
        if (temp_v1_33->unk_3FB3 != 0) {
            temp_v1_33->unk_3FB3 = 3;
        }
        temp_a0_15 = well + (sp14->sy * 0x12);
        if (temp_a0_15->unk_3FB6 != 0) {
            temp_a0_15->unk_3FB6 = 2;
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/update3d", Check3DVisibleBlocks);
#endif
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
