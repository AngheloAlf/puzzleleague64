#ifndef ATTACK_H
#define ATTACK_H

#include "ultra64.h"
#include "PR/gs2dex.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

typedef struct attack_t {
    /* 0x00 */ s32 state;
    /* 0x04 */ s32 type;
    /* 0x08 */ s32 disappear;
    /* 0x0C */ s32 delay;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ UNK_PAD unk_28[0x30-0x28];
    /* 0x30 */ uObjSprite rect;
} attack_t; // size = 0x48

#if 0
struct attack_t {
    // total size: 0x50
    int state; // offset 0x0, size 0x4
    int type; // offset 0x4, size 0x4
    int disappear; // offset 0x8, size 0x4
    int delay; // offset 0xC, size 0x4
    int counter; // offset 0x10, size 0x4
    int level; // offset 0x14, size 0x4
    int start; // offset 0x18, size 0x4
    int end; // offset 0x1C, size 0x4
    int expression; // offset 0x20, size 0x4
    int currRow; // offset 0x24, size 0x4
    int slot; // offset 0x28, size 0x4
    uObjSprite rect; // offset 0x30, size 0x18
    int ChainCriminalPlayerNo; // offset 0x48, size 0x4
    int ComboCriminalPlayerNo; // offset 0x4C, size 0x4
};
#endif

// void func_8005A8D0_usa();
// void func_8005A990_usa();
// void func_8005A9EC_usa();
// void func_8005AAE0_usa();
// void func_8005AE18_usa();
// void func_8005B6E4_usa();
// void func_8005BBF4_usa();
// void func_8005BD24_usa();
// void func_8005BEFC_usa();
// void func_8005BFB4_usa();
// void func_8005C2C4_usa();
s32 ReturnAttackSlot(struct tetWell * well, s32 row, s32 col);
void Match3DPosition(s32 num, s32 row, s32 col, s32 *x, s32 *y);
void UpdateAttack(struct tetWell *well, struct cursor_t *cursor, s32 num);
// void func_8005C780_usa();
void ChangeAttack(struct tetWell *well, struct cursor_t *cursor, s32 num, s32 combo);
// void func_8005CB30_usa();
void StartAttack(struct tetWell *well, s32 num);

#endif
