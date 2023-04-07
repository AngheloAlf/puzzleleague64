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

#if VERSION_USA || VERSION_EUR || VERSION_GER
INLINE void func_80000450_usa(void) {
    s32 var_s0;

    if (osRecvMesg(&B_801AB7F0_usa, NULL, OS_MESG_NOBLOCK) == 0) {
#if VERSION_EUR || VERSION_GER
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
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000450_fra);
#endif

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

#if VERSION_USA || VERSION_EUR || VERSION_GER
void Idle_ThreadEntry(void *arg) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &sPiMgrCmdQueue, sPiMgrCmdBuff, ARRAY_COUNT(sPiMgrCmdBuff));

    osCreateThread(&sMainThread, 6, pon_main, arg, STACK_TOP(sMainStack), 0xA);

    if (D_800B3AC4_usa == 0) {
        osStartThread(&sMainThread);
    }
    osSetThreadPri(NULL, 0);

    while (true) {}
}
#endif

extern OSScClient B_801AB810_usa;
extern OSSched B_8021AAA0_usa;

extern STACK(B_8021DF50_usa, OS_SC_STACKSIZE);

#if VERSION_USA || VERSION_EUR
void func_80000630_usa(void) {
    s32 mode;

    osCreateMesgQueue(&B_801AB7F0_usa, B_801C6E5C_usa, ARRAY_COUNT(B_801C6E5C_usa));
    osSetEventMesg(OS_EVENT_PRENMI, &B_801AB7F0_usa, (OSMesg)1);

    func_80000450_usa();

    osCreateMesgQueue(&B_8019D158_usa, B_8021BA28_usa, ARRAY_COUNT(B_8021BA28_usa));
    osCreateMesgQueue(&B_801C7058_usa, B_801C6EA0_usa, ARRAY_COUNT(B_801C6EA0_usa));

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
    osSetEventMesg(0xEU, &B_801AB7F0_usa, (OSMesg)1);
    osScAddClient(&B_8021AAA0_usa, &B_801AB810_usa, &B_801C7058_usa);
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

#if VERSION_EUR
    osViSetYScale(0.833);
#endif
}
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", Idle_ThreadEntry);

INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000654_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", func_80000630_usa);
#endif

#if VERSION_USA || VERSION_EUR || VERSION_GER
/**
 * Original name: pon_main
 */
void pon_main(void *arg UNUSED) {
    s32 var_s0 = 0;

    func_80000630_usa();
    gDemo = 0x2C;
    gMain = 0x1F4;
    gReset = -1;
    gTheGame.unk_9C0C = 1;

    while (true) {
        gTheGame.unk_9C10 = 0;

        switch (gMain) {
            case 0x258:
            case 0x2BC:
            case 0x28A:
                gTheGame.unk_9C0C = 1;
                gAllVertex = 0;
                var_s0 = doMenuLoop(var_s0);
                break;

            case 0x383:
                gTheGame.unk_9C0C = 2;
                var_s0 = doMenuLoop(var_s0);
                break;

            case 0x34C:
            case 0x378:
            case 0x384:
            case 0x357:
            case 0x14D:
            case 0x38E:
            case 0x36D:
            case 0x341:
            case 0x1F4:
                var_s0 = doMenuLoop(var_s0);
                break;

            default:
                var_s0 = doGameLoop(var_s0);
                break;
        }
    }
}
#endif

#if VERSION_USA || VERSION_EUR || VERSION_GER
/**
 * Original name: doMenuLoop
 */
