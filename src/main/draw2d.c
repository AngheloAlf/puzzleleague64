/**
 * Original filename: draw2d.c
 */

#include "draw2d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "bonus.h"
#include "fade.h"
#include "flic.h"
#include "sign.h"
#include "text.h"

#include "assets_variables.h"

#if REGION_NTSC
#define COUNTER_VALUE (100)
#else
#define COUNTER_VALUE (80)
#endif

#if REGION_NTSC
#define ADJUST_FRAMERATE(x) (x)
#else
#define ADJUST_FRAMERATE(x) (x * 5 / 6)
#endif

extern uObjTxtr D_010003F0_usa;
extern uObjTxtr D_800B7380_usa;
extern uObjTxtr D_800B7398_usa;
extern uObjTxtr D_800B73B0_usa;
extern uObjTxtr D_800B73C8_usa;
extern uObjTxtr D_800B73E0_usa;
extern uObjTxtr D_800B73F8_usa;
extern uObjTxtr D_800B7410_usa;
extern uObjTxtr D_800B7428_usa;
extern uObjTxtr D_800B7440_usa;
extern uObjTxtr D_800B7458_usa;
extern uObjTxtr D_800B7470_usa;
extern uObjTxtr D_800B7488_usa;
extern uObjTxtr D_800B74A0_usa;
extern uObjTxtr D_800B74B8_usa;

