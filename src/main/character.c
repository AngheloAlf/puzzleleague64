/**
 * Original filename: character.c
 */

#include "character.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_functions.h"
#include "main_variables.h"

#include "001F10.h"

#include "assets/character_block.h"

void InitCharacter(s32 left, s32 right) {
    s32 sp10[17][3] = {
        { 0x32, 0x36, 0x38 }, //
        { 0x33, 0x37, 0x36 }, //
        { 0x34, 0x37, 0x33 }, //
        { 0x36, 0x36, 0x36 }, //
        { 0x32, 0x32, 0x32 }, //
        { 0x38, 0x38, 0x33 }, //
        { 0x39, 0x32, 0x33 }, //
        { 0x35, 0x35, 0x35 }, //
        { 0x37, 0x37, 0x37 }, //
        { 0x36, 0x39, 0x39 }, //
        { 0x33, 0x33, 0x33 }, //
        { 0x3A, 0x34, 0x33 }, //
        { 0x32, 0x37, 0x39 }, //
        { 0x3B, 0x36, 0x3B }, //
        { 0x34, 0x3C, 0x3C }, //
        { 0x33, 0x37, 0x36 }, //
        { 0x32, 0x36, 0x38 }, //
    };
    uObjTxtr *txtr;
    CharacterBlockTextures *character_block_textures;
    s32 total;
    s32 who;
    s32 i;
    s32 j;

    for (i = 0; i < GAME_BUFFER_LEN; i++) {
        B_801C7368_usa[i].tlut.type = G_OBJLT_TLUT;
        B_801C7368_usa[i].tlut.image = NULL;
        B_801C7368_usa[i].tlut.phead = GS_PAL_HEAD(0);
        B_801C7368_usa[i].tlut.pnum = GS_PAL_NUM(CHARACTER_BLOCK_TLUT_SIZE);
        B_801C7368_usa[i].tlut.zero = 0;
        B_801C7368_usa[i].tlut.sid = 0;
        B_801C7368_usa[i].tlut.flag = (u32)-1;
        B_801C7368_usa[i].tlut.mask = 0;
    }

    for (i = 0; i < GAME_BUFFER_LEN; i++) {
        B_801C6E70_usa[i].block.type = G_OBJLT_TXTRBLOCK;
        B_801C6E70_usa[i].block.image = NULL;
        B_801C6E70_usa[i].block.tmem = GS_PIX2TMEM(0, G_IM_SIZ_8b);
        B_801C6E70_usa[i].block.tsize = GS_TB_TSIZE(CHARACTER_BLOCK_1_WIDTH * CHARACTER_BLOCK_1_HEIGHT, G_IM_SIZ_8b);
        B_801C6E70_usa[i].block.tline = GS_TB_TLINE(CHARACTER_BLOCK_1_WIDTH, G_IM_SIZ_8b);
        B_801C6E70_usa[i].block.sid = 0;
        B_801C6E70_usa[i].block.flag = (u32)-1;
        B_801C6E70_usa[i].block.mask = 0;
    }

    for (i = 0; i < GAME_BUFFER_LEN; i++) {
        for (j = 0; j < B_801F9D00_USA_LEN; j++) {
            txtr = &B_801F9D00_usa[i][j];
            txtr->block.type = G_OBJLT_TXTRBLOCK;
            txtr->block.image = NULL;
            txtr->block.tmem = GS_PIX2TMEM(0, G_IM_SIZ_8b);
            txtr->block.tsize = GS_TB_TSIZE(CHARACTER_BLOCK_2_WIDTH * CHARACTER_BLOCK_2_HEIGHT, G_IM_SIZ_8b);
            txtr->block.tline = GS_TB_TLINE(CHARACTER_BLOCK_2_WIDTH, G_IM_SIZ_8b);
            txtr->block.sid = 0;
            txtr->block.flag = (u32)-1;
            txtr->block.mask = 0;
        }
    }

    for (i = 0; i < GAME_BUFFER_LEN; i++) {
        for (j = 0; j < BRICKTXTR_LEN; j++) {
            txtr = &brickTxtr[i][j];
            txtr->block.type = G_OBJLT_TXTRBLOCK;
            txtr->block.image = NULL;
            txtr->block.tmem = GS_PIX2TMEM(0, G_IM_SIZ_16b);
            txtr->block.tsize = GS_TB_TSIZE(CHARACTER_BLOCK_5_WIDTH * CHARACTER_BLOCK_5_HEIGHT, G_IM_SIZ_16b);
            txtr->block.tline = GS_TB_TLINE(CHARACTER_BLOCK_5_WIDTH, G_IM_SIZ_16b);
            txtr->block.sid = 0;
            txtr->block.flag = (u32)-1;
            txtr->block.mask = 0;
        }
    }

    for (i = 0; i < GAME_BUFFER_LEN; i++) {
        B_801F9C48_usa[i].block.type = G_OBJLT_TXTRBLOCK;
        B_801F9C48_usa[i].block.image = NULL;
        B_801F9C48_usa[i].block.tmem = GS_PIX2TMEM(0, G_IM_SIZ_8b);
        B_801F9C48_usa[i].block.tsize = GS_TB_TSIZE(CHARACTER_BLOCK_3_WIDTH * CHARACTER_BLOCK_3_HEIGHT, G_IM_SIZ_8b);
        B_801F9C48_usa[i].block.tline = GS_TB_TLINE(CHARACTER_BLOCK_3_WIDTH, G_IM_SIZ_8b);
        B_801F9C48_usa[i].block.sid = 0;
        B_801F9C48_usa[i].block.flag = (u32)-1;
        B_801F9C48_usa[i].block.mask = 0;
    }

    for (i = 0; i < GAME_BUFFER_LEN; i++) {
        B_801F9CC8_usa[i].block.type = G_OBJLT_TXTRBLOCK;
        B_801F9CC8_usa[i].block.image = NULL;
        B_801F9CC8_usa[i].block.tmem = GS_PIX2TMEM(0, G_IM_SIZ_8b);
        B_801F9CC8_usa[i].block.tsize = GS_TB_TSIZE(CHARACTER_BLOCK_4_WIDTH * CHARACTER_BLOCK_4_HEIGHT, G_IM_SIZ_8b);
        B_801F9CC8_usa[i].block.tline = GS_TB_TLINE(CHARACTER_BLOCK_4_WIDTH, G_IM_SIZ_8b);
        B_801F9CC8_usa[i].block.sid = 0;
        B_801F9CC8_usa[i].block.flag = (u32)-1;
        B_801F9CC8_usa[i].block.mask = 0;
    }

    B_801C6BDC_usa[0] = 0;
    B_801C6BDC_usa[1] = 0;
    if (right == -1) {
        total = 1;
    } else {
        total = 2;
    }

    for (i = 0; i < total; i++) {
        character_block_textures = Pon_Image_Heap;

        if (i == 0) {
            who = sp10[left / 100][B_801C6EE8_usa - 1];
        } else {
            who = sp10[right / 100][B_801C6E58_usa - 1];
        }

        switch (who) {
            case 0x32:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_block_5337F0),
                              SEGMENT_VRAM_SIZE(segment_character_block_5337F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_block_5337F0), character_block_textures,
                                  SEGMENT_ROM_SIZE(segment_character_block_5337F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_block_5337F0));
                break;

            case 0x33:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_block_53A9F0),
                              SEGMENT_VRAM_SIZE(segment_character_block_53A9F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_block_53A9F0), character_block_textures,
                                  SEGMENT_ROM_SIZE(segment_character_block_53A9F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_block_53A9F0));
                break;

            case 0x34:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_block_541BF0),
                              SEGMENT_VRAM_SIZE(segment_character_block_541BF0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_block_541BF0), character_block_textures,
                                  SEGMENT_ROM_SIZE(segment_character_block_541BF0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_block_541BF0));
                break;

            case 0x35:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_block_548DF0),
                              SEGMENT_VRAM_SIZE(segment_character_block_548DF0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_block_548DF0), character_block_textures,
                                  SEGMENT_ROM_SIZE(segment_character_block_548DF0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_block_548DF0));
                break;

            case 0x37:
                if (i == 0) {
                    B_801C6BDC_usa[1] = -1;
                } else {
                    B_801C6BDC_usa[0] = -1;
                }
                osInvalDCache(SEGMENT_VRAM_START(segment_character_block_54FFF0),
                              SEGMENT_VRAM_SIZE(segment_character_block_54FFF0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_block_54FFF0), character_block_textures,
                                  SEGMENT_ROM_SIZE(segment_character_block_54FFF0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_block_54FFF0));
                break;

            case 0x38:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_block_5571F0),
                              SEGMENT_VRAM_SIZE(segment_character_block_5571F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_block_5571F0), character_block_textures,
                                  SEGMENT_ROM_SIZE(segment_character_block_5571F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_block_5571F0));
                break;

            case 0x39:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_block_55E3F0),
                              SEGMENT_VRAM_SIZE(segment_character_block_55E3F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_block_55E3F0), character_block_textures,
                                  SEGMENT_ROM_SIZE(segment_character_block_55E3F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_block_55E3F0));
                break;

            case 0x36:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_block_5655F0),
                              SEGMENT_VRAM_SIZE(segment_character_block_5655F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_block_5655F0), character_block_textures,
                                  SEGMENT_ROM_SIZE(segment_character_block_5655F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_block_5655F0));
                break;

            case 0x3B:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_block_56C7F0),
                              SEGMENT_VRAM_SIZE(segment_character_block_56C7F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_block_56C7F0), character_block_textures,
                                  SEGMENT_ROM_SIZE(segment_character_block_56C7F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_block_56C7F0));
                break;

            case 0x3C:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_block_57ABF0),
                              SEGMENT_VRAM_SIZE(segment_character_block_57ABF0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_block_57ABF0), character_block_textures,
                                  SEGMENT_ROM_SIZE(segment_character_block_57ABF0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_block_57ABF0));
                break;

            case 0x3A:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_block_5739F0),
                              SEGMENT_VRAM_SIZE(segment_character_block_5739F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_block_5739F0), character_block_textures,
                                  SEGMENT_ROM_SIZE(segment_character_block_5739F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_block_5739F0));
                break;
        }

        if (i == 0) {
            B_801C7360_usa[1] = &character_block_textures->unk_0000;

            B_801AB8A8_usa[1][0] = &character_block_textures->unk_0800[0];
            B_801AB8A8_usa[1][1] = &character_block_textures->unk_0800[1];
            B_801AB8A8_usa[1][2] = &character_block_textures->unk_0800[2];
            B_801AB8A8_usa[1][3] = &character_block_textures->unk_0800[3];
            B_801AB8A8_usa[1][4] = &character_block_textures->unk_0800[4];
            B_801AB8A8_usa[1][5] = &character_block_textures->unk_0800[5];

            B_801F9E20_usa[1] = &character_block_textures->unk_3800;
            B_8021BA60_usa[0] = &character_block_textures->unk_3C00;
            B_801C6C9C_usa[0] = &character_block_textures->unk_4000;

            B_801C7070_usa[1][0] = &character_block_textures->unk_4200[0];
            B_801C7070_usa[1][1] = &character_block_textures->unk_4200[1];
            B_801C7070_usa[1][2] = &character_block_textures->unk_4200[2];

            B_801C6E70_usa[1].block.image = B_801C7360_usa[1];

            for (j = 0; j < BRICKTXTR_LEN; j++) {
                brickTxtr[1][j].block.image = B_801C7070_usa[1][j];
            }

            for (j = 0; j < B_801F9D00_USA_LEN; j++) {
                B_801F9D00_usa[1][j].block.image = B_801AB8A8_usa[1][j];
            }

            B_801F9C48_usa[1].block.image = B_801F9E20_usa[1];
            B_801F9CC8_usa[0].block.image = B_8021BA60_usa[0];
            B_801C7368_usa[0].block.image = B_801C6C9C_usa[0];
        } else {
            B_801C7360_usa[0] = &character_block_textures->unk_0000;

            B_801AB8A8_usa[0][0] = &character_block_textures->unk_0800[0];
            B_801AB8A8_usa[0][1] = &character_block_textures->unk_0800[1];
            B_801AB8A8_usa[0][2] = &character_block_textures->unk_0800[2];
            B_801AB8A8_usa[0][3] = &character_block_textures->unk_0800[3];
            B_801AB8A8_usa[0][4] = &character_block_textures->unk_0800[4];
            B_801AB8A8_usa[0][5] = &character_block_textures->unk_0800[5];

            B_801F9E20_usa[0] = &character_block_textures->unk_3800;
            B_8021BA60_usa[1] = &character_block_textures->unk_3C00;
            B_801C6C9C_usa[1] = &character_block_textures->unk_4000;

            B_801C7070_usa[0][0] = &character_block_textures->unk_4200[0];
            B_801C7070_usa[0][1] = &character_block_textures->unk_4200[1];
            B_801C7070_usa[0][2] = &character_block_textures->unk_4200[2];

            B_801C6E70_usa[0].block.image = B_801C7360_usa[0];

            for (j = 0; j < BRICKTXTR_LEN; j++) {
                brickTxtr[0][j].block.image = B_801C7070_usa[0][j];
            }

            for (j = 0; j < B_801F9D00_USA_LEN; j++) {
                B_801F9D00_usa[0][j].block.image = B_801AB8A8_usa[0][j];
            }

            B_801F9C48_usa[0].block.image = B_801F9E20_usa[0];
            B_801F9CC8_usa[1].block.image = B_8021BA60_usa[1];
            B_801C7368_usa[1].block.image = B_801C6C9C_usa[1];
        }
    }
}

