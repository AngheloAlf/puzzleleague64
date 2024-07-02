#include "hvqm2util.h"

#include "ultra64.h"
#include "libmus/libmus.h"
#include "libmus/aud_thread.h"
#include "HVQM2File.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "buffers.h"
#include "cfb_keep.h"
#include "timekeeper.h"
#include "file.h"
#include "tetsound.h"
#include "image.h"
#include "sound.h"
#include "peel.h"
#include "boot_main.h"
#include "pon_thread.h"

#define VIDEO_MSG 666
#define RSP_DONE_MSG 667

typedef struct TimeKeeperCommand {
    /* 0x0 */ tkRewindProc rewind; /* Pointer to stream rewind function */
    /* 0x4 */ u32 samples_per_sec; /* Audio sampling rate */
} TimeKeeperCommand;               // size = 0x8

typedef struct TimeKeeperVideoRing {
    /* 0x00 */ u64 disptime; /* Display time */
    /* 0x08 */ void *vaddr;  /* Frame buffer address */
    /* 0x0C */ u32 *statP;   /* Pointer to frame buffer state flag */
} TimeKeeperVideoRing;       // size = 0x10

typedef struct TimeKeeperAudioRing {
    /* 0x0 */ void *buf; /* PCM data buffer */
    /* 0x4 */ u32 len;   /* PCM data length */
} TimeKeeperAudioRing;   // size = 0x8

#define TIMEKEEPER_VIDEO_RING_SIZE 2
#define TIMEKEEPER_AUDIO_RING_SIZE 3

typedef struct struct_8018EA50_usa {
    /* 0x00000 */ u64 pad1[2];
    /* 0x00010 */ s16 pcmbuf[NUM_PCMBUFs][PCMBUF_SIZE];
    /* 0x11908 */ u64 pad2[1];
    /* 0x11910 */ u8 hvqbuf[HVQ_DATASIZE_MAX];
    /* 0x18E40 */ u64 pad3[2];
    /* 0x18E50 */ u8 adpcmbuf[AUDIO_RECORD_SIZE_MAX];
    /* 0x19A08 */ u64 pad4[1];
    /* 0x19A10 */ u16 hvqwork[(SCREEN_WIDTH / 8) * (SCREEN_HEIGHT / 4) * 4];
    /* 0x1E510 */ u64 pad5[2];
    /* 0x1E520 */ HVQM2Info hvq_spfifo[HVQ_SPFIFO_SIZE];
    /* 0x45620 */ u64 pad6[2];
    /* 0x45630 */ STACK(hvq_yieldbuf, 0xC10);
    /* 0x46240 */ u8 hvqm_headerBuf[sizeof(HVQM2Header) + 0x10];
} struct_8018EA50_usa; // size = 0x46290

static struct_8018EA50_usa *B_8018EA50_usa;

static u32 B_8018EA54_usa;

static u32 gHVQM2UtilCurrentVideoRomAddress;

/**
 * Original name: audioDmaMesgBlock
 */
static OSIoMesg audioDmaMesgBlock;

/**
 * Original name: audioDmaMessageQ
 */
static OSMesgQueue audioDmaMessageQ;

/**
 * Original name: audioDmaMessages
 */
static OSMesg audioDmaMessages[1];

/**
 * Original name: videoDmaMesgBlock
 */
static OSIoMesg videoDmaMesgBlock;

/**
 * Original name: videoDmaMessageQ
 */
static OSMesgQueue videoDmaMessageQ;

/**
 * Original name: videoDmaMessages
 */
static OSMesg videoDmaMessages[1];

/**
 * Original name: spMesgQ
 */
static OSMesgQueue spMesgQ;

/**
 * Original name: spMesgBuf
 */
static OSMesg spMesgBuf[1];

/**
 * Original name: total_frames
 */
static u32 total_frames;

/**
 * Original name: total_audio_records
 */
static u32 total_audio_records;

/**
 * Original name: video_streamP
 */
static u32 video_streamP;

/**
 * Original name: audio_streamP
 */
static u32 audio_streamP;

#if REGION_PAL
static u32 B_8018DBFC_eur;
#endif

/**
 * Original name: audio_remain
 */
static u32 audio_remain;

/**
 * Original name: video_remain
 */
static u32 video_remain;

/**
 * Original name: disptime
 */
static u64 disptime;

/**
 * Original name: adpcm_state
 */
static ADPCMstate adpcm_state;

/**
 * Original name: tkThread
 */
static OSThread tkThread;

/**
 * Original name: tkStack
 */
static STACK(tkStack, 0x2000);

/**
 * Original name: daCounterThread
 */
static OSThread daCounterThread;

/**
 * Original name: daCounterStack
 */
static STACK(daCounterStack, 0x2000);

/**
 * Original name: tkCmdMesgQ
 */
static OSMesgQueue tkCmdMesgQ;

/**
 * Original name: tkCmdMesgBuf
 */
static OSMesg tkCmdMesgBuf[1];

/**
 * Original name: tkResMesgQ
 */
static OSMesgQueue tkResMesgQ;

/**
 * Original name: tkResMesgBuf
 */
static OSMesg tkResMesgBuf[1];

/**
 * Original name: viMessageQ
 */
static OSMesgQueue viMessageQ;

/**
 * Original name: viMessages
 */
