#ifndef THE_GAME_H
#define THE_GAME_H

#include "ultra64.h"
#include "PR/sched.h"
#include "PR/gs2dex.h"
#include "unk.h"

#include "text.h"

#define BLOCK_LEN_A (12)
#define BLOCK_LEN_B (18)

/* Original name: block_t. */
typedef struct block_t {
    /* 0x00 */ s32 state; /* Original name: state */
    /* 0x04 */ s32 delay; /* Original name: delay */
    /* 0x08 */ s32 disappear; /* Original name: disappear */
    /* 0x0C */ s32 drop; /* Original name: drop */
    /* 0x10 */ s32 type; /* Original name: type */
    /* 0x14 */ s32 bomb; /* Original name: bomb */
    /* 0x18 */ s32 sound; /* Original name: sound */
    /* 0x1C */ s32 currRow; /* Original name: currRow */
    /* 0x20 */ s32 chain_flag; /* Original name: chain_flag */
    /* 0x24 */ s32 frame_n; /* Original name: frame_n */
    /* 0x28 */ s32 frame_d; /* Original name: frame_d */
} block_t; // size = 0x2C

typedef struct tetWell_unk_2520 {
    /* 0x000 */ UNK_TYPE1 unk_000[0x5A0];
} tetWell_unk_2520; // size = 0x5A0

typedef struct tetWell_unk_2AC0 {
    /* 0x000 */ UNK_TYPE1 unk_000[0x410];
} tetWell_unk_2AC0; // size = 0x410

typedef struct tetWell_unk_2ED0 {
    /* 0x000 */ UNK_TYPE1 unk_000[0x960];
} tetWell_unk_2ED0; // size = 0x960

typedef struct tetWell_unk_000 {
    /* 0x00 */ UNK_TYPE2 unk_00;
    /* 0x02 */ UNK_TYPE1 unk_02[0x2];
    /* 0x04 */ UNK_TYPE1 unk_04[0x4];
    /* 0x08 */ UNK_TYPE2 unk_08;
    /* 0x0A */ UNK_TYPE1 unk_0A[0x2];
    /* 0x0C */ UNK_TYPE1 unk_0C[0xC];
} tetWell_unk_000; // size = 018

typedef struct tetWell_unk_3830 {
    /* 0x000 */ tetWell_unk_000 unk_000[6];
    /* 0x090 */ UNK_TYPE1 unk_090[0x630];
} tetWell_unk_3830; // size = 0x6C0

typedef struct tetWell_unk_3EF0 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x90];
} tetWell_unk_3EF0; // size = 0x90

typedef struct tetWell_unk_3F80 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x18];
} tetWell_unk_3F80; // size = 0x18

typedef struct tetWell_unk_3F98 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x18];
} tetWell_unk_3F98; // size = 0x18

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


/* Original name: tetWell */
typedef struct tetWell {
    /* 0x0000 */ block_t block[BLOCK_LEN_A][BLOCK_LEN_B]; /* Original name: block */
    /* 0x2520 */ tetWell_unk_2520 unk_2520;
    /* 0x2AC0 */ tetWell_unk_2AC0 unk_2AC0;
    /* 0x2ED0 */ tetWell_unk_2ED0 unk_2ED0;
    /* 0x3830 */ tetWell_unk_3830 unk_3830;
    /* 0x3EF0 */ tetWell_unk_3EF0 unk_3EF0;
    /* 0x3F80 */ tetWell_unk_3F80 unk_3F80;
    /* 0x3F98 */ tetWell_unk_3F98 unk_3F98;
    /* 0x3FB0 */ tetWell_unk_3FB0 unk_3FB0;
    /* 0x4088 */ f32 unk_4088;
    /* 0x408C */ UNK_TYPE1 unk_408C[0x320];
    /* 0x43AC */ s32 unk_43AC;
    /* 0x43B0 */ UNK_TYPE1 unk_43B0[0x8];
    /* 0x43B8 */ s32 unk_43B8;
    /* 0x43BC */ UNK_TYPE1 unk_43BC[0x24];
    /* 0x43E0 */ s32 unk_43E0;
    /* 0x43E4 */ UNK_TYPE1 unk_43E4[8];
    /* 0x43EC */ UNK_TYPE4 unk_43EC;
    /* 0x43F0 */ UNK_TYPE1 unk_43F0[0xC];
    /* 0x43FC */ UNK_TYPE4 unk_43FC;
    /* 0x4400 */ UNK_TYPE1 unk_4400[0x4];
    /* 0x4404 */ UNK_TYPE4 unk_4404;
    /* 0x4408 */ UNK_TYPE1 unk_4408[0x18];
    /* 0x4420 */ s32 unk_4420; // TODO: enum?
    /* 0x4424 */ s32 unk_4424; // enum_tetWell_unk_4424
    /* 0x4428 */ s32 unk_4428;
    /* 0x442C */ UNK_TYPE1 unk_442C[0x4];
} tetWell; // size = 0x4430


