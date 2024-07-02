#ifndef BUFFERS_H
#define BUFFERS_H

#include "ultra64.h"
#include "attributes.h"
#include "macros_defines.h"

extern u8 gBufferHeap[];

extern u8 D_803B0500[];

extern u16 gFramebuffers[2][SCREEN_HEIGHT * SCREEN_WIDTH];


#define FRAMEBUFFERS_BACKWARD_SET(i, buff, value) \
    do { \
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

#define FRAMEBUFFERS_COPY(i, dst, src) \
    do { \
        i = SCREEN_WIDTH * SCREEN_HEIGHT / sizeof(u16) / 8 - 1; \
        while (i != -1) { \
            *dst++ = *src++; \
            *dst++ = *src++; \
            *dst++ = *src++; \
            *dst++ = *src++; \
            *dst++ = *src++; \
            *dst++ = *src++; \
            *dst++ = *src++; \
            *dst++ = *src++; \
            i--; \
        } \
    } while (0)

#endif
