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
#include "text.h"

typedef struct tetWell_unk_3FB0 {
    /* 0x00 */ UNK_TYPE1 unk_00[0xD8];
} tetWell_unk_3FB0; // size = 0xD8

typedef enum enum_tetWell_unk_4424 {
    /*  1 */ ENUM_GAME_UNK_0000_UNK_4424_1 = 1,
    /*  2 */ ENUM_GAME_UNK_0000_UNK_4424_2,
    /*  3 */ ENUM_GAME_UNK_0000_UNK_4424_3,
    /*  4 */ ENUM_GAME_UNK_0000_UNK_4424_4,
    /*  5 */ ENUM_GAME_UNK_0000_UNK_4424_5,
    /*  6 */ ENUM_GAME_UNK_0000_UNK_4424_6,
    /*  7 */ ENUM_GAME_UNK_0000_UNK_4424_7,
    /*  8 */ ENUM_GAME_UNK_0000_UNK_4424_8,
    /*  9 */ ENUM_GAME_UNK_0000_UNK_4424_9,
    /* 10 */ ENUM_GAME_UNK_0000_UNK_4424_10,
    /* 11 */ ENUM_GAME_UNK_0000_UNK_4424_11,
    /* 12 */ ENUM_GAME_UNK_0000_UNK_4424_12,
    /* 13 */ ENUM_GAME_UNK_0000_UNK_4424_13,
    /* 14 */ ENUM_GAME_UNK_0000_UNK_4424_14,
    /* 15 */ ENUM_GAME_UNK_0000_UNK_4424_15,
    /* 16 */ ENUM_GAME_UNK_0000_UNK_4424_16,
    /* 18 */ ENUM_GAME_UNK_0000_UNK_4424_18 = 18,
    /* 31 */ ENUM_GAME_UNK_0000_UNK_4424_31 = 31,
    /* 41 */ ENUM_GAME_UNK_0000_UNK_4424_41 = 41,
} enum_tetWell_unk_4424;


#define TETWELL_UNK_3EF0_LEN_6 (6)

#define ICON_COUNT (10)

// TODO: This count seems to be 40 in panepon gc, so maybe it should adjust by player count
#define ATTACK_COUNT (10 * 2)

#define TETWELL_EXPLOSION_LEN (50)

/* Original name: tetWell */
typedef struct tetWell {
    /* 0x0000 */ block_t block[BLOCK_LEN_ROWS][BLOCK_LEN_B]; /* Original name: block */
    /* 0x2520 */ attack_t attack[ATTACK_COUNT];
    /* 0x2AC0 */ icon_t icon[ICON_COUNT];
    /* 0x2ED0 */ explode_t explosion[TETWELL_EXPLOSION_LEN];
    /* 0x3830 */ uObjSprite unk_3830[BLOCK_LEN_ROWS][TETWELL_OBJSPRITE_LEN_B];
    /* 0x3EF0 */ uObjSprite unk_3EF0[TETWELL_UNK_3EF0_LEN_6];
    /* 0x3F80 */ uObjSprite unk_3F80;
    /* 0x3F98 */ uObjSprite unk_3F98;
    /* 0x3FB0 */ tetWell_unk_3FB0 unk_3FB0;
    /* 0x4088 */ f32 unk_4088;
    /* 0x408C */ block_t new_block[BLOCK_LEN_B];
    /* 0x43A4 */ s32 unk_43A4;
    /* 0x43A8 */ s32 unk_43A8;
    /* 0x43AC */ s32 unk_43AC;
    /* 0x43B0 */ s32 unk_43B0;
    /* 0x43B4 */ s32 unk_43B4;
    /* 0x43B8 */ s32 unk_43B8;
    /* 0x43BC */ s32 unk_43BC;
    /* 0x43C0 */ s32 unk_43C0;
    /* 0x43C4 */ s32 unk_43C4;
    /* 0x43C8 */ s32 unk_43C8;
    /* 0x43CC */ UNK_TYPE1 unk_43CC[0x43E0-0x43CC];
    /* 0x43E0 */ s32 unk_43E0;
    /* 0x43E4 */ s32 unk_43E4;
    /* 0x43E8 */ UNK_PAD unk_43E8[0x4];
    /* 0x43EC */ UNK_TYPE4 unk_43EC;
    /* 0x43F0 */ s32 unk_43F0;
    /* 0x43F4 */ s32 unk_43F4;
    /* 0x43F8 */ s32 unk_43F8; // possibly part of "struct state_t state; // offset 0x4AA8, size 0x38", maybe "current_raise"
    /* 0x43FC */ s32 unk_43FC;
    /* 0x4400 */ UNK_TYPE1 unk_4400[0x4];
    /* 0x4404 */ UNK_TYPE4 unk_4404;
    /* 0x4408 */ UNK_TYPE1 unk_4408[0x14];
    /* 0x441C */ s32 unk_441C;
    /* 0x4420 */ s32 unk_4420; // TODO: enum?
    /* 0x4424 */ s32 unk_4424; // enum_tetWell_unk_4424
    /* 0x4428 */ s32 unk_4428;
    /* 0x442C */ UNK_TYPE1 unk_442C[0x4];
} tetWell; // size = 0x4430

