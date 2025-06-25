/**
 * Original filename: update.c
 */

#include "update.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "combo3d.h"
#include "info.h"
#include "the_game.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057650_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateTime);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateNextLevel);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057D1C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057D68_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057E10_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057EB8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057F84_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_8005806C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058168_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_8005825C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_8005834C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058458_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdatePlayerPuzzle);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_800587CC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058934_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdatePlayerStageClear);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdatePlayerStageClearTimeScore);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058D68_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateComboChainCount);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateWell);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateCursor);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateIcon);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateDistance);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", UpdateMainState);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_800578F0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdateTime);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdateNextLevel);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80057FBC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058030_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_800580D8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058180_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_8005824C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058334_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058430_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058524_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058614_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058458_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdatePlayerPuzzle);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_800587CC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058934_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdatePlayerStageClear);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdatePlayerStageClearTimeScore);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_80058D68_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", func_800590B8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdateWell);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdateCursor);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdateIcon);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdateDistance);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/update", UpdateMainState);
#endif

#if VERSION_USA || VERSION_EUR
void UpdateBuffer(struct_gInfo *info) {
    if (gTheGame.unk_9C0C == 1) {
        Update2DBuffer(info);
    } else {
        Update3DBuffer(info);
    }
}
#endif

#if VERSION_USA || VERSION_EUR
void Update2DBuffer(struct_gInfo *info) {
    struct_gInfo_unk_00068 *dynamicp = &info->unk_00068;
    s8 *sp14;
    s32 var_s6;

    dynamicp->unk_10240 = gOverflow;

    sp14 = D_800B7508_usa;
    if (gGameStatus & 0x40) {
        sp14 = TetrisBlockFrame;
    }

    for (var_s6 = 0; var_s6 < gTheGame.unk_9C08; var_s6++) {
        tetWell *well = &gTheGame.tetrisWell[var_s6];
        cursor_t *cursor = &gTheGame.cursorBlock[var_s6];
        block_t(*var_s0)[BLOCK_LEN_B];
        s32 var_a1;

        bcopy(cursor, &dynamicp->cursorBlock[var_s6], sizeof(cursor_t));
        bcopy(well->block, dynamicp->block[var_s6], sizeof(well->block));
        // Why only the first 4 bytes? Could this be a bug or is it intentional?
        bzero(&dynamicp->unk_10208[var_s6], 4);

        var_s0 = dynamicp->block[var_s6];
        for (var_a1 = 0; var_a1 < BLOCK_LEN_ROWS; var_a1++) {
            s32 var_a0;

            for (var_a0 = 0; var_a0 < BLOCK_LEN_B / 3; var_a0++) {
                block_t *var = &var_s0[var_a1][var_a0];

                var->frame_n = sp14[var->frame_n];
                dynamicp->unk_10208[var_s6][var->frame_n] = 1;
            }
        }

        bcopy(&well->unk_3830, &dynamicp->block_rect[var_s6],
              sizeof(uObjSprite) * BLOCK_LEN_ROWS * TETWELL_OBJSPRITE_LEN_B);
        bcopy(&well->unk_3EF0, &dynamicp->unk_18188[var_s6], sizeof(uObjSprite) * TETWELL_UNK_3EF0_LEN_6);

        if (cursor->unk_1C != -1) {
            bcopy(&well->unk_3F80, &dynamicp->unk_182A8[var_s6], sizeof(uObjSprite));
            bcopy(&well->unk_3F98, &dynamicp->unk_182D8[var_s6], sizeof(uObjSprite));
        }

        bcopy(&well->icon, &dynamicp->icon[var_s6], sizeof(icon_t) * ICON_COUNT);
        bcopy(&well->attack, &dynamicp->attack[var_s6], sizeof(attack_t) * ATTACK_COUNT);
        bcopy(&well->explosion, &dynamicp->explosion[var_s6], sizeof(explode_t) * EXPLOSION_COUNT);
    }

    bcopy(&gTheGame.drawText, &dynamicp->drawText, sizeof(text_t) * DRAWTEXT_COUNT);
}
#endif

#define ABS(x) (((x) < 0) ? -(x) : (x))

