/**
 * Original filename: tutorial.h
 */

#include "tutorial.h"

#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "image.h"
#include "menu.h"
#include "mimic.h"
#include "peel.h"
#include "screen.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tutorial", func_80087A90_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tutorial", InitTutorial);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tutorial", TutorialCheckState);
#endif

#if VERSION_USA
// Probably equivalent.
#ifdef NON_EQUIVALENT
extern s32 B_80193020_usa;

// The following variables are supposed to be part of the same struct. But the start address is unknown.
extern s32 B_801AD9D4_usa;
extern s32 B_801AD9D8_usa;
extern s32 B_801AD9DC_usa;
extern s32 B_801AD9E8_usa;

static inline void inlined_func(s32 var_a2) {
    s32 var_s1;
    s32 var_s0;

    if (var_a2 != -1) {
        s32 temp_s2 = ((B_80193020_usa & 0xFFFF) == 0x258) ? 0x259 : 0x258;

        if ((B_80193020_usa == 0) || ((B_80193020_usa >> 0x10) != var_a2)) {
            switch (var_a2) {
                case 1:
                    var_s1 = 0x8D;
                    var_s0 = 0x3C;
                    break;
                case 2:
                    var_s1 = 0x7C;
                    var_s0 = 0x3F;
                    break;
                case 0:
                    var_s1 = 0xBC;
                    var_s0 = 0x3F;
                    break;

                default:
                    return;
            }

            B_80193020_usa = (var_a2 << 0x10) | temp_s2;
            func_80028DC0_usa(B_801AD9D8_usa, temp_s2, var_a2);
            func_800288D8_usa(B_801AD9D8_usa, temp_s2, var_s1, var_s0);
        }
    }
}

static inline void inlined_func2(u16 temp) {
    s32 var_s0_2;
    s32 temp2 = temp;
    struct_imageLoad_arg0 *sp28;

    if (temp2 == 0x258) {
        var_s0_2 = 0x259;
    } else if (temp2 == 0x259) {
        var_s0_2 = 0x258;
    } else {
        return;
    }

    if (func_8002864C_usa(B_801AD9D8_usa, temp2, &sp28)) {
        if (sp28->unk_14 < 0xFF) {
            sp28->unk_14 += 8;
            if (sp28->unk_14 > 0xFF) {
                sp28->unk_14 = 0xFF;
            }
        }
    }

    if (func_8002864C_usa(B_801AD9D8_usa, var_s0_2, &sp28)) {
        if (sp28->unk_14 > 0) {
            sp28->unk_14 -= 8;
            if (sp28->unk_14 < 0) {
                sp28->unk_14 = 0;
            }
        }
    }
}

void DoTutorial(void) {
    screenTick_arg0 sp20;
    struct_imageLoad_arg0 *sp28;
    s32 temp_a0;
    s32 temp_s2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_v0;
    u16 temp;
    s32 temp2;

    s32 a0;
    s32 a1;
    s32 a2;
    s32 a3;
    s32 a4;
    s32 a5;
    s32 a6;
    s32 a7;

    sp20.unk_0 = 0;
    sp20.unk_4 = 0;

    if (!screenFlushing()) {
        peelTick();
    }

    screenSetBackLayers(0);

    a0 = B_801AD9D8_usa;
    a1 = gCounter;
    a2 = B_801AD9E8_usa;
    a3 = 0x4FFFC;
    a4 = -0x3F0018;
    a5 = 0x520002;
    a6 = B_801AD9DC_usa;
    a7 = B_801AD9D4_usa;
    menuTickFairy(a0, a1, a2, a3, a4, a5, a6, a7);
    DoMT();

    var_a2 = -1;
    temp2 = B_801AD9E8_usa;
    switch (gTheGame.unk_9C28) {
        case 0x1:
            // Why the `&=`?
            var_a2 &= (temp2 != 0x64) ? -1 : 0;
            if (temp2 == 0x67) {
                var_a2 = 1;
            }
            var_a2 = (temp2 != 0x7C) ? var_a2 : 0;
            break;
        case 0x2:
            var_a2 &= (temp2 != 0x64) ? -1 : 0;
            if (temp2 == 0x66) {
                var_a2 = 1;
            }
            var_a2 = (temp2 != 0x76) ? var_a2 : 0;
            break;
        case 0x5:
            var_a2 &= (temp2 != 0x64) ? -1 : 0;
            if (temp2 == 0x68) {
                var_a2 = 1;
            }
            var_a2 = (temp2 != 0x77) ? var_a2 : 0;
            break;
        case 0x3:
            if (temp2 == 0x64) {
                var_a2 = 2;
            }
            break;
        case 0x4:
            var_a2 &= (temp2 != 0x64) ? -1 : 0;
            if (temp2 == 0x66) {
                var_a2 = 1;
            }
            break;
    }

    inlined_func(var_a2);
    inlined_func2(B_80193020_usa);

    screenTick(&sp20);
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/tutorial", DoTutorial);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tutorial", func_8008885C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tutorial", func_800888C4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tutorial", func_80087E40_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tutorial", InitTutorial);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tutorial", TutorialCheckState);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tutorial", DoTutorial);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tutorial", func_80088C0C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tutorial", func_80088C74_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tutorial", func_80086560_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tutorial", InitTutorial);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tutorial", TutorialCheckState);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tutorial", DoTutorial);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tutorial", func_8008732C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tutorial", func_80087394_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tutorial", func_80086720_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tutorial", InitTutorial);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tutorial", TutorialCheckState);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tutorial", DoTutorial);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tutorial", func_800874EC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tutorial", func_80087554_ger);
#endif
