#ifndef FLIC_H
#define FLIC_H

#include "ultra64.h"

#include "other_types.h"

struct struct_gInfo_unk_00068;

// void InitFlic();
// void func_8004E4E4_usa();
// void func_8004E5E8_usa();
// void func_8004E688_usa();
// void func_8004E854_usa();
// void func_8004E8CC_usa();
// void func_8004E9D8_usa();
// void func_8004EAB8_usa();
void Draw2DAnimation(struct struct_gInfo_unk_00068 *dynamicp, s32 from, s32 to);
// void func_8004EC08_usa();
void func_8004EC4C_usa(TexturePtr arg0, s32 arg1, s32 arg2, s32 arg3);

#endif
