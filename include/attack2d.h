#ifndef ATTACK2D_H
#define ATTACK2D_H

#include "ultra64.h"
#include "unk.h"

#include "attack.h"

struct attack_t;
struct cursor_t;
struct tetWell;

void Init2DAttackPosition(struct attack_t *attack, ENUM_TYPE(AttackType, s32) type, s32 num);
void Init2DAttackFace(struct attack_t *attack);
// void Update2DAttackFace();
void Update2DAttack(struct tetWell *well, struct cursor_t *cursor, s32 num);
// void func_80072198_usa();
// void func_800724A4_usa();
void Change2DAttack(struct tetWell *well, struct cursor_t *cursor, s32 num, s32 combo);

#endif
