#ifndef UPDATE3D_H
#define UPDATE3D_H

#include "ultra64.h"

struct cursor_t;
struct tetWell;

void Update3DDistance(struct tetWell *well, struct cursor_t *cursor);
void Update3DPosition(struct tetWell *well, struct cursor_t *cursor, s32 flag);
void Update3DCursor(struct tetWell *well, struct cursor_t *cursor);
void Update3DIcon(struct tetWell *well, struct cursor_t *cursor, s32 num);
void Check3DVisibleBlocks(struct tetWell *well, struct cursor_t *cursor);

#endif
