#ifndef PLAYER_T_H
#define PLAYER_T_H

#include "ultra64.h"
#include "unk.h"

typedef struct player_t_unk_002 {
    /* 0x0 */ UNK_PAD unk_0[0xE];
} player_t_unk_002; // size = 0xE

typedef struct player_t_unk_02B {
    /* 0x0 */ UNK_PAD unk_0;
    /* 0x1 */ UNK_PAD unk_1;
    /* 0x2 */ UNK_PAD unk_2;
    /* 0x3 */ UNK_PAD unk_3;
    /* 0x4 */ UNK_PAD unk_4;
    /* 0x5 */ u8 unk_5;
} player_t_unk_02B; // size = 0x6

typedef struct player_t_unk_034 {
    /* 0x00 */ UNK_PAD unk_00[0x80];
} player_t_unk_034; // size = 0x80



typedef struct player_t_unk_0F1 {
    /* 0x0 */ UNK_PAD unk_0[0x8];
} player_t_unk_0F1; // size = 0x8

typedef struct player_t_unk_0F9 {
    /* 0x0 */ UNK_PAD unk_0[0x8];
} player_t_unk_0F9; // size = 0x8

typedef struct player_t_unk_101 {
    /* 0x0 */ UNK_PAD unk_0[0x8];
} player_t_unk_101; // size = 0x8

typedef struct player_t_unk_109 {
    /* 0x0 */ UNK_PAD unk_0[0x8];
} player_t_unk_109; // size = 0x8

typedef struct player_t_unk_111 {
    /* 0x0 */ UNK_PAD unk_0[0x8];
} player_t_unk_111; // size = 0x8

typedef struct player_t_unk_119 {
    /* 0x0 */ UNK_PAD unk_0[0x8];
} player_t_unk_119; // size = 0x8


typedef struct player_t_unk_121 {
    /* 0x000 */ UNK_PAD unk_000[0x672];
} player_t_unk_121; // size = 0x672

typedef struct player_t_unk_7A2 {
    /* 0x00 */ UNK_PAD unk_00[0xA];
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u16 unk_0E;
    /* 0x10 */ UNK_PAD unk_10[0x2];
} player_t_unk_7A2; // size = 0x12

typedef struct player_t_unk_7B4 {
    /* 0x0 */ u16 unk_0;
    /* 0x2 */ u16 unk_2;
    /* 0x4 */ u16 unk_4;
} player_t_unk_7B4; // size = 0x6


#define STRUCT_801A6DB8_USA_UNK_0B7_COUNT 4
#define STRUCT_801A6DB8_USA_UNK_0BB_COUNT 7
#define STRUCT_801A6DB8_USA_UNK_0C2_COUNT 7
#define STRUCT_801A6DB8_USA_UNK_0C9_COUNT 4
#define STRUCT_801A6DB8_USA_UNK_0CD_COUNT 7
#define STRUCT_801A6DB8_USA_UNK_0D4_COUNT 7

