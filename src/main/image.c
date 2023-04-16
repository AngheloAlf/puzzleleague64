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
#include "reend.h"

extern s32 gnSizeWaveLast;

#if VERSION_USA
void imageMake(struct_imageLoad_arg0 **arg0, void **arg1, u32 arg2) {
    *arg0 = *arg1 = (void *)ALIGN4((uintptr_t)*arg1);
    *arg1 = (void *)((uintptr_t)*arg1 + sizeof(struct_imageLoad_arg0));

    (*arg0)->unk_2C = *arg1 = (void *)ALIGN4((uintptr_t)*arg1);
    *arg1 = (void *)((uintptr_t)*arg1 + arg2 * sizeof(struct_bitmapLoad_arg0 *));

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
    (*arg0)->unk_30 = NULL;
    (*arg0)->unk_34 = NULL;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_8001EDE0_usa);
#endif

#if VERSION_USA
s32 imageLoad(struct_imageLoad_arg0 **arg0, char *filename, void **arg2) {
    File file;
    u32 magic;
    u32 sp24;
    u8 sp28;
    u8 sp29;
    u8 sp2A;
    u8 sp2B;
    u32 sp2C;
    s32 sp30;
    s32 needsReend;
    s32 i;

    if (fileTest((void *)filename)) {
        bcopy(filename, &file, sizeof(File));
    } else {
        fileOpen(&file, filename);
    }

    magic = 0;
    fileGet(&file, &magic, sizeof(u32));
    if (magic == 'BIF3') {
        needsReend = false;
    } else {
        needsReend = true;
        if (magic != '3FIB') {
            char *auxName;

            if (!fileTest((void *)filename)) {
                auxName = filename;
            } else {
                auxName = "<FILE>";
            }
            osSyncPrintf("imageLoad: Could not load IMAGE '%s'\n", auxName);
            return 0;
        }
    }

    fileGet(&file, &sp24, sizeof(u32));
    fileGet(&file, &sp28, sizeof(u8));
    fileGet(&file, &sp29, sizeof(u8));
    fileGet(&file, &sp2A, sizeof(u8));
    fileGet(&file, &sp2B, sizeof(u8));
    fileGet(&file, &sp2C, sizeof(u32));

    if (needsReend) {
        sp24 = REEND_UWORD(sp24);
        sp2C = REEND_UWORD(sp2C);
    }

    imageMake(arg0, arg2, sp2C);
    (*arg0)->unk_0C = sp24;
    (*arg0)->unk_18 = sp2C;
    (*arg0)->unk_94 = ((sp28 << 0x18) | (sp29 << 0x10) | (sp2A << 8) | sp2B);
    if (sp24 & 0x10) {
        fileGet(&file, &sp28, sizeof(u8));
        fileGet(&file, &sp29, sizeof(u8));
        fileGet(&file, &sp2A, sizeof(u8));
        fileGet(&file, &sp2B, sizeof(u8));
        (*arg0)->unk_98 = ((sp28 << 0x18) | (sp29 << 0x10) | (sp2A << 8) | sp2B);
    }

    if (sp24 & 8) {
        fileGet(&file, &sp30, 4);
        if (needsReend) {
            sp30 = REEND_SWORD(sp30);
        }
        fileSeek(&file, FILE_SEEK_CUR, sp30);
    }

    for (i = 0; i < sp2C; i++) {
        fileGet(&file, &(*arg0)->unk_1C[i], sizeof(s32));
        fileGet(&file, &(*arg0)->unk_20[i], sizeof(s32));
        fileGet(&file, &(*arg0)->unk_24[i], sizeof(s32));

        if (needsReend) {
            (*arg0)->unk_1C[i] = REEND_SWORD((*arg0)->unk_1C[i]);
            (*arg0)->unk_20[i] = REEND_SWORD((*arg0)->unk_20[i]);
            (*arg0)->unk_24[i] = REEND_SWORD((*arg0)->unk_24[i]);
        }

        bitmapLoad(&(*arg0)->unk_2C[i], &file, arg2, (sp24 & 0x200) ? -1 : 0);
    }

    if (sp24 & 0x200) {
        struct_imageLoad_arg0 *temp_a1_4 = *arg0;
        struct_bitmapLoad_arg0 *temp_v0 = temp_a1_4->unk_2C[0];
        s32 var_t0 = temp_v0->unk_04 * temp_v0->unk_10;
        s32 j;

        for (j = 1; j < temp_a1_4->unk_18; j++) {
            temp_v0 = temp_a1_4->unk_2C[j];
            var_t0 = MAX(var_t0, temp_v0->unk_04 * temp_v0->unk_10);
        }

        temp_a1_4->unk_30 = *arg2 = (void *)ALIGN16((uintptr_t)*arg2);

        var_t0 = ALIGN16(var_t0);

        temp_a1_4->unk_34 = *arg2 = (void *)ALIGN16((uintptr_t)*arg2 + var_t0);

        *arg2 = (void *)((uintptr_t)*arg2 + var_t0);
    }

    if (!fileTest((void *)filename)) {
        fileClose(&file);
        return -1;
    } else {
        bcopy(&file, filename, sizeof(File));
        return -1;
    }
}
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
