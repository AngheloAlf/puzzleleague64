/**
 * Original filename: editor.c
 */

#include "editor.h"

#include "macros_defines.h"
#include "main_variables.h"

#include "ai.h"
#include "file.h"
#include "image.h"
#include "info.h"
#include "peel.h"
#include "puzzle.h"
#include "screen.h"
#include "sfxlimit.h"
#include "sound.h"
#include "the_game.h"

typedef void (*struct_gaEditData_unk_4)(s32 arg0, screenTick_arg0 *arg1);

typedef struct struct_gaEditData {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ struct_gaEditData_unk_4 unk_4;
} struct_gaEditData; // size = 0x8

static s32 B_8018E9C0_usa;
static s32 B_8018E9C4_usa;
static s32 gnTickCount;
static s32 gnFlushCount;
static s16 B_8018E9D0_usa;
static s16 B_8018E9D2_usa;
static s32 giScreenEdit;
static void *gpHeapEdit;
static s32 B_8018E9DC_usa;
static s32 B_8018E9E0_usa;
static s32 B_8018E9E4_usa;
static s32 B_8018E9E8_usa;
static s32 B_8018E9EC_usa;
static s32 B_8018E9F0_usa;

nbool func_800306B0_usa(s32 arg0);


void func_8002F73C_usa(s32 arg0, screenTick_arg0 *arg1);
void func_8002F984_usa(s32 arg0, screenTick_arg0 *arg1);
void func_8002FCF0_usa(s32 arg0, screenTick_arg0 *arg1);
void func_8002FF38_usa(s32 arg0, screenTick_arg0 *arg1);
void func_80030278_usa(s32 arg0, screenTick_arg0 *arg1);
void func_800304FC_usa(s32 arg0, screenTick_arg0 *arg1);
void func_80030D10_usa(s32 arg0, screenTick_arg0 *arg1);
void func_80030D6C_usa(s32 arg0, screenTick_arg0 *arg1);
void func_80030DC8_usa(s32 arg0, screenTick_arg0 *arg1);

struct_gaEditData gaEditData[] = {
    { 1, func_80030D10_usa }, { 2, func_8002F73C_usa }, { 3, func_8002F984_usa },
    { 4, func_80030D6C_usa }, { 5, func_8002FCF0_usa }, { 6, func_8002FF38_usa },
    { 7, func_80030278_usa }, { 8, func_800304FC_usa }, { 9, func_80030DC8_usa },
};

void func_8002F2F0_usa(void) {
    DATA_INLINE_CONST s32 sp10[] = {
#if VERSION_GER
        0x69, //
        0x78, //
        0x86, //
#else
        0x64, //
        0x73, //
        0x82, //
#endif
    };
    s32 var_s0 = (B_8018E9C0_usa == 8) ? 1 : 2;

    screenHideArea(giScreenEdit, 0x64);

    if (gTheGame.controller[0].touch_button & U_JPAD) {
        if (B_8018E9D0_usa > 0) {
            B_8018E9D0_usa--;
            B_8018E9D2_usa = 0;
        } else if (B_8018E9D2_usa != 0) {
            B_8018E9D0_usa = var_s0;
        } else {
            B_8018E9D2_usa = 1;
        }
    }

    if (gTheGame.controller[0].touch_button & D_JPAD) {
        if (B_8018E9D0_usa < var_s0) {
            B_8018E9D0_usa++;
            B_8018E9D2_usa = 0;
        } else if (B_8018E9D2_usa != 0) {
            B_8018E9D0_usa = 0;
        } else {
            B_8018E9D2_usa = 1;
        }
    }

    screenShowImage(giScreenEdit, 0x1F4);
    screenSetImagePosition(giScreenEdit, 0x1F4, 0x78, sp10[B_8018E9D0_usa]);
}

