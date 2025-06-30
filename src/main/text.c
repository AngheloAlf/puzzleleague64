/**
 * Original filename: text.c
 */

#include "text.h"

#include "macros_defines.h"
#include "main_variables.h"

#include "draw3d.h"
#include "fade.h"
#include "info.h"
#include "the_game.h"

#include "assets_variables.h"

#define MAGIC_NUMBER 6

nbool InitWhichNumber(text_t *text, char number, s32 type) {
    u16 *addr;

    if (number == '\0') {
        return nfalse;
    }

    addr = &text->word.s.imageAdrs;

    switch (type) {
        case SETTEXTTYPE_14:
            if (number < '7') {
                text->texture = 0;
            } else {
                text->texture = 2;
            }
            break;

        case SETTEXTTYPE_15:
            if (number < '7') {
                text->texture = 1;
            } else {
                text->texture = 2;
            }
            break;

        case SETTEXTTYPE_16:
            if (number < '7') {
                text->texture = 3;
            } else {
                text->texture = 5;
            }
            break;

        case SETTEXTTYPE_17:
            if (number < '7') {
                text->texture = 4;
            } else {
                text->texture = 5;
            }
            break;

        default:
            return nfalse;
    }

    switch (number) {
        default:
            return nfalse;

        case ' ':
            text->texture = 0x46;
            break;

        case '\'':
            *addr = 0;
            break;

        case '-':
            *addr = 0;
            break;

        case '7':
            if ((type == SETTEXTTYPE_14) || (type == SETTEXTTYPE_16)) {
                *addr = 0;
            } else {
                *addr = 0x80;
            }
            break;

        case '3':
            *addr = 0x80;
            break;

        case '8':
            if ((type == SETTEXTTYPE_14) || (type == SETTEXTTYPE_16)) {
                FALLTHROUGH;
                case '0':
                    *addr = 2;
            } else {
                *addr = 0x82;
            }
            break;

        case '4':
            *addr = 0x82;
            break;

        case '9':
            if ((type == SETTEXTTYPE_14) || (type == SETTEXTTYPE_16)) {
                FALLTHROUGH;
                case '1':
                    *addr = 4;
            } else {
                *addr = 0x84;
            }
            break;

        case '5':
            *addr = 0x84;
            break;

        case ':':
            if ((type == SETTEXTTYPE_14) || (type == SETTEXTTYPE_16)) {
                FALLTHROUGH;
                case '2':
                    *addr = 6;
            } else {
                *addr = 0x86;
            }
            break;

        case '6':
            *addr = 0x86;
            break;
    }

    return ntrue;
}

INLINE void SetText(s32 x, s32 y, const char str[], SetTextType type) {
    s32 str_pos = 0;
    s32 count;

    for (count = gTheGame.unk_90C0; count < DRAWTEXT_COUNT; count++) {
        text_t *text = &gTheGame.drawText[count];

        if (!InitWhichNumber(text, str[str_pos], type)) {
            break;
        }

        text->word.s.objX = x << 2;
        text->word.s.objY = y << 2;
        text->word.s.imageW = 0x10 << 5;

        x += 9;
        str_pos++;
    }

    gTheGame.unk_90C0 = count;
}

