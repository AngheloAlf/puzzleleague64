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

#if 0
typedef enum struct_gpData_eMode {
    TM_NONE = 0,
    TM_CARD = 1,
    TM_LOGO = 2,
    TM_MAIN = 3,
    TM_CHAR = 4,
} struct_gpData_eMode;
#endif

// The values from the original struct are shifted.
// Try to use the original names whenever possible
typedef enum struct_gpData_eMode {
    /* 0 */ TM_0,
    /* 1 */ TM_1,
    /* 2 */ TM_2,
    /* 3 */ TM_3,
    /* 4 */ TM_4,
    /* 5 */ TM_5,
    /* 6 */ TM_LOGO, /* Original name: TM_LOGO */
                     // TM_MAIN ??
    /* 7 */ TM_CHAR, /* Original name: TM_CHAR */
} struct_gpData_eMode;

typedef struct struct_gpData {
    /* 0x00 */ s32 nTick;                 /* Original name: nTick */
    /* 0x04 */ u32 nMode;                 /* Original name: nMode */
    /* 0x08 */ s32 iScreen;               /* Original name: iScreen */
    /* 0x0C */ s32 nTickDemo;             /* Original name: nTickDemo */
    /* 0x10 */ s32 iCharacter;            /* Original name: iCharacter */
    /* 0x14 */ struct_gpData_eMode eMode; /* Original name: eMode */
} struct_gpData;                          // size = 0x18

static s32 B_8018A7F0_usa;

/**
 * Original name: gpData
 */
static struct_gpData *gpData;

/**
 * Original name: geDemoTitle
 */
#if VERSION_USA
// no longer static on other versions
static
#endif
    enum_geDemoTitle geDemoTitle;

static f32 B_FLT_8018A7FC_usa;
static f32 B_FLT_8018A800_usa;
static f32 B_FLT_8018A804_usa;
static u32 B_8018A808_usa;

u32 D_800B5890_usa[] = {
    0xFF000000, 0x00FF0000, 0x0000FF00, 0x00FFFF00, 0xFF00FF00, 0xFFFF0000, 0x00000000,
};

void func_80005C00_usa(void) {
    if (B_8018A808_usa < ARRAY_COUNTU(D_800B5890_usa)) {
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

/**
 * Original name: titleDrawImage
 */
void titleDrawImage(Gfx **gfxP, s32 arg1 UNUSED, s32 nTag) {
    Gfx *gfx = *gfxP;
    f32 var_fv1;
    f32 var_ft1;
    f32 var_ft0;
    s32 var_t9;

    switch (nTag) {
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
                gDPFillRectangle(gfx++, 0, var_t9, SCREEN_WIDTH - 1, var_t9);

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
            gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR |
                                            G_LOD | G_CLIPPING);
            break;

        case 0x78:
            gDPPipeSync(gfx++);
            gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BOTH | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR |
                                            G_LOD | G_CLIPPING);
            gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
            gDPSetCycleType(gfx++, G_CYC_FILL);
            gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetFillColor(gfx++, (GPACK_RGBA5551(255, 0, 0, 1) << 16) | GPACK_RGBA5551(255, 0, 0, 1));

            //! @bug: reading from unset variable var_t9
            gDPFillRectangle(gfx++, 0, var_t9, SCREEN_WIDTH - 1, var_t9);
            break;
    }

    *gfxP = gfx;
}

/**
 * Original name: DrawTitle
 */
void DrawTitle(void) {
    if (gpData->eMode == TM_CHAR) {
        screenDraw(&glistp, menuDrawProfile);
    } else {
        screenDraw(&glistp, titleDrawImage);
    }

    if (!screenFlushing()) {
        pon_DrawLoadingMessage(&glistp);
    }
}

/**
 * Original name: CheckTitleInput
 */
INLINE nbool CheckTitleInput(void) {
    s32 iController;

    // single iteration loop
    for (iController = 0; iController < 1; iController++) {
        if ((gTheGame.controller[iController].position != -1) && (gTheGame.controller[iController].touch_button != 0)) {
            return ntrue;
        }
    }

    return nfalse;
}

/**
 * Original name: DoTitle
 */
