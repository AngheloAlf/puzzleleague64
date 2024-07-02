/**
 * Original filename: sound.c
 */

#include "sound.h"

#include "ultra64.h"
#include "libmus/libmus.h"
#include "libmus/lib_memory.h"

#include "include_asm.h"
#include "macros_defines.h"
#include "unknown_structs.h"
#include "main_functions.h"
#include "main_variables.h"

#include "rom_offsets.h"
#include "sfxlimit.h"
#include "boot_main.h"
#include "pon_thread.h"

extern s16 D_800B3AE4_usa;

extern s32 D_800B3AEC_usa;

typedef struct struct_8018A748_usa {
    /* 0x00 */ UNK_TYPE4 unk_00;
    /* 0x04 */ musHandle unk_04;
    /* 0x08 */ void *unk_08;
    /* 0x0C */ struct song_t *song_addr;
    /* 0x10 */ UNK_TYPE4 unk_10;
    /* 0x14 */ UNK_TYPE4 unk_14;
    /* 0x18 */ UNK_TYPE4 unk_18;
    /* 0x1C */ UNK_TYPE2 unk_1C;
    /* 0x1E */ UNK_TYPE1 unk_1E[0x2];
    /* 0x20 */ UNK_TYPE1 unk_20[0x4];
    /* 0x24 */ UNK_TYPE2 unk_24;
    /* 0x26 */ UNK_TYPE2 unk_26;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ UNK_TYPE4 unk_34;
} struct_8018A748_usa; // size = 0x38

extern struct_8018A748_usa B_8018A748_usa[2];

extern s32 B_800CF2A0_usa;

extern u8 B_800CF2B0_usa[];
extern u8 B_8016F2B0_usa[];
extern u8 B_801842B0_usa[];

extern s32 B_8018A6C0_usa;
extern s32 B_8018A6F8_usa;
extern int B_801C7BAC_usa;

extern s16 B_8018A6F0_usa;

extern UNK_PTR B_8018A6B0_usa;
extern UNK_PTR B_8018A6B4_usa;
extern UNK_PTR B_8018A6B8_usa;
extern UNK_PTR B_8018A6BC_usa;
extern UNK_PTR B_8018A6C4_usa;
extern UNK_PTR B_8018A6C8_usa;
extern UNK_PTR B_8018A6CC_usa;
extern UNK_PTR B_8018A6D0_usa;
extern UNK_PTR B_8018A6D8_usa;
extern UNK_PTR B_8018A6DC_usa;
extern UNK_PTR B_8018A6E4_usa;
extern UNK_PTR B_8018A6E8_usa;
extern s32 B_8018A6E0_usa;
extern s16 B_8018A6EC_usa;
extern s16 B_8018A6EE_usa;
extern u16 B_801F9CC4_usa;
extern s16 D_800B3AD0_usa;
extern s16 D_800B3AD2_usa;
extern s16 D_800B3AD4_usa;

extern s32 D_800B3AE0_usa;
extern s16 D_800B3AE6_usa;
extern s32 D_800B3AE8_usa;
extern u16 D_800B3AFA_usa;
extern s16 D_800B3AFC_usa[];
extern s16 D_800B3AFE_usa;
extern s32 D_800B3B00_usa;

