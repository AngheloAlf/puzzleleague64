#include "libultra.h"
#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"
#include "libhvqm.h"

#if VERSION_USA
INLINE void romcpy(void *dest, romoffset_t src, size_t len, s32 pri, OSIoMesg *mb, OSMesgQueue *mq) {
    osInvalDCache(dest, len);

    while (osPiStartDma(mb, pri, 0, src, dest, len, mq) == -1) {}

    osRecvMesg(mq, NULL, OS_MESG_BLOCK);
}
#endif

#if VERSION_USA
// init_cfb
void func_8003E5DC_usa(void) {
    s32 var_a2;

    for (var_a2 = 0; var_a2 < 2; var_a2++) {
        s32 var_a0;

        for (var_a0 = 0; var_a0 < SCREEN_WIDTH * SCREEN_HEIGHT; var_a0++) {
            B_801AB620_usa[var_a2][var_a0] = 0;
        }

        B_801C6E48_usa[var_a2] = 0;
    }
}
#endif

#if VERSION_USA
// keep_cfb
INLINE void func_8003E638_usa(s32 arg0) {
    B_801C6E48_usa[arg0] |= 1;
}
#endif

#if VERSION_USA
// release_cfb
INLINE void func_8003E658_usa(s32 arg0) {
    if (arg0 >= 0) {
        B_801C6E48_usa[arg0] &= ~1;
    }
}
#endif

#if VERSION_USA
INLINE void func_8003E684_usa(void) {
    s32 var_a0;

    for (var_a0 = 0; var_a0 < 2; var_a0++) {
        B_801C6E48_usa[var_a0] &= ~1;
    }
}
#endif

#if VERSION_USA
// get_cfb
INLINE s32 func_8003E6B8_usa(void) {
    while (true) {
        s32 var_a0;

        for (var_a0 = 0; var_a0 < 2; var_a0++) {
            if (B_801C6E48_usa[var_a0] == 0) {
                return var_a0;
            }
        }
        osYieldThread();
    }
}
#endif

#if VERSION_USA
// tkGetTime
INLINE u64 func_8003E714_usa(void) {
    u64 temp_ret;

    if (!B_80192F64_usa) {
        return 0;
    }

    temp_ret = OS_CYCLES_TO_USEC(osGetTime() - B_80192F78_usa);

    if (B_80192F68_usa > 0) {
        temp_ret += B_80192F70_usa * 1000000LL / B_80192F68_usa;
    }

    return temp_ret;
}
#endif

#if VERSION_USA

STATIC_INLINE void tkClockDisable(void) {
    B_80192F64_usa = false;
}

STATIC_INLINE void tkClockStart(void) {
    B_80192F70_usa = 0;
    B_80192F78_usa = osGetTime();
    B_80192F64_usa = true;
}

typedef u32 (*tkAudioProc)(void *pcmbuf);
typedef tkAudioProc (*tkRewindProc)(void);

tkAudioProc func_80040B1C_usa(void);

typedef struct {
    tkRewindProc rewind; /* Pointer to stream rewind function */
    u32 samples_per_sec; /* Audio sampling rate */
} TKCMD;

typedef struct {
    u64 disptime; /* Display time */
    void *vaddr;  /* Frame buffer address */
    u32 *statP;   /* Pointer to frame buffer state flag */
} VideoRing;

extern VideoRing B_80192F00_usa[];
extern s32 B_80192F20_usa;
extern s32 B_80192F24_usa;

typedef struct AudioRing {
    void *buf; /* PCM data buffer */
    u32 len;   /* PCM data length */
} AudioRing;

extern OSThread B_80190CD0_usa;
extern OSMesgQueue B_80192EC0_usa;
extern void *B_80192ED8_usa;
extern void *B_80192EF8_usa;
extern s32 B_80192F28_usa;
extern AudioRing B_80192F30_usa[];
extern s32 B_80192F48_usa;
extern s32 B_80192F4C_usa;
extern s32 B_80192F50_usa;
extern u16 B_80192F60_usa;

typedef struct struct_8018EA50_usa_unk_00010 {
    /* 0x0000 */ s16 unk_0000[UNK_SIZE];
    /* 0x0002 */ UNK_TYPE1 unk_0002[0x5DA6];
} struct_8018EA50_usa_unk_00010; // size = 0x5DA8

typedef struct struct_8018EA50_usa {
    ///* 0x00000 */ UNK_TYPE1 unk_00000[0x18E50];
    /* 0x00000 */ UNK_TYPE1 unk_00000[0x10];
    /* 0x00010 */ struct_8018EA50_usa_unk_00010 unk_00010[UNK_SIZE];
    /* 0x05DB8 */ UNK_TYPE1 unk_05DB8[0x13098];
    /* 0x18E50 */ u8 unk_18E50[UNK_SIZE];
} struct_8018EA50_usa; // size = ?

extern struct_8018EA50_usa *B_8018EA50_usa;

