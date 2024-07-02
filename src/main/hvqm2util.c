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

/*
 * Macro for loading multi-byte data from buffer holding data from stream
 */
#define load32(from) (*(u32 *)(from))
#define load16(from) (*(u16 *)(from))

#if VERSION_USA || VERSION_EUR
INLINE void RomCopy(void *dest, RomOffset src, size_t len, s32 pri, OSIoMesg *mb, OSMesgQueue *mq) {
    osInvalDCache(dest, len);

    while (osPiStartDma(mb, pri, 0, src, dest, len, mq) == -1) {}

    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
}
#endif

#if VERSION_EUR
typedef struct struct_8003E60C_eur_s0 {
    /* 0x0 */ u8 unk_0;
    /* 0x1 */ u8 unk_1;
    /* 0x2 */ u8 unk_2;
    /* 0x3 */ u8 unk_3;
    /* 0x4 */ s32 unk_4;
    /* 0x8 */ UNK_TYPE1 unk_8[0x4];
    /* 0xC */ s32 unk_C;
} struct_8003E60C_eur_s0; // size = 0x10

extern u32 B_8018DBFC_eur;

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
    RomCopy(temp_s0, sp40, sizeof(struct_8003E60C_eur_s0), OS_MESG_PRI_NORMAL, &B_8018EA98_usa, &B_8018EAB0_usa);

    header->audio_format = temp_s0->unk_0;
    header->channels = temp_s0->unk_1;
    header->sample_bits = temp_s0->unk_2;
    header->audio_quantize_step = temp_s0->unk_3;
    header->total_audio_records = temp_s0->unk_4;
    header->max_audio_record_size = temp_s0->unk_C;
}
#endif

#if VERSION_USA || VERSION_EUR
// init_cfb
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
#endif

#if VERSION_USA || VERSION_EUR
// keep_cfb
INLINE void Cfb_Keep(s32 index) {
    gCfbStatus[index] |= CFB_STATUS_PRECIOUS;
}
#endif

#if VERSION_USA || VERSION_EUR
// release_cfb
INLINE void Cfb_Release(s32 index) {
    if (index >= 0) {
        gCfbStatus[index] &= ~CFB_STATUS_PRECIOUS;
    }
}
#endif

#if VERSION_USA || VERSION_EUR
// release_all_cfb
INLINE void Cfb_ReleaseAll(void) {
    s32 i;

    for (i = 0; i < CFB_NUM; i++) {
        gCfbStatus[i] &= ~CFB_STATUS_PRECIOUS;
    }
}
#endif

#if VERSION_USA || VERSION_EUR
// get_cfb
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
#endif

#if VERSION_USA || VERSION_EUR
// tkGetTime
INLINE u64 TimeKeeper_GetTime(void) {
    u64 ret;

    if (!gTimerKeeperClockActive) {
        return 0;
    }

    ret = OS_CYCLES_TO_USEC(osGetTime() - gTimerKeeperLastTime);

    if (gTimerKeeperSamplesPerSecond > 0) {
        ret += gTimerKeeperSamplesPlayed * 1000000LL / gTimerKeeperSamplesPerSecond;
    }

    return ret;
}
#endif

#if VERSION_USA || VERSION_EUR
STATIC_INLINE void tkClockDisable(void) {
    gTimerKeeperClockActive = false;
}

STATIC_INLINE void tkClockStart(void) {
    gTimerKeeperSamplesPlayed = 0;
    gTimerKeeperLastTime = osGetTime();
    gTimerKeeperClockActive = true;
}

