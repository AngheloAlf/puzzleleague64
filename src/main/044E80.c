#include "044E80.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "hvqm2util.h"
#include "image.h"
#include "screen.h"
#include "sfxlimit.h"
#include "sound.h"
#include "story.h"
#include "the_game.h"

typedef struct struct_80192FB0_unk_0028 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
} struct_80192FB0_unk_0028; // size = 0x28

#define STRUCT_80192FB0_UNK_0028_COUNT 0x80

typedef struct struct_80192FB0 {
    /* 0x0000 */ s32 unk_0000;
    /* 0x0004 */ u32 unk_0004;
    /* 0x0008 */ struct_imageLoad_arg0 *unk_0008;
    /* 0x000C */ s32 unk_000C;
    /* 0x0010 */ s32 unk_0010;
    /* 0x0014 */ s32 unk_0014;
    /* 0x0018 */ s32 unk_0018;
    /* 0x001C */ s32 unk_001C;
    /* 0x0020 */ s32 unk_0020;
    /* 0x0024 */ s32 unk_0024;
    /* 0x0028 */ struct_80192FB0_unk_0028 unk_0028[STRUCT_80192FB0_UNK_0028_COUNT];
    /* 0x1428 */ UNK_PAD unk_1428[0x4];
} struct_80192FB0; // size = 0x142C

extern RomOffset D_800B6950_usa[];
extern struct_80192FB0 *B_80192FB0_usa;
extern s32 D_800B6990_usa[];

#if VERSION_USA
#ifdef NON_MATCHING
void func_80044280_usa(s32 arg0, struct_80192FB0_unk_0028 *arg1) {
    s32 var_s2;
    struct_80192FB0_unk_0028 *var_s0;

    if (!(arg0 & 7)) {
        if (osGetCount() & 1) {
            if (osGetCount() & 4) {
                if (arg1->unk_00 < 8) {
                    arg1->unk_00++;
                }
            } else {
                if (arg1->unk_00 >= -7) {
                    arg1->unk_00--;
                }
            }
        }
    }

    for (var_s2 = 0; var_s2 < STRUCT_80192FB0_UNK_0028_COUNT; var_s2++) {
        var_s0 = &arg1[var_s2];

        if (var_s0->unk_14 != 0) {
            var_s0->unk_14--;
        } else {
            var_s0->unk_0C += var_s0->unk_10;
            var_s0->unk_08 += var_s0->unk_10;
            if (var_s0->unk_08 >= 0x3C1) {
                var_s0->unk_04 = var_s0->unk_18;
                var_s0->unk_08 = var_s0->unk_1C;
                var_s0->unk_10 = var_s0->unk_20;
                var_s0->unk_14 = var_s0->unk_24;
            }
            if (!(arg0 & 3)) {
                var_s0->unk_04 += var_s0->unk_00;
            }
            if (!(arg0 & 7) && (osGetCount() & 1)) {
                if (osGetCount() & 2) {
                    if (var_s0->unk_10 < 8) {
                        var_s0->unk_10++;
                    }
                } else {
                    if (var_s0->unk_10 >= 2) {
                        var_s0->unk_10--;
                    }
                }
            }
        }
    }
}
#else
void func_80044280_usa(s32, struct_80192FB0_unk_0028 *);
INCLUDE_ASM("asm/usa/nonmatchings/main/044E80", func_80044280_usa);
#endif
#endif

#if VERSION_USA
void func_8004441C_usa(struct_80192FB0_unk_0028 *arg0) {
    u8 sp10[0x10];
    s32 var_s0;
    s32 var_s2;
    s32 var_s3;
    u32 temp_v0;

    arg0->unk_00 = 0;

    for (var_s3 = 0; var_s3 < ARRAY_COUNT(sp10); var_s3++) {
        sp10[var_s3] = 0;
    }

    for (var_s3 = 0; var_s3 < STRUCT_80192FB0_UNK_0028_COUNT; var_s3++) {
        for (var_s2 = 0; var_s2 < 0x40; var_s2++) {
            temp_v0 = osGetCount();
            var_s0 = temp_v0 & 0x7F;
            if (!((sp10[var_s0 >> 3] >> (temp_v0 & 7)) & 1)) {
                break;
            }
        }

        if (var_s2 == 0x40) {
            var_s0 = 0;

            while (var_s0 < 0x80) {
                if (!(((s32) * (sp10 + (var_s0 >> 3)) >> (var_s0 & 7)) & 1)) {
                    break;
                }
                var_s0 += 1;
            }
        }

        var_s2 = var_s0 & 7;
        sp10[var_s0 >> 3] |= 1 << var_s2;

        arg0[var_s3].unk_18 = (var_s0 * 2.5f) * DOUBLE_LITERAL(4.0);
        arg0[var_s3].unk_1C = -0x10 - (osGetCount() & 0xF);
        arg0[var_s3].unk_24 = osGetCount() & 0x7F;

        arg0[var_s3].unk_20 = var_s0 & 3;
        if (arg0[var_s3].unk_20 == 0) {
            arg0[var_s3].unk_20 = 1;
        }
        arg0[var_s3].unk_0C = 0;
        arg0[var_s3 + 1].unk_00 = D_800B6990_usa[var_s2];
        arg0[var_s3].unk_04 = arg0[var_s3].unk_18;
        arg0[var_s3].unk_08 = arg0[var_s3].unk_1C;
        arg0[var_s3].unk_10 = arg0[var_s3].unk_20;
        arg0[var_s3].unk_14 = arg0[var_s3].unk_24;
    }
}
#endif

