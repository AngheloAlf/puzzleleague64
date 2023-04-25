/**
 * Information in this file and the corresponding C file taken from
 * https://cdn.hackaday.io/files/274271173436768/Simplified%20Windows%20BMP%20Bitmap%20File%20Format%20Specification.htm
 */

#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>
// #include <stdlib.h>

typedef struct {
    /* 0x0 */ char bfType[2];      /* The characters "BM" */
    /* 0x4 */ int32_t bfSize;      /* The size of the file in bytes */
    /* 0x8 */ int16_t bfReserved1; /* Unused, must be zero */
    /* 0xA */ int16_t bfReserved2; /* Unused, must be zero */
    /* 0xC */ int32_t bfOffBits;   /* Offset of pixel table */
} BMPFileHeader;                   /* size = 0x10, but squashes to 14 */

typedef struct {
    /* 0x00 */ uint32_t biSize;          /* Header Size - Must be at least 40 */
    /* 0x04 */ int32_t biWidth;          /* Image width in pixels */
    /* 0x08 */ int32_t biHeight;         /* Image height in pixels, negative for top-down */
    /* 0x0C */ uint16_t biPlanes;        /* Must be 1 */
    /* 0x0E */ uint16_t biBitCount;      /* Bits per pixel - 1, 4, 8, 16, 24, or 32 */
    /* 0x10 */ uint32_t biCompression;   /* Compression type (0 = uncompressed) */
    /* 0x14 */ uint32_t biSizeImage;     /* Image Size - may be zero for uncompressed images */
    /* 0x18 */ uint32_t biXPelsPerMeter; /* Preferred resolution in pixels per meter */
    /* 0x1C */ uint32_t biYPelsPerMeter; /* Preferred resolution in pixels per meter */
    /* 0x20 */ uint32_t biClrUsed;       /* Number Color Map entries that are actually used */
    /* 0x24 */ uint32_t biClrImportant;  /* Number of significant colors */
} BMPImageHeader;                        /* size = 0x28, but misaligned */

typedef struct {
    BMPFileHeader fileHeader;
    BMPImageHeader imageHeader;
    uint32_t* palette;
    uint8_t* pixels;
} BMPFile;

void WriteBMPFile(FILE* outFile, uint8_t* bitArray, size_t width, size_t height);
void ReadBMPHeaders(BMPFile* out, FILE* srcBMP);
bool CheckBMP(BMPFile* file);
void ExtractBMPPixels(uint8_t* out, BMPFile* inputFile, FILE* src);
