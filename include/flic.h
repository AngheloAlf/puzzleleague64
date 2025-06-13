#ifndef FLIC_H
#define FLIC_H

#include "ultra64.h"
#include "unk.h"

#include "libc/stdbool.h"

#include "other_types.h"

struct struct_gInfo_unk_00068;

void InitFlic(void);
void func_8004E4E4_usa(UNK_TYPE *arg0, s32 arg1, UNK_TYPE arg2, s32 arg3, UNK_TYPE arg4, UNK_TYPE arg5, UNK_TYPE arg6);
s32 func_8004E5E8_usa(UNK_TYPE *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_8004E688_usa(UNK_TYPE *arg0, s32 arg1, s32 arg2, s32 arg3);
// void func_8004E854_usa();
s32 func_8004E8CC_usa(UNK_TYPE *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_8004E9D8_usa(UNK_TYPE *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_8004EAB8_usa(UNK_TYPE *arg0, s32 arg1, s32 arg2, s32 arg3);
void Draw2DAnimation(struct struct_gInfo_unk_00068 *dynamicp, s32 from, s32 to);
// void func_8004EC08_usa();
void func_8004EC4C_usa(TexturePtr arg0, bool arg1, s32 main_height, s32 top_height);

#endif
