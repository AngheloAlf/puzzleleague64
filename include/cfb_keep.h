#ifndef CFB_KEEP_H
#define CFB_KEEP_H

#include "libultra.h"
#include "macros_defines.h"


#define CFB_NUM 2


typedef u16 CFBPix;

#define CFB_STATUS_FREE     0         /* Available */
#define CFB_STATUS_PRECIOUS (1<<0)    /* Constrained for decoding of next frame */
#define CFB_STATUS_SHOWING  (1<<1)    /* Waiting to display or displaying */


void Cfb_Init(void);
void Cfb_Keep(s32 index);
void Cfb_Release(s32 index);
void Cfb_ReleaseAll(void);
s32 Cfb_GetCurrentIndex(void);


extern CFBPix *B_801AB620_usa[CFB_NUM];
extern u32 gCfbStatus[CFB_NUM];


#endif
