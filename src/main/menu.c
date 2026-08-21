/**
 * Original filename: menu.c
 */

#include "menu.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "boot_main.h"
#include "buffers.h"
#include "image.h"
#include "info.h"
#include "peel.h"
#include "screen.h"
#include "segment_symbols.h"
#include "sfxlimit.h"
#include "sound.h"
#include "tetsound.h"
#include "the_game.h"

typedef enum enum_TypeMenu {
    MT_NONE = 0,
    MT_MANY = 1,
    MT_PLAY = 2,
    MT_MAIN = 3,
    MT_1P = 4,
    MT_1P_ENDLESS_NAME = 5,
    MT_1P_ENDLESS_LEVEL = 6,
    MT_1P_ENDLESS_CHARACTER = 7,
    MT_1P_VS_NAME = 8,
    MT_1P_VS_LEVEL = 9,
    MT_1P_ATTACK_NAME = 10,
    MT_1P_ATTACK_LEVEL = 11,
    MT_1P_ATTACK_CHARACTER = 12,
    MT_1P_CLEAR_NAME = 13,
    MT_1P_CLEAR_2D3D = 14,
    MT_1P_CLEAR_XTRA = 15,
    MT_1P_CLEAR_XTRATALK = 16,
    MT_1P_CLEAR_LEVEL = 17,
    MT_1P_PUZZLE_NAME = 18,
    MT_1P_PUZZLE_LEVEL = 19,
    MT_1P_PUZZLE_STAGE1 = 20,
    MT_1P_PUZZLE_STAGE2 = 21,
    MT_1P_PUZZLE_STAGE3 = 22,
    MT_1P_PUZZLE_STAGE3D = 23,
    MT_1P_PUZZLE_STAGE4 = 24,
    MT_1P_PUZZLE_STAGE5 = 25,
    MT_1P_PUZZLE_CUSTOM = 26,
    MT_2P = 27,
    MT_2P_VS_NAME = 28,
    MT_2P_VS_LEVEL = 29,
    MT_2P_VS_CHARACTER = 30,
    MT_2P_ATTACK_NAME = 31,
    MT_2P_ATTACK_LEVEL = 32,
    MT_2P_ATTACK_CHARACTER = 33,
    MT_2P_CLEAR_NAME = 34,
    MT_2P_CLEAR_LEVEL = 35,
    MT_2P_CLEAR_CHARACTER = 36,
    MT_4P = 37,
    MT_4P_LEVEL = 38,
    MT_4P_CHARACTER = 39,
    MT_HOWTO = 40,
    MT_HOWTO_CONTROLLER = 41,
    MT_PRACTICE = 42,
    MT_PRACTICE_PAGEDEMO = 43,
    MT_PRACTICE_PAGEMIMIC = 44,
    MT_PRACTICE_SUPEREASY = 45,
    MT_NAME = 46,
    MT_NAME_ENTRY = 47,
    MT_NAME_DELETE = 48,
    MT_OPTIONS = 49,
    MT_OPTIONS_RECORDNAME = 50,
    MT_OPTIONS_RECORDSHOW = 51,
    MT_OPTIONS_EDITOR = 52,
    MT_OPTIONS_EDITORNAME = 53,
    MT_OPTIONS_EDITOR_HOW = 54,
    MT_OPTIONS_CHARACTER = 55,
    MT_OPTIONS_CHARACTERSHOW = 56,
    MT_OPTIONS_SETTINGS = 57,
    MT_OPTIONS_SOUND = 58,
    MT_OPTIONS_SCREEN = 59,
    MT_MULTI_PLAY = 60,
    MT_HOW_MULTI_PLAYER_ATTACK = 61,
    MT_HOW_MULTI_PLAYER_SCORE = 62,
    MT_HOW_MULTI_PLAYER_CLEAR = 63,
    MT_ATTACK_BATTLE = 64,
    MT_SCORE_ATTACK = 65,
    MT_STAGE_CLEAR = 66,
} enum_TypeMenu;

typedef UNK_RET struct_gaMenuData_pfInit(s32);

typedef struct struct_gaMenuData {
    /* 0x00 */ char *szName;                     /* Original name: szName */
    /* 0x04 */ struct_gaMenuData_pfInit *pfInit; /* Original name: pfInit */
    /* 0x08 */ screenDraw_callback *pfDraw;      /* Original name: pfDraw */
    /* 0x0C */ UNK_PAD unk_0C[0x4];
    /* 0x10 */ enum_TypeMenu eType; /* Original name: eType */
    /* 0x14 */ UNK_PAD unk_14[0x4];
} struct_gaMenuData; // size = 0x18

nbool menuFind(struct_gaMenuData **ppData, enum_TypeMenu eType);

nbool menuSetScreen(enum_TypeMenu eType, s32 bBack);
void func_8000A940_usa(s32 arg0, s32 arg1, s32 arg2);

// menuUpdateSound?
void func_800175F8_usa(void);

s32 menuLoadData(void);
void func_800194DC_usa(enum_TypeMenu arg0);

extern s32 D_800B5A14_usa;

/**
 * Original name: gnPositionFairyX
 */
extern s32 gnPositionFairyX;
/**
 * Original name: gnPositionFairyY
 */
extern s32 gnPositionFairyY;

/**
 * Original name: gnSkipFrame
 */
extern s32 gnSkipFrame;
/**
 * Original name: gnCountMenu
 */
extern s32 gnCountMenu;

/**
 * Original name: geTypeMenu
 */
extern enum_TypeMenu geTypeMenu;

/**
 * Original name: gaMenuData
 */
extern struct_gaMenuData gaMenuData[0x2D];

// gaeTypeMenu?
extern enum_TypeMenu B_8018A850_usa[];

extern s32 B_8018A81C_usa;
/**
 * Original name: gbAudioChanged
 */
extern s32 gbAudioChanged;
/**
 * Original name: giScreenMenu
 */
extern s32 giScreenMenu;
/**
 * Original name: giScreenMenuLast
 */
extern s32 giScreenMenuLast;

extern s32 B_8018A854_usa;
extern s32 B_8018A8D0_usa;
extern s32 B_8018A8D4_usa;
extern s32 B_8018A8F4_usa;
extern s32 B_8018A8FC_usa;
extern s32 B_8018A900_usa;

/**
 * Original name: gnTickMenu
 */
extern s32 gnTickMenu;
extern s32 B_8018A910_usa;
extern s32 B_8018A914_usa;
extern s32 B_8018A918_usa;
extern s32 B_8018A924_usa;
extern void *B_8018A928_usa;
extern OSMesgQueue B_8018A948_usa;
extern s32 B_8018ABA8_usa;
extern s32 B_8018ABAC_usa;

extern char B_8018A960_usa[];

extern s32 B_8018A830_usa;
extern player_t_unk_002 B_8018A8D8_usa;
extern s16 B_8018A8E6_usa;
extern s32 B_8018A91C_usa;
extern OSIoMesg B_8018A930_usa;
extern UNK_TYPE B_8018A96F_usa;
extern s32 D_800B5A18_usa;
extern const char RO_STR_800C3D68_usa[];

extern s32 B_8018A82C_usa;
/**
 * Original name: gnPlayerCount
 */
extern s32 gnPlayerCount;
/**
 * Original name: ganPick
 */
extern s32 ganPick[2]; // static
/**
 * Original name: anTagBlinkLast
 */
extern u32 anTagBlinkLast[2]; // static

typedef struct struct_800072A0_usa_arg0_unk_58 {
    /* 0x0 */ UNK_PAD unk_C[0xC];
} struct_800072A0_usa_arg0_unk_58; // size = 0xC

