#include "001F10.h"

#include "sound.h"

void func_80001310_usa(RomOffset segmentRom, void *dstAddr, size_t segmentSize) {
    DmaRomToRam(segmentRom, dstAddr, segmentSize);
}
