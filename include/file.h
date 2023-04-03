#ifndef FILE_H
#define FILE_H

#include "libultra.h"
#include "unk.h"


typedef struct File {
    /* 0x00 */ UNK_TYPE1 unk_00[0x10]; // arbitrary size
} File; // size = ?


// void func_8001C8B0_usa();
// void func_8001CA94_usa();
// void func_8001CAC4_usa();
s32 fileGetAddress(File *arg0, UNK_TYPE *arg1);
UNK_RET fileOpen(File *arg0, const char *arg1);
UNK_RET fileClose(File *arg0);
// void func_8001CC7C_usa();
// void func_8001D1F8_usa();
s32 fileSetup(void);
// void func_8001D304_usa();

#endif
