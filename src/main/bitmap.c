/**
 * Original filename: bitmap.c
 */

#include "bitmap.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "file.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bitmap", bitmapLoadRLE);
#endif

#if VERSION_USA
#ifdef NON_EQUIVALENT
typedef struct struct_bitmapLoad_arg0 {
    u32 unk_00;
    UNK_TYPE unk_04;
    RomOffset unk_08;
    UNK_TYPE unk_0C;
    UNK_TYPE unk_10;
    UNK_TYPE unk_14;
    UNK_TYPE2 *unk_18;
    UNK_TYPE unk_1C;
    UNK_TYPE4 *unk_20;
} struct_bitmapLoad_arg0; // size = ?

#define UWORD(x) ((u32)(x))
#define SWORD(x) ((s32)(x))
#define REEND_UWORD(x) \
    ((UWORD(x) >> 0x18) | ((UWORD(x) >> 8) & 0xFF00) | ((UWORD(x) << 8) & 0xFF0000) | ((UWORD(x) << 0x18) & 0xFF000000))
#define REEND_SWORD(x) \
    ((UWORD(x) >> 0x18) | ((SWORD(x) >> 8) & 0xFF00) | ((UWORD(x) << 8) & 0xFF0000) | ((UWORD(x) << 0x18) & 0xFF000000))

#define USHORT(x) ((u16)(x))
#define REEND_USHORT(x) ((USHORT(x) >> 8) | ((USHORT(x) << 8) & ~0xFF))

//? bitmapLoadRLE(u32, File *, u32);              /* extern */
extern s32 gpBitmapLast;

s32 bitmapLoad(struct_bitmapLoad_arg0 **arg0, File *arg1, void **arg2, s32 arg3) {
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
    u32 var_a1;
    u32 var_a3;
    u32 var_s0;
    u32 var_t0;
    u32 var_v1;

    if (fileTest(arg1) != false) {
        bcopy(arg1, &sp10, 0x10);
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
        fileSeek(&sp10, 1, sp34);
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

    *arg0 = *arg2 = ((uintptr_t)*arg2 + 3) & ~3;

    *arg2 = (uintptr_t)*arg2 + 0x24;
    if (sp40 > 0) {
        (*arg0)->unk_18 = *arg2 = ((uintptr_t)*arg2 + 7) & ~7;

        *arg2 = (uintptr_t)*arg2 + sp40 * 2;
    } else {
        (*arg0)->unk_18 = 0U;
    }

    if (sp38 > 0) {
        (*arg0)->unk_1C = sp38;

        (*arg0)->unk_20 = *arg2 = ((uintptr_t)*arg2 + 3) & ~3;
        *arg2 = (uintptr_t)*arg2 + sp38 * 4;
    } else {
        (*arg0)->unk_1C = 0U;
        (*arg0)->unk_20 = 0U;
    }

    if (arg3 == 0) {
        (*arg0)->unk_08 = *arg2 = ((uintptr_t)*arg2 + 7) & ~7;

        *arg2 = (uintptr_t)*arg2 + var_a0;
    } else {
        (*arg0)->unk_08 = 0U;
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
        var_t1 = ((uintptr_t)*arg2 + 3) & ~3;
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

            (*arg0)->unk_18[var_a2] =
                (var_a1 >> 7) | (((var_v1 >> 3) << 0xB) | ((var_a3 << 3) & 0x7C0) | ((var_t0 >> 2) & 0x3E));
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
        fileSeek(&sp10, 1, sp30 * sp2C);

        (*arg0)->unk_00 |= 0x100000;
        (*arg0)->unk_08 = sp44;
    } else {
        fileGet(&sp10, (*arg0)->unk_08, sp30 * sp2C);
    }

    if (fileTest(arg1) != false) {
        bcopy(&sp10, arg1, 0x10);
    } else {
        fileClose(&sp10);
    }

    if (var_s3 != 0) {
        if ((sp24 & 0xF) == 4) {
            u32 temp_lo;
            temp_lo = (sp30 / sizeof(u16)) * sp2C;

            for (var_a2 = 0; var_a2 < temp_lo; var_a2++) {
                temp_a0_3 = var_a2 * sizeof(u16) + (*arg0)->unk_08;
                *temp_a0_3 = REEND_USHORT(*temp_a0_3);
            }
        } else if ((sp24 & 0xF) == 5) {
            u32 temp_lo;
            temp_lo = (sp30 / sizeof(u32)) * sp2C;

            for (var_a2 = 0; var_a2 < temp_lo; var_a2++) {
                temp_a1 = var_a2 * sizeof(u32) + (*arg0)->unk_08;
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