typedef struct struct_800072A0_usa_arg0 {
    /* 0x00 */ u32 unk_00; // TODO: unsure if u32 is correct
    /* 0x04 */ UNK_TYPE unk_04;
    /* 0x08 */ UNK_TYPE unk_08;
    /* 0x0C */ UNK_TYPE unk_0C;
    /* 0x10 */ UNK_TYPE unk_10;
    /* 0x14 */ UNK_TYPE unk_14;
    /* 0x18 */ UNK_TYPE unk_18;
    /* 0x1C */ UNK_TYPE unk_1C; // size_t?
    /* 0x20 */ UNK_TYPE unk_20;
    /* 0x24 */ u16 unk_24;
    /* 0x26 */ UNK_PAD unk_26[0x2];
    /* 0x28 */ UNK_TYPE unk_28;
    /* 0x2C */ UNK_TYPE unk_2C;
    /* 0x30 */ UNK_TYPE unk_30;
    /* 0x34 */ UNK_TYPE unk_34;
    /* 0x38 */ UNK_TYPE unk_38[8];
    /* 0x58 */ struct_800072A0_usa_arg0_unk_58 unk_58[GAME_PLAYER_COUNT];
} struct_800072A0_usa_arg0; // size >= 0xB8

nbool func_800072A0_usa(struct_800072A0_usa_arg0 *arg0);

STATIC_INLINE void static_inlined_meminit(void *dst, size_t size, s32 var_s1) {
#define BUFFER_SIZE 0x80
    void *ptr = dst;
    s32 remaining = size;
    void *buf = ALIGN_PTR(B_8018A960_usa);

#if 0
    // References
    // -> static unsigned char _cache$158[16384];
#endif

    if (B_8018A924_usa == 0) {
        bzero(ptr, remaining);
        return;
    }

    // I have no idea what's the deal with var_s1,
    // seems pointless
    if (var_s1 % BUFFER_SIZE != 0) {
        return;
    }

    for (; remaining > 0; remaining -= BUFFER_SIZE, var_s1 += BUFFER_SIZE, ptr += BUFFER_SIZE) {
        u32 page_num = var_s1 / BUFFER_SIZE;

        osInvalDCache(buf, BUFFER_SIZE);
        osFlashReadArray(&B_8018A930_usa, 0, page_num, buf, 1, &B_8018A948_usa);
        osRecvMesg(&B_8018A948_usa, NULL, OS_MESG_BLOCK);
        func_80000450_usa();
        bcopy(buf, ptr, MIN(remaining, BUFFER_SIZE));
    }
#undef BUFFER_SIZE
}

// RENAME TODO: menuLoadUserData ?
nbool func_800072A0_usa(struct_800072A0_usa_arg0 *arg0) {
    struct_800072A0_usa_arg0 sp18;
    s32 var_s4;
    s32 var_s6;
    s32 var_v0;
    s32 var_s7;

#if 0
    int bFlag1; // r5
    int bFlag2; // r6
    struct_menu_c_1407 data0; // r1+0xC4
    struct_menu_c_1407 data1; // r1+0xC
#endif

    var_s6 = -1;

    for (var_s4 = 0; var_s4 < 8; var_s4++) {
        static_inlined_meminit(&sp18, sizeof(struct_800072A0_usa_arg0), var_s4 << 14);

#if VERSION_FRA
#define THINGY -0x543210E0
#elif VERSION_GER
#define THINGY -0x543210F0
#else
#define THINGY -0x54321100
#endif
        // TODO: maybe unsigned?
        if (sp18.unk_10 != THINGY) {
            var_v0 = 0;
        } else if (sp18.unk_04 != 0xB8) {
            var_v0 = 0;
        } else if (sp18.unk_08 != 0x7BC) {
            var_v0 = 0;
        } else {
            var_v0 = -1;
        }

        if ((var_v0 != 0) && ((var_s6 == -1) || (var_s7 < sp18.unk_00))) {
            var_s6 = var_s4;
            var_s7 = sp18.unk_00;
        }
    }

    if (var_s6 == -1) {
        return nfalse;
    }

    static_inlined_meminit(arg0, sizeof(struct_800072A0_usa_arg0), var_s6 << 14);
    return ntrue;
}

UNK_RET func_80007538_usa(struct_800072A0_usa_arg0 *, s32); /* extern */

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80007538_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_800077AC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C31C0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80007E68_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80007F64_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000817C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_800081F0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80008428_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_800084E0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80008818_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_800088A0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800075F8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000786C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C36F0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80007F28_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80008024_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000823C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800082B0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800084E8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800085A0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800088D8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80008960_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800075D8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000784C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C1F20_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80007F08_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80008004_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000821C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80008290_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800084C8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80008580_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800088C0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80008948_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800075D8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000784C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B8EE0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80007F08_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80008004_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000821C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80008290_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800084C8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80008580_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800088C0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80008948_ger);
#endif

// TODO: change bBack to nbool?
/**
 * Original name: menuSetScreen
 */
nbool menuSetScreen(enum_TypeMenu eType, s32 bBack) {
    nbool bFlag;
    struct_gaMenuData *pMenuData;
    s32 nPlayerCount;
    s32 iScreen;
    s32 iScreenMenu;
    s32 nMode;

    if (!menuFind(&pMenuData, eType)) {
        return nfalse;
    }
    if (!screenFind(&iScreen, pMenuData->szName)) {
        return nfalse;
    }

    if ((iScreen == giScreenMenu) && (!screenChangePending())) {
        return nfalse;
    }

    if (eType >= MT_1P_PUZZLE_STAGE1 && eType <= MT_2P_ATTACK_NAME) {
        nPlayerCount = 2;
        nMode = 2;
    } else {
        nPlayerCount = 1;
        nMode = 1;
    }

    if ((bBack != 0) && (iScreen == giScreenMenuLast) && (screenChangePending())) {
        bFlag = ntrue;
    } else {
        bFlag = nfalse;
    }

    if (bBack != 0) {
        nMode |= 0x100;
    }
    if (giScreenMenu != -1) {
        nMode |= 0x200;
    }
    nMode |= 0x400;
    iScreenMenu = screenSet(pMenuData->szName, nMode);
    if (iScreenMenu == giScreenMenu) {
        return nfalse;
    }
    if (iScreenMenu != iScreen) {
        return nfalse;
    }

    gnTickMenu = 0;
    ganPick[0] = ganPick[1] = bFlag;
    geTypeMenu = eType;
    giScreenMenuLast = giScreenMenu;
    giScreenMenu = iScreenMenu;
    gnPlayerCount = nPlayerCount;
    anTagBlinkLast[0] = -1;
    anTagBlinkLast[1] = -1;
    if (bFlag == 0) {
        if (pMenuData->pfInit != NULL) {
            pMenuData->pfInit(iScreenMenu);
        }
    }
    if (geTypeMenu == MT_MAIN) {
        B_8018A82C_usa = 0;
    }

    if (gbAudioChanged != 0) {
        gbAudioChanged = 0;
        FadeOutAllSFXs(0x1E);
        if ((geTypeMenu != MT_2P_ATTACK_LEVEL) || (B_8021B960_usa != 0x3F)) {
            if ((geTypeMenu != MT_2P_CLEAR_LEVEL) && (geTypeMenu != MT_2P_CLEAR_CHARACTER)) {
                func_80002D8C_usa(0x1E);
            }
        }

        if (geTypeMenu == MT_MAIN) {
            PlayMIDI(BGM_INIT_TABLE, 0x3D, 0, 1);
        } else if ((geTypeMenu == MT_1P_PUZZLE_STAGE3) || (geTypeMenu == MT_1P_PUZZLE_STAGE3D) ||
                   (geTypeMenu == MT_PRACTICE_PAGEDEMO)) {
            PlayMIDI(BGM_INIT_TABLE, 0x3D, 0, 1);
        } else if (geTypeMenu == MT_2P_ATTACK_LEVEL) {
            if (B_8021B960_usa != 0x3F) {
                PlayMIDI(BGM_INIT_TABLE, 0x3F, 0, 1);
            }
        } else if ((geTypeMenu == MT_2P_CLEAR_NAME) || (geTypeMenu == MT_2P_CLEAR_LEVEL) ||
                   (geTypeMenu == MT_2P_CLEAR_CHARACTER)) {
            if (((geTypeMenu != MT_2P_CLEAR_LEVEL) && (geTypeMenu != MT_2P_CLEAR_CHARACTER)) ||
                (B_8021B960_usa != 0x40)) {
                PlayMIDI(BGM_INIT_TABLE, 0x40, 0, 1);
            }
        } else {
            PlayMIDI(BGM_INIT_TABLE, 0x3E, 0, 1);
        }
    }

    return ntrue;
}

