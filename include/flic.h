#ifndef FLIC_H
#define FLIC_H

#include "ultra64.h"
#include "unk.h"

#include "libc/stdbool.h"

#include "other_types.h"

struct struct_gInfo_unk_00068;

#define FLIC_COUNT 10

typedef struct flic_t {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 index;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
} flic_t; // size = 0x20

#if 0
struct flic_t {
    // total size: 0x20
    int duration; // offset 0x0, size 0x4
    int counter; // offset 0x4, size 0x4
    int type; // offset 0x8, size 0x4
    int layer; // offset 0xC, size 0x4
    int palette; // offset 0x10, size 0x4
    int index; // offset 0x14, size 0x4
    int texture; // offset 0x18, size 0x4
    int next_flic; // offset 0x1C, size 0x4
};
#endif

void InitFlic(void);
void InitTrack(char *currSegment, nbool first, s32 color, s32 bg, s32 text, s32 sprite, s32 track);
void InitAnimeBGTransparent(void);
void Draw2DAnimation(struct struct_gInfo_unk_00068 *dynamicp, s32 from, s32 to);
void Draw3DAnimation(struct struct_gInfo_unk_00068 *dynamicp, s32 arg1, s32 arg2);
void func_8004EC4C_usa(TexturePtr arg0, bool arg1, s32 main_height, s32 top_height);

#endif
