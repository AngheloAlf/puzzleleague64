#ifndef UNKNOWN_DEFINES_H
#define UNKNOWN_DEFINES_H

#define BRICKTXTR_LEN (3)
#define B_801F9D00_USA_LEN (6)

#define GAME_BUFFER_LEN 2

// TODO: enum?
#define AI_CHECK_COUNT 7

#define TETWELL_UNK_3EF0_LEN_6 (6)

#define GAME_PLAYER_COUNT 8

// yet another max macro.
// i don't want to include ultra64.h on this header just for this macro,
// ideally this can be removed eventually
#ifndef _MAX
#define _MAX(a, b) (((a)>(b)) ? (a) : (b))
#endif

#define BLOCK_COLS_2D (6)
#define BLOCK_COLS_3D (18)


#define BLOCK_LEN_ROWS (12)
#define BLOCK_LEN_B (_MAX(BLOCK_COLS_2D, BLOCK_COLS_3D))

// maybe remove in favor of BLOCK_COLS_2D?
#define TETWELL_OBJSPRITE_LEN_B (BLOCK_LEN_B / 3)



#endif
