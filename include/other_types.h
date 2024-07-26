#ifndef OTHER_TYPES_H
#define OTHER_TYPES_H

#include "ultra64.h"

// Header for files that are well known, but don't have a proper header home yet

typedef u32 RomOffset;
typedef void* TexturePtr;

// For bool like values where the true value is negative instead of positive.
typedef enum nbool {
    ntrue = -1,
    nfalse
} nbool;

#endif
