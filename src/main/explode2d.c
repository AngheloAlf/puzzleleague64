#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"


#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/explode2d", Start2DExplosion);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode2d", Start2DExplosion);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode2d", Start2DExplosion);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode2d", Start2DExplosion);
#endif


#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/explode2d", func_80072FDC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/explode2d", func_800730B0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/explode2d", func_80073138_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/explode2d", func_8007320C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/explode2d", func_800733D0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode2d", func_8007330C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode2d", func_800733E0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode2d", func_80073468_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode2d", func_8007353C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode2d", func_80073700_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode2d", func_80071A3C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode2d", func_80071B10_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode2d", func_80071B98_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode2d", func_80071C6C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode2d", func_80071E30_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode2d", func_80071BEC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode2d", func_80071CC0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode2d", func_80071D48_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode2d", func_80071E1C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode2d", func_80071FE0_ger);
#endif


#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/explode2d", Update2DExplosion);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/explode2d", Update2DExplosion);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/explode2d", Update2DExplosion);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/explode2d", Update2DExplosion);
#endif
