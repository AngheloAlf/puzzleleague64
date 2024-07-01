#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ultra64.h"
#include "unk.h"


void InitController(void);
void CheckController(void);
void func_80046F8C_usa(void);
void UpdateController();
void UpdateMenuController();

extern u8 D_800B69B0_usa;

#endif
