/**
 * Original filename: bonus.c
 */

#include "bonus.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "animation.h"
#include "bg_screen_load.h"
#include "buffers.h"
#include "end.h"
#include "hvqm2util.h"
#include "image.h"
#include "info.h"
#include "init2d.h"
#include "peel.h"
#include "screen.h"
#include "sfxlimit.h"
#include "sound.h"
#include "tetris.h"
#include "text.h"
#include "the_game.h"
#include "update.h"

#include "001F10.h"

typedef struct struct_800C4490_usa {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x4 */ UNK_TYPE4 unk_4;
    /* 0x8 */ UNK_TYPE4 unk_8;
    /* 0xC */ UNK_TYPE4 unk_C;
} struct_800C4490_usa; // size = 0x10

typedef struct struct_800C44F0_usa {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 unk_1;
} struct_800C44F0_usa; // size = 0x2

typedef struct struct_800C4518_usa {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x4 */ UNK_TYPE4 unk_4;
} struct_800C4518_usa; // size = 0x8

typedef struct struct_800C4598_usa {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x4 */ UNK_TYPE4 unk_4;
} struct_800C4598_usa; // size = 0x8

extern u32 D_1030FE0[];
extern u32 D_104C660[];
extern u32 D_105B710[];
extern u32 D_1070A60[];

typedef struct struct_8004EC4C_usa_arg2 {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x0 */ UNK_TYPE1 unk_4[0x4];
} struct_8004EC4C_usa_arg2; // size = 0x8

typedef struct struct_8004EC4C_usa_arg3 {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x0 */ UNK_TYPE1 unk_4[0x4];
} struct_8004EC4C_usa_arg3; // size = 0x8

