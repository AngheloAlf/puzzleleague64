/**
 * Original filename: combo.c
 */

#include "combo.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "attack.h"
#include "combo2d.h"
#include "combo3d.h"
#include "dlist.h"
#include "init2d.h"
#include "sfxlimit.h"
#include "the_game.h"

void CheckCollision(tetWell *well) {
    CheckRowCombos(well);
    CheckColCombos(well);
    if (gTheGame.unk_9C0C == 2) {
        Check3DConnectCombos(well);
    }
}

void CompactWell(tetWell *well, s32 num) {
    s32 check[2 * 10]; // GAME_BUFFER_LEN * 10 ?
    block_t *bot_block;
    block_t *top_block;
    s32 row;
    s32 col;
    s32 sp6C = 0;
    s32 sp74;
    s32 temp_v0_2;

    bzero(check, sizeof(s32) * 2 * 10);

    for (row = 0; row < BLOCK_LEN_ROWS - 1; row++) {
        for (col = 0; col < gMax; col++) {
            sp74 = row - 1;
            bot_block = &well->block[row][col];
            top_block = &well->block[row + 1][col];
            if ((bot_block->type == BLOCKTYPE_0) && (top_block->type != BLOCKTYPE_0)) {
                if (top_block->type == BLOCKTYPE_9) {
                    temp_v0_2 = ReturnAttackSlot(well, row + 1, col);
                    if (temp_v0_2 != -1) {
                        if (check[temp_v0_2] == 0) {
                            if (gTheGame.unk_9C0C == 1) {
                                Compact2DAttack(well, temp_v0_2);
                                check[temp_v0_2] = -1;
                            } else {
                                Compact3DAttack(well, temp_v0_2);
                                check[temp_v0_2] = -1;
                            }
                        }
                    }
                } else if (top_block->delay == 0) {
                    if ((top_block->state != BLOCKSTATE_1) && (top_block->state != BLOCKSTATE_6)) {
                        if (((bot_block->state == BLOCKSTATE_2) || (bot_block->state == BLOCKSTATE_3))) {
                            continue;
                        }
                    }

                    if ((top_block->state != BLOCKSTATE_2) && (top_block->state != BLOCKSTATE_3)) {
                        if ((top_block->state == BLOCKSTATE_5) || (top_block->state == BLOCKSTATE_6)) {
                            top_block->state = BLOCKSTATE_1;
                        }

                        bcopy(top_block, bot_block, sizeof(block_t));
                        Init2DTetrisTMEM(bot_block, &well->unk_3830[row][col]);
                        InitTetrisState(top_block);

                        if (row != 0) {
                            if ((well->block[sp74][col].state == BLOCKSTATE_1) ||
                                (well->block[sp74][col].type == BLOCKTYPE_0)) {
                                bot_block->state = BLOCKSTATE_1;
                            } else if (well->block[sp74][col].type == BLOCKTYPE_9) {
                                temp_v0_2 = ReturnAttackSlot(well, sp74, col);
                                if ((temp_v0_2 != -1) && (well->attack[temp_v0_2].state != ATTACKSTATE_6)) {
                                    sp6C = -1;
                                }
                            } else {
                                sp6C = -1;
                            }
                        } else {
                            well->unk_43C4 = -1;
                            sp6C = -1;
                        }
                    }
                }
            } else if ((bot_block->type != BLOCKTYPE_0) && (top_block->type != BLOCKTYPE_0)) {
                if (row == 0) {
                    if ((bot_block->state == BLOCKSTATE_1) || (bot_block->state == BLOCKSTATE_6)) {
                        bot_block->state = BLOCKSTATE_0;
                        well->unk_43C4 = -1;
                    }
                }

                if (top_block->type != BLOCKTYPE_9) {
                    if ((top_block->state != BLOCKSTATE_0) && (top_block->delay == 0)) {
                        if ((top_block->state == BLOCKSTATE_1) || (top_block->state == BLOCKSTATE_5) ||
                            (top_block->state == BLOCKSTATE_6)) {
                            switch (bot_block->state) {
                                case BLOCKSTATE_5:
                                    top_block->state = BLOCKSTATE_5;
                                    break;
                                case BLOCKSTATE_6:
                                    top_block->state = BLOCKSTATE_5;
                                    top_block->chain_flag = -1;
                                    break;
                                default:
                                    top_block->state = BLOCKSTATE_0;
                                    well->unk_43C4 = -1;
                                    break;
                            }
                        }
                    }
                }
            } else if (row == 0) {
                if ((bot_block->state == BLOCKSTATE_1) || (bot_block->state == BLOCKSTATE_6)) {
                    bot_block->state = BLOCKSTATE_0;
                    well->unk_43C4 = -1;
                }
            }
        }
    }

    if (sp6C != 0) {
        if (gTheGame.unk_9C08 == 1) {
            PlaySE(SFX_INIT_TABLE, 0xA9);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, 0xAA);
        } else {
            PlaySE(SFX_INIT_TABLE, 0xAB);
        }
    }

    if (gTheGame.unk_9C08 != 1) {
        for (col = 0; col < gMax; col++) {
            if (well->block[BLOCK_LEN_ROWS - 1][col].type != BLOCKTYPE_0) {
                break;
            }
        }

        if (gTheGame.unk_9C0C == 1) {
            // Use TETWELL_OBJSPRITE_LEN_B instead?
            if (col == BLOCK_LEN_B / 3) {
                Compact2DAttackNoWhere(well);
            }
        } else if (col == BLOCK_LEN_B) {
            Compact3DAttackNoWhere(well);
        }
    }
}

