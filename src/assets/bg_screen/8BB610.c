#include "bg_screen_load.h"

#include "alignment.h"
#include "libc/assert.h"

u16 bg_screen_8BB610_main[] ALIGNED(8) = {
#include "assets/bg_screen/8BB610/bg_screen_8BB610_main.rgba16.inc"
};
static_assert(sizeof(bg_screen_8BB610_main) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8BB610_MAIN_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8BB610_A[] ALIGNED(8) = {
#include "assets/bg_screen/8BB610/bg_screen_8BB610_A.rgba16.inc"
};
static_assert(sizeof(bg_screen_8BB610_A) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8BB610_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8BB610_B[] ALIGNED(8) = {
#include "assets/bg_screen/8BB610/bg_screen_8BB610_B.rgba16.inc"
};
static_assert(sizeof(bg_screen_8BB610_B) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8BB610_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8BB610_C[] ALIGNED(8) = {
#include "assets/bg_screen/8BB610/bg_screen_8BB610_C.rgba16.inc"
};
static_assert(sizeof(bg_screen_8BB610_C) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8BB610_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");
