/**
 * Original filename: puzzle.c
 */

#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "tetris.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088940_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088A48_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088AB4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088C08_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088D34_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088E38_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80088F94_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80089108_usa);
#endif

#if VERSION_USA
#if 0
// ? func_8006B314_usa(TheGame *, ?, s32 *);           /* extern */
// s32 func_80088AB4_usa(TheGame *, TheGame_unk_8860 *, void *, ?); /* extern */

s32 func_8008913C_usa(s32 arg0) {
    s32 var_v0;
    u8 temp_v0;
    void *temp_s0;

    temp_s0 = B_8021BEA4_usa + (((arg0 - 1) * 0x6E) + 0x121);
    if (gTheGame.unk_9C30 == 0) {
        temp_v0 = (B_8021BEA4_usa + arg0)->unk_792;
        gTheGame.unk_9C30 = (s32) temp_v0;
        gTheGame.unk_0000[0].unk_4408[0x20] = (s32) temp_v0;
    }
    func_8006B314_usa(&gTheGame, 0, &gTheGame.unk_9C30);
    var_v0 = -1;
    if (func_80088AB4_usa(&gTheGame, gTheGame.unk_8860, temp_s0, 1) == 0) {
        func_8006B314_usa(&gTheGame, 0);
        var_v0 = 0;
    }
    return var_v0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_8008913C_usa);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_80089200_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", func_8008928C_usa);
#endif

#if VERSION_USA
void InitPuzzleEditor(s32 arg0 UNUSED) {
    InitTetrisWell();
}
#endif

#if VERSION_USA
void DoPuzzleEditor(void) {
    Init2DTetrisBlocksTMEM(&gTheGame, -1);
    UpdateAnimation(&gTheGame, 0, 0);
}
#endif

#if VERSION_USA
#if 0
// ? Update2DBuffer(struct_gInfo *);                   /* extern */
// ? func_80047898_usa(u32);                           /* extern */
// ? func_8004879C_usa(s32, s32);                      /* extern */
// ? func_80049010_usa();                              /* extern */
// ? func_8004EB5C_usa(Gfx *, ?, ?, s32);              /* extern */
// ? func_8006CEA0_usa(Gfx *, TheGame *, ?, u32);      /* extern */
extern ? D_01000820_usa;

void DrawPuzzleEditor(Gfx *gfx) {
    Gfx *temp_v0;
    Gfx *temp_v0_2;
    Gfx *temp_v0_3;
    Gfx *temp_v1;

    Update2DBuffer(*fb);
    temp_v0 = glistp;
    glistp = temp_v0 + 8;
    temp_v0->words.w0 = 0xED000000;
    glistp = temp_v0 + 0x10;
    glistp = temp_v0 + 0x18;
    glistp = temp_v0 + 0x20;
    glistp = temp_v0 + 0x28;
    glistp = temp_v0 + 0x30;
    temp_v0->words.w1 = 0x5003BC;
    temp_v0->unk_8 = 0xE7000000U;
    temp_v0->unk_C = 0;
    temp_v0->unk_10 = 0xBA001402;
    temp_v0->unk_14 = 0x300000;
    temp_v0->unk_18 = 0xF7000000;
    temp_v0->unk_1C = 0x10001;
    temp_v0->unk_20 = 0xF64FC018;
    temp_v0->unk_24 = 0;
    temp_v0->unk_28 = 0xE7000000U;
    temp_v0->unk_2C = 0;
    glistp = temp_v0 + 0x38;
    temp_v0->unk_30 = 0xBA001402;
    temp_v0->unk_34 = 0;
    func_8004879C_usa(0x10001, 0xF64FC018);
    func_8004EB5C_usa(gfx, 1, 3);
    gBox_Level = 0x8C;
    func_80049010_usa();
    temp_v0_2 = glistp;
    glistp = temp_v0_2 + 8;
    glistp = temp_v0_2 + 0x10;
    glistp = temp_v0_2 + 0x18;
    temp_v0_2->unk_14 = 0x8000;
    glistp = temp_v0_2 + 0x20;
    temp_v0_2->unk_1C = &D_01000820_usa;
    glistp = temp_v0_2 + 0x28;
    glistp = temp_v0_2 + 0x30;
    glistp = temp_v0_2 + 0x38;
    glistp = temp_v0_2 + 0x40;
    temp_v0_2->unk_38 = 0xFA000000;
    temp_v0_2->words.w0 = 0xED00007C;
    temp_v0_2->words.w1 = 0x50037C;
    temp_v0_2->unk_8 = 0xE7000000U;
    temp_v0_2->unk_C = 0;
    temp_v0_2->unk_10 = 0xBA000E02;
    temp_v0_2->unk_18 = 0xC1000017;
    temp_v0_2->unk_20 = 0xE7000000U;
    temp_v0_2->unk_24 = 0;
    temp_v0_2->unk_28 = 0xB900031D;
    temp_v0_2->unk_2C = 0x0F0A4000;
    temp_v0_2->unk_30 = 0xFCFFFFFF;
    temp_v0_2->unk_34 = 0xFFFCF279;
    temp_v0_2->unk_3C = -1;
    func_8006CEA0_usa(gfx, &gTheGame, 0, 0x50037CU);
    temp_v1 = glistp;
    glistp = temp_v1 + 8;
    temp_v1->words.w0 = 0xED00001C;
    temp_v1->words.w1 = 0x5003BC;
    func_80047898_usa(0xED00001CU);
    func_8004EB5C_usa(gfx, 4, 4);
    temp_v0_3 = glistp;
    glistp = temp_v0_3 + 8;
    glistp = temp_v0_3 + 0x10;
    glistp = temp_v0_3 + 0x18;
    glistp = temp_v0_3 + 0x20;
    glistp = temp_v0_3 + 0x28;
    temp_v0_3->words.w0 = 0xE7000000;
    temp_v0_3->words.w1 = 0;
    temp_v0_3->unk_8 = 0xBA001402;
    temp_v0_3->unk_C = 0x300000;
    temp_v0_3->unk_10 = 0xF7000000;
    temp_v0_3->unk_14 = 0x63196319;
    temp_v0_3->unk_18 = 0xF647C230;
    temp_v0_3->unk_1C = 0x388068;
    temp_v0_3->unk_20 = 0xE7000000U;
    temp_v0_3->unk_24 = 0;
    glistp = temp_v0_3 + 0x30;
    temp_v0_3->unk_28 = 0xBA001402;
    temp_v0_3->unk_2C = 0;
    func_8004EB5C_usa(gfx, 5, 6, 0x63196319);
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/puzzle", DrawPuzzleEditor);
#endif
#endif
