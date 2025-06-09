#ifndef GAMEPAD_H
#define GAMEPAD_H

#include "ultra64.h"
#include "unk.h"

typedef struct gamepad_t {
    /* 0x00 */ UNK_PAD unk_00[0x4];
    /* 0x04 */ u16 touch_button;
    /* 0x06 */ u16 hold_button;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ UNK_TYPE1 unk_0C[2];
    /* 0x0E */ s16 unk_0E;
} gamepad_t; // size = 0x10

#if 0
struct gamepad_t {
    // total size: 0x10
    int position; // offset 0x0, size 0x4
    unsigned short touch_button; // offset 0x4, size 0x2
    unsigned short hold_button; // offset 0x6, size 0x2
    int hold; // offset 0x8, size 0x4
    unsigned short cont_button; // offset 0xC, size 0x2
    unsigned short button; // offset 0xE, size 0x2
};
#endif

#endif
