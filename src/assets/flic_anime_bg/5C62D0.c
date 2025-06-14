#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_5C62D0_0_header = {
    16,  // bpp
    0,   // is_intensity
    128, // width
    156, // height
    6,   // x
    60,  // y
};

FlicAnimeBGHeader flic_anime_bg_5C62D0_1_header = {
    16,  // bpp
    0,   // is_intensity
    112, // width
    84,  // height
    200, // x
    144, // y
};

u16 flic_anime_bg_5C62D0_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5C62D0/tex0.rgba16.inc"
};

u16 flic_anime_bg_5C62D0_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5C62D0/tex1.rgba16.inc"
};