// substruct of gTheGame
typedef struct player_t {
    /* 0x000 */ char unk_000;
    /* 0x001 */ UNK_PAD unk_001[0x1];
    /* 0x002 */ player_t_unk_002 unk_002;
    /* 0x010 */ u8 unk_010;
    /* 0x014 */ s32 unk_014;
    /* 0x018 */ s32 unk_018;
    /* 0x01C */ s32 unk_01C;
    /* 0x020 */ s32 unk_020;
    /* 0x024 */ s32 unk_024;
    /* 0x028 */ u8 unk_028;
    /* 0x029 */ u8 unk_029;
    /* 0x02A */ u8 unk_02A;
    /* 0x02B */ player_t_unk_02B unk_02B;
    /* 0x031 */ UNK_PAD unk_031[0x3]; // maybe struct padding?
    /* 0x034 */ player_t_unk_034 unk_034;
    /* 0x0B4 */ u8 unk_0B4;
    /* 0x0B5 */ u8 unk_0B5;
    /* 0x0B6 */ u8 unk_0B6;
    /* 0x0B7 */ char unk_0B7[STRUCT_801A6DB8_USA_UNK_0B7_COUNT];
    /* 0x0BB */ char unk_0BB[STRUCT_801A6DB8_USA_UNK_0BB_COUNT];
    /* 0x0C2 */ char unk_0C2[STRUCT_801A6DB8_USA_UNK_0C2_COUNT];
    /* 0x0C9 */ char unk_0C9[STRUCT_801A6DB8_USA_UNK_0C9_COUNT];
    /* 0x0CD */ char unk_0CD[STRUCT_801A6DB8_USA_UNK_0CD_COUNT];
    /* 0x0D4 */ char unk_0D4[STRUCT_801A6DB8_USA_UNK_0D4_COUNT];
    /* 0x0DB */ u8 unk_0DB;
    /* 0x0DC */ u8 unk_0DC;
    /* 0x0DD */ u8 unk_0DD;
    /* 0x0DE */ u8 unk_0DE;
    /* 0x0DF */ u8 unk_0DF;
    /* 0x0E0 */ char unk_0E0;
    /* 0x0E1 */ char unk_0E1;
    /* 0x0E2 */ char unk_0E2;
    /* 0x0E3 */ char unk_0E3;
    /* 0x0E4 */ char unk_0E4;
    /* 0x0E5 */ u8 unk_0E5;
    /* 0x0E6 */ u8 unk_0E6;
    /* 0x0E7 */ u8 unk_0E7;
    /* 0x0E8 */ u8 unk_0E8;
    /* 0x0E9 */ u8 unk_0E9;
    /* 0x0EA */ u8 unk_0EA;
    /* 0x0EB */ u8 unk_0EB;
    /* 0x0EC */ u8 unk_0EC;
    /* 0x0ED */ u8 unk_0ED;
    /* 0x0EE */ u8 unk_0EE;
    /* 0x0EF */ u8 unk_0EF;
    /* 0x0F0 */ u8 unk_0F0;
    /* 0x0F1 */ player_t_unk_0F1 unk_0F1;
    /* 0x0F9 */ player_t_unk_0F9 unk_0F9;
    /* 0x101 */ player_t_unk_101 unk_101;
    /* 0x109 */ player_t_unk_109 unk_109;
    /* 0x111 */ player_t_unk_111 unk_111;
    /* 0x119 */ player_t_unk_119 unk_119;
    /* 0x121 */ player_t_unk_121 unk_121;
    /* 0x793 */ UNK_PAD unk_793[0xF];
    /* 0x7A2 */ player_t_unk_7A2 unk_7A2;
    /* 0x7B4 */ player_t_unk_7B4 unk_7B4;
    /* 0x7BA */ UNK_PAD unk_7BA[0x2];
} player_t; // size = 0x7BC

