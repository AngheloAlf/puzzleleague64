#ifndef DRAW2D_H
#define DRAW2D_H

#include "ultra64.h"
#include "unk.h"

#include "the_game.h"


void Draw2DTetrisWell(struct_gInfo_unk_00068 *dynamicp, tetWell *well, s32 num);
void Draw2DCursor(struct_gInfo_unk_00068 *dynamicp);
void Draw2DIcon(struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DAttackBrick(struct_gInfo_unk_00068 *dynamicp, s32 num, s32 check);
s32 Draw2DAttackBlock(struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DExplosion(struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DClearLine(struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DSmoke(struct_gInfo_unk_00068 *dynamicp, s32 num);
void Draw2DSmallStars(struct_gInfo_unk_00068 *dynamicp, s32 layer);
void DrawTetris(struct_gInfo_unk_00068 *dynamicp);
void OverFlow(struct_gInfo_unk_00068 *dynamicp);
void Draw2DTetris(struct_gInfo_unk_00068 *dynamicp);

#endif
