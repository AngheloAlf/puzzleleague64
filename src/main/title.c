#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "hvqm2util.h"
#include "the_game.h"
#include "controller.h"
#include "build.h"
#include "buffers.h"
#include "sfxlimit.h"
#include "segment_symbols.h"

#if VERSION_USA
extern u32 D_800B5890_usa[];

void func_80005C00_usa(void) {
    if (B_8018A808_usa < 7) {
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
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/title", func_80005EC0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/title", DrawTitle);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/title", func_8000628C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/title", RO_STR_800C3128_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/title", RO_STR_800C3134_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/title", RO_STR_800C3144_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/title", RO_STR_800C314C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/title", RO_STR_800C3154_usa);
#endif

#if VERSION_USA
#if 0
typedef struct struct_8018A7F4_usa {
    /* 0x00 */ UNK_TYPE unk_00;
    /* 0x00 */ UNK_TYPE unk_04;
    /* 0x00 */ UNK_TYPE unk_08;
    /* 0x00 */ UNK_TYPE unk_0C;
    /* 0x00 */ UNK_TYPE unk_10;
    /* 0x00 */ UNK_TYPE unk_14;
    /* 0x18 */ UNK_TYPE1 unk_18[0x6C];
    /* 0x80 */ UNK_TYPE unk_80;
} struct_8018A7F4_usa; // size >= 0x84


void FadeOutSong(s32, UNK_TYPE);                        /* extern */
void PlayMIDI(UNK_TYPE *, UNK_TYPE, UNK_TYPE, UNK_TYPE);                  /* extern */
void func_80005184_usa(UNK_TYPE *arg0, UNK_TYPE arg1);
void func_80005C00_usa(void *);                        /* extern */
void func_80009D30_usa(s32, s32);                      /* extern */
void func_8001ACA8_usa(s32 *);                         /* extern */
s32 func_80024BF4_usa(s32 *);                       /* extern */
s32 func_80024C14_usa();                            /* extern */
s32 func_80024C2C_usa(void);
void func_8002629C_usa(s32 *);                         /* extern */
s32 func_800273BC_usa(UNK_TYPE *arg0, UNK_TYPE arg1);
void func_80027E80_usa(s32, UNK_TYPE);                        /* extern */
void func_80028378_usa(s32, UNK_TYPE);                        /* extern */
void func_800284E4_usa(s32, UNK_TYPE);                        /* extern */
void func_8002CC18_usa();                              /* extern */
void func_8002CFE4_usa(UNK_TYPE);                             /* extern */
s32 func_8002DA70_usa(void);
s32 HVQM2Util_Play(UNK_TYPE *, UNK_TYPE, s32);                 /* extern */
void func_80089BE0_usa(UNK_TYPE arg0, UNK_TYPE arg1);
extern s32 B_8018A7F0_usa;
extern struct_8018A7F4_usa *gpData;
extern s32 B_8018A7F8_usa;
extern s32 B_8018A808_usa;
extern s32 B_801A1574_usa;
extern s32 B_801A59A4_usa;
extern UNK_TYPE B_801A5B30_usa;
extern u16 B_801A5B34_usa;
extern s16 B_801A5B36_usa;
extern u16 B_801A5B3E_usa;
extern s16 B_801A5B44_usa;
extern s16 B_801A5B46_usa;
extern s32 B_801A6D78_usa;
extern s32 B_801A6D98_usa;
extern s32 B_801A6D9C_usa;
extern s32 B_801A6DA0_usa;
extern s32 B_801A6DA4_usa;
extern s32 B_801A6DA8_usa;
extern s32 B_801A6DAC_usa;
extern s32 B_801A6DB0_usa;
extern s32 B_801A6DB4_usa;
extern UNK_TYPE B_801A6DB8_usa;
extern UNK_TYPE B_801AB860_usa;
extern s32 gGameStatus;
extern s32 B_801AD9BC_usa;
extern s32 B_801ADAE8_usa;
extern s32 B_801C6FA0_usa;
extern s32 gSelection;
extern s32 B_8021BA98_usa;
extern UNK_TYPE *B_8021BEA4_usa;
extern UNK_TYPE *B_8021BEA8_usa;
extern s32 last_song_handle;
extern UNK_TYPE BGM_INIT_TABLE;
extern UNK_TYPE D_800B4160_usa;
extern u8 D_800B69B0_usa;
extern const char RO_STR_800C3128_usa[];
extern const char RO_STR_800C3134_usa[];
extern const char RO_STR_800C3144_usa[];
extern const char RO_STR_800C314C_usa[];
extern const char RO_STR_800C3154_usa[];

