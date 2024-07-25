/**
 * Original filename: peel.c
 */

#include "peel.h"
#include "ultra64.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "file.h"
#include "buffers.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/peel", func_8002C2C0_usa);
#endif

typedef struct struct_gaTile_unk_000 {
    /* 0x00 */ u16 unk_00[0x28];
} struct_gaTile_unk_000; // size = 0x50

typedef struct struct_gaTile {
    /* 0x000 */ struct_gaTile_unk_000 unk_000[UNK_SIZE];
    /* 0x050 */ UNK_TYPE1 unk_050[0xC30];
} struct_gaTile; // size = 0xC80

extern s32 geTypePeel;
extern s32 gbFadeAlpha;
extern UNK_PTR gapVtxPeel[];
extern s32 B_8018E598_usa;
extern struct_gaTile *gaTile[0x30];
extern RomOffset gnWaveData;
extern void *B_8018E93C_usa;
extern s32 B_801AB8E4_usa;

extern s32 B_8018E584_usa;
extern s32 gnAlphaPeel;
extern s32 B_8018E590_usa;
extern u32 B_8018E660_usa[];
extern s32 B_8018E934_usa;
extern f32 B_FLT_8018E920_usa;
extern f32 B_FLT_8018E924_usa;
extern s32 D_800B6444_usa;

