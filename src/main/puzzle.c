/**
 * Original filename: puzzle.c
 */

#include "puzzle.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "assets_variables.h"

#include "animation.h"
#include "bkground.h"
#include "draw2d.h"
#include "flic.h"
#include "info.h"
#include "init2d.h"
#include "init3d.h"
#include "tetris.h"
#include "the_game.h"
#include "update.h"

/**
 * Original name: Match2DPuzzle
 */
s32 Match2DPuzzle(u8 **ptr, s32 level, s32 arg2) {
#if 0
    // References
    // -> unsigned char puzzle04[1362];
    // -> unsigned char puzzle03[1355];
    // -> unsigned char puzzle02[977];
    // -> unsigned char puzzle01[1118];
    // -> unsigned char puzzle00[711];
#endif

    switch (level) {
        case 0x1:
            *ptr = D_800BB6F0_usa;
            return arg2;

        case 0x2:
            if (arg2 < 0x1F) {
                *ptr = D_800BB88C_usa;
                return arg2;
            }
            *ptr = D_800BC030_usa;
            return arg2 - 0x28;

        case 0x3:
            if (arg2 < 0x1F) {
                *ptr = D_800BC0FC_usa;
                return arg2;
            }
            *ptr = D_800BC91C_usa;
            return arg2 - 0x28;

        case 0x4:
            *ptr = D_800BCA1C_usa;
            return arg2;

        case 0x5:
            if (arg2 < 0x1F) {
                *ptr = D_800BCC78_usa;
                return arg2;
            }
            *ptr = D_800BD644_usa;
            return arg2 - 0x28;

        case 0x6:
            if (arg2 < 0x1F) {
                *ptr = D_800BD7B8_usa;
                return arg2;
            }
            *ptr = D_800BE1E8_usa;
            return arg2 - 0x28;
    }

#if PRESERVE_UB
    return 0;
#endif
}

s32 func_80088A48_usa(u8 **arg0, s32 arg1, s32 arg2) {
    switch (arg1) {
        case 0x1:
        case 0x4:
            break;

        case 0x2:
            *arg0 = D_800BBB14_usa;
            break;

        case 0x3:
            *arg0 = D_800BC404_usa;
            break;

        case 0x5:
            *arg0 = D_800BCF8C_usa;
            break;

        case 0x6:
            *arg0 = D_800BDB68_usa;
            break;
    }

    return arg2 - 0x1E;
}

#if VERSION_USA
#ifdef NON_MATCHING
// regalloc
s32 Init2DPuzzle(tetWell *well, cursor_t *cursor, u8 ptr[], s32 number) {
    s32 var_a3;
    s32 var_s3;
    s32 var_a0;
    s32 var_a1;
    BlockType var_t0;
    s32 temp_a2;
    u32 temp_v0_2;
    u32 temp_v1;

    var_s3 = -1;
    Init2DTetrisBlocks(well, 0);
    number--;

    for (var_a3 = 0; var_a3 < number; var_a3++) {
        temp_a2 = *ptr++;
        ptr += temp_a2 / 2;
        ptr += temp_a2 + 1;
    }

    temp_a2 = *ptr++;
    if (temp_a2 == 0) {
        cursor->target[0] = 0;
        return 0;
    }

    cursor->target[1] = cursor->target[0] = *ptr >> 4;

    for (var_a3 = 0; var_a3 < temp_a2; var_a3++) {
        if (var_s3 != 0) {
            temp_v1 = *ptr++;
            var_t0 = temp_v1 & 0xF;

            var_s3 = 0;
            temp_v0_2 = *ptr++;

            var_a0 = temp_v0_2 >> 4;
            var_a1 = temp_v0_2 & 0xF;
        } else {
            temp_v1 = *ptr++;
            var_t0 = temp_v1 >> 4;
            var_a0 = temp_v1 & 0xF;

            var_s3 = -1;

            temp_v0_2 = *ptr;
            var_a1 = temp_v0_2 >> 4;
        }
        well->block[var_a1][var_a0].type = var_t0;
    }

    Init2DTetrisBlocksTMEM(well, 0);

    return -1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", Init2DPuzzle);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", Init2DPuzzle);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", Init2DPuzzle);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", Init2DPuzzle);
#endif

/**
 * Original name: Save2DPuzzle
 */
s32 Save2DPuzzle(tetWell *well, cursor_t *cursor, u8 *ptr) {
    s32 row;
    s32 col;
    block_t *block;
    u8 value;
    s32 total = 0;
    nbool flag = ntrue;

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        for (col = 0; col < BLOCK_COLS_2D; col++) {
            total += well->block[row][col].type != BLOCKTYPE_0;
        }
    }

    *ptr++ = total;
    value = cursor->target[0] * 0x10;
    if (total == 0) {
        *ptr = value;
        return 0;
    }

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        for (col = 0; col < BLOCK_COLS_2D; col++) {
            if (well->block[row][col].type != BLOCKTYPE_0) {
                block = &well->block[row][col];

                if (flag) {
                    total--;

                    //! @bug: or'ing against old dirty state
                    value |= block->type;
                    *ptr++ = value;

                    value = col << 4;
                    value |= row;
                    *ptr++ = value;

                    flag = nfalse;
                } else {
                    total--;

                    value = block->type << 4;
                    value |= col;
                    *ptr++ = value;

                    value = row << 4;
                    if (total == 0) {
                        *ptr++ = value;
                    }

                    flag = ntrue;
                }
            }

            if (total == 0) {
                return -1;
            }
        }
    }

    return -1;
}

