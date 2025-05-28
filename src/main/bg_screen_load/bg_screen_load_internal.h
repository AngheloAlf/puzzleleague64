#include "bg_screen_load.h"

#include "attributes.h"
#include "main_functions.h"
#include "main_variables.h"

#include "segment_symbols.h"

#include "flic.h"

#define DEFINE_BGSCREENLOAD_FUNC(name, seg1, seg2) \
    void name (bool arg0, s32 arg1 UNUSED, s32 main_height, s32 top_height) { \
        void *heap = Pon_Image_Heap; \
        \
        if (arg0) { \
            osInvalDCache(SEGMENT_VRAM_START(seg1), SEGMENT_VRAM_SIZE(seg1)); \
            func_80001310_usa(SEGMENT_ROM_START(seg1), heap, SEGMENT_ROM_SIZE(seg1)); \
            Pon_Image_Heap += SEGMENT_ROM_SIZE(seg1); \
        } else { \
            osInvalDCache(SEGMENT_VRAM_START(seg2), SEGMENT_VRAM_SIZE(seg2)); \
            func_80001310_usa(SEGMENT_ROM_START(seg2), heap, SEGMENT_ROM_SIZE(seg2)); \
            Pon_Image_Heap += SEGMENT_ROM_SIZE(seg2); \
        } \
        \
        func_8004EC4C_usa(heap, arg0, main_height, top_height); \
    }
