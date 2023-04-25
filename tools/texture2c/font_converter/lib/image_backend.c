#include "image_backend.h"

#include <assert.h>
#include <string.h>
#include <png.h>

#include "macros.h"

/* ImageBackend */

void ImageBackend_Init(ImageBackend* image) {
    image->pixelMatrix = NULL;

    memset(image->colorPalette, 0, ARRAY_COUNT(image->colorPalette));
    memset(image->alphaPalette, 0, ARRAY_COUNT(image->alphaPalette));
    image->paletteLen = ARRAY_COUNT(image->colorPalette);

    image->width = 0;
    image->height = 0;
    image->colorType = 0;
    image->bitDepth = 0;

    image->hasImageData = false;
    image->isColorIndexed = false;
}

void ImageBackend_Destroy(ImageBackend* image) {
    ImageBackend_FreeImageData(image);
}

void ImageBackend_ReadPng(ImageBackend* image, FILE* inFile) {
    assert(image != NULL);
    assert(inFile != NULL);
    ImageBackend_FreeImageData(image);

    png_structp png = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (png == NULL) {
        // throw std::runtime_error("ImageBackend::ReadPng: Error.\n\t Couldn't
        // create png struct.");
        // TODO
        assert(!"Couldn't create png struct");
    }

    png_infop info = png_create_info_struct(png);
    if (info == NULL) {
        // throw std::runtime_error("ImageBackend::ReadPng: Error.\n\t Couldn't
        // create png info.");
        // TODO
        assert(!"Couldn't create png info");
    }

    if (setjmp(png_jmpbuf(png))) {
        // throw std::runtime_error("ImageBackend_ReadPng: Error.\n\t
        // setjmp(png_jmpbuf(ImageBackend* image,png)).");
        // TODO
        assert(!"setjmp(png_jmpbuf(png))");
    }

    png_init_io(png, inFile);

    png_read_info(png, info);

    image->width = png_get_image_width(png, info);
    image->height = png_get_image_height(png, info);
    image->colorType = png_get_color_type(png, info);
    image->bitDepth = png_get_bit_depth(png, info);

#ifdef TEXTURE_DEBUG
    printf("Width: %u\n", image->width);
    printf("Height: %u\n", image->height);
    printf("ColorType: ");
    switch (image->colorType) {
        case PNG_COLOR_TYPE_RGBA:
            printf("PNG_COLOR_TYPE_RGBA\n");
            break;

        case PNG_COLOR_TYPE_RGB:
            printf("PNG_COLOR_TYPE_RGB\n");
            break;

        case PNG_COLOR_TYPE_PALETTE:
            printf("PNG_COLOR_TYPE_PALETTE\n");
            break;

        default:
            printf("%u\n", image->colorType);
            break;
    }
    printf("BitDepth: %u\n", image->bitDepth);
    printf("\n");
#endif

    // Read any color_type into 8bit depth, RGBA format.
    // See http://www.libpng.org/pub/png/libpng-manual.txt

    if (image->bitDepth == 16)
        png_set_strip_16(png);

    if (image->colorType == PNG_COLOR_TYPE_PALETTE) {
        // png_set_palette_to_rgb(png);
        image->isColorIndexed = true;

        int paletteSizeTemp = 256;
        png_color* colorPaletteTemp;

        png_get_PLTE(png, info, &colorPaletteTemp, &paletteSizeTemp);
        assert(paletteSizeTemp <= ARRAY_COUNT(image->colorPalette));
        image->paletteLen = paletteSizeTemp;

        memcpy(image->colorPalette, colorPaletteTemp, paletteSizeTemp);

#ifdef TEXTURE_DEBUG
        {
            printf("palette\n  size: %zu\n", image->paletteSize);
            png_color* aux = (png_color*)image->colorPalette;
            for (size_t y = 0; y < image->paletteSize; y++) {
                printf("#%02X%02X%02X ", aux[y].red, aux[y].green, aux[y].blue);
                if ((y + 1) % 8 == 0)
                    printf("\n");
            }
            printf("\n");
        }
#endif

        png_byte* alphaPaletteTemp;
        png_get_tRNS(png, info, &alphaPaletteTemp, &paletteSizeTemp, NULL);
        assert(paletteSizeTemp <= ARRAY_COUNT(image->alphaPalette));

        memcpy(image->alphaPalette, alphaPaletteTemp, paletteSizeTemp);

#ifdef TEXTURE_DEBUG
        {
            printf("alpha\n  size: %i\n", paletteSizeTemp);
            png_byte* aux = (png_byte*)image->colorPalette;
            for (size_t y = 0; y < image->paletteSize; y++) {
                printf("%02X ", aux[y]);
                if ((y + 1) % 8 == 0)
                    printf("\n");
            }
            printf("\n");
        }
#endif
    }

    // PNG_COLOR_TYPE_GRAY_ALPHA is always 8 or 16bit depth.
    if (image->colorType == PNG_COLOR_TYPE_GRAY && image->bitDepth < 8)
        png_set_expand_gray_1_2_4_to_8(png);

    /*if (png_get_valid(png, info, PNG_INFO_tRNS))
        png_set_tRNS_to_alpha(png);*/

    // These color_type don't have an alpha channel then fill it with 0xff.
    /*if(*color_type == PNG_COLOR_TYPE_RGB ||
        *color_type == PNG_COLOR_TYPE_GRAY ||
        *color_type == PNG_COLOR_TYPE_PALETTE)
        png_set_filler(png, 0xFF, PNG_FILLER_AFTER);*/

    if (image->colorType == PNG_COLOR_TYPE_GRAY || image->colorType == PNG_COLOR_TYPE_GRAY_ALPHA)
        png_set_gray_to_rgb(png);

    png_read_update_info(png, info);

    size_t rowBytes = png_get_rowbytes(png, info);
    image->pixelMatrix = (uint8_t**)malloc(sizeof(uint8_t*) * image->height);
    for (size_t y = 0; y < image->height; y++) {
        image->pixelMatrix[y] = (uint8_t*)malloc(rowBytes);
    }

    png_read_image(png, image->pixelMatrix);

#ifdef TEXTURE_DEBUG
    printf("rowBytes: %zu\n", rowBytes);

    size_t bytePerPixel = ImageBackend_GetBytesPerPixel(image);
    printf("bytePerPixel: %zu\n", bytePerPixel);
    printf("imgData\n");
    for (size_t y = 0; y < image->height; y++) {
        for (size_t x = 0; x < image->width; x++) {
            for (size_t z = 0; z < bytePerPixel; z++) {
                printf("%02X ", image->pixelMatrix[y][x * bytePerPixel + z]);
            }
            printf(" ");
        }
        printf("\n");
    }
    printf("\n");
#endif

    png_destroy_read_struct(&png, &info, NULL);

    image->hasImageData = true;
}

