#ifndef MACROS_DEFINES_H
#define MACROS_DEFINES_H

#include "version.h"

#if defined(_MSC_VER)
#  define UNREACHABLE __assume(0)
#elif __IS_KMC__ || __IS_EGCS__
#  define UNREACHABLE
#elif defined(__GNUC__) || defined(__clang__)
#  define UNREACHABLE __builtin_unreachable()
#else
#  define UNREACHABLE
#endif

#define SCREEN_WIDTH  320
#define SCREEN_HEIGHT 240


#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))


#endif
