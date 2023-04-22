/**
 * Original filename: end.c
 */

#include "end.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "dlist.h"
#include "sound.h"
#include "sfxlimit.h"
#include "update.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80037270_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80037358_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80037440_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80037724_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80037900_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_800379D4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80037B0C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/end", RO_800C4980_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80037CBC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80038018_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003813C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80038228_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003837C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003853C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_800386D4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_800387AC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003880C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80038944_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80038B98_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80038C54_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80038F84_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003901C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/end", RO_800C49D0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/end", RO_800C49E0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/end", RO_800C4A70_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/end", RO_800C4B00_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003991C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80039A54_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80039B78_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80039DB0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/end", RO_800C4B14_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/end", RO_800C4B24_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003A0B8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003AD18_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003B590_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003BF04_usa);
#endif

#if VERSION_USA
#if 0
? func_80005184_usa(? *, ?);                        /* extern */
? func_80005888_usa(?, ?, ?);                       /* extern */
? func_80005A08_usa(s32);                           /* extern */
? func_8003490C_usa();                              /* extern */
? func_8003524C_usa(TheGame *, s8 *);               /* extern */
? func_8003536C_usa(TheGame *, s8 *);               /* extern */
? func_800353F4_usa(TheGame *, s8 *);               /* extern */
? func_8003547C_usa(TheGame *, s8 *);               /* extern */
? func_80035584_usa(s8 *);                          /* extern */
? func_80037270_usa(TheGame *);                     /* extern */
? func_80037358_usa(TheGame *);                     /* extern */
? func_80037440_usa(TheGame *);                     /* extern */
? func_80037724_usa(TheGame *);                     /* extern */
? func_80037900_usa(TheGame *);                     /* extern */
? func_80037B0C_usa(TheGame *, TheGame_unk_8860 *); /* extern */
s32 func_80037CBC_usa(TheGame *);                   /* extern */
? func_80038018_usa(TheGame *, ?);                  /* extern */
? func_8003813C_usa(TheGame *);                     /* extern */
? func_8003837C_usa(TheGame *, ?);                  /* extern */
? func_8003853C_usa(TheGame *, ?);                  /* extern */
? func_8003880C_usa();                              /* extern */
s32 func_80038944_usa(u32);                         /* extern */
s32 func_8003901C_usa(TheGame *);                   /* extern */
? func_80039A54_usa(?);                             /* extern */
? func_80039B78_usa();                              /* extern */
s32 func_8003A0B8_usa();                            /* extern */
? func_8003E508_usa(u32);                           /* extern */
? func_8004ADD0_usa(?);                             /* extern */
? func_8004C280_usa(s32);                           /* extern */
? func_8004F70C_usa(TheGame *, ?, ?);               /* extern */
s32 func_8004FA2C_usa();                            /* extern */
? func_80058458_usa(s32, s32);                      /* extern */
? func_8005866C_usa(TheGame_unk_8860 *, s32, s32);  /* extern */
? func_80058A10_usa(TheGame_unk_8860 *, s32, s32);  /* extern */
? func_80058D68_usa(s32, s32);                      /* extern */
? func_8005D8B4_usa(TheGame *);                     /* extern */
? func_8006AF30_usa(TheGame *);                     /* extern */
? func_8006B314_usa(TheGame *, ?);                  /* extern */
? func_8006B628_usa(TheGame *);                     /* extern */
? func_8006B730_usa(TheGame *);                     /* extern */
? func_8006C4A0_usa(?);                             /* extern */
? func_8006C7A0_usa(?, ?);                          /* extern */
? func_8006C9BC_usa(TheGame *, ?);                  /* extern */
extern u8 B_801C6C90_usa;
extern s32 B_8021BA5C_usa;
extern ? D_800B4160_usa;
extern s32 D_800B65B0_usa;
extern ? D_800B66FC_usa;

