/**
 * Original filename: other.c
 */

#include "other.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "001F10.h"
#include "info.h"
#include "the_game.h"

#include "assets_variables.h"

#if VERSION_USA
#if 0
void InitMiscStuff(void) {
    s32 sp14;
    void *sp1C;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 var_s7;
    u32 temp_s0;
    void *temp_v1;

    s32 temp;

    sp1C = Pon_Image_Heap;
    LOAD_DATA_SEGMENT(sp1C, segment_other_misc, Pon_Image_Heap);

    for (temp = 0; temp < 4; temp++) {
        gTheGame.unk_9B50[temp].b.imagePtr = NULL;
    }

    gTheGame.unk_9B48 = 0;

    switch (gSelection) {
        case 0x8C:
        case 0xAA:
        case 0xBE:
            var_s4 = 0x43;
            var_s7 = 0x60;
            var_s6 = 0x32;
            sp14 = 0xD0;
            var_s5 = 4;
            var_s2 = 0x63;
            var_s3 = 0;
            gTheGame.unk_9B50[0].b.frameX = 0x398;
            gTheGame.unk_9B50[1].b.frameX = 0x398;
            gTheGame.unk_9B50[2].b.frameX = 0x398;
            gTheGame.unk_9B50[3].b.frameX = 0x398;
            break;

        case 0x78:
        case 0x82:
            var_s4 = 0x40;
            var_s7 = 0x40;
            var_s6 = 0x45;
            sp14 = 0xA8;
            var_s5 = 2;
            var_s2 = 0x4D;
            var_s3 = 0x4CA0;
            gTheGame.unk_9B48 = -1;
            gTheGame.unk_9B50[0].b.frameX = 0x398;
            gTheGame.unk_9B50[1].b.frameX = 0x398;
            break;

        case 0x96:
        case 0xA0:
        case 0xB4:
        case 0xC8:
            gTheGame.unk_9B48 = -1;
            if (gTheGame.unk_9C0C == 1) {
                var_s4 = 0x6C;
                var_s7 = 0x80;
                var_s6 = 0xDD;
                sp14 = 0x90;
                var_s5 = 2;
                var_s2 = 0x1F;
                var_s3 = 0x7070;
                gTheGame.unk_9B50[0].b.frameX = 0x60;
                gTheGame.unk_9B50[1].b.frameX = 0x2F0;
            } else {
                var_s4 = 0x6C;
                var_s7 = 0x80;
                var_s6 = 0xC4;
                sp14 = 0x100;
                var_s5 = 2;
                var_s2 = 0x19;
                var_s3 = 0x14E90;
                gTheGame.unk_9B50[0].b.frameX = 0x60;
                gTheGame.unk_9B50[1].b.frameX = 0x2F0;
            }
            break;

        case 0x64:
            gTheGame.unk_9B48 = -1;
            var_s4 = 0x6C;
            var_s7 = 0x80;
            var_s6 = 0xDD;
            sp14 = 0x90;
            var_s5 = 2;
            var_s2 = 0xDF;
            var_s3 = 0x7070;
            gTheGame.unk_9B50[0].b.frameX = 0x60;
            gTheGame.unk_9B50[1].b.frameX = 0x2F0;
            break;
    }

    for (var_s1 = 0; var_s1 < var_s5; var_s1++) {
        gTheGame.unk_9B50[var_s1].s.imageX = 0;
        gTheGame.unk_9B50[var_s1].s.imageW = var_s7 << 2;
        gTheGame.unk_9B50[var_s1].s.frameW = var_s4 << 2;
        gTheGame.unk_9B50[var_s1].s.imageY = 0;
        gTheGame.unk_9B50[var_s1].s.imageH = var_s6 << 2;
        gTheGame.unk_9B50[var_s1].s.frameY = var_s2 << 2;
        gTheGame.unk_9B50[var_s1].s.frameH = var_s6 << 2;
        gTheGame.unk_9B50[var_s1].s.imagePtr = sp1C + var_s3;
        gTheGame.unk_9B50[var_s1].s.imageFmt = 2;
        gTheGame.unk_9B50[var_s1].s.imagePal = 0;
        gTheGame.unk_9B50[var_s1].s.imageFlip = 0;
        gTheGame.unk_9B50[var_s1].s.imageLoad = 0xFFF4;
        gTheGame.unk_9B50[var_s1].s.imageSiz = 1;
        guS2DInitBg(&gTheGame.unk_9B50[var_s1]);
        if (gTheGame.unk_9C0C == 2) {
            gTheGame.unk_9B50[var_s1].s.imageYorig = 0;
            gTheGame.unk_9B50[var_s1].s.scaleW = 0x400;
            gTheGame.unk_9B50[var_s1].s.scaleH = 0x400;
        }
        var_s3 += var_s7 * var_s6;
    }

    gTheGame.unk_9BF0.block.type = 0x30;
    gTheGame.unk_9BF0.block.tmem = 0x100;
    gTheGame.unk_9BF0.block.tline = 0;
    gTheGame.unk_9BF0.block.sid = 0;
    gTheGame.unk_9BF0.block.flag = (u32)-1;
    gTheGame.unk_9BF0.block.mask = 0;
    gTheGame.unk_9BF0.block.image = sp1C + var_s3;
    gTheGame.unk_9BF0.block.tsize = sp14 - 1;
    if ((gSelection == 0x8C) || (gSelection == 0xBE)) {
        var_s3 = 0x21490;

        gTheGame.unk_8C88[3].s.imageW = 0x200;
        gTheGame.unk_8C88[3].s.frameW = 0x200;
        gTheGame.unk_8C88[3].s.frameX = 0x1D8;
        gTheGame.unk_8C88[3].s.frameY = 0xB4;
        gTheGame.unk_8C88[3].s.imageLoad = 0x33;
        gTheGame.unk_8C88[3].s.imageFmt = 2;
        gTheGame.unk_8C88[3].s.imageSiz = 1;
        gTheGame.unk_8C88[3].s.scaleW = 0x400;
        gTheGame.unk_8C88[3].s.scaleH = 0x400;
        gTheGame.unk_8C88[3].s.imageX = 0;
        gTheGame.unk_8C88[3].s.imageY = 0;
        gTheGame.unk_8C88[3].s.imageH = 0x3C;
        gTheGame.unk_8C88[3].s.frameH = 0x3C;
        gTheGame.unk_8C88[3].s.imagePal = 0;
        gTheGame.unk_8C88[3].s.imageFlip = 0;
        gTheGame.unk_8C88[3].s.imageYorig = 0;
        gTheGame.unk_8BE0 = 0x30;
        gTheGame.unk_8BE8 = 0x100;
        var_s5 = 0xF;
        gTheGame.unk_8BEA = var_s5;
        gTheGame.unk_8BEC = 0;
        gTheGame.unk_8BEE = 0;
        gTheGame.unk_8BF0 = -1;
        gTheGame.unk_8BF4 = 0;
        gTheGame.unk_8C88[3].b.imagePtr = sp1C + var_s3;
        gTheGame.unk_8BE4 = sp1C + var_s3 + 0x780;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/other", InitMiscStuff);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/other", InitMiscStuff);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/other", InitMiscStuff);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/other", InitMiscStuff);
