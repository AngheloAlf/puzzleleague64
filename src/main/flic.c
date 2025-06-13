/**
 * Original name: flic.c
 */

#include "flic.h"

#include "include_asm.h"

#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "bg_screen_load.h"

extern s8 FlicLayer[6];

#if VERSION_USA
void InitFlic(void) {
    Game_unk_89E0 *var_v1;
    Game_unk_8B20 *var_v1_2;
    s32 var_a0;

    for (var_a0 = 0; var_a0 < GAME_UNK_89E0; var_a0++) {
        var_v1 = &gTheGame.unk_89E0[var_a0];
        var_v1->unk_00 = -1;
        var_v1->unk_04 = -1;
        var_v1->unk_08 = -1;
        var_v1->unk_0C = 0xA;
        var_v1->unk_10 = -1;
        var_v1->unk_14 = -1;
        var_v1->unk_18 = -1;
        var_v1->unk_1C = -1;
    }

    for (var_a0 = 0; var_a0 < GAME_UNK_8B20; var_a0++) {
        var_v1_2 = &gTheGame.unk_8B20[var_a0];
        var_v1_2->unk_0 = 0;
        var_v1_2->unk_4 = 0;
        var_v1_2->unk_8 = 0;
    }

    for (var_a0 = 0; var_a0 < ARRAY_COUNT(FlicLayer); var_a0++) {
        FlicLayer[var_a0] = 0xA;
    }
}
#endif

#if VERSION_USA
#if 0
void func_8004E4E4_usa(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 var_v0 = 0;

    if (arg2 != 0) {
        var_v0 = func_8004E5E8_usa(arg0, var_v0, (arg1 == 0) ? 5 : 0, arg2);
    }
    if (arg3 != 0) {
        var_v0 = func_8004E688_usa(arg0, var_v0, (arg1 == 0) ? 6 : 0, arg3);
    }
    if (arg4 != 0) {
        var_v0 = func_8004E8CC_usa(arg0, var_v0, (arg1 == 0) ? 5 : 0, arg4);
    }
    if (arg5 != 0) {
        var_v0 = func_8004E9D8_usa(arg0, var_v0, (arg1 == 0) ? 5 : 0, arg5);
    }
    if (arg6 != 0) {
        var_v0 = func_8004EAB8_usa(arg0, var_v0, (arg1 == 0) ? 5 : 0, arg6);
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", func_8004E4E4_usa);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", func_8004E5E8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", func_8004E688_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", func_8004E854_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", func_8004E8CC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", func_8004E9D8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", func_8004EAB8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", Draw2DAnimation);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", func_8004EC08_usa);
#endif

#if VERSION_USA
#ifdef NON_EQUIVALENT
void func_8004EC4C_usa(TexturePtr arg0, bool arg1, s32 main_height, s32 top_height) {
    s32 sp10[4];
    s32 var_a0;
    s32 var_s2;
    s32 var_v0;
    uObjBg *var_s0;
    s32 i;

    sp10[0] = main_height;
    sp10[1] = top_height;
    sp10[2] = top_height;
    sp10[3] = top_height;
    var_s2 = 0;

    if (arg1) {
        var_a0 = 0;
        var_v0 = 24;
    } else {
        var_a0 = 6;
        var_v0 = 188;
    }

    for (i = 0; i < 4; i++) {
        var_s0 = &gTheGame.unk_8C88[var_a0 + i];

        var_s0->b.imageX = 0;
        var_s0->b.imageW = BGSCREEN_TEX_WIDTH << 2;
        var_s0->b.frameX = var_v0 << 2;
        var_s0->b.frameW = (BGSCREEN_TEX_WIDTH - 4) << 2;

        var_s0->b.imageY = 0;
        var_s0->b.imageH = sp10[i] << 2;
        if (i == 0) {
            var_s0->b.frameY = (216 - sp10[i]) << 2;
        } else {
            var_s0->b.frameY = 24 << 2;
        }
        var_s0->b.frameH = sp10[i] << 2;

        var_s0->b.imagePtr = (TexturePtr)((uintptr_t)arg0 + var_s2);
        var_s0->b.imageLoad = G_BGLT_LOADTILE;
        var_s0->b.imageFmt = G_IM_FMT_RGBA;
        var_s0->b.imageSiz = G_IM_SIZ_16b;
        var_s0->b.imagePal = 0;
        var_s0->b.imageFlip = 0;

        guS2DInitBg(var_s0);
        var_s2 += sp10[i] * 224;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", func_8004EC4C_usa);
#endif
#endif