void ImageBackend_WritePng(ImageBackend* image, FILE* outFile) {
    assert(image != NULL);
    assert(outFile != NULL);
    assert(image->hasImageData);

    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png) {
        // throw std::runtime_error("ImageBackend::WritePng: Error.\n\t Couldn't
        // create png struct.");
        // TODO
        assert(!"Couldn't create png struct");
    }

    png_infop info = png_create_info_struct(png);
    if (info == NULL) {
        // throw std::runtime_error("ImageBackend::WritePng: Error.\n\t Couldn't
        // create png info.");
        // TODO
        assert(!"Couldn't create png info");
    }

    if (setjmp(png_jmpbuf(png))) {
        // throw std::runtime_error("ImageBackend_WritePng: Error.\n\t
        // setjmp(png_jmpbuf(ImageBackend* image,png)).");
        // TODO
        assert(!"setjmp(png_jmpbuf(png))");
    }

    png_init_io(png, outFile);

    png_set_IHDR(png, info, image->width, image->height,
                 image->bitDepth,  // 8,
                 image->colorType, // PNG_COLOR_TYPE_RGBA,
                 PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    if (image->isColorIndexed) {
        png_set_PLTE(png, info, (png_color*)image->colorPalette, image->paletteLen);

#ifdef TEXTURE_DEBUG
        printf("palette\n");
        png_color* aux = (png_color*)image->colorPalette;
        for (size_t y = 0; y < image->paletteSize; y++) {
            printf("#%02X%02X%02X ", aux[y].red, aux[y].green, aux[y].blue);
            if ((y + 1) % 8 == 0)
                printf("\n");
        }
        printf("\n");
#endif

        png_set_tRNS(png, info, image->alphaPalette, image->paletteLen, NULL);
    }

    png_write_info(png, info);

    // To remove the alpha channel for PNG_COLOR_TYPE_RGB format,
    // Use png_set_filler().
    // png_set_filler(png, 0, PNG_FILLER_AFTER);

#ifdef TEXTURE_DEBUG
    size_t bytePerPixel = ImageBackend_GetBytesPerPixel(image);
    printf("imgData\n");
    for (size_t y = 0; y < image->height; y++) {
        for (size_t x = 0; x < image->width * bytePerPixel; x++) {
            printf("%02X ", image->pixelMatrix[y][x]);
        }
        printf("\n");
    }
    printf("\n");
#endif

    png_write_image(png, image->pixelMatrix);
    png_write_end(png, NULL);

    png_destroy_write_struct(&png, &info);
}

