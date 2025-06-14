#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_5B6730_0_header = {
    16,  // bpp
    0,   // is_intensity
    128, // width
    184, // height
    0,   // x
    37,  // y
};

FlicAnimeBGHeader flic_anime_bg_5B6730_1_header = {
    16,  // bpp
    0,   // is_intensity
    96,  // width
    90,  // height
    221, // x
    134, // y
};

u16 flic_anime_bg_5B6730_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5B6730/tex0.rgba16.inc"
};

u16 flic_anime_bg_5B6730_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5B6730/tex1.rgba16.inc"
};
