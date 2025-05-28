#include "bg_screen_load.h"

#include "alignment.h"
#include "libc/assert.h"

u16 bg_screen_8E2A50_main[] ALIGNED(8) = {};
static_assert(sizeof(bg_screen_8E2A50_main) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8E2A50_MAIN_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8E2A50_A[] ALIGNED(8) = {
#include "assets/bg_screen/8E2A50/bg_screen_8E2A50_A.rgba16.inc"
};
static_assert(sizeof(bg_screen_8E2A50_A) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8E2A50_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8E2A50_B[] ALIGNED(8) = {
#include "assets/bg_screen/8E2A50/bg_screen_8E2A50_B.rgba16.inc"
};
static_assert(sizeof(bg_screen_8E2A50_B) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8E2A50_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8E2A50_C[] ALIGNED(8) = {
#include "assets/bg_screen/8E2A50/bg_screen_8E2A50_C.rgba16.inc"
};
static_assert(sizeof(bg_screen_8E2A50_C) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8E2A50_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");
