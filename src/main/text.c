/**
 * Original filename: text.c
 */

#include "text.h"

#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "assets_variables.h"

#define MAGIC_NUMBER 6

#if VERSION_USA
s32 InitWhichNumber(text_t *text, char number, s32 type) {
    u16 *addr;

    if (number == 0) {
        return 0;
    }

    addr = &text->word.s.imageAdrs;

    switch (type) {
        case 0x14:
            if (number < 0x37) {
                text->texture = 0;
            } else {
                text->texture = 2;
            }
            break;

        case 0x15:
            if (number >= 0x37) {
                text->texture = 2;
            } else {
                text->texture = 1;
            }
            break;

        case 0x16:
            if (number < 0x37) {
                text->texture = 3;
            } else {
                text->texture = 5;
            }
            break;

        default:
            return 0;

        case 0x17:
            if (number < 0x37) {
                text->texture = 4;
            } else {
                text->texture = 5;
            }
            break;
    }

    switch (number) {
        default:
            return 0;

        case ' ':
            text->texture = 0x46;
            break;

        case '\'':
            *addr = 0;
            break;

        case '-':
            *addr = 0;
            break;

        case '7':
            if ((type == 0x14) || (type == 0x16)) {
                *addr = 0;
            } else {
                *addr = 0x80;
            }
            break;

        case '3':
            *addr = 0x80;
            break;

        case '8':
            if ((type == 0x14) || (type == 0x16)) {
                FALLTHROUGH;
                case '0':
                    *addr = 2;
            } else {
                *addr = 0x82;
            }
            break;

        case '4':
            *addr = 0x82;
            break;

        case '9':
            if ((type == 0x14) || (type == 0x16)) {
                FALLTHROUGH;
                case '1':
                    *addr = 4;
            } else {
                *addr = 0x84;
            }
            break;

        case '5':
            *addr = 0x84;
            break;

        case ':':
            if ((type == 0x14) || (type == 0x16)) {
                FALLTHROUGH;
                case '2':
                    *addr = 6;
            } else {
                *addr = 0x86;
            }
            break;

        case '6':
            *addr = 0x86;
            break;
    }

    return -1;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/text", SetText);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E2C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E38_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E48_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E50_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E58_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E5C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E64_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E68_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E70_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E78_usa);
#endif

#if VERSION_USA
#if 0
extern const char RO_STR_800C5E2C_usa[];
extern const char RO_STR_800C5E38_usa[];
extern const char RO_STR_800C5E48_usa[];
extern const char RO_STR_800C5E50_usa[];
extern const char RO_STR_800C5E58_usa[];
extern const char RO_STR_800C5E5C_usa[];
extern const char RO_STR_800C5E64_usa[];
extern const char RO_STR_800C5E68_usa[];
extern const char RO_STR_800C5E70_usa[];
extern const char RO_STR_800C5E78_usa[];

// UpdateText
void func_8004C280_usa(void) {
    char sp18[1];
    text_t *var_s0;
    s16 temp_v0;
    s16 temp_v0_10;
    s16 temp_v0_11;
    s16 temp_v0_12;
    s16 temp_v0_13;
    s16 temp_v0_14;
    s16 temp_v0_15;
    s16 temp_v0_16;
    s16 temp_v0_17;
    s16 temp_v0_18;
    s16 temp_v0_19;
    s16 temp_v0_20;
    s16 temp_v0_21;
    s16 temp_v0_22;
    s16 temp_v0_23;
    s16 temp_v0_24;
    s16 temp_v0_25;
    s16 temp_v0_26;
    s16 temp_v0_27;
    s16 temp_v0_28;
    s16 temp_v0_29;
    s16 temp_v0_2;
    s16 temp_v0_30;
    s16 temp_v0_31;
    s16 temp_v0_32;
    s16 temp_v0_33;
    s16 temp_v0_34;
    s16 temp_v0_35;
    s16 temp_v0_36;
    s16 temp_v0_37;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 temp_v0_7;
    s16 temp_v0_8;
    s16 temp_v0_9;
    s32 *var_a2;
    s32 var_s1;
    s32 var_s3;
    s32 var_s3_10;
    s32 var_s3_11;
    s32 var_s3_12;
    s32 var_s3_13;
    s32 var_s3_14;
    s32 var_s3_15;
    s32 var_s3_16;
    s32 var_s3_17;
    s32 var_s3_18;
    s32 var_s3_19;
    s32 var_s3_20;
    s32 var_s3_21;
    s32 var_s3_22;
    s32 var_s3_23;
    s32 var_s3_24;
    s32 var_s3_25;
    s32 var_s3_26;
    s32 var_s3_27;
    s32 var_s3_28;
    s32 var_s3_29;
    s32 var_s3_2;
    s32 var_s3_30;
    s32 var_s3_31;
    s32 var_s3_32;
    s32 var_s3_33;
    s32 var_s3_34;
    s32 var_s3_35;
    s32 var_s3_36;
    s32 var_s3_37;
    s32 var_s3_3;
    s32 var_s3_4;
    s32 var_s3_5;
    s32 var_s3_6;
    s32 var_s3_7;
    s32 var_s3_8;
    s32 var_s3_9;
    s8 *var_s2;

    if (gMain >= 0x384) {
        if (gTheGame.unk_9C08 == 1) {
            if (gTheGame.unk_9C14 == 0) {
                sprintf(&sp18, &RO_STR_800C5E2C_usa, gTheGame.unk_9C18, gTheGame.unk_9C1C);
                var_s1 = gTheGame.unk_90C0;
                var_s3 = 0x3C;
                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                        break;
                    }
                    var_s0->unk_00.s.objX = var_s3 * 4;
                    var_s0->unk_00.s.objY = 0xA0;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s3 += 9;
                    var_s2 += 1;
                    var_s1 += 1;
                    var_s0++;
                }
            } else {
                sprintf(&sp18, &RO_STR_800C5E38_usa, gTheGame.unk_9C14, gTheGame.unk_9C18, gTheGame.unk_9C1C);
                var_s1 = gTheGame.unk_90C0;
                var_s3_2 = 0x21;
                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;
                while (var_s1 < 0x46) {
                    temp_v0_2 = var_s3_2 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                        break;
                    }
                    var_s3_2 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_2;
                    var_s0->unk_00.s.objY = 0xA0;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            }
        } else if (gSelection == 0x96) {
            if (gTheGame.unk_9C14 > 0) {
                sprintf(&sp18, &RO_STR_800C5E48_usa);
                var_s1 = gTheGame.unk_90C0;
                var_s3_3 = 0x8A;
                var_s0 = (var_s1 << 5) + (&gTheGame.unk_9C14 - 0xB4C);
                var_s2 = &sp18;
                while (var_s1 < 0x46) {
                    temp_v0_3 = var_s3_3 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                        break;
                    }
                    var_s3_3 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_3;
                    var_s0->unk_00.s.objY = 0x2B0;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            } else {
                sprintf(&sp18, &RO_STR_800C5E50_usa, gTheGame.unk_9C18, gTheGame.unk_9C1C);
                var_s3_4 = 0x8F;
                if (gTheGame.unk_9C18 < 0xA) {
                    var_s1 = gTheGame.unk_90C0;
                    var_s0 = (var_s1 << 5) + (&gTheGame.unk_9C14 - 0xB4C);
                    var_s2 = &sp18;
                    while (var_s1 < 0x46) {
                        temp_v0_4 = var_s3_4 * 4;
                        if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                            break;
                        }
                        var_s3_4 += 9;
                        var_s2 += 1;
                        var_s0->unk_00.s.objX = temp_v0_4;
                        var_s0->unk_00.s.objY = 0x2B0;
                        var_s0->unk_00.s.imageW = 0x200;
                        var_s1 += 1;
                        var_s0++;
                    }
                } else {
                    var_s1 = gTheGame.unk_90C0;
                    var_s3_5 = 0x8A;
                    var_s0 = (var_s1 << 5) + (&gTheGame.unk_9C14 - 0xB4C);
                    var_s2 = &sp18;
                    while (var_s1 < 0x46) {
                        temp_v0_5 = var_s3_5 * 4;
                        if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                            break;
                        }
                        var_s3_5 += 9;
                        var_s2 += 1;
                        var_s0->unk_00.s.objX = temp_v0_5;
                        var_s0->unk_00.s.objY = 0x2B0;
                        var_s0->unk_00.s.imageW = 0x200;
                        var_s1 += 1;
                        var_s0++;
                    }
                }
            }
        } else if (gTheGame.unk_9C14 > 0) {
            sprintf(&sp18, &RO_STR_800C5E48_usa);
            var_s1 = gTheGame.unk_90C0;
            var_s3_6 = 0x8A;
            var_s0 = (var_s1 << 5) + (&gTheGame.unk_9C14 - 0xB4C);
            var_s2 = &sp18;
            while (var_s1 < 0x46) {
                temp_v0_6 = var_s3_6 * 4;
                if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                    break;
                }
                var_s3_6 += 9;
                var_s2 += 1;
                var_s0->unk_00.s.objX = temp_v0_6;
                var_s0->unk_00.s.objY = 0x268;
                var_s0->unk_00.s.imageW = 0x200;
                var_s1 += 1;
                var_s0++;
            }
        } else {
            sprintf(&sp18, &RO_STR_800C5E50_usa, gTheGame.unk_9C18, gTheGame.unk_9C1C);
            var_s3_7 = 0x8F;
            if (gTheGame.unk_9C18 < 0xA) {
                var_s1 = gTheGame.unk_90C0;
                var_s0 = (var_s1 << 5) + (&gTheGame.unk_9C14 - 0xB4C);
                var_s2 = &sp18;
                while (var_s1 < 0x46) {
                loop_40:
                    temp_v0_7 = var_s3_7 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                        break;
                    }
                    var_s3_7 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_7;
                    var_s0->unk_00.s.objY = 0x268;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            } else {
                var_s1 = gTheGame.unk_90C0;
                var_s3_8 = 0x8A;
                var_s0 = (var_s1 << 5) + (&gTheGame.unk_9C14 - 0xB4C);
                var_s2 = &sp18;
                while (var_s1 < 0x46) {

                    temp_v0_8 = var_s3_8 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                        break;
                    }
                    var_s3_8 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_8;
                    var_s0->unk_00.s.objY = 0x268;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            }
        }
        gTheGame.unk_90C0 = var_s1;
    }

    switch (gSelection) {
        case 0x8C:
        case 0xBE:
            if (gSelection == 0x8C) {
                if (gTheGame.unk_9C0C == 1) {
                    var_a2 = gPlayer + 0x14;
                } else {
                    var_a2 = gPlayer + 0x18;
                }
            } else if (gTheGame.unk_9C0C == 1) {
                var_a2 = gPlayer + 0x1C;
            } else {
                var_a2 = gPlayer + 0x20;
            }
            if (gTheGame.tetrisWell[0].unk_43AC > 0xF423F) {
                gTheGame.tetrisWell[0].unk_43AC = 0xF423F;
            }
            if (gDemo == GDEMO_2C) {
                if (gTheGame.tetrisWell[0].unk_4420 != 0) {
                    if (*var_a2 < gTheGame.tetrisWell[0].unk_43AC) {
                        *var_a2 = gTheGame.tetrisWell[0].unk_43AC;
                    }
                    goto block_63;
                }
            } else {
            block_63:
                if (gTheGame.tetrisWell[0].unk_4420 != 0) {
                    sprintf(&sp18, &RO_STR_800C5E58_usa, *var_a2);
                    var_s1 = gTheGame.unk_90C0;
                    var_s3_9 = 0xE8;
                    var_s0 = &gTheGame.unk_90C8[var_s1];
                    var_s2 = &sp18;
                    while (var_s1 < 0x46) {
                    loop_66:
                        temp_v0_9 = var_s3_9 * 4;
                        if (InitWhichNumber(var_s0, *var_s2, 0x16) == 0) {
                            break;
                        }
                        var_s3_9 += 9;
                        var_s2 += 1;
                        var_s0->unk_00.s.objX = temp_v0_9;
                        var_s0->unk_00.s.objY = 0xA8;
                        var_s0->unk_00.s.imageW = 0x200;
                        var_s1 += 1;
                        var_s0++;
                    }
                    gTheGame.unk_90C0 = var_s1;
                }
            }

            sprintf(&sp18, &RO_STR_800C5E58_usa, gTheGame.tetrisWell[0].unk_43AC);
            var_s1 = gTheGame.unk_90C0;
            var_s3_10 = 0xE8;
            var_s0 = &gTheGame.unk_90C8[var_s1];
            var_s2 = &sp18;
            while (var_s1 < 0x46) {

                temp_v0_10 = var_s3_10 * 4;
                if (InitWhichNumber(var_s0, *var_s2, 0x15) == 0) {
                    break;
                }
                var_s3_10 += 9;
                var_s2 += 1;
                var_s0->unk_00.s.objX = temp_v0_10;
                var_s0->unk_00.s.objY = 0xFC;
                var_s0->unk_00.s.imageW = 0x200;
                var_s1 += 1;
                var_s0++;
            }
            gTheGame.unk_90C0 = var_s1;
            if (gTheGame.unk_8860[0].unk_0C > 0) {
                sprintf(&sp18, &RO_STR_800C5E5C_usa, gTheGame.unk_8860[0].unk_0C / 60);
                var_s1 = gTheGame.unk_90C0;
                var_s3_11 = 0xFA;
                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;
                while (var_s1 < 0x46) {
                    temp_v0_11 = var_s3_11 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                        break;
                    }
                    var_s3_11 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_11;
                    var_s0->unk_00.s.objY = 0x16C;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
                gTheGame.unk_90C0 = var_s1;
                gTheGame.unk_90C8[3].unk_18 = -1U;
                gTheGame.unk_90C8[4].unk_18 = -1U;
            } else {
                if (DoFlashDraw(0) != 0) {
                    sprintf(&sp18, &RO_STR_800C5E64_usa, gTheGame.tetrisWell[0].unk_43E0);
                    var_s1 = gTheGame.unk_90C0;
                    var_s3_12 = 0x10C;
                    var_s0 = &gTheGame.unk_90C8[var_s1];
                    var_s2 = &sp18;
                    while (var_s1 < 0x46) {
                    loop_82:
                        temp_v0_12 = var_s3_12 * 4;
                        if (InitWhichNumber(var_s0, *var_s2, 0x15) == 0) {
                            break;
                        }
                        var_s3_12 += 9;
                        var_s2 += 1;
                        var_s0->unk_00.s.objX = temp_v0_12;
                        var_s0->unk_00.s.objY = 0x16C;
                        var_s0->unk_00.s.imageW = 0x200;
                        var_s1 += 1;
                        var_s0++;
                    }
                    gTheGame.unk_90C0 = var_s1;
                }
                gTheGame.unk_90C8[3].unk_18 = 0;
                if (gTheGame.tetrisWell[0].unk_4408[0x18] < 2) {
                    gTheGame.unk_90C8[4].unk_18 = 1;
                } else {
                    gTheGame.unk_90C8[4].unk_18 = 2;
                }
            }
            break;

        case 0xAA:
            if (gTheGame.tetrisWell[0].unk_4420 != 5) {
                sprintf(&sp18, &RO_STR_800C5E68_usa, gTheGame.tetrisWell[0].unk_4424, gTheGame.tetrisWell[0].unk_4428);
                var_s1 = gTheGame.unk_90C0;
                var_s3_13 = 0x103;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_13 = var_s3_13 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x16) == 0) {
                        break;
                    }
                    var_s3_13 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_13;
                    var_s0->unk_00.s.objY = 0xA4;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
                gTheGame.unk_90C0 = var_s1;
            }
            if (gTheGame.tetrisWell[0].unk_43AC > 0xF423F) {
                gTheGame.tetrisWell[0].unk_43AC = 0xF423F;
            }
            sprintf(&sp18, &RO_STR_800C5E58_usa, gTheGame.tetrisWell[0].unk_43AC);
            var_s1 = gTheGame.unk_90C0;
            var_s3_14 = 0xE8;

            var_s0 = &gTheGame.unk_90C8[var_s1];
            var_s2 = &sp18;

            while (var_s1 < 0x46) {
                temp_v0_14 = var_s3_14 * 4;
                if (InitWhichNumber(var_s0, *var_s2, 0x15) == 0) {
                    break;
                }
                var_s3_14 += 9;
                var_s2 += 1;
                var_s0->unk_00.s.objX = temp_v0_14;
                var_s0->unk_00.s.objY = 0xFC;
                var_s0->unk_00.s.imageW = 0x200;
                var_s1 += 1;
                var_s0++;
            }
            gTheGame.unk_90C0 = var_s1;
            if (gTheGame.unk_8860[0].unk_0C > 0) {
                sprintf(&sp18, &RO_STR_800C5E5C_usa, gTheGame.unk_8860[0].unk_0C / 60);
                var_s1 = gTheGame.unk_90C0;
                var_s3_15 = 0xFA;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_15 = var_s3_15 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                        break;
                    }
                    var_s3_15 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_15;
                    var_s0->unk_00.s.objY = 0x16C;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
                gTheGame.unk_90C0 = var_s1;
                gTheGame.unk_90C8[3].unk_18 = -1U;
            } else {
                if (DoFlashDraw(0) != 0) {
                    sprintf(&sp18, &RO_STR_800C5E64_usa, gTheGame.tetrisWell[0].unk_43E0);
                    var_s1 = gTheGame.unk_90C0;
                    var_s3_16 = 0x10C;

                    var_s0 = &gTheGame.unk_90C8[var_s1];
                    var_s2 = &sp18;

                    while (var_s1 < 0x46) {
                        temp_v0_16 = var_s3_16 * 4;
                        if (InitWhichNumber(var_s0, *var_s2, 0x15) == 0) {
                            break;
                        }
                        var_s3_16 += 9;
                        var_s2 += 1;
                        var_s0->unk_00.s.objX = temp_v0_16;
                        var_s0->unk_00.s.objY = 0x16C;
                        var_s0->unk_00.s.imageW = 0x200;
                        var_s1 += 1;
                        var_s0++;
                    }
                    gTheGame.unk_90C0 = var_s1;
                }
                if (gTheGame.tetrisWell[0].unk_4420 != 5) {
                    gTheGame.unk_90C8[3].unk_18 = 0;
                    sprintf(&sp18, &RO_STR_800C5E64_usa, gTheGame.tetrisWell[0].unk_4424);
                    var_s1 = gTheGame.unk_90C0;
                    var_s3_17 = 0x10C;

                    var_s0 = (var_s1 << 5) + (&gTheGame.unk_90C8[3].unk_18 - 0x78);
                    var_s2 = &sp18;

                    while (var_s1 < 0x46) {
                        temp_v0_17 = var_s3_17 * 4;
                        if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                            break;
                        }
                        var_s3_17 += 9;
                        var_s2 += 1;
                        var_s0->unk_00.s.objX = temp_v0_17;
                        var_s0->unk_00.s.objY = 0x1E4;
                        var_s0->unk_00.s.imageW = 0x200;
                        var_s1 += 1;
                        var_s0++;
                    }
                    gTheGame.unk_90C0 = var_s1;
                }
            }
            break;

        default:
            break;

        case 0x78:
            sprintf(&sp18, &RO_STR_800C5E64_usa, gTheGame.tetrisWell[0].unk_4424);
            var_s1 = gTheGame.unk_90C0;
            var_s3_18 = 0x10C;

            var_s0 = &gTheGame.unk_90C8[var_s1];
            var_s2 = &sp18;

            while (var_s1 < 0x46) {
                temp_v0_18 = var_s3_18 * 4;
                if (InitWhichNumber(var_s0, *var_s2, 0x16) == 0) {
                    break;
                }
                var_s3_18 += 9;
                var_s2 += 1;
                var_s0->unk_00.s.objX = temp_v0_18;
                var_s0->unk_00.s.objY = 0xB0;
                var_s0->unk_00.s.imageW = 0x200;
                var_s1 += 1;
                var_s0++;
            }
            gTheGame.unk_90C0 = var_s1;
            break;

        case 0x82:
            if (gTheGame.tetrisWell[0].unk_4420 == 0) {
                sprintf(&sp18, &RO_STR_800C5E64_usa, gTheGame.tetrisWell[0].unk_4424);
                var_s1 = gTheGame.unk_90C0;
                var_s3_19 = 0x10C;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_19 = var_s3_19 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x16) == 0) {
                        break;
                    }
                    var_s3_19 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_19;
                    var_s0->unk_00.s.objY = 0xFC;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            } else if (gTheGame.tetrisWell[0].unk_4420 < 4) {
                sprintf(&sp18, &RO_STR_800C5E64_usa, gTheGame.tetrisWell[0].unk_4420);
                var_s1 = gTheGame.unk_90C0;
                var_s3_20 = 0x10C;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_20 = var_s3_20 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x17) == 0) {
                        break;
                    }
                    var_s3_20 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_20;
                    var_s0->unk_00.s.objY = 0xA8;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
                gTheGame.unk_90C0 = var_s1;
                sprintf(&sp18, &RO_STR_800C5E64_usa, gTheGame.tetrisWell[0].unk_4424);
                var_s1 = gTheGame.unk_90C0;
                var_s3_21 = 0x10C;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_21 = var_s3_21 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x15) == 0) {
                        break;
                    }
                    var_s3_21 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_21;
                    var_s0->unk_00.s.objY = 0xFC;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            } else {
                sprintf(&sp18, &RO_STR_800C5E64_usa, gTheGame.tetrisWell[0].unk_4420 - 3);
                var_s1 = gTheGame.unk_90C0;
                var_s3_22 = 0x10C;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_22 = var_s3_22 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x16) == 0) {
                        break;
                    }
                    var_s3_22 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_22;
                    var_s0->unk_00.s.objY = 0xA8;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
                gTheGame.unk_90C0 = var_s1;
                sprintf(&sp18, &RO_STR_800C5E64_usa, gTheGame.tetrisWell[0].unk_4424);
                var_s1 = gTheGame.unk_90C0;
                var_s3_23 = 0x10C;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_23 = var_s3_23 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                        break;
                    }
                    var_s3_23 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_23;
                    var_s0->unk_00.s.objY = 0xFC;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            }
            gTheGame.unk_90C0 = var_s1;
            break;

        case 0xC8:
            sprintf(&sp18, &RO_STR_800C5E70_usa, gTheGame.tetrisWell[0].unk_43AC % 100000, gTheGame.tetrisWell[0].unk_43AC);
            var_s1 = gTheGame.unk_90C0;
            var_s3_24 = 0x89;

            var_s0 = &gTheGame.unk_90C8[var_s1];
            var_s2 = &sp18;

            while (var_s1 < 0x46) {
                temp_v0_24 = var_s3_24 * 4;
                if (InitWhichNumber(var_s0, *var_s2, 0x15) == 0) {
                    break;
                }
                var_s3_24 += 9;
                var_s2 += 1;
                var_s0->unk_00.s.objX = temp_v0_24;
                var_s0->unk_00.s.objY = 0x160;
                var_s0->unk_00.s.imageW = 0x200;
                var_s1 += 1;
                var_s0++;
            }
            gTheGame.unk_90C0 = var_s1;
            sprintf(&sp18, &RO_STR_800C5E70_usa, gTheGame.tetrisWell[1].unk_43AC % 100000, gTheGame.tetrisWell[1].unk_43AC);
            var_s1 = gTheGame.unk_90C0;
            var_s3_25 = 0x8A;

            var_s0 = &gTheGame.unk_90C8[var_s1];
            var_s2 = &sp18;

            while (var_s1 < 0x46) {
                temp_v0_25 = var_s3_25 * 4;
                if (InitWhichNumber(var_s0, *var_s2, 0x14) == 0) {
                    break;
                }
                var_s3_25 += 9;
                var_s2 += 1;
                var_s0->unk_00.s.objX = temp_v0_25;
                var_s0->unk_00.s.objY = 0x1E4;
                var_s0->unk_00.s.imageW = 0x200;
                var_s1 += 1;
                var_s0++;
            }
            gTheGame.unk_90C0 = var_s1;
            sprintf(&sp18, &RO_STR_800C5E78_usa, gTheGame.tetrisWell[0].unk_4428);
            var_s3_26 = 0x93;
            if (gTheGame.tetrisWell[0].unk_4428 < 0xA) {
                var_s1 = gTheGame.unk_90C0;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_26 = var_s3_26 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x17) == 0) {
                        break;
                    }
                    var_s3_26 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_26;
                    var_s0->unk_00.s.objY = 0xE4;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            } else {
                var_s1 = gTheGame.unk_90C0;
                var_s3_27 = 0x8D;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_27 = var_s3_27 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x17) == 0) {
                        break;
                    }
                    var_s3_27 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_27;
                    var_s0->unk_00.s.objY = 0xE4;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            }
            gTheGame.unk_90C0 = var_s1;
            sprintf(&sp18, &RO_STR_800C5E78_usa, gTheGame.tetrisWell[1].unk_4428);
            var_s3_28 = 0xA3;
            if (gTheGame.tetrisWell[1].unk_4428 < 0xA) {
                var_s1 = gTheGame.unk_90C0;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_28 = var_s3_28 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x16) == 0) {
                        break;
                    }
                    var_s3_28 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_28;
                    var_s0->unk_00.s.objY = 0xE4;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            } else {
                var_s1 = gTheGame.unk_90C0;
                var_s3_29 = 0x9D;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_29 = var_s3_29 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x16) == 0) {
                        break;
                    }
                    var_s3_29 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_29;
                    var_s0->unk_00.s.objY = 0xE4;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            }
            gTheGame.unk_90C0 = var_s1;
            break;

        case 0xA0:
        case 0xB4:
            sprintf(&sp18, &RO_STR_800C5E78_usa, gTheGame.tetrisWell[0].unk_4420);
            var_s3_30 = 0x93;
            if (gTheGame.tetrisWell[0].unk_4420 < 0xA) {
                var_s1 = gTheGame.unk_90C0;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_30 = var_s3_30 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x17) == 0) {
                        break;
                    }
                    var_s3_30 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_30;
                    var_s0->unk_00.s.objY = 0x16C;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            } else {
                var_s1 = gTheGame.unk_90C0;
                var_s3_31 = 0x8D;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_31 = var_s3_31 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x17) == 0) {
                        break;
                    }
                    var_s3_31 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_31;
                    var_s0->unk_00.s.objY = 0x16C;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            }
            gTheGame.unk_90C0 = var_s1;
            sprintf(&sp18, &RO_STR_800C5E78_usa, gTheGame.tetrisWell[1].unk_4420);
            var_s3_32 = 0xA4;
            if (gTheGame.tetrisWell[1].unk_4420 < 0xA) {
                var_s1 = gTheGame.unk_90C0;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_32 = var_s3_32 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x16) == 0) {
                        break;
                    }
                    var_s3_32 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_32;
                    var_s0->unk_00.s.objY = 0x16C;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            } else {
                var_s1 = gTheGame.unk_90C0;
                var_s3_33 = 0xA1;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_33 = var_s3_33 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x16) == 0) {
                        break;
                    }
                    var_s3_33 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_33;
                    var_s0->unk_00.s.objY = 0x16C;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            }
            gTheGame.unk_90C0 = var_s1;
            sprintf(&sp18, &RO_STR_800C5E78_usa, gTheGame.tetrisWell[0].unk_4428);
            var_s3_34 = 0x93;
            if (gTheGame.tetrisWell[0].unk_4428 < 0xA) {
                var_s1 = gTheGame.unk_90C0;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_34 = var_s3_34 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x17) == 0) {
                        break;
                    }
                    var_s3_34 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_34;
                    var_s0->unk_00.s.objY = 0x1E4;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            } else {
                var_s1 = gTheGame.unk_90C0;
                var_s3_35 = 0x8D;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_35 = var_s3_35 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x17) == 0) {
                        break;
                    }
                    var_s3_35 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_35;
                    var_s0->unk_00.s.objY = 0x1E4;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            }
            gTheGame.unk_90C0 = var_s1;
            sprintf(&sp18, &RO_STR_800C5E78_usa, gTheGame.tetrisWell[1].unk_4428);
            var_s3_36 = 0xA4;
            if (gTheGame.tetrisWell[1].unk_4428 < 0xA) {
                var_s1 = gTheGame.unk_90C0;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_36 = var_s3_36 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x16) == 0) {
                        break;
                    }
                    var_s3_36 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_36;
                    var_s0->unk_00.s.objY = 0x1E4;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            } else {
                var_s1 = gTheGame.unk_90C0;
                var_s3_37 = 0x9F;

                var_s0 = &gTheGame.unk_90C8[var_s1];
                var_s2 = &sp18;

                while (var_s1 < 0x46) {
                    temp_v0_37 = var_s3_37 * 4;
                    if (InitWhichNumber(var_s0, *var_s2, 0x16) == 0) {
                        break;
                    }
                    var_s3_37 += 9;
                    var_s2 += 1;
                    var_s0->unk_00.s.objX = temp_v0_37;
                    var_s0->unk_00.s.objY = 0x1E4;
                    var_s0->unk_00.s.imageW = 0x200;
                    var_s1 += 1;
                    var_s0++;
                }
            }
            gTheGame.unk_90C0 = var_s1;
            break;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/text", func_8004C280_usa);
