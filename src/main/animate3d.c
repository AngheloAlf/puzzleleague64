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
INCLUDE_ASM("asm/usa/nonmatchings/main/animate3d", Move3DCursorUp);
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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate3d", Move3DCursorLeft);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate3d", Move3DCursorLeft);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate3d", Move3DCursorLeft);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate3d", Move3DCursorLeft);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animate3d", Move3DCursorRight);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animate3d", Move3DCursorRight);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animate3d", Move3DCursorRight);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animate3d", Move3DCursorRight);
#endif

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
