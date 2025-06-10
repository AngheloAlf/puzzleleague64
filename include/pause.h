#ifndef PAUSE_H
#define PAUSE_H

#include "ultra64.h"
#include "unk.h"

struct struct_gInfo_unk_00068;

// void func_80035B20_usa();
// void func_80035FF0_usa();
// void func_800364BC_usa();
void Draw2DPause(struct struct_gInfo_unk_00068 *dynamicp);
void Draw3DPause(struct struct_gInfo_unk_00068 *dynamicp);
void DrawPause(struct struct_gInfo_unk_00068 *dynamicp);

#endif
