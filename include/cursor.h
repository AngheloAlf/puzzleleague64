#ifndef CURSOR_H
#define CURSOR_H

#include "ultra64.h"
#include "PR/gs2dex.h"
#include "unk.h"

// maybe (playercount*2 + 3)?
#define CURSOR_UNK_28_COUNT 23
#define CURSOR_UNK_84_COUNT 5

/* Original name: cursor_t */
typedef struct cursor_t {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 extra_wait; /* Original name: extra_wait */ // TODO: maybe misnamed?
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 x; /* Original name: x */
    /* 0x14 */ s32 y; /* Original name: y */
    /* 0x18 */ s32 sx; /* Original name: sx */
    /* 0x1C */ s32 sy; /* Original name: sy */
    /* 0x20 */ s32 frame_n; /* Original name: frame_n */
    /* 0x24 */ s32 frame_d; /* Original name: frame_d */
    /* 0x28 */ s32 target[CURSOR_UNK_28_COUNT]; /* Original name: target */
    /* 0x84 */ s32 unk_84[CURSOR_UNK_84_COUNT];
    /* 0x98 */ uObjSprite rect; /* Original name: rect */
} cursor_t; // size = 0xB0

#if 0
struct cursor_t {
    // total size: 0x110
    int state; // offset 0x0, size 0x4
    int delay; // offset 0x4, size 0x4
    int waiting; // offset 0x8, size 0x4
    int extra_wait; // offset 0xC, size 0x4
    int x; // offset 0x10, size 0x4
    int y; // offset 0x14, size 0x4
    int sx; // offset 0x18, size 0x4
    int sy; // offset 0x1C, size 0x4
    int frame_n; // offset 0x20, size 0x4
    int frame_d; // offset 0x24, size 0x4
    int target[43]; // offset 0x28, size 0xAC
    int store[5]; // offset 0xD4, size 0x14
    uObjSprite rect; // offset 0xE8, size 0x18
    enum pStateEnum pstate; // offset 0x100, size 0x4
    int GameEnd_Value; // offset 0x104, size 0x4
    int AttackWhomLockOnto; // offset 0x108, size 0x4
};
#endif

#endif
