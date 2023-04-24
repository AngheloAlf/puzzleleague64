#ifndef THE_GAME_H
#define THE_GAME_H

#include "libultra.h"
#include "unk.h"

typedef struct TheGame_unk_0000_unk_0000_unk_000_unk_000 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x24];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ UNK_TYPE1 unk_28[0x4];
} TheGame_unk_0000_unk_0000_unk_000_unk_000; // size = 0x2C

typedef struct TheGame_unk_0000_unk_0000_unk_000 {
    TheGame_unk_0000_unk_0000_unk_000_unk_000 unk_000[6];
    /* 0x108 */ UNK_TYPE1 unk_108[0x210];
} TheGame_unk_0000_unk_0000_unk_000; // size = 0x318

typedef struct TheGame_unk_0000_unk_0000 {
    /* 0x0000 */ TheGame_unk_0000_unk_0000_unk_000 unk_0000[0xC];
} TheGame_unk_0000_unk_0000; // size = 0x2520

typedef struct TheGame_unk_0000_unk_2520 {
    /* 0x000 */ UNK_TYPE1 unk_000[0x5A0];
} TheGame_unk_0000_unk_2520; // size = 0x5A0

typedef struct TheGame_unk_0000_unk_2AC0 {
    /* 0x000 */ UNK_TYPE1 unk_000[0x410];
} TheGame_unk_0000_unk_2AC0; // size = 0x410

typedef struct TheGame_unk_0000_unk_2ED0 {
    /* 0x000 */ UNK_TYPE1 unk_000[0x960];
} TheGame_unk_0000_unk_2ED0; // size = 0x960

typedef struct TheGame_unk_0000_unk_3830 {
    /* 0x000 */ UNK_TYPE1 unk_000[0x6C0];
} TheGame_unk_0000_unk_3830; // size = 0x6C0

typedef struct TheGame_unk_0000_unk_3EF0 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x90];
} TheGame_unk_0000_unk_3EF0; // size = 0x90

typedef struct TheGame_unk_0000_unk_3F80 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x18];
} TheGame_unk_0000_unk_3F80; // size = 0x18

typedef struct TheGame_unk_0000_unk_3F98 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x18];
} TheGame_unk_0000_unk_3F98; // size = 0x18

typedef struct TheGame_unk_0000_unk_3FB0 {
    /* 0x00 */ UNK_TYPE1 unk_00[0xD8];
} TheGame_unk_0000_unk_3FB0; // size = 0xD8


typedef struct TheGame_unk_0000 {
    /* 0x0000 */ TheGame_unk_0000_unk_0000 unk_0000;
    /* 0x2520 */ TheGame_unk_0000_unk_2520 unk_2520;
    /* 0x2AC0 */ TheGame_unk_0000_unk_2AC0 unk_2AC0;
    /* 0x2ED0 */ TheGame_unk_0000_unk_2ED0 unk_2ED0;
    /* 0x3830 */ TheGame_unk_0000_unk_3830 unk_3830;
    /* 0x3EF0 */ TheGame_unk_0000_unk_3EF0 unk_3EF0;
    /* 0x3F80 */ TheGame_unk_0000_unk_3F80 unk_3F80;
    /* 0x3F98 */ TheGame_unk_0000_unk_3F98 unk_3F98;
    /* 0x3FB0 */ TheGame_unk_0000_unk_3FB0 unk_3FB0;
    /* 0x4088 */ f32 unk_4088;
    /* 0x408C */ UNK_TYPE1 unk_408C[0x32C];
    /* 0x43B8 */ s32 unk_43B8;
    /* 0x43BC */ UNK_TYPE1 unk_43BC[0x48];
    /* 0x4404 */ UNK_TYPE4 unk_4404;
    /* 0x4408 */ UNK_TYPE1 unk_4408[0x28];
} TheGame_unk_0000; // size = 0x4430


typedef struct TheGame_unk_8860 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x4];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ UNK_TYPE1 unk_08[0xC];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ UNK_TYPE4 unk_20;
    /* 0x24 */ UNK_TYPE1 unk_24[0x74];
    /* 0x98 */ uObjSprite unk_98;
} TheGame_unk_8860; // size = 0xB0


typedef struct TheGame_unk_90C8 {
    /* 0x000 */ UNK_TYPE1 unk_000[0x8C0];
} TheGame_unk_90C8; // size = 0x8C0




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

#define THEGAME_BUFFER_LEN 2