// timekeeperProc
void func_8003E854_usa(void *arg UNUSED) {
    TKCMD *cmd;
    void *sp24 = NULL;
    u32 *sp2C = NULL;

    osCreateMesgQueue(&B_80192EC0_usa, &B_80192ED8_usa, 2);
    osViSetEvent(&B_80192EC0_usa, NULL, 1U);

    osCreateMesgQueue(&B_80192EE0_usa, &B_80192EF8_usa, 2);
    osSetEventMesg(6U, &B_80192EE0_usa, (void *)1);

    osCreateThread(&B_80190CD0_usa, 4, func_80040A60_usa, NULL, STACK_TOP(B_80190E80_usa), 0xD);
    osStartThread(&B_80190CD0_usa);

    osRecvMesg(&B_80192E80_usa, (OSMesg *)&cmd, 1);

    while (true) {
        s32 sp34;
        s32 sp3C;
        s32 sp44;
        tkAudioProc sp4C;
        OSTime sp50;
        s32 var_s4;
        u32 *var_s5;
        void *var_s6;
        bool var_s7;
        s32 var_fp;

        while (cmd == NULL) {
            osSendMesg(&B_80192EA0_usa, NULL, 1);
            osRecvMesg(&B_80192E80_usa, (OSMesg *)&cmd, 1);
        }

        tkClockDisable();
        sp4C = cmd->rewind();

        B_80192F68_usa = cmd->samples_per_sec;
        if (B_80192F68_usa != 0) {
            osAiSetFrequency(B_80192F68_usa);
        }

        var_s7 = false;
        var_s6 = 0;
        var_s5 = NULL;
        var_s4 = 0;
        var_fp = 0;
        sp34 = 0;
        sp3C = 0;
        sp44 = 0;
        B_80192F54_usa = 0;
        B_80192F5C_usa = 0;
        B_80192F58_usa = 0;
        B_80192F4C_usa = 0;
        B_80192F50_usa = 0;
        B_80192F48_usa = 0;
        B_80192F24_usa = 0;
        B_80192F28_usa = 0;
        B_80192F20_usa = 0;

        osSendMesg(&B_80192EA0_usa, NULL, 1);

        sp50 = osGetTime();
        while ((sp3C == 0) || ((B_80192F20_usa > 0) || (var_s6 != 0)) || (sp44 == 0) || (B_80192F48_usa > 0) ||
               (B_80192F58_usa != 0)) {
            u64 temp_s0;
            OSTime temp_s2;

            osRecvMesg(&B_80192EC0_usa, NULL, 1);

            temp_s2 = sp50;
            sp50 = osGetTime();
            temp_s0 = func_8003E714_usa() + OS_CYCLES_TO_USEC(sp50 - temp_s2);

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

            if (sp34 || (B_80192F48_usa > 0) || sp44) {
                while (B_80192F20_usa != 0) {
                    if (B_80192F00_usa[B_80192F28_usa].disptime > temp_s0) {
                        break;
                    }
                    if (var_s5 != NULL) {
                        *var_s5 &= ~2;
                    }
                    var_s5 = B_80192F00_usa[B_80192F28_usa].statP;
                    var_s6 = B_80192F00_usa[B_80192F28_usa].vaddr;
                    *var_s5 |= 2;
                    osViSwapBuffer(var_s6);

                    B_80192F28_usa++;
                    if (B_80192F28_usa == 2) {
                        B_80192F28_usa = 0;
                    }

                    B_80192F20_usa--;
                }
            }
            if (sp34 != 0) {
                osSetThreadPri(NULL, 0xE);

                while ((B_80192F48_usa > 0) && (B_80192F58_usa == 0)) {
                    void *s0 = B_80192F30_usa[B_80192F50_usa].buf;
                    u32 s1 = B_80192F30_usa[B_80192F50_usa].len;

                    if (osAiGetStatus() & 0x80000000) {
                        break;
                    }
                    if (osAiSetNextBuffer(s0, s1) == -1) {
                        break;
                    }

                    B_80192F58_usa = s1 >> 2;
                    if (var_s7 == false) {
                        var_s7 = true;
                        tkClockStart();
                    }

                    B_80192F50_usa++;
                    if (B_80192F50_usa == 3) {
                        B_80192F50_usa = 0;
                    }
                    B_80192F48_usa--;
                }
                osSetThreadPri(NULL, 0xC);
            }

            if ((sp44 == 0) && (B_80192F48_usa < 3) && (B_80192F54_usa < 3)) {
                u32 temp_v0_7;
                void *temp_s0_4;
                s32 temp_s2_2;
                u16 *var_a2;
                u16 *var_a1;
                s32 var_a0;

                temp_v0_7 = sp4C((void *)(&B_8018EA50_usa->unk_00010[var_s4].unk_0000[var_fp << 1]));
                if (temp_v0_7 > 0) {
                    B_80192F54_usa += 1;

                    var_a1 = &B_80192F60_usa;
                    var_a0 = (var_fp << 1);
                    var_a0--;
                    var_a2 = (void *)(B_8018EA50_usa->unk_00010[var_s4].unk_0000);
                    while (var_a0 != -1) {
                        *var_a2++ = *var_a1++;
                        var_a0 -= 1;
                    }
                    temp_v0_7 += var_fp;
                    var_fp = temp_v0_7 & 1;
                    temp_v0_7 -= var_fp;
                    temp_s2_2 = temp_v0_7 << 2;

                    temp_s0_4 = (void *)(B_8018EA50_usa->unk_00010[var_s4].unk_0000);
                    osWritebackDCache(temp_s0_4, temp_s2_2);
                    B_80192F30_usa[B_80192F4C_usa].buf = temp_s0_4;
                    B_80192F30_usa[B_80192F4C_usa].len = temp_s2_2;
                    B_80192F4C_usa++;
                    if (B_80192F4C_usa == 3) {
                        B_80192F4C_usa = 0;
                    }
                    B_80192F48_usa += 1;

                    var_a2 = &B_80192F60_usa;
                    var_a0 = (var_fp << 1);
                    var_a0--;
                    var_a1 = (void *)((uintptr_t)B_8018EA50_usa->unk_00010[var_s4].unk_0000 + temp_s2_2);
                    while (var_a0 != -1) {
                        *var_a2++ = *var_a1++;
                        var_a0 -= 1;
                    }

                    var_s4++;
                    if (var_s4 >= 3) {
                        var_s4 = 0;
                    }
                } else {
                    sp44 = 1;
                }
            }

            if (osRecvMesg(&B_80192E80_usa, (OSMesg *)&cmd, 0) == 0) {
                sp3C = 1;
            }
        }
    }
}
#endif

#if VERSION_USA
// createTimekeeper
INLINE void func_8003F0EC_usa(void) {
    osCreateMesgQueue(&B_80192E80_usa, B_80192E98_usa, ARRAY_COUNT(B_80192E98_usa));
    osCreateMesgQueue(&B_80192EA0_usa, B_80192EB8_usa, ARRAY_COUNT(B_80192EB8_usa));
    osCreateThread(&B_8018EB20_usa, 3, func_8003E854_usa, NULL, STACK_TOP(B_8018ECD0_usa), 0xC);
    osStartThread(&B_8018EB20_usa);
}
#endif