static OSMesg viMessages[2];

/**
 * Original name: aiMessageQ
 */
static OSMesgQueue aiMessageQ;

/**
 * Original name: aiMessages
 */
static OSMesg aiMessages[2];

/**
 * Original name: videoRing
 */
static TimeKeeperVideoRing videoRing[TIMEKEEPER_VIDEO_RING_SIZE];

/**
 * Original name: videoRingCount
 */
static s32 videoRingCount;

/**
 * Original name: videoRingWrite
 */
static s32 videoRingWrite;

/**
 * Original name: videoRingRead
 */
static s32 videoRingRead;

/**
 * Original name: audioRing
 */
static TimeKeeperAudioRing audioRing[TIMEKEEPER_AUDIO_RING_SIZE];

/**
 * Original name: audioRingCount
 */
static s32 audioRingCount;

/**
 * Original name: audioRingWrite
 */
static s32 audioRingWrite;

/**
 * Original name: audioRingRead
 */
static s32 audioRingRead;

/**
 * Original name: pcmBufferCount
 */
static s32 pcmBufferCount;

/**
 * Original name: aiFIFOsamples
 */
static u32 aiFIFOsamples;

/**
 * Original name: aiDAsamples
 */
static u32 aiDAsamples;

/**
 * Original name: pcmModBuf
 */
static s16 pcmModBuf[(PCM_ALIGN - 1) * PCM_CHANNELS];

/**
 * Original name: clock_alive
 */
static bool clock_alive;

/**
 * Original name: samples_per_sec
 */
static u32 samples_per_sec;

/**
 * Original name: samples_played
 */
static u64 samples_played;

/**
 * Original name: last_time
 */
static u64 last_time;

/**
 * Macro for loading multi-byte data from buffer holding data from stream
 */
#define load32(from) (*(u32 *)(from))
#define load16(from) (*(u16 *)(from))

INLINE void RomCopy(void *dest, RomOffset src, size_t len, s32 pri, OSIoMesg *mb, OSMesgQueue *mq) {
    osInvalDCache(dest, len);

    while (osPiStartDma(mb, pri, 0, src, dest, len, mq) == -1) {}

    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
}

#if REGION_PAL
typedef struct struct_8003E60C_eur_s0 {
    /* 0x0 */ CARD8 audio_format;
    /* 0x1 */ CARD8 channels;
    /* 0x2 */ CARD8 sample_bits;
    /* 0x3 */ CARD8 audio_quantize_step;
    /* 0x4 */ CARD32 total_audio_records;
    /* 0x8 */ CARD32 samples_per_sec;
    /* 0xC */ CARD32 max_audio_record_size;
} struct_8003E60C_eur_s0; // size = 0x10

INLINE void func_8003E60C_eur(File *arg0, HVQM2Header *header) {
    u8 sp20[sizeof(struct_8003E60C_eur_s0) + 0x10];
    RomOffset sp40;
    struct_8003E60C_eur_s0 *temp_s0;

    if (!fileGetAddress(arg0, &sp40)) {
        B_8018DBFC_eur = gHVQM2UtilCurrentVideoRomAddress + sizeof(HVQM2Header);
        return;
    }

    temp_s0 = OS_DCACHE_ROUNDUP_ADDR(sp20);
    B_8018DBFC_eur = sp40 + sizeof(struct_8003E60C_eur_s0);
    RomCopy(temp_s0, sp40, sizeof(struct_8003E60C_eur_s0), OS_MESG_PRI_NORMAL, &videoDmaMesgBlock, &videoDmaMessageQ);

    header->audio_format = temp_s0->audio_format;
    header->channels = temp_s0->channels;
    header->sample_bits = temp_s0->sample_bits;
    header->audio_quantize_step = temp_s0->audio_quantize_step;
    header->total_audio_records = temp_s0->total_audio_records;
    header->max_audio_record_size = temp_s0->max_audio_record_size;
}
#endif

/**
 * Original name: init_cfb
 */
INLINE void Cfb_Init(void) {
    s32 i;

    for (i = 0; i < CFB_NUM; i++) {
        s32 j;

        for (j = 0; j < SCREEN_WIDTH * SCREEN_HEIGHT; j++) {
            gCfbBuffers[i][j] = 0;
        }

        gCfbStatus[i] = CFB_STATUS_FREE;
    }
}

/**
 * Original name: keep_cfb
 */
INLINE void Cfb_Keep(s32 index) {
    gCfbStatus[index] |= CFB_STATUS_PRECIOUS;
}

/**
 * Original name: release_cfb
 */
INLINE void Cfb_Release(s32 index) {
    if (index >= 0) {
        gCfbStatus[index] &= ~CFB_STATUS_PRECIOUS;
    }
}

/**
 * Original name: release_all_cfb
 */
INLINE void Cfb_ReleaseAll(void) {
    s32 i;

    for (i = 0; i < CFB_NUM; i++) {
        gCfbStatus[i] &= ~CFB_STATUS_PRECIOUS;
    }
}

/**
 * Original name: get_cfb
 */
INLINE s32 Cfb_GetCurrentIndex(void) {
    while (true) {
        s32 i;

        for (i = 0; i < CFB_NUM; i++) {
            if (gCfbStatus[i] == CFB_STATUS_FREE) {
                return i;
            }
        }

        osYieldThread();
    }
}