void UpdateText(void) {
    tetWell *well1 = &gTheGame.tetrisWell[0];
    tetWell *well2 = &gTheGame.tetrisWell[1];
    cursor_t *cursor1 = &gTheGame.cursorBlock[0];
    char string[0x10];
    s32 *hi_score;

    if (gMain >= GMAIN_384) {
        if (gTheGame.unk_9C08 == 1) {
            if (gTheGame.unk_9C14 == 0) {
                sprintf(string, "%2d'%02d", gTheGame.unk_9C18, gTheGame.unk_9C1C);
                SetText(0x3C, 0x28, string, SETTEXTTYPE_14);
            } else {
                sprintf(string, "%2d:%02d'%02d", gTheGame.unk_9C14, gTheGame.unk_9C18, gTheGame.unk_9C1C);
                SetText(0x21, 0x28, string, SETTEXTTYPE_14);
            }
        } else if (gSelection == 0x96) {
            if (gTheGame.unk_9C14 > 0) {
                sprintf(string, "59'59");
                SetText(0x8A, 0xAC, string, SETTEXTTYPE_14);
            } else {
                sprintf(string, "%d'%02d", gTheGame.unk_9C18, gTheGame.unk_9C1C);
                if (gTheGame.unk_9C18 < 0xA) {
                    SetText(0x8F, 0xAC, string, SETTEXTTYPE_14);
                } else {
                    SetText(0x8A, 0xAC, string, SETTEXTTYPE_14);
                }
            }
        } else if (gTheGame.unk_9C14 > 0) {
            sprintf(string, "59'59");
            SetText(0x8A, 0x9A, string, SETTEXTTYPE_14);
        } else {
            sprintf(string, "%d'%02d", gTheGame.unk_9C18, gTheGame.unk_9C1C);
            if (gTheGame.unk_9C18 < 0xA) {
                SetText(0x8F, 0x9A, string, SETTEXTTYPE_14);
            } else {
                SetText(0x8A, 0x9A, string, SETTEXTTYPE_14);
            }
        }
    }

    switch (gSelection) {
        case 0x8C:
        case 0xBE:
            if (gSelection == 0x8C) {
                if (gTheGame.unk_9C0C == 1) {
                    hi_score = &gPlayer[0]->unk_014;
                } else {
                    hi_score = &gPlayer[0]->unk_018;
                }
            } else {
                if (gTheGame.unk_9C0C == 1) {
                    hi_score = &gPlayer[0]->unk_01C;
                } else {
                    hi_score = &gPlayer[0]->unk_020;
                }
            }

            if (well1->unk_43AC > 999999) {
                well1->unk_43AC = 999999;
            }

            if (gDemo == GDEMO_2C) {
                if (well1->menu.unk_0 != 0) {
                    if (well1->unk_43AC > *hi_score) {
                        *hi_score = well1->unk_43AC;
                    }
                    goto block_63;
                }
            } else {
            block_63:
                if (well1->menu.unk_0 != 0) {
                    sprintf(string, "%6d", *hi_score);
                    SetText(0xE8, 0x2A, string, SETTEXTTYPE_16);
                }
            }

            sprintf(string, "%6d", well1->unk_43AC);
            SetText(0xE8, 0x3F, string, SETTEXTTYPE_15);

            if (cursor1->unk_0C > 0) {
                // TODO: dedicated macro?
                sprintf(string, "%02d", cursor1->unk_0C / ADJUST_FRAMERATE(60));
                SetText(0xFA, 0x5B, string, SETTEXTTYPE_14);

                gTheGame.drawText[3].texture = -1;
                gTheGame.drawText[4].texture = -1;
            } else {
                if (DoFlashDraw(0) != 0) {
                    sprintf(string, "%2d", well1->unk_43E0);
                    SetText(0x10C, 0x5B, string, SETTEXTTYPE_15);
                }

                gTheGame.drawText[3].texture = 0;
                if (gTheGame.tetrisWell[0].menu.unk_0 < 2) {
                    gTheGame.drawText[4].texture = 1;
                } else {
                    gTheGame.drawText[4].texture = 2;
                }
            }
            break;

        case 0xAA:
            if (well1->menu.unk_0 != 5) {
                sprintf(string, "%1d-%1d", well1->menu.unk_4, well1->menu.unk_8);
                SetText(0x103, 0x29, string, SETTEXTTYPE_16);
            }

            if (well1->unk_43AC > 999999) {
                well1->unk_43AC = 999999;
            }

            sprintf(string, "%6d", well1->unk_43AC);
            SetText(0xE8, 0x3F, string, SETTEXTTYPE_15);

            if (cursor1->unk_0C > 0) {
                sprintf(string, "%02d", cursor1->unk_0C / ADJUST_FRAMERATE(60));
                SetText(0xFA, 0x5B, string, SETTEXTTYPE_14);

                gTheGame.drawText[3].texture = -1;
            } else {
                if (DoFlashDraw(0) != 0) {
                    sprintf(string, "%2d", well1->unk_43E0);
                    SetText(0x10C, 0x5B, string, SETTEXTTYPE_15);
                }

                if (well1->menu.unk_0 != 5) {
                    gTheGame.drawText[3].texture = 0;
                    sprintf(string, "%2d", well1->menu.unk_4);
                    SetText(0x10C, 0x79, string, SETTEXTTYPE_14);
                }
            }
            break;

        default:
            break;

        case 0x78:
            sprintf(string, "%2d", well1->menu.unk_4);
            SetText(0x10C, 0x2C, string, SETTEXTTYPE_16);
            break;

        case 0x82:
            if (well1->menu.unk_0 == 0) {
                sprintf(string, "%2d", well1->menu.unk_4);
                SetText(0x10C, 0x3F, string, SETTEXTTYPE_16);
            } else if (well1->menu.unk_0 < 4) {
                sprintf(string, "%2d", well1->menu.unk_0);
                SetText(0x10C, 0x2A, string, SETTEXTTYPE_17);

                sprintf(string, "%2d", well1->menu.unk_4);
                SetText(0x10C, 0x3F, string, SETTEXTTYPE_15);
            } else {
                sprintf(string, "%2d", well1->menu.unk_0 - 3);
                SetText(0x10C, 0x2A, string, SETTEXTTYPE_16);

                sprintf(string, "%2d", well1->menu.unk_4);
                SetText(0x10C, 0x3F, string, SETTEXTTYPE_14);
            }
            break;

        case 0xC8:
            sprintf(string, "%05d", well1->unk_43AC % 100000, well1->unk_43AC);
            SetText(0x89, 0x58, string, SETTEXTTYPE_15);

            sprintf(string, "%05d", well2->unk_43AC % 100000, well2->unk_43AC);
            SetText(0x8A, 0x79, string, SETTEXTTYPE_14);

            sprintf(string, "%d", well1->menu.unk_8);
            if (well1->menu.unk_8 < 0xA) {
                SetText(0x93, 0x39, string, SETTEXTTYPE_17);
            } else {
                SetText(0x8D, 0x39, string, SETTEXTTYPE_17);
            }

            sprintf(string, "%d", well2->menu.unk_8);
            if (well2->menu.unk_8 < 0xA) {
                SetText(0xA3, 0x39, string, SETTEXTTYPE_16);
            } else {
                SetText(0x9D, 0x39, string, SETTEXTTYPE_16);
            }
            break;

        case 0xA0:
        case 0xB4:
            sprintf(string, "%d", well1->menu.unk_0);
            if (well1->menu.unk_0 < 0xA) {
                SetText(0x93, 0x5B, string, SETTEXTTYPE_17);
            } else {
                SetText(0x8D, 0x5B, string, SETTEXTTYPE_17);
            }

            sprintf(string, "%d", well2->menu.unk_0);
            if (well2->menu.unk_0 < 0xA) {
                SetText(0xA4, 0x5B, string, SETTEXTTYPE_16);
            } else {
                SetText(0xA1, 0x5B, string, SETTEXTTYPE_16);
            }

            sprintf(string, "%d", well1->menu.unk_8);
            if (well1->menu.unk_8 < 0xA) {
                SetText(0x93, 0x79, string, SETTEXTTYPE_17);
            } else {
                SetText(0x8D, 0x79, string, SETTEXTTYPE_17);
            }

            sprintf(string, "%d", well2->menu.unk_8);
            if (well2->menu.unk_8 < 0xA) {
                SetText(0xA4, 0x79, string, SETTEXTTYPE_16);
            } else {
                SetText(0x9F, 0x79, string, SETTEXTTYPE_16);
            }
            break;
    }
}

