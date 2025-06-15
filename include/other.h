#ifndef OTHER_H
#define OTHER_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct struct_gInfo_unk_00068;
struct tetWell;

void InitMiscStuff(void);
void UpdateMiscStuff(struct tetWell *well, struct cursor_t *cursor, s32 num);
void Draw2DMiscStuff(struct struct_gInfo_unk_00068 *dynamicp);
// void func_80053140_usa();
// void func_80053E64_usa();

#endif
