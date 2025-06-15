/**
 * Original filename: fade.c
 */

#include "fade.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/fade", func_80054020_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/fade", func_800542C0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/fade", func_80052A30_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/fade", func_80052BB0_ger);
#endif

void SetGameFade(void) {
    gBox_Level = 0x8C;
    gBlock_Level = 0xFF;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/fade", func_8005407C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/fade", func_8005431C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/fade", func_80052A8C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/fade", func_80052C0C_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/fade", DoGameFade);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/fade", DoGameFade);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/fade", DoGameFade);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/fade", DoGameFade);
#endif

void Draw2DGameFade(void) {
    if (gBlock_Level == 255) {
        gDPPipeSync(glistp++);
        gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
    } else {
        gDPPipeSync(glistp++);
        gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, gBlock_Level);
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/fade", func_80054320_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/fade", func_800545C0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/fade", func_80052D30_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/fade", func_80052EB0_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/fade", func_8005443C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/fade", func_800546DC_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/fade", func_80052E4C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/fade", func_80052FCC_ger);
#endif

s32 DoFlashDraw(s32 arg0) {
    if (Flash_period[arg0] > 0) {
        Flash_period[arg0]--;

        Flash_count[arg0]++;

        if (Flash_count[arg0] < 0xB) {
            return 0;
        }

        if (Flash_count[arg0] >= 0x15) {
            Flash_count[arg0] = 1;
            return 0;
        }
        return -1;
    }

    return -1;
}

s32 DoFlashDrawAlways(void) {
    s32 ret = DoFlashDraw(1);

    Flash_period[1] = 0x19;
    return ret;
}
