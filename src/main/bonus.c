/**
 * Original filename: bonus.c
 */

#include "bonus.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "segment_symbols.h"
#include "sfxlimit.h"
#include "buffers.h"

typedef struct struct_800C4490_usa {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x0 */ UNK_TYPE4 unk_4;
    /* 0x0 */ UNK_TYPE4 unk_8;
    /* 0x0 */ UNK_TYPE4 unk_C;
} struct_800C4490_usa; // size = 0x10

typedef struct struct_800C44A0_usa {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x0 */ UNK_TYPE4 unk_4;
    /* 0x0 */ UNK_TYPE4 unk_8;
    /* 0x0 */ UNK_TYPE4 unk_C;
} struct_800C44A0_usa; // size = 0x10

typedef struct struct_800C44F0_usa {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 unk_1;
} struct_800C44F0_usa; // size = 0x2





extern u8 B_801C6C90_usa;
extern s32 B_8021BA5C_usa;
extern u32 D_101A80[];
extern u32 D_1030FE0[];
extern u32 D_104C660[];
extern u32 D_105B710[];
extern u32 D_1070A60[];
extern u32 D_12C1B0[];
extern u32 D_50F3F0[];
extern u32 D_5337F0[];
extern u32 D_CA4A0[];
extern u32 D_FB480[];
extern void *Pon_Image_Heap;

typedef struct struct_8004EC4C_usa_arg2 {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x0 */ UNK_TYPE1 unk_4[0x4];
} struct_8004EC4C_usa_arg2; // size = 0x8

typedef struct struct_8004EC4C_usa_arg3 {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x0 */ UNK_TYPE1 unk_4[0x4];
} struct_8004EC4C_usa_arg3; // size = 0x8

#if VERSION_USA
#if 0
// ? func_800547E0_usa(TheGame *);                     /* extern */
// ? func_80073C20_usa(?, ?, s32, s32);                /* extern */
// ? func_80073D10_usa(?, ?, s32, s32);                /* extern */
// ? func_80073E00_usa(?, ?, s32, s32);                /* extern */
// ? func_80073EF0_usa(?, ?, s32, s32);                /* extern */
// ? func_80073FE0_usa(?, ?, s32, s32);                /* extern */
// ? func_800740D0_usa(?, ?, s32, s32);                /* extern */
// ? func_800741C0_usa(?, ?, s32, s32);                /* extern */
// ? func_800742B0_usa(?, ?, s32, s32);                /* extern */
// ? func_800743A0_usa(?, ?, s32, s32);                /* extern */
// ? func_80074490_usa(?, ?, s32, s32);                /* extern */
// ? func_80074580_usa(?, ?, s32, s32);                /* extern */
// ? func_80074670_usa(?, ?, s32, s32);                /* extern */
// ? func_80074760_usa(?, ?, s32, s32);                /* extern */
// ? func_80074850_usa(?, ?, s32, s32);                /* extern */
// ? func_80074940_usa(?, ?, s32, s32);                /* extern */


extern const struct_800C44A0_usa RO_800C44A0_usa[];
extern const struct_800C44F0_usa RO_800C44F0_usa[0xF];
extern const UNK_TYPE RO_800C4510_usa[2];
extern const UNK_TYPE RO_800C4518_usa[0x20];
extern const UNK_TYPE RO_800C4598_usa[0x20];


