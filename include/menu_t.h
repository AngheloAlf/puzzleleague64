#ifndef MENU_T_H
#define MENU_T_H

#include "ultra64.h"

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


typedef struct menu_t {
    /* 0x0 */ s32 unk_0; // TODO: enum?
    /* 0x4 */ s32 unk_4; // enum_tetWell_unk_4424
    /* 0x8 */ s32 unk_8;
    /* 0xC */ s32 unk_C;
} menu_t; // size = 0x10

#if 0
struct menu_t {
    // total size: 0x18
    int game; // offset 0x0, size 0x4
    int stage; // offset 0x4, size 0x4
    int speed; // offset 0x8, size 0x4
    int misc; // offset 0xC, size 0x4
    int ai; // offset 0x10, size 0x4
    int player; // offset 0x14, size 0x4
};
#endif

#endif
