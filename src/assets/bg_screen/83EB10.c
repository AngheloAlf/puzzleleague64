#include "bg_screen_load.h"

#include "alignment.h"
#include "libc/assert.h"

u16 bg_screen_83EB10_main[] ALIGNED(8) = {
#include "assets/bg_screen/83EB10/bg_screen_83EB10_main.rgba16.inc"
};
static_assert(sizeof(bg_screen_83EB10_main) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_83EB10_MAIN_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_83EB10_A[] ALIGNED(8) = {
#include "assets/bg_screen/83EB10/bg_screen_83EB10_A.rgba16.inc"
};
static_assert(sizeof(bg_screen_83EB10_A) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_83EB10_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_83EB10_B[] ALIGNED(8) = {
#include "assets/bg_screen/83EB10/bg_screen_83EB10_B.rgba16.inc"
};
static_assert(sizeof(bg_screen_83EB10_B) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_83EB10_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_83EB10_C[] ALIGNED(8) = {
#include "assets/bg_screen/83EB10/bg_screen_83EB10_C.rgba16.inc"
};
static_assert(sizeof(bg_screen_83EB10_C) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_83EB10_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");
