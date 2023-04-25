#include "bit_convert.h"

int8_t ToInt8BE(const uint8_t* data, int32_t offset) {
    return (uint8_t)data[offset + 0];
}

uint8_t ToUInt8BE(const uint8_t* data, int32_t offset) {
    return (uint8_t)data[offset + 0];
}

int16_t ToInt16BE(const uint8_t* data, int32_t offset) {
    return ((uint16_t)data[offset + 0] << 8) | (uint16_t)data[offset + 1];
}

uint16_t ToUInt16BE(const uint8_t* data, int32_t offset) {
    return ((uint16_t)data[offset + 0] << 8) | (uint16_t)data[offset + 1];
}

int32_t ToInt32BE(const uint8_t* data, int32_t offset) {
    return ((uint32_t)data[offset + 0] << 24) | ((uint32_t)data[offset + 1] << 16) | ((uint32_t)data[offset + 2] << 8) |
           (uint32_t)data[offset + 3];
}

uint32_t ToUInt32BE(const uint8_t* data, int32_t offset) {
    return ((uint32_t)data[offset + 0] << 24) | ((uint32_t)data[offset + 1] << 16) | ((uint32_t)data[offset + 2] << 8) |
           (uint32_t)data[offset + 3];
}

int64_t ToInt64BE(const uint8_t* data, int32_t offset) {
    return ((uint64_t)data[offset + 0] << 56) | ((uint64_t)data[offset + 1] << 48) |
           ((uint64_t)data[offset + 2] << 40) | ((uint64_t)data[offset + 3] << 32) |
           ((uint64_t)data[offset + 4] << 24) | ((uint64_t)data[offset + 5] << 16) | ((uint64_t)data[offset + 6] << 8) |
           ((uint64_t)data[offset + 7]);
}

uint64_t ToUInt64BE(const uint8_t* data, int32_t offset) {
    return ((uint64_t)data[offset + 0] << 56) | ((uint64_t)data[offset + 1] << 48) |
           ((uint64_t)data[offset + 2] << 40) | ((uint64_t)data[offset + 3] << 32) |
           ((uint64_t)data[offset + 4] << 24) | ((uint64_t)data[offset + 5] << 16) | ((uint64_t)data[offset + 6] << 8) |
           ((uint64_t)data[offset + 7]);
}

void FromUInt32ToBE(uint8_t* data, int32_t offset, uint32_t value) {
    data[offset + 0] = (uint8_t)(value >> 24);
    data[offset + 1] = (uint8_t)(value >> 16);
    data[offset + 2] = (uint8_t)(value >> 8);
    data[offset + 3] = (uint8_t)(value >> 0);
}
