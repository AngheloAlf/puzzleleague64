#ifndef STORY_H
#define STORY_H

#include "ultra64.h"
#include "other_types.h"
#include "unk.h"

struct struct_gInfo_unk_00068;

void storyDrawImage(Gfx **gfxP, UNK_TYPE arg1, UNK_TYPE arg2);
void func_8002B5D8_usa(Gfx **gfxP);
void func_8002B600_usa(UNK_TYPE4 arg0);
void func_8002B76C_usa(void **heapP);
nbool func_8002B7C8_usa(s32 arg0, s32 arg1);
nbool func_8002B85C_usa(s32 arg0, s32 arg1);
nbool func_8002B8B0_usa(s32 *arg0);
void DoStory(void);
void DrawStory(struct struct_gInfo_unk_00068 *arg0);
void InitStory(void);

#endif