// timekeeperProc
void TimeKeeper_ThreadEntry(void *arg UNUSED) {
    TimeKeeperCommand *cmd;
    void *sp24 = NULL;
    u32 *sp2C = NULL;

    osCreateMesgQueue(&B_80192EC0_usa, B_80192ED8_usa, ARRAY_COUNT(B_80192ED8_usa));
    osViSetEvent(&B_80192EC0_usa, NULL, 1U);

    osCreateMesgQueue(&B_80192EE0_usa, B_80192EF8_usa, ARRAY_COUNT(B_80192EF8_usa));
    osSetEventMesg(OS_EVENT_AI, &B_80192EE0_usa, (void *)1);

    osCreateThread(&gTimeKeeperCounterThread, 4, TimeKeeper_CounterThreadEntry, NULL,
                   STACK_TOP(gTimeKeeperCounterStack), 0xD);
    osStartThread(&gTimeKeeperCounterThread);

    osRecvMesg(&B_80192E80_usa, (OSMesg *)&cmd, OS_MESG_BLOCK);

    while (true) {
        s32 sp34;
        s32 sp3C;
        bool sp44;
        tkAudioProc sp4C;
        OSTime sp50;
        s32 var_s4;
        u32 *var_s5;
        void *var_s6;
        bool var_s7;
        s32 var_fp;

        while (cmd == NULL) {
            osSendMesg(&B_80192EA0_usa, NULL, OS_MESG_BLOCK);
            osRecvMesg(&B_80192E80_usa, (OSMesg *)&cmd, OS_MESG_BLOCK);
        }

        tkClockDisable();
        sp4C = cmd->rewind();

        gTimerKeeperSamplesPerSecond = cmd->samples_per_sec;
        if (gTimerKeeperSamplesPerSecond != 0) {
            osAiSetFrequency(gTimerKeeperSamplesPerSecond);
        }

        var_s7 = false;
        var_s6 = 0;
        var_s5 = NULL;
        var_s4 = 0;
        var_fp = 0;
        sp34 = 0;
        sp3C = 0;
        sp44 = false;
        B_80192F54_usa = 0;
        B_80192F5C_usa = 0;
        B_80192F58_usa = 0;
        B_80192F4C_usa = 0;
        gTimeKeeperAudioRingRead = 0;
        gTimeKeeperAudioRingCount = 0;
        gTimeKeeperVideoRingIndex = 0;
        gTimeKeeperVideoRingReadIndex = 0;
        gTimeKeeperVideoRingCount = 0;

        osSendMesg(&B_80192EA0_usa, NULL, OS_MESG_BLOCK);

        sp50 = osGetTime();
        while ((sp3C == 0) || ((gTimeKeeperVideoRingCount > 0) || (var_s6 != 0)) || !sp44 ||
               (gTimeKeeperAudioRingCount > 0) || (B_80192F58_usa != 0)) {
            u64 temp_s0;
            OSTime temp_s2;

            osRecvMesg(&B_80192EC0_usa, NULL, 1);

            temp_s2 = sp50;
            sp50 = osGetTime();
            temp_s0 = TimeKeeper_GetTime() + OS_CYCLES_TO_USEC(sp50 - temp_s2);

            if (var_s6 != 0) {
                if (sp34 == 0) {
                    sp34 = 1;
                    if ((var_s7 == false) && sp44) {
                        var_s7 = true;

                        tkClockStart();
                    }
                }

                if ((sp2C != NULL) && (sp24 != var_s6)) {
                    *sp2C &= ~2;
                }

                sp24 = var_s6;
                var_s6 = 0;
                sp2C = var_s5;
                var_s5 = NULL;
            }

            if (sp34 || (gTimeKeeperAudioRingCount > 0) || sp44) {
                while (gTimeKeeperVideoRingCount != 0) {
                    if (gTimeKeeperVideoRingBuffer[gTimeKeeperVideoRingReadIndex].disptime > temp_s0) {
                        break;
                    }

                    if (var_s5 != NULL) {
                        *var_s5 &= ~CFB_STATUS_SHOWING;
                    }

                    var_s5 = gTimeKeeperVideoRingBuffer[gTimeKeeperVideoRingReadIndex].statP;
                    var_s6 = gTimeKeeperVideoRingBuffer[gTimeKeeperVideoRingReadIndex].vaddr;
                    *var_s5 |= CFB_STATUS_SHOWING;
                    osViSwapBuffer(var_s6);

                    gTimeKeeperVideoRingReadIndex++;
                    if (gTimeKeeperVideoRingReadIndex == TIMEKEEPER_VIDEO_RING_SIZE) {
                        gTimeKeeperVideoRingReadIndex = 0;
                    }

                    gTimeKeeperVideoRingCount--;
                }
            }
            if (sp34 != 0) {
                osSetThreadPri(NULL, 0xE);

                while ((gTimeKeeperAudioRingCount > 0) && (B_80192F58_usa == 0)) {
                    void *s0 = B_80192F30_usa[gTimeKeeperAudioRingRead].buf;
                    u32 s1 = B_80192F30_usa[gTimeKeeperAudioRingRead].len;

                    if (osAiGetStatus() & AI_STATUS_FIFO_FULL) {
                        break;
                    }
                    if (osAiSetNextBuffer(s0, s1) == -1) {
                        break;
                    }

                    B_80192F58_usa = s1 >> 2;
                    if (!var_s7) {
                        var_s7 = true;
                        tkClockStart();
                    }

                    gTimeKeeperAudioRingRead++;
                    if (gTimeKeeperAudioRingRead == TIMEKEEPER_AUDIO_RING_SIZE) {
                        gTimeKeeperAudioRingRead = 0;
                    }
                    gTimeKeeperAudioRingCount--;
                }
                osSetThreadPri(NULL, 0xC);
            }

            if (!sp44 && (gTimeKeeperAudioRingCount < TIMEKEEPER_AUDIO_RING_SIZE) && (B_80192F54_usa < 3)) {
                u32 temp_v0_7;
                void *temp_s0_4;
                s32 temp_s2_2;
                u16 *var_a2;
                u16 *var_a1;
                s32 var_a0;

                temp_v0_7 = sp4C((void *)(&B_8018EA50_usa->pcmbuf[var_s4].unk_0000[var_fp << 1]));
                if (temp_v0_7 > 0) {
                    B_80192F54_usa++;

                    var_a1 = &B_80192F60_usa;
                    var_a0 = (var_fp << 1);
                    var_a0--;
                    var_a2 = (void *)(B_8018EA50_usa->pcmbuf[var_s4].unk_0000);
                    while (var_a0 != -1) {
                        *var_a2++ = *var_a1++;
                        var_a0 -= 1;
                    }
                    temp_v0_7 += var_fp;
                    var_fp = temp_v0_7 & 1;
                    temp_v0_7 -= var_fp;
                    temp_s2_2 = temp_v0_7 << 2;

                    temp_s0_4 = (void *)(B_8018EA50_usa->pcmbuf[var_s4].unk_0000);
                    osWritebackDCache(temp_s0_4, temp_s2_2);
                    B_80192F30_usa[B_80192F4C_usa].buf = temp_s0_4;
                    B_80192F30_usa[B_80192F4C_usa].len = temp_s2_2;
                    B_80192F4C_usa++;
                    if (B_80192F4C_usa == 3) {
                        B_80192F4C_usa = 0;
                    }
                    gTimeKeeperAudioRingCount += 1;

                    var_a2 = &B_80192F60_usa;
                    var_a0 = (var_fp << 1);
                    var_a0--;
                    var_a1 = (void *)((uintptr_t)B_8018EA50_usa->pcmbuf[var_s4].unk_0000 + temp_s2_2);
                    while (var_a0 != -1) {
                        *var_a2++ = *var_a1++;
                        var_a0--;
                    }

                    var_s4++;
                    if (var_s4 >= 3) {
                        var_s4 = 0;
                    }
                } else {
                    sp44 = true;
                }
            }

            if (osRecvMesg(&B_80192E80_usa, (OSMesg *)&cmd, OS_MESG_NOBLOCK) == 0) {
                sp3C = true;
            }
        }
    }
}
#endif