void Draw2DTemplate(struct_gInfo_unk_00068 *dynamicp) {
    s32 which = -1;
    s32 count;

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &otherLUT);

    for (count = 0; count < MAGIC_NUMBER; count++) {
        s32 currText = dynamicp->drawText[count].texture;

        if (currText == -1) {
            continue;
        }

        if (currText > 0xA) {
            currText = 0x19;
        }

        if (currText != which) {
            which = currText;

            switch (currText) {
                case 0x0:
                    gSPObjLoadTxtr(glistp++, &D_0101F240_usa);
                    break;

                case 0x1:
                    gSPObjLoadTxtr(glistp++, &D_0101F258_usa);
                    break;

                case 0x2:
                    gSPObjLoadTxtr(glistp++, &D_0101F270_usa);
                    break;

                case 0x3:
                    gSPObjLoadTxtr(glistp++, &D_0101F288_usa);
                    break;

                case 0x4:
                    gSPObjLoadTxtr(glistp++, &D_0101F2A0_usa);
                    break;

                case 0x5:
                    gSPObjLoadTxtr(glistp++, &D_0101F2D0_usa);
                    break;

                case 0x6:
                    gSPObjLoadTxtr(glistp++, &D_0101F2E8_usa);
                    break;

                case 0x7:
                    gSPObjLoadTxtr(glistp++, &D_0101F348_usa);
                    break;

                case 0x8:
                    gSPObjLoadTxtr(glistp++, &D_0101F360_usa);
                    break;

                default:
                    gSPObjLoadTxtr(glistp++, &D_0101F2B8_usa);
                    break;
#if 0
                case 0:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture1);
                    break;
                case 1:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture2);
                    break;
                case 2:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture3);
                    *(undefined2 *)(param_1 + 0x312cc) = 0x7e0;
                    break;
                case 3:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture4);
                    break;
                case 4:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture5);
                    break;
                case 5:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture7);
                    break;
                case 6:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture8);
                    break;
                case 7:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture12);
                    break;
                case 8:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture13);
                    break;
                case 9:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture14);
                    break;
                case 10:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture15);
                    break;
                default:
                    pon_gSPObjLoadTxtr(&glistp,&otherTexture6);
