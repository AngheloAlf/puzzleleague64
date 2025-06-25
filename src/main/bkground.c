/**
 * Original filename: bkground.c
 */

#include "bkground.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "001F10.h"
#include "the_game.h"

#include "assets/background.h"
#include "assets_variables.h"

#if VERSION_USA
#if 0
extern UNK_TYPE1 D_1336B0_A;
extern UNK_TYPE1 D_145AB0_A;
extern UNK_TYPE1 D_10375E0_A;
extern UNK_TYPE1 D_10499E0_A;

extern UNK_TYPE1 D_145AB0_B;
extern UNK_TYPE1 D_157EB0_B;
extern UNK_TYPE1 D_10375E0_B;
extern UNK_TYPE1 D_10499E0_B;

extern UNK_TYPE1 D_1827B0_C;
extern UNK_TYPE1 D_184FF0_C;
extern UNK_TYPE1 D_10499E0_C;
extern UNK_TYPE1 D_104C220_C;

extern UNK_TYPE1 D_17F330_D;
extern UNK_TYPE1 D_1827B0_D;
extern UNK_TYPE1 D_10499E0_D;
extern UNK_TYPE1 D_104CE60_D;

extern UNK_TYPE1 D_17C6B0_E;
extern UNK_TYPE1 D_17F330_E;
extern UNK_TYPE1 D_10499E0_E;
extern UNK_TYPE1 D_104C660_E;

extern UNK_TYPE1 D_157EB0_F;
extern UNK_TYPE1 D_16A2B0_F;
extern UNK_TYPE1 D_10375E0_F;
extern UNK_TYPE1 D_10499E0_F;

extern UNK_TYPE1 D_16A2B0_G;
extern UNK_TYPE1 D_17C6B0_G;
extern UNK_TYPE1 D_10375E0_G;
extern UNK_TYPE1 D_10499E0_G;