#endif
#endif

#if VERSION_USA
void Draw2DTemplate(struct_gInfo_unk_00068 *dynamicp) {
    s32 var_t1 = -1;
    s32 i;

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &otherLUT);

    for (i = 0; i < MAGIC_NUMBER; i++) {
        s32 var_v1 = dynamicp->drawText[i].texture;

        if (var_v1 == -1) {
            continue;
        }

        if (var_v1 >= 0xB) {
            var_v1 = 0x19;
        }

        if (var_v1 != var_t1) {
            var_t1 = var_v1;

            switch (var_v1) {
                case 0x0:
                    gSPObjLoadTxtr(glistp++, &D_0101F240_usa);
                    break;

                case 0x1:
                    gSPObjLoadTxtr(glistp++, &D_0101F258_usa);
                    break;

                case 0x2:
                    gSPObjLoadTxtr(glistp++, &D_0101F270_usa);
                    break;

                case 0x3:
                    gSPObjLoadTxtr(glistp++, &D_0101F288_usa);
                    break;

                case 0x4:
                    gSPObjLoadTxtr(glistp++, &D_0101F2A0_usa);
                    break;

                case 0x5:
                    gSPObjLoadTxtr(glistp++, &D_0101F2D0_usa);
                    break;

                case 0x6:
                    gSPObjLoadTxtr(glistp++, &D_0101F2E8_usa);
                    break;

                case 0x7:
                    gSPObjLoadTxtr(glistp++, &D_0101F348_usa);
                    break;

                case 0x8:
                    gSPObjLoadTxtr(glistp++, &D_0101F360_usa);
                    break;

                default:
                    gSPObjLoadTxtr(glistp++, &D_0101F2B8_usa);
                    break;
            }
        }

        gSPObjRectangle(glistp++, &dynamicp->drawText[i].word);
    }
}
#endif

