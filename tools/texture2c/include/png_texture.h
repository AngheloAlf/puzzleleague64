#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "image_backend.h"
#include "generic_buffer.h"

typedef enum TextureType {
    TextureType_rgba16,
    TextureType_rgba32,
    TextureType_i4,
    TextureType_i8,
    TextureType_ia4,
    TextureType_ia8,
    TextureType_ia16,
    TextureType_ci4,
    TextureType_ci8,
    TextureType_Max,
} TextureType;

void PngTexture_CopyPng(GenericBuffer* dst, const ImageBackend* textureData, TextureType texType);
void PngTexture_CopyPalette(GenericBuffer* dst, const ImageBackend* textureData);

uint32_t PngTexture_BitsPerPixel(TextureType texType);
