#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "hvqm2util.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/006800", func_80005C00_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/006800", func_80005EC0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/006800", func_8000620C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/006800", func_8000628C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/006800", RO_STR_800C3128_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/006800", RO_STR_800C3134_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/006800", RO_STR_800C3144_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/006800", RO_STR_800C314C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/006800", RO_STR_800C3154_usa);
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


void func_80002CB4_usa(s32, UNK_TYPE);                        /* extern */
void func_80005130_usa(UNK_TYPE *, UNK_TYPE, UNK_TYPE, UNK_TYPE);                  /* extern */
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
extern struct_8018A7F4_usa *B_8018A7F4_usa;
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
extern s32 B_801AB8E0_usa;
extern s32 B_801AD9BC_usa;
extern s32 B_801ADAE8_usa;
extern s32 B_801C6FA0_usa;
extern s32 B_801F9CF8_usa;
extern s32 B_8021BA98_usa;
extern UNK_TYPE *B_8021BEA4_usa;
extern UNK_TYPE *B_8021BEA8_usa;
extern s32 D_800B3AD8_usa;
extern UNK_TYPE D_800B3FB0_usa;
extern UNK_TYPE D_800B4160_usa;
extern u8 D_800B69B0_usa;
extern const char RO_STR_800C3128_usa[];
extern const char RO_STR_800C3134_usa[];
extern const char RO_STR_800C3144_usa[];
extern const char RO_STR_800C314C_usa[];
extern const char RO_STR_800C3154_usa[];

