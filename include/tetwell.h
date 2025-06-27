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


/* Original name: tetWell */
typedef struct tetWell {
    /* 0x0000 */ block_t block[BLOCK_LEN_ROWS][BLOCK_LEN_B]; /* Original name: block */
    /* 0x2520 */ attack_t attack[ATTACK_COUNT];
    /* 0x2AC0 */ icon_t icon[ICON_COUNT];
    /* 0x2ED0 */ explode_t explosion[EXPLOSION_COUNT];
    /* 0x3830 */ uObjSprite unk_3830[BLOCK_LEN_ROWS][TETWELL_OBJSPRITE_LEN_B];
    /* 0x3EF0 */ uObjSprite unk_3EF0[TETWELL_UNK_3EF0_LEN_6];
    /* 0x3F80 */ uObjSprite unk_3F80;
    /* 0x3F98 */ uObjSprite unk_3F98;
    /* 0x3FB0 */ char visible[BLOCK_LEN_ROWS][BLOCK_LEN_B];
    /* 0x4088 */ f32 translation;
    /* 0x408C */ block_t new_block[BLOCK_LEN_B];
    /* 0x43A4 */ s32 unk_43A4;
    /* 0x43A8 */ s32 unk_43A8;
    /* 0x43AC */ s32 unk_43AC;
    /* 0x43B0 */ s32 unk_43B0;
    /* 0x43B4 */ s32 unk_43B4;
    /* 0x43B8 */ s32 unk_43B8;
    /* 0x43BC */ s32 unk_43BC;
    /* 0x43C0 */ s32 unk_43C0;
    /* 0x43C4 */ s32 unk_43C4;
    /* 0x43C8 */ s32 unk_43C8;
    /* 0x43CC */ UNK_TYPE1 unk_43CC[0x43E0-0x43CC];
    /* 0x43E0 */ s32 unk_43E0;
    /* 0x43E4 */ s32 unk_43E4;
    /* 0x43E8 */ UNK_PAD unk_43E8[0x4];
    /* 0x43EC */ UNK_TYPE4 unk_43EC;
    /* 0x43F0 */ s32 unk_43F0;
    /* 0x43F4 */ s32 unk_43F4;
    /* 0x43F8 */ s32 unk_43F8; // possibly part of "struct state_t state; // offset 0x4AA8, size 0x38", maybe "current_raise"
    /* 0x43FC */ s32 unk_43FC;
    /* 0x4400 */ UNK_TYPE1 unk_4400[0x4];
    /* 0x4404 */ s32 unk_4404;
    /* 0x4408 */ UNK_TYPE1 unk_4408[0x14];
    /* 0x441C */ s32 unk_441C;
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
