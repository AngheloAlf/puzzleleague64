#include "assets/flic_anime_bg.h"

#include "alignment.h"
#include "libc/assert.h"
#include "macros_defines.h"

#define TEX_0_WIDTH 128
#define TEX_0_HEIGHT 184

FlicAnimeBGHeader flic_anime_bg_599F70_0_header = {
    16,           // bpp
    0,            // is_intensity
    TEX_0_WIDTH,  // width
    TEX_0_HEIGHT, // height
    0,            // x
    40,           // y
};

#define TEX_1_WIDTH 80
#define TEX_1_HEIGHT 84

FlicAnimeBGHeader flic_anime_bg_599F70_1_header = {
    16,           // bpp
    0,            // is_intensity
    TEX_1_WIDTH,  // width
    TEX_1_HEIGHT, // height
    220,          // x
    140,          // y
};

u16 flic_anime_bg_599F70_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/599F70/tex0.rgba16.inc"
};
static_assert(ARRAY_COUNT(flic_anime_bg_599F70_0_texture) == TEX_0_WIDTH * TEX_0_HEIGHT,
              "The texture doesn't have the expected dimensions.");

u16 flic_anime_bg_599F70_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/599F70/tex1.rgba16.inc"
};
static_assert(ARRAY_COUNT(flic_anime_bg_599F70_1_texture) == TEX_1_WIDTH * TEX_1_HEIGHT,
              "The texture doesn't have the expected dimensions.");