#if VERSION_USA || VERSION_EUR
// createTimekeeper
INLINE void TimeKeeper_StartThread(void) {
    osCreateMesgQueue(&B_80192E80_usa, B_80192E98_usa, ARRAY_COUNT(B_80192E98_usa));
    osCreateMesgQueue(&B_80192EA0_usa, B_80192EB8_usa, ARRAY_COUNT(B_80192EB8_usa));
    osCreateThread(&gTimeKeeperThread, 3, TimeKeeper_ThreadEntry, NULL, STACK_TOP(gTimeKeeperStack), 0xC);
    osStartThread(&gTimeKeeperThread);
}
#endif

#if VERSION_USA || VERSION_EUR
// tkStart
INLINE void TimeKeeper_PlayVideo(tkRewindProc rewind, u32 samples_per_sec) {
    TimeKeeperCommand cmd;

    cmd.rewind = rewind;
    cmd.samples_per_sec = samples_per_sec;

    osSendMesg(&B_80192E80_usa, (OSMesg *)&cmd, OS_MESG_BLOCK);
    osRecvMesg(&B_80192EA0_usa, (OSMesg *)NULL, OS_MESG_BLOCK);
}
#endif

#if VERSION_USA || VERSION_EUR
// tkStop
void TimeKeeper_StopVideo(void) {
    osSendMesg(&B_80192E80_usa, NULL, OS_MESG_BLOCK);
    osRecvMesg(&B_80192EA0_usa, NULL, OS_MESG_BLOCK);
}
#endif

