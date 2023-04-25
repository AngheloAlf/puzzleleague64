#include "jpeg_texture.h"

#include <assert.h>
#include <string.h>

#include "macros.h"
#include "bit_convert.h"

#define SCREEN_BUFFER_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(uint16_t))

#define JPEG_MARKER 0xFFD8FFE0
#define MARKER_DQT 0xFFDB

void JpegTexture_ReadJpeg(GenericBuffer* dst, FILE* inFile, bool fillBuffer) {
    assert(dst != NULL);
    assert(inFile != NULL);
    // TODO?
    assert(!dst->hasData);

    GenericBuffer_ReadBinary(dst, inFile);

    if (fillBuffer) {
        dst->bufferSize = SCREEN_BUFFER_SIZE;
        dst->buffer = realloc(dst->buffer, dst->bufferSize);
        assert(dst->buffer != NULL);
        dst->bufferLength = dst->bufferSize;
    }
}

void JpegTexture_CheckValidJpeg(GenericBuffer* buf) {
    uint32_t jpegMarker = ToUInt32BE(buf->buffer, 0);

    if (jpegMarker != JPEG_MARKER) {
        fprintf(stderr, "Warning: Missing jpeg marker at the beginning of file\n"
                        "\t The game will skip this jpeg.\n");
    }

    if (buf->buffer[6] != 'J' || buf->buffer[7] != 'F' || buf->buffer[8] != 'I' || buf->buffer[9] != 'F' ||
        buf->buffer[10] != '\0') {
        fprintf(stderr,
                "Warning: Missing 'JFIF' identifier.\n"
                "\t This image may be corrupted or not be a jpeg iamge.\n"
                "\t The identifier found was '%c%c%c%c%c'.\n",
                buf->buffer[6], buf->buffer[7], buf->buffer[8], buf->buffer[9], buf->buffer[10]);
    }

    uint8_t majorVersion = buf->buffer[11];
    uint8_t minorVersion = buf->buffer[12];
    if (majorVersion != 0x01 || minorVersion != 0x01) {
        fprintf(stderr,
                "Warning: Wrong JFIF version '%i.%02i'.\n"
                "\t The expected version is '1.01'. The game may not be able to decode this image "
                "properly.\n",
                majorVersion, minorVersion);
    }

    if (ToUInt16BE(buf->buffer, 20) != MARKER_DQT) {
        // This may happen when creating a custom image with Exif, XMP, thumbnail, progressive, etc.
        // enabled.
        fprintf(stderr, "Warning: There seems to be extra data before the image data.\n"
                        "\t The game may not be able to decode this image properly.\n");
    }
    if (buf->bufferLength > SCREEN_BUFFER_SIZE) {
        fprintf(stderr,
                "Warning: The image is bigger than the screen buffer.\n"
                "\t Image size: %zu bytes.\n"
                "\t Screen buffer size: %zu bytes.\n",
                buf->bufferLength, SCREEN_BUFFER_SIZE);
    }
}
