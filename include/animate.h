#ifndef ANIMATE_H
#define ANIMATE_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

// void func_80056910_usa();
void AddNewRow(struct tetWell *well, struct cursor_t *cursor, s32 num);
// void func_80056A7C_usa();
// void func_80056BAC_usa();
void CheckShake(struct tetWell *well, struct cursor_t *cursor);
s32 CheckFieldActive(struct tetWell *well);
// void func_8005731C_usa();

#endif