void func_800062D0_usa(void) {
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

    temp_s0 = B_8018A7F4_usa->unk_08;
    B_8018A7F4_usa->unk_00++;
    sp10 = 0;
    sp14 = 0;
    func_8002629C_usa(&sp10);
    temp_v1 = B_8018A7F4_usa->unk_14;
    temp_s2 = B_8018A7F4_usa->unk_00;
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
                if ((var_v0 != 0) && (D_800BE344_usa == 0)) {
                    D_800BE344_usa = -1;
                }
            }
            if (temp_s2 == ((temp_s2 / 600) * 0x258)) {
                func_8001ACA8_usa(&sp18);
                temp_a1 = B_8018A7F4_usa->unk_10 + 1;
                B_8018A7F4_usa->unk_10 = temp_a1;
                if (sp18 < temp_a1) {
                    D_800BE344_usa = -1;
                    func_80002CB4_usa(D_800B3AD8_usa, 0x3C);
                } else {
                    func_80009D30_usa(temp_s0, temp_a1);
                }
            }
            if ((temp_s2 + 2) == (((temp_s2 + 2) / 600) * 0x258)) {
                func_8002CFE4_usa(0xE);
            }
            break;

        case 0x3:                                   /* switch 1 */
            func_80005C00_usa(B_8018A7F4_usa);
            if (B_8018A808_usa == 7) {
                B_8018A7F4_usa->unk_00 = 0;
                B_8018A7F4_usa->unk_14 = 4;
                B_8018A7F4_usa->unk_80 = func_800273BC_usa(&RO_STR_800C3128_usa, 0x8E001);
            }
            break;
        case 0x4:                                   /* switch 1 */
            if ((func_80024C2C_usa() == 0) && (func_80024C14_usa() == 0) && (func_80024BF4_usa(&sp1C) != 0)) {
                HVQM2Util_Play(&RO_STR_800C3134_usa, 0, sp1C);
                B_8018A7F4_usa->unk_14 = 5;
            }
            break;
        case 0x5:                                   /* switch 1 */
            temp_v0 = func_800273BC_usa(&RO_STR_800C3144_usa, 0x8E401);
            if (temp_v0 != temp_s0) {
                B_8018A7F4_usa->unk_08 = temp_v0;
                B_8018A7F4_usa->unk_00 = 0;
                B_8018A7F4_usa->unk_14 = 6;
                func_80005130_usa(&D_800B3FB0_usa, 0x3C, 0, 0);
            }
            break;
        default:                                    /* switch 1 */
            var_s3 = B_8018A7F4_usa->unk_04;
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
                            B_801AB8E0_usa ^= 1;
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
                B_8018A7F4_usa->unk_0C = 0;
                B_8018A7F4_usa->unk_00 = 0;
                var_v0_2 = var_s3 & 4;
            }
            if (var_v0_2 != 0) {
                temp_v1_3 = B_8018A7F4_usa->unk_0C + 1;
                B_8018A7F4_usa->unk_0C = temp_v1_3;
                if ((temp_v1_3 == 0x384) && (B_8018A7F8_usa != 8)) {
                    func_80002CB4_usa(D_800B3AD8_usa, 0x3C);
                }
                if (B_8018A7F4_usa->unk_0C >= 0x3C0) {
                    B_8019CEC0_usa = 0xB;
                    B_8021BEA4_usa = &B_801A6DB8_usa;
                    B_8021BEA8_usa = &B_801A6DB8_usa;
                    D_800BE344_usa = -1;
                    B_801A1574_usa = 0;
                    B_801A59A4_usa = 0;
                    B_801AD9BC_usa = -1;
                    B_801ADAE8_usa = -1;
                    B_801AB8E0_usa |= 0x80;
                    B_8018A7F8_usa++;
                    if (B_8018A7F8_usa == 0xA) {
                        B_8018A7F8_usa = 1;
                    }
                    switch (B_8018A7F8_usa) {
                        case 0x1:
                            D_800BE348_usa = 0x34C;
                            B_801A6D78_usa = 1;
                            *B_801A6D7C_usa = 1;
                            B_801F9CF8_usa = 0x64;
                            B_801A6D98_usa = 1;
                            break;
                        case 0x3:
                            D_800BE348_usa = 0x34C;
                            B_801A6D78_usa = 1;
                            *B_801A6D7C_usa = 1;
                            B_801F9CF8_usa = 0x64;
                            B_801A6D98_usa = 2;
                            break;
                        case 0x5:
                            D_800BE348_usa = 0x34C;
                            B_801A6D78_usa = 1;
                            *B_801A6D7C_usa = 1;
                            B_801F9CF8_usa = 0x64;
                            B_801A6D98_usa = 3;
                            break;
                        case 0x7:
                            D_800BE348_usa = 0x34C;
                            B_801A6D78_usa = 1;
                            *B_801A6D7C_usa = 1;
                            B_801F9CF8_usa = 0x64;
                            B_801A6D98_usa = 4;
                            break;
                        case 0x2:
                        case 0x4:
                            var_a0 = 2;
                            D_800BE348_usa = 0x384;
                            B_801A6D78_usa = 1;
                            if (B_8018A7F8_usa == 2) {
                                var_a0 = 1;
                            }
                            *B_801A6D7C_usa = var_a0;
                            B_801F9CF8_usa = 0x8C;
                            B_801A6D98_usa = 1;
                            B_801A6DA4_usa = 0;
                            B_801A6DA0_usa = 1;
                            temp_v0_2 = osGetCount();
                            B_801A6D9C_usa = (temp_v0_2 & 0xFF) % 6;
                            func_80089BE0_usa(0, 6);
                            break;
                        case 0x6:
                        case 0x8:
                            D_800BE348_usa = 0x384;
                            B_801A6D78_usa = 2;
                            var_a0_2 = 2;
                            if (B_8018A7F8_usa == 6) {
                                var_a0_2 = 1;
                            }
                            *B_801A6D7C_usa = var_a0_2;
                            B_801F9CF8_usa = 0xA0;
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
                            B_8019CEC0_usa = 0x2C;
                            *B_801A6D7C_usa = 2;
                            D_800BE344_usa = 0;
                            B_801AB8E0_usa &= ~0x80;
                            B_8018A7F4_usa->unk_00 = 0;
                            B_8018A7F4_usa->unk_10 = 0;
                            B_8018A7F4_usa->unk_14 = 7;
                            temp_v0_3 = func_800273BC_usa(&RO_STR_800C314C_usa, 0x8E401);
                            B_8018A7F4_usa->unk_08 = temp_v0_3;
                            func_80009D30_usa(temp_v0_3, B_8018A7F4_usa->unk_10);
                            break;
                    }
                }
            }
            if ((B_8018A7F0_usa == 0) && (func_8002DA70_usa() == 0) && (D_800BE344_usa == 0) && (func_80024C2C_usa() == 0) && (func_80024C14_usa() == 0)) {
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
                    D_800BE348_usa = 0x258;
                    D_800BE344_usa = -1;
                    B_8019CEC0_usa = 0x2C;
                    B_801AB8E0_usa &= ~0x80;
                }
            }
            B_8018A7F4_usa->unk_04 = var_s3;
            break;
    }

    if (func_80024C2C_usa() == 0) {
        func_8002CC18_usa();
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/006800", func_800062D0_usa);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/006800", func_80006EC4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/006800", func_80007204_usa);
#endif
