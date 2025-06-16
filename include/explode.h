#ifndef EXPLODE_H
#define EXPLODE_H

#include "ultra64.h"
#include "PR/gs2dex.h"
#include "unk.h"

struct tetWell;

typedef struct explode_t {
    /* 0x00 */ s32 type; // TODO: enum?
    /* 0x04 */ s32 frame;
    /* 0x08 */ s32 pos;
    /* 0x0C */ s32 x;
    /* 0x10 */ s32 y;
    /* 0x18 */ uObjSprite rect;
} explode_t; // size = 0x30

void PlayExplosionSound(s32 num, s32 sound);
void StartExplosion(struct tetWell *well, s32 num, s32 row, s32 col, s32 type);
void UpdateExplosion(struct tetWell *well);

#endif
