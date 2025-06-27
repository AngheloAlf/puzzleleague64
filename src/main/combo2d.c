/**
 * Original filename: combo2d.c
 */

#include "combo2d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "dlist.h"
#include "init2d.h"
#include "tetwell.h"

void Compact2DAttackNoWhere(tetWell *well) {
    s32 count;

    for (count = 0; count < ATTACK_COUNT; count++) {
        if ((well->attack[count].state >= ATTACKSTATE_7) && (well->attack[count].unk_24 == 0xC)) {
            Compact2DAttack(well, count);
        }
    }
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
void Compact2DAttack(tetWell *well, s32 count) {
    attack_t *temp_s3;

    block_t *temp_s0;
    s32 temp_a1;
    s32 temp_a1_3;
    s32 var_a2;
    s32 var_s1;
    s32 var_s5; // pos?
    s32 var_s6; // lev?
    block_t *temp_a0;
    block_t *temp_a1_4;
    s32 temp2;

#if 0
    int lev; // r29
    int row; // r1+0x8
    int col; // r5
    int pos; // r28
    int skip; // r6
    struct block_t * top_block; // r23
    struct block_t * bot_block; // r4
    struct attack_t * attack; // r1+0x8
#endif

    temp_s3 = &well->attack[count];
    temp_a1 = temp_s3->unk_24;
    var_a2 = 0;
    if (temp_a1 < BLOCK_LEN_ROWS) {
        for (var_s1 = temp_s3->start; var_s1 < temp_s3->unk_1C; var_s1++) {
            temp_a0 = &well->block[temp_a1][var_s1];
            if (temp_a0->delay != 0) {
                temp_a0->delay--;
                var_a2 = -1;
            }
        }
    }

    if (var_a2 != 0) {
        return;
    }

    if (temp_s3->unk_24 < 1) {
        return;
    }

    temp_a1 = temp_s3->unk_24 - 1;
    for (var_s1 = temp_s3->start; var_s1 < temp_s3->unk_1C; var_s1++) {
        temp_a0 = &well->block[temp_a1][var_s1];
        if ((temp_a0->type != BLOCKTYPE_0) || (temp_a0->state == BLOCKSTATE_2) || (temp_a0->state == BLOCKSTATE_3)) {
            break;
        }
    }

    if (var_s1 != temp_s3->unk_1C) {
        return;
    }

    for (var_s6 = 0; var_s6 < temp_s3->unk_14; var_s6++) {
        var_s5 = 0;

        if (temp_s3->unk_24 + var_s6 < BLOCK_LEN_ROWS) {
            temp_a1 = temp_s3->unk_24 + var_s6 - 1;
            for (var_s1 = temp_s3->start; var_s1 < temp_s3->unk_1C; var_s1++) {
                temp_a1_4 = &well->block[temp_a1][var_s1];
                temp_s0 = &well->block[temp_s3->unk_24 + var_s6][var_s1];

                bcopy(temp_s0, temp_a1_4, sizeof(block_t));
                Init2DAttackTMEM(&well->unk_3830[temp_a1][var_s1], temp_s3->type, var_s6, var_s5);
                var_s5++;
                InitTetrisState(temp_s0);
            }
        } else if (temp_s3->unk_24 + var_s6 == BLOCK_LEN_ROWS) {
            temp_a1 = BLOCK_LEN_ROWS - 1;
            for (var_s1 = temp_s3->start; var_s1 < temp_s3->unk_1C; var_s1++) {
                well->block[temp_a1][var_s1].type = BLOCKTYPE_9;

                Init2DAttackTMEM(&well->unk_3830[temp_a1][var_s1], temp_s3->type, var_s6, var_s5);
                var_s5++;
            }
        } else if (temp_s3->unk_24 + var_s6 > BLOCK_LEN_ROWS) {
            break;
        }
    }

    temp_s3->unk_24--;
    if (temp_s3->state != ATTACKSTATE_5) {
        temp_s3->state = ATTACKSTATE_6;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/combo2d", Compact2DAttack);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo2d", Compact2DAttack);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo2d", Compact2DAttack);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo2d", Compact2DAttack);
#endif