#if VERSION_USA
void func_80001B10_usa(void) {
    D_800B3AEC_usa = -1;
    D_800B3AF8_usa = 1;
    D_800B3AFA_usa = 8;
    D_800B3AFC_usa[0] = 0x80;
    D_800B3AFE_usa = 0x80;
    D_800B3AD0_usa = 0x1C;
    D_800B3AD2_usa = 0xC;
    last_song_handle = 0;
    D_800B3ADC_usa = 0;
    D_800B3AE0_usa = 0;
    D_800B3AE4_usa = 0;
    D_800B3AE6_usa = 0;
    D_800B3AE8_usa = 0;
    B_801C7BAC_usa = 0;
    B_801F9CC4_usa = 0;
    B_8018A6EC_usa = 0;
    B_8018A6EE_usa = 0;
    B_8018A6F0_usa = 0;
    D_800B3AD4_usa = 0x1A;
    D_800B3B00_usa = 0;
    B_8018A6B8_usa = __MusIntMemMalloc(0xA00);
    B_8018A6BC_usa = __MusIntMemMalloc(0xA00);
    B_8018A6C4_usa = __MusIntMemMalloc(0x2000);
    B_8018A6C8_usa = __MusIntMemMalloc(0x400);
    B_8018A6CC_usa = __MusIntMemMalloc(0x400);
    B_8018A6D0_usa = __MusIntMemMalloc(0x400);
    B_8018A6B0_usa = __MusIntMemMalloc(0x10000);
    B_8018A6B4_usa = __MusIntMemMalloc(0x10000);
    B_8018A6E0_usa = 0;
    B_8018A6D8_usa = B_8018A6C4_usa;
    B_8018A6DC_usa = B_8018A6C8_usa;
    B_8018A6E4_usa = B_8018A6CC_usa;
    B_8018A6E8_usa = B_8018A6D0_usa;
}
#endif

#if VERSION_USA
INLINE void func_80001CAC_usa(RomOffset segmentRom, void *dstAddr, size_t segmentSize) {
    uintptr_t currentVram = (uintptr_t)dstAddr;
    s32 remainingSize = segmentSize;
    RomOffset currentRom = segmentRom;

    while (remainingSize != 0) {
        size_t blkSize = MIN(remainingSize, 0x4000);
        OSIoMesg mb;
        OSMesg sp38;

        osInvalDCache((void *)currentVram, blkSize);
        osPiStartDma(&mb, OS_MESG_PRI_NORMAL, OS_READ, currentRom, (void *)currentVram, blkSize, &B_8019D158_usa);
        osRecvMesg(&B_8019D158_usa, &sp38, OS_MESG_BLOCK);
        currentRom += blkSize;
        remainingSize -= blkSize;
        currentVram += blkSize;
    }
}
#endif

#if VERSION_USA
s16 func_80001D60_usa(s32 arg0, u16 arg1) {
    s16 temp_a1 = arg1;

    if (arg1 >= 2) {
        temp_a1 = 0;
    }

    if (!IsTuneBufferFree(temp_a1)) {
        func_80002C50_usa(B_8018A748_usa[temp_a1].unk_04);
        return -1;
    }

    B_8018A748_usa[temp_a1].unk_00 = arg0;
    if (arg0 < ARRAY_COUNTU(D_800B5330_usa) - 1) {
        RomOffsetPair *pair = &D_800B5330_usa[arg0];

        func_80001F68_usa(B_8016F2B0_usa, temp_a1);
        func_80001F90_usa(pair->start, pair->end - pair->start, temp_a1);
        SetSongCrossFadeVolume(BGM_INIT_TABLE[arg0].unk_1, temp_a1);
    }
    if (arg0 == ARRAY_COUNTU(D_800B5330_usa) - 1) {
        RomOffsetPair *pair = &D_800B5330_usa[arg0];

        func_80001F68_usa(B_801842B0_usa, temp_a1);
        func_80001F90_usa(pair->start, pair->end - pair->start, temp_a1);
        SetSongCrossFadeVolume(BGM_INIT_TABLE[arg0].unk_1, temp_a1);
    }
    return temp_a1;
}
#endif

#if VERSION_USA
s16 func_80001E98_usa(musHandle handle) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(B_8018A748_usa); i++) {
        if (B_8018A748_usa[i].unk_04 == handle) {
            return i;
        }
    }

    return -1;
}
#endif

#if VERSION_USA
s16 func_80001ED8_usa(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(B_8018A748_usa); i++) {
        if (B_8018A748_usa[i].unk_1C != 1) {
            return i;
        }
    }

    return -1;
}
#endif

#if VERSION_USA
s16 IsTuneBufferFree(s32 index) {
    return B_8018A748_usa[index].unk_1C != 1;
}
#endif

