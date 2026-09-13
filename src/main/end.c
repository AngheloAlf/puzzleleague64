/**
 * Original filename: end.c
 */

#include "end.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "libc/assert.h"

#include "animate3d.h"
#include "animation.h"
#include "bkground.h"
#include "dlist.h"
#include "explode.h"
#include "fade.h"
#include "info.h"
#include "init2d.h"
#include "init3d.h"
#include "menu.h"
#include "sfxlimit.h"
#include "sign.h"
#include "sound.h"
#include "the_game.h"
#include "update.h"
#include "update3d.h"

#include "assets/sign_gameover.h"

/**
 * Original name: GameOverSmoke
 */
void GameOverSmoke(tetWell *well) {
    s32 col;
    explode_t *explode;
    block_t *block;

    for (col = 0; col < gMax; col++) {
        block = &well->block[BLOCK_LEN_ROWS - 1][col];
        explode = &well->explosion[col];

        if (block->type == BLOCKTYPE_0) {
            continue;
        }

        explode->frame--;
        if (explode->frame >= -4) {
            explode->rect.s.imageAdrs = 6;
        } else if (explode->frame >= -10) {
            explode->rect.s.imageAdrs = 4;
        } else if (explode->frame >= -15) {
            explode->rect.s.imageAdrs = 2;
        } else {
            explode->rect.s.imageAdrs = 0;
        }

        if (explode->frame % 3 == 0) {
            explode->rect.s.objY = ((explode->rect.s.objY >> 2) - 1) << 2;
        }
    }
}

/**
 * Original name: DeadBlocksShakeOne2D
 */
void DeadBlocksShakeOne2D(tetWell *well) {
    uObjSprite_t *s;
    s32 col;
    s32 row;
    s32 diff;
    s32 temp;

    if (well->raise < 0) {
        return;
    }

    diff = dead1Shake[well->raise];
    well->raise--;
    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        for (col = 0; col < TETWELL_OBJSPRITE_LEN_B; col++) {
            s = &well->block_rect[row][col].s;

            temp = s->objY >> 2;
            s->objY = (temp - diff) << 2;
        }
    }

    if (gSelection >= SELECTION_83) {
        for (col = 0; col < TETWELL_UNK_3EF0_LEN_6; col++) {
            s = &well->new_block_rect[col].s;

            temp = s->objY >> 2;
            s->objY = (temp - diff) << 2;
        }

        temp = well->left2D.s.objY >> 2;
        well->left2D.s.objY = (temp - diff) << 2;

        temp = well->right2D.s.objY >> 2;
        well->right2D.s.objY = (temp - diff) << 2;
    }
}

/**
 * Original name: AllDeadBlocks
 */
void AllDeadBlocks(tetWell *well) {
    s32 row;
    s32 col;
    block_t *block;

    if (gGameStatus & GAME_STATUS_FLAG_40) {
        if (well->timer != 0) {
            well->timer--;
            if ((well->new_block[0].frame_n == 0x10) && (well->timer == 0)) {
                gMain = GMAIN_390;
            }
            return;
        }

        for (row = 0; row < BLOCK_LEN_ROWS; row++) {
            for (col = 0; col < gMax; col++) {
                block = &well->block[row][col];
                if (block->type == BLOCKTYPE_0) {
                    continue;
                }

                if (block->frame_n <= BLOCK_LEN_ROWS) {
                    block->frame_n = 0xD;
                } else if (block->frame_n == 0xD) {
                    block->frame_n = 0xE;
                } else if (block->frame_n == 0xE) {
                    block->frame_n = 0xF;
                } else if (block->frame_n == 0xF) {
                    block->frame_n = 0x10;
                }

                block->frame_d = 0;
            }
        }

        for (col = 0; col < gMax; col++) {
            block = &well->new_block[col];

            if (block->frame_n <= BLOCK_LEN_ROWS) {
                block->frame_n = 0xD;
            } else if (block->frame_n == 0xD) {
                block->frame_n = 0xE;
            } else if (block->frame_n == 0xE) {
                block->frame_n = 0xF;
            } else if (block->frame_n == 0xF) {
                block->frame_n = 0x10;
            }
        }

        if (block->frame_n == 0xD) {
            well->timer = 40;
        } else {
            well->timer = 5;
        }
    } else {
        if (well->timer != 0) {
            well->timer--;
            if ((well->new_block[0].frame_n == 0x13) && (well->timer == 0)) {
                gMain = GMAIN_390;
            }
            return;
        }

        for (row = 0; row < BLOCK_LEN_ROWS; row++) {
            for (col = 0; col < gMax; col++) {
                block = &well->block[row][col];
                if (block->type == BLOCKTYPE_0) {
                    continue;
                }

                if (block->frame_n <= 0xF) {
                    block->frame_n = 0x10;
                } else if (block->frame_n == 0x10) {
                    block->frame_n = 0x11;
                } else if (block->frame_n == 0x11) {
                    block->frame_n = 0x12;
                } else if (block->frame_n == 0x12) {
                    block->frame_n = 0x13;
                }

                block->frame_d = 0;
            }
        }

        for (col = 0; col < gMax; col++) {
            block = &well->new_block[col];

            if (block->frame_n <= 0xF) {
                block->frame_n = 0x10;
            } else if (block->frame_n == 0x10) {
                block->frame_n = 0x11;
            } else if (block->frame_n == 0x11) {
                block->frame_n = 0x12;
            } else if (block->frame_n == 0x12) {
                block->frame_n = 0x13;
            }
        }

        if (block->frame_n == 0x10) {
            well->timer = 40;
        } else {
            well->timer = 5;
        }
    }
}

/**
 * Original name: AllDeadFaces
 */