void func_8002F464_usa(s32 arg0 UNUSED, screenTick_arg0 *arg1) {
    s32 sp10;
    s32 sp14;
    s32 *temp = &arg1->unk_0;

    func_80027838_usa(giScreenEdit, 0x64);
    screenShowImage(giScreenEdit, 0xC8);
    screenShowImage(giScreenEdit, 0xC9);
    if (B_8018E9F0_usa != -1) {
        gTheGame.tetrisWell[0].block[B_8018E9EC_usa][B_8018E9E8_usa].type = B_8018E9F0_usa;
    }

    screenGetCursor(giScreenEdit, 0x64, &sp10, &sp14);
    sp14 = 0xB - sp14;

    B_8018E9E8_usa = sp10;
    B_8018E9EC_usa = sp14;
    B_8018E9F0_usa = gTheGame.tetrisWell[0].block[sp14][sp10].type;

    if (*temp == 0x18) {
        B_8018E9E4_usa = (B_8018E9E4_usa > 1) ? B_8018E9E4_usa - 1 : 6;
        PlaySE(SFX_INIT_TABLE, SFX_0A7);
    }
    if (*temp == 0x19) {
        B_8018E9E4_usa = (B_8018E9E4_usa < 6) ? B_8018E9E4_usa + 1 : 1;
        PlaySE(SFX_INIT_TABLE, SFX_0A8);
    }

    gTheGame.tetrisWell[0].block[sp14][sp10].type = B_8018E9E4_usa;

    if (*temp == 0x20) {
        PlaySE(SFX_INIT_TABLE, (B_8018E9F0_usa == 0) ? SFX_0A9 : SFX_16C);
        B_8018E9F0_usa = B_8018E9E4_usa;
    }

    if (*temp == 0x21) {
        B_8018E9F0_usa = 0;
        PlaySE(SFX_INIT_TABLE, SFX_006);
    }

    if (*temp == 0x22) {
        if (B_8018E9F0_usa != -1) {
            gTheGame.tetrisWell[0].block[B_8018E9EC_usa][B_8018E9E8_usa].type = B_8018E9F0_usa;
        }
        PlaySE(SFX_INIT_TABLE, SFX_0A5);
    }
}

void func_8002F73C_usa(s32 arg0 UNUSED, screenTick_arg0 *arg1) {
    u16 sp10[2];

    screenHideArea(giScreenEdit, 0x64);
    screenShowImage(giScreenEdit, 0xDC);
    screenShowImage(giScreenEdit, 0xDD);
    screenShowImage(giScreenEdit, 0x82);
    screenShowImage(giScreenEdit, 0x83);
    screenShowImage(giScreenEdit, 0x84);
    screenShowImage(giScreenEdit, 0x85);
    screenShowImage(giScreenEdit, 0x86);

    if ((arg1->unk_0 == 3) && (B_8018E9E0_usa >= 2)) {
        B_8018E9E0_usa--;
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }

    if ((arg1->unk_0 == 4) && (B_8018E9E0_usa < 5)) {
        B_8018E9E0_usa++;
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }

    if (B_8018E9E0_usa < 2) {
        screenHideImage(giScreenEdit, 0x8C);
        screenShowImage(giScreenEdit, 0x8D);
    } else if (B_8018E9E0_usa >= 5) {
        screenShowImage(giScreenEdit, 0x8C);
        screenHideImage(giScreenEdit, 0x8D);
    } else {
        screenShowImage(giScreenEdit, 0x8C);
        screenShowImage(giScreenEdit, 0x8D);
    }

    sp10[0] = (B_8018E9E0_usa & 0x3FF) | 0x1400;
    sp10[1] = 0;
    func_800297C8_usa(giScreenEdit, 0xCD, sp10);

    screenShowText(giScreenEdit, 0xC8);
    screenShowText(giScreenEdit, 0xCD);

    if (arg1->unk_0 == 0x20) {
        gTheGame.cursorBlock[0].target[0] = B_8018E9E0_usa;
        func_800306B0_usa(3);
        PlaySE(SFX_INIT_TABLE, SFX_002);
    }

    if (arg1->unk_0 == 0x21) {
        func_800306B0_usa(1);
        PlaySE(SFX_INIT_TABLE, SFX_006);
    }

    arg1->unk_0 = 0;
}

