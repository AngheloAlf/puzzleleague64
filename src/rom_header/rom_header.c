#include "ultra64.h"
#include "version.h"

typedef struct RomHeader {
    /* 0x00 */ u32 unk_00; // PI BSB Domain 1 register
    /* 0x04 */ u32 clockrate;
    /* 0x08 */ void (*entrypointAddr)(void);
    /* 0x0C */ u16 unk_0C;
    /* 0x0E */ u8 revision;
    /* 0x0F */ char libultraVersion;

    /* 0x10 */ u32 checksum1;
    /* 0x14 */ u32 checksum2;
    /* 0x18 */ u32 unk_18;
    /* 0x1C */ u32 unk_1C;

    /* 0x20 */ char gameName[20];

    /* 0x34 */ u32 unk_34;
    /* 0x38 */ u32 unk_38;
    /* 0x3C */ char cartridgeId[2];
    /* 0x3E */ char countryCode;
    /* 0x3F */ u8 version;
} RomHeader; // size = 0x40

void entrypoint(void);

RomHeader gRomHeader = {
    // unk_00
    0x80371240,
    // clockrate
    0x0000000F,
    // entrypointAddr
    entrypoint,
    // unk_0C
    0x0000,
    // revision
    20,
    // libultraVersion
    'J',

    // checksum1
    0,
    // checksum2
    0,
    // unk_18
    0x00000000,
    // unk_1C
    0x00000000,

    // gameName
    "PUZZLE LEAGUE N64   ",

    // unk_34
    0x00000000,
    // unk_38
    0x0000004E,
    // cartridgeId
    "PN",
// countryCode
#if VERSION_USA
    'E',
#elif VERSION_EUR
    'P',
#elif VERSION_FRA
    'F',
#elif VERSION_GER
    'D',
#else
    0,
#endif
    // version
    0,
};
