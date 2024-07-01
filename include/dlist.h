#ifndef DLIST_H
#define DLIST_H

#include "ultra64.h"
#include "unk.h"
#include "the_game.h"


// void func_80054020_usa();
void SetGameFade(void);
// void func_8005407C_usa();
// void func_800540AC_usa();
void Draw2DGameFade(void);
// void func_80054320_usa();
// void func_8005443C_usa();
s32 DoFlashDraw(s32 arg0);
// void func_800544D4_usa();
// void func_80054500_usa();
void func_800545E4_usa(s32 arg0);
// void func_80054624_usa();
void InitTetrisState(TheGame_unk_0000_unk_0000_unk_000_unk_000 *arg0);
void InitDisplayList(struct_gInfo *info);
// void func_800549A4_usa();
// void InitGameStateVar();
// void func_800552F4_usa();

#endif
