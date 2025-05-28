#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"


#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bg_screen_load/075540", func_80074940_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bg_screen_load/075540", func_80074C70_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bg_screen_load/075540", func_800733A0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bg_screen_load/075540", func_80073550_ger);
#endif
