/**
 * Original filename: other.c
 */

#include "other.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "assets_variables.h"
#include "the_game.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/other", func_80052720_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/other", func_800529C0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/other", func_80051130_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/other", func_800512B0_ger);
#endif

void UpdateMiscStuff(tetWell *well, cursor_t *cursor, s32 num) {
    s32 shake;

    switch (gSelection) {
        case 0x8C:
        case 0xAA:
        case 0xBE:
            if (gGameStatus & 0x20) {
                cursor->unk_0C = 0;
            } else if (cursor->unk_0C > 0) {
                if (gTheGame.unk_9B48 == 0) {
                    gTheGame.unk_9B48 = 1;
                }

                if (cursor->unk_0C > ADJUST_FRAMERATE(600)) {
                    shake = 0x32;
                } else if (cursor->unk_0C > ADJUST_FRAMERATE(360)) {
                    shake = 0x1E;
                } else if (cursor->unk_0C > ADJUST_FRAMERATE(120)) {
                    shake = 0xF;
                } else {
                    shake = 5;
                }

                if (gCounter % shake == 0) {
                    if (shake >= 0xF) {
                        if (gTheGame.unk_9B48 == 1) {
                            gTheGame.unk_9B48 = 2;
                        } else {
                            gTheGame.unk_9B48 = 1;
                        }
                    } else if (gTheGame.unk_9B48 == 1) {
                        gTheGame.unk_9B48 = 4;
                    } else if (gTheGame.unk_9B48 == 2) {
                        gTheGame.unk_9B48 = 3;
                    } else if (gTheGame.unk_9B48 == 3) {
                        gTheGame.unk_9B48 = 4;
                    } else {
                        gTheGame.unk_9B48 = 3;
                    }
                }
            } else {
                gTheGame.unk_9B48 = 0;
            }
            break;

        case 0x78:
        case 0x82:
            if (gTheGame.unk_9B48 > 1) {
                gTheGame.unk_9B48--;
            } else {
                gTheGame.unk_9B48 = -1;
            }

            if (cursor->unk_2C % 2 == 0) {
                gTheGame.drawText[3].word.s.imageAdrs = 0;
            } else {
                gTheGame.drawText[3].word.s.imageAdrs = 3;
            }
            break;

        case 0x64:
        case 0x96:
        case 0xA0:
        case 0xB4:
        case 0xC8:
            gTheGame.unk_9B48 = -1;
            gTheGame.unk_9B50[num].b.frameY = well->unk_441C * 4;
            break;
    }
}

void Draw2DMiscStuff(struct_gInfo_unk_00068 *dynamicp) {
    s32 index;

    if (gTheGame.unk_9B48 == 0) {
        return;
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &gTheGame.unk_9BF0);
    gDPSetRenderMode(glistp++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCycleType(glistp++, G_CYC_COPY);

    gDPPipeSync(glistp++);

    switch (gSelection) {
        case 0x8C:
        case 0xAA:
        case 0xBE:
            index = gTheGame.unk_9B48 - 1;
            gSPBgRectCopy(glistp++, &gTheGame.unk_9B50[index]);
            break;

        case 0x78:
        case 0x82:
            index = (gTheGame.unk_9B48 > 1) ? 1 : 0;
            gSPBgRectCopy(glistp++, &gTheGame.unk_9B50[index]);
            break;

        case 0x64:
        case 0x96:
        case 0xA0:
        case 0xB4:
        case 0xC8:
            gSPBgRectCopy(glistp++, &gTheGame.unk_9B50[0]);
            gSPBgRectCopy(glistp++, &gTheGame.unk_9B50[1]);
            break;
    }

    gDPPipeSync(glistp++);
    gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);

    if ((gSelection < 0x83) && (gMain >= GMAIN_384)) {
        gDPSetTextureLUT(glistp++, G_TT_RGBA16);
        gSPObjLoadTxtr(glistp++, &otherLUT);

        if (dynamicp->cursorBlock[0].unk_2C < 2) {
            gSPObjLoadTxtr(glistp++, &otherTexture9);
        } else if (dynamicp->cursorBlock[0].unk_2C < 4) {
            gSPObjLoadTxtr(glistp++, &otherTexture10);
        } else {
            gSPObjLoadTxtr(glistp++, &otherTexture11);
        }

        gSPObjRectangle(glistp++, &dynamicp->drawText[3].word);
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_NONE);
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/other", func_80053140_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/other", func_800533E0_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/other", func_80051B50_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/other", func_80051CD0_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/other", func_80053E64_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/other", func_80054104_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/other", func_80052874_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/other", func_800529F4_ger);
#endif
