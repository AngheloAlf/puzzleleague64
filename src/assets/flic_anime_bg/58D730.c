#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_58D730_0_header = {
    16,  // bpp
    0,   // is_intensity
    112, // width
    167, // height
    0,   // x
    48,  // y
};

FlicAnimeBGHeader flic_anime_bg_58D730_1_header = {
    16,  // bpp
    0,   // is_intensity
    96,  // width
    72,  // height
    220, // x
    142, // y
};

u16 flic_anime_bg_58D730_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/58D730/tex0.rgba16.inc"
};

u16 flic_anime_bg_58D730_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/58D730/tex1.rgba16.inc"
};
