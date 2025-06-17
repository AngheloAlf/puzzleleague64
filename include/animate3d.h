#ifndef ANIMATE3D_H
#define ANIMATE3D_H

#include "ultra64.h"
#include "unk.h"
#include "other_types.h"

#include "animate.h"

struct cursor_t;
struct tetWell;

void Input3D(struct tetWell *well, struct cursor_t *cursor, s32 num);
nbool Move3DCursorUp(struct tetWell *well, struct cursor_t *cursor, CursorHoldVal hold);
nbool Move3DCursorDown(struct cursor_t *cursor, CursorHoldVal hold);
nbool Move3DCursorLeft(struct cursor_t *cursor, CursorHoldVal hold);
nbool Move3DCursorRight(struct cursor_t *cursor, CursorHoldVal hold);
nbool Switch3DBlocks(struct tetWell *well, struct cursor_t *cursor, s32 num);
void Update3DSwitching(struct tetWell *well, struct cursor_t *cursor);
void Add3DNewRow(struct tetWell *well, struct cursor_t *cursor, s32 num);

#endif