#if VERSION_USA
// tkStart
INLINE void func_8003F178_usa(tkRewindProc rewind, u32 samples_per_sec) {
    TKCMD tkcmd;

    tkcmd.rewind = rewind;
    tkcmd.samples_per_sec = samples_per_sec;

    osSendMesg(&B_80192E80_usa, (OSMesg *)&tkcmd, OS_MESG_BLOCK);
    osRecvMesg(&B_80192EA0_usa, (OSMesg *)NULL, OS_MESG_BLOCK);
}
#endif

#if VERSION_USA
// tkStop
void func_8003F1C0_usa(void) {
    osSendMesg(&B_80192E80_usa, NULL, OS_MESG_BLOCK);
    osRecvMesg(&B_80192EA0_usa, NULL, OS_MESG_BLOCK);
}
#endif

#if VERSION_USA
// tkPushVideoframe
INLINE void func_8003F200_usa(void *vaddr, u32 *statP, u64 disptime) {
    *statP |= 2;

    while (B_80192F20_usa >= 2) {
        osYieldThread();
    }

    B_80192F00_usa[B_80192F24_usa].disptime = disptime;
    B_80192F00_usa[B_80192F24_usa].vaddr = vaddr;
    B_80192F00_usa[B_80192F24_usa].statP = statP;

    B_80192F24_usa++;
    if (B_80192F24_usa == 2) {
        B_80192F24_usa = 0;
    }

    B_80192F20_usa++;
}
#endif

#if VERSION_USA
// get_record?
INLINE romoffset_t func_8003F2F0_usa(HVQM2Record *header, void *body, u16 type, romoffset_t src, OSIoMesg *mb,
                                     OSMesgQueue *mq) {
    s32 bodySize;
    s32 pri = type == 0 ? 1 : 0;

    while (true) {
        romcpy(header, src, sizeof(HVQM2Record), pri, mb, mq);
        src += sizeof(HVQM2Record);

        bodySize = header->size;

        if (header->type == type) {
            break;
        }
        src += bodySize;
    }

    if (bodySize != 0) {
        romcpy(body, src, bodySize, pri, mb, mq);
        src += bodySize;
    }

    return src;
}
#endif

