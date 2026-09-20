/**
 * Original filename: draw3d.c
 */

#include "draw3d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "attack3d.h"
#include "bkground.h"
#include "bonus.h"
#include "character.h"
#include "flic.h"
#include "info.h"
#include "init3d.h"
#include "other.h"
#include "sign.h"
#include "text.h"
#include "the_game.h"

#include "assets_variables.h"

/**
 * Original nanme: Set3DTile
 */
void Set3DTile(void) {
    gDPPipeSync(glistp++);
    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, G_TX_RENDERTILE, 0, 0, 0x003C, 0x003C);
    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0002, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 1, 0, 0, 0x003C, 0x003C);
    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0004, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 2, 0, 0, 0x003C, 0x003C);
    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0006, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 3, 0, 0, 0x003C, 0x003C);
    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0080, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 4, 0, 0, 0x003C, 0x003C);
    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0082, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 5, 0, 0, 0x003C, 0x003C);
    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0084, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 6, 0, 0, 0x003C, 0x003C);
    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0086, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
               G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, G_TX_LOADTILE, 0, 0, 0x003C, 0x003C);
}

void func_8005E740_usa(void) {
    gDPPipeSync(glistp++);
    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0086, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
               G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, G_TX_LOADTILE, 0, 0, 0x003C, 0x003C);
}

/**
 * Original nanme: Set3DExplodeTile
 */
void Set3DExplodeTile(void) {
    gDPPipeSync(glistp++);

    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
               G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, G_TX_RENDERTILE, 0, 0, 0x003C, 0x003C);

    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0002, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 1, 0, 0, 0x001C, 0x001C);

    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0003, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 2, 0, 0, 0x001C, 0x001C);

    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0004, 3, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 3, 0, 0, 0x001C, 0x001C);

    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0005, 4, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 4, 0, 0, 0x001C, 0x001C);

    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0042, 5, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 5, 0, 0, 0x001C, 0x001C);

    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0043, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 6, 0, 0, 0x001C, 0x001C);

    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0044, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
               G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, G_TX_LOADTILE, 0, 0, 0x001C, 0x001C);
}

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/draw3d", RO_800C6E40_usa);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/draw3d", RO_800C70F0_eur);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/draw3d", RO_800C5750_fra);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/draw3d", RO_800BC710_ger);
#endif

#if VERSION_USA
#if 0
? Draw3DTetrisBlockSide(s32, s32, s32, s8);             /* extern */
extern ? RO_800C6E40_usa;

void Draw3DFrontTetrisWell(struct_gInfo_unk_00068 *dynamicp, s32 num) {
    ? sp10;
    u8 sp11;
    ? sp14;
    ? sp18;
    s8 sp1C;
    s8 sp1D;
    struct_gInfo_unk_00068 *sp24;
    s32 sp2C;
    s32 sp34;
    cursor_t *sp3C;
    void *sp44;
    void *sp4C;
    s32 sp54;
    ? *sp5C;
    ? *var_t2;
    Gfx *temp_t0;
    Gfx *temp_v1;
    Gfx *temp_v1_2;
    block_t *var_a2;
    block_t *var_a3;
    s32 temp_a0;
    s32 temp_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s3;
    s32 var_v1;
    s8 *var_s2;
    s8 *var_s2_2;
    s8 temp_a3;
    s8 temp_a3_2;
    u64 *var_s5;
    u8 *var_s4;
    u8 temp_v0;
    void *temp_a3_3;
    void *temp_v0_2;
    void *var_s1;
    void *var_s1_2;
    void *var_s6;
    void *var_s7;

    var_s5 = saved_reg_s5;
    sp24 = dynamicp;
    sp2C = num;
    sp34 = 9;
    sp10 = (unaligned s32) RO_800C6E40_usa.unk_0;
    sp14 = (unaligned s32) RO_800C6E40_usa.unk_4;
    sp18 = (unaligned s32) RO_800C6E40_usa.unk_8;
    sp1C = RO_800C6E40_usa.unk_C;
    sp1D = RO_800C6E40_usa.unk_D;
    temp_t0 = glistp;
    glistp = temp_t0 + 8;
    glistp = temp_t0 + 0x10;
    temp_t0->words.w0 = 0xE7000000;
    temp_t0->words.w1 = 0;
    temp_t0->unk_8 = 0xBA000E02;
    temp_t0->unk_C = 0x8000;
    sp4C = sp24 + ((sp2C * 0x2520) + 0x10244);
    sp44 = sp24 + ((sp2C * 0xD8) + 0x18308);
    sp3C = &sp24->cursorBlock[sp2C];
    if (gGameStatus & 0x40) {
        glistp = temp_t0 + 0x18;
        sp34 = 6;
        temp_t0->unk_10 = 0xFD100000;
        temp_t0->unk_14 = colorTable;
        glistp = temp_t0 + 0x20;
        temp_t0->unk_18 = 0xE8000000;
        glistp = temp_t0 + 0x28;
        temp_t0->unk_24 = 0x07000000;
        glistp = temp_t0 + 0x30;
        temp_t0->unk_28 = 0xE6000000;
        glistp = temp_t0 + 0x38;
        temp_t0->unk_30 = 0xF0000000;
        temp_t0->unk_1C = 0;
        temp_t0->unk_20 = 0xF5000100;
        temp_t0->unk_2C = 0;
        temp_t0->unk_34 = 0x073FC000;
        glistp = temp_t0 + 0x40;
        temp_t0->unk_38 = 0xE7000000;
        temp_t0->unk_3C = 0;
        if (gMain >= 0x38E) {
            sp34 = 9;
        }
    } else {
        glistp = temp_t0 + 0x18;
        temp_t0->unk_10 = 0xFD100000;
        temp_t0->unk_14 = D_010001F0_usa;
        glistp = temp_t0 + 0x20;
        temp_t0->unk_18 = 0xE8000000;
        glistp = temp_t0 + 0x28;
        temp_t0->unk_24 = 0x07000000;
        glistp = temp_t0 + 0x30;
        temp_t0->unk_28 = 0xE6000000;
        glistp = temp_t0 + 0x38;
        temp_t0->unk_30 = 0xF0000000;
        temp_t0->unk_1C = 0;
        temp_t0->unk_20 = 0xF5000100;
        temp_t0->unk_2C = 0;
        temp_t0->unk_34 = 0x073FC000;
        glistp = temp_t0 + 0x40;
        temp_t0->unk_38 = 0xE7000000;
        temp_t0->unk_3C = 0;
        if (gMain >= 0x38E) {
            sp34 = 0xD;
        }
    }
    Set3DTile();
    if (sp34 != 0) {
        var_s4 = &sp11;
        sp54 = 0x10208;
        sp5C = &sp10;
        var_t2 = &sp10;
        do {
            if (var_s4 == (var_t2 + 1)) {
                var_s5 = NULL;
                goto block_10;
            }
            if (*((sp2C * 0xE) + sp24 + sp54 + *var_s4) != 0) {
block_10:
                temp_v0 = *var_s4;
                switch (temp_v0) {
                    case 0x1:
                        var_s5 = tetrisBlock1.block.image;
                        break;
                    case 0x2:
                        var_s5 = tetrisBlock2.block.image;
                        break;
                    case 0x3:
                        var_s5 = tetrisBlock3.block.image;
                        break;
                    case 0x4:
                        var_s5 = tetrisBlock4.block.image;
                        break;
                    case 0x5:
                        var_s5 = tetrisBlock5.block.image;
                        break;
                    case 0x6:
                        var_s5 = tetrisBlock6.block.image;
                        break;
                    case 0x7:
                        var_s5 = tetrisBlock7.block.image;
                        break;
                    case 0x8:
                        var_s5 = tetrisBlock8.block.image;
                        break;
                    case 0x9:
                        var_s5 = tetrisBlock9.block.image;
                        break;
                    case 0xA:
                        var_s5 = (u64 *) D_01005C68_usa;
                        break;
                    case 0xB:
                        var_s5 = (u64 *) D_01006468_usa;
                        break;
                    case 0xC:
                        var_s5 = (u64 *) D_01006C68_usa;
                        break;
                    case 0xD:
                        var_s5 = (u64 *) D_01007468_usa;
                        break;
                }
                if (var_s5 != NULL) {
                    temp_v1 = glistp;
                    glistp = temp_v1 + 8;
                    temp_v1->words.w0 = 0xFD500000;
                    glistp = temp_v1 + 0x10;
                    temp_v1->unk_8 = 0xF5500000;
                    temp_v1->unk_C = 0x07000000;
                    glistp = temp_v1 + 0x18;
                    temp_v1->unk_10 = 0xE6000000;
                    glistp = temp_v1 + 0x20;
                    temp_v1->unk_18 = 0xF3000000;
                    glistp = temp_v1 + 0x28;
                    temp_v1->unk_20 = 0xE7000000;
                    glistp = temp_v1 + 0x30;
                    glistp = temp_v1 + 0x38;
                    temp_v1->words.w1 = (u32) var_s5;
                    temp_v1->unk_14 = 0;
                    temp_v1->unk_1C = 0x073FF100;
                    temp_v1->unk_24 = 0;
                    temp_v1->unk_28 = 0xF5481000;
                    temp_v1->unk_2C = 0;
                    temp_v1->unk_30 = 0xF2000000;
                    temp_v1->unk_34 = 0xFC07C;
                }
                var_s3 = 0;
                temp_v1_2 = glistp;
                var_s7 = sp44;
                var_s6 = sp4C;
                glistp = temp_v1_2 + 8;
                temp_v1_2->words.w0 = 0xE7000000;
                glistp = temp_v1_2 + 0x10;
                temp_v1_2->unk_C = 0x07000000;
                glistp = temp_v1_2 + 0x18;
                temp_v1_2->words.w1 = 0;
                temp_v1_2->unk_8 = 0xF5481086;
                temp_v1_2->unk_10 = 0xF2000000;
                temp_v1_2->unk_14 = 0x0703C03C;
                do {
                    var_s0 = 1;
                    var_s2 = var_s7 + 1;
                    var_s1 = var_s6 + 0x2C;
loop_29:
                    temp_a3 = *var_s2;
                    if (temp_a3 != 0) {
                        if ((var_s4 == (sp5C + 1)) && (temp_a3 >= 2)) {
                            Draw3DTetrisBlockSide(var_s3, var_s0, var_s1->unk_10, temp_a3);
                            if ((var_s1->unk_24 == sp11) && (*var_s2 < 4)) {
                                Draw3DTetrisBlock2(var_s0, var_s1->unk_10);
                                var_s2 += 1;
                            } else {
                                goto block_38;
                            }
                        } else {
                            if ((var_s1->unk_24 == *var_s4) && (*var_s2 < 4)) {
                                Draw3DTetrisBlock1(var_s3, var_s0, var_s1->unk_10);
                            }
                            goto block_38;
                        }
                    } else {
block_38:
                        var_s2 += 1;
                    }
                    var_s0 += 1;
                    var_s1 += 0x2C;
                    if (var_s0 < 5) {
                        goto loop_29;
                    }
                    var_s0_2 = 8;
                    var_s2_2 = var_s7 + 8;
                    var_s1_2 = var_s6 + 0x160;
loop_41:
                    temp_a3_2 = *var_s2_2;
                    if (temp_a3_2 != 0) {
                        if ((var_s4 == (sp5C + 1)) && (temp_a3_2 >= 2)) {
                            Draw3DTetrisBlockSide(var_s3, var_s0_2, var_s1_2->unk_10, temp_a3_2);
                            if ((var_s1_2->unk_24 == sp11) && (*var_s2_2 < 4)) {
                                Draw3DTetrisBlock2(var_s0_2, var_s1_2->unk_10);
                                var_s2_2 -= 1;
                            } else {
                                goto block_50;
                            }
                        } else {
                            if ((var_s1_2->unk_24 == *var_s4) && (*var_s2_2 < 4)) {
                                Draw3DTetrisBlock1(var_s3, var_s0_2, var_s1_2->unk_10);
                            }
                            goto block_50;
                        }
                    } else {
block_50:
                        var_s2_2 -= 1;
                    }
                    var_s0_2 -= 1;
                    var_s1_2 -= 0x2C;
                    if (var_s0_2 >= 5) {
                        goto loop_41;
                    }
                    var_s7 += 0x12;
                    var_s3 += 1;
                    var_s6 += 0x318;
                } while (var_s3 < 0xC);
                temp_a2 = sp3C->sy;
                if (temp_a2 != -1) {
                    if (gMain < 0x38E) {
                        if (*var_s4 == 3) {
                            temp_a3_3 = sp4C + (temp_a2 * 0x318);
                            var_a2 = temp_a3_3 + 0xDC;
                            var_a3 = temp_a3_3 + 0xB0;
                            goto block_61;
                        }
                    } else {
                        temp_v0_2 = (temp_a2 * 0x318) + sp4C;
                        var_v1 = temp_v0_2->unk_100;
                        temp_a0 = temp_v0_2->unk_D4;
                        var_a2 = temp_v0_2 + 0xDC;
                        var_a3 = temp_v0_2 + 0xB0;
                        if (var_v1 < temp_a0) {
                            var_v1 = temp_a0;
                        }
                        if (*var_s4 == var_v1) {
block_61:
                            Draw3DTetrisSwitch(sp24, sp2C, var_a2, var_a3);
                        }
                    }
                }
            }
            var_t2 = sp5C;
            var_s4 += 1;
        } while ((s32) (sp34 + var_t2) >= (s32) var_s4);
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DFrontTetrisWell);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DFrontTetrisWell);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DFrontTetrisWell);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DFrontTetrisWell);
#endif

#if VERSION_USA
#if 0
? Draw3DTetrisBlockSide(s32, s32, s32, s8);             /* extern */
extern ? RO_800C6E40_usa;

