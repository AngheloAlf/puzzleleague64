#include "assets/background.h"

#include "alignment.h"
#include "libc/assert.h"

u16 background_25E7F0[] ALIGNED(8) = {
#include "assets/background/background_25E7F0.rgba16.inc"
};
static_assert(sizeof(background_25E7F0) == BACKGROUND_WIDTH * BACKGROUND_HEIGHT * sizeof(u16),
              "Texture size doesn't match the expected dimensions");
