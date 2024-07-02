#ifndef HVQM2_UTIL_H
#define HVQM2_UTIL_H

#include "ultra64.h"
#include "hvqm2dec.h"
#include "adpcmdec.h"
#include "libc/stdint.h"

#include "timekeeper.h"
#include "file.h"

RomOffset HVQM2Util_GetRecord(HVQM2Record *header, void *body, u16 type, RomOffset src, OSIoMesg *mb, OSMesgQueue *mq);
void HVQM2Util_PrintInfo(HVQM2Header *header);
u32 HVQM2Util_GetNextAudioRecord(void *pcmbuf);
s32 HVQM2Util_Play(File *arg0, u32 arg1, void *heap);
s32 HVQM2Util_800409E4_usa(f32 arg0);
void HVQM2Util_80040A4C_usa(void);
tkAudioProc HVQM2Util_Rewind(void);

extern HVQM2Arg B_801AABA0_usa;
extern OSContPad B_801C7228_usa;

#endif
