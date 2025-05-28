#include "bg_screen_load.h"

#include "alignment.h"
#include "libc/assert.h"

u16 bg_screen_8088D0_main[] ALIGNED(8) = {
#include "assets/bg_screen/8088D0/bg_screen_8088D0_main.rgba16.inc"
};
static_assert(sizeof(bg_screen_8088D0_main) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8088D0_MAIN_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8088D0_A[] ALIGNED(8) = {
#include "assets/bg_screen/8088D0/bg_screen_8088D0_A.rgba16.inc"
};
static_assert(sizeof(bg_screen_8088D0_A) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8088D0_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8088D0_B[] ALIGNED(8) = {
#include "assets/bg_screen/8088D0/bg_screen_8088D0_B.rgba16.inc"
};
static_assert(sizeof(bg_screen_8088D0_B) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8088D0_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_8088D0_C[] ALIGNED(8) = {
#include "assets/bg_screen/8088D0/bg_screen_8088D0_C.rgba16.inc"
};
static_assert(sizeof(bg_screen_8088D0_C) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_8088D0_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");
