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
#if 0
? func_8000182C_usa(struct_gInfo *);                /* extern */
? DrawTitle(s32);                           /* extern */
? InitTitle(s32);                           /* extern */
? func_8001AD2C_usa(s8 *);                          /* extern */
? func_8001BB54_usa(s32);                           /* extern */
s32 func_80024C2C_usa();                            /* extern */
? func_8002BD30_usa(s8 *);                          /* extern */
? func_8002BE98_usa(s32);                           /* extern */
? func_8003077C_usa(s8 *);                          /* extern */
? func_80030A7C_usa(s32);                           /* extern */
? func_80030F20_usa(s32);                           /* extern */
? func_80031DDC_usa(s8 *);                          /* extern */
? func_80033648_usa(s32);                           /* extern */
? func_8003434C_usa(s8 *);                          /* extern */
? func_80054804_usa(struct_gInfo *);                /* extern */
? func_8006F4CC_usa(s8 *);                          /* extern */
? DrawMT(s8 *);                          /* extern */
? func_80087834_usa(s32);                           /* extern */
? InitTutorial(s32);                           /* extern */
? func_80089E6C_usa(s32);                           /* extern */
extern struct_gInfo **B_801C6E54_usa;
extern s8 *B_8021BEAC_usa;
extern ? D_1000010;
extern void *D_800B3AB0_usa;

s32 CreateMenuGfxTask(struct_gInfo *arg0) {
    s32 var_v0;
    s8 *temp_s1;
    s8 *temp_s2;
    s8 *temp_v1;
    s8 *temp_v1_2;

    B_8021BEAC_usa = &arg0->unk_00000[0x70];
    B_801C6E54_usa = &arg0;
    arg0->unk_68 = 0xBC000006;
    arg0->unk_6C = 0;
    B_8021BEAC_usa = &arg0->unk_00000[0x78];
    arg0->unk_70 = 0xBC000406;
    temp_s1 = B_8021BEAC_usa;
    temp_s2 = &arg0->unk_00000[0x68];
    arg0->unk_74 = osVirtualToPhysical(D_800B3AB0_usa);
    B_8021BEAC_usa = temp_s1 + 8;
    temp_s1->unk_0 = 0xBC000806;
    temp_s1->unk_4 = osVirtualToPhysical(temp_s2);
    if (gReset != 0) {
        temp_v1 = B_8021BEAC_usa;
        gReset = 0;
        B_8021BEAC_usa = temp_v1 + 8;
        temp_v1->unk_0 = 0x06000000;
        temp_v1->unk_4 = &D_1000010;
        if (gMain == 0x1F4) {
            InitTitle(gMain);
        } else if ((((gMain == 0x258) | (gMain == 0x28A)) != 0) || (gMain == 0x2BC)) {
            func_8001BB54_usa(gMain);
        } else {
            switch (gMain) {                        /* irregular */
                case 0x36D:
                    func_80030F20_usa(gMain);
                    break;
                case 0x378:
                    func_80030A7C_usa(gMain);
                    break;
                case 0x383:
                    func_8002BE98_usa(gMain);
                    break;
                case 0x341:
                    func_80087834_usa(gMain);
                    break;
                case 0x34C:
                    InitTutorial(gMain);
                    break;
                case 0x357:
                    func_80033648_usa(gMain);
                    break;
                default:
                    func_80089E6C_usa(gMain);
                    break;
            }
        }
    }
    func_80054804_usa(arg0);
    if (gMain == 0x1F4) {
        DrawTitle(gMain);
    } else if ((((gMain == 0x258) | (gMain == 0x28A)) != 0) || (gMain == 0x2BC)) {
        func_8001AD2C_usa(temp_s2);
    } else {
        switch (gMain) {                            /* switch 1; irregular */
            case 0x36D:                             /* switch 1 */
                func_80031DDC_usa(temp_s2);
                break;
            case 0x378:                             /* switch 1 */
                func_8003077C_usa(temp_s2);
                break;
            case 0x383:                             /* switch 1 */
                func_8002BD30_usa(temp_s2);
                break;
            default:                                /* switch 1 */
                if (((gMain == 0x341) | (gMain == 0x34C)) != 0) {
                    DrawMT(temp_s2);
                } else if (gMain == 0x357) {
                    func_8003434C_usa(temp_s2);
                } else {
                    func_8006F4CC_usa(temp_s2);
                }
                break;
        }
    }
    temp_v1_2 = B_8021BEAC_usa;
    B_8021BEAC_usa = temp_v1_2 + 8;
    temp_v1_2->unk_0 = 0xE9000000;
    B_8021BEAC_usa = temp_v1_2 + 0x10;
    temp_v1_2->unk_4 = 0;
    temp_v1_2->unk_8 = 0xB8000000;
    temp_v1_2->unk_C = 0;
    osWritebackDCacheAll();
    var_v0 = 0;
    if (func_80024C2C_usa() == 0) {
        func_8000182C_usa(arg0);
        var_v0 = -1;
    }
    return var_v0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/gfx", CreateMenuGfxTask);
#endif
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
