#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "file.h"
#include "buffers.h"

#if VERSION_USA
void func_8002B5D0_usa(void) {
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002B5D8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002B600_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002B76C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002B7C8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002B85C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002B8B0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002B8E8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002BD30_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002BE98_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002C2C0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002CC18_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002CFC8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002CFE4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/02C1D0", func_8002DA70_usa);
#endif

#if VERSION_USA
// ? fileClose(s8 *);                                  /* extern */
// s32 fileOpen(s8 *, ? *, s32, s32);                  /* extern */
extern s32 geTypePeel;
extern s32 gbFadeAlpha;
extern UNK_PTR gapVtxPeel[];
extern s32 B_8018E598_usa;
extern UNK_PTR gaTile[0x30];
extern UNK_TYPE gnWaveData;
extern s32 B_8018E93C_usa;
extern s32 B_801AB8E4_usa;
extern const char RO_STR_800C42B8_usa[];

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
    B_8018E93C_usa = temp_a0;

    for (i = 0; i < ARRAY_COUNT(gaTile); i++) {
        temp_a0 = (temp_a0 - 0xC80) & ~0xF;
        gaTile[ARRAY_COUNT(gaTile) - 1 - i] = (void *)temp_a0;
    }

    B_801AB8E4_usa = temp_a0;
    if (fileOpen(&sp10, RO_STR_800C42B8_usa) != 0) {
        fileGetAddress(&sp10, &gnWaveData);
        fileClose(&sp10);
    }
}
#endif

#if VERSION_USA
void func_8002DBF0_usa(void) {
}
#endif