void ImageBackend_InitEmptyRGBImage(ImageBackend* image, uint32_t nWidth, uint32_t nHeight, bool alpha) {
    ImageBackend_FreeImageData(image);

    image->width = nWidth;
    image->height = nHeight;
    image->colorType = PNG_COLOR_TYPE_RGB;
    if (alpha) {
        image->colorType = PNG_COLOR_TYPE_RGBA;
    }
    image->bitDepth = 8; // nBitDepth;

    size_t bytePerPixel = ImageBackend_GetBytesPerPixel(image);

    image->pixelMatrix = (uint8_t**)malloc(sizeof(uint8_t*) * image->height);
    for (size_t y = 0; y < image->height; y++) {
        image->pixelMatrix[y] = (uint8_t*)calloc(image->width * bytePerPixel, sizeof(uint8_t*));
    }

    image->hasImageData = true;
    image->isColorIndexed = false;
}

void ImageBackend_InitEmptyPaletteImage(ImageBackend* image, uint32_t nWidth, uint32_t nHeight) {
    ImageBackend_FreeImageData(image);

    image->width = nWidth;
    image->height = nHeight;
    image->colorType = PNG_COLOR_TYPE_PALETTE;
    image->bitDepth = 8;

    size_t bytePerPixel = ImageBackend_GetBytesPerPixel(image);

    image->pixelMatrix = (uint8_t**)malloc(sizeof(uint8_t*) * image->height);
    for (size_t y = 0; y < image->height; y++) {
        image->pixelMatrix[y] = (uint8_t*)calloc(image->width * bytePerPixel, sizeof(uint8_t*));
    }
    memset(image->colorPalette, 0, ARRAY_COUNT(image->colorPalette));
    memset(image->alphaPalette, 0, ARRAY_COUNT(image->alphaPalette));

    image->hasImageData = true;
    image->isColorIndexed = true;
}

RGBAPixel ImageBackend_GetPixel(const ImageBackend* image, size_t y, size_t x) {
    assert(y < image->height);
    assert(x < image->width);
    assert(!image->isColorIndexed);

    RGBAPixel pixel;
    RGBAPixel_Init(&pixel);

    size_t bytePerPixel = ImageBackend_GetBytesPerPixel(image);
    pixel.r = image->pixelMatrix[y][x * bytePerPixel + 0];
    pixel.g = image->pixelMatrix[y][x * bytePerPixel + 1];
    pixel.b = image->pixelMatrix[y][x * bytePerPixel + 2];
    if (image->colorType == PNG_COLOR_TYPE_RGBA) {
        pixel.a = image->pixelMatrix[y][x * bytePerPixel + 3];
    }
    return pixel;
}

uint8_t ImageBackend_GetIndexedPixel(const ImageBackend* image, size_t y, size_t x) {
    assert(y < image->height);
    assert(x < image->width);
    assert(image->isColorIndexed);

    return image->pixelMatrix[y][x];
}

RGBAPixel ImageBackend_GetPalettePixel(const ImageBackend* image, size_t index) {
    assert(index < image->paletteLen);
    assert(image->isColorIndexed);

    RGBAPixel pixel;
    RGBAPixel_Init(&pixel);

    pixel.r = image->colorPalette[index].r;
    pixel.g = image->colorPalette[index].g;
    pixel.b = image->colorPalette[index].b;
    pixel.a = image->alphaPalette[index];

    return pixel;
}

