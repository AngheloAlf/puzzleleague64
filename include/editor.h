#ifndef EDITOR_H
#define EDITOR_H

#include "ultra64.h"
#include "unk.h"

struct struct_gInfo_unk_00068;


// void func_8002F2F0_usa();
// void editTick();

void DrawEditor(struct struct_gInfo_unk_00068 *pDynamic);
void DoEditor(void);
void InitEditor(void);

void editDrawImage(Gfx **gfxP, s32 arg1, s32 nTag);

#endif