#if VERSION_USA
#ifdef NON_EQUIVALENT
//#if 1
void Draw2DTetrisWell(struct_gInfo_unk_00068 *dynamicp, tetWell *well, s32 num) {
    block_t(*temp_t9)[BLOCK_LEN_B];
    uObjSprite(*var_t0)[6];
    cursor_t *temp_t7;
    s32 var_a1;
    s32 var_t1;
    s32 var_t3;
    s32 var_t8;
    uObjSprite *var_a0_2;
    uObjTxtr *var_v0;
    block_t *temp_v1_5;
    block_t *var_a0;

    var_t8 = 9;
    if (gMain >= 0x38E) {
        var_t8 = 13;
        gLastOverflow = 0x320;
    }

    temp_t9 = dynamicp->unk_10244[num];
    var_t0 = dynamicp->unk_17408[num];
    temp_t7 = &dynamicp->cursorBlock[num];

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);

    if (gGameStatus & 0x40) {
        gSPObjLoadTxtr(glistp++, &colorLUT);
    } else {
        gSPObjLoadTxtr(glistp++, &D_010003F0_usa);
    }

    for (var_t3 = 1; var_t3 <= var_t8; var_t3++) {
        struct_gInfo_unk_10208 *temp = &dynamicp->unk_10208[num];
        if (temp->unk_0.unk_0[var_t3] == 0) {
            continue;
        }

        switch (var_t3) {
            case 0x1:
                gSPObjLoadTxtr(glistp++, &D_800B7380_usa);
                break;
            case 0x2:
                gSPObjLoadTxtr(glistp++, &D_800B7398_usa);
                break;
            case 0x3:
                gSPObjLoadTxtr(glistp++, &D_800B73B0_usa);
                break;
            case 0x4:
                gSPObjLoadTxtr(glistp++, &D_800B73C8_usa);
                break;
            case 0x5:
                gSPObjLoadTxtr(glistp++, &D_800B73E0_usa);
                break;
            case 0x6:
                gSPObjLoadTxtr(glistp++, &D_800B73F8_usa);
                break;
            case 0x7:
                gSPObjLoadTxtr(glistp++, &D_800B7410_usa);
                break;
            case 0x8:
                gSPObjLoadTxtr(glistp++, &D_800B7428_usa);
                break;
            case 0x9:
                gSPObjLoadTxtr(glistp++, &D_800B7440_usa);
                break;
            case 0xA:
                gSPObjLoadTxtr(glistp++, &D_800B7458_usa);
                break;
            case 0xB:
                gSPObjLoadTxtr(glistp++, &D_800B7470_usa);
                break;
            case 0xC:
                gSPObjLoadTxtr(glistp++, &D_800B7488_usa);
                break;
            case 0xD:
                gSPObjLoadTxtr(glistp++, &D_800B74A0_usa);
                break;
        }

        for (var_t1 = 11; var_t1 >= 0; var_t1--) {
            for (var_a1 = 0; var_a1 < 6; var_a1++) {
                var_a0 = &temp_t9[var_t1][var_a1];
                if (var_a0->delay != -2) {
                    if ((var_a0->type != 9) && (temp_v1_5->state != 2) && (temp_v1_5->state != 3) &&
                        (var_a0->type != 0) && (var_a0->frame_n == var_t3)) {
                        gSPObjRectangle(glistp++, &var_t0[var_t1][var_a1]);
                    }
                }
            }
        }
    }

    if (temp_t7->unk_1C != -1) {
        switch (MAX(temp_t9[temp_t7->unk_1C][temp_t7->unk_18 + 1].frame_n,
                    temp_t9[temp_t7->unk_1C][temp_t7->unk_18 + 0].frame_n)) {
            case 0x6: /* switch 4 */
                gSPObjLoadTxtr(glistp++, &D_800B73F8_usa);
                break;
            case 0x7: /* switch 4 */
                gSPObjLoadTxtr(glistp++, &D_800B7410_usa);
                break;
            case 0x8: /* switch 4 */
                gSPObjLoadTxtr(glistp++, &D_800B7428_usa);
                break;
            case 0x9: /* switch 4 */
                gSPObjLoadTxtr(glistp++, &D_800B7440_usa);
                break;
            default: /* switch 4 */
                gSPObjLoadTxtr(glistp++, &D_800B73B0_usa);
                break;
        }

        temp_v1_5 = &temp_t9[temp_t7->unk_1C][temp_t7->unk_18 + 1];
        if ((temp_v1_5->type != 0) && (temp_v1_5->state == 2 || temp_v1_5->state == 3)) {
            gSPObjRectangle(glistp++, &dynamicp->unk_182A8[num]);
        }
        temp_v1_5 = &temp_t9[temp_t7->unk_1C][temp_t7->unk_18];
        if ((temp_v1_5->type != 0) && (temp_v1_5->state == 2 || temp_v1_5->state == 3)) {
            gSPObjRectangle(glistp++, &dynamicp->unk_182D8[num]);
        }
    }

    if (gMain >= 0x38E) {
        if (gGameStatus & 0x40) {
            switch (well->unk_40B0) { /* switch 2 */
                case 0x8:             /* switch 2 */
                case 0xD:             /* switch 2 */
                    gSPObjLoadTxtr(glistp++, &D_800B73F8_usa);
                    break;
                case 0xE: /* switch 2 */
                    gSPObjLoadTxtr(glistp++, &D_800B7410_usa);
                    break;
                case 0xF: /* switch 2 */
                    gSPObjLoadTxtr(glistp++, &D_800B7428_usa);
                    break;
                case 0x10: /* switch 2 */
                    gSPObjLoadTxtr(glistp++, &D_800B7440_usa);
                    break;
                default:
                    gSPObjLoadTxtr(glistp++, &D_800B74B8_usa);
                    break;
            }
        } else {
            switch (well->unk_40B0) { /* switch 3 */
                case 0x8:             /* switch 3 */
                case 0x10:            /* switch 3 */
                    gSPObjLoadTxtr(glistp++, &D_800B7458_usa);
                    break;
                case 0x11: /* switch 3 */
                    gSPObjLoadTxtr(glistp++, &D_800B7470_usa);
                    break;
                case 0x12: /* switch 3 */
                    gSPObjLoadTxtr(glistp++, &D_800B7488_usa);
                    break;
                case 0x13: /* switch 3 */
                    gSPObjLoadTxtr(glistp++, &D_800B74A0_usa);
                    break;
                default:
                    gSPObjLoadTxtr(glistp++, &D_800B74B8_usa);
                    break;
            }
        }
    } else {
        gSPObjLoadTxtr(glistp++, &D_800B74B8_usa);
    }

    for (var_a1 = 0; var_a1 < 6; var_a1++) {
        gSPObjRectangle(glistp++, &dynamicp->unk_18188[num][var_a1]);
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DTetrisWell);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw2d", Draw2DTetrisWell);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw2d", Draw2DTetrisWell);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw2d", Draw2DTetrisWell);
#endif

