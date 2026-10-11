#ifndef MIMIC_H
#define MIMIC_H

#include "ultra64.h"
#include "unk.h"

struct ai_t;
struct cursor_t;
struct struct_gInfo_unk_00068;
struct tetWell;

typedef enum MimicMode {
    /*  0 */ MM_NONE,
    /*  1 */ MM_GIRLTEXT,
    /*  2 */ MM_LEVEL,
    /*  3 */ MM_STAGE,
    /*  4 */ MM_VIEWTEXT1,
    /*  5 */ MM_VIEW,
    /*  6 */ MM_VIEWTEXT2,
    /*  7 */ MM_PLAYTEXT1,
    /*  8 */ MM_PLAY,
    /*  9 */ MM_PLAYTEXT2,
    /* 10 */ MM_PLAYTEXT3,
} MimicMode;

typedef enum MimicKind {
    /* 1 */ MIMIC_COMBO = 1,
    /* 2 */ MIMIC_CHAIN,
    /* 3 */ MIMIC_SKILL_CHAIN,
    /* 4 */ MIMIC_TIMELAG,
} MimicKind;

extern MimicMode geModeMimic;

void LoadMimic1(s32 kind, s32 level, s32 number, s32 play);
void LoadMimic2(s32 kind, s32 level, s32 number, s32 play);
void MTMove(struct ai_t *brain, u8 *ptr);
void UpdateMT(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain);
void UpdateMTController(struct tetWell *well, struct cursor_t *cursor, s32 num);
void DoMT(void);
void MimicCheckState(struct tetWell *well, struct cursor_t *cursor);
s32 ViewMimic(void);
s32 PlayMimic(s32 *result);
void DrawMimic(struct struct_gInfo_unk_00068 *dynamicp);
void Draw2DMT(struct struct_gInfo_unk_00068 *dynamicp);
void Draw3DMT(struct struct_gInfo_unk_00068 *dynamicp);
void mimicTickText(UNK_TYPE arg0);
void DrawMT(struct struct_gInfo_unk_00068 *dynamicp);
void DoMimic(void);
void InitMimic(void);

#endif