#endif

void UpdateMiscStuff(tetWell *well, cursor_t *cursor, s32 num) {
    s32 shake;

    switch (gSelection) {
        case 0x8C:
        case 0xAA:
        case 0xBE:
            if (gGameStatus & 0x20) {
                cursor->unk_0C = 0;
            } else if (cursor->unk_0C > 0) {
                if (gTheGame.unk_9B48 == 0) {
                    gTheGame.unk_9B48 = 1;
                }

                if (cursor->unk_0C > ADJUST_FRAMERATE(600)) {
                    shake = 0x32;
                } else if (cursor->unk_0C > ADJUST_FRAMERATE(360)) {
                    shake = 0x1E;
                } else if (cursor->unk_0C > ADJUST_FRAMERATE(120)) {
                    shake = 0xF;
                } else {
                    shake = 5;
                }

                if (gCounter % shake == 0) {
                    if (shake >= 0xF) {
                        if (gTheGame.unk_9B48 == 1) {
                            gTheGame.unk_9B48 = 2;
                        } else {
                            gTheGame.unk_9B48 = 1;
                        }
                    } else if (gTheGame.unk_9B48 == 1) {
                        gTheGame.unk_9B48 = 4;
                    } else if (gTheGame.unk_9B48 == 2) {
                        gTheGame.unk_9B48 = 3;
                    } else if (gTheGame.unk_9B48 == 3) {
                        gTheGame.unk_9B48 = 4;
                    } else {
                        gTheGame.unk_9B48 = 3;
                    }
                }
            } else {
                gTheGame.unk_9B48 = 0;
            }
            break;

        case 0x78:
        case 0x82:
            if (gTheGame.unk_9B48 > 1) {
                gTheGame.unk_9B48--;
            } else {
                gTheGame.unk_9B48 = -1;
            }

            if (cursor->unk_2C % 2 == 0) {
                gTheGame.drawText[3].word.s.imageAdrs = 0;
            } else {
                gTheGame.drawText[3].word.s.imageAdrs = 3;
            }
            break;

        case 0x64:
        case 0x96:
        case 0xA0:
        case 0xB4:
        case 0xC8:
            gTheGame.unk_9B48 = -1;
            gTheGame.unk_9B50[num].b.frameY = well->unk_441C * 4;
            break;
    }
}

