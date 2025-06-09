/**
 * Original filename: combo.c
 */

#include "combo.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/combo", CheckCollision);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo", CheckCollision);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo", CheckCollision);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo", CheckCollision);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/combo", CompactWell);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo", CompactWell);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo", CompactWell);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo", CompactWell);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/combo", CheckIcon);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo", CheckIcon);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo", CheckIcon);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo", CheckIcon);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/combo", func_8005600C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/combo", func_80056180_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo", func_800562AC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo", func_80056420_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo", func_80054A1C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo", func_80054B90_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo", func_80054B9C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo", func_80054D10_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/combo", func_800562FC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/combo", func_800564E0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo", func_8005659C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo", func_80056780_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo", func_80054D0C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo", func_80054EF0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo", func_80054E8C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo", func_80055070_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/combo", CheckChainCounter);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo", CheckChainCounter);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo", CheckChainCounter);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo", CheckChainCounter);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/combo", ComboCount);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/combo", ComboCount);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/combo", ComboCount);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/combo", ComboCount);
#endif