#if VERSION_USA
void func_80001F40_usa(struct song_t *arg0, s16 index) {
    B_8018A748_usa[index].song_addr = arg0;
}
#endif

#if VERSION_USA
void func_80001F68_usa(void *arg0, s16 index) {
    B_8018A748_usa[index].unk_08 = arg0;
}
#endif

#if VERSION_USA
void func_80001F90_usa(RomOffset segmentRom, size_t segmentSize, s16 index) {
    func_80001CAC_usa(segmentRom, func_800028B8_usa(index), segmentSize);
}
#endif

#if VERSION_USA
int func_80002054_usa(void) {
    musConfig sp20;
    OSIoMesg mb;
    void *sp78;
    uintptr_t currentVram;
    s32 remainingSize;
    RomOffset currentRom;

    currentVram = (uintptr_t)B_8016F2B0_usa;
    remainingSize = D_800B5570_usa[3].unk_04 - D_800B5570_usa[3].unk_00;
    currentRom = D_800B5570_usa[3].unk_00;
    while (remainingSize != 0) {
        size_t blkSize = MIN(remainingSize, 0x4000);

        osInvalDCache((void *)currentVram, blkSize);
        osPiStartDma(&mb, 0, 0, currentRom, (void *)currentVram, blkSize, &B_8019D158_usa);
        osRecvMesg(&B_8019D158_usa, &sp78, 1);
        currentRom += blkSize;
        remainingSize -= blkSize;
        currentVram += blkSize;
    }

    currentVram = (uintptr_t)B_801842B0_usa;
    remainingSize = D_800B5570_usa[2].unk_04 - D_800B5570_usa[2].unk_00;
    currentRom = D_800B5570_usa[2].unk_00;
    while (remainingSize != 0) {
        size_t blkSize = MIN(remainingSize, 0x4000);

        osInvalDCache((void *)currentVram, blkSize);
        osPiStartDma(&mb, 0, 0, currentRom, (void *)currentVram, blkSize, &B_8019D158_usa);
        osRecvMesg(&B_8019D158_usa, &sp78, 1);
        currentRom += blkSize;
        remainingSize -= blkSize;
        currentVram += blkSize;
    }

    sp20.channels = 0x28;
    sp20.sched = &B_8021AAA0_usa;
    sp20.thread_priority = THREAD_PRI_LIBMUS;
    sp20.heap = B_800CF2B0_usa;
    sp20.heap_length = 0xA0000;
    sp20.ptr = B_8016F2B0_usa;
    sp20.syn_output_rate = 0x5622;
    sp20.syn_updates = 0x100;
    sp20.syn_rsp_cmds = 0x2000;
    sp20.syn_retraceCount = 1;
    sp20.syn_num_dma_bufs = 0x30;
    sp20.control_flag = 0;
    sp20.default_fxbank = 0;
    sp20.syn_dma_buf_size = 0x800;
    sp20.wbk = (void *)D_800B5570_usa[3].unk_10;
    return MusInitialize(&sp20);
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000222C_usa);
#endif

#if VERSION_USA
#if 0
extern s32 B_8018A6D8_usa;
extern s32 B_8018A6DC_usa;
extern s32 B_8018A6E4_usa;
extern s32 B_8018A6E8_usa;
extern ? B_8018A6F8_usa;
extern ? B_8018A6FC_usa;
extern ? B_8018A700_usa;
extern ? B_8018A704_usa;
extern ? D_800B5570_usa;

