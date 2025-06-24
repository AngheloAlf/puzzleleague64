#ifndef AI_H
#define AI_H

#include "ultra64.h"
#include "unk.h"

#include "unknown_defines.h"

struct cursor_t;
struct tetWell;

#define AI_MOVE_COUNT 25

typedef struct command_t {
    /* 0x0 */ s32 function;
    /* 0x4 */ s32 para1;
    /* 0x8 */ s32 para2;
} command_t; // size = 0xC

typedef struct ai_t {
    /* 0x000 */ s32 cursor_x;
    /* 0x004 */ s32 cursor_y;
    /* 0x008 */ s32 unk_008; // think?
    /* 0x00C */ s32 unk_00C; // speed?
    /* 0x010 */ s32 unk_010;
    /* 0x014 */ u8 unk_014; // character?
    /* 0x015 */ UNK_PAD unk_015[0x3];
    /* 0x018 */ s32 unk_018; // choice?
    /* 0x01C */ s32 unk_01C;
    /* 0x020 */ s32 unk_020; // garbage?
    /* 0x024 */ s32 unk_024;
    /* 0x028 */ s32 unk_028;
    /* 0x02C */ s32 unk_02C;
    /* 0x030 */ s32 unk_030;
    /* 0x034 */ s32 unk_034;
    /* 0x038 */ s32 unk_038;
    /* 0x03C */ s32 unk_03C;
    /* 0x040 */ s32 unk_040;
    /* 0x044 */ s32 unk_044;
    /* 0x048 */ command_t unk_048[UNK_SIZE]; // command[15]?
    /* 0x054 */ UNK_PAD unk_054[0x0FC-0x054];
    /* 0x0FC */ s32 unk_0FC;
    /* 0x100 */ s32 unk_100; // com_tail?
    /* 0x104 */ s32 unk_104; // total_command?
    /* 0x108 */ char move[AI_MOVE_COUNT]; // TODO: make an enum?
    /* 0x124 */ s32 unk_124; // move_head?
    /* 0x128 */ s32 unk_128; // move_tail?
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
// void AISetEasy();
// void AISetNormal();
// void AISetHard();
// void AISetSHard();
// void AISetUltra();
void AISetCharacter(struct ai_t *brain, s32 stage);
// void AISetLevel();
void AISetCursor(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain);
void AIChangeVision(struct ai_t *brain);
void AISetGarbage(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain);
void AIAddCommand(struct ai_t *brain, s32 func, s32 para1, s32 para2);
// void AIDelCommand();
// void AISetMove();
void AIFinishMove(struct ai_t *brain);
void AIClearCommand(struct ai_t *brain);
// void AIRowPack();
s32 AIVertMove(struct ai_t *brain, s32 row);
// void AIHoriMove();
// void AIHoriMoveBlock();
// void AIHoriMoveCheckCheck();
// void AISearchClose();
// void AIMoveAcross();
// void AIShortestD();
// void AISortRows();
// void AIDistance();
// void AILowerRow();
// void AIVisionCheck();
void AIBoundaryCheck(struct tetWell *well, struct ai_t *brain);
// void AIPossibleRow();
// void AIPossibleCol();
// void AIComboCheck();
// void AICombo3a();
// void AICombo3b();
// void AICombo45();
// void AIComboX();
// void AIFlashCheck();
// void AIScrollCheck();
// void AIVolumeCheck();
// void AIChainFrequency();
// void AIChainVert1();
// void AIChainVert2();
// void func_8007ACAC_usa();
// void AIChainVert4();
// void AIChainVert5();
// void AIChainHori1();
// void AIChainHori2();
// void AIChainHori3();
// void AIChainHori4();
// void AIChainHori5();
// void AIClearGarbage();
// void AIClearPosition();
// void AIChainPack();
// void AIChainGarbage1();
// void AIStupidMove();
void UpdateAI(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain, s32 num);
void AIMove(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain, s32 num);
void AI2DMove(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain, s32 num);
void AI3DMove(struct tetWell *well, struct cursor_t *cursor, struct ai_t *brain, s32 num);
void AISpeedUpMove(struct ai_t *brain);

#endif
