#ifndef TETWELL_H
#define TETWELL_H

#include "ultra64.h"
#include "PR/gs2dex.h"
#include "unk.h"

#include "unknown_defines.h"

#include "attack.h"
#include "block.h"
#include "explode.h"
#include "icon.h"
#include "menu_t.h"


/* Original name: state_t */
typedef struct state_t {
    /* 0x00 */ s32 comboFlash; /* Original name: comboFlash */
    /* 0x04 */ s32 comboFace; /* Original name: comboFace */
    /* 0x08 */ s32 comboExplode; /* Original name: comboExplode */
    /* 0x0C */ s32 blockDropDelay; /* Original name: blockDropDelay */
    /* 0x10 */ s32 unk_43D8;
    /* 0x14 */ s32 nextLevel; /* Original name: nextLevel */
    /* 0x18 */ s32 currLevel; /* Original name: currLevel */
    /* 0x1C */ s32 rand; /* Original name: rand */ // nbool?
    /* 0x20 */ s32 newBlock; /* Original name: newBlock */
    /* 0x24 */ u32 timer; /* Original name: timer */
    /* 0x28 */ u32 speed; /* Original name: speed */
    /* 0x2C */ s32 death; /* Original name: death */
    /* 0x30 */ s32 current_raise; /* Original name: current_raise */
    /* 0x34 */ s32 raise; /* Original name: raise */
} state_t; // size = 0x38

/* Original name: extra_t */
typedef struct extra_t {
    /* 0x00 */ s32 level; /* Original name: level */
    /* 0x04 */ s32 win; /* Original name: win */
    /* 0x08 */ s32 maxGarbage; /* Original name: maxGarbage */
    /* 0x0C */ s32 clearGarbage; /* Original name: clearGarbage */
    /* 0x10 */ UNK_PAD unk_4410[0x4];
    /* 0x14 */ s32 queueGarbage; /* Original name: queueGarbage */
    /* 0x18 */ s32 wellGarbage; /* Original name: wellGarbage */
} extra_t; // size = 0x1C

/* Original name: tetWell */
typedef struct tetWell {
    /* 0x0000 */ block_t block[BLOCK_LEN_ROWS][BLOCK_LEN_B]; /* Original name: block */
    /* 0x2520 */ attack_t attack[ATTACK_COUNT]; /* Original name: attack */
    /* 0x2AC0 */ icon_t icon[ICON_COUNT]; /* Original name: icon */
    /* 0x2ED0 */ explode_t explosion[EXPLOSION_COUNT]; /* Original name: explosion */
    /* 0x3830 */ uObjSprite block_rect[BLOCK_LEN_ROWS][TETWELL_OBJSPRITE_LEN_B]; /* Original name: block_rect */
    /* 0x3EF0 */ uObjSprite new_block_rect[TETWELL_UNK_3EF0_LEN_6]; /* Original name: new_block_rect */
    /* 0x3F80 */ uObjSprite left2D; /* Original name: left2D */
    /* 0x3F98 */ uObjSprite right2D; /* Original name: right2D */
    /* 0x3FB0 */ char visible[BLOCK_LEN_ROWS][BLOCK_LEN_B]; /* Original name: visible */
    /* 0x4088 */ f32 translation; /* Original name: translation */
    /* 0x408C */ block_t new_block[BLOCK_LEN_B]; /* Original name: new_block */
    /* 0x43A4 */ s32 unk_43A4;
    /* 0x43A8 */ s32 unk_43A8; // old_chain?
    /* 0x43AC */ s32 score; /* Original name: score */
    /* 0x43B0 */ s32 unk_43B0; /* Original name: raise */
    /* 0x43B4 */ s32 danger; /* Original name: danger */ // TODO: nbool?
    /* 0x43B8 */ s32 alert; /* Original name: alert */ // TODO: nbool?
    /* 0x43BC */ s32 unk_43BC;
    /* 0x43C0 */ s32 chain_garbage; /* Original name: chain_garbage */
    /* 0x43C4 */ s32 collision; /* Original name: collision */ // nbool?
    /* 0x43C8 */ state_t state; /* Original name: state */
    /* 0x4400 */ extra_t extra; /* Original name: extra */
    /* 0x441C */ s32 bot_height;
    /* 0x4420 */ menu_t menu;
} tetWell; // size = 0x4430

#if 0
struct tetWell {
    // total size: 0x57C0
    struct block_t block[12][18]; // offset 0x0, size 0x2520
    struct attack_t attack[40]; // offset 0x2520, size 0xC80
    struct icon_t icon[10]; // offset 0x31A0, size 0x410
    struct explode_t explosion[50]; // offset 0x35B0, size 0x960
    uObjSprite block_rect[12][6]; // offset 0x3F10, size 0x6C0
    uObjSprite new_block_rect[6]; // offset 0x45D0, size 0x90
    uObjSprite left2D; // offset 0x4660, size 0x18
    uObjSprite right2D; // offset 0x4678, size 0x18
    char visible[12][18]; // offset 0x4690, size 0xD8
    float translation; // offset 0x4768, size 0x4
    struct block_t new_block[18]; // offset 0x476C, size 0x318
    struct chain_t reaction; // offset 0x4A84, size 0x8
    int score; // offset 0x4A8C, size 0x4
    int raise; // offset 0x4A90, size 0x4
    int danger; // offset 0x4A94, size 0x4
    int alert; // offset 0x4A98, size 0x4
    int defrost; // offset 0x4A9C, size 0x4
    int chain_garbage; // offset 0x4AA0, size 0x4
    int collision; // offset 0x4AA4, size 0x4
    struct state_t state; // offset 0x4AA8, size 0x38
    struct extra_t extra; // offset 0x4AE0, size 0x1C
    int bot_height; // offset 0x4AFC, size 0x4
    struct menu_t menu; // offset 0x4B00, size 0x18
    struct attack_t attack4p[40]; // offset 0x4B18, size 0xC80
    int LastChainType; // offset 0x5798, size 0x4
    int LastComboType; // offset 0x579C, size 0x4
    int LastEXComboType; // offset 0x57A0, size 0x4
    int ChainAttackWhom; // offset 0x57A4, size 0x4
    int ComboAttackWhom; // offset 0x57A8, size 0x4
    int LastAttackWhom; // offset 0x57AC, size 0x4
    int RankingSignRaise; // offset 0x57B0, size 0x4
    int RankingSignColor; // offset 0x57B4, size 0x4
    int EntryNo; // offset 0x57B8, size 0x4
};
#endif


#endif
