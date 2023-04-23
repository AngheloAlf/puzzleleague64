#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H

#include "libultra.h"
#include "unk.h"
#include "unknown_structs.h"
#include "other_types.h"
#include "version.h"
#include "the_game.h"


void func_80000450_usa(void);
// void bootproc();
void Idle_ThreadEntry(void *arg);
void func_80000630_usa(void);
void pon_main(void *arg);
s32 doMenuLoop(s32 arg0);
s32 doGameLoop(s32 arg0);

void func_80001310_usa(RomOffset segmentRom, void * dstAddr, size_t segmentSize);

// void func_800019C0_usa();

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
void DrawMT(Gfx *);
void DoMimic();
void InitMimic(void);

// void func_80088940_usa();
// void func_80088A48_usa();
// void func_80088AB4_usa();
// void func_80088C08_usa();
// void func_80088D34_usa();
// void func_80088E38_usa();
// void func_80088F94_usa();
// void func_80089108_usa();
s32 func_8008913C_usa(s32 arg0);
// void func_80089200_usa();
// void func_8008928C_usa();
void func_80089318_usa(s32 arg0);
void DoPuzzleEditor(void);
// void func_8008937C_usa();

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
