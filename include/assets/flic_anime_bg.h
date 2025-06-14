#ifndef FLIC_ANIME_BG_H
#define FLIC_ANIME_BG_H

#include "ultra64.h"

typedef struct FlicAnimeBGHeader {
    /* 0x0 */ s16 bpp; // bits per pixel. Only 8 and 16 are supported in code, but only 16 is actually used.
    /* 0x2 */ s16 is_intensity; // I textures intead of CI. This is ignored if bpp is not 8.
    /* 0x4 */ s16 width;
    /* 0x6 */ s16 height;
    /* 0x8 */ u16 x;
    /* 0xA */ u16 y;
} FlicAnimeBGHeader; // size = 0xC

#endif