void LoadSFXBank(s32 arg0, s32 arg1) {
    OSIoMesg sp20;
    void *sp38;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_v0;
    s32 var_v1;
    u32 temp_a0;
    u32 temp_a3;
    u32 temp_a3_2;
    u32 var_a0;
    u32 var_s3;
    u32 var_s3_2;
    void *temp_a0_2;
    void *temp_a1;
    void *temp_s6;
    void *var_s2;
    void *var_s2_2;

    temp_a0 = arg1 & 0xFFFF;
    if (temp_a0 >= 5U) {
        osSyncPrintf("invalid index baka! \n");
        return;
    }
    temp_s6 = ((arg0 & 0xFFFF) * 0x14) + &D_800B5570_usa;
    temp_a3 = temp_s6->unk_0;
    if (temp_a3 != 0) {
        var_s2 = *(&B_8018A700_usa + (temp_a0 * 0x10));
        var_s3 = temp_a3;
        var_s1 = temp_s6->unk_4 - var_s3;
        if (var_s1 != 0) {
            do {
                var_s0 = var_s1;
                if (var_s1 >= 0x4001) {
                    var_s0 = 0x4000;
                }
                osInvalDCache(var_s2, var_s0);
                osPiStartDma(&sp20, 0, 0, var_s3, var_s2, (u32) var_s0, &B_8019D158_usa);
                osRecvMesg(&B_8019D158_usa, &sp38, 1);
                var_s3 += var_s0;
                var_s1 -= var_s0;
                var_s2 += var_s0;
            } while (var_s1 != 0);
        }
    }
    temp_a3_2 = temp_s6->unk_8;
    temp_v0 = arg1 & 0xFFFF;
    if (temp_a3_2 != 0) {
        var_s2_2 = *(&B_8018A6FC_usa + (temp_v0 * 0x10));
        var_s3_2 = temp_a3_2;
        var_s1_2 = temp_s6->unk_C - var_s3_2;
        var_a0 = arg0 & 0xFFFF;
        if (var_s1_2 != 0) {
            do {
                var_s0_2 = var_s1_2;
                if (var_s1_2 >= 0x4001) {
                    var_s0_2 = 0x4000;
                }
                osInvalDCache(var_s2_2, var_s0_2);
                osPiStartDma(&sp20, 0, 0, var_s3_2, var_s2_2, (u32) var_s0_2, &B_8019D158_usa);
                osRecvMesg(&B_8019D158_usa, &sp38, 1);
                var_s3_2 += var_s0_2;
                var_s1_2 -= var_s0_2;
                var_s2_2 += var_s0_2;
            } while (var_s1_2 != 0);
            var_a0 = arg0 & 0xFFFF;
        }
        if (var_a0 == 0) {
            var_v1 = B_8018A6D8_usa;
            var_v0 = arg1 & 0xFFFF;
        } else if (var_a0 < 2U) {
            var_v1 = B_8018A6DC_usa;
            var_v0 = arg1 & 0xFFFF;
        } else {
            var_v0 = arg1 & 0xFFFF;
            if (var_a0 < 0x15U) {
                var_v1 = B_8018A6E4_usa;
            } else {
                var_v1 = B_8018A6E8_usa;
            }
        }
        *(&B_8018A6FC_usa + (var_v0 * 0x10)) = var_v1;
    } else {
        *(&B_8018A6FC_usa + (temp_v0 * 0x10)) = 0;
    }
    temp_a1 = temp_s6->unk_10;
    if (temp_a1 != NULL) {
        temp_s0 = (arg1 & 0xFFFF) * 0x10;
        *(&B_8018A6F8_usa + temp_s0) = *(&B_8018A700_usa + temp_s0);
        *(&B_8018A704_usa + temp_s0) = temp_a1;
        MusPtrBankInitialize(*(&B_8018A6F8_usa + temp_s0), temp_a1);
        temp_a0_2 = *(&B_8018A6FC_usa + temp_s0);
        if (temp_a0_2 != NULL) {
            MusFxBankInitialize(temp_a0_2);
            MusFxBankSetPtrBank(*(&B_8018A6FC_usa + temp_s0), *(&B_8018A6F8_usa + temp_s0));
        }
    }
}
#endif
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", LoadSFXBank);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002620_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002684_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002694_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800026A0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800026C0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000272C_usa);
#endif

#if VERSION_USA
#if 0
extern UNK_TYPE B_8016F2B0_usa;
extern void *B_8018A6B0_usa;
extern void *B_8018A6B4_usa;

