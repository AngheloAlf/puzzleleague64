#ifndef DRAW2D_H
#define DRAW2D_H

#include "ultra64.h"
#include "unk.h"
#include "the_game.h"


void Draw2DTetrisWell(struct_gInfo_unk_00068 *dynamicp, tetWell *well, s32 num);
void Draw2DCursor(struct_gInfo_unk_00068 *arg0);
void Draw2DIcon(struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DAttackBrick(struct_gInfo_unk_00068 *dynamicp, s32 num, s32 check);
s32 Draw2DAttackBlock(struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DExplosion(struct_gInfo_unk_00068 *dynamicp, s32 num);
UNK_RET Draw2DClearLine(struct_gInfo_unk_00068 *dynamicp, s32 num);
// void func_8006F09C_usa();
// void func_8006F2FC_usa();
void DrawTetris(struct_gInfo_unk_00068 *arg0);
void OverFlow(struct_gInfo_unk_00068 *arg0);
void Draw2DTetris(struct_gInfo_unk_00068 *dynamicp);

#endif
