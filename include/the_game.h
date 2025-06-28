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
#include "tetwell.h"
#include "text.h"

typedef struct struct_801A6DB8_usa_unk_002 {
    /* 0x0 */ UNK_TYPE1 unk_0[0xE];
} struct_801A6DB8_usa_unk_002; // size = 0xE

typedef struct struct_801A6DB8_usa_unk_02B {
    /* 0x0 */ UNK_TYPE1 unk_0;
    /* 0x1 */ UNK_TYPE1 unk_1;
    /* 0x2 */ UNK_TYPE1 unk_2;
    /* 0x3 */ UNK_TYPE1 unk_3;
    /* 0x4 */ UNK_TYPE1 unk_4;
    /* 0x5 */ u8 unk_5;
} struct_801A6DB8_usa_unk_02B; // size = 0x6

typedef struct struct_801A6DB8_usa_unk_034 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x80];
} struct_801A6DB8_usa_unk_034; // size = 0x80



typedef struct struct_801A6DB8_usa_unk_0B7 {
    /* 0x0 */ char unk_0[0x4];
} struct_801A6DB8_usa_unk_0B7; // size = 0x4

typedef struct struct_801A6DB8_usa_unk_0BB {
    /* 0x0 */ char unk_0[0x7];
} struct_801A6DB8_usa_unk_0BB; // size = 0x7

typedef struct struct_801A6DB8_usa_unk_0C2 {
    /* 0x0 */ char unk_0[0x7];
} struct_801A6DB8_usa_unk_0C2; // size = 0x7

typedef struct struct_801A6DB8_usa_unk_0C9 {
    /* 0x0 */ char unk_0[0x4];
} struct_801A6DB8_usa_unk_0C9; // size = 0x4

typedef struct struct_801A6DB8_usa_unk_0CD {
    /* 0x0 */ char unk_0[0x7];
} struct_801A6DB8_usa_unk_0CD; // size = 0x7

typedef struct struct_801A6DB8_usa_unk_0D4 {
    /* 0x0 */ char unk_0[0x7];
} struct_801A6DB8_usa_unk_0D4; // size = 0x7


typedef struct struct_801A6DB8_usa_unk_0F1 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x8];
} struct_801A6DB8_usa_unk_0F1; // size = 0x8

typedef struct struct_801A6DB8_usa_unk_0F9 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x8];
} struct_801A6DB8_usa_unk_0F9; // size = 0x8

typedef struct struct_801A6DB8_usa_unk_101 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x8];
} struct_801A6DB8_usa_unk_101; // size = 0x8

typedef struct struct_801A6DB8_usa_unk_109 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x8];
} struct_801A6DB8_usa_unk_109; // size = 0x8

typedef struct struct_801A6DB8_usa_unk_111 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x8];
} struct_801A6DB8_usa_unk_111; // size = 0x8

typedef struct struct_801A6DB8_usa_unk_119 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x8];
} struct_801A6DB8_usa_unk_119; // size = 0x8


typedef struct struct_801A6DB8_usa_unk_121 {
    /* 0x000 */ UNK_TYPE1 unk_000[0x672];
} struct_801A6DB8_usa_unk_121; // size = 0x672

typedef struct struct_801A6DB8_usa_unk_7A2 {
    /* 0x00 */ UNK_TYPE1 unk_00[0xA];
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ UNK_TYPE1 unk_10[0x2];
} struct_801A6DB8_usa_unk_7A2; // size = 0x12

typedef struct struct_801A6DB8_usa_unk_7B4 {
    /* 0x0 */ u16 unk_0;
    /* 0x2 */ u16 unk_2;
    /* 0x4 */ u16 unk_4;
} struct_801A6DB8_usa_unk_7B4; // size = 0x6