#if VERSION_USA
void func_800445D8_usa(Gfx **gfxP, s32 arg1, s32 arg2);
INCLUDE_ASM("asm/usa/nonmatchings/main/044E80", func_800445D8_usa);
#endif

#if VERSION_USA
void func_800447C4_usa(Gfx **gfxP, s32 arg1, s32 arg2);
INCLUDE_ASM("asm/usa/nonmatchings/main/044E80", func_800447C4_usa);
#endif

#if VERSION_USA
void func_800449C4_usa(Gfx **gfxP) {
    if (B_80192FB0_usa->unk_0004 == 0xB) {
        screenDraw(gfxP, func_800447C4_usa);
    } else if (B_80192FB0_usa->unk_0004 < 7) {
        screenDraw(gfxP, func_800445D8_usa);
    } else {
        screenDraw(gfxP, NULL);
    }
}
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/044E80", RO_800C5848_usa);
#endif

#if VERSION_USA
void func_80044A1C_usa(void);
INCLUDE_ASM("asm/usa/nonmatchings/main/044E80", func_80044A1C_usa);
#endif

#if VERSION_USA
s32 func_80046470_usa(void);
INCLUDE_ASM("asm/usa/nonmatchings/main/044E80", func_80046470_usa);
#endif

#if VERSION_USA
void func_80046648_usa(s32 arg0) {
    void *sp10;
    struct_imageLoad_arg0 *sp14;
    s32 var_s2 = 0;

    switch (B_80192FB0_usa->unk_0004) {
        case 0x0:
            var_s2 = func_80046470_usa();
            break;

        case 0x1:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE1", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x4:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE4", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x5:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE5", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x2:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE2", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x3:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE3", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x6:
            switch (B_80192FB0_usa->unk_0020) {
                case 0:
                    if (func_80046470_usa() != 0) {
                        B_80192FB0_usa->unk_0024 = arg0;
                        B_80192FB0_usa->unk_0020 = 1;
                    }
                    break;

                case 0x1:
                    if (arg0 - B_80192FB0_usa->unk_0024 > 0xF0) {
                        B_80192FB0_usa->unk_0020 = 2;
                        B_80192FB0_usa->unk_0000 = screenSet("CHEATCODE6", 0x401);
                    }
                    break;

                case 0x2:
                    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
                        var_s2 = -1;
                    }
                    break;
            }
            break;

        case 0x7:
            if (!screenFlushing() && !func_80024C14_usa()) {
                if (func_80024BF4_usa(&sp10)) {
                    if (gTheGame.unk_9C28 == 3) {
                        HVQM2Util_Play((void *)"GAMEEND.HVQM", 0x1000U, sp10);
                        func_8002B85C_usa(5, 2);
                    } else {
                        HVQM2Util_Play((void *)"MEWINTRO.HVQM", 0x1000U, sp10);
                        gMain = GMAIN_384;
                        gReset = -1;
                        gTheGame.unk_9C0C = 1;
                        gSelection = 0x96;
                        gTheGame.unk_9C08 = 2;
                        gTheGame.unk_9C2C[0][2] = 1;
                    }
                }
            }
            break;

        case 0x8:
            if (!screenFlushing() && !func_80024C14_usa()) {
                if (func_80024BF4_usa(&sp10)) {
                    HVQM2Util_Play((void *)"YOUWIN.HVQM", 0x1000U, sp10);
                    func_8002B85C_usa(2, 8);
                }
            }
            break;

        case 0x9:
            if (!screenFlushing() && !func_80024C14_usa()) {
                if (func_80024BF4_usa(&sp10)) {
                    HVQM2Util_Play((void *)"YOULOSE.HVQM", 0x1000U, sp10);
                    gTheGame.unk_9C0C = 1;
                    gTheGame.unk_9C2C[0][0] = 0x12;
                    gMain = GMAIN_BONUS;
                    gReset = -1;
                }
            }
            break;

        case 0xA:
            if (arg0 == 0xA) {
                PlaySE(SFX_INIT_TABLE, 0x83);
            }

            if (arg0 >= 0xF1) {
                if (gTheGame.controller[0].touch_button & START_BUTTON) {
                    var_s2 = -1;
                }
            }
            break;

        case 0xB:
            if (arg0 == 0xA) {
                PlaySE(SFX_INIT_TABLE, 0x80);
            }

            if (arg0 >= 0xF1) {
                if (gTheGame.controller[0].touch_button & START_BUTTON) {
                    var_s2 = -1;
                }
            }

            if ((arg0 >= 0x79) && (func_8002864C_usa(B_80192FB0_usa->unk_0000, 0x6E, &sp14))) {
                if (sp14->unk_14 < 0xFF) {
                    sp14->unk_14 += 8;
                    if (sp14->unk_14 >= 0x100) {
                        sp14->unk_14 = 0xFF;
                    }
                }

                if (sp14->unk_14 > 0) {
                    func_80044280_usa(arg0, B_80192FB0_usa->unk_0028);
                }
            }
            break;
    }

    if (var_s2 != 0) {
        FadeOutAllSFXs(0x1E);
        func_80002D8C_usa(0x1E);
        gReset = -1;
        gMain = GMAIN_TITLE;
        gTheGame.unk_9C0C = 1;
    }
}
#endif

