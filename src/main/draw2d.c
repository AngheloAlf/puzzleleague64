/**
 * Original filename: draw2d.c
 */

#include "draw2d.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "animation.h"
#include "bkground.h"
#include "bonus.h"
#include "character.h"
#include "fade.h"
#include "flic.h"
#include "other.h"
#include "sign.h"
#include "text.h"

#include "assets_variables.h"

#if REGION_NTSC
#define COUNTER_VALUE (100)
#else
#define COUNTER_VALUE (80)
#endif

void Draw2DTetrisWell(struct_gInfo_unk_00068 *dynamicp, tetWell *well, s32 num) {
    block_t *block;
    cursor_t *cursor;
    block_t(*array)[BLOCK_LEN_B];
    uObjSprite(*sprite)[TETWELL_OBJSPRITE_LEN_B];
    // TODO:
    /*
    int which; // r26
    int total; // r19
    int row; // r27
    int col; // r30
    */
    s32 var_a1;
    s32 var_t1;
    s32 var_t3;
    s32 var_t8;

    var_t8 = STRUCT_GINFO_UNK_00068_UNK_10208_LEN - 5;
    if (gMain >= GMAIN_38E) {
        var_t8 = STRUCT_GINFO_UNK_00068_UNK_10208_LEN - 1;
        gLastOverflow = 800;
    }

    array = dynamicp->block[num];
    sprite = dynamicp->block_rect[num];
    cursor = &dynamicp->cursorBlock[num];

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);

    if (gGameStatus & 0x40) {
        gSPObjLoadTxtr(glistp++, &colorLUT);
    } else {
        gSPObjLoadTxtr(glistp++, &D_010003F0_usa);
    }

    for (var_t3 = 1; var_t3 <= var_t8; var_t3++) {
        if (dynamicp->unk_10208[num][var_t3] == 0) {
            continue;
        }

        // 0xA to 0xD do not exist in gc version
        switch (var_t3) {
            case 0x1:
                gSPObjLoadTxtr(glistp++, &tetrisBlock1);
                break;
            case 0x2:
                gSPObjLoadTxtr(glistp++, &tetrisBlock2);
                break;
            case 0x3:
                gSPObjLoadTxtr(glistp++, &tetrisBlock3);
                break;
            case 0x4:
                gSPObjLoadTxtr(glistp++, &tetrisBlock4);
                break;
            case 0x5:
                gSPObjLoadTxtr(glistp++, &tetrisBlock5);
                break;
            case 0x6:
                gSPObjLoadTxtr(glistp++, &tetrisBlock6);
                break;
            case 0x7:
                gSPObjLoadTxtr(glistp++, &tetrisBlock7);
                break;
            case 0x8:
                gSPObjLoadTxtr(glistp++, &tetrisBlock8);
                break;
            case 0x9:
                gSPObjLoadTxtr(glistp++, &tetrisBlock9);
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

        for (var_t1 = BLOCK_LEN_ROWS - 1; var_t1 >= 0; var_t1--) {
            for (var_a1 = 0; var_a1 < MIN(BLOCK_LEN_B, TETWELL_OBJSPRITE_LEN_B); var_a1++) {
                block = &array[var_t1][var_a1];
                if ((block->delay != -2) && (block->type != BLOCKTYPE_9) && (block->state != BLOCKSTATE_2) &&
                    (block->state != BLOCKSTATE_3) && (block->type != BLOCKTYPE_0) && (block->frame_n == var_t3)) {
                    gSPObjRectangle(glistp++, &sprite[var_t1][var_a1]);
                }
            }
        }
    }

    if (cursor->unk_1C != -1) {
        var_t3 =
            MAX(array[cursor->unk_1C][cursor->unk_18 + 1].frame_n, array[cursor->unk_1C][cursor->unk_18 + 0].frame_n);
        switch (var_t3) {
            case 0x6:
                gSPObjLoadTxtr(glistp++, &tetrisBlock6);
                break;
            case 0x7:
                gSPObjLoadTxtr(glistp++, &tetrisBlock7);
                break;
            case 0x8:
                gSPObjLoadTxtr(glistp++, &tetrisBlock8);
                break;
            case 0x9:
                gSPObjLoadTxtr(glistp++, &tetrisBlock9);
                break;
            default:
                gSPObjLoadTxtr(glistp++, &tetrisBlock3);
                break;
        }

        block = &array[cursor->unk_1C][cursor->unk_18 + 1];
        if ((block->type != BLOCKTYPE_0) && (block->state == BLOCKSTATE_2 || block->state == BLOCKSTATE_3)) {
            gSPObjRectangle(glistp++, &dynamicp->unk_182A8[num]);
        }
        block = &array[cursor->unk_1C][cursor->unk_18];
        if ((block->type != BLOCKTYPE_0) && (block->state == BLOCKSTATE_2 || block->state == BLOCKSTATE_3)) {
            gSPObjRectangle(glistp++, &dynamicp->unk_182D8[num]);
        }
    }

    if (gMain >= GMAIN_38E) {
        if (gGameStatus & 0x40) {
            switch (well->new_block[0].frame_n) {
                case 0x8:
                case 0xD:
                    gSPObjLoadTxtr(glistp++, &tetrisBlock6);
                    break;
                case 0xE:
                    gSPObjLoadTxtr(glistp++, &tetrisBlock7);
                    break;
                case 0xF:
                    gSPObjLoadTxtr(glistp++, &tetrisBlock8);
                    break;
                case 0x10:
                    gSPObjLoadTxtr(glistp++, &tetrisBlock9);
                    break;
                default:
                    gSPObjLoadTxtr(glistp++, &tetrisBlockNew);
                    break;
            }
        } else {
            switch (well->new_block[0].frame_n) {
                case 0x8:
                case 0x10:
                    gSPObjLoadTxtr(glistp++, &D_800B7458_usa);
                    break;
                case 0x11:
                    gSPObjLoadTxtr(glistp++, &D_800B7470_usa);
                    break;
                case 0x12:
                    gSPObjLoadTxtr(glistp++, &D_800B7488_usa);
                    break;
                case 0x13:
                    gSPObjLoadTxtr(glistp++, &D_800B74A0_usa);
                    break;
                default:
                    gSPObjLoadTxtr(glistp++, &tetrisBlockNew);
                    break;
            }
        }
    } else {
        gSPObjLoadTxtr(glistp++, &tetrisBlockNew);
    }

    for (var_a1 = 0; var_a1 < TETWELL_UNK_3EF0_LEN_6; var_a1++) {
        gSPObjRectangle(glistp++, &dynamicp->unk_18188[num][var_a1]);
    }
}

