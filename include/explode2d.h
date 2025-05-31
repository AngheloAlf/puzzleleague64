#ifndef EXPLODE2D_H
#define EXPLODE2D_H

#include "ultra64.h"

#include "unk.h"

struct tetWell;

void Start2DExplosion(struct tetWell *well, s32 row, s32 col, s32 type);
// void func_80072FDC_usa();
// void func_800730B0_usa();
// void func_80073138_usa();
// void func_8007320C_usa();
// void func_800733D0_usa();
void Update2DExplosion(struct tetWell * well);

#endif