// RENAME TODO: menuShowDiploma ?
nbool func_80008EA4_usa(s32 *arg0) {
    u8 *var_a2;
    s32 var_a1;
    s32 var_a3;
    s32 var_t0;
    s32 var_t1;

    // kinda cursed, but whatever
    if ((gPlayer[0] < &gTheGame.player[0]) || (&gTheGame.player[7] < gPlayer[0])) {
        osSyncPrintf("menuShowDiploma: INTERNAL ERROR: 'gPlayer' not valid!\n");
        return nfalse;
    }

    for (var_t1 = 0; var_t1 < 6; var_t1++) {
        switch (var_t1) {
            case 0x0:
                var_a3 = 0x1E;
                var_t0 = ARRAY_COUNT(gPlayer[0]->unk_0B7) - 1;
                var_a2 = (u8 *)gPlayer[0]->unk_0B7;
                break;

            case 0x1:
                var_a3 = 0x32;
                var_t0 = ARRAY_COUNT(gPlayer[0]->unk_0BB) - 1;
                var_a2 = (u8 *)gPlayer[0]->unk_0BB;
                break;

            case 0x2:
                var_a3 = 0x32;
                var_t0 = ARRAY_COUNT(gPlayer[0]->unk_0C2) - 1;
                var_a2 = (u8 *)gPlayer[0]->unk_0C2;
                break;

            case 0x3:
                var_a3 = 0x1E;
                var_t0 = ARRAY_COUNT(gPlayer[0]->unk_0C9) - 1;
                var_a2 = (u8 *)gPlayer[0]->unk_0C9;
                break;

            case 0x4:
                var_a3 = 0x32;
                var_t0 = ARRAY_COUNT(gPlayer[0]->unk_0CD) - 1;
                var_a2 = (u8 *)gPlayer[0]->unk_0CD;
                break;

            case 0x5:
                var_a3 = 0x32;
                var_t0 = ARRAY_COUNT(gPlayer[0]->unk_0D4) - 1;
                var_a2 = (u8 *)gPlayer[0]->unk_0D4;
                break;
        }

        for (var_a1 = 0; var_a1 < var_a3; var_a1++) {
            if (((var_a2[var_a1 >> 3] >> (var_a1 & 7)) & 1) == 0) {
                break;
            }
        }

        if (var_a1 == var_a3) {
            if (!(var_a2[var_t0] & 0x40)) {
                var_a2[var_t0] |= 0x40;
                if (arg0 != NULL) {
                    *arg0 = var_t1 + 2;
                }
                return ntrue;
            }
        }
    }

    if (arg0 != NULL) {
        *arg0 = 0;
    }
    return nfalse;
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000901C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80009228_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80009440_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_800095F8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_800C3284_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80009A78_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80009CA8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80009D30_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80009DBC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80009F60_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800090DC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800092E8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80009500_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800096B8_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C37B4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80009B38_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80009D68_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80009DF0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80009E7C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000A020_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800090C4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800092D0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800094E8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800096A0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_800C1FE4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80009B20_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80009D50_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80009DD8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80009E64_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000A018_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800090C4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800092D0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800094E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800096A0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B8FA4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80009B20_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80009D50_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80009DD8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80009E64_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000A018_ger);
#endif

extern UNK_TYPE2 D_800B5A10_usa[];
extern const char RO_800C32E8_usa[];
extern const char RO_800C32F0_usa[];
extern const char RO_800C32F8_usa[];

