/**
 * Original filename: fade.c
 */

#include "fade.h"

#include "macros_defines.h"
#include "main_variables.h"

#include "the_game.h"

/**
 * Original name: InitGameFade
 */
void InitGameFade(void) {
    gBox_Level = 0;
    gBlock_Level = 0;

    Flash_period[0] = 0;
    Flash_count[0] = 0;

    Flash_period[1] = 0x19;
    Flash_count[1] = 0;
}

/**
 * Original name: SetGameFade
 */
void SetGameFade(void) {
    gBox_Level = 0x8C;
    gBlock_Level = 0xFF;
}

void func_8005407C_usa(void) {
    if (gBlock_Level < 0xFF) {
        gBlock_Level -= 0x14;
    }
}

/**
 * Original name: DoGameFade
 */
void DoGameFade(s32 factor) {
    if (gMain == GMAIN_388) {
        if (gTheGame.totalPlayer == 1) {
            if (gSelection == SELECTION_82) {
                gBlock_Level = 0;
            }
            return;
        }

        if (gBox_Level > 0) {
            gBox_Level -= 5;
            if (gBox_Level < 0) {
                gBox_Level = 0;
            }
        }
        if (gBlock_Level > 0) {
            gBlock_Level -= 9;
            if (gBlock_Level < 0) {
                gBlock_Level = 0;
            }
        }
    } else if (gBlock_Level != 0xFF) {
        if (gBox_Level < 0x8C) {
            gBox_Level += factor * 4;
            if (gBox_Level >= 0x8D) {
                gBox_Level = 0x8C;
            }
        }
        if (gBlock_Level < 0xFF) {
            gBlock_Level += factor * 6;
            if (gBlock_Level >= 0x100) {
                gBlock_Level = 0xFF;
            }
        }
    }
}

/**
 * Original name: Draw2DGameFade
 */
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

/**
 * Original name: Draw3DGameFade
 */
void Draw3DGameFade(void) {
    if (gBlock_Level == 255) {
        gDPPipeSync(glistp++);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        gDPSetRenderMode(glistp++, G_RM_RA_OPA_SURF, G_RM_RA_OPA_SURF2);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
    } else {
        gDPPipeSync(glistp++);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, gBlock_Level);
    }
}

/**
 * Original name: StartFlash
 */
void StartFlash(s32 frame) {
    Flash_period[0] = frame;
    Flash_count[0] = 0;
}

// TODO: enum for which?
/**
 * Original name: DoFlashDraw
 */
nbool DoFlashDraw(s32 which) {
    if (Flash_period[which] > 0) {
        Flash_period[which]--;

        Flash_count[which]++;

        if (Flash_count[which] < 0xB) {
            return nfalse;
        }

        if (Flash_count[which] >= 0x15) {
            Flash_count[which] = 1;
            return nfalse;
        }
    }

    return ntrue;
}

/**
 * Original name: DoFlashDrawAlways
 */
nbool DoFlashDrawAlways(void) {
    nbool ret = DoFlashDraw(1);

    Flash_period[1] = 0x19;
    return ret;
}
