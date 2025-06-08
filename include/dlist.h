#ifndef DLIST_H
#define DLIST_H

#include "ultra64.h"
#include "unk.h"

struct block_t;
struct struct_gInfo;

// void func_80054500_usa();
void func_800545E4_usa(s32 arg0);
void func_80054624_usa(s32 arg0);
void InitTetrisState(struct block_t *block);
void InitDisplayList(struct struct_gInfo *info);
// void func_800549A4_usa();
void InitGameStateVar(void);
// void func_800552F4_usa();

#endif