/**
 * Original name: tkGetTime
 */
INLINE u64 TimeKeeper_GetTime(void) {
    u64 ret;

    if (!clock_alive) {
        return 0;
    }

    ret = OS_CYCLES_TO_USEC(osGetTime() - last_time);

    if (samples_per_sec > 0) {
        ret += samples_played * 1000000LL / samples_per_sec;
    }

    return ret;
}

/**
 * Original name: tkClockDisable
 */
STATIC_INLINE void tkClockDisable(void) {
    clock_alive = false;
}

/**
 * Original name: tkClockStart
 */
STATIC_INLINE void tkClockStart(void) {
    samples_played = 0;
    last_time = osGetTime();
    clock_alive = true;
}

/**
 * Original name: timekeeperProc
 */
void TimeKeeper_ThreadEntry(void *arg UNUSED) {
    TimeKeeperCommand *cmd;
    void *showing_cfb = NULL;      /* Frame buffer being displayed */
    u32 *showing_cfb_statP = NULL; /* Pointer to state flag of the frame buffer being displayed */

    /* Acquire retrace event */
    osCreateMesgQueue(&viMessageQ, viMessages, ARRAY_COUNT(viMessages));
    osViSetEvent(&viMessageQ, NULL, 1);

    /* Acquire AI event*/
    osCreateMesgQueue(&aiMessageQ, aiMessages, ARRAY_COUNT(aiMessages));
    osSetEventMesg(OS_EVENT_AI, &aiMessageQ, (OSMesg)1);

    /**
     * Create and start audio DA counter thread
     */
    osCreateThread(&daCounterThread, THREAD_ID_COUNTER, TimeKeeper_CounterThreadEntry, NULL, STACK_TOP(daCounterStack), THREAD_PRI_COUNTER);
    osStartThread(&daCounterThread);

    osRecvMesg(&tkCmdMesgQ, (OSMesg *)&cmd, OS_MESG_BLOCK);

    while (true) {
        bool video_started;    /* Flag indicating start of video display */
        bool audio_started;    /* Flag indicating start of audio playback */
        bool video_done;       /* Flag indicating end of video decoding */
        bool audio_done;       /* Flag indicating end of audio decoding */
        void *pushed_cfb;      /* Frame buffer reserved for swap */
        u32 *pushed_cfb_statP; /* Pointer to state flag of frame buffer reserved for swap */
        s32 next_pcmbufno;     /* The number of the PCM buffer to use next */
        s32 pcm_mod_samples;   /* The number of PCM samples left over */
        tkAudioProc audioproc;
        OSTime present_vtime;

        /**
         * Wait for movie playback command
         */
        while (cmd == NULL) {
            osSendMesg(&tkResMesgQ, NULL, OS_MESG_BLOCK);
            osRecvMesg(&tkCmdMesgQ, (OSMesg *)&cmd, OS_MESG_BLOCK);
        }

        tkClockDisable();
        audioproc = cmd->rewind();

        samples_per_sec = cmd->samples_per_sec;
        if (samples_per_sec != 0) {
            osAiSetFrequency(samples_per_sec);
        }

        audio_started = false;
        pushed_cfb = NULL;
        pushed_cfb_statP = NULL;
        next_pcmbufno = 0;
        pcm_mod_samples = 0;
        video_started = false;
        video_done = false;
        audio_done = false;
        pcmBufferCount = 0;
        aiDAsamples = 0;
        aiFIFOsamples = 0;
        audioRingWrite = 0;
        audioRingRead = 0;
        audioRingCount = 0;
        videoRingWrite = 0;
        videoRingRead = 0;
        videoRingCount = 0;

        /* Notification that playback preparations are finished */
        osSendMesg(&tkResMesgQ, NULL, OS_MESG_BLOCK);

        /**
         *  Movie playback loop
         *
         *  Loop until the command for playback of a new movie is generated.
         *
         *  In this loop, for every retrace:
         *  (a) play audio without interruption (send PCM data to the AI),
         *  (b) call the audioproc callback and prepare the next PCM data,
         *  (c) Take charge of the frame buffer and swap at the scheduled time.
         *
         *  This loop ends when the below conditions are all met:
         *
         *  1. tkStop() or tkStart() is executed,
         *       ( video_done != 0 )
         *  2. All accepted frame buffers have been swapped,
         *       ( videoRingCount == 0 && pushed_cfb == NULL )
         *  3. Audio records have been input to the end,
         *       ( audio_done != 0 )
         *  4. The final audio record has passed through the AI FIFO and
         *    has begun being passed to the DA.
         *       ( audioRingCount == 0 && aiFIFOsamples == 0 )
         *
         */
        present_vtime = osGetTime();
        while (!video_done || ((videoRingCount > 0) || (pushed_cfb != NULL)) || !audio_done || (audioRingCount > 0) ||
               (aiFIFOsamples > 0)) {
            u64 present_time;
            OSTime last_vtime;

            /**
             * Block until retrace comes
             */
            osRecvMesg(&viMessageQ, NULL, OS_MESG_BLOCK);

            last_vtime = present_vtime;
            present_vtime = osGetTime();
            present_time = TimeKeeper_GetTime() + OS_CYCLES_TO_USEC(present_vtime - last_vtime);

            if (pushed_cfb != NULL) {
                /* The display has switched from showing_cfb to pushed_cfb (it should have) */
                if (!video_started) {
                    /* Display of the first frame has begun (the audio will begin from here) */
                    video_started = true;
                    if (!audio_started && audio_done) {
                        audio_started = true;

                        tkClockStart();
                    }
                }

                /* Release showing_cfb  */
                if ((showing_cfb_statP != NULL) && (showing_cfb != pushed_cfb)) {
                    *showing_cfb_statP &= ~CFB_STATUS_SHOWING;
                }

                /* Update showing_cfb, pushed_cfb */
                showing_cfb = pushed_cfb;
                showing_cfb_statP = pushed_cfb_statP;
                pushed_cfb = NULL;
                pushed_cfb_statP = NULL;
            }

            /**
             * Push the next frame buffer to the VI
             *
             *     Before the start of video display (video_started == 0),
             *   wait until audio data is prepared for playback
             *   (audioRingCount > 0).
             */
            if (video_started || (audioRingCount > 0) || audio_done) {
                while (videoRingCount != 0) {
                    if (videoRing[videoRingRead].disptime > present_time) {
                        break;
                    }

                    if (pushed_cfb_statP != NULL) {
                        *pushed_cfb_statP &= ~CFB_STATUS_SHOWING;
                    }

                    pushed_cfb_statP = videoRing[videoRingRead].statP;
                    pushed_cfb = videoRing[videoRingRead].vaddr;
                    *pushed_cfb_statP |= CFB_STATUS_SHOWING;
                    osViSwapBuffer(pushed_cfb);

                    videoRingRead++;
                    if (videoRingRead == TIMEKEEPER_VIDEO_RING_SIZE) {
                        videoRingRead = 0;
                    }

                    videoRingCount--;
                }
            }

            /**
             * Push the next PCM data to the AI
             *
             *      Before the start of video display (video_started == 0)
             *    wait until the display of the first image frame
             *    has begun (video_started == 1).
             */
            if (video_started) {
                osSetThreadPri(NULL, THREAD_PRI_COUNTER+1);

                while ((audioRingCount > 0) && (aiFIFOsamples == 0)) {
                    void *buffer = audioRing[audioRingRead].buf;
                    size_t length = audioRing[audioRingRead].len;

                    if (osAiGetStatus() & AI_STATUS_FIFO_FULL) {
                        break;
                    }
                    if (osAiSetNextBuffer(buffer, length) == -1) {
                        break;
                    }

                    aiFIFOsamples = length >> PCM_BYTES_PER_SAMPLE_SHIFT;
                    if (!audio_started) {
                        /**
                         * Audio playback has begun.
                         * Here the time count starts to synchronize audio and video
                         */
                        audio_started = true;
                        tkClockStart();
                    }

                    audioRingRead++;
                    if (audioRingRead == TIMEKEEPER_AUDIO_RING_SIZE) {
                        audioRingRead = 0;
                    }
                    audioRingCount--;
                }
                osSetThreadPri(NULL, THREAD_PRI_TIMEKEEPER);
            }

            /**
             * Prepare the next PCM data
             */
            if (!audio_done && (audioRingCount < TIMEKEEPER_AUDIO_RING_SIZE) && (pcmBufferCount < NUM_PCMBUFs)) {
                u32 samples;
                void *buffer;
                s32 length;
                s16 *dp;
                s16 *sp;
                s32 i;

                samples =
                    audioproc((void *)(&B_8018EA50_usa->pcmbuf[next_pcmbufno][pcm_mod_samples << PCM_CHANNELS_SHIFT]));
                if (samples > 0) {
                    pcmBufferCount++;

                    sp = pcmModBuf;
                    i = pcm_mod_samples << PCM_CHANNELS_SHIFT;
                    i--;
                    dp = B_8018EA50_usa->pcmbuf[next_pcmbufno];
                    while (i != -1) {
                        *dp++ = *sp++;
                        i -= 1;
                    }
                    samples += pcm_mod_samples;
                    pcm_mod_samples = samples & (PCM_ALIGN - 1);
                    samples -= pcm_mod_samples;
                    length = samples << PCM_BYTES_PER_SAMPLE_SHIFT;

                    buffer = B_8018EA50_usa->pcmbuf[next_pcmbufno];
                    osWritebackDCache(buffer, length);
                    audioRing[audioRingWrite].buf = buffer;
                    audioRing[audioRingWrite].len = length;
                    audioRingWrite++;
                    if (audioRingWrite == TIMEKEEPER_AUDIO_RING_SIZE) {
                        audioRingWrite = 0;
                    }
                    audioRingCount++;

                    dp = pcmModBuf;
                    i = pcm_mod_samples << PCM_CHANNELS_SHIFT;
                    i--;
                    sp = (void *)((uintptr_t)B_8018EA50_usa->pcmbuf[next_pcmbufno] + length);
                    while (i != -1) {
                        *dp++ = *sp++;
                        i--;
                    }

                    next_pcmbufno++;
                    if (next_pcmbufno >= NUM_PCMBUFs) {
                        next_pcmbufno = 0;
                    }
                } else {
                    audio_done = true;
                }
            }

            if (osRecvMesg(&tkCmdMesgQ, (OSMesg *)&cmd, OS_MESG_NOBLOCK) == 0) {
                /**
                 * tkStop() or tkStart() has been executed
                 *
                 *     Set 1 in video_done and end this playback loop
                 *   after playback of the current movie's video and
                 *   and audio has completely finished.
                 */
                video_done = true;
            }
        }
    }
}

