/**
 * Original filename: tetris.c
 */

#include "tetris.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "ai.h"
#include "animate.h"
#include "animation.h"
#include "combo.h"
#include "dlist.h"
#include "fade.h"
#include "init3d.h"
#include "other.h"
#include "peel.h"
#include "sound.h"
#include "text.h"
#include "update.h"
#include "update3d.h"

#if VERSION_USA
#ifdef NON_EQUIVALENT
BlockType RandomBlock(tetWell *well) {
    s32 temp_a0;
    s32 var_t0 = 6;
    s32 temp3 = 1;
    f32 temp;

    if (well->unk_43E4 != 0) {
        var_t0 = 5;
    }
    temp_a0 = gTheGame.unk_9C10 + 0x29A74E;
    gTheGame.unk_9C10 = temp_a0 + (temp_a0 * 0x31EF68);
    temp = (gTheGame.unk_9C10 & 0x7FFFFFFF);
    temp /= 0x7FFFFFFF;
    temp *= var_t0;
    temp += temp3;
    temp_a0 = temp;
    return temp_a0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", RandomBlock);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetris", RandomBlock);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetris", RandomBlock);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetris", RandomBlock);
#endif

INLINE void ReturnSecond(s32 *second) {
    OSTime time = osGetTime();
    u64 microseconds = OS_CYCLES_TO_USEC(time - gTime);

    *second = microseconds / 1000000;
    if (*second == 1) {
        gTime = time;
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_80089828_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetris", func_80089BD8_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetris", func_80088278_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetris", func_80088438_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_8008997C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetris", func_80089D2C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetris", func_800883CC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetris", func_8008858C_ger);
#endif

s32 DemoCheck(s32 *frame) {
    func_800545E4_usa(1);

    if ((gTheGame.controller[0].touch_button != 0) || (gDemo == GDEMO_16)) {
        gDemo = GDEMO_16;
        gTheGame.unk_9C1C = 0;
        gTheGame.unk_9C18 = 0;
        gTheGame.unk_9C14 = 0;

#if VERSION_USA
        gGameStatus >>= 0x10;
#else
        if (B_801C607C_eur != 9) {
            gGameStatus >>= 0x10;
        }
#endif

        FadeOutSong(last_song_handle, 60);
        return -1;
    }

    if ((*frame > ADJUST_FRAMERATE(1800)) && (gMain == GMAIN_387)) {
        gDemo = GDEMO_21;
        gTheGame.unk_9C1C = 0;
        gTheGame.unk_9C18 = 0;
        gTheGame.unk_9C14 = 0;
        gGameStatus >>= 0x10;
        FadeOutSong(last_song_handle, 60);
        return -1;
    }

    *frame += 1;
    gDemo = GDEMO_0B;
    return 0;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_80089BE0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetris", func_80089FC8_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetris", func_80088668_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetris", func_80088828_ger);
#endif

#if VERSION_USA
#if 0
? InitGameStateVar();                               /* extern */
? func_800325F8_usa();                              /* extern */
? InitPause();                              /* extern */
? InitGameOver();                              /* extern */
s32 AnimationRandom(?);                           /* extern */
? InitMiscStuff();                              /* extern */
? func_80054020_usa();                              /* extern */
? InitCursor(s8 *);                          /* extern */
? func_800545E4_usa(s32);                           /* extern */
? func_80054624_usa(s32);                           /* extern */
? func_800552F4_usa();                              /* extern */
? Init3DNewRow(s8 *);                          /* extern */
? Init3DCursor(s8 *, s32);                     /* extern */
? Init3DTetrisBlocks(s8 *, s32);                     /* extern */
? Init3DIcons(s8 *);                          /* extern */
? Init3DAttackBlocks(s8 *);                          /* extern */
? Init3DExplosion(s8 *);                          /* extern */
? Init3DText();                              /* extern */
? Init3DClearLine(s8 *, s8 *, s32);               /* extern */
? Init2DNewRow(s8 *);                          /* extern */
? Init2DCursor(s8 *, s32);                     /* extern */
? Init2DTetrisBlocks(s8 *, s32);                     /* extern */
? Init2DIcons(s8 *);                          /* extern */
? Init2DAttackBlocks(s8 *);                          /* extern */
? Init2DExplosion(s8 *);                          /* extern */
? func_8006B798_usa();                              /* extern */
? func_8006C0E0_usa(s8 *, s8 *, s32);               /* extern */
? InitAI(s8 *, s8 *, ? *);               /* extern */
? AISetLevel(? *, s32, s32);                 /* extern */
s32 func_80088940_usa(void **, s32, s32);           /* extern */
s32 func_80088A48_usa(void **, s32, s32);           /* extern */
s32 Init2DPuzzle(s8 *, s8 *, void *, s32);     /* extern */
? Init3DPuzzle(s8 *, s8 *, void *, s32);       /* extern */
? func_8008997C_usa(s8 *, ? *, ?);                  /* extern */
extern s32 B_801AAB98_usa;
extern s32 B_801AB61C_usa;
extern ? B_801ADADC_usa;
extern s32 gMax;
extern s32 B_801C70D8_usa;
extern ? D_800B6AA0_usa;
extern ? D_800B6AF4_usa;
extern s32 D_800BE350_usa;
extern ? D_CA4A0;
extern ? D_FB480;
extern void *Pon_Image_Heap;
extern ? gBufferHeap;

void InitTetrisWell(void) {
    ? sp10;
    void *sp28;
    s8 *sp34;
    s32 sp44;
    s32 sp4C;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_s0;
    s32 var_fp;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_s1_6;
    s32 var_v0;
    s32 var_v1;
    s32 var_v1_2;
    s8 *temp_s3;
    s8 *temp_v1_2;
    s8 *temp_v1_3;
    s8 *temp_v1_4;
    s8 *temp_v1_5;
    s8 *temp_v1_6;
    s8 *temp_v1_7;
    u32 temp_v1;
    void *temp_a2;
    void *temp_a2_2;
    void *temp_s4;
    void *temp_s5;
    void *temp_s5_2;
    void *temp_s5_3;
    void *temp_s5_4;
    void *temp_s5_5;
    void *temp_s6;
    void *temp_s6_2;
    void *temp_s6_3;
    void *temp_s6_4;
    void *temp_s6_5;
    void *temp_s6_6;
    void *temp_s7;
    void *temp_s7_2;
    void *temp_s7_3;
    void *temp_s7_4;
    void *temp_s7_5;
    void *temp_s7_6;
    void *var_s0;
    void *var_s0_2;
    void *var_s0_3;
    void *var_s0_4;
    void *var_s0_5;
    void *var_s0_6;

    B_801AB61C_usa = 0;
    B_801AAB98_usa = 0;
    D_800BE350_usa = 0;
    temp_v1 = (u32) osGetTime();
    temp_a0 = gTheGame.unk_9C0C;
    B_801C70D8_usa = 0x10001;
    gTheGame.unk_9C10 = (s32) temp_v1;
    gCounter = 0;
    gOverflow = 0;
    var_v0 = 0x12;
    if (temp_a0 == 1) {
        var_v0 = 6;
    }
    gMax = var_v0;
    Pon_Image_Heap = (&D_FB480 - &D_CA4A0) + &gBufferHeap;
    var_fp = 0;
    func_80054624_usa(temp_a0);
    InitGameStateVar();
    func_800325F8_usa();
    func_800552F4_usa();
    InitMiscStuff();
    InitPause();
    InitGameOver();
    func_80054020_usa();
    if (gTheGame.unk_9C08 > 0) {
        sp44 = 0;
        sp4C = 0;
loop_4:
        temp_s3 = &gTheGame.tetrisWell[0].unk_0000.unk_0000[0].unk_000[0].unk_00[sp4C];
        sp34 = &gTheGame.unk_8860[0].unk_00[sp44];
        bzero(&sp10, 4);
        temp_s3->unk_43B0 = 0;
        temp_s3->unk_43A8 = 0;
        temp_s3->unk_43A4 = 0;
        temp_s3->unk_43B4 = 0;
        temp_s3->unk_43B8 = 0;
        temp_s3->unk_43BC = 0;
        temp_s3->unk_43C0 = 0;
        temp_s3->unk_43C4 = 0;
        temp_s3->unk_43F4 = 0;
        temp_s3->unk_441C = 0xDF;
        temp_s3->unk_43F8 = 0;
        temp_s3->unk_43FC = 0;
        InitCursor(sp34);
        func_800545E4_usa(var_fp);
        temp_s0 = gTheGame.unk_9C0C;
        if (temp_s0 == 1) {
            Init2DCursor(sp34, var_fp);
            Init2DTetrisBlocks(temp_s3, var_fp);
            switch (gSelection) {                   /* switch 1; irregular */
                case 0xAA:                          /* switch 1 */
                    bzero(&sp10, 0x12);
                    var_v1 = 0x1E;
                    if (temp_s3->unk_4420 != 5) {
                        var_v1 = ((temp_s3->unk_4424 - 1) * 5) - 1 + temp_s3->unk_4428;
                    }
                    var_s0 = (var_v1 * 6) + &D_800B6AF4_usa;
                    temp_s7 = var_s0 + 0xC;
                    temp_s4 = var_s0 + 6;
                    temp_s6 = temp_s4;
                    var_s1 = (s32) var_s0 < (s32) temp_s7;
                    do {
loop_15:
                        temp_v1_2 = &sp10 + AnimationRandom(6);
                        if (*temp_v1_2 != 0) {
                            goto loop_15;
                        }
                        if (var_s1 == 0) {
                            *temp_v1_2 = (s8) var_s0->unk_-C;
                        } else if ((s32) var_s0 >= (s32) temp_s6) {
                            *temp_v1_2 = (s8) var_s0->unk_-6;
                        } else {
                            *temp_v1_2 = (s8) var_s0->unk_0;
                        }
                        var_s0 += 1;
                        var_s1 = (s32) var_s0 < (s32) temp_s7;
                    } while ((s32) var_s0 < (s32) temp_s4);
block_52:
                    func_8008997C_usa(temp_s3, &sp10, 6);
block_54:
                    Init2DNewRow(temp_s3);
                    Init2DIcons(temp_s3);
                    Init2DAttackBlocks(temp_s3);
                    Init2DExplosion(temp_s3);
                    func_8006B798_usa();
                    if (((gSelection == 0xAA) | (gSelection == 0xB4)) != 0) {
                        func_8006C0E0_usa(temp_s3, sp34, var_fp);
                    }
                    Init2DTetrisBlocksTMEM((Game *) temp_s3, 0);
                    goto block_99;
                case 0x78:                          /* switch 1 */
                    temp_a2 = gPlayer + (((temp_s3->unk_4424 - 1) * 0x6E) + 0x121);
                    sp28 = temp_a2;
                    Init2DPuzzle(temp_s3, sp34, temp_a2, 1);
                    goto block_54;
                case 0x82:                          /* switch 1 */
                    temp_a1 = temp_s3->unk_4420;
                    if (temp_a1 != 0) {
                        Init2DPuzzle(temp_s3, sp34, sp28, func_80088940_usa(&sp28, temp_a1, temp_s3->unk_4424));
                        goto block_54;
                    }
                    temp_a2_2 = gPlayer + (((temp_s3->unk_4424 - 1) * 0x6E) + 0x121);
                    sp28 = temp_a2_2;
                    if (Init2DPuzzle(temp_s3, sp34, temp_a2_2, 1) == 0) {
                        gReset = -1;
                        gMain = GMAIN_2BC;
                        return;
                    }
                    goto block_54;
                case 0x96:                          /* switch 1 */
                    if (var_fp == temp_s0) {
                        AISetLevel(&B_801ADADC_usa, gTheGame.unk_9C28, gTheGame.unk_9C2C);
                        InitAI(temp_s3, sp34, &B_801ADADC_usa);
                    }
                    /* fallthrough */
                default:                            /* switch 1 */
                    if (var_fp == 0) {
                        bzero(&sp10, 0x12);
                        var_s0_2 = (AnimationRandom(0xE) * 6) + &D_800B6AA0_usa;
                        temp_s7_2 = var_s0_2 + 0xC;
                        temp_s5 = var_s0_2 + 6;
                        temp_s6_2 = temp_s5;
                        var_s1_2 = (s32) var_s0_2 < (s32) temp_s7_2;
                        do {
loop_33:
                            temp_v1_3 = &sp10 + AnimationRandom(6);
                            if (*temp_v1_3 != 0) {
                                goto loop_33;
                            }
                            if (var_s1_2 == 0) {
                                *temp_v1_3 = (s8) var_s0_2->unk_-C;
                            } else if ((s32) var_s0_2 >= (s32) temp_s6_2) {
                                *temp_v1_3 = (s8) var_s0_2->unk_-6;
                            } else {
                                *temp_v1_3 = (s8) var_s0_2->unk_0;
                            }
                            var_s0_2 += 1;
                            var_s1_2 = (s32) var_s0_2 < (s32) temp_s7_2;
                        } while ((s32) var_s0_2 < (s32) temp_s5);
                        goto block_52;
                    }
                    if (gTheGame.tetrisWell[0].unk_43BC[0x28] != temp_s3->unk_43E4) {
                        bzero(&sp10, 0x12);
                        var_s0_3 = (AnimationRandom(0xE) * 6) + &D_800B6AA0_usa;
                        temp_s7_3 = var_s0_3 + 0xC;
                        temp_s5_2 = var_s0_3 + 6;
                        temp_s6_3 = temp_s5_2;
                        var_s1_3 = (s32) var_s0_3 < (s32) temp_s7_3;
                        do {
loop_44:
                            temp_v1_4 = &sp10 + AnimationRandom(6);
                            if (*temp_v1_4 != 0) {
                                goto loop_44;
                            }
                            if (var_s1_3 == 0) {
                                *temp_v1_4 = (s8) var_s0_3->unk_-C;
                            } else if ((s32) var_s0_3 >= (s32) temp_s6_3) {
                                *temp_v1_4 = (s8) var_s0_3->unk_-6;
                            } else {
                                *temp_v1_4 = (s8) var_s0_3->unk_0;
                            }
                            var_s0_3 += 1;
                            var_s1_3 = (s32) var_s0_3 < (s32) temp_s7_3;
                        } while ((s32) var_s0_3 < (s32) temp_s5_2);
                        goto block_52;
                    }
                    bcopy(&gTheGame.tetrisWell[0].unk_43BC[0x28] - 0x43E4, temp_s3, 0x2520);
                    goto block_54;
            }
        } else {
            Init3DCursor(sp34, var_fp);
            Init3DTetrisBlocks(temp_s3, var_fp);
            temp_s3->unk_4088 = -0.768f;
            switch (gSelection) {                   /* irregular */
                case 0x82:
                    Init3DPuzzle(temp_s3, sp34, sp28, func_80088A48_usa(&sp28, temp_s3->unk_4420, temp_s3->unk_4424));
                    break;
                case 0xAA:
                    bzero(&sp10, 0x12);
                    var_v1_2 = 0x1E;
                    if (temp_s3->unk_4420 != 5) {
                        var_v1_2 = ((temp_s3->unk_4424 - 1) * 5) - 1 + temp_s3->unk_4428;
                    }
                    var_s0_4 = (var_v1_2 * 6) + &D_800B6AF4_usa;
                    temp_s7_4 = var_s0_4 + 0xC;
                    temp_s6_4 = var_s0_4 + 6;
                    temp_s5_3 = var_s0_4 + 0x12;
                    var_s1_4 = (s32) var_s0_4 < (s32) temp_s7_4;
                    do {
loop_65:
                        temp_v1_5 = &sp10 + AnimationRandom(0x12);
                        if (*temp_v1_5 != 0) {
                            goto loop_65;
                        }
                        if (var_s1_4 == 0) {
                            *temp_v1_5 = (s8) var_s0_4->unk_-C;
                        } else if ((s32) var_s0_4 >= (s32) temp_s6_4) {
                            *temp_v1_5 = (s8) var_s0_4->unk_-6;
                        } else {
                            *temp_v1_5 = (s8) var_s0_4->unk_0;
                        }
                        var_s0_4 += 1;
                        var_s1_4 = (s32) var_s0_4 < (s32) temp_s7_4;
                    } while ((s32) var_s0_4 < (s32) temp_s5_3);
block_95:
                    func_8008997C_usa(temp_s3, &sp10, 0x12);
                    break;
                default:
                    if (var_fp == 0) {
                        bzero(&sp10, 0x12);
                        var_s0_5 = (AnimationRandom(0xE) * 6) + &D_800B6AA0_usa;
                        temp_s7_5 = var_s0_5 + 0xC;
                        temp_s6_5 = var_s0_5 + 6;
                        temp_s5_4 = var_s0_5 + 0x12;
                        var_s1_5 = (s32) var_s0_5 < (s32) temp_s7_5;
                        do {
loop_76:
                            temp_v1_6 = &sp10 + AnimationRandom(0x12);
                            if (*temp_v1_6 != 0) {
                                goto loop_76;
                            }
                            if (var_s1_5 == 0) {
                                *temp_v1_6 = (s8) var_s0_5->unk_-C;
                            } else if ((s32) var_s0_5 >= (s32) temp_s6_5) {
                                *temp_v1_6 = (s8) var_s0_5->unk_-6;
                            } else {
                                *temp_v1_6 = (s8) var_s0_5->unk_0;
                            }
                            var_s0_5 += 1;
                            var_s1_5 = (s32) var_s0_5 < (s32) temp_s7_5;
                        } while ((s32) var_s0_5 < (s32) temp_s5_4);
                        goto block_95;
                    }
                    if (gTheGame.tetrisWell[0].unk_43BC[0x28] != temp_s3->unk_43E4) {
                        bzero(&sp10, 0x12);
                        var_s0_6 = (AnimationRandom(0xE) * 6) + &D_800B6AA0_usa;
                        temp_s7_6 = var_s0_6 + 0xC;
                        temp_s6_6 = var_s0_6 + 6;
                        temp_s5_5 = var_s0_6 + 0x12;
                        var_s1_6 = (s32) var_s0_6 < (s32) temp_s7_6;
                        do {
loop_87:
                            temp_v1_7 = &sp10 + AnimationRandom(0x12);
                            if (*temp_v1_7 != 0) {
                                goto loop_87;
                            }
                            if (var_s1_6 == 0) {
                                *temp_v1_7 = (s8) var_s0_6->unk_-C;
                            } else if ((s32) var_s0_6 >= (s32) temp_s6_6) {
                                *temp_v1_7 = (s8) var_s0_6->unk_-6;
                            } else {
                                *temp_v1_7 = (s8) var_s0_6->unk_0;
                            }
                            var_s0_6 += 1;
                            var_s1_6 = (s32) var_s0_6 < (s32) temp_s7_6;
                        } while ((s32) var_s0_6 < (s32) temp_s5_5);
                        goto block_95;
                    }
                    bcopy(&gTheGame.tetrisWell[0].unk_43BC[0x28] - 0x43E4, temp_s3, 0x2520);
                    break;
            }
            Init3DNewRow(temp_s3);
            Init3DIcons(temp_s3);
            Init3DAttackBlocks(temp_s3);
            Init3DExplosion(temp_s3);
            Init3DText();
            if (((gSelection == 0xAA) | (gSelection == 0xB4)) != 0) {
                Init3DClearLine(temp_s3, sp34, var_fp);
            }
block_99:
            sp44 += 0xB0;
            var_fp += 1;
            sp4C += 0x4430;
            if (var_fp >= gTheGame.unk_9C08) {

            } else {
                goto loop_4;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", InitTetrisWell);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetris", InitTetrisWell);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetris", InitTetrisWell);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetris", InitTetrisWell);
#endif

void DoTetris(void) {
    typedef struct Padding {
        s32 unk_0;
        s32 unk_4;
    } Padding;

    tetWell *well;
    cursor_t *cursor;
    s32 sp28 = 0; // elapsed seconds
    s32 var_a0;
    s32 var_s2;
    s32 num;
    s32 count;

#if 0
    int interval; // r20
    int blockHSize; // r31
#endif

    Padding pad UNUSED = { 0, 0 };
    s32 pad2[4] UNUSED;

    gTheGame.unk_90C0 = 6;
    for (count = 6; count < DRAWTEXT_COUNT; count++) {
        gTheGame.drawText[count].texture = -1;
    }

    ReturnSecond(&sp28);

    DoGameFade(5);
    UpdateMainState();
    if (gMain >= GMAIN_38E) {
        return;
    }

    if (D_800BE350_usa == 0) {
        gOverflow = 0;
    }

    for (num = 0; num < gTheGame.unk_9C08; num++) {
        well = &gTheGame.tetrisWell[num];
        cursor = &gTheGame.cursorBlock[num];

        if (D_800BE350_usa == 1) {
            B_801C6C94_usa = 0;
            if (gTheGame.controller[num].touch_button & Z_TRIG) {
                B_801C6C94_usa = -1;
            }

            if (B_801C6C94_usa == 0) {
                continue;
            }
        }

        B_801AAB98_usa += 1;
        if (!(gGameStatus & 0x20) || (gCounter % 2 != 0)) {
            if (gMain == GMAIN_387) {
                if ((cursor->unk_04 == 0) && (cursor->unk_0C == 0) && (well->unk_43F4 == 0) && (well->unk_43B0 == 0) &&
                    (gSelection >= 0x83) && (B_801AB61C_usa == 0) && (cursor->unk_00 <= 0) && (cursor->unk_08 == 0)) {
                    well->unk_43EC += well->unk_43F0;

                    if (well->unk_43EC >= 0x1000U) {
                        var_s2 = well->unk_43EC & 0xFFFF0000;
                        if (var_s2 < 0) {
                            var_a0 = var_s2 | 0xFFFF;
                        } else {
                            var_a0 = var_s2;
                        }
                        well->unk_43EC &= 0xFFFF;
                        var_s2 = (var_a0 >> 0x10);
                        well->unk_43FC = var_s2 * gTheGame.unk_9C0C;
                        well->unk_43F8 += well->unk_43FC;
                        if (gTheGame.unk_9C0C * 0x10 < well->unk_43F8) {
                            well->unk_43FC = gTheGame.unk_9C0C * 0x10 - (well->unk_43F8 - well->unk_43FC);
                            well->unk_43F8 = gTheGame.unk_9C0C * 0x10;
                        }
                    }
                }

                CompactWell(well, num);
            }
        }

        CheckGameInput(well, cursor, num);
        var_s2 = 0;
        if (gMain == GMAIN_387) {
            if ((gGameStatus & 0x20) && (gCounter % 2 == 0)) {
                if (gTheGame.unk_9C0C == 2) {
                    Update3DCursor(well, cursor);
                }
            } else {
                if (well->unk_43C4 != 0) {
                    CheckCollision(well);
                }

                well->unk_43C4 = 0;
                CheckChainCounter(well, cursor);
                var_s2 = ComboCount(well, cursor);
                if (well->unk_43BC != 0) {
                    well->unk_43C0 = 0;
                    well->unk_43BC = 0;
                }
                CheckShake(well, cursor);
                CheckIcon(well, var_s2);
                StartAttack(well, num);
                if (brainbrain[num].unk_00C != -1) {
                    UpdateAI(well, cursor, &brainbrain[num], num);
                }
                UpdateWell(well, cursor, num, var_s2);
                if ((gSelection == 0xA0) || (gSelection == 0x96)) {
                    ChangeAttack(well, cursor, num, var_s2);
                }
                UpdateCursor(well, cursor);
                UpdateIcon(well, cursor, num);
                if ((gSelection == 0xA0) || (gSelection == 0x96)) {
                    UpdateAttack(well, cursor, num);
                }

                UpdateExplosion(well);
            }

            UpdateNextLevel(well);
            UpdateDistance(well, cursor);
            UpdateAnimation(well, num, var_s2);
            UpdateMiscStuff(well, cursor, num);

            if ((cursor->unk_00 <= 0) && (well->unk_43F8 >= (gTheGame.unk_9C0C * 0x10))) {
                well->unk_43C4 = -1;
                AddNewRow(well, cursor, num);
                well->unk_43F8 = 0;
                if ((gSelection == 0xAA) || (gSelection == 0xB4)) {
                    cursor->unk_28 -= 1;
                }
            }

            if (gTheGame.unk_9C0C == 2) {
                Check3DVisibleBlocks(well, cursor);
            }

            HackGame(well);
            well->unk_43FC = 0;
            well->unk_43A4 = 0;
        }
    }

    if (gMain == GMAIN_387) {
        UpdateTime(sp28);
    }

    UpdateText();
    peelTick();
}

void HackGame(tetWell *well) {
    s32 count;

    if (gTheGame.unk_9C08 != 1) {
        for (count = 0; count < ATTACK_COUNT; count++) {
            if ((well->attack[count].type > ATTACKTYPE_4) && (well->attack[count].type < ATTACKTYPE_9)) {
                well->attack[count].state = ATTACKSTATE_0;
                well->attack[count].type = 0;
                well->attack[count].disappear = -1;
                well->attack[count].delay = 0;
                well->attack[count].unk_10 = 0;
                well->attack[count].unk_24 = -1;
                well->attack[count].unk_28 = -1;
            }
        }
    }
}
