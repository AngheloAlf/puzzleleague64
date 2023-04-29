/**
 * Original filename: puzzle.c
 */

#include "puzzle.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "assets_variables.h"
#include "tetris.h"
#include "update.h"
#include "draw2d.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088940_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088A48_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088AB4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088C08_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088D34_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088E38_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088F94_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80089108_usa);
#endif

#if VERSION_USA
#if 0
// ? func_8006B314_usa(TheGame *, ?, s32 *);           /* extern */
// s32 func_80088AB4_usa(TheGame *, TheGame_unk_8860 *, void *, ?); /* extern */

s32 func_8008913C_usa(s32 arg0) {
    s32 var_v0;
    u8 temp_v0;
    void *temp_s0;

    temp_s0 = gPlayer + (((arg0 - 1) * 0x6E) + 0x121);
    if (gTheGame.unk_9C30 == 0) {
        temp_v0 = (gPlayer + arg0)->unk_792;
        gTheGame.unk_9C30 = (s32) temp_v0;
        gTheGame.unk_0000[0].unk_4408[0x20] = (s32) temp_v0;
    }
    func_8006B314_usa(&gTheGame, 0, &gTheGame.unk_9C30);
    var_v0 = -1;
    if (func_80088AB4_usa(&gTheGame, gTheGame.unk_8860, temp_s0, 1) == 0) {
        func_8006B314_usa(&gTheGame, 0);
        var_v0 = 0;
    }
    return var_v0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_8008913C_usa);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80089200_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_8008928C_usa);
#endif

#if VERSION_USA
void InitPuzzleEditor(s32 arg0 UNUSED) {
    InitTetrisWell();
}
#endif

#if VERSION_USA
void DoPuzzleEditor(void) {
    Init2DTetrisBlocksTMEM(&gTheGame, -1);
    UpdateAnimation(&gTheGame, 0, 0);
}
#endif

#if VERSION_USA
void DrawPuzzleEditor(struct_gInfo_unk_00068 *arg0) {
    Update2DBuffer(*fb);

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 1);
    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_FILL);
    gDPSetFillColor(glistp++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
    gDPFillRectangle(glistp++, 0, 0, 319, 6);
    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);

    Draw2DBackground();
    Draw2DAnimation(arg0, 1, 3);
    gBox_Level = 0x8C;
    Draw2DShadeBox();

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 31, SCREEN_WIDTH, 223);
    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &colorLUT);
    gDPPipeSync(glistp++);
    gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);

    Draw2DTetrisWell(arg0, &gTheGame.unk_0000[0], 0);

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 7, SCREEN_WIDTH, SCREEN_HEIGHT - 1);

    Draw2DFrame();
    Draw2DAnimation(arg0, 4, 4);

    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_FILL);
    gDPSetFillColor(glistp++, (GPACK_RGBA5551(99, 99, 99, 1) << 16) | GPACK_RGBA5551(99, 99, 99, 1));
    gDPFillRectangle(glistp++, 226, 26, 287, 140);
    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);

    Draw2DAnimation(arg0, 5, 6);
}
#endif
