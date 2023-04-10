#ifndef SOUND_H
#define SOUND_H

#include "libultra.h"
#include "unk.h"


// void func_80001D60_usa();
// void func_80001E98_usa();
// void func_80001ED8_usa();
s16 IsTuneBufferFree(s32 arg0);
// void func_80001F40_usa();
// void func_80001F68_usa();
// void func_80001F90_usa();
// void func_80002054_usa();
// void func_8000222C_usa();
void LoadSFXBank(s32 arg0, s32 arg1);
// void func_80002620_usa();
// void func_80002684_usa();
// void func_80002694_usa();
// void func_800026A0_usa();
// void func_800026C0_usa();
// void func_8000272C_usa();
// void func_8000274C_usa();
void func_800027FC_usa(void);
void SetAudioSystemMixer(s32 arg0);
// void func_800028B8_usa();
// void func_800028D8_usa();
// void func_80002A10_usa();
// void func_80002AE8_usa();
// void func_80002C50_usa();
s32 FadeOutTuneBuffer(s32 arg0, s32 arg1);
s32 FadeOutSong(s32 arg0, s32 arg1);
// void func_80002CE0_usa();
// void func_80002D04_usa();
// void func_80002D30_usa();
void func_80002D5C_usa();
// void func_80002D8C_usa();
void func_80002DE8_usa();
void func_80002E0C_usa(s32 arg0);
void func_80002E34_usa(s32 arg0);
void func_80002E70_usa(s32 arg0);
// void func_80002EB8_usa();
UNK_RET SetSongTempo(UNK_TYPE, UNK_TYPE);
// void func_80002F68_usa();
// void func_80002F88_usa();
// void func_80002F98_usa();
// void func_80002FD0_usa();
// void func_80003054_usa();
// void func_800030D0_usa();
// void func_800030F0_usa();
// void func_800032A4_usa();
// void func_8000337C_usa();
// void func_8000339C_usa();
// void func_800033BC_usa();
// void func_800033DC_usa();
// void func_80003458_usa();
// void func_80003484_usa();
// void func_800034B4_usa();
// void func_800034EC_usa();
// void func_8000353C_usa();
// void func_800036D0_usa();
// void func_800036F0_usa();
// void func_80003760_usa();
// void func_800037A8_usa();
// void func_800037E8_usa();
// void func_800038E4_usa();
void AudioUpdate();
// void func_80003CE8_usa();
// void func_80003E00_usa();

#endif
