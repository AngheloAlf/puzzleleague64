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

s32 LoadFairySoundData(s16 music, s16 fairy1, s16 fairy2) {
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

    if ((music >= 0) && (music < 0x11)) {
        music *= 2;
    } else if (music < 0x19) {
        if ((gTheGame.menu[0].game == 5) && (gTheGame.menu[0].stage == 3)) {
            music++;
        } else if (gTheGame.menu[0].stage >= 4) {
            music++;
            if ((gTheGame.menu[0].game == 5) && (gTheGame.menu[0].stage == 6)) {
                music++;
            }
        }
        music *= 2;
    } else if (music < 0x1B) {
        music = music * 2 + 6;

        if (music == 0x38) {
            B_801C7348_usa++;
            B_801C7348_usa %= 3;
            if ((gTheGame.menu[0].game == 0) && (B_801C7348_usa == 0)) {
                B_801C7348_usa++;
            }
            music = D_800B3B34_usa[B_801C7348_usa];
        }
    } else if (music < 0x1E) {
        fairy2 = D_800B3B11[music];
        B_801C6EE8_usa = D_800B3B15[music];
        music = music * 2 - 4;
        fairy1 = fairy2;
    } else {
        music = 0x14;
    }

    if ((gMain != GMAIN_TUTORIAL) & (gMain != GMAIN_MIMIC)) {
        func_80003E00_usa(music, 0);
        func_80003E00_usa(music + 1, 1);
    }

    DangerMusicBgmIndex = music + 1;
    NormalMusicBgmIndex_ScoreAttack = 0x48;
    DangerMusicBgmIndex_ScoreAttack = 0x49;
    NormalMusicBgmIndex = music;

    if (gSelection == SELECTION_AA) {
        fairy1 = 0;
        fairy2 = 0xA;
        if (gTheGame.menu[0].game == 5) {
            if (gTheGame.menu[0].stage == 6) {
                fairy2 = 0xB;
            } else {
                fairy2 = 0xA;
            }
        }
    }

    B_801C7089_usa = fairy1;
    B_801C6C90_usa = fairy2;
    if ((fairy1 >= 0) && (fairy1 < 0x11)) {
        var_s4 = fairy1 + 4;
    }

    LoadSFXBank(var_s4, 3U);
    if (fairy2 >= 0) {
        if (fairy2 < 0x11) {
            var_s5 = fairy2 + 0x16;
        }
        LoadSFXBank(var_s5, 4U);
    }

    if ((gMain != GMAIN_MIMIC) && (gMain != GMAIN_TUTORIAL) && (gSelection != SELECTION_82) &&
        (gSelection != SELECTION_78)) {
        if (gSelection == SELECTION_AA) {
        } else if ((gSelection == SELECTION_96) && (fairy2 == 0x10)) {
            // These empty blocks seems required to match?
        } else if (((gSelection == SELECTION_A0) || (gSelection == SELECTION_B4) || (gSelection == SELECTION_C8)) &&
                   (fairy2 == 0x10)) {
            // ?
        } else {
            PlaySE(SFX_INIT_TABLE, SFX_17A);
        }
    }

    if (gSelection == SELECTION_AA) {
        if (gTheGame.menu[0].game == 5) {
            if (gTheGame.menu[0].stage == 3) {
                PlaySE(SFX_INIT_TABLE, SFX_082);
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

s32 PlayGameSong(tetWell *well) {
    ts_current_alert = well->alert;

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

    if ((TenSecond == 1) && (gSelection != SELECTION_C8)) {
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

    if ((TenSecond == 1) && (gSelection != SELECTION_C8)) {
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

// Maybe?
// int GetLoadSongNumber(int songnum /* r3 */)
s32 func_80004848_usa(s32 arg0) {
    if ((arg0 < 0x48) || (arg0 == 0xFF)) {
        return arg0;
    }
    return arg0 - 0x48;
}

/**
 * Original name: PlayGameMusicTest
 */
s32 PlayGameMusicTest(s32 song_index) {
    if (song_index < 0x49) {
        song_index--;
        func_80002D8C_usa(0x1E);
        PlayMIDI(BGM_INIT_TABLE, song_index, 0, 1);
        return 0;
    }

#if PRESERVE_UB
    return 0;
#endif
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetsound", func_800048C0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetsound", func_800048C0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetsound", func_800048C0_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetsound", func_800048C0_usa);
#endif

nbool func_80004B9C_usa(s32 arg0) {
    SfxInitStruct *sfx;
    u16 held = gTheGame.controller[0].button;
    u16 pressed = gTheGame.controller[0].touch_button;

    if (held & Z_TRIG) {
        pressed |= held & (L_TRIG | R_TRIG);
    }

    if (!(pressed & (L_TRIG | R_TRIG))) {
        return nfalse;
    }

    if (arg0 <= 0) {
        arg0 = 1;
    } else if (arg0 > 0x1E4) {
        arg0 = 0x1E4;
    }
    arg0--;
    arg0 = D_800B3B38_usa[arg0];
    if (arg0 < 0) {
        arg0 = 0;
    } else if (arg0 > 0x17B) {
        arg0 = 0x17B;
    }
    sfx = &SFX_INIT_TABLE[arg0];

    if (held & U_CBUTTONS) {
        if ((pressed & L_TRIG) && (sfx->vol != 0)) {
            sfx->vol--;
        }
        if ((pressed & R_TRIG) && (sfx->vol < 0xFF)) {
            sfx->vol++;
        }
    }
    if (held & L_CBUTTONS) {
        if ((pressed & L_TRIG) && (sfx->pan != 0)) {
            sfx->pan--;
        }
        if ((pressed & R_TRIG) && (sfx->pan < 0xFF)) {
            sfx->pan++;
        }
    }
    if (held & D_CBUTTONS) {
        if ((pressed & L_TRIG) && (sfx->pitch > 0.0f)) {
            sfx->pitch -= 0.5f;
        }
        if ((pressed & R_TRIG) && (sfx->pitch < 20.0f)) {
            sfx->pitch += 0.5f;
        }
    }
    if (held & R_CBUTTONS) {
        if ((pressed & L_TRIG) && (D_FLT_800B3B10_usa > 0.0f)) {
            D_FLT_800B3B10_usa -= 0.05f;
        }
        if ((pressed & R_TRIG) && (D_FLT_800B3B10_usa < 1.0f)) {
            D_FLT_800B3B10_usa += 0.05f;
        }
        func_80002E70_usa(D_FLT_800B3B10_usa * 0x7FFF);
    }

    return ntrue;
}

nbool func_80004E10_usa(s32 arg0) {
    SongInitStruct *song;
    u16 held = gTheGame.controller[0].button;
    u16 pressed = gTheGame.controller[0].touch_button;

    if (held & Z_TRIG) {
        pressed |= held & (L_TRIG | R_TRIG);
    }

    if (!(pressed & (L_TRIG | R_TRIG))) {
        return nfalse;
    }

    if (arg0 <= 0) {
        arg0 = 1;
    } else if (arg0 > 0x48) {
        arg0 = 0x48;
    }
    arg0--;
    song = &BGM_INIT_TABLE[arg0];

    if (held & U_CBUTTONS) {
        if ((pressed & L_TRIG) && (song->vol != 0)) {
            song->vol--;
        }
        if ((pressed & R_TRIG) && (song->vol < 0xFF)) {
            song->vol++;
        }
    }
    if (held & L_CBUTTONS) {
        if ((pressed & L_TRIG) && (song->pan != 0)) {
            song->pan--;
        }
        if ((pressed & R_TRIG) && (song->pan < 0xFF)) {
            song->pan++;
        }
    }
    if (held & D_CBUTTONS) {
        if ((pressed & L_TRIG) && (song->tempo != 0)) {
            song->tempo--;
        }
        if ((pressed & R_TRIG) && (song->tempo < 0xFF)) {
            song->tempo++;
        }
    }
    if (held & R_CBUTTONS) {
        if ((pressed & L_TRIG) && (D_FLT_800B3B14_usa > 0.0f)) {
            D_FLT_800B3B14_usa -= 0.01f;
        }
        if ((pressed & R_TRIG) && (D_FLT_800B3B14_usa < 1.0f)) {
            D_FLT_800B3B14_usa += 0.01f;
        }
        func_80002E34_usa(D_FLT_800B3B14_usa * 0x7FFF);
    }

    return ntrue;
}

void func_80005018_usa(s32 arg0, s32 *arg1) {
    SfxInitStruct *sfx;

    if (arg0 <= 0) {
        arg0 = 1;
    } else if (arg0 > 0x1E4) {
        arg0 = 0x1E4;
    }
    arg0--;
    arg0 = D_800B3B38_usa[arg0];
    if (arg0 < 0) {
        arg0 = 0;
    } else if (arg0 > 0x17B) {
        arg0 = 0x17B;
    }

    sfx = &SFX_INIT_TABLE[arg0];
    arg1[0] = sfx->vol;
    arg1[1] = sfx->pan;
    arg1[2] = sfx->pitch * 2.0f;
    arg1[3] = D_FLT_800B3B10_usa * 100.0f;
}

void func_800050C0_usa(s32 arg0, s32 *arg1) {
    SongInitStruct *song;

    if (arg0 <= 0) {
        arg0 = 1;
    } else if (arg0 > 0x48) {
        arg0 = 0x48;
    }
    arg0--;

    song = &BGM_INIT_TABLE[arg0];
    arg1[0] = song->vol;
    arg1[1] = song->pan;
    arg1[2] = song->tempo;
    arg1[3] = D_FLT_800B3B14_usa * 100.0f;
}
