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

#if VERSION_USA
#if 0
// ROM and VRAM addresses
extern UNK_TYPE D_1070A60_1;
extern UNK_TYPE D_1077C60_1;
extern UNK_TYPE D_1070A60_2;
extern UNK_TYPE D_1077C60_2;
extern UNK_TYPE D_1070A60_3;
extern UNK_TYPE D_1077C60_3;
extern UNK_TYPE D_1070A60_4;
extern UNK_TYPE D_1077C60_4;
extern UNK_TYPE D_1070A60_5;
extern UNK_TYPE D_1077C60_5;
extern UNK_TYPE D_1070A60_6;
extern UNK_TYPE D_1077C60_6;
extern UNK_TYPE D_1070A60_7;
extern UNK_TYPE D_1077C60_7;
extern UNK_TYPE D_1070A60_8;
extern UNK_TYPE D_1077C60_8;
extern UNK_TYPE D_1070A60_9;
extern UNK_TYPE D_1077C60_9;
extern UNK_TYPE D_1070A60_A;
extern UNK_TYPE D_1077C60_A;
extern UNK_TYPE D_1070A60_B;
extern UNK_TYPE D_1077C60_B;

extern UNK_TYPE D_5337F0;
extern UNK_TYPE D_53A9F0;
extern UNK_TYPE D_541BF0;
extern UNK_TYPE D_548DF0;
extern UNK_TYPE D_54FFF0;
extern UNK_TYPE D_5571F0;
extern UNK_TYPE D_55E3F0;
extern UNK_TYPE D_5655F0;
extern UNK_TYPE D_56C7F0;
extern UNK_TYPE D_5739F0;
extern UNK_TYPE D_57ABF0;
extern UNK_TYPE D_581DF0;