typedef struct Game_unk_8860 {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ UNK_TYPE1 unk_08[0x4];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ UNK_TYPE1 unk_10[0x4];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ UNK_TYPE4 unk_20;
    /* 0x24 */ UNK_TYPE1 unk_24[0x74];
    /* 0x98 */ uObjSprite unk_98;
} Game_unk_8860; // size = 0xB0


typedef struct Game_unk_89C4 {
    /* 0x00 */ u16 unk_00;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ UNK_TYPE1 unk_08[2];
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ UNK_TYPE1 unk_0C[4];
} Game_unk_89C4; // size = 0x10


typedef struct Game_unk_8B98 {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x04 */ UNK_PTR unk_04;
    /* 0x08 */ UNK_TYPE2 unk_08;
    /* 0x0A */ UNK_TYPE2 unk_0A;
    /* 0x0C */ UNK_TYPE2 unk_0C;
    /* 0x0E */ UNK_TYPE2 unk_0E;
    /* 0x10 */ UNK_TYPE4 unk_10;
    /* 0x14 */ UNK_TYPE4 unk_14;
} Game_unk_8B98; // size = 0x18


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


typedef struct struct_gInfo_unk_10208_unk_0 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x4];
} struct_gInfo_unk_10208_unk_0; // size = 0x4

typedef struct struct_gInfo_unk_10208 {
    /* 0x0 */ struct_gInfo_unk_10208_unk_0 unk_0;
    /* 0x4 */ UNK_TYPE1 unk_4[0xA];
} struct_gInfo_unk_10208; // size = 0xE


typedef struct struct_gInfo_unk_10224_unk_0 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x4];
} struct_gInfo_unk_10224_unk_0; // size = 0x4

typedef struct struct_gInfo_unk_10224 {
    /* 0x0 */ struct_gInfo_unk_10224_unk_0 unk_0;
    /* 0x4 */ UNK_TYPE1 unk_4[0xA];
} struct_gInfo_unk_10224; // size = 0xE

#define GAME_BUFFER_LEN 2
#define GAME_UNK_90C8_LEN 70

