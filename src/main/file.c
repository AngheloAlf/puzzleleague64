/**
 * Original name: file.c
 */

#include "file.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

typedef struct struct_gacBuffer_unk_0004 {
    /* 0x00 */ u8 unk_00;
    /* 0x00 */ u8 unk_01;
    /* 0x00 */ u8 unk_02;
    /* 0x00 */ u8 unk_03;
    /* 0x00 */ u8 unk_04;
    /* 0x00 */ u8 unk_05;
    /* 0x00 */ u8 unk_06;
    /* 0x00 */ u8 unk_07;
    /* 0x10 */ char unk_08[0x10];
} struct_gacBuffer_unk_0004; // size = 0x18

typedef struct struct_gacBuffer {
    /* 0x0000 */ s32 unk_0000;
    /* 0x0004 */ struct_gacBuffer_unk_0004 unk_0004[0x255]; // idk
} struct_gacBuffer;                                         // size = 0x3808

extern struct_gacBuffer gacBuffer;
extern s32 B_8018E3B8_usa;
extern s32 B_8018E3BC_usa;
extern u32 gnFileCount;
extern u32 D_9BDB40[];

#if VERSION_USA
#ifdef NON_EQUIVALENT
// maybe equivalent
s32 fileFind(File *arg0, const char *arg1) {
    s8 sp10[0x10];
    s8 *temp = (s8 *)arg1;
    s32 var_a2;
    s32 var_t2;
    s32 var_a2_2;
    struct_gacBuffer_unk_0004 *new_var = gacBuffer.unk_0004;

    for (var_a2 = 0; temp[var_a2] != 0; var_a2++) {
        if ((u8)temp[var_a2] - 'a' < 'z' - 'a' + 1U) {
            sp10[var_a2] = temp[var_a2] - ('a' - 'A');
        } else {
            sp10[var_a2] = temp[var_a2];
        }
    }

    if (gnFileCount != -1) {
        var_a2_2 = (gnFileCount * 0x18) + 4;
    } else {
        var_a2_2 = 0x3800;
    }
    func_80001CAC_usa((u32)D_9BDB40, &gacBuffer, var_a2_2);
    B_8018E3B8_usa = -1;

    for (var_t2 = 0; var_t2 < gnFileCount; var_t2++) {
        s32 var_a2_3;

        for (var_a2_3 = 0; var_a2_3 < var_a2; var_a2_3++) {
            if (new_var[var_t2].unk_08[var_a2_3] != sp10[var_a2_3]) {
                break;
            }
        }

        if (var_a2_3 == var_a2) {
            u32 temp;

            temp = ((gacBuffer.unk_0004[var_t2].unk_04 << 0x18) | (gacBuffer.unk_0004[var_t2].unk_05 << 0x10) |
                    (gacBuffer.unk_0004[var_t2].unk_06 << 8) | gacBuffer.unk_0004[var_t2].unk_07);
            arg0->unk_00 = var_t2;
            arg0->unk_04 = (gacBuffer.unk_0004[var_t2].unk_00 << 0x18) | (gacBuffer.unk_0004[var_t2].unk_01 << 0x10) |
                           (gacBuffer.unk_0004[var_t2].unk_02 << 8) | gacBuffer.unk_0004[var_t2].unk_03;
            arg0->unk_08 = temp;
            arg0->unk_08 += (RomOffset)D_9BDB40;
            return arg0->unk_04;
        }
    }
    return 0;
}
#else
s32 fileFind(File *arg0, const char *arg1);
INCLUDE_ASM("asm/usa/nonmatchings/main/file", fileFind);
#endif
#endif

#if VERSION_USA
s32 func_8001CA94_usa(const char *filename) {
    File sp10;

    if (fileFind(&sp10, filename) != 0) {
        return sp10.unk_04;
    }
    return 0;
}
#endif

#if VERSION_USA
INLINE bool fileTest(File *arg0) {
    return arg0->unk_00 < 0x255;
}
#endif

#if VERSION_USA
bool fileGetAddress(File *arg0, RomOffset *arg1) {
    File sp10;

    if (fileTest(arg0)) {
        *arg1 = arg0->unk_08 + arg0->unk_0C;
        return true;
    }
    if (fileFind(&sp10, (void *)arg0) != 0) {
        *arg1 = sp10.unk_08;
        return true;
    }
    return false;
}
#endif

#if VERSION_USA
#ifdef NON_MATCHING
// regalloc
s32 fileOpen(File *arg0, const char *arg1) {
    s32 temp_a0;
    s32 var_a2;

    if (fileFind(arg0, arg1) != 0) {
        //! @bug dereferences before checking if pointer is -1
        temp_a0 = arg0->unk_04;
        arg0->unk_0C = 0;
        if (arg0 == (File *)-1) {
            if (gnFileCount != -1) {
                var_a2 = (gnFileCount * 0x18) + 4;
            } else {
                var_a2 = 0x3800;
            }
            func_80001CAC_usa((RomOffset)D_9BDB40, &gacBuffer, var_a2);
            B_8018E3B8_usa = -1;
        } else if ((B_8018E3B8_usa != arg0->unk_00) || ((B_8018E3BC_usa > 0)) ||
                   (MIN(temp_a0, 0x3800) <= (temp_a0 - B_8018E3BC_usa))) {
            var_a2 = MIN(arg0->unk_04 - (arg0->unk_0C & ~1), 0x3800);
            B_8018E3B8_usa = arg0->unk_00;
            B_8018E3BC_usa = arg0->unk_0C & ~1;
            func_80001CAC_usa(arg0->unk_08 + B_8018E3BC_usa, &gacBuffer, (var_a2 + 1) & ~1);
        }
        return arg0->unk_00 + 1;
    }

    arg0->unk_00 = -1;
    return 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/file", fileOpen);
#endif
#endif

#if VERSION_USA
s32 fileClose(File *arg0 UNUSED) {
    return 0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/file", func_8001CC7C_usa);
#endif

#if VERSION_USA
s32 fileSeek(File *arg0, s32 mode, s32 offset) {
    char new_var = 1;

    if (!fileTest(arg0)) {
        return 0;
    }

    switch (mode) {
        case 0: // SEEK_SET
            break;

        case 1: // SEEK_CUR
            offset += arg0->unk_0C;
            break;

        case 2: // SEEK_END
            offset = arg0->unk_04 - (offset + new_var);
            break;
    }

    if (offset < 0) {
        arg0->unk_0C = 0;
    } else if (offset >= arg0->unk_04) {
        arg0->unk_0C = arg0->unk_04 - 1;
    } else {
        arg0->unk_0C = offset;
    }

    return arg0->unk_0C;
}
#endif

#if VERSION_USA
#ifdef NON_MATCHING
/**
 * Original name: fileSetup
 */
// rodata alignment issues
s32 fileSetup(void) {
    gnFileCount = -1U;
    B_8018E3B8_usa = -1U;
    B_8018E3BC_usa = -1U;
    func_80001CAC_usa((uintptr_t)D_9BDB40, &gacBuffer, 0x3800);
    B_8018E3B8_usa = -1U;
    gnFileCount = gacBuffer.unk_0000;
    if (gnFileCount >= 0x256U) {
        osSyncPrintf("fileSetup: Too many files for existing buffersize!");
    }

    return 0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/file", fileSetup);
#endif
#endif

#if VERSION_USA
s32 func_8001D304_usa(void) {
    return 0;
}
#endif
