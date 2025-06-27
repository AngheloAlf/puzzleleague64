/**
 * Original filename: image.c
 */

#include "image.h"

#include "include_asm.h"
#include "macros_defines.h"

#include "main_variables.h"

#include "file.h"
#include "reend.h"

extern s32 gnSizeWaveLast;

void imageMake(struct_imageLoad_arg0 **ppImage, void **heapP, u32 nCount) {
    *ppImage = *heapP = (void *)ALIGN4((uintptr_t)*heapP);
    *heapP = (void *)((uintptr_t)*heapP + sizeof(struct_imageLoad_arg0));

    (*ppImage)->unk_2C = *heapP = (void *)ALIGN4((uintptr_t)*heapP);
    *heapP = (void *)((uintptr_t)*heapP + nCount * sizeof(struct_bitmapLoad_arg0 *));

    (*ppImage)->unk_24 = *heapP = (void *)ALIGN4((uintptr_t)*heapP);
    *heapP = (void *)((uintptr_t)*heapP + nCount * sizeof(s32));

    (*ppImage)->unk_1C = *heapP = (void *)ALIGN4((uintptr_t)*heapP);
    *heapP = (void *)((uintptr_t)*heapP + nCount * sizeof(s32));

    (*ppImage)->unk_20 = *heapP = (void *)ALIGN4((uintptr_t)*heapP);
    *heapP = (void *)((uintptr_t)*heapP + nCount * sizeof(s32));

    (*ppImage)->unk_10 = 0;
    (*ppImage)->unk_0C = 0;
    (*ppImage)->unk_00 = 0;
    (*ppImage)->unk_04 = 0;
    (*ppImage)->unk_88 = 0x400;
    (*ppImage)->unk_8C = 0x400;
    (*ppImage)->unk_14 = 0xFF;
    (*ppImage)->unk_90 = 0;
    (*ppImage)->unk_92 = 0;
    (*ppImage)->unk_08 = 0;
    (*ppImage)->unk_28 = 0;
    (*ppImage)->unk_94 = -1;
    (*ppImage)->unk_98 = -1;
    (*ppImage)->unk_30 = NULL;
    (*ppImage)->unk_34 = NULL;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_8001EDE0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_8001EF20_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_8001EF30_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_8001EFA0_ger);
#endif