void ImageBackend_SetRGBPixel(ImageBackend* image, size_t y, size_t x, uint8_t nR, uint8_t nG, uint8_t nB, uint8_t nA) {
    assert(image->hasImageData);
    assert(y < image->height);
    assert(x < image->width);

    size_t bytePerPixel = ImageBackend_GetBytesPerPixel(image);
    image->pixelMatrix[y][x * bytePerPixel + 0] = nR;
    image->pixelMatrix[y][x * bytePerPixel + 1] = nG;
    image->pixelMatrix[y][x * bytePerPixel + 2] = nB;
    if (image->colorType == PNG_COLOR_TYPE_RGBA) {
        image->pixelMatrix[y][x * bytePerPixel + 3] = nA;
    }
}

void ImageBackend_SetGrayscalePixel(ImageBackend* image, size_t y, size_t x, uint8_t grayscale, uint8_t alpha) {
    assert(image->hasImageData);
    assert(y < image->height);
    assert(x < image->width);

    size_t bytePerPixel = ImageBackend_GetBytesPerPixel(image);
    image->pixelMatrix[y][x * bytePerPixel + 0] = grayscale;
    image->pixelMatrix[y][x * bytePerPixel + 1] = grayscale;
    image->pixelMatrix[y][x * bytePerPixel + 2] = grayscale;
    if (image->colorType == PNG_COLOR_TYPE_RGBA)
        image->pixelMatrix[y][x * bytePerPixel + 3] = alpha;
}

void ImageBackend_SetIndexedPixel(ImageBackend* image, size_t y, size_t x, uint8_t index, uint8_t grayscale) {
    assert(image->hasImageData);
    assert(y < image->height);
    assert(x < image->width);

    size_t bytePerPixel = ImageBackend_GetBytesPerPixel(image);
    image->pixelMatrix[y][x * bytePerPixel + 0] = index;

    assert(index < image->paletteLen);
    png_color* pal = (png_color*)image->colorPalette;
    pal[index].red = grayscale;
    pal[index].green = grayscale;
    pal[index].blue = grayscale;
    image->alphaPalette[index] = 255;
}

void ImageBackend_SetPaletteIndex(ImageBackend* image, size_t index, uint8_t nR, uint8_t nG, uint8_t nB, uint8_t nA) {
    assert(image->isColorIndexed);
    assert(index < image->paletteLen);

    png_color* pal = (png_color*)image->colorPalette;
    pal[index].red = nR;
    pal[index].green = nG;
    pal[index].blue = nB;
    image->alphaPalette[index] = nA;
}

void ImageBackend_SetPalette(ImageBackend* image, const ImageBackend* pal) {
    assert(image->isColorIndexed);
    size_t bytePerPixel = ImageBackend_GetBytesPerPixel(pal);

    for (size_t y = 0; y < pal->height; y++) {
        for (size_t x = 0; x < pal->width; x++) {
            size_t index = y * pal->width + x;
            if (index >= image->paletteLen) {
                /*
                 * Some TLUTs are bigger than 256 colors.
                 * For those cases, we will only take the first 256
                 * to colorize this CI texture.
                 */
                return;
            }

            uint8_t r = pal->pixelMatrix[y][x * bytePerPixel + 0];
            uint8_t g = pal->pixelMatrix[y][x * bytePerPixel + 1];
            uint8_t b = pal->pixelMatrix[y][x * bytePerPixel + 2];
            uint8_t a = pal->pixelMatrix[y][x * bytePerPixel + 3];
            ImageBackend_SetPaletteIndex(image, index, r, g, b, a);
        }
    }
}