void func_80047340_usa(void) {
    s32 sp14;
    u64 *sp24;
    void *sp2C;
    s32 var_a3;
    s32 var_s1;
    s32 var_s2;
    u16 temp_s5;
    u16 var_a1;
    u16 var_a2;
    uObjBg *temp_s0_5;
    void *temp_s7;
    void *var_s4;

    temp_s7 = Pon_Image_Heap;
    if (gTheGame.unk_9C0C == 1) {
        if (gTheGame.unk_9C08 == 1) {
            osInvalDCache(&D_10375E0_A, &D_10499E0_A - &D_10375E0_A);
            func_80001310_usa((u32)&D_1336B0_A, temp_s7, (u32)(&D_145AB0_A - &D_1336B0_A));
            Pon_Image_Heap = Pon_Image_Heap + (u32)(&D_145AB0_A - &D_1336B0_A);
        } else {
            osInvalDCache(&D_10375E0_B, &D_10499E0_B - &D_10375E0_B);
            func_80001310_usa((u32)&D_145AB0_B, temp_s7, (u32)(&D_157EB0_B - &D_145AB0_B));
            Pon_Image_Heap = Pon_Image_Heap + (u32)(&D_157EB0_B - &D_145AB0_B);

            var_s4 = Pon_Image_Heap;

            switch (gSelection) { /* switch 1; irregular */
                case 0x96:        
                    osInvalDCache(&D_10499E0_C, &D_104C220_C - &D_10499E0_C);
                    func_80001310_usa((u32)&D_1827B0_C, var_s4, (u32)(&D_184FF0_C - &D_1827B0_C));
                    Pon_Image_Heap = Pon_Image_Heap + (u32)(&D_184FF0_C - &D_1827B0_C);
                    sp14 = 0x86;
                    var_a3 = 0x56;
                    var_s1 = 0x99;
                    break;

                case 0xC8: 
                    osInvalDCache(&D_10499E0_D, &D_104CE60_D - &D_10499E0_D);
                    func_80001310_usa((u32)&D_17F330_D, var_s4, (u32)(&D_1827B0_D - &D_17F330_D));
                    Pon_Image_Heap = Pon_Image_Heap + (u32)(&D_1827B0_D - &D_17F330_D);
                    sp14 = 0x84;
                    var_a3 = 0x25;
                    var_s1 = 0xCA;
                    break;

                case 0xA0: 
                case 0xB4: 
                    osInvalDCache(&D_10499E0_E, &D_104C660_E - &D_10499E0_E);
                    func_80001310_usa((u32)&D_17C6B0_E, var_s4, (u32)(&D_17F330_E - &D_17C6B0_E));
                    Pon_Image_Heap = Pon_Image_Heap + (u32)(&D_17F330_E - &D_17C6B0_E);
                    sp14 = 0x84;
                    var_a3 = 0x45;
                    var_s1 = 0xAA;
                    break;
            }
        }
    } else {
        if (gTheGame.unk_9C08 == 1) {
            osInvalDCache(&D_10375E0_F, &D_10499E0_F - &D_10375E0_F);
            func_80001310_usa((u32)&D_157EB0_F, temp_s7, (u32)(&D_16A2B0_F - &D_157EB0_F));
            Pon_Image_Heap = Pon_Image_Heap + (u32)(&D_16A2B0_F - &D_157EB0_F);
        } else {
            osInvalDCache(&D_10375E0_G, &D_10499E0_G - &D_10375E0_G);
            func_80001310_usa((u32)&D_16A2B0_G, temp_s7, (u32)(&D_17C6B0_G - &D_16A2B0_G));
            Pon_Image_Heap = Pon_Image_Heap + (u32)(&D_17C6B0_G - &D_16A2B0_G);

            var_s4 = Pon_Image_Heap;
            switch (gSelection) { /* irregular */
                case 0xC8:
                    osInvalDCache(&D_10499E0_D, &D_104CE60_D - &D_10499E0_D);
                    func_80001310_usa((u32)&D_17F330_D, var_s4, (u32)(&D_1827B0_D - &D_17F330_D));
                    Pon_Image_Heap = Pon_Image_Heap + (u32)(&D_1827B0_D - &D_17F330_D);
                    sp14 = 0x84;
                    var_a3 = 0x25;
                    var_s1 = 0xCA;
                    break;

                case 0xB4:
                case 0xA0:
                    osInvalDCache(&D_10499E0_E, &D_104C660_E - &D_10499E0_E);
                    func_80001310_usa((u32)&D_17C6B0_E, var_s4, (u32)(&D_17F330_E - &D_17C6B0_E));
                    Pon_Image_Heap = Pon_Image_Heap + (u32)(&D_17F330_E - &D_17C6B0_E);
                    sp14 = 0x84;
                    var_a3 = 0x45;
                    var_s1 = 0xAA;
                    break;
            }
        }
    }

    var_s2 = 0;
    var_a2 = 0x500;
    var_a1 = 0x3A0;
    temp_s5 = var_s1 * 4;
    sp24 = temp_s7 + 0x12200;

    sp2C = var_s4 + (var_s1 << 6);
    while (var_s2 < gTheGame.unk_9C08) {
        temp_s0_5 = &gTheGame.frame[var_s2];
        if (var_s2 == 0) {
            temp_s0_5->b.imageX = 0;
            temp_s0_5->b.imageW = var_a2;
            temp_s0_5->b.frameX = 0;
            temp_s0_5->b.frameW = var_a2;
            temp_s0_5->b.imageY = 0;
            temp_s0_5->b.imageH = var_a1;
            temp_s0_5->b.frameY = 0x1C;
            temp_s0_5->b.frameH = var_a1;
            temp_s0_5->b.imagePtr = temp_s7;
        } else {
            temp_s0_5->b.imageX = 0;
            temp_s0_5->b.imageW = 0x100;
            temp_s0_5->b.frameW = 0x100;
            temp_s0_5->b.imageY = 0;
            temp_s0_5->b.imageH = temp_s5;
            temp_s0_5->b.frameX = sp14 * 4;
            temp_s0_5->b.frameH = temp_s5;
            temp_s0_5->b.imagePtr = var_s4;
            temp_s0_5->b.frameY = var_a3 * 4;
        }
        temp_s0_5->b.imageLoad = 0xFFF4;
        temp_s0_5->b.imageFmt = 2;
        temp_s0_5->b.imageSiz = 1;
        temp_s0_5->b.imagePal = 0;
        temp_s0_5->b.imageFlip = 0;
        guS2DInitBg(temp_s0_5);
        gTheGame.unk_99D8[var_s2].block.type = 0x30;
        if (var_s2 == 0) {
            gTheGame.unk_99D8[var_s2].block.image = sp24;
        } else {
            gTheGame.unk_99D8[var_s2].block.image = sp2C;
        }
        gTheGame.unk_99D8[var_s2].block.tsize = 0xFF;
        gTheGame.unk_99D8[var_s2].block.tmem = 0x100;
        gTheGame.unk_99D8[var_s2].block.tline = 0;
        gTheGame.unk_99D8[var_s2].block.sid = 0;
        gTheGame.unk_99D8[var_s2].block.flag = -1;
        gTheGame.unk_99D8[var_s2].block.mask = 0;

        if (gTheGame.unk_9C0C == 2) {
            temp_s0_5->s.imageYorig = 0;
            temp_s0_5->b.tmemW = 0x400;
            temp_s0_5->b.tmemH = 0x400;
        }
        var_s2 += 1;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80047340_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_800475E0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80045D60_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80045ED0_ger);
#endif

void Draw2DFrame(void) {
    func_8004B12C_usa();

    if (D_800B69C4_usa == -1) {
        gDPPipeSync(glistp++);
        gDPSetTextureLUT(glistp++, G_TT_NONE);
        gDPSetRenderMode(glistp++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetCycleType(glistp++, G_CYC_COPY);

        if (gSelection == 0x78) {
            gDPSetTextureLUT(glistp++, G_TT_RGBA16);
            gSPObjLoadTxtr(glistp++, &gTheGame.unk_99D8);
        }

        gDPPipeSync(glistp++);
        gSPBgRectCopy(glistp++, &gTheGame.frame);
    }

    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80047A00_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_80047A00_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80047A00_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80047A00_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80047D20_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_80047FC0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80046740_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_800468B0_ger);
#endif

// TODO: enum for `who`?
void InitBackground(s32 who) {
    void *currSegment = Pon_Image_Heap;

    switch (gSelection) {
        case 0x8C:
            LOAD_DATA_SEGMENT(currSegment, segment_background_184FF0, Pon_Image_Heap);
            break;

        case 0xBE:
            LOAD_DATA_SEGMENT(currSegment, segment_background_1A93F0, Pon_Image_Heap);
            break;

        case 0xAA:
            switch (who) {
                case 0x1:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_1CD7F0, Pon_Image_Heap);
                    break;

                case 0x2:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_1F1BF0, Pon_Image_Heap);
                    break;

                case 0x3:
                    if (gTheGame.tetrisWell[0].unk_4420 == 5) {
                        LOAD_DATA_SEGMENT(currSegment, segment_background_2A6FF0, Pon_Image_Heap);
                    } else {
                        LOAD_DATA_SEGMENT(currSegment, segment_background_215FF0, Pon_Image_Heap);
                    }
                    break;

                case 0x4:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_23A3F0, Pon_Image_Heap);
                    break;

                case 0x5:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_25E7F0, Pon_Image_Heap);
                    break;

                case 0x6:
                    if (gTheGame.tetrisWell[0].unk_4420 == 5) {
                        LOAD_DATA_SEGMENT(currSegment, segment_background_2CB3F0, Pon_Image_Heap);
                    } else {
                        LOAD_DATA_SEGMENT(currSegment, segment_background_282BF0, Pon_Image_Heap);
                    }
                    break;
            }
            break;

        case 0x78:
        case 0x82:
            switch (who) {
                case 1:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_2EF7F0, Pon_Image_Heap);
                    break;

                case 2:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_313BF0, Pon_Image_Heap);
                    break;

                case 3:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_337FF0, Pon_Image_Heap);
                    break;
            }

            B_8021BA78_usa = who - 1;
            break;

        case 0x96:
            if (gTheGame.unk_9C2C[0][0] != 0x10) {
                switch (who) {
                    case 0x0:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_35C3F0, Pon_Image_Heap);
                        break;

                    case 0x1:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_3807F0, Pon_Image_Heap);
                        break;

                    case 0x2:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_3A4BF0, Pon_Image_Heap);
                        break;

                    case 0x3:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_3C8FF0, Pon_Image_Heap);
                        break;

                    case 0x4:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_3ED3F0, Pon_Image_Heap);
                        break;

                    case 0x5:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_4117F0, Pon_Image_Heap);
                        break;

                    case 0x6:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_435BF0, Pon_Image_Heap);
                        break;

                    case 0x7:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_459FF0, Pon_Image_Heap);
                        break;

                    case 0x8:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_47E3F0, Pon_Image_Heap);
                        break;

                    case 0x9:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_4A27F0, Pon_Image_Heap);
                        break;

                    case 0xA:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_4C6BF0, Pon_Image_Heap);
                        break;

                    case 0xB:
                        LOAD_DATA_SEGMENT(currSegment, segment_background_4EAFF0, Pon_Image_Heap);
                        break;
                }
            } else {
                LOAD_DATA_SEGMENT(currSegment, segment_background_50F3F0, Pon_Image_Heap);
            }
            break;

        case 0xA0:
        case 0xB4:
        case 0xC8:
            switch (who) {
                case 0x0:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_35C3F0, Pon_Image_Heap);
                    break;

                case 0x1:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_3807F0, Pon_Image_Heap);
                    break;

                case 0x2:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_3A4BF0, Pon_Image_Heap);
                    break;

                case 0x3:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_3C8FF0, Pon_Image_Heap);
                    break;

                case 0x4:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_3ED3F0, Pon_Image_Heap);
                    break;

                case 0x5:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_4117F0, Pon_Image_Heap);
                    break;

                case 0x6:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_435BF0, Pon_Image_Heap);
                    break;

                case 0x7:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_459FF0, Pon_Image_Heap);
                    break;

                case 0x8:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_47E3F0, Pon_Image_Heap);
                    break;

                case 0x9:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_4A27F0, Pon_Image_Heap);
                    break;

                case 0xA:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_4C6BF0, Pon_Image_Heap);
                    break;

                case 0xB:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_4EAFF0, Pon_Image_Heap);
                    break;

                default:
                    LOAD_DATA_SEGMENT(currSegment, segment_background_50F3F0, Pon_Image_Heap);
                    break;
            }
            break;
    }

    gTheGame.unk_9A50.b.imageX = 0;
    gTheGame.unk_9A50.b.frameX = 0;
    gTheGame.unk_9A50.b.imageY = 0;
    gTheGame.unk_9A50.b.imageW = BACKGROUND_WIDTH << 2;
    gTheGame.unk_9A50.b.imageH = BACKGROUND_HEIGHT << 2;
    gTheGame.unk_9A50.b.frameW = BACKGROUND_WIDTH << 2;
    gTheGame.unk_9A50.b.frameY = 7 << 2;
    gTheGame.unk_9A50.b.frameH = BACKGROUND_HEIGHT << 2;

    gTheGame.unk_9A50.b.imagePtr = (void *)currSegment;
    gTheGame.unk_9A50.b.imageLoad = G_BGLT_LOADTILE;
    gTheGame.unk_9A50.b.imageFmt = G_IM_FMT_RGBA;
    gTheGame.unk_9A50.b.imageSiz = G_IM_SIZ_16b;
    gTheGame.unk_9A50.b.imagePal = 0;
    gTheGame.unk_9A50.b.imageFlip = 0;

    guS2DInitBg(&gTheGame.unk_9A50);
}

