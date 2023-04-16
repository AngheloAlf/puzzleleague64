#ifndef REEND_H
#define REEND_H

#include "libultra.h"


#define UWORD(x) ((u32)(x))
#define SWORD(x) ((s32)(x))
#define REEND_UWORD(x) \
    ((UWORD(x) >> 0x18) | ((UWORD(x) >> 8) & 0xFF00) | ((UWORD(x) << 8) & 0xFF0000) | ((UWORD(x) << 0x18) & 0xFF000000))
#define REEND_SWORD(x) \
    ((UWORD(x) >> 0x18) | ((SWORD(x) >> 8) & 0xFF00) | ((UWORD(x) << 8) & 0xFF0000) | ((UWORD(x) << 0x18) & 0xFF000000))

#define USHORT(x) ((u16)(x))
#define REEND_USHORT(x) ((USHORT(x) >> 8) | ((USHORT(x) << 8) & ~0xFF))


#endif
