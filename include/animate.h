#ifndef ANIMATE_H
#define ANIMATE_H

#include "ultra64.h"
#include "unk.h"
#include "other_types.h"

struct block_t;
struct cursor_t;
struct tetWell;

typedef enum CursorHoldVal {
    /*  0 */ CURSOR_HOLD_VAL_0,
// TODO REGION_NTSC?
#if VERSION_USA
    /* 10 */ CURSOR_HOLD_VAL_10 = 10,
#else
    /* 10 */ CURSOR_HOLD_VAL_10 = 8,
#endif
} CursorHoldVal;

void CheckGameInput(struct tetWell *well, struct cursor_t *cursor, s32 num);
void AddNewRow(struct tetWell *well, struct cursor_t *cursor, s32 num);
void RaiseBlocks(struct tetWell *well, struct cursor_t *cursor);
void AfterSwitch(struct tetWell *well, struct cursor_t *cursor, struct block_t *block1, struct block_t *block2, s32 dimen);
void CheckShake(struct tetWell *well, struct cursor_t *cursor);
nbool CheckFieldActive(struct tetWell *well);
// void func_8005731C_usa();

#endif