void Draw2DBackground(void) {
    gDPPipeSync(glistp++);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(glistp++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCycleType(glistp++, G_CYC_COPY);

    gDPPipeSync(glistp++);
    gSPBgRectCopy(glistp++, &gTheGame.unk_9A50);

    func_8004AE90_usa();

    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", Draw3DBackground);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", Draw3DBackground);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", Draw3DBackground);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", Draw3DBackground);
#endif

void func_80048D94_usa(void) {
    s16 sp0[ARRAY_COUNT(gTheGame.unk_9A08)];
    s16 sp8[17] UNUSED = {
        0x43, 0, 1, 0x43, 1, 7, 0, 0x43, 1, 7, 7, 0, 1, 0, 1, 0, 0,
    };
    s32 i;
    uObjSprite *var_v1;

    if ((gTheGame.unk_9C0C == 1) && (gTheGame.unk_9C08 != 1)) {
        sp0[0] = 0x47;
        sp0[1] = 0x47;
    } else {
        sp0[0] = 0;
        sp0[1] = 0;
    }
    sp0[2] = 0;

    var_v1 = gTheGame.unk_9A08;
    for (i = 0; i < ARRAY_COUNT(gTheGame.unk_9A08); i++) {
        var_v1[i].s.imageW = 8 << 5;
        var_v1[i].s.imageH = 8 << 5;
        var_v1[i].s.paddingX = 0;
        var_v1[i].s.paddingY = 0;
        var_v1[i].s.imageStride = 8;
        var_v1[i].s.imageAdrs = sp0[i];
        var_v1[i].s.imageFmt = G_IM_FMT_CI;
        var_v1[i].s.imageSiz = G_IM_SIZ_8b;
        var_v1[i].s.imagePal = 0;
        var_v1[i].s.imageFlags = 0;
    }

    if (gTheGame.unk_9C08 == 1) {
        gTheGame.unk_9A08[0].s.objX = 0x72 << 2;
        gTheGame.unk_9A08[0].s.scaleW = 0x4B;
        gTheGame.unk_9A08[0].s.objY = 0x1F << 2;
        gTheGame.unk_9A08[0].s.scaleH = 0x2A;

        gTheGame.unk_9A08[1].s.objX = 0x1F << 2;
        gTheGame.unk_9A08[1].s.scaleW = 0x66;
        gTheGame.unk_9A08[1].s.objY = 0x19 << 2;
        gTheGame.unk_9A08[1].s.scaleH = 0x108;

        gTheGame.unk_9A08[2].s.objX = 0xE2 << 2;
        gTheGame.unk_9A08[2].s.scaleW = 0x86;
        gTheGame.unk_9A08[2].s.objY = 0x19 << 2;
        gTheGame.unk_9A08[2].s.scaleH = 0x46;
    } else {
        gTheGame.unk_9A08[0].s.objX = 0x18 << 2;
        gTheGame.unk_9A08[0].s.scaleW = 0x4B;
        gTheGame.unk_9A08[0].s.objY = 0x1F << 2;
        gTheGame.unk_9A08[0].s.scaleH = 0x2A;

        gTheGame.unk_9A08[1].s.objX = 0xBC << 2;
        gTheGame.unk_9A08[1].s.scaleW = 0x4B;
        gTheGame.unk_9A08[1].s.objY = 0x1F << 2;
        gTheGame.unk_9A08[1].s.scaleH = 0x2A;

        if (gSelection == 0x96) {
            gTheGame.unk_9A08[2].s.objY = 0x51 << 2;
        } else {
            gTheGame.unk_9A08[2].s.objY = 0x40 << 2;
        }
        gTheGame.unk_9A08[2].s.objX = 0x86 << 2;
        gTheGame.unk_9A08[2].s.scaleW = 0x9D;
        gTheGame.unk_9A08[2].s.scaleH = 0x51;
    }
}

