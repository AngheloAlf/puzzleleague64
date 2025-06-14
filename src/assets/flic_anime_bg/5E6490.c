#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_5E6490_0_header = {
    16,  // bpp
    0,   // is_intensity
    112, // width
    173, // height
    5,   // x
    47,  // y
};

FlicAnimeBGHeader flic_anime_bg_5E6490_1_header = {
    16,  // bpp
    0,   // is_intensity
    80,  // width
    84,  // height
    227, // x
    140, // y
};

u16 flic_anime_bg_5E6490_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5E6490/tex0.rgba16.inc"
};

u16 flic_anime_bg_5E6490_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5E6490/tex1.rgba16.inc"
};
