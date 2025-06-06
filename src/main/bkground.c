/**
 * Original filename: bkground.c
 */

#include "bkground.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80047340_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_800475E0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80045D60_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80045ED0_ger);
#endif

void Draw2DFrame(void) {
    func_8004B12C_usa();

    if (D_800B69C4_usa == -1) {
        gDPPipeSync(glistp++);
        gDPSetTextureLUT(glistp++, G_TT_NONE);
        gDPSetRenderMode(glistp++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetCycleType(glistp++, G_CYC_COPY);

        if (gSelection == 0x78) {
            gDPSetTextureLUT(glistp++, G_TT_RGBA16);
            gSPObjLoadTxtr(glistp++, &gTheGame.unk_99D8);
        }

        gDPPipeSync(glistp++);
        gSPBgRectCopy(glistp++, &gTheGame.frame);
    }

    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80047A00_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_80047CA0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80046420_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80046590_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80047D20_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_80047FC0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80046740_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_800468B0_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80047E64_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_80048104_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80046884_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_800469F4_ger);
#endif

void Draw2DBackground(void) {
    gDPPipeSync(glistp++);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(glistp++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCycleType(glistp++, G_CYC_COPY);

    gDPPipeSync(glistp++);
    gSPBgRectCopy(glistp++, &gTheGame.unk_9A50);

    func_8004AE90_usa();

    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_800488AC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_80048B4C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_800472CC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_8004743C_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80048D94_usa);
INCLUDE_RODATA("asm/usa/nonmatchings/main/bkground", RO_800C5BF0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_80049034_eur);
INCLUDE_RODATA("asm/eur/nonmatchings/main/bkground", RO_800C5EA0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_800477B4_fra);
INCLUDE_RODATA("asm/fra/nonmatchings/main/bkground", RO_800C4500_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80047924_ger);
INCLUDE_RODATA("asm/ger/nonmatchings/main/bkground", RO_800BB4C0_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", Draw2DShadeBox);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", Draw2DShadeBox);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", Draw2DShadeBox);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", Draw2DShadeBox);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_8004917C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004941C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80047B9C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80047D0C_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80049584_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_80049824_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80047FA4_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80048114_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80049960_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_80049C00_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80048380_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_800484F0_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_8004A26C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004A50C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80048C8C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80048DFC_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", Draw2DBigScreen);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004ABE4_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80049364_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_800494D4_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_8004AA48_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004ACE8_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80049468_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_800495D8_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_8004ADD0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004ADD0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_8004ADD0_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_8004ADD0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_8004AE90_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004AE90_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_8004AE90_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_8004AE90_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_8004B0D8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004B378_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80049AF8_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80049C68_ger);
#endif

void func_8004B12C_usa(void) {
    if ((D_800B69C4_usa < 0x1A) && (D_800B69C4_usa != -1)) {
        gDPPipeSync(glistp++);

        gDPSetTextureLUT(glistp++, G_TT_NONE);
        gDPSetCycleType(glistp++, G_CYC_1CYCLE);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, D_800B69C4_usa * 0xA);

        if (gTheGame.unk_9C0C == 1) {
            gDPPipeSync(glistp++);
            gSPBgRect1Cyc(glistp++, &gTheGame.frame);
        } else {
            gDPPipeSync(glistp++);
            guS2DEmuBgRect1Cyc(&glistp, &gTheGame.frame);
        }
    } else if (D_800B69C4_usa != -1) {
        D_800B69C4_usa = -1;
        guS2DInitBg(&gTheGame.frame);
    }

    gDPPipeSync(glistp++);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
}
