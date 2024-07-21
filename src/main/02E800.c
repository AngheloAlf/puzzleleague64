#include "02E800.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02E800", func_8002DC00_usa);
#endif

#if VERSION_USA
s32 func_8002EDF0_usa(s32 arg0) {
    if (arg0 != 0) {
        return -1;
    }

    return 0;
}
#endif

#if VERSION_USA
Lights1 D_800B6450_usa = {
    { { { 0x40, 0x40, 0x40 }, 0, { 0x40, 0x40, 0x40 }, 0 } },
    { { { { 0xE0, 0xE0, 0xE0 }, 0, { 0xE0, 0xE0, 0xE0 }, 0, { 0, -1, 0 }, 0 } } },
};
s32 D_800B6468_usa = 0;
f32 D_FLT_800B646C_usa = 0.0f;
#endif

extern Mtx B_8018E940_usa[2];

typedef struct struct_8002EDFC_usa_arg0 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x4];
    /* 0x4 */ Gfx ***unk_4;
    /* 0x8 */ UNK_TYPE4 unk_8;
} struct_8002EDFC_usa_arg0; // size >= 0xC

#if VERSION_USA
s32 func_8002EDFC_usa(struct_8002EDFC_usa_arg0 *arg0, Gfx **gfxP) {
    Gfx *gfx;

    D_800B6468_usa++;

    D_FLT_800B646C_usa += 1.0;
    if (D_FLT_800B646C_usa >= 360.0) {
        D_FLT_800B646C_usa = D_FLT_800B646C_usa - 360.0;
    }

    if (arg0 == NULL) {
        return 0;
    }

    gfx = *gfxP;

    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
    gSPClearGeometryMode(gfx++, G_ZBUFFER | G_CULL_BOTH);
    gSPSetGeometryMode(gfx++, G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
    gDPSetTextureLOD(gfx++, G_TL_TILE);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetRenderMode(gfx++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gSPSetLights1(gfx++, D_800B6450_usa);

    guRotate(&B_8018E940_usa[D_800B6468_usa % ARRAY_COUNTU(B_8018E940_usa)], D_FLT_800B646C_usa, 0.0f, 1.0f, 0.0f);

    gSPMatrix(gfx++, &B_8018E940_usa[D_800B6468_usa % ARRAY_COUNTU(B_8018E940_usa)],
              G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gfx++, *arg0->unk_4[(D_800B6468_usa & 0xFF) % arg0->unk_8]);
    gSPPopMatrix(gfx++, G_MTX_MODELVIEW);

    *gfxP = gfx;

    return -1;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02E800", func_8002F194_usa);
#endif

#if VERSION_USA
void func_8002F2E0_usa(void) {
}
#endif

#if VERSION_USA
void func_8002F2E8_usa(void) {
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/02E800", func_8002DD20_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/02E800", func_8002EE1C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/02E800", func_8002EE28_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/02E800", func_8002F1C0_eur);
#endif

#if VERSION_EUR
void func_8002F30C_eur(void) {
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/02E800", func_8002F314_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/02E800", func_8002DC70_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/02E800", func_8002ED6C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/02E800", func_8002ED78_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/02E800", func_8002F110_fra);
#endif

#if VERSION_FRA
void func_8002F25C_fra(void) {
}
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/02E800", func_8002F264_fra);
#endif
