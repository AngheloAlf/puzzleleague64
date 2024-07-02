#ifndef BOOT_MAIN_H
#define BOOT_MAIN_H

#include "ultra64.h"
#include "PR/sched.h"

#include "stack.h"

void func_80000450_usa(void);
// void bootproc();
void Idle_ThreadEntry(void *arg);
void func_80000630_usa(void);
void pon_main(void *arg);
s32 doMenuLoop(s32 arg0);
s32 doGameLoop(s32 arg0);

extern OSScClient B_801AB810_usa;
extern OSSched B_8021AAA0_usa;

extern STACK(B_8021DF50_usa, OS_SC_STACKSIZE);

#endif
