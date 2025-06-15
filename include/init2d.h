#ifndef INIT2D_H
#define INIT2D_H

#include "ultra64.h"
#include "gs2dex.h"
#include "unk.h"

struct attack_t;
struct cursor_t;
struct block_t;
struct tetWell;

void Init2DNewRow(struct tetWell *well);
void Init2DCursor(struct cursor_t *cursor, s32 num);
void Init2DTetrisBlocks(struct tetWell *well, s32 num);
void Init2DTetrisBlocksTMEM(struct tetWell *well, s32 clear);
void Init2DIcons(struct tetWell *well);
void Init2DAttackBlocks(struct tetWell * well);
void Init2DExplosion(struct tetWell *well);
// void func_8006B798_usa();
// void func_8006C0E0_usa();
// void func_8006C204_usa();
void Init2DSmallStars(s32 num);
// void func_8006C7A0_usa();
void Init2DGameOverSmoke(struct tetWell *well, s32 num);
void Init2DTetrisTMEM(struct block_t *block, uObjSprite *rect);
// void func_8006CB30_usa();
// void func_8006CBEC_usa();
void Init2DAttackTMEM(uObjSprite *rect, s32 type, s32 lev, s32 pos);
void Init2DBrickTMEM(struct attack_t *attack);
// void func_8006CE14_usa();

#endif
