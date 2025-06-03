#ifndef EXPLODE2D_H
#define EXPLODE2D_H

#include "ultra64.h"

struct explode_t;
struct tetWell;

void Start2DExplosion(struct tetWell *well, s32 row, s32 col, s32 type);
void Start2DExBlosion(struct tetWell *well, s32 row, s32 col, s32 type);
void Start2DIconSplash(struct tetWell *well, s32 x, s32 y);
// void func_80073138_usa(explode_t *explode);
void Update2DExplode2(struct explode_t *explode);
// void func_800733D0_usa(explode_t *explode);
void Update2DExplosion(struct tetWell * well);

#endif