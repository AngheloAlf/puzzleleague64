#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "libhvqm.h"
#include "buffers.h"
#include "cfb_keep.h"
#include "timekeeper.h"
#include "hvqm2util.h"
#include "file.h"

#if VERSION_USA || VERSION_EUR
INLINE void RomCopy(void *dest, romoffset_t src, size_t len, s32 pri, OSIoMesg *mb, OSMesgQueue *mq) {
    osInvalDCache(dest, len);

    while (osPiStartDma(mb, pri, 0, src, dest, len, mq) == -1) {}

    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
}
#endif

#if VERSION_EUR
extern OSIoMesg B_8018DB98_eur;

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
extern u32 B_8018DB58_eur;

INLINE void func_8003E60C_eur(File *arg0, HVQM2Header *arg1) {
    u8 sp20[sizeof(struct_8003E60C_eur_s0) + 0x10];
    UNK_TYPE sp40;
    struct_8003E60C_eur_s0 *temp_s0;

    if (fileGetAddress(arg0, &sp40) == 0) {
        B_8018DBFC_eur = B_8018DB58_eur + 0x3C;
        return;
    }

    temp_s0 = OS_DCACHE_ROUNDUP_ADDR(sp20);
    B_8018DBFC_eur = sp40 + sizeof(struct_8003E60C_eur_s0);
    RomCopy(temp_s0, sp40, sizeof(struct_8003E60C_eur_s0), OS_MESG_PRI_NORMAL, &B_8018DB98_eur, &B_8018EAB0_usa);

    arg1->audio_format = temp_s0->unk_0;
    arg1->channels = temp_s0->unk_1;
    arg1->sample_bits = temp_s0->unk_2;
    arg1->audio_quantize_step = temp_s0->unk_3;
    arg1->total_audio_records = temp_s0->unk_4;
    arg1->max_audio_record_size = temp_s0->unk_C;
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
INLINE romoffset_t HVQM2Util_GetRecord(HVQM2Record *header, void *body, u16 type, romoffset_t src, OSIoMesg *mb,
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
    osSyncPrintf("File version        : %s\n", header);
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
// next_audio_record
u32 HVQM2Util_GetNextAudioRecord(void *arg0) {
    u8 sp20[sizeof(HVQM2Record) + 0x10];
    s16 *var_a0;
    HVQM2Record *temp_s2;
    HVQM2Audio *temp_a0;
    u32 temp_s0;
    u32 i;

    if (gHVQM2UtilRemainingAudioRecords == 0) {
        return 0;
    }

    temp_s2 = OS_DCACHE_ROUNDUP_ADDR(sp20);
    gHVQM2UtilAudioStreamP = HVQM2Util_GetRecord(temp_s2, B_8018EA50_usa->adpcmbuf, HVQM2_AUDIO, gHVQM2UtilAudioStreamP,
                                                 &B_8018EA60_usa, &B_8018EA78_usa);

    gHVQM2UtilRemainingAudioRecords--;

    temp_a0 = (void *)B_8018EA50_usa->adpcmbuf;
    temp_s0 = *(u32 *)(&temp_a0->samples);
    adpcmDecode(&temp_a0[1], *(u16 *)(&temp_s2->format), temp_s0, arg0, 1, &B_8018EB10_usa);

    var_a0 = arg0;
    for (i = 0; i < 0x2ED4U; i++) {
        var_a0[i] = (var_a0[i] * B_8018EA54_usa) >> 16;
    }

    return temp_s0;
}
#endif

#if VERSION_USA
#ifdef NON_MATCHING
typedef struct struct_8021AAE0_usa {
    /* 0x00 */ OSMesgQueue unk_00;
    /* 0x18 */ UNK_TYPE1 unk_18[0x58];
    /* 0x70 */ OSThread unk_70;
} struct_8021AAE0_usa; // size >= 0x220

extern struct_8021AAE0_usa B_8021AAE0_usa;

// stack problems
s32 HVQM2Util_Play(File *arg0, u32 arg1, void *arg2) {
    u8 pad[0x20] UNUSED;

    s32 sp40;
    UNK_TYPE sp44;

    s32 var_v0;
    s32 var_s7;
    u32 temp_s5;

    var_s7 = -1;
    temp_s5 = arg1 >> 0x10;
    arg1 = arg1 & 0xFFFF;
    if (arg1 & 0x1000) {
        func_8001F6B8_usa(&sp40, "iSkip16.BIF", &arg2);
        arg2 = ALIGN_PTR(arg2);
    }

    var_v0 = fileGetAddress(arg0, &sp44);
    if (var_v0 != 0) {
        // u8 pad2[0x8] UNUSED;
        u8 sp50[sizeof(HVQM2Record) + 0x10];

        HVQM2Record *temp_s2;

        s32 sp74;
        s32 sp7C;
        s32 sp84;
        s32 sp8C;
        s32 sp94;

        s32 *var_a0_6;

        s32 a1;

        u32 temp_a2;

        s32 *v1;

        register OSIntMask temp_s0_8;
        s32 var_s0;
        u16 temp_s0_3;
        s32 temp_s0_4;

        HVQM2Header *temp_s1;

        s32 var_s4;

        s32 temp;

        u32 sp9C;

        gHVQM2UtilCurrentVideoRomAddress = sp44;
        osViBlack(1U);
        func_8002CFC8_usa();
        func_80002D5C_usa();
        func_80002DE8_usa();

        for (var_s0 = 0; var_s0 < 8; var_s0++) {
            while (osViGetCurrentLine() != 0) {}
            while (osViGetCurrentLine() == 0) {}
        }

        osStopThread(&B_8021AAE0_usa.unk_70);
        osStopThread(&B_8019CFA0_usa);

        for (var_s0 = 0; var_s0 < 8; var_s0++) {
            while (osViGetCurrentLine() != 0) {}
            while (osViGetCurrentLine() == 0) {}
        }

        func_8008B21C_usa();

        gCfbBuffers[0] = (void *)&gFramebuffers[0];
        gCfbBuffers[1] = (void *)&gFramebuffers[1];

        B_8018EA50_usa = (void *)ALIGN8((uintptr_t)arg2);
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

        temp_s1 = OS_DCACHE_ROUNDUP_ADDR(&B_8018EA50_usa->unk_46240);

        osCreateMesgQueue(&B_8018EAD0_usa, B_8018EAE8_usa, ARRAY_COUNT(B_8018EAE8_usa));
        osSetEventMesg(4U, &B_8018EAD0_usa, NULL);
        osCreateMesgQueue(&B_8018EA78_usa, B_8018EA90_usa, ARRAY_COUNT(B_8018EA90_usa));
        osCreateMesgQueue(&B_8018EAB0_usa, B_8018EAC8_usa, ARRAY_COUNT(B_8018EAC8_usa));

        TimeKeeper_StartThread();

        hvqm2InitSP1(255);

        hvqtask.t.ucode = (void *)hvqm2sp1TextStart;
        hvqtask.t.ucode_size = (u8 *)hvqm2sp1TextEnd - (u8 *)hvqm2sp1TextStart;
        hvqtask.t.ucode_data = (u64 *)hvqm2sp1DataStart;

        hvqtask.t.type = 7;
        hvqtask.t.flags = 0;

        hvqtask.t.ucode_boot = (void *)rspbootTextStart;
        hvqtask.t.ucode_boot_size = (u8 *)rspbootTextEnd - (u8 *)rspbootTextStart;
        hvqtask.t.ucode_data_size = 0x70;

        hvqtask.t.data_ptr = (void *)&B_801AABA0_usa;
        hvqtask.t.yield_data_ptr = B_8018EA50_usa->hvq_yieldbuf;
        hvqtask.t.yield_data_size = sizeof(B_8018EA50_usa->hvq_yieldbuf);

        Cfb_Init();

        osViSwapBuffer(gCfbBuffers[1]);

        osViBlack(1U);

        RomCopy(temp_s1, gHVQM2UtilCurrentVideoRomAddress, 0x3C, OS_MESG_PRI_NORMAL, &B_8018EA98_usa, &B_8018EAB0_usa);

        gHVQM2UtilTotalVideoFrames = *(u32 *)&temp_s1->total_frames;
        sp9C = *(u32 *)&temp_s1->usec_per_frame;
        gHVQM2UtilTotalAudioRecords = *(u32 *)&temp_s1->total_audio_records;

        temp_a2 = (SCREEN_WIDTH - temp_s1->width) / 2;
        temp = (SCREEN_HEIGHT - temp_s1->height) / 2;
        sp94 = (temp * SCREEN_WIDTH) + temp_a2;
        hvqm2SetupSP1(temp_s1, SCREEN_WIDTH);

        Cfb_ReleaseAll();

        TimeKeeper_PlayVideo(HVQM2Util_Rewind, *(u32 *)&temp_s1->samples_per_sec);

        sp7C = -1;
        sp84 = 0;
        sp8C = 0;

        if ((temp_s5 != 0) && (temp_s5 < (u32)gHVQM2UtilTotalVideoFrames)) {
            gHVQM2UtilRemainingVideoFrames = (s32)temp_s5;
        }

        sp74 = 0;

        while (gHVQM2UtilRemainingVideoFrames > 0) {
            sp74++;
            if (sp74 >= 5) {
                osViBlack(0U);
            }
            osContStartReadData(&B_801AB988_usa);
            temp_s2 = OS_DCACHE_ROUNDUP_ADDR(sp50);

            gHVQM2UtilVideoStreamP = HVQM2Util_GetRecord(temp_s2, B_8018EA50_usa->hvqbuf, 1, gHVQM2UtilVideoStreamP,
                                                         &B_8018EA98_usa, &B_8018EAB0_usa);

            if (gHVQM2UtilDispTime > 0) {
                if (TimeKeeper_GetTime() > gHVQM2UtilDispTime + sp9C * 2) {
                    Cfb_ReleaseAll();

                    do {
                        gHVQM2UtilDispTime += sp9C;

                        gHVQM2UtilRemainingVideoFrames--;
                        if (gHVQM2UtilRemainingVideoFrames == 0) {
                            break;
                        }

                        gHVQM2UtilVideoStreamP =
                            HVQM2Util_GetRecord(temp_s2, B_8018EA50_usa->hvqbuf, 1, gHVQM2UtilVideoStreamP,
                                                &B_8018EA98_usa, &B_8018EAB0_usa);
                    } while ((*(u16 *)&temp_s2->format != 0) || (TimeKeeper_GetTime() > gHVQM2UtilDispTime));

                    if (gHVQM2UtilRemainingVideoFrames == 0) {
                        break;
                    }
                }
            }

            temp_s0_3 = *(u16 *)&temp_s2->format;
            var_s4 = 0;
            if (temp_s0_3 == 2) {
                var_s4 = var_s7;
            } else {
                var_s4 = Cfb_GetCurrentIndex();

                hvqtask.t.flags = 0;
                temp_s0_4 = hvqm2DecodeSP1(&B_8018EA50_usa->hvqbuf, temp_s0_3, &gCfbBuffers[var_s4][sp94],
                                           &gCfbBuffers[var_s7][sp94], B_8018EA50_usa->hvqwork, &B_801AABA0_usa,
                                           B_8018EA50_usa->hvq_spfifo);

                osWritebackDCacheAll();
                if (temp_s0_4 > 0) {
                    osInvalDCache(gCfbBuffers[var_s4], 0x25800);
                    osSpTaskStart(&hvqtask);
                    osRecvMesg(&B_8018EAD0_usa, NULL, 1);
                }
            }

            if (arg1 & 0x1000) {
                func_80021414_usa(sp40, 0xF2, 0xD0, gCfbBuffers[var_s4]);
            }

            Cfb_Keep(var_s4);

            if ((var_s7 >= 0) && (var_s7 != var_s4)) {
                Cfb_Release(var_s7);
            }

            TimeKeeper_AddVideoFrame(gCfbBuffers[var_s4], &gCfbStatus[var_s4], gHVQM2UtilDispTime);

            var_s7 = var_s4;

            gHVQM2UtilDispTime += sp9C;
            gHVQM2UtilRemainingVideoFrames--;

            if (osRecvMesg(&B_801AB7F0_usa, NULL, 0) == 0) {
                while (osAfterPreNMI() == -1) {}
                sp8C = -1;
                break;
            }

            osRecvMesg(&B_801AB988_usa, NULL, 1);
            osContGetReadData(&B_801C7228_usa);

            if (B_801C7228_usa.button == 0) {
                sp7C = 0;
            }

            if ((sp7C == 0) && (B_801C7228_usa.button & arg1)) {
                sp84 = -1;
                break;
            }
        }

        if (var_s7 >= 0) {
            TimeKeeper_AddVideoFrame(gCfbBuffers[var_s7], (void *)&gCfbStatus[var_s7], gHVQM2UtilDispTime);
        }

        if (sp8C == 0) {
            for (var_s0 = 0; var_s0 < 0x10; var_s0++) {
                while (osViGetCurrentLine() != 0) {}
                while (osViGetCurrentLine() == 0) {}
            }
        }

        temp_s0_8 = osSetIntMask(1U);
        osDestroyThread(&gTimeKeeperCounterThread);
        osDestroyThread(&gTimeKeeperThread);
        osSetIntMask(temp_s0_8);

        if (sp8C == 0) {
            var_a0_6 = osViGetNextFramebuffer();
            v1 = (void *)&gFramebuffers[0];
            if ((void *)var_a0_6 == (void *)&gFramebuffers[0]) {
                v1 = (void *)&gFramebuffers[1];
            }

            a1 = 0x12BF;
            while (a1 != -1) {
                *v1++ = *var_a0_6++;
                *v1++ = *var_a0_6++;
                *v1++ = *var_a0_6++;
                *v1++ = *var_a0_6++;
                *v1++ = *var_a0_6++;
                *v1++ = *var_a0_6++;
                *v1++ = *var_a0_6++;
                *v1++ = *var_a0_6++;

                a1 -= 1;
            }

            for (var_s0 = 0; var_s0 < 0x10; var_s0++) {
                while (osViGetCurrentLine() != 0) {}
                while (osViGetCurrentLine() == 0) {}
            }
        }

        osSetEventMesg(6U, NULL, NULL);
        osViSetEvent(&B_8021AAE0_usa.unk_00, (void *)0x29A, 1U);
        osSetEventMesg(4U, &B_8021AAE0_usa.unk_00, (void *)0x29B);
        osStartThread(&B_8021AAE0_usa.unk_70);
        InitGameAudioSystem();

        while (sp8C != 0) {
            v1 = (void *)&gFramebuffers[0];
            a1 = 0x95FF;

            while (a1 != -1) {
                *v1++ = 0;
                a1 -= 1;
            }

            v1 = (void *)&gFramebuffers[1];
            a1 = 0x95FF;

            while (a1 != -1) {
                *v1++ = 0;
                a1 -= 1;
            }
        }

        osViBlack(0U);
        var_v0 = sp84;
    }

    return var_v0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/hvqm2util", HVQM2Util_Play);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/hvqm2util", HVQM2Util_Play);
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

#if VERSION_USA
// rewind
tkAudioProc HVQM2Util_Rewind(void) {
    gHVQM2UtilVideoStreamP = gHVQM2UtilAudioStreamP = gHVQM2UtilCurrentVideoRomAddress + sizeof(HVQM2Header);
    gHVQM2UtilRemainingAudioRecords = gHVQM2UtilTotalAudioRecords;
    gHVQM2UtilRemainingVideoFrames = gHVQM2UtilTotalVideoFrames;

    gHVQM2UtilDispTime = 0;
    return HVQM2Util_GetNextAudioRecord;
}
#endif

#if VERSION_EUR
extern s32 B_8018DBEC_eur;
extern s32 B_8018DBF4_eur;
extern s32 B_8018DC04_eur;

tkAudioProc HVQM2Util_Rewind(void) {
    B_8018DBF4_eur = B_8018DB58_eur + 0x3C;
    gHVQM2UtilAudioStreamP = B_8018DBFC_eur;
    gHVQM2UtilRemainingAudioRecords = gHVQM2UtilTotalAudioRecords;
    B_8018DC04_eur = B_8018DBEC_eur;

    gHVQM2UtilDispTime = 0;
    return HVQM2Util_GetNextAudioRecord;
}
#endif
