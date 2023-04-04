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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/boot_main", func_80000450_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", func_80000450_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000450_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", func_80000450_ger);
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

#if VERSION_USA
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
    s32 *var_v1;
    s32 var_s0;
    s32 mode;
    s32 var_v0;

    osCreateMesgQueue(&B_801AB7F0_usa, B_801C6E5C_usa, ARRAY_COUNT(B_801C6E5C_usa));
    osSetEventMesg(0xEU, &B_801AB7F0_usa, (OSMesg)1);

    if (osRecvMesg(&B_801AB7F0_usa, NULL, 0) == 0) {
        var_s0 = -1;
        func_80002D5C_usa();
        func_80002DE8_usa();

        while (true) {
            if (var_s0 != 0) {
                var_s0 &= -(~osAfterPreNMI() == 0);
            }

            while (osViGetCurrentLine() != 0) {}
            while (osViGetCurrentLine() == 0) {}

            var_v1 = (void *)gFramebuffers[0];
            for (var_v0 = 0x95FF; var_v0 != -1; var_v0--) {
                *var_v1 = 0;
                var_v1++;
            }

            var_v1 = (void *)gFramebuffers[1];
            for (var_v0 = 0x95FF; var_v0 != -1; var_v0--) {
                *var_v1 = 0;
                var_v1++;
            }
        }
    }

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
}

/**
 * Original name: pon_main
 */
void pon_main(void *arg UNUSED) {
    s32 var_s0 = 0;

    func_80000630_usa();
    gDemo = 0x2C;
    gMain = 0x1F4;
    gReset = -1;
    B_801A6D7C_usa[0] = 1;

    while (true) {
        B_801A6D7C_usa[1] = 0;

        switch (gMain) {
            case 0x258:
            case 0x2BC:
            case 0x28A:
                B_801A6D7C_usa[0] = 1;
                gAllVertex = 0;
                var_s0 = doMenuLoop(var_s0);
                break;

            case 0x383:
                B_801A6D7C_usa[0] = 2;
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

/**
 * Original name: doMenuLoop
 */
s32 doMenuLoop(s32 arg0) {
    s32 var_s2 = 0;
    s32 var_s1 = 1;
    s32 sp14 = 0;
    s16 *sp10 = NULL;
    u32 *var_v1;
    s32 var_s0;
    s32 var_v0;

    while (var_s1 != 0) {
        osRecvMesg(&B_801C7058_usa, (OSMesg)&sp10, OS_MESG_BLOCK);
        if (osRecvMesg(&B_801AB7F0_usa, NULL, OS_MESG_NOBLOCK) == 0) {
            var_s0 = -1;
            func_80002D5C_usa();
            func_80002DE8_usa();
            while (true) {
                if (var_s0 != 0) {
                    var_s0 &= -(~osAfterPreNMI() == 0);
                }
                while (osViGetCurrentLine() != 0) {}
                while (osViGetCurrentLine() == 0) {}

                var_v1 = (void *)gFramebuffers[0];
                for (var_v0 = 0x95FF; var_v0 != -1; var_v0--) {
                    *var_v1 = 0;
                    var_v1++;
                }
                var_v1 = (void *)gFramebuffers[1];
                for (var_v0 = 0x95FF; var_v0 != -1; var_v0--) {
                    *var_v1 = 0;
                    var_v1++;
                }
            }
        }

        switch (*sp10) {
            case 1:
                osContStartReadData(&B_801AB988_usa);
                if (var_s2 < 2U) {
                    func_80059F84_usa(&gInfo[arg0]);
                    D_800BE340_usa += 1;
                    if (CreateMenuGfxTask(&gInfo[arg0]) != 0) {
                        var_s2 += 1;
                        arg0 ^= 1;
                    }
                }
                osRecvMesg(&B_801AB988_usa, NULL, OS_MESG_BLOCK);
                if (((gMain == 0x384) || (gMain == 0x341)) != 0) {
                    UpdateController();
                } else {
                    UpdateMenuController();
                }

                if ((B_801AB8E0_usa & 0x80) && (((gMain == 0x384) || (gMain == 0x34C)) != 0) &&
                    (DemoCheck(&sp14) != 0)) {
                    gMain = 0x1F4;
                    gReset = -1;
                    var_s1 = 0;
                } else {
                    s32 temp_s0_2;
                    temp_s0_2 = gMain;

                    if (gReset == 0) {
                        if (gMain < 0x384) {
                            switch (gMain) { /* switch 1; irregular */
                                case 0x1F4:
                                    func_800062D0_usa();
                                    break;

                                case 0x258:
                                case 0x28A:
                                case 0x2BC:
                                    func_8001AEB0_usa();
                                    break;

                                case 0x36D:
                                    DoBonus();
                                    break;

                                case 0x378:
                                    func_800308A8_usa();
                                    break;

                                case 0x383:
                                    func_8002B8E8_usa();
                                    break;

                                case 0x341:
                                    func_80085EEC_usa();
                                    break;

                                case 0x34C:
                                    func_80088570_usa();
                                    break;

                                case 0x357:
                                    func_80033B10_usa();
                                    break;
                            }

                            var_s1 &= -(temp_s0_2 == gMain);
                        } else if (((gMain == 0x384) || (gMain == 0x388))) {
                            func_800326A0_usa();
                            var_s1 &= -(((gMain == 0x387) || (gMain == 0x2BC)) == 0);
                        } else {
                            func_8003E4BC_usa();
                            var_s1 &= -(gMain >= 0x38E);
                        }
                    }
                    func_800039C0_usa();
                }
                break;

            case 2:
                var_s2 -= 1;
                break;
        }
    }

    while (var_s2 != 0) {
        osRecvMesg(&B_801C7058_usa, (OSMesg)&sp10, OS_MESG_BLOCK);
        var_s2 -= *sp10 == 2;
        if (osRecvMesg(&B_801AB7F0_usa, NULL, OS_MESG_NOBLOCK) == 0) {
            var_s0 = -1;
            func_80002D5C_usa();
            func_80002DE8_usa();

            while (true) {
                if (var_s0 != 0) {
                    var_s0 &= -(~osAfterPreNMI() == 0);
                }

                while (osViGetCurrentLine() != 0) {}
                while (osViGetCurrentLine() == 0) {}

                var_v1 = (void *)gFramebuffers[0];
                for (var_v0 = 0x95FF; var_v0 != -1; var_v0--) {
                    *var_v1 = 0;
                    var_v1++;
                }
                var_v1 = (void *)gFramebuffers[1];
                for (var_v0 = 0x95FF; var_v0 != -1; var_v0--) {
                    *var_v1 = 0;
                    var_v1++;
                }
            }
        }
    }

    return arg0;
}

/**
 * Original name: doGameLoop
 */
INCLUDE_ASM("asm/usa/nonmatchings/main/boot_main", doGameLoop);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", Idle_ThreadEntry);

INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", func_80000654_eur);

INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", func_800008AC_eur);

INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", func_80000A3C_eur);

INCLUDE_ASM("asm/eur/nonmatchings/main/boot_main", func_80000F88_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", Idle_ThreadEntry);

INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000654_fra);

INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_800008AC_fra);

INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000A3C_fra);

INCLUDE_ASM("asm/fra/nonmatchings/main/boot_main", func_80000F90_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", Idle_ThreadEntry);

INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", func_80000654_ger);

INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", func_800008AC_ger);

INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", func_80000A3C_ger);

INCLUDE_ASM("asm/ger/nonmatchings/main/boot_main", func_80000F90_ger);
#endif
