#ifndef SFXLIMIT_H
#define SFXLIMIT_H

#include "libultra.h"
#include "libmus.h"
#include "unk.h"

typedef struct struct_bgm_init_table {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 unk_1;
    /* 0x2 */ u8 pan;
    /* 0x3 */ u8 tempo;
} struct_bgm_init_table; // size = 0x4

typedef struct struct_sfx_init_table {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ UNK_TYPE1 unk_1[0x1];
    /* 0x2 */ s16 number;
    /* 0x4 */ u8 volume;
    /* 0x5 */ u8 pan;
    /* 0x6 */ UNK_TYPE1 unk_6[0x2];
    /* 0x8 */ f32 offset;
} struct_sfx_init_table; // size = 0xC


s32 PlayMIDI(struct_bgm_init_table arg0[], s32 arg1, s32 arg2, s32 arg3);
musHandle PlaySE(struct_sfx_init_table *arg0, s32 arg1);
// void func_80005270_usa();
// void func_8000541C_usa();
// void func_80005608_usa();
// void func_80005780_usa();
// void func_80005888_usa();
// void func_80005A08_usa();
void SetMIDIParam(s32 arg0, struct_bgm_init_table arg1[], s32 arg2, s32 arg3);


extern struct_bgm_init_table BGM_INIT_TABLE[];
extern struct_sfx_init_table SFX_INIT_TABLE[];

#endif