s32 doMenuLoop(s32 arg0) {
    s32 var_s2 = 0;
    bool var_s1 = true;
    s32 sp14 = 0;
    s16 *sp10 = NULL;

    while (var_s1) {
        osRecvMesg(&B_801C7058_usa, (OSMesg)&sp10, OS_MESG_BLOCK);

        func_80000450_usa();

        switch (*sp10) {
            case 1:
                osContStartReadData(&gSerialMsgQ);
                if (var_s2 < 2U) {
                    UpdateBuffer(&gInfo[arg0]);
                    gCounter += 1;
                    if (CreateMenuGfxTask(&gInfo[arg0]) != 0) {
                        var_s2 += 1;
                        arg0 ^= 1;
                    }
                }
                osRecvMesg(&gSerialMsgQ, NULL, OS_MESG_BLOCK);
                if (((gMain == 0x384) || (gMain == 0x341)) != 0) {
                    UpdateController();
                } else {
                    UpdateMenuController();
                }

                if ((gGameStatus & 0x80) && (((gMain == 0x384) || (gMain == 0x34C)) != 0) && (DemoCheck(&sp14) != 0)) {
                    gMain = 0x1F4;
                    gReset = -1;
                    var_s1 = false;
                } else {
                    s32 temp_s0_2 = gMain;

                    if (gReset == 0) {
                        if (gMain < 0x384) {
                            switch (gMain) {
                                case 0x1F4:
                                    DoTitle();
                                    break;

                                case 0x258:
                                case 0x28A:
                                case 0x2BC:
                                    DoMenu();
                                    break;

                                case 0x36D:
                                    DoBonus();
                                    break;

                                case 0x378:
                                    DoEditor();
                                    break;

                                case 0x383:
                                    DoStory();
                                    break;

                                case 0x341:
                                    DoMimic();
                                    break;

                                case 0x34C:
                                    DoTutorial();
                                    break;

                                case 0x357:
                                    DoStageClearIntro();
                                    break;
                            }

                            var_s1 &= -(temp_s0_2 == gMain);
                        } else if (((gMain == 0x384) || (gMain == 0x388))) {
                            DoCountDown();
                            var_s1 &= -(((gMain == 0x387) || (gMain == 0x2BC)) == 0);
                        } else {
                            DoGameOver();
                            var_s1 &= -(gMain >= 0x38E);
                        }
                    }
                    LoadDataMain();
                }
                break;

            case 2:
                var_s2 -= 1;
                break;
        }
    }

    while (var_s2 != 0) {
#if VERSION_GER
        if (osRecvMesg(&B_801C7058_usa, (OSMesg)&sp10, OS_MESG_NOBLOCK) == 0) {
            var_s2 -= *sp10 == 2;
        }
#else
        osRecvMesg(&B_801C7058_usa, (OSMesg)&sp10, OS_MESG_BLOCK);
        var_s2 -= *sp10 == 2;
#endif

        func_80000450_usa();
    }

    return arg0;
}
#endif

#if VERSION_USA
/**
 * Original name: doGameLoop
 */
#if 0
//? func_800016D8_usa(struct_gInfo *);                /* extern */
//s32 func_8000177C_usa(struct_gInfo *);              /* extern */
//? SetSongTempo(s32, ?);                        /* extern */
//? PlayGameSong(? *);                           /* extern */
//? DoTetris();                              /* extern */
extern ? gTheGame;
extern ? B_801A6D78_usa;
extern s32 B_801C70A8_usa;
extern u32 B_801C70AC_usa;
extern s32 D_800B3AD8_usa;