INLINE void Draw2DCursor(struct_gInfo_unk_00068 *dynamicp) {
    s32 i;

    if (dynamicp->cursorBlock[0].unk_20 == 0) {
        gSPObjLoadTxtr(glistp++, &cursorBig);
    } else {
        gSPObjLoadTxtr(glistp++, &cursorSmall);
    }

    for (i = 0; i < gTheGame.unk_9C08; i++) {
        cursor_t *cursor = &dynamicp->cursorBlock[i];

        if (cursor->unk_14 < 0xC) {
            gSPObjRectangle(glistp++, &cursor->rect);
        }
    }
}

void Draw2DIcon(struct_gInfo_unk_00068 *dynamicp, s32 num) {
    s32 i;
    icon_t *icn = dynamicp->icon[num];

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &D_01000608_usa);

    if ((gGameStatus & 8) && (gMain < GMAIN_38E)) {
        gDPPipeSync(glistp++);
        gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 100);
    }

    for (i = 0; i < ICON_COUNT; i++) {
        icon_t *icon = &icn[i];

        if (icon->flag != -1) {
            continue;
        }
        if (icon->count <= 0) {
            continue;
        }
        if ((gGameStatus & 0x10) && (gMain < GMAIN_38E) && (icon->count % 2 == 0)) {
            continue;
        }

        switch (icon->type) {
            case 0xC:
                if (icon->total < 12) {
                    gSPObjLoadTxtr(glistp++, &combo1Block);
                } else if (icon->total < 20) {
                    gSPObjLoadTxtr(glistp++, &combo2Block);
                } else if (icon->total < 28) {
                    gSPObjLoadTxtr(glistp++, &combo3Block);
                } else if (icon->total < 36) {
                    gSPObjLoadTxtr(glistp++, &combo4Block);
                } else if (icon->total < 44) {
                    gSPObjLoadTxtr(glistp++, &combo5Block);
                } else if (icon->total < 52) {
                    gSPObjLoadTxtr(glistp++, &combo6Block);
                } else if (icon->total < 60) {
                    gSPObjLoadTxtr(glistp++, &combo7Block);
                } else if (icon->total < 68) {
                    gSPObjLoadTxtr(glistp++, &combo8Block);
                } else {
                    gSPObjLoadTxtr(glistp++, &combo9Block);
                }
                break;

            case 0xA:
                if (icon->total < 9) {
                    gSPObjLoadTxtr(glistp++, &chain1Block);
                } else if (icon->total < 17) {
                    gSPObjLoadTxtr(glistp++, &chain2Block);
                } else if (icon->total < 25) {
                    gSPObjLoadTxtr(glistp++, &chain3Block);
                } else if (icon->total < 33) {
                    gSPObjLoadTxtr(glistp++, &chain4Block);
                } else if (icon->total < 41) {
                    gSPObjLoadTxtr(glistp++, &chain5Block);
                } else if (icon->total < 49) {
                    gSPObjLoadTxtr(glistp++, &chain6Block);
                } else if (icon->total < 57) {
                    gSPObjLoadTxtr(glistp++, &chain7Block);
                } else if (icon->total < 65) {
                    gSPObjLoadTxtr(glistp++, &chain8Block);
                } else if (icon->total < 73) {
                    gSPObjLoadTxtr(glistp++, &chain9Block);
                } else if (icon->total < 81) {
                    gSPObjLoadTxtr(glistp++, &chain10Block);
                } else if (icon->total < 89) {
                    gSPObjLoadTxtr(glistp++, &chain11Block);
                } else if (icon->total < 97) {
                    gSPObjLoadTxtr(glistp++, &chain12Block);
                } else {
                    gSPObjLoadTxtr(glistp++, &chain13Block);
                }
                break;

            case 0xB:
            case 0xD:
                gSPObjLoadTxtr(glistp++, &combo9Block);
                break;
        }

        gSPObjRectangle(glistp++, &icon->unk_28);
    }

    if (gGameStatus & 8) {
        gDPPipeSync(glistp++);
        gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
    }
}

