/**
 * Original filename: mimic.c
 */

#include "mimic.h"

#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "segment_symbols.h"

#include "ai.h"
#include "animation.h"
#include "buffers.h"
#include "character.h"
#include "dlist.h"
#include "init2d.h"
#include "other.h"
#include "peel.h"
#include "screen.h"
#include "sfxlimit.h"
#include "sound.h"
#include "tetsound.h"
#include "tutorial.h"
#include "update.h"
#include "067FB0.h"
#include "0707D0.h"

INLINE void SetupMimic(void **heapP) {
    s32 temp_a0;

    B_801C6EE8_usa = 1;
    B_801C6E58_usa = 1;
    Pon_Image_Heap = &gBufferHeap[SEGMENT_ROM_SIZE(segment_0CA4A0)];

    temp_a0 = gGameStatus & 0x40;
    gGameStatus = gGameStatus << 0x10;
    if (temp_a0 != 0) {
        gGameStatus |= 0x40;
    }

    func_80054624_usa(temp_a0);
    InitCharacter(0x385, -1);
    LoadFairySoundData(0x19, 9, 9);

    *heapP = Pon_Image_Heap;
}

INLINE void QuitMimic(void) {
    gGameStatus = gGameStatus >> 0x10;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80083050_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_8008336C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_800833B0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_800833E0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_800836FC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80083740_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80081B00_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80081E1C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_80081E60_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80081CC0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80081FDC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80082020_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", UpdateMT);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", UpdateMT);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", UpdateMT);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", UpdateMT);
#endif

void UpdateMTController(tetWell *well, cursor_t *cursor, s32 num) {
    gamepad_t *gamepad = &gTheGame.controller[num];
    u16 t_button = gamepad->touch_button;
    u16 h_button = gamepad->hold_button;
    s32 sound = 0;

    if (gTheGame.unk_9C0C == 1) {
        if (brainbrain[num].unk_00C == -1) {
            if (h_button & U_JPAD) {
                sound = Move2DCursorUp(well, cursor, gamepad->unk_08);
            } else if (h_button & D_JPAD) {
                sound = Move2DCursorDown(cursor, gamepad->unk_08);
            } else if (h_button & L_JPAD) {
                sound = Move2DCursorLeft(cursor, gamepad->unk_08);
            } else if (h_button & R_JPAD) {
                sound = Move2DCursorRight(cursor, gamepad->unk_08);
            }

            if (t_button & (A_BUTTON | B_BUTTON)) {
                Switch2DBlocks(well, cursor, num);
            }
        } else {
            UpdateMT(well, cursor, &brainbrain[num]);
        }

        Update2DSwitching(well, cursor);
    } else {
        if (brainbrain[num].unk_00C == -1) {
            if (h_button & U_JPAD) {
                sound = Move3DCursorUp(well, cursor, gamepad->unk_08);
            } else if (h_button & D_JPAD) {
                sound = Move3DCursorDown(cursor, gamepad->unk_08);
            } else if (h_button & L_JPAD) {
                sound = Move3DCursorLeft(cursor, gamepad->unk_08);
            } else if (h_button & R_JPAD) {
                sound = Move3DCursorRight(cursor, gamepad->unk_08);
            }

            if (t_button & (A_BUTTON | B_BUTTON)) {
                Switch3DBlocks(well, cursor, num);
            }
        } else {
            UpdateMT(well, cursor, &brainbrain[num]);
        }

        Update3DSwitching(well, cursor);
    }

    if (sound != 0) {
        PlaySE(SFX_INIT_TABLE, 0x96);
    }

    cursor->unk_24--;
    if (cursor->unk_24 == 0) {
// TODO: REGION_NTSC?
#if VERSION_USA
        cursor->unk_24 = 0xF;
#else
        cursor->unk_24 = 0xD;
#endif
        cursor->unk_20 ^= 1;
    }
}

