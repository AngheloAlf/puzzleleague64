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
    /* 0x04 */ musHandle unk_04; // handle
    /* 0x08 */ u8 *unk_08;
    /* 0x0C */ struct song_t *song_addr;
    /* 0x10 */ UNK_TYPE4 unk_10;
    /* 0x14 */ UNK_TYPE4 unk_14;
    /* 0x18 */ UNK_TYPE4 unk_18;
    /* 0x1C */ s16 unk_1C;
    /* 0x1E */ UNK_TYPE1 unk_1E[0x2];
    /* 0x20 */ UNK_TYPE1 unk_20[0x4];
    /* 0x24 */ UNK_TYPE2 unk_24;
    /* 0x26 */ UNK_TYPE2 unk_26;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 unk_30;
    /* 0x34 */ struct_8018A748_usa_callback *callback;
} struct_8018A748_usa; // size = 0x38

typedef struct struct_8018A6F8_usa {
    /* 0x0 */ void *unk_0;
    /* 0x4 */ void *unk_4;
    /* 0x8 */ void *unk_8;
    /* 0xC */ RomOffset unk_C;
} struct_8018A6F8_usa; // size = 0x10

extern s32 B_800CF2A0_usa;

// buffers
extern u8 B_800CF2B0_usa[];
extern u8 B_8016F2B0_usa[];
extern u8 B_801792B0_usa[];
extern u8 B_80182AB0_usa[];
extern u8 B_801842B0_usa[];
extern u8 B_801876B0_usa[];
extern u8 B_80188EB0_usa[];

extern struct song_t *B_8018A6B0_usa;
extern struct song_t *B_8018A6B4_usa;
extern UNK_PTR B_8018A6B8_usa;
extern UNK_PTR B_8018A6BC_usa;
extern UNK_TYPE **B_8018A6C0_usa;
extern UNK_PTR B_8018A6C4_usa;
extern UNK_PTR B_8018A6C8_usa;
extern UNK_PTR B_8018A6CC_usa;
extern UNK_PTR B_8018A6D0_usa;
extern UNK_PTR B_8018A6D8_usa;
extern UNK_PTR B_8018A6DC_usa;
extern s32 B_8018A6E0_usa;
extern UNK_PTR B_8018A6E4_usa;
extern UNK_PTR B_8018A6E8_usa;
extern s16 B_8018A6EC_usa;
extern s16 B_8018A6EE_usa;
extern s16 B_8018A6F0_usa;

extern struct_8018A6F8_usa B_8018A6F8_usa[5];

extern struct_8018A748_usa B_8018A748_usa[2];
extern s32 B_8018A7B8_usa[2][4];

// non static
extern int B_801C7BAC_usa;
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

typedef void(callback_800B3B00_usa)(UNK_TYPE arg0);
extern callback_800B3B00_usa *D_800B3B00_usa;

#if VERSION_USA
void func_80001B10_usa(void) {
    D_800B3AEC_usa = -1;
#if VERSION_USA || VERSION_EUR
    D_800B3AF8_usa = 1;
#endif
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
    D_800B3B00_usa = NULL;
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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80001B10_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80001B10_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80001B10_usa);
#endif

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

s16 func_80001D60_usa(s32 arg0, s16 arg1) {
    arg1 = ((u16)arg1 >= 2) ? 0 : arg1;

    if (!IsTuneBufferFree(arg1)) {
        func_80002C50_usa(B_8018A748_usa[arg1].unk_04);
        return -1;
    }

    B_8018A748_usa[arg1].unk_00 = arg0;
    if (arg0 < ARRAY_COUNTU(D_800B5330_usa) - 1) {
        RomOffsetPair *pair = &D_800B5330_usa[arg0];

        func_80001F68_usa(B_8016F2B0_usa, arg1);
        func_80001F90_usa(pair->start, pair->end - pair->start, arg1);
        SetSongCrossFadeVolume(BGM_INIT_TABLE[arg0].vol, arg1);
    }
    if (arg0 == ARRAY_COUNTU(D_800B5330_usa) - 1) {
        RomOffsetPair *pair = &D_800B5330_usa[arg0];

        func_80001F68_usa(B_801842B0_usa, arg1);
        func_80001F90_usa(pair->start, pair->end - pair->start, arg1);
        SetSongCrossFadeVolume(BGM_INIT_TABLE[arg0].vol, arg1);
    }
    return arg1;
}