#if 0
struct tetWell {
    // total size: 0x57C0
    struct block_t block[12][18]; // offset 0x0, size 0x2520
    struct attack_t attack[40]; // offset 0x2520, size 0xC80
    struct icon_t icon[10]; // offset 0x31A0, size 0x410
    struct explode_t explosion[50]; // offset 0x35B0, size 0x960
    uObjSprite block_rect[12][6]; // offset 0x3F10, size 0x6C0
    uObjSprite new_block_rect[6]; // offset 0x45D0, size 0x90
    uObjSprite left2D; // offset 0x4660, size 0x18
    uObjSprite right2D; // offset 0x4678, size 0x18
    char visible[12][18]; // offset 0x4690, size 0xD8
    float translation; // offset 0x4768, size 0x4
    struct block_t new_block[18]; // offset 0x476C, size 0x318
    struct chain_t reaction; // offset 0x4A84, size 0x8
    int score; // offset 0x4A8C, size 0x4
    int raise; // offset 0x4A90, size 0x4
    int danger; // offset 0x4A94, size 0x4
    int alert; // offset 0x4A98, size 0x4
    int defrost; // offset 0x4A9C, size 0x4
    int chain_garbage; // offset 0x4AA0, size 0x4
    int collision; // offset 0x4AA4, size 0x4
    struct state_t state; // offset 0x4AA8, size 0x38
    struct extra_t extra; // offset 0x4AE0, size 0x1C
    int bot_height; // offset 0x4AFC, size 0x4
    struct menu_t menu; // offset 0x4B00, size 0x18
    struct attack_t attack4p[40]; // offset 0x4B18, size 0xC80
    int LastChainType; // offset 0x5798, size 0x4
    int LastComboType; // offset 0x579C, size 0x4
    int LastEXComboType; // offset 0x57A0, size 0x4
    int ChainAttackWhom; // offset 0x57A4, size 0x4
    int ComboAttackWhom; // offset 0x57A8, size 0x4
    int LastAttackWhom; // offset 0x57AC, size 0x4
    int RankingSignRaise; // offset 0x57B0, size 0x4
    int RankingSignColor; // offset 0x57B4, size 0x4
    int EntryNo; // offset 0x57B8, size 0x4
};
#endif

typedef struct Game_unk_9AE0 {
    /* 0x00 */ UNK_TYPE1 unk_00[0xA];
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ UNK_TYPE1 unk_0C[0x2];
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ UNK_TYPE1 unk_14[0x28-0x14];
} Game_unk_9AE0; // size = 0x28


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
    /* 0x0 */ UNK_TYPE1 unk_0[0x4];
} struct_801A6DB8_usa_unk_0B7; // size = 0x4

