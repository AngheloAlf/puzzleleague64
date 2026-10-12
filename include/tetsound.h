#ifndef TETSOUND_H
#define TETSOUND_H

#include "ultra64.h"
#include "unk.h"
#include "other_types.h"

struct tetWell;

void InitGameAudioSystem(void);
void SetSoundOptions(s16 settings);
s32 LoadFairySoundData(s16 music, s16 fairy1, s16 fairy2);
s32 PlayGameSong(struct tetWell *well);
s32 func_80004848_usa(s32 arg0);
s32 PlayGameMusicTest(s32 song_index);
// void func_800048C0_usa();
nbool func_80004B9C_usa(s32 arg0);
nbool func_80004E10_usa(s32 arg0);
void func_80005018_usa(s32 arg0, s32 *arg1);
void func_800050C0_usa(s32 arg0, s32 *arg1);

#endif
