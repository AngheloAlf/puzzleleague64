#ifndef BONUS_H
#define BONUS_H

#include "ultra64.h"
#include "the_game.h"
#include "unk.h"


void InitBonus(void);
void DoBonus(void);
void DrawBonus(struct_gInfo_unk_00068 *arg0);
s32 DoWatchMenu(void);
// void func_800322D0_usa();
// void func_80032318_usa();
// void func_80032494_usa();
// void func_800325F8_usa();
void DoCountDown();
void DrawCountDown(void);
void InitStageClearIntro(void);
void DoStageClearIntro();
void func_80034140_usa(Gfx **gfxP, s32 arg1, s32 arg2);
void DrawStageClearIntro(struct_gInfo_unk_00068 *arg0);

#endif
