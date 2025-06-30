#ifndef TEXT_H
#define TEXT_H

#include "ultra64.h"
#include "PR/gs2dex.h"
#include "unk.h"

#define DRAWTEXT_COUNT 70

struct struct_gInfo_unk_00068;

/* Original name: text_t */
typedef struct text_t {
    /* 0x00 */ uObjSprite word; /* Original name: word */
    /* 0x18 */ s32 texture; /* Original name: texture */
    // /* 0x1C */ UNK_TYPE1 unk_1C[0x4]; // Probably alignment padding
} text_t; // size = 0x20

typedef enum SetTextType {
    /* 0x14 */ SETTEXTTYPE_14 = 0x14,
    /* 0x15 */ SETTEXTTYPE_15,
    /* 0x16 */ SETTEXTTYPE_16,
    /* 0x17 */ SETTEXTTYPE_17,
} SetTextType;

// TODO: enum or defines for `type`
void SetText(s32 x, s32 y, const char str[], SetTextType type);
void UpdateText(void);
void Draw2DTemplate(struct struct_gInfo_unk_00068 *dynamicp);
void Draw2DText(struct struct_gInfo_unk_00068 *dynamicp);
void Draw3DText(struct struct_gInfo_unk_00068 *dynamicp);

#endif