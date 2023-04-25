#pragma once

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void Write1bppPNG(FILE* outputFile, uint8_t* pixelArray, uint32_t width, uint32_t height);
void WriteGrayscalePNG(FILE* outputFile, uint8_t* pixelArray, uint32_t width, uint32_t height);

