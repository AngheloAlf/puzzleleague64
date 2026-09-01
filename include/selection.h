#ifndef SELECTION_H
#define SELECTION_H

// TODO: move to some other header when we figure out a better header to place it.

typedef enum Selection {
    /*   -1 */ SELECTION_DUMMY = -1,
    /* 0x64 */ SELECTION_64 = 0x64,
    /* 0x6E */ SELECTION_6E = 0x6E,
    /* 0x6F */ SELECTION_6F,
    /* 0x78 */ SELECTION_78 = 0x78,
    /* 0x82 */ SELECTION_82 = 0x82,
    /* 0x83 */ SELECTION_83,
    /* 0x8C */ SELECTION_8C = 0x8C,
    /* 0x96 */ SELECTION_96 = 0x96,
    /* 0xA0 */ SELECTION_A0 = 0xA0,
    /* 0xA1 */ SELECTION_A1,
    /* 0xAA */ SELECTION_AA = 0xAA,
    /* 0xB4 */ SELECTION_B4 = 0xB4,
    /* 0xBE */ SELECTION_BE = 0xBE,
    /* 0xC8 */ SELECTION_C8 = 0xC8,
} Selection;

#endif