#if VERSION_USA
#if 0
void func_8000A940_usa(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp10;
    u32 temp_s0;
    const char *var_a2;

    if (arg0 >= ARRAY_COUNTU(gTheGame.player)) {
        return;
    }

    switch (arg1) {                             /* irregular */
        case 0x5:
            var_a2 = RO_800C32E8_usa;
            break;
        case 0x6:
            var_a2 = RO_800C32F0_usa;
            break;
        default:
            if (arg1 != 7) {
                return;
            }
            var_a2 = RO_800C32F8_usa;
            break;
    }

    if (((arg2 ^ 1) == 0) && (arg0 == 0)) {
        temp_s0 = gTheGame.player[arg0].unk_7A2.unk_08[arg1];
    } else {
        temp_s0 = gTheGame.player[arg0].unk_7A2.unk_00[arg1];
    }

    if (screenFind(&sp10, var_a2)) {
        func_8002A1F4_usa(sp10, (arg2 != 0) ? 0x67 : 0x65, temp_s0 & 0xF, 0);
        func_8002A1F4_usa(sp10, (arg2 == 0) ? 0x64 : 0x68, (temp_s0 >> 4) & 0x7F, 0);
        if (arg2 == 0) {
            func_8002A1F4_usa(sp10, 0x66, (temp_s0 >> 0xB) & 1, 0);
        }
    }
    D_800B5A10_usa[arg2] = (temp_s0 >> 0xC) & 0xF;

}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000A940_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000A940_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000A940_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000A940_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000AABC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_800C32E8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_800C32F0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_800C32F8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000AC80_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000AE84_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000B25C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000B48C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000B7E4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000BBCC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000BD34_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000C338_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_800C3318_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000C8C0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000CDEC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000D7D8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000D990_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000DBEC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000DD28_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000ED60_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000EF04_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000F104_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000F2B4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000F6CC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000F7FC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8000FA44_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80010050_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80010238_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80010474_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80010724_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80011F30_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001225C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80012434_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80012738_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80012A64_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80012EF4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001305C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80013100_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C33B0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001348C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_800136E8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80013948_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80013D8C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_800C33EC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C33F8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3404_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3414_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3420_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C342C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C343C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C344C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C345C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C346C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3478_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3488_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3498_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C34A4_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C34B0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C34BC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C34C8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C34D4_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C34E0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C34EC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C34F8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3508_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3518_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3528_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3534_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3540_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C354C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3558_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3568_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3574_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3584_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3590_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C35A0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C35AC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C35B8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C35C4_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C35D0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C35DC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C35E8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C35F4_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3600_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C360C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C361C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3628_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3634_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3644_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3650_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3660_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3670_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3680_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3690_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C36A0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C36B0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C36C0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C36D0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C36E0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C36F0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3700_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3710_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3720_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3730_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3740_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3750_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3760_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3770_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3780_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3790_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C37A0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C37B0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C37C0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C37D0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C37E0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C37F0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3800_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3810_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3820_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3830_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3840_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3850_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3860_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3870_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3880_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3890_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C38A0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C38B0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C38C0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C38D0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C38E0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C38F0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3900_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3910_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3920_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_800C3930_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80013FB4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_800142DC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80014970_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80014C6C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80014EFC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_800150B4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80016690_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_800169E4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80016C34_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80016F6C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80017134_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80017470_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000AB7C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3818_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3820_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3828_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000AD40_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000AF44_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000B31C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000B54C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000B8A4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000BC8C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000BDF4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000C3F8_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3848_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3850_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000C980_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000CEAC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000D898_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000DA50_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000DCAC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000DDE8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000EE20_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000EFC4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000F1C4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000F398_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000F7B0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000F8E0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8000FB28_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80010134_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001031C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80010558_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80010808_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80012014_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80012340_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80012518_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001281C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80012B98_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80013028_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80013190_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80013234_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C38E0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800135C0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001381C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80013A7C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80013EC0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800140E8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80014410_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80014AA4_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_800C391C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3928_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3934_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3944_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3950_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C395C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C396C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C397C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C398C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C399C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C39A8_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C39B8_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C39C8_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C39D4_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C39E0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C39EC_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C39F8_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A04_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A10_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A1C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A28_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A38_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A48_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A58_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A64_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A70_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A7C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A88_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3A98_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3AA4_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3AB4_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3AC0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3AD0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3ADC_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3AE8_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3AF4_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B00_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B0C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B18_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B24_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B30_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B3C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B4C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B58_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B64_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B74_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B80_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3B90_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3BA0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3BB0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3BC0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3BD0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3BE0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3BF0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3C00_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3C10_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3C20_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3C30_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3C40_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3C50_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3C60_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3C70_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3C80_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3C90_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3CA0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3CB0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3CC0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3CD0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3CE0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3CF0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3D00_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3D10_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3D20_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3D30_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3D40_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3D50_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3D60_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3D70_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3D80_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3D90_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3DA0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3DB0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3DC0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3DD0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3DE0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3DF0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3E00_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3E10_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3E20_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3E30_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3E40_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3E50_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_800C3E60_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3FE0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C3FF8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80014DA0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80015030_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C404C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800151E8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800167C4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80016B18_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80016D68_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800170A0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80017268_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800175A4_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000AB74_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_800C2048_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_800C2050_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_800C2058_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000AD38_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000AF3C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000B314_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000B544_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000B89C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000BC84_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000BDEC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000C3F0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_800C2078_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000C978_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000CEA4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000D890_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000DA48_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000DCA4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000DDE0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000EE18_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000EFBC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000F1BC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000F390_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000F7A8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000F8D8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8000FB20_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001012C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80010314_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80010550_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80010800_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80012000_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80012344_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001251C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80012820_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80012B9C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001302C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80013194_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80013238_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2110_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800135C4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80013820_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80013A80_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80013EC4_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_800C214C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2158_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2164_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2174_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2180_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C218C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C219C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C21AC_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C21BC_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C21CC_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C21D8_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C21E8_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C21F8_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2204_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2210_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C221C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2228_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2234_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2240_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C224C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2258_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2268_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2278_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2288_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2294_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C22A0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C22AC_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C22B8_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C22C8_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C22D4_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C22E4_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C22F0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2300_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C230C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2318_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2324_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2330_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C233C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2348_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2354_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2360_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C236C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C237C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2388_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2394_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C23A4_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C23B0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C23C0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C23D0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C23E0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C23F0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2400_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2410_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2420_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2430_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2440_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2450_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2460_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2470_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2480_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2490_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C24A0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C24B0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C24C0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C24D0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C24E0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C24F0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2500_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2510_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2520_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2530_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2540_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2550_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2560_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2570_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2580_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2590_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C25A0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C25B0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C25C0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C25D0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C25E0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C25F0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2600_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2610_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2620_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2630_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2640_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2650_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2660_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2670_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2680_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800140EC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80014494_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80014B28_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80014DEC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001507C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C26FC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80015234_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800167F8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80016B4C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80016D9C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800170D4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001729C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800175D8_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000AB74_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9008_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9010_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9018_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000AD38_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000AF3C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000B314_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000B544_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000B89C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000BC84_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000BDEC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000C3F0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9038_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9040_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000C978_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000CEA4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000D890_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000DA48_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000DCA4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000DDE0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000EE18_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000EFBC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000F1BC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000F390_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000F7A8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000F8D8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8000FB20_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001012C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80010310_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001054C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800107FC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80012034_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80012378_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80012550_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80012854_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80012BD0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80013060_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800131C8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001326C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B90D0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800135F8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80013854_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80013AB4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80013EF8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80014120_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800144C8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80014B5C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B910C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9118_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9124_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9134_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9140_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B914C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B915C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B916C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B917C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B918C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9198_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B91A8_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B91B8_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B91C4_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B91D0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B91DC_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B91E8_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B91F4_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9200_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B920C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9218_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9228_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9238_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9248_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9254_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9260_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B926C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9278_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9288_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9294_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B92A4_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B92B0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B92C0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B92CC_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B92D8_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B92E4_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B92F0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B92FC_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9308_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9314_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9320_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B932C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B933C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9348_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9354_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9364_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9370_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9380_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9390_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B93A0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B93B0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B93C0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B93D0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B93E0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B93F0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9400_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9410_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9420_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9430_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9440_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9450_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9460_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9470_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9480_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9490_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B94A0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B94B0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B94C0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B94D0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B94E0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B94F0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9500_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9510_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9520_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9530_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9540_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9550_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9560_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9570_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9580_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9590_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B95A0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B95B0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B95C0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B95D0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B95E0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B95F0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9600_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9610_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9620_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9630_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9640_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9650_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9668_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80014E20_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800150B0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B96BC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80015268_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80016844_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80016B98_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80016DE8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80017120_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800172E8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80017624_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_800175F8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800175F8_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800175F8_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800175F8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80017A48_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80017B64_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3BA8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3BB8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3BC4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80017E18_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80017B7C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80017C98_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C40D8_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C40E8_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C40F4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80017F4C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80017BB0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80017CCC_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2788_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2798_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C27A4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80017F80_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80017BFC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80017D18_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9748_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9758_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9764_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80017FCC_ger);
#endif

/**
 * Original name: menuFind
 */
INLINE nbool menuFind(struct_gaMenuData **ppData, enum_TypeMenu eType) {
    s32 iMenu;

    for (iMenu = 0; iMenu < ARRAY_COUNTU(gaMenuData); iMenu++) {
        if (gaMenuData[iMenu].eType == eType) {
            *ppData = &gaMenuData[iMenu];
            return ntrue;
        }
    }

    return nfalse;
}

