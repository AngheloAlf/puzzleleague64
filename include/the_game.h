#ifndef THE_GAME_H
#define THE_GAME_H

#include "ultra64.h"
#include "PR/sched.h"
#include "PR/gs2dex.h"
#include "unk.h"

#include "unknown_defines.h"

#include "action.h"
#include "attack.h"
#include "block.h"
#include "cursor.h"
#include "explode.h"
#include "flic.h"
#include "gamepad.h"
#include "icon.h"
#include "menu_t.h"
#include "player_t.h"
#include "tetwell.h"
#include "text.h"


#define GAME_UNK_9A90_COUNT 4
#define GAME_PLAYER_COUNT 8

/* Original name: Game */
typedef struct Game {
    /* 0x0000 */ tetWell tetrisWell[GAME_BUFFER_LEN]; /* Original name: tetrisWell */
    /* 0x8860 */ cursor_t cursorBlock[GAME_BUFFER_LEN];
    /* 0x89C0 */ gamepad_t controller[GAME_BUFFER_LEN];
    /* 0x89E0 */ flic_t flic[FLIC_COUNT];
    /* 0x8B20 */ action_t action[ACTION_COUNT];
    /* 0x8B98 */ uObjTxtr unk_8B98[2 * UNK_SIZE]; // gLUT?
    /* 0x8BC8 */ UNK_PAD unk_8BC8[0x18];
    /* 0x8BE0 */ s32 unk_8BE0;
    /* 0x8BE4 */ void *unk_8BE4;
    /* 0x8BE8 */ s16 unk_8BE8;
    /* 0x8BEA */ s16 unk_8BEA;
    /* 0x8BEC */ s16 unk_8BEC;
    /* 0x8BEE */ s16 unk_8BEE;
    /* 0x8BF0 */ s32 unk_8BF0;
    /* 0x8BF4 */ s32 unk_8BF4;
    /* 0x8BF8 */ UNK_PAD unk_8BF8[0x90];
    /* 0x8C88 */ uObjBg unk_8C88[10]; // gBG?
    /* 0x8E18 */ UNK_TYPE1 unk_8E18[0xC8];
    /* 0x8EE0 */ uObjTxtr unk_8EE0[UNK_SIZE]; // gTEXT?
    /* 0x8EF8 */ UNK_PAD unk_8EF8[0x8FD0-0x8EF8];
    /* 0x8FD0 */ uObjSprite unk_8FD0[UNK_SIZE];
    /* 0x8FE8 */ UNK_PAD unk_8FE8[0x90A8-0x8FE8];
    /* 0x90A8 */ UNK_PAD unk_90A8[0x2];
    /* 0x90AA */ s16 unk_90AA;
    /* 0x90AC */ s16 unk_90AC;
    /* 0x90AE */ s16 unk_90AE;
    /* 0x90B0 */ UNK_PAD unk_90B0[0x90B2-0x90B0];
    /* 0x90B2 */ s16 unk_90B2;
    /* 0x90B4 */ s16 unk_90B4;
    /* 0x90B6 */ s16 unk_90B6;
    /* 0x90B8 */ s16 unk_90B8;
    /* 0x90BA */ s16 unk_90BA;
    /* 0x90BC */ s8 unk_90BC;
    /* 0x90BD */ s8 unk_90BD;
    /* 0x90BE */ s8 unk_90BE;
    /* 0x90BF */ s8 unk_90BF;
    /* 0x90C0 */ s32 unk_90C0; // currentText?
    /* 0x90C4 */ UNK_TYPE1 unk_90C4[0x4];
    /* 0x90C8 */ text_t drawText[DRAWTEXT_COUNT];
    /* 0x9988 */ uObjBg frame[UNK_SIZE];
    /* 0x99B0 */ UNK_TYPE1 unk_99B0[0x28];
    /* 0x99D8 */ uObjTxtr unk_99D8[UNK_SIZE];
    /* 0x99F0 */ UNK_PAD unk_99F0[0x18];
    /* 0x9A08 */ uObjSprite unk_9A08[3];
    /* 0x9A50 */ uObjBg unk_9A50; // bkground?
    /* 0x9A78 */ UNK_TYPE1 unk_9A78[0x9A90 - 0x9A78];
    /* 0x9A90 */ uObjBg unk_9A90[GAME_UNK_9A90_COUNT];
    /* 0x9B30 */ s32 unk_9B30;
    /* 0x9B34 */ void* unk_9B34;
    /* 0x9B38 */ s16 unk_9B38;
    /* 0x9B3A */ s16 unk_9B3A;
    /* 0x9B3C */ s16 unk_9B3C;
    /* 0x9B3E */ s16 unk_9B3E;
    /* 0x9B40 */ s32 unk_9B40;
    /* 0x9B44 */ s32 unk_9B44;
    /* 0x9B48 */ s32 unk_9B48;
    /* 0x9B4C */ UNK_TYPE1 unk_9B4C[0x9B50 - 0x9B4C];
    /* 0x9B50 */ uObjBg unk_9B50[4]; // at least 4
    /* 0x9BF0 */ uObjTxtr unk_9BF0; // tlut
    /* 0x9C08 */ s32 unk_9C08; // totalPlayer?
    /* 0x9C0C */ s32 unk_9C0C; // dimension?
    /* 0x9C10 */ s32 unk_9C10;
    /* 0x9C14 */ s32 unk_9C14;
    /* 0x9C18 */ s32 unk_9C18;
    /* 0x9C1C */ s32 unk_9C1C;
    /* 0x9C20 */ s32 unk_9C20;
    /* 0x9C24 */ UNK_TYPE4 unk_9C24;
    /* 0x9C28 */ menu_t menu[GAME_BUFFER_LEN];
    /* 0x9C48 */ player_t player[GAME_PLAYER_COUNT]; // player_t player?
} Game; // size >= 0xDA28