void Draw2DMiscStuff(struct_gInfo_unk_00068 *dynamicp) {
    s32 index;

    if (gTheGame.unk_9B48 == 0) {
        return;
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &gTheGame.unk_9BF0);
    gDPSetRenderMode(glistp++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCycleType(glistp++, G_CYC_COPY);

    gDPPipeSync(glistp++);

    switch (gSelection) {
        case 0x8C:
        case 0xAA:
        case 0xBE:
            index = gTheGame.unk_9B48 - 1;
            gSPBgRectCopy(glistp++, &gTheGame.unk_9B50[index]);
            break;

        case 0x78:
        case 0x82:
            index = (gTheGame.unk_9B48 > 1) ? 1 : 0;
            gSPBgRectCopy(glistp++, &gTheGame.unk_9B50[index]);
            break;

        case 0x64:
        case 0x96:
        case 0xA0:
        case 0xB4:
        case 0xC8:
            gSPBgRectCopy(glistp++, &gTheGame.unk_9B50[0]);
            gSPBgRectCopy(glistp++, &gTheGame.unk_9B50[1]);
            break;
    }

    gDPPipeSync(glistp++);
    gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);

    if ((gSelection < 0x83) && (gMain >= GMAIN_384)) {
        gDPSetTextureLUT(glistp++, G_TT_RGBA16);
        gSPObjLoadTxtr(glistp++, &otherLUT);

        if (dynamicp->cursorBlock[0].unk_2C < 2) {
            gSPObjLoadTxtr(glistp++, &otherTexture9);
        } else if (dynamicp->cursorBlock[0].unk_2C < 4) {
            gSPObjLoadTxtr(glistp++, &otherTexture10);
        } else {
            gSPObjLoadTxtr(glistp++, &otherTexture11);
        }

        gSPObjRectangle(glistp++, &dynamicp->drawText[3].word);
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_NONE);
}

extern UNK_TYPE D_010192A8_usa;
extern UNK_TYPE D_010194C0_usa;
extern UNK_TYPE D_0101A4C0_usa;
extern UNK_TYPE D_0101ACC0_usa;
extern UNK_TYPE D_0101E4C0_usa;
extern UNK_TYPE D_0101E940_usa;
extern UNK_TYPE D_0101EDC0_usa;
extern UNK_TYPE D_0101F378_usa;

