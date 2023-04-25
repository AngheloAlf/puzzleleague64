#pragma once

/* C macros */
#define ARRAY_COUNT(arr) (signed long long)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (unsigned long long)(sizeof(arr) / sizeof(arr[0]))

/* Mathematical macros */
#define CLAMP(x, min, max) ((x) < (min) ? (min) : (x) > (max) ? (max) : (x))
#define CLAMP_MAX(x, max) ((x) > (max) ? (max) : (x))
#define CLAMP_MIN(x, min) ((x) < (min) ? (min) : (x))
#define MEDIAN3(a1, a2, a3) \
    ((a2 >= a1) ? ((a3 >= a2) ? a2 : ((a1 >= a3) ? a1 : a3)) : ((a2 >= a3) ? a2 : ((a3 >= a1) ? a1 : a3)))

/* Constants */
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
