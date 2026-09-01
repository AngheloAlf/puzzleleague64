/**
 * Original filename: pause.c
 */

#include "pause.h"

#include "assets_variables.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "fade.h"
#include "info.h"
#include "init2d.h"
#include "init3d.h"
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

    limit = (gSelection == SELECTION_BE) || (gSelection < SELECTION_83) ? 3 : 2;
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
                PlaySE(SFX_INIT_TABLE, SFX_001);
            }
        } else if (gamepad->touch_button & D_JPAD) {
            (*pos)++;
            if (*pos >= limit) {
                *pos = limit - 1;
            } else {
                PlaySE(SFX_INIT_TABLE, SFX_001);
            }
        } else if (gamepad->touch_button & B_BUTTON) {
            gTheGame.cursorBlock[0].frame_n = 0;
            gTheGame.cursorBlock[1].frame_n = 0;
            PlaySE(SFX_INIT_TABLE, SFX_006);
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
                PlaySE(SFX_INIT_TABLE, SFX_002);
            } else if ((*pos == 1) && ((gSelection == SELECTION_BE) || (gSelection < SELECTION_83))) {
                gReset = -1;
                gMain = GMAIN_384;
                gCounter = 0;
                gTheGame.cursorBlock[0].target[2] = gWorld;
                PlaySE(SFX_INIT_TABLE, SFX_002);
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
                if (gSelection == SELECTION_AA) {
                    gPlayer[0]->kPLAYER1C_2Dscore = 0;
                }
                gGameStatus &= ~GAME_STATUS_FLAG_20;
                PlaySE(SFX_INIT_TABLE, SFX_002);
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

/**
 * Original name: Do3DPauseGame
 */
void Do3DPauseGame(gamepad_t *gamepad, s32 num, s32 flag) {
    s32 *pos;
    s32 limit;
    uObjSprite *sp;

    if (gTheGame.help.selection != num) {
        return;
    }

    limit = (gSelection == SELECTION_BE) || (gSelection < SELECTION_83) ? 3 : 2;
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
                PlaySE(SFX_INIT_TABLE, SFX_001);
            }
        } else if (gamepad->touch_button & D_JPAD) {
            (*pos)++;
            if (*pos >= limit) {
                *pos = limit - 1;
            } else {
                PlaySE(SFX_INIT_TABLE, SFX_001);
            }
        } else if (gamepad->touch_button & B_BUTTON) {
            gTheGame.cursorBlock[0].frame_n = 0;
            gTheGame.cursorBlock[1].frame_n = 0;
            PlaySE(SFX_INIT_TABLE, SFX_006);
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
                PlaySE(SFX_INIT_TABLE, SFX_002);
            } else if ((*pos == 1) && ((gSelection == SELECTION_BE || (gSelection == SELECTION_82)))) {
                gReset = -1;
                gMain = GMAIN_384;
                gCounter = 0;
                PlaySE(SFX_INIT_TABLE, SFX_002);
            } else {
                gMain = GMAIN_387;
                UpdateComboChainCount(0, 0, -gTheGame.tetrisWell[0].unk_43A8);
                UpdateComboChainCount(1, 0, -gTheGame.tetrisWell[1].unk_43A8);
                gReset = -1;
                gMain = GMAIN_2BC;

                gTheGame.hour = gTheGame.minute = gTheGame.second = 0;
                Init3DAttackBlocks(&gTheGame.tetrisWell[0]);
                Init3DAttackBlocks(&gTheGame.tetrisWell[1]);
                Init3DIcons(&gTheGame.tetrisWell[0]);
                Init3DIcons(&gTheGame.tetrisWell[1]);
                Init3DExplosion(&gTheGame.tetrisWell[0]);
                Init3DExplosion(&gTheGame.tetrisWell[1]);
                if (gSelection == SELECTION_AA) {
                    gPlayer[0]->kPLAYER1C_2Dscore = 0;
                }
                gGameStatus &= ~GAME_STATUS_FLAG_20;
                PlaySE(SFX_INIT_TABLE, SFX_002);
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
            sp->s.objX = 0x80;
            sp->s.objY = (*pos * 0x11 + 0x70) << 2;
        } else {
            gTheGame.unk_9A90[2].b.frameX = 191 << 2;
            gTheGame.unk_9A90[2].b.frameY = 103 << 2;
            sp->s.objX = 0x310;
            sp->s.objY = (*pos * 0x11 + 0x70) << 2;
        }
    }

    if (DoFlashDrawAlways()) {
        sp->s.imageAdrs = 0;
    } else {
        sp->s.imageAdrs = 1;
    }
}

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

