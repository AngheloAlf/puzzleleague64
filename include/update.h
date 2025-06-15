#ifndef UPDATE_H
#define UPDATE_H

#include "ultra64.h"
#include "unk.h"
#include "the_game.h"

struct cursor_t;
struct tetWell;

// void func_80057650_usa();
void UpdateTime(s32 second);
void UpdateNextLevel(struct tetWell * well);
// void func_80057D1C_usa();
// void func_80057D68_usa();
// void func_80057E10_usa();
// void func_80057EB8_usa();
// void func_80057F84_usa();
// void func_8005806C_usa();
// void func_80058168_usa();
// void func_8005825C_usa();
// void func_8005834C_usa();
// void func_80058458_usa();
// void UpdatePlayerPuzzle();
// void func_800587CC_usa();
// void func_80058934_usa();
// void UpdatePlayerStageClear();
void UpdatePlayerStageClearTimeScore(cursor_t *cursor, s32 loadsave, s32 round, s32 stage);
// void func_80058D68_usa();
void UpdateComboChainCount(s32 num, s32 combo, s32 total);
void UpdateWell(struct tetWell *well, struct cursor_t *cursor, s32 num, s32 total);
void UpdateCursor(struct tetWell *well, struct cursor_t *cursor);
void UpdateIcon(struct tetWell *well, struct cursor_t *cursor, s32 num);
void UpdateDistance(struct tetWell *well, struct cursor_t *cursor);
void UpdateMainState(void);
void UpdateBuffer(struct_gInfo *info);
void Update2DBuffer(struct_gInfo *info);
void Update3DBuffer(struct_gInfo *info);

#endif
