/**
 * Original filename: draw2d.c
 */

#include "draw2d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "bonus.h"
#include "fade.h"
#include "flic.h"
#include "sign.h"
#include "text.h"

#include "assets_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DTetrisWell);
#endif

#if VERSION_USA
INLINE void Draw2DCursor(struct_gInfo_unk_00068 *arg0) {
    s32 i;

    if (arg0->unk_172A8[0].unk_20 == 0) {
        gSPObjLoadTxtr(glistp++, &cursorBig);
    } else {
        gSPObjLoadTxtr(glistp++, &cursorSmall);
    }

    for (i = 0; i < gTheGame.unk_9C08; i++) {
        Game_unk_8860 *temp_a0 = &arg0->unk_172A8[i];

        if (temp_a0->unk_14 < 0xC) {
            gSPObjRectangle(glistp++, &temp_a0->unk_98);
        }
    }
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DIcon);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DAttackBrick);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DAttackBlock);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DExplosion);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DClearLine);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006F09C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006F2FC_usa);
#endif

#if VERSION_USA
void DrawTetris(struct_gInfo_unk_00068 *arg0) {
    if (gCounter < 2) {
        return;
    }

    if (gTheGame.unk_9C0C == 2) {
        Draw3DTetris(arg0);
    } else {
        Draw2DTetris(arg0);
    }

    if (gMain == GMAIN_384) {
        if (gCounter == 2) {
            func_8004FABC_usa();
        } else if (gCounter == 4) {
            func_80050420_usa();
        } else {
            if (gCounter < 0x64) {
                func_8005076C_usa();
            }
            if (gCounter > 0x62) {
                func_80050C2C_usa();
            }
        }
    }
}
#endif

#if VERSION_USA
INLINE void OverFlow(struct_gInfo_unk_00068 *arg0) {
    s32 var_s0;

    if ((gTheGame.unk_9C08 == 1) || (arg0->unk_10240 < 0x321)) {
        gLastOverflow = 0x320;
        return;
    }

    if (arg0->unk_10240 >= gLastOverflow + 0x6E) {
        gLastOverflow = gLastOverflow + 0x6E;
    } else if (gLastOverflow - 0x50 >= arg0->unk_10240) {
        gLastOverflow = gLastOverflow - 0x50;
    } else {
        gLastOverflow = arg0->unk_10240;
    }

    var_s0 = gLastOverflow - 0x320;
    var_s0 = MIN(var_s0, 0x1194);

    var_s0 = var_s0 / 10;
    while (var_s0 > 0) {
        s32 var_v1 = MIN(var_s0, 0xE8);

        gTheGame.unk_9A50.b.frameH = var_v1 * 4;
        var_s0 -= 0xE8;
        Draw2DBackground();
    }

    gTheGame.unk_9A50.b.frameH = 0xE8 * 4;
}
#endif

#if VERSION_USA
void Draw2DTetris(struct_gInfo_unk_00068 *arg0) {
    s32 sp10[GAME_BUFFER_LEN];
    s32 i;

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 7, SCREEN_WIDTH, SCREEN_HEIGHT - 1);

    Draw2DBackground();

    if (gOverflowFlag != 0) {
        OverFlow(arg0);
    }

    Draw2DAnimation(arg0, 1, 3);
    if ((gMain != GMAIN_384) || (gCounter >= 0x64)) {
        Draw2DShadeBox();

        gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 31, SCREEN_WIDTH, SCREEN_HEIGHT - 17);
        gDPPipeSync(glistp++);
        gDPSetTextureLUT(glistp++, G_TT_RGBA16);
        gSPObjLoadTxtr(glistp++, &colorLUT);

        Draw2DGameFade();

        for (i = 0; i < gTheGame.unk_9C08; i++) {
            Draw2DTetrisWell(arg0, &gTheGame.tetrisWell[i], i);
            sp10[i] = Draw2DAttackBlock(arg0, i);
        }

        gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 7, SCREEN_WIDTH, SCREEN_HEIGHT - 1);

        Draw2DFrame();
        Draw2DAnimation(arg0, 4, 4);
        Draw2DText(arg0);
        Draw2DMiscStuff(arg0);
        Draw2DAnimation(arg0, 5, 6);
        if ((gSelection == 0xAA) || (gSelection == 0xB4)) {
            for (i = 0; i < gTheGame.unk_9C08; i++) {
                Draw2DClearLine(arg0, i);
            }
        }

        if (gMain != GMAIN_388) {
            for (i = 0; i < gTheGame.unk_9C08; i++) {
                Draw2DAttackBrick(arg0, i, sp10[i]);
                Draw2DExplosion(arg0, i);
                Draw2DIcon(arg0, i);
            }
        }

        if ((gMain == GMAIN_387) || (gMain == GMAIN_384)) {
            gDPPipeSync(glistp++);
            gDPSetTextureLUT(glistp++, G_TT_RGBA16);
            gSPObjLoadTxtr(glistp++, &colorLUT);
            Draw2DCursor(arg0);
        }

        if (gMain >= GMAIN_388) {
            DrawPauseOver(arg0);
        } else if (gMain == GMAIN_384) {
            DrawCountDown();
        }
    }
}
#endif