void func_8000274C_usa(void) {
    s16 var_a1;

    for (var_a1 = 0; var_a1 < 2; var_a1++) {
        B_8018A748_usa[var_a1].unk_04 = 0;
        B_8018A748_usa[var_a1].unk_08 = &B_8016F2B0_usa;
        B_8018A748_usa[var_a1].unk_10 = 0;
        B_8018A748_usa[var_a1].unk_14 = 0;
        B_8018A748_usa[var_a1].unk_18 = 0;
        B_8018A748_usa[var_a1].unk_1C = 0;
        B_8018A748_usa[var_a1].unk_24 = 0;
    }

    B_8018A748_usa[0].unk_0C = B_8018A6B0_usa;
    B_8018A748_usa[1].unk_0C = B_8018A6B4_usa;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000274C_usa);
#endif
#endif

#if VERSION_USA
// InitAudio?
void func_800027FC_usa(void) {
    s32 i;

    B_801C7BAC_usa = func_80002054_usa();
    func_80001B10_usa();
    func_8000222C_usa();
    func_8000274C_usa();
    func_80001D60_usa(0x20, 0U);
    func_80001D60_usa(0x21, 1U);
    B_8018A6C0_usa = B_8018A6F8_usa;

    for (i = 0; i < 2; i++) {
        func_80003760_usa(i, 0x80, 0x80);
    }
}
#endif

#if VERSION_USA
void SetAudioSystemMixer(s16 arg0) {
    if (!arg0) {
        D_800B3AF8_usa = 0;
    } else {
        D_800B3AF8_usa = 1;
    }
}
#endif

#if VERSION_USA
struct song_t *func_800028B8_usa(s32 index) {
    return B_8018A748_usa[index].song_addr;
}
#endif

#if VERSION_USA
void func_800028D8_usa(s32 arg0) {
    if (B_8018A748_usa[D_800B3AE4_usa].unk_1C != 0) {
        MusHandleStop(B_8018A748_usa[D_800B3AE4_usa].unk_04, D_800B3AFA_usa);
    }

    MusPtrBankSetSingle(B_8018A748_usa[arg0].unk_08);
    B_8018A748_usa[arg0].unk_04 = MusStartSong(B_8018A748_usa[arg0].song_addr);
    B_8018A748_usa[arg0].unk_28 = 0;
    B_8018A748_usa[arg0].unk_2C = 0;
    MusHandleSetVolume(B_8018A748_usa[arg0].unk_04, 0);
    D_800B3AFC_usa[arg0] = B_8018A748_usa[arg0].unk_26;
    func_80003054_usa(arg0, D_800B3AFC_usa[arg0], D_800B3AFA_usa, 0);
    B_8018A748_usa[arg0].unk_1C = 1;
    last_song_handle = B_8018A748_usa[arg0].unk_04;
}
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/sound", RO_STR_800C2FD8_usa);
#endif

#if VERSION_USA
INCLUDE_RODATA("asm/usa/nonmatchings/main/sound", RO_STR_800C2FF0_usa);
#endif

#if VERSION_USA
extern const char RO_STR_800C2FD8_usa[];
extern const char RO_STR_800C2FF0_usa[];

// PlaySong?
INLINE s32 func_80002A10_usa(s32 arg0) {
    if (arg0 < 0) {
        osSyncPrintf(RO_STR_800C2FD8_usa, arg0);
        arg0 = 0;
    }
    if (arg0 >= 2) {
        osSyncPrintf(RO_STR_800C2FF0_usa, arg0, 1);
        arg0 = 0;
    }
    if ((B_8018A748_usa[arg0].unk_1C != 1) && (B_8018A6F0_usa < 0x1B) && (D_800B3AEC_usa != arg0)) {
        func_800028D8_usa(arg0);
        D_800B3AEC_usa = arg0;
        D_800B3AE4_usa = arg0;
        return last_song_handle;
    }

    return last_song_handle;
}
#endif

