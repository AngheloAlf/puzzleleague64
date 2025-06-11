#ifndef COMBO_H
#define COMBO_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

void CheckCollision(struct tetWell *well);
void CompactWell(struct tetWell *well, s32 num);
void CheckIcon(struct tetWell *well, s32 total);
void CheckRowCombos(struct tetWell *well);
void CheckColCombos(struct tetWell *well);
void SetRowState(struct tetWell *well, s32 count, s32 row, s32 col);
void SetColState(struct tetWell *well, s32 count, s32 row, s32 col);
void CheckChainCounter(struct tetWell *well, struct cursor_t *cursor);
s32 ComboCount(struct tetWell *well, struct cursor_t *cursor);

#endif
