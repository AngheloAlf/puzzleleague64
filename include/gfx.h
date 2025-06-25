#ifndef GFX_H
#define GFX_H

#include "ultra64.h"
#include "unk.h"

struct struct_gInfo;

void InitGFX(void);
s32 CreateMenuGfxTask(struct struct_gInfo *info);
void CreateGameGfxTask1(struct struct_gInfo *info);
s32 CreateGameGfxTask2(struct struct_gInfo *info);
void BuildTask(struct struct_gInfo *info);

#endif
