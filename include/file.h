#ifndef FILE_H
#define FILE_H

#include "libultra.h"
#include "other_types.h"
#include "libc/stdbool.h"
#include "unk.h"


typedef struct File {
    /* 0x00 */ u32 index;
    /* 0x04 */ s32 fileSize;
    /* 0x08 */ RomOffset romAddress;
    /* 0x0C */ s32 inFileOffset;
} File; // size = 0x10

#define FILE_NULL ((File *)-1)

#define FILE_SEEK_SET 0
#define FILE_SEEK_CUR 1
#define FILE_SEEK_END 2

s32 fileFind(File *file, char *filename);
s32 func_8001CA94_usa(char *filename);
bool fileTest(File *file);
bool fileGetAddress(File *file, RomOffset *dst);
s32 fileOpen(File *file, char *filename);
s32 fileClose(File *file);
s32 fileGet(File *file, void *dst, s32 totalSize);
s32 fileSeek(File *file, s32 mode, s32 offset);
s32 fileSetup(void);
s32 func_8001D304_usa(void);

#endif
