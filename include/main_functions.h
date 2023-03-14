#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H

#include "libultra.h"
#include "unk.h"
#include "unknown_structs.h"
#include "version.h"


// void func_80000450_usa();
// void bootproc();
void Idle_ThreadEntry(void *arg);
void func_80000630_usa(void);
void Main_ThreadEntry(void *arg);
s32 func_800009E4_usa(s32 arg0);
s32 func_80000EF8_usa(s32 arg0);

// void func_80001310_usa();
void func_80001330_usa();
s32 func_800013AC_usa(struct_801C7BB0_usa *arg0);
// void func_800016D8_usa();
// void func_8000177C_usa();
// void func_8000182C_usa();
// void func_800019C0_usa();
// void func_80001B10_usa();
// void func_80001CAC_usa();
// void func_80001D60_usa();
// void func_80001E98_usa();
// void func_80001ED8_usa();
// void func_80001F1C_usa();
// void func_80001F40_usa();
// void func_80001F68_usa();
// void func_80001F90_usa();
// void func_80002054_usa();
// void func_8000222C_usa();
// void func_80002348_usa();
// void func_80002620_usa();
// void func_80002684_usa();
// void func_80002694_usa();
// void func_800026A0_usa();
// void func_800026C0_usa();
// void func_8000272C_usa();
// void func_8000274C_usa();
// void func_800027FC_usa();
// void func_8000288C_usa();
// void func_800028B8_usa();
// void func_800028D8_usa();
// void func_80002A10_usa();
// void func_80002AE8_usa();
// void func_80002C50_usa();
// void func_80002C7C_usa();
// void func_80002CB4_usa();
// void func_80002CE0_usa();
// void func_80002D04_usa();
// void func_80002D30_usa();
void func_80002D5C_usa();
// void func_80002D8C_usa();
void func_80002DE8_usa();
// void func_80002E0C_usa();
// void func_80002E34_usa();
// void func_80002E70_usa();
// void func_80002EB8_usa();
// void func_80002F48_usa();
// void func_80002F68_usa();
// void func_80002F88_usa();
// void func_80002F98_usa();
// void func_80002FD0_usa();
// void func_80003054_usa();
// void func_800030D0_usa();
// void func_800030F0_usa();
// void func_800032A4_usa();
// void func_8000337C_usa();
// void func_8000339C_usa();
// void func_800033BC_usa();
// void func_800033DC_usa();
// void func_80003458_usa();
// void func_80003484_usa();
// void func_800034B4_usa();
// void func_800034EC_usa();
// void func_8000353C_usa();
// void func_800036D0_usa();
// void func_800036F0_usa();
// void func_80003760_usa();
// void func_800037A8_usa();
// void func_800037E8_usa();
// void func_800038E4_usa();
void func_800039C0_usa();
// void func_80003CE8_usa();
// void func_80003E00_usa();
void func_80003E90_usa();
// void func_80004060_usa();
// void func_800040D8_usa();
// void func_800045D8_usa();
// void func_80004848_usa();
// void func_8000486C_usa();
// void func_800048C0_usa();
// void func_80004B9C_usa();
// void func_80004E10_usa();
// void func_80005018_usa();
// void func_800050C0_usa();
// void func_80005130_usa();
// void func_80005184_usa();
// void func_80005270_usa();
// void func_8000541C_usa();
// void func_80005608_usa();
// void func_80005780_usa();
// void func_80005888_usa();
// void func_80005A08_usa();
// void func_80005B84_usa();
// void func_80005C00_usa();
// void func_80005EC0_usa();
// void func_8000620C_usa();
// void func_8000628C_usa();
void func_800062D0_usa();
// void func_80006EC4_usa();
void func_80007204_usa();
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
// void func_80008BB8_usa();
// void func_80008EA4_usa();
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
// void func_800192F4_usa();
// void func_800194DC_usa();
// void func_80019A24_usa();
// void func_80019DAC_usa();
// void func_80019F44_usa();
// void func_8001A158_usa();
// void func_8001A330_usa();
// void func_8001A50C_usa();
// void func_8001A7D0_usa();
// void func_8001A854_usa();
// void func_8001AB0C_usa();
// void func_8001ACA8_usa();
// void func_8001AD2C_usa();
void func_8001AEB0_usa();
// void func_8001BB54_usa();
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
// void func_8001C8B0_usa();
// void func_8001CA94_usa();
// void func_8001CAC4_usa();
// void func_8001CAD0_usa();
// void func_8001CB3C_usa();
// void func_8001CC74_usa();
// void func_8001CC7C_usa();
// void func_8001D1F8_usa();
void func_8001D278_usa();
// void func_8001D304_usa();
// void func_8001D310_usa();
// void func_8001D524_usa();
// void func_8001DCC4_usa();
// void func_8001E018_usa();
// void func_8001E0F8_usa();
// void func_8001E110_usa();
// void func_8001E184_usa();
// void func_8001E1E4_usa();
void func_8001EC9C_usa();
// void func_8001ECA4_usa();
// void func_8001ECB0_usa();
// void func_8001EDE0_usa();
// void func_8001F6B8_usa();
// void func_8001FC08_usa();
// void func_8001FD0C_usa();
// void func_8001FD94_usa();
// void func_8001FF70_usa();
// void func_80020044_usa();
// void func_800200B4_usa();
// void func_80020208_usa();
// void func_80020304_usa();
// void func_800205AC_usa();
// void func_8002063C_usa();
// void func_800206DC_usa();
// void func_80020754_usa();
// void func_800207FC_usa();
// void func_800209BC_usa();
// void func_80021414_usa();
// void func_8002156C_usa();
// void func_80022184_usa();
// void func_80022268_usa();
void func_800222D0_usa();
// void func_800222E4_usa();
// void func_800222F0_usa();
// void func_80022854_usa();
// void func_80022AF4_usa();
// void func_80023868_usa();
// void func_80023ECC_usa();
// void func_8002400C_usa();
// void func_80024534_usa();
// void func_8002496C_usa();
// void func_80024BF4_usa();
// void func_80024C14_usa();
// void func_80024C2C_usa();
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
// void func_8002A7D4_usa();
void func_8002B570_usa();
// void func_8002B5C4_usa();
// void func_8002B5D0_usa();
// void func_8002B5D8_usa();
// void func_8002B600_usa();
// void func_8002B76C_usa();
// void func_8002B7C8_usa();
// void func_8002B85C_usa();
// void func_8002B8B0_usa();
void func_8002B8E8_usa();
// void func_8002BD30_usa();
// void func_8002BE98_usa();
// void func_8002C2C0_usa();
// void func_8002CC18_usa();
// void func_8002CFC8_usa();
// void func_8002CFE4_usa();
// void func_8002DA70_usa();
void func_8002DAC8_usa();
// void func_8002DBF0_usa();
// void func_8002DC00_usa();
// void func_8002EDF0_usa();
// void func_8002EDFC_usa();
// void func_8002F194_usa();
// void func_8002F2E0_usa();
// void func_8002F2E8_usa();
// void func_8002F2F0_usa();
// void func_8002F464_usa();
// void func_8002F73C_usa();
// void func_8002F984_usa();
// void func_8002FCF0_usa();
// void func_8002FF38_usa();
// void func_80030278_usa();
// void func_800304FC_usa();
// void func_800306B0_usa();
// void func_8003077C_usa();
void func_800308A8_usa();
// void func_80030A7C_usa();
// void func_80030D10_usa();
// void func_80030D6C_usa();
// void func_80030DC8_usa();
// void func_80030E08_usa();
// void func_80030F20_usa();
void func_80031894_usa();
// void func_80031DDC_usa();
// void func_8003228C_usa();
// void func_800322D0_usa();
// void func_80032318_usa();
// void func_80032494_usa();
// void func_800325F8_usa();
void func_800326A0_usa();
// void func_80033004_usa();
// void func_80033648_usa();
void func_80033B10_usa();
// void func_80034140_usa();
// void func_8003434C_usa();
// void func_800343A0_usa();
// void func_800346B8_usa();
// void func_8003490C_usa();
// void func_80034DB8_usa();
// void func_8003520C_usa();
// void func_8003524C_usa();
// void func_800352DC_usa();
// void func_8003536C_usa();
// void func_800353B0_usa();
// void func_800353F4_usa();
// void func_80035438_usa();
// void func_8003547C_usa();
// void func_800354C0_usa();
// void func_80035504_usa();
// void func_80035584_usa();
// void func_800355EC_usa();
// void func_80035B20_usa();
// void func_80035FF0_usa();
// void func_800364BC_usa();
// void func_800364FC_usa();
// void func_80036A68_usa();
// void func_8003722C_usa();
// void func_80037270_usa();
// void func_80037358_usa();
// void func_80037440_usa();
// void func_80037724_usa();
// void func_80037900_usa();
// void func_800379D4_usa();
// void func_80037B0C_usa();
// void func_80037CBC_usa();
// void func_80038018_usa();
// void func_8003813C_usa();
// void func_80038228_usa();
// void func_8003837C_usa();
// void func_8003853C_usa();
// void func_800386D4_usa();
// void func_800387AC_usa();
// void func_8003880C_usa();
// void func_80038944_usa();
// void func_80038B98_usa();
// void func_80038C54_usa();
// void func_80038F84_usa();
// void func_8003901C_usa();
// void func_8003991C_usa();
// void func_80039A54_usa();
// void func_80039B78_usa();
// void func_80039DB0_usa();
// void func_8003A0B8_usa();
// void func_8003AD18_usa();
// void func_8003B590_usa();
// void func_8003BF04_usa();
// void func_8003BF44_usa();
// void func_8003D21C_usa();
void func_8003E4BC_usa();
// void func_8003E508_usa();
// void func_8003E530_usa();
// void func_8003E5DC_usa();
// void func_8003E638_usa();
// void func_8003E658_usa();
// void func_8003E684_usa();
// void func_8003E6B8_usa();
// void func_8003E714_usa();
// void func_8003E854_usa();
// void func_8003F0EC_usa();
// void func_8003F178_usa();
// void func_8003F1C0_usa();
// void func_8003F200_usa();
// void func_8003F2F0_usa();
// void func_8003F42C_usa();
// void func_8003F608_usa();
// void func_8003F810_usa();
// void func_800409E4_usa();
void func_80040A4C_usa();
// void func_80040A60_usa();
// void func_80040B1C_usa();
// void func_80040B80_usa();
// void func_80040DE4_usa();
// void func_80040F04_usa();
// void func_800410A4_usa();
// void func_8004123C_usa();
// void func_80041F1C_usa();
// void func_80042400_usa();
// void func_80042428_usa();
// void func_80042660_usa();
// void func_800427E4_usa();
// void func_800428B4_usa();
// void func_80042C24_usa();
// void func_80042FD4_usa();
// void func_80043110_usa();
// void func_80043380_usa();
// void func_8004360C_usa();
// void func_80043A60_usa();
// void func_80043CFC_usa();
// void func_80043D24_usa();
// void func_8004407C_usa();
// void func_80044280_usa();
// void func_8004441C_usa();
// void func_800445D8_usa();
// void func_800447C4_usa();
// void func_800449C4_usa();
// void func_80044A1C_usa();
// void func_80046470_usa();
// void func_80046648_usa();
// void func_80046C2C_usa();
void func_80046E10_usa();
// void func_80046E64_usa();
// void func_80046F8C_usa();
void func_80047050_usa();
void func_80047208_usa();
// void func_80047340_usa();
// void func_80047898_usa();
// void func_80047A00_usa();
// void func_80047D20_usa();
// void func_80047E64_usa();
// void func_8004879C_usa();
// void func_800488AC_usa();
// void func_80048D94_usa();
// void func_80049010_usa();
// void func_8004917C_usa();
// void func_80049584_usa();
// void func_80049960_usa();
// void func_8004A26C_usa();
// void func_8004A944_usa();
// void func_8004AA48_usa();
// void func_8004ADD0_usa();
// void func_8004AE90_usa();
// void func_8004B0D8_usa();
// void func_8004B12C_usa();
// void func_8004B300_usa();
// void func_8004BC64_usa();
// void func_8004C020_usa();
// void func_8004C1B8_usa();
// void func_8004C280_usa();
// void func_8004DA3C_usa();
// void func_8004DCC0_usa();
// void func_8004DF64_usa();
// void func_8004E450_usa();
// void func_8004E4E4_usa();
// void func_8004E5E8_usa();
// void func_8004E688_usa();
// void func_8004E854_usa();
// void func_8004E8CC_usa();
// void func_8004E9D8_usa();
// void func_8004EAB8_usa();
// void func_8004EB5C_usa();
// void func_8004EC08_usa();
// void func_8004EC4C_usa();
// void func_8004EDA0_usa();
// void func_8004EE24_usa();
// void func_8004EEFC_usa();
// void func_8004F010_usa();
// void func_8004F4BC_usa();
// void func_8004F5E4_usa();
// void func_8004F70C_usa();
// void func_8004FA2C_usa();
// void func_8004FABC_usa();
// void func_80050420_usa();
// void func_800504B8_usa();
// void func_8005076C_usa();
// void func_80050BA8_usa();
// void func_80050C2C_usa();
// void func_800512E0_usa();
// void func_80051998_usa();
// void func_800521A4_usa();
// void func_80052258_usa();
// void func_80052400_usa();
// void func_80052720_usa();
// void func_80052C28_usa();
// void func_80052E04_usa();
// void func_80053140_usa();
// void func_80053E64_usa();
// void func_80054020_usa();
// void func_8005405C_usa();
// void func_8005407C_usa();
// void func_800540AC_usa();
// void func_80054204_usa();
// void func_80054320_usa();
// void func_8005443C_usa();
// void func_80054454_usa();
// void func_800544D4_usa();
// void func_80054500_usa();
// void func_800545E4_usa();
// void func_80054624_usa();
// void func_800547E0_usa();
// void func_80054804_usa();
// void func_800549A4_usa();
// void func_80054A2C_usa();
// void func_800552F4_usa();
// void func_80055820_usa();
// void func_8005586C_usa();
// void func_80055D00_usa();
// void func_8005600C_usa();
// void func_80056180_usa();
// void func_800562FC_usa();
// void func_800564E0_usa();
// void func_800566C4_usa();
// void func_80056760_usa();
// void func_80056910_usa();
// void func_80056A3C_usa();
// void func_80056A7C_usa();
// void func_80056BAC_usa();
// void func_80056F70_usa();
// void func_800572B4_usa();
// void func_8005731C_usa();
// void func_80057650_usa();
// void func_80057754_usa();
// void func_80057950_usa();
// void func_80057D1C_usa();
// void func_80057D68_usa();
// void func_80057E10_usa();
// void func_80057EB8_usa();
// void func_80057F84_usa();
// void func_8005806C_usa();
// void func_80058168_usa();
// void func_8005825C_usa();
// void func_8005834C_usa();
// void func_80058458_usa();
// void func_8005866C_usa();
// void func_800587CC_usa();
// void func_80058934_usa();
// void func_80058A10_usa();
// void func_80058AE0_usa();
// void func_80058D68_usa();
// void func_80058DF0_usa();
// void func_80059038_usa();
// void func_800599C4_usa();
// void func_80059A18_usa();
// void func_80059A58_usa();
// void func_80059A98_usa();
void func_80059F84_usa(struct_801C7BB0_usa *arg0);
// void func_80059FC4_usa();
// void func_8005A2E8_usa();
// void func_8005A8D0_usa();
// void func_8005A990_usa();
// void func_8005A9EC_usa();
// void func_8005AAE0_usa();
// void func_8005AE18_usa();
// void func_8005B6E4_usa();
// void func_8005BBF4_usa();
// void func_8005BD24_usa();
// void func_8005BEFC_usa();
// void func_8005BFB4_usa();
// void func_8005C2C4_usa();
// void func_8005C460_usa();
// void func_8005C554_usa();
// void func_8005C718_usa();
// void func_8005C780_usa();
// void func_8005CAF0_usa();
// void func_8005CB30_usa();
// void func_8005CF68_usa();
// void func_8005D630_usa();
// void func_8005D868_usa();
// void func_8005D8B4_usa();
// void func_8005D900_usa();
// void func_8005DB88_usa();
// void func_8005DBD8_usa();
// void func_8005DCA8_usa();
// void func_8005DD3C_usa();
// void func_8005DDB4_usa();
// void func_8005DDF8_usa();
// void func_8005DE28_usa();
// void func_8005DE58_usa();
// void func_8005DE94_usa();
// void func_8005E0E8_usa();
// void func_8005E108_usa();
// void func_8005E128_usa();
// void func_8005E2DC_usa();
// void func_8005E360_usa();
// void func_8005E3F4_usa();
// void func_8005E484_usa();
// void func_8005E510_usa();
// void func_8005E740_usa();
// void func_8005E7A4_usa();
// void func_8005E9D4_usa();
// void func_8005F1C4_usa();
// void func_8005F984_usa();
// void func_8005FA6C_usa();
// void func_8005FB10_usa();
// void func_8005FD38_usa();
// void func_8005FF34_usa();
// void func_80060378_usa();
// void func_8006058C_usa();
// void func_80060DB4_usa();
// void func_800615D8_usa();
// void func_800616A4_usa();
// void func_800627E8_usa();
// void func_80062B20_usa();
// void func_80062DF0_usa();
// void func_80063110_usa();
// void func_80063F8C_usa();
// void func_800643A4_usa();
// void func_80064728_usa();
// void func_80064AAC_usa();
// void func_80064E44_usa();
// void func_8006531C_usa();
// void func_80065A40_usa();
// void func_80065AC0_usa();
// void func_800662D0_usa();
// void func_8006648C_usa();
// void func_800666F0_usa();
// void func_80066770_usa();
// void func_80066B84_usa();
// void func_80066BE8_usa();
// void func_80066C30_usa();
// void func_80066C50_usa();
// void func_80066C70_usa();
// void func_80067140_usa();
// void func_800671B4_usa();
// void func_800673B0_usa();
// void func_80067484_usa();
// void func_8006780C_usa();
// void func_80067860_usa();
// void func_80067CA0_usa();
// void func_80068BC0_usa();
// void func_80068E64_usa();
// void func_80068EDC_usa();
// void func_8006902C_usa();
// void func_8006908C_usa();
// void func_80069360_usa();
// void func_80069954_usa();
// void func_80069B8C_usa();
// void func_8006A650_usa();
// void func_8006A7E8_usa();
// void func_8006A8D8_usa();
// void func_8006A9EC_usa();
// void func_8006AA88_usa();
// void func_8006AC3C_usa();
// void func_8006ACCC_usa();
// void func_8006AF30_usa();
// void func_8006B24C_usa();
// void func_8006B314_usa();
// void func_8006B544_usa();
// void func_8006B628_usa();
// void func_8006B6A8_usa();
// void func_8006B730_usa();
// void func_8006B798_usa();
// void func_8006C0E0_usa();
// void func_8006C204_usa();
// void func_8006C4A0_usa();
// void func_8006C7A0_usa();
// void func_8006C9BC_usa();
// void func_8006CAC0_usa();
// void func_8006CB30_usa();
// void func_8006CBEC_usa();
// void func_8006CCA4_usa();
// void func_8006CD64_usa();
// void func_8006CE14_usa();
// void func_8006CEA0_usa();
// void func_8006D798_usa();
// void func_8006D87C_usa();
// void func_8006DED8_usa();
// void func_8006E254_usa();
// void func_8006EB24_usa();
// void func_8006EE48_usa();
// void func_8006F09C_usa();
// void func_8006F2FC_usa();
// void func_8006F4CC_usa();
// void func_8006F598_usa();
// void func_8006F6B0_usa();
// void func_8006FBD0_usa();
// void func_8006FC50_usa();
// void func_8006FF90_usa();
// void func_800703B8_usa();
// void func_80070428_usa();
// void func_80070478_usa();
// void func_800704C8_usa();
// void func_8007051C_usa();
// void func_80070B40_usa();
// void func_80070CA4_usa();
// void func_80070F50_usa();
// void func_800710CC_usa();
// void func_80071138_usa();
// void func_800716D0_usa();
// void func_8007194C_usa();
// void func_8007197C_usa();
// void func_80071AEC_usa();
// void func_80072198_usa();
// void func_800724A4_usa();
// void func_800726E4_usa();
// void func_80072E90_usa();
// void func_80072FDC_usa();
// void func_800730B0_usa();
// void func_80073138_usa();
// void func_8007320C_usa();
// void func_800733D0_usa();
// void func_80073488_usa();
// void func_80073680_usa();
// void func_8007371C_usa();
// void func_800737B8_usa();
// void func_800739F0_usa();
// void func_80073B30_usa();
// void func_80073C20_usa();
// void func_80073D10_usa();
// void func_80073E00_usa();
// void func_80073EF0_usa();
// void func_80073FE0_usa();
// void func_800740D0_usa();
// void func_800741C0_usa();
// void func_800742B0_usa();
// void func_800743A0_usa();
// void func_80074490_usa();
// void func_80074580_usa();
// void func_80074670_usa();
// void func_80074760_usa();
// void func_80074850_usa();
// void func_80074940_usa();
// void func_80074A30_usa();
// void func_80074A58_usa();
// void func_80074AEC_usa();
// void func_80074D4C_usa();
// void func_80074FF0_usa();
// void func_80075108_usa();
// void func_800751B4_usa();
// void func_80075278_usa();
// void func_80075354_usa();
// void func_80075458_usa();
// void func_80075524_usa();
// void func_800755B0_usa();
// void func_80075928_usa();
// void func_8007593C_usa();
// void func_80075980_usa();
// void func_800759DC_usa();
// void func_80075A1C_usa();
// void func_80075A38_usa();
// void func_80075A54_usa();
// void func_80075A60_usa();
// void func_80075A78_usa();
// void func_80075BC0_usa();
// void func_80075C60_usa();
// void func_80075D2C_usa();
// void func_80075E40_usa();
// void func_80076F54_usa();
// void func_80076F84_usa();
// void func_80077110_usa();
// void func_80077280_usa();
// void func_80077338_usa();
// void func_8007737C_usa();
// void func_80077670_usa();
// void func_800776FC_usa();
// void func_80077920_usa();
// void func_80077B00_usa();
// void func_8007855C_usa();
// void func_8007895C_usa();
// void func_80078B78_usa();
// void func_80078D78_usa();
// void func_80079094_usa();
// void func_8007928C_usa();
// void func_800794C8_usa();
// void func_8007959C_usa();
// void func_80079D64_usa();
// void func_80079DEC_usa();
// void func_8007A5C8_usa();
// void func_8007ACAC_usa();
// void func_8007AFF4_usa();
// void func_8007BF40_usa();
// void func_8007CE20_usa();
// void func_8007D484_usa();
// void func_8007E18C_usa();
// void func_8007EC98_usa();
// void func_8007F5AC_usa();
// void func_8007FEB4_usa();
// void func_80080504_usa();
// void func_80080724_usa();
// void func_80080AF0_usa();
// void func_800812A4_usa();
// void func_800814CC_usa();
// void func_800816DC_usa();
// void func_80082740_usa();
// void func_800829BC_usa();
// void func_80082CA0_usa();
// void func_80082EE0_usa();
// void func_80082F80_usa();
// void func_80083038_usa();
// void func_80083050_usa();
// void func_8008336C_usa();
// void func_800833B0_usa();
// void func_80083480_usa();
// void func_800844DC_usa();
// void func_80084758_usa();
// void func_80084A28_usa();
// void func_80084C18_usa();
// void func_80084C84_usa();
// void func_80084D24_usa();
// void func_80084D84_usa();
// void func_8008554C_usa();
// void func_80085CC8_usa();
// void func_80085E1C_usa();
void func_80085EEC_usa();
// void func_80087834_usa();
// void func_80087A90_usa();
// void func_80087B28_usa();
// void func_80088298_usa();
void func_80088570_usa();
// void func_8008885C_usa();
// void func_800888C4_usa();
// void func_80088940_usa();
// void func_80088A48_usa();
// void func_80088AB4_usa();
// void func_80088C08_usa();
// void func_80088D34_usa();
// void func_80088E38_usa();
// void func_80088F94_usa();
// void func_80089108_usa();
// void func_8008913C_usa();
// void func_80089200_usa();
// void func_8008928C_usa();
// void func_80089318_usa();
// void func_80089338_usa();
// void func_8008937C_usa();
// void func_800896C0_usa();
// void func_80089778_usa();
// void func_80089828_usa();
// void func_8008997C_usa();
s32 func_80089AEC_usa(s32 *arg0);
// void func_80089BE0_usa();
// void func_80089E6C_usa();
// void func_8008A7B4_usa();
// void func_8008ADB4_usa();
// void func_8008AE20_usa();
// void func_8008AF74_usa();
// void func_8008B21C_usa();
// void func_8008B2B0_usa();
// void func_8008B2DC_usa();
// void func_8008B310_usa();
// void func_8008B344_usa();
// void func_8008B598_usa();
// void func_8008B620_usa();
// void func_8008B740_usa();
// void func_8008B80C_usa();
// void func_8008B890_usa();
// void func_8008B948_usa();
// void func_8008B9A4_usa();
// void func_8008BA08_usa();
// void func_8008BA7C_usa();
// void func_8008BAF0_usa();
// void func_8008BB88_usa();
// void func_8008BC14_usa();
// void func_8008BC54_usa();
// void func_8008BC80_usa();
// void func_8008BCA4_usa();
// void func_8008BCB4_usa();
// void func_8008BD14_usa();
// void func_8008BD3C_usa();
// void func_8008BD68_usa();
// void func_8008BD9C_usa();
// void func_8008BDFC_usa();
// void func_8008BE80_usa();
// void func_8008BE8C_usa();
// void func_8008BE9C_usa();
// void func_8008BEAC_usa();
// void func_8008BEBC_usa();
// void func_8008BEC4_usa();
// void func_8008BED0_usa();
// void func_8008BEE0_usa();
// void func_8008BF4C_usa();
// void func_8008BFCC_usa();
// void func_8008BFDC_usa();
// void func_8008C044_usa();
// void func_8008C0CC_usa();
// void func_8008C170_usa();
// void func_8008C478_usa();
// void func_8008CA00_usa();
// void func_8008CA90_usa();
// void func_8008CC78_usa();
// void func_8008CD98_usa();
// void func_8008CE10_usa();
// void func_8008D028_usa();
// void func_8008D044_usa();
// void func_8008D0FC_usa();
// void func_8008D158_usa();
// void func_8008D1C4_usa();
// void func_8008D288_usa();
// void func_8008D3A4_usa();
// void func_8008D544_usa();
// void func_8008D6E0_usa();
// void func_8008D77C_usa();
// void func_8008D8D4_usa();
// void func_8008DAA4_usa();
// void func_8008DADC_usa();
// void func_8008DB90_usa();
// void func_8008DD3C_usa();
// void func_8008DFAC_usa();
// void func_8008E000_usa();
// void func_8008E518_usa();
// void func_8008E538_usa();
// void func_8008E568_usa();
// void func_8008E588_usa();
// void func_8008E594_usa();
// void func_8008E6C4_usa();
// void func_8008E7C0_usa();
// void func_8008E7D4_usa();
// void func_8008E7F8_usa();
// void func_8008E868_usa();
// void func_8008E8DC_usa();
// void func_8008E8EC_usa();
// void func_8008E91C_usa();
// void func_8008E92C_usa();
// void func_8008E93C_usa();
// void func_8008E94C_usa();
// void func_8008E9A4_usa();
// void func_8008E9B4_usa();
// void func_8008E9C0_usa();
// void func_8008E9D0_usa();
// void func_8008E9DC_usa();
// void func_8008EA98_usa();
// void func_8008EB58_usa();
// void func_8008EB80_usa();
// void func_8008EB8C_usa();
// void func_8008EB9C_usa();
// void func_8008EBA8_usa();
// void func_8008EBBC_usa();
// void func_8008EBD0_usa();
// void func_8008EBD8_usa();
// void func_8008EC20_usa();
// void func_8008EC2C_usa();
// void func_8008EC34_usa();
// void func_8008ECA4_usa();
// void func_8008ECB4_usa();
// void func_8008ED08_usa();
// void func_8008ED5C_usa();
// void func_8008EDB0_usa();
// void func_8008EDC0_usa();
// void func_8008EE98_usa();
// void func_8008EED4_usa();
// void func_8008EEE4_usa();
// void func_8008EF2C_usa();
// void func_8008EFA0_usa();
// void func_8008EFB0_usa();
// void func_8008F00C_usa();
// void func_8008F2DC_usa();
// void func_8008F374_usa();
// void func_8008F4CC_usa();
// void func_8008F76C_usa();
// void func_8008F784_usa();
// void func_8008F7C8_usa();
// void func_8008F80C_usa();
// void func_8008F870_usa();
// void func_8008F9F4_usa();
// void func_8008FACC_usa();
// void func_8008FADC_usa();
// void func_8008FB4C_usa();
// void func_8008FCF0_usa();
// void func_8008FD44_usa();
// void func_8008FDB0_usa();
// void func_8008FDC0_usa();
// void func_8008FE28_usa();
// void func_8008FE58_usa();
// void func_8008FEBC_usa();
// void func_8008FFA0_usa();
// void func_80090108_usa();
// void func_80090290_usa();
// void func_800902E0_usa();
// void func_80090314_usa();
// void func_8009032C_usa();
// void func_8009033C_usa();
// void func_80090368_usa();
// void func_800903E0_usa();
// void func_80090428_usa();
// void func_80090498_usa();
// void func_800904A0_usa();
// void func_800904A8_usa();
// void func_800904D8_usa();
// void func_800904E0_usa();
// void func_800904E8_usa();
// void func_8009061C_usa();
// void func_800906D0_usa();
// void func_800907D4_usa();
// void func_80090838_usa();
// void func_80090988_usa();
// void func_800909F0_usa();
// void func_80090A94_usa();
// void func_80090BF4_usa();
// void func_80090C6C_usa();
// void func_80090D2C_usa();
// void func_80090E9C_usa();

// void func_800AB740_usa();
// void func_800AB9F8_usa();
// void func_800ABBA8_usa();
// void func_800ABD1C_usa();
// void func_800AC0FC_usa();
// void func_800ACA5C_usa();
// void hvqm2DecodeSP1();
// void hvqm2SetupSP1();
// void hvqm2InitSP1();
// void adpcmDecode();
// void func_800AF5F0_usa();
// void func_800AF628_usa();
// void func_800AF724_usa();


#if REGION_PAL
void func_80001A80_eur(UNK_TYPE);
#endif


#endif
