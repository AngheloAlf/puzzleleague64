#ifndef SIGN_H
#define SIGN_H

#include "ultra64.h"

#include "gs2dex.h"

struct struct_gInfo_unk_00068;
struct tetWell;

void InitPause(void);
void InitGameOver(void);
// void func_8003490C_usa();
void LoadGameOver3D(void);
void DrawPauseOver(struct struct_gInfo_unk_00068 *arg0);
// void func_8003524C_usa();
void AnimateGameOver3D(struct tetWell *well, uObjBg *bg);
// void func_8003536C_usa();
void AnimateLose3D(struct tetWell *well, uObjBg *bg);
// void func_800353F4_usa();
void AnimateWin3D(struct tetWell *well, uObjBg *bg);
// void func_8003547C_usa();
void AnimateDraw3D(struct tetWell *well, uObjBg *bg);
void AnimatePauseKey(uObjBg *bg);
void AnimatePushKey(uObjBg *bg);
// void func_800355EC_usa();

#endif