void CheckIcon(tetWell *well, s32 total) {
    icon_t *icon;
    s32 var_t2 = 0;
    nbool var_t9 = ntrue;
    nbool var_t6 = nfalse;
    nbool var_t5 = nfalse;
    s32 var_a3_2;
    s32 var_t1;
    s32 var_t4;

#if 0
    int count; // r12
    int special; // r31
    int left; // r7
    int top; // r8
    int bonus; // r9
    int clear_chain; // r5
    int clear_combo; // r10
#endif

    if (total == 0) {
        return;
    }

    var_t4 = gMax;

    for (var_t1 = 0; var_t1 < ICON_COUNT; var_t1++) {
        if ((well->icon[var_t1].flag != 0) && (well->icon[var_t1].count < 0)) {
            icon = &well->icon[var_t1];

            if (var_t2 < icon->to_y) {
                var_t2 = icon->to_y;
                var_t4 = icon->from_x;
            }

            if ((icon->from_x < var_t4) && (icon->to_y >= var_t2)) {
                var_t2 = icon->to_y;
                var_t4 = icon->from_x;
            }
        }
    }

    if ((total != well->unk_43A4)) {
        if (total == 3) {
            var_t5 = ntrue;
        }
    }

    for (var_t1 = 0; var_t1 < ICON_COUNT; var_t1++) {
        if ((well->icon[var_t1].flag == 0) || (well->icon[var_t1].type != ICONTYPE_10) ||
            (well->icon[var_t1].count >= 0)) {
            continue;
        }

        icon = &well->icon[var_t1];

        if (!var_t6) {
            icon->count = -total;
            if (total >= 4) {
                var_t5 = ntrue;
            }

            icon->from_x = var_t4;
            icon->to_y = var_t2;
            var_t6 = ntrue;

            if ((well->unk_43B4 != 0) && (gTheGame.unk_9C08 == 1) && !(gGameStatus & 0x20)) {
                for (var_a3_2 = 0; var_a3_2 < ICON_COUNT; var_a3_2++) {
                    if (well->icon[var_a3_2].flag == 0) {
                        well->icon[var_a3_2].flag = -1;
                        well->icon[var_a3_2].type = ICONTYPE_11;
                        well->icon[var_a3_2].count = -1;
                        well->icon[var_a3_2].from_x = var_t4;
                        well->icon[var_a3_2].to_y = var_t2;
                        break;
                    }
                }
            }
        } else {
            icon->flag = 0;
        }
    }

    for (var_t1 = 0; var_t1 < ICON_COUNT; var_t1++) {
        if ((well->icon[var_t1].flag == 0) || (well->icon[var_t1].type != ICONTYPE_12) ||
            (well->icon[var_t1].count >= 0)) {
            continue;
        }

        icon = &well->icon[var_t1];
        if (var_t9) {
            var_a3_2 = ~well->unk_43A8;
            if (well->unk_43A8 < 0) {
                var_t9 = nfalse;
                if (var_a3_2 >= ARRAY_COUNT(D_800B6CC4_usa)) {
                    var_a3_2 = ARRAY_COUNT(D_800B6CC4_usa) - 1;
                }
                well->unk_43AC += D_800B6CC4_usa[var_a3_2];
            }
        }

        if (!var_t5) {
            icon->count = -total;
            icon->from_x = var_t4;
            icon->to_y = var_t2;
            var_t5 = ntrue;

            if ((well->unk_43B4 != 0) && (total != 3) && (gTheGame.unk_9C08 == 1) && !(gGameStatus & 0x20)) {
                for (var_a3_2 = 0; var_a3_2 < ICON_COUNT; var_a3_2++) {
                    if (well->icon[var_a3_2].flag == 0) {
                        well->icon[var_a3_2].flag = -1;
                        well->icon[var_a3_2].type = ICONTYPE_11;
                        well->icon[var_a3_2].count = -1;
                        well->icon[var_a3_2].from_x = var_t4;
                        well->icon[var_a3_2].to_y = var_t2;
                        break;
                    }
                }
            }
        } else {
            icon->flag = 0;
        }
    }
}

