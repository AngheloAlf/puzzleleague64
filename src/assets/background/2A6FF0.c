#include "assets/background.h"

#include "alignment.h"
#include "libc/assert.h"

u16 background_2A6FF0[] ALIGNED(8) = {
#include "assets/background/background_2A6FF0.rgba16.inc"
};
static_assert(sizeof(background_2A6FF0) == BACKGROUND_WIDTH * BACKGROUND_HEIGHT * sizeof(u16),
              "Texture size doesn't match the expected dimensions");