#if VERSION_USA
// duplicate of func_80001E98_usa, but the inlines require s32 instead of s16
STATIC_INLINE s32 inlined_func1(musHandle handle) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(B_8018A748_usa); i++) {
        if (B_8018A748_usa[i].unk_04 == handle) {
            return i;
        }
    }

    return -1;
}
#endif

s16 func_80001E98_usa(musHandle handle) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(B_8018A748_usa); i++) {
        if (B_8018A748_usa[i].unk_04 == handle) {
            return i;
        }
    }

    return -1;
}

s16 func_80001ED8_usa(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(B_8018A748_usa); i++) {
        if (B_8018A748_usa[i].unk_1C != 1) {
            return i;
        }
    }

    return -1;
}

s16 IsTuneBufferFree(s32 index) {
    return B_8018A748_usa[index].unk_1C != 1;
}

void func_80001F40_usa(struct song_t *arg0, s16 index) {
    B_8018A748_usa[index].song_addr = arg0;
}

void func_80001F68_usa(void *arg0, s16 index) {
    B_8018A748_usa[index].unk_08 = arg0;
}

void func_80001F90_usa(RomOffset segmentRom, size_t segmentSize, s16 index) {
    func_80001CAC_usa(segmentRom, func_800028B8_usa(index), segmentSize);
}

