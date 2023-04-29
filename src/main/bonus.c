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

extern u8 B_801C6C90_usa;
extern s32 gWhatever;
extern u32 D_1030FE0[];
extern u32 D_104C660[];
extern u32 D_105B710[];
extern u32 D_1070A60[];
extern void *Pon_Image_Heap;

typedef struct struct_8004EC4C_usa_arg2 {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x0 */ UNK_TYPE1 unk_4[0x4];
} struct_8004EC4C_usa_arg2; // size = 0x8

typedef struct struct_8004EC4C_usa_arg3 {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x0 */ UNK_TYPE1 unk_4[0x4];
} struct_8004EC4C_usa_arg3; // size = 0x8

void func_80073C20_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80073D10_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80073E00_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80073EF0_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80073FE0_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800740D0_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800741C0_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800742B0_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_800743A0_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80074490_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80074580_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80074670_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80074760_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80074850_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80074940_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

#if VERSION_USA
#ifdef NON_EQUIVALENT
void InitBonus(void) {
    struct_800C4490_usa sp10[] = { 0x40, 0x3E, 0x40, 0x45 };
    s32 sp20[] = { 0xF8, 0x100 };
    struct_800C4490_usa sp28[] = {
        { 0xC0, 0x2F, 0x13, 0x21 }, { 0x40, 0x1D, 0xB6, 0xBA }, { 0x40, 0x1D, 0xB6, 0xBA },
        { 0x40, 0x1D, 0xE1, 0xBA }, { 0x40, 0x1D, 0xE1, 0xBA },
    };
    struct_800C44F0_usa sp78[] = {
        { 0x00, 0x07 }, { 0x01, 0x01 }, { 0x02, 0x00 }, { 0x02, 0x02 }, { 0x05, 0x04 },
        { 0x0C, 0x02 }, { 0x02, 0x02 }, { 0x09, 0x06 }, { 0x02, 0x05 }, { 0x00, 0x00 },
        { 0x07, 0x06 }, { 0x04, 0x04 }, { 0x02, 0x03 }, { 0x05, 0x03 }, { 0x05, 0x09 },
    };
    u8 sp98[] = {
        0x1D, 0x30, 0x43, 0x56, 0x69, 0x7C,
    };
    struct_800C4518_usa spA0[] = {
        { 0xC0, 0x81 }, { 0xC0, 0x87 }, { 0xC0, 0x74 }, { 0xC0, 0x7E }, { 0xC0, 0x79 }, { 0xC0, 0x7A },
        { 0xC0, 0x6F }, { 0xC0, 0x6B }, { 0xC0, 0x65 }, { 0xC0, 0x6F }, { 0xC0, 0x2F }, { 0xC0, 0x6F },
        { 0xC0, 0x74 }, { 0xC0, 0x65 }, { 0xC0, 0 },    { 0xC0, 0x5D },
    };
    struct_800C4598_usa sp120[] = {
        { 0x00000041, 0x0000003F }, { 0x0000003F, 0x00000039 }, { 0x00000042, 0x0000004C }, { 0x00000047, 0x00000042 },
        { 0x00000065, 0x00000047 }, { 0x0000004E, 0x00000046 }, { 0x0000007E, 0x00000051 }, { 0x0000004F, 0x00000055 },
        { 0x0000005D, 0x0000005B }, { 0x00000057, 0x00000051 }, { 0x000000AC, 0x00000091 }, { 0x00000055, 0x00000051 },
        { 0x00000050, 0x0000004C }, { 0x00000071, 0x0000005B }, { 0x000000C0, 0x000000C0 }, { 0x0000005F, 0x00000063 },
    };
    s32 temp_s3;
    s32 var_s2;
    s32 var_s3;
    uObjBg *var_a0;
    TheGame_unk_8B98 *var_v1;
    void *temp_v0;
    uObjBg *var_s0;
    void *temp_s4;
    s32 s3 = 0;
    s32 s5 = 1;
    s32 s8 = 2;
    s32 new_var;
    uObjBg *temp;

    gCounter = 0;
    temp_v0 = &gBufferHeap[SEGMENT_ROM_SIZE(segment_0CA4A0)];
    new_var = 5;
    Pon_Image_Heap = temp_v0;
    osInvalDCache((void *)D_1030FE0, (u32)D_105B710 - (u32)D_1030FE0);
    func_80001310_usa(SEGMENT_ROM_START(segment_101A80), temp_v0, SEGMENT_ROM_SIZE(segment_101A80));
    Pon_Image_Heap += SEGMENT_ROM_SIZE(segment_101A80);
    if ((gSelection == 0x96) && (gTheGame.unk_8860[0].unk_00 != 7) && (gTheGame.unk_8860[1].unk_00 != 8) &&
        (B_801C6C90_usa == 0x10)) {
        PlayMIDI(BGM_INIT_TABLE, 0x20, 0, 1);
    }
    temp_v0 += s3;
    gTheGame.unk_9A50.b.imagePtr = temp_v0;

    guS2DInitBg(&gTheGame.unk_9A50);

    var_s3 = 0x24400;

    for (var_s2 = 0; var_s2 < s5; var_s2++) {
        var_a0 = &gTheGame.unk_8C88[var_s2 + 0];

        var_a0->b.imageX = 0;
        var_a0->b.imageW = sp10[var_s2].unk_0 << 2;
        var_a0->b.frameX = sp10[var_s2].unk_8 << 2;
        var_a0->b.frameW = sp10[var_s2].unk_0 << 2;

        var_a0->b.imageY = 0;
        var_a0->b.imageH = sp10[var_s2].unk_4 << 2;
        var_a0->b.frameY = sp10[var_s2].unk_C << 2;
        var_a0->b.frameH = sp10[var_s2].unk_4 << 2;

        var_a0->b.imagePtr = &temp_v0[var_s3];
        var_a0->b.imageLoad = G_BGLT_LOADTILE;
        var_a0->b.imageFmt = G_IM_FMT_RGBA;
        var_a0->b.imageSiz = G_IM_SIZ_16b;
        var_a0->b.imagePal = 0;
        var_a0->b.imageFlip = 0;

        guS2DInitBg(var_a0);

        var_s3 += sp10[var_s2].unk_0 * sp10[var_s2].unk_4 * 2;
    }

    var_s3 = 0x26300;
    var_s2 = 0;
    var_v1 = &gTheGame.unk_8B98[0];
    while (var_s2 < s8) {
        var_v1[var_s2].unk_00 = 0x30;
        var_v1[var_s2].unk_04 = &temp_v0[var_s3];
        var_v1[var_s2].unk_08 = 0x100;
        var_v1[var_s2].unk_0A = (s16)(sp20[var_s2] - 1);
        var_v1[var_s2].unk_0C = 0;
        var_v1[var_s2].unk_0E = 0;
        var_v1[var_s2].unk_10 = -1;
        var_v1[var_s2].unk_14 = 0;
        var_s3 += sp20[var_s2] * 2;
        var_s2 += 1;
    }

    for (var_s2 = 0; var_s2 < new_var; var_s2++) {
        var_s0 = &gTheGame.unk_8C88[var_s2 + 1];

        var_s0->b.imageX = 0;
        var_s0->b.imageW = sp28[var_s2].unk_0 << 2;
        var_s0->b.frameX = sp28[var_s2].unk_8 << 2;
        var_s0->b.frameW = sp28[var_s2].unk_0 << 2;

        var_s0->b.imageY = 0;
        var_s0->b.imageH = sp28[var_s2].unk_4 << 2;
        var_s0->b.frameY = sp28[var_s2].unk_C << 2;
        var_s0->b.frameH = sp28[var_s2].unk_4 << 2;

        var_s0->b.imagePtr = &temp_v0[var_s3];
        var_s0->b.imageLoad = G_BGLT_LOADTILE;
        var_s0->b.imageFmt = G_IM_FMT_CI;
        var_s0->b.imageSiz = G_IM_SIZ_8b;
        var_s0->b.imagePal = 0;
        var_s0->b.imageFlip = 0;

        guS2DInitBg(var_s0);
        var_s3 += sp28[var_s2].unk_0 * sp28[var_s2].unk_4;
    }

    if (gSelection == 0x96) {
        temp_s3 = gTheGame.unk_0000[1].unk_4424;
        switch (temp_s3) {
            case 0x1:
                func_80073C20_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;

            case 0x2:
                func_80073D10_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0x3:
                func_80073E00_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0x4:
                func_80073EF0_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0x5:
                func_80073FE0_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0x6:
                func_800740D0_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0x7:
                func_800741C0_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0x8:
                func_800742B0_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0x9:
                func_800743A0_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0xA:
                func_80074490_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0xB:
                func_80074580_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0xC:
                func_80074670_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0xD:
                func_80074760_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0xE:
                func_80074850_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;
            case 0xF:
            case 0x12:
                func_80074940_usa(0, 0, spA0[temp_s3].unk_4, sp120[temp_s3].unk_4);
                break;

            case 0x10:
                temp_s4 = Pon_Image_Heap;
                osInvalDCache((void *)D_104C660, (u32)D_1070A60 - (u32)D_104C660);
                func_80001310_usa(SEGMENT_ROM_START(segment_50F3F0), temp_s4, SEGMENT_ROM_SIZE(segment_50F3F0));
                Pon_Image_Heap = (uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_50F3F0);
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
            gTheGame.unk_8C88[6].b.frameX = (0xB2 - sp78[temp_s3 - 1].unk_0) << 2;
            gTheGame.unk_8C88[6].b.frameY = (sp120[temp_s3].unk_4 + 0x2B - sp78[temp_s3 - 1].unk_1) << 2;

            for (var_s2 = 7; var_s2 < 0xA; var_s2++) {
                gTheGame.unk_8C88[var_s2].b.frameX = (0xB2 - sp78[temp_s3 - 1].unk_0) << 2;
                gTheGame.unk_8C88[var_s2].b.frameY = (0x2B - sp78[temp_s3 - 1].unk_1) << 2;
            }
        }

        for (var_s2 = 0; var_s2 < 6; var_s2++) {
            InitTetrisState(&gTheGame.unk_0000[0].unk_0000.unk_0000[0].unk_000[var_s2]);
            gTheGame.unk_0000[0].unk_3830.unk_000[var_s2].unk_00 = (s16)(sp98[var_s2] * 4);
            gTheGame.unk_0000[0].unk_3830.unk_000[var_s2].unk_08 = -0x50;
            gTheGame.unk_0000[0].unk_0000.unk_0000[0].unk_000[var_s2].unk_04 = (s32)sp98[var_s2];
        }
    }

    gTheGame.unk_0000[0].unk_43EC = 0;
    gTheGame.unk_0000[0].unk_43FC = 0;
    gWhatever = 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", InitBonus);
#endif
#endif

#if VERSION_USA
#ifdef NON_EQUIVALENT
s32 func_8003228C_usa(void);
s32 DoGameOverTryAgain(void);
void SaveRom(void);
void SetText(s32, s32, const char *, s32);
s32 AnimationRandom(s32);
void Init2DTetrisTMEM(TheGame_unk_0000_unk_0000_unk_000_unk_000 *arg0, TheGame_unk_0000_unk_000 *arg1);
s32 RandomBlock(TheGame_unk_0000 *arg0);
extern s8 gameoverBounce[];

typedef struct struct_800C4660_usa {
    /* 0x0 */ UNK_TYPE4 unk_0;
    /* 0x4 */ UNK_TYPE4 unk_4;
} struct_800C4660_usa; // size = 0x8

typedef struct struct_800C48A8_usa {
    /* 0x0 */ UNK_TYPE2 unk_0;
    /* 0x2 */ UNK_TYPE2 unk_2;
} struct_800C48A8_usa; // size = 0x4

void DoBonus(void) {
    s32 var_s5 = 0;
    char sp10[8];
    struct_800C4660_usa sp18[] = {
        { 0x00000002, 0x00000078 }, { 0x00000004, 0x00000076 }, { 0x00000006, 0x00000075 }, { 0x00000008, 0x00000073 },
        { 0x0000000A, 0x00000072 }, { 0x0000000C, 0x00000071 }, { 0x0000000E, 0x00000070 }, { 0x00000010, 0x0000006F },
        { 0x00000012, 0x0000006E }, { 0x00000014, 0x0000006E }, { 0x00000016, 0x0000006D }, { 0x00000018, 0x0000006D },
        { 0x0000001A, 0x0000006C }, { 0x0000001C, 0x0000006C }, { 0x0000001E, 0x0000006C }, { 0x0000001E, 0x0000006C },
        { 0x00000020, 0x0000006D }, { 0x00000022, 0x0000006E }, { 0x00000024, 0x0000006F }, { 0x00000026, 0x00000070 },
        { 0x00000028, 0x00000072 }, { 0x0000002A, 0x00000074 }, { 0x0000002C, 0x00000076 }, { 0x0000002E, 0x00000078 },
        { 0x00000030, 0x0000007A }, { 0x00000032, 0x0000007C }, { 0x00000034, 0x0000007F }, { 0x00000036, 0x00000082 },
        { 0x00000038, 0x00000085 }, { 0x0000003A, 0x00000088 }, { 0x0000003C, 0x0000008C }, { 0x0000003E, 0x00000090 },
        { 0x00000040, 0x00000095 }, { 0x00000042, 0x0000009A }, { 0x00000044, 0x0000009F }, { 0x00000046, 0x000000A4 },
        { 0x00000047, 0x000000A9 }, { 0x00000049, 0x000000AE }, { 0x0000004B, 0x000000B4 }, { 0x0000004C, 0x000000BA },
        { 0x0000004D, 0x000000C0 }, { 0x0000004E, 0x000000C6 }, { 0x0000004F, 0x000000CC }, { 0x00000050, 0x000000D2 },
        { 0x00000051, 0x000000D8 }, { 0x00000052, 0x000000DE }, { 0x00000053, 0x000000E4 }, { 0x00000053, 0x000000EA },
        { 0x00000054, 0x000000F0 }, { 0x00000055, 0x000000F6 }, { 0x00000056, 0x000000FC }, { 0x00000057, 0x00000102 },
        { 0x00000058, 0x00000108 }, { 0x00000058, 0x0000010E }, { 0x00000059, 0x00000114 }, { 0x0000005A, 0x0000011A },
        { 0x0000005B, 0x0000011E },
    };
    UNK_TYPE4 sp1E0[] = {
        0x00000002, 0x00000005, 0x00000008, 0x0000000B, 0x0000000E, 0x00000010, 0x00000012, 0x00000013,
        0x00000013, 0x00000013, 0x00000012, 0x00000010, 0x0000000E, 0x0000000B, 0x00000008, 0x00000005,
        0x00000002, 0xFFFFFFFF, 0xFFFFFFFB, 0xFFFFFFF7, 0xFFFFFFF3, 0xFFFFFFEE, 0xFFFFFFE9, 0xFFFFFFE4,
        0xFFFFFFDE, 0xFFFFFFD8, 0xFFFFFFD2, 0xFFFFFFCC, 0xFFFFFFC5, 0xFFFFFFBE, 0xFFFFFFB7, 0xFFFFFFB0,
    };
    struct_800C48A8_usa sp260[] UNUSED = {
        0xF81D, 0xF01B, 0xE019, 0xC817, 0xB815, 0xA813, 0xB815, 0xC817, 0xE019, 0xF01B,
    };
    TheGame_unk_0000 *var_s2;
    s16 var_v0_5;
    s32 temp_ret;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_s3;
    s8 *var_s0;
    s32 i;
    s32 t0;

    gTheGame.unk_90C0 = 6;

    for (i = ARRAY_COUNT(gTheGame.unk_90C8) - 1; i >= 0; i--) {
        gTheGame.unk_90C8[i].unk_18 = -1;
    }

    var_s2 = &gTheGame.unk_0000[0];

    if (gSelection == 0x96) {
        if (gWhatever == 0) {
            t0 = DoGameOverTryAgain();
        }
        if ((t0 != 0) || (gWhatever != 0)) {
            if (gWhatever == 0) {
                if (gTheGame.unk_9C24 == 0) {
                    switch (gTheGame.unk_9C28) {
                        case 0x1:
                            var_s0 = gPlayer + 0xE0;
                            break;
                        case 0x2:
                            var_s0 = gPlayer + 0xE1;
                            break;
                        case 0x3:
                            var_s0 = gPlayer + 0xE2;
                            break;
                        case 0x4:
                            var_s0 = gPlayer + 0xE3;
                            break;
                        case 0x5:
                            var_s0 = gPlayer + 0xE4;
                            break;
                    }

                    if (gTheGame.unk_9C30 < 0x63) {
                        gTheGame.unk_9C30++;
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
                    if (gTheGame.unk_9C2C == 0x12) {
                        gTheGame.unk_9C2C = 0x13;
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

        gTheGame.unk_8C88[1].b.frameY = ((gTheGame.unk_8C88[1].b.frameY >> 0x2) - var_s5) * 4;

        var_s3 = 0;
        while (var_s3 < 6) {
            if (var_s2->unk_0000.unk_0000[0].unk_000[var_s3].unk_10 == 0) {
                temp_ret = AnimationRandom(0x1F4);
                if (temp_ret == ((temp_ret / 21) * 0x15)) {
                    var_s2->unk_0000.unk_0000[0].unk_000[var_s3].unk_10 = RandomBlock(var_s2);
                    Init2DTetrisTMEM(&var_s2->unk_0000.unk_0000[0].unk_000[var_s3], &var_s2->unk_3830.unk_000[var_s3]);
                    var_s2->unk_3830.unk_000[var_s3].unk_00 = var_s2->unk_0000.unk_0000[0].unk_000[var_s3].unk_04 * 4;
                }
            } else {
                var_a0 = var_s2->unk_3830.unk_000[var_s3].unk_08 >> 2;
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
                    var_s2->unk_0000.unk_0000[0].unk_000[var_s3].unk_10 = 0;
                    var_s2->unk_0000.unk_0000[0].unk_000[var_s3].unk_08 = 0;
                }

                // if (gTheGame.unk_0000[0].unk_0000.unk_0000) {}

                switch (var_s3) {
                    case 1:
                        if ((var_a0 >= 0x95) || (var_s2->unk_0000.unk_0000[0].unk_000[1].unk_08 != 0)) {
                            var_v0_5 = (0x9B - sp1E0[var_s2->unk_0000.unk_0000[0].unk_000[1].unk_08++]) * 4;
                        } else {
                            var_v0_5 = var_a0 * 4;
                        }
                        var_s2->unk_3830.unk_000[var_s3].unk_08 = var_v0_5;
                        break;

                    case 3:
                        if (var_a0 >= 0x46) {
                            if (var_s2->unk_0000.unk_0000[0].unk_000[3].unk_08 == 0) {
                                var_s2->unk_0000.unk_0000[0].unk_000[3].unk_0C = 8;
                            }
                            goto block_58;
                        }
                        var_v0_5 = var_a0 * 4;
                        if (var_s2->unk_0000.unk_0000[0].unk_000[3].unk_08 != 0) {
                        block_58:
                            if (var_s2->unk_0000.unk_0000[0].unk_000[3].unk_0C != 0) {
                                var_s2->unk_0000.unk_0000[0].unk_000[3].unk_0C--;
                            }
                            var_v0_5 = var_a0 * 4;
                            temp_v1_2 = var_s2->unk_0000.unk_0000[0].unk_000[3].unk_08;
                            var_s2->unk_0000.unk_0000[0].unk_000[3].unk_08++;
                            if (var_s2->unk_0000.unk_0000[0].unk_000[3].unk_08 >= 2) {
                                var_s2->unk_3830.unk_000[0].unk_00 = (sp18[temp_v1_2 - 1].unk_0 + 0x5A) * 4;

                                var_v0_5 = (sp18[temp_v1_2 - 1].unk_4 - 0x35) * 4;
                            }
                        }

                        var_s2->unk_3830.unk_000[var_s3].unk_08 = var_v0_5;
                        break;

                    default:
                        var_s2->unk_3830.unk_000[var_s3].unk_08 = var_a0 * 4;
                        break;
                }
            }

            var_s3 += 1;
        }

        sprintf(sp10, "%02d", gTheGame.unk_9C30);
        SetText(0x103, 0x17, sp10, 0x17);
    } else if (func_8003228C_usa() != 0) {
        gReset = -1;
        gMain = GMAIN_258;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/bonus", DoBonus);
#endif
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
