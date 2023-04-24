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

#define MAGIC_NUMBER 6

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
void Draw2DTemplate(struct_gInfo_unk_00068 *arg0) {
    s32 var_t1 = -1;
    s32 i;

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &otherLUT);

    for (i = 0; i < MAGIC_NUMBER; i++) {
        s32 var_v1 = arg0->unk_186F8[i].unk_18;


        if (var_v1 == -1) {
            continue;
        }

        if (var_v1 >= 0xB) {
            var_v1 = 0x19;
        }

        if (var_v1 != var_t1) {
            var_t1 = var_v1;

            switch (var_v1) {
                case 0x0:
                    gSPObjLoadTxtr(glistp++, &D_0101F240_usa);
                    break;

                case 0x1:
                    gSPObjLoadTxtr(glistp++, &D_0101F258_usa);
                    break;

                case 0x2:
                    gSPObjLoadTxtr(glistp++, &D_0101F270_usa);
                    break;

                case 0x3:
                    gSPObjLoadTxtr(glistp++, &D_0101F288_usa);
                    break;

                case 0x4:
                    gSPObjLoadTxtr(glistp++, &D_0101F2A0_usa);
                    break;

                case 0x5:
                    gSPObjLoadTxtr(glistp++, &D_0101F2D0_usa);
                    break;

                case 0x6:
                    gSPObjLoadTxtr(glistp++, &D_0101F2E8_usa);
                    break;

                case 0x7:
                    gSPObjLoadTxtr(glistp++, &D_0101F348_usa);
                    break;

                case 0x8:
                    gSPObjLoadTxtr(glistp++, &D_0101F360_usa);
                    break;

                default:
                    gSPObjLoadTxtr(glistp++, &D_0101F2B8_usa);
                    break;
            }
        }

        gSPObjRectangle(glistp++, &arg0->unk_186F8[i].unk_00);
    }
}
#endif

#if VERSION_USA
void Draw2DText(struct_gInfo_unk_00068 *arg0) {
    s8 sp10[MAGIC_NUMBER];
    s32 i;
    s32 var_s1 = 0;
    s32 j;

    Draw2DTemplate(arg0);
    bzero(sp10, MAGIC_NUMBER * sizeof(s8));

    for (i = MAGIC_NUMBER; i < THEGAME_UNK_90C8_LEN; i++) {
        if (arg0->unk_186F8[i].unk_18 < MAGIC_NUMBER) {
            sp10[arg0->unk_186F8[i].unk_18] = true;
        } else if (arg0->unk_186F8[i].unk_18 == -1) {
            var_s1 = i;
            break;
        }
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_RGBA16);
    gSPObjLoadTxtr(glistp++, &numberLUT);

    for (j = 0; j < MAGIC_NUMBER; j++) {
        if (!sp10[j]) {
            continue;
        }

        switch (j) {
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

        for (i = MAGIC_NUMBER; i < var_s1; i++) {
            if (arg0->unk_186F8[i].unk_18 == j) {
                gSPObjRectangle(glistp++, &arg0->unk_186F8[i].unk_00);
            }
        }
    }
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/text", func_8004DF64_usa);
#endif
