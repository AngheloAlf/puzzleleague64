#ifndef SFXLIMIT_H
#define SFXLIMIT_H

#include "ultra64.h"
#include "libmus/libmus.h"
#include "unk.h"

typedef struct SongInitStruct {
    /* 0x0 */ u8 bankRef;
    /* 0x1 */ u8 vol;
    /* 0x2 */ u8 pan;
    /* 0x3 */ u8 tempo;
} SongInitStruct; // size = 0x4

typedef struct SfxInitStruct {
    /* 0x0 */ u8 bankRef;
    /* 0x2 */ s16 sfxRef;
    /* 0x4 */ u8 vol;
    /* 0x5 */ u8 pan;
    /* 0x6 */ u8 priority;
    /* 0x8 */ f32 pitch;
} SfxInitStruct; // size = 0xC


s32 PlayMIDI(SongInitStruct bgmArray[], s32 songIndex, s32 songBuffer, s32 crossfade);
musHandle PlaySE(SfxInitStruct *sfxArray, s32 sfxIndex);
void func_80005270_usa(s32 arg0, s32 arg1, s32 arg2);
// void func_8000541C_usa();
void func_80005608_usa(s32 arg0, s32 arg1);
void func_80005780_usa(s32 arg0);
void func_80005888_usa(s32 arg0, s32 arg1, s32 arg2);
// void func_80005A08_usa();
void SetMIDIParam(musHandle handle, SongInitStruct bgmArray[], s32 songIndex, s32 songBuffer);


extern SongInitStruct BGM_INIT_TABLE[];
extern SfxInitStruct SFX_INIT_TABLE[];

#endif
