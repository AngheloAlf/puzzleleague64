#ifndef END_H
#define END_H

#include "ultra64.h"
#include "unk.h"

struct Game;
struct struct_gInfo_unk_00068;
struct tetWell;

void GameOverSmoke(struct tetWell *well);
void DeadBlocksShakeOne2D(struct tetWell *well);
void AllDeadBlocks(struct tetWell *well);
// void func_80037724_usa();
// void func_80037900_usa();
// void func_800379D4_usa();
// void func_80037B0C_usa();
s32 EndingExplosion(struct Game *the_game);
// void func_80038018_usa();
// void func_8003813C_usa();
// void func_80038228_usa();
// void func_8003837C_usa();
// void func_8003853C_usa();
// void func_800386D4_usa();
// void func_800387AC_usa();
// void func_8003880C_usa();
// void func_80038944_usa();
// void func_80038B98_usa();
s32 DoGameOverTryAgain(void);
// void func_80038F84_usa();
// void func_8003901C_usa();
// void func_8003991C_usa();
// void func_80039A54_usa();
// void func_80039B78_usa();
// void func_80039DB0_usa();
// void func_8003A0B8_usa();
void Draw2DGameOver(struct struct_gInfo_unk_00068 *arg0);
void Draw3DGameOver(struct struct_gInfo_unk_00068 *arg0);
void DrawGameOver(struct struct_gInfo_unk_00068 *arg0);
void DoGameOver2D(void);
void DoGameOver3D(void);
void DoGameOver(void);
void SaveRom(void);

#endif
