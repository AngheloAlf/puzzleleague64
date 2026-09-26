#ifndef DRAW3D_H
#define DRAW3D_H

#include "ultra64.h"
#include "unk.h"

#include "other_types.h"


struct struct_gInfo_unk_00068;
struct tetWell;

typedef enum enum_Draw3DGameStar_arg0 {
    /* 1 */ ENUM_DRAW3DGAMESTAR_ARG0_1 = 1,
    /* 2 */ ENUM_DRAW3DGAMESTAR_ARG0_2,
    /* 3 */ ENUM_DRAW3DGAMESTAR_ARG0_3,
    /* 4 */ ENUM_DRAW3DGAMESTAR_ARG0_4,
    /* 5 */ ENUM_DRAW3DGAMESTAR_ARG0_5,
    /* 6 */ ENUM_DRAW3DGAMESTAR_ARG0_6,
} enum_Draw3DGameStar_arg0;


void Set3DTile(void);
void func_8005E740_usa(void);
void Set3DExplodeTile(void);
void Draw3DFrontTetrisWell(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw3DBackTetrisWell(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
// void Draw3DTetrisBlock1();
// void Draw3DTetrisBlock2();
// void Draw3DTetrisBlockSide();
// void Draw3DTetrisSwitch();
void Draw3DTetrisNewBlock(struct struct_gInfo_unk_00068 *dynamicp, struct tetWell *well);
void Draw3DCursor(struct struct_gInfo_unk_00068 *dynamicp);
void Draw3DIcon(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw3DAttackBrick(struct struct_gInfo_unk_00068 *dynamicp, s32 num, s32 check);
// void func_800615D8_usa();
s32 Draw3DAttack(struct struct_gInfo_unk_00068 *dynamicp, s32 num, s32 front);
void Draw3DExplosion(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw3DClearLine(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw3DClearSign(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw3DGameOverStat(struct struct_gInfo_unk_00068 *dynamicp);
void Draw3DSmoke(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw3DGameStar(enum_Draw3DGameStar_arg0 which, const u16 arg1[], s32 arg2);
void func_80064728_usa(enum_Draw3DGameStar_arg0 arg0, const u16 arg1[], s32 arg2);
void func_80064AAC_usa(enum_Draw3DGameStar_arg0 arg0, const u16 arg1[], s32 arg2);
void Draw3DSmallStars(s32 layer);
void Draw3DTetris(struct struct_gInfo_unk_00068 *dynamicp);

#endif