#if VERSION_USA
#if 0
s32 menuLoadData(void) {
    struct_800072A0_usa_arg0 sp18;
    s32 spD0;
    player_t_unk_002 *var_s0;
    s32 temp_s4;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a2;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_5;
    s32 var_s1;
    s32 var_s2_2;
    s32 var_v1_2;
    void *temp_s3;
    void *var_s3;
    void *var_s5;

    B_8018A914_usa = 1;
    B_8018A918_usa = 1;
    B_8018A8D0_usa = 0;
    B_8018A8D4_usa = 0;
    for (var_s1 = 1; var_s1 < 8; var_s1++) {
        bzero(&gTheGame.player[var_s1].unk_002, sizeof(player_t_unk_002));
    }

    D_800B5A18_usa = 1;
    B_8018A830_usa = 0;
    B_8018A91C_usa = 2;
    bzero(&gTheGame.player[0].unk_002, sizeof(player_t_unk_002));

    if (func_800072A0_usa(&sp18) != 0) {
        B_8018A8E6_usa = 0;
        for (var_s1 = 0; var_s1 < 8; var_s1++) {
            bcopy(&sp18.unk_58[var_s1], &B_8018A8D8_usa, 0xC);

            // Inlined function?
            var_s0_2 = -1;
            for (var_a0 = 0; var_a0 < 8; var_a0++) {
                if (gTheGame.player[var_a0].unk_002.unk_0 == 0) {
                    var_s0_2 = var_a0;
                    break;
                }
            }

            if (var_s0_2 != -1) {
                menuInitUser((u32) var_s0_2);
                bcopy(&B_8018A8D8_usa, (var_s0_2 * 0x7BC) + &gTheGame.player[0].unk_002, 0xE);
            }
        }

        temp_s3 = B_801AB8E4_usa - (sp18.unk_1C + 0x400);
        var_s2_2 = sp18.unk_0C << 0xE;
        var_s5 = temp_s3;
        var_s1 = sp18.unk_1C;
        temp_s4 = (s32) &B_8018A96F_usa & ~0xF;
        if (B_8018A924_usa == 0) {
            bzero(temp_s3, sp18.unk_1C);
        } else {
            if (!(var_s2_2 & 0x7F)) {
                while (var_s1 > 0) {
                    var_s0_3 = var_s2_2;
                    if (var_s2_2 < 0) {
                        var_s0_3 = var_s2_2 + 0x7F;
                    }
                    osInvalDCache((void *) temp_s4, 0x80);
                    osFlashReadArray(&B_8018A930_usa, 0, (u32) (var_s0_3 >> 7), (void *) temp_s4, 1U, &B_8018A948_usa);
                    osRecvMesg(&B_8018A948_usa, NULL, 1);
                    func_80000450_usa();
                    var_a2 = var_s1;
                    if (var_s1 > 0x80) {
                        var_a2 = 0x80;
                    }
                    bcopy((void *) temp_s4, var_s5, var_a2);
                    var_s1 -= 0x80;
                    var_s2_2 += 0x80;
                    var_s5 += 0x80;
                }
            }
        }
        var_s3 = temp_s3 + 0xB8;

        for (var_s1 = 1; var_s1 < 8; var_s1++) {
            bcopy(var_s3, &gTheGame.player[var_s1], 0x7BC);
            var_s3 += 0x7BC;
        }

        B_8021BA98_usa ^= sp18.unk_18;
        B_8018A830_usa = sp18.unk_14;
        D_800B5A18_usa = sp18.unk_30;
        B_8018A91C_usa = sp18.unk_34;
        gGameStatus = (gGameStatus & 1) ^ sp18.unk_24;
        gOverflowFlag = sp18.unk_2C;
        B_8021BEA0_usa = sp18.unk_28;
        return -1;
    }

    screenFind(&spD0, &RO_STR_800C3D68_usa);

    for (var_s1 = 0; var_s1 < 1; var_s1++) {
        func_80029130_usa(spD0, var_s1 + 0x64, &B_8018A8D8_usa, 7);
        if (B_8018A8D8_usa.unk_0 != 1) {
            var_s0_5 = -1;

            for (var_a0_2 = 0; var_a0_2 < 8; var_a0_2++) {
                if (&gTheGame.player[var_a0_2].unk_002 == 0) {
                    var_s0_5 = var_a0_2;
                    break;
                }
            }

            if (var_s0_5 != -1) {
                menuInitUser(var_s0_5);
                bcopy(&B_8018A8D8_usa, &gTheGame.player[var_s0_5].unk_002, 0xE);
            }
        }
    }

    menuSaveData(1);
    return 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", menuLoadData);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", menuLoadData);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", menuLoadData);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", menuLoadData);
#endif

#if VERSION_USA
#if 0
nbool menuSaveData(s32 iPlayer) {
    struct_800072A0_usa_arg0 sp10;
    s32 var_a1;
    s32 var_s3;

    if (func_800072A0_usa(&sp10)) {
        sp10.unk_14 = B_8018A830_usa & ~0x40;
        sp10.unk_18 = B_8021BA98_usa;
        sp10.unk_24 = gGameStatus & 0xFF7F;
        sp10.unk_30 = D_800B5A18_usa;
        sp10.unk_34 = B_8018A91C_usa;
        sp10.unk_2C = gOverflowFlag;
        sp10.unk_28 = B_8021BEA0_usa;

        for (var_s3 = 0; var_s3 < GAME_PLAYER_COUNT; var_s3++) {
            bcopy(&gTheGame.player[var_s3].unk_002, &sp10.unk_58[var_s3], 0xC);
        }
    } else {
        bzero(&sp10, sizeof(struct_800072A0_usa_arg0));
        sp10.unk_0C = 7;
        sp10.unk_04 = 0xB8;
        sp10.unk_00 = 0;
        sp10.unk_10 = 0xABCDEF00;
        sp10.unk_08 = 0x7BC;
        sp10.unk_20 = 0;
        for (var_a1 = 0; var_a1 < 8; var_a1++) {
            sp10.unk_38[var_a1] = -1;
        }

        sp10.unk_14 = B_8018A830_usa & ~0x40;
        sp10.unk_18 = B_8021BA98_usa;
        sp10.unk_24 = gGameStatus & 0xFF7F;
        sp10.unk_30 = D_800B5A18_usa;
        sp10.unk_34 = B_8018A91C_usa;
        sp10.unk_2C = gOverflowFlag;
        sp10.unk_28 = B_8021BEA0_usa;
        for (var_s3 = 0; var_s3 < GAME_PLAYER_COUNT; var_s3++) {
            // What????
            bcopy(&gTheGame.player[var_s3].unk_002, &sp10.unk_58[var_s3], 0xC);
        }
    }

    func_80007538_usa(&sp10, iPlayer);

    return ntrue;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", menuSaveData);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", menuSaveData);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", menuSaveData);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", menuSaveData);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3C80_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3C88_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3C94_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3CA0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3CAC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3CBC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3CC8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3CD4_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3CE4_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3CF0_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3CFC_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3D08_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3D18_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3D28_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3D34_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3D40_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3D4C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3D58_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3D60_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3D68_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3D74_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/menu", RO_STR_800C3D80_usa);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C41B0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C41B8_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C41C4_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C41D0_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C41DC_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C41EC_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C41F8_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C4204_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C4214_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C4220_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C422C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C4238_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C4248_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C4258_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C4264_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C4270_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C427C_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C4288_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C4290_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C4298_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C42A4_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/menu", RO_STR_800C42B0_eur);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2860_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2868_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2874_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2880_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C288C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C289C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C28A8_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C28B4_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C28C4_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C28D0_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C28DC_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C28E8_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C28F8_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2908_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2914_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2920_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C292C_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2938_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2940_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2948_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2954_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/menu", RO_STR_800C2960_fra);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9820_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9828_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9834_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9840_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B984C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B985C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9868_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9874_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9884_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9890_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B989C_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B98A8_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B98B8_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B98C8_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B98D4_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B98E0_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B98EC_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B98F8_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9900_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9908_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9914_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/menu", RO_STR_800B9920_ger);
#endif

extern s32 B_801C6EF0_usa;
extern const char RO_800C3284_usa[];
extern const char RO_800C3318_usa[];
extern const char RO_STR_800C3BC4_usa[];
extern const char RO_STR_800C3CAC_usa[];
extern const char RO_STR_800C3CBC_usa[];
extern const char RO_STR_800C3CC8_usa[];
extern const char RO_STR_800C3CD4_usa[];
extern const char RO_STR_800C3CF0_usa[];
extern const char RO_STR_800C3D74_usa[];
extern const char RO_STR_800C3D80_usa[];

