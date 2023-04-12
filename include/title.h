#ifndef TITLE_H
#define TITLE_H

#include "libultra.h"
#include "unk.h"


typedef struct struct_gpData {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x04 */ UNK_TYPE4 unk_04;
    /* 0x08 */ UNK_TYPE4 unk_08;
    /* 0x0C */ UNK_TYPE4 unk_0C;
    /* 0x10 */ UNK_TYPE4 unk_10;
    /* 0x14 */ UNK_TYPE4 unk_14;
} struct_gpData; // size = 0x18


// void func_80005C00_usa();
// void func_80005EC0_usa();
void DrawTitle(void);
// void func_8000628C_usa();
void DoTitle(void);
void InitTitle(void);
void titleSetup(void);


extern struct_gpData *gpData;

#endif
