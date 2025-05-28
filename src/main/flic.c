/**
 * Original name: flic.c
 */

#include "flic.h"

#include "include_asm.h"

#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "bg_screen_load.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", InitFlic);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/flic", func_8004E4E4_usa);
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
