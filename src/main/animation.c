/**
 * Original filename: animation.c
 */

#include "animation.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "sfxlimit.h"
#include "the_game.h"
#include "update.h"

#include "074280.h"
#include "075630.h"

s32 AnimationRandom(s32 max) {
    s32 temp_v0 = gTheGame.unk_9C10;
    s32 new_var2 = 0x87C125;

    gTheGame.unk_9C10 = (temp_v0 + new_var2) + (temp_v0 * 0x7B6E72);
    temp_v0 = ((gTheGame.unk_9C10 & 0x7FFFFFFF) / ((f32)0x7FFFFFFF)) * max;
    return temp_v0;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_8004EE24_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_8004EEFC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/animation", RO_800C6020_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/animation", RO_800C60A0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_8004F010_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_8004F4BC_usa);
#endif

#if VERSION_USA
#if 0
void func_8004F5E4_usa(tetWell *well, s32 arg1, s32 arg2, s32 arg3) {
    text_t *var_a0;
    text_t *var_a0_2;
    s32 temp_a3;
    s32 var_a2;

    if (gTheGame.unk_9C08 == 1) {
        if ((gSelection == 0xAA) && (gTheGame.menu[0].unk_0 == 5)) {
            func_80074A58_usa(well, arg2, arg3);
        }
    } else if (arg1 == 1) {
        temp_a3 = (gSelection != 0x96) ? 6 : 2;

        var_a0 = &gTheGame.drawText;
        var_a0_2 = &gTheGame.drawText;
        for (var_a2 = 0; var_a2 < temp_a3; var_a2++, var_a0++, var_a0_2++) {
            if (var_a0_2->texture < 0xC8) {
                continue;
            }

            switch (var_a0_2->texture) {
                case 0xCD:
                    var_a0->word.s.imageAdrs = 2;
                    break;

                case 0xD2:
                    var_a0->word.s.imageAdrs = 4;
                    break;

                case 0xD7:
                    var_a0->word.s.imageAdrs = 6;
                    break;

                case 0xE6:
                    var_a0_2->texture = 0xC8;
                    var_a0->word.s.imageAdrs = 0;
                    break;
            }

            var_a0_2->texture += 1;
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_8004F5E4_usa);
#endif
#endif

#if VERSION_USA
#if 0
void UpdateAnimation(tetWell *well, s32 num, s32 combo) {
    s32 *temp_s0;
    text_t *var_a0;
    s32 *var_a1_2;
    s32 temp_a0;
    s32 temp_a3;
    s32 temp_s0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 var_a2;
    s32 var_s2;

    var_s2 = 0;
    if (combo != 0) {
        UpdateComboChainCount(num, -1);
    }

    temp_a0 = well->unk_43A8;
    temp_v1 = chain_check[num];
    if (temp_a0 != temp_v1) {
        if (temp_a0 == 0) {
            if (temp_v1 == -1) {
                var_s2 = 0x3E7;
            } else if (temp_v1 < -1) {
                var_s2 = 0x270F;
            }
            temp_s0 = &chain_check[num];
            UpdateComboChainCount(num, 0, -*temp_s0);
            temp_s0_2 = *temp_s0;

            if (temp_s0_2 == -3) {
                PlaySE(SFX_INIT_TABLE, 0x12C);
            } else if (temp_s0_2 == -4) {
                PlaySE(SFX_INIT_TABLE, 0x12D);
            } else if (temp_s0_2 < -4) {
                PlaySE(SFX_INIT_TABLE, 0x12E);
            }
        }

        temp_v1_2 = well->unk_43A8;
        chain_check[num] = temp_v1_2;
        if (temp_v1_2 < 0) {
            var_s2 = temp_v1_2;
        }
    }

    if (gSelection < 0x6F) {
        return;
    }

    if (gTheGame.unk_9C0C == 1) {
        if (gTheGame.unk_9C08 != 1) {
            if (num == 1) {
                temp_a3 = (gSelection != 0x96) ?  6 : 2;

                var_a0 = &gTheGame.drawText;
                for (var_a2 = 0; var_a2 < temp_a3; var_a2++) {
                    switch ((s32)var_a0->texture) {    /* switch 1; irregular */
                        case 0xCD:          /* switch 1 */
                            var_a0->word.s.imageAdrs = 2;
                            break;
                        case 0xD7:          /* switch 1 */
                            var_a0->word.s.imageAdrs = 6;
                            break;
                        case 0xE6:          /* switch 1 */
                            var_a0->texture = 0xC8;
                            var_a0->word.s.imageAdrs = 0;
                            break;
                        case 0xD2:          /* switch 1 */
                            var_a0->word.s.imageAdrs = 4;
                            break;
                    }

                    var_a0->texture += 1;

                    var_a0 += 0x20;
                }
            }
        } else {
            if ((gSelection == 0xAA) && (gTheGame.menu[0].unk_0 == 5)) {
                func_80074A58_usa(well, combo, var_s2);
            }
        }
    } else if (gTheGame.unk_9C08 == 1) {

        if ((gSelection == 0xAA) && (gTheGame.menu[0].unk_0 == 5)) {
            func_80074A58_usa(well, combo, var_s2);
        }
    } else if (num == 1) {
        temp_a3 = (gSelection != 0x96) ? 6 : 2;

        var_a0 = &gTheGame.drawText;
        for (var_a2 = 0; var_a2 < temp_a3; var_a2++) {
            temp_v1_4 = var_a0->texture;

            switch (temp_v1_4) {
                case 0xCD:
                    var_a0->word.s.imageAdrs = 2;
                    break;

                case 0xD7:
                    var_a0->word.s.imageAdrs = 6;
                    break;

                case 0xE6:
                    var_a0->texture = 0xC8;
                    var_a0->word.s.imageAdrs = 0;
                    break;

                case 0xD2:
                    var_a0->word.s.imageAdrs = 4;
                    break;
            }
            var_a0->texture += 1;

            var_a0 += 0x20;
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", UpdateAnimation);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_8004FA2C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_8004FABC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_8004F0C4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_8004F19C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/animation", RO_800C62D0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/animation", RO_800C6350_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_8004F2B0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_8004F75C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_8004F884_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", UpdateAnimation);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_8004FA2C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_8004FABC_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_8004D834_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_8004D90C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", jtbl_800C46D0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_STR_800C473C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_STR_800C4748_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_800C4758_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_800C4760_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_800C4768_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_800C476C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_800C4774_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_STR_800C4778_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_800C4780_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_800C4788_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", jtbl_800C4790_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", jtbl_800C48D8_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", jtbl_800C4900_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", jtbl_800C4918_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_800C4930_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/animation", RO_800C49B0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_8004DA20_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_8004DECC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_8004DFF4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", UpdateAnimation);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_8004FA2C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_8004FABC_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_8004D9B4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_8004DA8C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/animation", RO_800BB8F0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/animation", RO_800BB970_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_8004DBA0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_8004E04C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_8004E174_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", UpdateAnimation);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_8004FA2C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_8004FABC_usa);
#endif

void func_80050420_usa(void) {
    gTheGame.frame[0].b.imagePtr = B_8019CF9C_usa;
    gTheGame.frame[0].b.imageH = 240 << 2;
    gTheGame.frame[0].b.frameH = 240 << 2;
    gTheGame.frame[0].b.frameY = 0;
    gTheGame.frame[0].b.imageFmt = G_IM_FMT_RGBA;
    gTheGame.frame[0].b.imageSiz = G_IM_SIZ_16b;

    guS2DInitBg(&gTheGame.frame[0]);
    osWritebackDCache(&gTheGame.frame[0], sizeof(uObjBg));

    if (gTheGame.unk_9C08 == 1) {
        func_800512E0_usa();
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_800504B8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_8005076C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_80050BA8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_80050C2C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_800512E0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_80051998_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_800521A4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_80052258_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/animation", func_80052400_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_80050758_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_8005076C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_80050E48_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_80050C2C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_800512E0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_80051C38_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_800521A4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_800524F8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/animation", func_800526A0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_8004EEC8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_8005076C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_8004F5B8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_80050C2C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_800512E0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_800503A8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_800521A4_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_80050C68_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/animation", func_80050E10_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_8004F048_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_8005076C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_8004F738_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_80050C2C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_800512E0_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_80050528_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_800521A4_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_80050DE8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/animation", func_80050F90_ger);
#endif