#if VERSION_USA
#if 0
void func_800194DC_usa(enum_TypeMenu arg0) {
    s32 sp10;
    s32 temp_a1;
    s32 temp_s2;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    s32 var_a0;
    s32 var_a2;
    s32 var_s0;
    s32 var_s1;
    s32 var_s3;
    s32 var_s4;
    s32 var_v0;
    s32 var_v1;

    temp_s4 = gTheGame.menu[0].unk_8;
    temp_s7 = B_801C6EF0_usa;
    temp_s5 = gTheGame.menu[0].unk_0;
    temp_s2 = gTheGame.menu[0].unk_4;
    temp_s6 = gTheGame.menu[1].unk_8;

    switch (arg0) {                                 /* switch 1 */
        case MT_2P_ATTACK_LEVEL:                    /* switch 1 */
            B_8018A81C_usa = MT_MAIN;
            screenFind(&sp10, &RO_STR_800C3CF0_usa);
            func_8002A1F4_usa(sp10, 0x64, 0, temp_s5);
            break;

        case MT_HOWTO_CONTROLLER:                   /* switch 1 */
            screenFind(&sp10, &RO_STR_800C3CAC_usa);
            func_8002A1F4_usa(sp10, 0x64, 0, 1);
            screenFind(&sp10, &RO_STR_800C3D74_usa);
            func_8002A1F4_usa(sp10, 0x64, 0, temp_s5);
            break;

        case MT_2P_CLEAR_LEVEL:                     /* switch 1 */
        case MT_2P_CLEAR_CHARACTER:                 /* switch 1 */
            B_8018A81C_usa = MT_PLAY;
            screenFind(&sp10, &RO_STR_800C3CD4_usa);
            if (arg0 == MT_2P_CLEAR_LEVEL) {
                func_8002A1F4_usa(sp10, 0x64, 0, 0);
                screenFind(&sp10, &RO_STR_800C3CC8_usa);
            } else {
                func_8002A1F4_usa(sp10, 0x64, 0, 1);
                screenFind(&sp10, &RO_STR_800C3CBC_usa);
            }
            func_8002A1F4_usa(sp10, 0x64, 0, temp_s4 - 1);
            break;

        case MT_2P_CLEAR_NAME:                      /* switch 1 */
            B_8018A81C_usa = MT_PLAY;
            screenFind(&sp10, &RO_STR_800C3CD4_usa);
            func_8002A1F4_usa(sp10, 0x64, 0, 2);
            break;

        case MT_4P:                                 /* switch 1 */
            B_8018A81C_usa = MT_MANY;
            screenFind(&sp10, &RO_STR_800C3CAC_usa);
            func_8002A1F4_usa(sp10, 0x64, 0, 1);
            break;

        case MT_1P_ENDLESS_NAME:                    /* switch 1 */
        case MT_1P_VS_LEVEL:                        /* switch 1 */
            if (arg0 == MT_1P_ENDLESS_NAME) {
                B_8018A81C_usa = arg0;
            } else {
                B_8018A81C_usa = MT_1P;
            }
            screenFind(&sp10, &RO_800C3284_usa);
            if ((gGameStatus & 1) && (geTypeMenu != MT_1P_VS_LEVEL)) {
                var_s4 = temp_s4 - 1;
            } else {
                var_s4 = (temp_s4 - 1) * 2;
            }
            func_8002A1F4_usa(sp10, 0x64, var_s4, 0);
            var_a2 = 2;
            switch (temp_s5) {                      /* switch 2; irregular */
                case 0x1:                           /* switch 2 */
                    var_a2 = 0;
                    break;
                case 0x2:                           /* switch 2 */
                    var_a2 = 1;
                    break;
            }
            func_8002A1F4_usa(sp10, 0x65, var_a2, 0);
            func_8002A1F4_usa(sp10, 0x66, temp_s7 != 1, 0);
            break;

        case MT_1P_ENDLESS_CHARACTER:               /* switch 1 */
            B_8018A81C_usa = MT_1P_VS_NAME;
            switch (temp_s5) {                      /* switch 3 */
                case 0x1:                           /* switch 3 */
                    var_s0 = 0;
                    var_s3 = 0;
                    break;
                case 0x2:                           /* switch 3 */
                    var_s0 = 1;
                    var_s3 = 0;
                    break;
                case 0x3:                           /* switch 3 */
                    var_s0 = 2;
                    var_s3 = 0;
                    break;
                case 0x4:                           /* switch 3 */
                    var_s0 = 1;
                    var_s3 = 1;
                    break;
                case 0x5:                           /* switch 3 */
                    var_s0 = 2;
                    var_s3 = 1;
                    break;
            }
            screenFind(&sp10, &RO_800C3318_usa);
            func_8002A1F4_usa(sp10, 0x64, var_s0, var_s3);
            break;

        case MT_1P_ATTACK_NAME:                     /* switch 1 */
        case MT_1P_ATTACK_CHARACTER:                /* switch 1 */
        case MT_1P_CLEAR_NAME:                      /* switch 1 */
            B_8018A81C_usa = MT_1P_ENDLESS_LEVEL;
            break;

        case MT_1P_CLEAR_XTRATALK:                  /* switch 1 */
        case MT_1P_PUZZLE_NAME:                     /* switch 1 */
            B_8018A81C_usa = MT_NONE;
            screenFind(&sp10, &RO_STR_800C3BC4_usa);
            var_s0 = (temp_s5 - 1) % 3;
            func_8002A1F4_usa(sp10, 0x64, var_s0, 0);

            if (temp_s2 < 0x1F) {
                var_s1 = 0x65;
            } else if (temp_s2 < 0x29) {
                var_s1 = 0x66;
            } else {
                var_s1 = 0x67;
            }
            if (temp_s5 >= 4) {
                var_s1 += 3;
            }
            func_80027618_usa(sp10, var_s1, 0U);

            switch (var_s1) {                       /* switch 4 */
                case 0x65:                          /* switch 4 */
                    temp_a1 = temp_s2 - 1;
                    var_v0 = temp_a1;
                    if (temp_a1 < 0) {
                        var_v0 = temp_s2 + 6;
                    }
                    var_v1 = var_v0 >> 3;
                    var_s0 = temp_a1 - (var_v1 * 8);
                    var_s3 = var_v1;
                    break;

                case 0x66:                          /* switch 4 */
                    var_a0 = temp_s2 - 0x1F;
                    var_v1 = var_a0 / 3;
                    var_s0 = var_a0 % 3;
                    var_s3 = var_v1;
                    break;

                case 0x68:                          /* switch 4 */
                    temp_a1 = temp_s2 - 1;
                    var_v0 = temp_a1;
                    if (temp_a1 < 0) {
                        var_v0 = temp_s2 + 6;
                    }
                    var_v1 = var_v0 >> 3;
                    var_s0 = temp_a1 - (var_v1 * 8);
                    var_s3 = var_v1;
                    break;

                case 0x69:                          /* switch 4 */
                    var_a0 = temp_s2 - 0x1F;
                    var_v1 = var_a0 / 3;
                    var_s0 = var_a0 % 3;
                    var_s3 = var_v1;
                    break;

                case 0x67:                          /* switch 4 */
                case 0x6A:                          /* switch 4 */
                    var_a0 = temp_s2 - 0x29;
                    var_v1 = var_a0 / 3;
                    var_s0 = var_a0 % 3;
                    var_s3 = var_v1;
                    break;
            }
            func_8002A1F4_usa(sp10, var_s1, var_s0, var_s3);
            break;

        case MT_1P_PUZZLE_STAGE2:                   /* switch 1 */
        case MT_1P_PUZZLE_STAGE3:                   /* switch 1 */
        case MT_1P_PUZZLE_STAGE3D:                  /* switch 1 */
        case MT_1P_PUZZLE_STAGE5:                   /* switch 1 */
        case MT_1P_PUZZLE_CUSTOM:                   /* switch 1 */
        case MT_2P:                                 /* switch 1 */
        case MT_2P_VS_LEVEL:                        /* switch 1 */
        case MT_2P_VS_CHARACTER:                    /* switch 1 */
        case MT_2P_ATTACK_NAME:                     /* switch 1 */
            B_8018A81C_usa = MT_1P_ENDLESS_CHARACTER;
            func_8002A1F4_usa(sp10, 0x65, temp_s4 - 1, 0);
            func_8002A1F4_usa(sp10, 0x67, temp_s6 - 1, 0);
            func_8002A1F4_usa(sp10, 0x66, 0, temp_s7 != 1);
            break;

        default:                                    /* switch 1 */
            osSyncPrintf(&RO_STR_800C3D80_usa, arg0);
            break;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_800194DC_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_800194DC_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_800194DC_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_800194DC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80019A24_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80019DAC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_80019F44_usa);
#endif

#if VERSION_USA
/**
 * Original name: menuInitUser
 */
s32 menuInitUser(u32 arg0) {
    if (arg0 < GAME_PLAYER_COUNT) {
        player_t *player = &gTheGame.player[arg0];

        player->unk_000 = arg0;
        player->unk_010 = 0;
        bzero(&player->unk_002, 0xE);
        player->unk_014 = 0;
        player->unk_018 = 0;
        player->unk_01C = 0;
        player->unk_020 = 0;
        player->unk_024 = 0;
        player->unk_028 = 0;
        player->unk_029 = 0;
        player->unk_02A = 0;
        bzero(&player->unk_02B, 6);
        bzero(&player->unk_034, 0x80);
        player->unk_0B4 = 0;
        player->unk_0B5 = 0;
        player->unk_0B6 = 0;
        bzero(&player->unk_0B7, sizeof(char) * STRUCT_801A6DB8_USA_UNK_0B7_COUNT);
        bzero(&player->unk_0BB, sizeof(char) * STRUCT_801A6DB8_USA_UNK_0BB_COUNT);
        bzero(&player->unk_0C2, sizeof(char) * STRUCT_801A6DB8_USA_UNK_0C2_COUNT);
        bzero(&player->unk_0C9, sizeof(char) * STRUCT_801A6DB8_USA_UNK_0C9_COUNT);
        bzero(&player->unk_0CD, sizeof(char) * STRUCT_801A6DB8_USA_UNK_0CD_COUNT);
        bzero(&player->unk_0D4, sizeof(char) * STRUCT_801A6DB8_USA_UNK_0D4_COUNT);
        player->unk_0DB = 0;
        player->unk_0DC = 0;
        player->unk_0DD = 0;
        player->unk_0DE = 0;
        player->unk_0DF = 0;
        player->unk_0E0 = 0;
        player->unk_0E1 = 0;
        player->unk_0E2 = 0;
        player->unk_0E3 = 0;
        player->unk_0E4 = 0;
        player->unk_0F0 = 0;
        player->unk_0EF = 0;
        player->unk_0EE = 0;
        player->unk_0ED = 0;
        player->unk_0E6 = 0;
        player->unk_0E8 = 0;
        player->unk_0E5 = 0;
        player->unk_0E7 = 0;
        player->unk_0EA = 0;
        player->unk_0EC = 0;
        player->unk_0E9 = 0;
        player->unk_0EB = 0;
        bzero(&player->unk_0F1, 8);
        bzero(&player->unk_0F9, 8);
        bzero(&player->unk_101, 8);
        bzero(&player->unk_109, 8);
        bzero(&player->unk_111, 8);
        bzero(&player->unk_119, 8);
        bzero(&player->unk_121, 0x672);
        bzero(&player->unk_7A2, 0x12);
        bzero(&player->unk_7B4, 6);
        player->unk_7B4.unk_0 = 3;
        player->unk_7A2.unk_0A = 3;
        player->unk_7B4.unk_2 = 3;
        player->unk_7A2.unk_0C = 3;
        player->unk_7B4.unk_4 = 3;
        player->unk_7A2.unk_0E = 3;
        return -1;
    }

    return 0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001A330_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001A50C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80019B58_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_80019EE8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001A080_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001A294_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001A46C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001A648_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80019B8C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_80019F1C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001A0B4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001A2C8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001A4A0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001A67C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80019BD8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_80019F68_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001A100_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001A314_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001A4EC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001A6C8_ger);
#endif

/**
 * Original name: menuInitFairy
 */
void menuInitFairy(enum_menuTickFairy_ePosition ePosition) {
    switch (ePosition) {
        case MFP_LEFT:
            gnPositionFairyX = 0x16;
            gnPositionFairyY = 0x5E;
            break;

        case MFP_LEFT_MIDDLE:
            gnPositionFairyX = 0x56;
            gnPositionFairyY = 0x56;
            break;

        case MFP_RIGHT_MIDDLE:
            gnPositionFairyX = 0x7A;
            gnPositionFairyY = 0x56;
            break;

        case MFP_RIGHT:
            gnPositionFairyX = 0xBA;
            gnPositionFairyY = 0x5E;
            break;

        default:
            break;
    }
}

/**
 * Original name: ganOffsetFairy
 */
extern s32 ganOffsetFairy[8];

#if VERSION_USA
#ifdef NON_EQUIVALENT
void menuTickFairy(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, u32 arg6, s32 arg7) {
    s32 temp_s4;
    s32 temp_s6;
    s32 var_s0;
    s32 var_s3;
    s32 var_t0;
    s32 var_t1;

    switch (arg6) { /* irregular */
        case 0x1:
            var_t0 = 0x16;
            var_t1 = 0x5E;
            break;
        case 0x2:
            var_t0 = 0x56;
            var_t1 = 0x56;
            break;
        case 0x3:
            var_t0 = 0x7A;
            var_t1 = 0x56;
            break;
        case 0x4:
            var_t0 = 0xBA;
            var_t1 = 0x5E;
            break;
    }

    if (gnPositionFairyX < var_t0) {
        gnPositionFairyX += 1;
    }
    if (var_t0 < gnPositionFairyX) {
        gnPositionFairyX -= 1;
    }
    if (gnPositionFairyY < var_t1) {
        gnPositionFairyY += 1;
    }
    if (var_t1 < gnPositionFairyY) {
        gnPositionFairyY -= 1;
    }

    if (arg0 != -1) {
        if (arg2 == -1) {
            screenGetAreaText(arg0, &arg2);
        }

        var_s3 = arg4 & 0xFFFF;
        ganOffsetFairy[arg1 % ARRAY_COUNTU(ganOffsetFairy)] = 0;
        temp_s6 = ganOffsetFairy[(arg1 + 1) % ARRAY_COUNTU(ganOffsetFairy)];
        temp_s4 = arg4 >> 0x10;
        if (arg4 & 0x8000) {
            var_s3 |= 0xFFFF0000;
        }

        screenSetImagePosition(arg0, 0x262, gnPositionFairyX + (temp_s4 + 4),
                               gnPositionFairyY + (temp_s6 - 0x2C) + var_s3);
        if ((arg7 != 0) && screenTextDone(arg0, arg2)) {
            var_s0 = arg5 & 0xFFFF;
            if (arg5 & 0x8000) {
                var_s0 |= 0xFFFF0000;
            }
            arg5 >>= 0x10;
            screenShowImage(arg0, 0x263);
            screenSetImagePosition(arg0, 0x263, gnPositionFairyX + (arg5 + temp_s4),
                                   gnPositionFairyY + (var_s0 + var_s3));

        } else {
            screenHideImage(arg0, 0x263);
        }

        if (arg2 != -1) {
            var_s0 = arg3 & 0xFFFF;
            if (arg3 & 0x8000) {
                var_s0 |= 0xFFFF0000;
            }
            arg3 >>= 0x10;
            screenSetTextPosition(arg0, arg2, gnPositionFairyX + (arg3 + temp_s4 + 6),
                                  gnPositionFairyY + (temp_s6 - 0x24) + (var_s0 + var_s3));
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", menuTickFairy);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", menuTickFairy);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", menuTickFairy);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", menuTickFairy);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001AB0C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001AC48_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001AC7C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001ACC8_ger);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001ACA8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001ADE4_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001ADFC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001AE64_ger);
#endif

