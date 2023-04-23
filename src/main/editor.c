/**
 * Original filename: editor.c
 */

#include "editor.h"
#include "libultra.h"
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

typedef void (*struct_gaEditData_unk_4)(s32 arg0, screenTick_arg0 *arg1);

typedef struct struct_gaEditData {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ struct_gaEditData_unk_4 unk_4;
} struct_gaEditData; // size = 0x8

extern void *Pon_Image_Heap;
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
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002DC00_usa);
#endif

#if VERSION_USA
s32 func_8002EDF0_usa(s32 arg0) {
    if (arg0 != 0) {
        return -1;
    }

    return 0;
}
#endif

#if VERSION_USA
Lights1 D_800B6450_usa = {
    { { { 0x40, 0x40, 0x40 }, 0, { 0x40, 0x40, 0x40 }, 0 } },
    { { { { 0xE0, 0xE0, 0xE0 }, 0, { 0xE0, 0xE0, 0xE0 }, 0, { 0, -1, 0 }, 0 } } },
};
s32 D_800B6468_usa = 0;
f32 D_FLT_800B646C_usa = 0.0f;
#endif

extern Mtx B_8018E940_usa[2];

typedef struct struct_8002EDFC_usa_arg0 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x4];
    /* 0x4 */ Gfx ***unk_4;
    /* 0x8 */ UNK_TYPE4 unk_8;
} struct_8002EDFC_usa_arg0; // size >= 0xC

#if VERSION_USA
s32 func_8002EDFC_usa(struct_8002EDFC_usa_arg0 *arg0, Gfx **gfxP) {
    Gfx *gfx;

    D_800B6468_usa++;

    D_FLT_800B646C_usa += 1.0;
    if (D_FLT_800B646C_usa >= 360.0) {
        D_FLT_800B646C_usa = D_FLT_800B646C_usa - 360.0;
    }

    if (arg0 == NULL) {
        return 0;
    }

    gfx = *gfxP;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BOTH);
    gSPSetGeometryMode(gfx++, G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetRenderMode(gfx++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gSPSetLights1(gfx++, D_800B6450_usa);

    guRotate(&B_8018E940_usa[D_800B6468_usa % ARRAY_COUNTU(B_8018E940_usa)], D_FLT_800B646C_usa, 0.0f, 1.0f, 0.0f);

    gSPMatrix(gfx++, &B_8018E940_usa[D_800B6468_usa % ARRAY_COUNTU(B_8018E940_usa)],
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, *arg0->unk_4[(D_800B6468_usa & 0xFF) % arg0->unk_8]);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);

    *gfxP = gfx;

    return -1;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/editor", func_8002F194_usa);
#endif

#if VERSION_USA
void func_8002F2E0_usa(void) {
}
#endif

#if VERSION_USA
void func_8002F2E8_usa(void) {
}
#endif

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
void DrawEditor(Gfx *gfx) {
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

    if (screenFlushing() == 0) {
        DrawPuzzleEditor(gfx);
    }

    screenDraw(&glistp, editDrawImage);
    if (screenFlushing() == 0) {
        func_8002C2C0_usa(&glistp);
    }
}
#endif

#if VERSION_USA
void DoEditor(void) {
    screenTick_arg0 sp10;
    struct_gaEditData *sp18;

    if ((screenFlushing() == 0) && (gnFlushCount == -1)) {
        peelTick();
    }
    gnTickCount += 1;
    if ((screenFlushing() == 0) && (gnFlushCount == -1)) {
        DoPuzzleEditor();
    }

    sp10.unk_0 = 0;
    sp10.unk_4 = 0;
    if ((screenFlushing() == 0) && (gnFlushCount == -1)) {
        if (gTheGame.unk_89C4 & 0x4000) {
            sp10.unk_0 = 0x21;
        } else if (gTheGame.unk_89C4 & 0x8000) {
            sp10.unk_0 = 0x20;
        } else if (gTheGame.unk_89C4 & 0x20) {
            sp10.unk_0 = 0x18;
        } else if (gTheGame.unk_89C4 & 0x10) {
            sp10.unk_0 = 0x19;
        } else if (gTheGame.unk_89C4 & 0x1000) {
            sp10.unk_0 = 0x22;
        } else {
            if (gTheGame.unk_89C6 & 0x800) {
                sp10.unk_0 = 1;
            }
            if (gTheGame.unk_89C6 & 0x400) {
                sp10.unk_0 = 2;
            }
            if (gTheGame.unk_89C6 & 0x200) {
                sp10.unk_0 = 3;
            }
            if (gTheGame.unk_89C6 & 0x100) {
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
    func_80089318_usa(-1);
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
