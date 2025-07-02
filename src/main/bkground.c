/**
 * Original filename: bkground.c
 */

#include "bkground.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "001F10.h"
#include "the_game.h"

#include "assets/background.h"
#include "assets/background_frame.h"
#include "assets_variables.h"

void InitFrame(void) {
    uObjBg *obj;
    BackgroundFrame *bg_frame;
    u8 *ui_display;
    s32 x;
    s32 y;
    s32 height;
    s32 i;

    bg_frame = Pon_Image_Heap;
    if (gTheGame.unk_9C0C == 1) {
        if (gTheGame.unk_9C08 == 1) {
            LOAD_DATA_SEGMENT(bg_frame, segment_background_frame_2d_1p, Pon_Image_Heap);
        } else {
            LOAD_DATA_SEGMENT(bg_frame, segment_background_frame_2d_2p, Pon_Image_Heap);

            // 2d player display
            ui_display = Pon_Image_Heap;
            switch (gSelection) {
                case 0x96:
                    LOAD_DATA_SEGMENT(ui_display, segment_background_frame_ui_display_2p_C, Pon_Image_Heap);
                    x = (SCREEN_WIDTH - (BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH - 12)) / 2;
                    y = SCREEN_HEIGHT - 1 - BACKGROUND_FRAME_UI_DISPLAY_2P_C_HEIGHT;
                    height = BACKGROUND_FRAME_UI_DISPLAY_2P_C_HEIGHT;
                    break;

                case 0xC8:
                    LOAD_DATA_SEGMENT(ui_display, segment_background_frame_ui_display_2p_B, Pon_Image_Heap);
                    x = (SCREEN_WIDTH - (BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH - 8)) / 2;
                    y = SCREEN_HEIGHT - 1 - BACKGROUND_FRAME_UI_DISPLAY_2P_B_HEIGHT;
                    height = BACKGROUND_FRAME_UI_DISPLAY_2P_B_HEIGHT;
                    break;

                case 0xA0:
                case 0xB4:
                    LOAD_DATA_SEGMENT(ui_display, segment_background_frame_ui_display_2p_A, Pon_Image_Heap);
                    x = (SCREEN_WIDTH - (BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH - 8)) / 2;
                    y = SCREEN_HEIGHT - 1 - BACKGROUND_FRAME_UI_DISPLAY_2P_A_HEIGHT;
                    height = BACKGROUND_FRAME_UI_DISPLAY_2P_A_HEIGHT;
                    break;
            }
        }
    } else {
        if (gTheGame.unk_9C08 == 1) {
            LOAD_DATA_SEGMENT(bg_frame, segment_background_frame_3d_1p, Pon_Image_Heap);
        } else {
            LOAD_DATA_SEGMENT(bg_frame, segment_background_frame_3d_2p, Pon_Image_Heap);

            ui_display = Pon_Image_Heap;
            switch (gSelection) {
                case 0xC8:
                    LOAD_DATA_SEGMENT(ui_display, segment_background_frame_ui_display_2p_B, Pon_Image_Heap);
                    x = (SCREEN_WIDTH - (BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH - 8)) / 2;
                    y = SCREEN_HEIGHT - 1 - BACKGROUND_FRAME_UI_DISPLAY_2P_B_HEIGHT;
                    height = BACKGROUND_FRAME_UI_DISPLAY_2P_B_HEIGHT;
                    break;

                case 0xB4:
                case 0xA0:
                    LOAD_DATA_SEGMENT(ui_display, segment_background_frame_ui_display_2p_A, Pon_Image_Heap);
                    x = (SCREEN_WIDTH - (BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH - 8)) / 2;
                    y = SCREEN_HEIGHT - 1 - BACKGROUND_FRAME_UI_DISPLAY_2P_A_HEIGHT;
                    height = BACKGROUND_FRAME_UI_DISPLAY_2P_A_HEIGHT;
                    break;
            }
        }
    }

    for (i = 0; i < gTheGame.unk_9C08; i++) {
        obj = &gTheGame.frame[i];
        if (i == 0) {
            obj->s.imageX = 0;
            obj->s.imageW = BACKGROUND_FRAME_WIDTH << 2;
            obj->s.frameX = 0;
            obj->s.frameW = BACKGROUND_FRAME_WIDTH << 2;
            obj->s.imageY = 0;
            obj->s.imageH = BACKGROUND_FRAME_HEIGHT << 2;
            obj->s.frameY = (SCREEN_HEIGHT - BACKGROUND_FRAME_HEIGHT - 1) << 2;
            obj->s.frameH = BACKGROUND_FRAME_HEIGHT << 2;
            obj->s.imagePtr = (void *)bg_frame->frame;
        } else {
            obj->s.imageX = 0;
            obj->s.imageW = BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH << 2;
            obj->s.frameX = x << 2;
            obj->s.frameW = BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH << 2;
            obj->s.imageY = 0;
            obj->s.imageH = height << 2;
            obj->s.frameY = y << 2;
            obj->s.frameH = height << 2;
            obj->s.imagePtr = (void *)ui_display;
        }

        obj->s.imageLoad = G_BGLT_LOADTILE;
        obj->s.imageFmt = G_IM_FMT_CI;
        obj->s.imageSiz = G_IM_SIZ_8b;
        obj->s.imagePal = 0;
        obj->s.imageFlip = 0;
        guS2DInitBg(obj);

        gTheGame.unk_99D8[i].tlut.type = G_OBJLT_TLUT;
        if (i == 0) {
            gTheGame.unk_99D8[i].tlut.image = (void *)bg_frame->tlut;
        } else {
            gTheGame.unk_99D8[i].tlut.image = (void *)(ui_display + (BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH * height));
        }
        gTheGame.unk_99D8[i].tlut.pnum = GS_PAL_NUM(BACKGROUND_FRAME_TLUT_SIZE);
        gTheGame.unk_99D8[i].tlut.phead = GS_PAL_HEAD(0);
        gTheGame.unk_99D8[i].tlut.zero = 0;
        gTheGame.unk_99D8[i].tlut.sid = 0;
        gTheGame.unk_99D8[i].tlut.flag = (u32)-1;
        gTheGame.unk_99D8[i].tlut.mask = 0;

        if (gTheGame.unk_9C0C == 2) {
            obj->s.imageYorig = 0;
            obj->s.scaleW = 1 << 10;
            obj->s.scaleH = 1 << 10;
        }
    }
}

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
                    if (gTheGame.tetrisWell[0].menu.unk_0 == 5) {
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
                    if (gTheGame.tetrisWell[0].menu.unk_0 == 5) {
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
            if (gTheGame.menu[0].unk_4 != 0x10) {
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
