#ifndef ATTACK2D_H
#define ATTACK2D_H

#include "ultra64.h"
#include "unk.h"

struct attack_t;
struct cursor_t;
struct tetWell;

void Init2DAttackPosition(struct attack_t *attack, s32 type, s32 num);
// void func_8007194C_usa();
// void func_8007197C_usa();
void Update2DAttack(struct tetWell *well, struct cursor_t *cursor, s32 num);
// void func_80072198_usa();
// void func_800724A4_usa();
void Change2DAttack(struct tetWell *well, struct cursor_t *cursor, s32 num, s32 combo);

#endif
