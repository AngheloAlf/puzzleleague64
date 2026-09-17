#ifndef END_H
#define END_H

#include "ultra64.h"

#include "other_types.h"

struct cursor_t;
struct struct_gInfo_unk_00068;
struct tetWell;

void GameOverSmoke(struct tetWell *well);
void DeadBlocksShakeOne2D(struct tetWell *well);
void AllDeadBlocks(struct tetWell *well);
void AllDeadFaces(struct tetWell *well);
// void func_80037900_usa();
void KillRow3D(struct tetWell *well, struct cursor_t *cursor);
void GameOverSign(struct tetWell *well, struct cursor_t *cursor);
s32 EndingExplosion(struct tetWell *well);
// void func_80038018_usa();
void ChangeDeadFace(struct tetWell *well);
void DropRow3D(struct tetWell *well, struct cursor_t *cursor, s32 num);
// void func_8003837C_usa();
// void func_8003853C_usa();
// void func_800386D4_usa();
// void func_800387AC_usa();
void SmallStars(void);
nbool CircleStars(void);
// void func_80038B98_usa();
s32 DoGameOverTryAgain(void);
// void func_80038F84_usa();
s32 func_8003901C_usa(struct tetWell *well);
// void func_8003991C_usa();
void func_80039A54_usa(s32 chain_flag);
void func_80039B78_usa(void);
// void func_80039DB0_usa();
s32 func_8003A0B8_usa(void);
void Draw2DGameOver(struct struct_gInfo_unk_00068 *arg0);
void Draw3DGameOver(struct struct_gInfo_unk_00068 *arg0);
void DrawGameOver(struct struct_gInfo_unk_00068 *arg0);
void DoGameOver2D(void);
void DoGameOver3D(void);
void DoGameOver(void);
void SaveRom(void);

#endif
