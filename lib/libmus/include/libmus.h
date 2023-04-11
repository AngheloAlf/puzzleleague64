#ifndef LIBMUS_H
#define LIBMUS_H

#include "libultra.h"

typedef struct {
    unsigned long control_flag;

    int channels;
    void *sched;
    int thread_priority;
    unsigned char *heap;
    int heap_length;

    unsigned char *ptr;
    unsigned char *wbk;

    void *default_fxbank;

    int fifo_length;

    int syn_updates;
    int syn_output_rate;
    int syn_rsp_cmds;
    int syn_retraceCount;
    int syn_num_dma_bufs;
    int syn_dma_buf_size;

    // Special Addition
    OSPiHandle *diskrom_handle;
} musConfig;

typedef enum {
    MUSBOOL_OFF,
    MUSBOOL_ON,
} musBool;

typedef struct {
    u64 *data;       /* address of Acmd list			*/
    int data_size;   /* size of Acmd list			*/
    u64 *ucode;      /* address of microcode code	*/
    u64 *ucode_data; /* address of microcode data	*/
} musTask;

typedef unsigned long musHandle;

typedef void (*LIBMUScb_marker)(musHandle, int);

typedef void (*LIBMUScb_install)(void);
typedef void (*LIBMUScb_waitframe)(void);
typedef void (*LIBMUScb_dotask)(musTask *);

typedef struct {
    LIBMUScb_install install;     /* called when thread starts		*/
    LIBMUScb_waitframe waitframe; /* called to wait for vsync message */
    LIBMUScb_dotask dotask;       /* called to process RSP task		*/
} musSched;

/* control flags */
#define MUSCONTROL_RAM (1 << 0)

/* channel types flags */
#define MUSFLAG_EFFECTS 1
#define MUSFLAG_SONGS 2

/* initialise */
int MusInitialize(musConfig *config);

void func_8008B21C_usa(void);

/* audio configuration */
int MusSetFxType(int fxtype);
int MusSetSongFxChange(musBool onoff);

/* set master volume levels */
void MusSetMasterVolume(unsigned long flags, int volume);

/* start songs and sound effects */
musHandle MusStartSong(void *addr);
// void func_8008B310_usa();
musHandle MusStartSongFromMarker(void *addr, int marker);
musHandle MusStartEffect(int number);
musHandle MusStartEffect2(int number, int volume, int pan, int restartflag, int priority);

/* stop and query sound types */
void MusStop(unsigned long flags, int speed);
int MusAsk(unsigned long flags);

/* handle based processing */
int MusHandleAsk(musHandle handle);
int MusHandleStop(musHandle handle, int speed);
int MusHandleSetVolume(musHandle handle, int volume);
int MusHandleSetPan(musHandle handle, int pan);
int MusHandleSetFreqOffset(musHandle handle, float offset);
int MusHandleSetTempo(musHandle handle, int tempo);
int MusHandleSetReverb(musHandle handle, int reverb);
int MusHandlePause(musHandle handle);
int MusHandleUnPause(musHandle handle);
void *MusHandleGetPtrBank(musHandle handle);

/* sample bank support */
void MusPtrBankInitialize(void *pbank, void *wbank);
void *MusPtrBankSetSingle(void *ipbank);
void MusPtrBankSetCurrent(void *ipbank);
void *MusPtrBankGetCurrent(void);

/* sound effect bank support */
void MusFxBankInitialize(void *fxbank);
void MusFxBankSetSingle(void *ifxbank);
void MusFxBankSetCurrent(void *ifxbank);
void *MusFxBankGetCurrent(void);
int MusFxBankNumberOfEffects(void *ifxbank);
void MusFxBankSetPtrBank(void *ifxbank, void *ipbank);
void *MusFxBankGetPtrBank(void *ifxbank);
void MusFxBankSetSingle(void *ifxbank);

/* scheduler support */
void MusSetScheduler(musSched *sched_list);

/* marker callback support */
void MusSetMarkerCallback(void *callback);

/* wave list lookup in song header */
int MusHandleWaveCount(musHandle handle);
unsigned short *MusHandleWaveAddress(musHandle handle);

/* macros to support previous sample bank functions - use is not recommended! */
#define MusBankInitialize(pbank, wbank) MusPtrBankInitialize(pbank, wbank)

#define MusBankStartSong(ipbank, addr) MusStartSong((addr) == (void *)MusPtrBankSetSingle(ipbank) ? (addr) : (addr))

#define MusBankStartEffect(ipbank, number) \
    MusStartEffect((number) == (int)MusPtrBankSetSingle(ipbank) ? (number) : (number))

#define MusBankStartEffect2(ipbank, number, volume, pan, restartflag, priority)                                   \
    MusStartEffect2((number) == (int)MusPtrBankSetSingle(ipbank) ? (number) : (number), volume, pan, restartflag, \
                    priority)

// extern UNK_TYPE jumptable;
// extern UNK_TYPE D_800BE420_usa;
// extern UNK_TYPE BigRoomParams;
// extern UNK_TYPE D_800BE510_usa;
// extern UNK_TYPE D_800BE538_usa;
// extern UNK_TYPE D_800BE5C0_usa;
// extern UNK_TYPE D_800BE5E8_usa;
// extern UNK_TYPE EffectCount;
// extern UNK_TYPE EffectList;
// extern UNK_TYPE default_sched;
// extern UNK_TYPE __libmus_current_sched;
// extern UNK_TYPE last_task;

// extern UNK_TYPE diskrom_handle;
// extern UNK_TYPE frame_samples;
// extern UNK_TYPE frame_samples_min;
// extern UNK_TYPE extra_samples;
// extern UNK_TYPE audio_sched;
// extern UNK_TYPE sched_mem;

// extern UNK_TYPE audio_heap;

// extern UNK_TYPE __muscontrol_flag;

// extern UNK_TYPE __libmus_alglobals;

// extern UNK_TYPE gReverbFx;

#endif
