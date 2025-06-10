#ifndef ANIMATE3D_H
#define ANIMATE3D_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

// void func_80066770_usa();
s32 Move3DCursorUp(struct tetWell *well, struct cursor_t *cursor, s32 hold);
s32 Move3DCursorDown(struct cursor_t *cursor, s32 hold);
s32 Move3DCursorLeft(struct cursor_t *cursor, s32 hold);
s32 Move3DCursorRight(struct cursor_t *cursor, s32 hold);
s32 Switch3DBlocks(struct tetWell *well, struct cursor_t *cursor, s32 num);
void Update3DSwitching(struct tetWell *well, struct cursor_t *cursor);
void Add3DNewRow(struct tetWell *well, struct cursor_t *cursor, s32 num);

#endif
