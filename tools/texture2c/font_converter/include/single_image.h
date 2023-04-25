#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void PrintSingleImage(uint8_t** bitArrays, size_t arrayCount);
void WriteSingle1bppPNG(FILE* outputFile, uint8_t** bitArrays, size_t arrayCount);
void WriteSingleBMPImage(FILE* outputFile, uint8_t** bitArrays, size_t arrayCount);
void WriteSingleGrayscalePNG(FILE* outputFile, uint8_t** bitArrays, size_t arrayCount);
