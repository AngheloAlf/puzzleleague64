#include "assets/background.h"

#include "alignment.h"
#include "libc/assert.h"

u16 background_3ED3F0[] ALIGNED(8) = {
#include "assets/background/background_3ED3F0.rgba16.inc"
};
static_assert(sizeof(background_3ED3F0) == BACKGROUND_WIDTH * BACKGROUND_HEIGHT * sizeof(u16),
              "Texture size doesn't match the expected dimensions");
