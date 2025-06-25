#ifndef DRAW2D_H
#define DRAW2D_H

#include "ultra64.h"
#include "unk.h"

struct struct_gInfo_unk_00068;
struct tetWell;


void Draw2DTetrisWell(struct struct_gInfo_unk_00068 *dynamicp, struct tetWell *well, s32 num);
void Draw2DCursor(struct struct_gInfo_unk_00068 *dynamicp);
void Draw2DIcon(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DAttackBrick(struct struct_gInfo_unk_00068 *dynamicp, s32 num, s32 check);
s32 Draw2DAttackBlock(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DExplosion(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DClearLine(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DSmoke(struct struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DSmallStars(struct struct_gInfo_unk_00068 *dynamicp, s32 layer);
void DrawTetris(struct struct_gInfo_unk_00068 *dynamicp);
void OverFlow(struct struct_gInfo_unk_00068 *dynamicp);
void Draw2DTetris(struct struct_gInfo_unk_00068 *dynamicp);

#endif