/**
 * Original name: Init3DPuzzle
 */
s32 Init3DPuzzle(tetWell *well, cursor_t *cursor, u8 ptr[], s32 number) {
    s32 var_a2;
    u32 temp_a0;
    s32 temp_a3;
    s32 row;
    s32 col;
    BlockType type;

    Init3DTetrisBlocks(well, 0);
    number--;

    for (var_a2 = 0; var_a2 < number; var_a2++) {
        temp_a3 = *ptr;
        ptr += (temp_a3 * 2) + 2;
    }

    temp_a3 = *ptr++;
    if (temp_a3 == 0) {
        cursor->target[0] = 0;
        return 0;
    }

    cursor->target[1] = cursor->target[0] = *ptr;
    for (var_a2 = 0; var_a2 < temp_a3; var_a2++) {
        temp_a0 = *++ptr;

        type = temp_a0 >> 4;
        row = temp_a0 & 0xF;

        col = *++ptr;
        well->block[row][col].type = type;
    }

    return -1;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088E38_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80088E38_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087908_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80087AC8_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088F94_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80088F94_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80087A64_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80087C24_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80089108_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/puzzle", func_80089108_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/puzzle", func_80089108_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/puzzle", func_80089108_usa);
#endif

/**
 * Original name: LoadPuzzleEditor
 */
s32 LoadPuzzleEditor(s32 number) {
    tetWell *well = &gTheGame.tetrisWell[0];
    s32 temp = number - 1;
    u8 *ptr = gPlayer[0]->unk_121[temp];

    if (gTheGame.menu[0].speed == 0) {
        gTheGame.menu[0].speed = gPlayer[0]->unk_793[number - 1];
        well->menu.speed = gTheGame.menu[0].speed;
    }

    Init2DTetrisBlocks(well, 0);

    if (Init2DPuzzle(well, &gTheGame.cursorBlock[0], ptr, 1) != 0) {
        return -1;
    } else {
        Init2DTetrisBlocks(well, 0);
        return 0;
    }
}

/**
 * Original name: SavePuzzleEditor
 */
s32 SavePuzzleEditor(s32 number) {
    s32 temp = gTheGame.cursorBlock[0].target[0];
    tetWell *well = &gTheGame.tetrisWell[0];
    cursor_t *cursor = &gTheGame.cursorBlock[0];
    s32 temp2 = 1;
    u8 *ptr;

    if ((temp < 1) || (temp > 5)) {
        return 0;
    }

    ptr = gPlayer[0]->unk_121[number - temp2];
    gPlayer[0]->unk_793[number - 1] = gTheGame.menu[0].speed;

    return Save2DPuzzle(well, cursor, ptr);
}

/**
 * Original name: DeletePuzzleEditor
 */
s32 DeletePuzzleEditor(s32 number) {
    tetWell *well = &gTheGame.tetrisWell[0];
    cursor_t *cursor = &gTheGame.cursorBlock[0];
    s32 temp2 = 1;
    u8 *ptr;

    Init2DTetrisBlocks(well, 0);

    ptr = gPlayer[0]->unk_121[number - temp2];
    gPlayer[0]->unk_793[number - 1] = 0;
    Save2DPuzzle(well, cursor, ptr);
    return -1;
}

/**
 * Original name: InitPuzzleEditor
 */
void InitPuzzleEditor(s32 arg0 UNUSED) {
    InitTetrisWell();
}

/**
 * Original name: DoPuzzleEditor
 */
void DoPuzzleEditor(void) {
    Init2DTetrisBlocksTMEM(&gTheGame.tetrisWell[0], -1);
    UpdateAnimation(&gTheGame.tetrisWell[0], 0, 0);
}

/**
 * Original name: DrawPuzzleEditor
 */
void DrawPuzzleEditor(struct_gInfo_unk_00068 *dynamicp) {
    Update2DBuffer(*fb);

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 1);
    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_FILL);
    gDPSetFillColor(glistp++, (GPACK_RGBA5551(0, 0, 0, 1) << 16) | GPACK_RGBA5551(0, 0, 0, 1));
    gDPFillRectangle(glistp++, 0, 0, SCREEN_WIDTH - 1, 6);
    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);

    Draw2DBackground();
    Draw2DAnimation(dynamicp, 1, 3);
    gBox_Level = 0x8C;
    Draw2DShadeBox();

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 31, SCREEN_WIDTH, 223);
    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &colorLUT);
    gDPPipeSync(glistp++);
    gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);

    Draw2DTetrisWell(dynamicp, &gTheGame.tetrisWell[0], 0);

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 7, SCREEN_WIDTH, SCREEN_HEIGHT - 1);

    Draw2DFrame();
    Draw2DAnimation(dynamicp, 4, 4);

    gDPPipeSync(glistp++);

#if VERSION_USA || VERSION_EUR
    gDPSetCycleType(glistp++, G_CYC_FILL);
    gDPSetFillColor(glistp++, (GPACK_RGBA5551(99, 99, 99, 1) << 16) | GPACK_RGBA5551(99, 99, 99, 1));
    gDPFillRectangle(glistp++, 226, 26, SCREEN_WIDTH - 33, 140);
    gDPPipeSync(glistp++);
#endif

    gDPSetCycleType(glistp++, G_CYC_1CYCLE);

    Draw2DAnimation(dynamicp, 5, 6);
}
