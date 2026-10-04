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

typedef enum struct_gaEditData_eMode {
    /*  0 */ EM_NONE,      /* Original name: EM_NONE */
    /*  1 */ EM_MAKE,      /* Original name: EM_MAKE */
    /*  2 */ EM_MAKE_MOVE, /* Original name: EM_MAKE_MOVE */
    /*  3 */ EM_MAKE_SLOT, /* Original name: EM_MAKE_SLOT */
    /*  4 */ EM_EDIT,
    /*  5 */ EM_EDIT_SLOT,
    /*  6 */ EM_MENU,
    /*  7 */ EM_WIPE,
    /*  8 */ EM_WIPE_SURE,
    /*  9 */ STRUCT_GAEDITDATA_EMODE_9,
    /* 10 */ EM_BACK,
    /* 11 */ EM_PLAY,
} struct_gaEditData_eMode;

typedef void(struct_gaEditData_pfTick)(s32 iFrame, screenTick_arg0 *anCommand);

typedef struct struct_gaEditData {
    /* 0x0 */ struct_gaEditData_eMode eMode;
    /* 0x4 */ struct_gaEditData_pfTick *pfTick;
} struct_gaEditData; // size = 0x8

/* Original name: geMode */
static struct_gaEditData_eMode geMode;
/* Original name: geModeLast */
static struct_gaEditData_eMode geModeLast;
/* Original name: gnTickCount */
static s32 gnTickCount;
/* Original name: gnFlushCount */
static s32 gnFlushCount;
static s16 B_8018E9D0_usa;
static s16 B_8018E9D2_usa;
/* Original name: giScreenEdit */
static s32 giScreenEdit;
/* Original name: gpHeapEdit */
static void *gpHeapEdit;
/* Original name: giMenu */
static s32 giMenu;
/* Original name: gnMoveCount */
static s32 gnMoveCount;
/* Original name: gnTile */
static s32 gnTile;
/* Original name: giCursorX */
static s32 giCursorX;
/* Original name: giCursorY */
static s32 giCursorY;
/* Original name: gnCursorData */
static s32 gnCursorData;

nbool editSetMode(struct_gaEditData_eMode eMode);

void editTickMakeMove(s32 iFrame, screenTick_arg0 *anCommand);
void editTickMakeSlot(s32 iFrame, screenTick_arg0 *anCommand);
void editTickEditSlot(s32 iFrame, screenTick_arg0 *anCommand);
void editTickMenu(s32 iFrame, screenTick_arg0 *anCommand);
void editTickWipe(s32 iFrame, screenTick_arg0 *anCommand);
void editTickWipeSure(s32 iFrame, screenTick_arg0 *anCommand);
void editTickMake(s32 iFrame, screenTick_arg0 *anCommand);
void editTickEdit(s32 iFrame, screenTick_arg0 *anCommand);
void func_80030DC8_usa(s32 iFrame, screenTick_arg0 *anCommand);

/**
 * Original name: gaEditData
 */
