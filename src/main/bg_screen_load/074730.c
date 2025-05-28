#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "flic.h"

#if VERSION_USA
// ? func_8004EC4C_usa(void *, s32, ?, ?);             /* extern */
extern u32 D_1077C60[];
extern u32 D_108CF00[];
extern u32 D_109E540[];
extern u32 D_62AB10[];
extern u32 D_63FDB0[];
extern u32 D_7D39D0[];
extern u32 D_7E5010[];

void func_80073B30_usa(s32 arg0, s32 arg1 UNUSED, s32 arg2, s32 arg3) {
    void *heap = Pon_Image_Heap;

    if (arg0 != 0) {
        osInvalDCache(&D_1077C60, (u32) D_108CF00 - (u32) D_1077C60);
        func_80001310_usa((u32) D_62AB10, heap, (u32) D_63FDB0 - (u32) D_62AB10);
        Pon_Image_Heap += (u32) D_63FDB0 - (u32) D_62AB10;
    } else {
        osInvalDCache(&D_108CF00, (u32) D_109E540 - (u32) D_108CF00);
        func_80001310_usa((u32) D_7D39D0, heap, (u32) D_7E5010 - (u32) D_7D39D0);
        Pon_Image_Heap += (u32) D_7E5010 - (u32) D_7D39D0;
    }

    func_8004EC4C_usa(heap, arg0, arg2, arg3);
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bg_screen_load/074730", func_80073E60_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bg_screen_load/074730", func_80072590_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bg_screen_load/074730", func_80072740_ger);
#endif
