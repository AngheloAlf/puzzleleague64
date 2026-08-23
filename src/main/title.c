/**
 * Original filename: title.c
 */

#include "title.h"

#include "macros_defines.h"

#include "main_variables.h"

#include "ai.h"
#include "buffers.h"
#include "build.h"
#include "controller.h"
#include "hvqm2util.h"
#include "menu.h"
#include "peel.h"
#include "screen.h"
#include "segment_symbols.h"
#include "sfxlimit.h"
#include "sound.h"
#include "tetris.h"
#include "the_game.h"

typedef struct struct_gpData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14; // TODO: enum?
} struct_gpData; // size = 0x18

static s32 B_8018A7F0_usa;
static struct_gpData *gpData;

#if VERSION_USA
// no longer static on other versions
static
#endif
s32 B_8018A7F8_usa;

static f32 B_FLT_8018A7FC_usa;
static f32 B_FLT_8018A800_usa;
static f32 B_FLT_8018A804_usa;
static u32 B_8018A808_usa;


u32 D_800B5890_usa[] = {
    0xFF000000, 0x00FF0000, 0x0000FF00, 0x00FFFF00, 0xFF00FF00, 0xFFFF0000, 0x00000000,
};

void func_80005C00_usa(void) {
    if (B_8018A808_usa < ARRAY_COUNT(D_800B5890_usa)) {
        u32 temp_v1 = D_800B5890_usa[B_8018A808_usa];
        f32 temp_ft2 = (temp_v1 >> 0x18) & 0xFF;
        f32 temp_ft1 = (temp_v1 >> 0x10) & 0xFF;
        f32 temp_ft0 = (temp_v1 >> 8) & 0xFF;

        if (B_FLT_8018A7FC_usa < temp_ft2) {
            if ((B_FLT_8018A7FC_usa += 6.0) > temp_ft2) {
                B_FLT_8018A7FC_usa = temp_ft2;
            }
        }
        if (B_FLT_8018A7FC_usa > temp_ft2) {
            if ((B_FLT_8018A7FC_usa -= 6.0) < temp_ft2) {
                B_FLT_8018A7FC_usa = temp_ft2;
            }
        }

        if (B_FLT_8018A800_usa < temp_ft1) {
            if ((B_FLT_8018A800_usa += 6.0) > temp_ft1) {
                B_FLT_8018A800_usa = temp_ft1;
            }
        }
        if (temp_ft1 < B_FLT_8018A800_usa) {
            if ((B_FLT_8018A800_usa -= 6.0) < temp_ft1) {
                B_FLT_8018A800_usa = temp_ft1;
            }
        }

        if (B_FLT_8018A804_usa < temp_ft0) {
            if ((B_FLT_8018A804_usa += 6.0) > temp_ft0) {
                B_FLT_8018A804_usa = temp_ft0;
            }
        }
        if (temp_ft0 < B_FLT_8018A804_usa) {
            if ((B_FLT_8018A804_usa -= 6.0) < temp_ft0) {
                B_FLT_8018A804_usa = temp_ft0;
            }
        }

        if ((B_FLT_8018A7FC_usa == temp_ft2) && (B_FLT_8018A800_usa == temp_ft1) && (B_FLT_8018A804_usa == temp_ft0)) {
            B_8018A808_usa++;
        }
    }
}

