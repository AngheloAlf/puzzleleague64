#ifndef SCREEN_H
#define SCREEN_H

#include "libultra.h"
#include "unk.h"


typedef struct struct_gaScreen_unk_18 {
    /* 0x00 */ UNK_TYPE1 unk_00[0xC];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ UNK_TYPE1 unk_10[0x50];
} struct_gaScreen_unk_18; // size = 0x60

typedef struct struct_gaScreen_unk_20 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x14];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ UNK_TYPE1 unk_18[0x18];
} struct_gaScreen_unk_20; // size = 0x30

typedef struct struct_gaScreen_unk_24 {
    /* 0x00 */ UNK_TYPE1 unk_00[0x20];
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ UNK_TYPE1 unk_24[0xC];
} struct_gaScreen_unk_24; // size = 0x30

typedef struct struct_gaScreen {
    /* 0x00 */ UNK_TYPE1 unk_00[0x8];
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ UNK_TYPE1 unk_0C[0x4];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ struct_gaScreen_unk_18 *unk_18;
    /* 0x1C */ UNK_TYPE1 unk_1C[0x4];
    /* 0x20 */ struct_gaScreen_unk_20 *unk_20;
    /* 0x24 */ struct_gaScreen_unk_24 *unk_24;
    /* 0x28 */ UNK_TYPE1 unk_28[0x10];
} struct_gaScreen; // size = 0x38


// void func_800222F0_usa();
// void func_80022854_usa();
// void func_80022AF4_usa();
// void func_80023868_usa();
void screenWipeImages(void);
// void func_8002400C_usa();
// void func_80024534_usa();
// void func_8002496C_usa();
// void func_80024BF4_usa();
// void func_80024C14_usa();
s32 func_80024C2C_usa(void);
// void func_80024C54_usa();
// void func_8002552C_usa();
// void func_800255D8_usa();
// void func_80025850_usa();
// void func_80025CC4_usa();
// void func_8002629C_usa();
// void func_800273BC_usa();
// void func_8002758C_usa();
// void func_8002759C_usa();
// void func_800275A4_usa();
// void func_800275AC_usa();
// void func_80027618_usa();
// void func_800276CC_usa();
// void func_8002776C_usa();
// void func_80027838_usa();
// void func_80027914_usa();
// void func_800279D8_usa();
// void func_80027AB0_usa();
// void func_80027AD4_usa();
// void func_80027AF4_usa();
// void func_80027C04_usa();
// void func_80027D0C_usa();
// void func_80027E80_usa();
// void func_8002801C_usa();
// void func_80028034_usa();
// void func_800282AC_usa();
// void func_80028378_usa();
// void func_800284E4_usa();
// void func_8002864C_usa();
// void func_80028718_usa();
// void func_8002880C_usa();
// void func_800288D8_usa();
// void func_800289C0_usa();
// void func_80028A98_usa();
// void func_80028BAC_usa();
// void func_80028CBC_usa();
// void func_80028DC0_usa();
// void func_80028E80_usa();
// void func_80028F44_usa();
// void func_80029130_usa();
// void func_80029244_usa();
// void func_8002931C_usa();
// void func_800293FC_usa();
// void func_800294C8_usa();
// void func_80029594_usa();
// void func_800296B0_usa();
// void func_800297C8_usa();
// void func_80029980_usa();
// void func_80029A44_usa();
// void func_80029B10_usa();
// void func_80029C4C_usa();
// void func_80029D24_usa();
// void func_80029EC4_usa();
// void func_8002A074_usa();
// void func_8002A1F4_usa();
// void func_8002A2E8_usa();
// void func_8002A3B8_usa();
// void func_8002A488_usa();
// void func_8002A4FC_usa();
// void func_8002A574_usa();
// void func_8002A638_usa();
// void func_8002A708_usa();
// void screenLoad();
void screenSetup();
// void func_8002B5C4_usa();



// extern UNK_TYPE B_8018E4F0_usa;
extern s32 B_8018E4F4_usa;
extern s32 B_8018E4F8_usa;
// extern UNK_TYPE B_8018E4FC_usa;
// extern UNK_TYPE B_8018E500_usa;
extern s32 B_8018E504_usa;
extern s32 gnImageCount;
extern UNK_TYPE4 * gapImage;
extern UNK_TYPE *B_8018E510_usa;
extern s32 gnScreenCount;

extern struct_gaScreen *gaScreen;
extern s32 B_8018E520_usa;
extern s32 B_8018E524_usa;
extern s32 B_8018E528_usa;
// extern UNK_TYPE B_8018E52C_usa;
extern s32 B_8018E530_usa;
extern s32 B_8018E534_usa;
extern s32 B_8018E538_usa;
// extern UNK_TYPE B_8018E53C_usa;
extern s32 B_8018E540_usa;
// extern UNK_TYPE B_8018E544_usa;
// extern UNK_TYPE B_8018E548_usa;
extern s32 B_8018E550_usa;
// extern UNK_TYPE B_8018E554_usa;
extern s32 B_8018E558_usa;
extern UNK_TYPE gpImageNo;
extern UNK_TYPE gpImageYes;
extern s32 B_8018E564_usa;
extern s32 B_8018E568_usa;
extern s32 B_8018E56C_usa;




#endif
