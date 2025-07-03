/**
 * Original filename: tetris.c
 */

#include "tetris.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "ai.h"
#include "animate.h"
#include "animation.h"
#include "bonus.h"
#include "buffers.h"
#include "combo.h"
#include "dlist.h"
#include "fade.h"
#include "init2d.h"
#include "init3d.h"
#include "other.h"
#include "peel.h"
#include "puzzle.h"
#include "segment_symbols.h"
#include "sign.h"
#include "sound.h"
#include "text.h"
#include "the_game.h"
#include "update.h"
#include "update3d.h"

extern char panel_data[][6];
extern char clearpanel_data[][6];

INLINE BlockType RandomBlock(tetWell *well) {
    s32 var_t0 = 6;
    s32 temp3 = 1;
    f32 temp;
    s32 ret;
    f32 new_var;

#if 0
    float rand; // f3
    int max; // r6
#endif

    if (well->unk_43E4 != 0) {
        var_t0 = 5;
    }

    gTheGame.unk_9C10 += 0x29A74E + (gTheGame.unk_9C10 * 0x31EF68);

    new_var = (f32)0x7FFFFFFF;
    temp = (gTheGame.unk_9C10 & 0x7FFFFFFF) / new_var;
    temp = (temp * var_t0) + temp3;
    ret = temp;
    return ret;
}

INLINE void ReturnSecond(s32 *second) {
    OSTime time = osGetTime();
    u64 microseconds = OS_CYCLES_TO_USEC(time - gTime);

    *second = microseconds / 1000000;
    if (*second == 1) {
        gTime = time;
    }
}

INLINE void InitBlockPattern(tetWell *well, char ptr[18], s32 total, s32 clear) {
    s32 var_v0;
    char *which;
    s32 i;
    s32 v0;

    bzero(ptr, 18 * sizeof(char));

    if (clear) {
        if (well->menu.unk_0 == 5) {
            var_v0 = 0x1E;
        } else {
            var_v0 = (well->menu.unk_4 - 1) * 5 - 1;
            var_v0 += well->menu.unk_8;
        }

        which = clearpanel_data[var_v0];
    } else {
        var_v0 = AnimationRandom(0xE);
        which = panel_data[var_v0];
    }

    for (i = 0; i < total; i++) {
        s32 a = i < 12;
        s32 b = i < 6;

        do {
            v0 = AnimationRandom(total);
        } while (ptr[v0] != 0);

        if (!a) {
            ptr[v0] = which[i - 12];
        } else if (!b) {
            ptr[v0] = which[i - 6];
        } else {
            ptr[v0] = which[i];
        }
    }
}