void func_80005EC0_usa(Gfx **gfxP, s32 arg1 UNUSED, s32 arg2) {
    Gfx *gfx = *gfxP;
    f32 var_fv1;
    f32 var_ft1;
    f32 var_ft0;
    s32 var_t9;

    switch (arg2) {
        case 0x64:
            gDPPipeSync(gfx++);
            gSPClearGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_SHADING_SMOOTH);
            gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
            gDPSetCycleType(gfx++, G_CYC_FILL);
            gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);

            var_fv1 = B_FLT_8018A7FC_usa;
            var_ft1 = B_FLT_8018A800_usa;
            var_ft0 = B_FLT_8018A804_usa;

            for (var_t9 = 0; var_t9 < SCREEN_HEIGHT; var_t9++) {
                u32 color = GPACK_RGBA5551((s32)var_fv1, (s32)var_ft1, (s32)var_ft0, 1);

                gDPSetFillColor(gfx++, (color << 16) | color);
                gDPFillRectangle(gfx++, 0, var_t9, SCREEN_WIDTH-1, var_t9);

                var_fv1 += 256.0 / SCREEN_HEIGHT;
                if (var_fv1 >= 256.0) {
                    var_fv1 = 255;
                }

                var_ft1 += 256.0 / SCREEN_HEIGHT;
                if (var_ft1 >= 256.0) {
                    var_ft1 = 255;
                }

                var_ft0 += 256.0 / SCREEN_HEIGHT;
                if (var_ft0 >= 256.0) {
                    var_ft0 = 255;
                }
            }
            break;

        case 0x6E:
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_CLIPPING);
            break;

        case 0x78:
            gDPPipeSync(gfx++);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_CLIPPING);
            gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
            gDPSetCycleType(gfx++, G_CYC_FILL);
            gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetFillColor(gfx++, (GPACK_RGBA5551(255, 0, 0, 1) << 16) | GPACK_RGBA5551(255, 0, 0, 1));

            //! @bug: reading from unset variable var_t9
            gDPFillRectangle(gfx++, 0, var_t9, SCREEN_WIDTH-1, var_t9);
            break;
    }

    *gfxP = gfx;
}

void DrawTitle(void) {
    if (gpData->unk_14 == 7) {
        screenDraw(&glistp, func_8001A50C_usa);
    } else {
        screenDraw(&glistp, func_80005EC0_usa);
    }

    if (!screenFlushing()) {
        pon_DrawLoadingMessage(&glistp);
    }
}

INLINE nbool func_8000628C_usa(void) {
    s32 var_v1;

    // single iteration loop
    for (var_v1 = 0; var_v1 < 1; var_v1++) {
        if ((gTheGame.controller[var_v1].unk_00 != -1) && (gTheGame.controller[var_v1].touch_button != 0)) {
            return ntrue;
        }
    }

    return nfalse;
}

