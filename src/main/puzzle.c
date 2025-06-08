/**
 * Original filename: puzzle.c
 */

#include "puzzle.h"

#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "assets_variables.h"

#include "animation.h"
#include "bkground.h"
#include "draw2d.h"
#include "flic.h"
#include "init2d.h"
#include "tetris.h"
#include "update.h"

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
// ? func_8006B314_usa(Game *, ?, s32 *);           /* extern */
// s32 func_80088AB4_usa(Game *, cursor_t *, void *, ?); /* extern */

s32 func_8008913C_usa(s32 arg0) {
    s32 var_v0;
    u8 temp_v0;
    void *temp_s0;

    temp_s0 = gPlayer + (((arg0 - 1) * 0x6E) + 0x121);
    if (gTheGame.unk_9C2C[0][1] == 0) {
        temp_v0 = (gPlayer + arg0)->unk_792;
        gTheGame.unk_9C2C[0][1] = (s32) temp_v0;
        gTheGame.tetrisWell[0].unk_4408[0x20] = (s32) temp_v0;
    }
    func_8006B314_usa(&gTheGame, 0, &gTheGame.unk_9C2C[0][1]);
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
    Init2DTetrisBlocksTMEM(&gTheGame.tetrisWell[0], -1);
    UpdateAnimation(&gTheGame.tetrisWell[0], 0, 0);
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

    Draw2DTetrisWell(arg0, &gTheGame.tetrisWell[0], 0);

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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80088940_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80088A48_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80088AB4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80088C08_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80088D34_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80088E38_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80088F94_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80089108_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_8008913C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80089200_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_8008928C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_800896C8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", DoPuzzleEditor);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", DrawPuzzleEditor);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087410_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087518_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087584_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_800876D8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087804_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087908_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087A64_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80089108_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087C0C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087CD0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087D5C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087DE8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087E08_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087E4C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_800875D0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_800876D8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80087744_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80087898_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_800879C4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80087AC8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80087C24_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80089108_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80087DCC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80087E90_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80087F1C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80087FA8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80087FC8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_8008800C_ger);
#endif
