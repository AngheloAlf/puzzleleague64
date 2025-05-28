/**
 * Original filename: editor.c
 */

#include "editor.h"
#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "screen.h"
#include "sound.h"
#include "file.h"
#include "image.h"
#include "peel.h"
#include "sfxlimit.h"
#include "puzzle.h"

typedef void (*struct_gaEditData_unk_4)(s32 arg0, screenTick_arg0 *arg1);

typedef struct struct_gaEditData {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ struct_gaEditData_unk_4 unk_4;
} struct_gaEditData; // size = 0x8

extern void *gpHeapEdit;

extern s32 B_8018E9C0_usa; // geMode?
extern s32 gnFlushCount;
extern s32 giScreenEdit;
extern s32 B_8018E9F0_usa; // gnCursorData?

extern s32 gnTickCount;
extern s16 B_8018E9D0_usa;
extern s16 B_8018E9D2_usa;
extern s32 B_8018E9DC_usa;
extern s32 B_8018E9E0_usa;
extern s32 B_8018E9E4_usa;
extern s32 B_801AB808_usa;
extern s32 B_801C6BD8_usa;

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/editor", RO_800C4470_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002F2F0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002F464_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002F73C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002F984_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002FCF0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002FF38_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_80030278_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_800304FC_usa);
#endif

void func_8002F73C_usa(s32 arg0, screenTick_arg0 *arg1);
void func_8002F984_usa(s32 arg0, screenTick_arg0 *arg1);
void func_8002FCF0_usa(s32 arg0, screenTick_arg0 *arg1);
void func_8002FF38_usa(s32 arg0, screenTick_arg0 *arg1);
void func_80030278_usa(s32 arg0, screenTick_arg0 *arg1);
void func_800304FC_usa(s32 arg0, screenTick_arg0 *arg1);
void func_80030D10_usa(s32 arg0, screenTick_arg0 *arg1);
void func_80030D6C_usa(s32 arg0, screenTick_arg0 *arg1);
void func_80030DC8_usa(s32 arg0, screenTick_arg0 *arg1);

#if VERSION_USA
struct_gaEditData gaEditData[] = {
    { 1, func_80030D10_usa }, { 2, func_8002F73C_usa }, { 3, func_8002F984_usa },
    { 4, func_80030D6C_usa }, { 5, func_8002FCF0_usa }, { 6, func_8002FF38_usa },
    { 7, func_80030278_usa }, { 8, func_800304FC_usa }, { 9, func_80030DC8_usa },
};
#endif

#if VERSION_USA
STATIC_INLINE s32 inlined_func(s32 arg0, struct_gaEditData **sp10) {
    s32 i;

    for (i = 0; i < ARRAY_COUNTU(gaEditData); i++) {
        if (gaEditData[i].unk_0 == arg0) {
            *sp10 = &gaEditData[i];
            return -1;
        }
    }

    return 0;
}
#endif

#if VERSION_USA
INLINE s32 func_800306B0_usa(s32 arg0) {
    struct_gaEditData *sp10;

    if (arg0 == 0) {
        return 0;
    }

    if ((arg0 < 12) && (arg0 >= 10)) {
        gnFlushCount = 1;
    } else {
        if (inlined_func(arg0, &sp10) == 0) {
            return 0;
        }
        screenHideText(giScreenEdit, 0x812B80C8);
    }

    B_8018E9C0_usa = arg0;
    if (arg0 == 1) {
        B_8018E9F0_usa = -1;
    }

    return -1;
}
#endif

#if VERSION_USA
void DrawEditor(struct_gInfo_unk_00068 *arg0) {
    if (gnFlushCount > 0) {
        gnFlushCount = gnFlushCount - 1;
        if (gnFlushCount == 0) {
            gReset = -1;
            if (B_8018E9C0_usa == 0xA) {
                gMain = GMAIN_2BC;
            } else if (B_8018E9C0_usa == 0xB) {
                gMain = GMAIN_384;
                gSelection = 0x82;
                gTheGame.unk_9C08 = 1;
                gTheGame.unk_9C0C = 1;
                gTheGame.unk_9C28 = 0;
                gTheGame.unk_9C30 = 0;
                gTheGame.unk_0000[0].unk_4404 = 0;
                gTheGame.unk_0000[1].unk_4404 = 0;
                B_801AD9BC_usa = -1;
                B_801ADAE8_usa = -1;
                gTheGame.unk_9C2C = B_801AB808_usa;
            }
        }
    }

    if (!screenFlushing()) {
        DrawPuzzleEditor(arg0);
    }

    screenDraw(&glistp, editDrawImage);
    if (!screenFlushing()) {
        func_8002C2C0_usa(&glistp);
    }
}
#endif