#if VERSION_USA || VERSION_EUR
// tkPushVideoframe
INLINE void TimeKeeper_AddVideoFrame(void *vaddr, u32 *statP, u64 disptime) {
    *statP |= CFB_STATUS_SHOWING;

    while (gTimeKeeperVideoRingCount >= TIMEKEEPER_VIDEO_RING_SIZE) {
        osYieldThread();
    }

    gTimeKeeperVideoRingBuffer[gTimeKeeperVideoRingIndex].disptime = disptime;
    gTimeKeeperVideoRingBuffer[gTimeKeeperVideoRingIndex].vaddr = vaddr;
    gTimeKeeperVideoRingBuffer[gTimeKeeperVideoRingIndex].statP = statP;

    gTimeKeeperVideoRingIndex++;
    if (gTimeKeeperVideoRingIndex == TIMEKEEPER_VIDEO_RING_SIZE) {
        gTimeKeeperVideoRingIndex = 0;
    }

    gTimeKeeperVideoRingCount++;
}
#endif

#if VERSION_USA || VERSION_EUR
// get_record
INLINE RomOffset HVQM2Util_GetRecord(HVQM2Record *header, void *body, u16 type, RomOffset src, OSIoMesg *mb,
                                     OSMesgQueue *mq) {
    size_t bodySize;
    s32 pri = type == HVQM2_AUDIO ? OS_MESG_PRI_HIGH : OS_MESG_PRI_NORMAL;

    while (true) {
        RomCopy(header, src, sizeof(HVQM2Record), pri, mb, mq);
        src += sizeof(HVQM2Record);

        bodySize = header->size;

        if (header->type == type) {
            break;
        }
        src += bodySize;
    }

    if (bodySize > 0) {
        RomCopy(body, src, bodySize, pri, mb, mq);
        src += bodySize;
    }

    return src;
}
#endif

#if VERSION_USA || VERSION_EUR
// print_hvqm_info
void HVQM2Util_PrintInfo(HVQM2Header *header) {
    s32 var_s0;

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

    var_s0 = 0;
    if (header->max_frame_size > 0x7530) {
        var_s0 += 1;
        osSyncPrintf("ERROR: hvqbuf insufficient\n");
    }
    if (header->max_audio_record_size > 0xBB8) {
        var_s0 += 1;
        osSyncPrintf("ERROR: adpcmbuf insufficient\n");
    }
    if (header->max_sp_packets > 0x4E20) {
        var_s0 += 1;
        osSyncPrintf("ERROR: hvq_spfifo insufficient\n");
    }

    if (var_s0) {
        while (true) {}
    }
}
#endif

#if VERSION_USA || VERSION_EUR
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

    if (gHVQM2UtilRemainingAudioRecords == 0) {
        return 0;
    }

    record_header = OS_DCACHE_ROUNDUP_ADDR(header_buffer);
    gHVQM2UtilAudioStreamP = HVQM2Util_GetRecord(record_header, B_8018EA50_usa->adpcmbuf, HVQM2_AUDIO,
                                                 gHVQM2UtilAudioStreamP, &B_8018EA60_usa, &B_8018EA78_usa);

    gHVQM2UtilRemainingAudioRecords--;

    audio_headerP = (void *)B_8018EA50_usa->adpcmbuf;
    samples = load32(&audio_headerP->samples);
    adpcmDecode(&audio_headerP[1], load16(&record_header->format), samples, pcmbuf, 1, &adpcm_state);

    var_a0 = pcmbuf;
    for (i = 0; i < 0x2ED4U; i++) {
        var_a0[i] = (var_a0[i] * B_8018EA54_usa) >> 16;
    }

    return samples;
}
#endif

