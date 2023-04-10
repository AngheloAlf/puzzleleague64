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


s32 fileFind(File *arg0, char *arg1);
s32 func_8001CA94_usa(char *filename);
bool fileTest(File *arg0);
bool fileGetAddress(File *arg0, RomOffset *arg1);
s32 fileOpen(File *arg0, char *arg1);
s32 fileClose(File *arg0);
s32 fileGet(File *arg0, u8 *arg1, s32 arg2);
s32 fileSeek(File *arg0, s32 mode, s32 offset);
s32 fileSetup(void);
s32 func_8001D304_usa(void);

#endif