INLINE void Draw2DCursor(struct_gInfo_unk_00068 *dynamicp) {
    s32 i;

    if (dynamicp->cursorBlock[0].unk_20 == 0) {
        gSPObjLoadTxtr(glistp++, &cursorBig);
    } else {
        gSPObjLoadTxtr(glistp++, &cursorSmall);
    }

    for (i = 0; i < gTheGame.unk_9C08; i++) {
        cursor_t *cursor = &dynamicp->cursorBlock[i];

        if (cursor->y < 0xC) {
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
            case ICONTYPE_12:
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

            case ICONTYPE_10:
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

            case ICONTYPE_11:
            case ICONTYPE_13:
                gSPObjLoadTxtr(glistp++, &combo9Block);
                break;
        }

        gSPObjRectangle(glistp++, &icon->thing.rect);
    }

    if (gGameStatus & 8) {
        gDPPipeSync(glistp++);
        gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
    }
}

void Draw2DAttackBrick(struct_gInfo_unk_00068 *dynamicp, s32 num, s32 check) {
    attack_t *attk = dynamicp->attack[num];
    attack_t *attack;
    s32 count;

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_NONE);

    for (count = check; count >= 0; count--) {
        attack = &attk[count];

        if ((attack->state == ATTACKSTATE_2 || attack->state == ATTACKSTATE_3) && (attack->disappear < 5)) {
            if (attack->type < ATTACKTYPE_12) {
                gSPObjLoadTxtr(glistp++, &brickTxtr[num][0]);
            } else if (attack->type < ATTACKTYPE_18) {
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

        if ((attack->state == ATTACKSTATE_1) && (attack->delay < 0)) {
            gSPObjRectangle(glistp++, &attack->rect);
        }
    }

    gDPPipeSync(glistp++);
    gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
}

s32 Draw2DAttackBlock(struct_gInfo_unk_00068 *dynamicp, s32 num) {
    // TODO: name the remaining local variables
    /*
    int lev; // r29
    int row; // r1+0x8
    int col; // r25
    int count; // r1+0x1C
    int which; // r25
    int check; // r28
    int value; // r1+0x8
    int from; // r3
    int to; // r1+0x18
    int load; // r1+0x14
    */
    s32 var_t2 = -1;
    block_t(*array)[BLOCK_LEN_B] = dynamicp->block[num];
    attack_t *attk = dynamicp->attack[num];
    uObjSprite(*sprite)[TETWELL_OBJSPRITE_LEN_B] = dynamicp->block_rect[num];
    attack_t *attack;
    s32 temp_a1;
    s32 var_v0_2;
    s32 var_s0;
    s32 var_s2;
    s32 var_s5;
    s32 var_s6;
    s32 var_fp;
    s32 var_t1;
    s32 v0;

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);

    if (num == 0) {
        gSPObjLoadTxtr(glistp++, &B_801C7368_usa[1]);
    } else {
        gSPObjLoadTxtr(glistp++, &B_801C7368_usa[0]);
    }

    for (var_t1 = 0; var_t1 < ATTACK_COUNT; var_t1++) {
        if (attk[var_t1].state < ATTACKSTATE_5) {
            continue;
        }

        attack = &attk[var_t1];
        if (attack->disappear != -1) {
            if (attack->type == ATTACKTYPE_9) {
                gSPObjLoadTxtr(glistp++, &B_801C6E70_usa[num]);
                var_t2 = -1;
            } else if (var_t2 != 0) {
                gSPObjLoadTxtr(glistp++, &B_801F9D00_usa[num][0]);
                var_t2 = 0;
            }

            var_s6 = 0;
            for (var_s2 = 0; var_s2 < attack->unk_14; var_s2++) {
                temp_a1 = attack->unk_24 + var_s2;
                if (temp_a1 < BLOCK_LEN_ROWS) {
                    for (var_s0 = attack->start; var_s0 < attack->unk_1C; var_s0++) {
                        if (array[temp_a1][var_s0].type == BLOCKTYPE_9) {
                            if (array[temp_a1][var_s0].drop == 0) {
                                gSPObjRectangle(glistp++, &sprite[temp_a1][var_s0]);
                            } else if (array[temp_a1][var_s0].drop == 1) {
                                var_s6 = -1;
                            }
                        }
                    }
                }
            }

            if (var_s6 != 0) {
                var_s6 = attack->type - 0x16;
                if (var_s6 == 0xA) {
                    var_v0_2 = 0;
                    var_fp = 1;
                } else if (var_s6 == 0xB) {
                    var_v0_2 = 1;
                    var_fp = 3;
                } else {
                    var_v0_2 = 3;
                    var_fp = ARRAY_COUNT(B_801F9D00_usa[0]);
                }

                var_t2 = -1;
                for (var_s5 = var_v0_2; var_s5 < var_fp; var_s5++) {
                    gSPObjLoadTxtr(glistp++, &B_801F9D00_usa[num][var_s5]);

                    for (var_s2 = 1; var_s2 < attack->unk_14; var_s2++) {
                        temp_a1 = attack->unk_24 + var_s2;
                        if (temp_a1 < BLOCK_LEN_ROWS) {
                            for (var_s0 = attack->start; var_s0 < attack->unk_1C; var_s0++) {
                                v0 = ReturnAttackTexValue(NULL, var_s6, var_s2 - 1, var_s0);
                                v0 /= 10;
                                if ((v0 == var_s5) && (array[temp_a1][var_s0].drop == 1)) {
                                    gSPObjRectangle(glistp++, &sprite[temp_a1][var_s0]);
                                }
                            }
                        }
                    }
                }
            }
        } else if (attack->type < ATTACKTYPE_12) {
            for (var_s2 = 0; var_s2 < attack->unk_14; var_s2++) {
                temp_a1 = attack->unk_24 + var_s2;
                if (temp_a1 < BLOCK_LEN_ROWS) {
                    switch (attack->type) {
                        case ATTACKTYPE_1:
                        case ATTACKTYPE_2:
                        case ATTACKTYPE_3:
                        case ATTACKTYPE_4:
                        case ATTACKTYPE_10:
                            if (var_t2 != 0) {
                                var_t2 = 0;
                                gSPObjLoadTxtr(glistp++, &B_801F9D00_usa[num][0]);
                            }
                            break;

                        case ATTACKTYPE_9:
                            var_t2 = -1;
                            gSPObjLoadTxtr(glistp++, &B_801C6E70_usa[num]);
                            break;

                        case ATTACKTYPE_11:
                            var_t2 = -1;
                            if (var_s2 == 0) {
                                gSPObjLoadTxtr(glistp++, &B_801F9D00_usa[num][2]);
                            } else {
                                gSPObjLoadTxtr(glistp++, &B_801F9D00_usa[num][1]);
                            }
                            break;
                    }

                    for (var_s0 = attack->start; var_s0 < attack->unk_1C; var_s0++) {
                        gSPObjRectangle(glistp++, &sprite[temp_a1][var_s0]);
                    }
                }
            }
        } else {
            var_t2 = -1;

            for (var_s5 = 3; var_s5 < ARRAY_COUNT(B_801F9D00_usa[0]); var_s5++) {
                gSPObjLoadTxtr(glistp++, &B_801F9D00_usa[num][var_s5]);

                for (var_s2 = 0; var_s2 < attack->unk_14; var_s2++) {
                    temp_a1 = attack->unk_24 + var_s2;
                    if (temp_a1 < BLOCK_LEN_ROWS) {
                        for (var_s0 = attack->start; var_s0 < attack->unk_1C; var_s0++) {
                            v0 = ReturnAttackTexValue(NULL, attack->type, var_s2, var_s0);
                            v0 /= 10;
                            if (v0 == var_s5) {
                                gSPObjRectangle(glistp++, &sprite[temp_a1][var_s0]);
                            }
                        }
                    }
                }
            }
        }
    }

    var_t2 = -1;
    for (var_t1 = 0; var_t1 < ATTACK_COUNT; var_t1++) {
        attack = &attk[var_t1];
        if (attack->state == ATTACKSTATE_0) {
            return var_t1 - 1;
            // TODO: break
        }

        if ((attack->state >= ATTACKSTATE_7) && (attack->unk_20 != 0) && (attack->disappear == -1) &&
            (attack->unk_10 < 0)) {
            if (var_t2 != 0) {
                var_t2 = 0;
                gSPObjLoadTxtr(glistp++, &B_801F9C48_usa[num]);
            }
            gSPObjRectangle(glistp++, &attack->rect);
        }
    }

    return ATTACK_COUNT - 1;
}

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
    for (count = 0; count < EXPLOSION_COUNT; count++) {
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

void Draw2DClearLine(struct_gInfo_unk_00068 *dynamicp, s32 num) {
    s32 count;
    attack_t *attk;

    if ((gMain < GMAIN_388) && (gTheGame.cursorBlock[num].unk_28 <= 0)) {
        gDPPipeSync(glistp++);
        gDPSetTextureLUT(glistp++, G_TT_RGBA16);
        gSPObjLoadTxtr(glistp++, &numberLUT);
        gSPObjLoadTxtr(glistp++, &clearTexture);

        attk = dynamicp->attack[num];
        count = gCounter % 6;
        gSPObjRectangle(glistp++, &attk[count].rect);

        gDPPipeSync(glistp++);
        gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 128);

        count = 6;
        gSPObjRectangle(glistp++, &attk[count].rect);

        gDPPipeSync(glistp++);
        gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);
    }
}