#if VERSION_USA
#if 0
void Draw3DMiscStuff(struct_gInfo_unk_00068 *dynamicp) {
    UNK_TYPE *var_v0;
    UNK_TYPE *var_v0_2;
    Gfx *temp_a2;
    Gfx *temp_t0;
    Gfx *temp_t3;
    Gfx *temp_v0;
    Gfx *temp_v0_2;
    Gfx *temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_a2;
    u32 var_a0;
    u32 var_a0_3;
    uObjBg *var_a1_2;

    if (gTheGame.unk_9C08 != 2) {
        if (gTheGame.unk_9B48 == 0) {
            temp_t3 = glistp;
            glistp = temp_t3 + 8;
            glistp = temp_t3 + 0x10;
            temp_t3->unk_C = 0x8000;
            glistp = temp_t3 + 0x18;
            temp_t3->unk_10 = 0xFD100000;
            temp_t3->unk_14 = &D_010192A8_usa;
            glistp = temp_t3 + 0x20;
            temp_t3->unk_18 = 0xE8000000;
            glistp = temp_t3 + 0x28;
            glistp = temp_t3 + 0x30;
            glistp = temp_t3 + 0x38;
            temp_t3->unk_30 = 0xF0000000;
            glistp = temp_t3 + 0x40;
            temp_t3->words.w0 = 0xE7000000;
            temp_t3->words.w1 = 0;
            temp_t3->unk_8 = 0xBA000E02;
            temp_t3->unk_1C = 0;
            temp_t3->unk_20 = 0xF5000100;
            temp_t3->unk_24 = 0x07000000;
            temp_t3->unk_28 = 0xE6000000;
            temp_t3->unk_2C = 0;
            temp_t3->unk_34 = 0x073FC000;
            temp_t3->unk_38 = 0xE7000000;
            temp_t3->unk_3C = 0;
            switch (gSelection) {                   /* switch 1; irregular */
                case 0xBE:                          /* switch 1 */
                    /* fallthrough */
                case 0x8C:                          /* switch 1 */
                    temp_t0 = glistp;
                    glistp = temp_t0 + 8;
                    temp_t0->words.w1 = (u32) &D_010194C0_usa;
                    glistp = temp_t0 + 0x10;
                    glistp = temp_t0 + 0x18;
                    glistp = temp_t0 + 0x20;
                    glistp = temp_t0 + 0x28;
                    glistp = temp_t0 + 0x30;
                    glistp = temp_t0 + 0x38;
                    glistp = temp_t0 + 0x40;
                    temp_t0->unk_3C = 0x04000000;
                    glistp = temp_t0 + 0x48;
                    glistp = temp_t0 + 0x50;
                    glistp = temp_t0 + 0x58;
                    temp_t0->unk_50 = 0xB4000000;
                    temp_t0->words.w0 = 0xFD500000;
                    temp_t0->unk_8 = 0xF5500000;
                    temp_t0->unk_C = 0x07000000;
                    temp_t0->unk_10 = 0xE6000000;
                    temp_t0->unk_14 = 0;
                    temp_t0->unk_18 = 0xF3000000;
                    temp_t0->unk_1C = 0x073FF100;
                    temp_t0->unk_20 = 0xE7000000;
                    temp_t0->unk_24 = 0;
                    temp_t0->unk_28 = 0xF5481000;
                    temp_t0->unk_2C = 0;
                    temp_t0->unk_30 = 0xF2000000;
                    temp_t0->unk_34 = 0xFC07C;
                    temp_t0->unk_38 = 0xF54810C0;
                    temp_t0->unk_40 = 0xF2000000;
                    temp_t0->unk_44 = 0x040FC01C;
                    temp_t0->unk_48 = 0xE44A01DC;
                    temp_t0->unk_4C = 0x043A01BC;
                    temp_t0->unk_54 = 0;
                    temp_t0->unk_58 = 0xB3000000;
                    temp_t0->unk_5C = 0x04000400;
                    temp_t0->unk_60 = 0xE7000000;
                    temp_t0->unk_64 = 0;
                    temp_v1 = gTheGame.tetrisWell[0].menu.unk_0;
                    glistp = temp_t0 + 0x60;
                    glistp = temp_t0 + 0x68;
                    switch (temp_v1) {              /* switch 2; irregular */
                        case 0x0:                   /* switch 2 */
                            glistp = temp_t0 + 0x70;
                            temp_t0->unk_6C = &D_0101A4C0_usa;
                            glistp = temp_t0 + 0x78;
                            glistp = temp_t0 + 0x80;
                            glistp = temp_t0 + 0x88;
                            glistp = temp_t0 + 0x90;
                            glistp = temp_t0 + 0x98;
                            glistp = temp_t0 + 0xA0;
                            glistp = temp_t0 + 0xA8;
                            temp_t0->unk_68 = 0xFD500000;
                            temp_t0->unk_70 = 0xF5500000;
                            temp_t0->unk_74 = 0x07000000;
                            temp_t0->unk_78 = 0xE6000000;
                            temp_t0->unk_7C = 0;
                            temp_t0->unk_80 = 0xF3000000;
                            temp_t0->unk_84 = 0x073FF100;
                            temp_t0->unk_88 = 0xE7000000;
                            temp_t0->unk_8C = 0;
                            temp_t0->unk_90 = 0xF5481000;
                            temp_t0->unk_94 = 0;
                            temp_t0->unk_98 = 0xF2000000;
                            temp_t0->unk_9C = 0xFC07C;
                            temp_t0->unk_A0 = 0xF5481000;
block_22:
                            temp_t0->unk_A4 = 0x05000000;
                            break;
                        case 0x1:                   /* switch 2 */
                            glistp = temp_t0 + 0x70;
                            var_v0 = &D_0101A4C0_usa;
block_21:
                            temp_t0->unk_6C = var_v0;
                            glistp = temp_t0 + 0x78;
                            glistp = temp_t0 + 0x80;
                            glistp = temp_t0 + 0x88;
                            glistp = temp_t0 + 0x90;
                            glistp = temp_t0 + 0x98;
                            glistp = temp_t0 + 0xA0;
                            glistp = temp_t0 + 0xA8;
                            temp_t0->unk_68 = 0xFD500000;
                            temp_t0->unk_70 = 0xF5500000;
                            temp_t0->unk_74 = 0x07000000;
                            temp_t0->unk_78 = 0xE6000000;
                            temp_t0->unk_7C = 0;
                            temp_t0->unk_80 = 0xF3000000;
                            temp_t0->unk_84 = 0x073FF100;
                            temp_t0->unk_88 = 0xE7000000;
                            temp_t0->unk_8C = 0;
                            temp_t0->unk_90 = 0xF5481000;
                            temp_t0->unk_94 = 0;
                            temp_t0->unk_98 = 0xF2000000;
                            temp_t0->unk_9C = 0xFC07C;
                            temp_t0->unk_A0 = 0xF5481080;
                            goto block_22;
                        case 0x2:                   /* switch 2 */
                            glistp = temp_t0 + 0x70;
                            temp_t0->unk_6C = &D_0101ACC0_usa;
                            glistp = temp_t0 + 0x78;
                            glistp = temp_t0 + 0x80;
                            glistp = temp_t0 + 0x88;
                            glistp = temp_t0 + 0x90;
                            glistp = temp_t0 + 0x98;
                            glistp = temp_t0 + 0xA0;
                            glistp = temp_t0 + 0xA8;
                            temp_t0->unk_68 = 0xFD500000;
                            temp_t0->unk_70 = 0xF5500000;
                            temp_t0->unk_74 = 0x07000000;
                            temp_t0->unk_78 = 0xE6000000;
                            temp_t0->unk_7C = 0;
                            temp_t0->unk_80 = 0xF3000000;
                            temp_t0->unk_84 = 0x073FF100;
                            temp_t0->unk_88 = 0xE7000000;
                            temp_t0->unk_8C = 0;
                            temp_t0->unk_90 = 0xF5481000;
                            temp_t0->unk_94 = 0;
                            temp_t0->unk_98 = 0xF2000000;
                            temp_t0->unk_9C = 0xFC07C;
                            temp_t0->unk_A0 = 0xF5481000;
                            goto block_22;
                        case 0x3:                   /* switch 2 */
                            glistp = temp_t0 + 0x70;
                            var_v0 = &D_0101ACC0_usa;
                            goto block_21;
                    }
                    var_a0 = 0x050FC03C;
                    var_a2 = 0xE44A0224;
                    var_a1 = 0x053A01E4;
                    goto block_57;
                case 0xAA:                          /* switch 1 */
                    if (gTheGame.tetrisWell[0].menu.unk_0 != 5) {
                        glistp = temp_t3 + 0x48;
                        temp_t3->unk_40 = 0xFD500000;
                        temp_t3->unk_44 = &D_010194C0_usa;
                        glistp = temp_t3 + 0x50;
                        temp_t3->unk_48 = 0xF5500000;
                        glistp = temp_t3 + 0x58;
                        glistp = temp_t3 + 0x60;
                        temp_t3->unk_58 = 0xF3000000;
                        glistp = temp_t3 + 0x68;
                        glistp = temp_t3 + 0x70;
                        temp_t3->unk_5C = 0x073FF100;
                        glistp = temp_t3 + 0x78;
                        glistp = temp_t3 + 0x80;
                        temp_t3->unk_7C = 0x04000000;
                        glistp = temp_t3 + 0x88;
                        glistp = temp_t3 + 0x90;
                        glistp = temp_t3 + 0x98;
                        temp_t3->unk_90 = 0xB4000000;
                        temp_t3->unk_4C = 0x07000000;
                        temp_t3->unk_50 = 0xE6000000;
                        temp_t3->unk_54 = 0;
                        temp_t3->unk_60 = 0xE7000000;
                        temp_t3->unk_64 = 0;
                        temp_t3->unk_68 = 0xF5481000;
                        temp_t3->unk_6C = 0;
                        temp_t3->unk_70 = 0xF2000000;
                        temp_t3->unk_74 = 0xFC07C;
                        temp_t3->unk_78 = 0xF54810C0;
                        temp_t3->unk_80 = 0xF2000000;
                        temp_t3->unk_84 = 0x040FC01C;
                        temp_t3->unk_88 = 0xE44A01DC;
                        temp_t3->unk_8C = 0x043A01BC;
                        temp_t3->unk_94 = 0;
                        glistp = temp_t3 + 0xA0;
                        temp_t3->unk_98 = 0xB3000000;
                        temp_t3->unk_9C = 0x04000400;
                        glistp = temp_t3 + 0xA8;
                        temp_t3->unk_A0 = 0xE7000000;
                        temp_t3->unk_A4 = 0;
                    }
                    break;
            }
            goto block_59;
        }
        temp_v0 = glistp;
        temp_v0->unk_8 = 0xBA000E02;
        temp_v0->unk_C = 0x8000;
        temp_v0->words.w0 = 0xE7000000;
        temp_v0->words.w1 = 0;
        temp_v0->unk_10 = 0xFD100000;
        glistp = temp_v0 + 8;
        glistp = temp_v0 + 0x10;
        glistp = temp_v0 + 0x18;
        glistp = temp_v0 + 0x20;
        temp_v0->unk_18 = 0xE8000000;
        glistp = temp_v0 + 0x28;
        temp_v0->unk_24 = 0x07000000;
        glistp = temp_v0 + 0x30;
        temp_v0->unk_28 = 0xE6000000;
        glistp = temp_v0 + 0x38;
        temp_v0->unk_30 = 0xF0000000;
        glistp = temp_v0 + 0x40;
        temp_v0->unk_1C = 0;
        temp_v0->unk_20 = 0xF5000100;
        temp_v0->unk_2C = 0;
        temp_v0->unk_34 = 0x073FC000;
        temp_v0->unk_38 = 0xE7000000;
        temp_v0->unk_3C = 0;
        glistp = temp_v0 + 0x48;
        temp_v0->unk_40 = 0xE7000000;
        temp_v0->unk_44 = 0;
        temp_v0->unk_14 = (u64 *) gTheGame.unk_9BF0.block.image;
        switch (gSelection) {                       /* irregular */
            case 0xBE:
            case 0xAA:
            case 0x8C:
                var_a1_2 = ((gTheGame.unk_9B48 - 1) * 0x28) + (&gTheGame.unk_9B48 + 8);
block_45:
                guS2DEmuBgRect1Cyc(&glistp, var_a1_2);
                break;
            case 0x82:
                var_a1_2 = (((gTheGame.unk_9B48 < 2) ^ 1) * 0x28) + (&gTheGame.unk_9C08 - 0xB8);
                goto block_45;
            case 0xA0:
            case 0xB4:
            case 0xC8:
            case 0x96:
            case 0x64:
                guS2DEmuBgRect1Cyc(&glistp, gTheGame.unk_9B50);
                var_a1_2 = gTheGame.unk_9B50 + 0x28;
                goto block_45;
        }
        if (gSelection < 0x83) {
            var_a0_2 = 0xBA000E02;
            if (gMain >= 0x384) {
                temp_a2 = glistp;
                temp_a2->unk_8 = 0xBA000E02;
                temp_a2->unk_C = 0x8000;
                temp_a2->unk_10 = 0xFD100000;
                temp_a2->unk_14 = &D_010192A8_usa;
                temp_a2->unk_18 = 0xE8000000;
                temp_a2->words.w0 = 0xE7000000;
                temp_a2->words.w1 = 0;
                temp_a2->unk_1C = 0;
                temp_a2->unk_20 = 0xF5000100;
                temp_a2->unk_24 = 0x07000000;
                temp_a2->unk_28 = 0xE6000000;
                temp_a2->unk_2C = 0;
                temp_a2->unk_30 = 0xF0000000;
                temp_a2->unk_34 = 0x073FC000;
                temp_a2->unk_38 = 0xE7000000;
                temp_a2->unk_3C = 0;
                temp_v1_2 = dynamicp->cursorBlock[0].unk_2C;
                glistp = temp_a2 + 8;
                glistp = temp_a2 + 0x10;
                glistp = temp_a2 + 0x18;
                glistp = temp_a2 + 0x20;
                glistp = temp_a2 + 0x28;
                glistp = temp_a2 + 0x30;
                glistp = temp_a2 + 0x38;
                glistp = temp_a2 + 0x40;
                if (temp_v1_2 < 2) {
                    glistp = temp_a2 + 0x48;
                    temp_a2->unk_40 = 0xFD500000;
                    var_v0_2 = &D_0101E4C0_usa;
                } else if (temp_v1_2 < 4) {
                    glistp = temp_a2 + 0x48;
                    temp_a2->unk_40 = 0xFD500000;
                    var_v0_2 = &D_0101E940_usa;
                } else {
                    glistp = temp_a2 + 0x48;
                    temp_a2->unk_40 = 0xFD500000;
                    var_v0_2 = &D_0101EDC0_usa;
                }
                temp_a2->unk_44 = var_v0_2;
                glistp = temp_a2 + 0x50;
                temp_a2->unk_48 = 0xF5500000;
                glistp = temp_a2 + 0x58;
                glistp = temp_a2 + 0x60;
                temp_a2->unk_58 = 0xF3000000;
                glistp = temp_a2 + 0x68;
                glistp = temp_a2 + 0x70;
                glistp = temp_a2 + 0x78;
                temp_a2->unk_4C = 0x07000000;
                temp_a2->unk_50 = 0xE6000000;
                temp_a2->unk_54 = 0;
                temp_a2->unk_5C = 0x0723F156;
                temp_a2->unk_60 = 0xE7000000;
                temp_a2->unk_64 = 0;
                temp_a2->unk_68 = 0xF5480C00;
                temp_a2->unk_6C = 0;
                temp_a2->unk_70 = 0xF2000000;
                temp_a2->unk_74 = 0xBC05C;
                if (!(dynamicp->cursorBlock[0].unk_2C & 1)) {
                    var_a0_3 = 0xF5480C00;
                } else {
                    var_a0_3 = 0xF5480C03;
                }
                glistp += 8;
                glistp->words.w0 = var_a0_3;
                glistp->words.w1 = 0x03000000;
                var_a0 = 0x0305C05C;
                var_a2 = 0xE44341A0;
                var_a1 = 0x033D4140;
block_57:
                temp_v0_2 = glistp;
                glistp = temp_v0_2 + 8;
                temp_v0_2->words.w0 = 0xF2000000;
                glistp = temp_v0_2 + 0x10;
                glistp = temp_v0_2 + 0x18;
                temp_v0_2->unk_10 = 0xB4000000;
                glistp = temp_v0_2 + 0x20;
                temp_v0_2->unk_18 = 0xB3000000;
                glistp = temp_v0_2 + 0x28;
                temp_v0_2->words.w1 = var_a0;
                temp_v0_2->unk_8 = var_a2;
                temp_v0_2->unk_C = var_a1;
                temp_v0_2->unk_14 = 0;
                temp_v0_2->unk_1C = 0x04000400;
                temp_v0_2->unk_20 = 0xE7000000;
                temp_v0_2->unk_24 = 0;
                goto block_59;
            }
        } else {
block_59:
            var_a0_2 = 0xBA000E02;
        }
        temp_v0_3 = glistp;
        glistp = temp_v0_3 + 8;
        glistp = temp_v0_3 + 0x10;
        temp_v0_3->unk_C = 0x8000;
        glistp = temp_v0_3 + 0x18;
        temp_v0_3->unk_10 = 0xFD100000;
        temp_v0_3->unk_14 = &D_0101F378_usa;
        glistp = temp_v0_3 + 0x20;
        temp_v0_3->unk_18 = 0xE8000000;
        glistp = temp_v0_3 + 0x28;
        temp_v0_3->unk_24 = 0x07000000;
        glistp = temp_v0_3 + 0x30;
        temp_v0_3->unk_28 = 0xE6000000;
        glistp = temp_v0_3 + 0x38;
        temp_v0_3->unk_30 = 0xF0000000;
        temp_v0_3->words.w0 = 0xE7000000;
        temp_v0_3->words.w1 = 0;
        temp_v0_3->unk_8 = var_a0_2;
        temp_v0_3->unk_1C = 0;
        temp_v0_3->unk_20 = 0xF5000100;
        temp_v0_3->unk_2C = 0;
        temp_v0_3->unk_34 = 0x073FC000;
        glistp = temp_v0_3 + 0x40;
        temp_v0_3->unk_38 = 0xE7000000;
        temp_v0_3->unk_3C = 0;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/other", Draw3DMiscStuff);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/other", Draw3DMiscStuff);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/other", Draw3DMiscStuff);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/other", Draw3DMiscStuff);
#endif

void func_80053E64_usa(struct_gInfo_unk_00068 *dynamicp UNUSED) {
    if (gTheGame.unk_9C08 != 1) {
        gDPPipeSync(glistp++);
        gDPSetTexturePersp(glistp++, G_TP_NONE);
        gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPSetRenderMode(glistp++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

        gDPPipeSync(glistp++);
        gDPSetTextureLUT(glistp++, G_TT_RGBA16);
        gDPLoadTLUT_pal256(glistp++, gTheGame.unk_9BF0.tlut.image);

        guS2DEmuBgRect1Cyc(&glistp, &gTheGame.unk_9B50[0]);
        guS2DEmuBgRect1Cyc(&glistp, &gTheGame.unk_9B50[1]);
    }
}
