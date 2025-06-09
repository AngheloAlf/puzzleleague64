#ifndef TUTORIAL_H
#define TUTORIAL_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

// void func_80087A90_usa();
void InitTutorial(void);
void TutorialCheckState(struct tetWell *well, struct cursor_t *cursor);
void DoTutorial(void);
// void func_8008885C_usa();
// void func_800888C4_usa();

#endif