typedef struct struct_801A6DB8_usa_unk_0BB {
    /* 0x0 */ UNK_TYPE1 unk_0[0x7];
} struct_801A6DB8_usa_unk_0BB; // size = 0x7

typedef struct struct_801A6DB8_usa_unk_0C2 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x7];
} struct_801A6DB8_usa_unk_0C2; // size = 0x7

typedef struct struct_801A6DB8_usa_unk_0C9 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x4];
} struct_801A6DB8_usa_unk_0C9; // size = 0x4

typedef struct struct_801A6DB8_usa_unk_0CD {
    /* 0x0 */ UNK_TYPE1 unk_0[0x7];
} struct_801A6DB8_usa_unk_0CD; // size = 0x7

typedef struct struct_801A6DB8_usa_unk_0D4 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x7];
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


typedef struct struct_gInfo_unk_10224_unk_0 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x4];
} struct_gInfo_unk_10224_unk_0; // size = 0x4

typedef struct struct_gInfo_unk_10224 {
    /* 0x0 */ struct_gInfo_unk_10224_unk_0 unk_0;
    /* 0x4 */ UNK_TYPE1 unk_4[0xA];
} struct_gInfo_unk_10224; // size = 0xE

#define DRAWTEXT_COUNT 70

// TODO: Maybe make an enum for this?
#define STRUCT_GINFO_UNK_00068_UNK_10208_LEN (14)

typedef struct struct_gInfo_unk_00068 {
    /* 0x00000 */ Gfx unk_00000[UNK_SIZE];
    /* 0x00008 */ UNK_TYPE1 unk_00008[0x100F8];
    /* 0x10100 */ Mtx unk_10100[GAME_BUFFER_LEN]; // trans?
    /* 0x10180 */ Mtx unk_10180[GAME_BUFFER_LEN]; // rotate?
    /* 0x10200 */ UNK_TYPE1 unk_10200[0x8];
    /* 0x10208 */ char unk_10208[GAME_BUFFER_LEN][STRUCT_GINFO_UNK_00068_UNK_10208_LEN];
    /* 0x10224 */ s8 unk_10224[GAME_BUFFER_LEN][0xE];
    /* 0x10240 */ UNK_TYPE unk_10240;
    /* 0x10244 */ block_t block[GAME_BUFFER_LEN][BLOCK_LEN_ROWS][BLOCK_LEN_B];
    /* 0x14C84 */ UNK_TYPE1 unk_14C84[0x4];
    /* 0x14C88 */ attack_t attack[GAME_BUFFER_LEN][ATTACK_COUNT];
    /* 0x157C8 */ icon_t icon[GAME_BUFFER_LEN][ICON_COUNT];
    /* 0x15FE8 */ explode_t explosion[GAME_BUFFER_LEN][TETWELL_EXPLOSION_LEN];
    /* 0x172A8 */ cursor_t cursorBlock[GAME_BUFFER_LEN];
    /* 0x17408 */ uObjSprite block_rect[GAME_BUFFER_LEN][BLOCK_LEN_ROWS][TETWELL_OBJSPRITE_LEN_B];
    /* 0x18188 */ uObjSprite unk_18188[GAME_BUFFER_LEN][TETWELL_UNK_3EF0_LEN_6];
    /* 0x182A8 */ uObjSprite unk_182A8[GAME_BUFFER_LEN];
    /* 0x182D8 */ uObjSprite unk_182D8[GAME_BUFFER_LEN];
    /* 0x18308 */ tetWell_unk_3FB0 unk_18308[GAME_BUFFER_LEN];
    /* 0x184B8 */ Mtx unk_184B8[GAME_BUFFER_LEN];
    /* 0x18538 */ Mtx unk_18538[GAME_BUFFER_LEN];
    /* 0x185B8 */ UNK_TYPE1 unk_185B8[0x140];
    /* 0x186F8 */ text_t drawText[DRAWTEXT_COUNT];
} struct_gInfo_unk_00068; // size = 0x18FB8

