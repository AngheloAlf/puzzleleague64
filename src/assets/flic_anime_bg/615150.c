#include "assets/flic_anime_bg.h"

#include "alignment.h"

FlicAnimeBGHeader flic_anime_bg_615150_0_header = {
    16,  // bpp
    0,   // is_intensity
    64,  // width
    170, // height
    32,  // x
    53,  // y
};

FlicAnimeBGHeader flic_anime_bg_615150_1_header = {
    16,  // bpp
    0,   // is_intensity
    96,  // width
    72,  // height
    219, // x
    148, // y
};

u16 flic_anime_bg_615150_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/615150/tex0.rgba16.inc"
};

u16 flic_anime_bg_615150_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/615150/tex1.rgba16.inc"
};
