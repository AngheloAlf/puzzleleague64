#ifndef ANIMATION_H
#define ANIMATION_H

#include "ultra64.h"
#include "unk.h"

struct tetWell;

s32 AnimationRandom(s32 max);
// void func_8004EE24_usa();
// void func_8004EEFC_usa();
// void func_8004F010_usa();
// void func_8004F4BC_usa();
// void func_8004F5E4_usa();
// TODO: maybe misnamed
void UpdateAnimation(struct tetWell *well, s32 num, s32 combo);
// void func_8004FA2C_usa();
void func_8004FABC_usa(void);
void func_80050420_usa(void);
// void func_800504B8_usa();
void func_8005076C_usa(void);
// void func_80050BA8_usa();
void func_80050C2C_usa(void);
void func_800512E0_usa(void);
// void func_80051998_usa();
// void func_800521A4_usa();
// void func_80052258_usa();
// void func_80052400_usa();

#endif
