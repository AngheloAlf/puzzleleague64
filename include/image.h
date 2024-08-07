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

typedef struct struct_func_8002156C_usa_arg4 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} struct_func_8002156C_usa_arg4; // size = 0x10?


void imageMake(struct_imageLoad_arg0 **arg0, void **arg1, u32 arg2);
// void func_8001EDE0_usa();
s32 imageLoad(struct_imageLoad_arg0 **arg0, char *filename, void **arg2);
// void func_8001FC08_usa();
s32 func_8001FD0C_usa(struct_imageLoad_arg0 **arg0, RomOffset arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, void **heapP);
nbool imageCopy(struct_imageLoad_arg0 **arg0, struct_imageLoad_arg0 *arg1, void **heapP);
nbool imageMakeScan(struct_imageLoad_arg0 *arg0, void **heapP);
// void func_80020044_usa();
// void func_800200B4_usa();
// void func_80020208_usa();
// void func_80020304_usa();
nbool imageSetScale(struct_imageLoad_arg0 *arg0, f32 arg1, f32 arg2);
// void func_8002063C_usa();
// void func_800206DC_usa();
// void func_80020754_usa();
s32 func_800207FC_usa(UNK_PTR arg0, s32 arg1);
// void func_800209BC_usa();
s32 func_80021414_usa(struct_imageLoad_arg0 *, s32, s32, u16 *);
s32 imageDraw(struct_imageLoad_arg0 *arg0, Gfx **gfxP, s32 arg2, s32 arg3, struct_func_8002156C_usa_arg4 *arg4);
// void func_80022184_usa();
// void func_80022268_usa();
void imageSetup(void);
// void func_800222E4_usa();

#endif
