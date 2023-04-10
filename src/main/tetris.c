/**
 * Original filename: tetris.c
 */

#include "tetris.h"
#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "sound.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_800896C0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_80089778_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_80089828_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_8008997C_usa);
#endif

#if VERSION_USA
s32 DemoCheck(s32 *arg0) {
    func_800545E4_usa(1);

    if ((gTheGame.unk_89C4 != 0) || (gDemo == GDEMO_16)) {
        gDemo = GDEMO_16;
        gTheGame.unk_9C1C = 0;
        gTheGame.unk_9C18 = 0;
        gTheGame.unk_9C14 = 0;
        gGameStatus = gGameStatus >> 0x10;
        FadeOutSong(last_song_handle, 0x3C);
        return -1;
    }

    if ((*arg0 > 1800) && (gMain == GMAIN_387)) {
        gDemo = GDEMO_21;
        gTheGame.unk_9C1C = 0;
        gTheGame.unk_9C18 = 0;
        gTheGame.unk_9C14 = 0;
        gGameStatus = gGameStatus >> 0x10;
        FadeOutSong(last_song_handle, 0x3C);
        return -1;
    }

    *arg0 += 1;
    gDemo = GDEMO_0B;
    return 0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_80089BE0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", InitTetrisWell);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", DoTetris);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/tetris", func_8008ADB4_usa);
#endif
