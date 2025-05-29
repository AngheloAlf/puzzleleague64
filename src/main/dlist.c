/**
 * Original filename: dlist.c
 */

#include "dlist.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "assets_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_80054500_usa);
#endif

#if VERSION_USA
void func_800545E4_usa(s32 arg0) {
    gTheGame.unk_89C4[arg0].unk_04 = 0xA;
    gTheGame.unk_89C4[arg0].unk_00 = 0;
    gTheGame.unk_89C4[arg0].unk_02 = 0;
    gTheGame.unk_89C4[arg0].unk_0A = 0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_80054624_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/dlist", func_800547A0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/dlist", func_80054884_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/dlist", func_800548C4_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/dlist", func_80052F10_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/dlist", func_80052FF4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/dlist", func_80053034_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/dlist", func_80053090_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/dlist", func_80053174_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/dlist", func_800531B4_ger);
#endif

void InitTetrisState(block_t *arg0) {
    arg0->state = 0;
    arg0->delay = 0;
    arg0->disappear = 0;
    arg0->drop = 0;
    arg0->type = 0;
    arg0->frame_n = 0;
    arg0->bomb = 0;
    arg0->chain_flag = 0;
}

void InitDisplayList(struct_gInfo *info) {
    gSPDisplayList(glistp++, initRDP_dl);
    gDPPipeSync(glistp++);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, info->unk_19040);

    if ((gMain == GMAIN_384) || ((gMain > GMAIN_388))) {
        B_801C70D8_usa = (GPACK_RGBA5551(0, 0, 0, 1) << 16) | (GPACK_RGBA5551(0, 0, 0, 1) << 0);

        gDPSetCycleType(glistp++, G_CYC_FILL);
        gDPSetFillColor(glistp++, B_801C70D8_usa);
        gDPFillRectangle(glistp++, 0, 0, SCREEN_WIDTH - 1, 6);
        gDPPipeSync(glistp++);
    }

    gDPSetCycleType(glistp++, G_CYC_1CYCLE);

    if (gTheGame.unk_9C0C == 2) {
        gSPDisplayList(glistp++, init3D_dl);
        guS2DEmuSetScissor(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    } else {
        gSPDisplayList(glistp++, init2D_dl);
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_800549A4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", InitGameStateVar);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_800552F4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/dlist", func_80054C44_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/dlist", func_80054CCC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/dlist", func_80055594_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/dlist", func_800533B4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/dlist", func_8005343C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/dlist", func_80053D04_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/dlist", func_80053534_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/dlist", func_800535BC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/dlist", func_80053E84_ger);
#endif
