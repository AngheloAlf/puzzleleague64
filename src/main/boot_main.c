/**
 * Original filename: main.c
 */

#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "PR/sched.h"
#include "buffers.h"
#include "hvqm2util.h"
#include "file.h"
#include "gfx.h"
#include "controller.h"
#include "the_game.h"
#include "update.h"

INLINE void func_80000450_usa(void) {
    s32 var_s0;

    if (osRecvMesg(&B_801AB7F0_usa, NULL, OS_MESG_NOBLOCK) == 0) {
#if REGION_PAL
        osViSetYScale(1.0f);
        osViBlack(1);
#endif

        var_s0 = -1;
        func_80002D5C_usa();
        func_80002DE8_usa();

        while (true) {
            if (var_s0 != 0) {
                var_s0 &= -(~osAfterPreNMI() == 0);
            }

            while (osViGetCurrentLine() != 0) {}
            while (osViGetCurrentLine() == 0) {}

            FRAMEBUFFERS_BACKWARD_SET(0);
        }
    }
}

void bootproc(void) {
    s32 pad[0x10] UNUSED;

    osInitialize();
    osAiSetFrequency(0x4B00);

#if REGION_PAL
    func_80001A80_eur(0);
#endif

    osCreateThread(&sIdleThread, 1, Idle_ThreadEntry, NULL, STACK_TOP(sIdleStack), 0xA);
    osStartThread(&sIdleThread);
}

void Idle_ThreadEntry(void *arg) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &sPiMgrCmdQueue, sPiMgrCmdBuff, ARRAY_COUNT(sPiMgrCmdBuff));

    osCreateThread(&sMainThread, 6, pon_main, arg, STACK_TOP(sMainStack), 0xA);

    if (D_800B3AC4_usa == 0) {
        osStartThread(&sMainThread);
    }
    osSetThreadPri(NULL, 0);

    while (true) {}
}

extern OSScClient B_801AB810_usa;
extern OSSched B_8021AAA0_usa;

extern STACK(B_8021DF50_usa, OS_SC_STACKSIZE);

void func_80000630_usa(void) {
    s32 mode;

    osCreateMesgQueue(&B_801AB7F0_usa, B_801C6E5C_usa, ARRAY_COUNT(B_801C6E5C_usa));
    osSetEventMesg(OS_EVENT_PRENMI, &B_801AB7F0_usa, (OSMesg *)1);

    func_80000450_usa();

    osCreateMesgQueue(&B_8019D158_usa, B_8021BA28_usa, ARRAY_COUNT(B_8021BA28_usa));
    osCreateMesgQueue(&gfxFrameMsgQ, B_801C6EA0_usa, ARRAY_COUNT(B_801C6EA0_usa));

    switch (osTvType) {
        case OS_TV_PAL:
            mode = OS_VI_FPAL_LAN1;
            break;

        case OS_TV_MPAL:
            mode = OS_VI_MPAL_LAN1;
            break;

        case OS_TV_NTSC:
            mode = OS_VI_NTSC_LAN1;
            break;

        default:
            UNREACHABLE;
            break;
    }

    osCreateScheduler(&B_8021AAA0_usa, STACK_TOP(B_8021DF50_usa), 0x12, mode, 1);
    osSetEventMesg(OS_EVENT_PRENMI, &B_801AB7F0_usa, (OSMesg *)1);
    osScAddClient(&B_8021AAA0_usa, &B_801AB810_usa, &gfxFrameMsgQ);
    B_801AAB9C_usa = osScGetCmdQ(&B_8021AAA0_usa);

    InitGFX();
    InitController();
    InitGameAudioSystem();
    fileSetup();
    titleSetup();
    imageSetup();
    bitmapSetup();
    screenSetup();
    peelSetup();
    HVQM2Util_80040A4C_usa();

#if REGION_PAL
    osViSetYScale(0.833);
#endif
}

/**
 * Original name: pon_main
 */
void pon_main(void *arg UNUSED) {
    s32 var_s0 = 0;

    func_80000630_usa();
    gDemo = 0x2C;
    gMain = GMAIN_TITLE;
    gReset = -1;
    gTheGame.unk_9C0C = 1;

    while (true) {
        gTheGame.unk_9C10 = 0;

        switch (gMain) {
            case GMAIN_258:
            case GMAIN_2BC:
            case GMAIN_28A:
                gTheGame.unk_9C0C = 1;
                gAllVertex = 0;
                var_s0 = doMenuLoop(var_s0);
                break;

            case GMAIN_STORY:
                gTheGame.unk_9C0C = 2;
                var_s0 = doMenuLoop(var_s0);
                break;

            case GMAIN_TUTORIAL:
            case GMAIN_EDITOR:
            case GMAIN_384:
            case GMAIN_STAGE_CLEAR_INTRO:
            case GMAIN_14D:
            case GMAIN_38E:
            case GMAIN_BONUS:
            case GMAIN_MIMIC:
            case GMAIN_TITLE:
                var_s0 = doMenuLoop(var_s0);
                break;

            default:
                var_s0 = doGameLoop(var_s0);
                break;
        }
    }
}

/**
 * Original name: doMenuLoop
 */
