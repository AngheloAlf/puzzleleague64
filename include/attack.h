#ifndef ATTACK_H
#define ATTACK_H

#include "ultra64.h"
#include "PR/gs2dex.h"
#include "unk.h"

typedef struct attack_t {
    /* 0x00 */ s32 state;
    /* 0x04 */ s32 type;
    /* 0x08 */ s32 disappear;
    /* 0x0C */ s32 delay;
    /* 0x10 */ UNK_TYPE1 unk_10[0x30-0x10];
    /* 0x30 */ uObjSprite rect;
} attack_t; // size = 0x48

#if 0
struct attack_t {
    // total size: 0x50
    int state; // offset 0x0, size 0x4
    int type; // offset 0x4, size 0x4
    int disappear; // offset 0x8, size 0x4
    int delay; // offset 0xC, size 0x4
    int counter; // offset 0x10, size 0x4
    int level; // offset 0x14, size 0x4
    int start; // offset 0x18, size 0x4
    int end; // offset 0x1C, size 0x4
    int expression; // offset 0x20, size 0x4
    int currRow; // offset 0x24, size 0x4
    int slot; // offset 0x28, size 0x4
    uObjSprite rect; // offset 0x30, size 0x18
    int ChainCriminalPlayerNo; // offset 0x48, size 0x4
    int ComboCriminalPlayerNo; // offset 0x4C, size 0x4
};
#endif

#endif
