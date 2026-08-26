/**
 * Original filename: tetsound.c
 */

#include "tetsound.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "sfxlimit.h"
#include "sound.h"
#include "tetwell.h"
#include "the_game.h"

void InitGameAudioSystem(void) {
    TenSecond = 0;

#if VERSION_USA || VERSION_EUR
    DolbyEnabled = true;
#endif

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

    InitAudio();

    switch (D_800B3B18_usa) {
        case 0x0:
            func_80002E70_usa(D_FLT_800B3B10_usa * 0x7FFF);
            func_80002E34_usa(0x147);
            break;

        case 0x1:
            FadeOutAllSFXs(0);
            func_80002E70_usa(0x147);
            func_80002E34_usa(D_FLT_800B3B14_usa * 0x7FFF);
            break;

        case 0x2:
            func_80002E70_usa(D_FLT_800B3B10_usa * 0x7FFF);
            func_80002E34_usa(D_FLT_800B3B14_usa * 0x7FFF);
            break;

        case 0x3:
            FadeOutAllSFXs(0);
            func_80002E70_usa(0x147);
            func_80002E34_usa(0x147);
            break;
    }

    SetSoundOptions(DolbyEnabled);
}

void SetSoundOptions(s16 settings) {
    if (settings == false) {
        DolbyEnabled = false;
        SetAudioSystemMixer(0);
        LoadSFXBank(1, 1);
        GarbageBlockBaseSfx_L = 0x133;
        GarbageBlockBaseSfx_R = 0x13A;
    } else if (settings == true) {
        DolbyEnabled = true;
        SetAudioSystemMixer(1);
        LoadSFXBank(1, 1);
        GarbageBlockBaseSfx_L = 0x133;
        GarbageBlockBaseSfx_R = 0x13A;
    }
}

extern u8 D_800B3B11[];
extern u8 D_800B3B15[];
extern u8 D_800B3B34_usa[];

#if VERSION_USA
#ifdef NON_MATCHING
// regalloc
s32 LoadFairySoundData(s16 arg0, s16 arg1, s16 arg2) {
    s32 var_s4;
    s32 var_s5;

    var_s4 = 4;
    var_s5 = 0x16;

    ts_ok_start_timer = 1;
    ts_old_alert = -1;
    initgameBool = 1;
    NormalMusicBgmIndex_ScoreAttack = 0x48;
    DangerMusicBgmIndex_ScoreAttack = 0x49;
    ts_timer_counter = 0;
    ts_current_alert = 0;
    crossfadeBool = 0;
    TenSecond = 0;

    if (arg0 < 0x11U) {
        arg0 = arg0 * 2;
    } else if (arg0 < 0x19) {
        if ((gTheGame.menu[0].game == 5) && (gTheGame.menu[0].stage == 3)) {
            arg0++;
        } else if (gTheGame.menu[0].stage >= 4) {
            arg0++;
            if ((gTheGame.menu[0].game == 5) && (gTheGame.menu[0].stage == 6)) {
                arg0++;
            }
        }
        arg0 = arg0 * 2;
    } else if (arg0 < 0x1B) {
        arg0 = (arg0 * 2) + 6;

        if (arg0 == 0x38) {
            B_801C7348_usa++;
            B_801C7348_usa %= 3;
            if ((gTheGame.menu[0].game == 0) && (B_801C7348_usa == 0)) {
                B_801C7348_usa++;
            }
            arg0 = D_800B3B34_usa[B_801C7348_usa];
        }
    } else if (arg0 < 0x1E) {
        arg2 = D_800B3B11[arg0];
        B_801C6EE8_usa = D_800B3B15[arg0];
        arg0 = arg0 * 2 - 4;
        arg1 = arg2;
    } else {
        arg0 = 0x14;
    }

    if ((gMain != GMAIN_TUTORIAL) & (gMain != GMAIN_MIMIC)) {
        func_80003E00_usa(arg0, 0);
        func_80003E00_usa(arg0 + 1, 1);
    }

    DangerMusicBgmIndex = arg0 + 1;
    NormalMusicBgmIndex_ScoreAttack = 0x48;
    DangerMusicBgmIndex_ScoreAttack = 0x49;
    NormalMusicBgmIndex = arg0;

    if (gSelection == 0xAA) {
        arg1 = 0;
        arg2 = 0xA;
        if (gTheGame.menu[0].game == 5) {
            if (gTheGame.menu[0].stage == 6) {
                arg2 = 0xB;
            } else {
                arg2 = 0xA;
            }
        }
    }

    B_801C7089_usa = arg1;
    B_801C6C90_usa = arg2;
    if (arg1 < 0x11U) {
        var_s4 = arg1 + 4;
    }

    LoadSFXBank(var_s4, 3U);
    if (arg2 >= 0) {
        if (arg2 < 0x11) {
            var_s5 = arg2 + 0x16;
        }
        LoadSFXBank(var_s5, 4U);
    }

    if ((gMain != GMAIN_MIMIC) && (gMain != GMAIN_TUTORIAL) && (gSelection != 0x82) && (gSelection != 0x78)) {
        if (gSelection == 0xAA) {
        } else if ((gSelection == 0x96) && (arg2 == 0x10)) {
            // These empty blocks seems required to match?
        } else if (((gSelection == 0xA0) || (gSelection == 0xB4) || (gSelection == 0xC8)) && (arg2 == 0x10)) {
            // ?
        } else {
            PlaySE(SFX_INIT_TABLE, 0x17A);
        }
    }

    if (gSelection == 0xAA) {
        if (gTheGame.menu[0].game == 5) {
            if (gTheGame.menu[0].stage == 3) {
                PlaySE(SFX_INIT_TABLE, 0x82);
            } else if (gTheGame.menu[0].stage == 6) {
                B_801C7348_usa++;
                B_801C7348_usa %= 2;
                PlaySE(SFX_INIT_TABLE, B_801C7348_usa + 0x59);
            }
        } else {
            B_801C7348_usa++;
            B_801C7348_usa %= 5;
            func_80005888_usa(0, 2, B_801C7348_usa + 5);
        }
    }

    if ((gMain != GMAIN_TUTORIAL) & (gMain != GMAIN_MIMIC)) {
        PlayMIDI(NULL, -1, -1, -1);
        func_80002D8C_usa(0xF);
    }

    return 1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/tetsound", LoadFairySoundData);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", LoadFairySoundData);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", LoadFairySoundData);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetsound", LoadFairySoundData);
#endif

s32 PlayGameSong(tetWell *well) {
    ts_current_alert = well->unk_43B8;

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

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetsound", func_80004900_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetsound", func_80004924_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetsound", func_80004978_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetsound", func_80004C54_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetsound", func_80004EC8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetsound", func_800050D0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetsound", func_80005178_ger);
#endif
