#ifndef FILE_H
#define FILE_H

#include "libultra.h"
#include "other_types.h"
#include "libc/stdbool.h"
#include "unk.h"


typedef struct File {
    /* 0x00 */ u32 index;
    /* 0x04 */ s32 unk_04; // size?
    /* 0x09 */ RomOffset unk_08;
    /* 0x0C */ s32 unk_0C; // offset?
} File; // size = 0x10

#define FILE_NULL ((File *)-1)

s32 fileFind(File *file, char *filename);
s32 func_8001CA94_usa(char *filename);
bool fileTest(File *arg0);
bool fileGetAddress(File *arg0, RomOffset *arg1);
s32 fileOpen(File *arg0, char *arg1);
s32 fileClose(File *arg0);
s32 fileGet(File *file, void *dst, s32 totalSize);
s32 fileSeek(File *arg0, s32 mode, s32 offset);
s32 fileSetup(void);
s32 func_8001D304_usa(void);

#endif
