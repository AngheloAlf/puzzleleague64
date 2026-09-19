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
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DFrontTetrisWell);
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
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DBackTetrisWell);
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

void func_8005F984_usa(s32 arg0, s32 arg1, s32 arg2) {
    if (arg2 == 9) {
        return;
    }

    gSPVertex(glistp++, &gAllVertex[arg0 * 0x90 + arg1 * 8], 8, 0);
    gSPTexture(glistp++, 0x8000, 0x8000, 0, arg2 - 1, G_ON);

    if ((arg1 >= 9) || (arg1 <= 0)) {
        gSP2Triangles(glistp++, 4, 5, 6, 0, 4, 7, 5, 0);
    } else {
        gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
    }
}

void func_8005FA6C_usa(s32 arg0, s32 arg1) {
    if (arg1 == 9) {
        return;
    }

    gSPTexture(glistp++, 0x8000, 0x8000, 0, arg1 - 1, G_ON);
    if ((arg0 >= 9) || (arg0 <= 0)) {
        gSP2Triangles(glistp++, 4, 5, 6, 0, 4, 7, 5, 0);
    } else {
        gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_8005FB10_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_8005FDE0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_8005E520_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_8005E6D0_ger);
#endif

// Draw3DTetrisSwitch??
void func_8005FD38_usa(struct_gInfo_unk_00068 *arg0, s32 arg1, block_t *arg2, block_t *arg3) {
    s32 temp_v1 = arg0->cursorBlock[arg1].sy * 0x90;

    if (arg2->type != BLOCKTYPE_0) {
        gSPMatrix(glistp++, &arg0->left3D[arg1], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPTexture(glistp++, 0x8000, 0x8000, 0, arg2->type - 1, G_ON);
        gSPVertex(glistp++, &gAllVertex[temp_v1], 8, 0);
        gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
        gSPPopMatrix(glistp++, G_MTX_MODELVIEW);
    }

    if (arg3->type != BLOCKTYPE_0) {
        gSPMatrix(glistp++, &arg0->right3D[arg1], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPTexture(glistp++, 0x8000, 0x8000, 0, arg3->type - 1, G_ON);
        gSPVertex(glistp++, &gAllVertex[temp_v1], 8, 0);
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

    for (col = 1; col < 9; col++) {
        block = &well->new_block[col];

        gSPTexture(glistp++, 0x8000, 0x8000, 0, block->type - 1, G_ON);
        gSPVertex(glistp++, &gAllVertex[0xC * 0x90 + col * 0x8], 8, 0);
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
            gSPVertex(glistp++, &gAllVertex[a2 * 0x90 + temp_a1 * 8], 8, 0);
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
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DAttackBrick);
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

void func_800615D8_usa(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    gSPTexture(glistp++, 0x8000, 0x8000, 0, arg2, G_ON);
    gSPVertex(glistp++, &gAllVertex[arg0 * 0x90 + arg1 * 8], 8, 0);

    if (arg3 == 0) {
        gSP2Triangles(glistp++, 4, 5, 6, 0, 4, 7, 5, 0);
    } else {
        gSP1Quadrangle(glistp++, 0, 1, 2, 3, 0);
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DAttack);
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
    s32 temp_t4;
    s32 temp;

#if 0
    // Local variables
    int row; // r1+0x8
    int index; // r5
#endif

    if (gMain >= GMAIN_388) {
        return;
    }

    temp_t4 = gTheGame.cursorBlock[num].target[0];
    if (temp_t4 > 0) {
        return;
    }

    temp_t4 = -temp_t4;

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

    var_v0 = gCounter % 8;
    temp = var_v0 + 1;
    gSPVertex(glistp++, &gAllVertex[temp_t4 * 0x90 + temp * 8], 8, 0);

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
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80063110_usa);
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
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80063F8C_usa);
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
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80064E44_usa);
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
