/**
 * Original filename: character.c
 */

#include "character.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "001F10.h"

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
    uObjTxtr *temp_v0;
    void *temp_s1;
    s32 total;
    s32 who;
    s32 i;
    s32 j;

    for (i = 0; i < GAME_BUFFER_LEN; i++) {
        B_801C7368_usa[i].tlut.type = G_OBJLT_TLUT;
        B_801C7368_usa[i].tlut.image = NULL;
        B_801C7368_usa[i].tlut.phead = GS_PAL_HEAD(0);
        B_801C7368_usa[i].tlut.pnum = GS_PAL_NUM(256);
        B_801C7368_usa[i].tlut.zero = 0;
        B_801C7368_usa[i].tlut.sid = 0;
        B_801C7368_usa[i].tlut.flag = (u32)-1;
        B_801C7368_usa[i].tlut.mask = 0;
    }

    for (i = 0; i < GAME_BUFFER_LEN; i++) {
        B_801C6E70_usa[i].block.type = G_OBJLT_TXTRBLOCK;
        B_801C6E70_usa[i].block.image = NULL;
        B_801C6E70_usa[i].block.tmem = 0;      // TODO
        B_801C6E70_usa[i].block.tsize = 0xFF;  // TODO
        B_801C6E70_usa[i].block.tline = 0x100; // TODO
        B_801C6E70_usa[i].block.sid = 0;
        B_801C6E70_usa[i].block.flag = (u32)-1;
        B_801C6E70_usa[i].block.mask = 0;
    }

    for (i = 0; i < GAME_BUFFER_LEN; i++) {
        for (j = 0; j < B_801F9D00_USA_LEN; j++) {
            temp_v0 = &B_801F9D00_usa[i][j];
            temp_v0->block.type = G_OBJLT_TXTRBLOCK;
            temp_v0->block.image = NULL;
            temp_v0->block.tmem = 0;      // TODO
            temp_v0->block.tsize = 0xFF;  // TODO
            temp_v0->block.tline = 0x100; // TODO
            temp_v0->block.sid = 0;
            temp_v0->block.flag = (u32)-1;
            temp_v0->block.mask = 0;
        }
    }

    for (i = 0; i < GAME_BUFFER_LEN; i++) {
        for (j = 0; j < BRICKTXTR_LEN; j++) {
            temp_v0 = &brickTxtr[i][j];
            temp_v0->block.type = G_OBJLT_TXTRBLOCK;
            temp_v0->block.image = NULL;
            temp_v0->block.tmem = 0;      // TODO
            temp_v0->block.tsize = 0x1FF; // TODO
            temp_v0->block.tline = 0x80;  // TODO
            temp_v0->block.sid = 0;
            temp_v0->block.flag = (u32)-1;
            temp_v0->block.mask = 0;
        }
    }

    for (i = 0; i < GAME_BUFFER_LEN; i++) {
        B_801F9C48_usa[i].block.type = G_OBJLT_TXTRBLOCK;
        B_801F9C48_usa[i].block.image = NULL;
        B_801F9C48_usa[i].block.tmem = 0;      // TODO
        B_801F9C48_usa[i].block.tsize = 0x7F;  // TODO
        B_801F9C48_usa[i].block.tline = 0x100; // TODO
        B_801F9C48_usa[i].block.sid = 0;
        B_801F9C48_usa[i].block.flag = (u32)-1;
        B_801F9C48_usa[i].block.mask = 0;
    }

    for (i = 0; i < 2; i++) {
        B_801F9CC8_usa[i].block.type = G_OBJLT_TXTRBLOCK;
        B_801F9CC8_usa[i].block.image = NULL;
        B_801F9CC8_usa[i].block.tmem = 0;      // TODO
        B_801F9CC8_usa[i].block.tsize = 0x7F;  // TODO
        B_801F9CC8_usa[i].block.tline = 0x100; // TODO
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
        temp_s1 = Pon_Image_Heap;

        if (i == 0) {
            who = sp10[left / 100][B_801C6EE8_usa - 1];
        } else {
            who = sp10[right / 100][B_801C6E58_usa - 1];
        }

        switch (who) {
            case 0x32:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_5337F0),
                              SEGMENT_VRAM_SIZE(segment_character_5337F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_5337F0), temp_s1,
                                  SEGMENT_ROM_SIZE(segment_character_5337F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_5337F0));
                break;

            case 0x33:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_53A9F0),
                              SEGMENT_VRAM_SIZE(segment_character_53A9F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_53A9F0), temp_s1,
                                  SEGMENT_ROM_SIZE(segment_character_53A9F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_53A9F0));
                break;

            case 0x34:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_541BF0),
                              SEGMENT_VRAM_SIZE(segment_character_541BF0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_541BF0), temp_s1,
                                  SEGMENT_ROM_SIZE(segment_character_541BF0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_541BF0));
                break;

            case 0x35:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_548DF0),
                              SEGMENT_VRAM_SIZE(segment_character_548DF0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_548DF0), temp_s1,
                                  SEGMENT_ROM_SIZE(segment_character_548DF0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_548DF0));
                break;

            case 0x37:
                if (i == 0) {
                    B_801C6BDC_usa[1] = -1;
                } else {
                    B_801C6BDC_usa[0] = -1;
                }
                osInvalDCache(SEGMENT_VRAM_START(segment_character_54FFF0),
                              SEGMENT_VRAM_SIZE(segment_character_54FFF0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_54FFF0), temp_s1,
                                  SEGMENT_ROM_SIZE(segment_character_54FFF0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_54FFF0));
                break;

            case 0x38:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_5571F0),
                              SEGMENT_VRAM_SIZE(segment_character_5571F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_5571F0), temp_s1,
                                  SEGMENT_ROM_SIZE(segment_character_5571F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_5571F0));
                break;

            case 0x39:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_55E3F0),
                              SEGMENT_VRAM_SIZE(segment_character_55E3F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_55E3F0), temp_s1,
                                  SEGMENT_ROM_SIZE(segment_character_55E3F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_55E3F0));
                break;

            case 0x36:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_5655F0),
                              SEGMENT_VRAM_SIZE(segment_character_5655F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_5655F0), temp_s1,
                                  SEGMENT_ROM_SIZE(segment_character_5655F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_5655F0));
                break;

            case 0x3B:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_56C7F0),
                              SEGMENT_VRAM_SIZE(segment_character_56C7F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_56C7F0), temp_s1,
                                  SEGMENT_ROM_SIZE(segment_character_56C7F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_56C7F0));
                break;

            case 0x3C:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_57ABF0),
                              SEGMENT_VRAM_SIZE(segment_character_57ABF0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_57ABF0), temp_s1,
                                  SEGMENT_ROM_SIZE(segment_character_57ABF0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_57ABF0));
                break;

            case 0x3A:
                osInvalDCache(SEGMENT_VRAM_START(segment_character_5739F0),
                              SEGMENT_VRAM_SIZE(segment_character_5739F0));
                func_80001310_usa(SEGMENT_ROM_START(segment_character_5739F0), temp_s1,
                                  SEGMENT_ROM_SIZE(segment_character_5739F0));
                Pon_Image_Heap = (void *)((uintptr_t)Pon_Image_Heap + SEGMENT_ROM_SIZE(segment_character_5739F0));
                break;
        }

        if (i == 0) {
            B_801C7360_usa[1] = temp_s1 + 0x0;

            B_801AB8A8_usa[1][0] = temp_s1 + 0x800;
            B_801AB8A8_usa[1][1] = (void *)(temp_s1 + 0x1000);
            B_801AB8A8_usa[1][2] = (void *)(temp_s1 + 0x1800);
            B_801AB8A8_usa[1][3] = (void *)(temp_s1 + 0x2000);
            B_801AB8A8_usa[1][4] = (void *)(temp_s1 + 0x2800);
            B_801AB8A8_usa[1][5] = (void *)(temp_s1 + 0x3000);

            B_801F9E20_usa[1] = temp_s1 + 0x3800;
            B_8021BA60_usa[0] = temp_s1 + 0x3C00;
            B_801C6C9C_usa[0] = temp_s1 + 0x4000;

            B_801C7070_usa[1][0] = temp_s1 + 0x4200;
            B_801C7070_usa[1][1] = (void *)(temp_s1 + 0x5200);
            B_801C7070_usa[1][2] = (void *)(temp_s1 + 0x6200);

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
            B_801C7360_usa[0] = temp_s1 + 0x0;

            B_801AB8A8_usa[0][0] = temp_s1 + 0x800;
            B_801AB8A8_usa[0][1] = (void *)(temp_s1 + 0x1000);
            B_801AB8A8_usa[0][2] = (void *)(temp_s1 + 0x1800);
            B_801AB8A8_usa[0][3] = (void *)(temp_s1 + 0x2000);
            B_801AB8A8_usa[0][4] = (void *)(temp_s1 + 0x2800);
            B_801AB8A8_usa[0][5] = (void *)(temp_s1 + 0x3000);

            B_801F9E20_usa[0] = temp_s1 + 0x3800;
            B_8021BA60_usa[1] = temp_s1 + 0x3C00;
            B_801C6C9C_usa[1] = temp_s1 + 0x4000;

            B_801C7070_usa[0][0] = temp_s1 + 0x4200;
            B_801C7070_usa[0][1] = (void *)(temp_s1 + 0x5200);
            B_801C7070_usa[0][2] = (void *)(temp_s1 + 0x6200);

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

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/character", ReturnAttackTexValue);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/character", ReturnAttackTexValue);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/character", ReturnAttackTexValue);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/character", ReturnAttackTexValue);
#endif