#if VERSION_USA
#if 0
void func_80046C2C_usa(void **heapP, u32 arg1) {
    s32 temp_v0;
    u32 var_v0;

    temp_v0 = (s32) (*heapP + 3) & ~3;
    *heapP = (void *) temp_v0;
    B_80192FB0_usa = (struct_80192FB0 *) temp_v0;
    *heapP += 0x142C;

    if ((u32) arg1 < 7U) {
        B_80192FB0_usa->unk_0014 = 0;
        B_80192FB0_usa->unk_001C = 0;
        B_80192FB0_usa->unk_0018 = 0;
        B_80192FB0_usa->unk_0010 = 0;
        func_8001FD0C_usa(&B_80192FB0_usa->unk_0008, D_800B6950_usa[B_80192FB0_usa->unk_0014], 0, 0x54, 0x70, 0xC0, heapP);
#if 0
        ((B_80192FB0_usa->unk_0010 * 4) + B_80192FB0_usa)->unk_8->unk_14 = 0;
#endif
        ((s32**)B_80192FB0_usa)[B_80192FB0_usa->unk_0010+2][5] = 0;

        B_80192FB0_usa->unk_000C = 0;
    }

    if (arg1 == 0xB) {
        func_8004441C_usa(B_80192FB0_usa->unk_0028);
    }

    if (screenLoad("CREDITS.SBF", heapP) != 0) {
        B_80192FB0_usa->unk_0004 = arg1;
        switch (arg1) {
            case 0x0:
            case 0x1:
            case 0x2:
            case 0x3:
            case 0x4:
            case 0x5:
            case 0x6:
                B_80192FB0_usa->unk_0000 = screenSet("CREDITS", 0x401);
                func_80044A1C_usa();
                B_80192FB0_usa->unk_0020 = 0;
                break;

            case 0x7:
            case 0x8:
            case 0x9:
                B_80192FB0_usa->unk_0000 = screenSet("EMPTY", 0x401);
                break;

            case 0xA:
                B_80192FB0_usa->unk_0000 = screenSet("ENDING-1", 0x401);
                break;

            case 0xB:
                B_80192FB0_usa->unk_0000 = screenSet("ENDING-2", 0x401);
                break;
        }
    }


    if ((arg1 != 0xA) && (arg1 != 0xB)) {
        func_80002D8C_usa(0x1E);
        FadeOutAllSFXs(0x1E);
        if (B_80192FB0_usa->unk_0020 == 0) {
            PlayMIDI(BGM_INIT_TABLE, 0x47, 0, 1);
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/044E80", func_80046C2C_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/044E80", func_800444B0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/044E80", func_8004464C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/044E80", func_80044808_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/044E80", func_800449F4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/044E80", func_800449C4_usa);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/044E80", RO_800C5B28_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/044E80", func_80044C4C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/044E80", func_800466A0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/044E80", func_80046648_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/044E80", func_80046C2C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/044E80", func_800444E0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/044E80", func_8004467C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/044E80", func_80044838_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/044E80", func_80044A24_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/044E80", func_800449C4_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/044E80", func_80044C7C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/044E80", RO_800C41D8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/044E80", func_80046648_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/044E80", func_80046C2C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/044E80", func_80044650_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/044E80", func_800447EC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/044E80", func_800449A8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/044E80", func_80044B94_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/044E80", func_800449C4_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/044E80", func_80044DEC_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/044E80", RO_800BB198_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/044E80", func_80046648_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/044E80", func_80046C2C_usa);
#endif
