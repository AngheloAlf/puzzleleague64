#ifndef PEEL_H
#define PEEL_H

#include "ultra64.h"
#include "unk.h"

#include "other_types.h"


void pon_DrawLoadingMessage(Gfx **gfxP);
void peelTick(void);
void peelStop(void);
void func_8002CFE4_usa(s32 arg0);
nbool peelActive(void);
void peelSetup(void);
// void func_8002DBF0_usa();

#endif