s32 doMenuLoop(s32 arg0) {
    u32 var_s2 = 0;
    bool var_s1 = true;
    s32 sp14 = 0;
    s16 *sp10 = NULL;

    while (var_s1) {
        osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&sp10, OS_MESG_BLOCK);

        func_80000450_usa();

        switch (*sp10) {
            case 1:
                osContStartReadData(&gSerialMsgQ);
                if (var_s2 < ARRAY_COUNTU(gInfo)) {
                    UpdateBuffer(&gInfo[arg0]);
                    gCounter++;
                    if (CreateMenuGfxTask(&gInfo[arg0]) != 0) {
                        var_s2++;
                        arg0 ^= 1;
                    }
                }

                osRecvMesg(&gSerialMsgQ, NULL, OS_MESG_BLOCK);
                if ((gMain == GMAIN_384) || (gMain == GMAIN_MIMIC)) {
                    UpdateController();
                } else {
                    UpdateMenuController();
                }

                if ((gGameStatus & 0x80) && ((gMain == GMAIN_384) || (gMain == GMAIN_TUTORIAL)) &&
                    (DemoCheck(&sp14) != 0)) {
                    gMain = GMAIN_TITLE;
                    gReset = -1;
                    var_s1 = false;
                } else {
                    enum_gMain temp_s0_2 = gMain;

                    if (gReset == 0) {
                        if (gMain < GMAIN_384) {
                            switch (gMain) {
                                case GMAIN_TITLE:
                                    DoTitle();
                                    break;

                                case GMAIN_258:
                                case GMAIN_28A:
                                case GMAIN_2BC:
                                    DoMenu();
                                    break;

                                case GMAIN_BONUS:
                                    DoBonus();
                                    break;

                                case GMAIN_EDITOR:
                                    DoEditor();
                                    break;

                                case GMAIN_STORY:
                                    DoStory();
                                    break;

                                case GMAIN_MIMIC:
                                    DoMimic();
                                    break;

                                case GMAIN_TUTORIAL:
                                    DoTutorial();
                                    break;

                                case GMAIN_STAGE_CLEAR_INTRO:
                                    DoStageClearIntro();
                                    break;

                                default:
                                    break;
                            }

                            if (temp_s0_2 != gMain) {
                                var_s1 = false;
                            }
                        } else if (((gMain == GMAIN_384) || (gMain == GMAIN_388))) {
                            DoCountDown();

                            if ((gMain == GMAIN_387) || (gMain == GMAIN_2BC)) {
                                var_s1 = false;
                            }
                        } else {
                            DoGameOver();

                            if (gMain < GMAIN_38E) {
                                var_s1 = false;
                            }
                        }
                    }
                    AudioUpdate();
                }
                break;

            case 2:
                var_s2--;
                break;
        }
    }

    while (var_s2 > 0) {
#if VERSION_GER || VERSION_FRA
        if (osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&sp10, OS_MESG_NOBLOCK) == 0) {
            if (*sp10 == 2) {
                var_s2--;
            }
        }
#else
        osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&sp10, OS_MESG_BLOCK);
        if (*sp10 == 2) {
            var_s2--;
        }
#endif

        func_80000450_usa();
    }

    return arg0;
}

#if VERSION_USA
/**
 * Original name: doGameLoop
 */
s32 PlayGameSong(TheGame_unk_0000 *game);
UNK_RET SetSongTempo(UNK_TYPE, UNK_TYPE);

#ifdef NON_EQUIVALENT
s32 doGameLoop(s32 arg0) {
    s32 sp14;
    s16 *sp10;
    bool var_s2;
    u32 var_s1;

    var_s1 = 0;
    var_s2 = true;
    sp14 = 0;
    sp10 = NULL;

    gTime = osGetTime();

    while (var_s2) {
        osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&sp10, OS_MESG_BLOCK);
        func_80000450_usa();

        switch (*sp10) {
            case 0x1:
                if (var_s1 < 2U) {
                    osContStartReadData(&gSerialMsgQ);
                    CreateGameGfxTask1(&gInfo[arg0]);
                    osRecvMesg(&gSerialMsgQ, NULL, OS_MESG_BLOCK);
                    UpdateController();
                    if ((gGameStatus & 0x80) && (DemoCheck(&sp14) != 0)) {
                        gMain = GMAIN_TITLE;
                        gReset = -1;
                        var_s2 = false;
                    } else {
                        DoTetris();

                        if ((gMain < GMAIN_387) || (gMain > GMAIN_388)) {
                            var_s2 = false;
                        }
                        UpdateBuffer(&gInfo[arg0]);

                        if (gTheGame.unk_9C08 == 1) {
                            PlayGameSong(&gTheGame.unk_0000);
                            if (gGameStatus & 0x20) {
                                SetSongTempo(last_song_handle, 0x6E);
                            }
                        } else {
                            if (gTheGame.unk_0000[0].unk_43B8 == 0) {
                                PlayGameSong(&gTheGame.unk_0000[1]);
                            } else {
                                PlayGameSong(&gTheGame.unk_0000[0]);
                            }
                        }

                        AudioUpdate();
                        gCounter++;
                        if (CreateGameGfxTask2(&gInfo[arg0]) != 0) {
                            var_s1++;
                            arg0 ^= 1;
                        }
                    }
                }
                break;

            case 0x2:
                var_s1--;
                break;
        }
    }

    while (var_s1 != 0) {
        osRecvMesg(&gfxFrameMsgQ, (OSMesg *)&sp10, OS_MESG_BLOCK);
        if (*sp10 == 2) {
            var_s1--;
        }

        func_80000450_usa();
    }

    return arg0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/boot_main", doGameLoop);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", doGameLoop);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", doGameLoop);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", doGameLoop);
#endif
