#ifndef BUFFERS_H
#define BUFFERS_H

#include "ultra64.h"
#include "attributes.h"
#include "macros_defines.h"

extern u8 gBufferHeap[];

extern u8 D_803B0500[];

extern u16 gFramebuffers[2][SCREEN_HEIGHT * SCREEN_WIDTH];


#define FRAMEBUFFERS_BACKWARD_SET(value) \
    do { \
        s32 i; \
        u32 *buff; \
        \
        buff = (u32 *)gFramebuffers[0]; \
        for (i = SCREEN_WIDTH * SCREEN_HEIGHT / sizeof(u16) - 1; i != -1; i--) { \
            *buff = value; \
            buff++; \
        } \
        buff = (u32 *)gFramebuffers[1]; \
        for (i = SCREEN_WIDTH * SCREEN_HEIGHT / sizeof(u16) - 1; i != -1; i--) { \
            *buff = value; \
            buff++; \
        } \
    } while (0)

#endif
