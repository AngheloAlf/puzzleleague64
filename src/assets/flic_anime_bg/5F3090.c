#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_5F3090_0_header = {
    16,  // bpp
    0,   // is_intensity
    112, // width
    162, // height
    1,   // x
    60,  // y
};

FlicAnimeBGHeader flic_anime_bg_5F3090_1_header = {
    16,  // bpp
    0,   // is_intensity
    80,  // width
    86,  // height
    228, // x
    140, // y
};

u16 flic_anime_bg_5F3090_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5F3090/tex0.rgba16.inc"
};

u16 flic_anime_bg_5F3090_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5F3090/tex1.rgba16.inc"
};
