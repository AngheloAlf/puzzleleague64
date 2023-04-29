/**
 * Original filename: tetris.c
 */

#include "tetris.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "sound.h"
#include "dlist.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", RandomBlock);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_80089778_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_80089828_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_8008997C_usa);
#endif

#if VERSION_USA
s32 DemoCheck(s32 *arg0) {
    func_800545E4_usa(1);

    if ((gTheGame.unk_89C4 != 0) || (gDemo == GDEMO_16)) {
        gDemo = GDEMO_16;
        gTheGame.unk_9C1C = 0;
        gTheGame.unk_9C18 = 0;
        gTheGame.unk_9C14 = 0;
        gGameStatus = gGameStatus >> 0x10;
        FadeOutSong(last_song_handle, 0x3C);
        return -1;
    }

    if ((*arg0 > 1800) && (gMain == GMAIN_387)) {
        gDemo = GDEMO_21;
        gTheGame.unk_9C1C = 0;
        gTheGame.unk_9C18 = 0;
        gTheGame.unk_9C14 = 0;
        gGameStatus = gGameStatus >> 0x10;
        FadeOutSong(last_song_handle, 0x3C);
        return -1;
    }

    *arg0 += 1;
    gDemo = GDEMO_0B;
    return 0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_80089BE0_usa);
#endif