/**
 * Original name: Draw2DPause
 */
void Draw2DPause(struct_gInfo_unk_00068 *dynamicp UNUSED) {
    s32 iPlayer;

    if (gTheGame.help.current_pos < 0) {
        return;
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_NONE);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    for (iPlayer = 0; iPlayer < gTheGame.totalPlayer; iPlayer++) {
        s32 x = gTheGame.unk_9A90[iPlayer].b.frameX >> 2;
        s32 y = gTheGame.unk_9A90[iPlayer].b.frameY >> 2;
        s32 height = gTheGame.unk_9A90[0].b.imageH >> 2;
        s32 width = gTheGame.unk_9A90[0].b.imageW >> 2;
        s32 line_height = 8;
        s32 i;

        for (i = 0; i < height; i += line_height) {
            gDPLoadTextureBlock(glistp++, (u8 *)gTheGame.unk_9A90[iPlayer].b.imagePtr + sizeof(u32) * width * i,
                                G_IM_FMT_RGBA, G_IM_SIZ_32b, width, line_height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(glistp++, (x) << 2, (y + i) << 2, (x + width) << 2, (y + line_height + i) << 2,
                                G_TX_RENDERTILE, 0 << 5, 0 << 5, 1 << 10, 1 << 10);

            gDPPipeSync(glistp++);
        }
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &gTheGame.signLUT);
    gDPSetRenderMode(glistp++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetCycleType(glistp++, G_CYC_COPY);

    gDPPipeSync(glistp++);
    gSPBgRectCopy(glistp++, &gTheGame.unk_9A90[2]);

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &numberLUT);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
    gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gSPObjLoadTxtr(glistp++, &arrowTexture);
    gSPObjRectangle(glistp++, &gTheGame.gSPRITE[9]);
}

/**
 * Original name: Draw3DPause
 */
void Draw3DPause(struct_gInfo_unk_00068 *dynamicp UNUSED) {
    s32 iPlayer;
    s32 x;
    s32 y;
    s32 height;
    s32 width;
    s32 line_height;
    s32 i;
    uObjSprite *sp;

    if (gTheGame.help.current_pos < 0) {
        return;
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_NONE);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

    for (iPlayer = 0; iPlayer < gTheGame.totalPlayer; iPlayer++) {
        x = gTheGame.unk_9A90[iPlayer].b.frameX >> 2;
        y = gTheGame.unk_9A90[iPlayer].b.frameY >> 2;
        height = gTheGame.unk_9A90[0].b.imageH >> 2;
        width = gTheGame.unk_9A90[0].b.imageW >> 2;
        line_height = 8;

        for (i = 0; i < height; i += line_height) {
            gDPLoadTextureBlock(glistp++, (u8 *)gTheGame.unk_9A90[iPlayer].b.imagePtr + sizeof(u32) * width * i,
                                G_IM_FMT_RGBA, G_IM_SIZ_32b, width, line_height, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

            gSPTextureRectangle(glistp++, (x) << 2, (y + i) << 2, (x + width) << 2, (y + line_height + i) << 2,
                                G_TX_RENDERTILE, 0 << 5, 0 << 5, 1 << 10, 1 << 10);

            gDPPipeSync(glistp++);
        }
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(glistp++, gTheGame.signLUT.block.image);
    gDPSetTexturePersp(glistp++, G_TP_NONE);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(glistp++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
    gDPPipeSync(glistp++);

    guS2DEmuBgRect1Cyc(&glistp, &gTheGame.unk_9A90[2]);

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(glistp++, numberTable);

    sp = &gTheGame.gSPRITE[9];
    x = sp->s.objX >> 2;
    y = sp->s.objY >> 2;
    line_height = 8;

    gDPLoadTextureBlock(glistp++, arrow, G_IM_FMT_CI, G_IM_SIZ_8b, ARROW_WIDTH, ARROW_HEIGHT, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, sp->s.imageAdrs, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
               G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);

    gDPSetTileSize(glistp++, 1, 0 << 2, 0 << 2, 7 << 2, 7 << 2);

    gSPTextureRectangle(glistp++, x << 2, y << 2, (x + line_height) << 2, (y + line_height) << 2, 1, 0, 0, 1 << 10,
                        1 << 10);
}

/**
 * Original name: DrawPause
 */
void DrawPause(struct_gInfo_unk_00068 *dynamicp) {
    if (gTheGame.dimension == DIMENSION_3D) {
        Draw3DPause(dynamicp);
    } else {
        Draw2DPause(dynamicp);
    }
}
