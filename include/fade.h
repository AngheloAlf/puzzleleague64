#ifndef FADE_H
#define FADE_H

#include "ultra64.h"

#include "other_types.h"

void InitGameFade(void);
void SetGameFade(void);
// void func_8005407C_usa();
void DoGameFade(s32 factor);
void Draw2DGameFade(void);
// void func_80054320_usa();
// void func_8005443C_usa();
nbool DoFlashDraw(s32 which);
nbool DoFlashDrawAlways(void);

#endif
