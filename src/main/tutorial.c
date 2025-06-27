/**
 * Original filename: tutorial.h
 */

#include "tutorial.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "ai.h"
#include "buffers.h"
#include "character.h"
#include "dlist.h"
#include "end.h"
#include "image.h"
#include "init2d.h"
#include "init3d.h"
#include "menu.h"
#include "mimic.h"
#include "other.h"
#include "peel.h"
#include "puzzle.h"
#include "screen.h"
#include "segment_symbols.h"
#include "sfxlimit.h"
#include "tetsound.h"
#include "the_game.h"

s32 TutorialPattern(void) {
    u8 *ptr = garbage_rebreak;
    s32 count;
    s32 type;
    s32 *temp2;

    for (count = 1; count < brainbrain->unk_030; count++) {
        s32 temp = *ptr;
        ptr += (temp / 2) + 1;
    }

    ptr++;
    ptr += (brainbrain->unk_034 - 1) / 2;
    if (brainbrain->unk_034 % 2 == 0) {
        type = *ptr & 0xF;
    } else {
        type = *ptr >> 4;
    }

    temp2 = &brainbrain->unk_034;
    *temp2 += 1;

    return type;
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
void InitTutorial(void) {
    s32 var_a1;
    s32 var_a1_2;
    s32 var_s2; // num
    s32 var_s7;
    uObjSprite *var_a0_3;

    s32 s0 = 1;

    tetWell *s2;
    cursor_t *s1;
    ai_t *s3;

    var_a1 = 0;

    B_80193020_usa = 0;
    B_801C6EE8_usa = 1;
    B_801C6E58_usa = 1;
    Pon_Image_Heap = &gBufferHeap[SEGMENT_ROM_SIZE(segment_0CA4A0)];
    gCounter = 0;
    gTheGame.unk_9C0C = 1;
    if (gGameStatus & 0x80) {
        gGameStatus <<= 0x10;
        gGameStatus |= 0x80;
    } else {
        if (gGameStatus & 0x40) {
            var_a1 = -1;
        }
        gGameStatus <<= 0x10;
        if (var_a1 != 0) {
            gGameStatus |= 0x40;
        }
    }

    func_80054624_usa();
    InitGameStateVar();
    InitCharacter(s0, -1);

    bcopy(&B_801C7368_usa[0], &B_801C7368_usa[1], 0x18);
    bcopy(&B_801C6E70_usa[1], &B_801C6E70_usa[0], 0x18);
    // attackB, attackA
    bcopy(B_801F9D00_usa[1], B_801F9D00_usa[0], 0x90);
    // faceB, faceA
    bcopy(&B_801F9C48_usa[1], &B_801F9C48_usa[0], 0x18);

    LoadFairySoundData(0x19, s0 / 100, s0 / 100);
    if (gTheGame.menu[0].unk_0 == 5) {
        Init3DMatrixBlocks();
    }
    InitMiscStuff();
    chain_check[0] = 0;
    chain_check[1] = 0;
    anim_bg = 0;
    anim_sp = 0;
    gWhatever = 0;
    screenLoad("HOWTO.SBF", &Pon_Image_Heap);

    switch (gTheGame.menu[0].unk_0) { /* switch 1 */
        case 0x1:                     /* switch 1 */
            var_s7 = screenSet("HOWTO-BASIC1", 0x401);
            break;

        case 0x2: /* switch 1 */
            var_s7 = screenSet("HOWTO-BASIC2", 0x401);
            break;
        case 0x5: /* switch 1 */
            gTheGame.unk_9C0C = 2;
            var_s7 = screenSet("HOWTO-3D", 0x401);
            break;
        case 0x3: /* switch 1 */
            var_s7 = screenSet("HOWTO-VS1", 0x401);
            break;
        case 0x4: /* switch 1 */
            var_s7 = screenSet("HOWTO-VS2", 0x401);
            break;
    }

    if (gTheGame.menu[0].unk_0 == 3) {
        menuInitFairy(MFP_LEFT_MIDDLE);
    } else {
        menuInitFairy(MFP_RIGHT);
    }

    gTheGame.unk_9B50[0].b.frameH = 0x78;
    gTheGame.unk_9B50[1].b.frameH = 0x78;
    for (var_a1_2 = 0; var_a1_2 < 2; var_a1_2++) {
        var_a0_3 = &gTheGame.unk_9A08[var_a1_2];
        var_a0_3->s.imageW = 0x100;
        var_a0_3->s.imageH = 0x100;
        var_a0_3->s.paddingX = 0;
        var_a0_3->s.paddingY = 0;
        var_a0_3->s.imageStride = 8;
        var_a0_3->s.imageAdrs = 0;
        var_a0_3->s.imageFmt = 2;
        var_a0_3->s.imageSiz = 1;
        var_a0_3->s.imagePal = 0;
        var_a0_3->s.imageFlags = 0;
    }

    var_a0_3 = gTheGame.unk_9A08;
    var_a0_3[0].s.scaleH = 0x2A;
    var_a0_3[1].s.scaleH = 0x2A;
    var_a0_3[0].s.objX = 0x60;
    var_a0_3[0].s.scaleW = 0x4B;
    var_a0_3[1].s.scaleW = 0x4B;
    var_a0_3[0].s.objY = 0x7C;
    var_a0_3[1].s.objY = 0x7C;
    var_a0_3[1].s.objX = 0x2F0;

    if (gTheGame.menu[0].unk_0 != 3) {
        gTheGame.unk_9B50[1].b.frameH = 0;
    }

    st_AttackPosition[0] = 0x25;
    st_AttackPosition[1] = 0x25;
    st_Attack2DTopPosition[0][0] = 1;
    st_Attack2DTopPosition[1][0] = 1;
    st_Attack3DTopPosition[0][0] = 1;
    st_Attack3DTopPosition[1][0] = 1;
    attack_chain2[0] = 0;
    attack_chain2[1] = 0;
    gTheGame.unk_9C08 = 2;

    for (var_s2 = 0; var_s2 < gTheGame.unk_9C08; var_s2++) {
        s2 = &gTheGame.tetrisWell[var_s2];

        s2->unk_43B0 = 0;
        s2->unk_43A8 = 0;
        s2->unk_43A4 = 0;
        s2->unk_43B4 = 0;
        s2->unk_43B8 = 0;
        s2->unk_43BC = 0;
        s2->unk_43C0 = 0;
        s2->unk_43C4 = 0;
        s2->unk_43F4 = 0;
        s2->unk_441C = 0xDF;
        s2->unk_43F8 = 0;
        s2->unk_43FC = 0;

        if (gTheGame.unk_9C0C == 1) {
            s1 = &gTheGame.cursorBlock[var_s2];
            InitCursor(s1);
            Init2DCursor(s1, var_s2);
            Init2DIcons(s2);
            Init2DAttackBlocks(s2);
            Init2DExplosion(s2);
        }

        if (var_s2 == 1) {
            Init2DTetrisBlocks(s2, var_s2);
        }
    }

    s2 = &gTheGame.tetrisWell[0];
    s1 = &gTheGame.cursorBlock[0];
    s3 = &brainbrain[0];

    switch (gTheGame.menu[0].unk_0) { /* switch 2 */
        case 0x1:                     /* switch 2 */
            Init2DPuzzle(s2, s1, tutorial1, 1);
            s3->unk_03C = 1;
            break;

        case 0x2: /* switch 2 */
            Init2DPuzzle(s2, s1, tutorial2, 1);
            s3->unk_03C = 2;
            gTheGame.unk_90B4 = 0x100;
            gTheGame.unk_90B8 = 8;
            gTheGame.unk_90BC = 2;
            gTheGame.unk_90AA = 0x400;
            gTheGame.unk_90AE = 0;
            gTheGame.unk_90B2 = 0x400;
            gTheGame.unk_90B6 = 0;
            gTheGame.unk_90BD = 1;
            gTheGame.unk_90BE = 0;
            gTheGame.unk_90BF = 0;
            break;

        case 0x5: /* switch 2 */
            InitCursor(s1);
            Init3DCursor(s1, 0);
            Init3DPuzzle(s2, s1, tutorial3, 1);
            s3->unk_03C = 5;
            s2->translation = 0.0f;
            Init3DIcons(s2);
            Init3DAttackBlocks(s2);
            Init3DExplosion(s2);
            break;

        case 0x3: /* switch 2 */
            Init2DPuzzle(s2, s1, tutorial4, 1);
            s3->unk_03C = 3;
            break;

        case 0x4: /* switch 2 */
            Init2DPuzzle(s2, s1, tutorial5, 1);
            s3->unk_03C = 4;
            break;
    }

    s1->unk_28 = 0;
    s1->unk_2C = 0;
    if (gTheGame.unk_9C0C == 1) {
        Init2DNewRow(&s2[0]);
        Init2DNewRow(&s2[1]);
        gMax = 6;
    } else {
        Init3DNewRow(&s2[0]);
        Init3DNewRow(&s2[1]);
        s2[0].new_block[0].type = BLOCKTYPE_0;
        gMax = 0x12;
    }

    gTheGame.unk_9C08 = 1;
    s3->unk_00C = 0xA;
    InitAI(s2, s1, s3);
    s3->unk_040 = 0;
    s3->unk_044 = 0;
    s3->unk_028 = var_s7;
    if (gTheGame.menu[0].unk_0 == 3) {
        s3->unk_02C = 2;
    } else {
        s3->unk_02C = 4;
    }

    s3->unk_038 = 0x64;
    s3->unk_024 = 0;
    if (gGameStatus & 0x80) {
        if (gTheGame.menu[0].unk_0 == 4) {
            tutorial_move5[0] = 0x9C;
        }
        PlaySE(SFX_INIT_TABLE, 0x7F);
    } else if (gTheGame.menu[0].unk_0 == 4) {
        tutorial_move5[0] = 0x9E;
    }

    if (gTheGame.unk_9C0C == 1) {
        if (B_8021B960_usa != 0x3F) {
            PlayMIDI(BGM_INIT_TABLE, 0x3F, 0, 1);
        }
    } else {
        PlayMIDI(BGM_INIT_TABLE, 0x43, 0, 1);
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/tutorial", InitTutorial);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tutorial", InitTutorial);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tutorial", InitTutorial);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tutorial", InitTutorial);
#endif

void TutorialCheckState(tetWell *well, cursor_t *cursor) {
    s32 temp_s1;
    s32 var_a2;
    s32 col;

    var_a2 = 0;
    if (gTheGame.controller[0].touch_button & B_BUTTON) {
        gMain = GMAIN_2BC;
        gReset = -1;
        PlaySE(SFX_INIT_TABLE, 6);
        gGameStatus = gGameStatus >> 16;
        return;
    }

    if ((gTheGame.menu[0].unk_0 == 1) || (gTheGame.menu[0].unk_0 == 5)) {
        for (col = 0; col < gMax; col++) {
            block_t *block = &well->block[BLOCK_LEN_ROWS - 1][col];

            if (block->type != BLOCKTYPE_0) {
                break;
            }
        }

        if (col != gMax) {
            var_a2 = -1;
        }
    }

    if (var_a2 == 0) {
        return;
    }

    temp_s1 = gTheGame.unk_9C0C;
    if (temp_s1 == 1) {
        if ((anim_bg == 0) && (anim_sp == 0)) {
            Init2DExplosion(well);
            gTheGame.unk_9C08 = 2;
            Init2DGameOverSmoke(well, 0);
            anim_bg = 0x25;
            gTheGame.unk_9C08 = temp_s1;
            anim_sp = 0;
            cursor->unk_00 = 0x34C;
            PlaySE(SFX_INIT_TABLE, 0xA0);
            PlaySE(SFX_INIT_TABLE, 0x175);
        } else if (anim_bg != -0x34C) {
            well->unk_43FC = anim_bg;
            well->unk_43EC = anim_sp;
            GameOverSmoke(well);
            DeadBlocksShakeOne2D(well);
            AllDeadBlocks(well);
            anim_bg = well->unk_43FC;
            anim_sp = well->unk_43EC;
            well->unk_43FC = 0;
            well->unk_43EC = 0;
            if (gMain == GMAIN_390) {
                anim_bg = -0x34C;
                anim_sp = -0x34C;
            }
        }
    } else if ((anim_bg == 0) && (anim_sp == 0)) {
        anim_bg = 0x25;
        anim_sp = 0;
        cursor->unk_00 = 0x34C;
        PlaySE(SFX_INIT_TABLE, 0xA0);
        PlaySE(SFX_INIT_TABLE, 0x175);
    } else if (anim_bg != -0x34C) {
        well->unk_43FC = anim_bg;
        well->unk_43EC = anim_sp;
        if (well->unk_43FC >= 0) {
            s32 v1 = well->unk_43FC;

            well->translation += ((f32)dead1Shake[v1] / 250.0);
            well->unk_43FC = v1 - 1;
        }
        AllDeadBlocks(well);
        anim_bg = well->unk_43FC;
        anim_sp = well->unk_43EC;
        well->unk_43FC = 0;
        well->unk_43EC = 0;
        if (gMain == GMAIN_390) {
            anim_bg = -0x34C;
            anim_sp = -0x34C;
        }
    }

    gMain = GMAIN_TUTORIAL;
}

static inline void inlined_func(s32 var_a2) {
    s32 var_s1;
    s32 var_s0;

    if (var_a2 != -1) {
        s32 temp_s2 = ((B_80193020_usa & 0xFFFF) == 0x258) ? 0x259 : 0x258;

        if ((B_80193020_usa == 0) || ((B_80193020_usa >> 0x10) != var_a2)) {
            switch (var_a2) {
                case 1:
                    var_s1 = 0x8D;
                    var_s0 = 0x3C;
                    break;

                case 2:
                    var_s1 = 0x7C;
                    var_s0 = 0x3F;
                    break;

                case 0:
                    var_s1 = 0xBC;
                    var_s0 = 0x3F;
                    break;

                default:
                    return;
            }

            B_80193020_usa = (var_a2 << 0x10) | temp_s2;
            func_80028DC0_usa(brainbrain[0].unk_028, temp_s2, var_a2);
            func_800288D8_usa(brainbrain[0].unk_028, temp_s2, var_s1, var_s0);
        }
    }
}

static inline void inlined_func2(u16 temp) {
    s32 var_s0_2;
    s32 temp2 = temp;
    struct_imageLoad_arg0 *sp28;

    if (temp2 == 0x258) {
        var_s0_2 = 0x259;
    } else if (temp2 == 0x259) {
        var_s0_2 = 0x258;
    } else {
        return;
    }

    if (func_8002864C_usa(brainbrain[0].unk_028, temp2, &sp28)) {
        if (sp28->unk_14 < 0xFF) {
            sp28->unk_14 += 8;
            if (sp28->unk_14 > 0xFF) {
                sp28->unk_14 = 0xFF;
            }
        }
    }

    if (func_8002864C_usa(brainbrain[0].unk_028, var_s0_2, &sp28)) {
        if (sp28->unk_14 > 0) {
            sp28->unk_14 -= 8;
            if (sp28->unk_14 < 0) {
                sp28->unk_14 = 0;
            }
        }
    }
}

void DoTutorial(void) {
    screenTick_arg0 sp20;
    s32 var_a2;
    s32 temp2;

    sp20.unk_0 = 0;
    sp20.unk_4 = 0;

    if (!screenFlushing()) {
        peelTick();
    }

    screenSetBackLayers(0);

    menuTickFairy(brainbrain[0].unk_028, gCounter, brainbrain[0].unk_038, 0x4FFFC, -0x3F0018, 0x520002,
                  brainbrain[0].unk_02C, brainbrain[0].unk_024);
    DoMT();

    var_a2 = -1;
    temp2 = brainbrain[0].unk_038;
    switch (gTheGame.menu[0].unk_0) {
        case 0x1:
            // Why the `&=`?
            var_a2 &= (temp2 != 0x64) ? -1 : 0;
            if (temp2 == 0x67) {
                var_a2 = 1;
            }
            var_a2 = (temp2 != 0x7C) ? var_a2 : 0;
            break;
        case 0x2:
            var_a2 &= (temp2 != 0x64) ? -1 : 0;
            if (temp2 == 0x66) {
                var_a2 = 1;
            }
            var_a2 = (temp2 != 0x76) ? var_a2 : 0;
            break;
        case 0x5:
            var_a2 &= (temp2 != 0x64) ? -1 : 0;
            if (temp2 == 0x68) {
                var_a2 = 1;
            }
            var_a2 = (temp2 != 0x77) ? var_a2 : 0;
            break;
        case 0x3:
            if (temp2 == 0x64) {
                var_a2 = 2;
            }
            break;
        case 0x4:
            var_a2 &= (temp2 != 0x64) ? -1 : 0;
            if (temp2 == 0x66) {
                var_a2 = 1;
            }
            break;
    }

    inlined_func(var_a2);
    inlined_func2(B_80193020_usa);

    screenTick(&sp20);
}

void func_8008885C_usa(struct struct_gInfo_unk_00068 *dynamicp) {
    if (!screenFlushing()) {
        if (gTheGame.unk_9C0C == 1) {
            Draw2DMT(dynamicp);
        } else {
            Draw3DMT(dynamicp);
        }

        func_8002C2C0_usa(&glistp);
    }
}

void DrawTUT(Gfx **gfxP, s32 arg1 UNUSED, s32 arg2) {
    glistp = *gfxP;
    if (arg2 == 0x64) {
        Draw2DMT(tut_dynamicp);
    } else if (arg2 == 0x6E) {
        Draw3DMT(tut_dynamicp);
    }
    *gfxP = glistp;
}