struct_gaEditData gaEditData[] = {
    { EM_MAKE, editTickMake },                        //
    { EM_MAKE_MOVE, editTickMakeMove },               //
    { EM_MAKE_SLOT, editTickMakeSlot },               //
    { EM_EDIT, editTickEdit },                        //
    { EM_EDIT_SLOT, editTickEditSlot },               //
    { EM_MENU, editTickMenu },                        //
    { EM_WIPE, editTickWipe },                        //
    { EM_WIPE_SURE, editTickWipeSure },               //
    { STRUCT_GAEDITDATA_EMODE_9, func_80030DC8_usa }, //
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
    s32 var_s0 = (geMode == EM_WIPE_SURE) ? 1 : 2;

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

/**
 * Original name: editTick
 */
void editTick(s32 iFrame UNUSED, screenTick_arg0 *anCommand) {
    s32 iCursorX;
    s32 iCursorY;
    s32 *temp = &anCommand->unk_0;

    screenShowArea(giScreenEdit, 0x64);
    screenShowImage(giScreenEdit, 0xC8);
    screenShowImage(giScreenEdit, 0xC9);
    if (gnCursorData != -1) {
        gTheGame.tetrisWell[0].block[giCursorY][giCursorX].type = gnCursorData;
    }

    screenGetCursor(giScreenEdit, 0x64, &iCursorX, &iCursorY);
    iCursorY = 0xB - iCursorY;

    giCursorX = iCursorX;
    giCursorY = iCursorY;
    gnCursorData = gTheGame.tetrisWell[0].block[iCursorY][iCursorX].type;

    if (*temp == 0x18) {
        gnTile = (gnTile > 1) ? gnTile - 1 : 6;
        PlaySE(SFX_INIT_TABLE, SFX_0A7);
    }
    if (*temp == 0x19) {
        gnTile = (gnTile < 6) ? gnTile + 1 : 1;
        PlaySE(SFX_INIT_TABLE, SFX_0A8);
    }

    gTheGame.tetrisWell[0].block[iCursorY][iCursorX].type = gnTile;

    if (*temp == 0x20) {
        PlaySE(SFX_INIT_TABLE, (gnCursorData == 0) ? SFX_0A9 : SFX_16C);
        gnCursorData = gnTile;
    }

    if (*temp == 0x21) {
        gnCursorData = 0;
        PlaySE(SFX_INIT_TABLE, SFX_006);
    }

    if (*temp == 0x22) {
        if (gnCursorData != -1) {
            gTheGame.tetrisWell[0].block[giCursorY][giCursorX].type = gnCursorData;
        }
        PlaySE(SFX_INIT_TABLE, SFX_0A5);
    }
}

/**
 * Original name: editTickMakeMove
 */
void editTickMakeMove(s32 iFrame UNUSED, screenTick_arg0 *anCommand) {
    u16 anText[2];

    screenHideArea(giScreenEdit, 0x64);
    screenShowImage(giScreenEdit, 0xDC);
    screenShowImage(giScreenEdit, 0xDD);
    screenShowImage(giScreenEdit, 0x82);
    screenShowImage(giScreenEdit, 0x83);
    screenShowImage(giScreenEdit, 0x84);
    screenShowImage(giScreenEdit, 0x85);
    screenShowImage(giScreenEdit, 0x86);

    if ((anCommand->unk_0 == 3) && (gnMoveCount > 1)) {
        gnMoveCount--;
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }

    if ((anCommand->unk_0 == 4) && (gnMoveCount < 5)) {
        gnMoveCount++;
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }

    if (gnMoveCount < 2) {
        screenHideImage(giScreenEdit, 0x8C);
        screenShowImage(giScreenEdit, 0x8D);
    } else if (gnMoveCount >= 5) {
        screenShowImage(giScreenEdit, 0x8C);
        screenHideImage(giScreenEdit, 0x8D);
    } else {
        screenShowImage(giScreenEdit, 0x8C);
        screenShowImage(giScreenEdit, 0x8D);
    }

    anText[0] = (gnMoveCount & 0x3FF) | 0x1400;
    anText[1] = 0;
    screenSetTextField(giScreenEdit, 0xCD, anText);

    screenShowText(giScreenEdit, 0xC8);
    screenShowText(giScreenEdit, 0xCD);

    if (anCommand->unk_0 == 0x20) {
        gTheGame.cursorBlock[0].target[0] = gnMoveCount;
        editSetMode(EM_MAKE_SLOT);
        PlaySE(SFX_INIT_TABLE, SFX_002);
    }

    if (anCommand->unk_0 == 0x21) {
        editSetMode(EM_MAKE);
        PlaySE(SFX_INIT_TABLE, SFX_006);
    }

    anCommand->unk_0 = 0;
}

/**
 * Original name: editTickMakeSlot
 */
void editTickMakeSlot(s32 iFrame UNUSED, screenTick_arg0 *anCommand) {
    u16 anText[3];
    s32 temp_v1;
    s32 nCode;

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

    nCode = giSlot / 10;
    temp_v1 = nCode;
    if (nCode == 0) {
        nCode = 0xA;
    }
    anText[0] = (nCode & 0x3FF) | 0x1400;
    nCode = giSlot - (temp_v1 * 0xA);
    if (nCode == 0) {
        nCode = 0xA;
    }
    anText[1] = (nCode & 0x3FF) | 0x1400;
    anText[2] = 0;

    screenSetTextField(giScreenEdit, 0xEB, anText);

    if (anCommand->unk_0 == 0x21) {
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
        editSetMode(EM_MAKE);
    }

    if (anCommand->unk_0 == 0x20) {
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
                SavePuzzleEditor(giSlot);
                PlaySE(SFX_INIT_TABLE, SFX_16B);
                editSetMode(EM_BACK);
                break;

            case 1:
                PlaySE(SFX_INIT_TABLE, SFX_006);
                editSetMode(EM_BACK);
                break;

            case 2:
                PlaySE(SFX_INIT_TABLE, SFX_006);
                editSetMode(EM_MAKE);
                B_8018E9D2_usa = 0;
                B_8018E9D0_usa = 0;
                break;
        }
    }

    anCommand->unk_0 = 0;
}

