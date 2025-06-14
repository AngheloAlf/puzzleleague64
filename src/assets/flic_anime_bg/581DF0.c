#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_581DF0_0_header = {
    16,  // bpp
    0,   // is_intensity
    112, // width
    155, // height
    2,   // x
    60,  // y
};

FlicAnimeBGHeader flic_anime_bg_581DF0_1_header = {
    16,  // bpp
    0,   // is_intensity
    88,  // width
    72,  // height
    223, // x
    146, // y
};

u16 flic_anime_bg_581DF0_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/581DF0/tex0.rgba16.inc"
};

u16 flic_anime_bg_581DF0_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/581DF0/tex1.rgba16.inc"
};