bool ImageBackend_ConvertToColorIndexed(ImageBackend* image) {
    assert(!image->isColorIndexed);

    size_t bytePerPixel = ImageBackend_GetBytesPerPixel(image);
    size_t paletteMax = 0;

    // Create palette
    for (size_t y = 0; y < image->height; y++) {
        for (size_t x = 0; x < image->width; x++) {
            RGBAPixel pixel;
            RGBAPixel_Init(&pixel);

            pixel.r = image->pixelMatrix[y][x * bytePerPixel + 0];
            pixel.g = image->pixelMatrix[y][x * bytePerPixel + 1];
            pixel.b = image->pixelMatrix[y][x * bytePerPixel + 2];
            pixel.a = 255;
            if (image->colorType == PNG_COLOR_TYPE_RGBA) {
                pixel.a = image->pixelMatrix[y][x * bytePerPixel + 3];
            }

            bool wasColorPreviouslyAdded = false;
            for (size_t i = 0; i < paletteMax; i++) {
                RGBPixel* tempPixel = &image->colorPalette[i];

                if (tempPixel->r == pixel.r && tempPixel->g == pixel.g && tempPixel->b == pixel.b) {
                    if (image->alphaPalette[i] == pixel.a) {
                        wasColorPreviouslyAdded = true;
                        break;
                    }
                }
            }

            if (!wasColorPreviouslyAdded) {
                if (paletteMax >= ARRAY_COUNT(image->colorPalette)){
                    return false;
                }

                image->colorPalette[paletteMax].r = pixel.r;
                image->colorPalette[paletteMax].g = pixel.g;
                image->colorPalette[paletteMax].b = pixel.b;
                image->alphaPalette[paletteMax] = pixel.a;

                paletteMax++;
            }
        }
    }

    // Palettize the pixel matrix
    for (size_t y = 0; y < image->height; y++) {
        for (size_t x = 0; x < image->width; x++) {
            RGBAPixel pixel;
            RGBAPixel_Init(&pixel);

            pixel.r = image->pixelMatrix[y][x * bytePerPixel + 0];
            pixel.g = image->pixelMatrix[y][x * bytePerPixel + 1];
            pixel.b = image->pixelMatrix[y][x * bytePerPixel + 2];
            pixel.a = 255;
            if (image->colorType == PNG_COLOR_TYPE_RGBA) {
                pixel.a = image->pixelMatrix[y][x * bytePerPixel + 3];
            }

            for (size_t i = 0; i < paletteMax; i++) {
                RGBPixel* tempPixel = &image->colorPalette[i];

                if (tempPixel->r == pixel.r && tempPixel->g == pixel.g && tempPixel->b == pixel.b) {
                    if (image->alphaPalette[i] == pixel.a) {
                        //image->pixelMatrix[y][x * bytePerPixel + 0] = i;
                        //image->pixelMatrix[y][x * bytePerPixel + 1] = i;
                        //image->pixelMatrix[y][x * bytePerPixel + 2] = i;
                        //if (image->colorType == PNG_COLOR_TYPE_RGBA) {
                        //    image->pixelMatrix[y][x * bytePerPixel + 3] = i;
                        //}
                        image->pixelMatrix[y][x] = i;
                        break;
                    }
                }
            }
        }
    }

    image->paletteLen = paletteMax;

    image->isColorIndexed = true;
    image->colorType = PNG_COLOR_TYPE_PALETTE;
    image->bitDepth = 8;
    return true;
}

double ImageBackend_GetBytesPerPixel(const ImageBackend* image) {
    switch (image->colorType) {
        case PNG_COLOR_TYPE_RGBA:
            return 4 * image->bitDepth / 8;

        case PNG_COLOR_TYPE_RGB:
            return 3 * image->bitDepth / 8;

        case PNG_COLOR_TYPE_PALETTE:
            return 1 * image->bitDepth / 8;

        default:
            // throw std::invalid_argument("ImageBackend_GetBytesPerPixel(ImageBackend*
            // image,):\n\t Invalid color type.");
            // TODO
            assert(!"Invalid color type");
            return -1;
            break;
    }
}

void ImageBackend_FreeImageData(ImageBackend* image) {
    if (image->hasImageData) {
        for (size_t y = 0; y < image->height; y++) {
            free(image->pixelMatrix[y]);
        }
        free(image->pixelMatrix);
        image->pixelMatrix = NULL;
    }

    if (image->isColorIndexed) {
        image->isColorIndexed = false;
    }

    image->hasImageData = false;
}

/* RGBAPixel */

void RGBAPixel_Init(RGBAPixel* pixel) {
    pixel->r = 0;
    pixel->g = 0;
    pixel->b = 0;
    pixel->a = 0;
}

void RGBAPixel_SetRGBA(RGBAPixel* pixel, uint8_t nR, uint8_t nG, uint8_t nB, uint8_t nA) {
    pixel->r = nR;
    pixel->g = nG;
    pixel->b = nB;
    pixel->a = nA;
}

void RGBAPixel_SetGrayscale(RGBAPixel* pixel, uint8_t grayscale, uint8_t alpha) {
    pixel->r = grayscale;
    pixel->g = grayscale;
    pixel->b = grayscale;
    pixel->a = alpha;
}
