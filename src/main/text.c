/**
 * Original filename: text.c
 */

#include "text.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "assets_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/text", func_8004C020_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/text", func_8004C1B8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E2C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E38_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E48_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E50_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E58_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E5C_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E64_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E68_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E70_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/text", RO_STR_800C5E78_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/text", func_8004C280_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/text", Draw2DTemplate);
#endif

#if VERSION_USA
#ifdef NON_MATCHING
// regalloc
void Draw2DText(struct_gInfo_unk_00068 *arg0) {
    s8 sp10[6];
    s32 var_a0;
    s32 var_s1;
    s32 var_t0;

    var_s1 = 0;
    Draw2DTemplate();
    bzero(&sp10, 6);

    for (var_a0 = 6; var_a0 < THEGAME_UNK_90C8_LEN; var_a0++) {
        if (arg0->unk_186F8[var_a0].unk_18 < 6) {
            sp10[arg0->unk_186F8[var_a0].unk_18] = true;
        } else if (arg0->unk_186F8[var_a0].unk_18 == -1) {
            var_s1 = var_a0;
            break;
        }
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &numberLUT);

    for (var_t0 = 0; var_t0 < 6; var_t0++) {
        if (!sp10[var_t0]) {
            continue;
        }

        switch (var_t0) {
            case 0x0:
                gSPObjLoadTxtr(glistp++, &numberTexture1);
                break;

            case 0x1:
                gSPObjLoadTxtr(glistp++, &numberTexture2);
                break;

            case 0x2:
                gSPObjLoadTxtr(glistp++, &numberTexture3);
                break;

            case 0x3:
                gSPObjLoadTxtr(glistp++, &numberTexture4);
                break;

            case 0x4:
                gSPObjLoadTxtr(glistp++, &numberTexture5);
                break;

            case 0x5:
                gSPObjLoadTxtr(glistp++, &numberTexture6);
                break;
        }

        for (var_a0 = 6; var_a0 < var_s1; var_a0++) {
            if (arg0->unk_186F8[var_a0].unk_18 == var_t0) {
                gSPObjRectangle(glistp++, &arg0->unk_186F8[var_a0].unk_00);
            }
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/text", Draw2DText);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/text", func_8004DF64_usa);
#endif
