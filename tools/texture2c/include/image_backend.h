#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct RGBAPixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} RGBAPixel;

void RGBAPixel_Init(RGBAPixel* pixel);

void RGBAPixel_SetRGBA(RGBAPixel* pixel, uint8_t nR, uint8_t nG, uint8_t nB, uint8_t nA);
void RGBAPixel_SetGrayscale(RGBAPixel* pixel, uint8_t grayscale, uint8_t alpha);

typedef struct RGBPixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} RGBPixel;

typedef struct ImageBackend {
    uint8_t** pixelMatrix; // height * [width * bytePerPixel]

    RGBPixel colorPalette[256];
    uint8_t alphaPalette[256];
    size_t paletteLen;

    uint32_t width;
    uint32_t height;
    uint8_t colorType;
    uint8_t bitDepth;

    bool hasImageData;
    bool isColorIndexed;
} ImageBackend;

/* public */

void ImageBackend_Init(ImageBackend* image);
void ImageBackend_Destroy(ImageBackend* image);

void ImageBackend_ReadPng(ImageBackend* image, FILE* inFile);
void ImageBackend_WritePng(ImageBackend* image, FILE* outFile);

void ImageBackend_InitEmptyRGBImage(ImageBackend* image, uint32_t nWidth, uint32_t nHeight, bool alpha);
void ImageBackend_InitEmptyPaletteImage(ImageBackend* image, uint32_t nWidth, uint32_t nHeight);

RGBAPixel ImageBackend_GetPixel(const ImageBackend* image, size_t y, size_t x);
uint8_t ImageBackend_GetIndexedPixel(const ImageBackend* image, size_t y, size_t x);
RGBAPixel ImageBackend_GetPalettePixel(const ImageBackend* image, size_t index);

void ImageBackend_SetRGBPixel(ImageBackend* image, size_t y, size_t x, uint8_t nR, uint8_t nG, uint8_t nB, uint8_t nA);
void ImageBackend_SetGrayscalePixel(ImageBackend* image, size_t y, size_t x, uint8_t grayscale, uint8_t alpha);

void ImageBackend_SetIndexedPixel(ImageBackend* image, size_t y, size_t x, uint8_t index, uint8_t grayscale);
void ImageBackend_SetPaletteIndex(ImageBackend* image, size_t index, uint8_t nR, uint8_t nG, uint8_t nB, uint8_t nA);
void ImageBackend_SetPalette(ImageBackend* image, const ImageBackend* pal);

bool ImageBackend_ConvertToColorIndexed(ImageBackend* image);

double ImageBackend_GetBytesPerPixel(const ImageBackend* image);

void ImageBackend_FreeImageData(ImageBackend* image);