#if VERSION_USA
// Silly reorder at the top
#ifdef NON_MATCHING
void DoMT(void) {
    s32 pad[2] UNUSED;
    cursor_t *temp_s1; // cursor
    s32 temp_s2;       // count
    s32 var_s3;        // num
    s32 var_s6;        // total
    tetWell *temp_s0;  // well

    var_s6 = 1;

    pad[0] = 0;
    pad[1] = 0;

    if (gSelection == 0x6E) {
        MimicCheckState(&gTheGame.tetrisWell[0], &gTheGame.cursorBlock[0]);
    } else {
        TutorialCheckState(&gTheGame.tetrisWell[0], &gTheGame.cursorBlock[0]);
    }

    if (gMain == GMAIN_2BC) {
        return;
    }

    if ((gSelection == 0x64) && (gTheGame.unk_9C28 == 3)) {
        var_s6 = 2;
    }

    for (var_s3 = 0; var_s3 < var_s6; var_s3++) {
        temp_s0 = &gTheGame.tetrisWell[var_s3];
        temp_s1 = &gTheGame.cursorBlock[var_s3];

        if (temp_s1->unk_00 != 0x34C) {
            CompactWell(temp_s0, var_s3);
        }

        if (var_s3 == 0) {
            UpdateMTController(temp_s0, temp_s1, var_s3);
        }

        if (temp_s1->unk_00 != 0x34C) {
            if (temp_s0->unk_43C4 != 0) {
                CheckCollision(temp_s0);
            }

            temp_s0->unk_43C4 = 0;
            CheckChainCounter(temp_s0, temp_s1);
            temp_s2 = ComboCount(temp_s0, temp_s1);
            temp_s0->unk_43BC = 0;

            if (gSelection == 0x64) {
                CheckShake(temp_s0, temp_s1);
            }

            CheckIcon(temp_s0, temp_s2);
            StartAttack(temp_s0, var_s3);
            UpdateWell(temp_s0, temp_s1, var_s3, temp_s2);

            if (gSelection == 0x64) {
                ChangeAttack(temp_s0, temp_s1, var_s3, temp_s2);
            }
            UpdateCursor(temp_s0, temp_s1);
            UpdateIcon(temp_s0, temp_s1, var_s3);
            if (gSelection == 0x64) {
                UpdateAttack(temp_s0, temp_s1, var_s3);
            }
            UpdateExplosion(temp_s0);
            UpdateDistance(temp_s0, temp_s1);
            UpdateAnimation(temp_s0, var_s3, 0);
            UpdateMiscStuff(temp_s0, temp_s1, var_s3);
            if ((temp_s1->unk_00 <= 0) && (temp_s0->unk_43F8 >= (gTheGame.unk_9C0C * 0x10))) {

                temp_s0->unk_43C4 = -1;

                AddNewRow(temp_s0, temp_s1, var_s3);
                temp_s0->unk_43F8 = 0;
            }

            if (gTheGame.unk_9C0C == 2) {
                Check3DVisibleBlocks(temp_s0, temp_s1);
            }

            temp_s0->unk_43FC = 0;
            temp_s0->unk_43A4 = 0;
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", DoMT);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", DoMT);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", DoMT);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", DoMT);
#endif

void MimicCheckState(tetWell *well, cursor_t *cursor) {
    s32 result;

    if (well->unk_43A8 < cursor->unk_28) {
        cursor->unk_28 = well->unk_43A8;
    }

    if (CheckFieldActive(well) == 0) {
        if ((brainbrain[0].unk_00C == -1) && (well->unk_43A8 == 0)) {
            if (brainbrain[0].unk_03C == 5) {
                if (cursor->unk_2C == 0) {
                    return;
                }
                result = (cursor->unk_2C == cursor->unk_30) ? -1 : 0;
            } else if (cursor->unk_28 != 0) {
                result = ((-cursor->unk_30 >= cursor->unk_28)) ? -1 : 0;
            } else if (cursor->unk_2C != 0) {
                result = 0;
            } else {
                return;
            }

            if (result != 0) {
                cursor->unk_00 = 7;
                B_801C7348_usa++;
                B_801C7348_usa %= 5;
                func_80005888_usa(0, 2, B_801C7348_usa + 5);
            } else {
                cursor->unk_00 = 8;
                PlaySE(SFX_INIT_TABLE, 0xA0);
            }

            gMain = GMAIN_2BC;
        } else if (brainbrain[0].unk_104 < 0) {
            brainbrain[0].unk_00C = -1;
            brainbrain[0].unk_104 = 0;
            if (well->unk_43A8 == -3) {
                PlaySE(SFX_INIT_TABLE, 0x12C);
            } else if (well->unk_43A8 == -4) {
                PlaySE(SFX_INIT_TABLE, 0x12D);
            } else if (well->unk_43A8 < -4) {
                PlaySE(SFX_INIT_TABLE, 0x12E);
            }

            gMain = GMAIN_2BC;
        }
    }

    if (gMain == GMAIN_2BC) {
        Init2DIcons(well);
        Init2DExplosion(well);
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084C18_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084C84_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80084D24_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", Draw2DMT);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", Draw3DMT);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", func_80085CC8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80084FD0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_8008503C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_800850DC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", Draw2DMT);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", Draw3DMT);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", func_80086080_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_800836F0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_8008375C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_800837FC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", Draw2DMT);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", Draw3DMT);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", func_800847A0_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_800838B0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_8008391C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_800839BC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", Draw2DMT);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", Draw3DMT);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", func_80084960_ger);
#endif