#if VERSION_USA
int func_80002054_usa(void) {
    musConfig sp20;

    func_80001CAC_usa(D_800B5570_usa[3].unk_00, B_8016F2B0_usa, D_800B5570_usa[3].unk_04 - D_800B5570_usa[3].unk_00);
    func_80001CAC_usa(D_800B5570_usa[2].unk_00, B_801842B0_usa, D_800B5570_usa[2].unk_04 - D_800B5570_usa[2].unk_00);

    sp20.channels = 0x28;
    sp20.sched = &B_8021AAA0_usa;
    sp20.thread_priority = THREAD_PRI_LIBMUS;
    sp20.heap = B_800CF2B0_usa;
    sp20.heap_length = 0xA0000;
    sp20.ptr = B_8016F2B0_usa;
    sp20.syn_output_rate = 22050;
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
void func_8000222C_usa(void) {
    B_8018A6F8_usa[0].unk_8 = B_801792B0_usa;
    B_8018A6F8_usa[0].unk_0 = B_801792B0_usa;
    B_8018A6F8_usa[0].unk_4 = B_8018A6D8_usa;
    LoadSFXBank(0, 0);

    B_8018A6F8_usa[1].unk_8 = B_80182AB0_usa;
    B_8018A6F8_usa[1].unk_0 = B_80182AB0_usa;
    B_8018A6F8_usa[1].unk_4 = B_8018A6DC_usa;
    LoadSFXBank(1, 1);

    B_8018A6F8_usa[2].unk_8 = B_801842B0_usa;
    B_8018A6F8_usa[2].unk_0 = B_801842B0_usa;
    B_8018A6F8_usa[2].unk_4 = 0;
    LoadSFXBank(2, 2);

    B_8018A6F8_usa[3].unk_8 = B_801876B0_usa;
    B_8018A6F8_usa[3].unk_0 = B_801876B0_usa;
    B_8018A6F8_usa[3].unk_4 = B_8018A6E4_usa;
    LoadSFXBank(4, 3);

    B_8018A6F8_usa[4].unk_8 = B_80188EB0_usa;
    B_8018A6F8_usa[4].unk_0 = B_80188EB0_usa;
    B_8018A6F8_usa[4].unk_4 = B_8018A6E8_usa;
    LoadSFXBank(0x16, 4);

    func_80002620_usa(0);
}
#endif

#if VERSION_USA
void *LoadSFXBank(u16 arg0, u16 arg1) {
    struct_800B55A0_usa *temp_s6;
    u32 temp_a1;

    if (arg1 >= ARRAY_COUNTU(B_8018A6F8_usa)) {
        osSyncPrintf("invalid index baka! \n");
        return NULL;
    }

    temp_s6 = &D_800B5570_usa[arg0];

    if (temp_s6->unk_00 != 0) {
        func_80001CAC_usa(temp_s6->unk_00, B_8018A6F8_usa[arg1].unk_8, temp_s6->unk_04 - temp_s6->unk_00);
    }

    if (temp_s6->unk_08 != 0) {
        func_80001CAC_usa(temp_s6->unk_08, B_8018A6F8_usa[arg1].unk_4, temp_s6->unk_0C - temp_s6->unk_08);

        if (arg0 == 0) {
            B_8018A6F8_usa[arg1].unk_4 = B_8018A6D8_usa;
        } else if (arg0 < 2) {
            B_8018A6F8_usa[arg1].unk_4 = B_8018A6DC_usa;
        } else if (arg0 < 0x15) {
            B_8018A6F8_usa[arg1].unk_4 = B_8018A6E4_usa;
        } else {
            B_8018A6F8_usa[arg1].unk_4 = B_8018A6E8_usa;
        }
    } else {
        B_8018A6F8_usa[arg1].unk_4 = NULL;
    }

    temp_a1 = temp_s6->unk_10;
    if (temp_a1 != 0) {
        B_8018A6F8_usa[arg1].unk_0 = B_8018A6F8_usa[arg1].unk_8;
        B_8018A6F8_usa[arg1].unk_C = temp_a1;
        MusPtrBankInitialize(B_8018A6F8_usa[arg1].unk_0, (void *)B_8018A6F8_usa[arg1].unk_C);

        if (B_8018A6F8_usa[arg1].unk_4 != NULL) {
            MusFxBankInitialize(B_8018A6F8_usa[arg1].unk_4);
            MusFxBankSetPtrBank(B_8018A6F8_usa[arg1].unk_4, B_8018A6F8_usa[arg1].unk_0);
        }
    }

    return B_8018A6F8_usa[arg1].unk_0;
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80002054_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_8000222C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", LoadSFXBank);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002118_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_800022F0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_8000240C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002118_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_800022F0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_8000240C_ger);
#endif

void func_80002620_usa(s16 arg0) {
    if (B_8018A6F8_usa[arg0].unk_4 != NULL) {
        MusFxBankSetCurrent(B_8018A6F8_usa[arg0].unk_4);
        B_801F9CC4_usa = MusFxBankNumberOfEffects(B_8018A6F8_usa[arg0].unk_4) - 1;
    }
}

#if VERSION_USA
bool func_80002684_usa(void) {
    return D_800B3AE6_usa == 0;
}
#endif

#if VERSION_USA
s16 func_80002694_usa(s32 arg0 UNUSED, s16 arg1) {
    return arg1;
}
#endif

#if VERSION_USA
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800026A0_usa);
#endif

#if VERSION_USA
void func_800026C0_usa(s32 arg0) {
    D_800B3AE6_usa = arg0;
    MusPtrBankSetSingle(B_8018A6C0_usa);
    D_800B3AE0_usa = MusStartSong((arg0 == 0) ? B_8018A6B8_usa : B_8018A6BC_usa);
}
#endif

#if VERSION_USA
int func_8000272C_usa(musHandle handle, int speed) {
    return MusHandleStop(handle, speed);
}
#endif

#if VERSION_USA
void func_8000274C_usa(void) {
    s32 var_a1;

    for (var_a1 = 0; var_a1 < ARRAY_COUNT(B_8018A748_usa); var_a1++) {
        B_8018A748_usa[var_a1].unk_04 = 0;
        B_8018A748_usa[(s16)var_a1].unk_08 = B_8016F2B0_usa;
        B_8018A748_usa[var_a1].unk_10 = 0;
        B_8018A748_usa[var_a1].unk_14 = 0;
        B_8018A748_usa[var_a1].unk_18 = 0;
        B_8018A748_usa[var_a1].unk_1C = 0;
        B_8018A748_usa[var_a1].unk_24 = 0;
    }

    B_8018A748_usa[0].song_addr = B_8018A6B0_usa;
    B_8018A748_usa[1].song_addr = B_8018A6B4_usa;
}
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
    B_8018A6C0_usa = B_8018A6F8_usa[0].unk_0;

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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80002684_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80002694_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800026A0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800026C0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800027EC_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_8000274C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800027FC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", SetAudioSystemMixer);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002748_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002758_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002764_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002784_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_800027F0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002810_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_800027FC_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002950_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002748_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002758_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002764_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002784_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_800027F0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002810_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_800027FC_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002950_ger);
#endif

struct song_t *func_800028B8_usa(s32 index) {
    return B_8018A748_usa[index].song_addr;
}

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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800028D8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80002A10_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80002AE8_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_8000299C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002AD4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002BAC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_8000299C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002AD4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002BAC_ger);
#endif

