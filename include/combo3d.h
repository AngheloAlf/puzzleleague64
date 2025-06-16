#ifndef COMBO3D_H
#define COMBO3D_H

#include "ultra64.h"
#include "unk.h"

struct tetWell;

void Compact3DAttackNoWhere(struct tetWell *well);
void Compact3DAttack(struct tetWell *well, s32 count);
void Check3DConnectCombos(struct tetWell *well);
void Set3DRowConnectState(struct tetWell *well, s32 row, s32 left, s32 right);
// void func_800666F0_usa();

#endif
