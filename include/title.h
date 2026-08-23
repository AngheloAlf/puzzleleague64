#ifndef TITLE_H
#define TITLE_H

#include "ultra64.h"
#include "unk.h"

#include "other_types.h"


// void func_80005C00_usa();
void func_80005EC0_usa(Gfx **gfxP, s32 arg1, s32 arg2);
void DrawTitle(void);
nbool func_8000628C_usa(void);
void DoTitle(void);
void InitTitle(void);
void titleSetup(void);

#if !VERSION_USA
extern s32 B_8018A7F8_usa;
#endif

#endif