typedef struct struct_gInfo_unk_00068 {
    /* 0x00000 */ Gfx unk_00000[UNK_SIZE];
    /* 0x00008 */ UNK_TYPE1 unk_00008[0x100F8];
    /* 0x10100 */ Mtx unk_10100[GAME_BUFFER_LEN];
    /* 0x10180 */ Mtx unk_10180[GAME_BUFFER_LEN];
    /* 0x10200 */ UNK_TYPE1 unk_10200[0x8];
    /* 0x10208 */ struct_gInfo_unk_10208 unk_10208[GAME_BUFFER_LEN];
    /* 0x10224 */ struct_gInfo_unk_10224 unk_10224[GAME_BUFFER_LEN];
    /* 0x10240 */ UNK_TYPE unk_10240;
    /* 0x10244 */ block_t unk_10244[GAME_BUFFER_LEN][BLOCK_LEN_A][BLOCK_LEN_B];
    /* 0x14C84 */ UNK_TYPE1 unk_14C84[0x4];
    /* 0x14C88 */ tetWell_unk_2520 unk_14C88[GAME_BUFFER_LEN];
    /* 0x157C8 */ tetWell_unk_2AC0 unk_157C8[GAME_BUFFER_LEN];
    /* 0x15FE8 */ tetWell_unk_2ED0 unk_15FE8[GAME_BUFFER_LEN];
    /* 0x172A8 */ Game_unk_8860 unk_172A8[GAME_BUFFER_LEN];
    /* 0x17408 */ tetWell_unk_3830 unk_17408[GAME_BUFFER_LEN];
    /* 0x18188 */ tetWell_unk_3EF0 unk_18188[GAME_BUFFER_LEN];
    /* 0x182A8 */ tetWell_unk_3F80 unk_182A8[GAME_BUFFER_LEN];
    /* 0x182D8 */ tetWell_unk_3F98 unk_182D8[GAME_BUFFER_LEN];
    /* 0x18308 */ tetWell_unk_3FB0 unk_18308[GAME_BUFFER_LEN];
    /* 0x184B8 */ Mtx unk_184B8[GAME_BUFFER_LEN];
    /* 0x18538 */ Mtx unk_18538[GAME_BUFFER_LEN];
    /* 0x185B8 */ UNK_TYPE1 unk_185B8[0x140];
    /* 0x186F8 */ text_t unk_186F8[GAME_UNK_90C8_LEN];
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
    /* 0x8860 */ Game_unk_8860 unk_8860[GAME_BUFFER_LEN];
    /* 0x89C0 */ UNK_TYPE1 unk_89C0[0x4];
    /* 0x89C4 */ Game_unk_89C4 unk_89C4[UNK_SIZE];
    /* 0x89D4 */ UNK_TYPE2 unk_89D4;
    /* 0x89D6 */ UNK_TYPE2 unk_89D6;
    /* 0x89D8 */ UNK_TYPE1 unk_89D8[0x8B98-0x89D8];
    /* 0x8B98 */ Game_unk_8B98 unk_8B98[2];
    /* 0x8BC8 */ UNK_TYPE1 unk_8BC8[0xC0];
    /* 0x8C88 */ uObjBg unk_8C88[0xA];
    /* 0x8E18 */ UNK_TYPE1 unk_8E18[0x118];
    /* 0x8F30 */ UNK_TYPE1 unk_8F30[0x190];
    /* 0x90C0 */ s32 unk_90C0;
    /* 0x90C4 */ UNK_TYPE1 unk_90C4[0x4];
    /* 0x90C8 */ text_t unk_90C8[GAME_UNK_90C8_LEN];
    /* 0x9988 */ UNK_TYPE1 unk_9988[0xC8];
    /* 0x9A50 */ uObjBg unk_9A50;
    /* 0x9A78 */ UNK_TYPE1 unk_9A78[0x9AE0 - 0x9A78];
    /* 0x9AE0 */ Game_unk_9AE0 unk_9AE0;
    /* 0x9B08 */ UNK_TYPE1 unk_9B08[0x9C08 - 0x9B08];
    /* 0x9C08 */ s32 unk_9C08;
    /* 0x9C0C */ s32 unk_9C0C;
    /* 0x9C10 */ s32 unk_9C10;
    /* 0x9C14 */ s32 unk_9C14;
    /* 0x9C18 */ s32 unk_9C18;
    /* 0x9C1C */ s32 unk_9C1C;
    /* 0x9C20 */ UNK_TYPE1 unk_9C20[0x4];
    /* 0x9C24 */ UNK_TYPE4 unk_9C24;
    /* 0x9C28 */ UNK_TYPE4 unk_9C28;
    /* 0x9C2C */ UNK_TYPE4 unk_9C2C;
    /* 0x9C30 */ s32 unk_9C30;
    /* 0x9C34 */ UNK_TYPE4 unk_9C34;
    /* 0x9C38 */ UNK_TYPE1 unk_9C38[0x10];
    /* 0x9C48 */ struct_801A6DB8_usa unk_9C48[8];
} Game; // size >= 0xDA28


/* Original name: gTheGame */
extern Game gTheGame;

#endif