#if VERSION_USA || VERSION_EUR
typedef struct struct_8021AAE0_usa {
    /* 0x00 */ OSMesgQueue unk_00;
    /* 0x18 */ UNK_TYPE1 unk_18[0x58];
    /* 0x70 */ OSThread thread;
} struct_8021AAE0_usa; // size >= 0x220

extern struct_8021AAE0_usa B_8021AAE0_usa;

s32 HVQM2Util_Play(File *arg0, u32 arg1, void *arg2) {
    u8 pad[0x20] UNUSED;
    s32 prev_bufno = -1;
    struct_imageLoad_arg0 *sp40;
    RomOffset sp44;
    s32 var_v0;
    u32 temp_s5;

    temp_s5 = arg1 >> 0x10;
    arg1 = arg1 & 0xFFFF;
    if (arg1 & 0x1000) {
        imageLoad(&sp40, "iSkip16.BIF", &arg2);
        arg2 = ALIGN_PTR(arg2);
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

        osStopThread(&B_8021AAE0_usa.thread);
        osStopThread(&B_8019CFA0_usa);

        for (i = 0; i < 8; i++) {
            WAIT_FINISH_FRAME();
        }

        func_8008B21C_usa();

        gCfbBuffers[0] = (void *)&gFramebuffers[0];
        gCfbBuffers[1] = (void *)&gFramebuffers[1];

        B_8018EA50_usa = (void *)ALIGN8((uintptr_t)arg2);
        // TODO: do something with 0x46290
        arg2 = (void *)((uintptr_t)arg2 + 0x46290);
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

        header = OS_DCACHE_ROUNDUP_ADDR(&B_8018EA50_usa->unk_46240);

        osCreateMesgQueue(&B_8018EAD0_usa, B_8018EAE8_usa, ARRAY_COUNT(B_8018EAE8_usa));
        osSetEventMesg(OS_EVENT_SP, &B_8018EAD0_usa, NULL);
        osCreateMesgQueue(&B_8018EA78_usa, B_8018EA90_usa, ARRAY_COUNT(B_8018EA90_usa));
        osCreateMesgQueue(&B_8018EAB0_usa, B_8018EAC8_usa, ARRAY_COUNT(B_8018EAC8_usa));

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

        RomCopy(header, gHVQM2UtilCurrentVideoRomAddress, sizeof(HVQM2Header), OS_MESG_PRI_NORMAL, &B_8018EA98_usa,
                &B_8018EAB0_usa);

#if VERSION_EUR
        func_8003E60C_eur((void *)"intro.svqm", header);
#endif

        gHVQM2UtilTotalVideoFrames = load32(&header->total_frames);
        usec_per_frame = load32(&header->usec_per_frame);
        gHVQM2UtilTotalAudioRecords = load32(&header->total_audio_records);

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

        if ((temp_s5 != 0) && (temp_s5 < gHVQM2UtilTotalVideoFrames)) {
            gHVQM2UtilRemainingVideoFrames = temp_s5;
        }

        sp74 = 0;
        while (gHVQM2UtilRemainingVideoFrames > 0) {
            u8 sp50[sizeof(HVQM2Record) + 0x10];
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
            record_header = OS_DCACHE_ROUNDUP_ADDR(sp50);
            gHVQM2UtilVideoStreamP = HVQM2Util_GetRecord(record_header, B_8018EA50_usa->hvqbuf, HVQM2_VIDEO,
                                                         gHVQM2UtilVideoStreamP, &B_8018EA98_usa, &B_8018EAB0_usa);

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
            if (gHVQM2UtilDispTime > 0) { /* Excluding the first frame */
                if (TimeKeeper_GetTime() > gHVQM2UtilDispTime + usec_per_frame * 2) {
                    Cfb_ReleaseAll();

                    do {
                        gHVQM2UtilDispTime += usec_per_frame;

                        gHVQM2UtilRemainingVideoFrames--;
                        if (gHVQM2UtilRemainingVideoFrames == 0) {
                            break;
                        }

                        gHVQM2UtilVideoStreamP =
                            HVQM2Util_GetRecord(record_header, B_8018EA50_usa->hvqbuf, HVQM2_VIDEO,
                                                gHVQM2UtilVideoStreamP, &B_8018EA98_usa, &B_8018EAB0_usa);
                    } while ((load16(&record_header->format) != HVQM2_VIDEO_KEYFRAME) ||
                             (TimeKeeper_GetTime() > gHVQM2UtilDispTime));

                    if (gHVQM2UtilRemainingVideoFrames == 0) {
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
                    osRecvMesg(&B_8018EAD0_usa, NULL, OS_MESG_BLOCK);
                }
            }

            if (arg1 & 0x1000) {
                func_80021414_usa(sp40, 0xF2, 0xD0, gCfbBuffers[bufno]);
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
            TimeKeeper_AddVideoFrame(gCfbBuffers[bufno], &gCfbStatus[bufno], gHVQM2UtilDispTime);

            /**
             * Go to the process for next frame
             */
            prev_bufno = bufno;
            gHVQM2UtilDispTime += usec_per_frame;
            gHVQM2UtilRemainingVideoFrames--;

            if (osRecvMesg(&B_801AB7F0_usa, NULL, OS_MESG_NOBLOCK) == 0) {
#if VERSION_EUR
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
            TimeKeeper_AddVideoFrame(gCfbBuffers[prev_bufno], (void *)&gCfbStatus[prev_bufno], gHVQM2UtilDispTime);
        }

        if (sp8C == 0) {
            for (i = 0; i < 16; i++) {
                WAIT_FINISH_FRAME();
            }
        }

        {
            register OSIntMask mask = osSetIntMask(OS_IM_NONE);

            osDestroyThread(&gTimeKeeperCounterThread);
            osDestroyThread(&gTimeKeeperThread);
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
        osViSetEvent(&B_8021AAE0_usa.unk_00, (void *)0x29A, 1U);
        osSetEventMesg(OS_EVENT_SP, &B_8021AAE0_usa.unk_00, (void *)0x29B);
        osStartThread(&B_8021AAE0_usa.thread);
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

#endif

#if VERSION_USA || VERSION_EUR
s32 HVQM2Util_800409E4_usa(f32 arg0) {
    B_8018EA54_usa = arg0 * 0x10000;

    return -1;
}
#endif

#if VERSION_USA || VERSION_EUR
void HVQM2Util_80040A4C_usa(void) {
    B_8018EA54_usa = 0xCCCC;
}
#endif

#if VERSION_USA || VERSION_EUR
// daCounterProc
void TimeKeeper_CounterThreadEntry(void *arg UNUSED) {
    while (true) {
        osRecvMesg(&B_80192EE0_usa, NULL, OS_MESG_BLOCK);
        gTimerKeeperLastTime = osGetTime();

        if (B_80192F5C_usa != 0) {
            B_80192F54_usa--;
        }
        gTimerKeeperSamplesPlayed += B_80192F5C_usa;
        B_80192F5C_usa = B_80192F58_usa;
        B_80192F58_usa = 0;
    }
}
#endif

#if VERSION_USA || VERSION_EUR
// rewind
tkAudioProc HVQM2Util_Rewind(void) {
#if VERSION_USA
    gHVQM2UtilVideoStreamP = gHVQM2UtilAudioStreamP = gHVQM2UtilCurrentVideoRomAddress + sizeof(HVQM2Header);
#else
    gHVQM2UtilVideoStreamP = gHVQM2UtilCurrentVideoRomAddress + sizeof(HVQM2Header);
    gHVQM2UtilAudioStreamP = B_8018DBFC_eur;
#endif
    gHVQM2UtilRemainingAudioRecords = gHVQM2UtilTotalAudioRecords;
    gHVQM2UtilRemainingVideoFrames = gHVQM2UtilTotalVideoFrames;

    gHVQM2UtilDispTime = 0;
    return HVQM2Util_GetNextAudioRecord;
}
#endif
