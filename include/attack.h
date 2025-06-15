#ifndef ATTACK_H
#define ATTACK_H

#include "ultra64.h"
#include "PR/gs2dex.h"
#include "macros_defines.h"
#include "unk.h"

struct cursor_t;
struct tetWell;

typedef enum AttackState {
    /* 0 */ ATTACKSTATE_0,
    /* 1 */ ATTACKSTATE_1, // AttackFly
    /* 2 */ ATTACKSTATE_2, // AttackTop
    /* 3 */ ATTACKSTATE_3, // AttackTop
    /* 4 */ ATTACKSTATE_4, // AttackTop
    /* 5 */ ATTACKSTATE_5, // AttackFall
    /* 6 */ ATTACKSTATE_6, // AttackFall
    /* 7 */ ATTACKSTATE_7, // AttackShake
} AttackState;

typedef enum AttackType {
    /*  0 */ ATTACKTYPE_0,
    /*  1 */ ATTACKTYPE_1,
    /*  2 */ ATTACKTYPE_2,
    /*  3 */ ATTACKTYPE_3,
    /*  4 */ ATTACKTYPE_4,
    /*  9 */ ATTACKTYPE_9 = 9,
    /* 10 */ ATTACKTYPE_10,
    /* 11 */ ATTACKTYPE_11,
    /* 12 */ ATTACKTYPE_12,
    /* 13 */ ATTACKTYPE_13,
    /* 14 */ ATTACKTYPE_14,
    /* 15 */ ATTACKTYPE_15,
    /* 16 */ ATTACKTYPE_16,
    /* 18 */ ATTACKTYPE_18 = 18,
    /* 19 */ ATTACKTYPE_19,
    /* 20 */ ATTACKTYPE_20,
    /* 21 */ ATTACKTYPE_21,
} AttackType;

typedef struct attack_t {
    /* 0x00 */ ENUM_TYPE(AttackState, s32) state;
    /* 0x04 */ ENUM_TYPE(AttackType, s32) type;
    /* 0x08 */ s32 disappear;
    /* 0x0C */ s32 delay;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 start;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ UNK_PAD unk_2C[0x30-0x2C]; // alignment padding?
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
void func_8005A9EC_usa(struct tetWell *well, struct attack_t *attack);
void AttackFly(struct tetWell *well, struct attack_t *attack, s32 num);
void AttackTop(struct tetWell *well, struct cursor_t *cursor, struct attack_t *attack, s32 num, s32 actual);
void AttackFall(struct tetWell *well, struct cursor_t *cursor, struct attack_t *attack, s32 *sound);
void AttackShake(struct tetWell *well, struct cursor_t *cursor, struct attack_t *attack);
// void func_8005BD24_usa();
// void func_8005BEFC_usa();
// void func_8005BFB4_usa();
void AttackPackEmpty(struct tetWell * well, s32 num);
s32 ReturnAttackSlot(struct tetWell * well, s32 row, s32 col);
void Match3DPosition(s32 num, s32 row, s32 col, s32 *x, s32 *y);
void UpdateAttack(struct tetWell *well, struct cursor_t *cursor, s32 num);
// void func_8005C780_usa();
void ChangeAttack(struct tetWell *well, struct cursor_t *cursor, s32 num, s32 combo);
// void InitFlyAttack(struct tetWell *well, struct attack_t *attack, s32 posX, s32 posY, s32 type, s32 num);
void StartAttack(struct tetWell *well, s32 num);

#endif