void DoTitle(void) {
    screenTick_arg0 sp10;
    s32 sp18;
    void *heap;
    s32 temp_s0 = gpData->unk_08;
    s32 temp_s2;
    s32 temp_v0;
    s32 var_s3;

    gpData->unk_00++;
    sp10.unk_0 = 0;
    sp10.unk_4 = 0;
    screenTick(&sp10);
    temp_s2 = gpData->unk_00;

    if (gpData->unk_14 == 0x1) {
        osViBlack(1);
    } else if (gpData->unk_14 == 0x2) {
        screenShowText(temp_s0, 0x64);
        screenShowImage(temp_s0, 0x64);
    } else if (gpData->unk_14 == 0x7) {
        if (peelActive() == 0) {
            if (func_8000628C_usa() && (gReset == 0)) {
                gReset = -1;
            }
        }

        if (temp_s2 % 600 == 0) {
            func_8001ACA8_usa(&sp18);
            gpData->unk_10++;
            if (sp18 < gpData->unk_10) {
                gReset = -1;
                FadeOutSong(last_song_handle, 0x3C);
            } else {
                func_80009D30_usa(temp_s0, gpData->unk_10);
            }
        }

        if ((temp_s2 + 2) % 600 == 0) {
            func_8002CFE4_usa(0xE);
        }
    } else if (gpData->unk_14 == 0x3) {
        func_80005C00_usa();
        if (B_8018A808_usa == 7) {
            gpData->unk_00 = 0;
            gpData->unk_14 = 4;
            gpData->unk_08 = screenSet("EYECATCH", 0x8E001);
        }
    } else if (gpData->unk_14 == 0x4) {
        if (!screenFlushing() && !screenChangePending() && func_80024BF4_usa(&heap)) {
            HVQM2Util_Play((void *)"EYECATCH.HVQM", 0, heap);
            gpData->unk_14 = 5;
        }
    } else if (gpData->unk_14 == 0x5) {
        temp_v0 = screenSet("TITLE", 0x8E401);
        if (temp_v0 != temp_s0) {
            gpData->unk_00 = 0;
            gpData->unk_14 = 6;
            gpData->unk_08 = temp_v0;
            PlayMIDI(BGM_INIT_TABLE, 0x3C, 0, 0);
        }
    } else {
        var_s3 = gpData->unk_04;
        if (B_8018A7F0_usa > 0) {
            B_8018A7F0_usa--;
            screenShowImage(temp_s0, 0x6E);
            screenHideImage(temp_s0, 0x64);
        } else {
            screenHideImage(temp_s0, 0x6E);
            if (temp_s2 & 8) {
                screenHideImage(temp_s0, 0x64);
            } else {
                screenShowImage(temp_s0, 0x64);
            }
        }

        if (gTheGame.controller[0].unk_0E & Z_TRIG) {
            if (gTheGame.controller[0].touch_button != 0) {
                ganButton[giButton] = gTheGame.controller[0].touch_button;
                giButton = (giButton + 1) % ARRAY_COUNTU(ganButton);

                // Cheat code: Start from level 50~99 in Marathon mode
                if ((ganButton[(giButton - 4) % ARRAY_COUNTU(ganButton)] == B_BUTTON) && (ganButton[(giButton - 3) % ARRAY_COUNTU(ganButton)] == A_BUTTON)) {
                    if ((ganButton[(giButton - 2) % ARRAY_COUNTU(ganButton)] == L_TRIG) && (ganButton[(giButton - 1) % ARRAY_COUNTU(ganButton)] == L_TRIG)) {
                        gGameStatus ^= 1;
                        PlaySE(SFX_INIT_TABLE, 9);
                    }
                }

                // Cheat code: Unlock all puzzles in Puzzle University
                if ((ganButton[(giButton - 8) % ARRAY_COUNTU(ganButton)] == A_BUTTON) && (ganButton[(giButton - 7) % ARRAY_COUNTU(ganButton)] == B_BUTTON)) {
                    if ((ganButton[(giButton - 6) % ARRAY_COUNTU(ganButton)] == R_TRIG) && (ganButton[(giButton - 5) % ARRAY_COUNTU(ganButton)] == A_BUTTON)) {
                        if ((ganButton[(giButton - 4) % ARRAY_COUNTU(ganButton)] == A_BUTTON) && (ganButton[(giButton - 3) % ARRAY_COUNTU(ganButton)] == B_BUTTON)) {
                            if ((ganButton[(giButton - 2) % ARRAY_COUNTU(ganButton)] == R_TRIG) && (ganButton[(giButton - 1) % ARRAY_COUNTU(ganButton)] == A_BUTTON)) {
                                B_8021BA98_usa = ~B_8021BA98_usa;
                                PlaySE(SFX_INIT_TABLE, 9);
                            }
                        }
                    }
                }
            }

            gTheGame.controller[0].touch_button = 0;
            gTheGame.controller[0].hold_button = 0;
            gTheGame.controller[1].touch_button = 0;
            gTheGame.controller[1].hold_button = 0;
        }

        if (var_s3 & 2) {
            var_s3 = (D_800B69B0_usa & 1) ? 5 : 1;
            gpData->unk_0C = 0;
            gpData->unk_00 = 0;
        }

        if (var_s3 & 4) {
            gpData->unk_0C++;
            if ((gpData->unk_0C == 0x384) && (B_8018A7F8_usa != 8)) {
                FadeOutSong(last_song_handle, 0x3C);
            }

            if (gpData->unk_0C >= 0x3C0) {
                gDemo = GDEMO_0B;
                gReset = -1;
                gPlayer[0] = gTheGame.player;
                gPlayer[1] = gTheGame.player;
                gTheGame.tetrisWell[0].unk_4404 = 0;
                gTheGame.tetrisWell[1].unk_4404 = 0;
                brainbrain[0].unk_00C = -1;
                brainbrain[1].unk_00C = -1;
                gGameStatus |= 0x80;

                B_8018A7F8_usa++;
                if (B_8018A7F8_usa == 0xA) {
                    B_8018A7F8_usa = 1;
                }

                switch (B_8018A7F8_usa) {
                    case 0x1:
                        gMain = GMAIN_TUTORIAL;
                        gTheGame.unk_9C08 = 1;
                        gTheGame.unk_9C0C = 1;
                        gSelection = 0x64;
                        gTheGame.menu[0].unk_0 = 1;
                        break;

                    case 0x3:
                        gMain = GMAIN_TUTORIAL;
                        gTheGame.unk_9C08 = 1;
                        gTheGame.unk_9C0C = 1;
                        gSelection = 0x64;
                        gTheGame.menu[0].unk_0 = 2;
                        break;

                    case 0x5:
                        gMain = GMAIN_TUTORIAL;
                        gTheGame.unk_9C08 = 1;
                        gTheGame.unk_9C0C = 1;
                        gSelection = 0x64;
                        gTheGame.menu[0].unk_0 = 3;
                        break;

                    case 0x7:
                        gMain = GMAIN_TUTORIAL;
                        gTheGame.unk_9C08 = 1;
                        gTheGame.unk_9C0C = 1;
                        gSelection = 0x64;
                        gTheGame.menu[0].unk_0 = 4;
                        break;

                    case 0x2:
                    case 0x4:
                        gMain = GMAIN_384;
                        gTheGame.unk_9C08 = 1;
                        gTheGame.unk_9C0C = (B_8018A7F8_usa == 2) ? 1 : 2;
                        gSelection = 0x8C;
                        gTheGame.menu[0].unk_0 = 1;
                        gTheGame.menu[0].unk_C = 0;
                        gTheGame.menu[0].unk_8 = 1;
                        gTheGame.menu[0].unk_4 = (osGetCount() & 0xFF) % 6;
                        func_80089BE0_usa(0, 6);
                        break;

                    case 0x6:
                    case 0x8:
                        gMain = GMAIN_384;
                        gTheGame.unk_9C08 = 2;
                        gTheGame.unk_9C0C = (B_8018A7F8_usa == 6) ? 1 : 2;
                        gSelection = 0xA0;

                        gTheGame.menu[0].unk_0 = 0;
                        gTheGame.menu[0].unk_C = 0;
                        gTheGame.menu[0].unk_8 = (B_8018A7F8_usa == 6) ? 5 : 3;
                        gTheGame.menu[0].unk_4 = (((osGetCount() & 0xF) % 15) * 0x64) + (((osGetCount() >> 4) & 3) | 1);

                        func_80089BE0_usa(0, (B_8018A7F8_usa == 6) ? 8 : 5);

                        gTheGame.menu[1].unk_0 = 0;
                        gTheGame.menu[1].unk_C = 0;
                        gTheGame.menu[1].unk_8 = (B_8018A7F8_usa == 6) ? 5 : 3;
                        gTheGame.menu[1].unk_4 = (((osGetCount() & 0xF) % 15) * 0x64) + (((osGetCount() >> 4) & 3) | 1);

                        func_80089BE0_usa(1, (B_8018A7F8_usa == 6) ? 8 : 5);
                        break;

                    case 0x9:
                        gDemo = GDEMO_2C;
                        gTheGame.unk_9C0C = 2;
                        gReset = 0;
                        gGameStatus &= ~0x80;
                        gpData->unk_00 = 0;
                        gpData->unk_10 = 0;
                        gpData->unk_14 = 7;
                        gpData->unk_08 = screenSet("PROFILE", 0x8E401);
                        func_80009D30_usa(gpData->unk_08, gpData->unk_10);
                        break;
                }
            }
        }

        if ((B_8018A7F0_usa == 0) && (peelActive() == 0) && (gReset == 0) && !screenFlushing() && !screenChangePending()) {
            if (func_8000628C_usa() && func_80024BF4_usa(&heap)) {
                PlaySE(SFX_INIT_TABLE, 2);
                if (func_80024BF4_usa(&heap) && (HVQM2Util_Play((void *)"INTRO.HVQM", 0x1000U, heap) != 0)) {
                    PlaySE(SFX_INIT_TABLE, 2);
                }

                gMain = GMAIN_258;
                gReset = -1;
                gDemo = GDEMO_2C;
                gGameStatus &= ~0x80;
            }
        }

        gpData->unk_04 = var_s3;
    }

    if (!screenFlushing()) {
        peelTick();
    }
}

