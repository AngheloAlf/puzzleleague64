#ifndef UNKNOWN_STRUCTS_H
#define UNKNOWN_STRUCTS_H

#include "version.h"
#include "libultra.h"
#include "libc/stdint.h"
#include "libc/stdbool.h"
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
} enum_gMain;


typedef struct struct_gInfo {
    /* 0x00000 */ OSScTask scTask;
    /* 0x00068 */ Gfx unk_00068[UNK_SIZE];
    /* 0x00070 */ UNK_TYPE1 unk_00070[0x18FA0];
    #if VERSION_USA
    // EUR is 0x10 smaller
    // TODO: figure out exactly which members are not present
    /* 0x19010 */ UNK_TYPE1 unk_19010[0x10];
    #endif
    /* 0x19020 */ s16 unk_19020;
    /* 0x19022 */ UNK_TYPE1 unk_19022[0x2];
    /* 0x19024 */ UNK_TYPE1 unk_19024[0x1C];
    /* 0x19040 */ void *unk_19040;
    /* 0x19044 */ UNK_TYPE1 unk_19044[0x4];
} struct_gInfo; // size = 0x19048


#endif