/**
 * Original name: DrawMenu
 */
void DrawMenu(struct_gInfo_unk_00068 *arg0 UNUSED) {
    if (gnSkipFrame > 0) {
        gnSkipFrame--;
        return;
    }

    if (gReset == 0) {
        struct_gaMenuData *pMenuData;

        if (geTypeMenu == MT_PLAY) {
            if (menuFind(&pMenuData, B_8018A850_usa[gnCountMenu - 2])) {
                screenDraw(&glistp, pMenuData->pfDraw);
            }
        }

        if (menuFind(&pMenuData, geTypeMenu)) {
            screenDraw(&glistp, pMenuData->pfDraw);
        } else {
            screenDraw(&glistp, NULL);
        }

        if (!screenFlushing() && (geTypeMenu != MT_PLAY)) {
            pon_DrawLoadingMessage(&glistp);
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", DoMenu);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", DoMenu);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", DoMenu);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", DoMenu);
#endif

/**
 * Original name: InitMenu
 */
void InitMenu(void) {
    //! FAKE: This is likely to not be an array
    u8 sp10[0x4];
    void *pHeap;
    s32 var_s1;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s0;
    enum_TypeMenu eType;
    s32 s0;

#if 0
    char * szNameFile; // r27
    int bLoad; // r26
    int bFlag; // r28
#endif

    B_8018A81C_usa = 3;
    gTheGame.unk_9C0C = 1;
    giScreenMenuLast = -1;
    giScreenMenu = -1;
    gbAudioChanged = -1;
    gnPositionFairyX = 0xBA;
    B_8018ABA8_usa = 0;
    B_8018ABAC_usa = 0;
    gnTickMenu = 0;
    B_8018A910_usa = 0;
    gnSkipFrame = 0;
    gnPositionFairyY = 0x5E;
    giButton = 0;

    for (var_a0 = 0; var_a0 < ARRAY_COUNT(ganButton); var_a0++) {
        ganButton[var_a0] = 0;
    }

    B_8018A8F4_usa = -1;
    pHeap = &gBufferHeap[SEGMENT_ROM_SIZE(segment_0CA4A0)];

    if (D_800B5A14_usa == 0) {
        var_s0 = -1;
        osCartRomInit();
        osFlashInit();
        osFlashReadStatus(sp10);
        B_8018A924_usa = (sp10[0] != 0) ? -1 : 0;
        osCreateMesgQueue(&B_8018A948_usa, &B_8018A928_usa, 1);
        B_8018A914_usa = 1;
        B_8018A918_usa = 1;
        B_8018A8D0_usa = 0;
        B_8018A8D4_usa = 0;
        B_8021BEA0_usa = 0;
        gnCountMenu = 0;
        D_800B5A14_usa = 2;
    } else {
        var_s0 = 0;
    }

    if (screenLoad("MENU.SBF", &pHeap) != 0) {
        if (var_s0 != 0) {
            menuLoadData();
        } else if (gMain == GMAIN_2BC) {
            var_a0_2 = -1;
            if (gnCountMenu > 0) {
                eType = B_8018A850_usa[gnCountMenu - 1];
                if ((eType == MT_2P_ATTACK_LEVEL) || (eType == MT_2P_CLEAR_NAME) || (eType == MT_2P_CLEAR_LEVEL) ||
                    (eType == MT_2P_CLEAR_CHARACTER)) {
                    var_a0_2 = 0;
                }
            }
            if ((var_a0_2 != 0) && (gPlayer[0] != NULL)) {
                menuSaveData(gPlayer[0]->unk_000);
            }
        }

        func_800175F8_usa();
        B_8018A8FC_usa = 0;
        B_8018A900_usa = 0;
        if (gMain == GMAIN_28A) {
            eType = B_8018A850_usa[gnCountMenu - 1];
            var_s1 = -1;
            menuSetScreen(eType, 0);
            switch (eType) {
                case MT_1P_PUZZLE_STAGE3D:
                    var_s1 = 5;
                    break;

                case MT_2P:
                    var_s1 = 6;
                    break;

                case MT_2P_ATTACK_NAME:
                    var_s1 = 7;
                    break;

                default:
                    osSyncPrintf("kSELECT: Internal error: %d\n", eType);
                    break;
            }

            func_8000A940_usa(B_8018A8D0_usa, var_s1, 0);
            func_8000A940_usa(B_8018A8D4_usa, var_s1, 1);
        } else if ((gMain != GMAIN_2BC) || (gnCountMenu <= 0)) {
            gnCountMenu = 0;
            s0 = MT_MAIN;
            if (menuSetScreen(3, 0)) {
                B_8018A850_usa[gnCountMenu++] = s0;
            }
        } else {
            if ((gSelection == 0xA0) || (gSelection == 0xC8) || (gSelection == 0xB4)) {
                if (B_8019CF98_usa == 0x10) {
                    gnCountMenu -= 1;
                } else {
                    gnCountMenu -= 2;
                }
            } else if (gSelection == 0xAA) {
                gnCountMenu = 0;
                B_8018A850_usa[gnCountMenu++] = MT_MAIN;
                B_8018A850_usa[gnCountMenu++] = MT_1P_ATTACK_NAME;

                if ((gPlayer[0]->unk_02B.unk_0 & 0x1F) || (gPlayer[0]->unk_02B.unk_1 & 0x1F) ||
                    (gPlayer[0]->unk_02B.unk_2 & 0x1F) || (gPlayer[0]->unk_02B.unk_3 & 0x1F) ||
                    (gPlayer[0]->unk_02B.unk_4 & 0x1F) || (gPlayer[0]->unk_02B.unk_5 & 0x1F)) {
                    B_8018A850_usa[gnCountMenu++] = MT_1P_ATTACK_CHARACTER;
                }
            }

            eType = B_8018A850_usa[gnCountMenu - 1];
            func_800194DC_usa(eType);
            menuSetScreen(eType, 0);
        }
    }
}

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001BFF0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C034_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C070_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C0DC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C138_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C184_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C20C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C270_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C344_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C390_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C488_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C540_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C648_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C65C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C67C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C744_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C79C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C804_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/menu", func_8001C828_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C12C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C170_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C1AC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C218_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C274_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C2C0_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C348_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C3AC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C480_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C4CC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C5C4_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C67C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C784_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C798_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C7B8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C880_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C8D8_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C940_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/menu", func_8001C964_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C144_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C188_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C1C4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C230_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C28C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C2D8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C360_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C3C4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C498_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C4E4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C5DC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C694_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C79C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C7B0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C7D0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C898_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C8F0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C958_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/menu", func_8001C97C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C1AC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C1F0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C22C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C298_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C2F4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C340_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C3C8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C42C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C500_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C54C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C644_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C6FC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C804_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C818_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C838_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C900_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C958_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C9C0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/menu", func_8001C9E4_ger);
#endif

// TODO: remove
const s64 menu_fill_space = 0;
