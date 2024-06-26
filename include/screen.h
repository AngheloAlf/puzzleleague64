#ifndef SCREEN_H
#define SCREEN_H

#include "ultra64.h"
#include "unk.h"


typedef struct struct_gaScreen_unk_18_unk_5C {
    /* 0x0 */ u16 unk_0;
    /* 0x2 */ u16 unk_2;
    /* 0x4 */ u16 unk_4;
    /* 0x4 */ u16 unk_6;
} struct_gaScreen_unk_18_unk_5C; // size = 0x8

typedef struct struct_gaScreen_unk_18 {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x04 */ UNK_TYPE4 unk_04;
    /* 0x08 */ UNK_TYPE4 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ UNK_TYPE4 unk_10;
    /* 0x14 */ UNK_TYPE4 unk_14;
    /* 0x18 */ UNK_TYPE4 unk_18;
    /* 0x1C */ UNK_TYPE4 unk_1C;
    /* 0x20 */ UNK_TYPE4 unk_20;
    /* 0x24 */ UNK_TYPE4 unk_24;
    /* 0x28 */ UNK_TYPE4 unk_28;
    /* 0x2C */ UNK_TYPE4 unk_2C;
    /* 0x30 */ UNK_TYPE4 unk_30;
    /* 0x34 */ UNK_TYPE4 unk_34;
    /* 0x38 */ u8 *unk_38;
    /* 0x3C */ UNK_TYPE4 unk_3C;
    /* 0x40 */ UNK_TYPE4 unk_40;
    /* 0x44 */ UNK_TYPE4 unk_44;
    /* 0x48 */ UNK_TYPE4 unk_48;
    /* 0x4C */ UNK_TYPE4 unk_4C;
    /* 0x50 */ UNK_TYPE4 unk_50;
    /* 0x54 */ UNK_TYPE4 unk_54;
    /* 0x58 */ UNK_TYPE4 unk_58;
    /* 0x5C */ struct_gaScreen_unk_18_unk_5C *unk_5C;
} struct_gaScreen_unk_18; // size = 0x60

typedef struct struct_gaScreen_unk_20 {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x04 */ UNK_TYPE4 unk_04;
    /* 0x08 */ UNK_TYPE4 unk_08;
    /* 0x0C */ UNK_TYPE4 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ UNK_TYPE1 unk_18[0x4];
    /* 0x1C */ UNK_TYPE4 unk_1C;
    /* 0x20 */ UNK_TYPE4 unk_20;
    /* 0x24 */ u32 unk_24;
    /* 0x28 */ UNK_TYPE4 unk_28;
    /* 0x2C */ UNK_TYPE1 unk_2C[0x4];
} struct_gaScreen_unk_20; // size = 0x30

typedef struct struct_gaScreen_unk_1C {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x04 */ UNK_TYPE4 unk_04;
    /* 0x08 */ UNK_TYPE4 unk_08;
    /* 0x0C */ UNK_TYPE unk_0C;
    /* 0x10 */ UNK_TYPE unk_10;
    /* 0x14 */ UNK_TYPE4 *unk_14;
    /* 0x18 */ UNK_TYPE1 unk_18[0x2];
    /* 0x18 */ u16 unk_1A;
    /* 0x1C */ UNK_TYPE unk_1C;
    /* 0x20 */ UNK_TYPE unk_20;
    /* 0x24 */ UNK_TYPE unk_24;
    /* 0x28 */ UNK_TYPE1 unk_28[0x4];
    /* 0x2C */ UNK_TYPE *unk_2C;
    /* 0x30 */ UNK_TYPE1 unk_30[0xC];
    /* 0x3C */ UNK_TYPE unk_3C;
    /* 0x40 */ UNK_TYPE unk_40;
    /* 0x44 */ u32 unk_44;
    /* 0x48 */ UNK_TYPE1 unk_48[0x8];
    /* 0x50 */ u16 *unk_50;
    /* 0x54 */ UNK_TYPE unk_54;
    /* 0x58 */ UNK_TYPE unk_58;
    /* 0x5C */ UNK_TYPE unk_5C;
    /* 0x60 */ UNK_TYPE unk_60;
    /* 0x64 */ UNK_TYPE4 *unk_64;
    /* 0x68 */ UNK_TYPE4 *unk_68;
} struct_gaScreen_unk_1C; // size = 0x6C

typedef struct struct_gaScreen_unk_24 {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x04 */ UNK_TYPE4 unk_04;
    /* 0x08 */ UNK_TYPE4 unk_08;
    /* 0x0C */ UNK_TYPE4 unk_0C;
    /* 0x10 */ UNK_TYPE4 unk_10;
    /* 0x14 */ UNK_TYPE4 unk_14;
    /* 0x18 */ UNK_TYPE4 unk_18;
    /* 0x1C */ UNK_TYPE4 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ UNK_TYPE1 unk_24[0x4];
    /* 0x28 */ UNK_TYPE4 unk_28;
    /* 0x2C */ s32 unk_2C;
} struct_gaScreen_unk_24; // size = 0x30


