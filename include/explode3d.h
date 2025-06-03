#ifndef EXPLODE3D_H
#define EXPLODE3D_H

#include "ultra64.h"

#include "unk.h"

struct tetWell;

void Start3DExplosion(struct tetWell *well, s32 num, s32 row, s32 col, s32 type);
void Start3DExBlosion(struct tetWell *well, s32 num, s32 x, s32 y);
void Start3DIconSplash(struct tetWell *well, s32 num, s32 row, s32 col);
// void func_8006A9EC_usa();
// void func_8006AA88_usa();
// void func_8006AC3C_usa();
void Update3DExplosion(struct tetWell * well);

#endif