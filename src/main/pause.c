/**
 * Original filename: pause.c
 */

#include "pause.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "fade.h"
#include "info.h"
#include "init2d.h"
#include "sfxlimit.h"
#include "sign.h"
#include "sound.h"
#include "the_game.h"
#include "update.h"

/**
 * Original name: Do2DPauseGame
 */
void Do2DPauseGame(gamepad_t *gamepad, s32 num, s32 flag) {
    s32 *pos;
    s32 limit;
    uObjSprite *sp;

    if (gTheGame.help.selection != num) {
        return;
    }

    limit = (gSelection == 0xBE) || (gSelection < 0x83) ? 3 : 2;
    pos = &gTheGame.help.current_pos;
    sp = &gTheGame.gSPRITE[9];

    if (gamepad->button & U_CBUTTONS) {
        if (*pos >= 0) {
            *pos -= 0xC;
        }
    } else {
        if (*pos < 0) {
            *pos += 0xC;
        }

        if (gamepad->touch_button & U_JPAD) {
            (*pos)--;
            if (*pos < 0) {
                *pos = 0;
            } else {
                PlaySE(SFX_INIT_TABLE, 1);
            }
        } else if (gamepad->touch_button & D_JPAD) {
            (*pos)++;
            if (*pos >= limit) {
                *pos = limit - 1;
            } else {
                PlaySE(SFX_INIT_TABLE, 1);
            }
        } else if (gamepad->touch_button & B_BUTTON) {
            gTheGame.cursorBlock[0].frame_n = 0;
            gTheGame.cursorBlock[1].frame_n = 0;
            PlaySE(SFX_INIT_TABLE, 6);
            if (flag != 0) {
                gMain = GMAIN_387;
                FadeSong(last_song_handle, CROSSFADE_VOLUME[GetTuneBufferFromHandle(last_song_handle)], 0xF, NULL);
            } else {
                gMain = GMAIN_384;
            }
        } else if (gamepad->touch_button & (START_BUTTON | A_BUTTON)) {
            if (*pos == 0) {
                gTheGame.cursorBlock[0].frame_n = 0;
                gTheGame.cursorBlock[1].frame_n = 0;
                if (flag != 0) {
                    gMain = GMAIN_387;
                    FadeSong(last_song_handle, CROSSFADE_VOLUME[GetTuneBufferFromHandle(last_song_handle)], 0xF, NULL);
                } else {
                    gMain = GMAIN_384;
                }
                PlaySE(SFX_INIT_TABLE, 2);
            } else if ((*pos == 1) && ((gSelection == 0xBE) || (gSelection < 0x83))) {
                gReset = -1;
                gMain = GMAIN_384;
                gCounter = 0;
                gTheGame.cursorBlock[0].target[2] = gWorld;
                PlaySE(SFX_INIT_TABLE, 2);
            } else {
                gMain = GMAIN_387;
                UpdateComboChainCount(0, 0, -gTheGame.tetrisWell[0].unk_43A8);
                UpdateComboChainCount(1, 0, -gTheGame.tetrisWell[1].unk_43A8);
                gReset = -1;
                gMain = GMAIN_2BC;
                gTheGame.hour = gTheGame.minute = gTheGame.second = 0;
                Init2DAttackBlocks(&gTheGame.tetrisWell[0]);
                Init2DAttackBlocks(&gTheGame.tetrisWell[1]);
                Init2DIcons(&gTheGame.tetrisWell[0]);
                Init2DIcons(&gTheGame.tetrisWell[1]);
                Init2DExplosion(&gTheGame.tetrisWell[0]);
                Init2DExplosion(&gTheGame.tetrisWell[1]);
                if (gSelection == 0xAA) {
                    gPlayer[0]->kPLAYER1C_2Dscore = 0;
                }
                gGameStatus &= ~0x20;
                PlaySE(SFX_INIT_TABLE, 2);
            }
        }
    }

    if (gTheGame.totalPlayer == 1) {
        AnimatePauseKey(&gTheGame.unk_9A90[0]);

        gTheGame.cursorBlock[0].frame_n++;
        gTheGame.cursorBlock[0].frame_d++;

        gTheGame.unk_9A90[2].b.frameX = 117 << 2;
        gTheGame.unk_9A90[2].b.frameY = 103 << 2;

        sp->s.objX = 122 << 2;
        sp->s.objY = (*pos * 0x11 + 0x70) << 2;
    } else {
        AnimatePauseKey(&gTheGame.unk_9A90[0]);
        AnimatePauseKey(&gTheGame.unk_9A90[1]);

        if (gTheGame.help.selection == num) {
            gTheGame.cursorBlock[0].frame_n++;
        }
        gTheGame.cursorBlock[0].frame_d++;
        gTheGame.cursorBlock[1].frame_d++;

        if (gTheGame.help.selection == 0) {
            gTheGame.unk_9A90[2].b.frameX = 27 << 2;
            gTheGame.unk_9A90[2].b.frameY = 103 << 2;
            sp->s.objX = 32 << 2;
            sp->s.objY = (*pos * 0x11 + 0x70) << 2;
        } else {
            gTheGame.unk_9A90[2].b.frameX = 191 << 2;
            gTheGame.unk_9A90[2].b.frameY = 103 << 2;
            sp->s.objX = 196 << 2;
            sp->s.objY = (*pos * 0x11 + 0x70) << 2;
        }
    }

    if (DoFlashDrawAlways()) {
        sp->s.imageAdrs = 0;
    } else {
        sp->s.imageAdrs = 1;
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/pause", Do3DPauseGame);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/pause", Do3DPauseGame);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/pause", Do3DPauseGame);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/pause", Do3DPauseGame);
#endif

/**
 * Original name: DoPauseGame
 */
void DoPauseGame(gamepad_t *gamepad, s32 num, s32 flag) {
    if (gTheGame.dimension == DIMENSION_3D) {
        Do3DPauseGame(gamepad, num, flag);
    } else {
        Do2DPauseGame(gamepad, num, flag);
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/pause", Draw2DPause);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/pause", Draw2DPause);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/pause", Draw2DPause);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/pause", Draw2DPause);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/pause", Draw3DPause);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/pause", Draw3DPause);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/pause", Draw3DPause);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/pause", Draw3DPause);
#endif

void DrawPause(struct_gInfo_unk_00068 *dynamicp) {
    if (gTheGame.dimension == DIMENSION_3D) {
        Draw3DPause(dynamicp);
    } else {
        Draw2DPause(dynamicp);
    }
}
