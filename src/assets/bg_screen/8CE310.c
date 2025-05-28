#include "bg_screen_load.h"

#include "alignment.h"
#include "libc/assert.h"

u16 bg_screen_8CE310_main[] ALIGNED(8) = {
#include "assets/bg_screen/8CE310/bg_screen_8CE310_main.rgba16.inc"
};
static_assert(sizeof(bg_screen_8CE310_main) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8CE310_MAIN_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8CE310_A[] ALIGNED(8) = {
#include "assets/bg_screen/8CE310/bg_screen_8CE310_A.rgba16.inc"
};
static_assert(sizeof(bg_screen_8CE310_A) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8CE310_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8CE310_B[] ALIGNED(8) = {
#include "assets/bg_screen/8CE310/bg_screen_8CE310_B.rgba16.inc"
};
static_assert(sizeof(bg_screen_8CE310_B) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8CE310_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8CE310_C[] ALIGNED(8) = {
#include "assets/bg_screen/8CE310/bg_screen_8CE310_C.rgba16.inc"
};
static_assert(sizeof(bg_screen_8CE310_C) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8CE310_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");
