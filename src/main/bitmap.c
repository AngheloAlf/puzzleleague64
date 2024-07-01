/**
 * Original filename: bitmap.c
 */

#include "bitmap.h"
#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "file.h"
#include "reend.h"

extern s32 gpBitmapLast;

#if VERSION_USA
#if 0
s32 bitmapLoadRLE(struct_bitmapLoad_arg0 *arg0, File *arg1, void *arg2) {
    u8 sp10;
    u8 sp11;
    s32 temp_lo;
    s32 temp_s2;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    u8* temp_s3;
    u8 *temp_v1;
    u8 *var_v1;
    u8 temp_v0_2;
    u8 temp_v0_3;

    temp_s3 = arg0->unk_08;
    temp_lo = arg0->unk_04 * arg0->unk_10;
    if (!(((arg1->fileSize - arg1->inFileOffset) + 0xF) & ~0xF)) {
        return 0;
    }

    var_s0 = 0;
    while (var_s0 < temp_lo) {
        fileGet(arg1, &sp10, 1);
        if (!(sp10 & 0x80)) {
            if (sp10 & 0x40) {
                temp_v0 = ((sp10 >> 3) & 7) + 2;
                temp_s2 = (sp10 & 7) + 2;
                fileGet(arg1, temp_s3 + var_s0, temp_v0);
                var_a3 = 1;
                if (temp_s2 > 1) {
loop_7:
                    var_a2 = var_a3 * temp_v0;
                    var_a1 = 0;
                    if (temp_v0 != 0) {
                        var_a0 = var_a2 + var_s0;
                        var_v0_2 = var_s0;
loop_9:
                        var_a1 += 1;
                        temp_v1 = temp_s3 + var_a0;
                        var_a0 += 1;
                        *temp_v1 = *(temp_s3 + var_v0_2);
                        var_a2 += 1;
                        if (var_a0 < temp_lo) {
                            var_v0_2 = var_s0 + var_a1;
                            if (var_a1 >= temp_v0) {
                                goto block_11;
                            }
                            goto loop_9;
                        }
                    } else {
block_11:
                        var_a3 += 1;
                        if (((var_s0 + var_a2) < temp_lo) && (var_a3 < temp_s2)) {
                            goto loop_7;
                        }
                    }
                }
                var_s0 += temp_v0 * temp_s2;
            } else {
                fileGet(arg1, &sp11, 1);
                sp10 = (sp10 & 0x7F) + 1;
                var_v1 = var_s0 + temp_s3;
                while ((sp10 & 0xFF) != 0xFF) {
                    *var_v1 = sp11;
                    var_s0 += 1;
                    sp10--;
                    var_v1 += 1;
                }
            }
        } else {
            fileGet(arg1, temp_s3 + var_s0, sp10 + 1);
            var_s0 += 1 + sp10;
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", bitmapLoadRLE);
#endif
#endif

#if VERSION_USA
#ifdef NON_MATCHING
s32 bitmapLoad(struct_bitmapLoad_arg0 **arg0, File *arg1, void **arg2, s32 arg3) {
    s32 new_var;
    File sp10;
    s32 sp20;
    u32 sp24;
    u32 sp28;
    u32 sp2C;
    u32 sp30;
    s32 sp34;
    s32 sp38;
    s32 sp3C;
    s32 sp40;
    RomOffset sp44;
    s32 var_a2;
    s32 var_s3;
    u32 *var_t1;
    u16 *temp_a0_3;
    u32 *temp_a1;
    u32 var_a0;
    s32 a3;
    u32 var_a1;
    u8 var_a3;
    u32 var_s0;
    u32 var_t0;
    u8 var_v1;
    unsigned char new_var2;
    int new_var3;
    s32 new_var4;
    s32 new_var5;

    if (fileTest(arg1) != false) {
        bcopy(arg1, &sp10, sizeof(File));
    } else {
        fileOpen(&sp10, (char *)arg1);
    }

    fileGet(&sp10, &sp20, 4);
    if (sp20 == 'BFF2') {
        var_s3 = 0;
    } else {

        if (sp20 != '2FFB') {
            return 0;
        }
        var_s3 = 1;
    }

    gpBitmapLast = 0;
    fileGet(&sp10, &sp24, 4);
    fileGet(&sp10, &sp28, 4);
    fileGet(&sp10, &sp2C, 4);
    fileGet(&sp10, &sp30, 4);
    if (var_s3 != 0) {
        sp24 = REEND_UWORD(sp24);
        sp28 = REEND_UWORD(sp28);
        sp2C = REEND_UWORD(sp2C);
        sp30 = REEND_UWORD(sp30);
    }

    if (sp24 & 0x200000) {
        var_s0 = sp28 >> 0x10;
        sp28 &= 0xFFFF;
    }

    if (sp24 & 0x200) {
        fileGet(&sp10, &sp34, 4);
        if (var_s3 != 0) {
            sp34 = REEND_SWORD(sp34);
        }
        fileSeek(&sp10, FILE_SEEK_CUR, sp34);
    }

    if (sp24 & 0x400000) {
        fileGet(&sp10, &sp38, 4);
        fileGet(&sp10, &sp3C, 4);
        if (var_s3 != 0) {
            sp38 = REEND_SWORD(sp38);
            sp3C = REEND_SWORD(sp3C);
        }
    } else {
        sp3C = 0;
        sp38 = 0;
    }

    if ((sp24 & 0xF0) == 0x30) {
        fileGet(&sp10, &sp40, 4);
        if (var_s3 != 0) {
            sp40 = REEND_SWORD(sp40);
        }
    } else {
        sp40 = 0;
    }

    if (!(sp24 & 0x400000)) {
        var_a0 = sp30 * sp2C;
    } else {
        var_a0 = sp3C;
    }
    a3 = var_a0;

    new_var4 = sp40;
    new_var5 = sp38;
    *arg0 = *arg2 = (void *)(((uintptr_t)*arg2 + 3) & ~3);
    *arg2 = (void *)((uintptr_t)*arg2 + 0x24);

    if (new_var4 > 0) {
        new_var3 = new_var4 * 2;
        (*arg0)->unk_18 = *arg2 = (void *)(((uintptr_t)*arg2 + 7) & ~7);

        *arg2 = (void *)((uintptr_t)*arg2 + new_var3);
    } else {
        (*arg0)->unk_18 = 0U;
    }

    if (new_var5 > 0) {
        //(*arg0)->unk_1C = new_var5;
        new_var = new_var5;
        (*arg0)->unk_1C = new_var;

        (*arg0)->unk_20 = *arg2 = (void *)(((uintptr_t)*arg2 + 3) & ~3);
        //*arg2 = (uintptr_t)*arg2 + new_var5 * 4;
        *arg2 = (void *)((uintptr_t)(*arg2) + (new_var * 4));
    } else {
        (*arg0)->unk_1C = 0U;
        (*arg0)->unk_20 = 0U;
    }

    if (arg3 == 0) {
        (*arg0)->unk_08 = *arg2 = (void *)(((uintptr_t)*arg2 + 7) & ~7);

        *arg2 = (void *)((uintptr_t)*arg2 + a3);
    } else {
        (*arg0)->unk_08 = NULL;
    }

    (*arg0)->unk_00 = sp24;
    (*arg0)->unk_0C = sp28;
    (*arg0)->unk_10 = sp2C;
    (*arg0)->unk_04 = sp30;
    if (sp24 & 0x200000) {
        (*arg0)->unk_14 = var_s0;
    } else {
        (*arg0)->unk_14 = sp28;
    }

    if (sp40 > 0) {
        var_t1 = (void *)(((uintptr_t)*arg2 + 3) & ~3);
        fileGet(&sp10, var_t1, sp40 * 4);

        for (var_a2 = 0; var_a2 < sp40; var_a2++) {
            var_v1 = var_t1[var_a2] >> 0x18;
            var_a3 = var_t1[var_a2] >> 0x10;
            var_t0 = var_t1[var_a2] >> 8;

            if (sp24 & 0x400) {
                var_a1 = 0xFF;
                if (var_a2 == ((sp24 >> 0xC) & 0xFF)) {
                    var_a1 = 0;
                    var_t0 = 0;
                    var_a3 = 0;
                    var_v1 = 0;
                }
            } else {
                var_a1 = 0xFF;
            }

            //(*arg0)->unk_18[var_a2] =
            //    (((var_v1 >> 3) << 0xB) | ((var_a3 << 3) & 0x7C0) | ((var_t0 >> 2) & 0x3E)) | (var_a1 >> 7);
            new_var2 = (var_a1 >> 7);
            (*arg0)->unk_18[var_a2] =
                ((((var_v1 >> 3) << 0xB) | ((var_a3 << 3) & 0x7C0)) | ((var_t0 >> 2) & 0x3E)) | new_var2;
        }
    }

    if (sp24 & 0x400000) {
        fileGet(&sp10, (*arg0)->unk_20, sp38 * 4);
        fileGet(&sp10, (*arg0)->unk_08, sp3C);
    } else if (sp24 & 0x800) {
        bitmapLoadRLE(*arg0, &sp10, *arg2);
        (*arg0)->unk_00 &= ~0x800;
    } else if (arg3 != 0) {
        fileGetAddress(&sp10, &sp44);
        fileSeek(&sp10, FILE_SEEK_CUR, sp30 * sp2C);

        (*arg0)->unk_00 |= 0x100000;
        (*arg0)->unk_08 = (void *)sp44;
    } else {
        fileGet(&sp10, (*arg0)->unk_08, sp30 * sp2C);
    }

    if (fileTest(arg1) != false) {
        bcopy(&sp10, arg1, sizeof(File));
    } else {
        fileClose(&sp10);
    }

    if (var_s3 != 0) {
        if ((sp24 & 0xF) == 4) {
            u32 temp_lo;
            temp_lo = (sp30 / sizeof(u16)) * sp2C;

            for (var_a2 = 0; var_a2 < temp_lo; var_a2++) {
                temp_a0_3 = (void *)(var_a2 * sizeof(u16) + (uintptr_t)(*arg0)->unk_08);
                *temp_a0_3 = REEND_USHORT(*temp_a0_3);
            }
        } else if ((sp24 & 0xF) == 5) {
            u32 temp_lo;
            temp_lo = (sp30 / sizeof(u32)) * sp2C;

            for (var_a2 = 0; var_a2 < temp_lo; var_a2++) {
                temp_a1 = (void *)(var_a2 * sizeof(u32) + (uintptr_t)(*arg0)->unk_08);
                *temp_a1 = REEND_UWORD(*temp_a1);
            }
        }
    }
    return -1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", bitmapLoad);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", func_8001DCC4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", func_8001E018_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", func_8001E0F8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", func_8001E110_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", func_8001E184_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", func_8001E1E4_usa);
#endif

#if VERSION_USA
void bitmapSetup(void) {
}
#endif

#if VERSION_USA
void func_8001ECA4_usa(void) {
}
#endif
