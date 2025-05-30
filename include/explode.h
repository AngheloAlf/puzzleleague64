#ifndef EXPLODE_H
#define EXPLODE_H

#include "ultra64.h"
#include "PR/gs2dex.h"
#include "unk.h"

typedef struct explode_t {
    /* 0x00 */ s32 type;
    /* 0x04 */ s32 frame;
    /* 0x08 */ UNK_TYPE1 unk_08[0x10];
    /* 0x18 */ uObjSprite rect;
} explode_t; // size = 0x30

#if 0
struct explode_t {
    // total size: 0x30
    int type; // offset 0x0, size 0x4
    int frame; // offset 0x4, size 0x4
    int pos; // offset 0x8, size 0x4
    int x; // offset 0xC, size 0x4
    int y; // offset 0x10, size 0x4
    uObjSprite rect; // offset 0x18, size 0x18
};
#endif

#endif
