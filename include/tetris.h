#ifndef TETRIS_H
#define TETRIS_H

#include "ultra64.h"
#include "unk.h"

#include "block.h"

struct tetWell;

BlockType RandomBlock(struct tetWell *well);
// void InitBlockPattern();
void InitStartingBlocks(struct tetWell *well, char *ptr, s32 total);
s32 DemoCheck(s32 *frame);
void DemoCPU(s32 num, s32 level);
void InitTetrisWell(void);
void DoTetris(void);
void HackGame(struct tetWell *well);

#endif
