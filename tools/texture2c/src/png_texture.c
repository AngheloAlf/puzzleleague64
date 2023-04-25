#include "png_texture.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "bit_convert.h"
#include "yaz0/yaz0.h"

void PngTexture_CopyRgba16(GenericBuffer* dst, const ImageBackend* textureData) {
    size_t width = textureData->width;
    size_t height = textureData->height;

    for (uint16_t y = 0; y < height; y++) {
        for (uint16_t x = 0; x < width; x++) {
            size_t pos = ((y * width) + x) * 2;
            RGBAPixel pixel = ImageBackend_GetPixel(textureData, y, x);

            uint8_t r = pixel.r / 8;
            uint8_t g = pixel.g / 8;
            uint8_t b = pixel.b / 8;

            uint8_t alphaBit = pixel.a != 0;

            uint16_t data = (r << 11) + (g << 6) + (b << 1) + alphaBit;

            dst->buffer[pos + 0] = (data & 0xFF00) >> 8;
            dst->buffer[pos + 1] = (data & 0x00FF);
        }
    }
}

void PngTexture_CopyRgba32(GenericBuffer* dst, const ImageBackend* textureData) {
    size_t width = textureData->width;
    size_t height = textureData->height;

    for (uint16_t y = 0; y < height; y++) {
        for (uint16_t x = 0; x < width; x++) {
            size_t pos = ((y * width) + x) * 4;
            RGBAPixel pixel = ImageBackend_GetPixel(textureData, y, x);

            dst->buffer[pos + 0] = pixel.r;
            dst->buffer[pos + 1] = pixel.g;
            dst->buffer[pos + 2] = pixel.b;
            dst->buffer[pos + 3] = pixel.a;
        }
    }
}

void PngTexture_CopyI4(GenericBuffer* dst, const ImageBackend* textureData) {
    size_t width = textureData->width;
    size_t height = textureData->height;

    for (uint16_t y = 0; y < height; y++) {
        for (uint16_t x = 0; x < width; x += 2) {
            size_t pos = ((y * width) + x) / 2;
            uint8_t r1 = ImageBackend_GetPixel(textureData, y, x).r;
            uint8_t r2 = ImageBackend_GetPixel(textureData, y, x + 1).r;

            dst->buffer[pos] = (uint8_t)(((r1 / 16) << 4) + (r2 / 16));
        }
    }
}

void PngTexture_CopyI8(GenericBuffer* dst, const ImageBackend* textureData) {
    size_t width = textureData->width;
    size_t height = textureData->height;

    for (uint16_t y = 0; y < height; y++) {
        for (uint16_t x = 0; x < width; x++) {
            size_t pos = (y * width) + x;
            RGBAPixel pixel = ImageBackend_GetPixel(textureData, y, x);
            dst->buffer[pos] = pixel.r;
        }
    }
}

void PngTexture_CopyIA4(GenericBuffer* dst, const ImageBackend* textureData) {
    size_t width = textureData->width;
    size_t height = textureData->height;

    for (uint16_t y = 0; y < height; y++) {
        for (uint16_t x = 0; x < width; x += 2) {
            size_t pos = ((y * width) + x) / 2;
            uint8_t data = 0;

            for (uint16_t i = 0; i < 2; i++) {
                RGBAPixel pixel = ImageBackend_GetPixel(textureData, y, x + i);
                uint8_t cR = pixel.r;
                uint8_t alphaBit = pixel.a != 0;

                if (i == 0)
                    data |= (((cR / 32) << 1) + alphaBit) << 4;
                else
                    data |= ((cR / 32) << 1) + alphaBit;
            }

            dst->buffer[pos] = data;
        }
    }
}

void PngTexture_CopyIA8(GenericBuffer* dst, const ImageBackend* textureData) {
    size_t width = textureData->width;
    size_t height = textureData->height;

    for (uint16_t y = 0; y < height; y++) {
        for (uint16_t x = 0; x < width; x++) {
            size_t pos = ((y * width) + x) * 1;
            RGBAPixel pixel = ImageBackend_GetPixel(textureData, y, x);

            uint8_t r = pixel.r;
            uint8_t a = pixel.a;

            dst->buffer[pos] = ((r / 16) << 4) + (a / 16);
        }
    }
}