#if VERSION_USA
void DoEditor(void) {
    screenTick_arg0 sp10;
    struct_gaEditData *sp18;

    if (!screenFlushing() && (gnFlushCount == -1)) {
        peelTick();
    }
    gnTickCount += 1;
    if (!screenFlushing() && (gnFlushCount == -1)) {
        DoPuzzleEditor();
    }

    sp10.unk_0 = 0;
    sp10.unk_4 = 0;
    if (!screenFlushing() && (gnFlushCount == -1)) {
        if (gTheGame.unk_89C4[0].unk_00 & 0x4000) {
            sp10.unk_0 = 0x21;
        } else if (gTheGame.unk_89C4[0].unk_00 & 0x8000) {
            sp10.unk_0 = 0x20;
        } else if (gTheGame.unk_89C4[0].unk_00 & 0x20) {
            sp10.unk_0 = 0x18;
        } else if (gTheGame.unk_89C4[0].unk_00 & 0x10) {
            sp10.unk_0 = 0x19;
        } else if (gTheGame.unk_89C4[0].unk_00 & 0x1000) {
            sp10.unk_0 = 0x22;
        } else {
            if (gTheGame.unk_89C4[0].unk_02 & 0x800) {
                sp10.unk_0 = 1;
            }
            if (gTheGame.unk_89C4[0].unk_02 & 0x400) {
                sp10.unk_0 = 2;
            }
            if (gTheGame.unk_89C4[0].unk_02 & 0x200) {
                sp10.unk_0 = 3;
            }
            if (gTheGame.unk_89C4[0].unk_02 & 0x100) {
                sp10.unk_0 = 4;
            }
        }
    }

    if (inlined_func(B_8018E9C0_usa, &sp18) != 0) {
        screenHideImage(giScreenEdit, 0x812B8064);
        sp18->unk_4(gnTickCount, &sp10);
    }

    screenTick(&sp10);
    if (sp10.unk_0 != 0) {
        PlaySE(SFX_INIT_TABLE, 1);
    }
}
#endif

#if VERSION_USA
void InitEditor(void) {
    B_8018E9C0_usa = 0;
    gnTickCount = 0;
    gnFlushCount = -1;
    B_8018E9F0_usa = -1;
    giScreenEdit = -1;
    InitPuzzleEditor(-1);
    func_8008913C_usa(B_801AB808_usa);
    gTheGame.unk_9C34 = 0;
    B_8018E9DC_usa = 3;
    B_8018E9E0_usa = 1;
    B_8018E9E4_usa = 1;
    B_8018E9D2_usa = 0;
    B_8018E9D0_usa = 0;
    gpHeapEdit = Pon_Image_Heap;

    if (screenLoad("EDITOR.SBF", &gpHeapEdit) != 0) {
        giScreenEdit = screenSet("MAIN", 0xFF001);

        switch (B_801C6BD8_usa) {
            case 0:
                func_800306B0_usa(9);
                break;

            case 1:
                func_800306B0_usa(1);
                break;

            case 3:
                func_800306B0_usa(4);
                break;

            case 2:
                func_800306B0_usa(8);
                break;

            default:
                func_800306B0_usa(10);
                break;
        }
    }

    func_80002A10_usa(0);
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_80030D10_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_80030D6C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_80030DC8_usa);
#endif

#if VERSION_USA
void editDrawImage(Gfx **gfxP, s32 arg1 UNUSED, s32 arg2) {
    Gfx *gfx = *gfxP;

    if (arg2 == 0xA) {
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gSPClearGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_SHADING_SMOOTH);
        gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
        gDPSetFillColor(gfx++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
        gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    }

    *gfxP = gfx;
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_8002F320_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_8002F494_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_8002F76C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_8002F9B4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_8002FD20_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_8002FF68_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_800302A8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_8003052C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_800306E0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", DrawEditor);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", DoEditor);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/editor", RO_800C47C0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", InitEditor);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_80030D40_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_80030D9C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_80030DF8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/editor", func_80030E38_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_8002F270_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_8002F3E4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_8002F6BC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_8002F904_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_8002FC70_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_8002FEB8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_800301F8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_8003047C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_80030640_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", DrawEditor);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", DoEditor);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/editor", RO_800C2E70_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", InitEditor);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_80030CA0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_80030CFC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_80030D58_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/editor", func_80030D98_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_8002F3E0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_8002F554_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_8002F82C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_8002FA74_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_8002FDE0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_80030028_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_80030368_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_800305EC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_800307B0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", DrawEditor);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", DoEditor);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/editor", RO_800B9E30_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", InitEditor);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_80030E10_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_80030E6C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_80030EC8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/editor", func_80030F08_ger);
#endif