void InitBonus(void) {
    struct_800C4490_usa sp10[] = { 0x40, 0x3E, 0x40, 0x45 };
    s32 sp20[] = {0xF8, 0x100};
    struct_800C44A0_usa sp28[] = {
    {0xC0,
    0x2F,
    0x13,
    0x21},
    {0x40,
    0x1D,
    0xB6,
    0xBA},
    {0x40,
    0x1D,
    0xB6,
    0xBA},
    {0x40,
    0x1D,
    0xE1,
    0xBA},
    {0x40,
    0x1D,
    0xE1,
    0xBA},
};
    struct_800C44F0_usa sp78[] = {
    {0x00, 0x07}, {0x01, 0x01},
    {0x02, 0x00}, {0x02, 0x02},
    {0x05, 0x04}, {0x0C, 0x02},
    {0x02, 0x02}, {0x09, 0x06},
    {0x02, 0x05}, {0x00, 0x00},
    {0x07, 0x06}, {0x04, 0x04},
    {0x02, 0x03}, {0x05, 0x03},
    {0x05, 0x09},
};

    u8 sp98[] = {0x1D, 0x30, 0x43, 0x56, 0x69, 0x7C,};
    s8 sp9C;
    s8 sp9D;
    UNK_TYPE spA0;
    struct_8004EC4C_usa_arg2 spA4[UNK_SIZE];
    UNK_TYPE sp120;
    struct_8004EC4C_usa_arg3 sp124[UNK_SIZE];
    struct_800C44A0_usa *var_a3;
    UNK_TYPE *var_a3_2;
    UNK_TYPE *var_a3_3;
    UNK_TYPE *var_s1_2;
    struct_800C44F0_usa *temp_v0_18;
    s32 *var_a0_2;
    struct_800C44A0_usa *var_a2;
    s32 *var_a2_2;
    s32 *var_a2_3;
    s32 *var_s1;
    s32 temp_s3;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_a0_3;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s2_4;
    s32 var_s2_5;
    s32 var_s3;
    s32 var_s3_2;
    s32 var_s3_3;
    uObjBg *temp_s1;
    uObjBg *var_a0;
    TheGame_unk_8B98 *var_v1;
    u32 temp_s0;
    u32 temp_s0_2;
    void *temp_v0;
    u8 *var_s1_3;
    uObjBg *var_s0;
    void *temp_s4;

    var_a3_2 = &spA0;
    var_a2_2 = RO_800C4518_usa;

    #if 0
    do {
        var_a3_2->unk_0 = (s32) var_a2_2->unk_0;
        var_a3_2->unk_4 = (s32) var_a2_2->unk_4;
        var_a3_2->unk_8 = (s32) var_a2_2->unk_8;
        var_a3_2->unk_C = (s32) var_a2_2->unk_C;
        var_a2_2 += 0x10;
        var_a3_2 += 0x10;
    } while (var_a2_2 != (RO_800C4518_usa + 0x80));
    #endif

    var_a3_3 = &sp120;
    var_a2_3 = RO_800C4598_usa;

    #if 0
    do {
        var_a3_3->unk_0 = (s32) var_a2_3->unk_0;
        var_a3_3->unk_4 = (s32) var_a2_3->unk_4;
        var_a3_3->unk_8 = (s32) var_a2_3->unk_8;
        var_a3_3->unk_C = (s32) var_a2_3->unk_C;
        var_a2_3 += 0x10;
        var_a3_3 += 0x10;
    } while (var_a2_3 != (RO_800C4598_usa + 0x80));
    #endif

    temp_v0 = &gBufferHeap[SEGMENT_ROM_SIZE(segment_0CA4A0)];
    gCounter = 0;
    Pon_Image_Heap = temp_v0;
    osInvalDCache(D_1030FE0, D_105B710 - D_1030FE0);
    temp_s0 = D_12C1B0 - D_101A80;
    func_80001310_usa((u32) D_101A80, temp_v0, temp_s0);
    Pon_Image_Heap += temp_s0;
    if ((gSelection == 0x96) && (gTheGame.unk_8860[0].unk_00 != 7) && (gTheGame.unk_8860[1].unk_00 != 8) && (B_801C6C90_usa == 0x10)) {
        PlayMIDI(BGM_INIT_TABLE, 0x20, 0, 1);
    }
    gTheGame.unk_9A50.b.imagePtr = temp_v0;
    guS2DInitBg(&gTheGame.unk_9A50);
    var_s2 = 0;
    var_s3 = 0x24400;
    var_s1 = &sp10;
    var_a0 = &gTheGame.unk_8C88[0];
    while (var_s2 < 1) {
        var_a0->b.imageX = 0;
        var_a0->b.imageW = (s16) (var_s1[0x0/4] * 4);
        var_a0->b.frameX = (s16) (var_s1[0x8/4] * 4);
        var_a0->b.imageY = 0;
        var_a0->b.frameW = (s16) (var_s1[0x0/4] * 4);
        var_a0->b.imageH = (s16) (var_s1[0x4/4] * 4);
        var_a0->b.frameY = (s16) (var_s1[0xC/4] * 4);
        var_a0->b.imagePtr = &temp_v0[var_s3];
        var_a0->b.imageLoad = 0xFFF4;
        var_a0->b.imageFmt = 0;
        var_a0->b.imageSiz = 2;
        var_a0->b.imagePal = 0;
        var_a0->b.imageFlip = 0;
        var_a0->b.frameH = (s16) (var_s1[0x4/4] * 4);

        guS2DInitBg(var_a0);

        temp_v1 = var_s1[0x0/4] * var_s1[0x4/4];

        var_s2 += 1;
        var_s1 += 0x10;
        var_a0 += 0x28;
        var_s3 += temp_v1 * 2;
    }

    var_s3_2 = 0x26300;
    var_s2_2 = 0;
    var_v1 = &gTheGame.unk_8B98[0];
    while (var_s2_2 < 2) {
        var_v1[var_s2_2].unk_00 = 0x30;
        var_v1[var_s2_2].unk_04 = &temp_v0[var_s3_2];
        var_v1[var_s2_2].unk_08 = 0x100;
        var_v1[var_s2_2].unk_0C = 0;
        var_v1[var_s2_2].unk_0E = 0;
        var_v1[var_s2_2].unk_10 = -1;
        var_v1[var_s2_2].unk_14 = 0;
        var_v1[var_s2_2].unk_0A = (s16) (sp20[var_s2_2] - 1);
        temp_v0_2 = sp20[var_s2_2];
        var_s3_2 += temp_v0_2 * 2;
        var_s2_2 += 1;
    }

    var_s2_3 = 0;
    var_s1_2 = &sp28;
    var_s0 = &gTheGame.unk_8C88[1];
    while (var_s2_3 < 5) {
        var_s0[var_s2_3].b.imageX = 0;
        var_s0[var_s2_3].b.imageW = sp28[var_s2_3].unk_0 * 4;
        var_s0[var_s2_3].b.frameX = sp28[var_s2_3].unk_8 * 4;
        var_s0[var_s2_3].b.imageY = 0;
        var_s0[var_s2_3].b.frameW = sp28[var_s2_3].unk_0 * 4;
        var_s0[var_s2_3].b.imageH = sp28[var_s2_3].unk_4 * 4;
        var_s0[var_s2_3].b.frameY = sp28[var_s2_3].unk_C * 4;
        var_s0[var_s2_3].b.imagePtr = &temp_v0[var_s3_2];
        var_s0[var_s2_3].b.imageLoad = 0xFFF4;
        var_s0[var_s2_3].b.imageFmt = 2;
        var_s0[var_s2_3].b.imageSiz = 1;
        var_s0[var_s2_3].b.imagePal = 0;
        var_s0[var_s2_3].b.imageFlip = 0;
        var_s0[var_s2_3].b.frameH = sp28[var_s2_3].unk_4 * 4;
        guS2DInitBg(&var_s0[var_s2_3]);
        var_s3_2 += sp28[var_s2_3].unk_0 * sp28[var_s2_3].unk_4;
        var_s2_3 += 1;
    }



    if (gSelection == 0x96) {
        temp_s3 = gTheGame.unk_0000[1].unk_4424;
        switch (temp_s3) {
            case 0x1:
                func_80073C20_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;

            case 0x2:
                func_80073D10_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0x3:
                func_80073E00_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0x4:
                func_80073EF0_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0x5:
                func_80073FE0_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0x6:
                func_800740D0_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0x7:
                func_800741C0_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0x8:
                func_800742B0_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0x9:
                func_800743A0_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0xA:
                func_80074490_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0xB:
                func_80074580_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0xC:
                func_80074670_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0xD:
                func_80074760_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0xE:
                func_80074850_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;
            case 0xF:
            case 0x12:
                func_80074940_usa(0, 0, spA4[temp_s3].unk_0, sp124[temp_s3].unk_0);
                break;

            case 0x10:
                temp_s4 = Pon_Image_Heap;
                osInvalDCache(D_104C660, D_1070A60 - D_104C660);
                func_80001310_usa((u32) D_50F3F0, temp_s4, (RomOffset)D_5337F0 - (RomOffset)D_50F3F0);
                Pon_Image_Heap += (RomOffset)D_5337F0 - (RomOffset)D_50F3F0;
                bcopy(&gTheGame.unk_9A50, &gTheGame.unk_8C88[6], sizeof(uObjBg));
                gTheGame.unk_8C88[6].b.imagePtr = temp_s4;
                guS2DInitBg(&gTheGame.unk_8C88[6]);
                break;

            default:
                break;
        }

        if (temp_s3 == 0x10) {
            gTheGame.unk_8C88[6].b.frameX = -0x2C;
            gTheGame.unk_8C88[6].b.frameY = 0x44;
        } else {
            temp_v0_18 = &sp78[temp_s3 - 1];
            gTheGame.unk_8C88[6].b.frameX = (0xB2 - temp_v0_18->unk_0) * 4;
            gTheGame.unk_8C88[6].b.frameY = (sp124[temp_s3].unk_0 - (temp_v0_18->unk_1 - 0x2B)) * 4;
            var_s2_4 = 7;
            do {
                gTheGame.unk_8C88[var_s2_4].b.frameX = (0xB2 - temp_v0_18->unk_0) * 4;
                gTheGame.unk_8C88[var_s2_4].b.frameY = (0x2B - temp_v0_18->unk_1) * 4;
                var_s2_4 += 1;
            } while (var_s2_4 < 0xA);
        }

        var_s2_5 = 0;
        while (var_s2_5 < 6) {
            func_800547E0_usa(&gTheGame.unk_0000[0].unk_0000.unk_0000->unk_000[var_s2_5]);
            gTheGame.unk_0000[0].unk_3830.unk_000[var_s2_5].unk_08 = -0x50;
            gTheGame.unk_0000[0].unk_3830.unk_000[var_s2_5].unk_00 = (s16) (sp98[var_s2_5] * 4);
            gTheGame.unk_0000[0].unk_0000.unk_0000[0].unk_000[var_s2_5].unk_04 = (s32) sp98[var_s2_5];
            var_s2_5 += 1;
        }
    }

    gTheGame.unk_0000[0].unk_43EC = 0;
    gTheGame.unk_0000[0].unk_43FC = 0;
    B_8021BA5C_usa = 0;
}
#else

