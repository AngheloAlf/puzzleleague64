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
void func_80033004_usa(void);
// ? func_8003520C_usa(struct_gInfo_unk_00068 *);      /* extern */
// ? func_8004DCC0_usa(struct_gInfo_unk_00068 *);      /* extern */
// ? func_80052E04_usa(struct_gInfo_unk_00068 *);      /* extern */
void func_80054204_usa(void);
// ? func_8006D87C_usa(struct_gInfo_unk_00068 *, s32); /* extern */
// ? func_8006DED8_usa(struct_gInfo_unk_00068 *, s32, s32); /* extern */
// s32 func_8006E254_usa(struct_gInfo_unk_00068 *, s32); /* extern */
// ? func_8006EB24_usa(struct_gInfo_unk_00068 *, s32); /* extern */
// ? func_8006EE48_usa(struct_gInfo_unk_00068 *, s32); /* extern */
extern s32 B_80192FE0_usa;
extern uObjTxtrBlock_t D_01001438_usa;
extern uObjTxtrBlock_t D_01001450_usa;
extern s32 D_800BE34C_usa;

void Draw2DTetris(struct_gInfo_unk_00068 *arg0) {
    s32 sp10[UNK_SIZE];
    UNK_TYPE *var_v0_2;
    Gfx *temp_a0;
    Gfx *temp_v0;
    Gfx *temp_v0_2;
    Gfx *temp_v1_3;
    Gfx *temp_v1_4;
    TheGame *var_s1;
    s32 *var_s1_2;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_s0;
    s32 var_v0;
    s32 var_v1;
    TheGame_unk_8860 *temp_a0_2;

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 7, 320, 239);

    Draw2DBackground();
    if (D_800BE34C_usa != 0) {
        if ((gTheGame.unk_9C08 == 1) || (arg0->unk_10240 < 0x321)) {
            B_80192FE0_usa = 0x320;
        } else {
            if (arg0->unk_10240 >= B_80192FE0_usa + 0x6E) {
                B_80192FE0_usa = B_80192FE0_usa + 0x6E;
            } else if (B_80192FE0_usa - 0x50 >= arg0->unk_10240) {
                B_80192FE0_usa = B_80192FE0_usa - 0x50;
            } else {
                B_80192FE0_usa = arg0->unk_10240;
            }

            var_s0 = B_80192FE0_usa - 0x320;
            //if (var_s0 > 0x1194) {
            //    var_s0 = 0x1194;
            //}
            var_s0 = MIN(var_s0, 0x1194);
            var_s0 = var_s0 / 10;
            while (var_s0 > 0) {
                //var_v1 = var_s0;
                //if (var_s0 > 0xE8) {
                //    var_v1 = 0xE8;
                //}
                var_v1 = MIN(var_s0, 0xE8);
                gTheGame.unk_9A5E = (s16) (var_v1 * 4);
                var_s0 -= 0xE8;
                Draw2DBackground();
            }
            gTheGame.unk_9A5E = 0x3A0;
        }
    }
    Draw2DAnimation(arg0, 1, 3);
    if ((gMain != GMAIN_384) || (gCounter >= 0x64)) {
        Draw2DShadeBox();

#if 0
        temp_v1_3 = glistp;
        glistp = temp_v1_3 + 8;
        glistp = temp_v1_3 + 0x10;
        glistp = temp_v1_3 + 0x18;
        glistp = temp_v1_3 + 0x20;
        temp_v1_3->words.w0 = 0xED00007C;
        temp_v1_3->words.w1 = 0x0050037C;
        temp_v1_3->unk_8 = 0xE7000000;
        temp_v1_3->unk_C = 0x00000000;
        temp_v1_3->unk_10 = 0xBA000E02;
        temp_v1_3->unk_14 = 0x00008000;
        temp_v1_3->unk_18 = 0xC1000017;
        temp_v1_3->unk_1C = &colorLUT;
#endif
        gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 31, 320, 223);
        gDPPipeSync(glistp++);
        gDPSetTextureLUT(glistp++, G_TT_RGBA16);
        //glistp++ = (Gfx){0xC1000017, 0xFFFFFFFF};
        gSPObjLoadTxtr(glistp++, &colorLUT);

        func_80054204_usa();

        for (var_s0 = 0; var_s0 < gTheGame.unk_9C08; var_s0++) {
            Draw2DTetrisWell(arg0, &gTheGame.unk_0000[var_s0], var_s0);
            sp10[var_s0] = func_8006E254_usa(arg0, var_s0);
        }

        gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 7, 320, 239);

        Draw2DFrame();
        Draw2DAnimation(arg0, 4, 4);
        func_8004DCC0_usa(arg0);
        func_80052E04_usa(arg0);
        Draw2DAnimation(arg0, 5, 6);
        if ((gSelection == 0xAA) || (gSelection == 0xB4)) {
            var_s0 = 0;
            while (var_s0 < gTheGame.unk_9C08) {
                func_8006EE48_usa(arg0, var_s0);
                var_s0 += 1;
            }
        }

        if (gMain != GMAIN_388) {
            var_s0 = 0;
            while (var_s0 < gTheGame.unk_9C08) {
                func_8006DED8_usa(arg0, var_s0, sp10[var_s0]);
                func_8006EB24_usa(arg0, var_s0);
                func_8006D87C_usa(arg0, var_s0);
                var_s0 += 1;
            }
        }

        if ((gMain == GMAIN_387) || (gMain == GMAIN_384)) {
#if 0
            temp_a0 = glistp;
            temp_a0->words.w0 = 0xE7000000;
            temp_a0->words.w1 = 0;
            temp_a0->unk_8 = 0xBA000E02;
            temp_a0->unk_C = 0x8000;
            temp_a0->unk_10 = 0xC1000017;
            temp_a0->unk_14 = &colorLUT;
            glistp = temp_a0 + 8;
            glistp = temp_a0 + 0x10;
            glistp = temp_a0 + 0x18;
            temp_v0 = temp_a0 + 0x20;
            if (arg0->unk_172C8 == 0) {
                glistp = temp_v0;
                var_v0_2 = &D_01001438_usa;
                temp_a0->unk_18 = 0xC1000017;
            } else {
                glistp = temp_v0;
                var_v0_2 = &D_01001450_usa;
                temp_a0->unk_18 = 0xC1000017;
            }
            temp_a0->unk_1C = var_v0_2;
#endif

            gDPPipeSync(glistp++);
            gDPSetTextureLUT(glistp++, G_TT_RGBA16);

            gSPObjLoadTxtr(glistp++, &colorLUT);
            //if (arg0->unk_172C8 == 0)
            if (arg0->unk_172A8[0].unk_20 == 0)
            {
            gSPObjLoadTxtr(glistp++, &D_01001438_usa);
            } else {
            gSPObjLoadTxtr(glistp++, &D_01001450_usa);
            }
            //glistp++ = (Gfx){0xC1000017, 0xFFFFFFFF};
            //glistp++ = (Gfx){0xC1000017, 0xFFFFFFFF};

            for (var_a1 = 0; var_a1 < gTheGame.unk_9C08; var_a1++) {
                temp_a0_2 = &arg0->unk_172A8[var_a1];
                if (temp_a0_2->unk_14 < 0xC) {
                    //gMoveMem(glistp++, 0x00, 0, &temp_a0_2->unk_98);
                    //Gfx *temp = glistp++;
                    //temp->words.w0 = 0x03000000;
                    //temp->words.w1 = &temp_a0_2->unk_98;
                    gSPObjRectangle(glistp++, &temp_a0_2->unk_98);
                }
            }
        }

        if (gMain >= 0x388) {
            func_8003520C_usa(arg0);
        } else if (gMain == GMAIN_384) {
            func_80033004_usa();
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DTetris);
#endif
#endif
