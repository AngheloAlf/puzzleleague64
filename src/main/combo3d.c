/**
 * Original filename: combo3d.c
 */

#include "combo3d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "dlist.h"
#include "tetwell.h"

#if VERSION_USA
void Compact3DAttackNoWhere(tetWell *well) {
    s32 i;

    for (i = 0; i < ATTACK_COUNT; i++) {
        if ((well->attack[i].state >= ATTACKSTATE_7) && (well->attack[i].unk_24 == 0xC)) {
            Compact3DAttack(well, i);
        }
    }
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo3d", Compact3DAttackNoWhere);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo3d", Compact3DAttackNoWhere);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo3d", Compact3DAttackNoWhere);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/combo3d", Compact3DAttack);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo3d", Compact3DAttack);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo3d", Compact3DAttack);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo3d", Compact3DAttack);
#endif

#if VERSION_USA
#if 0
void Check3DConnectCombos(tetWell *well) {
    block_t *var_a1;
    s32 temp_a2;  // type
    s32 var_a2;   // left
    s32 var_a3_2; // right
    s32 var_s0;   // row
    s32 var_t0;   // count

    for (var_s0 = 0; var_s0 < 0xC; var_s0++) {
        var_a1 = &well->block[var_s0][0];
        temp_a2 = var_a1->type;
        if ((temp_a2 == 0) || (var_a1->delay != 0)) {
            continue;
        }

        if ((var_a1->state == 0) || (var_a1->state == 4) || (var_a1->state == 7)) {
            var_t0 = 1;

            for (var_a2 = 1; var_a2 < 0x12; var_a2++, var_t0++) {
                var_a1 = &well->block[var_s0][var_a2];
                if ((var_a1->type == 0) || (var_a1->type >= 8) || (var_a1->type != temp_a2) || (var_a1->delay != 0) ||
                    ((var_a1->state != 0) && (var_a1->state != 4) && (var_a1->state != 7))) {

                    for (var_a3_2 = 0x11; var_a3_2 > var_a2; var_a3_2--, var_t0++) {
                        var_a1 = &well->block[var_s0][var_a3_2];

                        if (((var_a1->type == BLOCKTYPE_0) || (var_a1->type >= 8)) || (var_a1->type != temp_a2) ||
                            ((var_a1->delay != 0)) ||
                            ((var_a1->state != BLOCKSTATE_0) && (var_a1->state != BLOCKSTATE_4) &&
                             (var_a1->state != BLOCKSTATE_7))) {

                            if (var_t0 >= 3) {
                                Set3DRowConnectState(well, var_s0, var_a2, var_a3_2);
                            }
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/combo3d", Check3DConnectCombos);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo3d", Check3DConnectCombos);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo3d", Check3DConnectCombos);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo3d", Check3DConnectCombos);
#endif

void Set3DRowConnectState(tetWell *well, s32 row, s32 left, s32 right) {
    s32 bomb = 0x1E;
    s32 sound = 0x64;
    BlockType kind = BLOCKTYPE_12;
    icon_t *icon = NULL;
    block_t *block;
    s32 count;
    s32 i;

    for (i = 0; i < left; i++) {
        if (well->block[row][i].chain_flag != 0) {
            kind = BLOCKTYPE_10;
        }
    }

    right++;
    for (i = right; i < BLOCK_LEN_B; i++) {
        if (well->block[row][i].chain_flag != 0) {
            kind = BLOCKTYPE_10;
        }
    }

    count = left - (right - BLOCK_LEN_B);
    if (count >= 6) {
        bomb = 0x1F;
    }

    if (kind != BLOCKTYPE_12) {
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

    for (i = 0; i < left; i++) {
        block = &well->block[row][i];

        block->state = BLOCKSTATE_7;
        block->bomb = bomb;
        block->sound = sound;
        if (kind == BLOCKTYPE_10) {
            block->chain_flag = -1;
        }
    }

    for (i = right; i < BLOCK_LEN_B; i++) {
        block = &well->block[row][i];
        block->state = 7;
        block->bomb = bomb;
        block->sound = sound;
        if (kind == BLOCKTYPE_10) {
            block->chain_flag = -1;
        }
    }

    if (icon != NULL) {
        icon->flag = -1;
        icon->to_x = left - 1;
        icon->count = -count;
        icon->type = kind;
        icon->from_x = right;
        icon->from_y = row;
        icon->to_y = row;
        if (well->block[row][0].type == BLOCKTYPE_7) {
            well->unk_43A4 += count;
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/combo3d", func_800666F0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo3d", func_800669C0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo3d", func_80065100_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo3d", func_800652B0_ger);
#endif
