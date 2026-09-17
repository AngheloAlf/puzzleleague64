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
void func_8005DE94_usa(const u16 arg0[], s32 arg1);
void Init3DSmallStars(s32 num);
void Init3DCircleStars(s32 num, s32 pos);
void Init3DGameOverSmoke(struct tetWell* well, s32 num);
void Init3DMatrixBlocks(void);
s32 Return3DComboTile(s32 combo);
s32 Return3DChainTile(s32 chain);

#endif