void Draw3DBackTetrisWell(struct_gInfo_unk_00068 *dynamicp, s32 num) {
    ? sp10;
    u8 sp11;
    ? sp14;
    ? sp18;
    s8 sp1C;
    s8 sp1D;
    struct_gInfo_unk_00068 *sp24;
    s32 sp2C;
    s32 sp34;
    s8 *sp3C;
    void *sp44;
    s32 sp4C;
    ? *sp54;
    s32 sp5C;
    ? *var_t1;
    Gfx *temp_a3;
    Gfx *temp_v1;
    Gfx *temp_v1_2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s3;
    s8 *var_s2;
    s8 *var_s2_2;
    s8 *var_s4;
    s8 temp_a3_2;
    s8 temp_a3_3;
    s8 temp_a3_4;
    u64 *var_s5;
    u8 *var_s6;
    u8 temp_v0;
    void *temp_s0;
    void *var_s1;
    void *var_s1_2;
    void *var_s7;

    var_s5 = saved_reg_s5;
    sp24 = dynamicp;
    sp2C = num;
    sp34 = 9;
    sp10 = (unaligned s32) RO_800C6E40_usa.unk_0;
    sp14 = (unaligned s32) RO_800C6E40_usa.unk_4;
    sp18 = (unaligned s32) RO_800C6E40_usa.unk_8;
    sp1C = RO_800C6E40_usa.unk_C;
    sp1D = RO_800C6E40_usa.unk_D;
    temp_a3 = glistp;
    glistp = temp_a3 + 8;
    glistp = temp_a3 + 0x10;
    temp_a3->words.w0 = 0xE7000000;
    temp_a3->words.w1 = 0;
    temp_a3->unk_8 = 0xBA000E02;
    temp_a3->unk_C = 0x8000;
    sp44 = sp24 + ((sp2C * 0x2520) + 0x10244);
    sp3C = sp24 + ((sp2C * 0xD8) + 0x18308);
    if (gGameStatus & 0x40) {
        glistp = temp_a3 + 0x18;
        sp34 = 6;
        temp_a3->unk_10 = 0xFD100000;
        temp_a3->unk_14 = colorTable;
        glistp = temp_a3 + 0x20;
        temp_a3->unk_18 = 0xE8000000;
        glistp = temp_a3 + 0x28;
        temp_a3->unk_24 = 0x07000000;
        glistp = temp_a3 + 0x30;
        temp_a3->unk_28 = 0xE6000000;
        glistp = temp_a3 + 0x38;
        temp_a3->unk_30 = 0xF0000000;
        temp_a3->unk_1C = 0;
        temp_a3->unk_20 = 0xF5000100;
        temp_a3->unk_2C = 0;
        temp_a3->unk_34 = 0x073FC000;
        glistp = temp_a3 + 0x40;
        temp_a3->unk_38 = 0xE7000000;
        temp_a3->unk_3C = 0;
        if (gMain >= 0x38E) {
            sp34 = 9;
        }
    } else {
        glistp = temp_a3 + 0x18;
        temp_a3->unk_10 = 0xFD100000;
        temp_a3->unk_14 = D_010001F0_usa;
        glistp = temp_a3 + 0x20;
        temp_a3->unk_18 = 0xE8000000;
        glistp = temp_a3 + 0x28;
        temp_a3->unk_24 = 0x07000000;
        glistp = temp_a3 + 0x30;
        temp_a3->unk_28 = 0xE6000000;
        glistp = temp_a3 + 0x38;
        temp_a3->unk_30 = 0xF0000000;
        temp_a3->unk_1C = 0;
        temp_a3->unk_20 = 0xF5000100;
        temp_a3->unk_2C = 0;
        temp_a3->unk_34 = 0x073FC000;
        glistp = temp_a3 + 0x40;
        temp_a3->unk_38 = 0xE7000000;
        temp_a3->unk_3C = 0;
        if (gMain >= 0x38E) {
            sp34 = 0xD;
        }
    }
    Set3DTile();
    if (sp34 != 0) {
        var_s6 = &sp11;
        sp4C = 0x10224;
        sp54 = &sp10;
        var_t1 = &sp10;
        do {
            if (var_s6 == (var_t1 + 1)) {
                var_s5 = NULL;
                goto block_10;
            }
            if (*((sp2C * 0xE) + sp24 + sp4C + *var_s6) != 0) {
block_10:
                temp_v0 = *var_s6;
                switch (temp_v0) {
                    case 0x1:
                        var_s5 = tetrisBlock1.block.image;
                        break;
                    case 0x2:
                        var_s5 = tetrisBlock2.block.image;
                        break;
                    case 0x3:
                        var_s5 = tetrisBlock3.block.image;
                        break;
                    case 0x4:
                        var_s5 = tetrisBlock4.block.image;
                        break;
                    case 0x5:
                        var_s5 = tetrisBlock5.block.image;
                        break;
                    case 0x6:
                        var_s5 = tetrisBlock6.block.image;
                        break;
                    case 0x7:
                        var_s5 = tetrisBlock7.block.image;
                        break;
                    case 0x8:
                        var_s5 = tetrisBlock8.block.image;
                        break;
                    case 0x9:
                        var_s5 = tetrisBlock9.block.image;
                        break;
                    case 0xA:
                        var_s5 = (u64 *) D_01005C68_usa;
                        break;
                    case 0xB:
                        var_s5 = (u64 *) D_01006468_usa;
                        break;
                    case 0xC:
                        var_s5 = (u64 *) D_01006C68_usa;
                        break;
                    case 0xD:
                        var_s5 = (u64 *) D_01007468_usa;
                        break;
                }
                if (var_s5 != NULL) {
                    temp_v1 = glistp;
                    glistp = temp_v1 + 8;
                    temp_v1->words.w0 = 0xFD500000;
                    glistp = temp_v1 + 0x10;
                    temp_v1->unk_8 = 0xF5500000;
                    temp_v1->unk_C = 0x07000000;
                    glistp = temp_v1 + 0x18;
                    temp_v1->unk_10 = 0xE6000000;
                    glistp = temp_v1 + 0x20;
                    temp_v1->unk_18 = 0xF3000000;
                    glistp = temp_v1 + 0x28;
                    temp_v1->unk_20 = 0xE7000000;
                    glistp = temp_v1 + 0x30;
                    glistp = temp_v1 + 0x38;
                    temp_v1->words.w1 = (u32) var_s5;
                    temp_v1->unk_14 = 0;
                    temp_v1->unk_1C = 0x073FF100;
                    temp_v1->unk_24 = 0;
                    temp_v1->unk_28 = 0xF5481000;
                    temp_v1->unk_2C = 0;
                    temp_v1->unk_30 = 0xF2000000;
                    temp_v1->unk_34 = 0xFC07C;
                }
                var_s4 = sp3C;
                temp_v1_2 = glistp;
                var_s7 = sp44;
                var_s3 = 0;
                sp5C = 0;
                glistp = temp_v1_2 + 8;
                temp_v1_2->words.w0 = 0xE7000000;
                glistp = temp_v1_2 + 0x10;
                temp_v1_2->unk_C = 0x07000000;
                glistp = temp_v1_2 + 0x18;
                temp_v1_2->words.w1 = 0;
                temp_v1_2->unk_8 = 0xF5481086;
                temp_v1_2->unk_10 = 0xF2000000;
                temp_v1_2->unk_14 = 0x0703C03C;
                do {
                    var_s0 = 0xD;
                    var_s2 = var_s4 + 0xD;
                    var_s1 = var_s7 + 0x23C;
loop_29:
                    temp_a3_2 = *var_s2;
                    if (temp_a3_2 != 0) {
                        if ((var_s6 == (sp54 + 1)) && (temp_a3_2 >= 2)) {
                            Draw3DTetrisBlockSide(var_s3, var_s0, var_s1->unk_10, temp_a3_2);
                            if ((var_s1->unk_24 == sp11) && (*var_s2 < 4)) {
                                Draw3DTetrisBlock2(var_s0, var_s1->unk_10);
                                var_s2 -= 1;
                            } else {
                                goto block_38;
                            }
                        } else {
                            if ((var_s1->unk_24 == *var_s6) && (*var_s2 < 4)) {
                                Draw3DTetrisBlock1(var_s3, var_s0, var_s1->unk_10);
                            }
                            goto block_38;
                        }
                    } else {
block_38:
                        var_s2 -= 1;
                    }
                    var_s0 -= 1;
                    var_s1 -= 0x2C;
                    if (var_s0 >= 9) {
                        goto loop_29;
                    }
                    var_s0_2 = 0xE;
                    var_s2_2 = var_s4 + 0xE;
                    var_s1_2 = var_s7 + 0x268;
loop_41:
                    temp_a3_3 = *var_s2_2;
                    if (temp_a3_3 != 0) {
                        if ((var_s6 == (sp54 + 1)) && (temp_a3_3 >= 2)) {
                            Draw3DTetrisBlockSide(var_s3, var_s0_2, var_s1_2->unk_10, temp_a3_3);
                            if ((var_s1_2->unk_24 == sp11) && (*var_s2_2 < 4)) {
                                Draw3DTetrisBlock2(var_s0_2, var_s1_2->unk_10);
                                var_s2_2 += 1;
                            } else {
                                goto block_50;
                            }
                        } else {
                            if ((var_s1_2->unk_24 == *var_s6) && (*var_s2_2 < 4)) {
                                Draw3DTetrisBlock1(var_s3, var_s0_2, var_s1_2->unk_10);
                            }
                            goto block_50;
                        }
                    } else {
block_50:
                        var_s2_2 += 1;
                    }
                    var_s0_2 += 1;
                    var_s1_2 += 0x2C;
                    if (var_s0_2 < 0x12) {
                        goto loop_41;
                    }
                    temp_a3_4 = *var_s4;
                    temp_s0 = sp44 + sp5C;
                    if (temp_a3_4 != 0) {
                        if ((var_s6 == (sp54 + 1)) && (temp_a3_4 >= 2)) {
                            Draw3DTetrisBlockSide(var_s3, 0, temp_s0->unk_10, temp_a3_4);
                            if ((temp_s0->unk_24 == sp11) && (*var_s4 < 4)) {
                                Draw3DTetrisBlock2(0, temp_s0->unk_10);
                                var_s4 += 0x12;
                            } else {
                                goto block_61;
                            }
                        } else {
                            if ((temp_s0->unk_24 == *var_s6) && (*var_s4 < 4)) {
                                Draw3DTetrisBlock1(var_s3, 0, temp_s0->unk_10);
                            }
                            goto block_61;
                        }
                    } else {
block_61:
                        var_s4 += 0x12;
                    }
                    var_s7 += 0x318;
                    var_s3 += 1;
                    sp5C += 0x318;
                } while (var_s3 < 0xC);
            }
            var_t1 = sp54;
            var_s6 += 1;
        } while ((s32) (sp34 + var_t1) >= (s32) var_s6);
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DBackTetrisWell);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DBackTetrisWell);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DBackTetrisWell);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DBackTetrisWell);
#endif

/**
 * Original nanme: Draw3DTetrisBlock1
 */
void Draw3DTetrisBlock1(s32 row, s32 col, BlockType type) {
    if (type == BLOCKTYPE_9) {
        return;
    }

    gSPVertex(glistp++, &gAllVertex[GET_VTX3D_INDEX(row, col)], VTX3D_VERTICES_PER_BLOCK, 0);
    gSPTexture(glistp++, 0x8000, 0x8000, 0, type - 1, G_ON);

    if ((col >= 9) || (col <= 0)) {
        gSP2Triangles(glistp++, 4, 5, 6, 0, 4, 7, 5, 0);
    } else {
        gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
    }
}

/**
 * Original nanme: Draw3DTetrisBlock2
 */
void Draw3DTetrisBlock2(s32 col, BlockType type) {
    if (type == BLOCKTYPE_9) {
        return;
    }

    gSPTexture(glistp++, 0x8000, 0x8000, 0, type - 1, G_ON);
    if ((col >= 9) || (col <= 0)) {
        gSP2Triangles(glistp++, 4, 5, 6, 0, 4, 7, 5, 0);
    } else {
        gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
    }
}

/**
 * Original nanme: Draw3DTetrisBlockSide
 */