void DoTitle(void) {
    void *heap;
    s32 iCharacter;
    u32 nMode;
    s32 nTick;
    s32 iScreen = gpData->iScreen;
    screenTick_arg0 anCommand;

    gpData->nTick++;
    anCommand.unk_0 = 0;
    anCommand.unk_4 = 0;
    screenTick(&anCommand);
    nTick = gpData->nTick;

    if (gpData->eMode == TM_1) {
        osViBlack(1);
    } else if (gpData->eMode == TM_2) {
        screenShowText(iScreen, 0x64);
        screenShowImage(iScreen, 0x64);
    } else if (gpData->eMode == TM_CHAR) {
        if (!peelActive()) {
            if (CheckTitleInput() && (gReset == 0)) {
                gReset = -1;
            }
        }

        if (nTick % 600 == 0) {
            menuFindCharacterMax(&iCharacter);
            gpData->iCharacter++;
            if (iCharacter < gpData->iCharacter) {
                gReset = -1;
                FadeOutSong(last_song_handle, 0x3C);
            } else {
                menuInitProfile(iScreen, gpData->iCharacter);
            }
        }

        if ((nTick + 2) % 600 == 0) {
            func_8002CFE4_usa(0xE);
        }
    } else if (gpData->eMode == TM_3) {
        func_80005C00_usa();
        if (B_8018A808_usa == ARRAY_COUNTU(D_800B5890_usa)) {
            gpData->nTick = 0;
            gpData->eMode = TM_4;
            gpData->iScreen = screenSet("EYECATCH", 0x8E001);
        }
    } else if (gpData->eMode == TM_4) {
        if (!screenFlushing() && !screenChangePending() && func_80024BF4_usa(&heap)) {
            HVQM2Util_Play((void *)"EYECATCH.HVQM", 0, heap);
            gpData->eMode = TM_5;
        }
    } else if (gpData->eMode == TM_5) {
        s32 temp_v0 = screenSet("TITLE", 0x8E401);

        if (temp_v0 != iScreen) {
            gpData->nTick = 0;
            gpData->eMode = TM_LOGO;
            gpData->iScreen = temp_v0;
            PlayMIDI(BGM_INIT_TABLE, 0x3C, 0, 0);
        }
    } else { /* TM_0, TM_LOGO */
        nMode = gpData->nMode;

        if (B_8018A7F0_usa > 0) {
            B_8018A7F0_usa--;
            screenShowImage(iScreen, 0x6E);
            screenHideImage(iScreen, 0x64);
        } else {
            screenHideImage(iScreen, 0x6E);
            if (nTick & 8) {
                screenHideImage(iScreen, 0x64);
            } else {
                screenShowImage(iScreen, 0x64);
            }
        }

        if (gTheGame.controller[0].button & Z_TRIG) {
            if (gTheGame.controller[0].touch_button != 0) {
                ganButton[giButton] = gTheGame.controller[0].touch_button;
                giButton = (giButton + 1) % ARRAY_COUNTU(ganButton);

                // Cheat code: Start from level 50~99 in Marathon mode
                if ((ganButton[(giButton - 4) % ARRAY_COUNTU(ganButton)] == B_BUTTON) &&
                    (ganButton[(giButton - 3) % ARRAY_COUNTU(ganButton)] == A_BUTTON)) {
                    if ((ganButton[(giButton - 2) % ARRAY_COUNTU(ganButton)] == L_TRIG) &&
                        (ganButton[(giButton - 1) % ARRAY_COUNTU(ganButton)] == L_TRIG)) {
                        gGameStatus ^= 1;
                        PlaySE(SFX_INIT_TABLE, 9);
                    }
                }

                // Cheat code: Unlock all puzzles in Puzzle University
                if ((ganButton[(giButton - 8) % ARRAY_COUNTU(ganButton)] == A_BUTTON) &&
                    (ganButton[(giButton - 7) % ARRAY_COUNTU(ganButton)] == B_BUTTON)) {
                    if ((ganButton[(giButton - 6) % ARRAY_COUNTU(ganButton)] == R_TRIG) &&
                        (ganButton[(giButton - 5) % ARRAY_COUNTU(ganButton)] == A_BUTTON)) {
                        if ((ganButton[(giButton - 4) % ARRAY_COUNTU(ganButton)] == A_BUTTON) &&
                            (ganButton[(giButton - 3) % ARRAY_COUNTU(ganButton)] == B_BUTTON)) {
                            if ((ganButton[(giButton - 2) % ARRAY_COUNTU(ganButton)] == R_TRIG) &&
                                (ganButton[(giButton - 1) % ARRAY_COUNTU(ganButton)] == A_BUTTON)) {
                                gbOpenTitle = ~gbOpenTitle;
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

        if (nMode & 2) {
            nMode = (D_800B69B0_usa & 1) ? 5 : 1;
            gpData->nTickDemo = 0;
            gpData->nTick = 0;
        }

        if (nMode & 4) {
            gpData->nTickDemo++;
            if ((gpData->nTickDemo == 900) && (geDemoTitle != TD_VS_3D)) {
                FadeOutSong(last_song_handle, 0x3C);
            }

            if (gpData->nTickDemo >= 960) {
                gDemo = GDEMO_0B;
                gReset = -1;
                gPlayer[0] = gTheGame.player;
                gPlayer[1] = gTheGame.player;
                gTheGame.tetrisWell[0].win = 0;
                gTheGame.tetrisWell[1].win = 0;
                brainbrain[0].speed = -1;
                brainbrain[1].speed = -1;
                gGameStatus |= 0x80;

                geDemoTitle++;
                if (geDemoTitle == TD_LAST) {
                    geDemoTitle = TD_RULES_1;
                }

                switch (geDemoTitle) {
                    case TD_RULES_1:
                        gMain = GMAIN_TUTORIAL;
                        gTheGame.totalPlayer = 1;
                        gTheGame.dimension = DIMENSION_2D;
                        gSelection = 0x64;
                        gTheGame.menu[0].game = 1;
                        break;

                    case TD_RULES_2:
                        gMain = GMAIN_TUTORIAL;
                        gTheGame.totalPlayer = 1;
                        gTheGame.dimension = DIMENSION_2D;
                        gSelection = 0x64;
                        gTheGame.menu[0].game = 2;
                        break;

                    case TD_RULES_VS1:
                        gMain = GMAIN_TUTORIAL;
                        gTheGame.totalPlayer = 1;
                        gTheGame.dimension = DIMENSION_2D;
                        gSelection = 0x64;
                        gTheGame.menu[0].game = 3;
                        break;

                    case TD_RULES_VS2:
                        gMain = GMAIN_TUTORIAL;
                        gTheGame.totalPlayer = 1;
                        gTheGame.dimension = DIMENSION_2D;
                        gSelection = 0x64;
                        gTheGame.menu[0].game = 4;
                        break;

                    case TD_ENDLESS_2D:
                    case TD_ENDLESS_3D:
                        gMain = GMAIN_384;
                        gTheGame.totalPlayer = 1;
                        gTheGame.dimension = (geDemoTitle == TD_ENDLESS_2D) ? DIMENSION_2D : DIMENSION_3D;
                        gSelection = 0x8C;
                        gTheGame.menu[0].game = 1;
                        gTheGame.menu[0].misc = 0;
                        gTheGame.menu[0].speed = 1;
                        gTheGame.menu[0].stage = (osGetCount() & 0xFF) % 6;
                        DemoCPU(0, 6);
                        break;

                    case TD_VS_2D:
                    case TD_VS_3D:
                        gMain = GMAIN_384;
                        gTheGame.totalPlayer = 2;
                        gTheGame.dimension = (geDemoTitle == TD_VS_2D) ? DIMENSION_2D : DIMENSION_3D;
                        gSelection = 0xA0;

                        gTheGame.menu[0].game = 0;
                        gTheGame.menu[0].misc = 0;
                        gTheGame.menu[0].speed = (geDemoTitle == TD_VS_2D) ? 5 : 3;
                        gTheGame.menu[0].stage = (((osGetCount() & 0xF) % 15) * 0x64) + (((osGetCount() >> 4) & 3) | 1);

                        DemoCPU(0, (geDemoTitle == TD_VS_2D) ? 8 : 5);

                        gTheGame.menu[1].game = 0;
                        gTheGame.menu[1].misc = 0;
                        gTheGame.menu[1].speed = (geDemoTitle == TD_VS_2D) ? 5 : 3;
                        gTheGame.menu[1].stage = (((osGetCount() & 0xF) % 15) * 0x64) + (((osGetCount() >> 4) & 3) | 1);

                        DemoCPU(1, (geDemoTitle == TD_VS_2D) ? 8 : 5);
                        break;

                    case TD_PROFILE:
                        gDemo = GDEMO_2C;
                        gTheGame.dimension = DIMENSION_3D;
                        gReset = 0;
                        gGameStatus &= ~0x80;
                        gpData->nTick = 0;
                        gpData->iCharacter = 0;
                        gpData->eMode = TM_CHAR;
                        gpData->iScreen = screenSet("PROFILE", 0x8E401);
                        menuInitProfile(gpData->iScreen, gpData->iCharacter);
                        break;

                    default:
                        break;
                }
            }
        }

        if ((B_8018A7F0_usa == 0) && !peelActive() && (gReset == 0)) {
            if (!screenFlushing() && !screenChangePending()) {
                if (CheckTitleInput() && func_80024BF4_usa(&heap)) {
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
        }

        gpData->nMode = nMode;
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

/**
 * Original name: InitTitle
 */
void InitTitle(void) {
    u16 sp10[0x80];
    void *pHeap;
    s32 sp114;
    s32 i;

#if 0
    // Local variables
    void * pHeap; // r1+0x28
    struct_image_c_92 * pImage; // r1+0x24
    @enum$94peel_c ePeel; // r1+0x8
#endif

    gTheGame.dimension = DIMENSION_3D;
    giButton = 0;

    for (i = 0; i < ARRAY_COUNT(ganButton); i++) {
        ganButton[i] = 0;
    }

    // funny alignment, current macros does not match
    pHeap = (void *)((((uintptr_t)gBufferHeap + 0xF) + SEGMENT_ROM_SIZE(segment_0CA4A0)) & ~0xF);

    gPlayer[0] = gTheGame.player;
    gPlayer[1] = gTheGame.player;

    gpData = pHeap;
    pHeap = (void *)((uintptr_t)pHeap + sizeof(struct_gpData));

    bzero(gpData, sizeof(struct_gpData));
    gpData->eMode = TM_0;
    gpData->nMode = 2;

    if (screenLoad("TITLE.SBF", &pHeap) != 0) {
        if (B_8018A7F0_usa > 0) {
            if (CHECK_INCORRECT_OS_TV_TYPE(osTvType)) {
                gpData->eMode = TM_1;
                gpData->iScreen = screenSet("BLANK", 0xFF401);
            } else if (D_800B69B0_usa & 1) {
                gpData->nTick = 0;
                gpData->eMode = TM_4;
                gpData->iScreen = screenSet("EYECATCH", 0xFF401);
            } else {
                gpData->eMode = TM_2;
                gpData->iScreen = screenSet("NO-CONTROLLER", 0xFF401);
            }
        } else {
            u32 var_a1;

            if ((gDemo == GDEMO_16) || (gDemo == GDEMO_21) || (geDemoTitle == TD_PROFILE)) {
                var_a1 = 0xE;
            } else {
                var_a1 = -1;
            }
            gpData->eMode = TM_LOGO;
            gpData->iScreen = screenSet("TITLE", ((var_a1 << 0xC) & 0x7F000) | 0x80401);
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
    if (gpData->eMode == TM_LOGO) {
        PlayMIDI(BGM_INIT_TABLE, 0x3C, 0, 1);
    }
    func_80002E70_usa(D_FLT_800B3B10_usa * 0x7FFF);
    func_80002E34_usa(D_FLT_800B3B14_usa * 0x7FFF);
}

/**
 * Original name: titleSetup
 */
void titleSetup(void) {
    s32 i;

    B_8018A7F0_usa = 0x78;
    B_8018A808_usa = 0;
    B_FLT_8018A7FC_usa = 0.0f;
    B_FLT_8018A800_usa = 0.0f;
    B_FLT_8018A804_usa = 0.0f;
    gbOpenTitle = 0;
    geDemoTitle = TD_NONE;
    gGameStatus = 0x300;
    gPlayer[0] = NULL;
    gPlayer[1] = NULL;

    for (i = 0; i < GAME_PLAYER_COUNT; i++) {
        menuInitUser(i);
    }

    func_80046F8C_usa();
}