#if VERSION_USA
#ifdef NON_EQUIVALENT
//#if 1
void peelTick(void) {
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_t0;
    s32 var_t0_2;
    s32 var_t1;
    s32 var_t1_2;
    s32 var_t3;
    u16 *var_a0;
    u16 temp_t2;
    u32 temp_a0;
    u32 temp_v0_2;
    u32 temp_v0_3;
    u32 temp_v1_3;
    s32 new_var;
    s32 temp = geTypePeel;
    s32 value = -1;

    D_800B6444_usa++;

    if (temp == -1) {
        return;
    } else if (temp == 7) {
        if ((D_800B6444_usa % 4) == 0) {
            if (B_8018E590_usa < 0x10) {
                B_8018E590_usa *= 2;

                for (var_t3 = 0; var_t3 < 0x30; var_t3++) {
                    for (var_t1 = 0; var_t1 < 0x28; var_t1 += B_8018E590_usa) {
                        for (var_t0 = 0; var_t0 < 0x28; var_t0 += B_8018E590_usa) {
                            var_a0 = &gaTile[var_t3]->unk_000[var_t1].unk_00[var_t0];
                            temp_t2 = *var_a0;

                            for (var_a3 = 0; var_a3 < B_8018E590_usa; var_a3++) {
                                if ((var_t1 + var_a3) >= 0x28) {
                                    break;
                                }

                                for (var_a1 = 0; var_a1 < B_8018E590_usa; var_a1++) {
                                    if ((var_t0 + var_a1) < 0x28) {
                                        *var_a0 = temp_t2;
                                    }
                                    var_a0++;
                                }
                                var_a0 += (0x28 - B_8018E590_usa);
                            }
                        }
                    }
                }
            } else {
                gbFadeAlpha = value;
            }
        }
    } else if (temp == 2) {
        B_FLT_8018E920_usa += 8.0;
        if (B_FLT_8018E920_usa >= 64.0) {
            gbFadeAlpha = value;
        }

        B_FLT_8018E924_usa += 4.0;
        if (B_FLT_8018E924_usa >= 360.0) {
            B_FLT_8018E924_usa -= 360.0;
        }

    } else if (temp == 1) {
        if ((D_800B6444_usa % 2) == 0) {
            B_8018E584_usa = 4;
            B_8018E934_usa++;
            if (B_8018E934_usa >= 0x1F) {
                gbFadeAlpha = value;
            } else {
                func_80001CAC_usa(gnWaveData + (B_8018E934_usa * 0x33A), B_8018E93C_usa, 0x33A);
                if (B_8018E934_usa == 7) {
                    gbFadeAlpha = value;
                }
            }
        }
    } else if ((temp != 0xE) && (temp != 7)) {
#define ABS(x) (((x) < 0) ? -(x) : (x))

        for (var_t3 = 0; var_t3 < 0x30; var_t3++) {
            temp_v1_3 = B_8018E660_usa[var_t3];
            var_a1_2 = temp_v1_3 & 0xF;
            if (temp_v1_3 & 8) {
                var_a1_2 = -(temp_v1_3 & 7);
            }
            // var_a1_2 = ((s8)temp_v1_3) / 16;
            // var_a1_2 = ABS((temp_v1_3)) >> 4 & 0xF;

            temp_a0 = temp_v1_3 >> 4;
            var_a3_2 = temp_a0 & 0xF;
            if (temp_a0 & 8) {
                var_a3_2 = -(temp_a0 & 7);
            }
            temp_v0_2 = temp_v1_3 >> 8;
            var_t0_2 = temp_v0_2 & 0xFFF;
            if (temp_v0_2 & 0x800) {
                var_t0_2 |= ~0xFFF;
            }
            temp_v0_3 = temp_v1_3 >> 0x14;
            var_t1_2 = temp_v0_3 & 0xFFF;
            if (temp_v0_3 & 0x800) {
                var_t1_2 |= ~0xFFF;
            }

            // B_8018E660_usa[var_t3] = (temp_v1_3 & 0xFF) | (((var_t0_2 + (var_a1_2 * 2)) & 0xFFF) << 8) | ((var_t1_2 +
            // (var_a3_2 * 2)) << 0x14);
            new_var = var_t1_2 + (var_a3_2 * 2);
            B_8018E660_usa[var_t3] =
                ((temp_v1_3 & 0xFF) | (((var_t0_2 + (var_a1_2 * 2)) & 0xFFF) << 8)) | (new_var << 0x14);
        }
    }

    if (gbFadeAlpha != 0) {
        if (gnAlphaPeel < B_8018E584_usa) {
            geTypePeel = -1;
        } else {
            gnAlphaPeel -= B_8018E584_usa;
            if ((gnAlphaPeel < 0x10) != 0) {
                geTypePeel = -1;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/peel", peelTick);
#endif
#endif

#if VERSION_USA
void peelStop(void) {
    geTypePeel = -1;
    gnAlphaPeel = 0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/peel", func_8002CFE4_usa);
#endif

#if VERSION_USA
s32 peelActive(void) {
    if (gbFadeAlpha != 0) {
        s32 var_a0 = 0;

        if (geTypePeel != -1) {
            if (gnAlphaPeel >= 0x81) {
                var_a0 = -1;
            }
        }
        return var_a0;
    } else if (geTypePeel != -1) {
        return -1;
    }
    return 0;
}
#endif

#if VERSION_USA
#ifdef NON_MATCHING
// rodata alignment issues
void peelSetup(void) {
    File sp10;
    u32 *var_a0;
    uintptr_t temp_a0;
    s32 i;
    u32 value = 0x00010001;

    gbFadeAlpha = 0;
    geTypePeel = -1;

    var_a0 = (void *)&gFramebuffers[0];
    for (i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH / (signed)sizeof(u16); i++) {
        *var_a0++ = value;
    }

    var_a0 = (void *)&gFramebuffers[1];
    for (i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH / (signed)sizeof(u16); i++) {
        *var_a0++ = value;
    }

    temp_a0 = (uintptr_t)&D_803B0500 & ~0xF;
    gapVtxPeel[0] = (void *)temp_a0;

    temp_a0 = (temp_a0 - 0x4B00) & ~0xF;
    gapVtxPeel[1] = (void *)temp_a0;

    temp_a0 = (temp_a0 - 0x33A) & ~0xF;
    B_8018E93C_usa = (void *)temp_a0;

    for (i = 0; i < ARRAY_COUNT(gaTile); i++) {
        temp_a0 = (temp_a0 - 0xC80) & ~0xF;
        gaTile[ARRAY_COUNT(gaTile) - 1 - i] = (void *)temp_a0;
    }

    B_801AB8E4_usa = temp_a0;
    if (fileOpen(&sp10, "RIPPLE.RDF") != 0) {
        fileGetAddress(&sp10, &gnWaveData);
        fileClose(&sp10);
    }
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/peel", peelSetup);
#endif
#endif

#if VERSION_USA
void func_8002DBF0_usa(void) {
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/peel", func_8002C2C0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/peel", peelTick);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/peel", peelStop);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/peel", func_8002CFE4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/peel", peelActive);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/peel", peelSetup);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/peel", func_8002DBF0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/peel", func_8002C2C0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/peel", peelTick);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/peel", peelStop);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/peel", func_8002D06C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/peel", func_8002DAF8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/peel", peelSetup);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/peel", func_8002DC60_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/peel", func_8002C2C0_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/peel", peelTick);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/peel", peelStop);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/peel", func_8002D1C4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/peel", func_8002DC50_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/peel", peelSetup);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/peel", func_8002DDD0_ger);
#endif
