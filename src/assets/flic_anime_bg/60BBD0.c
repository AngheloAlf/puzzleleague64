#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_60BBD0_0_header = {
    16,  // bpp
    0,   // is_intensity
    96,  // width
    135, // height
    31,  // x
    82,  // y
};

FlicAnimeBGHeader flic_anime_bg_60BBD0_1_header = {
    16,  // bpp
    0,   // is_intensity
    80,  // width
    77,  // height
    229, // x
    145, // y
};

u16 flic_anime_bg_60BBD0_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/60BBD0/tex0.rgba16.inc"
};

u16 flic_anime_bg_60BBD0_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/60BBD0/tex1.rgba16.inc"
};
