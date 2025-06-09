#ifndef UNKNOWN_STRUCTS_H
#define UNKNOWN_STRUCTS_H

#include "version.h"
#include "ultra64.h"
#include "libc/stdint.h"
#include "libc/stdbool.h"
#include "other_types.h"
#include "unk.h"

typedef enum enum_gMain {
    /*    -1 */ GMAIN__1 = -1,
    /* 0x14D */ GMAIN_14D = 0x14D,
    /* 0x1F4 */ GMAIN_TITLE = 0x1F4,
    /* 0x258 */ GMAIN_258 = 0x258, // menu related
    /* 0x28A */ GMAIN_28A = 0x28A, // menu related
    /* 0x2BC */ GMAIN_2BC = 0x2BC, // menu related
    /* 0x341 */ GMAIN_MIMIC = 0x341,
    /* 0x34C */ GMAIN_TUTORIAL = 0x34C,
    /* 0x357 */ GMAIN_STAGE_CLEAR_INTRO = 0x357,
    /* 0x36D */ GMAIN_BONUS = 0x36D,
    /* 0x378 */ GMAIN_EDITOR = 0x378,
    /* 0x383 */ GMAIN_STORY = 0x383,
    /* 0x384 */ GMAIN_384,
    /* 0x387 */ GMAIN_387 = 0x387,
    /* 0x388 */ GMAIN_388,
    /* 0x38E */ GMAIN_38E = 0x38E,
    /* 0x390 */ GMAIN_390 = 0x390,
    /* 0x393 */ GMAIN_393 = 0x393,
    /* 0x395 */ GMAIN_395 = 0x395,
} enum_gMain;

typedef enum enum_gDemo {
    /* 0x0B */ GDEMO_0B = 0x0B,
    /* 0x16 */ GDEMO_16 = 0x16,
    /* 0x21 */ GDEMO_21 = 0x21,
    /* 0x2C */ GDEMO_2C = 0x2C,
} enum_gDemo;


#endif
