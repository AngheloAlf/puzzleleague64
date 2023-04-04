#ifndef UNKNOWN_STRUCTS_H
#define UNKNOWN_STRUCTS_H

#include "version.h"
#include "libultra.h"
#include "libc/stdint.h"
#include "libc/stdbool.h"
#include "unk.h"


typedef struct struct_gInfo {
    /* 0x00000 */ UNK_TYPE1 unk_00000[0x19020];
    /* 0x19020 */ s16 unk_19020;
    /* 0x19022 */ UNK_TYPE1 unk_19022[0x2];
    /* 0x19024 */ UNK_TYPE1 unk_19024[0x1C];
    /* 0x19040 */ void *unk_19040;
    /* 0x19044 */ UNK_TYPE1 unk_19044[0x4];
} struct_gInfo; // size = 0x19048


#endif
