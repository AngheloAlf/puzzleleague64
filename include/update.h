#ifndef UPDATE_H
#define UPDATE_H

#include "ultra64.h"
#include "unk.h"

#include "other_types.h"

struct cursor_t;
struct tetWell;
struct struct_gInfo;

// void UpdateBlockFrame();
void UpdateTime(s32 second);
void UpdateNextLevel(struct tetWell *well);
void UpdateRaiseTimer(struct tetWell *well);
void UpdateComboScore(struct tetWell *well, struct cursor_t *cursor, s32 combo);
void UpdateChainScore(struct tetWell *well, struct cursor_t *cursor, s32 chain);
// void func_80057EB8_usa();
// void func_80057F84_usa();
// void func_8005806C_usa();
// void func_80058168_usa();
// void func_8005825C_usa();
// void func_8005834C_usa();
// void func_80058458_usa();
// void UpdatePlayerPuzzle();
nbool CheckPlayerPuzzleRound(s32 game, s32 stage);
nbool PlayPlayerPuzzleEnding(s32 game, s32 stage);
void UpdatePlayerStageClear(struct cursor_t *cursor, s32 round, s32 stage);
void UpdatePlayerStageClearTimeScore(struct cursor_t *cursor, s32 loadsave, s32 round, s32 stage);
void UpdatePlayerCPU(s32 game, s32 stage);
void UpdateComboChainCount(s32 num, s32 combo, s32 total);
void UpdateWell(struct tetWell *well, struct cursor_t *cursor, s32 num, s32 total);
void UpdateCursor(struct tetWell *well, struct cursor_t *cursor);
void UpdateIcon(struct tetWell *well, struct cursor_t *cursor, s32 num);
void UpdateDistance(struct tetWell *well, struct cursor_t *cursor);
void UpdateMainState(void);
void UpdateBuffer(struct struct_gInfo *info);
void Update2DBuffer(struct struct_gInfo *info);
void Update3DBuffer(struct struct_gInfo *info);

#endif