#if VERSION_USA
musHandle func_80002AE8_usa(s32 index, s32 volscale, s32 panscale, s32 temscale) {
    if ((B_8018A748_usa[index].unk_1C != 1) && (B_8018A6F0_usa < 0x1B) && (D_800B3AEC_usa != index)) {
        MusHandleStop(B_8018A748_usa[D_800B3AE4_usa].unk_04, D_800B3AFA_usa);
        MusPtrBankSetSingle(B_8018A748_usa[index].unk_08);
        B_8018A748_usa[index].unk_04 = func_8008B310_usa(B_8018A748_usa[index].song_addr, volscale, panscale, temscale);
        B_8018A748_usa[index].unk_28 = volscale;
        B_8018A748_usa[index].unk_2C = volscale;
        B_8018A748_usa[index].unk_1C = 1;
        D_800B3AEC_usa = index;
        D_800B3AE4_usa = index;
        last_song_handle = B_8018A748_usa[index].unk_04;
        return last_song_handle;
    }
    return last_song_handle;
}
#endif

#if VERSION_USA
int func_80002C50_usa(musHandle handle) {
    D_800B3AEC_usa = -1;
    return MusHandleStop(handle, 0);
}
#endif

#if VERSION_USA
int FadeOutTuneBuffer(s32 index, int speed) {
    return MusHandleStop(B_8018A748_usa[index].unk_04, speed);
}
#endif

#if VERSION_USA
int FadeOutSong(musHandle handle, int speed) {
    D_800B3AEC_usa = -1;
    return MusHandleStop(handle, speed);
}
#endif

#if VERSION_USA
s16 func_80002CE0_usa(musHandle handle) {
    return MusHandleAsk(handle);
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002D04_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002D30_usa);
#endif

#if VERSION_USA
void func_80002D5C_usa(void) {
    D_800B3AEC_usa = -1;
    MusStop(MUSFLAG_SONGS, 0);
}
#endif

#if VERSION_USA
void func_80002D8C_usa(s16 speed) {
    if (B_800CF2A0_usa < 327.67) {
        speed = 0;
    }
    D_800B3AEC_usa = -1;
    MusStop(MUSFLAG_SONGS, speed);
}
#endif

#if VERSION_USA
void func_80002DE8_usa(void) {
    MusStop(MUSFLAG_EFFECTS, 0);
}
#endif

#if VERSION_USA
void func_80002E0C_usa(s16 speed) {
    MusStop(MUSFLAG_EFFECTS, speed);
}
#endif

#if VERSION_USA
void func_80002E34_usa(s32 volume) {
    s32 var_s0 = volume;

    if (var_s0 > 0x7FFFU) {
        var_s0 = 0x7FFF;
    }
    B_800CF2A0_usa = var_s0;
    MusSetMasterVolume(MUSFLAG_SONGS, B_800CF2A0_usa);
}
#endif

#if VERSION_USA
void func_80002E70_usa(s32 volume) {
    s32 var_s0 = volume;

    if (var_s0 > 0x7FFFU) {
        var_s0 = 0x7FFF;
    }
    MusSetMasterVolume(MUSFLAG_EFFECTS, var_s0);
    B_801C6EF6_usa = var_s0;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002EB8_usa);
#endif

#if VERSION_USA
int SetSongTempo(musHandle handle, int tempo) {
    return MusHandleSetTempo(handle, tempo);
}
#endif

#if VERSION_USA
int func_80002F68_usa(musHandle handle, int pan) {
    return MusHandleSetPan(handle, pan);
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002F88_usa);
#endif

#if VERSION_USA
void SetSongCrossFadeVolume(s16 arg0, s16 arg1) {
    B_8018A748_usa[arg1].unk_26 = arg0;
    D_800B3AFC_usa[arg1] = arg0;
}
#endif

