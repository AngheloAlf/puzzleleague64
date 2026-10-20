/**
 * Original filename: bitmap.c
 */

#include "bitmap.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "reend.h"

#include "file.h"
#include "sound.h"

extern s32 gpBitmapLast;

// TODO: some functions may be misnamed
#if 0
static void bitmapMake(struct_bitmap_c_14 * * ppBitmap /* r1+0x0 */, void * ppHeap /* r1+0x4 */, int nPixel /* r1+0x8 */, int nColor /* r1+0xC */, int bDMA /* r1+0x10 */) {}
static int bitmapLoadRLE(struct_bitmap_c_14 * pBitmap /* r1+0x8 */, struct_bitmap_c_43 * pFile /* r27 */) {
int bitmapLoad(struct_bitmap_c_14 * * ppBitmap /* r31 */, void * pNameOrFile /* r28 */, void * ppHeap /* r30 */, int bDMA /* r27 */) {
int bitmapLoadROM(struct_bitmap_c_14 * * ppBitmap /* r27 */, void * pROMData /* r28 */, void * pROMCLUT /* r5 */, int nType /* r29 */, int nSizeX /* r7 */, int nSizeY /* r1+0x1C */, void * ppHeap /* r1+0x20 */) {
int bitmapFlip(struct_bitmap_c_14 * pBitmap /* r26 */) {
int bitmapLoadData(struct_bitmap_c_14 * pBitmap /* r3 */, void * pPixel /* r4 */) {}
int bitmapLoadTile(struct_bitmap_c_14 * pBitmap /* r1+0x8 */, int bLoad /* r4 */, union_pon_gc_c_173 * * ppGfx /* r1+0x10 */, struct_bitmap_c_332 * pTile /* r1+0x14 */, int * pnPixels /* r1+0x18 */) {
void bitmapSetup() {}
#endif

#if VERSION_USA
#if 0
s32 bitmapLoadRLE(struct_bitmapLoad_arg0 *arg0, File *arg1, void *arg2) {
    u8 sp10;
    u8 sp11;
    s32 temp_lo;
    s32 temp_s2;
    s32 temp_v0;
    s32 var_a1;
    s32 var_a2;
    s32 var_a3;
    s32 var_s0;
    u8 *temp_s3;
    s32 fileSize;
    s32 inFileOffset;

    fileSize = arg1->fileSize;
    inFileOffset = arg1->inFileOffset;
    temp_lo = arg0->unk_04 * arg0->unk_10;
    temp_s3 = arg0->unk_08;

    if (ALIGN16(fileSize - inFileOffset) == 0) {
        return 0;
    }

    var_s0 = 0;
    while (var_s0 < temp_lo) {
        fileGet(arg1, &sp10, 1);
        if (sp10 & 0x80) {
            if (sp10 & 0x40) {
                temp_v0 = ((sp10 >> 3) & 7) + 2;
                temp_s2 = (sp10 & 7) + 2;
                fileGet(arg1, &temp_s3[var_s0], temp_v0);

                for (var_a3 = 1; var_a3 < temp_s2; var_a3++) {
                    var_a2 = var_a3 * temp_v0;
                    var_a1 = 0;

                    while (var_a1 < temp_v0) {
                        temp_s3[var_a2 + var_s0] = temp_s3[var_s0 + var_a1];

                        var_a1 += 1;
                        var_a2 += 1;
                        if (var_s0 + var_a2 >= temp_lo) {
                            break;
                        }
                    }

                    if (var_s0 + var_a2 >= temp_lo) {
                        break;
                    }
                }

                var_s0 += temp_v0 * temp_s2;
            } else {
                fileGet(arg1, &sp11, 1);
                sp10 = (sp10 & 0x7F) + 1;
                while ((sp10 & 0xFF) != 0xFF) {
                    temp_s3[var_s0] = sp11;
                    var_s0 += 1;
                    sp10 = sp10 - 1;
                }
            }
        } else {
            fileGet(arg1, &temp_s3[var_s0], sp10 + 1);
            var_s0 = var_s0 + 1 + sp10;
        }
    }

    return -1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", bitmapLoadRLE);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bitmap", bitmapLoadRLE);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bitmap", bitmapLoadRLE);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bitmap", bitmapLoadRLE);
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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bitmap", bitmapLoad);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bitmap", bitmapLoad);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bitmap", bitmapLoad);
#endif

// bitmapLoadROM?
nbool func_8001DCC4_usa(struct_bitmapLoad_arg0 **arg0, RomOffset arg1, RomOffset arg2, u32 arg3, s32 arg4, s32 arg5,
                        void **heapP) {
    u16 *var_v1_2;
    u16 *var_v1_3;
    s32 temp_s1;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_s1;
    s32 var_s4;
    u16 temp_v0_4;
    s32 temp;

    arg3 &= FUNC_8001DCC4_ARG3_F | FUNC_8001DCC4_ARG3_F0 | FUNC_8001DCC4_ARG3_400 | FUNC_8001DCC4_ARG3_800000;

    switch (FUNC_8001DCC4_ARG3_GET_F(arg3)) {
        case ENUM_FUNC_8001DCC4_ARG3_F_2:
            var_s4 = arg4 >> 1;
            break;

        case ENUM_FUNC_8001DCC4_ARG3_F_3:
            var_s4 = arg4;
            break;

        case ENUM_FUNC_8001DCC4_ARG3_F_4:
            var_s4 = arg4 << 1;
            break;

        case ENUM_FUNC_8001DCC4_ARG3_F_5:
            var_s4 = arg4 << 2;
            break;
    }

    if (FUNC_8001DCC4_ARG3_GET_F0(arg3) == ENUM_FUNC_8001DCC4_ARG3_F0_30) {
        if (FUNC_8001DCC4_ARG3_GET_F(arg3) == ENUM_FUNC_8001DCC4_ARG3_F_3) {
            var_s1 = 0x100;
        } else {
            var_s1 = 0x10;
        }
    } else {
        var_s1 = 0;
    }

    if (!FUNC_8001DCC4_ARG3_GET_800000(arg3)) {
        temp = var_s4 * arg5;
    } else {
        temp = var_s4 * 0xF0;
    }
    var_a0 = temp;

    *arg0 = *heapP = ALIGN_TO(*heapP, struct_bitmapLoad_arg0);
    *heapP = *heapP + sizeof(struct_bitmapLoad_arg0);

    if (var_s1 > 0) {
        // ensure 8byte alignment for textures
        (*arg0)->unk_18 = *heapP = ALIGN_TO(*heapP, u64);
        *heapP += var_s1 * sizeof(u16);
    } else {
        (*arg0)->unk_18 = 0;
    }
    (*arg0)->unk_1C = 0;
    (*arg0)->unk_20 = NULL;

    // ensure 8byte alignment for textures
    (*arg0)->unk_08 = *heapP = ALIGN_TO(*heapP, u64);
    *heapP += var_a0;

    (*arg0)->unk_00 = arg3;
    (*arg0)->unk_0C = arg4;
    (*arg0)->unk_10 = !FUNC_8001DCC4_ARG3_GET_800000(arg3) ? arg5 : 0xF0;

    (*arg0)->unk_04 = var_s4;
    (*arg0)->unk_14 = arg4;

    if (var_s1 > 0) {
        DmaRomToRam(arg2, (*arg0)->unk_18, var_s1 * sizeof(u16));

        // This whole block seems to be doing nothing at all and just wasting
        // CPU cycles.
        if (FUNC_8001DCC4_ARG3_GET_400(arg3)) {
            for (var_a0_2 = 0; var_a0_2 < var_s1; var_a0_2++) {
                temp_v0_4 = (*arg0)->unk_18[var_a0_2] & GPACK_RGBA5551(255, 255, 255, 0);
                if (temp_v0_4 == GPACK_RGBA5551(0, 255, 0, 0)) {
                    (*arg0)->unk_18[var_a0_2] = temp_v0_4;
                }
            }
        }
    }

    if (FUNC_8001DCC4_ARG3_GET_800000(arg3)) {
        temp_s1 = 0xEF - arg5;
        DmaRomToRam(arg1, (*arg0)->unk_08 + (arg4 * temp_s1 * 2), var_s4 * arg5);

        for (var_a1 = 0; var_a1 < temp_s1; var_a1++) {
            // TODO: this cast is very fishy. Need to figure out what's going on here
            var_v1_2 = &((u16 *)(*arg0)->unk_08)[arg4 * var_a1];
            for (var_a0_2 = 0; var_a0_2 < arg4; var_a0_2++) {
                *var_v1_2++ = 0;
            }
        }

        var_v1_3 = &((u16 *)(*arg0)->unk_08)[arg4 * 0xEF];
        for (var_a0_2 = 0; var_a0_2 < arg4; var_a0_2++) {
            *var_v1_3++ = 0;
        }
    } else {
        DmaRomToRam(arg1, (*arg0)->unk_08, var_s4 * arg5);
    }

    return ntrue;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", func_8001E018_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bitmap", func_8001E018_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bitmap", func_8001E018_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bitmap", func_8001E018_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", func_8001E0F8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bitmap", func_8001E0F8_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bitmap", func_8001E0F8_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bitmap", func_8001E0F8_usa);
#endif

s32 func_8001E110_usa(struct_bitmapLoad_arg0 *arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    if (arg0 != NULL) {
        if (((arg0->unk_00 >> 22) & 1) && (arg1 >= 0)) {
            if (arg1 < arg0->unk_1C) {
                *arg2 = arg0->unk_20[arg1] & 0x3F;
                *arg3 = (arg0->unk_20[arg1] >> 6) & 0x3F;
                return -1;
            }
        }
    }

    return 0;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", func_8001E184_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bitmap", func_8001E184_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bitmap", func_8001E184_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bitmap", func_8001E184_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", func_8001E1E4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bitmap", func_8001E1E4_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bitmap", func_8001E1E4_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bitmap", func_8001E1E4_usa);
#endif

void bitmapSetup(void) {
}

void func_8001ECA4_usa(void) {
}
