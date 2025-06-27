#include "075630.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "main_variables.h"

#include "fade.h"
#include "the_game.h"

extern s32 D_800B6BB0_usa[];

#define D_800B80B0_usa_WIDTH (8)
#define D_800B80B0_usa_HEIGHT (145)
extern u16 D_800B80B0_usa[];

void func_80074A30_usa(tetWell *well UNUSED) {
    anim_sp = 0;
    func_80074AEC_usa();
}

void func_80074A58_usa(tetWell *well UNUSED, s32 arg1, s32 arg2) {
    if (arg2 < 0) {
        arg2 = MIN(-arg2, 0xC) - 1;
        anim_sp -= D_800B6CC4_usa[arg2];
    } else if (arg1 >= 4) {
        arg1 = MIN(arg1, 0x48) - 4;
        anim_sp -= D_800B6BB0_usa[arg1];
    }

    func_80074AEC_usa();
}

#if VERSION_USA
#ifdef NON_EQUIVALENT
//#if 1
void func_80074AEC_usa(void) {
    s32 sp14;
    s32 sp1C;
    s32 temp_a2;
    s32 temp_fp;
    s32 var_a0_2;
    s32 var_a1;
    s32 var_s0;
    s32 var_s2;
    u16 *temp_v1;
    s32 a0;

    if (anim_sp <= 0) {
        var_s0 = 0;
    } else {
        a0 = gTheGame.unk_9C0C;
        var_s0 = (anim_sp * 0x30) / (a0 * 0x270);
    }

    temp_fp = var_s0 < 0xD;
    sp14 = DoFlashDrawAlways();

    var_s2 = 0;
    for (var_a1 = 0; var_a1 < 0x30; var_a1++) {
        temp_a2 = (D_800B80B0_usa_HEIGHT - 1) - (var_s2 + 1);

        sp1C = var_a1 < 0x18;
        for (var_a0_2 = 0; var_a0_2 < 2; var_a0_2++) {
            temp_v1 = &D_800B80B0_usa[(temp_a2 - var_a0_2) * D_800B80B0_usa_WIDTH];
            if (var_s0 != 0) {
                if (var_a1 < 0xC) {
                    if (((gMain == GMAIN_384) || !temp_fp)) {
                        temp_v1[1] = 0xB94B;
                        temp_v1[2] = 0xFA11;
                        temp_v1[3] = 0xFBDF;
                        temp_v1[4] = 0xFBDF;
                        temp_v1[5] = 0xFA11;
                        temp_v1[6] = 0xB94B;
                    } else if (sp14 != 0) {
                        temp_v1[1] = 0xB94B;
                        temp_v1[2] = 0xFA11;
                        temp_v1[3] = 0xFBDF;
                        temp_v1[4] = 0xFBDF;
                        temp_v1[5] = 0xFA11;
                        temp_v1[6] = 0xB94B;
                    } else {
                        temp_v1[1] = 0x5295;
                        temp_v1[2] = 0x739D;
                        temp_v1[3] = 0xAD6B;
                        temp_v1[4] = 0xAD6B;
                        temp_v1[5] = 0x739D;
                        temp_v1[6] = 0x5295;
                    }
                } else if (sp1C != 0) {
                    temp_v1[1] = 0xBC01;
                    temp_v1[2] = 0xFD41;
                    temp_v1[3] = 0xFE9F;
                    temp_v1[4] = 0xFE9F;
                    temp_v1[5] = 0xFD41;
                    temp_v1[6] = 0xBC01;
                } else if (var_a1 >= 0x24) {
                    temp_v1[1] = 0x15C1;
                    temp_v1[2] = 0x1FC1;
                    temp_v1[3] = 0x8FDF;
                    temp_v1[4] = 0x8FDF;
                    temp_v1[5] = 0x1FC1;
                    temp_v1[6] = 0x15C1;
                } else {
                    temp_v1[1] = 0xBDC1;
                    temp_v1[2] = 0xFFC1;
                    temp_v1[3] = 0xFFDF;
                    temp_v1[4] = 0xFFDF;
                    temp_v1[5] = 0xFFC1;
                    temp_v1[6] = 0xBDC1;
                }
                var_s0 -= var_a0_2 == 1;
            } else {
                temp_v1[1] = 0x5295;
                temp_v1[2] = 0x739D;
                temp_v1[3] = 0xAD6B;
                temp_v1[4] = 0xAD6B;
                temp_v1[5] = 0x739D;
                temp_v1[6] = 0x5295;
            }
        }
        var_s2 += 3;
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/075630", func_80074AEC_usa);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/075630", func_80074AEC_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/075630", func_80074AEC_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/075630", func_80074AEC_usa);
#endif

void func_80074D4C_usa(void) {
    if ((gMain == GMAIN_384) && (gCounter % 3 == 0)) {
        if (anim_sp < (gTheGame.unk_9C0C * 0x270)) {
            anim_sp += gTheGame.unk_9C0C * 0xD;
        }
    }

    gDPPipeSync(glistp++);
    gDPSetTextureLUT(glistp++, G_TT_NONE);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
    gDPSetCombineMode(glistp++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(glistp++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
    gDPLoadTextureBlock(glistp++, D_800B80B0_usa, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800B80B0_usa_WIDTH,
                        D_800B80B0_usa_HEIGHT, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                        G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(glistp++, 0x0060, 0x0114, 0x0080, 0x0358, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);

    if (gTheGame.unk_9C0C == 2) {
        gDPPipeSync(glistp++);
        gDPSetRenderMode(glistp++, G_RM_TEX_EDGE, G_RM_TEX_EDGE2);
    }
}