void AllDeadFaces(tetWell *well) {
    s32 row;
    s32 col;
    block_t *block;

    if (gGameStatus & GAME_STATUS_FLAG_40) {
        if (well->timer != 0) {
            well->timer--;
            if ((well->new_block[0].frame_n == 8) && (well->timer == 0)) {
                gMain = GMAIN_390;
            }
            return;
        }

        for (row = 0; row < BLOCK_LEN_ROWS; row++) {
            for (col = 0; col < gMax; col++) {
                block = &well->block[row][col];

                if ((block->type != BLOCKTYPE_0) && (block->frame_n < 0xD)) {
                    block->frame_n = 8;
                }
            }
        }

        for (col = 0; col < gMax; col++) {
            block = &well->new_block[col];
            if (block->frame_n < 0xD) {
                block->frame_n = 8;
            }
        }

        if (block->frame_n == 8) {
            well->timer = 60;
        }
    } else {
        if (well->timer != 0) {
            well->timer--;
            if ((well->new_block[0].frame_n == 0x10) && (well->timer == 0)) {
                gMain = GMAIN_390;
            }
            return;
        }

        for (row = 0; row < BLOCK_LEN_ROWS; row++) {
            for (col = 0; col < gMax; col++) {
                block = &well->block[row][col];
                if ((block->type != BLOCKTYPE_0) && (block->frame_n < 0x10)) {
                    block->frame_n = 0x10;
                }
            }
        }

        for (col = 0; col < gMax; col++) {
            block = &well->new_block[col];
            if (block->frame_n < 0x10) {
                block->frame_n = 0x10;
            }
        }

        if (block->frame_n == 0x10) {
            well->timer = 60;
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80037900_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", func_80037900_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", func_80037900_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", func_80037900_usa);
#endif

/**
 * Original name: KillRow3D
 */
void KillRow3D(tetWell *well, cursor_t *cursor UNUSED) {
    block_t *top_block;
    block_t *bot_block;
    s32 col;
    s32 row;
    s32 done;

    done = -1;
    well->timer++;
    if (well->timer < 30) {
        return;
    }

    if (well->timer % 2 == 1) {
        return;
    }

    for (row = 0; row < BLOCK_LEN_ROWS - 1; row++) {
        for (col = 0; col < BLOCK_LEN_B; col++) {
            bot_block = &well->block[row][col];
            top_block = &well->block[row + 1][col];
            bcopy_chk(top_block, bot_block);
            InitTetrisState(top_block);
        }
    }

    for (col = 0; col < BLOCK_LEN_B; col++) {
        done &= well->block[0][col].type == BLOCKTYPE_0 ? -1 : 0;
    }

    if (done) {
        for (col = 0; col < BLOCK_LEN_B; col++) {
            InitTetrisState(&well->new_block[col]);
        }

        gMain = GMAIN_391;
        well->timer = 20;
    }
}

/**
 * Original name: GameOverSign
 */
void GameOverSign(tetWell *well, cursor_t *cursor) {
    s32 var_s1;
    s32 temp;

    if (well->raise >= 0) {
        switch (gSelection) {
            case SELECTION_8C:
                var_s1 = gameoverShake[well->raise];
                if (well->raise == 0x50) {
                    PlaySE(SFX_INIT_TABLE, SFX_0A4);
                }
                break;

            case SELECTION_BE:
                if (cursor->state == 7) {
                    gTheGame.unk_9A90[0].b.frameY = 50 << 2;
                    well->raise = 0;
                    gMain = GMAIN_393;
                    return;
                }
                var_s1 = gameoverShake[well->raise];
                break;

            case SELECTION_78:
            case SELECTION_82:
            case SELECTION_AA:
                if (cursor->state == 7) {
                    var_s1 = clearroundShake[well->raise];
                    if (well->raise == 0x48) {
                        if ((gSelection == SELECTION_AA) && (gTheGame.menu[0].speed == 5)) {
                            func_80005888_usa(0, 0, 2);
                        }
                        PlaySE(SFX_INIT_TABLE, SFX_0A4);
                    }
                } else {
                    var_s1 = gameoverShake[well->raise];
                    if (well->raise == 0x50) {
                        PlaySE(SFX_INIT_TABLE, SFX_0A4);
                    }
                }
                break;

            default:
                break;
        }

        well->raise--;
    } else {
        gMain = GMAIN_393;
        return;
    }

    temp = gTheGame.unk_9A90[0].b.frameY >> 2;
    gTheGame.unk_9A90[0].b.frameY = (temp - var_s1) << 2;
}

/**
 * Original name: EndingExplosion
 */
s32 EndingExplosion(tetWell *well) {
    u8 sp18[][2] = {
        { 0x0B, 0x00 }, { 0x07, 0x02 }, { 0x01, 0x00 }, { 0x09, 0x04 }, { 0x03, 0x02 }, { 0x05, 0x04 },
        { 0x07, 0x00 }, { 0x0B, 0x04 }, { 0x05, 0x02 }, { 0x01, 0x04 }, { 0x09, 0x02 }, { 0x03, 0x00 },
        { 0x0B, 0x02 }, { 0x07, 0x04 }, { 0x09, 0x00 }, { 0x01, 0x02 }, { 0x05, 0x00 }, { 0x03, 0x04 },
    };
    s32 var_s0;
    s32 var_s2;

    if (gSelection == SELECTION_82) {
        switch (well->menu.game) {
            case 0x0:
            case 0x1:
            case 0x4:
                var_s0 = 1;
                break;

            case 0x2:
            case 0x3:
            case 0x5:
                if (well->menu.stage < ENUM_GAME_UNK_0000_UNK_4424_31) {
                    var_s0 = 1;
                } else if (well->menu.stage < ENUM_GAME_UNK_0000_UNK_4424_41) {
                    var_s0 = 2;
                } else {
                    var_s0 = 3;
                }
                break;

            case 0x6:
                if (well->menu.stage < ENUM_GAME_UNK_0000_UNK_4424_31) {
                    var_s0 = 1;
                } else if (well->menu.stage < ENUM_GAME_UNK_0000_UNK_4424_41) {
                    var_s0 = 2;
                } else {
                    var_s0 = 3;
                }
                break;
        }
    }

    if (gWhatever == 3) {
        if (gSelection == SELECTION_AA) {
            if (well->menu.speed < 3) {
                PlaySE(SFX_INIT_TABLE, SFX_12C);
            } else if (well->menu.speed < 5) {
                PlaySE(SFX_INIT_TABLE, SFX_12D);
            } else {
                PlaySE(SFX_INIT_TABLE, SFX_12E);
            }
        } else if (gSelection == SELECTION_82) {
            switch (var_s0) {
                case 1:
                    PlaySE(SFX_INIT_TABLE, SFX_12C);
                    break;

                case 2:
                    PlaySE(SFX_INIT_TABLE, SFX_12D);
                    break;

                case 3:
                    PlaySE(SFX_INIT_TABLE, SFX_12E);
                    break;
            }
        } else {
            PlaySE(SFX_INIT_TABLE, SFX_12C);
        }
    }

    if (gWhatever < 0x6D) {
        s32 temp_v1_5 = gWhatever / 3;

        if (gWhatever == (temp_v1_5 * 3)) {
            s32 var_a1_2;

            if (gWhatever > ARRAY_COUNT(sp18) * 3) {
                var_a1_2 = temp_v1_5 - 1 - ARRAY_COUNT(sp18);
            } else {
                var_a1_2 = temp_v1_5 - 1;
            }

            if (gTheGame.dimension == DIMENSION_2D) {
                StartExplosion(well, 0, sp18[var_a1_2][0], sp18[var_a1_2][1], 0x1F);
            } else {
                StartExplosion(well, 0, sp18[var_a1_2][0], sp18[var_a1_2][1] + 2, 0x1F);
            }
        }
    }

    if (gSelection == SELECTION_AA) {
        if (well->menu.speed < 3) {
            var_s2 = 0x82;
        } else if (well->menu.speed < 5) {
            var_s2 = 0xAA;
        } else {
            var_s2 = 0xCD;
        }
    } else if (gSelection != SELECTION_82) {
        var_s2 = 0x82;
    } else {
        switch (var_s0) {
            case 0x1:
                var_s2 = 0x82;
                break;

            case 0x2:
                var_s2 = 0xAA;
                break;

            case 0x3:
                var_s2 = 0xCD;
                break;
        }
    }

    return (var_s2 >= gWhatever) ? -1 : 0;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80038018_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", func_80038018_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", func_80038018_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", func_80038018_usa);
#endif

/**
 * Original name: ChangeDeadFace
 */
void ChangeDeadFace(tetWell *well) {
    block_t *block;
    s32 temp_t5;
    s32 row;
    s32 col;
    nbool flag;

    flag = nfalse;
    temp_t5 = (gGameStatus & 0x40) ? 3 : 0;
    if (well->timer != 0) {
        well->timer--;
        return;
    }

    for (row = BLOCK_LEN_ROWS - 1; row >= 0; row--) {
        for (col = 0; col < gMax; col++) {
            block = &well->block[row][col];

            if (block->type != BLOCKTYPE_0) {
                if (block->frame_n != 0x10 - temp_t5) {
                    block->frame_n = 0x10 - temp_t5;
                    flag = ntrue;
                }
            }
        }

        if (flag) {
            well->timer = 2;
            return;
        }
    }

    for (col = 0; col < gMax; col++) {
        block = &well->new_block[col];
        block->frame_n = 0x10 - temp_t5;
    }
    return;
}

/**
 * Original name: DropRow3D
 */
void DropRow3D(tetWell *well, cursor_t *cursor, s32 num) {
    s32 col;
    s32 row;
    s32 var_v1_2;

    well->timer++;
    if (well->timer < 5) {
        return;
    }

    if (well->timer == 5) {
        PlaySE(SFX_INIT_TABLE, SFX_0A3);
    }

    well->translation += DOUBLE_LITERAL(0.048);
    if (well->timer % 10 == 0) {
        row = BLOCK_LEN_ROWS - 1 - well->timer / 10;

        for (col = 0; col < BLOCK_LEN_B; col++) {
            if (well->block[row][col].type != BLOCKTYPE_9) {
                well->block[row][col].type = BLOCKTYPE_0;
            }
        }
    }

    if (cursor->sx == 0) {
        Move3DCursorRight(cursor, CURSOR_HOLD_VAL_0);
    }

    var_v1_2 = (gTheGame.unk_9B50[num].b.frameY >> 2) - 6;
    var_v1_2 = MAX(var_v1_2, 0x19);
    gTheGame.unk_9B50[num].b.frameY = var_v1_2 << 2;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003837C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", func_8003837C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", func_8003837C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", func_8003837C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003853C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", func_8003853C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", func_8003853C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", func_8003853C_usa);
#endif

INLINE void func_800386D4_usa(tetWell *well, s32 arg1) {
    s32 temp;
    s32 temp2;
    s32 temp3;
    s32 temp4;

    if (well->timer != 0) {
        well->timer--;
        return;
    }

    // TODO: hardcoded number
    if (well->raise == 0x36) {
        PlaySE(SFX_INIT_TABLE, SFX_0A4);
    }

    temp3 = wallsdownShake[well->raise];
    well->raise--;

    temp4 = (gTheGame.dimension == DIMENSION_3D) ? 1 : 0;
    temp2 = temp3 - temp4;
    temp = gTheGame.unk_9B50[arg1].b.frameY >> 2;
    gTheGame.unk_9B50[arg1].b.frameY = (temp - temp2) << 2;

    if (well->raise < 0) {
        gMain = GMAIN_394;
    }
}

INLINE void func_800387AC_usa(tetWell *well, s32 arg1) {
    s32 var_a0;

    // TODO: hardcoded number
    if (well->raise >= 0x32) {
        return;
    }

    var_a0 = wallsdownShake[well->raise];
    if (var_a0 == -0x10) {
        var_a0 = -0x1C;
    }
    gTheGame.unk_9A90[arg1].b.frameY = ((gTheGame.unk_9A90[arg1].b.frameY >> 2) - var_a0) << 2;
}

/**
 * Original name: SmallStars
 */
void SmallStars(void) {
    tetWell *well = &gTheGame.tetrisWell[0];
    s32 total = 0;
    s32 row;
    s32 col;
    s32 y;
    block_t *block;
    uObjSprite_t *s;
    DATA_INLINE_CONST u8 stars_TMEM[4][4] = {
        { 0x00, 0x02, 0x04, 0x06 },
        { 0x80, 0x82, 0x84, 0x86 },
        { 0x00, 0x02, 0x04, 0x06 },
        { 0x80, 0x82, 0x84, 0x86 },
    };

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        for (col = 0; col < MIN(BLOCK_LEN_B, TETWELL_OBJSPRITE_LEN_B); col++) {
            block = &well->block[row][col];
            s = &well->block_rect[row][col].s;

            y = s->objY >> 2;
            y += block->drop;
            if (total % 2 == 0) {
                if (y >= 0xD7) {
                    y = 0;
                }
            } else {
                if (y >= 0xF0) {
                    y = 0;
                }
            }
            s->objY = y << 2;

            block->frame_d++;
            if (block->frame_d >= 3) {
                block->frame_d = 0;
                block->frame_n++;

                if (block->frame_n >= ARRAY_COUNT(stars_TMEM[0])) {
                    block->frame_n = 0;
                }
            }
            total++;
            s->imageAdrs = stars_TMEM[block->currRow][block->frame_n];

            if (total >= 0x15) {
                return;
            }
        }
    }
}

/**
 * Original name: CircleStars
 */
nbool CircleStars(void) {
    s32 total = 0;
    s32 row;
    s32 col;
    s32 temp;
    s32 temp3;
    block_t *block;
    uObjSprite_t *s;
    DATA_INLINE_CONST u8 stars_TMEM[4][4] = {
        { 0x00, 0x02, 0x04, 0x06 },
        { 0x80, 0x82, 0x84, 0x86 },
        { 0x00, 0x02, 0x04, 0x06 },
        { 0x80, 0x82, 0x84, 0x86 },
    };
    DATA_INLINE_CONST f32 gSinTable[36] = {
        0.0f,      0.173648f,  0.34202f,   0.5f,       0.642787f,  0.766044f,  0.866025f,  0.939692f,  0.984808f,
        1.0f,      0.984808f,  0.939693f,  0.866026f,  0.766046f,  0.642789f,  0.500002f,  0.342022f,  0.173651f,
        0.000003f, -0.173645f, -0.342017f, -0.499997f, -0.642785f, -0.766042f, -0.866024f, -0.939691f, -0.984807f,
        -1.0f,     -0.984809f, -0.939694f, -0.866028f, -0.766047f, -0.642791f, -0.500004f, -0.342025f, -0.173653f,
    };
    DATA_INLINE_CONST f32 gCosTable[36] = {
        1.0f,       0.984808f,  0.939693f,  0.866026f,  0.766045f,  0.642788f,  0.500001f,  0.342021f,  0.173649f,
        0.000001f,  -0.173647f, -0.342019f, -0.499998f, -0.642786f, -0.766043f, -0.866024f, -0.939692f, -0.984807f,
        -1.0f,      -0.984808f, -0.939694f, -0.866027f, -0.766046f, -0.64279f,  -0.500003f, -0.342024f, -0.173652f,
        -0.000004f, 0.173644f,  0.342016f,  0.499996f,  0.642784f,  0.766041f,  0.866023f,  0.939691f,  0.984807f,
    };
    tetWell *well = &gTheGame.tetrisWell[1];

    // the usage of block_t on this function doesn't make much sense

    for (row = 0; row < BLOCK_LEN_ROWS; row++) {
        for (col = 0; col < MIN(BLOCK_LEN_B, TETWELL_OBJSPRITE_LEN_B); col++) {
            block = &well->block[row][col];
            s = &well->block_rect[row][col].s;

            block->state++;
            if ((block->sound < 0x25) && (block->state > BLOCKSTATE_0)) {
                block->state = BLOCKSTATE_0;
                block->sound += 2;
            }

            temp = block->sound * gCosTable[block->chain_flag / 10];
            temp3 = block->sound * gSinTable[block->chain_flag / 10];

            s->objX = (temp + block->drop) << 2;
            s->objY = (temp3 + block->delay) << 2;

            block->frame_d++;
            if (block->frame_d >= 3) {
                block->frame_d = 0;
                block->frame_n++;
                if (block->frame_n >= ARRAY_COUNT(stars_TMEM[0])) {
                    block->frame_n = 0;
                }
            }

            s->imageAdrs = stars_TMEM[block->currRow][block->frame_n];

            total++;
            if (total >= 0xC) {
                if ((block->sound < 0x25) || (block->state < 0x21)) {
                    return nfalse;
                }
                return ntrue;
            }
        }
    }

#if PRESERVE_UB
    // Not really a bug, since the early return inside the loop will always
    // trigger before finishing the loop
    return nfalse;
#endif
}

nbool func_80038B98_usa(s32 arg0) {
    s32 i;

    for (i = 0; i < arg0; i++) {
        if (gTheGame.controller[i].touch_button != 0) {
            if ((gSelection != SELECTION_96) || (gTheGame.cursorBlock[0].state == gTheGame.cursorBlock[1].state) ||
                (gTheGame.cursorBlock[0].state == 7) || (gTheGame.cursorBlock[1].state == 8)) {
                FadeOutSong(last_song_handle, 0x5A);
                FadeOutAllSFXs(0x1E);
            }

            PlaySE(SFX_INIT_TABLE, SFX_002);
            return ntrue;
        }
    }

    return nfalse;
}

/**
 * Original name: DoGameOverTryAgain
 */
s32 DoGameOverTryAgain(void) {
    u16 button = gTheGame.controller[0].touch_button;
    s32 *pos = &gTheGame.help.current_pos;

    if (button & L_JPAD) {
        if (*pos != 0) {
            PlaySE(SFX_INIT_TABLE, SFX_167);
        }
        *pos = 0;
    } else if (button & R_JPAD) {
        if (*pos != 1) {
            PlaySE(SFX_INIT_TABLE, SFX_168);
        }
        *pos = 1;
    } else if (button & (A_BUTTON | START_BUTTON)) {
        FadeOutSong(last_song_handle, 0x5A);
        FadeOutAllSFXs(0x1E);
        if (*pos == 0) {
            PlaySE(SFX_INIT_TABLE, SFX_005);
        } else {
            PlaySE(SFX_INIT_TABLE, SFX_006);
        }
        return -1;
    }

    if (gTheGame.dimension == DIMENSION_2D) {
        uObjBg *bg = &gTheGame.unk_9A90[2];

        if (*pos == 0) {
            bg->s.imageH = SIGNEND_1P_YESNO_HEIGHT << 2;
            bg->s.frameH = SIGNEND_1P_YESNO_HEIGHT << 2;

            if ((bg->s.imagePtr != (void *)endSegment->texs_1p.yesno_3) &&
                (bg->s.imagePtr != (void *)endSegment->texs_1p.yesno_4)) {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_3;
            }
            if (DoFlashDrawAlways()) {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_3;
            } else {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_4;
            }
        } else {
            bg->s.imageH = SIGNEND_1P_YESNO_HEIGHT << 2;
            bg->s.frameH = SIGNEND_1P_YESNO_HEIGHT << 2;

            if ((bg->s.imagePtr != (void *)endSegment->texs_1p.yesno_1) &&
                (bg->s.imagePtr != (void *)endSegment->texs_1p.yesno_2)) {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_1;
            }
            if (DoFlashDrawAlways()) {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_1;
            } else {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_2;
            }
        }
        osWritebackDCache(&gTheGame.unk_9A90[2], sizeof(uObjBg));
    } else {
        uObjBg *bg = &gTheGame.unk_9A90[2];

        if (*pos == 0) {
            bg->s.imageH = SIGNEND_1P_YESNO_HEIGHT << 2;
            bg->s.frameH = SIGNEND_1P_YESNO_HEIGHT << 2;

            if ((bg->s.imagePtr != (void *)endSegment->texs_1p.yesno_3) &&
                (bg->s.imagePtr != (void *)endSegment->texs_1p.yesno_4)) {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_3;
            }
            if (DoFlashDrawAlways()) {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_3;
            } else {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_4;
            }
        } else {
            bg->s.imageH = SIGNEND_1P_YESNO_HEIGHT << 2;
            bg->s.frameH = SIGNEND_1P_YESNO_HEIGHT << 2;

            if ((bg->s.imagePtr != (void *)endSegment->texs_1p.yesno_1) &&
                (bg->s.imagePtr != (void *)endSegment->texs_1p.yesno_2)) {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_1;
            }
            if (DoFlashDrawAlways()) {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_1;
            } else {
                bg->s.imagePtr = (void *)endSegment->texs_1p.yesno_2;
            }
        }
        osWritebackDCache(&gTheGame.unk_9A90[2], sizeof(uObjBg));
    }

    return 0;
}

void func_80038F84_usa(void) {
    s32 var_a0;
    s32 temp;

    if (gGameStatus & GAME_STATUS_FLAG_2) {
        return;
    }

    var_a0 = 0;
    for (temp = 0x19; temp < 0x3C; temp++) {
        if (st_Combo2[temp] != 0) {
            var_a0 += st_Combo2[temp];
            st_Combo2[temp] = 0;
        }
    }
    st_Combo2[0x19] = var_a0;

    var_a0 = 0;
    for (temp = 4; temp < 0x5A; temp++) {
        if (st_Chain2[temp] != 0) {
            var_a0 += st_Chain2[temp];
            st_Chain2[temp] = 0;
        }
    }

    st_Chain2[0x4] = var_a0;
}

#if VERSION_USA
// DoGameOverStat?
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003901C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", func_8003901C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", func_8003901C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", func_8003901C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003991C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", func_8003991C_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", func_8003991C_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", func_8003991C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80039A54_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", func_80039A54_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", func_80039A54_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", func_80039A54_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80039B78_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", func_80039B78_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", func_80039B78_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", func_80039B78_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_80039DB0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", func_80039DB0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", func_80039DB0_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", func_80039DB0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/end", RO_800C4B14_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/end", RO_800C4B24_usa);
#endif

#if VERSION_USA
// DoGameOverInput??
INCLUDE_ASM("asm/usa/nonmatchings/main/end", func_8003A0B8_usa);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/end", RO_800C4E64_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/end", RO_800C4E74_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", func_8003A0B8_usa);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/end", RO_800C3514_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/end", RO_800C3524_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", func_8003A0B8_usa);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/end", RO_800BA4D4_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/end", RO_800BA4E4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", func_8003A0B8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", Draw2DGameOver);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", Draw2DGameOver);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", Draw2DGameOver);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", Draw2DGameOver);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/end", Draw3DGameOver);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", Draw3DGameOver);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", Draw3DGameOver);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", Draw3DGameOver);
#endif

