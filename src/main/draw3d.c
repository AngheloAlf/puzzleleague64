/**
 * Original filename: draw3d.c
 */

#include "draw3d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "bkground.h"
#include "bonus.h"
#include "flic.h"
#include "info.h"
#include "other.h"
#include "sign.h"
#include "text.h"
#include "the_game.h"

#include "assets_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_8005E510_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_8005E740_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_8005E7A4_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/draw3d", RO_800C6E40_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DFrontTetrisWell);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DBackTetrisWell);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_8005F984_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_8005FA6C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_8005FB10_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_8005FD38_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DTetrisNewBlock);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DCursor);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DIcon);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DAttackBrick);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_800615D8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DAttack);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DExplosion);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DClearLine);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DClearSign);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80063110_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80063F8C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_800643A4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80064728_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80064AAC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80064E44_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_8005E7E0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_8005EA10_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_8005EA74_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/draw3d", RO_800C70F0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DFrontTetrisWell);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DBackTetrisWell);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_8005FC54_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_8005FD3C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_8005FDE0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_80060008_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DTetrisNewBlock);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DCursor);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DIcon);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DAttackBrick);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_800618A8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DAttack);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DExplosion);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DClearLine);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DClearSign);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_80063110_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_80063F8C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_800643A4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_800649F8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_80064D7C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_80064E44_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_8005CF20_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_8005D150_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_8005D1B4_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/draw3d", RO_800C5750_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DFrontTetrisWell);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DBackTetrisWell);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_8005E394_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_8005E47C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_8005E520_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_8005E748_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DTetrisNewBlock);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DCursor);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DIcon);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DAttackBrick);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_8005FFE8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DAttack);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DExplosion);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DClearLine);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DClearSign);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_80063110_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_80063F8C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_800643A4_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_80063138_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_800634BC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_80064E44_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_8005D0D0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_8005D300_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_8005D364_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/draw3d", RO_800BC710_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DFrontTetrisWell);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DBackTetrisWell);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_8005E544_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_8005E62C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_8005E6D0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_8005E8F8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DTetrisNewBlock);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DCursor);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DIcon);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DAttackBrick);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_80060198_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DAttack);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DExplosion);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DClearLine);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DClearSign);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_80063110_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_80063F8C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_800643A4_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_800632E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_8006366C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_80064E44_usa);
#endif

void Draw3DTetris(struct_gInfo_unk_00068 *dynamicp) {
    s32 sp28[GAME_BUFFER_LEN]; // end_attack?
    u16 perspNorm;
    nbool sp3C = ntrue;
    s32 num;

    if (gAllVertex == NULL) {
        return;
    }

    Draw3DBackground();
    if ((gMain == GMAIN_384) && (gCounter < ADJUST_COUNTER(100))) {
        return;
    }

    if (gMain >= GMAIN_38F) {
        func_80053E64_usa(dynamicp);
    }

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 31, SCREEN_WIDTH, SCREEN_HEIGHT - 19);

    if (((gMain == GMAIN_388) || (gMain < GMAIN_384)) && ((gTheGame.unk_9C08 == 2) || (gSelection == 0x82))) {
        sp3C = nfalse;
    }

    for (num = 0; num < gTheGame.unk_9C08; num++) {
        gDPPipeSync(glistp++);
        gDPSetTextureLUT(glistp++, G_TT_RGBA16);
        gDPLoadTLUT_pal256(glistp++, colorTable);
        gSPMatrix(glistp++, &dynamicp->unk_10100[num], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

        guPerspective(&dynamicp->unk_10000[num], &perspNorm, 33.0f, 0.88f, 10.0f, 3000.0f, 1.0f);
        guLookAt(&dynamicp->unk_10080[num], 0.0f, 0.0f, 900.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        gSPPerspNormalize(glistp++, perspNorm);
        gSPMatrix(glistp++, &dynamicp->unk_10000[num], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gSPMatrix(glistp++, &dynamicp->unk_10080[num], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gDPPipeSync(glistp++);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gSPMatrix(glistp++, &gIdent, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPMatrix(glistp++, &dynamicp->unk_10180[num], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

        if (sp3C) {
            Draw3DTetrisNewBlock(dynamicp, &gTheGame.tetrisWell[num]);
            Draw3DAttack(dynamicp, num, 0);
            Draw3DBackTetrisWell(dynamicp, num);

            sp28[num] = Draw3DAttack(dynamicp, num, -1);
            Draw3DFrontTetrisWell(dynamicp, num);

            gDPPipeSync(glistp++);
            gDPSetRenderMode(glistp++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

            if (gMain < GMAIN_38E) {
                Draw3DIcon(dynamicp, num);
            }
            if ((gSelection == 0xAA) || (gSelection == 0xB4)) {
                Draw3DClearLine(dynamicp, num);
            }
        }
    }

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 7, SCREEN_WIDTH, SCREEN_HEIGHT - 1);

    if (gMain == GMAIN_384) {
        func_80053E64_usa(dynamicp);
    }

    func_80047A00_usa();

    gDPPipeSync(glistp++);
    gDPSetTexturePersp(glistp++, G_TP_NONE);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(glistp++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

    Draw3DText(dynamicp);
    Draw3DMiscStuff(dynamicp);
    if ((gSelection == 0xAA) || (gSelection == 0xB4)) {
        for (num = 0; num < gTheGame.unk_9C08; num++) {
            Draw3DClearSign(dynamicp, num);
        }
    }

    Draw3DAnimation(dynamicp, -1, -1);
    if (sp3C) {
        for (num = 0; num < gTheGame.unk_9C08; num++) {
            Draw3DAttackBrick(dynamicp, num, sp28[num]);
            Draw3DExplosion(dynamicp, num);
        }
    }

    if ((gMain == GMAIN_387) || ((gMain == GMAIN_384) && (gCounter > ADJUST_COUNTER(180)))) {
        Draw3DCursor(dynamicp);
    }
    if (gMain >= GMAIN_388) {
        DrawPauseOver(dynamicp);
    } else if (gMain == GMAIN_384) {
        DrawCountDown();
    }

    gSPTexture(glistp++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
}
