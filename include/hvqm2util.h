#ifndef HVQM2_UTIL_H
#define HVQM2_UTIL_H

#include "libultra.h"
#include "timekeeper.h"
#include "libhvqm.h"
#include "libc/stdint.h"
#include "file.h"

RomOffset HVQM2Util_GetRecord(HVQM2Record *header, void *body, u16 type, RomOffset src, OSIoMesg *mb, OSMesgQueue *mq);
void HVQM2Util_PrintInfo(HVQM2Header *header);
u32 HVQM2Util_GetNextAudioRecord(void *arg0);
s32 HVQM2Util_Play(File *arg0, u32 arg1, void *arg2);
s32 HVQM2Util_800409E4_usa(f32 arg0);
void HVQM2Util_80040A4C_usa(void);
tkAudioProc HVQM2Util_Rewind(void);

typedef struct struct_8018EA50_usa_unk_00010 {
    /* 0x0000 */ s16 unk_0000[UNK_SIZE];
    /* 0x0002 */ UNK_TYPE1 unk_0002[0x5DA6];
} struct_8018EA50_usa_unk_00010; // size = 0x5DA8

typedef struct struct_8018EA50_usa {
    ///* 0x00000 */ UNK_TYPE1 unk_00000[0x18E50];
    /* 0x00000 */ UNK_TYPE1 unk_00000[0x10];
    /* 0x00010 */ struct_8018EA50_usa_unk_00010 pcmbuf[UNK_SIZE];
    /* 0x05DB8 */ UNK_TYPE1 unk_05DB8[0xBB58];
    /* 0x11910 */ UNK_TYPE1 hvqbuf[UNK_SIZE];
    /* 0x11911 */ UNK_TYPE1 unk_11911[0x753F];
    /* 0x18E50 */ u8 adpcmbuf[UNK_SIZE];
    /* 0x18E51 */ UNK_TYPE1 unk_18E51[0xBBF];
    /* 0x19A10 */ u16 hvqwork[UNK_SIZE];
    /* 0x19A12 */ UNK_TYPE1 unk_19A11[0x4B0E];
    /* 0x1E520 */ HVQM2Info hvq_spfifo[UNK_SIZE];
    /* 0x1E528 */ UNK_TYPE1 unk_1E528[0x27108];
    /* 0x45630 */ STACK(hvq_yieldbuf, 0xC10);
    /* 0x46240 */ UNK_TYPE1 unk_46240[UNK_SIZE];
    /* 0x46241 */ UNK_TYPE1 unk_46241[0x4F];
} struct_8018EA50_usa; // size = 0x46290?

extern struct_8018EA50_usa *B_8018EA50_usa;

extern ADPCMstate B_8018EB10_usa;

extern OSMesg B_8018EA90_usa[1];
extern OSIoMesg B_8018EA98_usa;
extern OSMesgQueue B_8018EAB0_usa;
extern OSMesg B_8018EAC8_usa[1];
extern OSMesgQueue B_8018EAD0_usa;
extern OSMesg B_8018EAE8_usa[1];
extern OSThread B_8019CFA0_usa;
extern HVQM2Arg B_801AABA0_usa;
extern OSContPad B_801C7228_usa;

#endif
