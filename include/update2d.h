#ifndef UPDATE2D_H
#define UPDATE2D_H

#include "ultra64.h"

struct cursor_t;
struct tetWell;

void Update2DDistance(struct tetWell *well, struct cursor_t *cursor);
// void func_800710CC_usa();
void Update2DIcon(struct tetWell *well, struct cursor_t *cursor, s32 num);

#endif
