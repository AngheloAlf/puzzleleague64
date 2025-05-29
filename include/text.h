#ifndef TEXT_H
#define TEXT_H

#include "ultra64.h"
#include "unk.h"

#include "PR/gs2dex.h"

struct struct_gInfo_unk_00068;

/* Original name: text_t */
typedef struct text_t {
    /* 0x00 */ uObjSprite word; /* Original name: word */
    /* 0x18 */ u32 texture; /* Original name: texture */
    // /* 0x1C */ UNK_TYPE1 unk_1C[0x4]; // Probably alignment padding
} text_t; // size = 0x20

// TODO: enum or defines for `type`
s32 InitWhichNumber(text_t *arg0, char arg1, s32 type);
void SetText(s32 x, s32 y, const char *str, s32 type);
// void func_8004C280_usa();
void Draw2DTemplate(struct struct_gInfo_unk_00068 *dynamicp);
void Draw2DText(struct struct_gInfo_unk_00068 *dynamicp);
// void func_8004DF64_usa();

#endif