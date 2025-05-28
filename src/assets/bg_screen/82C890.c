#include "bg_screen_load.h"

#include "alignment.h"
#include "libc/assert.h"

u16 bg_screen_82C890_main[] ALIGNED(8) = {
#include "assets/bg_screen/82C890/bg_screen_82C890_main.rgba16.inc"
};
static_assert(sizeof(bg_screen_82C890_main) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_82C890_MAIN_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_82C890_A[] ALIGNED(8) = {
#include "assets/bg_screen/82C890/bg_screen_82C890_A.rgba16.inc"
};
static_assert(sizeof(bg_screen_82C890_A) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_82C890_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_82C890_B[] ALIGNED(8) = {
#include "assets/bg_screen/82C890/bg_screen_82C890_B.rgba16.inc"
};
static_assert(sizeof(bg_screen_82C890_B) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_82C890_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");

u16 bg_screen_82C890_C[] ALIGNED(8) = {
#include "assets/bg_screen/82C890/bg_screen_82C890_C.rgba16.inc"
};
static_assert(sizeof(bg_screen_82C890_C) == BGSCREEN_TEX_WIDTH * BGSCREEN_TEX_82C890_TOP_HEIGHT * sizeof(u16),
              "Expected texture size doesn't match the expected dimensions");
