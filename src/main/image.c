/**
 * Original filename: image.c
 */

#include "image.h"

#include "include_asm.h"
#include "macros_defines.h"

#include "main_variables.h"

#include "file.h"
#include "reend.h"
#include "the_game.h"

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

// imageLoadROM?
nbool func_8001FD0C_usa(struct_imageLoad_arg0 **arg0, RomOffset arg1, RomOffset arg2, s32 arg3, s32 arg4, s32 arg5,
                        void **heapP) {
    struct_bitmapLoad_arg0 *sp20;

    if (func_8001DCC4_usa(&sp20, arg1, arg2, arg3, arg4, arg5, heapP)) {
        imageMake(arg0, heapP, 1);
        (*arg0)->unk_18 = 1;
        *(*arg0)->unk_2C = sp20;

        return ntrue;
    }

    return nfalse;
}

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

/**
 * Original name: imageSetScale
 */
nbool imageSetScale(struct_imageLoad_arg0 *pImage, f32 rScaleX, f32 rScaleY) {
    if ((pImage != NULL) && (rScaleX != DOUBLE_LITERAL(0.0))) {
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
#if 0
// ? func_8001E184_usa(struct_bitmapLoad_arg0 *, s32); /* extern */
// ? func_8001EDE0_usa(struct_imageLoad_arg0 *, Gfx **, uObjBg *); /* extern */
// s32 func_800209BC_usa(struct_imageLoad_arg0 *, Gfx **); /* extern */

s32 imageDraw(struct_imageLoad_arg0 *pImage, Gfx **gfxP, s32 nX, s32 nY, struct_func_8002156C_usa_arg4 *pTile) {
    Gfx *sp1C;
    Gfx *temp_a2;
    Gfx *temp_a3;
    Gfx *var_a1_4;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_lo;
    s32 temp_t0;
    s32 temp_t1;
    s32 var_a0;
    s32 var_a0_5;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_v0_10;
    s32 var_v0_2;
    struct_bitmapLoad_arg0 *temp_s2;
    u32 temp_a0_3;
    u32 temp_a0_4;
    u32 var_a0_2;
    uObjBg *temp_s1;

    if (pImage == NULL) {
        return 0;
    }

    if (pImage->unk_14 == 0) {
        return -1;
    }

    if (pImage->unk_0C & 0x24) {
        temp_t1 = pImage->unk_18;
        var_a1 = *pImage->unk_24;
        var_a0 = 0;
        if (temp_t1 > 0) {
            temp_t0 = pImage->unk_10;
            var_v0_2 = temp_t0 < 0;

            while (var_a0 < temp_t1) {
                if (!((var_v0_2 != 0) || (temp_t0 >= var_a1))) {
                    break;
                }
                var_a0 += 1;
                var_v0_2 = temp_t0 < var_a1;
                var_a1 += pImage->unk_24[var_a0];
            }

            if (var_a0 >= pImage->unk_18) {
                goto block_9;
            }
        } else {
block_9:
            var_a0 = pImage->unk_18 - 1;
        }
    } else {
        var_a0 = pImage->unk_00;
    }

    temp_s2 = pImage->unk_2C[var_a0];

    if ((((u32) (nX + temp_s2->unk_0C) >> 0x1F) | (nX >= 0x140)) != 0) {
        return 0;
    }

    temp_a0 = temp_s2->unk_10;
    if ((((u32) (nY + temp_a0) >> 0x1F) | (nY >= 0xF0)) != 0) {
        return 0;
    }

    if (pTile == NULL) {
        var_a1_2 = (s32) (temp_s2->unk_14 << 0xA) / (s32) pImage->unk_88;
        temp_lo = (temp_a0 << 0xA) / pImage->unk_8C;
    } else {
        var_a1_2 = (s32) (pTile->unk_08 << 0xA) / (s32) pImage->unk_88;
        temp_lo = (pTile->unk_0C << 0xA) / pImage->unk_8C;
    }

    if (pImage->unk_0C & 0x80) {
        if ((nX - (var_a1_2 >> 1)) >= 0x140) {
            return 0;
        } else if ((nX + (var_a1_2 >> 1)) < 0) {
            return 0;
        } else if ((nY - ((s32) (temp_lo * 7) >> 3)) >= 0xF0) {
            return 0;
        } else if ((nY + (temp_lo >> 3)) < 0) {
            return 0;
        }
    } else {
        if (nX >= 0x140) {
            return 0;
        } else if (((nX + var_a1_2) - 1) < 0) {
            return 0;
        } else if (nY >= 0xF0) {
            return 0;
        } else if (((nY + temp_lo) - 1) < 0) {
            return 0;
        }
    }

    pImage->unk_04 ^= 1;
    temp_s1 = &pImage->unk_38[pImage->unk_04];
    if ((u8)temp_s2->unk_00 == 0x55) {
        return func_800209BC_usa(pImage, gfxP);
    }
    if (pImage->unk_0C & 0x80) {
        temp_s1->b.frameX = (nX - (var_a1_2 >> 1)) * 4;
        temp_s1->b.frameY = (nY - ((s32) (temp_lo * 7) >> 3)) * 4;
    } else {
        temp_s1->b.frameX = nX * 4;
        temp_s1->b.frameY = nY * 4;
    }

    temp_s1->b.frameW = var_a1_2 * 4;
    if (pImage->unk_0C & 0x1000) {
        temp_s1->b.frameH = (temp_lo - 1) * 4;
    } else {
        temp_s1->b.frameH = temp_lo * 4;
    }

    switch ((s32)(temp_s2->unk_00 & 0xF)) {    /* switch 1; irregular */
        case 2:
            temp_s1->b.imageSiz = G_IM_SIZ_4b;
            var_a1_3 = temp_s2->unk_04 * 2;
            break;

        case 3:
            temp_s1->b.imageSiz = G_IM_SIZ_8b;
            var_a1_3 = temp_s2->unk_04;
            break;

        case 0x4:           /* switch 1 */
            temp_s1->b.imageSiz = G_IM_SIZ_16b;
            var_a1_3 = (s32) temp_s2->unk_04 >> 1;
            break;

        case 0x5:           /* switch 1 */
            temp_s1->b.imageSiz = G_IM_SIZ_32b;
            var_a1_3 = (s32) temp_s2->unk_04 >> 2;
            break;

        default:            /* switch 1 */
            return 0;
    }

    if (!(pImage->unk_0C & 0xC000)) {
        temp_s1->b.imageW = (var_a1_3 + 1) * 4;
    } else {
        temp_s1->b.imageW = var_a1_3 * 4;
    }

    if (pImage->unk_0C & 0x1001) {
        temp_s1->b.imageH = temp_s2->unk_10 * 4;
    } else {
        temp_s1->b.imageH = (temp_s2->unk_10 + 1) * 4;
    }

    temp_s1->b.imageFlip = (u16) pImage->unk_0C & 1;
    if (pImage->unk_0C & 0x200) {
        func_8001E184_usa(temp_s2, ((pImage->unk_04 * 4) + pImage)->unk_30);
        temp_s1->b.imagePtr = ((pImage->unk_04 * 4) + pImage)->unk_30;
    } else {
        temp_s1->b.imagePtr = temp_s2->unk_08;
    }

    if (pTile == NULL) {
        temp_s1->b.imageLoad = 0x33;
        if (pImage->unk_0C & 0x2000) {
            temp_s1->b.imageX = pImage->unk_90;
            temp_s1->b.imageY = pImage->unk_92;
        } else {
            temp_s1->b.imageX = pImage->unk_90 << 5;
            temp_s1->b.imageY = pImage->unk_92 << 5;
        }
    } else {
        temp_s1->b.imageLoad = 0xFFF4;
        if (pImage->unk_0C & 0x2000) {
            temp_s1->b.imageX = pImage->unk_90 + (pTile->unk_00 << 5);
            temp_s1->b.imageY = pImage->unk_92 + (pTile->unk_04 << 5);
        } else {
            temp_s1->b.imageX = (pImage->unk_90 + pTile->unk_00) << 5;
            temp_s1->b.imageY = (pImage->unk_92 + pTile->unk_04) << 5;
        }
    }

    temp_s1->s.imageYorig = (s32) temp_s1->b.imageY;
    temp_s1->b.tmemW = (u16) pImage->unk_88;
    temp_s1->b.tmemH = (u16) pImage->unk_8C;

    sp1C = *gfxP;

    gDPPipeSync(sp1C++);

    switch ((s32)temp_s2->unk_00 & 0xF0) { /* switch 2; irregular */
        case 0x10:
            temp_s1->b.imageFmt = G_IM_FMT_I;
            var_a0_2 = pImage->unk_94;
#if 0
            var_a1_4 = sp1C;

            var_a1_4->words.w0 = 0xFA000000;
            var_a1_4->words.w1 = ((var_a0_2 >> 0x18) << 0x18) | (var_a0_2 & 0xFF0000) | (var_a0_2 & 0xFF00) | (var_a0_2 & 0xFF);
            var_a1_4->unk_8 = 0xFC11FE23;
            var_a1_4->unk_C = 0xFFFFF7FB;

            sp1C = var_a1_4 + 8;
            sp1C = var_a1_4 + 0x10;
#endif
            gDPSetPrimColor(sp1C++, 0, 0, var_a0_2 >> 0x18, var_a0_2 >> 0x10, var_a0_2 >> 0x8, var_a0_2 >> 0);
            gDPSetCombineMode(sp1C++, G_CC_MODULATEI_PRIM, G_CC_MODULATEI_PRIM);
            break;

        case 0x20:
            temp_s1->b.imageFmt = G_IM_FMT_IA;
            temp_a0_4 = pImage->unk_94;
            temp_a1 = pImage->unk_14;
            var_v0_10 = (temp_a1 == 0xFF) ? temp_a0_4 : temp_a1;
#if 0
            temp_a2 = sp1C;
            temp_a2->words.w0 = 0xFA000000;
            temp_a2->words.w1 = ((temp_a0_4 >> 0x18) << 0x18) | (temp_a0_4 & 0xFF0000) | (temp_a0_4 & 0xFF00) | (var_v0_10 & 0xFF);
            sp1C = temp_a2 + 8;
#endif
            gDPSetPrimColor(sp1C++, 0, 0, temp_a0_4 >> 0x18, temp_a0_4 >> 0x10, temp_a0_4 >> 0x8, var_v0_10);

            if (pImage->unk_0C & 0x10) {
                var_a0_2 = pImage->unk_98;

#if 0
                var_a1_4 = sp1C;

                var_a1_4->words.w0 = 0xFB000000;
                var_a1_4->words.w1 = ((var_a0_2 >> 0x18) << 0x18) | (var_a0_2 & 0xFF0000) | (var_a0_2 & 0xFF00) | (var_a0_2 & 0xFF);
                var_a1_4->unk_8 = 0xFC30FE61;
                var_a1_4->unk_C = 0x55FEF379;

                sp1C = var_a1_4 + 8;
                sp1C = var_a1_4 + 0x10;
#endif
                gDPSetEnvColor(sp1C++, var_a0_2 >> 0x18, var_a0_2 >> 0x10, var_a0_2 >> 0x8, var_a0_2);
                gDPSetCombineMode(sp1C++, G_CC_BLENDPEDECALA, G_CC_BLENDPEDECALA);
            } else {
                gDPSetCombineMode(sp1C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            }
            break;

        case 0x50:      /* switch 2 */
            temp_s1->b.imageFmt = G_IM_FMT_RGBA;
            if (pImage->unk_14 == 0xFF) {
                if (pImage->unk_0C & 0x8000) {
                    gDPSetCombineMode(sp1C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                } else {
                    gDPSetCombineMode(sp1C++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                }
            } else {
                gDPSetPrimColor(sp1C++, 0, 0, 255, 255, 255, (u8)pImage->unk_14);
                gDPSetCombineMode(sp1C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
            }
            break;

        case 0x30:      /* switch 2 */
            temp_s1->b.imageFmt = G_IM_FMT_CI;
            if (pImage->unk_14 == 0xFF) {
                if (pImage->unk_0C & 0x8000) {
                    gDPSetCombineMode(sp1C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                } else {
                    gDPSetCombineMode(sp1C++, G_CC_DECALRGBA, G_CC_DECALRGBA);
                }
            } else {
#if 0
                temp_a3 = sp1C;

                temp_a3->words.w0 = 0xFA000000;
                temp_a3->words.w1 = (u8)pImage->unk_14 | ~0xFF;

                sp1C = temp_a3 + 8;
#endif
                gDPSetPrimColor(sp1C++, 0, 0, 255, 255, 255, (u8)pImage->unk_14);

                if (pImage->unk_0C & 0x10) {
                    temp_a0_3 = pImage->unk_98;
#if 0
                    temp_a3->unk_8 = 0xF8000000;
                    temp_a3->unk_C = (s32) (((temp_a0_3 >> 0x18) << 0x18) | (temp_a0_3 & 0xFF0000) | (temp_a0_3 & 0xFF00) | ((0xFF - pImage->unk_14) & 0xFF));
                    temp_a3->unk_10 = 0xFCFFFFFF;
                    temp_a3->unk_14 = 0xFFFCF238;

                    sp1C = temp_a3 + 0x10;
                    sp1C = temp_a3 + 0x18;
#endif
                    gDPSetFogColor(sp1C++, temp_a0_3 >> 0x18, temp_a0_3 >> 0x10, temp_a0_3 >> 0x8, 0xFF - pImage->unk_14);
                    gDPSetCombineMode(sp1C++, G_CC_DECALRGBA, G_CC_PASS2);
                } else {
#if 0
                    temp_a3->unk_8 = 0xFC119623;
                    temp_a3->unk_C = 0xFF2FFFFF;
                    sp1C = temp_a3 + 0x10;
#endif
                    gDPSetCombineMode(sp1C++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                }
            }
            break;

        default:        /* switch 2 */
            return 0;
    }

    if (((temp_s2->unk_00 & 0xF0) == 0x20) || (((temp_s2->unk_00 & 0xF0) == 0x30) && ((temp_s2->unk_00 & 0x400) || (pImage->unk_14 != 0xFF))) || ((temp_s2->unk_00 & 0xF0) == 0x50)) {
        if ((temp_s2->unk_00 & 0xF0) == 0x30) {
            if (pImage->unk_0C & 0x10) {
                gDPSetCycleType(sp1C++, G_CYC_2CYCLE);
                gDPSetRenderMode(sp1C++, G_RM_FOG_PRIM_A, G_RM_XLU_SURF2);
            } else {
                if ((pImage->unk_14 != 0xFF) || (pImage->unk_0C & 0x8000)) {
                    goto block_102;
                } else {
                    goto block_103;
                }
            }
        } else {
block_102:
            gDPSetCycleType(sp1C++, G_CYC_1CYCLE);
            gDPSetRenderMode(sp1C++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        }
    } else {
block_103:
        gDPSetCycleType(sp1C++, G_CYC_1CYCLE);
        gDPSetRenderMode(sp1C++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    }

    gDPSetTextureLOD(sp1C++, G_TL_TILE);
    gDPSetTextureConvert(sp1C++, G_TC_FILT);
    gDPSetTexturePersp(sp1C++, G_TP_NONE);
    gDPSetTextureDetail(sp1C++, G_TD_CLAMP);
    gDPSetAlphaDither(sp1C++, G_AD_DISABLE);

    if ((temp_s2->unk_00 & 0xF0) == 0x30) {
        gDPSetTextureLUT(sp1C++, G_TT_RGBA16);

        switch ((s32)(temp_s2->unk_00 & 0xF)) { /* switch 4; irregular */
            case 0x2:   /* switch 4 */
                var_a0_5 = 0x07030000;

                temp_s1->b.imagePal = 0;
                gDPLoadTLUT_pal16(sp1C++, 0, temp_s2->unk_18);
                break;

            case 0x3:   /* switch 4 */
                temp_s1->b.imagePal = 0;
                gDPLoadTLUT_pal256(sp1C++, temp_s2->unk_18);
                break;

            default:    /* switch 4 */
                return 0;
        }
    } else {
        temp_s1->b.imagePal = 0;

        gDPSetTextureLUT(sp1C++, G_TT_NONE);
    }

    if ((temp_s2->unk_00 & 0x400) && (pImage->unk_14 == 0xFF)) {
        gDPSetAlphaCompare(sp1C++, G_AC_THRESHOLD);
        gDPSetBlendColor(sp1C++, 0, 0, 0, 127);
    } else {
        gDPSetAlphaCompare(sp1C++, G_AC_NONE);
    }
    if (pImage->unk_0C & 0x1000) {
        gDPSetTextureFilter(sp1C++, G_TF_BILERP);
    } else {
        gDPSetTextureFilter(sp1C++, G_TF_POINT);
    }

    if (pImage->unk_0C & 0xC000) {
        func_8001EDE0_usa(pImage, &sp1C, temp_s1);
    } else if (gTheGame.dimension == DIMENSION_2D) {
        gSPBgRect1Cyc(sp1C++, temp_s1);
    } else {
        guS2DEmuSetScissor(0U, 0U, 0x140U, 0xF0U, (u8) ((pImage->unk_0C >> 0xC) & 1));
        guS2DEmuBgRect1Cyc(&sp1C, temp_s1);
    }

    *gfxP = sp1C;
    return -1;

}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/image", imageDraw);
#endif
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
