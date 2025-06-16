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


#define CHECK_FLAG_ALL(flags, mask) (((flags) & (mask)) == (mask))

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))

#define STATIC_INLINE static inline
#ifdef PERMUTER
#define INLINE static inline
#else
#define INLINE inline
#endif

#define DATA_INLINE_CONST const

// Allows having m2c to use enum variants whenever possible.
#ifdef M2CTX
#define ENUM_TYPE(e, t) e
#else
#define ENUM_TYPE(e, t) t
#endif

// A way to make easier finding double literals.
#define DOUBLE_LITERAL(x) (x)

#define saved_reg_s0 0
#define saved_reg_s1 0
#define saved_reg_s2 0
#define saved_reg_s3 0
#define saved_reg_s4 0
#define saved_reg_s5 0
#define saved_reg_s6 0
#define saved_reg_s7 0
#define saved_reg_fp 0
#define bitwise
#define saved_reg_f20 0.0f
#define saved_reg_f22 0.0f

#define WAIT_FINISH_FRAME()                     \
    do {} while (osViGetCurrentLine() != 0);    \
    do {} while (osViGetCurrentLine() == 0)

#if REGION_NTSC
#define ADJUST_FRAMERATE(x) (x)
#else
#define ADJUST_FRAMERATE(x) ((x) * 5 / 6)
#endif

#endif
