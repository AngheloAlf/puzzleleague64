/**
 * Original filename: dlist.c
 */

#include "dlist.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_80054020_usa);
#endif

#if VERSION_USA
void SetGameFade(void) {
    gBox_Level = 0x8C;
    gBlock_Level = 0xFF;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_8005407C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_800540AC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", Draw2DGameFade);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_80054320_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_8005443C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", DoFlashDraw);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_800544D4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_80054500_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_800545E4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_80054624_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", InitTetrisState);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", InitDisplayList);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_800549A4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", InitGameStateVar);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/dlist", func_800552F4_usa);
#endif
