#ifndef DMA_ROM_COPY_H
#define DMA_ROM_COPY_H


#define DmaRomCopy(segmentRom, dstAddr, segmentSize) \
    do { \
        uintptr_t currentVram = (uintptr_t)dstAddr; \
        s32 remainingSize = segmentSize; \
        RomOffset currentRom = segmentRom; \
        \
        while (remainingSize != 0) { \
            size_t blkSize = MIN(remainingSize, 0x4000); \
            OSIoMesg mb; \
            OSMesg sp38; \
        \
            osInvalDCache((void*)currentVram, blkSize); \
            osPiStartDma(&mb, OS_MESG_PRI_NORMAL, OS_READ, currentRom, (void*)currentVram, blkSize, &B_8019D158_usa); \
            osRecvMesg(&B_8019D158_usa, &sp38, OS_MESG_BLOCK); \
            currentRom += blkSize; \
            remainingSize -= blkSize; \
            currentVram += blkSize; \
        } \
    } while (0)


#endif
