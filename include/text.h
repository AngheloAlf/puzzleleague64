#ifndef TEXT_H
#define TEXT_H

#include "ultra64.h"
#include "the_game.h"
#include "unk.h"

s32 InitWhichNumber(TheGame_unk_90C8 *arg0, char arg1, s32 arg2);
void SetText(s32, s32, const char *, s32);
// void func_8004C280_usa();
void Draw2DTemplate(struct_gInfo_unk_00068 *arg0);
void Draw2DText(struct_gInfo_unk_00068 *arg0);
// void func_8004DF64_usa();

#endif