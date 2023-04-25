#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <png.h>

/* ByteBuffer */

typedef struct {
    size_t length;
    uint8_t* bytes;
} ByteBuffer;

ByteBuffer* Buffer_Create(ByteBuffer* buffer, size_t length) {
    buffer->bytes = malloc(length);
    buffer->length = length;
    return buffer;
}

ByteBuffer* Buffer_Resize(ByteBuffer* buffer, size_t newLength) {
    buffer->bytes = realloc(buffer->bytes, newLength);
    buffer->length = newLength;
    return buffer;
}

ByteBuffer* Buffer_Append(ByteBuffer* buffer, uint8_t* appendage, size_t length) {
    size_t currentEnd = buffer->length;

    Buffer_Resize(buffer, buffer->length + length);
    memcpy(&buffer->bytes[currentEnd], appendage, length);
    return buffer;
}

void Buffer_Free(ByteBuffer* buffer) {
    free(buffer->bytes);
}

/* Conversion */

void I1_UnpackByte(uint8_t* dest, uint8_t byte) {
    int i;
    for (i = 0; i < 8; i++) {
        dest[i] = (byte >> (7-i)) & 1;
    }
}

int main(int argc, char** argv) {
    FILE* inFile;
    // FILE* outFile = fopen("crash_screen_font.png", "wb");
    size_t inFileSize;
    ByteBuffer inData;
    ByteBuffer bitArray;

    inFile = fopen("crash_screen_font.bin", "rb");

    fseek(inFile, 0, SEEK_END);
    inFileSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);

    Buffer_Create(&inData, inFileSize);
    fread(inData.bytes, inFileSize, 1, inFile);

    fclose(inFile);

    Buffer_Create(&bitArray, inFileSize * 8);

    {
        size_t i;
        for (i = 0; i < inData.length; i++) {
            I1_UnpackByte( &bitArray.bytes[8 * i], inData.bytes[i]);
        }
    }
    Buffer_Free(&inData);

    {
        size_t charWidth   = 6;
        size_t charHeight  = 7;
        size_t imageWidth  = 32;
        size_t imageHeight = 64;

        size_t charsPerRow = imageWidth / charWidth;
        size_t charRows = imageHeight / charHeight;

        size_t charNum = 35;

        for (charNum = 0; charNum < charRows * charsPerRow; charNum++) {

            size_t charPos[2] = { charNum % charsPerRow, charNum / charsPerRow };
            size_t charStart = charPos[0] * charWidth + charPos[1] * imageWidth * charHeight;

            printf("%X, %X, %X\n", charPos[0], charPos[1], charStart);

            {
                size_t i;
                size_t index = charStart;
                printf("+------------+\n");
                printf("|");
                for (i = 0; i < charWidth * charHeight; i++, index++) {

                    printf("%s", bitArray.bytes[index] ? "\x1b[47m  \x1b[0m" : "  ");
                    if (((i + 1) % charWidth) == 0) {
                        printf("|\n");
                        if (((i + 1) % (charWidth * charHeight)) != 0) {
                            printf("|");
                        }
                        index += imageWidth - charWidth;
                    }
                }
                printf("+------------+\n");
            }
        }

    }


    // {
    //     size_t i;
    //     printf("  ");
    //     for (i = 0; i < 32; i++) {
    //         printf("%2d", i);
    //     }
    //     for (i = 0; i < bitArray.length; i++) {
    //         if ((i & 0x1F) == 0) {
    //             putchar('\n');
    //             printf("%2d ", i / 0x20);
    //         }
    //         printf("%s", bitArray.bytes[i] ? "\x1b[47m  \x1b[0m" : "  ");
    //     }
    //     putchar('\n');
    // }
    Buffer_Free(&bitArray);

    return 0;
}