/**
 * Original name: createTimekeeper
 */
INLINE void TimeKeeper_StartThread(void) {
    osCreateMesgQueue(&tkCmdMesgQ, tkCmdMesgBuf, ARRAY_COUNT(tkCmdMesgBuf));
    osCreateMesgQueue(&tkResMesgQ, tkResMesgBuf, ARRAY_COUNT(tkResMesgBuf));
    osCreateThread(&tkThread, THREAD_ID_TIMEKEEPER, TimeKeeper_ThreadEntry, NULL, STACK_TOP(tkStack), THREAD_PRI_TIMEKEEPER);
    osStartThread(&tkThread);
}

/**
 * Original name: tkStart
 */
INLINE void TimeKeeper_PlayVideo(tkRewindProc rewind, u32 samples_per_sec) {
    TimeKeeperCommand cmd;

    cmd.rewind = rewind;
    cmd.samples_per_sec = samples_per_sec;

    osSendMesg(&tkCmdMesgQ, (OSMesg *)&cmd, OS_MESG_BLOCK);
    osRecvMesg(&tkResMesgQ, (OSMesg *)NULL, OS_MESG_BLOCK);
}

/**
 * Original name: tkStop
 */
void TimeKeeper_StopVideo(void) {
    osSendMesg(&tkCmdMesgQ, NULL, OS_MESG_BLOCK);
    osRecvMesg(&tkResMesgQ, NULL, OS_MESG_BLOCK);
}

