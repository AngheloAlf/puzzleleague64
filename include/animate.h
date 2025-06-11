#ifndef ANIMATE_H
#define ANIMATE_H

#include "ultra64.h"
#include "unk.h"
#include "other_types.h"

struct block_t;
struct cursor_t;
struct tetWell;

// void func_80056910_usa();
void AddNewRow(struct tetWell *well, struct cursor_t *cursor, s32 num);
// void func_80056A7C_usa();
void AfterSwitch(struct tetWell *well, struct cursor_t *cursor, struct block_t *block1, struct block_t *block2, s32 dimen);
void CheckShake(struct tetWell *well, struct cursor_t *cursor);
nbool CheckFieldActive(struct tetWell *well);
// void func_8005731C_usa();

#endif
