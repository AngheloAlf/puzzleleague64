#ifndef GFX_H
#define GFX_H

#include "ultra64.h"
#include "unk.h"
#include "the_game.h"


void InitGFX(void);
s32 CreateMenuGfxTask(struct_gInfo *info);
void CreateGameGfxTask1(struct_gInfo *info);
s32 CreateGameGfxTask2(struct_gInfo *info);
void BuildTask(struct_gInfo *info);

#endif
