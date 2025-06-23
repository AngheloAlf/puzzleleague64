/**
 * Original filename: sign.c
 */

#include "sign.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "001F10.h"
#include "end.h"
#include "pause.h"

#include "assets/sign_gameover.h"
#include "assets/sign_pause.h"

void InitPause(void) {
    SignPauseTextures *currSegment;
    uObjBg *bg;
    s32 count;

    currSegment = Pon_Image_Heap;
    LOAD_DATA_SEGMENT_DW(currSegment, sign_pause, Pon_Image_Heap);

    for (count = 0; count < GAME_UNK_9A90_COUNT; count++) {
        gTheGame.unk_9A90[count].s.imagePtr = NULL;
    }

    for (count = 0; count < GAME_UNK_9A90_COUNT - 1; count++) {
        bg = &gTheGame.unk_9A90[count];

        bg->s.imageX = 0;
        bg->s.frameX = -(160 << 2);
        bg->s.imageW = SIGNPAUSE_POPUP_WIDTH << 2;
        bg->s.frameW = SIGNPAUSE_POPUP_WIDTH << 2;
        bg->s.imageY = 0;
        bg->s.frameY = -(160 << 2);

        bg->s.imageLoad = G_BGLT_LOADTILE;
        bg->s.imageFmt = G_IM_FMT_CI;
        bg->s.imagePal = 0;
        bg->s.imageSiz = G_IM_SIZ_8b;
        bg->s.imageFlip = 0;

        if (count < 2) {
            bg->s.imageW = SIGNPAUSE_PAUSE_WIDTH << 2;
            bg->s.frameW = SIGNPAUSE_PAUSE_WIDTH << 2;
            bg->s.imageH = SIGNPAUSE_PAUSE_HEIGHT << 2;
            bg->s.frameH = SIGNPAUSE_PAUSE_HEIGHT << 2;
            bg->s.imagePtr = (void *)currSegment->pause;
        } else if ((gSelection == 0xBE) || (gSelection < 0x83)) {
            bg->s.imageH = SIGNPAUSE_POPUP_CONTINUE_RESTART_HEIGHT << 2;
            bg->s.frameH = SIGNPAUSE_POPUP_CONTINUE_RESTART_HEIGHT << 2;
            bg->s.imagePtr = (void *)currSegment->popup_continue_restart;
        } else {
            bg->s.imageH = SIGNPAUSE_POPUP_CONTINUE_HEIGHT << 2;
            bg->s.frameH = SIGNPAUSE_POPUP_CONTINUE_HEIGHT << 2;
            bg->s.imagePtr = (void *)currSegment->popup_continue;
        }

        guS2DInitBg(bg);
    }

    if (gTheGame.unk_9C08 == 1) {
        gTheGame.unk_9A90[gTheGame.unk_9C08].s.imagePtr = NULL;
    }

    // uObjBg? uObjTxtr? uObjSprite?
    gTheGame.unk_9B30 = 0x30;
    gTheGame.unk_9B34 = currSegment->popup_palette;
    gTheGame.unk_9B38 = 0x100;
    gTheGame.unk_9B3A = 0xFF;
    gTheGame.unk_9B40 = -1;
    gTheGame.unk_90AA = 0x400;
    gTheGame.unk_90B2 = 0x400;
    gTheGame.unk_90B8 = 8;
    gTheGame.unk_90BC = 2;
    gTheGame.unk_9B3C = 0;
    gTheGame.unk_9B3E = 0;
    gTheGame.unk_9B44 = 0;
    gTheGame.unk_90AC = 0x100;
    gTheGame.unk_90AE = 0;
    gTheGame.unk_90B4 = 0x100;
    gTheGame.unk_90B6 = 0;
    gTheGame.unk_90BA = 0;
    gTheGame.unk_90BD = 1;
    gTheGame.unk_90BE = 0;
    gTheGame.unk_90BF = 0;

    if (gTheGame.unk_9C08 == 1) {
        gTheGame.unk_9A90[0].s.frameX = 137 << 2;
        gTheGame.unk_9A90[0].s.frameY = 75 << 2;
    } else {
        gTheGame.unk_9A90[0].s.frameX = 46 << 2;
        gTheGame.unk_9A90[0].s.frameY = 75 << 2;
        gTheGame.unk_9A90[1].s.frameX = 210 << 2;
        gTheGame.unk_9A90[1].s.frameY = 75 << 2;
    }

    if (gTheGame.unk_9C0C == 2) {
        for (count = 0; count < GAME_UNK_9A90_COUNT; count++) {
            gTheGame.unk_9A90[count].s.imageYorig = 0;
            gTheGame.unk_9A90[count].s.scaleW = 1 << 10;
            gTheGame.unk_9A90[count].s.scaleH = 1 << 10;
        }
    }
}

void InitGameOver(void) {
    void *var_s1;

    endSegment = Pon_Image_Heap;
    if (gTheGame.unk_9C0C == 1) {
        if (gTheGame.unk_9C08 == 1) {
            LOAD_DATA_SEGMENT(endSegment, sign_gameover_2d_1p, Pon_Image_Heap);
        } else {
            LOAD_DATA_SEGMENT(endSegment, sign_gameover_2d_2p, Pon_Image_Heap);

            var_s1 = Pon_Image_Heap;

            LOAD_DATA_SEGMENT(var_s1, sign_gameover_2d_1p, Pon_Image_Heap);

            // TODO: wtf is this doing? Maybe it is trying to load the push_any_button texture from the 1p segment?
            bcopy((char *)endSegment + 0x3E200, var_s1, 0x1A00);
            Pon_Image_Heap = var_s1 + 0x1A00;
        }
    } else {
        if (gTheGame.unk_9C08 == 1) {
            LOAD_DATA_SEGMENT(endSegment, sign_gameover_3d_1p, Pon_Image_Heap);
        } else {
            LOAD_DATA_SEGMENT(endSegment, sign_gameover_3d_2p, Pon_Image_Heap);

            var_s1 = Pon_Image_Heap;

            LOAD_DATA_SEGMENT(var_s1, sign_gameover_3d_1p, Pon_Image_Heap);

            bcopy((char *)endSegment + 0x3E200, var_s1, 0x1A00);
            Pon_Image_Heap = var_s1 + 0x1A00;
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_8003490C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_8003490C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_8003490C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_8003490C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", LoadGameOver3D);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", LoadGameOver3D);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", LoadGameOver3D);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", LoadGameOver3D);
#endif

void DrawPauseOver(struct_gInfo_unk_00068 *arg0) {
    if (gMain == GMAIN_388) {
        DrawPause(arg0);
    } else {
        DrawGameOver(arg0);
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_8003524C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_8003524C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_8003524C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_8003524C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_800352DC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_800352DC_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_800352DC_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_800352DC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_8003536C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_8003536C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_8003536C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_8003536C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_800353B0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_800353B0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_800353B0_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_800353B0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_800353F4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_800353F4_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_800353F4_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_800353F4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_80035438_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_80035438_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_80035438_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_80035438_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_8003547C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_8003547C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_8003547C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_8003547C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_800354C0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_800354C0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_800354C0_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_800354C0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_80035504_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_80035534_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_800354A4_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_80035614_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_80035584_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_80035584_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_80035584_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_80035584_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_800355EC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_8003561C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_8003558C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_800356FC_ger);
#endif
