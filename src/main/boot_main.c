#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/boot_main", func_80000450_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", func_80000450_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000450_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", func_80000450_ger);
#endif

void bootproc(void) {
    s32 pad[0x10] UNUSED;

    osInitialize();
    osAiSetFrequency(0x4B00);

#if REGION_PAL
    func_80001A80_eur(0);
#endif

    osCreateThread(&sIdleThread, 1, Idle_ThreadEntry, NULL, STACK_TOP(sIdleStack), 0xA);
    osStartThread(&sIdleThread);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/boot_main", Idle_ThreadEntry);

INCLUDE_ASM("asm/usa/nonmatchings/main/boot_main", func_80000630_usa);

INCLUDE_ASM("asm/usa/nonmatchings/main/boot_main", Main_ThreadEntry);

INCLUDE_ASM("asm/usa/nonmatchings/main/boot_main", func_800009E4_usa);

INCLUDE_ASM("asm/usa/nonmatchings/main/boot_main", func_80000EF8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", Idle_ThreadEntry);

INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", func_80000654_eur);

INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", func_800008AC_eur);

INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", func_80000A3C_eur);

INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", func_80000F88_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", Idle_ThreadEntry);

INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000654_fra);

INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_800008AC_fra);

INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000A3C_fra);

INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000F90_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", Idle_ThreadEntry);

INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", func_80000654_ger);

INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", func_800008AC_ger);

INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", func_80000A3C_ger);

INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", func_80000F90_ger);
#endif
