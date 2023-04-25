#include "bmp.h"

#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "macros.h"

BMPFileHeader defaultBMPFileHeader = { "BM", -1, 0, 0, -1 };

BMPImageHeader defaultBMPImageHeader = { 40, -1, -1, 1, 1, 0, 0, 0, 0, 0, 0 };

uint32_t defaultBMPPalette[] = { 0x00000000, 0xFFFFFFFF };

#define DEFAULT_BMP_PALETTE \
    { 0x00000000, 0xFFFFFFFF }

#define FILE_HEADER_SIZE 14
#define IMAGE_HEADER_SIZE 40

/* Writing */

void SillyBitpacking(uint8_t* packedArray, uint8_t* bitArray, size_t width, size_t height) {
    size_t bytesPerRow = width / 8 + !!(width & 7);
    size_t padding = (-width / 8) & 3;
    size_t absHeight = ABS(height);
    size_t row;
    size_t column;

    memset(packedArray, 0, (bytesPerRow + padding) * absHeight);

    for (row = 0; row < absHeight; row++) {
        for (column = 0; column < width; column++) {
            packedArray[(bytesPerRow + padding) * row + (column / 8)] |= bitArray[width * row + column]
                                                                         << (7 - (column & 7));
        }
    }
}

void WriteBMPFile(FILE* outFile, uint8_t* bitArray, size_t width, size_t height) {
    BMPFileHeader fileHeader = defaultBMPFileHeader;
    BMPImageHeader imageHeader = defaultBMPImageHeader;
    uint32_t palette[] = DEFAULT_BMP_PALETTE;
    size_t rowPadding = (-width / 8) & 3;
    uint8_t* pixelArray;
    size_t pixelArrayCount = height * (width / 8 + !!(width & 7) + rowPadding);

    assert(width > 0);
    assert(height != 0);
    imageHeader.biWidth = width;
    imageHeader.biHeight = -height;

    fileHeader.bfSize = FILE_HEADER_SIZE + IMAGE_HEADER_SIZE + sizeof(palette) + pixelArrayCount;
    fileHeader.bfOffBits = FILE_HEADER_SIZE + IMAGE_HEADER_SIZE + sizeof(palette);

    pixelArray = malloc(pixelArrayCount);
    SillyBitpacking(pixelArray, bitArray, width, height);

    fwrite(&fileHeader.bfType, 2, 1, outFile);
    fwrite(&fileHeader.bfSize, 4, 1, outFile);
    fwrite(&fileHeader.bfReserved1, 2, 1, outFile);
    fwrite(&fileHeader.bfReserved2, 2, 1, outFile);
    fwrite(&fileHeader.bfOffBits, 4, 1, outFile);

    fwrite(&imageHeader, IMAGE_HEADER_SIZE, 1, outFile);

    fwrite(palette, sizeof(palette), 1, outFile);

    fwrite(pixelArray, pixelArrayCount, 1, outFile);

    free(pixelArray);
}

/* Reading */

void ReadBMPHeaders(BMPFile* out, FILE* srcBMP) {
    fread(&out->fileHeader.bfType, 2, 1, srcBMP);
    fread(&out->fileHeader.bfSize, 4, 1, srcBMP);
    fread(&out->fileHeader.bfReserved1, 2, 1, srcBMP);
    fread(&out->fileHeader.bfReserved2, 2, 1, srcBMP);
    fread(&out->fileHeader.bfOffBits, 4, 1, srcBMP);

    fread(&out->imageHeader, IMAGE_HEADER_SIZE, 1, srcBMP);

    // printf("End process headers\n");
}

bool CheckBMP(BMPFile* file) {
    /* Validity checks */

    if (file->imageHeader.biPlanes != 1) {
        fprintf(stderr, "CheckBMP: error: file is not a valid bitmap file: plane count must be 1\n");
        return false;
    }
    if (file->imageHeader.biWidth <= 0) {
        fprintf(stderr, "CheckBMP: error: not a valid BMP file: image width <= 0\n");
        return false;
    }
    if (file->imageHeader.biHeight == 0) {
        fprintf(stderr, "CheckBMP: error: not a valid BMP file: image height = 0\n");
        return false;
    }
    if (file->fileHeader.bfOffBits > file->fileHeader.bfSize) {
        fprintf(stderr, "CheckBMP: error: not a valid BMP file: pixel array offset is larger than filesize\n");
    }

    /* Supported type checks */

    if (file->fileHeader.bfType[0] != 'B' || file->fileHeader.bfType[1] != 'M') {
        fprintf(stderr, "CheckBMP: error: file is not a supported bitmap type: string is not \"BM\"\n");
        return false;
    }
    if (file->imageHeader.biSize != 0x28) {
        fprintf(stderr, "CheckBMP: error: file is not a supported bitmap type: image header is not 0x28 in size\n");
        return false;
    }
    if (file->fileHeader.bfOffBits != 0x3E) {
        fprintf(stderr,
                "CheckBMP: error: file is not a supported bitmap type: palette does not contain exactly 2 colours\n");
        return false;
    }
    if (file->imageHeader.biHeight > 0) {
        fprintf(stderr, "CheckBMP: error: not a supported BMP file: only top-down are supported\n");
        return false;
    }
    if (file->imageHeader.biBitCount != 1) {
        fprintf(stderr, "CheckBMP: error: not a supported bitmap type: bit depth %d is not 1\n",
                file->imageHeader.biBitCount);
        return false;
    }
    if (file->imageHeader.biCompression != 0) {
        fprintf(stderr, "CheckBMP: error: not a supported bitmap type: only uncompressed are supported\n");
        return false;
    }

    return true;
}

// void UnpackBMP();

void ExtractBMPPixels(uint8_t* pixelsArrayOut, BMPFile* inputFile, FILE* src) {
    // BMPFile inputFile;
    size_t width;
    size_t absHeight;
    size_t rowPadding;
    size_t pixelArrayCount;
    size_t pixelsSize;
    size_t bytesPerRow;
    size_t padding;

    // ReadBMPHeaders(&inputFile, src);
    // CheckBMP(&inputFile);

    width = inputFile->imageHeader.biWidth;
    absHeight = ABS(inputFile->imageHeader.biHeight);
    rowPadding = (-width / 8) & 3;
    pixelArrayCount = absHeight * (width / 8 + !!(width & 7) + rowPadding);
    pixelsSize = inputFile->fileHeader.bfSize - inputFile->fileHeader.bfOffBits;
    bytesPerRow = width / 8 + !!(width & 7);
    padding = (-width / 8) & 3;

    // printf("Malloc for palette\n");
    inputFile->palette = malloc(8 * sizeof(uint8_t));
    fread(inputFile->palette, 8, 1, src);
    // printf("Finish reading input palette\n");

    // printf("Malloc for pixels\n");
    inputFile->pixels = malloc(pixelsSize * sizeof(uint8_t));
    fread(inputFile->pixels, pixelsSize, 1, src);
    // printf("Finish reading input pixels\n");

    {
        size_t row;
        for (row = 0; row < absHeight; row++) {
            size_t column;
            for (column = 0; column < width; column++) {
                pixelsArrayOut[width * row + column] =
                    (inputFile->pixels[(bytesPerRow + padding) * row + (column / 8)] >> (7 - (column & 7))) & 1;
                // printf("%s", (pixelsArrayOut[width * row + column] ? "\x1b[30;47m1,\x1b[0m" : "0,"));
            }
            // printf("\n");
        }
    }

    free(inputFile->palette);
    free(inputFile->pixels);
}
