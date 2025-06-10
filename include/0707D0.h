#ifndef _0707D0_H
#define _0707D0_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

// combo2d.c
// void func_8006FBD0_usa();
// void func_8006FC50_usa();

// animate2d.c
// void func_8006FF90_usa();
s32 Move2DCursorUp(struct tetWell *well, struct cursor_t *cursor, s32 hold);
s32 Move2DCursorDown(struct cursor_t *cursor, s32 hold);
s32 Move2DCursorLeft(struct cursor_t *cursor, s32 hold);
s32 Move2DCursorRight(struct cursor_t *cursor, s32 hold);
s32 Switch2DBlocks(struct tetWell *well, struct cursor_t *cursor, s32 num);
void Update2DSwitching(struct tetWell *well, struct cursor_t *cursor);
void Add2DNewRow(struct tetWell *well, struct cursor_t *cursor, s32 num);

#endif
