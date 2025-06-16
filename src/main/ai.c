/**
 * Original filename: ai.c
 */

#include "ai.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "animate.h"
#include "animation.h"
#include "pause.h"
#include "sfxlimit.h"
#include "sound.h"

void InitAI(tetWell *well, cursor_t *cursor, ai_t *brain) {
    s32 count;

    brain->unk_01C = 1;
    brain->unk_020 = 0;
    brain->unk_024 = -1;
    brain->unk_038 = 0;
    brain->unk_010 = brain->unk_00C;
    AIClearCommand(brain);
    AIFinishMove(brain);

    for (count = 0; count < AI_UNK_108_COUNT; count++) {
        brain->move[count] = 0;
    }

    brain->unk_000 = 2;
    brain->unk_004 = 5;
    AISetCursor(well, cursor, brain);
    AIChangeVision(brain);

    if (gSelection == 0x96) {
        if (AnimationRandom(0x13D) % 2 == 0) {
            AIAddCommand(brain, 1, 2, 0);
            AIAddCommand(brain, 0xA, 0, 0);
        } else if (AnimationRandom(0x42) % 2 == 0) {
            AIAddCommand(brain, 1, 3, 0);
            AIAddCommand(brain, 0xA, 0, 0);
        }
    }
}

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/ai", RO_800C7490_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/ai", RO_800C749C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/ai", RO_800C74AC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/ai", RO_800C74BC_usa);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/ai", RO_800C7740_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/ai", RO_800C774C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/ai", RO_800C775C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/ai", RO_800C776C_eur);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/ai", RO_800C5DA0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/ai", RO_800C5DAC_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/ai", RO_800C5DBC_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/ai", RO_800C5DCC_fra);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075108_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_800751B4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075278_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075354_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075458_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075524_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_800755B0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075438_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800754E4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800755A8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075684_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075794_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007586C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800758F8_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80073B68_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80073C14_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80073CD8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80073DB4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80073EC4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80073F9C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80074028_fra);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/ai", RO_800BCD60_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/ai", RO_800BCD6C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/ai", RO_800BCD7C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/ai", RO_800BCD8C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80073D18_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80073DC4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80073E88_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80073F64_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80074074_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007414C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800741D8_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AISetCursor);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AISetCursor);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AISetCursor);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AISetCursor);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIChangeVision);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIChangeVision);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIChangeVision);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIChangeVision);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075980_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075D10_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80074440_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800745F0_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIAddCommand);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIAddCommand);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIAddCommand);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIAddCommand);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075A1C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075DAC_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800744DC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007468C_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075A38_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075DC8_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800744F8_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800746A8_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIFinishMove);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIFinishMove);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIFinishMove);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIFinishMove);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AIClearCommand);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AIClearCommand);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AIClearCommand);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AIClearCommand);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075A78_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075BC0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075C60_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075D2C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80075E40_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80076F54_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80076F84_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80077110_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80077280_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80077338_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007737C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80077670_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_800776FC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80077920_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80077B00_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007855C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007895C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80078B78_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80078D78_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80079094_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007928C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_800794C8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007959C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80079D64_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80079DEC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007A5C8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007ACAC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007AFF4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007BF40_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007CE20_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007D484_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007E18C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007EC98_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007F5AC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_8007FEB4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80080504_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80080724_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80080AF0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_800812A4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_800814CC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075E08_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075F50_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80075FF0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800760BC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800761D0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800772E4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077314_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800774A0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077610_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800776C8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007770C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077A00_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077A8C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077CB0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80077E90_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_800788EC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80078CEC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80078F08_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80079108_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80079424_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007961C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80079858_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007992C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007A0F4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007A17C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007A958_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007B03C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007B384_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007C2D0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007D1B0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007D814_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007E51C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007F028_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8007F93C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80080244_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80080894_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80080AB4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80080E80_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80081634_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_8008185C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80074538_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80074680_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80074720_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800747EC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80074900_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075A14_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075A44_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075BD0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075D40_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075DF8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80075E3C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80076130_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800761BC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800763E0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800765C0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007701C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007741C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80077638_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80077838_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80077B54_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80077D4C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80077F88_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007805C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80078824_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_800788AC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80079088_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007976C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80079AB4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007AA00_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007B8E0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007BF44_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007CC4C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007D758_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007E06C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007E974_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007EFC4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007F1E4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007F5B0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007FD64_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_8007FF8C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800746E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80074830_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800748D0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007499C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80074AB0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075BC4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075BF4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075D80_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075EF0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075FA8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80075FEC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800762E0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007636C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80076590_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80076770_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800771CC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800775CC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800777E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800779E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80077D04_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80077EFC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80078138_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007820C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_800789D4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80078A5C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80079238_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007991C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80079C64_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007ABB0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007BA90_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007C0F4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007CDFC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007D908_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007E21C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007EB24_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007F174_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007F394_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007F760_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8007FF14_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_8008013C_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", UpdateAI);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", UpdateAI);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", UpdateAI);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", UpdateAI);
#endif

void AIMove(tetWell *well, cursor_t *cursor, ai_t *brain, s32 num) {
    if (gMain == GMAIN_387) {
        if ((gDemo == GDEMO_0B) && (gTheGame.controller[num].touch_button & START_BUTTON)) {
            gTheGame.cursorBlock[0].unk_20 = 0;
            gMain = GMAIN_388;
            gTheGame.unk_9C20 = num;
            gTheGame.unk_9C24 = 0;
            FadeSong(last_song_handle, 0x28, 0xA, NULL);
            FadeOutAllSFXs(0xF);
            PlaySE(SFX_INIT_TABLE, 0xA5);
            UpdateAnimation(well, num, 0);
            return;
        }
    } else if (gMain == GMAIN_388) {
        DoPauseGame(&gTheGame.controller[num], num, -1);
        if (gMain == GMAIN_388) {
            UpdateAnimation(well, num, 0);
        }
        return;
    }

    if (well->unk_43B0 != 0) {
        if (well->unk_43B0 < 0) {
            well->unk_43B0++;
        }

        if (well->unk_43B0 > 0) {
            RaiseBlocks(well, cursor);
            if (well->unk_43B0 == 0) {
                brain->unk_104 = 0;
                brain->unk_0FC = 0;
                brain->unk_100 = 0;
                brain->unk_124 = 0;
                brain->unk_128 = 0;
            }
            return;
        }
    }

    brain->unk_010--;
    if ((brain->unk_010 <= 0) && (brain->unk_124 != brain->unk_128)) {
        if (AnimationRandom(0x177) % 3 == 0) {
            brain->unk_010 = brain->unk_00C + AnimationRandom(2);
        } else {
            brain->unk_010 = brain->unk_00C - AnimationRandom(2);
        }

        if (well->unk_43F4 != 0) {
            brain->unk_010 = brain->unk_00C - AnimationRandom(3);
        } else if (brain->unk_020 != 0) {
            brain->unk_010 = brain->unk_010 - AnimationRandom(3);
        }

        if (gTheGame.unk_9C0C == 1) {
            AI2DMove(well, cursor, brain, num);
        } else {
            AI3DMove(well, cursor, brain, num);
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AI2DMove);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AI2DMove);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AI2DMove);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AI2DMove);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", AI3DMove);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", AI3DMove);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", AI3DMove);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", AI3DMove);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/ai", func_80082EE0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/ai", func_80083270_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/ai", func_80081990_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/ai", func_80081B50_ger);
#endif
