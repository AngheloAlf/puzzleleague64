#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_5A8C10_0_header = {
    16,  // bpp
    0,   // is_intensity
    128, // width
    156, // height
    0,   // x
    59,  // y
};

FlicAnimeBGHeader flic_anime_bg_5A8C10_1_header = {
    16,  // bpp
    0,   // is_intensity
    96,  // width
    84,  // height
    224, // x
    142, // y
};

u16 flic_anime_bg_5A8C10_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5A8C10/tex0.rgba16.inc"
};

u16 flic_anime_bg_5A8C10_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5A8C10/tex1.rgba16.inc"
};
