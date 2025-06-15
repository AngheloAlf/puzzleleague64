#ifndef TETSOUND_H
#define TETSOUND_H

#include "ultra64.h"
#include "unk.h"

struct tetWell;

void InitGameAudioSystem(void);
void SetSoundOptions(s16 arg0);
s32 LoadFairySoundData(s16 arg0, s16 arg1, s16 arg2);
s32 PlayGameSong(struct tetWell *well);
// void func_80004848_usa();
// void func_8000486C_usa();
// void func_800048C0_usa();
// void func_80004B9C_usa();
// void func_80004E10_usa();
// void func_80005018_usa();
// void func_800050C0_usa();

#endif
