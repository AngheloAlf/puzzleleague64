#ifndef _001F10_H
#define _001F10_H

#include "ultra64.h"

#include "other_types.h"
#include "segment_symbols.h"

void func_80001310_usa(RomOffset segmentRom, void * dstAddr, size_t segmentSize);

#define LOAD_DATA_SEGMENT(dst, segment, heap)                                        \
    osInvalDCache(SEGMENT_VRAM_START(segment), SEGMENT_VRAM_SIZE(segment));          \
    func_80001310_usa(SEGMENT_ROM_START(segment), (dst), SEGMENT_ROM_SIZE(segment)); \
    heap = (void *)((uintptr_t)heap + SEGMENT_ROM_SIZE(segment))

#endif
