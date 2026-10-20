#ifndef BITMAP_H
#define BITMAP_H

#include "ultra64.h"

#include "other_types.h"

#include "file.h"

typedef enum enum_func_8001DCC4_arg3_F {
    /* 2 */ ENUM_FUNC_8001DCC4_ARG3_F_2 = 2,
    /* 3 */ ENUM_FUNC_8001DCC4_ARG3_F_3,
    /* 4 */ ENUM_FUNC_8001DCC4_ARG3_F_4,
    /* 5 */ ENUM_FUNC_8001DCC4_ARG3_F_5,
} enum_func_8001DCC4_arg3_F;

typedef enum enum_func_8001DCC4_arg3_F0 {
    /* 0x30 */ ENUM_FUNC_8001DCC4_ARG3_F0_30 = 0x30,
} enum_func_8001DCC4_arg3_F0;

#define FUNC_8001DCC4_ARG3_F 0xF
#define FUNC_8001DCC4_ARG3_F0 0xF0
#define FUNC_8001DCC4_ARG3_400 0x400
#define FUNC_8001DCC4_ARG3_800000 0x800000

// Returns value of enum enum_func_8001DCC4_arg3_F
#define FUNC_8001DCC4_ARG3_GET_F(val) ((s32)((arg3) & FUNC_8001DCC4_ARG3_F))

// Returns value of enum enum_func_8001DCC4_arg3_F0
#define FUNC_8001DCC4_ARG3_GET_F0(val) ((s32)((arg3) & FUNC_8001DCC4_ARG3_F0))

#define FUNC_8001DCC4_ARG3_GET_400(val) ((arg3) & FUNC_8001DCC4_ARG3_400)
#define FUNC_8001DCC4_ARG3_GET_800000(val) ((arg3) & FUNC_8001DCC4_ARG3_800000)

#define FUNC_8001DCC4_ARG3_PACK(a800000, a400, aF0, aF) \
    ( \
        (((a800000) << 23) & FUNC_8001DCC4_ARG3_800000) \
        | (((a400) << 10) & FUNC_8001DCC4_ARG3_400) \
        | (((aF0) << 4) & FUNC_8001DCC4_ARG3_F0) \
        | (((aF)) & FUNC_8001DCC4_ARG3_F) \
    )

typedef struct struct_bitmapLoad_arg0 {
    /* 0x00 */ u32 unk_00; // FUNC_8001DCC4_ARG3 bitpack
    /* 0x04 */ s32 unk_04; // size_t?
    /* 0x08 */ void *unk_08; // maybe u16 *?
    /* 0x0C */ s32 unk_0C; // size_t?
    /* 0x10 */ s32 unk_10; // size_t?
    /* 0x14 */ s32 unk_14; // size_t?
    /* 0x18 */ u16 *unk_18;
    /* 0x1C */ u32 unk_1C;
    /* 0x20 */ u32 *unk_20;
} struct_bitmapLoad_arg0; // size = 0x24

s32 bitmapLoadRLE(struct_bitmapLoad_arg0* arg0, File * arg1, void *arg2);
s32 bitmapLoad(struct_bitmapLoad_arg0 **arg0, File *arg1, void **arg2, s32 arg3);
nbool func_8001DCC4_usa(struct_bitmapLoad_arg0 **arg0, RomOffset arg1, RomOffset arg2, u32 arg3, s32 arg4, s32 arg5, void **heapP);
// void func_8001E018_usa();
// void func_8001E0F8_usa();
s32 func_8001E110_usa(struct_bitmapLoad_arg0 *arg0, s32 arg1, s32 * arg2, s32 * arg3);
// void func_8001E184_usa();
// void func_8001E1E4_usa();
void bitmapSetup(void);
// void func_8001ECA4_usa();

#endif
