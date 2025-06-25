#include "041780.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "screen.h"
#include "sfxlimit.h"
#include "the_game.h"

typedef struct struct_80192F80_usa {
    /* 0x00 */ UNK_PAD unk_00[0x8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ UNK_PAD unk_10[0x10];
    /* 0x20 */ struct struct_imageLoad_arg0 *unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ s32 unk_34;
} struct_80192F80_usa; // size >= 0x38

extern struct_80192F80_usa *B_80192F80_usa;
extern u16 D_800B6794_usa[];

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/041780", func_80040B80_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/041780", func_80040B80_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/041780", func_80040B80_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/041780", func_80040B80_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/041780", func_80040DE4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/041780", func_80040DE4_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/041780", func_80040DE4_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/041780", func_80040DE4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/041780", func_80040F04_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/041780", func_80040F04_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/041780", func_80040F04_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/041780", func_80040F04_usa);
#endif

// ShowWinner?
void func_800410A4_usa(void) {
    struct struct_imageLoad_arg0 *sp10;
    s32 var_s1;
    u32 var_s0;

    if (gTheGame.cursorBlock[1].unk_00 == 8) {
        var_s1 = 0;
    } else if (gTheGame.cursorBlock[0].unk_00 == 8) {
        var_s1 = 1;
    } else {
        var_s1 = 0;
#if VERSION_USA
        osSyncPrintf("ShowWinner: Internal error: No clear winner? (%d,%d)\n", gTheGame.cursorBlock[0].unk_00,
                     gTheGame.cursorBlock[1].unk_00);
#endif
    }

    B_80192F80_usa->unk_34 = var_s1;
    if (B_80192F80_usa->unk_08 != 0) {
        var_s0 = (var_s1 != 0) ? 15 : 0;
    } else {
        var_s0 = gTheGame.unk_9C2C[var_s1][0] / 100;
    }

    if (var_s0 >= 16) {
        var_s0 = 0;
#if VERSION_USA
        osSyncPrintf("ShowWinner: Internal error: Character out-of-range! (%d)\n", 0);
#endif
    }

    B_80192F80_usa->unk_30 = 0;
    B_80192F80_usa->unk_2C = var_s0;
    screenShowText(B_80192F80_usa->unk_0C, var_s0 + 0xC8);

    B_80192F80_usa->unk_24 = D_800B6794_usa[var_s0] & 0xFF;
    B_80192F80_usa->unk_28 = D_800B6794_usa[var_s0] >> 8;
    screenShowImage(B_80192F80_usa->unk_0C, (var_s1 != 1) ? 0xC9 : 0xC8);

    screenShowImage(B_80192F80_usa->unk_0C, 0x820781F4);
    screenShowText(B_80192F80_usa->unk_0C, 0x80EF80DC);

    if (func_8002864C_usa(B_80192F80_usa->unk_0C, B_80192F80_usa->unk_2C + 0x12C, &sp10)) {
        B_80192F80_usa->unk_20 = sp10;
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/041780", func_8004123C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/041780", func_8004123C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/041780", func_8004123C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/041780", func_8004123C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/041780", func_80041F1C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/041780", func_80041F1C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/041780", func_80041F1C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/041780", func_80041F1C_usa);
#endif
