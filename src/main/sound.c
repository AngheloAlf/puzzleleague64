/**
 * Original filename: sound.c
 */

#include "sound.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "libmus.h"

typedef struct struct_8018A748_usa {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x04 */ UNK_TYPE4 unk_04;
    /* 0x08 */ UNK_TYPE4 unk_08;
    /* 0x0C */ UNK_TYPE4 unk_0C;
    /* 0x10 */ UNK_TYPE4 unk_10;
    /* 0x14 */ UNK_TYPE4 unk_14;
    /* 0x18 */ UNK_TYPE4 unk_18;
    /* 0x1C */ UNK_TYPE2 unk_1C;
    /* 0x1E */ UNK_TYPE1 unk_1E[0x2];
    /* 0x20 */ UNK_TYPE1 unk_20[0x4];
    /* 0x24 */ UNK_TYPE2 unk_24;
    /* 0x26 */ UNK_TYPE2 unk_26;
    /* 0x28 */ UNK_TYPE4 unk_28;
    /* 0x2C */ UNK_TYPE4 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ UNK_TYPE4 unk_34;
} struct_8018A748_usa; // size = 0x38

extern struct_8018A748_usa B_8018A748_usa[2];

extern s32 B_800CF2A0_usa;
extern s32 D_800B3AEC_usa;

extern s16 B_801C6EF6_usa;

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80001D60_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80001E98_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80001ED8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", IsTuneBufferFree);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80001F40_usa);
#endif

#if VERSION_USA
#if 0
extern ? B_8018A750_usa;

void func_80001F68_usa(s32 arg0, s16 arg1) {
    *(&B_8018A750_usa + (arg1 * 0x38)) = arg0;
}
#endif
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80001F68_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80001F90_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002054_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000222C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", LoadSFXBank);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002620_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002684_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002694_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800026A0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800026C0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000272C_usa);
#endif

#if VERSION_USA
#if 0
extern UNK_TYPE B_8016F2B0_usa;
extern s32 B_8018A6B0_usa;
extern s32 B_8018A6B4_usa;

void func_8000274C_usa(void) {
    s16 var_a1;

    for (var_a1 = 0; var_a1 < 2; var_a1++) {
        B_8018A748_usa[var_a1].unk_04 = 0;
        B_8018A748_usa[var_a1].unk_08 = &B_8016F2B0_usa;
        B_8018A748_usa[var_a1].unk_10 = 0;
        B_8018A748_usa[var_a1].unk_14 = 0;
        B_8018A748_usa[var_a1].unk_18 = 0;
        B_8018A748_usa[var_a1].unk_1C = 0;
        B_8018A748_usa[var_a1].unk_24 = 0;
    }

    B_8018A748_usa[0].unk_0C = B_8018A6B0_usa;
    B_8018A748_usa[1].unk_0C = B_8018A6B4_usa;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000274C_usa);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800027FC_usa);
#endif

#if VERSION_USA
void SetAudioSystemMixer(s16 arg0) {
    if (!arg0) {
        D_800B3AF8_usa = 0;
    } else {
        D_800B3AF8_usa = 1;
    }
}
#endif

#if VERSION_USA
#if 0
extern ? B_8018A754_usa;

s32 func_800028B8_usa(s32 arg0) {
    return *(&B_8018A754_usa + (arg0 * 0x38));
}
#endif
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800028B8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800028D8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002A10_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002AE8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002C50_usa);
#endif

#if VERSION_USA
#if 0
extern ? B_8018A74C_usa;

s32 FadeOutTuneBuffer(s32 arg0, s32 arg1) {
    return MusHandleStop(*(&B_8018A74C_usa + (arg0 * 0x38)), arg1);
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", FadeOutTuneBuffer);
#endif
#endif

#if VERSION_USA
int FadeOutSong(musHandle handle, int speed) {
    D_800B3AEC_usa = -1;
    return MusHandleStop(handle, speed);
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002CE0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002D04_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002D30_usa);
#endif

#if VERSION_USA
void func_80002D5C_usa(void) {
    D_800B3AEC_usa = -1;
    MusStop(MUSFLAG_SONGS, 0);
}
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/sound", RO_STR_800C2FD8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/sound", RO_STR_800C2FF0_usa);
#endif

#if VERSION_USA
void func_80002D8C_usa(s16 speed) {
    if (B_800CF2A0_usa < 327.67) {
        speed = 0;
    }
    D_800B3AEC_usa = -1;
    MusStop(MUSFLAG_SONGS, speed);
}
#endif

#if VERSION_USA
void func_80002DE8_usa(void) {
    MusStop(MUSFLAG_EFFECTS, 0);
}
#endif

#if VERSION_USA
void func_80002E0C_usa(s16 speed) {
    MusStop(MUSFLAG_EFFECTS, speed);
}
#endif

#if VERSION_USA
void func_80002E34_usa(s32 volume) {
    s32 var_s0 = volume;

    if (var_s0 > 0x7FFFU) {
        var_s0 = 0x7FFF;
    }
    B_800CF2A0_usa = var_s0;
    MusSetMasterVolume(MUSFLAG_SONGS, B_800CF2A0_usa);
}
#endif

#if VERSION_USA
void func_80002E70_usa(s32 volume) {
    s32 var_s0 = volume;

    if (var_s0 > 0x7FFFU) {
        var_s0 = 0x7FFF;
    }
    MusSetMasterVolume(MUSFLAG_EFFECTS, var_s0);
    B_801C6EF6_usa = var_s0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002EB8_usa);
#endif

#if VERSION_USA
int SetSongTempo(musHandle handle, int tempo) {
    return MusHandleSetTempo(handle, tempo);
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002F68_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002F88_usa);
#endif

#if VERSION_USA
#if 0
extern ? B_8018A76E_usa;
extern ? D_800B3AFC_usa;

void func_80002F98_usa(s16 arg0, s16 arg1) {
    *(&B_8018A76E_usa + (arg1 * 0x38)) = arg0;
    *(&D_800B3AFC_usa + (arg1 * 2)) = arg0;
}
#endif
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002F98_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002FD0_usa);
#endif

#if VERSION_USA
#if 0
extern ? B_8018A770_usa;
extern ? B_8018A774_usa;
extern ? B_8018A77C_usa;
extern ? B_FLT_8018A778_usa;

void func_80003054_usa(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    f32 temp_ft0;
    s32 temp_v0;

    temp_v0 = arg0 * 0x38;
    temp_ft0 = (f32) arg1;
    *(&B_8018A774_usa + temp_v0) = temp_ft0;
    *(&B_8018A77C_usa + temp_v0) = arg3;
    *(&B_FLT_8018A778_usa + temp_v0) = (temp_ft0 - *(&B_8018A770_usa + temp_v0)) / (f32) arg2;
}
#endif
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80003054_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800030D0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800030F0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800032A4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000337C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000339C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800033BC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800033DC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80003458_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80003484_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800034B4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800034EC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000353C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800036D0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800036F0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80003760_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800037A8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800037E8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800038E4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", AudioUpdate);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80003CE8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80003E00_usa);
#endif
