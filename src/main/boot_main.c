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
void Idle_ThreadEntry(void *arg) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &sPiMgrCmdQueue, sPiMgrCmdBuff, ARRAY_COUNT(sPiMgrCmdBuff));

    osCreateThread(&sMainThread, 6, Main_ThreadEntry, arg, STACK_TOP(sMainStack), 0xA);

    if (D_800B3AC4_usa == 0) {
        osStartThread(&sMainThread);
    }
    osSetThreadPri(NULL, 0);

    while (true) {}
}
INCLUDE_ASM("asm/usa/nonmatchings/main/boot_main", func_80000630_usa);

void Main_ThreadEntry(void *arg UNUSED) {
    s32 var_s0 = 0;

    func_80000630_usa();
    B_8019CEC0_usa = 0x2C;
    D_800BE348_usa = 0x1F4;
    D_800BE344_usa = -1;
    B_801A6D7C_usa[0] = 1;

    while (true) {
        B_801A6D7C_usa[1] = 0;

        switch (D_800BE348_usa) {
            case 0x258:
            case 0x2BC:
            case 0x28A:
                B_801A6D7C_usa[0] = 1;
                B_801F9CB8_usa = 0;
                var_s0 = func_800009E4_usa(var_s0);
                break;

            case 0x383:
                B_801A6D7C_usa[0] = 2;
                var_s0 = func_800009E4_usa(var_s0);
                break;

            case 0x34C:
            case 0x378:
            case 0x384:
            case 0x357:
            case 0x14D:
            case 0x38E:
            case 0x36D:
            case 0x341:
            case 0x1F4:
                var_s0 = func_800009E4_usa(var_s0);
                break;

            default:
                var_s0 = func_80000EF8_usa(var_s0);
                break;
        }
    }
}

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
