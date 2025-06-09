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

extern MimicMode geModeMimic;

// void func_80083050_usa();
// void func_8008336C_usa();
// void func_800833B0_usa();
void UpdateMT(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain);
void UpdateMTController(struct tetWell *well, struct cursor_t *cursor, s32 num);
void DoMT(void);
void MimicCheckState(struct tetWell *well, struct cursor_t *cursor);
// void func_80084C18_usa();
// void func_80084C84_usa();
// void func_80084D24_usa();
void Draw2DMT(struct struct_gInfo_unk_00068 *dynamicp);
void Draw3DMT(struct struct_gInfo_unk_00068 *dynamicp);
// void func_80085CC8_usa();
void DrawMT(struct struct_gInfo_unk_00068 *dynamicp);
void DoMimic(void);
void InitMimic(void);

#endif