#if VERSION_USA
#if 0
void func_80002FD0_usa(musHandle handle, s16 arg1, s16 arg2, s32 arg3) {
    s32 var_a0;
    s32 var_v0;

    for (var_a0 = 0; var_a0 < 2; var_a0++){
        var_v0 = var_a0;
        if (B_8018A748_usa[var_a0].unk_04 == handle) {
            break;
        }
        var_v0 = -1;
    }

    if (var_v0 < 0) {
        osSyncPrintf(" NOT A TUNEBUFFER SONG! \n");
        return;
    }
    func_80003054_usa(var_v0, arg1, arg2, arg3);
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80002FD0_usa);
#endif
#endif

#if VERSION_USA
void func_80003054_usa(s16 arg0, s16 arg1, s16 arg2, s32 arg3) {
    B_8018A748_usa[arg0].unk_2C = arg1;
    B_8018A748_usa[arg0].unk_34 = arg3;
    B_8018A748_usa[arg0].unk_30 = (arg1 - B_8018A748_usa[arg0].unk_28) / arg2;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800030D0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800030F0_usa);
#endif

#if VERSION_USA
extern int D_800B3AF0_usa; // priority
extern int D_800B3AF4_usa; // restartflag

musHandle PlaySFX(int number, int volume, int pan) {
    if (number > B_801F9CC4_usa) {
        number = 0;
    }

    if (D_800B3AF8_usa == 0) {
        pan = 0x80;
    }

    if (B_8018A6EC_usa <= D_800B3AD0_usa) {
        B_8018A6EE_usa = MusAsk(MUSFLAG_EFFECTS);
        if (D_800B3AD2_usa >= B_8018A6EE_usa) {
            D_800B3ADC_usa = MusStartEffect2(number, volume, pan, D_800B3AF4_usa, D_800B3AF0_usa);
            return D_800B3ADC_usa;
        }
    }

    return -1;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000337C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000339C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", SetFrequencySFX);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800033DC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80003458_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80003484_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800034B4_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800034EC_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_8000353C_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800036D0_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800036F0_usa);
#endif

#if VERSION_USA
#if 0
extern ? B_8018A7BC_usa;
extern ? B_8018A7C0_usa;

void func_80003760_usa(s16 arg0, s16 arg1, s16 arg2) {
    s16 var_a2;
    s32 temp_v0;

    var_a2 = arg2;
    if (D_800B3AF8_usa == 0) {
        var_a2 = 0x80;
    }
    temp_v0 = (s32) (arg0 << 0x10) >> 0xC;
    *(&B_8018A7BC_usa + temp_v0) = (s32) arg1;
    *(&B_8018A7C0_usa + temp_v0) = (s32) var_a2;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80003760_usa);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800037A8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800037E8_usa);
#endif

#if VERSION_USA
void func_800038E4_usa(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(B_8018A748_usa); i++) {
        if (B_8018A748_usa[i].unk_1C != 2) {
            if (MusHandleAsk(B_8018A748_usa[i].unk_04) == 0) {
                if (B_8021B968_usa == 0) {
                    B_8018A748_usa[i].unk_1C = 0;
                } else {
                    B_8018A748_usa[i].unk_24 = 1;
                }
            } else {
                B_8018A748_usa[i].unk_1C = 1;
                B_8018A748_usa[i].unk_24 = 0;
            }
        }
    }

    if (B_8021B968_usa == 1) {
        B_8021B968_usa = 0;
    }
}
#endif

#if VERSION_USA
#if 0
typedef struct struct_8021BA7C_usa {
    /* 0x0 */ UNK_TYPE1 unk_0[0x1];
    /* 0x1 */ u8 unk_1;
    /* 0x2 */ u8 unk_2;
    /* 0x3 */ u8 unk_3;
} struct_8021BA7C_usa; // size >= ?


