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

        if (gTheGame.unk_9C08 == 1) {
            PlaySE(SFX_INIT_TABLE, which + 0xAC);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, which + 0xD0);
        } else {
            PlaySE(SFX_INIT_TABLE, which + 0xF4);
        }
    } else if (type == 2) {
        which = MIN(which, 9);

        if (gTheGame.unk_9C08 == 1) {
            PlaySE(SFX_INIT_TABLE, which + 0xB2);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, which + 0xD6);
        } else {
            PlaySE(SFX_INIT_TABLE, which + 0xFA);
        }
    } else if (type == 3) {
        which = MIN(which, 9);

        if (gTheGame.unk_9C08 == 1) {
            PlaySE(SFX_INIT_TABLE, which + 0xBC);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, which + 0xE0);
        } else {
            PlaySE(SFX_INIT_TABLE, which + 0x104);
        }
    } else if (type == 4) {
        which = MIN(which, 9);

        if (gTheGame.unk_9C08 == 1) {
            PlaySE(SFX_INIT_TABLE, which + 0xC6);
        } else if (num == 0) {
            PlaySE(SFX_INIT_TABLE, which + 0xEA);
        } else {
            PlaySE(SFX_INIT_TABLE, which + 0x10E);
        }
    } else {
        if (which > 6) {
            which = (which % 4) + 3;
        }

        if (DolbyEnabled != 0) {
            if (num == 0) {
                PlaySE(SFX_INIT_TABLE, which + 0x141);
            } else {
                PlaySE(SFX_INIT_TABLE, which + 0x148);
            }
        } else {
            PlaySE(SFX_INIT_TABLE, which + 0x133);
        }
    }
}

void StartExplosion(tetWell *well, s32 num, s32 row, s32 col, s32 type) {
    if (gTheGame.unk_9C0C == 1) {
        Start2DExplosion(well, row, col, type);
    } else {
        Start3DExplosion(well, num, row, col, type);
    }
}

void UpdateExplosion(tetWell *well) {
    if (gTheGame.unk_9C0C == 1) {
        Update2DExplosion(well);
    } else {
        Update3DExplosion(well);
    }
}
