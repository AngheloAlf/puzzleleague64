#ifndef ROM_OFFSETS_H
#define ROM_OFFSETS_H

#include "other_types.h"


typedef struct RomOffsetPair {
    /* 0x0 */ RomOffset start;
    /* 0x4 */ RomOffset end;
} RomOffsetPair; // size = 0x8

typedef struct struct_800B55A0_usa {
    /* 0x00 */ RomOffset unk_00;
    /* 0x04 */ RomOffset unk_04;
    /* 0x08 */ RomOffset unk_08;
    /* 0x0C */ RomOffset unk_0C;
    /* 0x10 */ RomOffset unk_10;
} struct_800B55A0_usa; // size = 0x14


extern RomOffsetPair D_800B5330_usa[];
extern RomOffsetPair D_800B5568_usa;
extern struct_800B55A0_usa D_800B5570_usa[];

#endif
