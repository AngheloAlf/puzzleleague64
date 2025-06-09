#ifndef COMBO_H
#define COMBO_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

void CheckCollision(struct tetWell *well);
void CompactWell(struct tetWell *well, s32 num);
void CheckIcon(struct tetWell *well, s32 total);
// void func_8005600C_usa();
// void func_80056180_usa();
// void func_800562FC_usa();
// void func_800564E0_usa();
void CheckChainCounter(struct tetWell *well, struct cursor_t *cursor);
s32 ComboCount(struct tetWell *well, struct cursor_t *cursor);

#endif
