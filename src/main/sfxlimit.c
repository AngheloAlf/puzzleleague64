/**
 * Original filename: sfxlimit.c
 */

#include "sfxlimit.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"
#include "sound.h"

extern s32 B_801AB7E0_usa;
extern s32 B_801C7154_usa;
extern SongInitStruct *B_8021BA7C_usa;
extern s32 B_8021DF48_usa;

s32 PlayMIDI(SongInitStruct bgmArray[], s32 songIndex, s32 songBuffer, s32 crossfade) {
    if (songIndex < 0) {
        B_801C7154_usa = 0;
        return 0;
    }

    B_8021BA7C_usa = &bgmArray[songIndex];
    B_8021B960_usa = songIndex;
    B_801AB7E0_usa = songBuffer;
    B_8021DF48_usa = crossfade;
    B_801C7154_usa = 1;
    return 0;
}

// TODO: enum for sfxIndex?
musHandle PlaySE(SfxInitStruct *sfxArray, s32 sfxIndex) {
    SfxInitStruct *sfxPtr;

    if (B_801C6EF6_usa <= 327.67) {
        return 0;
    }

    sfxPtr = &sfxArray[sfxIndex];

    func_80002620_usa(sfxPtr->bankRef);

    if (sfxIndex == 1) {
        PlaySFX(sfxPtr->sfxRef, 1, 0x7F);
    }

    PlaySFX(sfxPtr->sfxRef, sfxPtr->vol, sfxPtr->pan);

    if (sfxPtr->pitch != 0.0f) {
        SetFrequencySFX(D_800B3ADC_usa, sfxPtr->pitch);
    }

    func_80002620_usa(0);

    return D_800B3ADC_usa;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_80005270_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sfxlimit", func_80005270_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sfxlimit", func_80005330_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sfxlimit", func_80005270_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_8000541C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sfxlimit", func_8000541C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sfxlimit", func_800054DC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sfxlimit", func_8000541C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_80005608_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sfxlimit", func_80005608_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sfxlimit", func_800056C8_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sfxlimit", func_80005608_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_80005780_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sfxlimit", func_80005780_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sfxlimit", func_80005840_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sfxlimit", func_80005780_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_80005888_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sfxlimit", func_80005888_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sfxlimit", func_80005888_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sfxlimit", func_80005888_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sfxlimit", func_80005A08_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sfxlimit", func_80005A08_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sfxlimit", func_80005A08_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sfxlimit", func_80005A08_usa);
#endif

void SetMIDIParam(musHandle handle, SongInitStruct bgmArray[], s32 songIndex, s32 songBuffer) {
    SongInitStruct *bgmPtr = &bgmArray[songIndex];

    if (func_80002CE0_usa(handle) != 0) {
        SetSongCrossFadeVolume(bgmPtr->vol, songBuffer);
        func_80002F68_usa(last_song_handle, bgmPtr->pan);
        SetSongTempo(last_song_handle, bgmPtr->tempo);
    }
}
