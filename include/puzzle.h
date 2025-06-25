#ifndef PUZZLE_H
#define PUZZLE_H

#include "ultra64.h"
#include "unk.h"

struct cursor_t;
struct tetWell;
struct struct_gInfo_unk_00068;

// void func_80088940_usa();
// void func_80088A48_usa();
s32 Init2DPuzzle(struct tetWell *well, struct cursor_t *cursor, u8 *ptr, s32 number);
// void func_80088C08_usa();
s32 Init3DPuzzle(struct tetWell *well, struct cursor_t *cursor, u8 *ptr, s32 number);
// void func_80088E38_usa();
// void func_80088F94_usa();
// void func_80089108_usa();
s32 func_8008913C_usa(s32 arg0);
// void func_80089200_usa();
// void func_8008928C_usa();
void InitPuzzleEditor(s32 arg0);
void DoPuzzleEditor(void);
void DrawPuzzleEditor(struct struct_gInfo_unk_00068 *arg0);

#endif
