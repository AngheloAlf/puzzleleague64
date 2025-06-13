#ifndef ATTACK3D_H
#define ATTACK3D_H

#include "ultra64.h"
#include "unk.h"

struct attack_t;
struct cursor_t;
struct tetWell;

void Init3DAttackPosition(struct attack_t *attack, s32 type, s32 num);
void Set3DRingPosition(struct attack_t *attack);
void Upgrade3DBrick(struct tetWell *well, s32 slot, s32 num);
void Draw3DChain3_CrossBoundary(struct attack_t *attack, s32 * begin, s32 * end, s32 * pos);
void Update3DAttack(struct tetWell *well, struct cursor_t *cursor, s32 num);
// void func_80069360_usa();
// void func_80069954_usa();
void Change3DAttack(struct tetWell *well, struct cursor_t *cursor, s32 num, s32 combo);

#endif
