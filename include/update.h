#ifndef UPDATE_H
#define UPDATE_H

#include "ultra64.h"
#include "unk.h"
#include "the_game.h"


// void func_80057650_usa();
// void func_80057754_usa();
// void func_80057950_usa();
// void func_80057D1C_usa();
// void func_80057D68_usa();
// void func_80057E10_usa();
// void func_80057EB8_usa();
// void func_80057F84_usa();
// void func_8005806C_usa();
// void func_80058168_usa();
// void func_8005825C_usa();
// void func_8005834C_usa();
// void func_80058458_usa();
// void UpdatePlayerPuzzle();
// void func_800587CC_usa();
// void func_80058934_usa();
// void UpdatePlayerStageClear();
void UpdatePlayerStageClearTimeScore(Game_unk_8860 *arg0, s32 arg1, s32 arg2, s32 arg3);
// void func_80058D68_usa();
// void func_80058DF0_usa();
// void func_80059038_usa();
// void func_800599C4_usa();
// void func_80059A18_usa();
// void func_80059A58_usa();
// void func_80059A98_usa();
void UpdateBuffer(struct_gInfo *info);
void Update2DBuffer(struct_gInfo *info);
void Update3DBuffer(struct_gInfo *info);

#endif