const struct_800C4490_usa RO_800C4490_usa[] = { 0x40, 0x3E, 0x40, 0x45 };

const struct_800C44A0_usa RO_800C44A0_usa[] = {
    {0xC0,
    0x2F,
    0x13,
    0x21},
    {0x40,
    0x1D,
    0xB6,
    0xBA},
    {0x40,
    0x1D,
    0xB6,
    0xBA},
    {0x40,
    0x1D,
    0xE1,
    0xBA},
    {0x40,
    0x1D,
    0xE1,
    0xBA},
};

const struct_800C44F0_usa RO_800C44F0_usa[0xF] = {
    {0x00, 0x07}, {0x01, 0x01},
    {0x02, 0x00}, {0x02, 0x02},
    {0x05, 0x04}, {0x0C, 0x02},
    {0x02, 0x02}, {0x09, 0x06},
    {0x02, 0x05}, {0x00, 0x00},
    {0x07, 0x06}, {0x04, 0x04},
    {0x02, 0x03}, {0x05, 0x03},
    {0x05, 0x09},
};

const UNK_TYPE RO_800C4510_usa[2] = { 0x1D304356, 0x697C0000 };
const UNK_TYPE RO_800C4518_usa[0x20] = {
    0xC0,
    0x81,
    0xC0,
    0x87,
    0xC0,
    0x74,
    0xC0,
    0x7E,
    0xC0,
    0x79,
    0xC0,
    0x7A,
    0xC0,
    0x6F,
    0xC0,
    0x6B,
    0xC0,
    0x65,
    0xC0,
    0x6F,
    0xC0,
    0x2F,
    0xC0,
    0x6F,
    0xC0,
    0x74,
    0xC0,
    0x65,
    0xC0,
    0,
    0xC0,
    0x5D,
};
const UNK_TYPE RO_800C4598_usa[0x20] = {
    0x00000041,
    0x0000003F,
    0x0000003F,
    0x00000039,
    0x00000042,
    0x0000004C,
    0x00000047,
    0x00000042,
    0x00000065,
    0x00000047,
    0x0000004E,
    0x00000046,
    0x0000007E,
    0x00000051,
    0x0000004F,
    0x00000055,
    0x0000005D,
    0x0000005B,
    0x00000057,
    0x00000051,
    0x000000AC,
    0x00000091,
    0x00000055,
    0x00000051,
    0x00000050,
    0x0000004C,
    0x00000071,
    0x0000005B,
    0x000000C0,
    0x000000C0,
    0x0000005F,
    0x00000063,
};

INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", InitBonus);
#endif
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/bonus", RO_800C4660_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/bonus", RO_800C4828_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/bonus", RO_800C48A8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", DoBonus);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", DrawBonus);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", func_8003228C_usa);
#endif

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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", func_800325F8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", DoCountDown);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", DrawCountDown);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", InitStageClearIntro);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", DoStageClearIntro);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", func_80034140_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", DrawStageClearIntro);
#endif
