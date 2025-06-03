#ifndef EXPLODE3D_H
#define EXPLODE3D_H

#include "ultra64.h"

#include "unk.h"

struct tetWell;

void Start3DExplosion(struct tetWell *well, s32 num, s32 row, s32 col, s32 type);
void Start3DExBlosion(struct tetWell *well, s32 num, s32 x, s32 y);
void Start3DIconSplash(struct tetWell *well, s32 num, s32 row, s32 col);
void Update3DExplosion(struct tetWell * well);

#endif