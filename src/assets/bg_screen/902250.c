#include "bg_screen_load.h"

#include "alignment.h"
#include "libc/assert.h"

u16 bg_screen_902250_main[] ALIGNED(8) = {
#include "assets/bg_screen/902250/bg_screen_902250_main.rgba16.inc"
};
static_assert(sizeof(bg_screen_902250_main) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_902250_MAIN_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_902250_A[] ALIGNED(8) = {
#include "assets/bg_screen/902250/bg_screen_902250_A.rgba16.inc"
};
static_assert(sizeof(bg_screen_902250_A) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_902250_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_902250_B[] ALIGNED(8) = {
#include "assets/bg_screen/902250/bg_screen_902250_B.rgba16.inc"
};
static_assert(sizeof(bg_screen_902250_B) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_902250_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_902250_C[] ALIGNED(8) = {
#include "assets/bg_screen/902250/bg_screen_902250_C.rgba16.inc"
};
static_assert(sizeof(bg_screen_902250_C) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_902250_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");
