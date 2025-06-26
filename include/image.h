#ifndef IMAGE_H
#define IMAGE_H

#include "ultra64.h"
#include "unk.h"
#include "bitmap.h"


// ImageScan?
typedef struct struct_imageLoad_arg0_unk_28 {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ UNK_TYPE2 unk_8;
    /* 0xA */ UNK_TYPE2 unk_A;
} struct_imageLoad_arg0_unk_28; // size = 0xC

// Image?
typedef struct struct_imageLoad_arg0 {
    /* 0x00 */ UNK_TYPE unk_00;
    /* 0x04 */ UNK_TYPE unk_04;
    /* 0x08 */ UNK_TYPE2 unk_08; // count of unk_28
    /* 0x0A */ UNK_TYPE1 unk_0A[0x02]; // pad?
    /* 0x08 */ u32 unk_0C;
    /* 0x10 */ UNK_TYPE unk_10;
    /* 0x14 */ UNK_TYPE unk_14;
    /* 0x18 */ s32 unk_18; // count of unk_2C, unk_1C, unk_20 and unk_24
    /* 0x1C */ s32 *unk_1C;
    /* 0x20 */ s32 *unk_20;
    /* 0x24 */ s32 *unk_24;
    /* 0x28 */ struct_imageLoad_arg0_unk_28 *unk_28;
    /* 0x2C */ struct_bitmapLoad_arg0 **unk_2C;
    /* 0x30 */ UNK_TYPE *unk_30;
    /* 0x34 */ UNK_TYPE *unk_34;
    /* 0x38 */ UNK_TYPE1 unk_38[0x50];
    /* 0x88 */ s32 unk_88;
    /* 0x8C */ s32 unk_8C;
    /* 0x90 */ UNK_TYPE2 unk_90;
    /* 0x92 */ UNK_TYPE2 unk_92;
    /* 0x94 */ u32 unk_94;
    /* 0x98 */ u32 unk_98;
    /* 0x9C */ UNK_TYPE1 unk_9C[0x4];
} struct_imageLoad_arg0; // size >= 0xA0

