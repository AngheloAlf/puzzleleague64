#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/002710", func_80001B10_usa);
#endif

#if VERSION_USA
void func_80001CAC_usa(RomOffset segmentRom, void *dstAddr, size_t segmentSize) {
    s32 remainingSize;
    u32 currentRom;
    void *currentVram;

    currentVram = dstAddr;
    remainingSize = segmentSize;
    currentRom = segmentRom;
    while (remainingSize != 0) {
        size_t blkSize = MIN(remainingSize, 0x4000);
        OSIoMesg mb;
        void *sp38;

        osInvalDCache(currentVram, blkSize);
        osPiStartDma(&mb, OS_MESG_PRI_NORMAL, OS_READ, currentRom, currentVram, blkSize, &B_8019D158_usa);
        osRecvMesg(&B_8019D158_usa, &sp38, OS_MESG_BLOCK);
        currentRom += blkSize;
        remainingSize -= blkSize;
        currentVram += blkSize;
    }
}
#endif
