/**
 * Original filename: image.c
 */

#include "image.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "file.h"

extern s32 gnSizeWaveLast;

#if VERSION_USA
void imageMake(struct_imageLoad_arg0 **arg0, void **arg1, u32 arg2) {
    *arg0 = *arg1 = (void *)ALIGN4((uintptr_t)*arg1);
    *arg1 = (void *)((uintptr_t)*arg1 + sizeof(struct_imageLoad_arg0));

    (*arg0)->unk_2C = *arg1 = (void *)ALIGN4((uintptr_t)*arg1);
    *arg1 = (void *)((uintptr_t)*arg1 + arg2 * sizeof(struct_imageLoad_arg0_unk_2C *));

    (*arg0)->unk_24 = *arg1 = (void *)ALIGN4((uintptr_t)*arg1);
    *arg1 = (void *)((uintptr_t)*arg1 + arg2 * sizeof(s32));

    (*arg0)->unk_1C = *arg1 = (void *)ALIGN4((uintptr_t)*arg1);
    *arg1 = (void *)((uintptr_t)*arg1 + arg2 * sizeof(s32));

    (*arg0)->unk_20 = *arg1 = (void *)ALIGN4((uintptr_t)*arg1);
    *arg1 = (void *)((uintptr_t)*arg1 + arg2 * sizeof(s32));

    (*arg0)->unk_10 = 0;
    (*arg0)->unk_0C = 0;
    (*arg0)->unk_00 = 0;
    (*arg0)->unk_04 = 0;
    (*arg0)->unk_88 = 0x400;
    (*arg0)->unk_8C = 0x400;
    (*arg0)->unk_14 = 0xFF;
    (*arg0)->unk_90 = 0;
    (*arg0)->unk_92 = 0;
    (*arg0)->unk_08 = 0;
    (*arg0)->unk_28 = 0;
    (*arg0)->unk_94 = -1;
    (*arg0)->unk_98 = -1;
    (*arg0)->unk_30 = 0;
    (*arg0)->unk_34 = 0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_8001EDE0_usa);
#endif

#if VERSION_USA
#if 0
//? bitmapLoad(s32, File *, void **, s32);     /* extern */