s32 doGameLoop(s32 arg0) {
    void *sp10;
    s32 sp14;
    ? *var_a0;
    s16 temp_v1;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    u16 (*var_v1)[0x12C00];
    u16 (*var_v1_2)[0x12C00];
    u16 (*var_v1_3)[0x12C00];
    u16 (*var_v1_4)[0x12C00];
    u32 var_s1;
    u64 temp_ret;

    var_s0 = arg0;
    var_s1 = 0;
    var_s2 = 1;
    sp14 = 0;
    sp10 = NULL;
    temp_ret = osGetTime();
    B_801C70A8_usa = temp_ret;
    B_801C70AC_usa = (u32) temp_ret;
loop_1:
    osRecvMesg(&B_801C7058_usa, &sp10, 1);
    if (osRecvMesg(&B_801AB7F0_usa, NULL, 0) == 0) {
        var_s0_2 = -1;
        func_80002D5C_usa();
        func_80002DE8_usa();
loop_3:
        if (var_s0_2 != 0) {
            var_s0_2 &= -(~osAfterPreNMI() == 0);
        }
        do {

        } while (osViGetCurrentLine() != 0);
        do {
            var_v0 = 0x95FF;
        } while (osViGetCurrentLine() == 0);
        var_v1 = gFramebuffers;
        do {
            *var_v1 = 0;
            var_v0 -= 1;
            var_v1 += 4;
        } while (var_v0 != -1);
        var_v1_2 = gFramebuffers + 0x25800;
        var_v0_2 = 0x95FF;
        do {
            *var_v1_2 = 0;
            var_v0_2 -= 1;
            var_v1_2 += 4;
        } while (var_v0_2 != -1);
        goto loop_3;
    }
    temp_v1 = *sp10;
    switch (temp_v1) {                              /* irregular */
        case 0x2:
            var_s1 -= 1;
            break;
        case 0x1:
            if (var_s1 < 2U) {
                osContStartReadData(&gSerialMsgQ);
                func_800016D8_usa(&gInfo[var_s0]);
                osRecvMesg(&gSerialMsgQ, NULL, 1);
                UpdateController();
                if ((gGameStatus & 0x80) && (DemoCheck(&sp14) != 0)) {
                    gMain = 0x1F4;
                    gReset = -1;
                    var_s2 = 0;
                } else {
                    DoTetris();
                    var_s2 &= -((u32) (gMain - 0x387) < 2U);
                    UpdateBuffer(&gInfo[var_s0]);
                    if (B_801A6D78_usa.unk_0 == 1) {
                        PlayGameSong(&gTheGame);
                        if (gGameStatus & 0x20) {
                            SetSongTempo(D_800B3AD8_usa, 0x6E);
                        }
                    } else {
                        if (B_801A6D78_usa.unk_-5850 != 0) {
                            var_a0 = (&B_801A6D78_usa - 0x5850) - 0x43B8;
                        } else {
                            var_a0 = &B_801A6D78_usa - 0x57D8;
                        }
                        PlayGameSong(var_a0);
                    }
                    LoadDataMain();
                    gCounter += 1;
                    if (func_8000177C_usa(&gInfo[var_s0]) != 0) {
                        var_s1 += 1;
                        var_s0 ^= 1;
                    }
                }
            }
            break;
    }
    if (var_s2 == 0) {
        if (var_s1 != 0) {
loop_32:
            osRecvMesg(&B_801C7058_usa, &sp10, 1);
            var_s1 -= *sp10 == 2;
            if (osRecvMesg(&B_801AB7F0_usa, NULL, 0) == 0) {
                var_s0_3 = -1;
                func_80002D5C_usa();
                func_80002DE8_usa();
loop_34:
                if (var_s0_3 != 0) {
                    var_s0_3 &= -(~osAfterPreNMI() == 0);
                }
                do {

                } while (osViGetCurrentLine() != 0);
                do {
                    var_v0_3 = 0x95FF;
                } while (osViGetCurrentLine() == 0);
                var_v1_3 = gFramebuffers;
                do {
                    *var_v1_3 = 0;
                    var_v0_3 -= 1;
                    var_v1_3 += 4;
                } while (var_v0_3 != -1);
                var_v1_4 = gFramebuffers + 0x25800;
                var_v0_4 = 0x95FF;
                do {
                    *var_v1_4 = 0;
                    var_v0_4 -= 1;
                    var_v1_4 += 4;
                } while (var_v0_4 != -1);
                goto loop_34;
            }
            if (var_s1 == 0) {
                /* Duplicate return node #44. Try simplifying control flow for better match */
                return var_s0;
            }
            goto loop_32;
        }
        return var_s0;
    }
    goto loop_1;
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
INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_800008AC_fra);

INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000A3C_fra);

INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000F90_fra);
#endif
