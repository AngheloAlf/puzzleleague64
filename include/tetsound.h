#ifndef TETSOUND_H
#define TETSOUND_H

#include "ultra64.h"
#include "unk.h"
#include "the_game.h"

void InitGameAudioSystem(void);
void SetSoundOptions(s16 arg0);
UNK_RET func_800040D8_usa(UNK_TYPE arg0, UNK_TYPE arg1, UNK_TYPE arg2);
s32 PlayGameSong(tetWell *game);
// void func_80004848_usa();
// void func_8000486C_usa();
// void func_800048C0_usa();
// void func_80004B9C_usa();
// void func_80004E10_usa();
// void func_80005018_usa();
// void func_800050C0_usa();

#endif
