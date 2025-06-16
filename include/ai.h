#ifndef AI_H
#define AI_H

#include "ultra64.h"
#include "unk.h"

#include "unknown_defines.h"

struct cursor_t;
struct tetWell;

#define AI_UNK_108_COUNT 25

typedef struct ai_t {
    /* 0x000 */ s32 unk_000;
    /* 0x004 */ s32 unk_004;
    /* 0x008 */ UNK_PAD unk_008[0x4];
    /* 0x00C */ s32 unk_00C;
    /* 0x010 */ s32 unk_010;
    /* 0x014 */ UNK_PAD unk_014[0x018-0x014];
    /* 0x018 */ s32 unk_018;
    /* 0x01C */ s32 unk_01C;
    /* 0x020 */ s32 unk_020;
    /* 0x024 */ s32 unk_024;
    /* 0x028 */ s32 unk_028;
    /* 0x02C */ s32 unk_02C;
    /* 0x030 */ s32 unk_30;
    /* 0x034 */ s32 unk_34;
    /* 0x038 */ s32 unk_038;
    /* 0x03C */ s32 unk_03C;
    /* 0x040 */ s32 unk_040;
    /* 0x044 */ s32 unk_044;
    /* 0x048 */ UNK_PAD unk_048[0x0FC-0x048];
    /* 0x0FC */ s32 unk_0FC;
    /* 0x100 */ s32 unk_100;
    /* 0x104 */ s32 unk_104;
    /* 0x108 */ char move[AI_UNK_108_COUNT];
    /* 0x124 */ s32 unk_124;
    /* 0x128 */ s32 unk_128;
} ai_t; // size = 0x12C

#if 0
struct ai_t {
    // total size: 0x128
    int cursor_x; // offset 0x0, size 0x4
    int cursor_y; // offset 0x4, size 0x4
    int think; // offset 0x8, size 0x4
    int speed; // offset 0xC, size 0x4
    int delay; // offset 0x10, size 0x4
    unsigned char character; // offset 0x14, size 0x1
    signed char choice; // offset 0x15, size 0x1
    int step; // offset 0x18, size 0x4
    int chain; // offset 0x1C, size 0x4
    int garbage; // offset 0x20, size 0x4
    int t; // offset 0x24, size 0x4
    int b; // offset 0x28, size 0x4
    int l; // offset 0x2C, size 0x4
    int r; // offset 0x30, size 0x4
    int direction; // offset 0x34, size 0x4
    int where; // offset 0x38, size 0x4
    int from; // offset 0x3C, size 0x4
    int to; // offset 0x40, size 0x4
    struct command_t command[15]; // offset 0x44, size 0xB4
    int com_head; // offset 0xF8, size 0x4
    int com_tail; // offset 0xFC, size 0x4
    int total_command; // offset 0x100, size 0x4
    char move[25]; // offset 0x104, size 0x19
    int move_head; // offset 0x120, size 0x4
    int move_tail; // offset 0x124, size 0x4
};
#endif

extern ai_t brainbrain[GAME_BUFFER_LEN];

void InitAI(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain);
// void func_80075108_usa();
// void func_800751B4_usa();
// void func_80075278_usa();
// void func_80075354_usa();
// void func_80075458_usa();
// void func_80075524_usa();
// void func_800755B0_usa();
void AISetCursor(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain);
void AIChangeVision(struct ai_t *brain);
// void func_80075980_usa();
void AIAddCommand(struct ai_t *brain, s32 func, s32 para1, s32 para2);
// void func_80075A1C_usa();
// void func_80075A38_usa();
void AIFinishMove(struct ai_t *brain);
void AIClearCommand(struct ai_t *brain);
// void func_80075A78_usa();
// void func_80075BC0_usa();
// void func_80075C60_usa();
// void func_80075D2C_usa();
// void func_80075E40_usa();
// void func_80076F54_usa();
// void func_80076F84_usa();
// void func_80077110_usa();
// void func_80077280_usa();
// void func_80077338_usa();
// void func_8007737C_usa();
// void func_80077670_usa();
// void func_800776FC_usa();
// void func_80077920_usa();
// void func_80077B00_usa();
// void func_8007855C_usa();
// void func_8007895C_usa();
// void func_80078B78_usa();
// void func_80078D78_usa();
// void func_80079094_usa();
// void func_8007928C_usa();
// void func_800794C8_usa();
// void func_8007959C_usa();
// void func_80079D64_usa();
// void func_80079DEC_usa();
// void func_8007A5C8_usa();
// void func_8007ACAC_usa();
// void func_8007AFF4_usa();
// void func_8007BF40_usa();
// void func_8007CE20_usa();
// void func_8007D484_usa();
// void func_8007E18C_usa();
// void func_8007EC98_usa();
// void func_8007F5AC_usa();
// void func_8007FEB4_usa();
// void func_80080504_usa();
// void func_80080724_usa();
// void func_80080AF0_usa();
// void func_800812A4_usa();
// void func_800814CC_usa();
void UpdateAI(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain, s32 num);
void AIMove(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain, s32 num);
void AI2DMove(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain, s32 num);
void AI3DMove(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain, s32 num);
// void func_80082EE0_usa();

#endif