int func_80002C50_usa(musHandle handle) {
    D_800B3AEC_usa = -1;
    return MusHandleStop(handle, 0);
}

#if VERSION_USA
int FadeOutTuneBuffer(s32 index, int speed) {
    return MusHandleStop(B_8018A748_usa[index].unk_04, speed);
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", FadeOutTuneBuffer);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002D40_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002D40_ger);
#endif

int FadeOutSong(musHandle handle, int speed) {
    D_800B3AEC_usa = -1;
    return MusHandleStop(handle, speed);
}

s16 func_80002CE0_usa(musHandle handle) {
    return MusHandleAsk(handle);
}

#if VERSION_USA
s16 func_80002D04_usa(void) {
    B_8018A6F0_usa = MusAsk(MUSFLAG_SONGS);

    return B_8018A6F0_usa;
}
#endif

#if VERSION_USA
s16 func_80002D30_usa(void) {
    B_8018A6EE_usa = MusAsk(MUSFLAG_EFFECTS);

    return B_8018A6EE_usa;
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80002D04_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80002D30_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002DC8_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002DF4_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002DC8_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002DF4_ger);
#endif

void func_80002D5C_usa(void) {
    D_800B3AEC_usa = -1;
    MusStop(MUSFLAG_SONGS, 0);
}

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/sound", RO_800C3508_eur);
#endif

#if VERSION_EUR
INCLUDE_RODATA("asm/eur/nonmatchings/main/sound", RO_800C3520_eur);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/sound", RO_800C1D38_fra);
#endif

#if VERSION_FRA
INCLUDE_RODATA("asm/fra/nonmatchings/main/sound", RO_800C1D50_fra);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/sound", RO_800B8CF8_ger);
#endif

#if VERSION_GER
INCLUDE_RODATA("asm/ger/nonmatchings/main/sound", RO_800B8D10_ger);
#endif

void func_80002D8C_usa(s16 speed) {
    if (B_800CF2A0_usa < 327.67) {
        speed = 0;
    }
    D_800B3AEC_usa = -1;
    MusStop(MUSFLAG_SONGS, speed);
}

void func_80002DE8_usa(void) {
    MusStop(MUSFLAG_EFFECTS, 0);
}

void func_80002E0C_usa(s16 speed) {
    MusStop(MUSFLAG_EFFECTS, speed);
}

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
void func_80002EB8_usa(musHandle arg0, s32 arg1) {
    s32 var_v1;

    if (arg1 > 0x100U) {
        arg1 = 0x100;
    }

    var_v1 = inlined_func1(arg0);

    if (var_v1 >= 0) {
        B_8018A748_usa[var_v1].unk_2C = B_8018A748_usa[var_v1].unk_28 = arg1;
    }
    MusHandleSetVolume(arg0, arg1);
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80002E34_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80002E70_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80002EB8_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002E34_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002E70_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80002F7C_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002E34_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002E70_usa);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80002F7C_ger);
#endif

int SetSongTempo(musHandle handle, int tempo) {
    return MusHandleSetTempo(handle, tempo);
}

int func_80002F68_usa(musHandle handle, int pan) {
    return MusHandleSetPan(handle, pan);
}

void func_80002F88_usa(s16 arg0) {
    D_800B3AFA_usa = arg0;
}

#if VERSION_USA
void SetSongCrossFadeVolume(s16 arg0, s16 arg1) {
    B_8018A748_usa[arg1].unk_26 = arg0;
    D_800B3AFC_usa[arg1] = arg0;
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", SetSongCrossFadeVolume);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", SetSongCrossFadeVolume);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", SetSongCrossFadeVolume);
#endif

#if VERSION_USA
void func_80002FD0_usa(musHandle handle, s16 arg1, s16 arg2, struct_8018A748_usa_callback *arg3) {
    s32 var_v0 = inlined_func1(handle);

    if (var_v0 < 0) {
        osSyncPrintf(" NOT A TUNEBUFFER SONG! \n");
        return;
    }

    func_80003054_usa(var_v0, arg1, arg2, arg3);
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80002FD0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003094_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003094_ger);
#endif

