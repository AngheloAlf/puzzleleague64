#include "bg_screen_load.h"

#include "alignment.h"
#include "libc/assert.h"

u16 bg_screen_8A8050_main[] ALIGNED(8) = {
#include "assets/bg_screen/8A8050/bg_screen_8A8050_main.rgba16.inc"
};
static_assert(sizeof(bg_screen_8A8050_main) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8A8050_MAIN_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8A8050_A[] ALIGNED(8) = {
#include "assets/bg_screen/8A8050/bg_screen_8A8050_A.rgba16.inc"
};
static_assert(sizeof(bg_screen_8A8050_A) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8A8050_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8A8050_B[] ALIGNED(8) = {
#include "assets/bg_screen/8A8050/bg_screen_8A8050_B.rgba16.inc"
};
static_assert(sizeof(bg_screen_8A8050_B) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8A8050_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8A8050_C[] ALIGNED(8) = {
#include "assets/bg_screen/8A8050/bg_screen_8A8050_C.rgba16.inc"
};
static_assert(sizeof(bg_screen_8A8050_C) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8A8050_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");
