#ifndef FILE_H
#define FILE_H

#include "libultra.h"
#include "unk.h"
#include "libc/stdint.h"
#include "libc/stdbool.h"


typedef struct File {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x09 */ RomOffset unk_08;
    /* 0x0C */ s32 unk_0C;
} File; // size = 0x10


// void fileFind();
s32 func_8001CA94_usa(const char *filename);
bool fileTest(File *arg0);
bool fileGetAddress(File *arg0, RomOffset *arg1);
UNK_RET fileOpen(File *arg0, const char *arg1);
UNK_RET fileClose(File *arg0);
// void func_8001CC7C_usa();
s32 fileSeek(File *arg0, s32 mode, s32 offset);
s32 fileSetup(void);
s32 func_8001D304_usa(void);

#endif
