#ifndef FADE_H
#define FADE_H

#include "ultra64.h"

#include "unk.h"

// void func_80054020_usa();
void SetGameFade(void);
// void func_8005407C_usa();
void DoGameFade(s32 factor);
void Draw2DGameFade(void);
// void func_80054320_usa();
// void func_8005443C_usa();
s32 DoFlashDraw(s32 arg0);
s32 DoFlashDrawAlways(void);

#endif