void func_8002F984_usa(s32 arg0 UNUSED, screenTick_arg0 *arg1) {
    u16 sp10[3];
    s32 temp_v1;
    s32 var_v0;

    func_8002F2F0_usa();
    screenShowImage(giScreenEdit, 0x82);
    screenShowImage(giScreenEdit, 0x83);
    screenShowImage(giScreenEdit, 0x84);
    screenShowImage(giScreenEdit, 0x85);
    screenShowImage(giScreenEdit, 0x86);
    screenShowText(giScreenEdit, 0xEB);
    screenShowText(giScreenEdit, 0x12C);
    screenShowText(giScreenEdit, 0x190);
    screenShowText(giScreenEdit, 0x1F4);

    var_v0 = B_801AB808_usa / 10;
    temp_v1 = var_v0;
    if (var_v0 == 0) {
        var_v0 = 0xA;
    }
    sp10[0] = (var_v0 & 0x3FF) | 0x1400;
    var_v0 = B_801AB808_usa - (temp_v1 * 0xA);
    if (var_v0 == 0) {
        var_v0 = 0xA;
    }
    sp10[1] = (var_v0 & 0x3FF) | 0x1400;
    sp10[2] = 0;

    func_800297C8_usa(giScreenEdit, 0xEB, sp10);

    if (arg1->unk_0 == 0x21) {
        screenHideImage(giScreenEdit, 0x82);
        screenHideImage(giScreenEdit, 0x83);
        screenHideImage(giScreenEdit, 0x84);
        screenHideImage(giScreenEdit, 0x85);
        screenHideImage(giScreenEdit, 0x86);
        screenHideImage(giScreenEdit, 0x1F4);
        screenHideText(giScreenEdit, 0xEB);
        screenHideText(giScreenEdit, 0x12C);
        screenHideText(giScreenEdit, 0x190);
        screenHideText(giScreenEdit, 0x1F4);
        B_8018E9D2_usa = 0;
        B_8018E9D0_usa = 0;
        PlaySE(SFX_INIT_TABLE, SFX_006);
        func_800306B0_usa(1);
    }

    if (arg1->unk_0 == 0x20) {
        screenHideImage(giScreenEdit, 0x82);
        screenHideImage(giScreenEdit, 0x83);
        screenHideImage(giScreenEdit, 0x84);
        screenHideImage(giScreenEdit, 0x85);
        screenHideImage(giScreenEdit, 0x86);
        screenHideImage(giScreenEdit, 0x1F4);
        screenHideText(giScreenEdit, 0xEB);
        screenHideText(giScreenEdit, 0x12C);
        screenHideText(giScreenEdit, 0x190);
        screenHideText(giScreenEdit, 0x1F4);

        switch (B_8018E9D0_usa) {
            case 0:
                func_80089200_usa(B_801AB808_usa);
                PlaySE(SFX_INIT_TABLE, SFX_16B);
                func_800306B0_usa(10);
                break;

            case 1:
                PlaySE(SFX_INIT_TABLE, SFX_006);
                func_800306B0_usa(10);
                break;

            case 2:
                PlaySE(SFX_INIT_TABLE, SFX_006);
                func_800306B0_usa(1);
                B_8018E9D2_usa = 0;
                B_8018E9D0_usa = 0;
                break;
        }
    }

    arg1->unk_0 = 0;
}

void func_8002FCF0_usa(s32 arg0 UNUSED, screenTick_arg0 *arg1) {
    u16 sp10[2];

    screenHideArea(giScreenEdit, 0x64);
    screenShowImage(giScreenEdit, 0xDC);
    screenShowImage(giScreenEdit, 0xDD);
    screenShowImage(giScreenEdit, 0x82);
    screenShowImage(giScreenEdit, 0x83);
    screenShowImage(giScreenEdit, 0x84);
    screenShowImage(giScreenEdit, 0x85);
    screenShowImage(giScreenEdit, 0x86);

    if (arg1->unk_0 == 3) {
        if (B_8018E9E0_usa >= 2) {
            B_8018E9E0_usa -= 1;
            PlaySE(SFX_INIT_TABLE, SFX_001);
        }
    }

    if (arg1->unk_0 == 4) {
        if (B_8018E9E0_usa < 5) {
            B_8018E9E0_usa += 1;
            PlaySE(SFX_INIT_TABLE, SFX_001);
        }
    }

    if (B_8018E9E0_usa < 2) {
        screenHideImage(giScreenEdit, 0x8C);
        screenShowImage(giScreenEdit, 0x8D);
    } else if (B_8018E9E0_usa >= 5) {
        screenShowImage(giScreenEdit, 0x8C);
        screenHideImage(giScreenEdit, 0x8D);
    } else {
        screenShowImage(giScreenEdit, 0x8C);
        screenShowImage(giScreenEdit, 0x8D);
    }

    sp10[0] = (B_8018E9E0_usa & 0x3FF) | 0x1400;
    sp10[1] = 0;
    func_800297C8_usa(giScreenEdit, 0xCD, sp10);

    screenShowText(giScreenEdit, 0xC8);
    screenShowText(giScreenEdit, 0xCD);

    if (arg1->unk_0 == 0x20) {
        gTheGame.cursorBlock[0].target[0] = B_8018E9E0_usa;
        func_800306B0_usa(6);
        PlaySE(SFX_INIT_TABLE, SFX_002);
    }

    if (arg1->unk_0 == 0x21) {
        func_800306B0_usa(4);
        PlaySE(SFX_INIT_TABLE, SFX_006);
    }

    arg1->unk_0 = 0;
}