s32 imageLoad(struct_imageLoad_arg0 **ppImage, void *pNameOrFile, void **heapP) {
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

#if 0
    struct_bitmap_c_43 file; // r1+0x28
    int iBitmap; // r26
    int bFlip; // r29
    int nSize; // r1+0x24
    unsigned char nRed; // r1+0x23
    unsigned char nGreen; // r1+0x22
    unsigned char nBlue; // r1+0x21
    unsigned char nAlpha; // r1+0x20
    unsigned int nHeader; // r1+0x1C
    unsigned int nType; // r1+0x18
    unsigned int nBitmapCount; // r1+0x14
#endif

    if (fileTest(pNameOrFile)) {
        bcopy(pNameOrFile, &file, sizeof(File));
    } else {
        fileOpen(&file, pNameOrFile);
    }

    magic = 0;
    fileGet(&file, &magic, sizeof(u32));
    if (magic == 'BIF3') {
        needsReend = false;
    } else if (magic == '3FIB') {
        needsReend = true;
    } else {
#if VERSION_USA
        char *auxName = fileTest(pNameOrFile) ? "<FILE>" : pNameOrFile;

        osSyncPrintf("imageLoad: Could not load IMAGE '%s'\n", auxName);
#endif

        return 0;
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

    imageMake(ppImage, heapP, sp2C);
    (*ppImage)->unk_0C = sp24;
    (*ppImage)->unk_18 = sp2C;
    (*ppImage)->unk_94 = ((sp28 << 0x18) | (sp29 << 0x10) | (sp2A << 8) | sp2B);
    if (sp24 & 0x10) {
        fileGet(&file, &sp28, sizeof(u8));
        fileGet(&file, &sp29, sizeof(u8));
        fileGet(&file, &sp2A, sizeof(u8));
        fileGet(&file, &sp2B, sizeof(u8));
        (*ppImage)->unk_98 = ((sp28 << 0x18) | (sp29 << 0x10) | (sp2A << 8) | sp2B);
    }

    if (sp24 & 8) {
        fileGet(&file, &sp30, 4);
        if (needsReend) {
            sp30 = REEND_SWORD(sp30);
        }
        fileSeek(&file, FILE_SEEK_CUR, sp30);
    }

    for (i = 0; i < sp2C; i++) {
        fileGet(&file, &(*ppImage)->unk_1C[i], sizeof(s32));
        fileGet(&file, &(*ppImage)->unk_20[i], sizeof(s32));
        fileGet(&file, &(*ppImage)->unk_24[i], sizeof(s32));

        if (needsReend) {
            (*ppImage)->unk_1C[i] = REEND_SWORD((*ppImage)->unk_1C[i]);
            (*ppImage)->unk_20[i] = REEND_SWORD((*ppImage)->unk_20[i]);
            (*ppImage)->unk_24[i] = REEND_SWORD((*ppImage)->unk_24[i]);
        }

        bitmapLoad(&(*ppImage)->unk_2C[i], &file, heapP, (sp24 & 0x200) ? -1 : 0);
    }

    if (sp24 & 0x200) {
        struct_imageLoad_arg0 *temp_a1_4 = *ppImage;
        struct_bitmapLoad_arg0 *temp_v0 = temp_a1_4->unk_2C[0];
        s32 var_t0 = temp_v0->unk_04 * temp_v0->unk_10;
        s32 j;

        for (j = 1; j < temp_a1_4->unk_18; j++) {
            temp_v0 = temp_a1_4->unk_2C[j];
            var_t0 = MAX(var_t0, temp_v0->unk_04 * temp_v0->unk_10);
        }

        temp_a1_4->unk_30 = *heapP = (void *)ALIGN16((uintptr_t)*heapP);

        var_t0 = ALIGN16(var_t0);

        temp_a1_4->unk_34 = *heapP = (void *)ALIGN16((uintptr_t)*heapP + var_t0);

        *heapP = (void *)((uintptr_t)*heapP + var_t0);
    }

    if (!fileTest(pNameOrFile)) {
        fileClose(&file);
        return -1;
    } else {
        bcopy(&file, pNameOrFile, sizeof(File));
        return -1;
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_8001FC08_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_8001FD1C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_8001FD2C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_8001FD9C_ger);
#endif

#if VERSION_USA
// imageLoadROM?
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_8001FD0C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_8001FD0C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_8001FD0C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_8001FD0C_usa);
#endif

nbool imageCopy(struct_imageLoad_arg0 **ppImage, struct_imageLoad_arg0 *pImage, void **heapP) {
    s32 i;

    imageMake(ppImage, heapP, pImage->unk_18);
    (*ppImage)->unk_0C = pImage->unk_0C;
    (*ppImage)->unk_18 = pImage->unk_18;
    (*ppImage)->unk_94 = pImage->unk_94;
    (*ppImage)->unk_98 = pImage->unk_98;

    for (i = 0; i < pImage->unk_18; i++) {
        (*ppImage)->unk_2C[i] = pImage->unk_2C[i];
        (*ppImage)->unk_1C[i] = pImage->unk_1C[i];
        (*ppImage)->unk_20[i] = pImage->unk_20[i];
        (*ppImage)->unk_24[i] = pImage->unk_24[i];
    }

    if (pImage->unk_0C & 0x200) {
        struct_imageLoad_arg0 *temp_t0 = *ppImage;
        struct_bitmapLoad_arg0 *temp_v0 = temp_t0->unk_2C[0];
        s32 size = temp_v0->unk_04 * temp_v0->unk_10;
        s32 j;

        for (j = 1; j < temp_t0->unk_18; j++) {
            temp_v0 = temp_t0->unk_2C[j];
            if (size < temp_v0->unk_04 * temp_v0->unk_10) {
                size = temp_v0->unk_04 * temp_v0->unk_10;
            }
        }

        size = ALIGN(size, 16);

        temp_t0->unk_30 = *heapP = (void *)ALIGN(*heapP, 16);
        *heapP += size;

        temp_t0->unk_34 = *heapP = (void *)ALIGN(*heapP, 16);
        *heapP += size;
    }

    return ntrue;
}

nbool imageMakeScan(struct_imageLoad_arg0 *pImage, void **heapP) {
    s32 i;
    s32 j;
    s32 count;

    count = 0;
    for (i = 0; i < pImage->unk_18; i++) {
        if (count < pImage->unk_2C[i]->unk_10) {
            count = pImage->unk_2C[i]->unk_10;
        }
    }
    pImage->unk_08 = count;

    pImage->unk_28 = *heapP = (void *)ALIGN(*heapP, ALIGNOF(*pImage->unk_28));
    *heapP += count * sizeof(*pImage->unk_28);

    for (j = 0; j < count; j++) {
        pImage->unk_28[j].unk_0 = 0;
        pImage->unk_28[j].unk_4 = -1;
        pImage->unk_28[j].unk_8 = 0;
        pImage->unk_28[j].unk_A = 0;
    }

    return ntrue;
}

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
nbool imageSetScale(struct_imageLoad_arg0 *pImage, f32 rScaleX, f32 rScaleY) {
    if ((pImage != NULL) && (rScaleX != 0.0)) {
        pImage->unk_88 = 1024 / rScaleX;
        if (rScaleX != rScaleY) {
            pImage->unk_8C = 1024 / rScaleY;
        } else {
            pImage->unk_8C = pImage->unk_88;
        }
        return ntrue;
    }
    return nfalse;
}
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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_80020158_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_800201C8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_8002031C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_80020418_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_800206C0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_80020750_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_800207F0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_80020868_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_80020910_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_80020AD0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_80020168_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_800201D8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_8002032C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_80020428_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_800206D0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_80020760_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_80020800_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_80020878_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_80020920_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_80020AE0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_800201D8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_80020248_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_8002039C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_80020498_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_80020740_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_800207D0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_80020870_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_800208E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_80020990_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_80020B50_ger);
#endif