#endif
            }
        }

        gSPObjRectangle(glistp++, &dynamicp->drawText[count].word);
    }
}

void Draw2DText(struct_gInfo_unk_00068 *dynamicp) {
    char array[MAGIC_NUMBER];
    s32 i;
    s32 j;
    s32 last = 0;

    Draw2DTemplate(dynamicp);
    bzero(array, MAGIC_NUMBER * sizeof(char));

    for (i = MAGIC_NUMBER; i < DRAWTEXT_COUNT; i++) {
        if (dynamicp->drawText[i].texture < ARRAY_COUNTU(array)) {
            array[dynamicp->drawText[i].texture] = true;
        } else if (dynamicp->drawText[i].texture == -1) {
            last = i;
            break;
        }
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &numberLUT);

    for (j = 0; j < MAGIC_NUMBER; j++) {
        if (!array[j]) {
            continue;
        }

        switch (j) {
            case 0x0:
                gSPObjLoadTxtr(glistp++, &numberTexture1);
                break;

            case 0x1:
                gSPObjLoadTxtr(glistp++, &numberTexture2);
                break;

            case 0x2:
                gSPObjLoadTxtr(glistp++, &numberTexture3);
                break;

            case 0x3:
                gSPObjLoadTxtr(glistp++, &numberTexture4);
                break;

            case 0x4:
                gSPObjLoadTxtr(glistp++, &numberTexture5);
                break;

            case 0x5:
                gSPObjLoadTxtr(glistp++, &numberTexture6);
                break;
        }

        for (i = MAGIC_NUMBER; i < last; i++) {
            if (dynamicp->drawText[i].texture == j) {
                gSPObjRectangle(glistp++, &dynamicp->drawText[i].word);
            }
        }
    }
}

void Draw3DText(struct_gInfo_unk_00068 *dynamicp) {
    char array[MAGIC_NUMBER];
    s32 last = 0;
    u8 *ptr;
    s32 count;
    s32 which;

    bzero(array, MAGIC_NUMBER * sizeof(char));

    for (count = 6; count < DRAWTEXT_COUNT; count++) {
        if (dynamicp->drawText[count].texture < ARRAY_COUNTU(array)) {
            array[dynamicp->drawText[count].texture] = 1;
        } else if (dynamicp->drawText[count].texture == -1) {
            last = count;
            break;
        }
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gDPLoadTLUT_pal256(glistp++, numberTable);
    gDPSetAlphaCompare(glistp++, G_AC_THRESHOLD);

    Set3DTile();

    for (which = 0; which < MAGIC_NUMBER; which++) {
        if (!array[which]) {
            continue;
        }

        switch (which) {
            case 0x0:
                ptr = w_text1;
                break;

            case 0x1:
                ptr = w_text2;
                break;

            case 0x2:
                ptr = w_text3;
                break;

            case 0x3:
                ptr = w_text4;
                break;

            case 0x4:
                ptr = w_text5;
                break;

            case 0x5:
                ptr = w_text6;
                break;
        }

        gDPLoadTextureBlock(glistp++, ptr, G_IM_FMT_CI, G_IM_SIZ_8b, W_TEXT_WIDTH, W_TEXT_HEIGHT, 0,
                            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                            G_TX_NOLOD);

        func_8005E740_usa();

        for (count = MAGIC_NUMBER; count < last; count++) {
            if (dynamicp->drawText[count].texture == which) {
                text_t *text = &dynamicp->drawText[count];
                s32 tile;

                switch (text->word.s.imageAdrs) {
                    case 0x0:
                        tile = 0;
                        break;
                    case 0x4:
                        tile = 2;
                        break;
                    case 0x80:
                        tile = 4;
                        break;
                    case 0x84:
                        tile = 6;
                        break;
                    case 0x86:
                        tile = 7;
                        break;
                    case 0x2:
                        tile = 1;
                        break;
                    case 0x6:
                        tile = 3;
                        break;
                    case 0x82:
                        tile = 5;
                        break;
                }

                gSPTextureRectangle(glistp++, text->word.s.objX, text->word.s.objY,
                                    ((text->word.s.objX >> 2) + 0xB) << 2, ((text->word.s.objY >> 2) + 0xF) << 2, tile,
                                    0, 0, 0x0400, 0x0400);
            }
        }
    }
}
