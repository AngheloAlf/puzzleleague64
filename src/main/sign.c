/**
 * Original filename: sign.c
 */

#include "sign.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "001F10.h"
#include "end.h"
#include "info.h"
#include "pause.h"
#include "the_game.h"

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

    if (gTheGame.totalPlayer == 1) {
        gTheGame.unk_9A90[gTheGame.totalPlayer].s.imagePtr = NULL;
    }

    gTheGame.signLUT.tlut.type = G_OBJLT_TLUT;
    gTheGame.signLUT.tlut.image = (u64 *)currSegment->popup_palette;
    gTheGame.signLUT.tlut.phead = GS_PAL_HEAD(0);
    gTheGame.signLUT.tlut.pnum = GS_PAL_NUM(256);
    gTheGame.signLUT.tlut.zero = 0;
    gTheGame.signLUT.tlut.sid = 0;
    gTheGame.signLUT.tlut.flag = (u32)-1;
    gTheGame.signLUT.tlut.mask = 0x0;

    gTheGame.gSPRITE[9].s.scaleW = 1 << 10;
    gTheGame.gSPRITE[9].s.scaleH = 1 << 10;

    gTheGame.gSPRITE[9].s.imageStride = 8;

    gTheGame.gSPRITE[9].s.imageW = 8 << 5;
    gTheGame.gSPRITE[9].s.paddingX = 0;
    gTheGame.gSPRITE[9].s.imageH = 8 << 5;
    gTheGame.gSPRITE[9].s.paddingY = 0;

    gTheGame.gSPRITE[9].s.imageAdrs = 0;

    gTheGame.gSPRITE[9].s.imageFmt = G_IM_FMT_CI;
    gTheGame.gSPRITE[9].s.imageSiz = G_IM_SIZ_8b;
    gTheGame.gSPRITE[9].s.imagePal = 0;
    gTheGame.gSPRITE[9].s.imageFlags = 0;

    if (gTheGame.totalPlayer == 1) {
        gTheGame.unk_9A90[0].s.frameX = 137 << 2;
        gTheGame.unk_9A90[0].s.frameY = 75 << 2;
    } else {
        gTheGame.unk_9A90[0].s.frameX = 46 << 2;
        gTheGame.unk_9A90[0].s.frameY = 75 << 2;
        gTheGame.unk_9A90[1].s.frameX = 210 << 2;
        gTheGame.unk_9A90[1].s.frameY = 75 << 2;
    }

    if (gTheGame.dimension == DIMENSION_3D) {
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
    if (gTheGame.dimension == DIMENSION_2D) {
        if (gTheGame.totalPlayer == 1) {
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
        if (gTheGame.totalPlayer == 1) {
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
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", AnimatePauseKey);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", AnimatePauseKey);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", AnimatePauseKey);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", AnimatePauseKey);
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