#if VERSION_USA
#ifdef NON_EQUIVALENT
s32 func_80021414_usa(struct_imageLoad_arg0 *arg0, s32 arg1, s32 arg2, u16 *arg3) {
    s32 *sp0;
    s32 temp_v1;
    s32 var_a1;
    s32 var_a2;
    s32 var_t0;
    s32 var_t1;
    struct_bitmapLoad_arg0 *temp_t1;
    u16 *var_a3;
    u16 *var_t0_2;
    u16 *var_v1;
    u16 temp_a0;

    if (arg0 == NULL) {
        return 0;
    }

    if (arg0->unk_0C & 0x24) {
        var_t1 = *arg0->unk_24;
        var_t0 = 0;
        while (var_t0 < arg0->unk_18) {
            if ((arg0->unk_10 >= temp_v1) && (arg0->unk_10 < var_t1)) {
                break;
            }
            temp_v1 = var_t1;
            var_t0 += 1;
            var_t1 += arg0->unk_24[var_t0];
        }
        if (var_t0 >= arg0->unk_18) {
            var_t0 = arg0->unk_18 - 1;
        }
    } else {
        var_t0 = arg0->unk_00;
    }

    *sp0 = var_t0;
    temp_t1 = arg0->unk_2C[*sp0];
    if ((u8)temp_t1->unk_00 != 0x54) {
        return 0;
    }
    var_a3 = &arg3[(arg2 * 0x140) + arg1];
    var_a2 = 0;
    while (var_a2 < temp_t1->unk_10) {
        var_t0_2 = var_a3;
        var_a1 = 0;
        var_v1 = temp_t1->unk_08 + (temp_t1->unk_04 * var_a2);
        while (var_a1 < temp_t1->unk_0C) {
            if (var_v1[var_a1] & 1) {
                *var_t0_2 = var_v1[var_a1];
            }
            var_t0_2++;
            var_a1++;
        }
        var_a2 += 1;
        var_a3 += 0x280 / 2;
    }
    return -1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_80021414_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_80021414_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_80021414_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_80021414_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", imageDraw);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", imageDraw);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", imageDraw);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", imageDraw);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_80022184_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_80022298_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_800222A8_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_80022318_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/image", func_80022268_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/image", func_8002237C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/image", func_8002238C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/image", func_800223FC_ger);
#endif

void imageSetup(void) {
    gnSizeWaveLast = -1;
}

void func_800222E4_usa(void) {
}
