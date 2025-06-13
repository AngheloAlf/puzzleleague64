#ifndef _074280_H
#define _074280_H

#include "ultra64.h"
#include "unk.h"

typedef enum enum_func_800737B8_usa_arg0 {
    /* 1 */ ENUM_FUNC_800737B8_USA_ARG0_1 = 1,
    /* 2 */ ENUM_FUNC_800737B8_USA_ARG0_2,
    /* 3 */ ENUM_FUNC_800737B8_USA_ARG0_3,
    /* 4 */ ENUM_FUNC_800737B8_USA_ARG0_4,
    /* 5 */ ENUM_FUNC_800737B8_USA_ARG0_5,
    /* 6 */ ENUM_FUNC_800737B8_USA_ARG0_6,
} enum_func_800737B8_usa_arg0;

typedef enum enum_func_800739F0_usa_arg0 {
    /* 1 */ ENUM_FUNC_800739F0_USA_ARG0_1 = 1,
    /* 2 */ ENUM_FUNC_800739F0_USA_ARG0_2,
    /* 3 */ ENUM_FUNC_800739F0_USA_ARG0_3,
} enum_func_800739F0_usa_arg0;

void func_80073680_usa(void);
void func_8007371C_usa(void);
void func_800737B8_usa(enum_func_800737B8_usa_arg0 arg0);
void func_800739F0_usa(enum_func_800739F0_usa_arg0 arg0);

#endif
