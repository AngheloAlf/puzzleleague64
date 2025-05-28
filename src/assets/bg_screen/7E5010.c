#include "bg_screen_load.h"

#include "alignment.h"
#include "libc/assert.h"

u16 bg_screen_7E5010_main[] ALIGNED(8) = {
#include "assets/bg_screen/7E5010/bg_screen_7E5010_main.rgba16.inc"
};
static_assert(sizeof(bg_screen_7E5010_main) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_7E5010_MAIN_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_7E5010_A[] ALIGNED(8) = {
#include "assets/bg_screen/7E5010/bg_screen_7E5010_A.rgba16.inc"
};
static_assert(sizeof(bg_screen_7E5010_A) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_7E5010_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_7E5010_B[] ALIGNED(8) = {
#include "assets/bg_screen/7E5010/bg_screen_7E5010_B.rgba16.inc"
};
static_assert(sizeof(bg_screen_7E5010_B) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_7E5010_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_7E5010_C[] ALIGNED(8) = {
#include "assets/bg_screen/7E5010/bg_screen_7E5010_C.rgba16.inc"
};
static_assert(sizeof(bg_screen_7E5010_C) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_7E5010_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");
