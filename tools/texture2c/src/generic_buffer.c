#include "generic_buffer.h"

#include <assert.h>
#include <string.h>
#include <inttypes.h>

#include "bit_convert.h"
#include "yaz0/yaz0.h"
#include "macros.h"

void GenericBuffer_Init(GenericBuffer* buffer) {
    buffer->buffer = NULL;
    buffer->bufferSize = 0;
    buffer->bufferLength = 0;
    buffer->hasData = false;
    buffer->isCompressed = false;
}

void GenericBuffer_Destroy(GenericBuffer* buffer) {
    if (buffer->buffer != NULL) {
        free(buffer->buffer);
    }
}

void GenericBuffer_WriteAsRawCArray(GenericBuffer* buffer, TypeBitWidth bitWidth, FILE* outFile) {
    assert(buffer->hasData);
    assert(bitWidth >= 0 && bitWidth < TypeBitWidth_Max);
    assert(outFile != NULL);

    size_t step = 8;
    size_t elementsPerLine = 4;
    switch (bitWidth) {
        case TypeBitWidth_64:
            step = 8;
            elementsPerLine = 4;
            break;
        case TypeBitWidth_32:
            step = 4;
            elementsPerLine = 8;
            break;

        case TypeBitWidth_16:
            step = 2;
            elementsPerLine = 16;
            break;

        case TypeBitWidth_8:
            step = 1;
            elementsPerLine = 32;
            break;

        default:
            break;
    }

    size_t i;
    for (i = 0; i < buffer->bufferLength; i += step) {
        if ((i / step) % elementsPerLine == 0) {
            fprintf(outFile, "    ");
        }

        switch (bitWidth) {
            case TypeBitWidth_64:
                fprintf(outFile, "0x%016" PRIX64 ", ", ToUInt64BE(buffer->buffer, i));
                break;

            case TypeBitWidth_32:
                fprintf(outFile, "0x%08" PRIX32 ", ", ToUInt32BE(buffer->buffer, i));
                break;

            case TypeBitWidth_16:
                fprintf(outFile, "0x%04" PRIX16 ", ", ToUInt16BE(buffer->buffer, i));
                break;

            case TypeBitWidth_8:
                fprintf(outFile, "0x%02" PRIX8 ", ", ToUInt8BE(buffer->buffer, i));
                break;

            default:
                break;
        }

        if ((i / step + 1) % elementsPerLine == 0) {
            fprintf(outFile, "\n");
        }
    }

    // Ensure there's a newline at the end
    if ((i / step) % elementsPerLine != 0) {
        fprintf(outFile, "\n");
    }
}

void GenericBuffer_ReadBinary(GenericBuffer* buffer, FILE* inFile) {
    assert(!buffer->hasData);

    long startingPoint = ftell(inFile);
    fseek(inFile, 0, SEEK_END);
    buffer->bufferSize = ftell(inFile) - startingPoint;
    fseek(inFile, startingPoint, SEEK_SET);

    buffer->buffer = malloc(buffer->bufferSize * sizeof(uint8_t));

    buffer->bufferLength = fread(buffer->buffer, sizeof(uint8_t), buffer->bufferSize, inFile);

    assert(buffer->bufferLength <= buffer->bufferSize);

    buffer->hasData = true;
}

void GenericBuffer_Yaz0Compress(GenericBuffer* buffer) {
    assert(buffer->hasData);
    assert(!buffer->isCompressed);

    size_t uncompressedSize = buffer->bufferLength;

    uint8_t* tempBuffer = malloc(uncompressedSize * sizeof(uint8_t) * 2);

    // compress data
    size_t compSize = yaz0_encode(buffer->buffer, tempBuffer, uncompressedSize);

    // make Yaz0 header
    uint8_t header[16] = { 0 };
    header[0] = 'Y';
    header[1] = 'a';
    header[2] = 'z';
    header[3] = '0';
    FromUInt32ToBE(header, 4, uncompressedSize);

    memcpy(buffer->buffer, header, ARRAY_COUNT(header));
    memcpy(buffer->buffer + ARRAY_COUNT(header), tempBuffer, compSize);

    buffer->bufferLength = ARRAY_COUNT(header) + compSize;
    buffer->isCompressed = true;

    free(tempBuffer);
}

void GenericBuffer_Yaz0Decompress(GenericBuffer* buffer) {
    assert(buffer->hasData);
    assert(buffer->isCompressed);

    if (buffer->buffer[0] != 'Y' || buffer->buffer[1] != 'a' || buffer->buffer[2] != 'z' || buffer->buffer[3] != '0') {
        assert(!"Missing Yaz0 header");
    }
    size_t uncompressedSize = ToUInt32BE(buffer->buffer, 4);

    uint8_t* tempBuffer = malloc(uncompressedSize * sizeof(uint8_t));

    yaz0_decode(buffer->buffer + 16, tempBuffer, uncompressedSize);

    memcpy(buffer->buffer, tempBuffer, uncompressedSize);

    buffer->bufferLength = uncompressedSize;
    buffer->isCompressed = false;

    free(tempBuffer);
}
