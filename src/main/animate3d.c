/**
 * Original filename: animate3d.c
 */

#include "animate3d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate3d", func_80066770_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate3d", func_80066A40_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate3d", func_80065180_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate3d", func_80065330_ger);
#endif

#if VERSION_USA
#ifdef NON_MATCHING
s32 Move3DCursorUp(tetWell *well, cursor_t *cursor, s32 hold) {
    s32 temp;

    if (well->unk_43F8 == 0) {
        if (cursor->y < 0xB) {
            cursor->y += 1;
            temp = cursor->rect.s.objY >> 2;
            cursor->rect.s.objY = (temp << 2) - (4 << 2);
            if ((hold == 0xA) || (hold == 0)) {
                return -1;
            }
        }
    } else {
        if (cursor->y < 0xA) {
            cursor->y++;
            temp = cursor->rect.s.objY >> 2;
            cursor->rect.s.objY = (temp << 2) - 0x10;
            if ((hold == 0xA) || (hold == 0)) {
                return -1;
            }
        }
    }
    return 0;
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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate3d", Move3DCursorDown);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate3d", Move3DCursorDown);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate3d", Move3DCursorDown);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate3d", Move3DCursorDown);
#endif

s32 Move3DCursorLeft(cursor_t *cursor, s32 hold UNUSED) {
    if (cursor->unk_18 == 0) {
        cursor->unk_18 = 4;
        return -1;
    }

    return 0;
}

s32 Move3DCursorRight(cursor_t *cursor, s32 hold UNUSED) {
    if (cursor->unk_18 == 0) {
        cursor->unk_18 = -4;
        return -1;
    }

    return 0;
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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate3d", Update3DSwitching);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate3d", Update3DSwitching);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate3d", Update3DSwitching);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate3d", Update3DSwitching);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate3d", Add3DNewRow);
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
