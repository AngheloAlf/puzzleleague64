/**
 * Original filename: dlist.c
 */

#include "dlist.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "info.h"
#include "the_game.h"
#include "update.h"

#include "assets_variables.h"

#if VERSION_USA
void InitCursor(cursor_t *cursor) {
    s32 var_v0;

    cursor->unk_00 = 0;
    cursor->unk_04 = 0;
    cursor->unk_08 = 0;
    cursor->unk_0C = 0;
    cursor->unk_20 = 0;
    cursor->unk_24 = 0xF;

    if ((gTheGame.unk_9C0C == 2) || (gSelection < 0x8C)) {
        cursor->x = 2;
        cursor->y = 3;
    } else {
        cursor->y = 0xC;
        cursor->x = 4;
    }

    cursor->unk_18 = -1;
    cursor->unk_1C = -1;

    if ((gSelection == 0x78) || (gSelection == 0x82)) {
        return;
    }
    if ((gSelection == 0xAA) || (gSelection == 0xB4)) {
        return;
    }

    for (var_v0 = 0; var_v0 < CURSOR_UNK_28_COUNT; var_v0++) {
        cursor->unk_28[var_v0] = 0;
    }

    for (var_v0 = 0; var_v0 < CURSOR_UNK_84_COUNT; var_v0++) {
        cursor->unk_84[var_v0] = 0;
    }
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/dlist", InitCursor);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/dlist", InitCursor);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/dlist", InitCursor);
#endif

// TODO: maybe void InitGamePad(int num /* r1+0x0 */)?
void InitGamePad(s32 arg0) {
    // TODO: REGION_NTSC?
#if VERSION_USA
    gTheGame.controller[arg0].unk_08 = 0xA;
#else
    gTheGame.controller[arg0].unk_08 = 0x8;
#endif
    gTheGame.controller[arg0].touch_button = 0;
    gTheGame.controller[arg0].hold_button = 0;
    gTheGame.controller[arg0].unk_0E = 0;
}

void func_80054624_usa(void) {
    if (gGameStatus & 0x40) {
        tetrisBlock1.block.image = (u64 *)D_01008468_usa;
        tetrisBlock2.block.image = (u64 *)D_01008C68_usa;
        tetrisBlock3.block.image = (u64 *)D_01009468_usa;
        tetrisBlock4.block.image = (u64 *)D_01009C68_usa;
        tetrisBlock5.block.image = (u64 *)D_0100A468_usa;
        tetrisBlock6.block.image = (u64 *)D_0100AC68_usa;
        tetrisBlock7.block.image = (u64 *)D_0100B468_usa;
        tetrisBlock8.block.image = (u64 *)D_0100BC68_usa;
        tetrisBlock9.block.image = (u64 *)D_0100C468_usa;
        D_800B7458_usa.block.image = NULL;
        D_800B7470_usa.block.image = NULL;
        D_800B7488_usa.block.image = NULL;
        D_800B74A0_usa.block.image = NULL;
        tetrisBlockNew.block.image = (u64 *)D_0100CC68_usa;
    } else {
        tetrisBlock1.block.image = (u64 *)D_01001468_usa;
        tetrisBlock2.block.image = (u64 *)D_01001C68_usa;
        tetrisBlock3.block.image = (u64 *)D_01002468_usa;
        tetrisBlock4.block.image = (u64 *)D_01002C68_usa;
        tetrisBlock5.block.image = (u64 *)D_01003468_usa;
        tetrisBlock6.block.image = (u64 *)D_01003C68_usa;
        tetrisBlock7.block.image = (u64 *)D_01004468_usa;
        tetrisBlock8.block.image = (u64 *)D_01004C68_usa;
        tetrisBlock9.block.image = (u64 *)D_01005468_usa;
        D_800B7458_usa.block.image = (u64 *)D_01005C68_usa;
        D_800B7470_usa.block.image = (u64 *)D_01006468_usa;
        D_800B7488_usa.block.image = (u64 *)D_01006C68_usa;
        D_800B74A0_usa.block.image = (u64 *)D_01007468_usa;
        tetrisBlockNew.block.image = (u64 *)D_01007C68_usa;
    }
}

void InitTetrisState(block_t *block) {
    block->state = BLOCKSTATE_0;
    block->delay = 0;
    block->disappear = 0;
    block->drop = 0;
    block->type = BLOCKTYPE_0;
    block->frame_n = 0;
    block->bomb = 0;
    block->chain_flag = 0;
}

void InitDisplayList(struct_gInfo *info) {
    gSPDisplayList(glistp++, initRDP_dl);
    gDPPipeSync(glistp++);
    gDPSetColorImage(glistp++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, info->unk_19040);

    if ((gMain == GMAIN_384) || ((gMain > GMAIN_388))) {
        gFrameColor = (GPACK_RGBA5551(0, 0, 0, 1) << 16) | (GPACK_RGBA5551(0, 0, 0, 1) << 0);

        gDPSetCycleType(glistp++, G_CYC_FILL);
        gDPSetFillColor(glistp++, gFrameColor);
        gDPFillRectangle(glistp++, 0, 0, SCREEN_WIDTH - 1, 6);
        gDPPipeSync(glistp++);
    }

    gDPSetCycleType(glistp++, G_CYC_1CYCLE);

    if (gTheGame.unk_9C0C == 2) {
        gSPDisplayList(glistp++, init3D_dl);
        guS2DEmuSetScissor(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    } else {
        gSPDisplayList(glistp++, init2D_dl);
    }
}

#if VERSION_USA
// SetMenuVar?
void func_800549A4_usa(void) {
    s32 num;

    for (num = 0; num < gTheGame.unk_9C08; num++) {
        tetWell *well = &gTheGame.tetrisWell[num];

        well->menu.unk_0 = gTheGame.menu[num].unk_0;
        well->menu.unk_8 = gTheGame.menu[num].unk_8;
        well->menu.unk_4 = gTheGame.menu[num].unk_4;
        well->menu.unk_C = gTheGame.menu[num].unk_C;
    }
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", InitGameStateVar);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_800552F4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/dlist", func_80054C44_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/dlist", InitGameStateVar);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/dlist", func_80055594_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/dlist", func_800533B4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/dlist", InitGameStateVar);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/dlist", func_80053D04_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/dlist", func_80053534_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/dlist", InitGameStateVar);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/dlist", func_80053E84_ger);
#endif