#if VERSION_USA
void Draw2DText(struct_gInfo_unk_00068 *dynamicp) {
    s8 sp10[MAGIC_NUMBER];
    s32 i;
    s32 var_s1 = 0;
    s32 j;

    Draw2DTemplate(dynamicp);
    bzero(sp10, MAGIC_NUMBER * sizeof(s8));

    for (i = MAGIC_NUMBER; i < GAME_UNK_90C8_LEN; i++) {
        if (dynamicp->drawText[i].texture < ARRAY_COUNTU(sp10)) {
            sp10[dynamicp->drawText[i].texture] = true;
        } else if (dynamicp->drawText[i].texture == -1) {
            var_s1 = i;
            break;
        }
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &numberLUT);

    for (j = 0; j < MAGIC_NUMBER; j++) {
        if (!sp10[j]) {
            continue;
        }

        switch (j) {
            case 0x0:
                gSPObjLoadTxtr(glistp++, &numberTexture1);
                break;

            case 0x1:
                gSPObjLoadTxtr(glistp++, &numberTexture2);
                break;

            case 0x2:
                gSPObjLoadTxtr(glistp++, &numberTexture3);
                break;

            case 0x3:
                gSPObjLoadTxtr(glistp++, &numberTexture4);
                break;

            case 0x4:
                gSPObjLoadTxtr(glistp++, &numberTexture5);
                break;

            case 0x5:
                gSPObjLoadTxtr(glistp++, &numberTexture6);
                break;
        }

        for (i = MAGIC_NUMBER; i < var_s1; i++) {
            if (dynamicp->drawText[i].texture == j) {
                gSPObjRectangle(glistp++, &dynamicp->drawText[i].word);
            }
        }
    }
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/text", func_8004DF64_usa);
#endif