#define GASCREEN_UNK_28_LEN 2U

typedef struct struct_gaScreen {
    /* 0x00 */ char *unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ UNK_TYPE4 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ struct_gaScreen_unk_18 *unk_18;
    /* 0x1C */ struct_gaScreen_unk_1C *unk_1C;
    /* 0x20 */ struct_gaScreen_unk_20 *unk_20;
    /* 0x24 */ struct_gaScreen_unk_24 *unk_24;
    /* 0x28 */ UNK_TYPE4 unk_28[GASCREEN_UNK_28_LEN];
    /* 0x30 */ UNK_TYPE4 unk_30[GASCREEN_UNK_28_LEN];
} struct_gaScreen; // size = 0x38


typedef struct struct_800222F0_usa_arg2 {
    /* 0x00 */ UNK_TYPE unk_00;
    /* 0x04 */ UNK_TYPE unk_04;
    /* 0x08 */ UNK_TYPE unk_08;
    /* 0x0C */ UNK_TYPE unk_0C;
    /* 0x10 */ UNK_TYPE unk_10;
} struct_800222F0_usa_arg2; // size >= 0x14


typedef struct screenTick_arg0 {
    /* 0x0 */ s32 unk_0;
    /* 0x4 */ s32 unk_4;
} screenTick_arg0; // size = 0x8



s32 screenCenterText(struct_gaScreen_unk_1C *arg0);
// void func_80022AF4_usa();
void screenUpdateArea(struct_gaScreen_unk_18 *arg0);
void screenWipeImages(void);
// void func_8002400C_usa();
// void func_80024534_usa();
// void func_8002496C_usa();
// void func_80024BF4_usa();
// void func_80024C14_usa();
s32 screenFlushing(void);
void screenDraw(Gfx **gfxP, void (*callback)(Gfx **, UNK_TYPE, UNK_TYPE));
s32 screenFindImage(s32 arg0, s32 arg1, struct_gaScreen_unk_1C **arg2);
// void func_800255D8_usa();
// void func_80025850_usa();
// void func_80025CC4_usa();
void screenTick(screenTick_arg0 *arg0);
s32 screenSet(const char *arg0, s32 arg1);
// void screenGet();
// void func_8002759C_usa();
// void func_800275A4_usa();
// void func_800275AC_usa();
// void func_80027618_usa();
s32 func_800276CC_usa(s32 arg0, UNK_TYPE4 *arg1, s32 arg2);
// void func_8002776C_usa();
// void func_80027838_usa();
// void func_80027914_usa();
// void func_800279D8_usa();
// void func_80027AB0_usa();
// void func_80027AD4_usa();
// void func_80027AF4_usa();
// void func_80027C04_usa();
s32 screenHideText(s32 arg0, s32 arg1);
// void func_80027E80_usa();
// void func_8002801C_usa();
// void func_80028034_usa();
// void func_800282AC_usa();
s32 screenHideImage(s32 arg0, s32 arg1);
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
void screenSetText(s32 arg0, s32 arg1, u16 *arg2);
// void func_80029130_usa();
// void func_80029244_usa();
// void func_8002931C_usa();
// void func_800293FC_usa();
// void func_800294C8_usa();
// void func_80029594_usa();
void func_800296B0_usa(u16 *dst, const char *src, s32 dstLen);
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
s32 screenFind(s32 *dst, const char *arg1);
s32 screenLoad(char *arg0, void **arg1);
void screenSetup(void);
// void func_8002B5C4_usa();



// extern UNK_TYPE B_8018E4F0_usa;
extern void *B_8018E4F4_usa;
extern void *B_8018E4F8_usa;
// extern UNK_TYPE B_8018E4FC_usa;
// extern UNK_TYPE B_8018E500_usa;
extern s32 B_8018E504_usa;
extern s32 gnImageCount;
extern UNK_TYPE4 * gapImage;
extern char * *gapNameImage;
extern s32 gnScreenCount;

extern struct_gaScreen *gaScreen;
extern s32 giScreen;
extern s32 B_8018E524_usa;
extern s32 B_8018E528_usa;
extern s32 B_8018E52C_usa;
extern s32 B_8018E530_usa;
extern s32 gnAlphaFade;
extern s32 geModeFade;
extern s32 B_8018E53C_usa;
extern s32 B_8018E540_usa;
// extern UNK_TYPE B_8018E544_usa;
// extern UNK_TYPE B_8018E548_usa;
extern s32 B_8018E550_usa;
// extern UNK_TYPE B_8018E554_usa;
extern s32 B_8018E558_usa;



#endif