#if 0
struct Game {
    // total size: 0x21C08
    struct tetWell tetrisWell[4]; // offset 0x0, size 0x15F00
    struct cursor_t cursorBlock[4]; // offset 0x15F00, size 0x440
    struct gamepad_t controller[4]; // offset 0x16340, size 0x40
    struct flic_t flic[340]; // offset 0x16380, size 0x2A80
    struct action_t action[40]; // offset 0x18E00, size 0x1E0
    uObjTxtr gLUT[40]; // offset 0x18FE0, size 0x3C0
    uObjBg gBG[200]; // offset 0x193A0, size 0x1F40
    uObjTxtr gTEXT[80]; // offset 0x1B2E0, size 0x780
    uObjSprite gSPRITE[160]; // offset 0x1BA60, size 0xF00
    int currentText; // offset 0x1C960, size 0x4
    struct text_t drawText[70]; // offset 0x1C968, size 0x8C0
    uObjBg frame; // offset 0x1D228, size 0x28
    uObjTxtr frameLUT; // offset 0x1D250, size 0x18
    uObjSprite shadeBOX[4]; // offset 0x1D268, size 0x60
    uObjBg bkground; // offset 0x1D2C8, size 0x28
    uObjTxtr bkgroundLUT; // offset 0x1D2F0, size 0x18
    uObjBg sign[8]; // offset 0x1D308, size 0x140
    uObjBg alpha[4]; // offset 0x1D448, size 0xA0
    uObjTxtr signLUT; // offset 0x1D4E8, size 0x18
    int miscToggle; // offset 0x1D500, size 0x4
    uObjBg misc[4]; // offset 0x1D508, size 0xA0
    uObjTxtr miscLUT[4]; // offset 0x1D5A8, size 0x60
    int totalPlayer; // offset 0x1D608, size 0x4
    int dimension; // offset 0x1D60C, size 0x4
    int seed; // offset 0x1D610, size 0x4
    int hour; // offset 0x1D614, size 0x4
    int minute; // offset 0x1D618, size 0x4
    int second; // offset 0x1D61C, size 0x4
    struct help_t help; // offset 0x1D620, size 0x8
    struct menu_t menu[4]; // offset 0x1D628, size 0x60
    struct player_t player[8]; // offset 0x1D688, size 0x4400
    int LastAlivePlayer; // offset 0x21A88, size 0x4
    int NoEntryPlayer; // offset 0x21A8C, size 0x4
    struct MultiModeData_t MultiModeData; // offset 0x21A90, size 0x168
    char kPLAYER4VTL_2D1st[4]; // offset 0x21BF8, size 0x4
    char kPLAYER4VTL_2D2nd[4]; // offset 0x21BFC, size 0x4
    char kPLAYER4VTL_2D3rd[4]; // offset 0x21C00, size 0x4
    char kPLAYER4VTL_2D4th[4]; // offset 0x21C04, size 0x4
};
#endif


/* Original name: gTheGame */
extern Game gTheGame;

#endif
