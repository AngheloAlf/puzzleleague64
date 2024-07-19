/**
 * Original filename: tetsound.c
 */

#include "tetsound.h"
#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "sfxlimit.h"
#include "sound.h"

#if VERSION_USA
void InitGameAudioSystem(void) {
    TenSecond = 0;
    DolbyEnabled = true;
    DangerMusicBgmIndex = 1;
    NormalMusicBgmIndex = 0;
    crossfadeBool = 0;
    NormalMusicBgmIndex_ScoreAttack = 0x48;
    DangerMusicBgmIndex_ScoreAttack = 0x49;
    initgameBool = 1;
    ts_ok_start_timer = 1;
    ts_timer_counter = 0;
    ts_current_alert = 0;
    ts_old_alert = -1;

    func_800027FC_usa();

    switch (D_800B3B18_usa) {
        case 0x0:
            func_80002E70_usa(D_FLT_800B3B10_usa * 0x7FFF);
            func_80002E34_usa(0x147);
            break;
        case 0x1:
            func_80002E0C_usa(0);
            func_80002E70_usa(0x147);
            func_80002E34_usa(D_FLT_800B3B14_usa * 0x7FFF);
            break;
        case 0x2:
            func_80002E70_usa(D_FLT_800B3B10_usa * 0x7FFF);
            func_80002E34_usa(D_FLT_800B3B14_usa * 0x7FFF);
            break;
        case 0x3:
            func_80002E0C_usa(0);
            func_80002E70_usa(0x147);
            func_80002E34_usa(0x147);
            break;
    }

    SetSoundOptions(DolbyEnabled);
}
#endif

#if VERSION_USA
void SetSoundOptions(s16 arg0) {
    if (arg0 == false) {
        DolbyEnabled = false;
        SetAudioSystemMixer(0);
        LoadSFXBank(1, 1);
        GarbageBlockBaseSfx_L = 0x133;
        GarbageBlockBaseSfx_R = 0x13A;
    } else if (arg0 == true) {
        DolbyEnabled = true;
        SetAudioSystemMixer(1);
        LoadSFXBank(1, 1);
        GarbageBlockBaseSfx_L = 0x133;
        GarbageBlockBaseSfx_R = 0x13A;
    }
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetsound", func_800040D8_usa);
#endif

#if VERSION_USA
s32 PlayGameSong(TheGame_unk_0000 *game) {
    ts_current_alert = game->unk_43B8;

    if (initgameBool) {
        initgameBool = false;
        if (ts_current_alert == -1) {
            ts_old_alert = 0;
        } else {
            ts_old_alert = -1;
        }
    }

    if (ts_old_alert != ts_current_alert) {
        ts_old_alert = ts_current_alert;

        if (ts_ok_start_timer != 0) {
            ts_ok_start_timer = 0;
            ts_timer_counter = 0xC;
            if (crossfadeBool) {
                FadeOutSong(last_song_handle, 0xA);
            }
        }
    }

    if ((TenSecond == 1) && (gSelection != 0xC8)) {
        DangerMusicBgmIndex = DangerMusicBgmIndex_ScoreAttack;
        NormalMusicBgmIndex = NormalMusicBgmIndex_ScoreAttack;
    }

    if (ts_current_alert == -1) {
        ts_song_index = DangerMusicBgmIndex;
        ts_song_buffer = 1;
    } else if (ts_current_alert == 0) {
        ts_song_index = NormalMusicBgmIndex;
        ts_song_buffer = 0;
    }

    if ((TenSecond == 1) && (gSelection != 0xC8)) {
        SetMIDIParam(last_song_handle, BGM_INIT_TABLE, ts_song_index, ts_song_buffer);
    }

    if (ts_ok_start_timer == 0) {
        ts_timer_counter--;
        if (ts_timer_counter < 0) {
            if (gMain == GMAIN_388) {
                ts_timer_counter = 0;
            } else if (IsTuneBufferFree(ts_song_buffer)) {
                PlayMIDI(BGM_INIT_TABLE, ts_song_index, ts_song_buffer, crossfadeBool);
                ts_ok_start_timer = 1;
                crossfadeBool = 2;
            } else {
                FadeOutTuneBuffer(ts_song_buffer, 0);
            }
        }
    }

    return 1;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetsound", func_80004848_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetsound", func_8000486C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetsound", func_800048C0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetsound", func_80004B9C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetsound", func_80004E10_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetsound", func_80005018_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetsound", func_800050C0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", InitGameAudioSystem);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", SetSoundOptions);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", func_800040D8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", PlayGameSong);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", func_80004848_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", func_8000486C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", func_800048C0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", func_80004B9C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", func_80004E10_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", func_80005018_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", func_800050C0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", InitGameAudioSystem);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", func_80004118_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", func_80004190_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", func_80004690_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", func_80004900_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", func_80004924_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", func_80004978_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", func_80004C54_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", func_80004EC8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", func_800050D0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", func_80005178_fra);
#endif
