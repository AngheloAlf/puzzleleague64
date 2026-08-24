#ifndef TITLE_H
#define TITLE_H

#include "ultra64.h"
#include "unk.h"

#include "other_types.h"


// void func_80005C00_usa();
void titleDrawImage(Gfx **gfxP, s32 arg1, s32 nTag);
void DrawTitle(void);
nbool CheckTitleInput(void);
void DoTitle(void);
void InitTitle(void);
void titleSetup(void);

// Maybe TitleDemo?
typedef enum enum_geDemoTitle {
    /*  0 */ TD_NONE, /* Original name: TD_NONE */
    /*  1 */ TD_RULES_1, /* Original name: TD_RULES_1 */
    /*  2 */ TD_ENDLESS_2D, /* Original name: TD_ENDLESS_2D */
    /*  3 */ TD_RULES_2, /* Original name: TD_RULES_2 */
    /*  4 */ TD_ENDLESS_3D, /* Original name: TD_ENDLESS_3D */
    /*  5 */ TD_RULES_VS1, /* Original name: TD_RULES_VS1 */
    /*  6 */ TD_VS_2D, /* Original name: TD_VS_2D */
    /*  7 */ TD_RULES_VS2, /* Original name: TD_RULES_VS2 */
    /*  8 */ TD_VS_3D, /* Original name: TD_VS_3D */
    /*  9 */ TD_PROFILE, /* Original name: TD_PROFILE */
    /* 10 */ TD_LAST, /* Original name: TD_LAST */
} enum_geDemoTitle;

#if !VERSION_USA
extern enum_geDemoTitle geDemoTitle;
#endif

#endif