/**
 * Original name: tkPushVideoframe
 */
INLINE void TimeKeeper_AddVideoFrame(void *vaddr, u32 *statP, u64 disptime) {
    *statP |= CFB_STATUS_SHOWING;

    while (videoRingCount >= TIMEKEEPER_VIDEO_RING_SIZE) {
        osYieldThread();
    }

    videoRing[videoRingWrite].disptime = disptime;
    videoRing[videoRingWrite].vaddr = vaddr;
    videoRing[videoRingWrite].statP = statP;

    videoRingWrite++;
    if (videoRingWrite == TIMEKEEPER_VIDEO_RING_SIZE) {
        videoRingWrite = 0;
    }

    videoRingCount++;
}

/**
 * Original name: get_record
 */
INLINE RomOffset HVQM2Util_GetRecord(HVQM2Record *header, void *body, u16 type, RomOffset src, OSIoMesg *mb,
                                     OSMesgQueue *mq) {
    size_t record_size;
    s32 pri = type == HVQM2_AUDIO ? OS_MESG_PRI_HIGH : OS_MESG_PRI_NORMAL;

    while (true) {
        RomCopy(header, src, sizeof(HVQM2Record), pri, mb, mq);
        src += sizeof(HVQM2Record);

        record_size = header->size;

        if (header->type == type) {
            break;
        }
        src += record_size;
    }

    if (record_size > 0) {
        RomCopy(body, src, record_size, pri, mb, mq);
        src += record_size;
    }

    return src;
}

/**
 * Original name: print_hvqm_info
 */
void HVQM2Util_PrintInfo(HVQM2Header *header) {
    s32 errors;

    osSyncPrintf("\n");
    osSyncPrintf("File version        : %s\n", header->file_version);
    osSyncPrintf("File size           : %d\n", header->file_size);
    osSyncPrintf("Image width         : %d\n", header->width);
    osSyncPrintf("Image height        : %d\n", header->height);
    osSyncPrintf("Compress type       : %s\n", header->v_sampling_rate == 1 ? "4:2:2" : "4:1:1");
    osSyncPrintf("Total frames        : %d\n", header->total_frames);
    osSyncPrintf("Video rate          : %f frame/sec\n", 1000000.0 / header->usec_per_frame);
    osSyncPrintf("Total audio records : %d\n", header->total_audio_records);
    osSyncPrintf("Audio rate          : %d Hz\n", header->samples_per_sec);
    osSyncPrintf("\n");
    osSyncPrintf("Display mode        : %s\n", "16-bit RGBA");
    osSyncPrintf("\n");

    errors = 0;
    if (header->max_frame_size > HVQ_DATASIZE_MAX) {
        errors++;
        osSyncPrintf("ERROR: hvqbuf insufficient\n");
    }
    if (header->max_audio_record_size > AUDIO_RECORD_SIZE_MAX) {
        errors++;
        osSyncPrintf("ERROR: adpcmbuf insufficient\n");
    }
    if (header->max_sp_packets > 20000) {
        errors++;
        osSyncPrintf("ERROR: hvq_spfifo insufficient\n");
    }

    if (errors) {
        while (true) {}
    }
}

/**
 * Original name: next_audio_record
 */
