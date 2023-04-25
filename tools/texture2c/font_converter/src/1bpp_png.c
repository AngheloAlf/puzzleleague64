#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <png.h>

#include "image_backend.h"

void Write1bppPNG(FILE* outputFile, uint8_t* pixelArray, uint32_t width, uint32_t height) {
    ImageBackend image;

    ImageBackend_Init(&image);

    image.width = width;
    image.height = height;
    image.pixelMatrix = (uint8_t**)malloc(sizeof(uint8_t*) * image.height);
    {
        size_t y;
        for (y = 0; y < image.height; y++) {
            image.pixelMatrix[y] = (uint8_t*)calloc(image.width / 8, sizeof(uint8_t));
        }
    }
    image.paletteLen = 0;
    image.colorType = PNG_COLOR_TYPE_GRAY;
    image.bitDepth = 1;
    image.hasImageData = true;
    image.isColorIndexed = false;
    puts("Set up image struct");
    {
        size_t row;
        for (row = 0; row < height; row++) {
            size_t column;
            printf("start row %zd\n", row);
            for (column = 0; column < width; column++) {
                // printf("%d\n", pixelArray[width * row + column] << (7 - column & 7));
                image.pixelMatrix[row][column / 8] |= pixelArray[width * row + column] << (7 - column & 7);
            }
            printf("row %zd done\n", row);
        }
    }
    puts("Set up pixels");

    ImageBackend_WritePng(&image, outputFile);
    ImageBackend_Destroy(&image);
}

void WriteGrayscalePNG(FILE* outputFile, uint8_t* pixelArray, uint32_t width, uint32_t height) {
    ImageBackend image;

    ImageBackend_Init(&image);
    ImageBackend_InitEmptyRGBImage(&image, width, height, false);

    {
        size_t currentPixel;
        for (currentPixel = 0; currentPixel < width * height; currentPixel++) {
            uint8_t grayscale =  ( (pixelArray[currentPixel] != 0) ? 255 : 0 );
            uint8_t alpha = grayscale; 
            ImageBackend_SetGrayscalePixel(&image, currentPixel / width, currentPixel % width, grayscale, alpha);
        }
    }

    ImageBackend_WritePng(&image, outputFile);
    ImageBackend_Destroy(&image);
}
