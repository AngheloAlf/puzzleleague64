/**
 * Original filename: story.c
 */

#include "story.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "segment_symbols.h"

#include "buffers.h"
#include "info.h"
#include "menu.h"
#include "peel.h"
#include "screen.h"
#include "sfxlimit.h"
#include "sound.h"
#include "the_game.h"

#include "041780.h"
#include "043000.h"
#include "043D10.h"
#include "044E80.h"

#define STRUCT_8018E570_USA_UNK_LEN 0x10

typedef struct struct_8018E570_usa {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ void *unk_10; // heap
    /* 0x14 */ void *unk_14;
    /* 0x18 */ s32 unk_18[STRUCT_8018E570_USA_UNK_LEN];
    /* 0x58 */ s32 unk_58[STRUCT_8018E570_USA_UNK_LEN];
} struct_8018E570_usa; // size = 0x98

extern struct_8018E570_usa *B_8018E570_usa;

void storyDrawImage(Gfx **gfxP UNUSED, UNK_TYPE arg1 UNUSED, UNK_TYPE arg2 UNUSED) {
}

INLINE void func_8002B5D8_usa(Gfx **gfxP) {
    screenDraw(gfxP, storyDrawImage);
}

STATIC_INLINE void inlined_func(void) {
    if (gTheGame.menu[0].unk_4 == 0x10) {
        func_8002B85C_usa(5, 7);
    } else if (gTheGame.menu[0].unk_4 == 0xC) {
        func_8002B85C_usa(2, 1);
    } else if (gTheGame.menu[0].unk_4 >= 2) {
        func_8002B85C_usa(3, 1);
    } else {
        func_8002B85C_usa(2, 0);
    }
}

void func_8002B600_usa(UNK_TYPE4 arg0 UNUSED) {
    s32 temp_s1;
    s32 temp_v0_2;
    s32 var_s0;

    switch (gTheGame.menu[0].unk_0) {
        case 0x1:
            var_s0 = 0xB;
            break;

        case 0x2:
            var_s0 = 0xE;
            break;

        case 0x3:
            var_s0 = 0xF;
            break;

        case 0x4:
            var_s0 = 0x10;
            break;

        case 0x5:
            var_s0 = 0x10;
            break;
    }

    temp_s1 = gTheGame.menu[0].unk_4;
    temp_v0_2 = screenGet();
    if (temp_v0_2 != -1) {
        if ((gTheGame.controller[0].touch_button & (U_JPAD | R_JPAD)) && (temp_s1 < var_s0)) {
            temp_s1++;
        }

        if (((gTheGame.controller[0].touch_button & (D_JPAD | L_JPAD))) && (temp_s1 >= 2)) {
            temp_s1--;
        }

        if (gTheGame.controller[0].touch_button & A_BUTTON) {
            inlined_func();
            PlaySE(SFX_INIT_TABLE, 2);
        }

        if (temp_s1 != gTheGame.menu[0].unk_4) {
            gTheGame.menu[0].unk_4 = temp_s1;
            PlaySE(SFX_INIT_TABLE, 1);
            screenSetNumber(temp_v0_2, 0x64, gTheGame.menu[0].unk_4, -1);
        }
    }
}

INLINE void func_8002B76C_usa(void **heapP) {
    if (screenLoad("CHEAT.SBF", heapP) != 0) {
        screenSetNumber(screenSet("CHEAT", 0x400), 0x64, gTheGame.menu[0].unk_4, -1);
    }
}

nbool func_8002B7C8_usa(s32 arg0, s32 arg1) {
    s32 temp_v0;

    if (arg1 < 0) {
        arg1 = -arg1;
    }

    temp_v0 = func_80001ED8_usa();
    if (temp_v0 >= 0) {
        FadeOutAllSFXs(0x1E);
        func_80002D8C_usa(0x1E);
        if (arg1 > 0) {
            func_80002F88_usa(arg1);
        }
        PlayMIDI(BGM_INIT_TABLE, arg0, temp_v0, arg1 > 0);
        return ntrue;
    }
    return nfalse;
}

INLINE nbool func_8002B85C_usa(s32 arg0, s32 arg1) {
    if (B_8018E570_usa->unk_00 < STRUCT_8018E570_USA_UNK_LEN) {
        B_8018E570_usa->unk_04 = B_801C7060_usa + 2;
        B_8018E570_usa->unk_58[B_8018E570_usa->unk_00] = arg0;
        B_8018E570_usa->unk_18[B_8018E570_usa->unk_00] = arg1;
        return ntrue;
    }
    return nfalse;
}

