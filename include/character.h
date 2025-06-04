#ifndef CHARACTER_H
#define CHARACTER_H

#include "ultra64.h"
#include "unk.h"

struct attack_t;

void InitCharacter(s32 left, s32 right);
s32 ReturnAttackTexValue(struct attack_t *attack, s32 type, s32 lev, s32 pos);

#endif