void CheckRowCombos(tetWell *well) {
    s32 row;
    s32 col;

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        BlockType type = BLOCKTYPE_0;
        s32 count = 1;

        for (col = 0; col < gMax; col++) {
            block_t *block = &well->block[row][col];

            if (((block->type != BLOCKTYPE_0) && (block->type < BLOCKTYPE_8)) && (block->type == type) &&
                ((block->delay == 0))) {
                if ((block->state == BLOCKSTATE_0) || (block->state == BLOCKSTATE_4) ||
                    (block->state == BLOCKSTATE_7)) {
                    count++;
                    continue;
                }
            }

            if (count >= 3) {
                SetRowState(well, count, row, col - 1);
            }

            type = BLOCKTYPE_0;
            if ((block->type != BLOCKTYPE_0) && (block->type < BLOCKTYPE_8) && (block->delay == 0)) {
                if ((block->state == BLOCKSTATE_0) || (block->state == BLOCKSTATE_4) ||
                    (block->state == BLOCKSTATE_7)) {
                    type = block->type;
                }
            }
            count = 1;
        }

        if (count >= 3) {
            SetRowState(well, count, row, col - 1);
        }
    }
}

void CheckColCombos(tetWell *well) {
    s32 row;
    s32 col;

    for (col = 0; col < gMax; col++) {
        BlockType type = BLOCKTYPE_0;
        s32 count = 1;

        for (row = 0; row < BLOCK_LEN_ROWS; row++) {
            block_t *block = &well->block[row][col];

            if (((block->type != BLOCKTYPE_0) & (block->type < BLOCKTYPE_8)) && (block->type == type) &&
                (block->delay == 0)) {
                if ((block->state == BLOCKSTATE_0) || (block->state == BLOCKSTATE_4) ||
                    (block->state == BLOCKSTATE_7)) {
                    count++;
                    continue;
                }
            }

            if (count >= 3) {
                SetColState(well, count, row - 1, col);
            }

            type = BLOCKTYPE_0;
            if ((block->type != BLOCKTYPE_0) && (block->type < BLOCKTYPE_8) && (block->delay == 0)) {
                if (((block->state == BLOCKSTATE_0) || (block->state == BLOCKSTATE_4)) ||
                    (block->state == BLOCKSTATE_7)) {
                    type = block->type;
                }
            }

            count = 1;
        }

        if (count >= 3) {
            SetColState(well, count, row - 1, col);
        }
    }
}

void SetRowState(tetWell *well, s32 count, s32 row, s32 col) {
    icon_t *icon = NULL;
    s32 bomb = 0x1E;
    s32 sound = 0x64;
    IconType kind = ICONTYPE_12;
    block_t *block;
    s32 i;

    for (i = 0; i < count; i++) {
        if (well->block[row][col - i].chain_flag != 0) {
            kind = ICONTYPE_10;
        }
    }

    if (count >= 6) {
        bomb = 0x1F;
    }

    if (kind != ICONTYPE_12) {
        i = well->unk_43A8;
        if (i < -1) {
            bomb = 0x21;
            sound = 0x190;
        } else if (i == -1) {
            bomb = 0x20;
            sound = 0x12C;
        } else {
            bomb = 0x1F;
            sound = 0xC8;
        }
    }

    for (i = 0; i < ICON_COUNT; i++) {
        if (well->icon[i].flag == 0) {
            icon = &well->icon[i];
            break;
        }
    }

    for (i = 0; i < count; i++) {
        block = &well->block[row][col - i];

        block->state = BLOCKSTATE_7;
        block->bomb = bomb;
        block->sound = sound;
        if (kind == ICONTYPE_10) {
            block->chain_flag = -1;
        }
    }

    if (icon != NULL) {
        icon->type = kind;
        icon->flag = -1;
        icon->from_x = col - (count - 1);
        icon->count = -count;
        icon->from_y = row;
        icon->to_x = col;
        icon->to_y = row;

        if (well->block[row][col].type == BLOCKTYPE_7) {
            well->unk_43A4 += count;
        }
    }
}