void DoTitle(void) {
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    UNK_TYPE var_a1;
    UNK_TYPE var_a1_2;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_a3;
    s32 temp_s0;
    s32 temp_s2;
    s32 temp_t0;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s3;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    u32 temp_s0_2;
    u32 temp_s0_3;
    u32 temp_v0_2;

    temp_s0 = gpData->unk_08;
    gpData->unk_00++;
    sp10 = 0;
    sp14 = 0;
    func_8002629C_usa(&sp10);
    temp_v1 = gpData->unk_14;
    temp_s2 = gpData->unk_00;
    switch (temp_v1) {                              /* switch 1; irregular */
        case 0x1:                                   /* switch 1 */
            osViBlack(1U);
            break;
        case 0x2:                                   /* switch 1 */
            func_80027E80_usa(temp_s0, 0x64);
            func_800284E4_usa(temp_s0, 0x64);
            break;
        case 0x7:                                   /* switch 1 */
            if (func_8002DA70_usa() == 0) {
                var_v1 = 0;
loop_8:
                if (*(&B_801A5B30_usa + var_v1) != -1) {
                    if (*(&B_801A5B34_usa + var_v1) == 0) {
                        goto block_12;
                    }
                    var_v0 = -1;
                } else {
block_12:
                    var_v1 += 0x10;
                    var_v0 = 0;
                    if (var_v1 <= 0) {
                        goto loop_8;
                    }
                }
                if ((var_v0 != 0) && (gReset == 0)) {
                    gReset = -1;
                }
            }
            if (temp_s2 == ((temp_s2 / 600) * 0x258)) {
                func_8001ACA8_usa(&sp18);
                temp_a1 = gpData->unk_10 + 1;
                gpData->unk_10 = temp_a1;
                if (sp18 < temp_a1) {
                    gReset = -1;
                    FadeOutSong(last_song_handle, 0x3C);
                } else {
                    func_80009D30_usa(temp_s0, temp_a1);
                }
            }
            if ((temp_s2 + 2) == (((temp_s2 + 2) / 600) * 0x258)) {
                func_8002CFE4_usa(0xE);
            }
            break;

        case 0x3:                                   /* switch 1 */
            func_80005C00_usa(gpData);
            if (B_8018A808_usa == 7) {
                gpData->unk_00 = 0;
                gpData->unk_14 = 4;
                gpData->unk_80 = func_800273BC_usa(&RO_STR_800C3128_usa, 0x8E001);
            }
            break;
        case 0x4:                                   /* switch 1 */
            if ((func_80024C2C_usa() == 0) && (func_80024C14_usa() == 0) && (func_80024BF4_usa(&sp1C) != 0)) {
                HVQM2Util_Play(&RO_STR_800C3134_usa, 0, sp1C);
                gpData->unk_14 = 5;
            }
            break;
        case 0x5:                                   /* switch 1 */
            temp_v0 = func_800273BC_usa(&RO_STR_800C3144_usa, 0x8E401);
            if (temp_v0 != temp_s0) {
                gpData->unk_08 = temp_v0;
                gpData->unk_00 = 0;
                gpData->unk_14 = 6;
                PlayMIDI(&BGM_INIT_TABLE, 0x3C, 0, 0);
            }
            break;
        default:                                    /* switch 1 */
            var_s3 = gpData->unk_04;
            if (B_8018A7F0_usa > 0) {
                B_8018A7F0_usa -= 1;
                func_800284E4_usa(temp_s0, 0x6E);
                goto block_36;
            }
            func_80028378_usa(temp_s0, 0x6E);
            if (temp_s2 & 8) {
block_36:
                func_80028378_usa(temp_s0, 0x64);
            } else {
                func_800284E4_usa(temp_s0, 0x64);
            }
            if (B_801A5B3E_usa & 0x2000) {
                if (B_801A5B34_usa != 0) {
                    temp_a1_2 = (B_801C6FA0_usa + 1) & 0xF;
                    *(&B_801AB860_usa + (B_801C6FA0_usa * 4)) = (s32) B_801A5B34_usa;
                    B_801C6FA0_usa = temp_a1_2;
                    if ((*(&B_801AB860_usa + (((temp_a1_2 - 4) & 0xF) * 4)) == 0x4000) && (*((((temp_a1_2 - 3) & 0xF) * 4) + &B_801AB860_usa) == 0x8000)) {
                        temp_v1_2 = *((((temp_a1_2 - 2) & 0xF) * 4) + &B_801AB860_usa);
                        if ((temp_v1_2 == 0x20) && (*((((temp_a1_2 - 1) & 0xF) * 4) + &B_801AB860_usa) == temp_v1_2)) {
                            gGameStatus ^= 1;
                            func_80005184_usa(&D_800B4160_usa, 9);
                        }
                    }
                    temp_a2 = *(&B_801AB860_usa + (((B_801C6FA0_usa - 8) & 0xF) * 4));
                    if (temp_a2 == 0x8000) {
                        temp_t0 = *((((B_801C6FA0_usa - 7) & 0xF) * 4) + &B_801AB860_usa);
                        if (temp_t0 == 0x4000) {
                            temp_a3 = *((((B_801C6FA0_usa - 6) & 0xF) * 4) + &B_801AB860_usa);
                            if (temp_a3 == 0x10) {
                                temp_a1_3 = *((((B_801C6FA0_usa - 5) & 0xF) * 4) + &B_801AB860_usa);
                                if (temp_a1_3 == temp_a2) {
                                    temp_a2_2 = *((((B_801C6FA0_usa - 4) & 0xF) * 4) + &B_801AB860_usa);
                                    if ((temp_a2_2 == temp_a1_3) && (*((((B_801C6FA0_usa - 3) & 0xF) * 4) + &B_801AB860_usa) == temp_t0) && (*((((B_801C6FA0_usa - 2) & 0xF) * 4) + &B_801AB860_usa) == temp_a3) && (*((((B_801C6FA0_usa - 1) & 0xF) * 4) + &B_801AB860_usa) == temp_a2_2)) {
                                        B_8021BA98_usa = ~B_8021BA98_usa;
                                        func_80005184_usa(&D_800B4160_usa, 9);
                                    }
                                }
                            }
                        }
                    }
                }
                B_801A5B34_usa = 0;
                B_801A5B36_usa = 0;
                B_801A5B44_usa = 0;
                B_801A5B46_usa = 0;
            }
            var_v0_2 = var_s3 & 4;
            if (var_s3 & 2) {
                var_s3 = (-(D_800B69B0_usa & 1) & 5) | 1;
                gpData->unk_0C = 0;
                gpData->unk_00 = 0;
                var_v0_2 = var_s3 & 4;
            }
            if (var_v0_2 != 0) {
                temp_v1_3 = gpData->unk_0C + 1;
                gpData->unk_0C = temp_v1_3;
                if ((temp_v1_3 == 0x384) && (B_8018A7F8_usa != 8)) {
                    FadeOutSong(last_song_handle, 0x3C);
                }
                if (gpData->unk_0C >= 0x3C0) {
                    gDemo = 0xB;
                    B_8021BEA4_usa = &B_801A6DB8_usa;
                    B_8021BEA8_usa = &B_801A6DB8_usa;
                    gReset = -1;
                    B_801A1574_usa = 0;
                    B_801A59A4_usa = 0;
                    B_801AD9BC_usa = -1;
                    B_801ADAE8_usa = -1;
                    gGameStatus |= 0x80;
                    B_8018A7F8_usa++;
                    if (B_8018A7F8_usa == 0xA) {
                        B_8018A7F8_usa = 1;
                    }
                    switch (B_8018A7F8_usa) {
                        case 0x1:
                            gMain = 0x34C;
                            B_801A6D78_usa = 1;
                            *B_801A6D7C_usa = 1;
                            gSelection = 0x64;
                            B_801A6D98_usa = 1;
                            break;
                        case 0x3:
                            gMain = 0x34C;
                            B_801A6D78_usa = 1;
                            *B_801A6D7C_usa = 1;
                            gSelection = 0x64;
                            B_801A6D98_usa = 2;
                            break;
                        case 0x5:
                            gMain = 0x34C;
                            B_801A6D78_usa = 1;
                            *B_801A6D7C_usa = 1;
                            gSelection = 0x64;
                            B_801A6D98_usa = 3;
                            break;
                        case 0x7:
                            gMain = 0x34C;
                            B_801A6D78_usa = 1;
                            *B_801A6D7C_usa = 1;
                            gSelection = 0x64;
                            B_801A6D98_usa = 4;
                            break;
                        case 0x2:
                        case 0x4:
                            var_a0 = 2;
                            gMain = 0x384;
                            B_801A6D78_usa = 1;
                            if (B_8018A7F8_usa == 2) {
                                var_a0 = 1;
                            }
                            *B_801A6D7C_usa = var_a0;
                            gSelection = 0x8C;
                            B_801A6D98_usa = 1;
                            B_801A6DA4_usa = 0;
                            B_801A6DA0_usa = 1;
                            temp_v0_2 = osGetCount();
                            B_801A6D9C_usa = (temp_v0_2 & 0xFF) % 6;
                            func_80089BE0_usa(0, 6);
                            break;
                        case 0x6:
                        case 0x8:
                            gMain = 0x384;
                            B_801A6D78_usa = 2;
                            var_a0_2 = 2;
                            if (B_8018A7F8_usa == 6) {
                                var_a0_2 = 1;
                            }
                            *B_801A6D7C_usa = var_a0_2;
                            gSelection = 0xA0;
                            B_801A6D98_usa = 0;
                            B_801A6DA4_usa = 0;
                            var_v1_2 = 3;
                            if (B_8018A7F8_usa == 6) {
                                var_v1_2 = 5;
                            }
                            B_801A6DA0_usa = var_v1_2;
                            temp_s0_2 = osGetCount();
                            B_801A6D9C_usa = (((temp_s0_2 & 0xF) % 15) * 0x64) + (((osGetCount() >> 4) & 3) | 1);
                            var_a1 = 5;
                            if (B_8018A7F8_usa == 6) {
                                var_a1 = 8;
                            }
                            func_80089BE0_usa(0, var_a1);
                            B_801A6DA8_usa = 0;
                            B_801A6DB4_usa = 0;
                            var_v1_3 = 3;
                            if (B_8018A7F8_usa == 6) {
                                var_v1_3 = 5;
                            }
                            B_801A6DB0_usa = var_v1_3;
                            temp_s0_3 = osGetCount();
                            B_801A6DAC_usa = (((temp_s0_3 & 0xF) % 15) * 0x64) + (((osGetCount() >> 4) & 3) | 1);
                            var_a1_2 = 5;
                            if (B_8018A7F8_usa == 6) {
                                var_a1_2 = 8;
                            }
                            func_80089BE0_usa(1, var_a1_2);
                            break;
                        case 0x9:
                            gDemo = 0x2C;
                            *B_801A6D7C_usa = 2;
                            gReset = 0;
                            gGameStatus &= ~0x80;
                            gpData->unk_00 = 0;
                            gpData->unk_10 = 0;
                            gpData->unk_14 = 7;
                            temp_v0_3 = func_800273BC_usa(&RO_STR_800C314C_usa, 0x8E401);
                            gpData->unk_08 = temp_v0_3;
                            func_80009D30_usa(temp_v0_3, gpData->unk_10);
                            break;
                    }
                }
            }
            if ((B_8018A7F0_usa == 0) && (func_8002DA70_usa() == 0) && (gReset == 0) && (func_80024C2C_usa() == 0) && (func_80024C14_usa() == 0)) {
                var_v1_4 = 0;

                while (var_v1_4 <= 0) {
                    if (*(&B_801A5B30_usa + var_v1_4) != -1) {
                        if (*(&B_801A5B34_usa + var_v1_4) != 0) {
                            var_v0_3 = -1;
                            break;
                        }
                    }
                    var_v1_4 += 0x10;
                    var_v0_3 = 0;
                }

                if ((var_v0_3 != 0) && (func_80024BF4_usa(&sp1C) != 0)) {
                    func_80005184_usa(&D_800B4160_usa, 2);
                    if ((func_80024BF4_usa(&sp1C) != 0) && (HVQM2Util_Play(&RO_STR_800C3154_usa, 0x1000, sp1C) != 0)) {
                        func_80005184_usa(&D_800B4160_usa, 2);
                    }
                    gMain = 0x258;
                    gReset = -1;
                    gDemo = 0x2C;
                    gGameStatus &= ~0x80;
                }
            }
            gpData->unk_04 = var_s3;
            break;
    }

    if (func_80024C2C_usa() == 0) {
        func_8002CC18_usa();
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/title", DoTitle);
#endif
#endif

#if VERSION_USA
typedef struct struct_gpData {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x04 */ UNK_TYPE4 unk_04;
    /* 0x08 */ UNK_TYPE4 unk_08;
    /* 0x0C */ UNK_TYPE4 unk_0C;
    /* 0x10 */ UNK_TYPE4 unk_10;
    /* 0x14 */ UNK_TYPE4 unk_14;
} struct_gpData; // size = 0x18

extern struct_gpData *gpData;
extern s32 B_801AB89C_usa;
extern s32 B_801C6FA0_usa;
extern u8 D_800B69B0_usa;
extern u32 D_CA4A0[];
extern u32 D_FB480[];
extern const char RO_STR_800C3128_usa[];
extern const char RO_STR_800C3144_usa[];

#if 0
// ? func_80002D8C_usa(?);                             /* extern */
// s32 func_800273BC_usa(s8 *, s32, s32);              /* extern */
// ? func_80027D0C_usa(s32, ?);                        /* extern */
// ? func_80028F44_usa(s32, ?, ? *);                   /* extern */
// ? func_800296B0_usa(? *, s8 *, ?);                  /* extern */
// s32 func_8002A708_usa(s32 *, s8 *);                 /* extern */
// s32 screenLoad(? *, s32 *);                  /* extern */

void InitTitle(void) {
    s16 sp10[0x80];
    s32 sp110;
    s32 sp114;
    s32 *var_v1;
    s32 temp_a0;
    s32 temp_v0;
    s32 var_a0;
    s32 var_a1;
    char *var_a0_2;

    var_a0 = 0xF;
    var_v1 = &B_801AB89C_usa;
    gTheGame.unk_9C0C = 2;
    B_801C6FA0_usa = 0;
    do {
        *var_v1 = 0;
        var_a0 -= 1;
        var_v1 -= 1;
    } while (var_a0 >= 0);
    temp_a0 = (((uintptr_t)gBufferHeap + 0xF) + SEGMENT_ROM_SIZE(segment_0CA4A0)) & ~0xF;
    B_8021BEA4_usa = &gTheGame.unk_9C48;
    B_8021BEA8_usa = &gTheGame.unk_9C48;
    sp110 = temp_a0;
    gpData = temp_a0;
    sp110 = (void*)((uintptr_t)temp_a0 + 0x18);
    bzero((void *) temp_a0, 0x18);
    gpData->unk_14 = 0;
    gpData->unk_04 = 2;

    if (screenLoad("TITLE.SBF", &sp110) != 0) {
        if (B_8018A7F0_usa > 0) {
            if (osTvType == 0) {
                var_a0_2 = "BLANK";
                gpData->unk_14 = 1;
            } else if (D_800B69B0_usa & 1) {
                var_a0_2 = RO_STR_800C3128_usa;
                gpData->unk_00 = 0;
                gpData->unk_14 = 4;
            } else {
                var_a0_2 = "NO-CONTROLLER";
                gpData->unk_14 = 2;
            }
            gpData->unk_08 = func_800273BC_usa(var_a0_2, 0xFF401);
        } else {
            var_a1 = -1;
            if ((gDemo == 0x16) || (gDemo == 0x21) || (B_8018A7F8_usa == 9)) {
                var_a1 = 0xE;
            }
            gpData->unk_14 = 6;
            gpData->unk_08 = func_800273BC_usa(RO_STR_800C3144_usa, ((var_a1 << 0xC) & 0x7F000) | 0x80401);
            gDemo = 0x2C;
        }

        if (func_8002A708_usa(&sp114, "COPYRIGHT") != 0) {
            func_800296B0_usa(&sp10, gBuildDate, 0x80);
            func_80028F44_usa(sp114, 0x64, &sp10);
        }
        if (func_8002A708_usa(&sp114, RO_STR_800C3144_usa) != 0) {
            func_800296B0_usa(&sp10, gBuildDate, 0x80);
            func_80028F44_usa(sp114, 0x64, &sp10);
        }
        if (func_8002A708_usa(&sp114, RO_STR_800C3144_usa) != 0) {
            func_80027D0C_usa(sp114, 0x64);
        }
    }

    func_80002E0C_usa(0x1E);
    func_80002D8C_usa(0x1E);
    if (gpData->unk_14 == 6) {
        PlayMIDI(BGM_INIT_TABLE, 0x3C, 0, 1);
    }
    func_80002E70_usa(D_FLT_800B3B10_usa * 0x7FFF);
    func_80002E34_usa(D_FLT_800B3B14_usa * 0x7FFF);
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/title", InitTitle);
#endif
#endif

#if VERSION_USA
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
    B_8021BEA4_usa = NULL;
    B_8021BEA8_usa = NULL;

    for (i = 0; i < ARRAY_COUNT(gTheGame.unk_9C48); i++) {
        menuInitUser(i);
    }

    func_80046F8C_usa();
}
#endif
