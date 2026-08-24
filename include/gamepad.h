#ifndef GAMEPAD_H
#define GAMEPAD_H

#include "ultra64.h"
#include "unk.h"

typedef struct gamepad_t {
    /* 0x00 */ s32 position;
    /* 0x04 */ u16 touch_button;
    /* 0x06 */ u16 hold_button;
    /* 0x08 */ s32 hold;
    /* 0x0C */ u16 cont_button;
    /* 0x0E */ u16 button;
} gamepad_t; // size = 0x10

#endif
