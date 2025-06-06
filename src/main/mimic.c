/**
 * Original filename: mimic.c
 */

#include "mimic.h"

#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "segment_symbols.h"

#include "buffers.h"
#include "character.h"
#include "dlist.h"
#include "tetsound.h"

void SetupMimic(void **heapP) {
    s32 temp_a0;

    B_801C6EE8_usa = 1;
    B_801C6E58_usa = 1;
    Pon_Image_Heap = &gBufferHeap[SEGMENT_ROM_SIZE(segment_0CA4A0)];

    temp_a0 = gGameStatus & 0x40;
    gGameStatus = gGameStatus << 0x10;
    if (temp_a0 != 0) {
        gGameStatus |= 0x40;
    }

    func_80054624_usa(temp_a0);
    InitCharacter(0x385, -1);
    func_800040D8_usa(0x19, 9, 9);

    *heapP = Pon_Image_Heap;
}

void QuitMimic(void) {
    gGameStatus = gGameStatus >> 0x10;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80083050_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_8008336C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_800833B0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80083480_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_800844DC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084758_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084A28_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084C18_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084C84_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084D24_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084D84_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_8008554C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80085CC8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_800833E0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_800836FC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80083740_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80083810_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80084894_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80084B10_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80084DE0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80084FD0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_8008503C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_800850DC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_8008513C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80085904_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80086080_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80081B00_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80081E1C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80081E60_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80081F30_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80082FB4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80083230_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80083500_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_800836F0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_8008375C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_800837FC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_8008385C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80084024_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_800847A0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80081CC0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80081FDC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80082020_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_800820F0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80083174_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_800833F0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_800836C0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_800838B0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_8008391C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_800839BC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80083A1C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_800841E4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80084960_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", DrawMT);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", DrawMT);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", DrawMT);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", DrawMT);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", DoMimic);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", DoMimic);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", DoMimic);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", DoMimic);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/mimic", RO_800C76E4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", InitMimic);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/mimic", RO_800C7994_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", InitMimic);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/mimic", RO_800C5FF4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", InitMimic);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/mimic", RO_800BCFB4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", InitMimic);
#endif
