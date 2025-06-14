#include "ultra64.h"

#include "alignment.h"

typedef struct AnimeBGHeader {
    /* 0x0 */ s16 unk_0; // bpp? (bits per pixel) // only 8 and 16 seem to be supported
    /* 0x2 */ s16 unk_2; // Intensity image. This is ignored if unk_0 is not 8.
    /* 0x4 */ s16 unk_4; // width
    /* 0x6 */ s16 unk_6; // height
    /* 0x8 */ u16 unk_8; // x
    /* 0xA */ u16 unk_A; // y
} AnimeBGHeader;         // size = 0xC

AnimeBGHeader assets_074280_0_header = {
    16, 0, 112, 155, 2, 60,
};

AnimeBGHeader assets_074280_1_header = {
    16, 0, 88, 72, 223, 146,
};

u16 assets_074280_0_texture[] ALIGNED(8) = {
#include "assets/assets_074280/581DF0/tex0.rgba16.inc"
};

u16 assets_074280_1_texture[] ALIGNED(8) = {
#include "assets/assets_074280/581DF0/tex1.rgba16.inc"
};