#if VERSION_USA
#if 0
? InitGameStateVar();                               /* extern */
? func_800325F8_usa();                              /* extern */
? func_800343A0_usa();                              /* extern */
? func_800346B8_usa();                              /* extern */
s32 AnimationRandom(?);                           /* extern */
? func_80052720_usa();                              /* extern */
? func_80054020_usa();                              /* extern */
? func_80054500_usa(s8 *);                          /* extern */
? func_800545E4_usa(s32);                           /* extern */
? func_80054624_usa(s32);                           /* extern */
? func_800552F4_usa();                              /* extern */
? func_8005D900_usa(s8 *);                          /* extern */
? func_8005DB88_usa(s8 *, s32);                     /* extern */
? func_8005DBD8_usa(s8 *, s32);                     /* extern */
? func_8005DD3C_usa(s8 *);                          /* extern */
? func_8005DDB4_usa(s8 *);                          /* extern */
? func_8005DDF8_usa(s8 *);                          /* extern */
? func_8005DE28_usa();                              /* extern */
? func_8005DE58_usa(s8 *, s8 *, s32);               /* extern */
? func_8006AF30_usa(s8 *);                          /* extern */
? func_8006B24C_usa(s8 *, s32);                     /* extern */
? func_8006B314_usa(s8 *, s32);                     /* extern */
? func_8006B628_usa(s8 *);                          /* extern */
? func_8006B6A8_usa(s8 *);                          /* extern */
? func_8006B730_usa(s8 *);                          /* extern */
? func_8006B798_usa();                              /* extern */
? func_8006C0E0_usa(s8 *, s8 *, s32);               /* extern */
? func_80074FF0_usa(s8 *, s8 *, ? *);               /* extern */
? func_800755B0_usa(? *, s32, s32);                 /* extern */
s32 func_80088940_usa(void **, s32, s32);           /* extern */
s32 func_80088A48_usa(void **, s32, s32);           /* extern */
s32 func_80088AB4_usa(s8 *, s8 *, void *, s32);     /* extern */
? func_80088D34_usa(s8 *, s8 *, void *, s32);       /* extern */
? func_8008997C_usa(s8 *, ? *, ?);                  /* extern */
extern s32 B_801AAB98_usa;
extern s32 B_801AB61C_usa;
extern ? B_801ADADC_usa;
extern s32 B_801C7050_usa;
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
    B_801C7050_usa = var_v0;
    Pon_Image_Heap = (&D_FB480 - &D_CA4A0) + &gBufferHeap;
    var_fp = 0;
    func_80054624_usa(temp_a0);
    InitGameStateVar();
    func_800325F8_usa();
    func_800552F4_usa();
    func_80052720_usa();
    func_800343A0_usa();
    func_800346B8_usa();
    func_80054020_usa();
    if (gTheGame.unk_9C08 > 0) {
        sp44 = 0;
        sp4C = 0;
loop_4:
        temp_s3 = &gTheGame.unk_0000[0].unk_0000.unk_0000[0].unk_000[0].unk_00[sp4C];
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
        func_80054500_usa(sp34);
        func_800545E4_usa(var_fp);
        temp_s0 = gTheGame.unk_9C0C;
        if (temp_s0 == 1) {
            func_8006B24C_usa(sp34, var_fp);
            func_8006B314_usa(temp_s3, var_fp);
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
                    func_8006AF30_usa(temp_s3);
                    func_8006B628_usa(temp_s3);
                    func_8006B6A8_usa(temp_s3);
                    func_8006B730_usa(temp_s3);
                    func_8006B798_usa();
                    if (((gSelection == 0xAA) | (gSelection == 0xB4)) != 0) {
                        func_8006C0E0_usa(temp_s3, sp34, var_fp);
                    }
                    Init2DTetrisBlocksTMEM((TheGame *) temp_s3, 0);
                    goto block_99;
                case 0x78:                          /* switch 1 */
                    temp_a2 = B_8021BEA4_usa + (((temp_s3->unk_4424 - 1) * 0x6E) + 0x121);
                    sp28 = temp_a2;
                    func_80088AB4_usa(temp_s3, sp34, temp_a2, 1);
                    goto block_54;
                case 0x82:                          /* switch 1 */
                    temp_a1 = temp_s3->unk_4420;
                    if (temp_a1 != 0) {
                        func_80088AB4_usa(temp_s3, sp34, sp28, func_80088940_usa(&sp28, temp_a1, temp_s3->unk_4424));
                        goto block_54;
                    }
                    temp_a2_2 = B_8021BEA4_usa + (((temp_s3->unk_4424 - 1) * 0x6E) + 0x121);
                    sp28 = temp_a2_2;
                    if (func_80088AB4_usa(temp_s3, sp34, temp_a2_2, 1) == 0) {
                        gReset = -1;
                        gMain = GMAIN_2BC;
                        return;
                    }
                    goto block_54;
                case 0x96:                          /* switch 1 */
                    if (var_fp == temp_s0) {
                        func_800755B0_usa(&B_801ADADC_usa, gTheGame.unk_9C28, gTheGame.unk_9C2C);
                        func_80074FF0_usa(temp_s3, sp34, &B_801ADADC_usa);
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
                    if (gTheGame.unk_0000[0].unk_43BC[0x28] != temp_s3->unk_43E4) {
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
                    bcopy(&gTheGame.unk_0000[0].unk_43BC[0x28] - 0x43E4, temp_s3, 0x2520);
                    goto block_54;
            }
        } else {
            func_8005DB88_usa(sp34, var_fp);
            func_8005DBD8_usa(temp_s3, var_fp);
            temp_s3->unk_4088 = -0.768f;
            switch (gSelection) {                   /* irregular */
                case 0x82:
                    func_80088D34_usa(temp_s3, sp34, sp28, func_80088A48_usa(&sp28, temp_s3->unk_4420, temp_s3->unk_4424));
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
                    if (gTheGame.unk_0000[0].unk_43BC[0x28] != temp_s3->unk_43E4) {
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
                    bcopy(&gTheGame.unk_0000[0].unk_43BC[0x28] - 0x43E4, temp_s3, 0x2520);
                    break;
            }
            func_8005D900_usa(temp_s3);
            func_8005DD3C_usa(temp_s3);
            func_8005DDB4_usa(temp_s3);
            func_8005DDF8_usa(temp_s3);
            func_8005DE28_usa();
            if (((gSelection == 0xAA) | (gSelection == 0xB4)) != 0) {
                func_8005DE58_usa(temp_s3, sp34, var_fp);
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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", DoTetris);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_8008ADB4_usa);
#endif
