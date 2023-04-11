#ifndef SEGMENT_SYMBOLS_H
#define SEGMENT_SYMBOLS_H

#include "libultra.h"
#include "libc/stdint.h"

#define DECLARE_VRAM_SEGMENT(name) \
    extern u32 name ## _VRAM[]; \
    extern u32 name ## _VRAM_END[]

#define DECLARE_ROM_SEGMENT(name) \
    extern u32 name ## _ROM_START[]; \
    extern u32 name ## _ROM_END[]

#define DECLARE_DATA_SEGMENT(name)   \
    extern u32 name ## _DATA_START[]; \
    extern u32 name ## _DATA_END[]; \
    extern u32 name ## _DATA_SIZE[]

#define DECLARE_BSS_SEGMENT(name)   \
    extern u32 name ## _BSS_START[]; \
    extern u32 name ## _BSS_END[]

#define DECLARE_SEGMENT(name) \
    DECLARE_VRAM_SEGMENT(name); \
    DECLARE_ROM_SEGMENT(name); \
    DECLARE_DATA_SEGMENT(name); \
    DECLARE_BSS_SEGMENT(name)

#define SEGMENT_VRAM_START(segment) (segment ## _VRAM)
#define SEGMENT_VRAM_END(segment)   (segment ## _VRAM_END)
#define SEGMENT_VRAM_SIZE(segment)  ((uintptr_t)SEGMENT_VRAM_END(segment) - (uintptr_t)SEGMENT_VRAM_START(segment))

#define SEGMENT_ROM_START(segment) ((RomOffset)segment ## _ROM_START)
#define SEGMENT_ROM_END(segment)   ((RomOffset)segment ## _ROM_END)
#define SEGMENT_ROM_SIZE(segment)  (SEGMENT_ROM_END(segment) - SEGMENT_ROM_START(segment))

#define SEGMENT_DATA_SIZE_CONST(segment) ((RomOffset)segment ## _DATA_SIZE)

#define SEGMENT_BSS_START(segment) (segment ## _BSS_START)
#define SEGMENT_BSS_END(segment)   (segment ## _BSS_END)
#define SEGMENT_BSS_SIZE(segment)  ((uintptr_t)SEGMENT_BSS_END(segment) - (uintptr_t)SEGMENT_BSS_START(segment))

DECLARE_SEGMENT(header);

DECLARE_SEGMENT(ipl3);

DECLARE_SEGMENT(entry);

DECLARE_SEGMENT(main);

DECLARE_SEGMENT(buffer1);
DECLARE_SEGMENT(buffer2);
DECLARE_SEGMENT(framebuffer);

DECLARE_SEGMENT(segment_0CA4A0);

// DECLARE_SEGMENT(segment_0FB480);

DECLARE_SEGMENT(bin_file);

// DECLARE_SEGMENT(segment_17C2A80);


#endif
