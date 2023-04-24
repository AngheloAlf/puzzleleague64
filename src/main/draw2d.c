/**
 * Original filename: draw2d.c
 */

#include "draw2d.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "assets_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DTetrisWell);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006D798_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006D87C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006DED8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006E254_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006EB24_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006EE48_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006F09C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006F2FC_usa);
#endif

#if VERSION_USA
void DrawTetris(struct_gInfo_unk_00068 *arg0) {
    if (gCounter < 2) {
        return;
    }

    if (gTheGame.unk_9C0C == 2) {
        Draw3DTetris(arg0);
    } else {
        Draw2DTetris(arg0);
    }

    if (gMain == GMAIN_384) {
        if (gCounter == 2) {
            func_8004FABC_usa();
        } else if (gCounter == 4) {
            func_80050420_usa();
        } else {
            if (gCounter < 0x64) {
                func_8005076C_usa();
            }
            if (gCounter > 0x62) {
                func_80050C2C_usa();
            }
        }
    }
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006F598_usa);
#endif

#if VERSION_USA
#if 0
// ? func_80033004_usa();                              /* extern */
// ? func_8003520C_usa(Gfx *);                         /* extern */
// ? func_8004DCC0_usa(Gfx *);                         /* extern */
// ? func_80052E04_usa(Gfx *);                         /* extern */
// ? func_80054204_usa(u32, u32, s32, s32);            /* extern */
// ? func_8006D87C_usa(Gfx *, s32);                    /* extern */
// ? func_8006DED8_usa(Gfx *, s32, s32);               /* extern */
// s32 func_8006E254_usa(Gfx *, s32);                  /* extern */
// ? func_8006EB24_usa(Gfx *, s32);                    /* extern */
// ? func_8006EE48_usa(Gfx *, s32);                    /* extern */
extern s32 B_80192FE0_usa;
extern UNK_TYPE D_01001438_usa;
extern UNK_TYPE D_01001450_usa;
extern s32 D_800BE34C_usa;

