#ifndef ANIMATE2D_H
#define ANIMATE2D_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

void Input2D(struct tetWell *well, struct cursor_t *cursor, s32 num);
s32 Move2DCursorUp(struct tetWell *well, struct cursor_t *cursor, s32 hold);
s32 Move2DCursorDown(struct cursor_t *cursor, s32 hold);
s32 Move2DCursorLeft(struct cursor_t *cursor, s32 hold);
s32 Move2DCursorRight(struct cursor_t *cursor, s32 hold);
s32 Switch2DBlocks(struct tetWell *well, struct cursor_t *cursor, s32 num);
void Update2DSwitching(struct tetWell *well, struct cursor_t *cursor);
void Add2DNewRow(struct tetWell *well, struct cursor_t *cursor, s32 num);

#endif
