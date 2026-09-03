/**
 * Original filename: update2d.c
 */

#include "update2d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update2d", Update2DDistance);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update2d", Update2DDistance);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update2d", Update2DDistance);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update2d", Update2DDistance);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update2d", func_800710CC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update2d", func_800713EC_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update2d", func_8006FB2C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update2d", func_8006FCDC_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update2d", Update2DIcon);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update2d", Update2DIcon);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/update2d", Update2DIcon);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/update2d", Update2DIcon);
#endif
