#ifndef MAIN_FUNCTIONS_H
#define MAIN_FUNCTIONS_H

#include "ultra64.h"
#include "unk.h"
#include "unknown_structs.h"
#include "other_types.h"
#include "version.h"
#include "the_game.h"

struct ai_t;

void func_80042400_usa(Gfx **gfxP);
// void func_80042428_usa();
// void func_80042660_usa();
// void func_800427E4_usa();
void func_800428B4_usa(s32 arg0);
void func_80042C24_usa(void **heapP, s32 arg1);
// void func_80042FD4_usa();
// void func_80043110_usa();
// void func_80043380_usa();
// void func_8004360C_usa();
// void func_80043A60_usa();
void func_80043CFC_usa(Gfx **gfxP);
void func_80043D24_usa(s32 arg0);
void func_8004407C_usa(void **heapP, s32 arg1);
// void func_80044280_usa();
// void func_8004441C_usa();
// void func_800445D8_usa();
// void func_800447C4_usa();
void func_800449C4_usa(Gfx **gfxP);
// void func_80044A1C_usa();
// void func_80046470_usa();
void func_80046648_usa(s32 arg0);
void func_80046C2C_usa(void **heapP, s32 arg1);

void Init3DNewRow(struct tetWell *well);
void Init3DCursor(struct cursor_t *cursor, s32 num);
// void func_8005DBD8_usa();
// void func_8005DCA8_usa();
void Init3DIcons(struct tetWell *well);
void Init3DAttackBlocks(struct tetWell *well);
void Init3DExplosion(struct tetWell *well);
// void func_8005DE28_usa();
// void func_8005DE58_usa();
// void func_8005DE94_usa();
// void func_8005E0E8_usa();
// void func_8005E108_usa();
// void func_8005E128_usa();
// void func_8005E2DC_usa();
void Init3DMatrixBlocks(void);
// void func_8005E3F4_usa();
// void func_8005E484_usa();

// void func_8005E510_usa();
// void func_8005E740_usa();
// void func_8005E7A4_usa();
// void Draw3DFrontTetrisWell();
// void Draw3DBackTetrisWell();
// void func_8005F984_usa();
// void func_8005FA6C_usa();
// void func_8005FB10_usa();
// void func_8005FD38_usa();
// void Draw3DTetrisNewBlock();
// void Draw3DCursor();
// void Draw3DIcon();
// void func_80060DB4_usa();
// void func_800615D8_usa();
// void func_800616A4_usa();
// void Draw3DExplosion();
// void func_80062B20_usa();
// void func_80062DF0_usa();
// void func_80063110_usa();
// void func_80063F8C_usa();
// void func_800643A4_usa();
// void func_80064728_usa();
// void func_80064AAC_usa();
// void func_80064E44_usa();
void Draw3DTetris(struct_gInfo_unk_00068 *arg0);
void Compact3DAttackNoWhere(struct tetWell *well);
void Compact3DAttack(struct tetWell *well, s32 count);
void Check3DConnectCombos(struct tetWell *well);
// void func_8006648C_usa();
// void func_800666F0_usa();

void InitAI(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain);
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
void UpdateAI(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain, s32 num);
// void func_80082740_usa();
// void func_800829BC_usa();
// void func_80082CA0_usa();
// void func_80082EE0_usa();

#endif