s32 ReturnAttackTexValue(attack_t *attack, s32 type, s32 lev, s32 pos) {
    char *ptr;
    s32 actual;
    s32 value;

    if ((gTheGame.unk_9C0C == 2) && (type >= 0xE)) {
        type -= 2;
    }

    switch (type) {
        case 0x1:
            ptr = attack_combo4;
            break;
        case 0x2:
            ptr = attack_combo5;
            break;
        case 0x3:
            ptr = attack_combo6;
            break;
        case 0x4:
            ptr = attack_combo7;
            break;
        case 0xA:
            ptr = attack_combo7;
            break;
        case 0x9:
            ptr = attack_chain3[0];
            break;
        case 0xB:
            if (gTheGame.unk_9C0C == 1) {
                ptr = attack_chain3[lev];
            } else {
                ptr = ring_chain3;
            }
            break;
        case 0xC:
            ptr = attack_chain4;
            break;
        case 0xD:
            ptr = attack_chain5;
            break;
        case 0xE:
            ptr = attack_chain6;
            break;
        case 0xF:
            ptr = attack_chain7;
            break;
        case 0x10:
            ptr = attack_chain8;
            break;
        case 0x11:
            ptr = attack_chain9;
            break;
        case 0x12:
            ptr = attack_chain10;
            break;
        case 0x13:
            ptr = attack_chain11;
            break;
        case 0x14:
            ptr = attack_chain12;
            break;
        case 0x15:
            ptr = attack_chain13;
            break;
        case 0x16:
            ptr = attack_chain13;
            break;
        default:
            return 0;
    }

    if ((gTheGame.unk_9C0C == 1) || (type < 0xC)) {
        if (type >= 0xC) {
            value = ptr[lev];
            switch (value) {
                case 0x1:
                    value = attackRow1[pos];
                    break;
                case 0x2:
                    value = attackRow2[pos];
                    break;
                case 0x3:
                    value = attackRow3[pos];
                    break;
                case 0x4:
                    value = attackRow4[pos];
                    break;
                case 0x5:
                    value = attackRow5[pos];
                    break;
                case 0x6:
                    value = attackRow6[pos];
                    break;
                case 0x7:
                    value = attackRow7[pos];
                    break;
                case 0x8:
                    value = attackRow8[pos];
                    break;
                case 0x9:
                    value = attackRow9[pos];
                    break;
                default:
                    break;
            }
        } else {
            value = ptr[pos];
        }

        return value;
    }

    if (attack->unk_18 >= 0xA) {
        actual = attack->unk_18 - 0xA;
    } else {
        actual = attack->unk_18 + 8;
    }

    if (attack->type > 0x16) {
        type = attack->type - 0x16;
    } else {
        type = attack->type;
    }

    if ((type == 0xC) || (type == 0xD)) {
        if (pos == actual) {
            pos = 2;
        } else if (pos == (actual + 1)) {
            pos = 3;
        } else {
            pos = 1;
        }
    } else if (pos == actual) {
        pos = 2;
    } else if (pos == (actual + 1)) {
        pos = 3;
    } else if (actual % 2 == 0) {
        if (pos % 2 == 0) {
            pos = 4;
        } else {
            pos = 1;
        }
    } else if (pos % 2 == 1) {
        pos = 4;
    } else {
        pos = 1;
    }

    switch (type) {
        case 0xC:
            value = attack_combo7[pos];
            break;

        case 0xD:
            value = attack_chain3[lev][pos];
            break;

        default:
            value = ptr[lev];
            switch (value) {
                case 0x1:
                    value = attackRow1[pos];
                    break;
                case 0x2:
                    value = attackRow2[pos];
                    break;
                case 0x3:
                    value = attackRow3[pos];
                    break;
                case 0x4:
                    value = attackRow4[pos];
                    break;
                case 0x5:
                    value = attackRow5[pos];
                    break;
                case 0x6:
                    value = attackRow6[pos];
                    break;
                case 0x7:
                    value = attackRow7[pos];
                    break;
                case 0x8:
                    value = attackRow8[pos];
                    break;
                case 0x9:
                    value = attackRow9[pos];
                    break;
                default:
                    break;
            }
            break;
    }

    return value;
}