#if VERSION_USA
#define CHECK_INCORRECT_OS_TV_TYPE(x) ((x) == OS_TV_PAL)
#elif VERSION_EUR
#define CHECK_INCORRECT_OS_TV_TYPE(x) ((x) == OS_TV_NTSC)
#elif VERSION_FRA || VERSION_GER
#define CHECK_INCORRECT_OS_TV_TYPE(x) (((x) == OS_TV_NTSC) || ((x) == OS_TV_MPAL))
#else
#error "No region selected"
#endif

void InitTitle(void) {
    u16 sp10[0x80];
    void *sp110;
    s32 sp114;
    s32 i;

    gTheGame.unk_9C0C = 2;
    giButton = 0;

    for (i = 0; i < ARRAY_COUNT(ganButton); i++) {
        ganButton[i] = 0;
    }

    // funny alignment, current macros does not match
    sp110 = (void *)((((uintptr_t)gBufferHeap + 0xF) + SEGMENT_ROM_SIZE(segment_0CA4A0)) & ~0xF);

    gPlayer[0] = gTheGame.player;
    gPlayer[1] = gTheGame.player;
    gpData = sp110;
    sp110 = (void *)((uintptr_t)sp110 + sizeof(struct_gpData));
    bzero(gpData, sizeof(struct_gpData));
    gpData->unk_14 = 0;
    gpData->unk_04 = 2;

    if (screenLoad("TITLE.SBF", &sp110) != 0) {
        if (B_8018A7F0_usa > 0) {
            if (CHECK_INCORRECT_OS_TV_TYPE(osTvType)) {
                gpData->unk_14 = 1;
                gpData->unk_08 = screenSet("BLANK", 0xFF401);
            } else if (D_800B69B0_usa & 1) {
                gpData->unk_00 = 0;
                gpData->unk_14 = 4;
                gpData->unk_08 = screenSet("EYECATCH", 0xFF401);
            } else {
                gpData->unk_14 = 2;
                gpData->unk_08 = screenSet("NO-CONTROLLER", 0xFF401);
            }
        } else {
            u32 var_a1;

            if ((gDemo == GDEMO_16) || (gDemo == GDEMO_21) || (B_8018A7F8_usa == 9)) {
                var_a1 = 0xE;
            } else {
                var_a1 = -1;
            }
            gpData->unk_14 = 6;
            gpData->unk_08 = screenSet("TITLE", ((var_a1 << 0xC) & 0x7F000) | 0x80401);
            gDemo = GDEMO_2C;
        }

        if (screenFind(&sp114, "COPYRIGHT")) {
            // Cast const away
            func_800296B0_usa(sp10, (char *)gBuildDate, ARRAY_COUNT(sp10));
            screenSetText(sp114, 0x64, sp10);
        }
        if (screenFind(&sp114, "TITLE")) {
            // Cast const away
            func_800296B0_usa(sp10, (char *)gBuildDate, ARRAY_COUNT(sp10));
            screenSetText(sp114, 0x64, sp10);
        }

#if VERSION_USA || VERSION_EUR
        if (screenFind(&sp114, "TITLE")) {
            screenHideText(sp114, 0x64);
        }
#endif
    }

    FadeOutAllSFXs(0x1E);
    func_80002D8C_usa(0x1E);
    if (gpData->unk_14 == 6) {
        PlayMIDI(BGM_INIT_TABLE, 0x3C, 0, 1);
    }
    func_80002E70_usa(D_FLT_800B3B10_usa * 0x7FFF);
    func_80002E34_usa(D_FLT_800B3B14_usa * 0x7FFF);
}

void titleSetup(void) {
    s32 i;

    B_8018A7F0_usa = 0x78;
    B_8018A808_usa = 0;
    B_FLT_8018A7FC_usa = 0.0f;
    B_FLT_8018A800_usa = 0.0f;
    B_FLT_8018A804_usa = 0.0f;
    B_8021BA98_usa = 0;
    B_8018A7F8_usa = 0;
    gGameStatus = 0x300;
    gPlayer[0] = NULL;
    gPlayer[1] = NULL;

    for (i = 0; i < GAME_PLAYER_COUNT; i++) {
        menuInitUser(i);
    }

    func_80046F8C_usa();
}
