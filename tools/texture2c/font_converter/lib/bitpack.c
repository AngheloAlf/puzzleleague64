#include "bitpack.h"

#include <stdint.h>

/**
 * Expects an array of 8 single bits, packs them into a byte and returns it.
 * E.g. { 1, 0, 1, 0, 0, 0, 1, 0 } -> 0xA2
 */
uint8_t PackByte(const uint8_t* bits) {
    uint8_t ret = 0;
    int i;
    for (i = 0; i < 8; i++) {
        ret |= !!bits[i] << (7 - i);
    }
    return ret;
}

/* Unpack a byte into a _preallocated_ array of bits */
uint8_t* UnpackByte(uint8_t* out, const uint8_t in) {
    int i;
    for (i = 0; i < 8; i++) {
        out[i] = in >> (7 - i) & 1;
    }
    return out;
}
