#include "assets/flic_anime_bg.h"

#include "alignment.h"
#include "libc/assert.h"
#include "macros_defines.h"

#define TEX_0_WIDTH 112
#define TEX_0_HEIGHT 162

FlicAnimeBGHeader flic_anime_bg_5F3090_0_header = {
    16,           // bpp
    0,            // is_intensity
    TEX_0_WIDTH,  // width
    TEX_0_HEIGHT, // height
    1,            // x
    60,           // y
};

#define TEX_1_WIDTH 80
#define TEX_1_HEIGHT 86

FlicAnimeBGHeader flic_anime_bg_5F3090_1_header = {
    16,           // bpp
    0,            // is_intensity
    TEX_1_WIDTH,  // width
    TEX_1_HEIGHT, // height
    228,          // x
    140,          // y
};

u16 flic_anime_bg_5F3090_0_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5F3090/tex0.rgba16.inc"
};
static_assert(ARRAY_COUNT(flic_anime_bg_5F3090_0_texture) == TEX_0_WIDTH * TEX_0_HEIGHT,
              "The texture doesn't have the expected dimensions.");

u16 flic_anime_bg_5F3090_1_texture[] ALIGNED(8) = {
#include "assets/flic_anime_bg/5F3090/tex1.rgba16.inc"
};
static_assert(ARRAY_COUNT(flic_anime_bg_5F3090_1_texture) == TEX_1_WIDTH * TEX_1_HEIGHT,
              "The texture doesn't have the expected dimensions.");
