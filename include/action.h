#ifndef ACTION_H
#define ACTION_H

#include "ultra64.h"
#include "unk.h"

#define ACTION_COUNT 10

typedef struct action_t {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ s32 unk_8;
} action_t; // size = 0xC

#if 0
struct action_t {
    // total size: 0xC
    int current_flic; // offset 0x0, size 0x4
    int posX; // offset 0x4, size 0x4
    int posY; // offset 0x8, size 0x4
};
#endif

#endif