#if VERSION_USA
//#ifdef NON_EQUIVALENT
#if 0
void InitBonus(void) {
    s32 var_s3 = 0;
    s32 s5 = 1;
    s32 s8 = 2;
    DATA_INLINE_CONST2 struct_800C4490_usa sp10[] = { 0x40, 0x3E, 0x40, 0x45 };
    DATA_INLINE_CONST2 s32 sp20[] = { 0xF8, 0x100 };
    DATA_INLINE_CONST2 struct_800C4490_usa sp28[] = {
        { 0xC0, 0x2F, 0x13, 0x21 }, { 0x40, 0x1D, 0xB6, 0xBA }, { 0x40, 0x1D, 0xB6, 0xBA },
        { 0x40, 0x1D, 0xE1, 0xBA }, { 0x40, 0x1D, 0xE1, 0xBA },
    };
    DATA_INLINE_CONST2 struct_800C44F0_usa sp78[] = {
        { 0x00, 0x07 }, { 0x01, 0x01 }, { 0x02, 0x00 }, { 0x02, 0x02 }, { 0x05, 0x04 },
        { 0x0C, 0x02 }, { 0x02, 0x02 }, { 0x09, 0x06 }, { 0x02, 0x05 }, { 0x00, 0x00 },
        { 0x07, 0x06 }, { 0x04, 0x04 }, { 0x02, 0x03 }, { 0x05, 0x03 }, { 0x05, 0x09 },
    };
    DATA_INLINE_CONST2 u8 sp98[] = {
        0x1D, 0x30, 0x43, 0x56, 0x69, 0x7C,
    };
    DATA_INLINE_CONST2 struct_800C4518_usa spA0[] = {
        { 192, 129 },                             //
        { 192, BGSCREEN_TEX_7E5010_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_1
        { 192, BGSCREEN_TEX_7F5BD0_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_2
        { 192, BGSCREEN_TEX_8088D0_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_3
        { 192, BGSCREEN_TEX_81A450_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_4
        { 192, BGSCREEN_TEX_82C890_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_5
        { 192, BGSCREEN_TEX_83EB10_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_6
        { 192, BGSCREEN_TEX_8520D0_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_7
        { 192, BGSCREEN_TEX_865D90_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_8
        { 192, BGSCREEN_TEX_87A4D0_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_9
        { 192, BGSCREEN_TEX_88DA90_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_10
        { 192, BGSCREEN_TEX_8A8050_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_11
        { 192, BGSCREEN_TEX_8BB610_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_12
        { 192, BGSCREEN_TEX_8CE310_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_13
        { 192, BGSCREEN_TEX_8E2A50_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_14
        { 192, BGSCREEN_TEX_902250_MAIN_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_15
    };
    DATA_INLINE_CONST2 struct_800C4598_usa sp120[] = {
        { 65, 63 },                              //
        { 63, BGSCREEN_TEX_7E5010_TOP_HEIGHT },  // ENUM_GAME_UNK_0000_UNK_4424_1
        { 66, BGSCREEN_TEX_7F5BD0_TOP_HEIGHT },  // ENUM_GAME_UNK_0000_UNK_4424_2
        { 71, BGSCREEN_TEX_8088D0_TOP_HEIGHT },  // ENUM_GAME_UNK_0000_UNK_4424_3
        { 101, BGSCREEN_TEX_81A450_TOP_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_4
        { 78, BGSCREEN_TEX_82C890_TOP_HEIGHT },  // ENUM_GAME_UNK_0000_UNK_4424_5
        { 126, BGSCREEN_TEX_83EB10_TOP_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_6
        { 79, BGSCREEN_TEX_8520D0_TOP_HEIGHT },  // ENUM_GAME_UNK_0000_UNK_4424_7
        { 93, BGSCREEN_TEX_865D90_TOP_HEIGHT },  // ENUM_GAME_UNK_0000_UNK_4424_8
        { 87, BGSCREEN_TEX_87A4D0_TOP_HEIGHT },  // ENUM_GAME_UNK_0000_UNK_4424_9
        { 172, BGSCREEN_TEX_88DA90_TOP_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_10
        { 85, BGSCREEN_TEX_8A8050_TOP_HEIGHT },  // ENUM_GAME_UNK_0000_UNK_4424_11
        { 80, BGSCREEN_TEX_8BB610_TOP_HEIGHT },  // ENUM_GAME_UNK_0000_UNK_4424_12
        { 113, BGSCREEN_TEX_8CE310_TOP_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_13
        { 192, BGSCREEN_TEX_8E2A50_TOP_HEIGHT }, // ENUM_GAME_UNK_0000_UNK_4424_14
        { 95, BGSCREEN_TEX_902250_TOP_HEIGHT },  // ENUM_GAME_UNK_0000_UNK_4424_15
    };
    s32 var_s2;
    uObjTxtr *var_v1;
    void *temp_v0;
    uObjBg *var_s0;
    void *temp_s4;
    volatile unsigned short pad;
    s32 t1 = 5;

    gCounter = 0;
    Pon_Image_Heap = &gBufferHeap[SEGMENT_ROM_SIZE(segment_0CA4A0)];

    temp_s4 = Pon_Image_Heap;

    osInvalDCache((void *)D_1030FE0, (u32)D_105B710 - (u32)D_1030FE0);
    func_80001310_usa(SEGMENT_ROM_START(segment_101A80), temp_s4, SEGMENT_ROM_SIZE(segment_101A80));
    Pon_Image_Heap += SEGMENT_ROM_SIZE(segment_101A80);

    if ((gSelection == 0x96) && (gTheGame.cursorBlock[0].unk_00 != 7) && (gTheGame.cursorBlock[1].unk_00 != 8) &&
        (B_801C6C90_usa == 0x10)) {
        PlayMIDI(BGM_INIT_TABLE, 0x20, 0, 1);
    }
    gTheGame.unk_9A50.b.imagePtr = temp_s4 + var_s3;
    // temp_s4 = gTheGame.unk_9A50.b.imagePtr;

    guS2DInitBg(&gTheGame.unk_9A50);

    var_s3 = 0x24400;

    for (var_s2 = 0; var_s2 < s5; var_s2++) {
        var_s0 = &gTheGame.unk_8C88[var_s2];

        var_s0->b.imageX = 0;
        var_s0->b.imageW = sp10[var_s2].unk_0 << 2;
        var_s0->b.frameX = sp10[var_s2].unk_8 << 2;
        var_s0->b.frameW = sp10[var_s2].unk_0 << 2;

        var_s0->b.imageY = 0;
        var_s0->b.imageH = sp10[var_s2].unk_4 << 2;
        var_s0->b.frameY = sp10[var_s2].unk_C << 2;
        var_s0->b.frameH = sp10[var_s2].unk_4 << 2;

        var_s0->b.imagePtr = &temp_s4[var_s3];
        var_s0->b.imageLoad = G_BGLT_LOADTILE;
        var_s0->b.imageFmt = G_IM_FMT_RGBA;
        var_s0->b.imageSiz = G_IM_SIZ_16b;
        var_s0->b.imagePal = 0;
        var_s0->b.imageFlip = 0;

        guS2DInitBg(var_s0);

        var_s3 += sp10[var_s2].unk_0 * sp10[var_s2].unk_4 * 2;
    }

    var_s3 = 0x26300;
    var_s2 = 0;
    while (var_s2 < s8) {
        var_v1 = &gTheGame.unk_8B98[var_s2];
        var_v1->tlut.type = 0x30;
        var_v1->tlut.image = &temp_s4[var_s3];
        var_v1->tlut.phead = 0x100;
        var_v1->tlut.pnum = (sp20[var_s2] - 1);
        var_v1->tlut.zero = 0;
        var_v1->tlut.sid = 0;
        var_v1->tlut.flag = -1;
        var_v1->tlut.mask = 0;
        var_s3 += sp20[var_s2] * 2;
        var_s2 += 1;
    }

    if (t1) {
        for (var_s2 = 0; var_s2 < 5; var_s2++, s5++) {
            var_s0 = &gTheGame.unk_8C88[s5];

            var_s0->b.imageX = 0 << 2;
            var_s0->b.imageW = sp28[var_s2].unk_0 << 2;
            var_s0->b.frameX = sp28[var_s2].unk_8 << 2;
            var_s0->b.frameW = sp28[var_s2].unk_0 << 2;
            var_s0->b.imageY = 0 << 2;
            var_s0->b.imageH = sp28[var_s2].unk_4 << 2;
            var_s0->b.frameY = sp28[var_s2].unk_C << 2;
            var_s0->b.frameH = sp28[var_s2].unk_4 << 2;
            var_s0->b.imagePtr = &temp_s4[var_s3];
            var_s0->b.imageLoad = G_BGLT_LOADTILE;
            var_s0->b.imageFmt = G_IM_FMT_CI;
            var_s0->b.imageSiz = G_IM_SIZ_8b;
            var_s0->b.imagePal = 0;
            var_s0->b.imageFlip = 0;

            guS2DInitBg(var_s0);
            var_s3 += sp28[var_s2].unk_0 * sp28[var_s2].unk_4;
        }
    }

    if (gSelection == 0x96) {
        var_s3 = gTheGame.tetrisWell[1].unk_4424;
        switch (var_s3) {
            case ENUM_GAME_UNK_0000_UNK_4424_1:
                func_80073C20_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;

            case ENUM_GAME_UNK_0000_UNK_4424_2:
                func_80073D10_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_3:
                func_80073E00_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_4:
                func_80073EF0_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_5:
                func_80073FE0_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_6:
                func_800740D0_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_7:
                func_800741C0_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_8:
                func_800742B0_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_9:
                func_800743A0_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_10:
                func_80074490_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_11:
                func_80074580_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_12:
                func_80074670_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_13:
                func_80074760_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_14:
                func_80074850_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;
            case ENUM_GAME_UNK_0000_UNK_4424_15:
            case ENUM_GAME_UNK_0000_UNK_4424_18:
                func_80074940_usa(false, 0, spA0[var_s3].unk_4, sp120[var_s3].unk_4);
                break;

            case ENUM_GAME_UNK_0000_UNK_4424_16:
                temp_s4 = Pon_Image_Heap;

                osInvalDCache((void *)D_104C660, (u32)D_1070A60 - (u32)D_104C660);
                func_80001310_usa(SEGMENT_ROM_START(segment_background_50F3F0), temp_s4,
                                  SEGMENT_ROM_SIZE(segment_background_50F3F0));
                Pon_Image_Heap = (uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_background_50F3F0);

                bcopy(&gTheGame.unk_9A50, &gTheGame.unk_8C88[6], sizeof(uObjBg));
                gTheGame.unk_8C88[6].b.imagePtr = temp_s4;
                guS2DInitBg(&gTheGame.unk_8C88[6]);
                break;

            default:
                break;
        }

        if (var_s3 == ENUM_GAME_UNK_0000_UNK_4424_16) {
            gTheGame.unk_8C88[6].b.frameX = -0x2C;
            gTheGame.unk_8C88[6].b.frameY = 0x44;
        } else {
            gTheGame.unk_8C88[6].b.frameX = (0xB2 - sp78[var_s3 - 1].unk_0) << 2;
            gTheGame.unk_8C88[6].b.frameY = (sp120[var_s3].unk_4 + 0x2B - sp78[var_s3 - 1].unk_1) << 2;

            for (var_s2 = 7; var_s2 < ARRAY_COUNT(gTheGame.unk_8C88); var_s2++) {
                gTheGame.unk_8C88[var_s2].b.frameX = (0xB2 - sp78[var_s3 - 1].unk_0) << 2;
                gTheGame.unk_8C88[var_s2].b.frameY = (0x2B - sp78[var_s3 - 1].unk_1) << 2;
            }
        }

        for (var_s2 = 0; var_s2 < 6; var_s2++) {
            InitTetrisState(&gTheGame.tetrisWell[0].block[0][var_s2]);
            gTheGame.tetrisWell[0].unk_3830[0][var_s2].s.objX = sp98[var_s2] << 2;
            gTheGame.tetrisWell[0].unk_3830[0][var_s2].s.objY = -(20 << 2);
            gTheGame.tetrisWell[0].block[0][var_s2].delay = sp98[var_s2];
        }
    }

    gTheGame.tetrisWell[0].unk_43EC = 0;
    gTheGame.tetrisWell[0].unk_43FC = 0;
    gWhatever = 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", InitBonus);
#endif
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/bonus", RO_800C47E0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/bonus", RO_800C47F0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/bonus", RO_800C4840_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/bonus", RO_800C4860_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/bonus", RO_800C4868_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/bonus", RO_800C48E8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bonus", InitBonus);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/bonus", RO_800C2E90_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/bonus", RO_800C2EA0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/bonus", RO_800C2EF0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/bonus", RO_800C2F10_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/bonus", RO_800C2F18_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/bonus", RO_800C2F98_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bonus", InitBonus);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/bonus", RO_800B9E50_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/bonus", RO_800B9E60_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/bonus", RO_800B9EB0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/bonus", RO_800B9ED0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/bonus", RO_800B9ED8_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/bonus", RO_800B9F58_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bonus", InitBonus);
#endif

typedef struct struct_800C4660_usa {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x4 */ UNK_TYPE4 unk_4;
} struct_800C4660_usa; // size = 0x8

typedef struct struct_800C48A8_usa {
    /* 0x0 */ u16 unk_0;
    /* 0x2 */ u16 unk_2;
} struct_800C48A8_usa; // size = 0x4

void DoBonus(void) {
    s32 var_s5 = 0;
    char sp10[8];
    struct_800C4660_usa sp18[] = {
        { 2, 120 },  { 4, 118 },  { 6, 117 },  { 8, 115 },  { 10, 114 }, { 12, 113 }, { 14, 112 }, { 16, 111 },
        { 18, 110 }, { 20, 110 }, { 22, 109 }, { 24, 109 }, { 26, 108 }, { 28, 108 }, { 30, 108 }, { 30, 108 },
        { 32, 109 }, { 34, 110 }, { 36, 111 }, { 38, 112 }, { 40, 114 }, { 42, 116 }, { 44, 118 }, { 46, 120 },
        { 48, 122 }, { 50, 124 }, { 52, 127 }, { 54, 130 }, { 56, 133 }, { 58, 136 }, { 60, 140 }, { 62, 144 },
        { 64, 149 }, { 66, 154 }, { 68, 159 }, { 70, 164 }, { 71, 169 }, { 73, 174 }, { 75, 180 }, { 76, 186 },
        { 77, 192 }, { 78, 198 }, { 79, 204 }, { 80, 210 }, { 81, 216 }, { 82, 222 }, { 83, 228 }, { 83, 234 },
        { 84, 240 }, { 85, 246 }, { 86, 252 }, { 87, 258 }, { 88, 264 }, { 88, 270 }, { 89, 276 }, { 90, 282 },
        { 91, 286 },
    };
    s32 sp1E0[] = {
        2, 5,  8,  11, 14,  16,  18,  19,  19,  19,  18,  16,  14,  11,  8,   5,
        2, -1, -5, -9, -13, -18, -23, -28, -34, -40, -46, -52, -59, -66, -73, -80,
    };
    struct_800C48A8_usa sp260[] UNUSED = {
        { 0xF81D, 0xF01B }, { 0xE019, 0xC817 }, { 0xB815, 0xA813 }, { 0xB815, 0xC817 }, { 0xE019, 0xF01B },
    };
    tetWell *var_s2;
    s32 i;

    gTheGame.unk_90C0 = 6;

    for (i = ARRAY_COUNT(gTheGame.drawText) - 1; i >= 0; i--) {
        gTheGame.drawText[i].texture = (u32)-1;
    }

    var_s2 = &gTheGame.tetrisWell[0];

    if (gSelection == 0x96) {
        s32 var_a0;
        s32 var_s3;
        s32 t0;

        if (gWhatever == 0) {
            t0 = DoGameOverTryAgain();
        }

        if ((t0 != 0) || (gWhatever != 0)) {
            if (gWhatever == 0) {
                if (gTheGame.unk_9C24 == 0) {
                    char *var_s0;

                    switch (gTheGame.menu[0].unk_0) {
                        case 0x1:
                            var_s0 = &gPlayer[0]->unk_0E0;
                            break;
                        case 0x2:
                            var_s0 = &gPlayer[0]->unk_0E1;
                            break;
                        case 0x3:
                            var_s0 = &gPlayer[0]->unk_0E2;
                            break;
                        case 0x4:
                            var_s0 = &gPlayer[0]->unk_0E3;
                            break;
                        case 0x5:
                            var_s0 = &gPlayer[0]->unk_0E4;
                            break;
                    }

                    if (gTheGame.menu[0].unk_8 < 0x63) {
                        gTheGame.menu[0].unk_8++;
                    }

                    if (*var_s0 < 0x63) {
                        *var_s0 += 1;
                    }
                }
            }

            gWhatever++;
            if (gWhatever >= 0x14) {
                gReset = -1;
                if (gTheGame.unk_9C24 == 0) {
                    gMain = GMAIN_384;
                    SaveRom();
                    if (gTheGame.menu[0].unk_4 == 0x12) {
                        gTheGame.menu[0].unk_4 = 0x13;
                        gMain = GMAIN_STORY;
                    }
                } else {
                    gMain = GMAIN_258;
                }
            }
        }

        if (var_s2->unk_43FC >= 0) {
            var_s5 = gameoverBounce[var_s2->unk_43FC];
            var_s2->unk_43FC--;
        } else {
            var_s2->unk_43FC = 0x27;
        }

        var_a0 = gTheGame.unk_8C88[1].b.frameY >> 0x2;
        gTheGame.unk_8C88[1].b.frameY = (var_a0 - var_s5) << 2;

        for (var_s3 = 0; var_s3 < BLOCK_LEN_B / 3; var_s3++) {
            if (var_s2->block[0][var_s3].type == BLOCKTYPE_0) {
                s32 temp_ret = AnimationRandom(500);

                if (temp_ret == ((temp_ret / 21) * 0x15)) {
                    var_s2->block[0][var_s3].type = RandomBlock(var_s2);
                    Init2DTetrisTMEM(&var_s2->block[0][var_s3], &var_s2->unk_3830[0][var_s3]);
                    var_s2->unk_3830[0][var_s3].s.objX = var_s2->block[0][var_s3].delay * 4;
                }
            } else {
                var_a0 = var_s2->unk_3830[0][var_s3].s.objY >> 2;
                if (var_a0 < 0x28) {
                    var_a0 = var_a0 + 4;
                } else if (var_a0 < 0x32) {
                    var_a0 = var_a0 + 5;
                } else if (var_a0 < 0x82) {
                    var_a0 = var_a0 + 6;
                } else {
                    var_a0 = var_a0 + 7;
                }

                if (var_a0 >= 0xF0) {
                    var_a0 = -0x14;
                    var_s2->block[0][var_s3].type = BLOCKTYPE_0;
                    var_s2->block[0][var_s3].disappear = 0;
                }

                switch (var_s3) {
                    case 1:
                        if ((var_a0 >= 0x95) || (var_s2->block[0][1].disappear != 0)) {
                            var_a0 = (0x9B - sp1E0[var_s2->block[0][1].disappear++]);
                        }
                        break;

                    case 3:
                        if (var_a0 >= 0x46) {
                            if (var_s2->block[0][3].disappear == 0) {
                                var_s2->block[0][3].drop = 8;
                            }
                        }

                        if ((var_a0 >= 0x46) || (var_s2->block[0][3].disappear != 0)) {
                            s32 temp_v1_2;

                            if (var_s2->block[0][3].drop != 0) {
                                var_s2->block[0][3].drop--;
                            }

                            temp_v1_2 = var_s2->block[0][3].disappear;
                            var_s2->block[0][3].disappear++;
                            if (var_s2->block[0][3].disappear >= 2) {
                                t0 = temp_v1_2 - 1;

                                var_s2->unk_3830[0][3].s.objX = (sp18[t0].unk_0 + 0x5A) << 2;

                                var_a0 = (sp18[temp_v1_2 - 1].unk_4 - 0x35);
                            }
                        }
                        break;
                }

                var_s2->unk_3830[0][var_s3].s.objY = var_a0 << 2;
            }
        }

        sprintf(sp10, "%02d", gTheGame.menu[0].unk_8);
        SetText(0x103, 0x17, sp10, SETTEXTTYPE_17);
    } else if (DoWatchMenu() != 0) {
        gReset = -1;
        gMain = GMAIN_258;
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", DrawBonus);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bonus", DrawBonus);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bonus", DrawBonus);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bonus", DrawBonus);
#endif

s32 DoWatchMenu(void) {
    s32 ret = 0;
    s32 pad[2] UNUSED;

    if (gTheGame.controller[0].touch_button & (A_BUTTON | START_BUTTON)) {
        ret = 1;
    } else if (gTheGame.controller[0].touch_button & B_BUTTON) {
        ret = 2;
    }

    if (ret) {
        return ret;
    }
    return 0;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", func_800322D0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", func_80032318_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/bonus", RO_800C48DC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/bonus", RO_800C490C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/bonus", RO_800C4914_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", func_80032494_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bonus", func_80032300_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bonus", func_80032348_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/bonus", RO_800C4C2C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/bonus", RO_800C4C5C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/bonus", RO_800C4C64_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bonus", func_800324C4_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bonus", func_8003225C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bonus", func_800322A4_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/bonus", RO_800C32DC_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/bonus", RO_800C330C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/bonus", RO_800C3314_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bonus", func_80032420_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bonus", func_800323D0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bonus", func_80032418_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/bonus", RO_800BA29C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/bonus", RO_800BA2CC_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/bonus", RO_800BA2D4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bonus", func_80032594_ger);
#endif

void func_800325F8_usa(void) {
    void *heap = Pon_Image_Heap;

    LOAD_DATA_SEGMENT(heap, segment_0FB480, Pon_Image_Heap);

    B_8018EA00_usa = (void *)((uintptr_t)heap + 0x0000);
    B_8018EA08_usa = (void *)((uintptr_t)heap + 0x1800);
    B_8018EA04_usa = (void *)((uintptr_t)heap + 0x3300);
    B_8018EA0C_usa = (void *)((uintptr_t)heap + 0x4B00);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", DoCountDown);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bonus", DoCountDown);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bonus", DoCountDown);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bonus", DoCountDown);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", DrawCountDown);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bonus", DrawCountDown);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bonus", DrawCountDown);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bonus", DrawCountDown);
#endif

void InitStageClearIntro(void) {
    s32 pad[0x6] UNUSED;
    s16 sp38[12];
    s32 pad2[0xA] UNUSED;
    void *sp78;
    s32 var_a3;
    s32 var_s0;
    s32 temp;
    s32 a4;
    s32 a5;
    s32 temp2;

    if (B_801F9CFC_usa == 0) {
        func_80002D8C_usa(0x1E);
    }

    sp78 = &gBufferHeap[SEGMENT_ROM_SIZE(segment_0CA4A0)];
    B_8018EA10_usa = NULL;
    if ((gPlayer[0]->unk_02B.unk_0 & 0x1F) == 0x1F) {
        if (((gPlayer[0]->unk_02B.unk_1 & 0x1F) == 0x1F) && ((gPlayer[0]->unk_02B.unk_2 & 0x1F) == 0x1F) &&
            ((gPlayer[0]->unk_02B.unk_3 & 0x1F) == 0x00) && ((gPlayer[0]->unk_02B.unk_4 & 0x1F) == 0x00) &&
            ((gPlayer[0]->unk_02B.unk_5 & 0x1F) == 0x00)) {
            if (!(gPlayer[0]->unk_02B.unk_2 & 0x40)) {
                gTheGame.menu[0].unk_0 = 5;
                gPlayer[0]->unk_02B.unk_2 |= 0x40;
            } else if ((gTheGame.menu[0].unk_0 == 2) && (gTheGame.cursorBlock[0].unk_00 == 7)) {
                B_8018EA10_usa = "spaTR2.HVQM";
            }
        }

        if (((gPlayer[0]->unk_02B.unk_0 & 0x1F) == 0x1F) && ((gPlayer[0]->unk_02B.unk_1 & 0x1F) == 0x1F) &&
            ((gPlayer[0]->unk_02B.unk_2 & 0x1F) == 0x1F) && ((gPlayer[0]->unk_02B.unk_3 & 0x1F) == 0x1F) &&
            ((gPlayer[0]->unk_02B.unk_4 & 0x1F) == 0x1F)) {
            if (((gPlayer[0]->unk_02B.unk_5 & 0x1F) == (gPlayer[0]->unk_02B.unk_0 & 0x1F)) &&
                !(gPlayer[0]->unk_02B.unk_5 & 0x40)) {
                B_8018EA10_usa = "spaTR1.HVQM";
                gTheGame.menu[0].unk_0 = 5;
                gPlayer[0]->unk_02B.unk_5 |= 0x40;
            }
        }
    }

    if (gTheGame.menu[0].unk_0 == 5) {
        if (gTheGame.menu[0].unk_4 >= 5) {
            var_s0 = 7;
        } else {
            var_s0 = 6;
        }
    } else {
        var_s0 = gTheGame.menu[0].unk_4 - 1;
    }

    B_8018EA2C_usa = D_800B64E8_usa[var_s0][0];
    B_8018EA30_usa = D_800B64E8_usa[var_s0][1];
    B_8018EA34_usa = D_800B64F8_usa[var_s0][0];
    B_8018EA38_usa = D_800B64F8_usa[var_s0][1];

    DmaRomToRam(D_800B6528_usa[var_s0], sp38, sizeof(sp38));

    if (sp38[0] == 0x10) {
        var_a3 = 0x54;
    } else if (sp38[1] == 0) {
        var_a3 = 0x33;
    } else {
        var_a3 = 0x13;
    }
    a4 = sp38[2];
    a5 = sp38[3];
    temp = (a4 * a5 * 2);
    func_8001FD0C_usa(&B_8018EA24_usa, D_800B6528_usa[var_s0] + sizeof(sp38), 0, var_a3, a4, a5, &sp78);

    if (sp38[6] == 0x10) {
        var_a3 = 0x54;
    } else if (sp38[7] == 0) {
        var_a3 = 0x33;
    } else {
        var_a3 = 0x13;
    }
    a4 = sp38[8];
    a5 = sp38[9];
    temp2 = temp + sizeof(sp38);
    func_8001FD0C_usa(&B_8018EA28_usa, D_800B6528_usa[var_s0] + temp2, 0, var_a3, a4, a5, &sp78);
    func_8001FD0C_usa(&B_8018EA20_usa, D_800B6508_usa[var_s0], 0, 0x800054, 0x140, 0xE8, &sp78);

    gWhatever = gTheGame.unk_9C0C = (gTheGame.menu[0].unk_4 >= 4) ? 2 : 1;

    UpdatePlayerStageClearTimeScore(gTheGame.cursorBlock, -1, gTheGame.menu[0].unk_4, 1);

    gTheGame.unk_9C1C = 0;
    gTheGame.unk_9C18 = 0;
    gTheGame.unk_9C14 = 0;
    gCounter = 0;
    gTheGame.cursorBlock[0].unk_00 = 0;
    if (screenLoad("CLEAR.SBF", &sp78) != 0) {
        u32 x;

        gnTickClear = 0;
        if (B_8018EA10_usa != NULL) {
            x = 0xFF001;
        } else {
            x = 0x1;
        }
        giScreenClear = screenSet("CLEAR", x | 0x400);

        screenSetNumber(giScreenClear, 0x32, gTheGame.tetrisWell[0].unk_43AC, -1);
        if (gTheGame.menu[0].unk_0 == 5) {
            if (gTheGame.menu[0].unk_4 < 5) {
                gnTagTextClear = -0xC8;
                screenShowText(giScreenClear, 0x19A);
            } else {
                gnTagTextClear = -0xFA;
                screenShowText(giScreenClear, 0x1A4);
            }
        } else {
            gnTagTextClear = -(((gTheGame.menu[0].unk_4 - 1) * 0xA) + 0x64);
            screenShowText(giScreenClear, gTheGame.menu[0].unk_4 + 0x18F);
        }
    }

    if (B_801F9CFC_usa == 0) {
        PlayMIDI(BGM_INIT_TABLE, 0x14, 0, 1);
    }

    B_801F9CFC_usa = 0;
}

void DoStageClearIntro(void) {
    screenTick_arg0 sp10 = { 0, 0 };
    s32 var_s1 = 0;
    void *heap;
    u32 sp1C;
    struct_imageLoad_arg0 *sp20;
    s32 sp24;
    s32 sp28;
    s32 var_s0;

    gTheGame.unk_9C08 = 1;
    screenTick(&sp10);

    if (B_8018EA10_usa != NULL) {
        if (!screenFlushing() && !func_80024C14_usa() && func_80024BF4_usa(&heap)) {
            HVQM2Util_Play((File *)B_8018EA10_usa, 0x1000U, heap);
            B_8018EA10_usa = NULL;
        }
        return;
    }

    if (gnTagTextClear != -1) {
        B_8018EA3C_usa = 0;
        B_8018EA40_usa = 0;
        if ((gnTagTextClear < 0) || screenTextDone(giScreenClear, gnTagTextClear)) {
            if (screenTextDone(giScreenClear, gnTagTextClear)) {
                if (screenGetTextType(giScreenClear, gnTagTextClear + 1, &sp1C)) {
                    screenShowImage(giScreenClear, 0x79);
                } else if (gnTagTextClear > 0) {
                    gnTagTextClear = -1;
                }
            }

            gnTickClear++;

            if (((gnTagTextClear < 0) && (gnTickClear >= 0xF0)) || ((gnTagTextClear >= 0) && (gnTickClear >= 0x708))) {
                gnTickClear = 0;
                screenHideImage(giScreenClear, 0x79);
                if (gnTagTextClear < 0) {
                    gnTagTextClear = -gnTagTextClear;
                    screenShowText(giScreenClear, gnTagTextClear);
                    screenHideText(giScreenClear, 0x81A48190);
                } else if (screenGetTextType(giScreenClear, gnTagTextClear + 1, &sp1C)) {
                    screenHideText(giScreenClear, gnTagTextClear);
                    gnTagTextClear = gnTagTextClear + 1;
                    screenShowText(giScreenClear, gnTagTextClear);
                } else {
                    gnTagTextClear = -1;
                }
            } else {
                if (gTheGame.controller[0].touch_button & A_BUTTON) {
                    gnTickClear = 0x708;
                }
            }
        } else if (gTheGame.controller[0].touch_button & A_BUTTON) {
            func_80027AD4_usa();
        }
    } else {
        switch (B_8018EA40_usa) {
            case 0x0:
                if (gTheGame.controller[0].touch_button & A_BUTTON) {
                    B_8018EA40_usa = 1;
                    screenHideImage(giScreenClear, 0x79);
                    screenHideImage(giScreenClear, 0x1F4);
                    screenHideText(giScreenClear, 0x812B8064);
                }
                break;

            case 0x1:
                if (func_8002864C_usa(giScreenClear, 0x78, &sp20)) {
                    if (sp20->unk_14 > 0) {
                        sp20->unk_14 -= 4;
                        if (sp20->unk_14 <= 0) {
                            PlaySE(SFX_INIT_TABLE, 0xA4);
                            B_8018EA40_usa = 2;
                            sp20->unk_14 = 0;
                        }
                    }
                }
                break;

            case 0x2:
                B_8018EA3C_usa += 6;
                if (B_8018EA3C_usa > 0x80) {
                    PlaySE(SFX_INIT_TABLE, 0xA4);
                    B_8018EA40_usa = 3;
                    screenHideImage(giScreenClear, 0x83);
                    screenHideImage(giScreenClear, 0x8D);
                }
                screenHideText(giScreenClear, 0x32);
                screenSetImagePosition(giScreenClear, 0x83, -B_8018EA3C_usa, 0x25);
                screenSetImagePosition(giScreenClear, 0x8D, B_8018EA3C_usa + 0xB8, 0x7F);
                break;

            case 0x3:
                var_s0 = 0;
                if ((func_800289C0_usa(giScreenClear, 0x6E, &sp24, &sp28) != 0) && (sp28 >= -0x99)) {
                    var_s0 = -1;
                    screenSetImagePosition(giScreenClear, 0x6E, sp24, sp28 - 6);
                }
                if ((func_800289C0_usa(giScreenClear, 0x6F, &sp24, &sp28) != 0) && (sp28 < 0xF1)) {
                    var_s0 = -1;
                    screenSetImagePosition(giScreenClear, 0x6F, sp24, sp28 + 4);
                }
                if (var_s0 == 0) {
                    B_8018EA40_usa = 4;
                }
                break;

            case 0x4:
                var_s1 = -1;
                break;
        }
    }

    if (gCounter >= 0x1F) {
        if ((var_s1 != 0) || (gTheGame.controller[0].touch_button & START_BUTTON)) {
            PlaySE(SFX_INIT_TABLE, 4);
            if (B_8018EA40_usa == 0) {
                B_8018EA40_usa = 1;
                gnTagTextClear = -1;
                screenHideImage(giScreenClear, 0x79);
                screenHideImage(giScreenClear, 0x1F4);
                screenHideText(giScreenClear, 0x812B8064);
                screenHideText(giScreenClear, 0x81A48190);
            } else {
                gReset = -1;
                gMain = GMAIN_384;
                gTheGame.unk_9C0C = gWhatever;
                gWhatever = 0;
                FadeOutSong(last_song_handle, 0x5A);
            }
        } else if (gTheGame.controller[0].touch_button & B_BUTTON) {
            gReset = -1;
            gMain = GMAIN_2BC;
            PlaySE(SFX_INIT_TABLE, 6);
        }
    }

    if (!screenFlushing()) {
        peelTick();
    }
}

void func_80034140_usa(Gfx **gfxP, s32 arg1 UNUSED, s32 arg2) {
    struct_func_8002156C_usa_arg4 sp18;
    Gfx *gfx = *gfxP;

    switch (arg2) {
        case 0x64:
            if (B_8018EA40_usa >= 3U) {
                imageDraw(B_8018EA20_usa, &gfx, 0, 0, NULL);
            }
            break;

        case 0x82:
            if (B_8018EA40_usa < 3U) {
                sp18.unk_00 = B_8018EA2C_usa;
                sp18.unk_04 = B_8018EA30_usa;
                sp18.unk_08 = 0x70;
                sp18.unk_0C = 0x9C;
                imageDraw(B_8018EA24_usa, &gfx, -B_8018EA3C_usa, 0x2A, &sp18);
            }
            break;

        case 0x8C:
            if (B_8018EA40_usa < 3U) {
                sp18.unk_00 = B_8018EA34_usa;
                sp18.unk_04 = B_8018EA38_usa;
                sp18.unk_08 = 0x50;
                sp18.unk_0C = 0x54;
                imageDraw(B_8018EA28_usa, &gfx, B_8018EA3C_usa + 0xCB, 0x83, &sp18);
            }
            break;

        case 0x96:
            gDPPipeSync(gfx++);
            gDPSetCycleType(gfx++, G_CYC_FILL);
            gDPSetAlphaCompare(gfx++, G_AC_NONE);
            gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
            gSPClearGeometryMode(gfx++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_LIGHTING | G_SHADING_SMOOTH);
            gDPSetFillColor(gfx++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
            gDPFillRectangle(gfx++, 0, 0, SCREEN_WIDTH - 1, 6);
            break;
    }

    *gfxP = gfx;
}

void DrawStageClearIntro(struct_gInfo_unk_00068 *arg0 UNUSED) {
    screenDraw(&glistp, func_80034140_usa);
    if (!screenFlushing()) {
        pon_DrawLoadingMessage(&glistp);
    }
}