/**
 * Original name: DrawGameOver
 */
void DrawGameOver(struct_gInfo_unk_00068 *arg0) {
    if (gTheGame.dimension == DIMENSION_3D) {
        Draw3DGameOver(arg0);
    } else {
        Draw2DGameOver(arg0);
    }
}

#if VERSION_USA
#if 0
? PlaySE(? *, ?);                        /* extern */
? func_80005888_usa(?, ?, ?);                       /* extern */
? func_80005A08_usa(s32);                           /* extern */
? func_8003490C_usa();                              /* extern */
? func_8003524C_usa(Game *, s8 *);               /* extern */
? func_8003536C_usa(Game *, s8 *);               /* extern */
? func_800353F4_usa(Game *, s8 *);               /* extern */
? func_8003547C_usa(Game *, s8 *);               /* extern */
? AnimatePushKey(s8 *);                          /* extern */
? GameOverSmoke(Game *);                     /* extern */
? DeadBlocksShakeOne2D(Game *);                     /* extern */
? AllDeadBlocks(Game *);                     /* extern */
? AllDeadFaces(Game *);                     /* extern */
? func_80037900_usa(Game *);                     /* extern */
? GameOverSign(Game *, cursor_t *); /* extern */
s32 EndingExplosion(Game *);                   /* extern */
? func_80038018_usa(Game *, ?);                  /* extern */
? ChangeDeadFace(Game *);                     /* extern */
? func_8003837C_usa(Game *, ?);                  /* extern */
? func_8003853C_usa(Game *, ?);                  /* extern */
? SmallStars();                              /* extern */
s32 CircleStars();                         /* extern */
s32 func_8003901C_usa(Game *);                   /* extern */
? func_80039A54_usa(?);                             /* extern */
? func_80039B78_usa();                              /* extern */
s32 func_8003A0B8_usa();                            /* extern */
? SaveRom(u32);                           /* extern */
? func_8004ADD0_usa(?);                             /* extern */
? UpdateText(s32);                           /* extern */
? UpdateAnimation(Game *, ?, ?);               /* extern */
s32 func_8004FA2C_usa();                            /* extern */
? UpdateRecord2(s32, s32);                      /* extern */
? UpdatePlayerPuzzle(cursor_t *, s32, s32);  /* extern */
? UpdatePlayerStageClear(cursor_t *, s32, s32);  /* extern */
? UpdatePlayerCPU(s32, s32);                      /* extern */
? UpdateExplosion(Game *);                     /* extern */
? Init2DNewRow(Game *);                     /* extern */
? Init2DTetrisBlocks(Game *, ?);                  /* extern */
? Init2DIcons(Game *);                     /* extern */
? Init2DExplosion(Game *);                     /* extern */
? Init2DSmallStars(?);                             /* extern */
? Init2DCircleStars(?, ?);                          /* extern */
? Init2DGameOverSmoke(Game *, ?);                  /* extern */
extern u8 B_801C6C90_usa;
extern s32 gWhatever;
extern ? SFX_INIT_TABLE;
extern s32 D_800B65B0_usa;
extern ? wallsdownShake;