typedef struct struct_gInfo_unk_00068 {
    /* 0x00000 */ Gfx unk_00000[UNK_SIZE];
    /* 0x00008 */ UNK_TYPE1 unk_00008[0x100F8];
    /* 0x10100 */ Mtx unk_10100[THEGAME_BUFFER_LEN];
    /* 0x10180 */ Mtx unk_10180[THEGAME_BUFFER_LEN];
    /* 0x10200 */ UNK_TYPE1 unk_10200[0x8];
    /* 0x10208 */ struct_gInfo_unk_10208 unk_10208[THEGAME_BUFFER_LEN];
    /* 0x10224 */ struct_gInfo_unk_10224 unk_10224[THEGAME_BUFFER_LEN];
    /* 0x10240 */ UNK_TYPE unk_10240;
    /* 0x10244 */ TheGame_unk_0000_unk_0000 unk_10244[THEGAME_BUFFER_LEN];
    /* 0x14C84 */ UNK_TYPE1 unk_14C84[0x4];
    /* 0x14C88 */ TheGame_unk_0000_unk_2520 unk_14C88[THEGAME_BUFFER_LEN];
    /* 0x157C8 */ TheGame_unk_0000_unk_2AC0 unk_157C8[THEGAME_BUFFER_LEN];
    /* 0x15FE8 */ TheGame_unk_0000_unk_2ED0 unk_15FE8[THEGAME_BUFFER_LEN];
    /* 0x172A8 */ TheGame_unk_8860 unk_172A8[THEGAME_BUFFER_LEN];
    /* 0x17408 */ TheGame_unk_0000_unk_3830 unk_17408[THEGAME_BUFFER_LEN];
    /* 0x18188 */ TheGame_unk_0000_unk_3EF0 unk_18188[THEGAME_BUFFER_LEN];
    /* 0x182A8 */ TheGame_unk_0000_unk_3F80 unk_182A8[THEGAME_BUFFER_LEN];
    /* 0x182D8 */ TheGame_unk_0000_unk_3F98 unk_182D8[THEGAME_BUFFER_LEN];
    /* 0x18308 */ TheGame_unk_0000_unk_3FB0 unk_18308[THEGAME_BUFFER_LEN];
    /* 0x184B8 */ Mtx unk_184B8[THEGAME_BUFFER_LEN];
    /* 0x18538 */ Mtx unk_18538[THEGAME_BUFFER_LEN];
    /* 0x185B8 */ UNK_TYPE1 unk_185B8[0x140];
    /* 0x186F8 */ TheGame_unk_90C8 unk_186F8;
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


typedef struct TheGame {
    /* 0x0000 */ TheGame_unk_0000 unk_0000[THEGAME_BUFFER_LEN];
    /* 0x8860 */ TheGame_unk_8860 unk_8860[THEGAME_BUFFER_LEN];
    /* 0x89C0 */ UNK_TYPE1 unk_89C0[0x4];
    /* 0x89C4 */ u16 unk_89C4;
    /* 0x89C6 */ u16 unk_89C6;
    /* 0x89C8 */ UNK_TYPE1 unk_89C8[0x700];
    /* 0x90C8 */ TheGame_unk_90C8 unk_90C8;
    /* 0x9988 */ UNK_TYPE1 unk_9988[0xD4];
    /* 0x9A5C */ UNK_TYPE1 unk_9A5C[0x2];
    /* 0x9A5C */ UNK_TYPE2 unk_9A5E;
    /* 0x9A60 */ UNK_TYPE1 unk_9A60[0x1A8];
    /* 0x9C08 */ s32 unk_9C08; // playercount? // goes up to THEGAME_BUFFER_LEN
    /* 0x9C0C */ s32 unk_9C0C;
    /* 0x9C10 */ s32 unk_9C10;
    /* 0x9C14 */ s32 unk_9C14;
    /* 0x9C18 */ s32 unk_9C18;
    /* 0x9C1C */ s32 unk_9C1C;
    /* 0x9C20 */ UNK_TYPE1 unk_9C20[0x8];
    /* 0x9C28 */ UNK_TYPE4 unk_9C28;
    /* 0x9C2C */ UNK_TYPE4 unk_9C2C;
    /* 0x9C30 */ UNK_TYPE4 unk_9C30;
    /* 0x9C34 */ UNK_TYPE4 unk_9C34;
    /* 0x9C38 */ UNK_TYPE1 unk_9C38[0x10];
    /* 0x9C48 */ struct_801A6DB8_usa unk_9C48[8];
} TheGame; // size >= 0xDA28


extern TheGame gTheGame;

#endif
