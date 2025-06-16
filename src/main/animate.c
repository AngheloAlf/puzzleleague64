/**
 * Original filename: animate.c
 */

#include "animate.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "ai.h"
#include "animate2d.h"
#include "animate3d.h"

void CheckGameInput(tetWell *well, cursor_t *cursor, s32 num) {
    if (gTheGame.unk_9C0C == 1) {
        if (brainbrain[num].unk_00C == -1) {
            Input2D(well, cursor, num);
        } else {
            AIMove(well, cursor, &brainbrain[num], num);
        }
        Update2DSwitching(well, cursor);
    } else {
        if (brainbrain[num].unk_00C == -1) {
            Input3D(well, cursor, num);
        } else {
            AIMove(well, cursor, &brainbrain[num], num);
        }
        Update3DSwitching(well, cursor);
    }

    cursor->unk_24--;
    if (cursor->unk_24 == 0) {
// TODO: REGION_NTSC?
#if VERSION_USA
        cursor->unk_24 = 0xF;
#else
        cursor->unk_24 = 0xD;
#endif
        cursor->unk_20 ^= 1;
    }
}

void AddNewRow(tetWell *well, cursor_t *cursor, s32 num) {
    if (gTheGame.unk_9C0C == 1) {
        Add2DNewRow(well, cursor, num);
    } else {
        Add3DNewRow(well, cursor, num);
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate", RaiseBlocks);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate", RaiseBlocks);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate", RaiseBlocks);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate", RaiseBlocks);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate", AfterSwitch);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate", AfterSwitch);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate", AfterSwitch);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate", AfterSwitch);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate", CheckShake);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate", CheckShake);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate", CheckShake);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate", CheckShake);
#endif

nbool CheckFieldActive(tetWell *well) {
    s32 row;
    s32 col;

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        for (col = 0; col < gMax; col++) {
            if (well->block[row][col].state != BLOCKSTATE_0) {
                return ntrue;
            }
        }
    }

    return nfalse;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate", func_8005731C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate", func_800575BC_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate", func_80055D2C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate", func_80055EAC_ger);
#endif
