#include "bg_screen_load.h"

#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "segment_symbols.h"

#include "flic.h"

extern u32 D_1077C60[];
extern u32 D_108CF00[];
extern u32 D_109E540[];

void func_80073B30_usa(s32 arg0, s32 arg1 UNUSED, s32 arg2, s32 arg3) {
    void *heap = Pon_Image_Heap;

    if (arg0 != 0) {
        // osInvalDCache(SEGMENT_VRAM_START(segment_bg_screen_62AB10), SEGMENT_VRAM_SIZE(segment_bg_screen_62AB10));
        osInvalDCache(&D_1077C60, (u32) D_108CF00 - (u32) D_1077C60);
        func_80001310_usa(SEGMENT_ROM_START(segment_bg_screen_62AB10), heap, SEGMENT_ROM_SIZE(segment_bg_screen_62AB10));
        Pon_Image_Heap += SEGMENT_ROM_SIZE(segment_bg_screen_62AB10);
    } else {
        // osInvalDCache(SEGMENT_VRAM_START(segment_bg_screen_7D39D0), SEGMENT_VRAM_SIZE(segment_bg_screen_7D39D0));
        osInvalDCache(&D_108CF00, (u32) D_109E540 - (u32) D_108CF00);
        func_80001310_usa(SEGMENT_ROM_START(segment_bg_screen_7D39D0), heap, SEGMENT_ROM_SIZE(segment_bg_screen_7D39D0));
        Pon_Image_Heap += SEGMENT_ROM_SIZE(segment_bg_screen_7D39D0);
    }

    func_8004EC4C_usa(heap, arg0, arg2, arg3);
}
