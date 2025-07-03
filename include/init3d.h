#ifndef INIT3D_H
#define INIT3D_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

void Init3DNewRow(struct tetWell *well);
void Init3DCursor(struct cursor_t *cursor, s32 num);
void Init3DTetrisBlocks(struct tetWell *well, s32 num);
void Init3DTetrisBlocksState(struct tetWell *well);
void Init3DIcons(struct tetWell *well);
void Init3DAttackBlocks(struct tetWell *well);
void Init3DExplosion(struct tetWell *well);
void Init3DText(void);
void Init3DClearLine(struct tetWell* well, struct cursor_t *cursor, s32 num);
// void func_8005DE94_usa();
void Init3DSmallStars(s32 num);
// void func_8005E108_usa();
void Init3DGameOverSmoke(struct tetWell* well, s32 num);
void Init3DMatrixBlocks(void);
s32 Return3DComboTile(s32 combo);
// void func_8005E484_usa();

#endif
