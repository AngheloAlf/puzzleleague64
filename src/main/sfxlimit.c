/**
 * Original filename: sfxlimit.c
 */

#include "sfxlimit.h"
#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "sound.h"

extern s32 B_801AB7E0_usa;
extern s32 B_801C7154_usa;
extern s32 B_8021B960_usa;
extern struct_bgm_init_table *B_8021BA7C_usa;
extern s32 B_8021DF48_usa;

#if VERSION_USA
s32 PlayMIDI(struct_bgm_init_table arg0[], s32 arg1, s32 arg2, s32 arg3) {
    if (arg1 < 0) {
        B_801C7154_usa = 0;
        return 0;
    }

    B_8021BA7C_usa = &arg0[arg1];
    B_8021B960_usa = arg1;
    B_801AB7E0_usa = arg2;
    B_8021DF48_usa = arg3;
    B_801C7154_usa = 1;
    return 0;
}
#endif

#if VERSION_USA
musHandle PlaySE(struct_sfx_init_table *arg0, s32 arg1) {
    struct_sfx_init_table *temp_s0;

    if (B_801C6EF6_usa <= 327.67) {
        return 0;
    }

    temp_s0 = &arg0[arg1];

    func_80002620_usa(temp_s0->unk_0);

    if (arg1 == 1) {
        PlaySFX(temp_s0->number, 1, 0x7F);
    }

    PlaySFX(temp_s0->number, temp_s0->volume, temp_s0->pan);

    if (temp_s0->offset != 0.0f) {
        SetFrequencySFX(D_800B3ADC_usa, temp_s0->offset);
    }

    func_80002620_usa(0);

    return D_800B3ADC_usa;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_80005270_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_8000541C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_80005608_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_80005780_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_80005888_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_80005A08_usa);
#endif

#if VERSION_USA
void SetMIDIParam(s32 arg0, struct_bgm_init_table arg1[], s32 arg2, s32 arg3) {
    struct_bgm_init_table *temp_s0 = &arg1[arg2];

    if (func_80002CE0_usa(arg0) != 0) {
        SetSongCrossFadeVolume(temp_s0->unk_1, arg3);
        func_80002F68_usa(last_song_handle, temp_s0->pan);
        SetSongTempo(last_song_handle, temp_s0->tempo);
    }
}
#endif
