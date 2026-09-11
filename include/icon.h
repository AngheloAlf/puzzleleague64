#ifndef ICON_H
#define ICON_H

#include "ultra64.h"
#include "PR/gs2dex.h"
#include "macros_defines.h"
#include "unk.h"

#define ICON_COUNT (10)

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

/* Original name: icon_t */
typedef struct icon_t {
    /* 0x00 */ s32 flag; /* Original name: flag */ // bool?
    /* 0x04 */ ENUM_TYPE(IconType, s32) type; /* Original name: type */
    /* 0x08 */ s32 total; /* Original name: total */
    /* 0x0C */ s32 from_x; /* Original name: from_x */
    /* 0x10 */ s32 from_y; /* Original name: from_y */
    /* 0x14 */ s32 to_x; /* Original name: to_x */
    /* 0x18 */ s32 to_y; /* Original name: to_y */
    /* 0x1C */ s32 count; /* Original name: count */
    /* 0x20 */ s32 distance; /* Original name: distance */
    /* 0x28 */ IconThing thing; /* Original name: thing */
} icon_t; // size = 0x68

#endif
