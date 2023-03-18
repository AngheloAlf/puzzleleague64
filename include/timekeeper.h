#ifndef TIME_KEEPER_H
#define TIME_KEEPER_H

#include "libultra.h"
#include "macros_defines.h"
#include "libc/stdbool.h"

typedef u32 (*tkAudioProc)(void *pcmbuf);
typedef tkAudioProc (*tkRewindProc)(void);

typedef struct TimeKeeperCommand {
    /* 0x0 */ tkRewindProc rewind; /* Pointer to stream rewind function */
    /* 0x4 */ u32 samples_per_sec; /* Audio sampling rate */
} TimeKeeperCommand; // size = 0x8

typedef struct TimeKeeperVideoRing {
    /* 0x00 */ u64 disptime; /* Display time */
    /* 0x08 */ void *vaddr;  /* Frame buffer address */
    /* 0x0C */ u32 *statP;   /* Pointer to frame buffer state flag */
} TimeKeeperVideoRing; // size = 0x10

typedef struct TimeKeeperAudioRing {
    /* 0x0 */ void *buf; /* PCM data buffer */
    /* 0x4 */ u32 len;   /* PCM data length */
} TimeKeeperAudioRing; // size = 0x8

#define TIMEKEEPER_VIDEO_RING_SIZE 2
#define TIMEKEEPER_AUDIO_RING_SIZE 3


u64 TimeKeeper_GetTime(void);
void TimeKeeper_CounterThreadEntry(void *arg);


extern bool gTimerKeeperClockActive;
extern OSTime gTimerKeeperLastTime;
extern u64 gTimerKeeperSamplesPlayed;


extern TimeKeeperVideoRing gTimeKeeperVideoRingBuffer[TIMEKEEPER_VIDEO_RING_SIZE];
extern TimeKeeperAudioRing B_80192F30_usa[TIMEKEEPER_AUDIO_RING_SIZE];

extern OSThread gTimeKeeperCounterThread;
extern STACK(gTimeKeeperCounterStack, 0x2000);

extern OSMesgQueue B_80192EC0_usa;
extern OSMesg B_80192ED8_usa[2];
extern OSMesg B_80192EF8_usa[2];
extern s32 gTimeKeeperVideoRingReadIndex;
extern s32 gTimeKeeperAudioRingCount;
extern s32 B_80192F4C_usa;
extern s32 gTimeKeeperAudioRingRead;
extern u16 B_80192F60_usa;

extern OSThread gTimeKeeperThread;
extern STACK(gTimeKeeperStack, 0x2000);
extern OSMesgQueue B_80192E80_usa;
extern OSMesg B_80192E98_usa[1];
extern OSMesgQueue B_80192EA0_usa;
extern OSMesg B_80192EB8_usa[1];

extern s32 gTimeKeeperVideoRingCount;
extern s32 gTimeKeeperVideoRingIndex;

extern u32 gHVQM2UtilTotalVideoFrames;
extern u32 gHVQM2UtilTotalAudioRecords;
extern romoffset_t gHVQM2UtilVideoStreamP;
extern romoffset_t gHVQM2UtilAudioStreamP;
extern u32 gHVQM2UtilRemainingAudioRecords;
extern u32 gHVQM2UtilRemainingVideoFrames;
extern u64 gHVQM2UtilDispTime;

extern romoffset_t gHVQM2UtilCurrentVideoRomAddress;

#endif
