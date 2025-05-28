#include "bg_screen_load.h"

#include "alignment.h"
#include "libc/assert.h"

u16 bg_screen_81A450_main[] ALIGNED(8) = {
#include "assets/bg_screen/81A450/bg_screen_81A450_main.rgba16.inc"
};
static_assert(sizeof(bg_screen_81A450_main) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_81A450_MAIN_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_81A450_A[] ALIGNED(8) = {
#include "assets/bg_screen/81A450/bg_screen_81A450_A.rgba16.inc"
};
static_assert(sizeof(bg_screen_81A450_A) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_81A450_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_81A450_B[] ALIGNED(8) = {
#include "assets/bg_screen/81A450/bg_screen_81A450_B.rgba16.inc"
};
static_assert(sizeof(bg_screen_81A450_B) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_81A450_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_81A450_C[] ALIGNED(8) = {
#include "assets/bg_screen/81A450/bg_screen_81A450_C.rgba16.inc"
};
static_assert(sizeof(bg_screen_81A450_C) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_81A450_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");