u32 HVQM2Util_GetNextAudioRecord(void *pcmbuf) {
    u8 header_buffer[sizeof(HVQM2Record) + 0x10];
    s16 *var_a0;
    HVQM2Record *record_header;
    HVQM2Audio *audio_headerP;
    u32 samples;
    s32 i;

    if (audio_remain == 0) {
        return 0;
    }

    record_header = OS_DCACHE_ROUNDUP_ADDR(header_buffer);
    audio_streamP = HVQM2Util_GetRecord(record_header, B_8018EA50_usa->adpcmbuf, HVQM2_AUDIO, audio_streamP,
                                        &audioDmaMesgBlock, &audioDmaMessageQ);

    audio_remain--;

    audio_headerP = (void *)B_8018EA50_usa->adpcmbuf;
    samples = load32(&audio_headerP->samples);
    adpcmDecode(&audio_headerP[1], load16(&record_header->format), samples, pcmbuf, 1, &adpcm_state);

    var_a0 = pcmbuf;
    for (i = 0; i < 0x2ED4U; i++) {
        var_a0[i] = (var_a0[i] * B_8018EA54_usa) >> 16;
    }

    return samples;
}

#if VERSION_USA || VERSION_EUR
#define FUNC_80021414_USA_ARG1 0xF2
#define FUNC_80021414_USA_ARG2 0xD0
#elif VERSION_FRA
#define FUNC_80021414_USA_ARG1 0xDE
#define FUNC_80021414_USA_ARG2 0xCE
#elif VERSION_GER
#define FUNC_80021414_USA_ARG1 0xA2
#define FUNC_80021414_USA_ARG2 0xCE
#endif