void Draw3DTetrisBlockSide(s32 row, s32 col, BlockType type, s32 flag) {
    gSPVertex(glistp++, &gAllVertex[GET_VTX3D_INDEX(row, col)], VTX3D_VERTICES_PER_BLOCK, 0);

    gDPPipeSync(glistp++);
    gDPSetCombineMode(glistp++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);

    switch (type) {
        case BLOCKTYPE_1:
            gDPSetPrimColor(glistp++, 0, 0, 0, 90, 0, 255);
            break;

        case BLOCKTYPE_2:
            gDPSetPrimColor(glistp++, 0, 0, 66, 0, 140, 255);
            break;

        case BLOCKTYPE_4:
            gDPSetPrimColor(glistp++, 0, 0, 82, 74, 0, 255);
            break;

        case BLOCKTYPE_3:
            gDPSetPrimColor(glistp++, 0, 0, 90, 0, 0, 255);
            break;

        case BLOCKTYPE_5:
            gDPSetPrimColor(glistp++, 0, 0, 0, 107, 107, 255);
            break;

        case BLOCKTYPE_6:
            gDPSetPrimColor(glistp++, 0, 0, 0, 0, 148, 255);
            break;

        case BLOCKTYPE_7:
            gDPSetPrimColor(glistp++, 0, 0, 123, 123, 123, 255);
            break;

        case BLOCKTYPE_8:
        default:
            gDPSetPrimColor(glistp++, 0, 0, 68, 68, 68, 255);
            break;

    }

    if (!(flag & 1)) {
        gSP2Triangles(glistp++, 4, 0, 3, 0, 3, 7, 4, 0);
    } else {
        gSP2Triangles(glistp++, 1, 6, 5, 0, 5, 2, 1, 0);
    }

    gDPPipeSync(glistp++);
    gDPSetCombineMode(glistp++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
}

/**
 * Original nanme: Draw3DTetrisSwitch
 */
void Draw3DTetrisSwitch(struct_gInfo_unk_00068 *dynamicp, s32 num, block_t *left, block_t *right) {
    s32 index = GET_VTX3D_INDEX(dynamicp->cursorBlock[num].sy, 0);

    if (left->type != BLOCKTYPE_0) {
        gSPMatrix(glistp++, &dynamicp->left3D[num], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPTexture(glistp++, 0x8000, 0x8000, 0, left->type - 1, G_ON);
        gSPVertex(glistp++, &gAllVertex[index], VTX3D_VERTICES_PER_BLOCK, 0);
        gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
        gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
    }

    if (right->type != BLOCKTYPE_0) {
        gSPMatrix(glistp++, &dynamicp->right3D[num], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPTexture(glistp++, 0x8000, 0x8000, 0, right->type - 1, G_ON);
        gSPVertex(glistp++, &gAllVertex[index], VTX3D_VERTICES_PER_BLOCK, 0);
        gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
        gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
    }
}

/**
 * Original nanme: Draw3DTetrisNewBlock
 */
void Draw3DTetrisNewBlock(struct_gInfo_unk_00068 *dynamicp UNUSED, tetWell *well) {
    s32 col;
    Texture *tex;
    block_t *block;

    if (well->new_block[0].type == BLOCKTYPE_0) {
        return;
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);

    if (gGameStatus & GAME_STATUS_FLAG_40) {
        gDPLoadTLUT_pal256(glistp++, colorTable);

        if (gMain >= GMAIN_38E) {
            switch (well->new_block[0].frame_n) {
                case 0x8:
                case 0xD:
                    tex = tetrisBlock6.block.image;
                    break;

                case 0xE:
                    tex = tetrisBlock7.block.image;
                    break;

                case 0xF:
                    tex = tetrisBlock8.block.image;
                    break;

                case 0x10:
                    tex = tetrisBlock9.block.image;
                    break;

                default:
                    tex = tetrisBlockNew.block.image;
                    break;
            }
        } else {
            tex = tetrisBlockNew.block.image;
        }
    } else {
        gDPLoadTLUT_pal256(glistp++, D_010001F0_usa);

        if (gMain >= GMAIN_38E) {
            switch (well->new_block[0].frame_n) {
                case 0x8:
                case 0x10:
                    tex = block6;
                    break;

                case 0x11:
                    tex = block7;
                    break;

                case 0x12:
                    tex = block8;
                    break;

                case 0x13:
                    tex = block9;
                    break;

                default:
                    tex = blockn;
                    break;
            }
        } else {
            tex = blockn;
        }
    }

    gDPLoadTextureBlock(glistp++, tex, G_IM_FMT_CI, G_IM_SIZ_8b, BLOCK_TEX_WIDTH, BLOCK_TEX_HEIGHT, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Set3DTile();

    for (col = 1; col < BLOCK_COLS_3D / 2; col++) {
        block = &well->new_block[col];

        gSPTexture(glistp++, 0x8000, 0x8000, 0, block->type - 1, G_ON);
        gSPVertex(glistp++, &gAllVertex[GET_VTX3D_INDEX(BLOCK_LEN_ROWS, col)], VTX3D_VERTICES_PER_BLOCK, 0);
        gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
    }
}

/**
 * Original nanme: Draw3DCursor
 */
void Draw3DCursor(struct_gInfo_unk_00068 *dynamicp) {
    cursor_t *cursor;
    u16 *tex;
    s32 num;
    s32 x;
    s32 y;

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_NONE);

    if (dynamicp->cursorBlock[0].frame_n == 0) {
        tex = big_c;
    } else {
        tex = small_c;
    }
    gDPLoadTextureBlock(glistp++, tex, G_IM_FMT_RGBA, G_IM_SIZ_16b, CURSOR_TEX_WIDTH, CURSOR_TEX_HEIGHT, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    for (num = 0; num < gTheGame.totalPlayer; num++) {
        cursor = &dynamicp->cursorBlock[num];

        x = cursor->rect.s.objX;
        y = cursor->rect.s.objY;

        gSPTextureRectangle(glistp++, x << 2, y << 2, (x + CURSOR_TEX_REAL_WIDTH) << 2, (y + CURSOR_TEX_HEIGHT) << 2,
                            G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        gDPPipeSync(glistp++);
    }
}

/**
 * Original nanme: Draw3DIcon
 */
void Draw3DIcon(struct_gInfo_unk_00068 *dynamicp, s32 num) {
    s32 var_a3; // i?
    s32 temp_a1;
    s32 var_s2;
    s32 var_s3;
    s32 a2;
    s32 tile;
    s32 var_s5; // index?

    u8 *old_tex;
    u8 *tex;
    icon_t *icon;
    icon_t *icn = dynamicp->icon[num];

#if 0
    // Local variables
    int i; // r1+0x38
    int pos; // r1+0x8
    int count; // r5
    int total; // r1+0x34
    int index; // r1+0x8
    unsigned char * old_tex; // r1+0x30
    unsigned char * tex; // r29
    struct icon_t * icon; // r1+0x8
    struct icon_t (* icn)[10]; // r5
#endif

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(glistp++, D_01000408_usa);

    Set3DTile();

    if (gGameStatus & GAME_STATUS_FLAG_8) {
        gDPPipeSync(glistp++);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 100);
    }

    old_tex = NULL;
    for (var_s5 = 0; var_s5 < ICON_COUNT; var_s5++) {
        icon = &icn[var_s5];

        if (icon->flag != -1) {
            continue;
        }

        if (icon->count <= 0) {
            continue;
        }

        if (icon->from_x < 2 || icon->from_x > 7) {
            continue;
        }
        if ((gGameStatus & GAME_STATUS_FLAG_10) && (gMain < GMAIN_38E) && (icon->count % 2 == 0)) {
            continue;
        }

        switch (icon->type) {
            case ICONTYPE_12:
                var_s3 = 1;
                if (icon->total < 0xC) {
                    tex = combo01;
                } else if (icon->total < 0x14) {
                    tex = combo02;
                } else if (icon->total < 0x1C) {
                    tex = combo03;
                } else if (icon->total < 0x24) {
                    tex = combo04;
                } else if (icon->total < 0x2C) {
                    tex = combo05;
                } else if (icon->total < 0x34) {
                    tex = combo06;
                } else if (icon->total < 0x3C) {
                    tex = combo07;
                } else if (icon->total < 0x44) {
                    tex = combo08;
                } else {
                    tex = combo09;
                }
                var_s2 = Return3DComboTile(icon->total);
                break;

            case ICONTYPE_10:
                var_s3 = 1;
                if (icon->total < 9) {
                    tex = chain01;
                } else if (icon->total < 0x11) {
                    tex = chain02;
                } else if (icon->total < 0x19) {
                    tex = chain03;
                } else if (icon->total < 0x21) {
                    tex = chain04;
                } else if (icon->total < 0x29) {
                    tex = chain05;
                } else if (icon->total < 0x31) {
                    tex = chain06;
                } else if (icon->total < 0x39) {
                    tex = chain07;
                } else if (icon->total < 0x41) {
                    tex = chain08;
                } else if (icon->total < 0x49) {
                    tex = chain09;
                } else if (icon->total < 0x51) {
                    tex = chain010;
                } else if (icon->total < 0x59) {
                    tex = chain011;
                } else if (icon->total < 0x61) {
                    tex = chain012;
                } else {
                    tex = chain013;
                }
                var_s2 = Return3DChainTile(icon->total);
                break;

            case ICONTYPE_13:
                var_s3 = 2;
                tex = combo09;
                var_s2 = 4;
                break;

            case ICONTYPE_11:
                var_s3 = 2;
                tex = combo09;
                var_s2 = 6;
                break;
        }

        if (old_tex != tex) {
            gDPLoadTextureBlock(glistp++, tex, G_IM_FMT_CI, G_IM_SIZ_8b, COMBO_CHAIN_TEX_WIDTH, COMBO_CHAIN_TEX_HEIGHT,
                                0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                                G_TX_NOLOD, G_TX_NOLOD);

            old_tex = tex;
        }

        if (var_s2 == 7) {
            gDPPipeSync(glistp++);
            gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0086, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPSetTileSize(glistp++, G_TX_LOADTILE, 0, 0, 0x003C, 0x003C);
        }

        if (var_s3 == 2) {
            gDPPipeSync(glistp++);
            gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0086, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
            gDPSetTileSize(glistp++, G_TX_LOADTILE, 0, 0, 0x003C, 0x003C);
        }

        for (var_a3 = 0; var_a3 < var_s3; var_a3++) {
            temp_a1 = icon->from_x + var_a3;
            a2 = icon->to_y;
            tile = var_s2 + var_a3;

            gSPMatrix(glistp++, &icon->thing.move, G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPVertex(glistp++, &gAllVertex[GET_VTX3D_INDEX(a2, temp_a1)], VTX3D_VERTICES_PER_BLOCK, 0);
            gSPTexture(glistp++, 0x8000, 0x8000, 0, tile, G_ON);
            gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
            gDPPipeSync(glistp++);
            gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
        }
    }

    if (gGameStatus & GAME_STATUS_FLAG_8) {
        gDPPipeSync(glistp++);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        gDPSetRenderMode(glistp++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    }
}

#if VERSION_USA
#if 0
void Draw3DAttackBrick(struct_gInfo_unk_00068 *dynamicp, s32 num, s32 check) {
    Gfx *temp_a0;
    Gfx *temp_a1;
    Gfx *temp_a2;
    Gfx *temp_v0_2;
    Gfx *temp_v1;
    Gfx *temp_v1_3;
    Gfx *temp_v1_5;
    Gfx *temp_v1_6;
    Gfx *temp_v1_7;
    Gfx *var_v1;
    s16 temp_t0;
    s16 temp_t1;
    s32 temp_t7;
    s32 temp_v1_2;
    s32 temp_v1_4;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_t3;
    s32 var_t3_2;
    u16 temp_t0_2;
    u16 temp_t1_2;
    u16 var_a3;
    u32 var_a0;
    u32 var_v0_2;
    u8 temp_v0;
    void *temp_s3;
    void *temp_t4;
    void *var_a1_3;
    void *var_a3_2;
    void *var_t5;
    void *var_t9;
    void *var_v0;

    temp_v1 = glistp;
    var_t9 = NULL;
    var_t3 = check;
    glistp = temp_v1 + 8;
    temp_v1->words.w0 = 0xBA000E02;
    temp_v1->words.w1 = 0;
    temp_s3 = dynamicp + ((num * 0x5A0) + 0x14C88);
    if (check >= 0) {
        temp_t7 = num * 0xC;
        var_t5 = (check * 0x48) + temp_s3;
        do {
            if (((u32) (var_t5->unk_0 - 2) < 2U) && (var_t5->unk_8 < 5)) {
                temp_t0 = var_t5->unk_30;
                temp_t4 = var_t5 + 0x30;
                if ((u32) temp_t0 < 0x141U) {
                    temp_v1_2 = var_t5->unk_4;
                    temp_t1 = var_t5->unk_38;
                    if (temp_v1_2 < 0xC) {
                        var_v0 = *B_801C7070_usa[num];
                    } else if (temp_v1_2 < 0x12) {
                        var_v0 = *(&B_801C7070_usa[0][1] + temp_t7);
                    } else {
                        var_v0 = *(&B_801C7070_usa[0][2] + temp_t7);
                    }
                    if (var_t9 != var_v0) {
                        temp_v1_3 = glistp;
                        var_t9 = var_v0;
                        glistp = temp_v1_3 + 8;
                        temp_v1_3->words.w0 = 0xFD100000;
                        glistp = temp_v1_3 + 0x10;
                        temp_v1_3->unk_8 = 0xF5100000;
                        glistp = temp_v1_3 + 0x18;
                        temp_v1_3->unk_10 = 0xE6000000;
                        glistp = temp_v1_3 + 0x20;
                        temp_v1_3->unk_18 = 0xF3000000;
                        glistp = temp_v1_3 + 0x28;
                        glistp = temp_v1_3 + 0x30;
                        temp_v1_3->words.w1 = (u32) var_t9;
                        temp_v1_3->unk_C = 0x07000000;
                        temp_v1_3->unk_14 = 0;
                        temp_v1_3->unk_1C = 0x077FF080;
                        temp_v1_3->unk_20 = 0xE7000000;
                        temp_v1_3->unk_24 = 0;
                        temp_v1_3->unk_28 = 0xF5102000;
                        temp_v1_3->unk_2C = 0;
                        glistp = temp_v1_3 + 0x38;
                        temp_v1_3->unk_30 = 0xF2000000;
                        temp_v1_3->unk_34 = 0xFC07C;
                    }
                    temp_v1_4 = var_t5->unk_4;
                    if (temp_v1_4 < 4) {
                        var_a3 = var_t5->unk_36;
                        if (temp_v1_4 == 1) {
                            var_a1 = 0;
                        } else {
                            var_a1 = 0xA;
                            if (temp_v1_4 == 2) {
                                var_a1 = 6;
                            }
                        }
                        temp_v1_5 = glistp;
                        glistp = temp_v1_5 + 8;
                        glistp = temp_v1_5 + 0x10;
                        temp_v1_5->unk_8 = (s32) (var_a1 | 0xF5102000);
                        glistp = temp_v1_5 + 0x18;
                        temp_v1_5->words.w0 = 0xE7000000;
                        temp_v1_5->words.w1 = 0;
                        temp_v1_5->unk_C = 0x07000000;
                        temp_v1_5->unk_10 = 0xF2000000;
                        temp_v1_5->unk_14 = (s32) (((((var_a3 - 1) * 4) & 0xFFF) << 0xC) | 0x0700003C);
                    } else {
                        temp_v1_6 = glistp;
                        glistp = temp_v1_6 + 8;
                        temp_v1_6->words.w0 = 0xE7000000;
                        temp_v1_6->words.w1 = 0;
                        temp_v0 = temp_t4->unk_16;
                        var_a3 = 0x14;
                        switch (temp_v0) {
                            case 0x1:
                                temp_v1_7 = glistp;
                                glistp = temp_v1_7 + 8;
                                temp_v1_7->words.w1 = 0x01000000;
                                temp_v1_7->words.w0 = 0xF5102000;
                                glistp = temp_v1_7 + 0x10;
                                temp_v1_7->unk_8 = 0xF2000000;
                                temp_v1_7->unk_C = 0x0104C03C;
                                break;
                            case 0x2:
                                var_a0 = 0xF5102005;
                                var_v1 = glistp;
                                var_a1_2 = 0x0204C03C;
                                glistp = var_v1 + 8;
                                var_v0_2 = 0x02000000;
block_26:
                                var_v1->words.w1 = var_v0_2;
                                var_v1->words.w0 = var_a0;
                                glistp = var_v1 + 0x10;
                                var_v1->unk_8 = 0xF2000000;
                                var_v1->unk_C = var_a1_2;
                                break;
                            case 0x3:
                                var_a0 = 0xF510200A;
                                var_v1 = glistp;
                                var_a1_2 = 0x0304C03C;
                                glistp = var_v1 + 8;
                                var_v0_2 = 0x03000000;
                                goto block_26;
                            case 0x4:
                                var_a0 = 0xF5102100;
                                var_v1 = glistp;
                                var_a1_2 = 0x0404C03C;
                                glistp = var_v1 + 8;
                                var_v0_2 = 0x04000000;
                                goto block_26;
                            case 0x5:
                                var_a0 = 0xF5102105;
                                var_v1 = glistp;
                                var_a1_2 = 0x0504C03C;
                                glistp = var_v1 + 8;
                                var_v0_2 = 0x05000000;
                                goto block_26;
                            case 0x6:
                                var_a0 = 0xF510210A;
                                var_v1 = glistp;
                                var_a1_2 = 0x0604C03C;
                                glistp = var_v1 + 8;
                                var_v0_2 = 0x06000000;
                                goto block_26;
                        }
                    }
                    temp_a1 = glistp;
                    glistp = temp_a1 + 8;
                    temp_a1->words.w0 = ((((temp_t0 + var_a3) * 4) & 0xFFF) << 0xC) | ((((temp_t1 + 0x10) * 4) & 0xFFF) | 0xE4000000);
                    glistp = temp_a1 + 0x10;
                    temp_a1->unk_8 = 0xB4000000;
                    glistp = temp_a1 + 0x18;
                    temp_a1->unk_10 = 0xB3000000;
                    glistp = temp_a1 + 0x20;
                    temp_a1->unk_C = 0;
                    temp_a1->unk_14 = 0x04000400;
                    temp_a1->unk_18 = 0xE7000000;
                    temp_a1->unk_1C = 0;
                    temp_a1->words.w1 = ((temp_t4->unk_16 & 7) << 0x18) | (((temp_t0 * 4) & 0xFFF) << 0xC) | ((temp_t1 * 4) & 0xFFF);
                }
            }
            var_t3 -= 1;
            var_t5 -= 0x48;
        } while (var_t3 >= 0);
    }
    temp_a2 = glistp;
    glistp = temp_a2 + 8;
    glistp = temp_a2 + 0x10;
    temp_a2->words.w0 = 0xE7000000;
    temp_a2->words.w1 = 0;
    temp_a2->unk_8 = 0xBA000E02;
    temp_a2->unk_C = 0x8000;
    if (num == 0) {
        temp_a2->unk_10 = 0xFD100000;
        glistp = temp_a2 + 0x18;
        glistp = temp_a2 + 0x20;
        temp_a2->unk_18 = 0xE8000000;
        glistp = temp_a2 + 0x28;
        temp_a2->unk_24 = 0x07000000;
        glistp = temp_a2 + 0x30;
        temp_a2->unk_28 = 0xE6000000;
        glistp = temp_a2 + 0x38;
        temp_a2->unk_30 = 0xF0000000;
        temp_a2->unk_1C = 0;
        temp_a2->unk_20 = 0xF5000100;
        temp_a2->unk_2C = 0;
        temp_a2->unk_34 = 0x073FC000;
        glistp = temp_a2 + 0x40;
        temp_a2->unk_38 = 0xE7000000;
        temp_a2->unk_3C = 0;
        temp_a2->unk_14 = (void *) B_801C6C9C_usa[1];
        var_a3_2 = B_8021BA60_usa[1];
    } else {
        temp_a2->unk_10 = 0xFD100000;
        glistp = temp_a2 + 0x18;
        glistp = temp_a2 + 0x20;
        temp_a2->unk_18 = 0xE8000000;
        glistp = temp_a2 + 0x28;
        temp_a2->unk_24 = 0x07000000;
        glistp = temp_a2 + 0x30;
        temp_a2->unk_28 = 0xE6000000;
        glistp = temp_a2 + 0x38;
        temp_a2->unk_30 = 0xF0000000;
        temp_a2->unk_1C = 0;
        temp_a2->unk_20 = 0xF5000100;
        temp_a2->unk_2C = 0;
        temp_a2->unk_34 = 0x073FC000;
        glistp = temp_a2 + 0x40;
        temp_a2->unk_38 = 0xE7000000;
        temp_a2->unk_3C = 0;
        temp_a2->unk_14 = (void *) B_801C6C9C_usa->unk_0;
        var_a3_2 = B_8021BA60_usa->unk_0;
    }
    temp_v0_2 = glistp;
    var_t3_2 = 0;
    glistp = temp_v0_2 + 8;
    temp_v0_2->words.w0 = 0xFD500000;
    glistp = temp_v0_2 + 0x10;
    temp_v0_2->unk_8 = 0xF5500000;
    temp_v0_2->unk_C = 0x07000000;
    glistp = temp_v0_2 + 0x18;
    temp_v0_2->unk_10 = 0xE6000000;
    glistp = temp_v0_2 + 0x20;
    temp_v0_2->unk_18 = 0xF3000000;
    glistp = temp_v0_2 + 0x28;
    temp_v0_2->unk_20 = 0xE7000000;
    glistp = temp_v0_2 + 0x30;
    glistp = temp_v0_2 + 0x38;
    temp_v0_2->words.w1 = (u32) var_a3_2;
    temp_v0_2->unk_14 = 0;
    temp_v0_2->unk_1C = 0x071FF100;
    temp_v0_2->unk_24 = 0;
    temp_v0_2->unk_28 = 0xF5481000;
    temp_v0_2->unk_2C = 0;
    temp_v0_2->unk_30 = 0xF2000000;
    temp_v0_2->unk_34 = 0xFC03C;
    if (check >= 0) {
        var_a1_3 = temp_s3;
        do {
            var_t3_2 += 1;
            if ((var_a1_3->unk_0 == 1) && (var_a1_3->unk_C < 0)) {
                temp_a0 = glistp;
                temp_t0_2 = var_a1_3->unk_32;
                temp_t1_2 = var_a1_3->unk_3A;
                glistp = temp_a0 + 8;
                temp_a0->words.w0 = ((((temp_t0_2 + 0x10) * 4) & 0xFFF) << 0xC) | ((((temp_t1_2 + 0x10) * 4) & 0xFFF) | 0xE4000000);
                glistp = temp_a0 + 0x10;
                glistp = temp_a0 + 0x18;
                temp_a0->words.w1 = (((temp_t0_2 * 4) & 0xFFF) << 0xC) | ((temp_t1_2 * 4) & 0xFFF);
                temp_a0->unk_8 = 0xB4000000;
                temp_a0->unk_C = 0;
                temp_a0->unk_10 = 0xB3000000;
                temp_a0->unk_14 = 0x04000400;
                glistp = temp_a0 + 0x20;
                temp_a0->unk_18 = 0xE7000000;
                temp_a0->unk_1C = 0;
            }
            var_a1_3 += 0x48;
        } while (check >= var_t3_2);
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DAttackBrick);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DAttackBrick);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DAttackBrick);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DAttackBrick);
#endif

void func_800615D8_usa(s32 row, s32 col, s32 arg2, s32 arg3) {
    gSPTexture(glistp++, 0x8000, 0x8000, 0, arg2, G_ON);
    gSPVertex(glistp++, &gAllVertex[GET_VTX3D_INDEX(row, col)], VTX3D_VERTICES_PER_BLOCK, 0);

    if (arg3 == 0) {
        gSP2Triangles(glistp++, 4, 5, 6, 0, 4, 7, 5, 0);
    } else {
        gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
    }
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
s32 Draw3DAttack(struct_gInfo_unk_00068 *dynamicp, s32 num, s32 front) {
    s32 var_s6; // sp10
    s32 sp14;
    s32 sp18;
    s32 sp24;
    block_t (*sp2C)[18];
    char (*sp34)[18];
    void **sp3C;
    void * (*sp4C)[6];
    attack_t *temp_s1;
    attack_t *var_t8;
    s32 temp_s7;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_fp;
    s32 temp_ret;
    s32 temp_ret_2;
    s32 temp_t0;
    s32 temp_t1_2;
    s32 temp_t1_3;
    s32 temp_t1_4;
    s32 temp_t1_5;
    s32 temp_t4;
    s32 temp_v1_2;
    s32 var_fp;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s7;
    s32 var_t0;
    s32 var_t5;
    s32 var_t6;
    s32 var_t7;
    s32 var_t9;
    s32 var_v0;
    u32 temp_t2;
    void *temp_t2_2;
    block_t *temp_v1_5;
    void *var_a1;
    void *var_t2;
    void *var_t3;

    s32 s5;

    attack_t *blah;

    var_t9 = front;

    sp2C = dynamicp->block[num];
    sp34 = dynamicp->visible[num];

    #if 0
    temp_t1 = glistp;

    temp_t1->words.w0 = 0xE7000000;
    temp_t1->words.w1 = 0x00000000;
    temp_t1->unk_8 = 0xBA000E02;
    temp_t1->unk_C = 0x00008000;

    if (num == 0) {
        var_a1 = B_801C6C9C_usa[1];
    } else {
        var_a1 = B_801C6C9C_usa->unk_0;
    }

    temp_t1->unk_10 = 0xFD100000;
    temp_t1->unk_14 = var_a1;
    temp_t1->unk_18 = 0xE8000000;
    temp_t1->unk_1C = 0x00000000;

    temp_t1->unk_20 = 0xF5000100;
    temp_t1->unk_24 = 0x07000000;
    temp_t1->unk_28 = 0xE6000000;
    temp_t1->unk_2C = 0x00000000;

    temp_t1->unk_30 = 0xF0000000;
    temp_t1->unk_34 = 0x073FC000;
    temp_t1->unk_38 = 0xE7000000;
    temp_t1->unk_3C = 0x00000000;

    glistp = temp_t1 + 8;
    glistp = temp_t1 + 0x10;
    glistp = temp_t1 + 0x18;
    glistp = temp_t1 + 0x20;
    glistp = temp_t1 + 0x28;
    glistp = temp_t1 + 0x30;
    glistp = temp_t1 + 0x38;
    glistp = temp_t1 + 0x40;
    #endif

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);

    if (num == 0) {
        var_a1 = B_801C6C9C_usa[1];
    } else {
        var_a1 = B_801C6C9C_usa[0];
    }
    gDPLoadTLUT_pal256(glistp++, var_a1);


    var_t3 = NULL;
    sp3C = &B_801C7360_usa[num];
    blah = dynamicp->attack[num];
    sp4C = B_801AB8A8_usa[num];

    for (sp24 = 0; sp24 < 0x14; sp24++) {
        var_t8 = &blah[sp24];
        if (var_t8->state < 5) {
            continue;
        }

        temp_s1 = var_t8;
        if (var_t9 != 0) {
            temp_a0 = var_t8->unk_1C;
            if (var_t8->start == temp_a0) {
                var_s6 = 0;
                sp14 = 9;
                var_t7 = 0;
            } else if (temp_a0 < var_t8->start) {
                temp_a1 = var_t8->start;
                var_s6 = 0;
                sp14 = temp_a0;
                var_t7 = 0x12 - temp_a1;
                if (var_t8->type == ATTACKTYPE_11) {
                    if ((u32) (temp_a1 - 6) < 3U) {
                        sp14 = 0x12;
                    }
                }
            } else {
                var_s6 = var_t8->start;
                if (temp_a0 >= 0xA) {
                    sp14 = 9;
                    var_t7 = 0;
                } else {
                    sp14 = temp_a0;
                    var_t7 = 0;
                }
            }
        } else {
            temp_v1_2 = var_t8->start;
            if (temp_v1_2 == var_t8->unk_1C) {
                var_s6 = 9;
                sp14 = 0x12;
                var_t7 = 9;
            } else {
                if (var_t8->unk_1C < temp_v1_2) {
                    var_s6 = temp_v1_2;
                    sp14 = 0x12;
                    var_t7 = 0;
                } else {
                    if (temp_v1_2 >= 9) {
                        var_s6 = temp_v1_2;
                        var_t7 = 0;
                        sp14 = temp_s1->unk_1C;
                    } else {
                        var_s6 = 9;
                        var_t7 = 9 - temp_v1_2;
                        sp14 = temp_s1->unk_1C;
                    }
                }
            }
        }

        s5 = sp14;
        if (temp_s1->disappear != -1) {
            if (temp_s1->type == ATTACKTYPE_9) {
                var_t2 = *sp3C;
            } else {
                var_t2 = B_801AB8A8_usa[num];
            }

            if (var_t3 != var_t2) {
                var_t3 = var_t2;

                #if 0
                temp_v1_3 = glistp;

                temp_v1_3->words.w0 = 0xFD500000;
                temp_v1_3->words.w1 = (u32) var_t3;
                temp_v1_3->unk_8 = 0xF5500000;
                temp_v1_3->unk_C = 0x07000000;

                temp_v1_3->unk_10 = 0xE6000000;
                temp_v1_3->unk_14 = 0;
                temp_v1_3->unk_18 = 0xF3000000;
                temp_v1_3->unk_1C = 0x073FF100;

                temp_v1_3->unk_20 = 0xE7000000;
                temp_v1_3->unk_24 = 0;
                temp_v1_3->unk_28 = 0xF5481000;
                temp_v1_3->unk_2C = 0;

                temp_v1_3->unk_30 = 0xF2000000;
                temp_v1_3->unk_34 = 0xFC07C;
                temp_v1_3->unk_38 = 0xE7000000;
                temp_v1_3->unk_3C = 0;

                temp_v1_3->unk_40 = 0xF5481086;
                temp_v1_3->unk_44 = 0x07000000;
                temp_v1_3->unk_48 = 0xF2000000;
                temp_v1_3->unk_4C = 0x0703C03C;

                glistp = temp_v1_3 + 8;
                glistp = temp_v1_3 + 0x10;
                glistp = temp_v1_3 + 0x18;
                glistp = temp_v1_3 + 0x20;
                glistp = temp_v1_3 + 0x28;
                glistp = temp_v1_3 + 0x30;
                glistp = temp_v1_3 + 0x38;
                glistp = temp_v1_3 + 0x40;
                glistp = temp_v1_3 + 0x48;
                glistp = temp_v1_3 + 0x50;
                #endif

                gDPLoadTextureBlock(glistp++, var_t3, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

                gDPPipeSync(glistp++);
                gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0086, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPSetTileSize(glistp++, G_TX_LOADTILE, 0, 0, 0x003C, 0x003C);
            }

            var_s7 = 0;

            for (var_s0 = 0; var_s0 < temp_s1->level; var_s0++) {
                temp_t1_2 = temp_s1->currRow + var_s0;
                if (temp_t1_2 >= 0xC) {
                    continue;
                }

                for (; var_s6 < sp14; var_s6++) {
                    if (temp_s1->type == ATTACKTYPE_11) {
                        Draw3DChain3_CrossBoundary(temp_s1, &var_s6, &sp14, &sp18);
                    }
                    var_t0 = -1;
                    if ((temp_s1->delay > 0) || (temp_s1->counter > 0)) {
                        var_t0 = (temp_s1->delay & 1) ? 7 : 3;
                    } else {
                        temp_v1_5 = &sp2C[temp_t1_2][var_s6];

                        if (temp_v1_5->type == 9) {
                            if (temp_v1_5->drop == 0) {
                                var_t0 = 3;
                            } else if (temp_v1_5->drop == 1) {
                                var_s7 = -1;
                            }
                        }
                    }

                    if ((var_t0 != -1) && (sp34[temp_t1_2][var_s6] != 0)) {
                        #if 0
                        temp_a2 = glistp;

                        temp_a2->words.w0 = ((var_t0 & 7) << 8) | 0xBB000001;
                        temp_a2->words.w1 = 0x80008000;
                        temp_a2->unk_8 = 0x0400207F;
                        temp_a2->unk_C = &gAllVertex[(temp_t1_2 * 0x90) + (var_s6 * 8)];
                        if (var_t9 == 0) {
                            temp_a2->unk_10 = 0xB1080A0C;
                            temp_a2->unk_14 = 0x00080E0A;
                        } else {
                            temp_a2->unk_10 = 0xB1000204;
                            temp_a2->unk_14 = 0x00000406;
                        }

                        glistp = temp_a2 + 8;
                        glistp = temp_a2 + 0x10;
                        glistp = temp_a2 + 0x18;
                        #endif

                        gSPTexture(glistp++, 0x8000, 0x8000, 0, var_t0, G_ON);
                        gSPVertex(glistp++, &gAllVertex[GET_VTX3D_INDEX(temp_t1_2, var_s6)], VTX3D_VERTICES_PER_BLOCK, 0);
                        if (var_t9 == 0) {
                            gSP2Triangles(glistp++, 4, 5, 6, 0, 4, 7, 5, 0);
                        } else {
                            gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
                        }

                    }
                }

                if (sp14 != s5) {
                    sp14 = s5;
                }
            }

            if (var_s7 != 0) {
                temp_s7 = temp_s1->type - 0x16;
                if (temp_s7 == 12) {
                    var_v0 = 0;
                    var_t6 = 0;
                } else if (temp_s7 == 13) {
                    var_v0 = 2;
                    var_t6 = 1;
                } else {
                    var_v0 = 5;
                    var_t6 = 3;
                }

                var_s2 = var_v0;
                var_t5 = var_s2 * 0xA;
                for (; var_s2 >= var_t6; var_s2--) {
                    temp_t2 = (*sp4C)[var_s2];
                    if (var_t3 != temp_t2) {
                        var_t3 = (void *) temp_t2;

                        #if 0
                        temp_v0_3 = glistp;

                        temp_v0_3->words.w0 = 0xFD500000;
                        temp_v0_3->words.w1 = (u32) var_t3;
                        temp_v0_3->unk_8 = 0xF5500000;
                        temp_v0_3->unk_C = 0x07000000;

                        temp_v0_3->unk_10 = 0xE6000000;
                        temp_v0_3->unk_14 = 0;
                        temp_v0_3->unk_18 = 0xF3000000;
                        temp_v0_3->unk_1C = 0x073FF100;

                        temp_v0_3->unk_20 = 0xE7000000;
                        temp_v0_3->unk_24 = 0;
                        temp_v0_3->unk_28 = 0xF5481000;
                        temp_v0_3->unk_2C = 0;

                        temp_v0_3->unk_30 = 0xF2000000;
                        temp_v0_3->unk_34 = 0xFC07C;
                        temp_v0_3->unk_38 = 0xE7000000;
                        temp_v0_3->unk_3C = 0;

                        temp_v0_3->unk_40 = 0xF5481086;
                        temp_v0_3->unk_44 = 0x07000000;
                        temp_v0_3->unk_48 = 0xF2000000;
                        temp_v0_3->unk_4C = 0x0703C03C;

                        glistp = temp_v0_3 + 8;
                        glistp = temp_v0_3 + 0x10;
                        glistp = temp_v0_3 + 0x18;
                        glistp = temp_v0_3 + 0x20;
                        glistp = temp_v0_3 + 0x28;
                        glistp = temp_v0_3 + 0x30;
                        glistp = temp_v0_3 + 0x38;
                        glistp = temp_v0_3 + 0x40;
                        glistp = temp_v0_3 + 0x48;
                        glistp = temp_v0_3 + 0x50;
                        #endif
                        gDPLoadTextureBlock(glistp++, var_t3, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        gDPPipeSync(glistp++);
                        gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0086, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                        gDPSetTileSize(glistp++, G_TX_LOADTILE, 0, 0, 0x003C, 0x003C);
                    }

                    temp_fp = var_t5;
                    for (var_s0_2 = 1; var_s0_2 < temp_s1->level; var_s0_2++) {
                        temp_t1_3 = temp_s1->currRow + var_s0_2;
                        if (temp_t1_3 >= 0xC) {
                            continue;
                        }

                        sp18 = var_t7;
                        for (; var_s6 < sp14; var_s6++) {
                            temp_ret = ReturnAttackTexValue(temp_s1, temp_s7, var_s0_2 - 1, sp18);

                            if (((temp_ret / 10) == var_s2) && (sp2C[temp_t1_3][var_s6].drop == 1) && (sp34[temp_t1_3][var_s6] != 0)) {
                                #if 0
                                temp_a2_2 = glistp;

                                temp_a2_2->words.w0 = (((temp_ret - temp_fp) & 7) << 8) | 0xBB000001;
                                temp_a2_2->words.w1 = 0x80008000;
                                temp_a2_2->unk_8 = 0x0400207F;
                                temp_a2_2->unk_C = &gAllVertex[(temp_t1_3 * 0x90) + (var_s6 * 8)];
                                if (var_t9 == 0) {
                                    temp_a2_2->unk_10 = 0xB1080A0C;
                                    temp_a2_2->unk_14 = 0x80E0A;
                                } else {
                                    temp_a2_2->unk_10 = 0xB1000204;
                                    temp_a2_2->unk_14 = 0x406;
                                }

                                glistp = temp_a2_2 + 8;
                                glistp = temp_a2_2 + 0x10;
                                glistp = temp_a2_2 + 0x18;
                                #endif

                                gSPTexture(glistp++, 0x8000, 0x8000, 0, temp_ret - temp_fp, G_ON);
                                gSPVertex(glistp++, &gAllVertex[GET_VTX3D_INDEX(temp_t1_3, var_s6)], VTX3D_VERTICES_PER_BLOCK, 0);
                                if (var_t9 == 0) {
                                    gSP2Triangles(glistp++, 4, 5, 6, 0, 4, 7, 5, 0);
                                } else {
                                    gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
                                }
                            }

                            sp18 += 1;
                        }
                    }

                    var_t5 -= 0xA;
                }
            }
        } else {
            if (temp_s1->type < 0xE) {
                for (var_s0_3 = 0; var_s0_3 < temp_s1->level; var_s0_3++) {
                    temp_t1_4 = temp_s1->currRow + var_s0_3;
                    if (temp_t1_4 >= 0xC) {
                        continue;
                    }

                    switch (temp_s1->type) { /* irregular */
                        case ATTACKTYPE_9:
                            var_t2 = *sp3C;
                            break;
                        case ATTACKTYPE_13:
                            if (var_s0_3 == 0) {
                                var_t2 = B_801AB8A8_usa[num][2];
                            } else {
                                var_t2 = B_801AB8A8_usa[num][1];
                            }
                            break;
                        default:
                            var_t2 = B_801AB8A8_usa[num][0];
                            break;
                    }

                    if (var_t3 != var_t2) {
                        var_t3 = var_t2;

                        #if 0
                        temp_v0_5 = glistp;

                        temp_v0_5->words.w0 = 0xFD500000;
                        temp_v0_5->words.w1 = (u32) var_t3;
                        temp_v0_5->unk_8 = 0xF5500000;
                        temp_v0_5->unk_C = 0x07000000;

                        temp_v0_5->unk_10 = 0xE6000000;
                        temp_v0_5->unk_14 = 0;
                        temp_v0_5->unk_18 = 0xF3000000;
                        temp_v0_5->unk_1C = 0x073FF100;

                        temp_v0_5->unk_20 = 0xE7000000;
                        temp_v0_5->unk_24 = 0;
                        temp_v0_5->unk_28 = 0xF5481000;
                        temp_v0_5->unk_2C = 0;

                        temp_v0_5->unk_30 = 0xF2000000;
                        temp_v0_5->unk_34 = 0xFC07C;
                        temp_v0_5->unk_38 = 0xE7000000;
                        temp_v0_5->unk_3C = 0;

                        temp_v0_5->unk_40 = 0xF5481086;
                        temp_v0_5->unk_44 = 0x07000000;
                        temp_v0_5->unk_48 = 0xF2000000;
                        temp_v0_5->unk_4C = 0x0703C03C;

                        glistp = temp_v0_5 + 8;
                        glistp = temp_v0_5 + 0x10;
                        glistp = temp_v0_5 + 0x18;
                        glistp = temp_v0_5 + 0x20;
                        glistp = temp_v0_5 + 0x28;
                        glistp = temp_v0_5 + 0x30;
                        glistp = temp_v0_5 + 0x38;
                        glistp = temp_v0_5 + 0x40;
                        glistp = temp_v0_5 + 0x48;
                        glistp = temp_v0_5 + 0x50;
                        #endif

                        gDPLoadTextureBlock(glistp++, var_t3, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        gDPPipeSync(glistp++);
                        gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0086, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                        gDPSetTileSize(glistp++, G_TX_LOADTILE, 0, 0, 0x003C, 0x003C);
                    }

                    sp18 = var_t7;
                    for (; var_s6 < sp14; var_s6++) {
                        if (temp_s1->type == ATTACKTYPE_11) {
                            Draw3DChain3_CrossBoundary(temp_s1, &var_s6, &sp14, &sp18);
                        }

                        temp_t0 = ReturnAttackTexValue(temp_s1, temp_s1->type, var_s0_3, sp18) % 10;
                        if (sp34[temp_t1_4][var_s6] != 0) {
                            #if 0
                            temp_a2_3 = glistp;

                            temp_a2_3->words.w0 = ((temp_t0 & 7) << 8) | 0xBB000001;
                            temp_a2_3->words.w1 = 0x80008000;
                            temp_a2_3->unk_8 = 0x0400207F;
                            temp_a2_3->unk_C = &gAllVertex[(temp_t1_4 * 0x90) + (var_s6 * 8)];
                            if (var_t9 == 0) {
                                temp_a2_3->unk_10 = 0xB1080A0C;
                                temp_a2_3->unk_14 = 0x80E0A;
                            } else {
                                temp_a2_3->unk_10 = 0xB1000204;
                                temp_a2_3->unk_14 = 0x406;
                            }

                            glistp = temp_a2_3 + 8;
                            glistp = temp_a2_3 + 0x10;
                            glistp = temp_a2_3 + 0x18;
                            #endif

                            gSPTexture(glistp++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
                            gSPVertex(glistp++, &gAllVertex[GET_VTX3D_INDEX(temp_t1_4, var_s6)], VTX3D_VERTICES_PER_BLOCK, 0);
                            gSP2Triangles(glistp++, 4, 5, 6, 0, 4, 7, 5, 0);
                            gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
                        }
                        sp18 += 1;
                    }

                    if (sp14 != s5) {
                        sp14 = s5;
                    }
                }
            } else {

                for (var_s2_2 = 5; var_s2_2 >= 3; var_s2_2--) {
                    temp_t2_2 = (*sp4C)[var_s2_2];
                    if (var_t3 != temp_t2_2) {
                        var_t3 = temp_t2_2;

                        #if 0
                        temp_v0_7 = glistp;

                        temp_v0_7->words.w0 = 0xFD500000;
                        temp_v0_7->words.w1 = (u32) var_t3;
                        temp_v0_7->unk_8 = 0xF5500000;
                        temp_v0_7->unk_C = 0x07000000;

                        temp_v0_7->unk_10 = 0xE6000000;
                        temp_v0_7->unk_14 = 0;
                        temp_v0_7->unk_18 = 0xF3000000;
                        temp_v0_7->unk_1C = 0x073FF100;

                        temp_v0_7->unk_20 = 0xE7000000;
                        temp_v0_7->unk_24 = 0;
                        temp_v0_7->unk_28 = 0xF5481000;
                        temp_v0_7->unk_2C = 0;

                        temp_v0_7->unk_30 = 0xF2000000;
                        temp_v0_7->unk_34 = 0xFC07C;
                        temp_v0_7->unk_38 = 0xE7000000;
                        temp_v0_7->unk_3C = 0;

                        temp_v0_7->unk_40 = 0xF5481086;
                        temp_v0_7->unk_44 = 0x07000000;
                        temp_v0_7->unk_48 = 0xF2000000;
                        temp_v0_7->unk_4C = 0x0703C03C;

                        glistp = temp_v0_7 + 8;
                        glistp = temp_v0_7 + 0x10;
                        glistp = temp_v0_7 + 0x18;
                        glistp = temp_v0_7 + 0x20;
                        glistp = temp_v0_7 + 0x28;
                        glistp = temp_v0_7 + 0x30;
                        glistp = temp_v0_7 + 0x38;
                        glistp = temp_v0_7 + 0x40;
                        glistp = temp_v0_7 + 0x48;
                        glistp = temp_v0_7 + 0x50;
                        #endif

                        gDPLoadTextureBlock(glistp++, var_t3, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                        gDPPipeSync(glistp++);
                        gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0086, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                        gDPSetTileSize(glistp++, G_TX_LOADTILE, 0, 0, 0x003C, 0x003C);
                    }

                    for (var_s0_4 = 0; var_s0_4 < temp_s1->level; var_s0_4++) {
                        temp_t1_5 = temp_s1->currRow + var_s0_4;
                        if (temp_t1_5 >= 0xC) {
                            continue;
                        }

                        sp18 = var_t7;
                        for (; var_s6 < sp14; var_s6++) {
                            temp_ret_2 = ReturnAttackTexValue(temp_s1, temp_s1->type, var_s0_4, sp18);

                            if (((temp_ret_2 / 10) == var_s2_2) && (sp34[temp_t1_5][var_s6] != 0)) {
                                #if 0
                                temp_a2_4 = glistp;

                                temp_a2_4->words.w0 = (((temp_ret_2 - var_fp) & 7) << 8) | 0xBB000001;
                                temp_a2_4->words.w1 = 0x80008000;
                                temp_a2_4->unk_8 = 0x0400207F;
                                temp_a2_4->unk_C = &gAllVertex[(temp_t1_5 * 0x90) + (var_s6 * 8)];
                                if (var_t9 == 0) {
                                    temp_a2_4->unk_10 = 0xB1080A0C;
                                    temp_a2_4->unk_14 = 0x80E0A;
                                } else {
                                    temp_a2_4->unk_10 = 0xB1000204;
                                    temp_a2_4->unk_14 = 0x406;
                                }

                                glistp = temp_a2_4 + 8;
                                glistp = temp_a2_4 + 0x10;
                                glistp = temp_a2_4 + 0x18;
                                #endif

                                gSPTexture(glistp++, 0x8000, 0x8000, 0, temp_ret_2 - 10 * var_s2_2, G_ON);
                                gSPVertex(glistp++, &gAllVertex[GET_VTX3D_INDEX(temp_t1_5, var_s6)], VTX3D_VERTICES_PER_BLOCK, 0);
                                gSP2Triangles(glistp++, 4, 5, 6, 0, 4, 7, 5, 0);
                                gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
                            }

                            sp18 += 1;
                        }
                    }

                }
            }
        }
    }

    return 0x13;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DAttack);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DAttack);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DAttack);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DAttack);
#endif

/**
 * Original nanme: Draw3DExplosion
 */
void Draw3DExplosion(struct_gInfo_unk_00068 *dynamicp, s32 num) {
    explode_t *exp = dynamicp->explosion[num];
    uObjSprite_t *s;
    u8 *tex;
    s32 count;
    s32 ss;
    s32 tt;

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(glistp++, B_801C6C9C_usa[num]);

    tex = B_8021BA60_usa[num];
    gDPLoadTextureBlock(glistp++, tex, G_IM_FMT_CI, G_IM_SIZ_8b, 64, 16, 0, G_TX_NOMIRROR | G_TX_WRAP,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    Set3DExplodeTile();

    for (count = 0; count < EXPLOSION_COUNT; count++) {
        if (!(exp[count].frame >= 0)) {
            continue;
        }

        s = &exp[count].rect.s;
        if ((s->scaleW >= 1) && (s->scaleW <= 8)) {
            ss = (s->paddingX == 1) ? 0 : s->imageSiz;
            tt = (s->paddingY == 1) ? 0 : s->imageSiz;

            gSPTextureRectangle(glistp++, s->objX << 2, s->objY << 2, (s->objX + s->imageSiz) << 2,
                                (s->objY + s->imageSiz) << 2, s->imagePal, ss << 0x5, tt << 5, s->paddingX << 0xA,
                                s->paddingY << 0xA);
            gDPPipeSync(glistp++);
        }
    }
}

/**
 * Original nanme: Draw3DClearLine
 */
void Draw3DClearLine(struct_gInfo_unk_00068 *dynamicp UNUSED, s32 num) {
    s32 var_v0;
    s32 row;
    s32 col;

#if 0
    // Local variables
    int row; // r1+0x8
    int index; // r5
#endif

    if (gMain >= GMAIN_388) {
        return;
    }

    row = gTheGame.cursorBlock[num].target[0];
    if (row > 0) {
        return;
    }

    row = -row;

    gDPPipeSync(glistp++);

    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(glistp++, numberTable);
    gDPLoadTextureBlock(glistp++, clear, G_IM_FMT_CI, G_IM_SIZ_8b, CLEAR_TEX_WIDTH, CLEAR_TEX_HEIGHT, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gDPPipeSync(glistp++);
    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 1, 0, 0, 0x003C, 0x003C);

    var_v0 = gCounter % VTX3D_VERTICES_PER_BLOCK;
    col = var_v0 + 1;
    gSPVertex(glistp++, &gAllVertex[GET_VTX3D_INDEX(row, col)], VTX3D_VERTICES_PER_BLOCK, 0);

    gSPTexture(glistp++, 0x8000, 0x8000, 0, 1, G_ON);
    gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
}

/**
 * Original nanme: Draw3DClearSign
 */
void Draw3DClearSign(struct_gInfo_unk_00068 *dynamicp, s32 num) {
    s32 tmem;
    s32 x;
    s32 y;

    if (gMain >= GMAIN_388) {
        return;
    }

    if (gTheGame.cursorBlock[num].target[0] > 0) {
        return;
    }

    tmem = (num != 0) ? 0x82 : 2;

    gDPLoadTextureBlock(glistp++, clear, G_IM_FMT_CI, G_IM_SIZ_8b, CLEAR_TEX_WIDTH, CLEAR_TEX_HEIGHT, 0,
                        G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gDPPipeSync(glistp++);

    gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, tmem, 2, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD,
               G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(glistp++, 2, 0, 0, 0x00BC, 0x003C);

    x = dynamicp->attack[num][0].rect.s.objX;
    y = dynamicp->attack[num][0].rect.s.objY;

    gDPPipeSync(glistp++);
    gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 100);

    gSPTextureRectangle(glistp++, x << 2, y << 2, (x + 0x30) << 2, (y + 0x10) << 2, 2, 0, 0, 0x0400, 0x0400);

    gDPPipeSync(glistp++);
    // two gDPPipeSync in a row?

    gDPPipeSync(glistp++);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(glistp++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
}

#if VERSION_USA
#if 0
extern ? D_01022620_usa;

void func_80063110_usa(s32 arg0) {
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    void **sp24;
    s32 sp28;
    s32 sp2C;
    Gfx *temp_a1;
    Gfx *temp_a1_2;
    Gfx *temp_a1_3;
    Gfx *temp_a2;
    Gfx *temp_a3;
    Gfx *temp_a3_2;
    Gfx *temp_a3_3;
    Gfx *temp_v0;
    Gfx *temp_v0_2;
    Gfx *temp_v1_5;
    s32 temp_a1_4;
    s32 temp_t0;
    s32 temp_t0_2;
    s32 temp_t0_3;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_t1_3;
    s32 temp_v0_3;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_s2_3;
    s32 var_s3;
    s32 var_t2;
    s32 var_t3;
    s32 var_t4;
    s32 var_t6;
    s32 var_t7;
    u16 temp_t2;
    u8 *var_s0;
    void **var_t5;
    void *var_s0_2;
    void *var_s1;

    var_s0 = saved_reg_s0;
    var_s3 = saved_reg_s3;
    sp14 = arg0;
    temp_v0 = glistp;
    var_s2 = 0;
    var_s1 = sp14 + 0x157C8;
    glistp = temp_v0 + 8;
    glistp = temp_v0 + 0x10;
    temp_v0->unk_C = 0x8000;
    glistp = temp_v0 + 0x18;
    temp_v0->unk_10 = 0xFD100000;
    temp_v0->unk_14 = D_01000408_usa;
    glistp = temp_v0 + 0x20;
    temp_v0->unk_18 = 0xE8000000;
    glistp = temp_v0 + 0x28;
    temp_v0->unk_24 = 0x07000000;
    glistp = temp_v0 + 0x30;
    temp_v0->unk_28 = 0xE6000000;
    glistp = temp_v0 + 0x38;
    temp_v0->unk_30 = 0xF0000000;
    temp_v0->words.w0 = 0xE7000000;
    temp_v0->words.w1 = 0;
    temp_v0->unk_8 = 0xBA000E02;
    temp_v0->unk_1C = 0;
    temp_v0->unk_20 = 0xF5000100;
    temp_v0->unk_2C = 0;
    temp_v0->unk_34 = 0x073FC000;
    glistp = temp_v0 + 0x40;
    temp_v0->unk_38 = 0xE7000000;
    temp_v0->unk_3C = 0;
    Set3DTile();
loop_1:
    if (var_s1->unk_0 == -1) {
        temp_v1 = var_s1->unk_4;
        switch (temp_v1) {                          /* irregular */
            case 0xC:
                temp_v1_2 = var_s1->unk_8;
                if (temp_v1_2 < 0xC) {
                    var_s0 = combo01;
                } else if (temp_v1_2 < 0x14) {
                    var_s0 = combo02;
                } else if (temp_v1_2 < 0x1C) {
                    var_s0 = combo03;
                } else if (temp_v1_2 < 0x24) {
                    var_s0 = combo04;
                } else if (temp_v1_2 < 0x2C) {
                    var_s0 = combo05;
                } else if (temp_v1_2 < 0x34) {
                    var_s0 = combo06;
                } else if (temp_v1_2 < 0x3C) {
                    var_s0 = combo07;
                } else {
                    var_s0 = combo09;
                    if (temp_v1_2 < 0x44) {
                        var_s0 = combo08;
                    }
                }
                var_s3 = Return3DComboTile(var_s1->unk_8);
                break;
            case 0xA:
                temp_v1_3 = var_s1->unk_8;
                if (temp_v1_3 < 9) {
                    var_s0 = chain01;
                } else if (temp_v1_3 < 0x11) {
                    var_s0 = chain02;
                } else if (temp_v1_3 < 0x19) {
                    var_s0 = chain03;
                } else if (temp_v1_3 < 0x21) {
                    var_s0 = chain04;
                } else if (temp_v1_3 < 0x29) {
                    var_s0 = chain05;
                } else if (temp_v1_3 < 0x31) {
                    var_s0 = chain06;
                } else if (temp_v1_3 < 0x39) {
                    var_s0 = chain07;
                } else if (temp_v1_3 < 0x41) {
                    var_s0 = chain08;
                } else if (temp_v1_3 < 0x49) {
                    var_s0 = chain09;
                } else if (temp_v1_3 < 0x51) {
                    var_s0 = chain010;
                } else {
                    temp_v1_4 = var_s1->unk_8;
                    if (temp_v1_4 < 0x59) {
                        var_s0 = chain011;
                    } else {
                        var_s0 = chain013;
                        if (temp_v1_4 < 0x61) {
                            var_s0 = chain012;
                        }
                    }
                }
                var_s3 = Return3DChainTile(var_s1->unk_8);
                break;
            case 0xD:
                var_s0 = combo09;
                break;
        }
        temp_a3 = glistp;
        temp_t0 = (s32) (var_s1->unk_28 << 0x10) >> 0x12;
        temp_t1 = (s32) (var_s1->unk_30 << 0x10) >> 0x12;
        glistp = temp_a3 + 8;
        temp_a3->words.w0 = 0xFD500000;
        glistp = temp_a3 + 0x10;
        temp_a3->unk_8 = 0xF5500000;
        glistp = temp_a3 + 0x18;
        temp_a3->unk_10 = 0xE6000000;
        glistp = temp_a3 + 0x20;
        temp_a3->unk_18 = 0xF3000000;
        glistp = temp_a3 + 0x28;
        glistp = temp_a3 + 0x30;
        glistp = temp_a3 + 0x38;
        temp_a3->words.w1 = (u32) var_s0;
        temp_a3->unk_C = 0x07000000;
        temp_a3->unk_14 = 0;
        temp_a3->unk_1C = 0x073FF100;
        temp_a3->unk_20 = 0xE7000000;
        temp_a3->unk_24 = 0;
        temp_a3->unk_28 = 0xF5481000;
        temp_a3->unk_2C = 0;
        temp_a3->unk_30 = 0xF2000000;
        temp_a3->unk_34 = 0xFC07C;
        if (var_s3 == 7) {
            glistp = temp_a3 + 0x40;
            glistp = temp_a3 + 0x48;
            temp_a3->unk_38 = 0xE7000000;
            temp_a3->unk_3C = 0;
            temp_a3->unk_40 = 0xF5481086;
            temp_a3->unk_44 = 0x07000000;
            glistp = temp_a3 + 0x50;
            temp_a3->unk_48 = 0xF2000000;
            temp_a3->unk_4C = 0x0703C03C;
        }
        if (var_s1->unk_4 == 0xD) {
            temp_a1 = glistp;
            glistp = temp_a1 + 8;
            glistp = temp_a1 + 0x10;
            glistp = temp_a1 + 0x18;
            temp_a1->unk_8 = 0xF5481080;
            glistp = temp_a1 + 0x20;
            temp_a1->unk_14 = 0x0707C03C;
            temp_a1->unk_18 = (s32) (((((temp_t0 + 0x20) * 4) & 0xFFF) << 0xC) | ((((temp_t1 + 0x10) * 4) & 0xFFF) | 0xE4000000));
            glistp = temp_a1 + 0x28;
            temp_a1->unk_20 = 0xB4000000;
            glistp = temp_a1 + 0x30;
            temp_a1->words.w0 = 0xE7000000;
            temp_a1->words.w1 = 0;
            temp_a1->unk_C = 0x07000000;
            temp_a1->unk_10 = 0xF2000000;
            temp_a1->unk_1C = (s32) ((((temp_t0 * 4) & 0xFFF) << 0xC) | (((temp_t1 * 4) & 0xFFF) | 0x07000000));
            temp_a1->unk_24 = 0;
            temp_a1->unk_28 = 0xB3000000;
            temp_a1->unk_2C = 0x04000400;
        } else {
            temp_a1_2 = glistp;
            glistp = temp_a1_2 + 8;
            temp_a1_2->words.w0 = ((((temp_t0 + 0x10) * 4) & 0xFFF) << 0xC) | ((((temp_t1 + 0x10) * 4) & 0xFFF) | 0xE4000000);
            glistp = temp_a1_2 + 0x10;
            temp_a1_2->unk_8 = 0xB4000000;
            glistp = temp_a1_2 + 0x18;
            temp_a1_2->words.w1 = ((var_s3 & 7) << 0x18) | (((temp_t0 * 4) & 0xFFF) << 0xC) | ((temp_t1 * 4) & 0xFFF);
            temp_a1_2->unk_C = 0;
            temp_a1_2->unk_10 = 0xB3000000;
            temp_a1_2->unk_14 = 0x04000400;
        }
        var_s2 += 1;
        glistp->words.w0 = 0xE7000000;
        glistp->words.w1 = 0;
        glistp += 8;
        var_s1 += 0x68;
        if (var_s2 < 0xA) {
            goto loop_1;
        }
    }
    var_s2_2 = 6;
    var_t7 = 0x8000;
    var_t6 = 0xFD100000;
    var_t5 = &gTheGame.unk_8BE4;
    var_t4 = 0xE8000000;
    var_t2 = 0x07000000;
    var_t3 = 0xF0000000;
    var_s0_2 = sp14 + 0xC0;
    do {
        temp_v1_5 = glistp;
        temp_v1_5->words.w0 = 0xE7000000;
        temp_v1_5->words.w1 = 0;
        temp_v1_5->unk_8 = 0xBA000E02;
        temp_v1_5->unk_C = var_t7;
        temp_v1_5->unk_10 = var_t6;
        glistp = temp_v1_5 + 8;
        glistp = temp_v1_5 + 0x10;
        glistp = temp_v1_5 + 0x18;
        glistp = temp_v1_5 + 0x20;
        glistp = temp_v1_5 + 0x28;
        glistp = temp_v1_5 + 0x30;
        glistp = temp_v1_5 + 0x38;
        glistp = temp_v1_5 + 0x40;
        temp_v1_5->unk_18 = var_t4;
        temp_v1_5->unk_1C = 0;
        temp_v1_5->unk_20 = 0xF5000100;
        temp_v1_5->unk_24 = var_t2;
        temp_v1_5->unk_28 = 0xE6000000;
        temp_v1_5->unk_2C = 0;
        temp_v1_5->unk_30 = var_t3;
        temp_v1_5->unk_34 = 0x073FC000;
        temp_v1_5->unk_38 = 0xE7000000;
        temp_v1_5->unk_3C = 0;
        glistp = temp_v1_5 + 0x48;
        temp_v1_5->unk_40 = 0xE7000000;
        temp_v1_5->unk_44 = 0;
        temp_v1_5->unk_14 = (void *) *var_t5;
        sp18 = var_t2;
        sp1C = var_t3;
        sp20 = var_t4;
        sp24 = var_t5;
        sp28 = var_t6;
        sp2C = var_t7;
        guS2DEmuBgRect1Cyc(&glistp, (uObjBg *) (var_t5 + 0x11C));
        temp_a3_2 = glistp;
        temp_a3_2->words.w0 = 0xE7000000;
        temp_a3_2->words.w1 = 0;
        temp_a3_2->unk_8 = 0xBA000E02;
        temp_a3_2->unk_C = var_t7;
        temp_a3_2->unk_14 = numberTable;
        temp_a3_2->unk_10 = var_t6;
        temp_a3_2->unk_1C = 0;
        temp_a3_2->unk_20 = 0xF5000100;
        temp_a3_2->unk_18 = var_t4;
        temp_a3_2->unk_28 = 0xE6000000;
        temp_a3_2->unk_2C = 0;
        temp_a3_2->unk_24 = var_t2;
        temp_a3_2->unk_34 = 0x073FC000;
        temp_a3_2->unk_38 = 0xE7000000;
        temp_a3_2->unk_3C = 0;
        temp_a3_2->unk_30 = var_t3;
        temp_v1_6 = var_s0_2->unk_18710;
        glistp = temp_a3_2 + 8;
        glistp = temp_a3_2 + 0x10;
        glistp = temp_a3_2 + 0x18;
        glistp = temp_a3_2 + 0x20;
        glistp = temp_a3_2 + 0x28;
        glistp = temp_a3_2 + 0x30;
        glistp = temp_a3_2 + 0x38;
        glistp = temp_a3_2 + 0x40;
        if (((temp_v1_6 == 0xA) | (temp_v1_6 == 0xC)) != 0) {
            glistp = temp_a3_2 + 0x48;
            temp_a3_2->unk_40 = 0xFD500000;
            temp_a3_2->unk_44 = &D_01022620_usa;
            glistp = temp_a3_2 + 0x50;
            temp_a3_2->unk_48 = 0xF5500000;
            glistp = temp_a3_2 + 0x58;
            glistp = temp_a3_2 + 0x60;
            temp_a3_2->unk_58 = 0xF3000000;
            glistp = temp_a3_2 + 0x68;
            glistp = temp_a3_2 + 0x70;
            glistp = temp_a3_2 + 0x78;
            glistp = temp_a3_2 + 0x80;
            temp_a3_2->unk_4C = var_t2;
            temp_a3_2->unk_50 = 0xE6000000;
            temp_a3_2->unk_54 = 0;
            temp_a3_2->unk_5C = 0x073FF100;
            temp_a3_2->unk_60 = 0xE7000000;
            temp_a3_2->unk_64 = 0;
            temp_a3_2->unk_68 = 0xF5481000;
            temp_a3_2->unk_6C = 0;
            temp_a3_2->unk_70 = 0xF2000000;
            temp_a3_2->unk_74 = 0xFC07C;
            temp_a3_2->unk_78 = 0xE7000000;
            temp_a3_2->unk_7C = 0;
            temp_t0_2 = (s32) (var_s0_2->unk_186F8 << 0x10) >> 0x12;
            temp_t1_2 = (s32) (var_s0_2->unk_18700 << 0x10) >> 0x12;
            if (var_s0_2->unk_18710 == 0xA) {
                glistp = temp_a3_2 + 0x88;
                temp_a3_2->unk_84 = 0x03000000;
                temp_a3_2->unk_80 = 0xF5481000;
                glistp = temp_a3_2 + 0x90;
                temp_a3_2->unk_88 = 0xF2000000;
                temp_a3_2->unk_8C = 0x030BC03C;
            } else {
                glistp = temp_a3_2 + 0x88;
                temp_a3_2->unk_84 = 0x03000000;
                temp_a3_2->unk_80 = 0xF5481080;
                glistp = temp_a3_2 + 0x90;
                temp_a3_2->unk_88 = 0xF2000000;
                temp_a3_2->unk_8C = 0x030BC03C;
            }
            temp_a1_3 = glistp;
            glistp = temp_a1_3 + 8;
            temp_a1_3->words.w0 = ((((temp_t0_2 + 0x30) * 4) & 0xFFF) << 0xC) | ((((temp_t1_2 + 0x10) * 4) & 0xFFF) | 0xE4000000);
            glistp = temp_a1_3 + 0x10;
            temp_a1_3->unk_8 = 0xB4000000;
            glistp = temp_a1_3 + 0x18;
            temp_a1_3->unk_10 = 0xB3000000;
            temp_a1_3->words.w1 = (((temp_t0_2 * 4) & 0xFFF) << 0xC) | (((temp_t1_2 * 4) & 0xFFF) | 0x03000000);
            temp_a1_3->unk_C = 0;
            temp_a1_3->unk_14 = 0x04000400;
            glistp = temp_a1_3 + 0x20;
            temp_a1_3->unk_18 = 0xE7000000;
            temp_a1_3->unk_1C = 0;
        }
        var_s2_2 += 1;
        var_s0_2 += 0x20;
    } while (var_s2_2 < 0x46);
    var_s2_3 = 1;
    temp_v0_2 = glistp;
    glistp = temp_v0_2 + 8;
    glistp = temp_v0_2 + 0x10;
    temp_v0_2->unk_C = 0x8000;
    glistp = temp_v0_2 + 0x18;
    temp_v0_2->unk_10 = 0xFD100000;
    temp_v0_2->unk_14 = numberTable;
    glistp = temp_v0_2 + 0x20;
    temp_v0_2->unk_18 = 0xE8000000;
    glistp = temp_v0_2 + 0x28;
    temp_v0_2->unk_24 = 0x07000000;
    glistp = temp_v0_2 + 0x30;
    temp_v0_2->unk_28 = 0xE6000000;
    glistp = temp_v0_2 + 0x38;
    temp_v0_2->unk_30 = 0xF0000000;
    temp_v0_2->words.w0 = 0xE7000000;
    temp_v0_2->words.w1 = 0;
    temp_v0_2->unk_8 = 0xBA000E02;
    temp_v0_2->unk_1C = 0;
    temp_v0_2->unk_20 = 0xF5000100;
    temp_v0_2->unk_2C = 0;
    temp_v0_2->unk_34 = 0x073FC000;
    glistp = temp_v0_2 + 0x40;
    temp_v0_2->unk_38 = 0xE7000000;
    temp_v0_2->unk_3C = 0;
    do {
        temp_v0_3 = 0xA - var_s2_3;
        temp_v1_7 = temp_v0_3 * 0x18;
        temp_a3_3 = glistp;
        temp_t2 = *(&gTheGame.gSPRITE[0].s.imageAdrs + temp_v1_7);
        temp_t0_3 = (s32) ((u16) gTheGame.gSPRITE[temp_v0_3].s.objX << 0x10) >> 0x12;
        temp_t1_3 = (s32) (*(&gTheGame.gSPRITE[0].s.objY + temp_v1_7) << 0x10) >> 0x12;
        glistp = temp_a3_3 + 8;
        temp_a3_3->words.w0 = 0xFD500000;
        temp_a3_3->words.w1 = (u32) arrow;
        glistp = temp_a3_3 + 0x10;
        temp_a3_3->unk_8 = 0xF5500000;
        temp_a3_3->unk_C = 0x07000000;
        glistp = temp_a3_3 + 0x18;
        temp_a3_3->unk_10 = 0xE6000000;
        glistp = temp_a3_3 + 0x20;
        temp_a3_3->unk_18 = 0xF3000000;
        glistp = temp_a3_3 + 0x28;
        glistp = temp_a3_3 + 0x30;
        glistp = temp_a3_3 + 0x38;
        temp_a3_3->unk_14 = 0;
        temp_a3_3->unk_1C = 0x070FF100;
        temp_a3_3->unk_20 = 0xE7000000;
        temp_a3_3->unk_24 = 0;
        temp_a3_3->unk_28 = 0xF5481000;
        temp_a3_3->unk_2C = 0;
        temp_a3_3->unk_30 = 0xF2000000;
        temp_a3_3->unk_34 = 0xFC01C;
        if (var_s2_3 == 1) {
            glistp = temp_a3_3 + 0x40;
            glistp = temp_a3_3 + 0x48;
            temp_a3_3->unk_40 = (s32) ((temp_t2 & 0x1FF) | 0xF5481000);
            temp_a3_3->unk_44 = 0x01000000;
            temp_a3_3->unk_38 = 0xE7000000;
            temp_a3_3->unk_3C = 0;
            glistp = temp_a3_3 + 0x50;
            temp_a3_3->unk_48 = 0xF2000000;
            temp_a3_3->unk_4C = 0x0101C01C;
        } else {
            glistp = temp_a3_3 + 0x40;
            temp_a3_3->unk_38 = (s32) ((temp_t2 & 0x1FF) | 0xF5481000);
            temp_a3_3->unk_3C = 0x02000000;
            glistp = temp_a3_3 + 0x48;
            temp_a3_3->unk_40 = 0xF2000000;
            temp_a3_3->unk_44 = 0x0201C01C;
        }
        temp_a2 = glistp;
        temp_a1_4 = var_s2_3 & 7;
        var_s2_3 += 1;
        glistp = temp_a2 + 8;
        glistp = temp_a2 + 0x10;
        temp_a2->unk_8 = 0xB4000000;
        glistp = temp_a2 + 0x18;
        temp_a2->unk_10 = 0xB3000000;
        glistp = temp_a2 + 0x20;
        temp_a2->words.w0 = ((((temp_t0_3 + 8) * 4) & 0xFFF) << 0xC) | ((((temp_t1_3 + 8) * 4) & 0xFFF) | 0xE4000000);
        temp_a2->words.w1 = (temp_a1_4 << 0x18) | (((temp_t0_3 * 4) & 0xFFF) << 0xC) | ((temp_t1_3 * 4) & 0xFFF);
        temp_a2->unk_C = 0;
        temp_a2->unk_14 = 0x04000400;
        temp_a2->unk_18 = 0xE7000000;
        temp_a2->unk_1C = 0;
    } while (var_s2_3 < 3);
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80063110_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_80063110_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_80063110_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_80063110_usa);
#endif

#if VERSION_USA
#if 0
extern ? D_01018E90_usa;

void func_80063F8C_usa(s32 arg0, s32 arg1) {
    Gfx *temp_a1;
    Gfx *temp_v0;
    Gfx *temp_v0_3;
    Gfx *temp_v1_2;
    s32 temp_v1;
    s32 var_s2;
    s32 var_t0;
    s32 var_t1;
    s32 var_t2;
    s32 var_t3;
    u16 temp_v1_3;
    void *temp_a3;
    void *temp_v0_2;

    var_s2 = saved_reg_s2;
    if ((arg0 + (arg1 * 0xB0))->unk_172A8 == 8) {
        temp_v0 = glistp;
        glistp = temp_v0 + 8;
        glistp = temp_v0 + 0x10;
        glistp = temp_v0 + 0x18;
        temp_v0->unk_10 = 0xFD900000;
        temp_v0->unk_14 = &D_01018E90_usa;
        glistp = temp_v0 + 0x20;
        temp_v0->unk_18 = 0xF5900000;
        temp_v0->unk_1C = 0x07000000;
        glistp = temp_v0 + 0x28;
        temp_v0->unk_20 = 0xE6000000;
        glistp = temp_v0 + 0x30;
        temp_v0->unk_28 = 0xF3000000;
        glistp = temp_v0 + 0x38;
        glistp = temp_v0 + 0x40;
        glistp = temp_v0 + 0x48;
        temp_v0->words.w0 = 0xE7000000;
        temp_v0->words.w1 = 0;
        temp_v0->unk_8 = 0xBA000E02;
        temp_v0->unk_C = 0;
        temp_v0->unk_24 = 0;
        temp_v0->unk_2C = 0x071FF100;
        temp_v0->unk_30 = 0xE7000000;
        temp_v0->unk_34 = 0;
        temp_v0->unk_38 = 0xF5881000;
        temp_v0->unk_3C = 0;
        temp_v0->unk_40 = 0xF2000000;
        temp_v0->unk_44 = 0xFC03C;
        Set3DTile();
        var_t0 = 0;
        temp_v1 = arg1 * 0x960;
        var_t3 = temp_v1;
        temp_v1_2 = glistp;
        var_t2 = 0;
        var_t1 = 0x2208;
        glistp = temp_v1_2 + 8;
        glistp = temp_v1_2 + 0x10;
        glistp = temp_v1_2 + 0x18;
        temp_v1_2->unk_14 = -0xC07;
        glistp = temp_v1_2 + 0x20;
        temp_v1_2->unk_18 = 0xFA000000;
        temp_v1_2->words.w0 = 0xE7000000;
        temp_v1_2->words.w1 = 0;
        temp_v1_2->unk_8 = 0xB900031D;
        temp_v1_2->unk_C = 0x504240;
        temp_v1_2->unk_10 = 0xFC11FE23;
        temp_v1_2->unk_1C = -1;
        do {
            if (((u32) (var_t0 - 2) < 6U) && ((arg0 + (var_t1 + (arg1 * 0x2520)))->unk_10254 != 0) && ((arg0 + var_t3)->unk_15FEC >= -0x13)) {
                temp_v0_2 = arg0 + (temp_v1 + 0x15FE8) + var_t2;
                temp_v1_3 = temp_v0_2->unk_2A;
                temp_a3 = temp_v0_2 + 0x18;
                switch (temp_v1_3) {                /* irregular */
                    case 0x0:
                        var_s2 = 0;
                        break;
                    case 0x6:
                        var_s2 = 3;
                        break;
                    case 0x2:
                        var_s2 = 1;
                        break;
                    case 0x4:
                        var_s2 = 2;
                        break;
                }
                temp_a1 = glistp;
                temp_a1->words.w0 = ((((((s32) (temp_v0_2->unk_18 << 0x10) >> 0x12) + 0x18) * 4) & 0xFFF) << 0xC) | ((((((s32) (temp_a3->unk_8 << 0x10) >> 0x12) + 0x10) * 4) & 0xFFF) | 0xE4000000);
                glistp = temp_a1 + 8;
                glistp = temp_a1 + 0x10;
                temp_a1->unk_8 = 0xB4000000;
                glistp = temp_a1 + 0x18;
                temp_a1->unk_10 = 0xB3000000;
                glistp = temp_a1 + 0x20;
                temp_a1->unk_18 = 0xE7000000;
                temp_a1->unk_C = 0;
                temp_a1->unk_14 = 0x02AE0400;
                temp_a1->unk_1C = 0;
                temp_a1->words.w1 = ((var_s2 & 7) << 0x18) | ((temp_v0_2->unk_18 & 0xFFF) << 0xC) | (temp_a3->unk_8 & 0xFFF);
            }
            var_t3 += 0x30;
            var_t2 += 0x30;
            var_t0 += 1;
            var_t1 += 0x2C;
        } while (var_t0 < 0x12);
        temp_v0_3 = glistp;
        glistp = temp_v0_3 + 8;
        temp_v0_3->words.w0 = 0xE7000000;
        glistp = temp_v0_3 + 0x10;
        temp_v0_3->words.w1 = 0;
        temp_v0_3->unk_8 = 0xFCFFFFFF;
        temp_v0_3->unk_C = 0xFFFCF279;
        glistp = temp_v0_3 + 0x18;
        temp_v0_3->unk_10 = 0xB900031D;
        temp_v0_3->unk_14 = 0x0F0A7008;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80063F8C_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_80063F8C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_80063F8C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_80063F8C_usa);
#endif

void func_800643A4_usa(enum_func_800643A4_usa_arg0 arg0, const u16 arg1[], s32 arg2) {
    s32 y;
    s32 x;
    s32 tile;

    gDPPipeSync(glistp++);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, arg1);

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(glistp++, D_010192A8_usa);
    gDPLoadTextureBlock(glistp++, D_0101C4C0_usa, G_IM_FMT_CI, G_IM_SIZ_8b, D_0101C4C0_USA_WIDTH, D_0101C4C0_USA_HEIGHT,
                        0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Set3DTile();

    switch (arg0) {
        case ENUM_FUNC_800643A4_USA_ARG0_1:
            x = 141;
            y = 170;
            tile = 4;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_2:
            x = 141;
            y = 187;
            tile = 4;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_3:
            x = 141;
            y = 204;
            tile = 4;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_4:
            x = 163;
            y = 170;
            tile = 5;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_5:
            x = 163;
            y = 187;
            tile = 5;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_6:
            x = 163;
            y = 204;
            tile = 5;
            break;
    }

    y += arg2;
    gSPTextureRectangle(glistp++, x << 2, y << 2, (x + 0x10) << 2, (y + 0x10) << 2, tile, 0, 0, 0x0400, 0x0400);

    gDPPipeSync(glistp++);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, (*fb)->unk_19040);
}

void func_80064728_usa(enum_func_800643A4_usa_arg0 arg0, const u16 arg1[], s32 arg2) {
    s32 y;
    s32 x;
    s32 tile;

    gDPPipeSync(glistp++);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, arg1);

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(glistp++, D_010192A8_usa);
    gDPLoadTextureBlock(glistp++, D_0101C4C0_usa, G_IM_FMT_CI, G_IM_SIZ_8b, D_0101C4C0_USA_WIDTH, D_0101C4C0_USA_HEIGHT,
                        0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    Set3DTile();

    switch (arg0) {
        case ENUM_FUNC_800643A4_USA_ARG0_1:
            x = 141;
            y = 170;
            tile = 6;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_2:
            x = 141;
            y = 187;
            tile = 6;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_3:
            x = 141;
            y = 204;
            tile = 6;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_4:
            x = 163;
            y = 170;
            tile = 7;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_5:
            x = 163;
            y = 187;
            tile = 7;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_6:
            x = 163;
            y = 204;
            tile = 7;
            break;
    }

    y += arg2;
    gSPTextureRectangle(glistp++, x << 2, y << 2, (x + 0x10) << 2, (y + 0x10) << 2, tile, 0, 0, 0x0400, 0x0400);

    gDPPipeSync(glistp++);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, (*fb)->unk_19040);
}

void func_80064AAC_usa(enum_func_800643A4_usa_arg0 arg0, const u16 arg1[], s32 arg2) {
    s32 y;
    s32 x;

    gDPPipeSync(glistp++);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, arg1);

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(glistp++, D_010192A8_usa);
    gDPLoadTextureBlock(glistp++, D_0101CCC0_usa, G_IM_FMT_CI, G_IM_SIZ_8b, D_0101CCC0_USA_WIDTH, D_0101CCC0_USA_HEIGHT,
                        0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                        G_TX_NOLOD);

    gDPPipeSync(glistp++);

    if ((s32)arg0 <= ENUM_FUNC_800643A4_USA_ARG0_3) {
        gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0002, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                   G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    } else {
        gDPSetTile(glistp++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0082, 6, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                   G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    }

    gDPSetTileSize(glistp++, 6, 0, 0, 0x003C, 0x003C);

    switch (arg0) {
        case ENUM_FUNC_800643A4_USA_ARG0_1:
            x = 0x8D;
            y = 0xAA;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_2:
            x = 0x8D;
            y = 0xBB;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_3:
            x = 0x8D;
            y = 0xCC;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_4:
            x = 0xA3;
            y = 0xAA;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_5:
            x = 0xA3;
            y = 0xBB;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_6:
            x = 0xA3;
            y = 0xCC;
            break;
    }

    y += arg2;
    gSPTextureRectangle(glistp++, x << 2, y << 2, (x + 0x10) << 2, (y + 0x10) << 2, 6, 0, 0, 0x0400, 0x0400);

    gDPPipeSync(glistp++);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, (*fb)->unk_19040);
}

#if VERSION_USA
#if 0
extern ? D_01023C80_usa;
extern ? D_01024480_usa;

void func_80064E44_usa(s32 arg0) {
    s32 sp14;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    ? *var_v0;
    Gfx *temp_a1;
    Gfx *temp_v1;
    Gfx *var_v1;
    s32 temp_a0;
    s32 temp_s1;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 var_fp;
    s32 var_s0;
    s32 var_s2;
    s32 var_s3;
    s32 var_s6;
    s32 var_s7;
    s32 var_t0;
    s32 var_t1;
    u16 temp_v1_4;

    var_s0 = saved_reg_s0;
    var_s6 = 0;
    temp_v1 = glistp;
    var_t0 = 0;
    var_s7 = 0;
    var_fp = 0;
    sp14 = arg0;
    var_t1 = gMain == GMAIN_393;
    sp1C = var_t1 * 0x444;
    glistp = temp_v1 + 8;
    glistp = temp_v1 + 0x10;
    temp_v1->unk_C = 0x8000;
    glistp = temp_v1 + 0x18;
    temp_v1->unk_10 = 0xFD100000;
    temp_v1->unk_14 = numberTable;
    glistp = temp_v1 + 0x20;
    temp_v1->unk_18 = 0xE8000000;
    glistp = temp_v1 + 0x28;
    temp_v1->unk_24 = 0x07000000;
    glistp = temp_v1 + 0x30;
    temp_v1->unk_28 = 0xE6000000;
    glistp = temp_v1 + 0x38;
    temp_v1->words.w0 = 0xE7000000;
    temp_v1->words.w1 = 0;
    temp_v1->unk_8 = 0xBA000E02;
    temp_v1->unk_1C = 0;
    temp_v1->unk_20 = 0xF5000100;
    temp_v1->unk_2C = 0;
    temp_v1->unk_30 = 0xF0000000;
    temp_v1->unk_34 = 0x073FC000;
    glistp = temp_v1 + 0x40;
    temp_v1->unk_38 = 0xE7000000;
    temp_v1->unk_3C = 0;
loop_1:
    var_s3 = var_fp;
    var_s2 = 0;
    temp_s5 = (sp1C - var_t1) * 0x10;
loop_2:
    temp_a0 = var_s2 + var_s7 + temp_s5;
    if (*(&gTheGame.tetrisWell[0].block[0][0].bomb + temp_a0) == sp14) {
        temp_v1_2 = var_s3 + temp_s5;
        temp_s4 = (s32) (*(gTheGame.tetrisWell[0].block_rect[0] + temp_v1_2) << 0x10) >> 0x12;
        temp_s1 = (s32) (*(&gTheGame.tetrisWell[0].block_rect[0][0].s.objY + temp_v1_2) << 0x10) >> 0x12;
        if ((gMain < 0x395) || ((u32) (temp_s1 - 0x24) < 0xAEU)) {
            temp_v1_3 = *(&gTheGame.tetrisWell[0].block[0][0].currRow + temp_a0);
            if (temp_v1_3 >= 0) {
                if (temp_v1_3 < 2) {
                    var_v1 = glistp;
                    glistp = var_v1 + 8;
                    var_v1->words.w0 = 0xFD500000;
                    var_v0 = &D_01023C80_usa;
                    goto block_10;
                }
                if (temp_v1_3 < 4) {
                    var_v1 = glistp;
                    glistp = var_v1 + 8;
                    var_v1->words.w0 = 0xFD500000;
                    var_v0 = &D_01024480_usa;
block_10:
                    var_v1->words.w1 = (u32) var_v0;
                    glistp = var_v1 + 0x10;
                    var_v1->unk_8 = 0xF5500000;
                    var_v1->unk_C = 0x07000000;
                    glistp = var_v1 + 0x18;
                    var_v1->unk_10 = 0xE6000000;
                    glistp = var_v1 + 0x20;
                    var_v1->unk_18 = 0xF3000000;
                    glistp = var_v1 + 0x28;
                    var_v1->unk_20 = 0xE7000000;
                    glistp = var_v1 + 0x30;
                    glistp = var_v1 + 0x38;
                    var_v1->unk_14 = 0;
                    var_v1->unk_1C = 0x073FF100;
                    var_v1->unk_24 = 0;
                    var_v1->unk_28 = 0xF5481000;
                    var_v1->unk_2C = 0;
                    var_v1->unk_30 = 0xF2000000;
                    var_v1->unk_34 = 0xFC07C;
                }
            }
            sp20 = var_t0;
            sp24 = var_t1;
            Set3DTile();
            temp_v1_4 = *(&gTheGame.tetrisWell[0].block_rect[0][0].s.imageAdrs + (var_s3 + temp_s5));
            switch (temp_v1_4) {                    /* irregular */
                case 0x0:
                    var_s0 = 0;
                    break;
                case 0x4:
                    var_s0 = 2;
                    break;
                case 0x80:
                    var_s0 = 4;
                    break;
                case 0x86:
                    var_s0 = 7;
                    break;
                case 0x2:
                    var_s0 = 1;
                    break;
                case 0x6:
                    var_s0 = 3;
                    break;
                case 0x82:
                    var_s0 = 5;
                    break;
                case 0x84:
                    var_s0 = 6;
                    break;
            }
            temp_a1 = glistp;
            glistp = temp_a1 + 8;
            temp_a1->words.w0 = ((((temp_s4 + 0x10) * 4) & 0xFFF) << 0xC) | ((((temp_s1 + 0x10) * 4) & 0xFFF) | 0xE4000000);
            glistp = temp_a1 + 0x10;
            temp_a1->unk_8 = 0xB4000000;
            glistp = temp_a1 + 0x18;
            temp_a1->unk_10 = 0xB3000000;
            glistp = temp_a1 + 0x20;
            temp_a1->words.w1 = ((var_s0 & 7) << 0x18) | (((temp_s4 * 4) & 0xFFF) << 0xC) | ((temp_s1 * 4) & 0xFFF);
            temp_a1->unk_C = 0;
            temp_a1->unk_14 = 0x04000400;
            temp_a1->unk_18 = 0xE7000000;
            temp_a1->unk_1C = 0;
            goto block_41;
        }
        goto block_44;
    }
block_41:
    var_s6 += 1;
    if (var_s6 < 0x15) {
block_44:
        var_s2 += 0x2C;
        var_s3 += 0x18;
        if (var_s2 >= 0x108) {
            var_s7 += 0x318;
            var_t0 += 1;
            var_fp += 0x90;
            if (var_t0 >= 0xC) {
                return;
            }
            goto loop_1;
        }
        goto loop_2;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80064E44_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_80064E44_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_80064E44_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_80064E44_usa);
#endif

/**
 * Original nanme: Draw3DTetris
 */
void Draw3DTetris(struct_gInfo_unk_00068 *dynamicp) {
    s32 sp28[GAME_BUFFER_LEN]; // end_attack?
    u16 perspNorm;
    nbool sp3C = ntrue;
    s32 num;

    if (gAllVertex == NULL) {
        return;
    }

    Draw3DBackground();
    if ((gMain == GMAIN_384) && (gCounter < ADJUST_COUNTER(100))) {
        return;
    }

    if (gMain >= GMAIN_38F) {
        func_80053E64_usa(dynamicp);
    }

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 31, SCREEN_WIDTH, SCREEN_HEIGHT - 19);

    if (((gMain == GMAIN_388) || (gMain < GMAIN_384)) &&
        ((gTheGame.totalPlayer == 2) || (gSelection == SELECTION_82))) {
        sp3C = nfalse;
    }

    for (num = 0; num < gTheGame.totalPlayer; num++) {
        gDPPipeSync(glistp++);
        gDPSetTextureLUT(glistp++, G_TT_RGBA16);
        gDPLoadTLUT_pal256(glistp++, colorTable);
        gSPMatrix(glistp++, &dynamicp->trans[num], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

        guPerspective(&dynamicp->unk_10000[num], &perspNorm, 33.0f, 0.88f, 10.0f, 3000.0f, 1.0f);
        guLookAt(&dynamicp->unk_10080[num], 0.0f, 0.0f, 900.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

        gSPPerspNormalize(glistp++, perspNorm);
        gSPMatrix(glistp++, &dynamicp->unk_10000[num], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gSPMatrix(glistp++, &dynamicp->unk_10080[num], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        gDPPipeSync(glistp++);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA, G_CC_MODULATEIA);
        gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gSPMatrix(glistp++, &gIdent, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPMatrix(glistp++, &dynamicp->rotate[num], G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);

        if (sp3C) {
            Draw3DTetrisNewBlock(dynamicp, &gTheGame.tetrisWell[num]);
            Draw3DAttack(dynamicp, num, 0);
            Draw3DBackTetrisWell(dynamicp, num);

            sp28[num] = Draw3DAttack(dynamicp, num, -1);
            Draw3DFrontTetrisWell(dynamicp, num);

            gDPPipeSync(glistp++);
            gDPSetRenderMode(glistp++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

            if (gMain < GMAIN_38E) {
                Draw3DIcon(dynamicp, num);
            }
            if ((gSelection == SELECTION_AA) || (gSelection == SELECTION_B4)) {
                Draw3DClearLine(dynamicp, num);
            }
        }
    }

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 7, SCREEN_WIDTH, SCREEN_HEIGHT - 1);

    if (gMain == GMAIN_384) {
        func_80053E64_usa(dynamicp);
    }

    func_80047A00_usa();

    gDPPipeSync(glistp++);
    gDPSetTexturePersp(glistp++, G_TP_NONE);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(glistp++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);

    Draw3DText(dynamicp);
    Draw3DMiscStuff(dynamicp);
    if ((gSelection == SELECTION_AA) || (gSelection == SELECTION_B4)) {
        for (num = 0; num < gTheGame.totalPlayer; num++) {
            Draw3DClearSign(dynamicp, num);
        }
    }

    Draw3DAnimation(dynamicp, -1, -1);
    if (sp3C) {
        for (num = 0; num < gTheGame.totalPlayer; num++) {
            Draw3DAttackBrick(dynamicp, num, sp28[num]);
            Draw3DExplosion(dynamicp, num);
        }
    }

    if ((gMain == GMAIN_387) || ((gMain == GMAIN_384) && (gCounter > ADJUST_COUNTER(180)))) {
        Draw3DCursor(dynamicp);
    }
    if (gMain >= GMAIN_388) {
        DrawPauseOver(dynamicp);
    } else if (gMain == GMAIN_384) {
        DrawCountDown();
    }

    gSPTexture(glistp++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
}