void func_8002FF38_usa(s32 arg0 UNUSED, screenTick_arg0 *arg1) {
    u16 sp10[3];

    func_8002F2F0_usa();

    screenShowImage(giScreenEdit, 0x82);
    screenShowImage(giScreenEdit, 0x83);
    screenShowImage(giScreenEdit, 0x84);
    screenShowImage(giScreenEdit, 0x85);
    screenShowImage(giScreenEdit, 0x86);

    screenShowText(giScreenEdit, 0xEB);
    screenShowText(giScreenEdit, 0x12C);
    screenShowText(giScreenEdit, 0x190);
    screenShowText(giScreenEdit, 0x1F4);

    if (B_801AB808_usa < 0xA) {
        sp10[0] = (B_801AB808_usa & 0x3FF) | 0x1400;
        sp10[1] = 0;
    } else {
        sp10[0] = 0xA;
        sp10[1] = ((B_801AB808_usa - 0xA) & 0x3FF) | 0x1400;
        sp10[2] = 0;
    }
    func_800297C8_usa(giScreenEdit, 0xEB, sp10);

    if (arg1->unk_0 == 0x21) {
        screenHideImage(giScreenEdit, 0x82);
        screenHideImage(giScreenEdit, 0x83);
        screenHideImage(giScreenEdit, 0x84);
        screenHideImage(giScreenEdit, 0x85);
        screenHideImage(giScreenEdit, 0x86);
        screenHideImage(giScreenEdit, 0x1F4);
        screenHideText(giScreenEdit, 0xEB);
        screenHideText(giScreenEdit, 0x12C);
        screenHideText(giScreenEdit, 0x190);
        screenHideText(giScreenEdit, 0x1F4);
        B_8018E9D2_usa = 0;
        B_8018E9D0_usa = 0;
        PlaySE(SFX_INIT_TABLE, SFX_006);
        func_800306B0_usa(4);
    }

    if (arg1->unk_0 == 0x20) {
        screenHideImage(giScreenEdit, 0x82);
        screenHideImage(giScreenEdit, 0x83);
        screenHideImage(giScreenEdit, 0x84);
        screenHideImage(giScreenEdit, 0x85);
        screenHideImage(giScreenEdit, 0x86);
        screenHideImage(giScreenEdit, 0x1F4);
        screenHideText(giScreenEdit, 0xEB);
        screenHideText(giScreenEdit, 0x12C);
        screenHideText(giScreenEdit, 0x190);
        screenHideText(giScreenEdit, 0x1F4);

        switch (B_8018E9D0_usa) {
            case 0:
                func_80089200_usa(B_801AB808_usa);
                PlaySE(SFX_INIT_TABLE, SFX_16B);
                func_800306B0_usa(10);
                break;

            case 1:
                PlaySE(SFX_INIT_TABLE, SFX_006);
                func_800306B0_usa(10);
                break;

            case 2:
                PlaySE(SFX_INIT_TABLE, SFX_006);
                func_800306B0_usa(4);
                B_8018E9D2_usa = 0;
                B_8018E9D0_usa = 0;
                break;
        }
    }

    arg1->unk_0 = 0;
}