extern uObjTxtr brickTxtr[GAME_BUFFER_LEN][3];
// either B_801C7368_usa or B_801F9CC8_usa should be explodeTxtr
extern uObjTxtr B_801C7368_usa[GAME_BUFFER_LEN];
extern uObjTxtr B_801F9CC8_usa[GAME_BUFFER_LEN];

void Draw2DAttackBrick(struct_gInfo_unk_00068 *dynamicp, s32 num, s32 check) {
    attack_t *attk = dynamicp->attack[num];
    attack_t *attack;
    s32 count;

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_NONE);

    for (count = check; count >= 0; count--) {
        attack = &attk[count];

        if ((attack->state == 2 || attack->state == 3) && (attack->disappear < 5)) {
            if (attack->type < 0xC) {
                gSPObjLoadTxtr(glistp++, &brickTxtr[num][0]);
            } else if (attack->type < 0x12) {
                gSPObjLoadTxtr(glistp++, &brickTxtr[num][1]);
            } else {
                gSPObjLoadTxtr(glistp++, &brickTxtr[num][2]);
            }

            gSPObjRectangle(glistp++, &attack->rect);
        }
    }

    gDPPipeSync(glistp++);
    gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 100);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);

    if (num == 0) {
        gSPObjLoadTxtr(glistp++, &B_801C7368_usa[1]);
        gSPObjLoadTxtr(glistp++, &B_801F9CC8_usa[1]);
    } else {
        gSPObjLoadTxtr(glistp++, &B_801C7368_usa[0]);
        gSPObjLoadTxtr(glistp++, &B_801F9CC8_usa[0]);
    }

    for (count = 0; count <= check; count++) {
        attack = &attk[count];

        if ((attack->state == 1) && (attack->delay < 0)) {
            gSPObjRectangle(glistp++, &attack->rect);
        }
    }

    gDPPipeSync(glistp++);
    gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DAttackBlock);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw2d", Draw2DAttackBlock);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw2d", Draw2DAttackBlock);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw2d", Draw2DAttackBlock);
#endif

void Draw2DExplosion(struct_gInfo_unk_00068 *dynamicp, s32 num) {
    explode_t *exp = dynamicp->explosion[num];
    explode_t *explode;
    s32 fade;
    s32 count;

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);

    gSPObjLoadTxtr(glistp++, &B_801C7368_usa[num]);
    gSPObjLoadTxtr(glistp++, &B_801F9CC8_usa[num]);

    fade = 0;
    for (count = 0; count < TETWELL_EXPLOSION_LEN; count++) {
        explode = &exp[count];

        if (explode->type == 0x19) {
            if ((gGameStatus & 0x10) && ((explode->frame % 2) == 1)) {
                continue;
            }

            if ((gGameStatus & 0x8) && (fade == 0)) {
                gDPPipeSync(glistp++);
                gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
                gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
                gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 100);
                fade = 1;
            }
        } else if (fade == 1) {
            fade = 2;
        }

        if (fade == 2) {
            gDPPipeSync(glistp++);
            gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
            gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
            gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
            fade = 0;
        }

        if (explode->frame >= 0) {
            gSPObjRectangle(glistp++, &explode->rect);
        }
    }

    gDPPipeSync(glistp++);
    gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", Draw2DClearLine);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw2d", Draw2DClearLine);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw2d", Draw2DClearLine);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw2d", Draw2DClearLine);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006F09C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw2d", func_8006F09C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw2d", func_8006F09C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw2d", func_8006F09C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/draw2d", func_8006F2FC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/draw2d", func_8006F2FC_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/draw2d", func_8006F2FC_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/draw2d", func_8006F2FC_usa);
#endif

