#ifndef SOUND_H
#define SOUND_H

#include "ultra64.h"
#include "libc/stdbool.h"
#include "libmus/libmus.h"
#include "other_types.h"
#include "unk.h"

struct song_t;

typedef void (struct_8018A748_usa_callback)(musHandle, s32);

void func_80001B10_usa(void);
void DmaRomToRam(RomOffset segmentRom, void *dstAddr, size_t segmentSize);
s16 func_80001D60_usa(s32 arg0, s16 arg1);
s16 func_80001E98_usa(musHandle handle);
s16 func_80001ED8_usa(void);
s16 IsTuneBufferFree(s32 index);
void func_80001F40_usa(struct song_t *arg0, s16 index);
void func_80001F68_usa(void *arg0, s16 index);
void func_80001F90_usa(RomOffset segmentRom, size_t segmentSize, s16 index);
int func_80002054_usa(void);
void func_8000222C_usa(void);
void *LoadSFXBank(u16 arg0, u16 arg1);
void func_80002620_usa(s16 arg0);
bool func_80002684_usa(void);
s16 func_80002694_usa(s32 arg0, s16 arg1);
// void func_800026A0_usa();
void func_800026C0_usa(s32 arg0);
int func_8000272C_usa(musHandle handle, int speed);
void func_8000274C_usa(void);
void func_800027FC_usa(void);
void SetAudioSystemMixer(s16 arg0);
struct song_t *func_800028B8_usa(s32 index);
void func_800028D8_usa(s32 arg0);
s32 func_80002A10_usa(s32 arg0);
musHandle func_80002AE8_usa(s32 index, s32 volscale, s32 panscale, s32 temscale);
int func_80002C50_usa(musHandle handle);
int FadeOutTuneBuffer(s32 index, int speed);
int FadeOutSong(musHandle handle, int speed);
s16 func_80002CE0_usa(musHandle handle);
s16 func_80002D04_usa(void);
s16 func_80002D30_usa(void);
void func_80002D5C_usa(void);
void func_80002D8C_usa(s16 speed);
void func_80002DE8_usa(void);
void FadeOutAllSFXs(s16 speed);
void func_80002E34_usa(s32 volume);
void func_80002E70_usa(s32 volume);
void func_80002EB8_usa(musHandle arg0, s32 arg1);
int SetSongTempo(musHandle handle, int tempo);
int func_80002F68_usa(musHandle handle, int pan);
void func_80002F88_usa(s16 arg0);
void SetSongCrossFadeVolume(s16 arg0, s16 arg1);
void FadeSong(musHandle handle, s16 arg1, s16 arg2, struct_8018A748_usa_callback *arg3);
void func_80003054_usa(s16 arg0, s16 arg1, s16 arg2, struct_8018A748_usa_callback *callback);
int func_800030D0_usa(musHandle handle, int speed);
void func_800030F0_usa(void);
musHandle PlaySFX(int number, int volume, int pan);
int func_8000337C_usa(musHandle handle, int speed);
int func_8000339C_usa(musHandle handle, int speed);
int SetFrequencySFX(musHandle handle, float offset);
int func_800033DC_usa(musHandle handle, s16 arg1, s16 arg2);
int func_80003458_usa(musHandle handle, int volume);
int func_80003484_usa(musHandle handle, int pan);
s16 func_800034B4_usa(f32 arg0, f32 arg1);
s32 func_800034EC_usa(f32 arg0);
musHandle func_8000353C_usa(int number, f32 arg1, f32 arg2, f32 arg3);
bool func_800036D0_usa(musHandle handle);
s16 func_800036F0_usa(s16 arg0, s32 arg1);
void func_80003760_usa(s16 arg0, s16 arg1, s16 arg2);
s32 func_800037A8_usa(s16 arg0, s32 arg1);
void func_800037E8_usa(void);
void func_800038E4_usa(void);
void AudioUpdate(void);
void func_80003CE8_usa(u16 arg0);
void func_80003E00_usa(s32 arg0, s32 arg1);


// extern UNK_TYPE D_800B3AD0_usa;
// extern UNK_TYPE D_800B3AD2_usa;
// extern UNK_TYPE D_800B3AD4_usa;
extern musHandle last_song_handle;
extern musHandle D_800B3ADC_usa;
// extern UNK_TYPE D_800B3AE0_usa;
// extern UNK_TYPE D_800B3AE4_usa;
// extern UNK_TYPE D_800B3AE6_usa;
// extern UNK_TYPE D_800B3AE8_usa;
// extern UNK_TYPE D_800B3AEC_usa;
// extern UNK_TYPE D_800B3AF0_usa;
// extern UNK_TYPE D_800B3AF4_usa;
extern s16 D_800B3AF8_usa;
// extern UNK_TYPE D_800B3AFA_usa;
// extern UNK_TYPE D_800B3AFC_usa;
// extern UNK_TYPE D_800B3AFE_usa;
// extern UNK_TYPE D_800B3B00_usa;


extern u16 B_8021B968_usa;

#endif