s32 HVQM2Util_Play(File *arg0, u32 arg1, void *heap) {
    u8 pad[0x20] UNUSED;
    s32 prev_bufno = -1;
    struct_imageLoad_arg0 *sp40;
    RomOffset sp44;
    s32 var_v0;
    u32 temp_s5;

    temp_s5 = arg1 >> 0x10;
    arg1 = arg1 & 0xFFFF;
    if (arg1 & 0x1000) {
        imageLoad(&sp40, "iSkip16.BIF", &heap);
        heap = ALIGN_PTR(heap);
    }

    var_v0 = fileGetAddress(arg0, &sp44);
    if (var_v0 != 0) {
        HVQM2Header *header;
        s32 sp74;
        s32 sp7C;
        s32 sp84;
        s32 sp8C;
        s32 screen_offset;
        s32 h_offset;
        s32 v_offset;
        s32 a1;
        u32 *current_fb;
        s32 i;
        u32 usec_per_frame;

        gHVQM2UtilCurrentVideoRomAddress = sp44;
        osViBlack(true);
        peelStop();
        func_80002D5C_usa();
        func_80002DE8_usa();

        for (i = 0; i < 8; i++) {
            WAIT_FINISH_FRAME();
        }

        osStopThread(&B_8021AAA0_usa.thread);
        osStopThread(&B_8019CFA0_usa);

        for (i = 0; i < 8; i++) {
            WAIT_FINISH_FRAME();
        }

        func_8008B21C_usa();

        gCfbBuffers[0] = (void *)&gFramebuffers[0];
        gCfbBuffers[1] = (void *)&gFramebuffers[1];

        B_8018EA50_usa = (void *)ALIGN8((uintptr_t)heap);
        heap = (void *)((uintptr_t)heap + sizeof(struct_8018EA50_usa));
        if (((uintptr_t)&B_8018EA50_usa->pcmbuf) & 0xF) {
            osSyncPrintf("ERROR: 'pcmbuf' not 16-byte aligned!\n");
        }
        if ((uintptr_t)&B_8018EA50_usa->hvqbuf & 0xF) {
            osSyncPrintf("ERROR: 'hvqbuf' not 16-byte aligned!\n");
        }
        if ((uintptr_t)&B_8018EA50_usa->adpcmbuf & 0xF) {
            osSyncPrintf("ERROR: 'adpcmbuf' not 16-byte aligned!\n");
        }
        if ((uintptr_t)(&B_8018EA50_usa->hvqwork) & 0xF) {
            osSyncPrintf("ERROR: 'hvqwork' not 16-byte aligned!\n");
        }
        if ((uintptr_t)&B_8018EA50_usa->hvq_spfifo & 0xF) {
            osSyncPrintf("ERROR: 'hvq_spfifo' not 16-byte aligned!\n");
        }
        if ((uintptr_t)&B_8018EA50_usa->hvq_yieldbuf & 0xF) {
            osSyncPrintf("ERROR: 'hvq_yieldbuf' not 16-byte aligned!\n");
        }

        header = OS_DCACHE_ROUNDUP_ADDR(&B_8018EA50_usa->hvqm_headerBuf);

        /**
         * Acquire an SP event (if using the RSP version of the decoder)
         */
        osCreateMesgQueue(&spMesgQ, spMesgBuf, ARRAY_COUNT(spMesgBuf));
        osSetEventMesg(OS_EVENT_SP, &spMesgQ, NULL);

        /**
         * Create DMA message queue for the reading in of audio records
         */
        osCreateMesgQueue(&audioDmaMessageQ, audioDmaMessages, ARRAY_COUNT(audioDmaMessages));

        /**
         * Create DMA message queue for the reading in of video records
         */
        osCreateMesgQueue(&videoDmaMessageQ, videoDmaMessages, ARRAY_COUNT(videoDmaMessages));

        TimeKeeper_StartThread();

        hvqm2InitSP1(255);

        hvqtask.t.ucode = (void *)hvqm2sp1TextStart;
        hvqtask.t.ucode_size = (u8 *)hvqm2sp1TextEnd - (u8 *)hvqm2sp1TextStart;
        hvqtask.t.ucode_data = (u64 *)hvqm2sp1DataStart;

        hvqtask.t.type = M_HVQMTASK;
        hvqtask.t.flags = 0;

        hvqtask.t.ucode_boot = (void *)rspbootTextStart;
        hvqtask.t.ucode_boot_size = (u8 *)rspbootTextEnd - (u8 *)rspbootTextStart;
        hvqtask.t.ucode_data_size = HVQM2_UCODE_DATA_SIZE;

        hvqtask.t.data_ptr = (void *)&B_801AABA0_usa;
        hvqtask.t.yield_data_ptr = B_8018EA50_usa->hvq_yieldbuf;
        hvqtask.t.yield_data_size = sizeof(B_8018EA50_usa->hvq_yieldbuf);

        /**
         * Initialize the frame buffer (clear buffer contents and status flag)
         */
        Cfb_Init();
        osViSwapBuffer(gCfbBuffers[1]);

        osViBlack(true);

        RomCopy(header, gHVQM2UtilCurrentVideoRomAddress, sizeof(HVQM2Header), OS_MESG_PRI_NORMAL, &videoDmaMesgBlock,
                &videoDmaMessageQ);

#if REGION_PAL
        func_8003E60C_eur((void *)"intro.svqm", header);
#endif

        total_frames = load32(&header->total_frames);
        usec_per_frame = load32(&header->usec_per_frame);
        total_audio_records = load32(&header->total_audio_records);

        /**
         * Determine video display position
         * (adjust offset so a small image is expanded in the center of the
         *  frame buffer)
         */
        h_offset = (SCREEN_WIDTH - header->width) / 2;
        v_offset = (SCREEN_HEIGHT - header->height) / 2;
        screen_offset = (v_offset * SCREEN_WIDTH) + h_offset;

        /**
         * Setup the HVQM2 image decoder
         */
        hvqm2SetupSP1(header, SCREEN_WIDTH);

        Cfb_ReleaseAll();

        TimeKeeper_PlayVideo(HVQM2Util_Rewind, load32(&header->samples_per_sec));

        sp7C = -1;
        sp84 = 0;
        sp8C = 0;

        if ((temp_s5 != 0) && (temp_s5 < total_frames)) {
            video_remain = temp_s5;
        }

        sp74 = 0;
        while (video_remain > 0) {
            u8 header_buffer[sizeof(HVQM2Record) + 0x10];
            HVQM2Record *record_header;
            u16 frame_format;
            s32 bufno = 0;

            sp74++;
            if (sp74 >= 5) {
                osViBlack(false);
            }
            osContStartReadData(&gSerialMsgQ);

            /**
             * Fetch video record
             */
            record_header = OS_DCACHE_ROUNDUP_ADDR(header_buffer);
            video_streamP = HVQM2Util_GetRecord(record_header, B_8018EA50_usa->hvqbuf, HVQM2_VIDEO, video_streamP,
                                                &videoDmaMesgBlock, &videoDmaMessageQ);

            /**
             * This block is an example of how to force the video to play
             * in sync with the audio.
             *
             * The video and audio is synchronized and played back by the
             * timekeeper thread, but this assumes the video (frame buffer)
             * is always completed and sent to the timekeeper thread before
             * its scheduled display time.
             *
             *   But with mixed I/O the compressed data can be read late and
             * decoding can take more time due to the increased burden on the
             * CPU, leading to a situation where the video can become delayed
             * relative to the audio.
             *
             *   One way to counter this is to skip to the next keyframe
             * whenever the frame to be decoded is late by an amount of
             * time equal to 2 or more frames.
             *
             */
            if (disptime > 0) { /* Excluding the first frame */
                if (TimeKeeper_GetTime() > disptime + usec_per_frame * 2) {
                    Cfb_ReleaseAll();

                    do {
                        disptime += usec_per_frame;

                        video_remain--;
                        if (video_remain == 0) {
                            break;
                        }

                        video_streamP = HVQM2Util_GetRecord(record_header, B_8018EA50_usa->hvqbuf, HVQM2_VIDEO,
                                                            video_streamP, &videoDmaMesgBlock, &videoDmaMessageQ);
                    } while ((load16(&record_header->format) != HVQM2_VIDEO_KEYFRAME) ||
                             (TimeKeeper_GetTime() > disptime));

                    if (video_remain == 0) {
                        break;
                    }
                }
            }

            /**
             * Decode the compressed image data and expand it in the frame buffer
             */
            frame_format = load16(&record_header->format);
            if (frame_format == HVQM2_VIDEO_HOLD) {
                /**
                 * Just like when frame_format != HVQM2_VIDEO_HOLD you
                 * could call hvqm2Decode*() and decode in a new frame
                 * buffer (in this case, just copying from the buffer of
                 * the preceding frame).  But here we make use of the
                 * preceding frame's buffer for the next frame in order
                 * to speed up the process.
                 */
                bufno = prev_bufno;
            } else {
                s32 status;

                /* Get the frame buffer */
                bufno = Cfb_GetCurrentIndex();

                /**
                 * Process first half in the CPU
                 */
                hvqtask.t.flags = 0;
                status = hvqm2DecodeSP1(&B_8018EA50_usa->hvqbuf, frame_format, &gCfbBuffers[bufno][screen_offset],
                                        &gCfbBuffers[prev_bufno][screen_offset], B_8018EA50_usa->hvqwork,
                                        &B_801AABA0_usa, B_8018EA50_usa->hvq_spfifo);

                osWritebackDCacheAll();

                /**
                 * Process last half in the RSP
                 */
                if (status > 0) {
                    osInvalDCache(gCfbBuffers[bufno], SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(u16));
                    osSpTaskStart(&hvqtask);
                    osRecvMesg(&spMesgQ, NULL, OS_MESG_BLOCK);
                }
            }

            if (arg1 & 0x1000) {
                func_80021414_usa(sp40, FUNC_80021414_USA_ARG1, FUNC_80021414_USA_ARG2, gCfbBuffers[bufno]);
            }

            /**
             * This completes decoding of the image
             * This frame is needed for decoding of the next frame, so keep it
             */
            Cfb_Keep(bufno);

            if ((prev_bufno >= 0) && (prev_bufno != bufno)) {
                Cfb_Release(prev_bufno);
            }

            /**
             * Entrust the completed frame buffer to the timekeeper
             */
            TimeKeeper_AddVideoFrame(gCfbBuffers[bufno], &gCfbStatus[bufno], disptime);

            /**
             * Go to the process for next frame
             */
            prev_bufno = bufno;
            disptime += usec_per_frame;
            video_remain--;

            if (osRecvMesg(&B_801AB7F0_usa, NULL, OS_MESG_NOBLOCK) == 0) {
#if REGION_PAL
                osViSetYScale(1.0f);
                osViBlack(true);
#endif

                while (osAfterPreNMI() == -1) {}
                sp8C = -1;
                break;
            }

            osRecvMesg(&gSerialMsgQ, NULL, OS_MESG_BLOCK);
            osContGetReadData(&B_801C7228_usa);

            if (B_801C7228_usa.button == 0) {
                sp7C = 0;
            }

            if ((sp7C == 0) && (B_801C7228_usa.button & arg1)) {
                sp84 = -1;
                break;
            }
        }

        /**
         * At this point the processing of the last frame of the movie is complete.
         */

        /**
         * Dummy so the last frame will continue to be displayed until disptime
         */
        if (prev_bufno >= 0) {
            TimeKeeper_AddVideoFrame(gCfbBuffers[prev_bufno], (void *)&gCfbStatus[prev_bufno], disptime);
        }

        if (sp8C == 0) {
            for (i = 0; i < 16; i++) {
                WAIT_FINISH_FRAME();
            }
        }

        {
            register OSIntMask mask = osSetIntMask(OS_IM_NONE);

            osDestroyThread(&daCounterThread);
            osDestroyThread(&tkThread);
            osSetIntMask(mask);
        }

        if (sp8C == 0) {
            u32 *next_fb = osViGetNextFramebuffer();

            current_fb = (void *)&gFramebuffers[0];
            if ((void *)next_fb == (void *)&gFramebuffers[0]) {
                current_fb = (void *)&gFramebuffers[1];
            }

            FRAMEBUFFERS_COPY(a1, current_fb, next_fb);

            for (i = 0; i < 16; i++) {
                WAIT_FINISH_FRAME();
            }
        }

        osSetEventMesg(OS_EVENT_AI, NULL, NULL);
        osViSetEvent(&B_8021AAA0_usa.interruptQ, (OSMesg)VIDEO_MSG, 1);
        osSetEventMesg(OS_EVENT_SP, &B_8021AAA0_usa.interruptQ, (OSMesg)RSP_DONE_MSG);
        osStartThread(&B_8021AAA0_usa.thread);
        InitGameAudioSystem();

        // infinite loop?
        while (sp8C != 0) {
            FRAMEBUFFERS_BACKWARD_SET(a1, current_fb, 0);
        }

        osViBlack(false);
        var_v0 = sp84;
    }

    return var_v0;
}

