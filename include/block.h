#ifndef BLOCK_H
#define BLOCK_H

#include "ultra64.h"
#include "macros_defines.h"

#define BLOCK_LEN_ROWS (12)
#define BLOCK_LEN_B (18)

#define TETWELL_OBJSPRITE_LEN_B (BLOCK_LEN_B / 3)

typedef enum BlockState {
    /* 0 */ BLOCKSTATE_0,
    /* 1 */ BLOCKSTATE_1,
    /* 2 */ BLOCKSTATE_2,
    /* 3 */ BLOCKSTATE_3,
    /* 4 */ BLOCKSTATE_4,
    /* 5 */ BLOCKSTATE_5,
    /* 6 */ BLOCKSTATE_6,
    /* 7 */ BLOCKSTATE_7,
    /* 9 */ BLOCKSTATE_9 = 9,
} BlockState;

typedef enum BlockType {
    /*  0 */ BLOCKTYPE_0,
    /*  1 */ BLOCKTYPE_1,
    /*  2 */ BLOCKTYPE_2,
    /*  3 */ BLOCKTYPE_3,
    /*  4 */ BLOCKTYPE_4,
    /*  5 */ BLOCKTYPE_5,
    /*  6 */ BLOCKTYPE_6,
    /*  7 */ BLOCKTYPE_7,
    /*  8 */ BLOCKTYPE_8,
    /*  9 */ BLOCKTYPE_9,
    /* 10 */ BLOCKTYPE_10,
    /* 12 */ BLOCKTYPE_12 = 12,
} BlockType;

/* Original name: block_t. */
typedef struct block_t {
    /* 0x00 */ ENUM_TYPE(BlockState, s32) state; /* Original name: state */
    /* 0x04 */ s32 delay; /* Original name: delay */
    /* 0x08 */ s32 disappear; /* Original name: disappear */
    /* 0x0C */ s32 drop; /* Original name: drop */
    /* 0x10 */ ENUM_TYPE(BlockType, s32) type; /* Original name: type */
    /* 0x14 */ s32 bomb; /* Original name: bomb */
    /* 0x18 */ s32 sound; /* Original name: sound */
    /* 0x1C */ s32 currRow; /* Original name: currRow */
    /* 0x20 */ s32 chain_flag; /* Original name: chain_flag */ // bool?
    /* 0x24 */ s32 frame_n; /* Original name: frame_n */
    /* 0x28 */ s32 frame_d; /* Original name: frame_d */
} block_t; // size = 0x2C

#endif
