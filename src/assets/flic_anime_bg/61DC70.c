#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_61DC70_0_header = {
    16,  // bpp
    0,   // is_intensity
    128, // width
    169, // height
    0,   // x
    54,  // y
};

FlicAnimeBGHeader flic_anime_bg_61DC70_1_header = {
    16,  // bpp
    0,   // is_intensity
    64,  // width
    75,  // height
    234, // x
    153, // y
};

u16 flic_anime_bg_61DC70_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/61DC70/tex0.rgba16.inc"
};

u16 flic_anime_bg_61DC70_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/61DC70/tex1.rgba16.inc"
};