#if 0
struct player_t {
    // total size: 0x880
    char id; // offset 0x0, size 0x1
    signed short name[7]; // offset 0x2, size 0xE
    int kPLAYER1E_2Dscore; // offset 0x10, size 0x4
    int kPLAYER1E_3Dscore; // offset 0x14, size 0x4
    int kPLAYER1T_2Dscore; // offset 0x18, size 0x4
    int kPLAYER1T_3Dscore; // offset 0x1C, size 0x4
    int kPLAYER1C_2Dscore; // offset 0x20, size 0x4
    int kPLAYER1C_2Dlastscore; // offset 0x24, size 0x4
    int kPLAYER1C_3Dscore; // offset 0x28, size 0x4
    int kPLAYER1C_3Dlastscore; // offset 0x2C, size 0x4
    char kPLAYER1C_2Dhour; // offset 0x30, size 0x1
    char kPLAYER1C_2Dminute; // offset 0x31, size 0x1
    char kPLAYER1C_2Dsecond; // offset 0x32, size 0x1
    char kPLAYER1C_2Dround[6]; // offset 0x33, size 0x6
    int kPLAYER1C_2Dtime[32]; // offset 0x3C, size 0x80
    char kPLAYER1C_3Dhour; // offset 0xBC, size 0x1
    char kPLAYER1C_3Dminute; // offset 0xBD, size 0x1
    char kPLAYER1C_3Dsecond; // offset 0xBE, size 0x1
    char kPLAYER1C_3Dround[6]; // offset 0xBF, size 0x6
    int kPLAYER1C_3Dtime[32]; // offset 0xC8, size 0x80
    char kPLAYER1P_hour; // offset 0x148, size 0x1
    char kPLAYER1P_minute; // offset 0x149, size 0x1
    char kPLAYER1P_second; // offset 0x14A, size 0x1
    char kPLAYER1P_easy1[6]; // offset 0x14B, size 0x6
    char kPLAYER1P_hard1[6]; // offset 0x151, size 0x6
    char kPLAYER1P_easy2[6]; // offset 0x157, size 0x6
    char kPLAYER1P_hard2[6]; // offset 0x15D, size 0x6
    char kPLAYER1P_special[12]; // offset 0x163, size 0xC
    char kPLAYER1V_kEASY; // offset 0x16F, size 0x1
    char kPLAYER1V_kNORMAL; // offset 0x170, size 0x1
    char kPLAYER1V_kHARD; // offset 0x171, size 0x1
    char kPLAYER1V_kSHARD; // offset 0x172, size 0x1
    char kPLAYER1V_kULTRA; // offset 0x173, size 0x1
    char kPLAYER1V_kEASY_continue; // offset 0x174, size 0x1
    char kPLAYER1V_kNORMAL_continue; // offset 0x175, size 0x1
    char kPLAYER1V_kHARD_continue; // offset 0x176, size 0x1
    char kPLAYER1V_kSHARD_continue; // offset 0x177, size 0x1
    char kPLAYER1V_kULTRA_continue; // offset 0x178, size 0x1
    signed short kPLAYER1V_kEASY_character; // offset 0x17A, size 0x2
    signed short kPLAYER1V_kNORMAL_character; // offset 0x17C, size 0x2
    signed short kPLAYER1V_kHARD_character; // offset 0x17E, size 0x2
    signed short kPLAYER1V_kSHARD_character; // offset 0x180, size 0x2
    signed short kPLAYER1V_kULTRA_character; // offset 0x182, size 0x2
    signed short k2D_combo; // offset 0x184, size 0x2
    signed short k2D_comboMode; // offset 0x186, size 0x2
    signed short k2D_chain; // offset 0x188, size 0x2
    signed short k2D_chainMode; // offset 0x18A, size 0x2
    signed short k3D_combo; // offset 0x18C, size 0x2
    signed short k3D_comboMode; // offset 0x18E, size 0x2
    signed short k3D_chain; // offset 0x190, size 0x2
    signed short k3D_chainMode; // offset 0x192, size 0x2
    char kPLAYER2V_2Dwin[8]; // offset 0x194, size 0x8
    char kPLAYER2V_2Dlose[8]; // offset 0x19C, size 0x8
    char kPLAYER2V_3Dwin[8]; // offset 0x1A4, size 0x8
    char kPLAYER2V_3Dlose[8]; // offset 0x1AC, size 0x8
    char kPLAYER2T_2Dwin[8]; // offset 0x1B4, size 0x8
    char kPLAYER2T_2Dlose[8]; // offset 0x1BC, size 0x8
    char kPLAYER2T_3Dwin[8]; // offset 0x1C4, size 0x8
    char kPLAYER2T_3Dlose[8]; // offset 0x1CC, size 0x8
    char kPLAYER2L_2Dwin[8]; // offset 0x1D4, size 0x8
    char kPLAYER2L_2Dlose[8]; // offset 0x1DC, size 0x8
    char kPLAYER2L_3Dwin[8]; // offset 0x1E4, size 0x8
    char kPLAYER2L_3Dlose[8]; // offset 0x1EC, size 0x8
    unsigned char kPLAYER1PE_editor[1650]; // offset 0x1F4, size 0x672
    signed short menu_setting[12]; // offset 0x866, size 0x18
};
#endif


#endif
