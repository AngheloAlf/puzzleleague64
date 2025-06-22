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

#if VERSION_USA
// InitPause
#if 0
extern UNK_TYPE1 D_10A51D0;
extern UNK_TYPE1 D_10AA150;
extern UNK_TYPE1 D_9393C0;
extern UNK_TYPE1 D_93E340;

void func_800343A0_usa(void) {
    s32 temp_a0;
    s32 var_s1;
    s32 var_v0;
    uObjBg *var_s0;
    void *temp_s2;

    temp_s2 = Pon_Image_Heap;
    osInvalDCache(&D_10A51D0, &D_10AA150 - &D_10A51D0);
    func_80001310_usa((u32)&D_9393C0, temp_s2, (u32)(&D_93E340 - &D_9393C0));
    Pon_Image_Heap += (u32)(&D_93E340 - &D_9393C0);

    for (var_v0 = 0; var_v0 < 4; var_v0++) {
        gTheGame.unk_9A90[var_v0].s.imagePtr = 0;
    }

    for (var_s1 = 0; var_s1 < 3; var_s1++) {
        var_s0 = &gTheGame.unk_9A90[var_s1];
        var_s0->s.imageLoad = 0xFFF4;
        var_s0->s.imageFmt = 2;
        var_s0->s.imageSiz = 1;
        var_s0->s.imageX = 0;
        var_s0->s.frameX = -0x280;
        var_s0->s.imageW = 0x200;
        var_s0->s.frameW = 0x200;
        var_s0->s.imageY = 0;
        var_s0->s.frameY = -0x280;
        var_s0->s.imagePal = 0;
        var_s0->s.imageFlip = 0;
        if (var_s1 < 2) {
            var_s0->s.imageW = 0x100;
            var_s0->s.frameW = 0x100;
            var_s0->s.imageH = 0x60;
            var_s0->s.frameH = 0x60;
            var_s0->s.imagePtr = (u64 *)temp_s2;
        } else if (((gSelection == 0xBE) || (gSelection < 0x83))) {
            var_s0->s.imageH = 0xF4;
            var_s0->s.frameH = 0xF4;
            var_s0->s.imagePtr = temp_s2 + 0x2F00;
        } else {
            var_s0->s.imageH = 0xB8;
            var_s0->s.frameH = 0xB8;
            var_s0->s.imagePtr = temp_s2 + 0x1800;
        }
        guS2DInitBg(var_s0);
    }

    temp_a0 = gTheGame.unk_9C08;
    if (temp_a0 == 1) {
        gTheGame.unk_9A90[temp_a0].s.imagePtr = NULL;
    }

    gTheGame.unk_9B30 = 0x30;
    gTheGame.unk_9B34 = temp_s2 + 0x4D80;
    gTheGame.unk_9B3A = 0xFF;
    gTheGame.unk_9B40 = -1;
    gTheGame.unk_90AA = 0x400;
    gTheGame.unk_90B2 = 0x400;
    gTheGame.unk_90B8 = 8;
    gTheGame.unk_90BC = 2;
    gTheGame.unk_9B3C = 0;
    gTheGame.unk_9B3E = 0;
    gTheGame.unk_9B44 = 0;
    gTheGame.unk_9B38 = 0x100;
    gTheGame.unk_90AC = 0x100;
    gTheGame.unk_90AE = 0;
    gTheGame.unk_90B4 = 0x100;
    gTheGame.unk_90B6 = 0;
    gTheGame.unk_90BA = 0;
    gTheGame.unk_90BD = 1;
    gTheGame.unk_90BE = 0;
    gTheGame.unk_90BF = 0;
    if (temp_a0 == 1) {
        gTheGame.unk_9A90[0].s.frameX = 0x224;
        gTheGame.unk_9A90[0].s.frameY = 0x12C;
    } else {
        gTheGame.unk_9A90[0].s.frameX = 0xB8;
        gTheGame.unk_9A90[0].s.frameY = 0x12C;
        gTheGame.unk_9A90[1].s.frameX = 0x348;
        gTheGame.unk_9A90[1].s.frameY = 0x12C;
    }

    if (gTheGame.unk_9C0C == 2) {
        for (var_s1 = 0; var_s1 < 4; var_s1++) {
            gTheGame.unk_9A90[var_s1].s.imageYorig = 0;
            gTheGame.unk_9A90[var_s1].s.scaleW = 0x400;
            gTheGame.unk_9A90[var_s1].s.scaleH = 0x400;
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/sign", func_800343A0_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sign", func_800343D0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sign", func_80034330_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sign", func_800344A0_ger);
#endif

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