// substruct of gTheGame
typedef struct struct_801A6DB8_usa {
    /* 0x000 */ char unk_000;
    /* 0x001 */ UNK_TYPE1 unk_001[0x1];
    /* 0x002 */ struct_801A6DB8_usa_unk_002 unk_002;
    /* 0x010 */ u8 unk_010;
    /* 0x014 */ s32 unk_014;
    /* 0x018 */ s32 unk_018;
    /* 0x01C */ s32 unk_01C;
    /* 0x020 */ s32 unk_020;
    /* 0x024 */ s32 unk_024;
    /* 0x028 */ u8 unk_028;
    /* 0x029 */ u8 unk_029;
    /* 0x02A */ u8 unk_02A;
    /* 0x02B */ struct_801A6DB8_usa_unk_02B unk_02B;
    /* 0x031 */ UNK_TYPE1 unk_031[0x3]; // maybe struct padding?
    /* 0x034 */ struct_801A6DB8_usa_unk_034 unk_034;
    /* 0x0B4 */ u8 unk_0B4;
    /* 0x0B5 */ u8 unk_0B5;
    /* 0x0B6 */ u8 unk_0B6;
    /* 0x0B7 */ struct_801A6DB8_usa_unk_0B7 unk_0B7;
    /* 0x0BB */ struct_801A6DB8_usa_unk_0BB unk_0BB;
    /* 0x0C2 */ struct_801A6DB8_usa_unk_0C2 unk_0C2;
    /* 0x0C9 */ struct_801A6DB8_usa_unk_0C9 unk_0C9;
    /* 0x0CD */ struct_801A6DB8_usa_unk_0CD unk_0CD;
    /* 0x0D4 */ struct_801A6DB8_usa_unk_0D4 unk_0D4;
    /* 0x0DB */ u8 unk_0DB;
    /* 0x0DC */ u8 unk_0DC;
    /* 0x0DD */ u8 unk_0DD;
    /* 0x0DE */ u8 unk_0DE;
    /* 0x0DF */ u8 unk_0DF;
    /* 0x0E0 */ char unk_0E0;
    /* 0x0E1 */ char unk_0E1;
    /* 0x0E2 */ char unk_0E2;
    /* 0x0E3 */ char unk_0E3;
    /* 0x0E4 */ char unk_0E4;
    /* 0x0E5 */ u8 unk_0E5;
    /* 0x0E6 */ u8 unk_0E6;
    /* 0x0E7 */ u8 unk_0E7;
    /* 0x0E8 */ u8 unk_0E8;
    /* 0x0E9 */ u8 unk_0E9;
    /* 0x0EA */ u8 unk_0EA;
    /* 0x0EB */ u8 unk_0EB;
    /* 0x0EC */ u8 unk_0EC;
    /* 0x0ED */ u8 unk_0ED;
    /* 0x0EE */ u8 unk_0EE;
    /* 0x0EF */ u8 unk_0EF;
    /* 0x0F0 */ u8 unk_0F0;
    /* 0x0F1 */ struct_801A6DB8_usa_unk_0F1 unk_0F1;
    /* 0x0F9 */ struct_801A6DB8_usa_unk_0F9 unk_0F9;
    /* 0x101 */ struct_801A6DB8_usa_unk_101 unk_101;
    /* 0x109 */ struct_801A6DB8_usa_unk_109 unk_109;
    /* 0x111 */ struct_801A6DB8_usa_unk_111 unk_111;
    /* 0x119 */ struct_801A6DB8_usa_unk_119 unk_119;
    /* 0x121 */ struct_801A6DB8_usa_unk_121 unk_121;
    /* 0x793 */ UNK_TYPE1 unk_793[0xF];
    /* 0x7A2 */ struct_801A6DB8_usa_unk_7A2 unk_7A2;
    /* 0x7B4 */ struct_801A6DB8_usa_unk_7B4 unk_7B4;
    /* 0x7BA */ UNK_TYPE1 unk_7BA[0x2];
} struct_801A6DB8_usa; // size = 0x7BC

#define GAME_UNK_9A90_COUNT 4

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
    /* 0x9C28 */ menu_t menu[GAME_BUFFER_LEN]; // menu_t?
    /* 0x9C48 */ struct_801A6DB8_usa unk_9C48[8];
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
