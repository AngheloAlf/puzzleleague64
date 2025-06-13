#ifndef UPDATE3D_H
#define UPDATE3D_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

void Update3DDistance(struct tetWell *well, struct cursor_t *cursor);
void Update3DPosition(struct tetWell *well, struct cursor_t *cursor, s32 flag);
void Update3DCursor(struct tetWell *well, struct cursor_t *cursor);
// void func_80067860_usa();
void Check3DVisibleBlocks(struct tetWell *well, struct cursor_t *cursor);

#endif
