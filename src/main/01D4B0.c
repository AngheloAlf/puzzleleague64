#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/01D4B0", func_8001C8B0_usa);
#endif

typedef struct struct_8001CAD0_usa_sp10 {
    /* 0x0 */ UNK_TYPE1 unk_0[0x4];
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ u32 unk_8;
} struct_8001CAD0_usa_sp10; // size >= 0xC

s32 func_8001C8B0_usa(struct_8001CAD0_usa_sp10 *, const char *); /* extern */

#if VERSION_USA
s32 func_8001CA94_usa(const char *arg0) {
    struct_8001CAD0_usa_sp10 sp10;

    if (func_8001C8B0_usa(&sp10, arg0) != 0) {
        return sp10.unk_4;
    }
    return 0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/01D4B0", func_8001CAC4_usa);
#endif

#if VERSION_USA
#if 0
s32 func_8001CAD0_usa(const char *arg0, u32 *arg1) {
    struct_8001CAD0_usa_sp10 sp10;
    u32 temp;

    if (((s32*)arg0)[0] < 0x255U) {
        *arg1 = ((s32*)arg0)[2] + ((s32*)arg0)[3];
        return 1;
    }
    if (func_8001C8B0_usa(&sp10, arg0) == 0) {
        return 0;
    }

    *arg1 = sp10.unk_8;
    return 1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/01D4B0", func_8001CAD0_usa);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/01D4B0", func_8001CB3C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/01D4B0", func_8001CC74_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/01D4B0", func_8001CC7C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/01D4B0", func_8001D1F8_usa);
#endif

#if VERSION_USA
void func_80001CAC_usa(uintptr_t, UNK_PTR, size_t); /* extern */
extern u32 B_8018ABB0_usa;
extern u32 B_8018E3B8_usa;
extern u32 B_8018E3BC_usa;
extern u32 gnFileCount;
extern u32 D_9BDB40[];

#ifdef NON_MATCHING
/**
 * Original name: fileSetup
 */
// rodata alignment issues
s32 fileSetup(void) {
    gnFileCount = -1U;
    B_8018E3B8_usa = -1U;
    B_8018E3BC_usa = -1U;
    func_80001CAC_usa((uintptr_t)D_9BDB40, &B_8018ABB0_usa, 0x3800);
    B_8018E3B8_usa = -1U;
    gnFileCount = B_8018ABB0_usa;
    if (B_8018ABB0_usa >= 0x256U) {
        osSyncPrintf("fileSetup: Too many files for existing buffersize!");
    }

    return 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/01D4B0", fileSetup);
#endif
#endif

#if VERSION_USA
s32 func_8001D304_usa(void) {
    return 0;
}
#endif
