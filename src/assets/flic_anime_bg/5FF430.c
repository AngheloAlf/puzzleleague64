#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_5FF430_0_header = {
    16,  // bpp
    0,   // is_intensity
    144, // width
    112, // height
    0,   // x
    52,  // y
};

FlicAnimeBGHeader flic_anime_bg_5FF430_1_header = {
    16,  // bpp
    0,   // is_intensity
    96,  // width
    98,  // height
    218, // x
    133, // y
};

u16 flic_anime_bg_5FF430_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5FF430/tex0.rgba16.inc"
};

u16 flic_anime_bg_5FF430_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5FF430/tex1.rgba16.inc"
};
