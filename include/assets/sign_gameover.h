#ifndef ASSETS_SIGN_GAMEOVER_H
#define ASSETS_SIGN_GAMEOVER_H

#include "ultra64.h"

#define SIGNEND_1P_STAGE_CLEAR_WIDTH 104
#define SIGNEND_1P_STAGE_CLEAR_HEIGHT 86
#define SIGNEND_1P_ROUND_CLEAR_WIDTH 104
#define SIGNEND_1P_ROUND_CLEAR_HEIGHT 99
#define SIGNEND_1P_GAME_OVER_WIDTH 104
#define SIGNEND_1P_GAME_OVER_HEIGHT 96
#define SIGNEND_1P_TIME_UP_WIDTH 104
#define SIGNEND_1P_TIME_UP_HEIGHT 79
#define SIGNEND_1P_TRY_AGAIN_WIDTH 104
#define SIGNEND_1P_TRY_AGAIN_HEIGHT 20
#define SIGNEND_1P_YESNO_WIDTH 104
#define SIGNEND_1P_YESNO_HEIGHT 24
#define SIGNEND_1P_PUSH_ANY_BUTTON_WIDTH 104
#define SIGNEND_1P_PUSH_ANY_BUTTON_HEIGHT 16

typedef struct SignGameOver1pTextures {
    /* 0x00000 */ u32 stage_clear[SIGNEND_1P_STAGE_CLEAR_WIDTH * SIGNEND_1P_STAGE_CLEAR_HEIGHT];
    /* 0x08BC0 */ u32 round_clear[SIGNEND_1P_ROUND_CLEAR_WIDTH * SIGNEND_1P_ROUND_CLEAR_HEIGHT];
    /* 0x12CA0 */ u32 game_over[SIGNEND_1P_GAME_OVER_WIDTH * SIGNEND_1P_GAME_OVER_HEIGHT];
    /* 0x1C8A0 */ u32 time_up[SIGNEND_1P_TIME_UP_WIDTH * SIGNEND_1P_TIME_UP_HEIGHT];
    /* 0x24900 */ u32 try_again[SIGNEND_1P_TRY_AGAIN_WIDTH * SIGNEND_1P_TRY_AGAIN_HEIGHT];
    /* 0x26980 */ u32 yesno_1[SIGNEND_1P_YESNO_WIDTH * SIGNEND_1P_YESNO_HEIGHT];
    /* 0x29080 */ u32 yesno_2[SIGNEND_1P_YESNO_WIDTH * SIGNEND_1P_YESNO_HEIGHT];
    /* 0x2B780 */ u32 yesno_3[SIGNEND_1P_YESNO_WIDTH * SIGNEND_1P_YESNO_HEIGHT];
    /* 0x2DE80 */ u32 yesno_4[SIGNEND_1P_YESNO_WIDTH * SIGNEND_1P_YESNO_HEIGHT];
    /* 0x30580 */ u32 push_any_button[SIGNEND_1P_PUSH_ANY_BUTTON_WIDTH * SIGNEND_1P_PUSH_ANY_BUTTON_HEIGHT];
} SignGameOver1pTextures; // size = 0x31F80

#define SIGNEND_2P_WIDTH 112
#define SIGNEND_2P_HEIGHT 42

typedef struct SignGameOver2pTextures {
    /* 0x0000 */ u16 win_blue[SIGNEND_2P_WIDTH * SIGNEND_2P_HEIGHT];
    /* 0x24C0 */ u16 win_red[SIGNEND_2P_WIDTH * SIGNEND_2P_HEIGHT];
    /* 0x4980 */ u16 lose_blue[SIGNEND_2P_WIDTH * SIGNEND_2P_HEIGHT];
    /* 0x6E40 */ u16 lose_red[SIGNEND_2P_WIDTH * SIGNEND_2P_HEIGHT];
    /* 0x9300 */ u16 draw_blue[SIGNEND_2P_WIDTH * SIGNEND_2P_HEIGHT];
    /* 0xB7C0 */ u16 draw_red[SIGNEND_2P_WIDTH * SIGNEND_2P_HEIGHT];
} SignGameOver2pTextures; // size = 0xDC80


typedef union SignGameOverTexs {
    SignGameOver1pTextures texs_1p;
    SignGameOver2pTextures texs_2p;
} SignGameOverTexs; // size = 0x31F80

extern SignGameOverTexs *endSegment;

#endif