#if VERSION_USA
// print_hvqm_info
void func_8003F42C_usa(HVQM2Header *header) {
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

#if VERSION_USA
extern ADPCMstate B_8018EB10_usa;

// next_audio_record
u32 func_8003F608_usa(void *arg0) {
    u8 sp20[sizeof(HVQM2Record) + 0x10];
    s16 *var_a0;
    HVQM2Record *temp_s2;
    HVQM2Audio *temp_a0;
    u32 temp_s0;
    u32 var_v1;

    if (B_8018EAFC_usa == 0) {
        return 0U;
    }

    temp_s2 = OS_DCACHE_ROUNDUP_ADDR(sp20);

    B_8018EAF8_usa =
        func_8003F2F0_usa(temp_s2, B_8018EA50_usa->unk_18E50, 0, B_8018EAF8_usa, &B_8018EA60_usa, &B_8018EA78_usa);

    B_8018EAFC_usa -= 1;

    temp_a0 = (void *)B_8018EA50_usa->unk_18E50;
    temp_s0 = *(u32 *)(&temp_a0->samples);
    adpcmDecode(&temp_a0[1], *(u16 *)(&temp_s2->format), temp_s0, arg0, 1U, &B_8018EB10_usa);
    var_v1 = 0;

    var_a0 = arg0;
    while (var_v1 < 0x2ED4U) {
        var_a0[var_v1] = (var_a0[var_v1] * B_8018EA54_usa) >> 16;
        var_v1 += 1;
    }

    return temp_s0;
}
#endif

#if VERSION_USA
#if 0
s32 func_8001CAD0_usa(s32, u32 *);                  /* extern */
UNK_RET func_8001F6B8_usa(s32 *, const char *, s32 *);             /* extern */
UNK_RET func_80021414_usa(s32, s32, s32, s16 *);              /* extern */
UNK_RET func_8002CFC8_usa();                              /* extern */
UNK_RET func_8008B21C_usa();                              /* extern */
extern void *B_8018EA90_usa;
extern OSIoMesg B_8018EA98_usa;
extern OSMesgQueue B_8018EAB0_usa;
extern void *B_8018EAC8_usa;
extern OSMesgQueue B_8018EAD0_usa;
extern void *B_8018EAE8_usa;
extern OSThread B_8019CFA0_usa;
extern u64 B_801AABA0_usa;
extern OSContPad B_801C7228_usa;
extern OSMesgQueue B_8021AAE0_usa;
extern OSThread B_8021AB50_usa;
extern u64 D_800AF9C0_usa;
extern u64 D_800AFA90_usa;
// maybe [SCREEN_HEIGHT][SCREEN_WIDTH]
extern s16 D_803B5000[SCREEN_WIDTH][SCREEN_HEIGHT];
extern s16 D_803DA800;

s32 func_8003F810_usa(s32 arg0, u32 arg1, s32 arg2) {
    s32 sp40;
    u32 sp44;
    u32 (*(*sp48)())(void *);
    s32 sp4C;
    u8 sp50[0x10+0x10];
    u32 sp6C;
    s32 sp74;
    s32 sp7C;
    s32 sp84;
    s32 sp8C;
    s32 sp94;
    u32 sp9C;
    s32 spA4;
    s16 **temp_s1_3;
    s16 **var_a2;
    s16 *temp_s1_4;
    s16 *temp_s1_5;
    s16 *temp_v1_10;
    s16 *temp_v1_11;
    s16 *temp_v1_12;
    s16 *temp_v1_13;
    s16 *temp_v1_14;
    s16 *temp_v1_15;
    s16 *temp_v1_16;
    s16 *var_v1_4;
    s32 *var_v1_5;
    s32 *var_v1_6;
    s32 *temp_a0_10;
    s32 *temp_a0_3;
    s32 *temp_a0_4;
    s32 *temp_a0_5;
    s32 *temp_a0_6;
    s32 *temp_a0_7;
    s32 *temp_a0_8;
    s32 *temp_a0_9;
    s32 *temp_s0_6;
    s32 *temp_s0_7;
    s32 *temp_v0_4;
    s32 *var_a0_6;
    s32 *var_t0;
    s32 *var_v1;
    s32 *var_v1_2;
    s32 *var_v1_3;
    s32 temp_a2_2;
    s32 temp_s0_2;
    HVQM2Header *temp_s1;
    s32 temp_s1_2;
    HVQM2Record *temp_s2;
    s32 temp_s3_3;
    s32 temp_s3_4;
    s32 temp_t3_2;
    s32 temp_t3_3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_8;
    s32 temp_v1_9;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_5;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_a3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_7;
    s32 var_s0_8;
    s32 var_s4;
    s32 var_s7;
    s32 var_v0;
    s8 *temp_s3;
    s8 *temp_s3_2;
    u16 temp_s0_3;
    u32 *temp_s0_5;
    u32 temp_a0;
    u32 temp_a0_2;
    u32 temp_a1;
    u32 temp_a1_2;
    u32 temp_a1_3;
    u32 temp_a1_4;
    u32 temp_a1_5;
    u32 temp_a1_6;
    u32 temp_a1_7;
    u32 temp_a1_8;
    u32 temp_a2;
    u32 temp_s0;
    u32 temp_s0_4;
    u32 temp_s0_8;
    u64 temp_s2_2;
    u64 temp_s2_3;
    u32 temp_s5;
    u32 temp_t1;
    u32 temp_t1_2;
    u32 temp_t1_3;
    u32 temp_t3;
    u32 temp_v1_2;
    u32 temp_v1_3;
    u32 temp_v1_4;
    u32 temp_v1_5;
    u32 temp_v1_6;
    u32 temp_v1_7;
    u32 var_a1;
    u32 var_s0_3;
    u32 var_s0_4;
    u32 var_s1;
    u32 var_s1_2;
    u32 var_s1_3;
    u32 var_s1_4;
    u32 var_t1;
    u64 temp_ret;
    u64 temp_ret_2;
    u64 temp_ret_3;
    u64 temp_ret_4;
    u64 temp_ret_5;
    u64 temp_ret_6;
    u64 var_a0_4;
    u64 var_s0_5;
    u64 var_s0_6;
    u64 var_t0_2;

    sp6C = arg1;
    var_s7 = -1;
    temp_s5 = sp6C >> 0x10;
    temp_t3 = sp6C & 0xFFFF;
    sp6C = temp_t3;
    if (temp_t3 & 0x1000) {
        func_8001F6B8_usa(&sp40, "iSkip16.BIF", &arg2);
        arg2 = (arg2 + 0xF) & ~0xF;
    }

    var_v0 = func_8001CAD0_usa(arg0, &sp44);
    if (var_v0 != 0) {
        B_8018EA58_usa = sp44;
        osViBlack(1U);
        func_8002CFC8_usa();
        func_80002D5C_usa();
        func_80002DE8_usa();

        for (var_s0 = 0; var_s0 < 8; var_s0++) {
            while (osViGetCurrentLine() != 0) {
            }
            while (osViGetCurrentLine() == 0) {
            }
        }

        osStopThread(&B_8021AB50_usa);
        osStopThread(&B_8019CFA0_usa);

        for (var_s0 = 0; var_s0 < 8; var_s0++) {
            while (osViGetCurrentLine() != 0) {
            }
            while (osViGetCurrentLine() == 0) {
            }
        }

        func_8008B21C_usa();

        B_801AB620_usa[0] = &D_803B5000;
        B_801AB620_usa[1] = &D_803DA800;

        temp_v0 = (arg2 + 7) & ~7;
        B_8018EA50_usa = (struct_8018EA50_usa *) temp_v0;
        arg2 += 0x46290;
        if ((temp_v0 + 0x10) & 0xF) {
            osSyncPrintf("ERROR: 'pcmbuf' not 16-byte aligned!\n");
        }
        if ((s32) &B_8018EA50_usa->unk_05DB8[0xBB58] & 0xF) {
            osSyncPrintf("ERROR: 'hvqbuf' not 16-byte aligned!\n");
        }
        if ((s32) B_8018EA50_usa->unk_18E50 & 0xF) {
            osSyncPrintf("ERROR: 'adpcmbuf' not 16-byte aligned!\n");
        }
        if ((s32) (B_8018EA50_usa + 0x19A10) & 0xF) {
            osSyncPrintf("ERROR: 'hvqwork' not 16-byte aligned!\n");
        }
        if ((s32) (B_8018EA50_usa + 0x1E520) & 0xF) {
            osSyncPrintf("ERROR: 'hvq_spfifo' not 16-byte aligned!\n");
        }
        if ((s32) (B_8018EA50_usa + 0x45630) & 0xF) {
            osSyncPrintf("ERROR: 'hvq_yieldbuf' not 16-byte aligned!\n");
        }

        temp_s1 = ((u32) (B_8018EA50_usa + 0x4624F) >> 4) * 0x10;

        osCreateMesgQueue(&B_8018EAD0_usa, &B_8018EAE8_usa, 1);
        osSetEventMesg(4U, &B_8018EAD0_usa, NULL);
        osCreateMesgQueue(&B_8018EA78_usa, &B_8018EA90_usa, 1);
        osCreateMesgQueue(&B_8018EAB0_usa, &B_8018EAC8_usa, 1);

        #if 0
        osCreateMesgQueue(&B_80192E80_usa, B_80192E98_usa, 1);
        osCreateMesgQueue(&B_80192EA0_usa, B_80192EB8_usa, 1);
        osCreateThread(&B_8018EB20_usa, 3, func_8003E854_usa, NULL, &B_80190CD0_usa, 0xC);
        osStartThread(&B_8018EB20_usa);
        #else
        func_8003F0EC_usa();
        #endif

        hvqm2InitSP1(0xFFU);
        var_t0 = B_801C6E48_usa;
        var_a3 = 0;
        var_a2 = B_801AB620_usa;
        hvqtask.t.ucode_size = hvqm2sp1TextEnd - hvqm2sp1TextStart;
        hvqtask.t.ucode_data = (u64 *) hvqm2sp1DataStart;
        hvqtask.t.ucode = (u64 *) hvqm2sp1TextStart;
        hvqtask.t.type = 7;
        hvqtask.t.ucode_boot_size = &D_800AFA90_usa - &D_800AF9C0_usa;
        hvqtask.t.ucode_data_size = 0x70;
        hvqtask.t.data_ptr = &B_801AABA0_usa;
        hvqtask.t.flags = 0;
        hvqtask.t.ucode_boot = &D_800AF9C0_usa;
        hvqtask.t.yield_data_size = 0xC10;
        hvqtask.t.yield_data_ptr = B_8018EA50_usa + 0x45630;

        do {
            var_a0 = 0;
loop_25:
            temp_v1 = var_a0 * 2;
            var_a0 += 1;
            *(temp_v1 + *var_a2) = 0;
            if (var_a0 <= 0x12BFF) {
                goto loop_25;
            }
            *var_t0 = 0;
            var_t0 += 4;
            var_a3 += 4;
            var_a2 += 4;
        } while (var_a3 < 8);

        osViSwapBuffer(*(B_801AB620_usa + 4));
        osViBlack(1U);
        temp_s0 = B_8018EA58_usa;

        #if 0
        osInvalDCache((void *) temp_s1, 0x3C);
        do {

        } while (osPiStartDma(&B_8018EA98_usa, 0, 0, temp_s0, (void *) temp_s1, 0x3CU, &B_8018EAB0_usa) == -1);
        osRecvMesg(&B_8018EAB0_usa, NULL, 1);
        #else
        romcpy(temp_s1, temp_s0, 0x3C, 0, &B_8018EA98_usa, &B_8018EAB0_usa);
        #endif

        B_8018EAEC_usa = temp_s1->total_frames;
        sp9C = temp_s1->usec_per_frame;
        temp_a2 = 0x140 - temp_s1->width;
        B_8018EAF0_usa = temp_s1->total_audio_records;
        sp94 = (((s32) (0xF0 - temp_s1->height) / 2) * 0x140) + ((s32) (temp_a2 + (temp_a2 >> 0x1F)) >> 1);
        hvqm2SetupSP1((HVQM2Header *) temp_s1, 0x140U);

        #if 0
        var_a0_2 = 0;
        var_v1 = B_801C6E48_usa;
        do {
            var_a0_2 += 1;
            *var_v1 &= ~1;
            var_v1 += 4;
        } while (var_a0_2 < 2);
        #else
        func_8003E684_usa();
        #endif

        sp7C = -1;
        sp84 = 0;
        sp8C = 0;

        #if 0
        sp48 = func_80040B1C_usa;
        sp4C = temp_s1->samples_per_sec;
        osSendMesg(&B_80192E80_usa, &sp48, 1);
        osRecvMesg(&B_80192EA0_usa, NULL, 1);
        #else
        func_8003F178_usa(func_80040B1C_usa, temp_s1->samples_per_sec);
        #endif

        if ((temp_s5 != 0) && (temp_s5 < (u32) B_8018EAEC_usa)) {
            B_8018EB00_usa = (s32) temp_s5;
        }

        sp74 = 0;
        if (B_8018EB00_usa != 0) {
            spA4 = 0x11910;
loop_36:
            temp_t3_2 = sp74 + 1;
            sp74 = temp_t3_2;
            if (temp_t3_2 >= 5) {
                osViBlack(0U);
            }
            osContStartReadData(&B_801AB988_usa);
            temp_s2 = ((((u32) &sp50) + 0xF) >> 4) * 0x10;
            var_s0_3 = B_8018EAF4_usa;
            temp_s3 = &B_8018EA50_usa->unk_00000[spA4];

            #if 0
loop_39:

            #if 0
            osInvalDCache((void *) temp_s2, 8);
            do {

            } while (osPiStartDma(&B_8018EA98_usa, 0, 0, var_s0_3, (void *) temp_s2, 8U, &B_8018EAB0_usa) == -1);
            osRecvMesg(&B_8018EAB0_usa, NULL, 1);
            #else
            romcpy(temp_s2, var_s0_3, 8, 0, &B_8018EA98_usa, &B_8018EAB0_usa);
            #endif

            temp_s1_2 = temp_s2->size;
            var_s0_4 = var_s0_3 + 8;
            if (temp_s2->type != 1) {
                var_s0_3 = var_s0_4 + temp_s1_2;
                goto loop_39;
            }
            if (temp_s1_2 != 0) {
                #if 0
                osInvalDCache(temp_s3, temp_s1_2);
                do {

                } while (osPiStartDma(&B_8018EA98_usa, 0, 0, var_s0_4, temp_s3, (u32) temp_s1_2, &B_8018EAB0_usa) == -1);
                osRecvMesg(&B_8018EAB0_usa, NULL, 1);
                #else
                romcpy(temp_s3, var_s0_4, temp_s1_2, 0, &B_8018EA98_usa, &B_8018EAB0_usa);
                #endif

                var_s0_4 += temp_s1_2;
            }
            #else
            var_s0_4 = func_8003F2F0_usa(temp_s2, temp_s3, 1, var_s0_3, &B_8018EA98_usa, &B_8018EAB0_usa);
            #endif

            B_8018EAF4_usa = var_s0_4;
            if ((B_8018EB08_usa != 0) || (*(&B_8018EB08_usa + 4) != 0)) {
                #if 0
                if (B_80192F64_usa == false) {
                    var_t0_2 = 0;
                    var_t1 = 0;
                } else {
                    temp_ret = osGetTime();
                    temp_v1_2 = (u32) temp_ret;
                    temp_a1 = *(&B_80192F78_usa + 4);
                    temp_a1_2 = temp_v1_2 - temp_a1;
                    temp_ret_2 = __udivdi3((((temp_ret - B_80192F78_usa) - (temp_v1_2 < temp_a1)) << 6) | (temp_a1_2 >> 0x1A), temp_a1_2 << 6, 0, 0xBB8U);
                    var_s0_5 = temp_ret_2;
                    var_s1 = (u32) temp_ret_2;
                    if (B_80192F68_usa != 0) {
                        temp_t1 = *(&B_80192F70_usa + 4);
                        temp_v1_3 = temp_t1 * 0x1F;
                        temp_v0_2 = (((B_80192F70_usa << 5) | (temp_t1 >> 0x1B)) - B_80192F70_usa) - ((u32) (temp_t1 << 5) < temp_t1);
                        temp_a1_3 = temp_t1 * 0x3D09;
                        temp_ret_3 = __udivdi3(((((((((temp_v0_2 << 6) | (temp_v1_3 >> 0x1A)) - temp_v0_2) - ((u32) (temp_t1 * 0x7C0) < temp_v1_3)) * 8) | ((u32) (temp_t1 * 0x7A1) >> 0x1D)) + B_80192F70_usa + (temp_a1_3 < temp_t1)) << 6) | (temp_a1_3 >> 0x1A), temp_t1 * 0xF4240, 0, B_80192F68_usa);
                        temp_v1_4 = (u32) temp_ret_3;
                        var_s1 += temp_v1_4;
                        var_s0_5 = var_s0_5 + temp_ret_3 + (var_s1 < temp_v1_4);
                    }
                    var_t0_2 = var_s0_5;
                    var_t1 = var_s1;
                }
                #else
                var_t0_2 = func_8003E714_usa();
                #endif
                temp_a0 = sp9C * 2;
                temp_a1_4 = *(&B_8018EB08_usa + 4) + temp_a0;
                temp_a0_2 = B_8018EB08_usa + (temp_a1_4 < temp_a0);
                if ((temp_a0_2 < var_t0_2) || ((var_t0_2 == temp_a0_2) && (temp_a1_4 < var_t1))) {
                    #if 0
                    var_a0_3 = 0;
                    var_v1_2 = B_801C6E48_usa;
                    do {
                        var_a0_3 += 1;
                        *var_v1_2 &= ~1;
                        var_v1_2 += 4;
                    } while (var_a0_3 < 2);
                    #else
                    func_8003E684_usa();
                    #endif
loop_78:

                    #if 0
                    temp_a1_5 = *(&B_8018EB08_usa + 4) + sp9C;
                    B_8018EB08_usa += temp_a1_5 < sp9C;
                    *(&B_8018EB08_usa + 4) = temp_a1_5;
                    #else
                    B_8018EB08_usa += sp9C;
                    #endif

                    B_8018EB00_usa--;
                    if (B_8018EB00_usa != 0) {
                        var_s1_2 = B_8018EAF4_usa;
                        temp_s3_2 = &B_8018EA50_usa->unk_00000[spA4];

                        #if 0
loop_61:

                        #if 0
                        osInvalDCache((void *) temp_s2, 8);
                        do {

                        } while (osPiStartDma(&B_8018EA98_usa, 0, 0, var_s1_2, (void *) temp_s2, 8U, &B_8018EAB0_usa) == -1);
                        osRecvMesg(&B_8018EAB0_usa, NULL, 1);
                        #else
                        romcpy(temp_s2, var_s1_2, 8, 0, &B_8018EA98_usa, &B_8018EAB0_usa);
                        #endif

                        temp_s0_2 = temp_s2->size;
                        var_s1_3 = var_s1_2 + 8;
                        if (temp_s2->type != 1) {
                            var_s1_2 = var_s1_3 + temp_s0_2;
                            goto loop_61;
                        }
                        if (temp_s0_2 != 0) {
                            #if 0
                            osInvalDCache(temp_s3_2, temp_s0_2);
                            do {

                            } while (osPiStartDma(&B_8018EA98_usa, 0, 0, var_s1_3, temp_s3_2, (u32) temp_s0_2, &B_8018EAB0_usa) == -1);
                            osRecvMesg(&B_8018EAB0_usa, NULL, 1);
                            #else
                            romcpy(temp_s3_2, var_s1_3, temp_s0_2, 0, &B_8018EA98_usa, &B_8018EAB0_usa);
                            #endif
                            var_s1_3 += temp_s0_2;
                        }
                        #else
                        var_s1_3 = func_8003F2F0_usa(temp_s2, temp_s3_2, 1, var_s1_2, &B_8018EA98_usa, &B_8018EAB0_usa);
                        #endif

                        B_8018EAF4_usa = var_s1_3;
                        if (temp_s2->format == 0) {
                            #if 0
                            if (B_80192F64_usa == false) {
                                var_a0_4 = 0;
                                var_a1 = 0;
                            } else {
                                temp_ret_4 = osGetTime();
                                temp_v1_5 = (u32) temp_ret_4;
                                temp_a1_6 = *(&B_80192F78_usa + 4);
                                temp_a1_7 = temp_v1_5 - temp_a1_6;
                                temp_ret_5 = __udivdi3((((temp_ret_4 - B_80192F78_usa) - (temp_v1_5 < temp_a1_6)) << 6) | (temp_a1_7 >> 0x1A), temp_a1_7 << 6, 0, 0xBB8U);
                                var_s0_6 = temp_ret_5;
                                var_s1_4 = (u32) temp_ret_5;
                                if (B_80192F68_usa != 0) {
                                    temp_t1_2 = *(&B_80192F70_usa + 4);
                                    temp_v1_6 = temp_t1_2 * 0x1F;
                                    temp_v0_3 = (((B_80192F70_usa << 5) | (temp_t1_2 >> 0x1B)) - B_80192F70_usa) - ((u32) (temp_t1_2 << 5) < temp_t1_2);
                                    temp_a1_8 = temp_t1_2 * 0x3D09;
                                    temp_ret_6 = __udivdi3(((((((((temp_v0_3 << 6) | (temp_v1_6 >> 0x1A)) - temp_v0_3) - ((u32) (temp_t1_2 * 0x7C0) < temp_v1_6)) * 8) | ((u32) (temp_t1_2 * 0x7A1) >> 0x1D)) + B_80192F70_usa + (temp_a1_8 < temp_t1_2)) << 6) | (temp_a1_8 >> 0x1A), temp_t1_2 * 0xF4240, 0, B_80192F68_usa);
                                    temp_v1_7 = (u32) temp_ret_6;
                                    var_s1_4 += temp_v1_7;
                                    var_s0_6 = var_s0_6 + temp_ret_6 + (var_s1_4 < temp_v1_7);
                                }
                                var_a0_4 = var_s0_6;
                                var_a1 = var_s1_4;
                            }
                            #else
                            var_a0_4 = func_8003E714_usa();
                            #endif

                            if (((u32) B_8018EB08_usa < var_a0_4) || ((var_a0_4 == B_8018EB08_usa) && ((u32) *(&B_8018EB08_usa + 4) < var_a1))) {
                                goto loop_78;
                            }
                        } else {
                            goto loop_78;
                        }
                    }
                    if (B_8018EB00_usa != 0) {
                        goto block_80;
                    }
                } else {
                    goto block_80;
                }
            } else {
block_80:
                temp_s0_3 = temp_s2->format;
                var_a0_5 = 0;
                if ((temp_s0_3 & 0xFFFF) == 2) {
                    var_s4 = var_s7;
                } else {
                    #if 0
loop_82:
                    var_v1_3 = B_801C6E48_usa;
loop_83:
                    if (*var_v1_3 != 0) {
                        var_a0_5 += 1;
                        var_v1_3 += 4;
                        if (var_a0_5 >= 2) {
                            osYieldThread();
                            var_a0_5 = 0;
                            goto loop_82;
                        }
                        goto loop_83;
                    }
                    #else
                    var_a0_5 = func_8003E6B8_usa();
                    #endif
                    var_s4 = var_a0_5;
                    temp_s1_3 = &B_801AB620_usa[var_a0_5];
                    hvqtask.t.flags = 0;
                    temp_s0_4 = hvqm2DecodeSP1(&B_8018EA50_usa->unk_00000[spA4], (u32) temp_s0_3, (u16 *) &(*temp_s1_3)[sp94], (u16 *) &B_801AB620_usa[var_s7][sp94], B_8018EA50_usa + 0x19A10, (HVQM2Arg *) &B_801AABA0_usa, B_8018EA50_usa + 0x1E520);

                    osWritebackDCacheAll();
                    if ((s32) temp_s0_4 > 0) {
                        osInvalDCache(*temp_s1_3, 0x25800);
                        temp_s0_5 = &hvqtask.t.flags - 4;
                        osSpTaskLoad((OSTask *) temp_s0_5);
                        osSpTaskStartGo((OSTask *) temp_s0_5);
                        osRecvMesg(&B_8018EAD0_usa, NULL, 1);
                    }
                }

                if (sp6C & 0x1000) {
                    func_80021414_usa(sp40, 0xF2, 0xD0, B_801AB620_usa[var_s4]);
                }

                #if 0
                temp_a0_3 = &B_801C6E48_usa[var_s4];
                *temp_a0_3 |= 1;
                #else
                func_8003E638_usa(var_s4);
                #endif

                if ((var_s7 >= 0) && (var_s7 != var_s4)) {
                    #if 0
                    if (var_s7 >= 0) {
                        temp_v0_4 = &B_801C6E48_usa[var_s7];
                        *temp_v0_4 &= ~1;
                    }
                    #else
                    func_8003E658_usa(var_s7);
                    #endif
                }
                temp_s1_4 = B_801AB620_usa[var_s4];
                temp_s0_6 = &B_801C6E48_usa[var_s4];
                temp_s2_2 = B_8018EB08_usa;
                temp_s3_3 = *(&B_8018EB08_usa + 4);
                #if 0
                *temp_s0_6 |= 2;
loop_95:
                if (B_80192F20_usa >= 2) {
                    osYieldThread();
                    goto loop_95;
                }
                temp_v1_8 = B_80192F24_usa * 0x10;
                temp_v0_5 = B_80192F24_usa + 1;
                B_80192F00_usa[B_80192F24_usa].disptime = temp_s2_2;
                // *(B_80192F00_usa + 4 + temp_v1_8) = temp_s3_3;
                *(&B_80192F00_usa->vaddr + temp_v1_8) = temp_s1_4;
                *(&B_80192F00_usa->statP + temp_v1_8) = temp_s0_6;
                B_80192F24_usa = temp_v0_5;
                var_s7 = var_s4;
                if (temp_v0_5 == 2) {
                    B_80192F24_usa = 0;
                }
                B_80192F20_usa += 1;
                #else
                func_8003F200_usa(temp_s1_4, temp_s0_6, temp_s2_2);
                #endif
                temp_t1_3 = *(&B_8018EB08_usa + 4) + sp9C;
                B_8018EB08_usa += temp_t1_3 < sp9C;
                *(&B_8018EB08_usa + 4) = temp_t1_3;
                B_8018EB00_usa -= 1;
                if (osRecvMesg(&B_801AB7F0_usa, NULL, 0) == 0) {
                    do {

                    } while (osAfterPreNMI() == -1);
                    sp8C = -1;
                } else {
                    osRecvMesg(&B_801AB988_usa, NULL, 1);
                    osContGetReadData(&B_801C7228_usa);
                    temp_t3_3 = sp7C & -(B_801C7228_usa.button != 0);
                    sp7C = temp_t3_3;
                    if ((temp_t3_3 == 0) && (B_801C7228_usa.button & sp6C)) {
                        sp84 = -1;
                    } else if (B_8018EB00_usa != 0) {
                        goto loop_36;
                    }
                }
            }
        }

        if (var_s7 >= 0) {
            temp_s1_5 = B_801AB620_usa[var_s7];
            temp_s0_7 = &B_801C6E48_usa[var_s7];
            temp_s2_3 = B_8018EB08_usa;
            temp_s3_4 = *(&B_8018EB08_usa + 4);
            #if 0
            *temp_s0_7 |= 2;
loop_108:
            if (B_80192F20_usa >= 2) {
                osYieldThread();
                goto loop_108;
            }
            temp_v1_9 = B_80192F24_usa * 0x10;
            temp_v0_6 = B_80192F24_usa + 1;
            B_80192F00_usa[B_80192F24_usa].disptime = temp_s2_3;
            // *(B_80192F00_usa + 4 + temp_v1_9) = temp_s3_4;
            *(&B_80192F00_usa->vaddr + temp_v1_9) = temp_s1_5;
            *(&B_80192F00_usa->statP + temp_v1_9) = temp_s0_7;
            B_80192F24_usa = temp_v0_6;
            if (temp_v0_6 == 2) {
                B_80192F24_usa = 0;
            }
            B_80192F20_usa += 1;
            #else
            func_8003F200_usa(temp_s1_5, temp_s0_7, temp_s2_3);
            #endif
        }
        var_s0_7 = 0;
        if (sp8C == 0) {
            do {
loop_113:
                if (osViGetCurrentLine() != 0) {
                    goto loop_113;
                }
loop_114:
                if (osViGetCurrentLine() == 0) {
                    goto loop_114;
                }
                var_s0_7 += 1;
            } while (var_s0_7 < 0x10);
        }
        temp_s0_8 = osSetIntMask(1U);
        osDestroyThread(&B_80190CD0_usa);
        osDestroyThread(&B_8018EB20_usa);
        osSetIntMask(temp_s0_8);
        if (sp8C == 0) {
            var_a0_6 = osViGetNextFramebuffer();
            var_v1_4 = &D_803B5000;
            var_a1_2 = 0x12BF;
            if (var_a0_6 == &D_803B5000) {
                var_v1_4 = &D_803DA800;
            }
            do {
                temp_a0_4 = var_a0_6 + 4;
                var_a1_2 -= 1;
                *var_v1_4 = (s32) *var_a0_6;
                temp_v1_10 = var_v1_4 + 4;
                temp_a0_5 = temp_a0_4 + 4;
                *temp_v1_10 = (s32) *temp_a0_4;
                temp_v1_11 = temp_v1_10 + 4;
                temp_a0_6 = temp_a0_5 + 4;
                *temp_v1_11 = (s32) *temp_a0_5;
                temp_v1_12 = temp_v1_11 + 4;
                temp_a0_7 = temp_a0_6 + 4;
                *temp_v1_12 = (s32) *temp_a0_6;
                temp_v1_13 = temp_v1_12 + 4;
                temp_a0_8 = temp_a0_7 + 4;
                *temp_v1_13 = (s32) *temp_a0_7;
                temp_v1_14 = temp_v1_13 + 4;
                temp_a0_9 = temp_a0_8 + 4;
                *temp_v1_14 = (s32) *temp_a0_8;
                temp_v1_15 = temp_v1_14 + 4;
                temp_a0_10 = temp_a0_9 + 4;
                *temp_v1_15 = (s32) *temp_a0_9;
                temp_v1_16 = temp_v1_15 + 4;
                var_a0_6 = temp_a0_10 + 4;
                *temp_v1_16 = (s32) *temp_a0_10;
                var_v1_4 = temp_v1_16 + 4;
            } while (var_a1_2 != -1);
            var_s0_8 = 0;
            do {
loop_122:
                if (osViGetCurrentLine() != 0) {
                    goto loop_122;
                }
loop_123:
                if (osViGetCurrentLine() == 0) {
                    goto loop_123;
                }
                var_s0_8 += 1;
            } while (var_s0_8 < 0x10);
        }
        osSetEventMesg(6U, NULL, NULL);
        osViSetEvent(&B_8021AAE0_usa, (void *)0x29A, 1U);
        osSetEventMesg(4U, &B_8021AAE0_usa, (void *)0x29B);
        osStartThread(&B_8021AAE0_usa + 0x70);
        func_80003E90_usa();
        if (sp8C != 0) {
            do {
                var_v1_5 = &D_803B5000;
                var_a1_3 = 0x95FF;

                while (var_a1_3 != -1) {
                    *var_v1_5 = 0;
                    var_v1_5++;
                    var_a1_3 -= 1;
                }


                var_v1_6 = &D_803DA800;
                var_a1_4 = 0x95FF;

                while (var_a1_4 != -1) {
                    *var_v1_6 = 0;
                    var_v1_6++;
                    var_a1_4 -= 1;
                }

            } while (sp8C != 0);
        }
        osViBlack(0U);
        var_v0 = sp84;
    }

    return var_v0;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/03F130_usa", func_8003F810_usa);
#endif
#endif

#if VERSION_USA
s32 func_800409E4_usa(f32 arg0) {
    B_8018EA54_usa = arg0 * 0x10000;

    return -1;
}
#endif

#if VERSION_USA
void func_80040A4C_usa(void) {
    B_8018EA54_usa = 0xCCCC;
}
#endif

#if VERSION_USA

// daCounterProc
void func_80040A60_usa(void *arg UNUSED) {
    while (true) {
        osRecvMesg(&B_80192EE0_usa, NULL, 1);
        B_80192F78_usa = osGetTime();
        if (B_80192F5C_usa != 0) {
            B_80192F54_usa -= 1;
        }
        B_80192F70_usa += B_80192F5C_usa;
        B_80192F5C_usa = B_80192F58_usa;
        B_80192F58_usa = 0;
    }
}
#endif

#if VERSION_USA
// rewind
tkAudioProc func_80040B1C_usa(void) {
    B_8018EAF4_usa = B_8018EAF8_usa = B_8018EA58_usa + sizeof(HVQM2Header);
    B_8018EAFC_usa = B_8018EAF0_usa;
    B_8018EB00_usa = B_8018EAEC_usa;
    B_8018EB08_usa = 0;
    return func_8003F608_usa;
}
#endif