void func_80030278_usa(s32 arg0 UNUSED, screenTick_arg0 *arg1) {
    u16 sp10[3];
    s32 temp_v1;
    nbool var_s0;
    s32 var_v0;

    B_8018E9C4_usa = 7;
    screenHideArea(giScreenEdit, 0x64);
    screenShowImage(giScreenEdit, 0xD2);
    screenShowImage(giScreenEdit, 0xD3);
    screenShowImage(giScreenEdit, 0x82);
    screenShowImage(giScreenEdit, 0x83);
    screenShowImage(giScreenEdit, 0x84);
    screenShowImage(giScreenEdit, 0x85);
    screenShowImage(giScreenEdit, 0x86);
    screenShowImage(giScreenEdit, 0x8C);
    screenSetImagePosition(giScreenEdit, 0x8C, 0x96, 0x82);
    screenShowImage(giScreenEdit, 0x8D);
    screenSetImagePosition(giScreenEdit, 0x8D, 0xB4, 0x82);

    var_s0 = nfalse;
    if ((arg1->unk_0 == 3) && (B_801AB808_usa >= 2)) {
        B_801AB808_usa -= 1;
        var_s0 = ntrue;
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }
    if ((arg1->unk_0 == 4) && (B_801AB808_usa < 0xF)) {
        B_801AB808_usa += 1;
        var_s0 = ntrue;
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }
    if (var_s0) {
        func_8008913C_usa(B_801AB808_usa);
    }

    var_v0 = B_801AB808_usa / 10;
    temp_v1 = var_v0;
    if (var_v0 == 0) {
        var_v0 = 0xA;
    }
    sp10[0] = (var_v0 & 0x3FF) | 0x1400;
    var_v0 = B_801AB808_usa - (temp_v1 * 0xA);
    if (var_v0 == 0) {
        var_v0 = 0xA;
    }
    sp10[1] = (var_v0 & 0x3FF) | 0x1400;
    sp10[2] = 0;
    func_800297C8_usa(giScreenEdit, 0xE6, sp10);

    screenShowText(giScreenEdit, 0xE6);
    if (arg1->unk_0 == 0x21) {
        func_800306B0_usa(10);
        PlaySE(SFX_INIT_TABLE, SFX_006);
    }
    if (arg1->unk_0 == 0x20) {
        func_800306B0_usa(8);
        PlaySE(SFX_INIT_TABLE, SFX_002);
    }

    arg1->unk_0 = 0;
}

void func_800304FC_usa(s32 arg0 UNUSED, screenTick_arg0 *arg1) {
    u16 sp10[3];

    func_8002F2F0_usa();

    screenShowText(giScreenEdit, 0x12C);
    screenShowText(giScreenEdit, 0x190);
    screenShowImage(giScreenEdit, 0xD2);
    screenShowImage(giScreenEdit, 0xD3);
    screenShowImage(giScreenEdit, 0x82);
    screenShowImage(giScreenEdit, 0x83);
    screenShowImage(giScreenEdit, 0x84);
    screenShowImage(giScreenEdit, 0x85);
    screenShowImage(giScreenEdit, 0x86);
    screenShowText(giScreenEdit, 0xE7);

    if (B_801AB808_usa < 0xA) {
        sp10[0] = (B_801AB808_usa & 0x3FF) | 0x1400;
        sp10[1] = 0;
    } else {
#if VERSION_USA || VERSION_EUR
        sp10[0] = 1;
        sp10[1] = ((B_801AB808_usa - 0xA) & 0x3FF) | 0x1400;
#else
        sp10[0] = 0x1401;
        if (B_801AB808_usa != 0xA) {
            sp10[1] = ((B_801AB808_usa - 0xA) & 0x3FF) | 0x1400;
        } else {
            sp10[1] = 0x140A;
        }
#endif
        sp10[2] = 0;
    }
    func_800297C8_usa(giScreenEdit, 0xE7, sp10);

    screenShowText(giScreenEdit, 0xE7);
    if (arg1->unk_0 == 0x21) {
        PlaySE(SFX_INIT_TABLE, SFX_006);
        func_800306B0_usa(10);
    }

    if (arg1->unk_0 == 0x20) {
        if (B_8018E9D0_usa != 0) {
            PlaySE(SFX_INIT_TABLE, SFX_006);
        } else {
            func_8008928C_usa(B_801AB808_usa);
            PlaySE(SFX_INIT_TABLE, SFX_16B);
        }

        func_800306B0_usa(10);
    }

    arg1->unk_0 = 0;
}

STATIC_INLINE nbool inlined_func(s32 arg0, struct_gaEditData **sp10) {
    s32 i;

    for (i = 0; i < ARRAY_COUNTU(gaEditData); i++) {
        if (gaEditData[i].unk_0 == arg0) {
            *sp10 = &gaEditData[i];
            return ntrue;
        }
    }

    return nfalse;
}

// weirdly some functions call func_800306B0_usa and get it inlined, but some
// others don't, so I separated this into an inlinable function to handle this
// weirdness.
STATIC_INLINE nbool func_800306B0_usa_inner(s32 arg0) {
    struct_gaEditData *sp10;

    if (arg0 == 0) {
        return nfalse;
    }

    if ((arg0 == 10) || (arg0 == 11)) {
        gnFlushCount = 1;
    } else {
        if (!inlined_func(arg0, &sp10)) {
            return nfalse;
        }
        screenHideText(giScreenEdit, 0x812B80C8);
    }

    B_8018E9C0_usa = arg0;
    if (arg0 == 1) {
        B_8018E9F0_usa = -1;
    }

    return ntrue;
}