#if VERSION_USA
void func_80003054_usa(s16 arg0, s16 arg1, s16 arg2, struct_8018A748_usa_callback *callback) {
    B_8018A748_usa[arg0].unk_2C = arg1;
    B_8018A748_usa[arg0].callback = callback;
    B_8018A748_usa[arg0].unk_30 = (arg1 - B_8018A748_usa[arg0].unk_28) / arg2;
}
#endif

#if VERSION_USA
int func_800030D0_usa(musHandle handle, int speed) {
    return MusHandleStop(handle, speed);
}
#endif

#if VERSION_USA
void func_800030F0_usa(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(B_8018A748_usa); i++) {
        s16 temp = B_8018A748_usa[i].unk_28;
        s16 temp_fv1 = (s32)B_8018A748_usa[i].unk_2C;

        if (temp == temp_fv1) {
            if (B_8018A748_usa[i].callback != NULL) {
                B_8018A748_usa[i].callback(B_8018A748_usa[i].unk_04, 0);
            }
        } else {
            B_8018A748_usa[i].unk_28 += B_8018A748_usa[i].unk_30;

            if (B_8018A748_usa[i].unk_30 > 0.0f) {
                if (temp_fv1 < B_8018A748_usa[i].unk_28) {
                    B_8018A748_usa[i].unk_28 = temp_fv1;
                }
            } else {
                if (B_8018A748_usa[i].unk_28 < temp_fv1) {
                    B_8018A748_usa[i].unk_28 = temp_fv1;
                }
            }

            temp = (s32)B_8018A748_usa[i].unk_28;

            MusHandleSetVolume(B_8018A748_usa[i].unk_04, temp);
            if (B_8018A748_usa[i].unk_28 == temp_fv1) {
                if (B_8018A748_usa[i].callback != NULL) {
                    B_8018A748_usa[i].callback(B_8018A748_usa[i].unk_04, 0);
                }
            }
        }
    }
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80003054_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80003190_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800030F0_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003118_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003194_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_800031B4_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003118_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003194_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_800031B4_ger);
#endif

extern int D_800B3AF0_usa; // priority
extern int D_800B3AF4_usa; // restartflag

INLINE musHandle PlaySFX(int number, int volume, int pan) {
    if (number > B_801F9CC4_usa) {
        number = 0;
    }

    if (D_800B3AF8_usa == 0) {
        pan = 0x80;
    }

    if (B_8018A6EC_usa > D_800B3AD0_usa) {
        return (musHandle)-1;
    }

    B_8018A6EE_usa = MusAsk(MUSFLAG_EFFECTS);
    if (D_800B3AD2_usa < B_8018A6EE_usa) {
        return (musHandle)-1;
    }

    D_800B3ADC_usa = MusStartEffect2(number, volume, pan, D_800B3AF4_usa, D_800B3AF0_usa);
    return D_800B3ADC_usa;
}

#if VERSION_USA
int func_8000337C_usa(musHandle handle, int speed) {
    return MusHandleStop(handle, speed);
}
#endif

#if VERSION_USA
int func_8000339C_usa(musHandle handle, int speed) {
    return MusHandleStop(handle, speed);
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_8000343C_eur);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_8000345C_eur);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003440_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003460_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003440_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003460_ger);
#endif

int SetFrequencySFX(musHandle handle, float offset) {
    return MusHandleSetFreqOffset(handle, offset);
}

#if VERSION_USA
int func_800033DC_usa(musHandle handle, s16 arg1, s16 arg2) {
    f32 temp1 = arg1;
    f32 temp2 = arg2;

    temp1 -= 64.0;
    temp2 /= 127.0;

    return MusHandleSetFreqOffset(handle, temp1 + temp2);
}
#endif

#if VERSION_USA
int func_80003458_usa(musHandle handle, int volume) {
    if (volume > 0x100U) {
        volume = 0x100U;
    }

    return MusHandleSetVolume(handle, volume);
}
#endif

#if VERSION_USA
int func_80003484_usa(musHandle handle, int pan) {
    if (D_800B3AF8_usa == 0) {
        pan = 0x80;
    }
    return MusHandleSetPan(handle, pan);
}
#endif

#if VERSION_USA
INLINE s16 func_800034B4_usa(f32 arg0, f32 arg1) {
    f32 temp = (arg1 - arg0) * (65536.0 / arg1);

    return ((s32)temp >> 9);
}
#endif

