/**
 * Original filename: gfx.c
 */

#include "gfx.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "segment_symbols.h"
#include "buffers.h"

#if VERSION_USA
extern UNK_PTR D_800B3AB0_usa;

void InitGFX(void) {
    D_800B3AB0_usa = gBufferHeap;
    func_80001310_usa(SEGMENT_ROM_START(segment_0CA4A0), D_800B3AB0_usa, SEGMENT_ROM_SIZE(segment_0CA4A0));
    gInfo[0].unk_19020 = 2;
    gInfo[0].unk_19040 = gFramebuffers[0];
    gInfo[1].unk_19020 = 2;
    gInfo[1].unk_19040 = gFramebuffers[1];
    osViSetSpecialFeatures(OS_VI_DITHER_FILTER_ON | OS_VI_DIVOT_ON | OS_VI_GAMMA_DITHER_OFF | OS_VI_GAMMA_OFF);
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/gfx", CreateMenuGfxTask);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/gfx", func_800016D8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/gfx", func_8000177C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/gfx", func_8000182C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/gfx", func_800019C0_usa);
#endif