/**
 * Original name: editTickEditSlot
 */
void editTickEditSlot(s32 iFrame UNUSED, screenTick_arg0 *anCommand) {
    u16 anText[2];

    screenHideArea(giScreenEdit, 0x64);
    screenShowImage(giScreenEdit, 0xDC);
    screenShowImage(giScreenEdit, 0xDD);
    screenShowImage(giScreenEdit, 0x82);
    screenShowImage(giScreenEdit, 0x83);
    screenShowImage(giScreenEdit, 0x84);
    screenShowImage(giScreenEdit, 0x85);
    screenShowImage(giScreenEdit, 0x86);

    if ((anCommand->unk_0 == 3) && (gnMoveCount >= 2)) {
        gnMoveCount -= 1;
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }

    if ((anCommand->unk_0 == 4) && (gnMoveCount < 5)) {
        gnMoveCount++;
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }

    if (gnMoveCount < 2) {
        screenHideImage(giScreenEdit, 0x8C);
        screenShowImage(giScreenEdit, 0x8D);
    } else if (gnMoveCount >= 5) {
        screenShowImage(giScreenEdit, 0x8C);
        screenHideImage(giScreenEdit, 0x8D);
    } else {
        screenShowImage(giScreenEdit, 0x8C);
        screenShowImage(giScreenEdit, 0x8D);
    }

    anText[0] = (gnMoveCount & 0x3FF) | 0x1400;
    anText[1] = 0;
    screenSetTextField(giScreenEdit, 0xCD, anText);

    screenShowText(giScreenEdit, 0xC8);
    screenShowText(giScreenEdit, 0xCD);

    if (anCommand->unk_0 == 0x20) {
        gTheGame.cursorBlock[0].target[0] = gnMoveCount;
        editSetMode(EM_MENU);
        PlaySE(SFX_INIT_TABLE, SFX_002);
    }

    if (anCommand->unk_0 == 0x21) {
        editSetMode(EM_EDIT);
        PlaySE(SFX_INIT_TABLE, SFX_006);
    }

    anCommand->unk_0 = 0;
}

/**
 * Original name: editTickMenu
 */
void editTickMenu(s32 iFrame UNUSED, screenTick_arg0 *anCommand) {
    u16 anText[3];

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

    if (giSlot < 0xA) {
        anText[0] = (giSlot & 0x3FF) | 0x1400;
        anText[1] = 0;
    } else {
        anText[0] = 0xA;
        anText[1] = ((giSlot - 0xA) & 0x3FF) | 0x1400;
        anText[2] = 0;
    }
    screenSetTextField(giScreenEdit, 0xEB, anText);

    if (anCommand->unk_0 == 0x21) {
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
        editSetMode(EM_EDIT);
    }

    if (anCommand->unk_0 == 0x20) {
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
                SavePuzzleEditor(giSlot);
                PlaySE(SFX_INIT_TABLE, SFX_16B);
                editSetMode(EM_BACK);
                break;

            case 1:
                PlaySE(SFX_INIT_TABLE, SFX_006);
                editSetMode(EM_BACK);
                break;

            case 2:
                PlaySE(SFX_INIT_TABLE, SFX_006);
                editSetMode(EM_EDIT);
                B_8018E9D2_usa = 0;
                B_8018E9D0_usa = 0;
                break;
        }
    }

    anCommand->unk_0 = 0;
}

/**
 * Original name: editTickWipe
 */