void PngTexture_CopyIA16(GenericBuffer* dst, const ImageBackend* textureData) {
    size_t width = textureData->width;
    size_t height = textureData->height;

    for (uint16_t y = 0; y < height; y++) {
        for (uint16_t x = 0; x < width; x++) {
            size_t pos = ((y * width) + x) * 2;
            RGBAPixel pixel = ImageBackend_GetPixel(textureData, y, x);

            uint8_t cR = pixel.r;
            uint8_t aR = pixel.a;

            dst->buffer[pos + 0] = cR;
            dst->buffer[pos + 1] = aR;
        }
    }
}

void PngTexture_CopyCI4(GenericBuffer* dst, const ImageBackend* textureData) {
    size_t width = textureData->width;
    size_t height = textureData->height;

    for (uint16_t y = 0; y < height; y++) {
        for (uint16_t x = 0; x < width; x += 2) {
            size_t pos = ((y * width) + x) / 2;

            uint8_t cR1 = ImageBackend_GetIndexedPixel(textureData, y, x);
            uint8_t cR2 = ImageBackend_GetIndexedPixel(textureData, y, x + 1);

            dst->buffer[pos] = (cR1 << 4) | (cR2);
        }
    }
}

void PngTexture_CopyCI8(GenericBuffer* dst, const ImageBackend* textureData) {
    size_t width = textureData->width;
    size_t height = textureData->height;

    for (uint16_t y = 0; y < height; y++) {
        for (uint16_t x = 0; x < width; x++) {
            size_t pos = ((y * width) + x);
            uint8_t cR = ImageBackend_GetIndexedPixel(textureData, y, x);

            dst->buffer[pos] = cR;
        }
    }
}

typedef void (*CopyPngCallbacks)(GenericBuffer* dst, const ImageBackend* textureData);

CopyPngCallbacks readPngArray[TextureType_Max] = {
    [TextureType_rgba16] = PngTexture_CopyRgba16, [TextureType_rgba32] = PngTexture_CopyRgba32,
    [TextureType_i4] = PngTexture_CopyI4,         [TextureType_i8] = PngTexture_CopyI8,
    [TextureType_ia4] = PngTexture_CopyIA4,       [TextureType_ia8] = PngTexture_CopyIA8,
    [TextureType_ia16] = PngTexture_CopyIA16,     [TextureType_ci4] = PngTexture_CopyCI4,
    [TextureType_ci8] = PngTexture_CopyCI8,
};

void PngTexture_CopyPng(GenericBuffer* dst, const ImageBackend* textureData, TextureType texType) {
    assert(dst != NULL);
    assert(textureData != NULL);
    assert(texType >= 0 && texType < TextureType_Max);
    // TODO?
    assert(!dst->hasData);

    dst->bufferSize = textureData->width * textureData->height * PngTexture_BitsPerPixel(texType) / 8;
    dst->bufferLength = dst->bufferSize;
    dst->buffer = calloc(dst->bufferSize, sizeof(uint8_t));

    readPngArray[texType](dst, textureData);

    dst->hasData = true;
}

void PngTexture_CopyPalette(GenericBuffer* dst, const ImageBackend* textureData) {
    assert(dst != NULL);
    assert(textureData != NULL);
    // TODO?
    assert(!dst->hasData);

    dst->bufferSize = textureData->paletteLen * 2;
    dst->bufferLength = dst->bufferSize;
    dst->buffer = calloc(dst->bufferSize, sizeof(uint8_t));

    size_t paletteLen = textureData->paletteLen;

    for (uint16_t i = 0; i < paletteLen; i++) {
        size_t pos = i * 2;
        RGBAPixel pixel = ImageBackend_GetPalettePixel(textureData, i);

        uint8_t r = pixel.r / 8;
        uint8_t g = pixel.g / 8;
        uint8_t b = pixel.b / 8;

        uint8_t alphaBit = pixel.a != 0;

        uint16_t data = (r << 11) + (g << 6) + (b << 1) + alphaBit;

        dst->buffer[pos + 0] = (data & 0xFF00) >> 8;
        dst->buffer[pos + 1] = (data & 0x00FF);
    }

    dst->hasData = true;
}

uint32_t PngTexture_BitsPerPixel(TextureType texType) {
    switch (texType) {
        case TextureType_rgba32:
            return 32;

        case TextureType_rgba16:
        case TextureType_ia16:
            return 16;

        case TextureType_i8:
        case TextureType_ia8:
        case TextureType_ci8:
            return 8;

        case TextureType_i4:
        case TextureType_ia4:
        case TextureType_ci4:
            return 4;

        case TextureType_Max:
            break;
    }

    return -1;
}