void Draw2DSmoke(struct_gInfo_unk_00068 *dynamicp, s32 num) {
    s32 var_t6;
    s32 new_var;

    if (dynamicp->cursorBlock[num].unk_00 == 8) {
        gDPPipeSync(glistp++);
        gDPSetTextureLUT(glistp++, G_TT_NONE);
        gSPObjLoadTxtr(glistp++, &deadsmoke);

        gDPPipeSync(glistp++);
        gDPSetCycleType(glistp++, G_CYC_1CYCLE);
        gDPSetRenderMode(glistp++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
        gDPSetCombineMode(glistp++, G_CC_MODULATEIDECALA_PRIM, G_CC_MODULATEIDECALA_PRIM);
        gDPSetPrimColor(glistp++, 0, 0, 255, 255, 255, 255);

        for (var_t6 = 0; var_t6 < 6; var_t6++) {
            new_var = BLOCK_LEN_ROWS - 1;
            if ((dynamicp->block[num][new_var][var_t6].type != BLOCKTYPE_0) &&
                (dynamicp->explosion[num][var_t6].frame >= -0x13)) {
                gSPObjRectangle(glistp++, &dynamicp->explosion[num][var_t6].rect);
            }
        }

        gDPPipeSync(glistp++);
        gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
        gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    }
}

void Draw2DSmallStars(struct_gInfo_unk_00068 *dynamicp, s32 layer) {
    s32 num = gMain == GMAIN_395 ? 1 : 0;
    s32 total = 0;
    s32 i;
    s32 j;

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &numberLUT);

    for (i = 0; i < BLOCK_LEN_ROWS; i++) {
        for (j = 0; j < MIN(BLOCK_LEN_B, TETWELL_OBJSPRITE_LEN_B); j++) {
            if (dynamicp->block[num][i][j].bomb == layer) {
                switch (dynamicp->block[num][i][j].currRow) {
                    case 0:
                    case 1:
                        gSPObjLoadTxtr(glistp++, &stars1Texture);
                        break;

                    case 2:
                    case 3:
                        gSPObjLoadTxtr(glistp++, &stars2Texture);
                        break;
                }

                gSPObjRectangle(glistp++, &dynamicp->block_rect[num][i][j]);
            }

            total += 1;
            if (total >= 21) {
                return;
            }
        }
    }
}

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
