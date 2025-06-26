#include "043D10.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "screen.h"
#include "the_game.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/043D10", func_80043110_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/043D10", func_80043380_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/043D10", func_8004360C_usa);
#endif

#if VERSION_USA
void func_80043A60_usa(Gfx **arg0, s32 arg1, s32 arg2);
INCLUDE_ASM("asm/usa/nonmatchings/main/043D10", func_80043A60_usa);
#endif

#if VERSION_USA
void func_80043CFC_usa(Gfx **gfxP) {
    screenDraw(gfxP, func_80043A60_usa);
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/043D10", func_80043D24_usa);
#endif

typedef struct struct_80192FA0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ UNK_PAD unk_10[0x4];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ UNK_PAD unk_20[0x4];
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ UNK_PAD unk_30[0x4];
    /* 0x34 */ s32 unk_34;
    /* 0x38 */ s32 unk_38;
    /* 0x3C */ UNK_PAD unk_3C[0x18];
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ UNK_PAD unk_58[0x4];
    /* 0x5C */ s32 unk_5C;
    /* 0x60 */ UNK_PAD unk_60[0x4];
    /* 0x64 */ s32 unk_64[3];
    /* 0x70 */ s32 unk_70[3];
    /* 0x7C */ s32 unk_7C[3];
    /* 0x88 */ s32 unk_88[3];
    /* 0x94 */ UNK_PAD unk_94[0xB0 - 0x94];
    /* 0xB0 */ s32 unk_B0;
} struct_80192FA0; // size = 0xB4

extern struct_80192FA0 *B_80192FA0_usa;
extern const char RO_800C581C_usa[];
extern const char RO_STR_800C5828_usa[];

#if VERSION_USA
#if 0
void func_8004407C_usa(void **heapP, s32 arg1) {
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 temp_v0;
    s32 var_a0;
    s32 var_s2;

    temp_v0 = (s32) (*heapP + 3) & ~3;
    *heapP = (void *) temp_v0;
    B_80192FA0_usa = (struct_80192FA0 *) temp_v0;
    *heapP += 0xB4;
    if (screenLoad(RO_STR_800C5828_usa, heapP) != 0) {
        B_80192FA0_usa->unk_00 = screenSet(RO_800C581C_usa, 0xFF001);
    }

    var_a0 = 0;
    while (var_a0 < 3) {
        B_80192FA0_usa->unk_7C[var_a0] = 0;
        B_80192FA0_usa->unk_88[var_a0] = 0;
        B_80192FA0_usa->unk_64[var_a0] = 0;
        B_80192FA0_usa->unk_70[var_a0] = 0;
        var_a0 += 1;
    }

    B_80192FA0_usa->unk_28 = 1;
    B_80192FA0_usa->unk_38 = 2;
    B_80192FA0_usa->unk_2C = -0x96;
    B_80192FA0_usa->unk_1C = -0x96;
    B_80192FA0_usa->unk_0C = -0x96;
    B_80192FA0_usa->unk_5C = 0;
    B_80192FA0_usa->unk_54 = 0;
    B_80192FA0_usa->unk_18 = 0;
    B_80192FA0_usa->unk_34 = 0;
    B_80192FA0_usa->unk_24 = 0;
    B_80192FA0_usa->unk_14 = 0;
    B_80192FA0_usa->unk_04 = 0x14;
    B_80192FA0_usa->unk_B0 = 0;
    B_80192FA0_usa->unk_08 = 0;
    if (screenFind(&sp10, RO_800C581C_usa) != nfalse) {
        var_s2 = 0;
        func_8002A2E8_usa(sp10, 0x64, &sp14, &sp18);
        func_8002A1F4_usa(sp10, 0x64, sp14, 0);
        func_8002A2E8_usa(sp10, 0x65, &sp14, &sp18);
        func_8002A1F4_usa(sp10, 0x65, sp14, 0);
        do {
            screenHideImage(sp10, var_s2 + 0xC8);
            var_s2 += 1;
        } while (var_s2 < 0x10);
        screenHideImage(sp10, 0x258);
        screenHideImage(sp10, 0x259);
        screenShowImage(sp10, 0xC8);
        func_80028DC0_usa(sp10, 0xC8, 0);
        screenShowImage(sp10, gTheGame.unk_9C2C[0][0] + 0xC8);
        func_80028DC0_usa(sp10, gTheGame.unk_9C2C[0][0] + 0xC8, 1);
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/043D10", func_8004407C_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/043D10", func_80043340_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/043D10", func_800435B0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/043D10", func_8004383C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/043D10", func_80043C90_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/043D10", func_80043CFC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/043D10", func_80043D24_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/043D10", func_8004407C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/043D10", func_800432B0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/043D10", func_800435E4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/043D10", func_80043870_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/043D10", func_80043CC4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/043D10", func_80043CFC_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/043D10", func_80043D24_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/043D10", func_8004407C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/043D10", func_80043420_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/043D10", func_80043754_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/043D10", func_800439E0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/043D10", func_80043E34_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/043D10", func_80043CFC_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/043D10", func_80043D24_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/043D10", func_8004407C_usa);
#endif