void DoGameOver2D(void) {
    ? var_a0;
    ? var_a0_5;
    ? var_a0_6;
    ? var_a0_7;
    ? var_a1;
    ? var_a1_2;
    ? var_a1_3;
    ? var_a1_4;
    ? var_a1_5;
    ? var_a1_6;
    ? var_a1_7;
    TheGame *var_a0_2;
    TheGame *var_v1_3;
    TheGame_unk_0000 *var_a0_4;
    enum enum_gMain var_v1_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s3;
    s32 var_v0;
    s32 var_v1;
    s8 temp_a0_2;
    s8 var_v1_4;
    s8 var_v1_5;
    u32 temp_a0;
    u32 temp_a0_3;
    u32 temp_v1;
    u32 var_a0_3;

    var_v1 = 0xC0;
    gTheGame.unk_89C8[0x6F8] = 6;
    do {
        (&gTheGame.unk_90C8.unk_000[0x18])[var_v1] = -1;
        var_v1 += 0x20;
    } while (var_v1 < 0x8C0);
    func_8004C280_usa(-1);
    if ((gMain < 0x396) || (B_8021BA5C_usa < 6) || (func_8003A0B8_usa() == 0)) {
        var_s3 = 0;
        if (gTheGame.unk_9C08 == 1) {
            switch (gMain) {                        /* switch 1 */
                case GMAIN_38E:                     /* switch 1 */
                    if (gSelection != 0x82) {
                        if (gSelection == 0xAA) {
                            func_80058A10_usa(gTheGame.unk_8860, gTheGame.unk_9C20[0xC], gTheGame.unk_9C20[0x10]);
                        }
                    } else {
                        func_8005866C_usa(gTheGame.unk_8860, gTheGame.unk_9C20[8], gTheGame.unk_9C20[0xC]);
                    }
                    func_8003490C_usa();
                    switch (gSelection) {           /* switch 3; irregular */
                        case 0x8C:                  /* switch 3 */
                        case 0xAA:                  /* switch 3 */
                        case 0xBE:                  /* switch 3 */
                            gTheGame.unk_9988[0x1C0] = 0;
                            gTheGame.unk_8860[0].unk_C = 0;
                            break;
                        case 0x78:                  /* switch 3 */
                            /* fallthrough */
                        case 0x82:                  /* switch 3 */
                            gTheGame.unk_9988[0x1C0] = -1;
                            break;
                    }
                    gGameStatus &= ~0x20;
                    func_8006B628_usa(&gTheGame);
                    func_8006B730_usa(&gTheGame);
                    gTheGame.unk_9C20[4] = 0;
                    gTheGame.unk_89C8[0x6E8] = -0x280;
                    gTheGame.unk_89C8[0x6D0] = -0x280;
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        func_8006C9BC_usa(&gTheGame, 0);
                    }
                    func_80039A54_usa(0);
                    if (gSelection == 0x8C) {
                        if (gTheGame.unk_43AC < 0x2710) {

                        } else {
                            goto block_29;
                        }
                    } else if ((gSelection == 0xBE) && (gTheGame.unk_8860[0].unk_0 != 8)) {
block_29:
                        func_80039A54_usa(-1);
                    }
                    gMain = 0x38F;
                    gTheGame.unk_43FC = 0x25;
                    B_8021BA5C_usa = 0;
                    D_800B65B0_usa = 0;
                    gTheGame.unk_43EC = 0;
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        func_80005184_usa(&D_800B4160_usa, 0xA0);
                        if (gSelection >= 0x83) {
                            var_a1 = 0x175;
                            goto block_39;
                        }
                    } else {
                        var_a1 = 0x174;
                        if (gSelection != 0xBE) {
                            func_80005184_usa(&D_800B4160_usa, 0xA1);
                            if (gTheGame.unk_9C20[8] != 5) {
                                if (gTheGame.unk_9C20[0x10] == 5) {
                                    var_a1 = 0x9F;
                                } else {
                                    var_a1 = 0x9E;
                                }
                                goto block_39;
                            }
                        } else {
block_39:
                            func_80005184_usa(&D_800B4160_usa, var_a1);
                        }
                    }
                    FadeOutSong(last_song_handle, 0x3C);
                    break;
                case 0x38F:                         /* switch 1 */
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        func_80037270_usa(&gTheGame);
                        func_80037358_usa(&gTheGame);
                        func_80037440_usa(&gTheGame);
                    } else {
                        func_80037724_usa(&gTheGame);
                    }
                    if (gMain == 0x390) {
                        gTheGame.unk_43EC = 0x28;
                    }
                    break;
                case 0x390:                         /* switch 1 */
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        func_80037900_usa(&gTheGame);
                        var_v1_2 = gMain;
                        var_v0 = 0x391;
                        goto block_50;
                    }
                    temp_v0 = gTheGame.unk_43EC - 1;
                    gTheGame.unk_43EC = temp_v0;
                    if (temp_v0 == 0) {
                        var_v0 = gSelection;
                        gMain = 0x391;
                        var_v1_2 = 0xBE;
block_50:
                        if (var_v0 == var_v1_2) {
                            func_8006B314_usa(&gTheGame, 0);
                            func_8006AF30_usa(&gTheGame);
                        }
                    }
                    break;
                case 0x391:                         /* switch 1 */
                    temp_v0_2 = B_8021BA5C_usa;
                    if (temp_v0_2 == 0) {
                        if ((gSelection != 0x82) || (gTheGame.unk_9C20[8] != 0)) {
                            func_8003E508_usa();
                        }
                    }
                    B_8021BA5C_usa = temp_v0_2 + 1;
                    if (((gSelection == 0x8C) | (gSelection == 0xBE)) != 0) {
                        func_8006B628_usa(&gTheGame);
                        var_s0 = func_8003901C_usa(&gTheGame);
                        if (B_8021BA5C_usa == 0x55) {
                            var_a0 = -1;
                            if (func_8004FA2C_usa() != 0) {
                                goto block_62;
                            }
                        } else {
                            var_a0 = 0;
                            if (B_8021BA5C_usa >= 0x56) {
block_62:
                                func_8004ADD0_usa(var_a0);
                            }
                        }
                        if (B_8021BA5C_usa == 0x5A) {
                            if (gSelection == 0x8C) {
                                if (gTheGame.unk_43AC >= 0x2710) {
                                    PlayMIDI(&BGM_INIT_TABLE, 0x46, 0, 2);
                                    func_80005184_usa(&D_800B4160_usa, 0x7D);
                                } else {
                                    goto block_72;
                                }
                            } else if (gSelection == 0xBE) {
                                if (gTheGame.unk_8860[0].unk_0 != 8) {
                                    if (gTheGame.unk_43AC >= 0x2710) {
                                        PlayMIDI(&BGM_INIT_TABLE, 0x46, 0, 2);
                                        func_80005184_usa(&D_800B4160_usa, 0x80);
                                    } else {
                                        var_a1_2 = 0x45;
                                        goto block_73;
                                    }
                                } else {
block_72:
                                    var_a1_2 = 0x42;
block_73:
                                    PlayMIDI(&BGM_INIT_TABLE, var_a1_2, 0, 1);
                                }
                            }
                        }
                    } else {
                        var_s0 = 0;
                        if (gTheGame.unk_8860[0].unk_0 == 7) {
                            var_s0 = func_80037CBC_usa(&gTheGame);
                            func_8005D8B4_usa(&gTheGame);
                        }
                    }
                    if ((var_s0 == 0) && (B_8021BA5C_usa >= 0x5B)) {
                        gMain = 0x392;
                    }
                    if (gMain == 0x392) {
                        func_8006B314_usa(&gTheGame, 0);
                        func_8006AF30_usa(&gTheGame);
                        func_8006B628_usa(&gTheGame);
                        if ((gSelection >= 0x83) || (gTheGame.unk_8860[0].unk_0 != 7)) {
                            if ((gSelection == 0xAA) && (gTheGame.unk_8860[0].unk_0 == 7)) {
                                goto block_85;
                            }
                            gTheGame.unk_43FC = 0x59;
                        } else {
block_85:
                            gTheGame.unk_43FC = 0x50;
                        }
                    }
                    break;
                case 0x392:                         /* switch 1 */
                    func_80037B0C_usa(&gTheGame, gTheGame.unk_8860);
                    if (gMain == 0x393) {
                        gTheGame.unk_9C20[4] = 0;
                        gTheGame.unk_43EC = 0;
                    }
                    break;
                case 0x393:                         /* switch 1 */
                    gTheGame.unk_9988[0x13C] = 0x26CU;
                    gTheGame.unk_9988[0x164] = 0x2D0;
                    if (gTheGame.unk_8860[0].unk_0 == 7) {
                        if (((gSelection < 0x83) | (gSelection == 0xAA)) != 0) {
                            PlayMIDI(&BGM_INIT_TABLE, 0x45, 0, 1);
                            if (gSelection == 0x82) {
                                func_80005A08_usa(gTheGame.unk_9C20[8]);
                            }
                        }
                    } else if ((gSelection != 0x8C) & (gSelection != 0xBE)) {
                        if (func_8004FA2C_usa() != 0) {
                            func_8004ADD0_usa(-1);
                        }
                        PlayMIDI(&BGM_INIT_TABLE, 0x42, 0, 1);
                        if (gSelection == 0xAA) {
                            if (gTheGame.unk_9C20[8] == 5) {
                                if (gTheGame.unk_9C20[0xC] == 3) {
                                    func_80005184_usa(&D_800B4160_usa, 0x81);
                                } else {
                                    goto block_101;
                                }
                            } else {
block_101:
                                func_80005888_usa(0, 2, 2);
                            }
                        }
                    }
                    B_8021BA5C_usa = 0;
                    gMain = 0x396;
                    break;
                case 0x396:                         /* switch 1 */
                    func_8003524C_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                    func_80039B78_usa();
                    func_8004ADD0_usa(0);
                    switch (gSelection) {           /* switch 4; irregular */
                        case 0x8C:                  /* switch 4 */
                            if (gTheGame.unk_9C20[8] != 0) {
                                switch (gSelection) { /* switch 5; irregular */
                                    case 0xAA:      /* switch 4 */
                                    case 0xAA:      /* switch 5 */
                                        if (gTheGame.unk_8860[0].unk_0 != 7) {
                                            if (((gSelection == 0x82) && (gTheGame.unk_8860[0].unk_0 == 7)) || (gSelection == 0x78)) {
                                                goto block_111;
                                            }
                                        } else {
                                            goto block_111;
                                        }
                                        break;
                                }
                            } else {
                            case 0x78:              /* switch 4 */
                            case 0x78:              /* switch 5 */
block_111:
                                func_80035584_usa(&gTheGame.unk_9988[0x130]);
                            }
                            break;
                    }
                    B_8021BA5C_usa += 1;
                    break;
            }
            var_a0_2 = &gTheGame;
            if (gTheGame.unk_9C0C == 1) {
                var_a1_3 = 0;
                goto block_270;
            }
        } else {
            temp_v1 = gTheGame.unk_8860[0].unk_0;
            var_a0_3 = gTheGame.unk_8860[1];
            var_s1 = 0;
            if (temp_v1 != var_a0_3) {
                if (temp_v1 != 8) {
                    if (var_a0_3 != 7) {
                        var_s3 = -1;
                    } else {
                        goto block_120;
                    }
                } else {
block_120:
                    var_s1 = -1;
                }
            }
            switch (gMain) {                        /* switch 2 */
                case GMAIN_38E:                     /* switch 2 */
                    if (var_s3 != var_s1) {
                        if (var_s3 != 0) {
                            gTheGame.unk_4404 = (s32) (gTheGame.unk_4404 + 1);
                        } else if (var_s1 != 0) {
                            gTheGame.unk_0000[1].unk_4404 = (s32) (gTheGame.unk_0000[1].unk_4404 + 1);
                        }
                    }
                    if ((gSelection == 0x96) & var_s3) {
                        func_80058D68_usa(gTheGame.unk_9C20[8], gTheGame.unk_9C20[0xC]);
                    } else {
                        temp_a0 = (u32) (gGameStatus & 0xF00) >> 8;
                        if ((gTheGame.unk_4404 == temp_a0) || (gTheGame.unk_0000[1].unk_4404 == temp_a0)) {
                            func_80058458_usa(var_s3, var_s1);
                        }
                    }
                    var_s0_2 = 0;
                    func_8003490C_usa();
                    gOverflow = 0;
                    func_8006B628_usa(&gTheGame);
                    func_8006B628_usa((TheGame *) &gTheGame.unk_0000[1]);
                    func_8006B730_usa(&gTheGame);
                    func_8006B730_usa((TheGame *) &gTheGame.unk_0000[1]);
                    var_a0_4 = &gTheGame.unk_0000[1];
                    var_v1_3 = &gTheGame;
                    gTheGame.unk_9C20[4] = 0;
                    do {
                        if (var_v1_3->unk_2520 < 4) {
                            var_v1_3->unk_2520 = 0;
                        }
                        if (var_a0_4->unk_2520 < 4) {
                            var_a0_4->unk_2520 = 0;
                        }
                        var_v1_3->unk_2540 = 0;
                        var_a0_4->unk_2540 = 0;
                        var_a0_4 += 0x48;
                        var_s0_2 += 1;
                        var_v1_3 += 0x48;
                    } while (var_s0_2 < 0x14);
                    gTheGame.unk_9988[0x1D6] = 0x374;
                    gTheGame.unk_9988[0x1FE] = 0x374;
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        func_8006C9BC_usa(&gTheGame, 0);
                    }
                    if (gTheGame.unk_8860[1] == 8) {
                        func_8006C9BC_usa((TheGame *) &gTheGame.unk_0000[1], 1);
                    }
                    gMain = 0x38F;
                    B_8021BA5C_usa = 0;
                    gTheGame.unk_43EC = 0;
                    gTheGame.unk_0000[1].unk_43EC = 0;
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        gTheGame.unk_43FC = 0x27;
                    }
                    if (gTheGame.unk_8860[1] == 8) {
                        gTheGame.unk_0000[1].unk_43FC = 0x27;
                    }
                    if (gSelection == 0x96) {
                        var_a1_4 = 0x175;
                        if (((var_s3 == var_s1) | (var_s1 != 0)) != 0) {

                        } else {
                            goto block_152;
                        }
                    } else {
                        var_a1_4 = 0x175;
                        if (var_s3 == var_s1) {

                        } else {
block_152:
                            var_a1_4 = 0x174;
                        }
                    }
                    func_80005184_usa(&D_800B4160_usa, var_a1_4);
                    FadeOutSong(last_song_handle, 0x3C);
                    break;
                case 0x38F:                         /* switch 2 */
                    if (var_s3 == 0) {
                        func_80037270_usa(&gTheGame);
                        func_80038018_usa(&gTheGame, 0);
                        func_8003813C_usa(&gTheGame);
                    }
                    if (var_s1 == 0) {
                        func_80037270_usa((TheGame *) &gTheGame.unk_0000[1]);
                        func_80038018_usa((TheGame *) &gTheGame.unk_0000[1], 1);
                        func_8003813C_usa((TheGame *) &gTheGame.unk_0000[1]);
                    }
                    break;
                case 0x390:                         /* switch 2 */
                    temp_v0_3 = B_8021BA5C_usa;
                    if (temp_v0_3 == 0) {
                        if (gSelection != 0x96) {
                            var_a0_3 = (u32) (gGameStatus & 0xF00) >> 8;
                            if ((gTheGame.unk_4404 != var_a0_3) && (gTheGame.unk_0000[1].unk_4404 != var_a0_3)) {

                            } else {
                                goto block_164;
                            }
                        } else if (-var_s3 != 0) {
block_164:
                            func_8003E508_usa(var_a0_3);
                        }
                    }
                    B_8021BA5C_usa = temp_v0_3 + 1;
                    if (gTheGame.unk_43EC != 0) {
                        gTheGame.unk_43EC = (s32) (gTheGame.unk_43EC - 1);
                    } else {
                        temp_v0_4 = gTheGame.unk_0000[1].unk_43EC;
                        if (temp_v0_4 != 0) {
                            gTheGame.unk_0000[1].unk_43EC = (s32) (temp_v0_4 - 1);
                        } else {
                            gMain = 0x391;
                            if (var_s3 != 0) {
                                gTheGame.unk_43FC = 0x32;
                            }
                            if (var_s1 != 0) {
                                gTheGame.unk_0000[1].unk_43FC = 0x32;
                            }
                        }
                    }
                    break;
                case 0x391:                         /* switch 2 */
                    if ((var_s3 == 0) & (var_s1 == 0)) {
                        gMain = 0x392;
                    }
                    if (var_s3 != 0) {
                        func_8003837C_usa(&gTheGame, 0);
                    }
                    if (var_s1 != 0) {
                        func_8003837C_usa((TheGame *) &gTheGame.unk_0000[1], 1);
                    }
                    if (gMain == 0x392) {
                        if (var_s3 == 0) {
                            gTheGame.unk_43FC = 0x60;
                        }
                        if (var_s1 == 0) {
                            gTheGame.unk_0000[1].unk_43FC = 0x60;
                        }
                    }
                    break;
                case 0x392:                         /* switch 2 */
                    if (var_s3 == 0) {
                        func_8003853C_usa(&gTheGame, 0);
                    }
                    if (var_s1 == 0) {
                        func_8003853C_usa((TheGame *) &gTheGame.unk_0000[1], 1);
                    }
                    if (gMain == 0x393) {
                        gTheGame.unk_43FC = 0x36;
                        gTheGame.unk_0000[1].unk_43FC = 0x36;
                        gTheGame.unk_43EC = 0x3C;
                        gTheGame.unk_0000[1].unk_43EC = 0x3C;
                    }
                    break;
                case 0x393:                         /* switch 2 */
                    if (gTheGame.unk_43EC != 0) {
                        gTheGame.unk_43EC = (s32) (gTheGame.unk_43EC - 1);
                    } else {
                        if (gTheGame.unk_43FC == 0x36) {
                            func_80005184_usa(&D_800B4160_usa, 0xA4);
                        }
                        temp_a0_2 = *(&D_800B66FC_usa + gTheGame.unk_43FC);
                        gTheGame.unk_43FC = (s32) (gTheGame.unk_43FC - 1);
                        gTheGame.unk_9988[0x1D4] = (u16) ((((s32) (gTheGame.unk_9988[0x1D4] << 0x10) >> 0x12) - (temp_a0_2 - (gTheGame.unk_9C0C == 2))) * 4);
                        if (gTheGame.unk_43FC < 0) {
                            gMain = 0x394;
                        }
                    }
                    temp_v0_5 = gTheGame.unk_0000[1].unk_43EC;
                    if (temp_v0_5 != 0) {
                        gTheGame.unk_0000[1].unk_43EC = (s32) (temp_v0_5 - 1);
                    } else {
                        if (gTheGame.unk_0000[1].unk_43FC == 0x36) {
                            func_80005184_usa(&D_800B4160_usa, 0xA4);
                        }
                        temp_v0_6 = gTheGame.unk_0000[1].unk_43FC;
                        gTheGame.unk_0000[1].unk_43FC = (s32) (temp_v0_6 - 1);
                        gTheGame.unk_9988[0x1FC] = (u16) ((((s32) (gTheGame.unk_9988[0x1FC] << 0x10) >> 0x12) - (*(&D_800B66FC_usa + temp_v0_6) - (gTheGame.unk_9C0C == 2))) * 4);
                        if (gTheGame.unk_0000[1].unk_43FC < 0) {
                            gMain = 0x394;
                        }
                    }
                    if (gTheGame.unk_43FC < 0x32) {
                        var_v1_4 = *(&D_800B66FC_usa + gTheGame.unk_43FC);
                        if (var_v1_4 == -0x10) {
                            var_v1_4 = -0x1C;
                        }
                        gTheGame.unk_9988[0x114] = (u16) ((((s32) (gTheGame.unk_9988[0x114] << 0x10) >> 0x12) - var_v1_4) * 4);
                    }
                    temp_v1_2 = gTheGame.unk_0000[1].unk_43FC;
                    if (temp_v1_2 < 0x32) {
                        var_v1_5 = *(&D_800B66FC_usa + temp_v1_2);
                        if (var_v1_5 == -0x10) {
                            var_v1_5 = -0x1C;
                        }
                        gTheGame.unk_9988[0x13C] = (u16) ((((s32) (gTheGame.unk_9988[0x13C] << 0x10) >> 0x12) - var_v1_5) * 4);
                    }
                    if ((((gSelection == 0x96) & var_s3) || (((gSelection == 0xA0) | (gSelection == 0xB4)) != 0) || (gSelection == 0xC8)) && (gTheGame.unk_43EC == 0) && (gTheGame.unk_43FC == 0x29)) {
                        if (B_801C6C90_usa != 0x10) {
                            func_80005184_usa(&D_800B4160_usa, 0x17A);
                        } else {
block_267:
                            PlayMIDI(&BGM_INIT_TABLE, 0x45, 0, 1);
                        }
                    }
                    break;
                case 0x394:                         /* switch 2 */
                    gTheGame.unk_9988[0x164] = 0x30C;
                    gTheGame.unk_9988[0x18C] = 0x30C;
                    if (gSelection != 0x96) {
                        temp_a0_3 = (u32) (gGameStatus & 0xF00) >> 8;
                        if (gTheGame.unk_0000[0].unk_43BC[0x48] == temp_a0_3) {
                            temp_v1_3 = gTheGame.unk_9C20[8] + 1;
                            gTheGame.unk_4420 = (s32) (gTheGame.unk_4420 + 1);
                            gTheGame.unk_9C20[8] = temp_v1_3;
                            if (temp_v1_3 >= 0x64) {
                                gTheGame.unk_4420 = 0x63;
                                gTheGame.unk_9C20[8] = 0x63;
                            }
                        } else if (gTheGame.unk_0000[1].unk_43BC[0x48] == temp_a0_3) {
                            temp_v1_4 = gTheGame.unk_9C20[0x18] + 1;
                            gTheGame.unk_0000[1].unk_4420 = (s32) (gTheGame.unk_0000[1].unk_4420 + 1);
                            gTheGame.unk_9C20[0x18] = temp_v1_4;
                            if (temp_v1_4 >= 0x64) {
                                gTheGame.unk_0000[1].unk_4420 = 0x63;
                                gTheGame.unk_9C20[0x18] = 0x63;
                            }
                        }
                    }
                    if (var_s3 != 0) {
                        if (gSelection == 0x96) {
                            var_a0_5 = 0;
                            var_a1_5 = 0;
                        } else if (gTheGame.unk_4404 == 1) {
                            var_a0_5 = 1;
                            var_a1_5 = 0;
                        } else {
                            var_a0_5 = 1;
                            if (gTheGame.unk_4404 == 2) {
                                var_a1_5 = 1;
                            } else {
                                var_a1_5 = 2;
                            }
                        }
                        func_8006C7A0_usa(var_a0_5, var_a1_5);
                        func_80005888_usa(0, 1, 2);
                    }
                    if (var_s1 != 0) {
                        if (gSelection == 0x96) {
                            var_a0_6 = 1;
                            var_a1_6 = 0;
                        } else {
                            temp_v1_5 = gTheGame.unk_0000[1].unk_4404;
                            if (temp_v1_5 == 1) {
                                var_a0_6 = 0;
                                var_a1_6 = 0;
                            } else {
                                var_a0_6 = 0;
                                if (temp_v1_5 == 2) {
                                    var_a1_6 = 1;
                                } else {
                                    var_a1_6 = 2;
                                }
                            }
                        }
                        func_8006C7A0_usa(var_a0_6, var_a1_6);
                        func_80005888_usa(0, 2, 2);
                        if (gSelection == 0x96) {
                            var_a1_7 = 0x42;
                            if (B_801C6C90_usa != 0x10) {

                            } else {
                                var_a1_7 = 0x20;
                            }
                            PlayMIDI(&BGM_INIT_TABLE, var_a1_7, 0, 1);
                        }
                    }
                    gTheGame.unk_43FC = -1;
                    gTheGame.unk_0000[1].unk_43FC = -1;
                    gTheGame.unk_43EC = 0;
                    gTheGame.unk_0000[1].unk_43EC = 0;
                    B_8021BA5C_usa = 0;
                    var_a0_7 = 0;
                    if ((var_s3 != 0) || (var_a0_7 = 1, (var_s1 != 0))) {
                        func_8006C4A0_usa(var_a0_7);
                    }
                    if (var_s3 != var_s1) {
                        gMain = 0x395;
                    } else {
block_254:
                        gMain = 0x396;
                    }
                    break;
                case 0x395:                         /* switch 2 */
                    if (func_80038944_usa(var_a0_3) != 0) {
                        goto block_254;
                    }
                    break;
                case 0x396:                         /* switch 2 */
                    if (var_s3 == var_s1) {
                        func_8003547C_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                        func_8003547C_usa((TheGame *) &gTheGame.unk_0000[1], &gTheGame.unk_9988[0x108] + 0x28);
                    } else {
                        if (var_s3 != 0) {
                            func_8003536C_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                        } else {
                            func_800353F4_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                        }
                        if (var_s1 != 0) {
                            func_8003536C_usa((TheGame *) &gTheGame.unk_0000[1], &gTheGame.unk_9988[0x130]);
                        } else {
                            func_800353F4_usa((TheGame *) &gTheGame.unk_0000[1], &gTheGame.unk_9988[0x130]);
                        }
                        func_8003880C_usa();
                    }
                    func_80035584_usa(&gTheGame.unk_9988[0x158]);
                    func_80035584_usa(&gTheGame.unk_9988[0x158] + 0x28);
                    temp_v0_7 = B_8021BA5C_usa + 1;
                    B_8021BA5C_usa = temp_v0_7;
                    if ((temp_v0_7 == 0xDC) && ((gSelection != 0x96) || ((var_s3 != 0) & (var_s1 == 0)))) {
                        goto block_267;
                    }
                    break;
            }
            if (gTheGame.unk_9C0C == 1) {
                func_8004F70C_usa(&gTheGame, 0, 0);
                var_a0_2 = (TheGame *) &gTheGame.unk_0000[1];
                var_a1_3 = 1;
block_270:
                func_8004F70C_usa(var_a0_2, var_a1_3, 0);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/end", DoGameOver2D);
#endif
#endif

#if VERSION_USA
#if 0
? func_80005184_usa(? *, ?);                        /* extern */
? func_80005888_usa(?, ?, ?);                       /* extern */
? func_80005A08_usa(s32);                           /* extern */
? func_80034DB8_usa();                              /* extern */
? func_800352DC_usa(TheGame *, s8 *);               /* extern */
? func_800353B0_usa(TheGame *, s8 *);               /* extern */
? func_80035438_usa(TheGame *, s8 *);               /* extern */
? func_800354C0_usa(TheGame *, s8 *);               /* extern */
? func_80035584_usa(s8 *);                          /* extern */
? func_80037270_usa(TheGame *);                     /* extern */
? func_80037440_usa(TheGame *);                     /* extern */
? func_80037724_usa(TheGame *);                     /* extern */
? func_800379D4_usa(TheGame *, TheGame_unk_8860 *); /* extern */
? func_80037B0C_usa(TheGame *, TheGame_unk_8860 *); /* extern */
s32 func_80037CBC_usa(TheGame *);                   /* extern */
? func_8003813C_usa(TheGame *);                     /* extern */
? func_80038228_usa(TheGame *, TheGame_unk_8860 *, ?); /* extern */
? func_8003880C_usa();                              /* extern */
s32 func_80038944_usa(s32);                         /* extern */
s32 func_8003901C_usa(TheGame *);                   /* extern */
? func_80039A54_usa(?);                             /* extern */
? func_80039B78_usa();                              /* extern */
s32 func_8003A0B8_usa();                            /* extern */
? func_8003E508_usa(u32);                           /* extern */
? func_8004ADD0_usa(?);                             /* extern */
? func_8004C280_usa(s32);                           /* extern */
? func_8004E450_usa();                              /* extern */
s32 func_8004FA2C_usa();                            /* extern */
? func_800521A4_usa(?);                             /* extern */
? func_80058458_usa(s32, s32);                      /* extern */
? func_8005866C_usa(TheGame_unk_8860 *, s32, s32);  /* extern */
? func_80058A10_usa(TheGame_unk_8860 *, s32, s32);  /* extern */
? func_8005D8B4_usa(TheGame *);                     /* extern */
? func_8005D900_usa(TheGame *);                     /* extern */
? func_8005DBD8_usa(TheGame *, ?);                  /* extern */
? func_8005DD3C_usa(TheGame *);                     /* extern */
? func_8005DDB4_usa(TheGame *);                     /* extern */
? func_8005DDF8_usa(TheGame *);                     /* extern */
? func_8005E0E8_usa(?);                             /* extern */
? func_8005E108_usa(?, ?);                          /* extern */
? func_8005E128_usa(TheGame *, ?);                  /* extern */
? func_8006780C_usa(TheGame_unk_0000 *, TheGame_unk_8860 *); /* extern */
? func_80067CA0_usa(TheGame *, TheGame_unk_8860 *); /* extern */
extern u8 B_801C6C90_usa;
extern s32 B_8021BA5C_usa;
extern ? D_800B4160_usa;
extern s32 D_800B65B0_usa;
extern ? D_800B66FC_usa;
extern ? D_800B6734_usa;
extern ? D_800B675C_usa;

void DoGameOver3D(void) {
    ? var_a0_2;
    ? var_a0_5;
    ? var_a1;
    ? var_a1_4;
    ? var_a1_5;
    ? var_a1_6;
    TheGame *var_a0;
    TheGame *var_v1_2;
    TheGame_unk_0000 *var_a0_3;
    TheGame_unk_8860 *var_a1_3;
    f64 temp_fv0;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_6;
    s32 var_a0_4;
    s32 var_a1_2;
    s32 var_a1_7;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v1;
    s8 temp_a0_4;
    s8 var_v1_3;
    s8 var_v1_4;
    u32 temp_a0_2;
    u32 temp_a0_3;
    u32 temp_a0_5;

    var_v1 = 0xC0;
    gTheGame.unk_89C8[0x6F8] = 6;
    do {
        (&gTheGame.unk_90C8.unk_000[0x18])[var_v1] = -1;
        var_v1 += 0x20;
    } while (var_v1 < 0x8C0);
    func_8004C280_usa(-1);
    if ((gMain < 0x395) || (B_8021BA5C_usa < 6) || (func_8003A0B8_usa() == 0)) {
        var_s4 = 0;
        if (gTheGame.unk_9C08 == 1) {
            switch (gMain) {                        /* switch 1 */
                case GMAIN_38E:                     /* switch 1 */
                    if (gSelection != 0x82) {
                        if (gSelection == 0xAA) {
                            func_80058A10_usa(gTheGame.unk_8860, gTheGame.unk_9C20[0xC], gTheGame.unk_9C20[0x10]);
                        }
                    } else {
                        func_8005866C_usa(gTheGame.unk_8860, gTheGame.unk_9C20[8], gTheGame.unk_9C20[0xC]);
                    }
                    func_80034DB8_usa();
                    func_8004E450_usa();
                    switch (gSelection) {           /* switch 3; irregular */
                        case 0x8C:                  /* switch 3 */
                        case 0xAA:                  /* switch 3 */
                        case 0xBE:                  /* switch 3 */
                            gTheGame.unk_9988[0x1C0] = 0;
                            gTheGame.unk_8860[0].unk_C = 0;
                            break;
                        case 0x78:                  /* switch 3 */
                            /* fallthrough */
                        case 0x82:                  /* switch 3 */
                            gTheGame.unk_9988[0x1C0] = -1;
                            break;
                    }
                    gGameStatus &= ~0x20;
                    func_8005DD3C_usa(&gTheGame);
                    func_8005DDF8_usa(&gTheGame);
                    gTheGame.unk_9C20[4] = 0;
                    gTheGame.unk_89C8[0x6E8] = -0x280;
                    gTheGame.unk_89C8[0x6D0] = -0x280;
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        func_8005E128_usa(&gTheGame, 0);
                    }
                    func_80039A54_usa(0);
                    if (gSelection == 0x8C) {
                        if (gTheGame.unk_43AC < 0x2710) {

                        } else {
                            goto block_29;
                        }
                    } else if ((gSelection == 0xBE) && (gTheGame.unk_8860[0].unk_0 != 8)) {
block_29:
                        func_80039A54_usa(-1);
                    }
                    gMain = 0x38F;
                    gTheGame.unk_43FC = 0x25;
                    B_8021BA5C_usa = 0;
                    D_800B65B0_usa = 0;
                    gTheGame.unk_43EC = 0;
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        func_80005184_usa(&D_800B4160_usa, 0xA0);
                        if (gSelection != 0x82) {
                            var_a1 = 0x175;
                            goto block_39;
                        }
                    } else {
                        var_a1 = 0x174;
                        if (gSelection != 0xBE) {
                            func_80005184_usa(&D_800B4160_usa, 0xA1);
                            if (gTheGame.unk_9C20[8] != 5) {
                                if (gTheGame.unk_9C20[0x10] == 5) {
                                    var_a1 = 0x9F;
                                } else {
                                    var_a1 = 0x9E;
                                }
                                goto block_39;
                            }
                        } else {
block_39:
                            func_80005184_usa(&D_800B4160_usa, var_a1);
                        }
                    }
                    FadeOutSong(last_song_handle, 0x3C);
                    var_a0 = &gTheGame;
                    break;
                case 0x38F:                         /* switch 1 */
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        func_80037270_usa(&gTheGame);
                        if (gTheGame.unk_43FC >= 0) {
                            temp_fv0 = (f64) gTheGame.unk_0000[0].unk_4088 + ((f64) (f32) *(&D_800B6734_usa + gTheGame.unk_43FC) / 250.0);
                            gTheGame.unk_43FC = (s32) (gTheGame.unk_43FC - 1);
                            gTheGame.unk_0000[0].unk_4088 = (f32) temp_fv0;
                        }
                        func_80037440_usa(&gTheGame);
                    } else {
                        func_80037724_usa(&gTheGame);
                    }
                    var_a0 = &gTheGame;
                    if (gMain == 0x390) {
                        gTheGame.unk_43EC = 0x28;
                    }
                    break;
                case 0x390:                         /* switch 1 */
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        func_800379D4_usa(&gTheGame, gTheGame.unk_8860);
                        var_a0 = &gTheGame;
                    } else {
                        temp_v0 = gTheGame.unk_43EC - 1;
                        gTheGame.unk_43EC = temp_v0;
                        if (temp_v0 == 0) {
                            gMain = 0x391;
                            var_a0 = &gTheGame;
                            if (gSelection == 0xBE) {
                                func_8005DBD8_usa(&gTheGame, 0);
                                func_8005D900_usa(&gTheGame);
                                var_a0 = &gTheGame;
                            }
                        } else {
                        default:                    /* switch 1 */
block_108:
                            var_a0 = &gTheGame;
                        }
                    }
                    break;
                case 0x391:                         /* switch 1 */
                    temp_v0_2 = B_8021BA5C_usa;
                    if (temp_v0_2 == 0) {
                        func_8003E508_usa();
                    }
                    B_8021BA5C_usa = temp_v0_2 + 1;
                    if (gTheGame.unk_43EC != 0) {
                        gTheGame.unk_43EC = (s32) (gTheGame.unk_43EC - 1);
                        goto block_108;
                    }
                    if (((gSelection == 0x8C) | (gSelection == 0xBE)) != 0) {
                        func_8005DD3C_usa(&gTheGame);
                        var_s0 = func_8003901C_usa(&gTheGame);
                        if (B_8021BA5C_usa == 0x55) {
                            var_a0_2 = -1;
                            if (func_8004FA2C_usa() != 0) {
                                goto block_62;
                            }
                        } else {
                            var_a0_2 = 0;
                            if (B_8021BA5C_usa >= 0x56) {
block_62:
                                func_8004ADD0_usa(var_a0_2);
                            }
                        }
                        if (B_8021BA5C_usa == 0x5A) {
                            if (gSelection == 0x8C) {
                                if (gTheGame.unk_43AC >= 0x2710) {
                                    PlayMIDI(BGM_INIT_TABLE, 0x46, 0, 2);
                                    func_80005184_usa(&D_800B4160_usa, 0x7D);
                                } else {
                                    goto block_72;
                                }
                            } else if (gSelection == 0xBE) {
                                if (gTheGame.unk_8860[0].unk_0 != 8) {
                                    if (gTheGame.unk_43AC >= 0x2710) {
                                        PlayMIDI(BGM_INIT_TABLE, 0x46, 0, 2);
                                        func_80005184_usa(&D_800B4160_usa, 0x80);
                                    } else {
                                        var_a1_2 = 0x45;
                                        goto block_73;
                                    }
                                } else {
block_72:
                                    var_a1_2 = 0x42;
block_73:
                                    PlayMIDI(BGM_INIT_TABLE, var_a1_2, 0, 1);
                                }
                            }
                        }
                    } else {
                        var_s0 = 0;
                        if (gTheGame.unk_8860[0].unk_0 == 7) {
                            var_s0 = func_80037CBC_usa(&gTheGame);
                            func_8005D8B4_usa(&gTheGame);
                        }
                    }
                    if ((var_s0 == 0) && (B_8021BA5C_usa >= 0x5B)) {
                        gMain = 0x392;
                    }
                    var_a0 = &gTheGame;
                    if (gMain == 0x392) {
                        func_8005DBD8_usa(&gTheGame, 0);
                        func_8005D900_usa(&gTheGame);
                        func_8005DD3C_usa(&gTheGame);
                        if ((gSelection >= 0x83) || (gTheGame.unk_8860[0].unk_0 != 7)) {
                            if ((gSelection == 0xAA) && (gTheGame.unk_8860[0].unk_0 == 7)) {
                                goto block_85;
                            }
                            gTheGame.unk_43FC = 0x59;
                        } else {
block_85:
                            gTheGame.unk_43FC = 0x50;
                        }
                        goto block_108;
                    }
                    break;
                case 0x392:                         /* switch 1 */
                    func_80037B0C_usa(&gTheGame, gTheGame.unk_8860);
                    var_a0 = &gTheGame;
                    if (gMain == 0x393) {
                        gTheGame.unk_9C20[4] = 0;
                        gTheGame.unk_43EC = 0;
                    }
                    break;
                case 0x393:                         /* switch 1 */
                    gTheGame.unk_9988[0x13C] = 0x26CU;
                    gTheGame.unk_9988[0x164] = 0x2D0;
                    if (gTheGame.unk_8860[0].unk_0 == 7) {
                        if (((gSelection < 0x83) | (gSelection == 0xAA)) != 0) {
                            PlayMIDI(BGM_INIT_TABLE, 0x45, 0, 1);
                            if (gSelection == 0x82) {
                                func_80005A08_usa(gTheGame.unk_9C20[8]);
                            }
                        }
                    } else if ((gSelection != 0x8C) & (gSelection != 0xBE)) {
                        if (func_8004FA2C_usa() != 0) {
                            func_8004ADD0_usa(-1);
                        }
                        PlayMIDI(BGM_INIT_TABLE, 0x42, 0, 1);
                        if (gSelection == 0xAA) {
                            if (gTheGame.unk_9C20[8] == 5) {
                                if (gTheGame.unk_9C20[0xC] == 3) {
                                    func_80005184_usa(&D_800B4160_usa, 0x81);
                                } else {
                                    goto block_101;
                                }
                            } else {
block_101:
                                func_80005888_usa(0, 2, 2);
                            }
                        }
                    }
                    B_8021BA5C_usa = 0;
                    gMain = 0x395;
                    var_a0 = &gTheGame;
                    break;
                case 0x395:                         /* switch 1 */
                    func_800352DC_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                    func_80039B78_usa();
                    func_8004ADD0_usa(0);
                    if ((((gSelection == 0xAA) | (gSelection == 0x82)) != 0) && (gTheGame.unk_8860[0].unk_0 == 7)) {
                        func_80035584_usa(&gTheGame.unk_9988[0x108] + 0x28);
                    }
                    B_8021BA5C_usa += 1;
                    goto block_108;
            }
            var_a1_3 = gTheGame.unk_8860;
        } else {
            temp_v1 = gTheGame.unk_8860[0].unk_0;
            temp_a0 = gTheGame.unk_8860[1];
            var_s3 = 0;
            if (temp_v1 != temp_a0) {
                if (temp_v1 != 8) {
                    if (temp_a0 != 7) {
                        var_s4 = -1;
                    } else {
                        goto block_115;
                    }
                } else {
block_115:
                    var_s3 = -1;
                }
            }
            switch (gMain) {                        /* switch 2 */
                case GMAIN_38E:                     /* switch 2 */
                    if (var_s4 != var_s3) {
                        if (var_s4 != 0) {
                            gTheGame.unk_4404 = (s32) (gTheGame.unk_4404 + 1);
                        } else if (var_s3 != 0) {
                            gTheGame.unk_0000[1].unk_4404 = (s32) (gTheGame.unk_0000[1].unk_4404 + 1);
                        }
                    }
                    temp_a0_2 = (u32) (gGameStatus & 0xF00) >> 8;
                    if ((gTheGame.unk_4404 == temp_a0_2) || (gTheGame.unk_0000[1].unk_4404 == temp_a0_2)) {
                        func_80058458_usa(var_s4, var_s3);
                    }
                    var_s0_2 = 0;
                    func_80034DB8_usa();
                    func_8004E450_usa();
                    func_8005DD3C_usa(&gTheGame);
                    func_8005DD3C_usa((TheGame *) &gTheGame.unk_0000[1]);
                    func_8005DDF8_usa(&gTheGame);
                    func_8005DDF8_usa((TheGame *) &gTheGame.unk_0000[1]);
                    gTheGame.unk_9C20[4] = 0;
                    var_a0_3 = &gTheGame.unk_0000[1];
                    var_v1_2 = &gTheGame;
                    do {
                        if (var_v1_2->unk_2520 < 4) {
                            var_v1_2->unk_2520 = 0;
                        }
                        if (var_a0_3->unk_2520 < 4) {
                            var_a0_3->unk_2520 = 0;
                        }
                        var_v1_2->unk_2540 = 0;
                        var_a0_3->unk_2540 = 0;
                        var_a0_3 += 0x48;
                        var_s0_2 += 1;
                        var_v1_2 += 0x48;
                    } while (var_s0_2 < 0x14);
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        func_8005E128_usa(&gTheGame, 0);
                    }
                    if (gTheGame.unk_8860[1] == 8) {
                        func_8005E128_usa((TheGame *) &gTheGame.unk_0000[1], 1);
                    }
                    gMain = 0x38F;
                    B_8021BA5C_usa = 0;
                    gTheGame.unk_43EC = 0;
                    gTheGame.unk_0000[1].unk_43EC = 0;
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        gTheGame.unk_43FC = 0x27;
                    }
                    if (gTheGame.unk_8860[1] == 8) {
                        gTheGame.unk_0000[1].unk_43FC = 0x27;
                    }
                    gTheGame.unk_9988[0x1D4] = 0x37CU;
                    gTheGame.unk_9988[0x1FC] = 0x37CU;
                    if (var_s4 != var_s3) {
                        var_a1_4 = 0x174;
                    } else {
                        var_a1_4 = 0x175;
                    }
                    func_80005184_usa(&D_800B4160_usa, var_a1_4);
                    FadeOutSong(last_song_handle, 0x3C);
                    break;
                case 0x38F:                         /* switch 2 */
                    if (var_s4 == 0) {
                        func_80037270_usa(&gTheGame);
                        if (gTheGame.unk_43FC >= 0) {
                            gTheGame.unk_0000[0].unk_4088 = (f32) ((f64) gTheGame.unk_0000[0].unk_4088 + ((f64) (f32) *(&D_800B675C_usa + gTheGame.unk_43FC) / 250.0));
                            func_8003813C_usa(&gTheGame);
                        }
                    }
                    if (var_s3 == 0) {
                        func_80037270_usa((TheGame *) &gTheGame.unk_0000[1]);
                        temp_v0_3 = gTheGame.unk_0000[1].unk_43FC;
                        if (temp_v0_3 >= 0) {
                            gTheGame.unk_0000[1].unk_4088 = (f32) ((f64) gTheGame.unk_0000[1].unk_4088 + ((f64) (f32) *(&D_800B675C_usa + temp_v0_3) / 250.0));
                            func_8003813C_usa((TheGame *) &gTheGame.unk_0000[1]);
                        }
                    }
                    temp_v1_2 = gTheGame.unk_0000[1].unk_43FC - 1;
                    gTheGame.unk_43FC = (s32) (gTheGame.unk_43FC - 1);
                    gTheGame.unk_0000[1].unk_43FC = temp_v1_2;
                    if ((B_8021BA5C_usa == 0) && (gTheGame.unk_43FC < -0x3C) && (temp_v1_2 < -0x3C)) {
                        temp_a0_3 = (u32) (gGameStatus & 0xF00) >> 8;
                        if ((gTheGame.unk_4404 == temp_a0_3) || (gTheGame.unk_0000[1].unk_4404 == temp_a0_3)) {
                            func_8003E508_usa(temp_a0_3);
                        }
                        B_8021BA5C_usa += 1;
                    }
                    if ((gTheGame.unk_43FC < -0x5A) && (gTheGame.unk_0000[1].unk_43FC < -0x5A)) {
                        gMain = 0x390;
                        gTheGame.unk_43EC = 0;
                        gTheGame.unk_0000[1].unk_43EC = 0;
                    }
                    break;
                case 0x390:                         /* switch 2 */
                    func_80038228_usa(&gTheGame, gTheGame.unk_8860, 0);
                    func_80038228_usa((TheGame *) &gTheGame.unk_0000[1], &gTheGame.unk_8860[1], 1);
                    var_a0_4 = 0;
                    if (((f64) gTheGame.unk_0000[0].unk_4088 > 1.8) && ((f64) gTheGame.unk_0000[1].unk_4088 > 1.8)) {
                        var_a0_4 = -1;
                    }
                    if (var_a0_4 != 0) {
                        gMain = 0x391;
                        func_8005DBD8_usa(&gTheGame, 0);
                        func_8005DBD8_usa((TheGame *) &gTheGame.unk_0000[1], 1);
                        func_8005D900_usa(&gTheGame);
                        func_8005D900_usa((TheGame *) &gTheGame.unk_0000[1]);
                        func_8005DDB4_usa(&gTheGame);
                        func_8005DDB4_usa((TheGame *) &gTheGame.unk_0000[1]);
                        gTheGame.unk_43FC = 0x36;
                        gTheGame.unk_0000[1].unk_43FC = 0x36;
                        gTheGame.unk_43EC = 0x5A;
                        gTheGame.unk_0000[1].unk_43EC = 0x5A;
                        func_800521A4_usa(5);
                    } else {
                    default:                        /* switch 2 */
                    }
                    break;
                case 0x391:                         /* switch 2 */
                    if (gTheGame.unk_43EC != 0) {
                        gTheGame.unk_43EC = (s32) (gTheGame.unk_43EC - 1);
                    } else {
                        if (gTheGame.unk_43FC == 0x36) {
                            func_80005184_usa(&D_800B4160_usa, 0xA4);
                        }
                        temp_a0_4 = *(&D_800B66FC_usa + gTheGame.unk_43FC);
                        gTheGame.unk_43FC = (s32) (gTheGame.unk_43FC - 1);
                        gTheGame.unk_9988[0x1D4] = (u16) ((((s32) (gTheGame.unk_9988[0x1D4] << 0x10) >> 0x12) - (temp_a0_4 - (gTheGame.unk_9C0C == 2))) * 4);
                        if (gTheGame.unk_43FC < 0) {
                            gMain = 0x394;
                        }
                    }
                    temp_v0_4 = gTheGame.unk_0000[1].unk_43EC;
                    if (temp_v0_4 != 0) {
                        gTheGame.unk_0000[1].unk_43EC = (s32) (temp_v0_4 - 1);
                    } else {
                        if (gTheGame.unk_0000[1].unk_43FC == 0x36) {
                            func_80005184_usa(&D_800B4160_usa, 0xA4);
                        }
                        temp_v0_5 = gTheGame.unk_0000[1].unk_43FC;
                        gTheGame.unk_0000[1].unk_43FC = (s32) (temp_v0_5 - 1);
                        gTheGame.unk_9988[0x1FC] = (u16) ((((s32) (gTheGame.unk_9988[0x1FC] << 0x10) >> 0x12) - (*(&D_800B66FC_usa + temp_v0_5) - (gTheGame.unk_9C0C == 2))) * 4);
                        if (gTheGame.unk_0000[1].unk_43FC < 0) {
                            gMain = 0x394;
                        }
                    }
                    if (gTheGame.unk_43FC < 0x32) {
                        var_v1_3 = *(&D_800B66FC_usa + gTheGame.unk_43FC);
                        if (var_v1_3 == -0x10) {
                            var_v1_3 = -0x1C;
                        }
                        gTheGame.unk_9988[0x114] = (u16) ((((s32) (gTheGame.unk_9988[0x114] << 0x10) >> 0x12) - var_v1_3) * 4);
                    }
                    temp_v1_3 = gTheGame.unk_0000[1].unk_43FC;
                    if (temp_v1_3 < 0x32) {
                        var_v1_4 = *(&D_800B66FC_usa + temp_v1_3);
                        if (var_v1_4 == -0x10) {
                            var_v1_4 = -0x1C;
                        }
                        gTheGame.unk_9988[0x13C] = (u16) ((((s32) (gTheGame.unk_9988[0x13C] << 0x10) >> 0x12) - var_v1_4) * 4);
                    }
                    if ((gTheGame.unk_43FC < 0) && ((gMain = 0x392, (((gSelection == 0x96) & var_s4) != 0)) || (((gSelection == 0xA0) | (gSelection == 0xB4)) != 0) || (gSelection == 0xC8))) {
                        if (B_801C6C90_usa != 0x10) {
                            func_80005184_usa(&D_800B4160_usa, 0x17A);
                        } else {
block_238:
                            PlayMIDI(BGM_INIT_TABLE, 0x45, 0, 1);
                        }
                    }
                    break;
                case 0x392:                         /* switch 2 */
                    temp_a0_5 = (u32) (gGameStatus & 0xF00) >> 8;
                    if (gTheGame.unk_0000[0].unk_43BC[0x48] == temp_a0_5) {
                        temp_v1_4 = gTheGame.unk_9C20[8] + 1;
                        gTheGame.unk_4420 = (s32) (gTheGame.unk_4420 + 1);
                        gTheGame.unk_9C20[8] = temp_v1_4;
                        if (temp_v1_4 >= 0x64) {
                            gTheGame.unk_4420 = 0x63;
                            gTheGame.unk_9C20[8] = 0x63;
                        }
                    } else if (gTheGame.unk_0000[1].unk_43BC[0x48] == temp_a0_5) {
                        temp_v1_5 = gTheGame.unk_9C20[0x18] + 1;
                        gTheGame.unk_0000[1].unk_4420 = (s32) (gTheGame.unk_0000[1].unk_4420 + 1);
                        gTheGame.unk_9C20[0x18] = temp_v1_5;
                        if (temp_v1_5 >= 0x64) {
                            gTheGame.unk_0000[1].unk_4420 = 0x63;
                            gTheGame.unk_9C20[0x18] = 0x63;
                        }
                    }
                    if (var_s4 != 0) {
                        if (gTheGame.unk_4404 == 1) {
                            var_a1_5 = 0;
                        } else if (gTheGame.unk_4404 == 2) {
                            var_a1_5 = 1;
                        } else {
                            var_a1_5 = 2;
                        }
                        func_8005E108_usa(1, var_a1_5);
                        func_80005888_usa(0, 1, 2);
                    }
                    if (var_s3 != 0) {
                        temp_v1_6 = gTheGame.unk_0000[1].unk_4404;
                        if (temp_v1_6 == 1) {
                            var_a1_6 = 0;
                        } else if (temp_v1_6 == 2) {
                            var_a1_6 = 1;
                        } else {
                            var_a1_6 = 2;
                        }
                        func_8005E108_usa(0, var_a1_6);
                        func_80005888_usa(0, 2, 2);
                        if (gSelection == 0x96) {
                            var_a1_7 = 0x42;
                            if (B_801C6C90_usa != 0x10) {

                            } else {
                                var_a1_7 = 0x20;
                            }
                            PlayMIDI(BGM_INIT_TABLE, var_a1_7, 0, 1);
                        }
                    }
                    gTheGame.unk_43FC = -1;
                    gTheGame.unk_0000[1].unk_43FC = -1;
                    gTheGame.unk_43EC = 0;
                    gTheGame.unk_0000[1].unk_43EC = 0;
                    B_8021BA5C_usa = 0;
                    if (var_s4 != var_s3) {
                        gMain = 0x393;
                    } else {
block_221:
                        gMain = 0x394;
                    }
                    break;
                case 0x393:                         /* switch 2 */
                    if (func_80038944_usa(temp_a0) != 0) {
                        goto block_221;
                    }
                    break;
                case 0x394:                         /* switch 2 */
                    gTheGame.unk_9988[0x164] = 0x304;
                    gTheGame.unk_9988[0x18C] = 0x304;
                    var_a0_5 = 0;
                    if ((var_s4 != 0) || (var_a0_5 = 1, (var_s3 != 0))) {
                        func_8005E0E8_usa(var_a0_5);
                    }
                    gMain = 0x395;
                    break;
                case 0x395:                         /* switch 2 */
                    if (var_s4 == var_s3) {
                        func_800354C0_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                        func_800354C0_usa((TheGame *) &gTheGame.unk_0000[1], &gTheGame.unk_9988[0x108] + 0x28);
                    } else {
                        if (var_s4 != 0) {
                            func_800353B0_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                        } else {
                            func_80035438_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                        }
                        if (var_s3 != 0) {
                            func_800353B0_usa((TheGame *) &gTheGame.unk_0000[1], &gTheGame.unk_9988[0x130]);
                        } else {
                            func_80035438_usa((TheGame *) &gTheGame.unk_0000[1], &gTheGame.unk_9988[0x130]);
                        }
                        func_8003880C_usa();
                    }
                    func_80035584_usa(&gTheGame.unk_9988[0x158]);
                    func_80035584_usa(&gTheGame.unk_9988[0x158] + 0x28);
                    temp_v0_6 = B_8021BA5C_usa + 1;
                    B_8021BA5C_usa = temp_v0_6;
                    if (temp_v0_6 == 0xDC) {
                        if ((gSelection != 0x96) || ((var_s4 != 0) & (var_s3 == 0))) {
                            goto block_238;
                        }
                    }
                    break;
            }
            func_8006780C_usa(gTheGame.unk_0000, gTheGame.unk_8860);
            func_8006780C_usa(&gTheGame.unk_0000[1], &gTheGame.unk_8860[1]);
            func_80067CA0_usa(&gTheGame, gTheGame.unk_8860);
            var_a0 = (TheGame *) &gTheGame.unk_0000[1];
            var_a1_3 = &gTheGame.unk_8860[1];
        }
        func_80067CA0_usa(var_a0, var_a1_3);
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/end", DoGameOver3D);
#endif
#endif

#if VERSION_USA
void DoGameOver(void) {
    SetGameFade();

    if (gTheGame.unk_9C0C == 2) {
        DoGameOver3D();
    } else {
        DoGameOver2D();
    }
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003E508_usa);
#endif
