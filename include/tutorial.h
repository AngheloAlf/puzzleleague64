#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

// void TutorialPattern();
void InitTutorial(void);
void TutorialCheckState(struct tetWell *well, struct cursor_t *cursor);
void DoTutorial(void);
// void func_8008885C_usa();
// void DrawTUT(Gfx **ppGfx, s32 nTag);
void DrawTUT(Gfx **gfxP, s32 arg1, s32 arg2);

#endif
