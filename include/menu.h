#ifndef MENU_H
#define MENU_H

#include "ultra64.h"
#include "other_types.h"
#include "unk.h"

struct struct_gInfo_unk_00068;


typedef enum enum_menuTickFairy_ePosition {
    MFP_NONE = 0,
    MFP_LEFT = 1,
    MFP_LEFT_MIDDLE = 2,
    MFP_RIGHT_MIDDLE = 3,
    MFP_RIGHT = 4,
} enum_menuTickFairy_ePosition;


// void func_800072A0_usa();
// void func_80007538_usa();
// void func_800077AC_usa();
// void func_80007E68_usa();
// void func_80007F64_usa();
// void func_8000817C_usa();
// void func_800081F0_usa();
// void func_80008428_usa();
// void func_800084E0_usa();
// void func_80008818_usa();
// void func_800088A0_usa();
// void menuSetScreen();
nbool func_80008EA4_usa(s32 *arg0, s32 arg1, UNK_PTR arg2);
// void func_8000901C_usa();
// void func_80009228_usa();
// void func_80009440_usa();
// void func_800095F8_usa();
// void func_80009A78_usa();
// void func_80009CA8_usa();
// void func_80009D30_usa();
// void func_80009DBC_usa();
// void func_80009F60_usa();
// void func_8000A940_usa();
// void func_8000AABC_usa();
// void func_8000AC80_usa();
// void func_8000AE84_usa();
// void func_8000B25C_usa();
// void func_8000B48C_usa();
// void func_8000B7E4_usa();
// void func_8000BBCC_usa();
// void func_8000BD34_usa();
// void func_8000C338_usa();
// void func_8000C8C0_usa();
// void func_8000CDEC_usa();
// void func_8000D7D8_usa();
// void func_8000D990_usa();
// void func_8000DBEC_usa();
// void func_8000DD28_usa();
// void func_8000ED60_usa();
// void func_8000EF04_usa();
// void func_8000F104_usa();
// void func_8000F2B4_usa();
// void func_8000F6CC_usa();
// void func_8000F7FC_usa();
// void func_8000FA44_usa();
// void func_80010050_usa();
// void func_80010238_usa();
// void func_80010474_usa();
// void func_80010724_usa();
// void func_80011F30_usa();
// void func_8001225C_usa();
// void func_80012434_usa();
// void func_80012738_usa();
// void func_80012A64_usa();
// void func_80012EF4_usa();
// void func_8001305C_usa();
// void func_80013100_usa();
// void func_8001348C_usa();
// void func_800136E8_usa();
// void func_80013948_usa();
// void func_80013D8C_usa();
// void func_80013FB4_usa();
// void func_800142DC_usa();
// void func_80014970_usa();
// void func_80014C6C_usa();
// void func_80014EFC_usa();
// void func_800150B4_usa();
// void func_80016690_usa();
// void func_800169E4_usa();
// void func_80016C34_usa();
// void func_80016F6C_usa();
// void func_80017134_usa();
// void func_80017470_usa();
// void func_800175F8_usa();
// void func_80017A48_usa();
// void func_80017B64_usa();
// void func_80017E18_usa();
// void func_80018EAC_usa();
// void func_80018EF8_usa();
void menuSaveData(UNK_TYPE arg0);
// void func_800194DC_usa();
// void func_80019A24_usa();
// void func_80019DAC_usa();
// void func_80019F44_usa();
s32 menuInitUser(u32 arg0);
// void func_8001A330_usa();
// void func_8001A50C_usa();
void menuInitFairy(enum_menuTickFairy_ePosition ePosition);
void menuTickFairy(s32, s32, s32, s32, s32, s32, u32, s32);
// void menuTickFairy(s32 iScreen, s32 nFrame, s32 nTagText, s32 nOffsetText, s32 nOffsetBox, enum_menuTickFairy_ePosition ePosition, s32 bArrow);
// void func_8001AB0C_usa();
// void func_8001ACA8_usa();
void DrawMenu(struct struct_gInfo_unk_00068 *arg0);
void DoMenu(void);
void InitMenu(void);
// void func_8001BFF0_usa();
// void func_8001C034_usa();
// void func_8001C070_usa();
// void func_8001C0DC_usa();
// void func_8001C138_usa();
// void func_8001C184_usa();
// void func_8001C20C_usa();
// void func_8001C270_usa();
// void func_8001C344_usa();
// void func_8001C390_usa();
// void func_8001C488_usa();
// void func_8001C540_usa();
// void func_8001C648_usa();
// void func_8001C65C_usa();
// void func_8001C67C_usa();
// void func_8001C744_usa();
// void func_8001C79C_usa();
// void func_8001C804_usa();
// void func_8001C828_usa();

#endif
