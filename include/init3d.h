#ifndef INIT3D_H
#define INIT3D_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

void Init3DNewRow(struct tetWell *well);
void Init3DCursor(struct cursor_t *cursor, s32 num);
void Init3DTetrisBlocks(struct tetWell *well);
void Init3DTetrisBlocksState(struct tetWell *well);
void Init3DIcons(struct tetWell *well);
void Init3DAttackBlocks(struct tetWell *well);
void Init3DExplosion(struct tetWell *well);
// void func_8005DE28_usa();
// void func_8005DE58_usa();
// void func_8005DE94_usa();
// void func_8005E0E8_usa();
// void func_8005E108_usa();
// void func_8005E128_usa();
// void func_8005E2DC_usa();
void Init3DMatrixBlocks(void);
// void func_8005E3F4_usa();
// void func_8005E484_usa();

#endif