s32 imageLoad(struct_imageLoad_arg0 **arg0, char *arg1, void **arg2) {
    File sp10;
    s32 sp20;
    u32 sp24;
    u8 sp28;
    u8 sp29;
    u8 sp2A;
    u8 sp2B;
    u32 sp2C;
    u32 sp30;
    struct_imageLoad_arg0 *temp_a1_4;
    s32 temp_lo;
    s32 temp_s0;
    s32 temp_t0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_a0;
    s32 var_s7;
    s32 var_t0;
    s8 *var_a1;
    u32 *temp_a1;
    u32 *temp_a1_2;
    u32 *temp_a1_3;
    u32 temp_a3;
    u32 temp_v1;
    u32 temp_v1_2;
    u32 temp_v1_3;
    u32 var_s1;
    void **temp_t1;
    void **var_a3;
    struct_imageLoad_arg0_unk_2C *temp_v0;
    struct_imageLoad_arg0_unk_2C *temp_v0_2;

    if (fileTest((File *) arg1)) {
        bcopy(arg1, &sp10, 0x10);
    } else {
        fileOpen(&sp10, arg1);
    }
    sp20 = 0;
    fileGet(&sp10, &sp20, 4);
    if (sp20 == 'BIF3') {
        var_s7 = 0;
    } else {
        var_s7 = 1;
        if (sp20 != '3FIB') {
            if (!fileTest((File *) arg1)) {
                var_a1 = arg1;
            } else {
                var_a1 = "<FILE>";
            }
            osSyncPrintf("imageLoad: Could not load IMAGE '%s'\n", var_a1);
            return 0;
        }
    }

    fileGet(&sp10, &sp24, 4);
    fileGet(&sp10, &sp28, 1);
    fileGet(&sp10, &sp29, 1);
    fileGet(&sp10, &sp2A, 1);
    fileGet(&sp10, &sp2B, 1);
    fileGet(&sp10, &sp2C, 4);
    if (var_s7 != 0) {
        sp24 = (sp24 >> 0x18) | ((sp24 >> 8) & 0xFF00) | ((sp24 << 8) & 0xFF0000) | (sp24 << 0x18);
        sp2C = (sp2C >> 0x18) | ((sp2C >> 8) & 0xFF00) | ((sp2C << 8) & 0xFF0000) | (sp2C << 0x18);
    }
    imageMake(arg0, arg2, sp2C);
    (*arg0)->unk_0C = sp24;
    (*arg0)->unk_18 = sp2C;
    (*arg0)->unk_94 = (s32) ((sp28 << 0x18) | (sp29 << 0x10) | (sp2A << 8) | sp2B);
    if (sp24 & 0x10) {
        fileGet(&sp10, &sp28, 1);
        fileGet(&sp10, &sp29, 1);
        fileGet(&sp10, &sp2A, 1);
        fileGet(&sp10, &sp2B, 1);
        (*arg0)->unk_98 = (s32) ((sp28 << 0x18) | (sp29 << 0x10) | (sp2A << 8) | sp2B);
    }
    if (sp24 & 8) {
        fileGet(&sp10, &sp30, 4);
        if (var_s7 != 0) {
            sp30 = (sp30 >> 0x18) | (((s32) sp30 >> 8) & 0xFF00) | ((sp30 << 8) & 0xFF0000) | (sp30 << 0x18);
        }
        fileSeek(&sp10, 1, (s32) sp30);
    }

    var_s1 = 0;
    while (var_s1 < sp2C) {
        temp_s0 = var_s1 * 4;
        fileGet(&sp10, (*arg0)->unk_1C + temp_s0, 4);
        fileGet(&sp10, (*arg0)->unk_20 + temp_s0, 4);
        fileGet(&sp10, (*arg0)->unk_24 + temp_s0, 4);
        if (var_s7 != 0) {
            temp_a1 = temp_s0 + (*arg0)->unk_1C;
            temp_v1 = *temp_a1;
            *temp_a1 = (temp_v1 >> 0x18) | (((s32) temp_v1 >> 8) & 0xFF00) | ((temp_v1 << 8) & 0xFF0000) | ((temp_v1 << 0x18) & 0xFF000000);
            temp_a1_2 = temp_s0 + (*arg0)->unk_20;
            temp_v1_2 = *temp_a1_2;
            *temp_a1_2 = (temp_v1_2 >> 0x18) | (((s32) temp_v1_2 >> 8) & 0xFF00) | ((temp_v1_2 << 8) & 0xFF0000) | ((temp_v1_2 << 0x18) & 0xFF000000);
            temp_a1_3 = temp_s0 + (*arg0)->unk_24;
            temp_v1_3 = *temp_a1_3;
            *temp_a1_3 = (temp_v1_3 >> 0x18) | (((s32) temp_v1_3 >> 8) & 0xFF00) | ((temp_v1_3 << 8) & 0xFF0000) | ((temp_v1_3 << 0x18) & 0xFF000000);
        }
        bitmapLoad((*arg0)->unk_2C + temp_s0, &sp10, arg2, -((sp24 & 0x200) != 0));
        var_s1 += 1;
    }

    var_a0 = 1;
    if (sp24 & 0x200) {
        temp_a1_4 = *arg0;
        temp_t1 = temp_a1_4->unk_2C;
        temp_v0 = *temp_t1;
        temp_a3 = temp_a1_4->unk_18;
        var_t0 = temp_v0->unk_04 * temp_v0->unk_10;

        var_a3 = temp_t1 + 4;
        while (var_a0 < (s32) temp_a3) {
            temp_v0_2 = *var_a3;
            temp_lo = temp_v0_2->unk_04 * temp_v0_2->unk_10;
            if (var_t0 < temp_lo) {
                var_t0 = temp_lo;
            }
            var_a0 += 1;
            var_a3 += 4;
        }

        temp_v0_3 = (s32) (*arg2 + 0xF) & ~0xF;
        *arg2 = (void *) temp_v0_3;
        temp_a1_4->unk_30 = temp_v0_3;
        temp_t0 = (var_t0 + 0xF) & ~0xF;
        temp_v0_4 = (s32) (*arg2 + temp_t0 + 0xF) & ~0xF;
        *arg2 = (void *) temp_v0_4;
        temp_a1_4->unk_34 = temp_v0_4;
        *arg2 += temp_t0;
    }

    if (!fileTest((File *) arg1)) {
        fileClose(&sp10);
        return -1;
    }
    bcopy(&sp10, arg1, 0x10);
    return -1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/image", imageLoad);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_8001FC08_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_8001FD0C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_8001FD94_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_8001FF70_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_80020044_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_800200B4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_80020208_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_80020304_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_800205AC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_8002063C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_800206DC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_80020754_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_800207FC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_800209BC_usa);
#endif

#if VERSION_USA
#if 0
s32 func_80021414_usa(s32 arg0, s32 arg1, s32 arg2, u16 *arg3) {
    s32 temp_t2;
    s32 temp_t3;
    s32 temp_v1;
    s32 var_a1;
    s32 var_a2;
    s32 var_t0;
    s32 var_t1;
    s32 var_v0;
    u16 *var_a3;
    u16 *var_t0_2;
    u16 *var_v1;
    u16 temp_a0;
    void *temp_t1;

    if (arg0 != 0) {
        if (arg0->unk_C & 0x24) {
            temp_t3 = arg0->unk_18;
            var_t1 = *arg0->unk_24;
            var_t0 = 0;
            if (temp_t3 > 0) {
                temp_t2 = arg0->unk_10;
                var_v0 = temp_t2 < 0;
loop_4:
                if ((var_v0 != 0) || (temp_t2 >= var_t1)) {
                    var_t0 += 1;
                    temp_v1 = var_t1;
                    var_t1 += *((var_t0 * 4) + arg0->unk_24);
                    var_v0 = temp_t2 < temp_v1;
                    if (var_t0 < temp_t3) {
                        goto loop_4;
                    }
                }
                if (var_t0 >= arg0->unk_18) {
                    goto block_8;
                }
            } else {
block_8:
                var_t0 = arg0->unk_18 - 1;
            }
        } else {
            var_t0 = arg0->unk_0;
        }
        *sp = var_t0;
        temp_t1 = *((sp0 * 4) + arg0->unk_2C);
        if (temp_t1->unk_3 != 0x54) {
            goto block_11;
        }
        var_a3 = &arg3[(arg2 * 0x140) + arg1];
        var_a2 = 0;
        if (temp_t1->unk_10 > 0) {
            do {
                var_t0_2 = var_a3;
                var_a1 = 0;
                var_v1 = temp_t1->unk_8 + (temp_t1->unk_4 * var_a2);
                if (temp_t1->unk_C > 0) {
                    do {
                        temp_a0 = *var_v1;
                        if (temp_a0 & 1) {
                            *var_t0_2 = temp_a0;
                        }
                        var_t0_2 += 2;
                        var_a1 += 1;
                        var_v1 += 2;
                    } while (var_a1 < temp_t1->unk_C);
                }
                var_a2 += 1;
                var_a3 += 0x280;
            } while (var_a2 < temp_t1->unk_10);
        }
        return -1;
    }
block_11:
    return 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_80021414_usa);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_8002156C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_80022184_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_80022268_usa);
#endif

#if VERSION_USA
void imageSetup(void) {
    gnSizeWaveLast = -1;
}
#endif

#if VERSION_USA
void func_800222E4_usa(void) {
}
#endif
