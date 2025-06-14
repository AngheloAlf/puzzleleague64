#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_5D4870_0_header = {
    16,  // bpp
    0,   // is_intensity
    128, // width
    186, // height
    0,   // x
    47,  // y
};

FlicAnimeBGHeader flic_anime_bg_5D4870_1_header = {
    16,  // bpp
    0,   // is_intensity
    128, // width
    98,  // height
    192, // x
    135, // y
};

u16 flic_anime_bg_5D4870_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5D4870/tex0.rgba16.inc"
};

u16 flic_anime_bg_5D4870_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5D4870/tex1.rgba16.inc"
};