#if VERSION_USA
#ifdef NON_MATCHING
// inline issue (RandomBlock)
void InitStartingBlocks(tetWell *well, char *ptr, s32 total) {
    s32 temp_fv0;
    s32 var_t1;
    s32 var_t8;

#if 0
    int row; // r12
    int col; // r31
#endif

    for (var_t8 = 0; var_t8 < total; var_t8++) {
        for (var_t1 = 0; var_t1 < ptr[var_t8]; var_t1++) {
            do {
                temp_fv0 = RandomBlock(well);
            } while ((temp_fv0 == well->block[var_t1][var_t8 - 1].type) ||
                     (temp_fv0 == well->block[var_t1 - 1][var_t8].type));
            well->block[var_t1][var_t8].type = temp_fv0;
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", InitStartingBlocks);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetris", func_80089D2C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetris", func_800883CC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetris", func_8008858C_ger);
#endif

s32 DemoCheck(s32 *frame) {
    InitGamePad(1);

    if ((gTheGame.controller[0].touch_button != 0) || (gDemo == GDEMO_16)) {
        gDemo = GDEMO_16;
        gTheGame.unk_9C1C = 0;
        gTheGame.unk_9C18 = 0;
        gTheGame.unk_9C14 = 0;

#if VERSION_USA
        gGameStatus >>= 0x10;
#else
        if (B_801C607C_eur != 9) {
            gGameStatus >>= 0x10;
        }
#endif

        FadeOutSong(last_song_handle, 60);
        return -1;
    }

    if ((*frame > ADJUST_FRAMERATE(1800)) && (gMain == GMAIN_387)) {
        gDemo = GDEMO_21;
        gTheGame.unk_9C1C = 0;
        gTheGame.unk_9C18 = 0;
        gTheGame.unk_9C14 = 0;
        gGameStatus >>= 0x10;
        FadeOutSong(last_song_handle, 60);
        return -1;
    }

    *frame += 1;
    gDemo = GDEMO_0B;
    return 0;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_80089BE0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetris", func_80089FC8_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetris", func_80088668_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetris", func_80088828_ger);
#endif

#if VERSION_USA
#ifdef NON_MATCHING
// Inline issue (InitBlockPattern)
void InitTetrisWell(void) {
    char sp10[18];
    char *sp28;
    cursor_t *sp34;
    s32 var_fp;
    tetWell *temp_s3;
    s32 v0;
    s32 v0_2;
    s32 a3;

#if 0
    int num; // r21
    int flag; // r1+0x8
    struct tetWell * well; // r31
    struct cursor_t * cursor; // r19
    unsigned char * puzzle; // r1+0x6C
    char pattern[18]; // r1+0x58
#endif

    B_801AB61C_usa = 0;
    B_801AAB98_usa = 0;
    D_800BE350_usa = 0;
    // maybe?
#if 0
    gShit = 0;
    FRAME = 0;
    DEBUGDEBUG = 0;
#endif

    gTheGame.unk_9C10 = osGetTime();
    gFrameColor = 0x00010001;
    gCounter = 0;
    gOverflow = 0;
    if (gTheGame.unk_9C0C == 1) {
        gMax = 6;
    } else {
        gMax = 0x12;
    }

    Pon_Image_Heap = &gBufferHeap[SEGMENT_ROM_SIZE(segment_0CA4A0)];

    func_80054624_usa();
    InitGameStateVar();

    // Either of these should be InitWorld
    func_800325F8_usa();
    func_800552F4_usa();

    InitMiscStuff();
    InitPause();
    InitGameOver();
    InitGameFade();

    for (var_fp = 0; var_fp < gTheGame.unk_9C08; var_fp++) {
        temp_s3 = &gTheGame.tetrisWell[var_fp];
        sp34 = &gTheGame.cursorBlock[var_fp];

        // TODO: Why 4? Was it a typo? i.e. sizeof(&sp10)
        bzero(sp10, 4);

        temp_s3->unk_43B0 = 0;
        temp_s3->unk_43A8 = 0;
        temp_s3->unk_43A4 = 0;
        temp_s3->unk_43B4 = 0;
        temp_s3->unk_43B8 = 0;
        temp_s3->unk_43BC = 0;
        temp_s3->unk_43C0 = 0;
        temp_s3->unk_43C4 = 0;
        temp_s3->unk_43F4 = 0;
        temp_s3->unk_441C = 0xDF;
        temp_s3->unk_43F8 = 0;
        temp_s3->unk_43FC = 0;

        InitCursor(sp34);
        InitGamePad(var_fp);

        if (gTheGame.unk_9C0C == 1) {
            Init2DCursor(sp34, var_fp);
            Init2DTetrisBlocks(temp_s3, var_fp);

            switch (gSelection) { /* switch 1; irregular */
                case 0xAA:        /* switch 1 */
                    InitBlockPattern(temp_s3, sp10, 6, 1);
                    InitStartingBlocks(temp_s3, sp10, 6);
                    break;

                case 0x78: /* switch 1 */
                    v0 = temp_s3->menu.unk_4 - 1;
                    sp28 = gPlayer[0]->unk_121[v0];
                    Init2DPuzzle(temp_s3, sp34, sp28, 1);
                    break;

                case 0x82: /* switch 1 */
                    if (temp_s3->menu.unk_0 != 0) {
                        a3 = Match2DPuzzle(&sp28, temp_s3->menu.unk_0, temp_s3->menu.unk_4);
                        Init2DPuzzle(temp_s3, sp34, sp28, a3);
                    } else {
                        v0_2 = temp_s3->menu.unk_4 - 1;
                        sp28 = gPlayer[0]->unk_121[v0_2];
                        if (Init2DPuzzle(temp_s3, sp34, sp28, 1) == 0) {
                            gReset = -1;
                            gMain = GMAIN_2BC;
                            return;
                        }
                    }
                    break;

                case 0x96: /* switch 1 */
                    if (var_fp == 1) {
                        AISetLevel(&brainbrain[1], gTheGame.menu[0].unk_0, gTheGame.menu[0].unk_4);
                        InitAI(temp_s3, sp34, &brainbrain[1]);
                    }
                    FALLTHROUGH;

                default: /* switch 1 */
                    if (var_fp == 0) {

                        InitBlockPattern(temp_s3, sp10, 6, 0);
                        InitStartingBlocks(temp_s3, sp10, 6);
                    } else if (gTheGame.tetrisWell[0].unk_43E4 != temp_s3->unk_43E4) {

                        InitBlockPattern(temp_s3, sp10, 6, 0);
                        InitStartingBlocks(temp_s3, sp10, 6);
                    } else {
                        bcopy(gTheGame.tetrisWell[0].block, temp_s3->block,
                              sizeof(block_t) * BLOCK_LEN_ROWS * BLOCK_LEN_B);
                    }
                    break;
            }

            Init2DNewRow(temp_s3);
            Init2DIcons(temp_s3);
            Init2DAttackBlocks(temp_s3);
            Init2DExplosion(temp_s3);
            Init2DText();
            if ((gSelection == 0xAA) || (gSelection == 0xB4)) {
                Init2DClearLine(temp_s3, sp34, var_fp);
            }
            Init2DTetrisBlocksTMEM(temp_s3, 0);
        } else {
            Init3DCursor(sp34, var_fp);
            Init3DTetrisBlocks(temp_s3, var_fp);
            temp_s3->translation = -0.768f;

            switch (gSelection) { /* irregular */
                case 0x82: {
                    a3 = func_80088A48_usa(&sp28, temp_s3->menu.unk_0, temp_s3->menu.unk_4);
                    Init3DPuzzle(temp_s3, sp34, sp28, a3);
                } break;

                case 0xAA:

                    // do {
                    InitBlockPattern(temp_s3, sp10, 18, 1);
                    //} while (0);
                    InitStartingBlocks(temp_s3, sp10, 0x12);
                    break;

                default:
                    if (var_fp == 0) {

                        InitBlockPattern(temp_s3, sp10, 18, 0);
                        InitStartingBlocks(temp_s3, sp10, 0x12);
                    } else if (gTheGame.tetrisWell[0].unk_43E4 != temp_s3->unk_43E4) {

                        InitBlockPattern(temp_s3, sp10, 18, 0);
                        InitStartingBlocks(temp_s3, sp10, 0x12);
                    } else {
                        bcopy(&gTheGame.tetrisWell[0].block, temp_s3->block,
                              sizeof(block_t) * BLOCK_LEN_ROWS * BLOCK_LEN_B);
                    }
                    break;
            }

            Init3DNewRow(temp_s3);
            Init3DIcons(temp_s3);
            Init3DAttackBlocks(temp_s3);
            Init3DExplosion(temp_s3);
            Init3DText();
            if ((gSelection == 0xAA) || (gSelection == 0xB4)) {
                Init3DClearLine(temp_s3, sp34, var_fp);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", InitTetrisWell);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/tetris", InitTetrisWell);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/tetris", InitTetrisWell);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/tetris", InitTetrisWell);
#endif

void DoTetris(void) {
    typedef struct Padding {
        s32 unk_0;
        s32 unk_4;
    } Padding;

    tetWell *well;
    cursor_t *cursor;
    s32 sp28 = 0; // elapsed seconds
    s32 var_a0;
    s32 var_s2;
    s32 num;
    s32 count;

#if 0
    int interval; // r20
    int blockHSize; // r31
#endif

    Padding pad UNUSED = { 0, 0 };
    s32 pad2[4] UNUSED;

    gTheGame.unk_90C0 = 6;
    for (count = 6; count < DRAWTEXT_COUNT; count++) {
        gTheGame.drawText[count].texture = -1;
    }

    ReturnSecond(&sp28);

    DoGameFade(5);
    UpdateMainState();
    if (gMain >= GMAIN_38E) {
        return;
    }

    if (D_800BE350_usa == 0) {
        gOverflow = 0;
    }

    for (num = 0; num < gTheGame.unk_9C08; num++) {
        well = &gTheGame.tetrisWell[num];
        cursor = &gTheGame.cursorBlock[num];

        if (D_800BE350_usa == 1) {
            B_801C6C94_usa = 0;
            if (gTheGame.controller[num].touch_button & Z_TRIG) {
                B_801C6C94_usa = -1;
            }

            if (B_801C6C94_usa == 0) {
                continue;
            }
        }

        B_801AAB98_usa += 1;
        if (!(gGameStatus & 0x20) || (gCounter % 2 != 0)) {
            if (gMain == GMAIN_387) {
                if ((cursor->unk_04 == 0) && (cursor->unk_0C == 0) && (well->unk_43F4 == 0) && (well->unk_43B0 == 0) &&
                    (gSelection >= 0x83) && (B_801AB61C_usa == 0) && (cursor->unk_00 <= 0) && (cursor->unk_08 == 0)) {
                    well->unk_43EC += well->unk_43F0;

                    if (well->unk_43EC >= 0x1000U) {
                        var_s2 = well->unk_43EC & 0xFFFF0000;
                        if (var_s2 < 0) {
                            var_a0 = var_s2 | 0xFFFF;
                        } else {
                            var_a0 = var_s2;
                        }
                        well->unk_43EC &= 0xFFFF;
                        var_s2 = (var_a0 >> 0x10);
                        well->unk_43FC = var_s2 * gTheGame.unk_9C0C;
                        well->unk_43F8 += well->unk_43FC;
                        if (gTheGame.unk_9C0C * 0x10 < well->unk_43F8) {
                            well->unk_43FC = gTheGame.unk_9C0C * 0x10 - (well->unk_43F8 - well->unk_43FC);
                            well->unk_43F8 = gTheGame.unk_9C0C * 0x10;
                        }
                    }
                }

                CompactWell(well, num);
            }
        }

        CheckGameInput(well, cursor, num);
        var_s2 = 0;
        if (gMain == GMAIN_387) {
            if ((gGameStatus & 0x20) && (gCounter % 2 == 0)) {
                if (gTheGame.unk_9C0C == 2) {
                    Update3DCursor(well, cursor);
                }
            } else {
                if (well->unk_43C4 != 0) {
                    CheckCollision(well);
                }

                well->unk_43C4 = 0;
                CheckChainCounter(well, cursor);
                var_s2 = ComboCount(well, cursor);
                if (well->unk_43BC != 0) {
                    well->unk_43C0 = 0;
                    well->unk_43BC = 0;
                }
                CheckShake(well, cursor);
                CheckIcon(well, var_s2);
                StartAttack(well, num);
                if (brainbrain[num].unk_00C != -1) {
                    UpdateAI(well, cursor, &brainbrain[num], num);
                }
                UpdateWell(well, cursor, num, var_s2);
                if ((gSelection == 0xA0) || (gSelection == 0x96)) {
                    ChangeAttack(well, cursor, num, var_s2);
                }
                UpdateCursor(well, cursor);
                UpdateIcon(well, cursor, num);
                if ((gSelection == 0xA0) || (gSelection == 0x96)) {
                    UpdateAttack(well, cursor, num);
                }

                UpdateExplosion(well);
            }

            UpdateNextLevel(well);
            UpdateDistance(well, cursor);
            UpdateAnimation(well, num, var_s2);
            UpdateMiscStuff(well, cursor, num);

            if ((cursor->unk_00 <= 0) && (well->unk_43F8 >= (gTheGame.unk_9C0C * 0x10))) {
                well->unk_43C4 = -1;
                AddNewRow(well, cursor, num);
                well->unk_43F8 = 0;
                if ((gSelection == 0xAA) || (gSelection == 0xB4)) {
                    cursor->unk_28[0] -= 1;
                }
            }

            if (gTheGame.unk_9C0C == 2) {
                Check3DVisibleBlocks(well, cursor);
            }

            HackGame(well);
            well->unk_43FC = 0;
            well->unk_43A4 = 0;
        }
    }

    if (gMain == GMAIN_387) {
        UpdateTime(sp28);
    }

    UpdateText();
    peelTick();
}

void HackGame(tetWell *well) {
    s32 count;

    if (gTheGame.unk_9C08 != 1) {
        for (count = 0; count < ATTACK_COUNT; count++) {
            if ((well->attack[count].type > ATTACKTYPE_4) && (well->attack[count].type < ATTACKTYPE_9)) {
                well->attack[count].state = ATTACKSTATE_0;
                well->attack[count].type = 0;
                well->attack[count].disappear = -1;
                well->attack[count].delay = 0;
                well->attack[count].unk_10 = 0;
                well->attack[count].unk_24 = -1;
                well->attack[count].unk_28 = -1;
            }
        }
    }
}