#if VERSION_USA || VERSION_EUR
void Update3DBuffer(struct_gInfo *info) {
    struct_gInfo_unk_00068 *dynamicp = &info->unk_00068;
    tetWell *well;
    cursor_t *cursor;
    s32 num;
    s32 frame;
    // TODO: which one is row and col?
    s32 var_a2;
    int var_v1;
    block_t(*var_s0)[BLOCK_LEN_B];
    s8 *var_s7;

    var_s7 = D_800B7508_usa;
    if (gGameStatus & 0x40) {
        var_s7 = TetrisBlockFrame;
    }

    for (num = 0; num < gTheGame.unk_9C08; num++) {
        well = &gTheGame.tetrisWell[num];
        cursor = &gTheGame.cursorBlock[num];

        bcopy(cursor, &dynamicp->cursorBlock[num], sizeof(cursor_t));
        bcopy(&well->block, &dynamicp->block[num], sizeof(block_t) * BLOCK_LEN_ROWS * BLOCK_LEN_B);

        // Why only the first 4 bytes? Could this be a bug or is it intentional?
        bzero(&dynamicp->unk_10208[num], 4);
        // Why only the first 4 bytes? Could this be a bug or is it intentional?
        bzero(&dynamicp->unk_10224[num], 4);

        var_s0 = dynamicp->block[num];
        for (var_v1 = 0; var_v1 < BLOCK_LEN_ROWS; var_v1++) {
            block_t *something = var_s0[var_v1];

            for (var_a2 = 1; var_a2 < BLOCK_LEN_B / 2; var_a2++) {
                frame = var_s7[something[var_a2].frame_n];
                something[var_a2].frame_n = frame;
                dynamicp->unk_10208[num][frame] = 1;
            }

            for (var_a2 = BLOCK_LEN_B / 2; var_a2 < BLOCK_LEN_B; var_a2++) {
                frame = var_s7[something[var_a2].frame_n];
                something[var_a2].frame_n = frame;
                dynamicp->unk_10224[num][frame] = 1;
            }

            frame = var_s7[something[0].frame_n];
            something[0].frame_n = frame;
            dynamicp->unk_10224[num][frame] = 1;
        }

        bcopy(&well->icon, &dynamicp->icon[num], sizeof(icon_t) * ICON_COUNT);
        bcopy(&well->attack, &dynamicp->attack[num], sizeof(attack_t) * ATTACK_COUNT);
        bcopy(&well->explosion, &dynamicp->explosion[num], sizeof(explode_t) * EXPLOSION_COUNT);
        bcopy(&well->visible, &dynamicp->unk_18308[num], sizeof(char) * BLOCK_LEN_ROWS * BLOCK_LEN_B);

        if (gSelection == 0x64) {
            gTransMtx[3][0] = -0.51f;
        } else if (gTheGame.unk_9C08 == 1) {
            gTransMtx[3][0] = 0.06f;
        } else if (num == 0) {
            gTransMtx[3][0] = -0.51f;
        } else {
            gTransMtx[3][0] = 0.51f;
        }

        gTransMtx[3][1] = well->translation + 0.01;

        guMtxF2L(gTransMtx, &dynamicp->unk_10100[num]);

        if (cursor->unk_18 > 0) {
            var_v1 = ABS(cursor->unk_18);

            gRotateYMtx[0][0] = rotate_cos[var_v1];
            gRotateYMtx[2][0] = rotate_sin[var_v1];
            gRotateYMtx[0][2] = -rotate_sin[var_v1];
            gRotateYMtx[2][2] = rotate_cos[var_v1];
        } else if (cursor->unk_18 < 0) {
            var_v1 = ABS(cursor->unk_18);

            gRotateYMtx[0][0] = rotate_cos[var_v1];
            gRotateYMtx[2][0] = -rotate_sin[var_v1];
            gRotateYMtx[0][2] = rotate_sin[var_v1];
            gRotateYMtx[2][2] = rotate_cos[var_v1];
        } else {
            gRotateYMtx[0][0] = 1.0f;
            gRotateYMtx[2][0] = 0.0f;
            gRotateYMtx[0][2] = 0.0f;
            gRotateYMtx[2][2] = 1.0f;
        }

        guMtxF2L(gRotateYMtx, &dynamicp->unk_10180[num]);

        if (cursor->unk_1C != -1) {
            var_a2 = 3 - cursor->unk_04;

            gRotateYMtx[0][0] = switch_cos[var_a2];
            gRotateYMtx[2][0] = switch_sin[var_a2];
            gRotateYMtx[0][2] = -switch_sin[var_a2];
            gRotateYMtx[2][2] = switch_cos[var_a2];

            guMtxF2L(gRotateYMtx, &dynamicp->unk_184B8[num]);

            var_a2 = cursor->unk_04 - 1;

            gRotateYMtx[0][0] = switch_cos[var_a2];
            gRotateYMtx[2][0] = switch_sin[var_a2];
            gRotateYMtx[0][2] = -switch_sin[var_a2];
            gRotateYMtx[2][2] = switch_cos[var_a2];

            guMtxF2L(gRotateYMtx, &dynamicp->unk_18538[num]);
        }
    }

    bcopy(&gTheGame.drawText, &dynamicp->drawText, sizeof(text_t) * DRAWTEXT_COUNT);
}
#endif