void DoGameOver2D(void) {
    ? var_a0;
    ? var_a0_5;
    ? var_a0_6;
    ? var_a0_7;
    ? var_a1;
    ? var_a1_2;
    ? var_a1_3;
    ? var_a1_4;
    ? var_a1_5;
    ? var_a1_6;
    ? var_a1_7;
    Game *var_a0_2;
    Game *var_v1_3;
    tetWell *var_a0_4;
    enum enum_gMain var_v1_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_7;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s3;
    s32 var_v0;
    s32 var_v1;
    s8 temp_a0_2;
    s8 var_v1_4;
    s8 var_v1_5;
    u32 temp_a0;
    u32 temp_a0_3;
    u32 temp_v1;
    u32 var_a0_3;

    var_v1 = 0xC0;
    gTheGame.unk_89C8[0x6F8] = 6;
    do {
        (&gTheGame.unk_90C8.unk_000[0x18])[var_v1] = -1;
        var_v1 += 0x20;
    } while (var_v1 < 0x8C0);
    UpdateText(-1);
    if ((gMain < 0x396) || (gWhatever < 6) || (func_8003A0B8_usa() == 0)) {
        var_s3 = 0;
        if (gTheGame.unk_9C08 == 1) {
            switch (gMain) {                        /* switch 1 */
                case GMAIN_38E:                     /* switch 1 */
                    if (gSelection != SELECTION_82) {
                        if (gSelection == SELECTION_AA) {
                            UpdatePlayerStageClear(gTheGame.unk_8860, gTheGame.help.selection[0xC], gTheGame.help.selection[0x10]);
                        }
                    } else {
                        UpdatePlayerPuzzle(gTheGame.unk_8860, gTheGame.help.selection[8], gTheGame.help.selection[0xC]);
                    }
                    func_8003490C_usa();
                    switch (gSelection) {           /* switch 3; irregular */
                        case SELECTION_8C:                  /* switch 3 */
                        case SELECTION_AA:                  /* switch 3 */
                        case SELECTION_BE:                  /* switch 3 */
                            gTheGame.unk_9988[0x1C0] = 0;
                            gTheGame.unk_8860[0].unk_C = 0;
                            break;
                        case SELECTION_78:                  /* switch 3 */
                            /* fallthrough */
                        case SELECTION_82:                  /* switch 3 */
                            gTheGame.unk_9988[0x1C0] = -1;
                            break;
                    }
                    gGameStatus &= ~0x20;
                    Init2DIcons(&gTheGame);
                    Init2DExplosion(&gTheGame);
                    gTheGame.help.selection[4] = 0;
                    gTheGame.unk_89C8[0x6E8] = -0x280;
                    gTheGame.unk_89C8[0x6D0] = -0x280;
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        Init2DGameOverSmoke(&gTheGame, 0);
                    }
                    func_80039A54_usa(0);
                    if (gSelection == SELECTION_8C) {
                        if (gTheGame.unk_43AC < 0x2710) {

                        } else {
                            goto block_29;
                        }
                    } else if ((gSelection == SELECTION_BE) && (gTheGame.unk_8860[0].unk_0 != 8)) {
block_29:
                        func_80039A54_usa(-1);
                    }
                    gMain = 0x38F;
                    gTheGame.unk_43FC = 0x25;
                    gWhatever = 0;
                    D_800B65B0_usa = 0;
                    gTheGame.unk_43EC = 0;
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        PlaySE(&SFX_INIT_TABLE, 0xA0);
                        if (gSelection >= SELECTION_83) {
                            var_a1 = 0x175;
                            goto block_39;
                        }
                    } else {
                        var_a1 = 0x174;
                        if (gSelection != SELECTION_BE) {
                            PlaySE(&SFX_INIT_TABLE, 0xA1);
                            if (gTheGame.help.selection[8] != 5) {
                                if (gTheGame.help.selection[0x10] == 5) {
                                    var_a1 = 0x9F;
                                } else {
                                    var_a1 = 0x9E;
                                }
                                goto block_39;
                            }
                        } else {
block_39:
                            PlaySE(&SFX_INIT_TABLE, var_a1);
                        }
                    }
                    FadeOutSong(last_song_handle, 0x3C);
                    break;
                case 0x38F:                         /* switch 1 */
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        GameOverSmoke(&gTheGame);
                        DeadBlocksShakeOne2D(&gTheGame);
                        AllDeadBlocks(&gTheGame);
                    } else {
                        AllDeadFaces(&gTheGame);
                    }
                    if (gMain == 0x390) {
                        gTheGame.unk_43EC = 0x28;
                    }
                    break;
                case 0x390:                         /* switch 1 */
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        func_80037900_usa(&gTheGame);
                        var_v1_2 = gMain;
                        var_v0 = 0x391;
                        goto block_50;
                    }
                    temp_v0 = gTheGame.unk_43EC - 1;
                    gTheGame.unk_43EC = temp_v0;
                    if (temp_v0 == 0) {
                        var_v0 = gSelection;
                        gMain = GMAIN_391;
                        var_v1_2 = 0xBE;
block_50:
                        if (var_v0 == var_v1_2) {
                            Init2DTetrisBlocks(&gTheGame, 0);
                            Init2DNewRow(&gTheGame);
                        }
                    }
                    break;
                case 0x391:                         /* switch 1 */
                    temp_v0_2 = gWhatever;
                    if (temp_v0_2 == 0) {
                        if ((gSelection != SELECTION_82) || (gTheGame.help.selection[8] != 0)) {
                            SaveRom();
                        }
                    }
                    gWhatever = temp_v0_2 + 1;
                    if (((gSelection == SELECTION_8C) | (gSelection == SELECTION_BE)) != 0) {
                        Init2DIcons(&gTheGame);
                        var_s0 = func_8003901C_usa(&gTheGame);
                        if (gWhatever == 0x55) {
                            var_a0 = -1;
                            if (func_8004FA2C_usa() != 0) {
                                goto block_62;
                            }
                        } else {
                            var_a0 = 0;
                            if (gWhatever >= 0x56) {
block_62:
                                func_8004ADD0_usa(var_a0);
                            }
                        }
                        if (gWhatever == 0x5A) {
                            if (gSelection == SELECTION_8C) {
                                if (gTheGame.unk_43AC >= 0x2710) {
                                    PlayMIDI(&BGM_INIT_TABLE, 0x46, 0, 2);
                                    PlaySE(&SFX_INIT_TABLE, 0x7D);
                                } else {
                                    goto block_72;
                                }
                            } else if (gSelection == SELECTION_BE) {
                                if (gTheGame.unk_8860[0].unk_0 != 8) {
                                    if (gTheGame.unk_43AC >= 0x2710) {
                                        PlayMIDI(&BGM_INIT_TABLE, 0x46, 0, 2);
                                        PlaySE(&SFX_INIT_TABLE, 0x80);
                                    } else {
                                        var_a1_2 = 0x45;
                                        goto block_73;
                                    }
                                } else {
block_72:
                                    var_a1_2 = 0x42;
block_73:
                                    PlayMIDI(&BGM_INIT_TABLE, var_a1_2, 0, 1);
                                }
                            }
                        }
                    } else {
                        var_s0 = 0;
                        if (gTheGame.unk_8860[0].unk_0 == 7) {
                            var_s0 = EndingExplosion(&gTheGame);
                            UpdateExplosion(&gTheGame);
                        }
                    }
                    if ((var_s0 == 0) && (gWhatever >= 0x5B)) {
                        gMain = GMAIN_392;
                    }
                    if (gMain == GMAIN_392) {
                        Init2DTetrisBlocks(&gTheGame, 0);
                        Init2DNewRow(&gTheGame);
                        Init2DIcons(&gTheGame);
                        if ((gSelection >= SELECTION_83) || (gTheGame.unk_8860[0].unk_0 != 7)) {
                            if ((gSelection == SELECTION_AA) && (gTheGame.unk_8860[0].unk_0 == 7)) {
                                goto block_85;
                            }
                            gTheGame.unk_43FC = 0x59;
                        } else {
block_85:
                            gTheGame.unk_43FC = 0x50;
                        }
                    }
                    break;
                case 0x392:                         /* switch 1 */
                    GameOverSign(&gTheGame, gTheGame.unk_8860);
                    if (gMain == 0x393) {
                        gTheGame.help.selection[4] = 0;
                        gTheGame.unk_43EC = 0;
                    }
                    break;
                case 0x393:                         /* switch 1 */
                    gTheGame.unk_9988[0x13C] = 0x26CU;
                    gTheGame.unk_9988[0x164] = 0x2D0;
                    if (gTheGame.unk_8860[0].unk_0 == 7) {
                        if (((gSelection < SELECTION_83) | (gSelection == SELECTION_AA)) != 0) {
                            PlayMIDI(&BGM_INIT_TABLE, 0x45, 0, 1);
                            if (gSelection == SELECTION_82) {
                                func_80005A08_usa(gTheGame.help.selection[8]);
                            }
                        }
                    } else if ((gSelection != SELECTION_8C) & (gSelection != SELECTION_BE)) {
                        if (func_8004FA2C_usa() != 0) {
                            func_8004ADD0_usa(-1);
                        }
                        PlayMIDI(&BGM_INIT_TABLE, 0x42, 0, 1);
                        if (gSelection == SELECTION_AA) {
                            if (gTheGame.help.selection[8] == 5) {
                                if (gTheGame.help.selection[0xC] == 3) {
                                    PlaySE(&SFX_INIT_TABLE, 0x81);
                                } else {
                                    goto block_101;
                                }
                            } else {
block_101:
                                func_80005888_usa(0, 2, 2);
                            }
                        }
                    }
                    gWhatever = 0;
                    gMain = 0x396;
                    break;
                case 0x396:                         /* switch 1 */
                    func_8003524C_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                    func_80039B78_usa();
                    func_8004ADD0_usa(0);
                    switch (gSelection) {           /* switch 4; irregular */
                        case SELECTION_8C:                  /* switch 4 */
                            if (gTheGame.help.selection[8] != 0) {
                                switch (gSelection) { /* switch 5; irregular */
                                    case 0xAA:      /* switch 4 */
                                    case 0xAA:      /* switch 5 */
                                        if (gTheGame.unk_8860[0].unk_0 != 7) {
                                            if (((gSelection == SELECTION_82) && (gTheGame.unk_8860[0].unk_0 == 7)) || (gSelection == SELECTION_78)) {
                                                goto block_111;
                                            }
                                        } else {
                                            goto block_111;
                                        }
                                        break;
                                }
                            } else {
                            case 0x78:              /* switch 4 */
                            case 0x78:              /* switch 5 */
block_111:
                                AnimatePushKey(&gTheGame.unk_9988[0x130]);
                            }
                            break;
                    }
                    gWhatever += 1;
                    break;
            }
            var_a0_2 = &gTheGame;
            if (gTheGame.unk_9C0C == 1) {
                var_a1_3 = 0;
                goto block_270;
            }
        } else {
            temp_v1 = gTheGame.unk_8860[0].unk_0;
            var_a0_3 = gTheGame.unk_8860[1];
            var_s1 = 0;
            if (temp_v1 != var_a0_3) {
                if (temp_v1 != 8) {
                    if (var_a0_3 != 7) {
                        var_s3 = -1;
                    } else {
                        goto block_120;
                    }
                } else {
block_120:
                    var_s1 = -1;
                }
            }
            switch (gMain) {                        /* switch 2 */
                case GMAIN_38E:                     /* switch 2 */
                    if (var_s3 != var_s1) {
                        if (var_s3 != 0) {
                            gTheGame.unk_4404 = (s32) (gTheGame.unk_4404 + 1);
                        } else if (var_s1 != 0) {
                            gTheGame.tetrisWell[1].unk_4404 = (s32) (gTheGame.tetrisWell[1].unk_4404 + 1);
                        }
                    }
                    if ((gSelection == SELECTION_96) & var_s3) {
                        UpdatePlayerCPU(gTheGame.help.selection[8], gTheGame.help.selection[0xC]);
                    } else {
                        temp_a0 = (u32) (gGameStatus & 0xF00) >> 8;
                        if ((gTheGame.unk_4404 == temp_a0) || (gTheGame.tetrisWell[1].unk_4404 == temp_a0)) {
                            UpdateRecord2(var_s3, var_s1);
                        }
                    }
                    var_s0_2 = 0;
                    func_8003490C_usa();
                    gOverflow = 0;
                    Init2DIcons(&gTheGame);
                    Init2DIcons((Game *) &gTheGame.tetrisWell[1]);
                    Init2DExplosion(&gTheGame);
                    Init2DExplosion((Game *) &gTheGame.tetrisWell[1]);
                    var_a0_4 = &gTheGame.tetrisWell[1];
                    var_v1_3 = &gTheGame;
                    gTheGame.help.selection[4] = 0;
                    do {
                        if (var_v1_3->unk_2520 < 4) {
                            var_v1_3->unk_2520 = 0;
                        }
                        if (var_a0_4->unk_2520 < 4) {
                            var_a0_4->unk_2520 = 0;
                        }
                        var_v1_3->unk_2540 = 0;
                        var_a0_4->unk_2540 = 0;
                        var_a0_4 += 0x48;
                        var_s0_2 += 1;
                        var_v1_3 += 0x48;
                    } while (var_s0_2 < 0x14);
                    gTheGame.unk_9988[0x1D6] = 0x374;
                    gTheGame.unk_9988[0x1FE] = 0x374;
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        Init2DGameOverSmoke(&gTheGame, 0);
                    }
                    if (gTheGame.unk_8860[1] == 8) {
                        Init2DGameOverSmoke((Game *) &gTheGame.tetrisWell[1], 1);
                    }
                    gMain = 0x38F;
                    gWhatever = 0;
                    gTheGame.unk_43EC = 0;
                    gTheGame.tetrisWell[1].unk_43EC = 0;
                    if (gTheGame.unk_8860[0].unk_0 == 8) {
                        gTheGame.unk_43FC = 0x27;
                    }
                    if (gTheGame.unk_8860[1] == 8) {
                        gTheGame.tetrisWell[1].unk_43FC = 0x27;
                    }
                    if (gSelection == SELECTION_96) {
                        var_a1_4 = 0x175;
                        if (((var_s3 == var_s1) | (var_s1 != 0)) != 0) {

                        } else {
                            goto block_152;
                        }
                    } else {
                        var_a1_4 = 0x175;
                        if (var_s3 == var_s1) {

                        } else {
block_152:
                            var_a1_4 = 0x174;
                        }
                    }
                    PlaySE(&SFX_INIT_TABLE, var_a1_4);
                    FadeOutSong(last_song_handle, 0x3C);
                    break;
                case 0x38F:                         /* switch 2 */
                    if (var_s3 == 0) {
                        GameOverSmoke(&gTheGame);
                        func_80038018_usa(&gTheGame, 0);
                        ChangeDeadFace(&gTheGame);
                    }
                    if (var_s1 == 0) {
                        GameOverSmoke((Game *) &gTheGame.tetrisWell[1]);
                        func_80038018_usa((Game *) &gTheGame.tetrisWell[1], 1);
                        ChangeDeadFace((Game *) &gTheGame.tetrisWell[1]);
                    }
                    break;
                case 0x390:                         /* switch 2 */
                    temp_v0_3 = gWhatever;
                    if (temp_v0_3 == 0) {
                        if (gSelection != SELECTION_96) {
                            var_a0_3 = (u32) (gGameStatus & 0xF00) >> 8;
                            if ((gTheGame.unk_4404 != var_a0_3) && (gTheGame.tetrisWell[1].unk_4404 != var_a0_3)) {

                            } else {
                                goto block_164;
                            }
                        } else if (-var_s3 != 0) {
block_164:
                            SaveRom(var_a0_3);
                        }
                    }
                    gWhatever = temp_v0_3 + 1;
                    if (gTheGame.unk_43EC != 0) {
                        gTheGame.unk_43EC = (s32) (gTheGame.unk_43EC - 1);
                    } else {
                        temp_v0_4 = gTheGame.tetrisWell[1].unk_43EC;
                        if (temp_v0_4 != 0) {
                            gTheGame.tetrisWell[1].unk_43EC = (s32) (temp_v0_4 - 1);
                        } else {
                            gMain = GMAIN_391;
                            if (var_s3 != 0) {
                                gTheGame.unk_43FC = 0x32;
                            }
                            if (var_s1 != 0) {
                                gTheGame.tetrisWell[1].unk_43FC = 0x32;
                            }
                        }
                    }
                    break;
                case 0x391:                         /* switch 2 */
                    if ((var_s3 == 0) & (var_s1 == 0)) {
                        gMain = GMAIN_392;
                    }
                    if (var_s3 != 0) {
                        func_8003837C_usa(&gTheGame, 0);
                    }
                    if (var_s1 != 0) {
                        func_8003837C_usa((Game *) &gTheGame.tetrisWell[1], 1);
                    }
                    if (gMain == GMAIN_392) {
                        if (var_s3 == 0) {
                            gTheGame.unk_43FC = 0x60;
                        }
                        if (var_s1 == 0) {
                            gTheGame.tetrisWell[1].unk_43FC = 0x60;
                        }
                    }
                    break;
                case 0x392:                         /* switch 2 */
                    if (var_s3 == 0) {
                        func_8003853C_usa(&gTheGame, 0);
                    }
                    if (var_s1 == 0) {
                        func_8003853C_usa((Game *) &gTheGame.tetrisWell[1], 1);
                    }
                    if (gMain == 0x393) {
                        gTheGame.unk_43FC = 0x36;
                        gTheGame.tetrisWell[1].unk_43FC = 0x36;
                        gTheGame.unk_43EC = 0x3C;
                        gTheGame.tetrisWell[1].unk_43EC = 0x3C;
                    }
                    break;
                case 0x393:                         /* switch 2 */
                    if (gTheGame.unk_43EC != 0) {
                        gTheGame.unk_43EC = (s32) (gTheGame.unk_43EC - 1);
                    } else {
                        if (gTheGame.unk_43FC == 0x36) {
                            PlaySE(&SFX_INIT_TABLE, 0xA4);
                        }
                        temp_a0_2 = *(&wallsdownShake + gTheGame.unk_43FC);
                        gTheGame.unk_43FC = (s32) (gTheGame.unk_43FC - 1);
                        gTheGame.unk_9988[0x1D4] = (u16) ((((s32) (gTheGame.unk_9988[0x1D4] << 0x10) >> 0x12) - (temp_a0_2 - (gTheGame.unk_9C0C == 2))) * 4);
                        if (gTheGame.unk_43FC < 0) {
                            gMain = GMAIN_394;
                        }
                    }
                    temp_v0_5 = gTheGame.tetrisWell[1].unk_43EC;
                    if (temp_v0_5 != 0) {
                        gTheGame.tetrisWell[1].unk_43EC = (s32) (temp_v0_5 - 1);
                    } else {
                        if (gTheGame.tetrisWell[1].unk_43FC == 0x36) {
                            PlaySE(&SFX_INIT_TABLE, 0xA4);
                        }
                        temp_v0_6 = gTheGame.tetrisWell[1].unk_43FC;
                        gTheGame.tetrisWell[1].unk_43FC = (s32) (temp_v0_6 - 1);
                        gTheGame.unk_9988[0x1FC] = (u16) ((((s32) (gTheGame.unk_9988[0x1FC] << 0x10) >> 0x12) - (*(&wallsdownShake + temp_v0_6) - (gTheGame.unk_9C0C == 2))) * 4);
                        if (gTheGame.tetrisWell[1].unk_43FC < 0) {
                            gMain = GMAIN_394;
                        }
                    }
                    if (gTheGame.unk_43FC < 0x32) {
                        var_v1_4 = *(&wallsdownShake + gTheGame.unk_43FC);
                        if (var_v1_4 == -0x10) {
                            var_v1_4 = -0x1C;
                        }
                        gTheGame.unk_9988[0x114] = (u16) ((((s32) (gTheGame.unk_9988[0x114] << 0x10) >> 0x12) - var_v1_4) * 4);
                    }
                    temp_v1_2 = gTheGame.tetrisWell[1].unk_43FC;
                    if (temp_v1_2 < 0x32) {
                        var_v1_5 = *(&wallsdownShake + temp_v1_2);
                        if (var_v1_5 == -0x10) {
                            var_v1_5 = -0x1C;
                        }
                        gTheGame.unk_9988[0x13C] = (u16) ((((s32) (gTheGame.unk_9988[0x13C] << 0x10) >> 0x12) - var_v1_5) * 4);
                    }
                    if ((((gSelection == SELECTION_96) & var_s3) || (((gSelection == SELECTION_A0) | (gSelection == SELECTION_B4)) != 0) || (gSelection == SELECTION_C8)) && (gTheGame.unk_43EC == 0) && (gTheGame.unk_43FC == 0x29)) {
                        if (B_801C6C90_usa != 0x10) {
                            PlaySE(&SFX_INIT_TABLE, 0x17A);
                        } else {
block_267:
                            PlayMIDI(&BGM_INIT_TABLE, 0x45, 0, 1);
                        }
                    }
                    break;
                case 0x394:                         /* switch 2 */
                    gTheGame.unk_9988[0x164] = 0x30C;
                    gTheGame.unk_9988[0x18C] = 0x30C;
                    if (gSelection != SELECTION_96) {
                        temp_a0_3 = (u32) (gGameStatus & 0xF00) >> 8;
                        if (gTheGame.tetrisWell[0].unk_43BC[0x48] == temp_a0_3) {
                            temp_v1_3 = gTheGame.help.selection[8] + 1;
                            gTheGame.unk_4420 = (s32) (gTheGame.unk_4420 + 1);
                            gTheGame.help.selection[8] = temp_v1_3;
                            if (temp_v1_3 >= 0x64) {
                                gTheGame.unk_4420 = 0x63;
                                gTheGame.help.selection[8] = 0x63;
                            }
                        } else if (gTheGame.tetrisWell[1].unk_43BC[0x48] == temp_a0_3) {
                            temp_v1_4 = gTheGame.help.selection[0x18] + 1;
                            gTheGame.tetrisWell[1].unk_4420 = (s32) (gTheGame.tetrisWell[1].unk_4420 + 1);
                            gTheGame.help.selection[0x18] = temp_v1_4;
                            if (temp_v1_4 >= 0x64) {
                                gTheGame.tetrisWell[1].unk_4420 = 0x63;
                                gTheGame.help.selection[0x18] = 0x63;
                            }
                        }
                    }
                    if (var_s3 != 0) {
                        if (gSelection == SELECTION_96) {
                            var_a0_5 = 0;
                            var_a1_5 = 0;
                        } else if (gTheGame.unk_4404 == 1) {
                            var_a0_5 = 1;
                            var_a1_5 = 0;
                        } else {
                            var_a0_5 = 1;
                            if (gTheGame.unk_4404 == 2) {
                                var_a1_5 = 1;
                            } else {
                                var_a1_5 = 2;
                            }
                        }
                        Init2DCircleStars(var_a0_5, var_a1_5);
                        func_80005888_usa(0, 1, 2);
                    }
                    if (var_s1 != 0) {
                        if (gSelection == SELECTION_96) {
                            var_a0_6 = 1;
                            var_a1_6 = 0;
                        } else {
                            temp_v1_5 = gTheGame.tetrisWell[1].unk_4404;
                            if (temp_v1_5 == 1) {
                                var_a0_6 = 0;
                                var_a1_6 = 0;
                            } else {
                                var_a0_6 = 0;
                                if (temp_v1_5 == 2) {
                                    var_a1_6 = 1;
                                } else {
                                    var_a1_6 = 2;
                                }
                            }
                        }
                        Init2DCircleStars(var_a0_6, var_a1_6);
                        func_80005888_usa(0, 2, 2);
                        if (gSelection == SELECTION_96) {
                            var_a1_7 = 0x42;
                            if (B_801C6C90_usa != 0x10) {

                            } else {
                                var_a1_7 = 0x20;
                            }
                            PlayMIDI(&BGM_INIT_TABLE, var_a1_7, 0, 1);
                        }
                    }
                    gTheGame.unk_43FC = -1;
                    gTheGame.tetrisWell[1].unk_43FC = -1;
                    gTheGame.unk_43EC = 0;
                    gTheGame.tetrisWell[1].unk_43EC = 0;
                    gWhatever = 0;
                    var_a0_7 = 0;
                    if ((var_s3 != 0) || (var_a0_7 = 1, (var_s1 != 0))) {
                        Init2DSmallStars(var_a0_7);
                    }
                    if (var_s3 != var_s1) {
                        gMain = 0x395;
                    } else {
block_254:
                        gMain = 0x396;
                    }
                    break;
                case 0x395:                         /* switch 2 */
                    if (CircleStars() != 0) {
                        goto block_254;
                    }
                    break;
                case 0x396:                         /* switch 2 */
                    if (var_s3 == var_s1) {
                        func_8003547C_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                        func_8003547C_usa((Game *) &gTheGame.tetrisWell[1], &gTheGame.unk_9988[0x108] + 0x28);
                    } else {
                        if (var_s3 != 0) {
                            func_8003536C_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                        } else {
                            func_800353F4_usa(&gTheGame, &gTheGame.unk_9988[0x108]);
                        }
                        if (var_s1 != 0) {
                            func_8003536C_usa((Game *) &gTheGame.tetrisWell[1], &gTheGame.unk_9988[0x130]);
                        } else {
                            func_800353F4_usa((Game *) &gTheGame.tetrisWell[1], &gTheGame.unk_9988[0x130]);
                        }
                        SmallStars();
                    }
                    AnimatePushKey(&gTheGame.unk_9988[0x158]);
                    AnimatePushKey(&gTheGame.unk_9988[0x158] + 0x28);
                    temp_v0_7 = gWhatever + 1;
                    gWhatever = temp_v0_7;
                    if ((temp_v0_7 == 0xDC) && ((gSelection != SELECTION_96) || ((var_s3 != 0) & (var_s1 == 0)))) {
                        goto block_267;
                    }
                    break;
            }
            if (gTheGame.unk_9C0C == 1) {
                UpdateAnimation(&gTheGame, 0, 0);
                var_a0_2 = (Game *) &gTheGame.tetrisWell[1];
                var_a1_3 = 1;
block_270:
                UpdateAnimation(var_a0_2, var_a1_3, 0);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/end", DoGameOver2D);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/end", DoGameOver2D);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/end", DoGameOver2D);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/end", DoGameOver2D);
