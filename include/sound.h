#ifndef SOUND_H
#define SOUND_H

#include "libultra.h"
#include "libmus.h"
#include "unk.h"
#include "other_types.h"


void func_80001B10_usa(void);
void func_80001CAC_usa(RomOffset segmentRom, void *dstAddr, size_t segmentSize);
s16 func_80001D60_usa(s32 arg0, u16 arg1);
s16 func_80001E98_usa(musHandle handle);
s16 func_80001ED8_usa(void);
s16 IsTuneBufferFree(s32 index);
void func_80001F40_usa(void *arg0, s16 index);
void func_80001F68_usa(void *arg0, s16 index);
void func_80001F90_usa(RomOffset segmentRom, size_t segmentSize, s16 index);
int func_80002054_usa(void);
void func_8000222C_usa(void);
void LoadSFXBank(s32 arg0, s32 arg1);
// void func_80002620_usa();
// void func_80002684_usa();
// void func_80002694_usa();
// void func_800026A0_usa();
// void func_800026C0_usa();
// void func_8000272C_usa();
void func_8000274C_usa(void);
void func_800027FC_usa(void);
void SetAudioSystemMixer(s16 arg0);
void *func_800028B8_usa(s32 index);
void func_800028D8_usa(s32 arg0);
s32 func_80002A10_usa(s32 arg0);
// void func_80002AE8_usa();
int func_80002C50_usa(musHandle handle);
int FadeOutTuneBuffer(s32 index, int speed);
int FadeOutSong(musHandle handle, int speed);
s16 func_80002CE0_usa(musHandle handle);
// void func_80002D04_usa();
// void func_80002D30_usa();
void func_80002D5C_usa(void);
void func_80002D8C_usa(s16 speed);
void func_80002DE8_usa(void);
void func_80002E0C_usa(s16 speed);
void func_80002E34_usa(s32 volume);
void func_80002E70_usa(s32 volume);
// void func_80002EB8_usa();
int SetSongTempo(musHandle handle, int tempo);
int func_80002F68_usa(musHandle handle, int pan);
// void func_80002F88_usa();
void SetSongCrossFadeVolume(s16 arg0, s16 arg1);
// void func_80002FD0_usa();
void func_80003054_usa(s16 arg0, s16 arg1, s16 arg2, s32 arg3);
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
void func_80003760_usa(s16 arg0, s16 arg1, s16 arg2);
// void func_800037A8_usa();
// void func_800037E8_usa();
// void func_800038E4_usa();
void AudioUpdate();
// void func_80003CE8_usa();
// void func_80003E00_usa();



extern musHandle last_song_handle;

#endif
