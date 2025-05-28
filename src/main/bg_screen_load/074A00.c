#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"


#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bg_screen_load/074A00", func_80073E00_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bg_screen_load/074A00", func_80074130_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bg_screen_load/074A00", func_80072860_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bg_screen_load/074A00", func_80072A10_ger);
#endif