nbool func_8002B8B0_usa(s32 *arg0) {
    if (B_8018E570_usa->unk_00 > 0) {
        *arg0 = B_8018E570_usa->unk_58[B_8018E570_usa->unk_00 - 1];
        return ntrue;
    }
    *arg0 = 0;
    return nfalse;
}

void DoStory(void) {
    screenTick_arg0 sp10;
    void *heap;

    B_8018E570_usa->unk_08++;
    if (B_8018E570_usa->unk_04 > 0) {
        return;
    }

    if (B_8018E570_usa->unk_04 == 0) {
        s32 s0 = 0;
        s32 temp_a1;

        heap = B_8018E570_usa->unk_10;

        B_8018E570_usa->unk_04 = -1;
        B_8018E570_usa->unk_08 = 0;
        temp_a1 = B_8018E570_usa->unk_18[B_8018E570_usa->unk_00];
        switch (B_8018E570_usa->unk_58[B_8018E570_usa->unk_00]) {
            case 0:
                break;

            case 0x1:
                func_8002B76C_usa(&heap);
                break;

            case 0x2:
                func_80041F1C_usa(&heap, temp_a1);
                break;

            case 0x3:
                func_80042C24_usa(&heap, temp_a1);
                break;

            case 0x4:
                func_8004407C_usa(&heap, temp_a1);
                break;

            case 0x5:
                func_80046C2C_usa(&heap, temp_a1);
                break;
        }

        B_8018E570_usa->unk_14 = heap;
        B_8018E570_usa->unk_00 += 1;

        if (s0 != 0) {
            if (gPlayer[0] != NULL) {
                menuSaveData(gPlayer[0]->unk_000);
            }

#if VERSION_USA || VERSION_EUR
            if (gPlayer[1] != NULL) {
                menuSaveData(gPlayer[1]->unk_000);
            }
#endif
        }
    } else {
        if (screenFlushing()) {
            gTheGame.controller[0].touch_button = 0;
            gTheGame.controller[0].hold_button = 0;
            gTheGame.controller[1].touch_button = 0;
            gTheGame.controller[1].hold_button = 0;
        }

        sp10.unk_0 = 0;
        sp10.unk_4 = 0;
        if (gTheGame.controller[0].touch_button & U_JPAD) {
            sp10.unk_0 = 1;
        }
        if (gTheGame.controller[0].touch_button & D_JPAD) {
            sp10.unk_0 = 2;
        }
        if (gTheGame.controller[0].touch_button & L_JPAD) {
            sp10.unk_0 = 3;
        }
        if (gTheGame.controller[0].touch_button & R_JPAD) {
            sp10.unk_0 = 4;
        }
        screenTick(&sp10);

        if (sp10.unk_0 != 0) {
            PlaySE(SFX_INIT_TABLE, 1);
        }

        if (B_8018E570_usa->unk_00 > 0) {
            if (gTheGame.controller[0].touch_button & B_BUTTON) {
                nbool var_a3 = ((B_8018E570_usa->unk_58[B_8018E570_usa->unk_00 - 1] == 2) &&
                                (B_8018E570_usa->unk_18[B_8018E570_usa->unk_00 - 1] == 1))
                                   ? ntrue
                                   : nfalse;

                if ((B_8018E570_usa->unk_58[B_8018E570_usa->unk_00 - 1] == 1) |
                        (B_8018E570_usa->unk_58[B_8018E570_usa->unk_00 - 1] == 4) ||
                    (B_8018E570_usa->unk_58[B_8018E570_usa->unk_00 - 1] == 3) || var_a3) {
                    if ((B_8018E570_usa->unk_58[B_8018E570_usa->unk_00 - 1] == 3) && (B_8018E570_usa->unk_00 >= 2) &&
                        (B_8018E570_usa->unk_58[B_8018E570_usa->unk_00 - 2] == 2) &&
                        (B_8018E570_usa->unk_18[B_8018E570_usa->unk_00 - 2] == 0)) {
                        B_8018E570_usa->unk_00 = B_8018E570_usa->unk_00 - 1;
                    }

                    if ((B_8018E570_usa->unk_00 >= 2) && !var_a3) {
                        B_8018E570_usa->unk_00 -= 2;
                        func_8002B85C_usa(B_8018E570_usa->unk_58[B_8018E570_usa->unk_00],
                                          B_8018E570_usa->unk_18[B_8018E570_usa->unk_00]);
                        PlaySE(SFX_INIT_TABLE, 6);
                    } else {
                        gMain = GMAIN_2BC;
                        gReset = -1;
                    }
                }
            } else {
                switch (B_8018E570_usa->unk_58[B_8018E570_usa->unk_00 - 1]) {
                    case 0x1:
                        func_8002B600_usa(B_8018E570_usa->unk_08);
                        break;

                    case 0x2:
                        func_8004123C_usa(B_8018E570_usa->unk_08);
                        break;

                    case 0x3:
                        func_800428B4_usa(B_8018E570_usa->unk_08);
                        break;

                    case 0x4:
                        func_80043D24_usa(B_8018E570_usa->unk_08);
                        break;

                    case 0x5:
                        func_80046648_usa(B_8018E570_usa->unk_08);
                        break;
                }
            }
        }

        if (!screenFlushing() && (B_8018E570_usa->unk_04 == -1)) {
            peelTick();
        }
    }
}

