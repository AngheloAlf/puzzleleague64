/**
 * Original filename: animate2d.c
 */

#include "animate2d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "animate.h"
#include "animation.h"
#include "init2d.h"
#include "sfxlimit.h"
#include "update.h"

// TODO REGION_NTSC?
#if VERSION_USA
#define HOLD_VAL 10
#else
#define HOLD_VAL 8
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate2d", Input2D);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate2d", Input2D);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate2d", Input2D);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate2d", Input2D);
#endif

s32 Move2DCursorUp(tetWell *well, cursor_t *cursor, s32 hold) {
    s32 pixel;

    if (well->unk_43F8 == 0) {
        if (cursor->y < 11) {
            pixel = cursor->rect.s.objY >> 2;
            cursor->rect.s.objY = (pixel - 16) << 2;
            cursor->y++;

            if ((hold == HOLD_VAL) || (hold == 0)) {
                return -1;
            }
        }
    } else {
        if (cursor->y < 10) {
            pixel = cursor->rect.s.objY >> 2;
            cursor->rect.s.objY = (pixel - 16) << 2;
            cursor->y++;

            if ((hold == HOLD_VAL) || (hold == 0)) {
                return -1;
            }
        }
    }

    return 0;
}

s32 Move2DCursorDown(cursor_t *cursor, s32 hold) {
    s32 pixel;

    if (cursor->y > 0) {
        pixel = cursor->rect.s.objY >> 2;
        cursor->rect.s.objY = (pixel + 16) << 2;
        cursor->y--;
        if ((hold == HOLD_VAL) || (hold == 0)) {
            return -1;
        }
    }

    return 0;
}

s32 Move2DCursorLeft(cursor_t *cursor, s32 hold) {
    s32 pixel;

    if (cursor->x > 0) {
        pixel = cursor->rect.s.objX >> 2;
        cursor->rect.s.objX = (pixel - 18) << 2;
        cursor->x--;

        if ((hold == HOLD_VAL) || (hold == 0)) {
            return -1;
        }
    }

    return 0;
}

s32 Move2DCursorRight(cursor_t *cursor, s32 hold) {
    s32 pixel;

    // TODO: macro-ify
    if (cursor->x < 6 - 2) {
        pixel = cursor->rect.s.objX >> 2;
        cursor->rect.s.objX = (pixel + 0x12) << 2;
        cursor->x++;
        if ((hold == HOLD_VAL) || (hold == 0)) {
            return -1;
        }
    }
    return 0;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate2d", Switch2DBlocks);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate2d", Switch2DBlocks);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate2d", Switch2DBlocks);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate2d", Switch2DBlocks);
#endif

void Update2DSwitching(tetWell *well, cursor_t *cursor) {
    block_t *block1;
    block_t *block2;

    if (cursor->unk_1C == -1) {
        return;
    }

    if ((cursor->unk_04 == 2) || (cursor->unk_04 == 3)) {
        well->unk_3F98.s.objX -= 5 << 2;
        well->unk_3F80.s.objX += 5 << 2;
    } else {
        well->unk_3F98.s.objX -= 4 << 2;
        well->unk_3F80.s.objX += 4 << 2;
    }

    cursor->unk_04--;
    if (cursor->unk_04 == 0) {
        block1 = &well->block[cursor->unk_1C][cursor->unk_18];
        block2 = &well->block[cursor->unk_1C][cursor->unk_18 + 1];
        if (block1->type != BLOCKTYPE_0) {
            Init2DTetrisTMEM(block1, &well->unk_3830[cursor->unk_1C][cursor->unk_18]);
        }
        if (block2->type != BLOCKTYPE_0) {
            Init2DTetrisTMEM(block2, &well->unk_3830[cursor->unk_1C][cursor->unk_18 + 1]);
        }
        // TODO: Dimensions define?
        AfterSwitch(well, cursor, block1, block2, 1);
    }
}

#if VERSION_USA
#ifdef NON_MATCHING
void Add2DNewRow(tetWell *well, cursor_t *cursor, s32 num) {
    s32 var_a0;
    s32 var_s1;
    s32 sp24;
    s32 temp2;

    sp24 = 0;
    for (var_a0 = 0; var_a0 < 6; var_a0++) {
        for (var_s1 = 0xB; var_s1 >= 1; var_s1--) {
            bcopy(&well->block[var_s1 - 1][var_a0], &well->block[var_s1][var_a0], 0x2C);
            well->block[var_s1][var_a0].currRow = var_s1;
            bcopy(&well->unk_3830[var_s1 - 1][var_a0], &well->unk_3830[var_s1][var_a0], 0x18);
        }

        bcopy(&well->new_block[var_a0], &well->block[0][var_a0], 0x2C);
        bcopy(&well->unk_3EF0[var_a0], &well->unk_3830[0][var_a0], 0x18);
    }

    for (var_a0 = 0; var_a0 < 0x14; var_a0++) {
        if (well->attack[var_a0].state >= ATTACKSTATE_7) {
            well->attack[var_a0].unk_24 += 1;
        }
    }

    Init2DNewRow(well);
    if ((cursor->unk_1C != -1) & (cursor->unk_1C < 0xB)) {
        cursor->unk_1C++;
    }

    if (cursor->y >= 0xA) {
        if (cursor->y > 0) {
            temp2 = cursor->rect.s.objY >> 2;
            cursor->rect.s.objY = (temp2 + 0x10) << 2;
            cursor->y--;
            sp24 = -1;
        } else {
            sp24 = 0;
        }
    }

    cursor->y++;
    if (sp24 != 0) {
        if (gTheGame.unk_9C08 == 1) {
            PlaySE(SFX_INIT_TABLE, 0x96);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, 0x97);
        } else {
            PlaySE(SFX_INIT_TABLE, 0x98);
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/animate2d", Add2DNewRow);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate2d", Add2DNewRow);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate2d", Add2DNewRow);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate2d", Add2DNewRow);
#endif