s16 func_80001D60_usa(s32 arg0, s32 arg1);
// ? func_800028D8_usa(s32);                           /* extern */
// ? func_800030F0_usa();                              /* extern */
// ? func_800037E8_usa();                              /* extern */
// ? func_800038E4_usa();                              /* extern */
extern s16 B_8018A6EC_usa;
extern u16 B_8018A6EE_usa;
extern u8 B_8018A7B8_usa[];
extern s32 B_801AB7E0_usa;
extern s16 B_801AB7E2_usa;
extern s32 B_801C7154_usa;
extern s32 B_8021B960_usa;
extern struct_8021BA7C_usa *B_8021BA7C_usa;
extern s32 B_8021DF48_usa;
extern s16 D_800B3AFA_usa;
extern s16 D_800B3AFC_usa[];
extern const char RO_STR_800C2FD8_usa[];
extern const char RO_STR_800C2FF0_usa[];

void AudioUpdate(void) {
    s16 var_a0;
    s16 var_a1;
    s32 temp_v1;
    s32 var_s0;
    s32 var_v0_2;
    u8 temp_a0;

    B_8018A6EE_usa = MusAsk(1U);
    B_8018A6F0_usa = MusAsk(2U);
    B_8018A6EC_usa = B_8018A6EE_usa + B_8018A6F0_usa;

    func_800037E8_usa();

    var_a0 = 0;
    while (var_a0 < 2) {
        temp_v1 = var_a0 * 0x10;
        if (*(B_8018A7B8_usa + temp_v1) != 0) {
            *(B_8018A7B8_usa + temp_v1) = 0;
        }
        var_a0 = var_a0 + 1;
    }

    if (B_801C7154_usa != 0) {
        var_v0_2 = 1;
        if (B_8018A748_usa[B_801AB7E0_usa].unk_1C == 1) {
            var_v0_2 = 0;
        }

        if ((var_v0_2 != 0) && (func_80001D60_usa(B_8021B960_usa, B_801AB7E2_usa) >= 0)) {
            B_801C7154_usa = 0;
            if (B_8021DF48_usa == 0) {
                temp_a0 = B_8021BA7C_usa->unk_1;
                D_800B3AFA_usa = 0;
                B_8018A748_usa[B_801AB7E2_usa].unk_26 = temp_a0;
                D_800B3AFC_usa[B_801AB7E2_usa] = temp_a0;
                var_s0 = B_801AB7E0_usa;
                if (var_s0 < 0) {
                    osSyncPrintf(RO_STR_800C2FD8_usa, var_s0);
                    var_s0 = 0;
                }

                if (var_s0 < 2) {
                    osSyncPrintf(&RO_STR_800C2FF0_usa, var_s0, 1);
                    var_s0 = 0;
                }
                if (B_8018A748_usa[var_s0].unk_1C != 1) {
                    goto block_23;
                }
            } else {

                B_8018A748_usa[B_801AB7E2_usa].unk_26 = B_8021BA7C_usa->unk_1;
                D_800B3AFC_usa[B_801AB7E2_usa] = B_8021BA7C_usa->unk_1;
                var_a1 = 0x1E;
                if (B_8021DF48_usa == 1) {
                    var_a1 = 0x3C;
                }
                D_800B3AFA_usa = var_a1;
                var_s0 = B_801AB7E0_usa;
                if (var_s0 < 0) {
                    osSyncPrintf(RO_STR_800C2FD8_usa, var_s0);
                    var_s0 = 0;
                }

                if (var_s0 < 2) {
                    osSyncPrintf(&RO_STR_800C2FF0_usa, var_s0, 1);
                    var_s0 = 0;
                }
                if (B_8018A748_usa[var_s0].unk_1C != 1) {
block_23:
                    if ((B_8018A6F0_usa < 0x1B) && (D_800B3AEC_usa != var_s0)) {
                        func_800028D8_usa(var_s0);
                        D_800B3AEC_usa = var_s0;
                        D_800B3AE4_usa = var_s0;
                    }
                }
            }

            MusHandleSetPan(last_song_handle, B_8021BA7C_usa->unk_2);
            MusHandleSetTempo(last_song_handle, B_8021BA7C_usa->unk_3);
        }
    }

    func_800030F0_usa();
    func_800038E4_usa();
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", AudioUpdate);
#endif
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80003CE8_usa);
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_80003E00_usa);
#endif
