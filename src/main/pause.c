/**
 * Original filename: pause.c
 */

#include "pause.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "the_game.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/pause", func_80035B20_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/pause", func_80035B50_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/pause", func_80035AC0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/pause", func_80035C30_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/pause", func_80035FF0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/pause", func_80036020_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/pause", func_80035F90_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/pause", func_80036100_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/pause", DoPauseGame);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/pause", DoPauseGame);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/pause", DoPauseGame);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/pause", DoPauseGame);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/pause", Draw2DPause);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/pause", Draw2DPause);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/pause", Draw2DPause);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/pause", Draw2DPause);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/pause", Draw3DPause);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/pause", Draw3DPause);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/pause", Draw3DPause);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/pause", Draw3DPause);
#endif

void DrawPause(struct_gInfo_unk_00068 *dynamicp) {
    if (gTheGame.unk_9C0C == 2) {
        Draw3DPause(dynamicp);
    } else {
        Draw2DPause(dynamicp);
    }
}
