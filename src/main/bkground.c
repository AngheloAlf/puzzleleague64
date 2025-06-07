/**
 * Original filename: bkground.c
 */

#include "bkground.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "assets_variables.h"

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

void func_80048D94_usa(void) {
    s16 sp0[ARRAY_COUNT(gTheGame.unk_9A08)];
    s16 sp8[17] UNUSED = {
        0x43, 0, 1, 0x43, 1, 7, 0, 0x43, 1, 7, 7, 0, 1, 0, 1, 0, 0,
    };
    s32 i;
    uObjSprite *var_v1;

    if ((gTheGame.unk_9C0C == 1) && (gTheGame.unk_9C08 != 1)) {
        sp0[0] = 0x47;
        sp0[1] = 0x47;
    } else {
        sp0[0] = 0;
        sp0[1] = 0;
    }
    sp0[2] = 0;

    var_v1 = gTheGame.unk_9A08;
    for (i = 0; i < ARRAY_COUNT(gTheGame.unk_9A08); i++) {
        var_v1[i].s.imageW = 8 << 5;
        var_v1[i].s.imageH = 8 << 5;
        var_v1[i].s.paddingX = 0;
        var_v1[i].s.paddingY = 0;
        var_v1[i].s.imageStride = 8;
        var_v1[i].s.imageAdrs = sp0[i];
        var_v1[i].s.imageFmt = G_IM_FMT_CI;
        var_v1[i].s.imageSiz = G_IM_SIZ_8b;
        var_v1[i].s.imagePal = 0;
        var_v1[i].s.imageFlags = 0;
    }

    if (gTheGame.unk_9C08 == 1) {
        gTheGame.unk_9A08[0].s.objX = 0x72 << 2;
        gTheGame.unk_9A08[0].s.scaleW = 0x4B;
        gTheGame.unk_9A08[0].s.objY = 0x1F << 2;
        gTheGame.unk_9A08[0].s.scaleH = 0x2A;

        gTheGame.unk_9A08[1].s.objX = 0x1F << 2;
        gTheGame.unk_9A08[1].s.scaleW = 0x66;
        gTheGame.unk_9A08[1].s.objY = 0x19 << 2;
        gTheGame.unk_9A08[1].s.scaleH = 0x108;

        gTheGame.unk_9A08[2].s.objX = 0xE2 << 2;
        gTheGame.unk_9A08[2].s.scaleW = 0x86;
        gTheGame.unk_9A08[2].s.objY = 0x19 << 2;
        gTheGame.unk_9A08[2].s.scaleH = 0x46;
    } else {
        gTheGame.unk_9A08[0].s.objX = 0x18 << 2;
        gTheGame.unk_9A08[0].s.scaleW = 0x4B;
        gTheGame.unk_9A08[0].s.objY = 0x1F << 2;
        gTheGame.unk_9A08[0].s.scaleH = 0x2A;

        gTheGame.unk_9A08[1].s.objX = 0xBC << 2;
        gTheGame.unk_9A08[1].s.scaleW = 0x4B;
        gTheGame.unk_9A08[1].s.objY = 0x1F << 2;
        gTheGame.unk_9A08[1].s.scaleH = 0x2A;

        if (gSelection == 0x96) {
            gTheGame.unk_9A08[2].s.objY = 0x51 << 2;
        } else {
            gTheGame.unk_9A08[2].s.objY = 0x40 << 2;
        }
        gTheGame.unk_9A08[2].s.objX = 0x86 << 2;
        gTheGame.unk_9A08[2].s.scaleW = 0x9D;
        gTheGame.unk_9A08[2].s.scaleH = 0x51;
    }
}

void Draw2DShadeBox(void) {
    s32 count;
    s32 total;

    if (gTheGame.unk_9C08 == 1) {
        total = ARRAY_COUNT(gTheGame.unk_9A08);
    } else if (gMain < GMAIN_393) {
        total = ARRAY_COUNT(gTheGame.unk_9A08) - 1;
    } else {
        return;
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &numberLUT);
    gSPObjLoadTxtr(glistp++, &transTexture);

    gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, gBox_Level);

    for (count = 0; count < total; count++) {
        gSPObjRectangle(glistp++, &gTheGame.unk_9A08[count]);
    }
}

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

void Draw2DBigScreen(uObjTxtr *lut, uObjBg *ptr) {
    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, lut);
    gDPSetRenderMode(glistp++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCycleType(glistp++, G_CYC_COPY);

    gDPPipeSync(glistp++);
    gSPBgRectCopy(glistp++, ptr);

    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
    gDPSetTextureLUT(glistp++, G_TT_NONE);
}

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

void func_8004AE90_usa(void) {
    if (D_800B69C0_usa == -1) {
        return;
    }

    if (D_800B69C0_usa < 4) {
        gDPPipeSync(glistp++);
        gDPSetCycleType(glistp++, G_CYC_1CYCLE);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, ((D_800B69C0_usa * 0x32) + 0x64));

        if (gTheGame.unk_9C0C == 1) {
            gDPPipeSync(glistp++);
            gSPBgRect1Cyc(glistp++, &gTheGame.unk_8C88[0]);

            gDPPipeSync(glistp++);
            gSPBgRect1Cyc(glistp++, &gTheGame.unk_8C88[1]);
        } else if ((gSelection != 0xAA) & (gSelection != 0x82)) {
            gDPPipeSync(glistp++);
            guS2DEmuBgRect1Cyc(&glistp, &gTheGame.unk_8C88[0]);

            gDPPipeSync(glistp++);
            guS2DEmuBgRect1Cyc(&glistp, &gTheGame.unk_8C88[1]);
        }

        if (D_800B69C0_usa == 3) {
            gTheGame.unk_9A50.b.imagePtr = gTheGame.unk_8C88[2].b.imagePtr;
        }
    }

    gDPPipeSync(glistp++);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
}

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
