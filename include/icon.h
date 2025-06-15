#ifndef ICON_H
#define ICON_H

#include "ultra64.h"
#include "PR/gs2dex.h"
#include "macros_defines.h"
#include "unk.h"

typedef enum IconType {
    // -1 ?
    /* 10 */ ICONTYPE_10 = 10,
    /* 11 */ ICONTYPE_11,
    /* 12 */ ICONTYPE_12,
    /* 13 */ ICONTYPE_13,
} IconType;

typedef union IconThing {
    uObjSprite rect;
    Mtx move;
} IconThing;

typedef struct icon_t {
    /* 0x00 */ s32 flag; // bool?
    /* 0x04 */ ENUM_TYPE(IconType, s32) type;
    /* 0x08 */ s32 total;
    /* 0x0C */ s32 from_x;
    /* 0x10 */ s32 from_y;
    /* 0x14 */ s32 to_x;
    /* 0x18 */ s32 to_y;
    /* 0x1C */ s32 count;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ UNK_TYPE1 unk_24[0x28-0x024]; // alignment padding?
    /* 0x28 */ IconThing thing;
} icon_t; // size = 0x68

#if 0
typedef union /* union_pon_gc_c_262 */ {
    union {
        struct {
            // total size: 0x18
            signed short objX; // offset 0x0, size 0x2
            unsigned short scaleW; // offset 0x2, size 0x2
            unsigned short imageW; // offset 0x4, size 0x2
            unsigned short paddingX; // offset 0x6, size 0x2
            signed short objY; // offset 0x8, size 0x2
            unsigned short scaleH; // offset 0xA, size 0x2
            unsigned short imageH; // offset 0xC, size 0x2
            unsigned short paddingY; // offset 0xE, size 0x2
            unsigned short imageStride; // offset 0x10, size 0x2
            unsigned short imageAdrs; // offset 0x12, size 0x2
            unsigned char imageFmt; // offset 0x14, size 0x1
            unsigned char imageSiz; // offset 0x15, size 0x1
            unsigned char imagePal; // offset 0x16, size 0x1
            unsigned char imageFlags; // offset 0x17, size 0x1
        } s; // offset 0x0, size 0x18
        long long force_structure_alignment; // offset 0x0, size 0x8
    } rect; // offset 0x0, size 0x18
    union {
        long m[4][4]; // offset 0x0, size 0x40
        long long force_structure_alignment; // offset 0x0, size 0x8
    } move; // offset 0x0, size 0x40
} union_pon_gc_c_262;

struct icon_t {
    // total size: 0x68
    int flag; // offset 0x0, size 0x4
    int type; // offset 0x4, size 0x4
    int total; // offset 0x8, size 0x4
    int from_x; // offset 0xC, size 0x4
    int from_y; // offset 0x10, size 0x4
    int to_x; // offset 0x14, size 0x4
    int to_y; // offset 0x18, size 0x4
    int count; // offset 0x1C, size 0x4
    int distance; // offset 0x20, size 0x4
    union_pon_gc_c_262 thing; // offset 0x28, size 0x40
};
#endif

#endif
