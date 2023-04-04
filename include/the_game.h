#ifndef THE_GAME_H
#define THE_GAME_H

#include "libultra.h"
#include "unk.h"


typedef struct struct_801A6DB8_usa_unk_002 {
    /* 0x0 */ UNK_TYPE1 unk_0[0xE];
} struct_801A6DB8_usa_unk_002; // size = 0xE

typedef struct struct_801A6DB8_usa_unk_02B {
    /* 0x0 */ UNK_TYPE1 unk_0[0x6];
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
    /* 0x000 */ u8 unk_000;
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
    /* 0x0E0 */ u8 unk_0E0;
    /* 0x0E1 */ u8 unk_0E1;
    /* 0x0E2 */ u8 unk_0E2;
    /* 0x0E3 */ u8 unk_0E3;
    /* 0x0E4 */ u8 unk_0E4;
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


typedef struct TheGame {
    /* 0x0000 */ UNK_TYPE1 unk_0000[0x9C0C];
    /* 0x9C0C */ s32 unk_9C0C;
    /* 0x9C10 */ s32 unk_9C10;
    /* 0x9C14 */ UNK_TYPE1 unk_9C14[0x34];
    /* 0x9C48 */ struct_801A6DB8_usa unk_9C48[8];
} TheGame; // size >= 0xDA28


extern TheGame gTheGame;

#endif
