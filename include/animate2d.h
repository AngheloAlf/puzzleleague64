#ifndef ANIMATE2D_H
#define ANIMATE2D_H

#include "ultra64.h"
#include "unk.h"
#include "other_types.h"

#include "animate.h"

struct cursor_t;
struct tetWell;

void Input2D(struct tetWell *well, struct cursor_t *cursor, s32 num);
nbool Move2DCursorUp(struct tetWell *well, struct cursor_t *cursor, CursorHoldVal hold);
nbool Move2DCursorDown(struct cursor_t *cursor, CursorHoldVal hold);
nbool Move2DCursorLeft(struct cursor_t *cursor, CursorHoldVal hold);
nbool Move2DCursorRight(struct cursor_t *cursor, CursorHoldVal hold);
nbool Switch2DBlocks(struct tetWell *well, struct cursor_t *cursor, s32 num);
void Update2DSwitching(struct tetWell *well, struct cursor_t *cursor);
void Add2DNewRow(struct tetWell *well, struct cursor_t *cursor, s32 num);

#endif
