#ifndef TIME_KEEPER_H
#define TIME_KEEPER_H

#include "ultra64.h"
#include "macros_defines.h"
#include "libc/stdbool.h"
#include "stack.h"
#include "other_types.h"

/*
 * Size of buffer for video records 
 */
#define HVQ_DATASIZE_MAX  30000

/*
 * Size of buffer for audio records
 */
#define AUDIO_RECORD_SIZE_MAX  3000

/*
 * Size of data area for HVQM2 microcode
 */
#define HVQ_SPFIFO_SIZE   20000

/*
 * Audio DA specifications
 */
#define  PCM_CHANNELS        2	/* Number of channels */
#define  PCM_CHANNELS_SHIFT  1	/* log2(PCM_CHANNELS) */
#define  PCM_ALIGN           2	/* Alignment of number of samples to send */
#define  PCM_BYTES_PER_SAMPLE  (2 * PCM_CHANNELS) /* Number of bytes in one sample */
#define  PCM_BYTES_PER_SAMPLE_SHIFT  2	/* log2(PCM_BYTES_PER_SAMPLE) */

/*
 * Audio record definitions
 */
#define  AUDIO_SAMPLE_BITS	4
#define  AUDIO_SAMPLES_MAX	(((AUDIO_RECORD_SIZE_MAX-sizeof(HVQM2Audio))*8/AUDIO_SAMPLE_BITS)+1) /* Maximum number of records per sample */

/*
 * PCM buffer specifications
 */
#define  NUM_PCMBUFs	3	/* Number of PCM buffers (2 or more, at least 3 recommended) */
#define  PCMBUF_SPREAD	((PCM_ALIGN-1)+AUDIO_SAMPLES_MAX) /* Minimum required capacity for PCM buffer = Number of samples carried forward from last time + number of samples newly decoded */
#define  PCMBUF_ALIGNED  ((PCMBUF_SPREAD+(PCM_ALIGN-1))&(~(PCM_ALIGN-1))) /* pcmbuf[i] address is aligned */
#define  PCMBUF_SIZE     (PCMBUF_ALIGNED*PCM_CHANNELS)

typedef u32 (*tkAudioProc)(void *pcmbuf);
typedef tkAudioProc (*tkRewindProc)(void);

u64 TimeKeeper_GetTime(void);
void TimeKeeper_CounterThreadEntry(void *arg);

#endif
