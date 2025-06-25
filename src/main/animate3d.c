/**
 * Original filename: animate3d.c
 */

#include "animate3d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "animate.h"
#include "init3d.h"
#include "sfxlimit.h"
#include "the_game.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate3d", Input3D);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate3d", Input3D);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate3d", Input3D);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate3d", Input3D);
#endif

#if VERSION_USA
#ifdef NON_MATCHING
nbool Move3DCursorUp(tetWell *well, cursor_t *cursor, CursorHoldVal hold) {
    s32 temp;

    if (well->unk_43F8 == 0) {
        if (cursor->y < 0xB) {
            cursor->y += 1;
            temp = cursor->rect.s.objY >> 2;
            cursor->rect.s.objY = (temp << 2) - (4 << 2);
            if ((hold == CURSOR_HOLD_VAL_10) || (hold == CURSOR_HOLD_VAL_0)) {
                return ntrue;
            }
        }
    } else {
        if (cursor->y < 0xA) {
            cursor->y++;
            temp = cursor->rect.s.objY >> 2;
            cursor->rect.s.objY = (temp << 2) - 0x10;
            if ((hold == CURSOR_HOLD_VAL_10) || (hold == CURSOR_HOLD_VAL_0)) {
                return ntrue;
            }
        }
    }
    return nfalse;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/animate3d", Move3DCursorUp);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate3d", Move3DCursorUp);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate3d", Move3DCursorUp);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate3d", Move3DCursorUp);
#endif

nbool Move3DCursorDown(cursor_t *cursor, CursorHoldVal hold) {
    if (cursor->y > 0) {
        s32 temp = cursor->rect.s.objY;

        cursor->rect.s.objY = temp + 0x10;
        cursor->y--;

        if ((hold == CURSOR_HOLD_VAL_10) || (hold == CURSOR_HOLD_VAL_0)) {
            return ntrue;
        }
    }

    return nfalse;
}

nbool Move3DCursorLeft(cursor_t *cursor, CursorHoldVal hold UNUSED) {
    if (cursor->unk_18 == 0) {
        cursor->unk_18 = 4;
        return ntrue;
    }

    return nfalse;
}

nbool Move3DCursorRight(cursor_t *cursor, CursorHoldVal hold UNUSED) {
    if (cursor->unk_18 == 0) {
        cursor->unk_18 = -4;
        return ntrue;
    }

    return nfalse;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate3d", Switch3DBlocks);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate3d", Switch3DBlocks);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate3d", Switch3DBlocks);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate3d", Switch3DBlocks);
#endif

void Update3DSwitching(tetWell *well, cursor_t *cursor) {
    if (cursor->unk_1C != -1) {
        cursor->unk_04--;
        if ((cursor->unk_04 == 0) || (cursor->unk_18 != 0)) {
            AfterSwitch(well, cursor, &well->block[cursor->unk_1C][4], &well->block[cursor->unk_1C][5], 2);
        }
    }
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
void Add3DNewRow(tetWell *well, cursor_t *cursor, s32 num) {
    cursor_t *sp14;
    s32 sp1C;
    s32 sp24;
    s32 temp_v1;
    s32 var_a0;
    s32 var_s1;
    s32 var_s5;
    s32 var_v0;
    s32 temp;

    sp14 = cursor;
    sp1C = num;
    sp24 = 0;

    for (var_s5 = 0; var_s5 < 18; var_s5++) {
        for (var_s1 = 11; var_s1 > 0; var_s1--) {
            bcopy(&well->block[var_s1 - 1][var_s5], &well->block[var_s1][var_s5], 0x2C);
            well->block[var_s1][var_s5].currRow = var_s1;
        }

        bcopy(&well->new_block[var_s5], &well->block[0][var_s5], 0x2C);
    }

    well->translation = 0.0f;

    for (var_a0 = 0; var_a0 < 0x14; var_a0++) {
        if (well->attack[var_a0].state >= 7) {
            well->attack[var_a0].unk_24 += 1;
        }
    }

    Init3DNewRow(well);

    if ((sp14->unk_1C != -1) && (sp14->unk_1C < 0xB)) {
        sp14->unk_1C++;
    }

    temp_v1 = sp14->y;
    var_v0 = temp_v1 + 1;
    if (temp_v1 >= 0xA) {
        if (temp_v1 <= 0) {
            sp24 = 0;
        } else {
            sp24 = -1;
            temp = sp14->rect.s.objY;
            sp14->rect.s.objY = temp + 4 << 2;
            sp14->y--;
        }
        var_v0 = sp14->y + 1;
    }
    sp14->y = var_v0;

    if (sp24 != 0) {
        if (gTheGame.unk_9C08 == 1) {
            PlaySE(&SFX_INIT_TABLE, 0x96);
        } else if (sp1C == 0) {
            PlaySE(&SFX_INIT_TABLE, 0x97);
        } else {
            PlaySE(&SFX_INIT_TABLE, 0x98);
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/animate3d", Add3DNewRow);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate3d", Add3DNewRow);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate3d", Add3DNewRow);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate3d", Add3DNewRow);
#endif