void DrawTetris(struct_gInfo_unk_00068 *dynamicp) {
    if (gCounter < 2) {
        return;
    }

    if (gTheGame.unk_9C0C == 2) {
        Draw3DTetris(dynamicp);
    } else {
        Draw2DTetris(dynamicp);
    }

    if (gMain == GMAIN_384) {
        if (gCounter == 2) {
            func_8004FABC_usa();
        } else if (gCounter == 4) {
            func_80050420_usa();
        } else {
            if (gCounter <= COUNTER_VALUE - 1) {
                func_8005076C_usa();
            }
            if (gCounter >= COUNTER_VALUE - 1) {
                func_80050C2C_usa();
            }
        }
    }
}

INLINE void OverFlow(struct_gInfo_unk_00068 *dynamicp) {
    s32 size;

    if ((gTheGame.unk_9C08 == 1) || (dynamicp->unk_10240 <= 0x320)) {
        gLastOverflow = 0x320;
        return;
    }

    if (dynamicp->unk_10240 >= gLastOverflow + 0x6E) {
        gLastOverflow = gLastOverflow + 0x6E;
    } else if (gLastOverflow - 0x50 >= dynamicp->unk_10240) {
        gLastOverflow = gLastOverflow - 0x50;
    } else {
        gLastOverflow = dynamicp->unk_10240;
    }

    size = (gLastOverflow - 0x320);
    size = ADJUST_FRAMERATE(size);
    size = MIN(size, 0x1194);

    size = size / 10;
    while (size > 0) {
        s32 height = MIN(size, 0xE8);

        gTheGame.unk_9A50.b.frameH = height << 2;
        size -= 0xE8;
        Draw2DBackground();
    }

    gTheGame.unk_9A50.b.frameH = 0xE8 << 2;
}

void Draw2DTetris(struct_gInfo_unk_00068 *dynamicp) {
    s32 end_attack[GAME_BUFFER_LEN];
    s32 i;

    gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 7, SCREEN_WIDTH, SCREEN_HEIGHT - 1);

    Draw2DBackground();

    if (gOverflowFlag != 0) {
        OverFlow(dynamicp);
    }

    Draw2DAnimation(dynamicp, 1, 3);
    if ((gMain != GMAIN_384) || (gCounter >= COUNTER_VALUE)) {
        Draw2DShadeBox();

        gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 31, SCREEN_WIDTH, SCREEN_HEIGHT - 17);
        gDPPipeSync(glistp++);
        gDPSetTextureLUT(glistp++, G_TT_RGBA16);
        gSPObjLoadTxtr(glistp++, &colorLUT);

        Draw2DGameFade();

        for (i = 0; i < gTheGame.unk_9C08; i++) {
            Draw2DTetrisWell(dynamicp, &gTheGame.tetrisWell[i], i);
            end_attack[i] = Draw2DAttackBlock(dynamicp, i);
        }

        gDPSetScissor(glistp++, G_SC_NON_INTERLACE, 0, 7, SCREEN_WIDTH, SCREEN_HEIGHT - 1);

        Draw2DFrame();
        Draw2DAnimation(dynamicp, 4, 4);
        Draw2DText(dynamicp);
        Draw2DMiscStuff(dynamicp);
        Draw2DAnimation(dynamicp, 5, 6);
        if ((gSelection == 0xAA) || (gSelection == 0xB4)) {
            for (i = 0; i < gTheGame.unk_9C08; i++) {
                Draw2DClearLine(dynamicp, i);
            }
        }

        if (gMain != GMAIN_388) {
            for (i = 0; i < gTheGame.unk_9C08; i++) {
                Draw2DAttackBrick(dynamicp, i, end_attack[i]);
                Draw2DExplosion(dynamicp, i);
                Draw2DIcon(dynamicp, i);
            }
        }

        if ((gMain == GMAIN_387) || (gMain == GMAIN_384)) {
            gDPPipeSync(glistp++);
            gDPSetTextureLUT(glistp++, G_TT_RGBA16);
            gSPObjLoadTxtr(glistp++, &colorLUT);
            Draw2DCursor(dynamicp);
        }

        if (gMain >= GMAIN_388) {
            DrawPauseOver(dynamicp);
        } else if (gMain == GMAIN_384) {
            DrawCountDown();
        }
    }
}
