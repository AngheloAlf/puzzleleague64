#ifndef PON_THREAD_H
#define PON_THREAD_H

typedef enum ThreadId {
    /* 1 */ THREAD_ID_IDLE = 1,
    /* 3 */ THREAD_ID_LIBMUS = 3,
    /* 3 */ THREAD_ID_TIMEKEEPER = 3,
    /* 4 */ THREAD_ID_COUNTER,
    /* 6 */ THREAD_ID_MAIN = 6,
} ThreadId;

typedef enum ThreadPriority {
    /* 10 */ THREAD_PRI_IDLE = 10,
    /* 10 */ THREAD_PRI_MAIN = 10,
    /* 12 */ THREAD_PRI_TIMEKEEPER = 12,
    /* 13 */ THREAD_PRI_COUNTER,
    /* 15 */ THREAD_PRI_LIBMUS = 15,
} ThreadPriority;

#endif
