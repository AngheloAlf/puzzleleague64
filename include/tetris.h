#ifndef TETRIS_H
#define TETRIS_H

#include "ultra64.h"
#include "unk.h"

#include "block.h"

struct tetWell;

BlockType RandomBlock(struct tetWell *well);
// void func_80089778_usa();
// void func_80089828_usa();
// void func_8008997C_usa();
s32 DemoCheck(s32 *arg0);
// void func_80089BE0_usa();
void InitTetrisWell(void);
void DoTetris(void);
// void func_8008ADB4_usa();

#endif