void DrawStory(struct_gInfo_unk_00068 *arg0 UNUSED) {
    if (B_8018E570_usa->unk_04 > 0) {
        B_8018E570_usa->unk_04--;
    } else if (B_8018E570_usa->unk_00 > 0) {
        Gfx *gfx = glistp;

        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR |
                                        G_LOD | G_CLIPPING);
        gSPSetGeometryMode(gfx++, G_SHADE | G_SHADING_SMOOTH);

        switch (B_8018E570_usa->unk_58[B_8018E570_usa->unk_00 - 1]) {
            case 0x1:
                func_8002B5D8_usa(&gfx);
                break;

            case 0x2:
                func_80040DE4_usa(&gfx);
                break;

            case 0x3:
                func_80042400_usa(&gfx);
                break;

            case 0x4:
                func_80043CFC_usa(&gfx);
                break;

            case 0x5:
                func_800449C4_usa(&gfx);
                break;
        }

        if (!screenFlushing()) {
            func_8002C2C0_usa(&gfx);
        }

        glistp = gfx;
    }
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
void InitStory(void) {
    void *var_a0;
    void *temp_a2;

    var_a0 = gBufferHeap + 3;
    var_a0 = (uintptr_t)(SEGMENT_ROM_SIZE(segment_0CA4A0) + (var_a0)) & ~3;
    B_8018E570_usa = var_a0;
    temp_a2 = (uintptr_t)var_a0 + sizeof(struct_8018E570_usa);
    B_8018E570_usa->unk_0C = 0;
    B_8018E570_usa->unk_08 = 0;
    B_8018E570_usa->unk_00 = 0;
    B_8018E570_usa->unk_10 = temp_a2;
    B_8018E570_usa->unk_04 = -1;

    if (gSelection != 0x96) {
        if ((gSelection == 0x8C) || (gSelection == 0xBE)) {
            func_8002B85C_usa(2, 0);
        } else if (gSelection == 0xAA) {
            gPlayer[0]->unk_02B.unk_5 |= 0x20;
            menuSaveData(gPlayer[0]->unk_000);

            func_8002B85C_usa(2, 9);
        } else if (gSelection == 0x82) {
            s32 sp10;

            if (func_80008EA4_usa(&sp10, gSelection, temp_a2)) {
                func_8002B85C_usa(2, sp10);
            } else {
                gMain = GMAIN_2BC;
                gReset = -1;
            }
        } else if ((gSelection == 0xA0) || (gSelection == 0xB4) || (gSelection == 0xC8)) {
            func_8002B85C_usa(2, 0);
        } else {
            func_8002B85C_usa(5, 0);
        }
    } else if (gTheGame.menu[0].unk_4 == 0x13) {
        gTheGame.menu[0].unk_4 = 0xF;
        func_8002B85C_usa(3, 5);
    } else if (gTheGame.menu[0].unk_4 == 0x11) {
        if ((gTheGame.cursorBlock[0].unk_00 == 7) || (gTheGame.cursorBlock[1].unk_00 == 8)) {
            func_8002B85C_usa(5, 8);
        } else {
            func_8002B85C_usa(5, 9);
        }
    } else {
        if (gTheGame.menu[0].unk_C == 0) {
            inlined_func();
        } else {
            if (gTheGame.menu[0].unk_4 == 0x2) {
                func_8002B85C_usa(3, 2);
            } else if (gTheGame.menu[0].unk_4 == 0xA) {
                func_8002B85C_usa(3, 3);
            } else if (gTheGame.menu[0].unk_4 == 0xB) {
                func_8002B85C_usa(3, 4);
            } else {
                func_8002B85C_usa(2, 0);
            }
        }
        gTheGame.menu[0].unk_C += 1;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/story", InitStory);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/story", InitStory);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/story", InitStory);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/story", InitStory);
#endif

#if VERSION_USA
// hack to ensure correct alignment of rodata
static const f64 sFileBumpRodataAlignment UNUSED = 0;
#endif
