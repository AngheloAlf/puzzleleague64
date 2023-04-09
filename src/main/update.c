/**
 * Original filename: update.c
 */

#include "update.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "the_game.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057650_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057754_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057950_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057D1C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057D68_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057E10_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057EB8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80057F84_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_8005806C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058168_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_8005825C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_8005834C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058458_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_8005866C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_800587CC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058934_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058A10_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058AE0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058D68_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80058DF0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80059038_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_800599C4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80059A18_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80059A58_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", func_80059A98_usa);
#endif

#if VERSION_USA
void UpdateBuffer(struct_gInfo *info) {
    if (gTheGame.unk_9C0C == 1) {
        Update2DBuffer(info);
    } else {
        Update3DBuffer(info);
    }
}
#endif

extern s8 D_800B7508_usa[];
extern s8 TetrisBlockFrame[];

#if VERSION_USA
void Update2DBuffer(struct_gInfo *info) {
    struct_gInfo_unk_00068 *new_var5 = &info->unk_00068;
    s8 *sp14;
    s32 var_s6;

    new_var5->unk_10240 = gOverflow;

    sp14 = D_800B7508_usa;
    if (gGameStatus & 0x40) {
        sp14 = TetrisBlockFrame;
    }

    for (var_s6 = 0; var_s6 < gTheGame.unk_9C08; var_s6++) {
        TheGame_unk_0000 *__src = &gTheGame.unk_0000[var_s6];
        TheGame_unk_8860 *temp = &gTheGame.unk_8860[var_s6];
        TheGame_unk_0000_unk_0000 *var_s0;
        s32 var_a1;

        bcopy(temp, &new_var5->unk_172A8[var_s6], sizeof(TheGame_unk_8860));
        bcopy(&__src->unk_0000, &new_var5->unk_10244[var_s6], sizeof(TheGame_unk_0000_unk_0000));
        bzero(&new_var5->unk_10208[var_s6].unk_0, sizeof(struct_gInfo_unk_10208_unk_0));

        var_s0 = &new_var5->unk_10244[var_s6];
        for (var_a1 = 0; var_a1 < ARRAY_COUNT(var_s0->unk_0000); var_a1++) {
            s32 var_a0;

            for (var_a0 = 0; var_a0 < ARRAY_COUNT(var_s0->unk_0000[var_a1].unk_000); var_a0++) {
                TheGame_unk_0000_unk_0000_unk_000_unk_000 *var = &var_s0->unk_0000[var_a1].unk_000[var_a0];

                var->unk_24 = sp14[var->unk_24];
                //! FAKE
                (&(*(&new_var5->unk_10208[var_s6])).unk_0)->unk_0[var->unk_24] = 1;
            }
        }

        bcopy(&__src->unk_3830, &new_var5->unk_17408[var_s6], sizeof(TheGame_unk_0000_unk_3830));
        bcopy(&__src->unk_3EF0, &new_var5->unk_18188[var_s6], sizeof(TheGame_unk_0000_unk_3EF0));

        if (temp->unk_1C != -1) {
            bcopy(&__src->unk_3F80, &new_var5->unk_182A8[var_s6], sizeof(TheGame_unk_0000_unk_3F80));
            bcopy(&__src->unk_3F98, &new_var5->unk_182D8[var_s6], sizeof(TheGame_unk_0000_unk_3F98));
        }

        bcopy(&__src->unk_2AC0, &new_var5->unk_157C8[var_s6], sizeof(TheGame_unk_0000_unk_2AC0));
        bcopy(&__src->unk_2520, &new_var5->unk_14C88[var_s6], sizeof(TheGame_unk_0000_unk_2520));
        bcopy(&__src->unk_2ED0, &new_var5->unk_15FE8[var_s6], sizeof(TheGame_unk_0000_unk_2ED0));
    }

    bcopy(&gTheGame.unk_90C8, &new_var5->unk_186F8, sizeof(TheGame_unk_90C8));
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/update", Update3DBuffer);
#endif
