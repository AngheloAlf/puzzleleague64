#ifndef GAME_STATUS_H
#define GAME_STATUS_H

// TODO: Merge with another header

// Uncomment each flag when they are actually used
#define GAME_STATUS_FLAG_1               (1 << 0)
#define GAME_STATUS_FLAG_2               (1 << 1)
#define GAME_STATUS_FLAG_4               (1 << 2)
#define GAME_STATUS_FLAG_8               (1 << 3)
#define GAME_STATUS_FLAG_10              (1 << 4)
#define GAME_STATUS_FLAG_20              (1 << 5)
#define GAME_STATUS_FLAG_40              (1 << 6)
#define GAME_STATUS_FLAG_80              (1 << 7)

// Handled by GAME_STATUS_GET_WIN_RECORD and GAME_STATUS_SET_WIN_RECORD
// #define GAME_STATUS_FLAG_100             (1 << 8)
// #define GAME_STATUS_FLAG_200             (1 << 9)
// #define GAME_STATUS_FLAG_400             (1 << 10)
// #define GAME_STATUS_FLAG_800             (1 << 11)

// #define GAME_STATUS_FLAG_1000            (1 << 12)
// #define GAME_STATUS_FLAG_2000            (1 << 13)
// #define GAME_STATUS_FLAG_4000            (1 << 14)
// #define GAME_STATUS_FLAG_8000            (1 << 15)

// Save old state (?)
#define GAME_STATUS_SHIFT_LEFT(x) ((x) <<= 16)
// Restore old state (?) // clear current(?)
#define GAME_STATUS_SHIFT_RIGHT(x) ((x) >>= 16)

// idk about the name, maybe rename
#define GAME_STATUS_GET_WIN_RECORD(x) (((x) & 0xF00) >> 8)
#define GAME_STATUS_SET_WIN_RECORD(val) ((((val) << 8) & 0xF00))

#endif