#endif

/**
 * Original name: DoGameOver3D
 */
void DoGameOver3D(void) {
    s32 count;
    s32 temp;
    nbool win1;
    nbool win2;
    tetWell *well1;
    tetWell *well2;
    cursor_t *cursor1;
    cursor_t *cursor2;

    gTheGame.currentText = 6;
    for (count = gTheGame.currentText; count < DRAWTEXT_COUNT; count++) {
        gTheGame.drawText[count].texture = -1;
    }

    UpdateText();

    well1 = &gTheGame.tetrisWell[0];
    well2 = &gTheGame.tetrisWell[1];
    cursor1 = &gTheGame.cursorBlock[0];
    cursor2 = &gTheGame.cursorBlock[1];

    if ((gMain >= GMAIN_395) && (gWhatever >= 6) && (func_8003A0B8_usa() != 0)) {
        return;
    }

    if (gTheGame.totalPlayer == 1) {
        switch (gMain) {
            case GMAIN_38E:
                switch (gSelection) {
                    case SELECTION_AA:
                        UpdatePlayerStageClear(cursor1, gTheGame.menu[0].stage, gTheGame.menu[0].speed);
                        break;

                    case SELECTION_82:
                        UpdatePlayerPuzzle(cursor1, gTheGame.menu[0].game, gTheGame.menu[0].stage);
                        break;

                    default:
                        break;
                }

                LoadGameOver3D();
                InitFlic();

                switch (gSelection) {
                    case SELECTION_8C:
                    case SELECTION_AA:
                    case SELECTION_BE:
                        gTheGame.miscToggle = 0;
                        cursor1->extra_wait = 0;
                        break;

                    case SELECTION_78:
                    case SELECTION_82:
                        gTheGame.miscToggle = -1;
                        break;

                    default:
                        break;
                }

                gGameStatus &= ~GAME_STATUS_FLAG_20;
                Init3DIcons(well1);
                Init3DExplosion(well1);
                gTheGame.help.current_pos = 0;
                gTheGame.gSPRITE[9].s.objY = -(160 << 2);
                gTheGame.gSPRITE[8].s.objY = -(160 << 2);
                if (cursor1->state == 8) {
                    Init3DGameOverSmoke(well1, 0);
                }

                func_80039A54_usa(0);
                if (gSelection == SELECTION_8C) {
                    if (well1->score >= 10000) {
                        func_80039A54_usa(-1);
                    }
                } else if (gSelection == SELECTION_BE) {
                    if (cursor1->state != 8) {
                        func_80039A54_usa(-1);
                    }
                }

                gMain = GMAIN_38F;
                well1->raise = 0x25;
                gWhatever = 0;
                D_800B65B0_usa = 0;
                well1->timer = 0;
                if (cursor1->state == 8) {
                    PlaySE(SFX_INIT_TABLE, SFX_0A0);
                    if (gSelection != SELECTION_82) {
                        PlaySE(SFX_INIT_TABLE, SFX_175);
                    }
                } else if (gSelection != SELECTION_BE) {
                    PlaySE(SFX_INIT_TABLE, SFX_0A1);
                    if (gTheGame.menu[0].game != 5) {
                        if (gTheGame.menu[0].speed == 5) {
                            PlaySE(SFX_INIT_TABLE, SFX_09F);
                        } else {
                            PlaySE(SFX_INIT_TABLE, SFX_09E);
                        }
                    }
                } else {
                    PlaySE(SFX_INIT_TABLE, SFX_174);
                }

                FadeOutSong(last_song_handle, 0x3C);
                break;

            case GMAIN_38F:
                if (cursor1->state == 8) {
                    GameOverSmoke(well1);
                    if (well1->raise >= 0) {
                        count = dead1Shake[well1->raise];
                        well1->raise--;
                        well1->translation += (f32)count / DOUBLE_LITERAL(250.0);
                    }
                    AllDeadBlocks(well1);
                } else {
                    AllDeadFaces(well1);
                }

                if (gMain == GMAIN_390) {
                    well1->timer = 40;
                }
                break;

            case GMAIN_390:
                if (cursor1->state == 8) {
                    KillRow3D(well1, cursor1);
                } else {
                    well1->timer--;
                    if (well1->timer == 0) {
                        gMain = GMAIN_391;
                        if (gSelection == SELECTION_BE) {
                            Init3DTetrisBlocks(well1, 0);
                            Init3DNewRow(well1);
                        }
                    }
                }
                break;

            case GMAIN_391:
                if (gWhatever == 0) {
                    SaveRom();
                }

                gWhatever++;
                if (well1->timer != 0) {
                    well1->timer--;
                } else {
                    if ((gSelection == SELECTION_8C) || (gSelection == SELECTION_BE)) {
                        Init3DIcons(well1);
                        count = func_8003901C_usa(well1);

                        if (gWhatever == 0x55) {
                            if (func_8004FA2C_usa() != 0) {
                                func_8004ADD0_usa(-1);
                            }
                        } else {
                            if (gWhatever >= 0x56) {
                                func_8004ADD0_usa(0);
                            }
                        }

                        if (gWhatever == 0x5A) {
                            if (gSelection == SELECTION_8C) {
                                if (well1->score >= 10000) {
                                    PlayMIDI(BGM_INIT_TABLE, 0x46, 0, 2);
                                    PlaySE(SFX_INIT_TABLE, SFX_07D);
                                } else {
                                    PlayMIDI(BGM_INIT_TABLE, 0x42, 0, 1);
                                }
                            } else if (gSelection == SELECTION_BE) {
                                if (cursor1->state != 8) {
                                    if (well1->score >= 0x2710) {
                                        PlayMIDI(BGM_INIT_TABLE, 0x46, 0, 2);
                                        PlaySE(SFX_INIT_TABLE, SFX_080);
                                    } else {
                                        PlayMIDI(BGM_INIT_TABLE, 0x45, 0, 1);
                                    }
                                } else {
                                    PlayMIDI(BGM_INIT_TABLE, 0x42, 0, 1);
                                }
                            }
                        }
                    } else if (cursor1->state == 7) {
                        count = EndingExplosion(well1);
                        UpdateExplosion(well1);
                    } else {
                        count = 0;
                    }

                    if ((count == 0) && (gWhatever >= 0x5B)) {
                        gMain = GMAIN_392;
                    }

                    if (gMain == GMAIN_392) {
                        Init3DTetrisBlocks(well1, 0);
                        Init3DNewRow(well1);
                        Init3DIcons(well1);

                        if (((gSelection < 0x83) && (cursor1->state == 7))) {
                            well1->raise = 0x50;
                        } else if ((gSelection == SELECTION_AA) && (cursor1->state == 7)) {
                            well1->raise = 0x50;
                        } else {
                            well1->raise = 0x59;
                        }
                    }
                }
                break;

            case GMAIN_392:
                GameOverSign(well1, cursor1);

                if (gMain == GMAIN_393) {
                    gTheGame.help.current_pos = 0;
                    well1->timer = 0;
                }
                break;

            case GMAIN_393:
                gTheGame.unk_9A90[1].b.frameY = 155 << 2;
                gTheGame.unk_9A90[2].b.frameY = 180 << 2;

                if (cursor1->state == 7) {
                    if ((gSelection < SELECTION_83) || (gSelection == SELECTION_AA)) {
                        PlayMIDI(BGM_INIT_TABLE, 0x45, 0, 1);
                        if (gSelection == SELECTION_82) {
                            func_80005A08_usa(gTheGame.menu[0].game);
                        }
                    }
                } else if ((gSelection != SELECTION_8C) && (gSelection != SELECTION_BE)) {
                    if (func_8004FA2C_usa() != 0) {
                        func_8004ADD0_usa(-1);
                    }

                    PlayMIDI(BGM_INIT_TABLE, 0x42, 0, 1);
                    if (gSelection == SELECTION_AA) {
                        if (gTheGame.menu[0].game == 5) {
                            if (gTheGame.menu[0].stage == 3) {
                                PlaySE(SFX_INIT_TABLE, SFX_081);
                            } else {
                                func_80005888_usa(0, 2, 2);
                            }
                        } else {
                            func_80005888_usa(0, 2, 2);
                        }
                    }
                }

                gWhatever = 0;
                gMain = GMAIN_395;
                break;

            case GMAIN_395:
                AnimateGameOver3D(well1, &gTheGame.unk_9A90[0]);
                func_80039B78_usa();
                func_8004ADD0_usa(0);
                if ((gSelection == SELECTION_AA) || (gSelection == SELECTION_82)) {
                    if (cursor1->state == 7) {
                        AnimatePushKey(&gTheGame.unk_9A90[1]);
                    }
                }
                gWhatever++;
                break;

            default:
                break;
        }

        Check3DVisibleBlocks(well1, cursor1);
    } else {
        win1 = nfalse;
        win2 = nfalse;
        if (cursor1->state != cursor2->state) {
            if ((cursor1->state == 8) || (cursor2->state == 7)) {
                win2 = ntrue;
            } else {
                win1 = ntrue;
            }
        }

        switch (gMain) {
            case GMAIN_38E:
                if (win1 != win2) {
                    if (win1) {
                        well1->win++;
                    } else if (win2) {
                        well2->win++;
                    }
                }

                temp = GAME_STATUS_GET_WIN_RECORD(gGameStatus);
                if ((well1->win == temp) || (well2->win == temp)) {
                    UpdateRecord2(win1, win2);
                }

                LoadGameOver3D();
                InitFlic();
                Init3DIcons(well1);
                Init3DIcons(well2);
                Init3DExplosion(well1);
                Init3DExplosion(well2);
                gTheGame.help.current_pos = 0;

                for (count = 0; count < ATTACK_COUNT; count++) {
                    if (well1->attack[count].state < ATTACKSTATE_4) {
                        well1->attack[count].state = ATTACKSTATE_0;
                    }
                    if (well2->attack[count].state < ATTACKSTATE_4) {
                        well2->attack[count].state = ATTACKSTATE_0;
                    }

                    well1->attack[count].expression = 0;
                    well2->attack[count].expression = 0;
                }

                if (cursor1->state == 8) {
                    Init3DGameOverSmoke(well1, 0);
                }
                if (cursor2->state == 8) {
                    Init3DGameOverSmoke(well2, 1);
                }

                gMain = GMAIN_38F;
                gWhatever = 0;
                well1->timer = 0;
                well2->timer = 0;
                if (cursor1->state == 8) {
                    well1->raise = 0x27;
                }
                if (cursor2->state == 8) {
                    well2->raise = 0x27;
                }
                gTheGame.unk_9B50[0].b.frameY = 0x37C;
                gTheGame.unk_9B50[1].b.frameY = 0x37C;

                if (win1 == win2) {
                    PlaySE(SFX_INIT_TABLE, SFX_175);
                } else {
                    PlaySE(SFX_INIT_TABLE, SFX_174);
                }

                FadeOutSong(last_song_handle, 0x3C);
                break;

            case GMAIN_38F:
                if (!win1) {
                    GameOverSmoke(well1);
                    if (well1->raise >= 0) {
                        count = dead2Shake[well1->raise];
                        well1->translation += (f32)count / DOUBLE_LITERAL(250.0);
                        ChangeDeadFace(well1);
                    }
                }

                if (!win2) {
                    GameOverSmoke(well2);
                    if (well2->raise >= 0) {
                        count = dead2Shake[well2->raise];
                        well2->translation += (f32)count / DOUBLE_LITERAL(250.0);
                        ChangeDeadFace(well2);
                    }
                }

                well1->raise -= 1;
                well2->raise--;
                if ((gWhatever == 0) && (well1->raise < -0x3C) && (well2->raise < -0x3C)) {
                    temp = GAME_STATUS_GET_WIN_RECORD(gGameStatus);
                    if ((well1->win == temp) || (well2->win == temp)) {
                        SaveRom();
                    }
                    gWhatever++;
                }

                if ((well1->raise < -0x5A) && (well2->raise < -0x5A)) {
                    gMain = GMAIN_390;
                    well1->timer = 0;
                    well2->timer = 0;
                }
                break;

            case GMAIN_390:
                DropRow3D(well1, cursor1, 0);
                DropRow3D(well2, cursor2, 1);

                if ((well1->translation > DOUBLE_LITERAL(1.8)) && (well2->translation > DOUBLE_LITERAL(1.8))) {
                    temp = ntrue;
                } else {
                    temp = nfalse;
                }

                if (temp) {
                    gMain = GMAIN_391;

                    Init3DTetrisBlocks(well1, 0);
                    Init3DTetrisBlocks(well2, 1);
                    Init3DNewRow(well1);
                    Init3DNewRow(well2);
                    Init3DAttackBlocks(well1);
                    Init3DAttackBlocks(well2);

                    well1->raise = 0x36;
                    well2->raise = 0x36;
                    well1->timer = 90;
                    well2->timer = 90;

                    func_800521A4_usa(5);
                }
                break;

            case GMAIN_391:
                func_800386D4_usa(well1, 0);
                func_800386D4_usa(well2, 1);

                func_800387AC_usa(well1, 0);
                func_800387AC_usa(well2, 1);

                if (well1->raise < 0) {
                    gMain = GMAIN_392;

                    if (((gSelection == SELECTION_96) && win1) || (gSelection == SELECTION_A0) ||
                        (gSelection == SELECTION_B4) || (gSelection == SELECTION_C8)) {
                        if (B_801C6C90_usa != 0x10) {
                            PlaySE(SFX_INIT_TABLE, SFX_17A);
                        } else {
                            PlayMIDI(BGM_INIT_TABLE, 0x45, 0, 1);
                        }
                    }
                }
                break;

            case GMAIN_392:
                temp = GAME_STATUS_GET_WIN_RECORD(gGameStatus);
                if (gTheGame.tetrisWell[0].win == temp) {
                    well1->menu.game++;
                    gTheGame.menu[0].game++;
                    if (gTheGame.menu[0].game > 99) {
                        well1->menu.game = 99;
                        gTheGame.menu[0].game = 99;
                    }
                } else if (gTheGame.tetrisWell[1].win == temp) {
                    well2->menu.game++;
                    gTheGame.menu[1].game++;
                    if (gTheGame.menu[1].game > 99) {
                        well2->menu.game = 99;
                        gTheGame.menu[1].game = 99;
                    }
                }

                if (win1) {
                    if (well1->win == 1) {
                        Init3DCircleStars(1, 0);
                    } else if (well1->win == 2) {
                        Init3DCircleStars(1, 1);
                    } else {
                        Init3DCircleStars(1, 2);
                    }

                    func_80005888_usa(0, 1, 2);
                }

                if (win2) {
                    if (well2->win == 1) {
                        Init3DCircleStars(0, 0);
                    } else if (well2->win == 2) {
                        Init3DCircleStars(0, 1);
                    } else {
                        Init3DCircleStars(0, 2);
                    }

                    func_80005888_usa(0, 2, 2);
                    if (gSelection == SELECTION_96) {
                        if (B_801C6C90_usa != 0x10) {
                            PlayMIDI(BGM_INIT_TABLE, 0x42, 0, 1);
                        } else {
                            PlayMIDI(BGM_INIT_TABLE, 0x20, 0, 1);
                        }
                    }
                }

                well1->raise = -1;
                well2->raise = -1;
                well1->timer = 0;
                well2->timer = 0;

                gWhatever = 0;
                if (win1 != win2) {
                    gMain = GMAIN_393;
                } else {
                    gMain = GMAIN_394;
                }
                break;

            case GMAIN_393:
                if (CircleStars()) {
                    gMain = GMAIN_394;
                }
                break;

            case GMAIN_394:
                gTheGame.unk_9A90[2].b.frameY = 193 << 2;
                gTheGame.unk_9A90[3].b.frameY = 193 << 2;
                if (win1) {
                    Init3DSmallStars(0);
                } else if (win2) {
                    Init3DSmallStars(1);
                }

                gMain = GMAIN_395;
                break;

            case GMAIN_395:
                if (win1 == win2) {
                    AnimateDraw3D(well1, &gTheGame.unk_9A90[0]);
                    AnimateDraw3D(well2, &gTheGame.unk_9A90[1]);
                } else {
                    if (win1) {
                        AnimateLose3D(well1, &gTheGame.unk_9A90[0]);
                    } else {
                        AnimateWin3D(well1, &gTheGame.unk_9A90[0]);
                    }
                    if (win2) {
                        AnimateLose3D(well2, &gTheGame.unk_9A90[1]);
                    } else {
                        AnimateWin3D(well2, &gTheGame.unk_9A90[1]);
                    }

                    SmallStars();
                }

                AnimatePushKey(&gTheGame.unk_9A90[2]);
                AnimatePushKey(&gTheGame.unk_9A90[3]);

                gWhatever++;
                if (gWhatever == 0xDC) {
                    if ((gSelection != SELECTION_96) || (win1 && !win2)) {
                        PlayMIDI(BGM_INIT_TABLE, 0x45, 0, 1);
                    }
                }
                break;

            default:
                break;
        }

        Update3DCursor(well1, cursor1);
        Update3DCursor(well2, cursor2);
        Check3DVisibleBlocks(well1, cursor1);
        Check3DVisibleBlocks(well2, cursor2);
    }
}

/**
 * Original name: DoGameOver
 */
void DoGameOver(void) {
    SetGameFade();

    if (gTheGame.dimension == DIMENSION_3D) {
        DoGameOver3D();
    } else {
        DoGameOver2D();
    }
}

/**
 * Original name: SaveRom
 */
void SaveRom(void) {
    menuSaveData(1);
}
