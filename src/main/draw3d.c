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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_8005E7A4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_8005EA74_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_8005D1B4_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_8005D364_ger);
#endif

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

    gDPLoadTextureBlock(glistp++, tex, G_IM_FMT_CI, G_IM_SIZ_8b, BLOCK_TEX_WIDTH, BLOCK_TEX_HEIGHT, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    Set3DTile();

    for (col = 1; col < 9; col++) {
        block = &well->new_block[col];

        gSPTexture(glistp++, 0x8000, 0x8000, 0, block->type - 1, G_ON);
        gSPVertex(glistp++, &gAllVertex[0x6C0 + col * 0x8], 8, 0);
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
    gDPLoadTextureBlock(glistp++, tex, G_IM_FMT_RGBA, G_IM_SIZ_16b, CURSOR_TEX_WIDTH, CURSOR_TEX_HEIGHT, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    for (num = 0; num < gTheGame.totalPlayer; num++) {
        cursor = &dynamicp->cursorBlock[num];

        x = cursor->rect.s.objX;
        y = cursor->rect.s.objY;

        gSPTextureRectangle(glistp++, x << 2, y << 2, (x + CURSOR_TEX_REAL_WIDTH) << 2, (y + CURSOR_TEX_HEIGHT) << 2, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
        gDPPipeSync(glistp++);
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DIcon);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DIcon);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DIcon);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DIcon);
#endif

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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DExplosion);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DExplosion);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DExplosion);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DExplosion);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DClearLine);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DClearLine);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DClearLine);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DClearLine);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", Draw3DClearSign);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", Draw3DClearSign);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", Draw3DClearSign);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", Draw3DClearSign);
#endif

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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_800643A4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_800643A4_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_800643A4_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_800643A4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw3d", func_80064728_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw3d", func_80064728_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw3d", func_80064728_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw3d", func_80064728_usa);
#endif

void func_80064AAC_usa(enum_func_800643A4_usa_arg0 arg0, const u16 arg1[], s32 arg2) {
    s32 var_t6;
    s32 var_t7;

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
            var_t7 = 0x8D;
            var_t6 = 0xAA;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_2:
            var_t7 = 0x8D;
            var_t6 = 0xBB;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_3:
            var_t7 = 0x8D;
            var_t6 = 0xCC;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_4:
            var_t7 = 0xA3;
            var_t6 = 0xAA;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_5:
            var_t7 = 0xA3;
            var_t6 = 0xBB;
            break;

        case ENUM_FUNC_800643A4_USA_ARG0_6:
            var_t7 = 0xA3;
            var_t6 = 0xCC;
            break;
    }

    var_t6 += arg2;

    gSPTextureRectangle(glistp++, var_t7 << 2, var_t6 << 2, (var_t7 + 0x10) << 2, (var_t6 + 0x10) << 2, 6, 0, 0, 0x0400,
                        0x0400);
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
