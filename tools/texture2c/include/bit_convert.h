#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

int8_t ToInt8BE(const uint8_t* data, int32_t offset);
uint8_t ToUInt8BE(const uint8_t* data, int32_t offset);

int16_t ToInt16BE(const uint8_t* data, int32_t offset);
uint16_t ToUInt16BE(const uint8_t* data, int32_t offset);

int32_t ToInt32BE(const uint8_t* data, int32_t offset);
uint32_t ToUInt32BE(const uint8_t* data, int32_t offset);

int64_t ToInt64BE(const uint8_t* data, int32_t offset);
uint64_t ToUInt64BE(const uint8_t* data, int32_t offset);

void FromUInt32ToBE(uint8_t* data, int32_t offset, uint32_t value);