void InitCharacter(s32 left, s32 right) {
    s32 sp10[17][3] = {
        { 0x32, 0x36, 0x38 },
        { 0x33, 0x37, 0x36 },
        { 0x34, 0x37, 0x33 },
        { 0x36, 0x36, 0x36 },
        { 0x32, 0x32, 0x32 },
        { 0x38, 0x38, 0x33 },
        { 0x39, 0x32, 0x33 },
        { 0x35, 0x35, 0x35 },
        { 0x37, 0x37, 0x37 },
        { 0x36, 0x39, 0x39 },
        { 0x33, 0x33, 0x33 },
        { 0x3A, 0x34, 0x33 },
        { 0x32, 0x37, 0x39 },
        { 0x3B, 0x36, 0x3B },
        { 0x34, 0x3C, 0x3C },
        { 0x33, 0x37, 0x36 },
        { 0x32, 0x36, 0x38 },
    };
    s32 var_s2;
    void *temp_s1;

    uObjTxtr *temp_v0;

    s32 var_a1;
    s32 var_fp;
    s32 var_v0;
    s32 var_v1_7;
    u32 var_s0;


    for (var_s2 = 0; var_s2 < GAME_BUFFER_LEN; var_s2++) {
        B_801C7368_usa[var_s2].tlut.type  = G_OBJLT_TLUT;
        B_801C7368_usa[var_s2].tlut.image = NULL;
        B_801C7368_usa[var_s2].tlut.phead = GS_PAL_HEAD(0);
        B_801C7368_usa[var_s2].tlut.pnum = GS_PAL_NUM(256);
        B_801C7368_usa[var_s2].tlut.zero = 0;
        B_801C7368_usa[var_s2].tlut.sid = 0;
        B_801C7368_usa[var_s2].tlut.flag = (u32)-1;
        B_801C7368_usa[var_s2].tlut.mask = 0;
    }

    for (var_s2 = 0; var_s2 < GAME_BUFFER_LEN; var_s2++) {
        B_801C6E70_usa[var_s2].block.type = G_OBJLT_TXTRBLOCK;
        B_801C6E70_usa[var_s2].block.image = NULL;
        B_801C6E70_usa[var_s2].block.tmem = 0; // TODO
        B_801C6E70_usa[var_s2].block.tsize = 0xFF; // TODO
        B_801C6E70_usa[var_s2].block.tline = 0x100; // TODO
        B_801C6E70_usa[var_s2].block.sid = 0;
        B_801C6E70_usa[var_s2].block.flag = (u32)-1;
        B_801C6E70_usa[var_s2].block.mask = 0;
    }

    for (var_s2 = 0; var_s2 < GAME_BUFFER_LEN; var_s2++) {
        for (var_a1 = 0; var_a1 < 6; var_a1++) {
            temp_v0 = &B_801F9D00_usa[var_s2][var_a1];
            temp_v0->block.type = G_OBJLT_TXTRBLOCK;
            temp_v0->block.image = NULL;
            temp_v0->block.tmem = 0; // TODO
            temp_v0->block.tsize = 0xFF; // TODO
            temp_v0->block.tline = 0x100; // TODO
            temp_v0->block.sid = 0;
            temp_v0->block.flag = (u32)-1;
            temp_v0->block.mask = 0;
        }
    }

    for (var_s2 = 0; var_s2 < GAME_BUFFER_LEN; var_s2++) {
        for (var_a1 = 0; var_a1 < 3; var_a1++) {
            temp_v0 = &brickTxtr[var_s2][var_a1];
            temp_v0->block.type = G_OBJLT_TXTRBLOCK;
            temp_v0->block.image = NULL;
            temp_v0->block.tmem = 0; // TODO
            temp_v0->block.tsize = 0x1FF; // TODO
            temp_v0->block.tline = 0x80; // TODO
            temp_v0->block.sid = 0;
            temp_v0->block.flag = (u32)-1;
            temp_v0->block.mask = 0;
        }
    }

    for (var_s2 = 0; var_s2 < GAME_BUFFER_LEN; var_s2++) {
        B_801F9C48_usa[var_s2].block.type = G_OBJLT_TXTRBLOCK;
        B_801F9C48_usa[var_s2].block.image = NULL;
        B_801F9C48_usa[var_s2].block.tmem = 0; // TODO
        B_801F9C48_usa[var_s2].block.tsize = 0x7F; // TODO
        B_801F9C48_usa[var_s2].block.tline = 0x100; // TODO
        B_801F9C48_usa[var_s2].block.sid = 0;
        B_801F9C48_usa[var_s2].block.flag = (u32)-1;
        B_801F9C48_usa[var_s2].block.mask = 0;
    }

    for (var_s2 = 0; var_s2 < 2; var_s2++) {
        B_801F9CC8_usa[var_s2].block.type = G_OBJLT_TXTRBLOCK;
        B_801F9CC8_usa[var_s2].block.image = NULL;
        B_801F9CC8_usa[var_s2].block.tmem = 0; // TODO
        B_801F9CC8_usa[var_s2].block.tsize = 0x7F; // TODO
        B_801F9CC8_usa[var_s2].block.tline = 0x100; // TODO
        B_801F9CC8_usa[var_s2].block.sid = 0;
        B_801F9CC8_usa[var_s2].block.flag = (u32)-1;
        B_801F9CC8_usa[var_s2].block.mask = 0;
    }

    B_801C6BDC_usa[0] = 0;
    B_801C6BDC_usa[1] = 0;
    var_fp = 2;
    if (right == -1) {
        var_fp = 1;
    }

    for (var_s2 = 0; var_s2 < var_fp; var_s2++) {
        temp_s1 = Pon_Image_Heap;

        if (var_s2 == 0) {
            var_v1_7 = left / 100;
            var_v0 = B_801C6EE8_usa;
        } else {
            var_v1_7 = right / 100;
            var_v0 = B_801C6E58_usa;
        }

        switch (sp10[var_v1_7][var_v0-1]) {
            case 0x32:
                osInvalDCache(&D_1070A60_1, (u32)&D_1077C60_1 - (u32)&D_1070A60_1);
                var_s0 = (u32)&D_53A9F0 - (u32)&D_5337F0;
                func_80001310_usa((u32) &D_5337F0, temp_s1, var_s0);
                Pon_Image_Heap += var_s0;
                break;

            case 0x33:
                osInvalDCache(&D_1070A60_2, (u32)&D_1077C60_2 - (u32)&D_1070A60_2);
                var_s0 = (u32)&D_541BF0 - (u32)&D_53A9F0;
                func_80001310_usa((u32) &D_53A9F0, temp_s1, var_s0);
                Pon_Image_Heap += var_s0;
                break;

            case 0x34:
                osInvalDCache(&D_1070A60_3, (u32)&D_1077C60_3 - (u32)&D_1070A60_3);
                var_s0 = (u32)&D_548DF0 - (u32)&D_541BF0;
                func_80001310_usa((u32) &D_541BF0, temp_s1, var_s0);
                Pon_Image_Heap += var_s0;
                break;

            case 0x35:
                osInvalDCache(&D_1070A60_4, (u32)&D_1077C60_4 - (u32)&D_1070A60_4);
                var_s0 = (u32)&D_54FFF0 - (u32)&D_548DF0;
                func_80001310_usa((u32) &D_548DF0, temp_s1, var_s0);
                Pon_Image_Heap += var_s0;
                break;

            case 0x37:
                if (var_s2 == 0) {
                    B_801C6BDC_usa[1] = -1;
                } else {
                    B_801C6BDC_usa[0] = -1;
                }
                osInvalDCache(&D_1070A60_5, (u32)&D_1077C60_5 - (u32)&D_1070A60_5);
                var_s0 = (u32)&D_5571F0 - (u32)&D_54FFF0;
                func_80001310_usa((u32) &D_54FFF0, temp_s1, var_s0);
                Pon_Image_Heap += var_s0;
                break;

            case 0x38:
                osInvalDCache(&D_1070A60_6, (u32)&D_1077C60_6 - (u32)&D_1070A60_6);
                var_s0 = (u32)&D_55E3F0 - (u32)&D_5571F0;
                func_80001310_usa((u32) &D_5571F0, temp_s1, var_s0);
                Pon_Image_Heap += var_s0;
                break;

            case 0x39:
                osInvalDCache(&D_1070A60_7, (u32)&D_1077C60_7 - (u32)&D_1070A60_7);
                var_s0 = (u32)&D_5655F0 - (u32)&D_55E3F0;
                func_80001310_usa((u32) &D_55E3F0, temp_s1, var_s0);
                Pon_Image_Heap += var_s0;
                break;

            case 0x36:
                osInvalDCache(&D_1070A60_8, (u32)&D_1077C60_8 - (u32)&D_1070A60_8);
                var_s0 = (u32)&D_56C7F0 - (u32)&D_5655F0;
                func_80001310_usa((u32) &D_5655F0, temp_s1, var_s0);
                Pon_Image_Heap += var_s0;
                break;

            case 0x3B:
                osInvalDCache(&D_1070A60_9, (u32)&D_1077C60_9 - (u32)&D_1070A60_9);
                var_s0 = (u32)&D_5739F0 - (u32)&D_56C7F0;
                func_80001310_usa((u32) &D_56C7F0, temp_s1, var_s0);
                Pon_Image_Heap += var_s0;
                break;

            case 0x3C:
                osInvalDCache(&D_1070A60_A, (u32)&D_1077C60_A - (u32)&D_1070A60_A);
                var_s0 = (u32)&D_581DF0 - (u32)&D_57ABF0;
                func_80001310_usa((u32) &D_57ABF0, temp_s1, var_s0);
                Pon_Image_Heap += var_s0;
                break;

            case 0x3A:
                osInvalDCache(&D_1070A60_B, (u32)&D_1077C60_B - (u32)&D_1070A60_B);
                var_s0 = (u32)&D_57ABF0 - (u32)&D_5739F0;
                func_80001310_usa((u32) &D_5739F0, temp_s1, var_s0);
                Pon_Image_Heap += var_s0;
                break;
        }

        if (var_s2 == 0) {
            B_801C7360_usa[1] = temp_s1;

            B_801AB8A8_usa[1][0] = temp_s1 + 0x800;
            B_801AB8A8_usa[1][1] = (void *) (temp_s1 + 0x1000);
            B_801AB8A8_usa[1][2] = (void *) (temp_s1 + 0x1800);
            B_801AB8A8_usa[1][3] = (void *) (temp_s1 + 0x2000);
            B_801AB8A8_usa[1][4] = (void *) (temp_s1 + 0x2800);
            B_801AB8A8_usa[1][5] = (void *) (temp_s1 + 0x3000);

            B_801F9E20_usa[1] = temp_s1 + 0x3800;
            B_8021BA60_usa[0] = temp_s1 + 0x3C00;
            B_801C6C9C_usa[0] = temp_s1 + 0x4000;

            B_801C7070_usa[1][0] = temp_s1 + 0x4200;
            B_801C7070_usa[1][1] = (void *) (temp_s1 + 0x5200);
            B_801C7070_usa[1][2] = (void *) (temp_s1 + 0x6200);

            B_801C6E70_usa[1].block.image = (u64 *) temp_s1;

            for (var_a1 = 0; var_a1 < 3; var_a1++) {
                brickTxtr[1][var_a1].block.image = B_801C7070_usa[1][var_a1];
            }

            for (var_a1 = 0; var_a1 < 6; var_a1++) {
                B_801F9D00_usa[1][var_a1].block.image = B_801AB8A8_usa[1][var_a1];
            }

            B_801F9C48_usa[1].block.image = B_801F9E20_usa[1];
            B_801F9CC8_usa[0].block.image = B_8021BA60_usa[0];
            B_801C7368_usa[0].block.image = B_801C6C9C_usa[0];
        } else {
            B_801C7360_usa[0] = temp_s1;

            B_801AB8A8_usa[0][0] = temp_s1 + 0x800;
            B_801AB8A8_usa[0][1] = (void *) (temp_s1 + 0x1000);
            B_801AB8A8_usa[0][2] = (void *) (temp_s1 + 0x1800);
            B_801AB8A8_usa[0][3] = (void *) (temp_s1 + 0x2000);
            B_801AB8A8_usa[0][4] = (void *) (temp_s1 + 0x2800);
            B_801AB8A8_usa[0][5] = (void *) (temp_s1 + 0x3000);

            B_801F9E20_usa[0] = temp_s1 + 0x3800;
            B_8021BA60_usa[1] = temp_s1 + 0x3C00;
            B_801C6C9C_usa[1] = temp_s1 + 0x4000;

            B_801C7070_usa[0][0] = temp_s1 + 0x4200;
            B_801C7070_usa[0][1] = (void *) (temp_s1 + 0x5200);
            B_801C7070_usa[0][2] = (void *) (temp_s1 + 0x6200);

            B_801C6E70_usa[0].block.image = (u64 *) temp_s1;

            for (var_a1 = 0; var_a1 < 3; var_a1++) {
                brickTxtr[0][var_a1].block.image = B_801C7070_usa[0][var_a1];
            }

            for (var_a1 = 0; var_a1 < 6; var_a1++) {
                B_801F9D00_usa[0][var_a1].block.image = B_801AB8A8_usa[0][var_a1];
            }

            B_801F9C48_usa[0].block.image = B_801F9E20_usa[0];
            B_801F9CC8_usa[1].block.image = B_8021BA60_usa[1];
            B_801C7368_usa[1].block.image = B_801C6C9C_usa[1];
        }
    }
}
#else
INCLUDE_RODATA("asm/usa/nonmatchings/main/character", RO_800C5C18_usa);
INCLUDE_ASM("asm/usa/nonmatchings/main/character", InitCharacter);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/character", ReturnAttackTexValue);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/character", RO_800C5EC8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/character", InitCharacter);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/character", ReturnAttackTexValue);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/character", RO_800C4528_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/character", InitCharacter);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/character", ReturnAttackTexValue);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/character", RO_800BB4E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/character", InitCharacter);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/character", ReturnAttackTexValue);
#endif