void Draw2DShadeBox(void) {
    s32 count;
    s32 total;

    if (gTheGame.unk_9C08 == 1) {
        total = ARRAY_COUNT(gTheGame.unk_9A08);
    } else if (gMain < GMAIN_393) {
        total = ARRAY_COUNT(gTheGame.unk_9A08) - 1;
    } else {
        return;
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &numberLUT);
    gSPObjLoadTxtr(glistp++, &transTexture);

    gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, gBox_Level);

    for (count = 0; count < total; count++) {
        gSPObjRectangle(glistp++, &gTheGame.unk_9A08[count]);
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_8004917C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004941C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80047B9C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80047D0C_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80049584_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_80049824_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80047FA4_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80048114_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_80049960_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_80049C00_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80048380_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_800484F0_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_8004A26C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004A50C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80048C8C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80048DFC_ger);
#endif

void Draw2DBigScreen(uObjTxtr *lut, uObjBg *ptr) {
    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, lut);
    gDPSetRenderMode(glistp++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCycleType(glistp++, G_CYC_COPY);

    gDPPipeSync(glistp++);
    gSPBgRectCopy(glistp++, ptr);

    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
    gDPSetTextureLUT(glistp++, G_TT_NONE);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_8004AA48_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004ACE8_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80049468_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_800495D8_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_8004ADD0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004ADD0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_8004ADD0_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_8004ADD0_usa);
