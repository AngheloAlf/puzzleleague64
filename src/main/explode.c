/**
 * Original filename: explode.c
 */

#include "explode.h"

#include "main_variables.h"

#include "explode2d.h"
#include "explode3d.h"
#include "sfxlimit.h"
#include "the_game.h"

void PlayExplosionSound(s32 num, s32 sound) {
    s32 which = sound % 100;
    s32 type = sound / 100;

    if (type == 1) {
        which = MIN(which, 9);

        if (gTheGame.totalPlayer == 1) {
            PlaySE(SFX_INIT_TABLE, which + SFX_0AC);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, which + SFX_0D0);
        } else {
            PlaySE(SFX_INIT_TABLE, which + SFX_0F4);
        }
    } else if (type == 2) {
        which = MIN(which, 9);

        if (gTheGame.totalPlayer == 1) {
            PlaySE(SFX_INIT_TABLE, which + SFX_0B2);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, which + SFX_0D6);
        } else {
            PlaySE(SFX_INIT_TABLE, which + SFX_0FA);
        }
    } else if (type == 3) {
        which = MIN(which, 9);

        if (gTheGame.totalPlayer == 1) {
            PlaySE(SFX_INIT_TABLE, which + SFX_0BC);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, which + SFX_0E0);
        } else {
            PlaySE(SFX_INIT_TABLE, which + SFX_104);
        }
    } else if (type == 4) {
        which = MIN(which, 9);

        if (gTheGame.totalPlayer == 1) {
            PlaySE(SFX_INIT_TABLE, which + SFX_0C6);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, which + SFX_0EA);
        } else {
            PlaySE(SFX_INIT_TABLE, which + SFX_10E);
        }
    } else {
        if (which > 6) {
            which = (which % 4) + 3;
        }

        if (DolbyEnabled != 0) {
            if (num == 0) {
                PlaySE(SFX_INIT_TABLE, which + SFX_141);
            } else {
                PlaySE(SFX_INIT_TABLE, which + SFX_148);
            }
        } else {
            PlaySE(SFX_INIT_TABLE, which + SFX_133);
        }
    }
}

void StartExplosion(tetWell *well, s32 num, s32 row, s32 col, s32 type) {
    if (gTheGame.dimension == DIMENSION_2D) {
        Start2DExplosion(well, row, col, type);
    } else {
        Start3DExplosion(well, num, row, col, type);
    }
}

void UpdateExplosion(tetWell *well) {
    if (gTheGame.dimension == DIMENSION_2D) {
        Update2DExplosion(well);
    } else {
        Update3DExplosion(well);
    }
}