#if 0
typedef struct /* struct_image_c_92 */ {
    // total size: 0xA0
    int iFrame; // offset 0x0, size 0x4
    int iObject; // offset 0x4, size 0x4
    signed short nSizeScan; // offset 0x8, size 0x2
    int nType; // offset 0xC, size 0x4
    int nTick; // offset 0x10, size 0x4
    int nTranslucent; // offset 0x14, size 0x4
    int nBitmapCount; // offset 0x18, size 0x4
    int * anPositionX; // offset 0x1C, size 0x4
    int * anPositionY; // offset 0x20, size 0x4
    int * anFrameDelay; // offset 0x24, size 0x4
    struct {
        // total size: 0xC
        int nData; // offset 0x0, size 0x4
        int nRGBA; // offset 0x4, size 0x4
        signed short nDeltaX; // offset 0x8, size 0x2
        signed short nDeltaY; // offset 0xA, size 0x2
    } * aScan; // offset 0x28, size 0x4
    struct {
        // total size: 0x1C
        int nType; // offset 0x0, size 0x4
        int nStride; // offset 0x4, size 0x4
        void * aPixel; // offset 0x8, size 0x4
        int nSizeX; // offset 0xC, size 0x4
        int nSizeY; // offset 0x10, size 0x4
        int nSizeOriginalX; // offset 0x14, size 0x4
        unsigned short * aColorPalette; // offset 0x18, size 0x4
    } * * apBitmap; // offset 0x2C, size 0x4
    void * apPixel[2]; // offset 0x30, size 0x8
    union {
        struct {
            // total size: 0x28
            unsigned short imageX; // offset 0x0, size 0x2
            unsigned short imageW; // offset 0x2, size 0x2
            signed short frameX; // offset 0x4, size 0x2
            unsigned short frameW; // offset 0x6, size 0x2
            unsigned short imageY; // offset 0x8, size 0x2
            unsigned short imageH; // offset 0xA, size 0x2
            signed short frameY; // offset 0xC, size 0x2
            unsigned short frameH; // offset 0xE, size 0x2
            unsigned long long * imagePtr; // offset 0x10, size 0x4
            unsigned short imageLoad; // offset 0x14, size 0x2
            unsigned char imageFmt; // offset 0x16, size 0x1
            unsigned char imageSiz; // offset 0x17, size 0x1
            unsigned short imagePal; // offset 0x18, size 0x2
            unsigned short imageFlip; // offset 0x1A, size 0x2
            unsigned short tmemW; // offset 0x1C, size 0x2
            unsigned short tmemH; // offset 0x1E, size 0x2
            unsigned short tmemLoadSH; // offset 0x20, size 0x2
            unsigned short tmemLoadTH; // offset 0x22, size 0x2
            unsigned short tmemSizeW; // offset 0x24, size 0x2
            unsigned short tmemSize; // offset 0x26, size 0x2
        } b; // offset 0x0, size 0x28
        struct {
            // total size: 0x28
            unsigned short imageX; // offset 0x0, size 0x2
            unsigned short imageW; // offset 0x2, size 0x2
            signed short frameX; // offset 0x4, size 0x2
            unsigned short frameW; // offset 0x6, size 0x2
            unsigned short imageY; // offset 0x8, size 0x2
            unsigned short imageH; // offset 0xA, size 0x2
            signed short frameY; // offset 0xC, size 0x2
            unsigned short frameH; // offset 0xE, size 0x2
            unsigned long long * imagePtr; // offset 0x10, size 0x4
            unsigned short imageLoad; // offset 0x14, size 0x2
            unsigned char imageFmt; // offset 0x16, size 0x1
            unsigned char imageSiz; // offset 0x17, size 0x1
            unsigned short imagePal; // offset 0x18, size 0x2
            unsigned short imageFlip; // offset 0x1A, size 0x2
            unsigned short scaleW; // offset 0x1C, size 0x2
            unsigned short scaleH; // offset 0x1E, size 0x2
            long imageYorig; // offset 0x20, size 0x4
            unsigned char padding[4]; // offset 0x24, size 0x4
        } s; // offset 0x0, size 0x28
        long long force_structure_alignment; // offset 0x0, size 0x8
    } aObject[2]; // offset 0x38, size 0x50
    int nScaleX; // offset 0x88, size 0x4
    int nScaleY; // offset 0x8C, size 0x4
    unsigned short nScrollX; // offset 0x90, size 0x2
    unsigned short nScrollY; // offset 0x92, size 0x2
    unsigned int nColor0; // offset 0x94, size 0x4
    unsigned int nColor1; // offset 0x98, size 0x4
} struct_image_c_92;
#endif

typedef struct struct_func_8002156C_usa_arg4 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} struct_func_8002156C_usa_arg4; // size = 0x10?

void imageMake(struct_imageLoad_arg0 **ppImage, void **heapP, u32 nCount);
// void func_8001EDE0_usa();
s32 imageLoad(struct_imageLoad_arg0 **ppImage, void *pNameOrFile, void **heapP);
// void func_8001FC08_usa();
s32 func_8001FD0C_usa(struct_imageLoad_arg0 **arg0, RomOffset arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void **heapP);
nbool imageCopy(struct_imageLoad_arg0 **ppImage, struct_imageLoad_arg0 *pImage, void **heapP);
nbool imageMakeScan(struct_imageLoad_arg0 *pImage, void **heapP);
// void func_80020044_usa();
// void func_800200B4_usa();
// void func_80020208_usa();
// void func_80020304_usa();
nbool imageSetScale(struct_imageLoad_arg0 *pImage, f32 rScaleX, f32 rScaleY);
// void func_8002063C_usa();
// void func_800206DC_usa();
// void func_80020754_usa();
s32 func_800207FC_usa(UNK_PTR arg0, s32 arg1);
// void func_800209BC_usa();
s32 func_80021414_usa(struct_imageLoad_arg0 *, s32, s32, u16 *);
s32 imageDraw(struct_imageLoad_arg0 *pImage, Gfx **gfxP, s32 nX, s32 nY, struct_func_8002156C_usa_arg4 *pTile);
// void func_80022184_usa();
// void func_80022268_usa();
void imageSetup(void);
// void func_800222E4_usa();

#endif
