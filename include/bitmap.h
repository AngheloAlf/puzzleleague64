#ifndef BITMAP_H
#define BITMAP_H

#include "ultra64.h"
#include "unk.h"
#include "file.h"

typedef struct struct_bitmapLoad_arg0 {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ UNK_TYPE unk_04;
    /* 0x08 */ void *unk_08;
    /* 0x0C */ UNK_TYPE unk_0C;
    /* 0x10 */ UNK_TYPE unk_10;
    /* 0x14 */ UNK_TYPE unk_14;
    /* 0x18 */ UNK_TYPE2 *unk_18;
    /* 0x1C */ u32 unk_1C;
    /* 0x20 */ u32 *unk_20;
} struct_bitmapLoad_arg0; // size = 0x24

s32 bitmapLoadRLE(struct_bitmapLoad_arg0* arg0, File * arg1, void *arg2);
s32 bitmapLoad(struct_bitmapLoad_arg0 **arg0, File *arg1, void **arg2, s32 arg3);
// void func_8001DCC4_usa();
// void func_8001E018_usa();
// void func_8001E0F8_usa();
s32 func_8001E110_usa(struct_bitmapLoad_arg0 *arg0, s32 arg1, s32 * arg2, s32 * arg3);
// void func_8001E184_usa();
// void func_8001E1E4_usa();
void bitmapSetup(void);
// void func_8001ECA4_usa();

#endif
