#ifndef ASSETS_BACKGROUND_FRAME_H
#define ASSETS_BACKGROUND_FRAME_H

#include "background.h"

#include "alignment.h"

#define BACKGROUND_FRAME_WIDTH BACKGROUND_WIDTH
#define BACKGROUND_FRAME_HEIGHT BACKGROUND_HEIGHT
#define BACKGROUND_FRAME_TLUT_SIZE 0x100

#define BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH 64
#define BACKGROUND_FRAME_UI_DISPLAY_2P_A_HEIGHT 170
#define BACKGROUND_FRAME_UI_DISPLAY_2P_B_HEIGHT 202
#define BACKGROUND_FRAME_UI_DISPLAY_2P_C_HEIGHT 153

typedef struct BackgroundFrame {
	/* 0x00000 */ u8 frame[BACKGROUND_FRAME_WIDTH * BACKGROUND_FRAME_HEIGHT] ALIGNED(8);
	/* 0x12200 */ u16 tlut[BACKGROUND_FRAME_TLUT_SIZE] ALIGNED(8);
} BackgroundFrame; // size = 0x12400

typedef struct BackgroundFrameUiDisplay2P_A {
	/* 0x00000 */ u8 frame[BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH * BACKGROUND_FRAME_UI_DISPLAY_2P_A_HEIGHT] ALIGNED(8);
	/* 0x12200 */ u16 tlut[BACKGROUND_FRAME_TLUT_SIZE] ALIGNED(8);
} BackgroundFrameUiDisplay2P_A; // size = 0x12400

typedef struct BackgroundFrameUiDisplay2P_B {
	/* 0x00000 */ u8 frame[BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH * BACKGROUND_FRAME_UI_DISPLAY_2P_B_HEIGHT] ALIGNED(8);
	/* 0x12200 */ u16 tlut[BACKGROUND_FRAME_TLUT_SIZE] ALIGNED(8);
} BackgroundFrameUiDisplay2P_B; // size = 0x12400

typedef struct BackgroundFrameUiDisplay2P_C {
	/* 0x00000 */ u8 frame[BACKGROUND_FRAME_UI_DISPLAY_2P_WIDTH * BACKGROUND_FRAME_UI_DISPLAY_2P_C_HEIGHT] ALIGNED(8);
	/* 0x12200 */ u16 tlut[BACKGROUND_FRAME_TLUT_SIZE] ALIGNED(8);
} BackgroundFrameUiDisplay2P_C; // size = 0x12400

#endif
