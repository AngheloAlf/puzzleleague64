#include "bg_screen_load.h"

#include "alignment.h"
#include "libc/assert.h"

u16 bg_screen_865D90_main[] ALIGNED(8) = {
#include "assets/bg_screen/865D90/bg_screen_865D90_main.rgba16.inc"
};
static_assert(sizeof(bg_screen_865D90_main) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_865D90_MAIN_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_865D90_A[] ALIGNED(8) = {
#include "assets/bg_screen/865D90/bg_screen_865D90_A.rgba16.inc"
};
static_assert(sizeof(bg_screen_865D90_A) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_865D90_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_865D90_B[] ALIGNED(8) = {
#include "assets/bg_screen/865D90/bg_screen_865D90_B.rgba16.inc"
};
static_assert(sizeof(bg_screen_865D90_B) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_865D90_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_865D90_C[] ALIGNED(8) = {
#include "assets/bg_screen/865D90/bg_screen_865D90_C.rgba16.inc"
};
static_assert(sizeof(bg_screen_865D90_C) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_865D90_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");