void editTickWipe(s32 iFrame UNUSED, screenTick_arg0 *anCommand) {
    u16 anText[3];
    s32 temp_v1;
    nbool bLoad;
    s32 nCode;

    geModeLast = EM_WIPE;
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

    bLoad = nfalse;
    if ((anCommand->unk_0 == 3) && (giSlot >= 2)) {
        giSlot -= 1;
        bLoad = ntrue;
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }
    if ((anCommand->unk_0 == 4) && (giSlot < 0xF)) {
        giSlot += 1;
        bLoad = ntrue;
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }
    if (bLoad) {
        LoadPuzzleEditor(giSlot);
    }

    nCode = giSlot / 10;
    temp_v1 = nCode;
    if (nCode == 0) {
        nCode = 0xA;
    }
    anText[0] = (nCode & 0x3FF) | 0x1400;
    nCode = giSlot - (temp_v1 * 0xA);
    if (nCode == 0) {
        nCode = 0xA;
    }
    anText[1] = (nCode & 0x3FF) | 0x1400;
    anText[2] = 0;
    screenSetTextField(giScreenEdit, 0xE6, anText);

    screenShowText(giScreenEdit, 0xE6);
    if (anCommand->unk_0 == 0x21) {
        editSetMode(EM_BACK);
        PlaySE(SFX_INIT_TABLE, SFX_006);
    }
    if (anCommand->unk_0 == 0x20) {
        editSetMode(EM_WIPE_SURE);
        PlaySE(SFX_INIT_TABLE, SFX_002);
    }

    anCommand->unk_0 = 0;
}

/**
 * Original name: editTickWipeSure
 */
void editTickWipeSure(s32 iFrame UNUSED, screenTick_arg0 *anCommand) {
    u16 anText[3];

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

    if (giSlot < 0xA) {
        anText[0] = (giSlot & 0x3FF) | 0x1400;
        anText[1] = 0;
    } else {
#if VERSION_USA || VERSION_EUR
        anText[0] = 1;
        anText[1] = ((giSlot - 0xA) & 0x3FF) | 0x1400;
#else
        anText[0] = 0x1401;
        if (giSlot != 0xA) {
            anText[1] = ((giSlot - 0xA) & 0x3FF) | 0x1400;
        } else {
            anText[1] = 0x140A;
        }
#endif
        anText[2] = 0;
    }
    screenSetTextField(giScreenEdit, 0xE7, anText);

    screenShowText(giScreenEdit, 0xE7);
    if (anCommand->unk_0 == 0x21) {
        PlaySE(SFX_INIT_TABLE, SFX_006);
        editSetMode(EM_BACK);
    }

    if (anCommand->unk_0 == 0x20) {
        if (B_8018E9D0_usa != 0) {
            PlaySE(SFX_INIT_TABLE, SFX_006);
        } else {
            DeletePuzzleEditor(giSlot);
            PlaySE(SFX_INIT_TABLE, SFX_16B);
        }

        editSetMode(EM_BACK);
    }

    anCommand->unk_0 = 0;
}

STATIC_INLINE nbool inlined_func(struct_gaEditData_eMode eMode, struct_gaEditData **ppData) {
    s32 iData;

    for (iData = 0; iData < ARRAY_COUNTU(gaEditData); iData++) {
        if (gaEditData[iData].eMode == eMode) {
            *ppData = &gaEditData[iData];
            return ntrue;
        }
    }

    return nfalse;
}

// weirdly some functions call editSetMode and get it inlined, but some
// others don't, so I separated this into an inlinable function to handle this
// weirdness.
STATIC_INLINE nbool editSetMode_inner(struct_gaEditData_eMode eMode) {
    struct_gaEditData *sp10;

    if (eMode == EM_NONE) {
        return nfalse;
    }

    if ((eMode == EM_BACK) || (eMode == EM_PLAY)) {
        gnFlushCount = 1;
    } else {
        if (!inlined_func(eMode, &sp10)) {
            return nfalse;
        }
        screenHideText(giScreenEdit, 0x812B80C8);
    }

    geMode = eMode;
    if (eMode == EM_MAKE) {
        gnCursorData = -1;
    }

    return ntrue;
}

/**
 * Original name: editSetMode
 */
nbool editSetMode(struct_gaEditData_eMode eMode) {
    return editSetMode_inner(eMode);
}

/**
 * Original name: DrawEditor
 */
