#pragma once

#include <unistd.h>
#include <stdint.h>

/* Buffer to be used to hold one bit per byte for ease of conversion, used internally */
typedef struct {
    uint8_t* buffer;
    size_t width;
    size_t height;
} BitBuffer;