#if VERSION_USA
INLINE s32 func_800034EC_usa(f32 arg0) {
    if (arg0 > 180.0) {
        arg0 = arg0 - 180.0;
    } else {
        arg0 = 180.0 - arg0;
    }
    arg0 *= 64.0 / 45.0;

    return arg0;
}
#endif

#if VERSION_USA
musHandle func_8000353C_usa(int number, f32 arg1, f32 arg2, f32 arg3) {
    int volume;
    int pan;
    musHandle handle;
    f32 offset = 0.0f;

    if (arg2 <= arg1) {
        return -1;
    }

    pan = func_800034EC_usa(arg3);
    volume = func_800034B4_usa(arg1, arg2);
    handle = PlaySFX(number, volume, pan);

    if ((s32)handle >= 0) {
        MusHandleSetFreqOffset(handle, offset);
    }
    return handle;
}
#endif

#if VERSION_USA
bool func_800036D0_usa(musHandle handle) {
    return MusHandleAsk(handle) == 0;
}
#endif

#if VERSION_USA
#if NON_MATCHING
s16 func_800036F0_usa(s16 arg0, s32 arg1) {
    s32 temp_a2;
    s32 temp;

    temp_a2 = (B_801F9CC4_usa >= arg1) ? arg1 : 0;
    temp = (arg0 >= ARRAY_COUNT(B_8018A7B8_usa)) ? ARRAY_COUNT(B_8018A7B8_usa) - 1 : arg0;

    if (temp_a2 >= B_8018A7B8_usa[temp][0]) {
        B_8018A7B8_usa[temp][0] = temp_a2;
        return temp;
    }
    return -1;
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", func_800036F0_usa);
#endif
#endif

#if VERSION_USA
void func_80003760_usa(s16 arg0, s16 arg1, s16 arg2) {
    if (D_800B3AF8_usa == 0) {
        arg2 = 0x80;
    }

    B_8018A7B8_usa[arg0][1] = arg1;
    B_8018A7B8_usa[arg0][2] = arg2;
}
#endif

#if VERSION_USA
s32 func_800037A8_usa(s16 arg0, s32 arg1) {
    if ((arg0 < 0) || (B_8018A7B8_usa[arg0][0] != arg1)) {
        return -1;
    }
    return B_8018A7B8_usa[arg0][3];
}
#endif

#if VERSION_USA
void func_800037E8_usa(void) {
    s16 i;

    for (i = 0; i < ARRAY_COUNT(B_8018A7B8_usa); i++) {
        if (B_8018A7B8_usa[i][0] != 0) {
            if (B_8018A6EC_usa > D_800B3AD0_usa) {
                return;
            }

            B_8018A6EE_usa = MusAsk(1U);
            if (D_800B3AD2_usa < B_8018A6EE_usa) {
                return;
            }

            D_800B3ADC_usa = MusStartEffect2(B_8018A7B8_usa[i][0], B_8018A7B8_usa[i][1], B_8018A7B8_usa[i][2],
                                             D_800B3AF4_usa, D_800B3AF0_usa);
            B_8018A7B8_usa[i][3] = D_800B3ADC_usa;
        }
    }
}
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

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800033DC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80003458_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80003484_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800034B4_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800034EC_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_8000353C_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800036D0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800036F0_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80003760_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800037A8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800037E8_usa);
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_800038E4_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_800034A0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_8000351C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003548_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003578_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_800035B0_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003600_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003794_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_800037B4_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003824_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_8000386C_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_800038AC_fra);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_800039A8_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_800034A0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_8000351C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003548_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003578_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_800035B0_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003600_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003794_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_800037B4_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003824_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_8000386C_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_800038AC_ger);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_800039A8_ger);
#endif

extern s32 B_801AB7E0_usa;
extern s16 B_801AB7E2_usa;
extern s32 B_801C7154_usa;
extern s32 B_8021B960_usa;
extern u8 *B_8021BA7C_usa;
extern s32 B_8021DF48_usa;

