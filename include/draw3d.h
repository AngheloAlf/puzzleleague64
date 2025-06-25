#ifndef DRAW3D_H
#define DRAW3D_H

#include "ultra64.h"
#include "unk.h"

struct struct_gInfo_unk_00068;
struct tetWell;

// void func_8005E510_usa();
// void func_8005E740_usa();
// void func_8005E7A4_usa();
void Draw3DFrontTetrisWell(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw3DBackTetrisWell(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
// void func_8005F984_usa();
// void func_8005FA6C_usa();
// void func_8005FB10_usa();
// void func_8005FD38_usa();
void Draw3DTetrisNewBlock(struct struct_gInfo_unk_00068 *dynamicp, struct tetWell *well);
void Draw3DCursor(struct struct_gInfo_unk_00068 *dynamicp);
void Draw3DIcon(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw3DAttackBrick(struct struct_gInfo_unk_00068 *dynamicp, s32 num, s32 check);
// void func_800615D8_usa();
s32 Draw3DAttack(struct struct_gInfo_unk_00068 *dynamicp, s32 num, s32 front);
void Draw3DExplosion(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw3DClearLine(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw3DClearSign(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
// void func_80063110_usa();
// void func_80063F8C_usa();
// void func_800643A4_usa();
// void func_80064728_usa();
// void func_80064AAC_usa();
// void func_80064E44_usa();
void Draw3DTetris(struct struct_gInfo_unk_00068 *dynamicp);

#endif
