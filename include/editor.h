#ifndef EDITOR_H
#define EDITOR_H

#include "ultra64.h"
#include "the_game.h"
#include "unk.h"


// void func_8002F2F0_usa();
// void func_8002F464_usa();

s32 func_800306B0_usa(s32 arg0);
void DrawEditor(struct_gInfo_unk_00068 *arg0);
void DoEditor(void);
void InitEditor(void);

void editDrawImage(Gfx **gfxP, s32 arg1, s32 arg2);

#endif