void Draw2DTetris(Gfx *gfx) {
    s32 sp10;
    UNK_TYPE *var_v0_2;
    Gfx *temp_a0;
    Gfx *temp_v0;
    Gfx *temp_v0_2;
    Gfx *temp_v1;
    Gfx *temp_v1_3;
    Gfx *temp_v1_4;
    TheGame *var_s1;
    s32 *var_s1_2;
    s32 *var_s2;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s0_5;
    s32 var_v0;
    s32 var_v1;
    void *temp_a0_2;

    temp_v1 = glistp;
    glistp = temp_v1 + 8;
    temp_v1->words.w0 = 0xED00001C;
    temp_v1->words.w1 = 0x5003BC;
    Draw2DBackground();
    if (D_800BE34C_usa != 0) {
        if ((gTheGame.unk_9C08 == 1) || (temp_v1_2 = gfx->unk_10240, ((temp_v1_2 < 0x321) != 0))) {
            B_80192FE0_usa = 0x320;
        } else {
            var_a0 = B_80192FE0_usa + 0x6E;
            if ((temp_v1_2 >= var_a0) || (var_a0 = B_80192FE0_usa - 0x50, ((var_a0 < temp_v1_2) == 0))) {
                B_80192FE0_usa = var_a0;
            } else {
                B_80192FE0_usa = temp_v1_2;
            }
            var_s0 = B_80192FE0_usa - 0x320;
            if (var_s0 >= 0x1195) {
                var_s0 = 0x1194;
            }
            var_s0_2 = var_s0 / 10;
            if (var_s0_2 > 0) {
                var_v0 = var_s0_2 < 0xE9;
                do {
                    var_v1 = var_s0_2;
                    if (var_v0 == 0) {
                        var_v1 = 0xE8;
                    }
                    gTheGame.unk_9988[0xD6] = (s16) (var_v1 * 4);
                    var_s0_2 -= 0xE8;
                    Draw2DBackground();
                    var_v0 = var_s0_2 < 0xE9;
                } while (var_s0_2 > 0);
            }
            gTheGame.unk_9988[0xD6] = 0x3A0;
        }
    }
    Draw2DAnimation(gfx, 1, 3);
    if ((gMain != GMAIN_384) || (gCounter >= 0x64)) {
        var_s0_3 = 0;
        Draw2DShadeBox();
        temp_v1_3 = glistp;
        glistp = temp_v1_3 + 8;
        glistp = temp_v1_3 + 0x10;
        temp_v1_3->unk_8 = 0xE7000000;
        glistp = temp_v1_3 + 0x18;
        temp_v1_3->unk_14 = 0x8000;
        glistp = temp_v1_3 + 0x20;
        temp_v1_3->words.w0 = 0xED00007C;
        temp_v1_3->words.w1 = 0x50037C;
        temp_v1_3->unk_C = 0;
        temp_v1_3->unk_10 = 0xBA000E02;
        temp_v1_3->unk_18 = 0xC1000017;
        temp_v1_3->unk_1C = &colorLUT;
        func_80054204_usa(0x50037CU, 0xED00007CU, 0xBA000E02, 0xC1000017);
        if (gTheGame.unk_9C08 > 0) {
            var_s2 = &sp10;
            var_s1 = &gTheGame;
            do {
                Draw2DTetrisWell(gfx, var_s1, var_s0_3);
                *var_s2 = func_8006E254_usa(gfx, var_s0_3);
                var_s2 += 4;
                var_s0_3 += 1;
                var_s1 += 0x4430;
            } while (var_s0_3 < gTheGame.unk_9C08);
        }
        temp_v1_4 = glistp;
        glistp = temp_v1_4 + 8;
        temp_v1_4->words.w0 = 0xED00001C;
        temp_v1_4->words.w1 = 0x5003BC;
        Draw2DFrame();
        Draw2DAnimation(gfx, 4, 4);
        func_8004DCC0_usa(gfx);
        func_80052E04_usa(gfx);
        Draw2DAnimation(gfx, 5, 6);
        if (((gSelection == 0xAA) | (gSelection == 0xB4)) != 0) {
            var_s0_4 = 0;
            if (gTheGame.unk_9C08 > 0) {
                do {
                    func_8006EE48_usa(gfx, var_s0_4);
                    var_s0_4 += 1;
                } while (var_s0_4 < gTheGame.unk_9C08);
            }
        }
        if (gMain != GMAIN_388) {
            var_s0_5 = 0;
            if (gTheGame.unk_9C08 > 0) {
                var_s1_2 = &sp10;
                do {
                    func_8006DED8_usa(gfx, var_s0_5, *var_s1_2);
                    func_8006EB24_usa(gfx, var_s0_5);
                    func_8006D87C_usa(gfx, var_s0_5);
                    var_s0_5 += 1;
                    var_s1_2 += 4;
                } while (var_s0_5 < gTheGame.unk_9C08);
            }
        }
        if (((gMain == GMAIN_387) | (gMain == GMAIN_384)) != 0) {
            temp_a0 = glistp;
            temp_a0->words.w0 = 0xE7000000;
            temp_a0->unk_C = 0x8000;
            temp_a0->words.w1 = 0;
            temp_a0->unk_8 = 0xBA000E02;
            temp_a0->unk_10 = 0xC1000017;
            temp_a0->unk_14 = &colorLUT;
            glistp = temp_a0 + 8;
            glistp = temp_a0 + 0x10;
            glistp = temp_a0 + 0x18;
            temp_v0 = temp_a0 + 0x20;
            if (gfx->unk_172C8 == 0) {
                glistp = temp_v0;
                var_v0_2 = &D_01001438_usa;
                temp_a0->unk_18 = 0xC1000017;
            } else {
                glistp = temp_v0;
                var_v0_2 = &D_01001450_usa;
                temp_a0->unk_18 = 0xC1000017;
            }
            temp_a0->unk_1C = var_v0_2;
            var_a1 = 0;
            if (gTheGame.unk_9C08 > 0) {
                var_a2 = 0x172A8;
                do {
                    temp_a0_2 = gfx + var_a2;
                    if (temp_a0_2->unk_14 < 0xC) {
                        temp_v0_2 = glistp;
                        glistp = temp_v0_2 + 8;
                        temp_v0_2->words.w0 = 0x03000000;
                        temp_v0_2->words.w1 = (u32) (temp_a0_2 + 0x98);
                    }
                    var_a1 += 1;
                    var_a2 += 0xB0;
                } while (var_a1 < gTheGame.unk_9C08);
            }
        }
        if (gMain >= 0x388) {
            func_8003520C_usa(gfx);
            return;
        }
        if (gMain == GMAIN_384) {
            func_80033004_usa();
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DTetris);
#endif
#endif