#endif

void func_8004AE90_usa(void) {
    if (D_800B69C0_usa == -1) {
        return;
    }

    if (D_800B69C0_usa < 4) {
        gDPPipeSync(glistp++);
        gDPSetCycleType(glistp++, G_CYC_1CYCLE);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, ((D_800B69C0_usa * 0x32) + 0x64));

        if (gTheGame.unk_9C0C == 1) {
            gDPPipeSync(glistp++);
            gSPBgRect1Cyc(glistp++, &gTheGame.unk_8C88[0]);

            gDPPipeSync(glistp++);
            gSPBgRect1Cyc(glistp++, &gTheGame.unk_8C88[1]);
        } else if ((gSelection != 0xAA) & (gSelection != 0x82)) {
            gDPPipeSync(glistp++);
            guS2DEmuBgRect1Cyc(&glistp, &gTheGame.unk_8C88[0]);

            gDPPipeSync(glistp++);
            guS2DEmuBgRect1Cyc(&glistp, &gTheGame.unk_8C88[1]);
        }

        if (D_800B69C0_usa == 3) {
            gTheGame.unk_9A50.b.imagePtr = gTheGame.unk_8C88[2].b.imagePtr;
        }
    }

    gDPPipeSync(glistp++);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/bkground", func_8004B0D8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/bkground", func_8004B378_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/bkground", func_80049AF8_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/bkground", func_80049C68_ger);
#endif

void func_8004B12C_usa(void) {
    if ((D_800B69C4_usa < 0x1A) && (D_800B69C4_usa != -1)) {
        gDPPipeSync(glistp++);

        gDPSetTextureLUT(glistp++, G_TT_NONE);
        gDPSetCycleType(glistp++, G_CYC_1CYCLE);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);

        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, D_800B69C4_usa * 0xA);

        if (gTheGame.unk_9C0C == 1) {
            gDPPipeSync(glistp++);
            gSPBgRect1Cyc(glistp++, &gTheGame.frame[0]);
        } else {
            gDPPipeSync(glistp++);
            guS2DEmuBgRect1Cyc(&glistp, &gTheGame.frame[0]);
        }
    } else if (D_800B69C4_usa != -1) {
        D_800B69C4_usa = -1;
        guS2DInitBg(&gTheGame.frame[0]);
    }

    gDPPipeSync(glistp++);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
}