#if VERSION_USA
#ifdef NON_EQUIVALENT
void AudioUpdate(void) {
    s16 var_a0;
    s32 var_s0;

    B_8018A6EE_usa = MusAsk(MUSFLAG_EFFECTS);
    B_8018A6F0_usa = MusAsk(MUSFLAG_SONGS);
    B_8018A6EC_usa = B_8018A6EE_usa + B_8018A6F0_usa;
    func_800037E8_usa();

    for (var_a0 = 0; var_a0 < 2; var_a0++) {
        if (B_8018A7B8_usa[var_a0][0] != 0) {
            B_8018A7B8_usa[var_a0][0] = 0;
        }
    }

    if (B_801C7154_usa != 0) {
        if ((B_8018A748_usa[B_801AB7E0_usa].unk_1C != 1) &&
            !(func_80001D60_usa(B_8021B960_usa, B_801AB7E2_usa) & 0x8000)) {
            B_801C7154_usa = 0;
            if (B_8021DF48_usa == 0) {
                D_800B3AFC_usa[B_801AB7E2_usa] = B_8018A748_usa[B_801AB7E2_usa].unk_26 = B_8021BA7C_usa[1];
                D_800B3AFA_usa = 0;

                var_s0 = B_801AB7E0_usa;
                if (var_s0 < 0) {
                    osSyncPrintf(RO_STR_800C2FD8_usa, var_s0);
                    var_s0 = 0;
                }

                if (var_s0 >= 2) {
                    osSyncPrintf(RO_STR_800C2FF0_usa, var_s0, 1);
                    var_s0 = 0;
                }

                if (B_8018A748_usa[var_s0].unk_1C != 1) {
                    goto block_23;
                }
            } else {
                D_800B3AFC_usa[B_801AB7E2_usa] = B_8018A748_usa[B_801AB7E2_usa].unk_26 = B_8021BA7C_usa[1];
                D_800B3AFA_usa = (B_8021DF48_usa == 1) ? 0x3C : 0x1E;

                var_s0 = B_801AB7E0_usa;
                if (var_s0 < 0) {
                    osSyncPrintf(RO_STR_800C2FD8_usa, var_s0);
                    var_s0 = 0;
                }

                if (var_s0 >= 2) {
                    osSyncPrintf(RO_STR_800C2FF0_usa, var_s0, 1);
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

            MusHandleSetPan(last_song_handle, B_8021BA7C_usa[2]);
            MusHandleSetTempo(last_song_handle, B_8021BA7C_usa[3]);
        }
    }

    func_800030F0_usa();
    func_800038E4_usa();
}
#else
INCLUDE_ASM("asm/usa/nonmatchings/main/sound", AudioUpdate);
#endif
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", AudioUpdate);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", AudioUpdate);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", AudioUpdate);
#endif

#if VERSION_USA
void func_80003CE8_usa(u16 arg0) {
    if (B_8018A748_usa->unk_08 == B_801842B0_usa) {
        D_800B3AEC_usa = -1;
        MusHandleStop(B_8018A748_usa->unk_04, 3);

        while ((MusHandleAsk(B_8018A748_usa->unk_04) << 0x10) != 0) {
            if (D_800B3B00_usa != NULL) {
                D_800B3B00_usa(0);
            }
            AudioUpdate();
        }
    }

    if (B_8018A748_usa[1].unk_08 == B_801842B0_usa) {
        D_800B3AEC_usa = -1;
        MusHandleStop(B_8018A748_usa[1].unk_04, 3);

        while ((MusHandleAsk(B_8018A748_usa[1].unk_04) << 0x10) != 0) {
            if (D_800B3B00_usa != NULL) {
                D_800B3B00_usa(0);
            }
            AudioUpdate();
        }
    }

    LoadSFXBank(arg0, 2);
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80003CE8_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003DAC_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003DAC_ger);
#endif

#if VERSION_USA
void func_80003E00_usa(s32 arg0, s32 arg1) {
    s32 temp_s0;

    if (func_80001D60_usa(arg0, arg1) < 0) {
        do {
            temp_s0 = func_80001D60_usa(arg0, arg1);
            if (D_800B3B00_usa != 0) {
                D_800B3B00_usa(0);
            }
            AudioUpdate();
        } while (temp_s0 < 0);
    }
}
#endif

#if VERSION_EUR
INCLUDE_ASM("asm/eur/nonmatchings/main/sound", func_80003E00_usa);
#endif

#if VERSION_FRA
INCLUDE_ASM("asm/fra/nonmatchings/main/sound", func_80003EC4_fra);
#endif

#if VERSION_GER
INCLUDE_ASM("asm/ger/nonmatchings/main/sound", func_80003EC4_ger);
#endif