nbool func_800306B0_usa(s32 arg0) {
    return func_800306B0_usa_inner(arg0);
}

/**
 * Original name: DrawEditor
 */
void DrawEditor(struct_gInfo_unk_00068 *arg0) {
    if (gnFlushCount > 0) {
        gnFlushCount = gnFlushCount - 1;
        if (gnFlushCount == 0) {
            gReset = -1;
            if (B_8018E9C0_usa == 0xA) {
                gMain = GMAIN_2BC;
            } else if (B_8018E9C0_usa == 0xB) {
                gMain = GMAIN_384;
                gSelection = SELECTION_82;
                gTheGame.totalPlayer = 1;
                gTheGame.dimension = DIMENSION_2D;
                gTheGame.menu[0].game = 0;
                gTheGame.menu[0].speed = 0;
                gTheGame.tetrisWell[0].extra.win = 0;
                gTheGame.tetrisWell[1].extra.win = 0;
                brainbrain[0].speed = -1;
                brainbrain[1].speed = -1;
                gTheGame.menu[0].stage = B_801AB808_usa;
            }
        }
    }

    if (!screenFlushing()) {
        DrawPuzzleEditor(arg0);
    }

    screenDraw(&glistp, editDrawImage);
    if (!screenFlushing()) {
        pon_DrawLoadingMessage(&glistp);
    }
}

/**
 * Original name: DoEditor
 */
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
        if (gTheGame.controller[0].touch_button & B_BUTTON) {
            sp10.unk_0 = 0x21;
        } else if (gTheGame.controller[0].touch_button & A_BUTTON) {
            sp10.unk_0 = 0x20;
        } else if (gTheGame.controller[0].touch_button & L_TRIG) {
            sp10.unk_0 = 0x18;
        } else if (gTheGame.controller[0].touch_button & R_TRIG) {
            sp10.unk_0 = 0x19;
        } else if (gTheGame.controller[0].touch_button & START_BUTTON) {
            sp10.unk_0 = 0x22;
        } else {
            if (gTheGame.controller[0].hold_button & U_JPAD) {
                sp10.unk_0 = 1;
            }
            if (gTheGame.controller[0].hold_button & D_JPAD) {
                sp10.unk_0 = 2;
            }
            if (gTheGame.controller[0].hold_button & L_JPAD) {
                sp10.unk_0 = 3;
            }
            if (gTheGame.controller[0].hold_button & R_JPAD) {
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
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }
}

/**
 * Original name: InitEditor
 */
void InitEditor(void) {
    B_8018E9C0_usa = 0;
    gnTickCount = 0;
    gnFlushCount = -1;
    B_8018E9F0_usa = -1;
    giScreenEdit = -1;
    InitPuzzleEditor(-1);
    func_8008913C_usa(B_801AB808_usa);
    gTheGame.menu[0].misc = 0;
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
                func_800306B0_usa_inner(9);
                break;

            case 1:
                func_800306B0_usa_inner(1);
                break;

            case 3:
                func_800306B0_usa_inner(4);
                break;

            case 2:
                func_800306B0_usa_inner(8);
                break;

            default:
                func_800306B0_usa_inner(10);
                break;
        }
    }

    func_80002A10_usa(0);
}

void func_80030D10_usa(s32 arg0, screenTick_arg0 *arg1) {
    B_8018E9C4_usa = 1;
    func_8002F464_usa(arg0, arg1);

    if (arg1->unk_0 == 0x22) {
        PlaySE(SFX_INIT_TABLE, SFX_0A5);
        func_800306B0_usa(2);
    }
}

void func_80030D6C_usa(s32 arg0, screenTick_arg0 *arg1) {
    B_8018E9C4_usa = 4;
    func_8002F464_usa(arg0, arg1);

    if (arg1->unk_0 == 0x22) {
        func_800306B0_usa(5);
        PlaySE(SFX_INIT_TABLE, SFX_002);
    }
}

void func_80030DC8_usa(s32 arg0 UNUSED, screenTick_arg0 *arg1 UNUSED) {
    if (!screenChangePending() && !screenFlushing()) {
        func_800306B0_usa(11);
    }
}

/**
 * Original name: editDrawImage
 */
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