void SetColState(tetWell *well, s32 count, s32 row, s32 col) {
    icon_t *icon = NULL;
    s32 bomb = 0x1E;
    s32 sound = 0x64;
    IconType kind = ICONTYPE_12;
    block_t *block;
    s32 i;

    for (i = 0; i < count; i++) {
        if (well->block[row - i][col].chain_flag != 0) {
            kind = ICONTYPE_10;
        }
    }

    if (count >= 6) {
        bomb = 0x1F;
    }

    if (kind != ICONTYPE_12) {
        i = well->unk_43A8;
        if (i < -1) {
            bomb = 0x21;
            sound = 0x190;
        } else if (i == -1) {
            bomb = 0x20;
            sound = 0x12C;
        } else {
            bomb = 0x1F;
            sound = 0xC8;
        }
    }

    for (i = 0; i < ICON_COUNT; i++) {
        if (well->icon[i].flag == 0) {
            icon = &well->icon[i];
            break;
        }
    }

    for (i = 0; i < count; i++) {
        block = &well->block[row - i][col];

        block->state = BLOCKSTATE_7;
        block->bomb = bomb;
        block->sound = sound;
        if (kind == ICONTYPE_10) {
            block->chain_flag = -1;
        }
    }

    if (icon != NULL) {
        icon->type = kind;
        icon->flag = -1;
        icon->from_y = row - (count - 1);
        icon->count = -count;
        icon->from_x = col;
        icon->to_x = col;
        icon->to_y = row;

        if (well->block[row][col].type == BLOCKTYPE_7) {
            well->unk_43A4 += count;
        }
    }
}

void CheckChainCounter(tetWell *well, cursor_t *cursor UNUSED) {
    s32 row;
    s32 col;

    if ((well->unk_43C0 != 0) || (well->unk_43A8 == 0)) {
        return;
    }

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        for (col = 0; col < gMax; col++) {
            block_t *block = &well->block[row][col];

            if ((block->state == BLOCKSTATE_4) || (block->state == BLOCKSTATE_5) || (block->state == BLOCKSTATE_1)) {
                return;
            }
            if ((block->state != BLOCKSTATE_9) && (block->chain_flag != 0)) {
                return;
            }
        }
    }

    well->unk_43A8 = 0;
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
s32 ComboCount(tetWell *well, cursor_t *cursor) {
    s32 var_t1;
    s32 var_t2;
    block_t *var_a2;
    block_t *var_a3;
    s32 temp;
    s32 temp2;
    s32 temp3;

    block_t *a;
    block_t *b;

    s32 col;

    var_t2 = 0;
    temp2 = well->unk_43C8;
    for (var_t1 = 0; var_t1 < BLOCK_LEN_ROWS; var_t1++) {
        a = well->block[var_t1];
        b = well->block[var_t1 - 1];
        temp3 = (gGameStatus & 0x40) ? 9 : 12;

        for (col = 0; col < gMax; col++) {
            if (a[col].state == 7) {
                a[col].delay = temp2;
                var_t2++;
            }

            if ((a[col].type != 0) && (a[col].type < 9) && (a[col].delay > 0)) {
                a[col].delay--;

                if ((well->unk_43BC != 0) && (a[col].state == 9)) {
                    a[col].state = 6;
                    a[col].chain_flag = -1;
                    a[col].frame_n = temp3;
                    a[col].frame_d = 3;
                }
            }

            if ((a[col].state == 0) || (a[col].state == 4)) {
                if (a[col].chain_flag != 0) {
                    if (var_t1 == 0) {
                        a[col].chain_flag = 0;
                    } else if (b[col].type != 0) {
                        if ((b[col].state < 1) || (b[col].state > 6)) {
                            a[col].chain_flag = 0;
                        }
                    }
                }
            }
        }
    }

    if ((gSelection == 0x6E) && (var_t2 != 0)) {
        cursor->unk_2C = var_t2;
    }

    return var_t2;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/combo", ComboCount);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo", ComboCount);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo", ComboCount);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo", ComboCount);
#endif