s32 HVQM2Util_800409E4_usa(f32 arg0) {
    B_8018EA54_usa = arg0 * 0x10000;

    return -1;
}

void HVQM2Util_80040A4C_usa(void) {
    B_8018EA54_usa = 0xCCCC;
}

/**
 * Original name: daCounterProc
 */
void TimeKeeper_CounterThreadEntry(void *arg UNUSED) {
    while (true) {
        osRecvMesg(&aiMessageQ, NULL, OS_MESG_BLOCK);
        last_time = osGetTime();

        if (aiDAsamples != 0) {
            pcmBufferCount--;
        }
        samples_played += aiDAsamples;
        aiDAsamples = aiFIFOsamples;
        aiFIFOsamples = 0;
    }
}

// rewind
tkAudioProc HVQM2Util_Rewind(void) {
#if VERSION_USA
    video_streamP = audio_streamP = gHVQM2UtilCurrentVideoRomAddress + sizeof(HVQM2Header);
#else
    video_streamP = gHVQM2UtilCurrentVideoRomAddress + sizeof(HVQM2Header);
    audio_streamP = B_8018DBFC_eur;
#endif
    audio_remain = total_audio_records;
    video_remain = total_frames;

    disptime = 0;
    return HVQM2Util_GetNextAudioRecord;
}