typedef struct struct_gInfo {
    /* 0x00000 */ OSScTask scTask;
    /* 0x00068 */ struct_gInfo_unk_00068 unk_00068;
    /* 0x19020 */ s16 unk_19020;
    /* 0x19022 */ UNK_TYPE1 unk_19022[0x2];
    /* 0x19024 */ UNK_TYPE1 unk_19024[0x1C];
    /* 0x19040 */ void *unk_19040;
    /* 0x19044 */ UNK_TYPE1 unk_19044[0x4];
} struct_gInfo; // size = 0x19048

/* Original name: Game */
typedef struct Game {
    /* 0x0000 */ tetWell tetrisWell[GAME_BUFFER_LEN]; /* Original name: tetrisWell */
    /* 0x8860 */ cursor_t cursorBlock[GAME_BUFFER_LEN];
    /* 0x89C0 */ gamepad_t controller[GAME_BUFFER_LEN];
    /* 0x89E0 */ flic_t flic[FLIC_COUNT];
    /* 0x8B20 */ action_t action[ACTION_COUNT];
    /* 0x8B98 */ uObjTxtr unk_8B98[2 * UNK_SIZE]; // gLUT?
    /* 0x8BC8 */ UNK_TYPE1 unk_8BC8[0xC0];
    /* 0x8C88 */ uObjBg unk_8C88[10]; // gBG?
    /* 0x8E18 */ UNK_TYPE1 unk_8E18[0xC8];
    /* 0x8EE0 */ uObjTxtr unk_8EE0[UNK_SIZE]; // gTEXT?
    /* 0x8EF8 */ UNK_PAD unk_8EF8[0x8FD0-0x8EF8];
    /* 0x8FD0 */ uObjSprite unk_8FD0[UNK_SIZE];
    /* 0x8FE8 */ UNK_TYPE1 unk_8FE8[0x90C0-0x8FE8];
    /* 0x90C0 */ s32 unk_90C0;
    /* 0x90C4 */ UNK_TYPE1 unk_90C4[0x4];
    /* 0x90C8 */ text_t drawText[DRAWTEXT_COUNT];
    /* 0x9988 */ uObjBg frame;
    /* 0x99B0 */ UNK_TYPE1 unk_99B0[0x28];
    /* 0x99D8 */ uObjTxtr unk_99D8;
    /* 0x99F0 */ UNK_PAD unk_99F0[0x18];
    /* 0x9A08 */ uObjSprite unk_9A08[3];
    /* 0x9A50 */ uObjBg unk_9A50; // bkground?
    /* 0x9A78 */ UNK_TYPE1 unk_9A78[0x9AE0 - 0x9A78];
    /* 0x9AE0 */ Game_unk_9AE0 unk_9AE0;
    /* 0x9B08 */ UNK_TYPE1 unk_9B08[0x9B48 - 0x9B08];
    /* 0x9B48 */ s32 unk_9B48;
    /* 0x9B4C */ UNK_TYPE1 unk_9B4C[0x9B50 - 0x9B4C];
    /* 0x9B50 */ uObjBg unk_9B50[2]; // at least 2
    /* 0x9BA0 */ UNK_TYPE1 unk_9BA0[0x9BF0 - 0x9BA0];
    /* 0x9BF0 */ uObjTxtr unk_9BF0;
    /* 0x9C08 */ s32 unk_9C08;
    /* 0x9C0C */ s32 unk_9C0C; // dimension?
    /* 0x9C10 */ s32 unk_9C10;
    /* 0x9C14 */ s32 unk_9C14;
    /* 0x9C18 */ s32 unk_9C18;
    /* 0x9C1C */ s32 unk_9C1C;
    /* 0x9C20 */ UNK_TYPE1 unk_9C20[0x4];
    /* 0x9C24 */ UNK_TYPE4 unk_9C24;
    /* 0x9C28 */ UNK_TYPE4 unk_9C28;
    /* 0x9C2C */ s32 unk_9C2C[UNK_SIZE][4];
    /* 0x9C3C */ UNK_TYPE1 unk_9C3C[0xC];
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