void DrawMT(struct_gInfo_unk_00068 *dynamicp) {
    tut_dynamicp = dynamicp;
    screenDraw(&glistp, DrawTUT);

    if (screenFlushing()) {
        return;
    }

    if ((gMain == GMAIN_MIMIC) && (geModeMimic >= MM_STAGE)) {
        if (gTheGame.unk_9C0C == 1) {
            Draw2DMT(dynamicp);
        } else {
            Draw3DMT(dynamicp);
        }

        if (!screenFlushing()) {
            func_8002C2C0_usa(&glistp);
        }
    }

    func_8002C2C0_usa(&glistp);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/mimic", DoMimic);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/mimic", DoMimic);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/mimic", DoMimic);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/mimic", DoMimic);
#endif

const char RO_800C76E4_usa[] = "MIMIC?.SBF";

// maybe mimicShowText?
STATIC_INLINE void inlined_function() {
    u32 nType;
    s32 temp_s0;
    s32 temp_s0_2;

    giScreenMimic = screenSet("MIMIC", 0x401);
    temp_s0 = gnTagTextMimic;
    geModeMimic = MM_NONE;
    B_80193014_usa = 0;
    gnTagTextMimic = (gTheGame.unk_9C2C[0][1] * 0xA) + 0x1EA;
    if (screenGetTextType(giScreenMimic, gnTagTextMimic, &nType)) {
        screenHideText(giScreenMimic, -0x3FFFFE0C);
        screenShowText(giScreenMimic, gnTagTextMimic);
    } else {
        gnTagTextMimic = temp_s0;
    }

    temp_s0_2 = ((B_8019300C_usa & 0xFFFF) == 0x258) ? 0x259 : 0x258;
    if ((B_8019300C_usa == 0) || ((B_8019300C_usa >> 0x10) != 0)) {
        B_8019300C_usa = temp_s0_2;
        func_80028DC0_usa(giScreenMimic, temp_s0_2, 0);
        func_800288D8_usa(giScreenMimic, temp_s0_2, 0x9E, 0x48);
    }
}

void InitMimic(void) {
    void *sp10;
    char *temp;

    gnTagTextMimic = -1;
    B_80192FF0_usa = 0;
    B_8019300C_usa = 0;
    B_80193004_usa = 0;
    B_80193000_usa = 0;
    B_80192FFC_usa = 0;
    B_80192FF8_usa = 0;

    SetupMimic(&sp10);

    //! @bug: Modifies a `const` symbol.
    // cast const away
    temp = (char *)RO_800C76E4_usa;
    temp[5] = gTheGame.unk_9C2C[0][1] + '0';

    if (screenLoad(temp, &sp10) != 0) {
        inlined_function();
    }

    if (B_8021B960_usa != 0x40) {
        func_80002D8C_usa(0x1E);
        PlayMIDI(BGM_INIT_TABLE, 0x40, 0, 1);
    }
}