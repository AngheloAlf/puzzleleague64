#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_599F70_0_header = {
    16,  // bpp
    0,   // is_intensity
    128, // width
    184, // height
    0,   // x
    40,  // y
};

FlicAnimeBGHeader flic_anime_bg_599F70_1_header = {
    16,  // bpp
    0,   // is_intensity
    80,  // width
    84,  // height
    220, // x
    140, // y
};

u16 flic_anime_bg_599F70_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/599F70/tex0.rgba16.inc"
};

u16 flic_anime_bg_599F70_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/599F70/tex1.rgba16.inc"
};