void DrawEditor(struct_gInfo_unk_00068 *pDynamic) {
    if (gnFlushCount > 0) {
        gnFlushCount--;
        if (gnFlushCount == 0) {
            gReset = -1;
            if (geMode == EM_BACK) {
                gMain = GMAIN_2BC;
            } else if (geMode == EM_PLAY) {
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
                gTheGame.menu[0].stage = giSlot;
            }
        }
    }

    if (!screenFlushing()) {
        DrawPuzzleEditor(pDynamic);
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
    screenTick_arg0 anCommand;
    struct_gaEditData *pData;

    if (!screenFlushing() && (gnFlushCount == -1)) {
        peelTick();
    }

    gnTickCount++;
    if (!screenFlushing() && (gnFlushCount == -1)) {
        DoPuzzleEditor();
    }

    anCommand.unk_0 = 0;
    anCommand.unk_4 = 0;
    if (!screenFlushing() && (gnFlushCount == -1)) {
        if (gTheGame.controller[0].touch_button & B_BUTTON) {
            anCommand.unk_0 = 0x21;
        } else if (gTheGame.controller[0].touch_button & A_BUTTON) {
            anCommand.unk_0 = 0x20;
        } else if (gTheGame.controller[0].touch_button & L_TRIG) {
            anCommand.unk_0 = 0x18;
        } else if (gTheGame.controller[0].touch_button & R_TRIG) {
            anCommand.unk_0 = 0x19;
        } else if (gTheGame.controller[0].touch_button & START_BUTTON) {
            anCommand.unk_0 = 0x22;
        } else {
            if (gTheGame.controller[0].hold_button & U_JPAD) {
                anCommand.unk_0 = 1;
            }
            if (gTheGame.controller[0].hold_button & D_JPAD) {
                anCommand.unk_0 = 2;
            }
            if (gTheGame.controller[0].hold_button & L_JPAD) {
                anCommand.unk_0 = 3;
            }
            if (gTheGame.controller[0].hold_button & R_JPAD) {
                anCommand.unk_0 = 4;
            }
        }
    }

    if (inlined_func(geMode, &pData)) {
        screenHideImage(giScreenEdit, 0x812B8064);
        pData->pfTick(gnTickCount, &anCommand);
    }

    screenTick(&anCommand);
    if (anCommand.unk_0 != 0) {
        PlaySE(SFX_INIT_TABLE, SFX_001);
    }
}

/**
 * Original name: InitEditor
 */
void InitEditor(void) {
    geMode = EM_NONE;
    gnTickCount = 0;
    gnFlushCount = -1;
    gnCursorData = -1;
    giScreenEdit = -1;
    InitPuzzleEditor(-1);
    LoadPuzzleEditor(giSlot);
    gTheGame.menu[0].misc = 0;
    giMenu = 3;
    gnMoveCount = 1;
    gnTile = 1;
    B_8018E9D2_usa = 0;
    B_8018E9D0_usa = 0;
    gpHeapEdit = Pon_Image_Heap;

    if (screenLoad("EDITOR.SBF", &gpHeapEdit) != 0) {
        giScreenEdit = screenSet("MAIN", 0xFF001);

        switch (B_801C6BD8_usa) {
            case 0:
                editSetMode_inner(STRUCT_GAEDITDATA_EMODE_9);
                break;

            case 1:
                editSetMode_inner(EM_MAKE);
                break;

            case 3:
                editSetMode_inner(EM_EDIT);
                break;

            case 2:
                editSetMode_inner(EM_WIPE_SURE);
                break;

            default:
                editSetMode_inner(EM_BACK);
                break;
        }
    }

    func_80002A10_usa(0);
}

/**
 * Original name: editTickMake
 */
void editTickMake(s32 iFrame, screenTick_arg0 *anCommand) {
    geModeLast = EM_MAKE;
    editTick(iFrame, anCommand);

    if (anCommand->unk_0 == 0x22) {
        PlaySE(SFX_INIT_TABLE, SFX_0A5);
        editSetMode(EM_MAKE_MOVE);
    }
}

/**
 * Original name: editTickEdit
 */
void editTickEdit(s32 iFrame, screenTick_arg0 *anCommand) {
    geModeLast = EM_EDIT;
    editTick(iFrame, anCommand);

    if (anCommand->unk_0 == 0x22) {
        editSetMode(EM_EDIT_SLOT);
        PlaySE(SFX_INIT_TABLE, SFX_002);
    }
}

void func_80030DC8_usa(s32 iFrame UNUSED, screenTick_arg0 *arg1 UNUSED) {
    if (!screenChangePending() && !screenFlushing()) {
        editSetMode(EM_PLAY);
    }
}

/**
 * Original name: editDrawImage
 */
void editDrawImage(Gfx **gfxP, s32 arg1 UNUSED, s32 nTag) {
    Gfx *gfx = *gfxP;

    if (nTag == 0xA) {
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
