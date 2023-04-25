#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "1bpp_png.h"
#include "bmp.h"

/* Defines, may replace some with args later */

/* total rows of characters */
#define ROW_MAX 32
/* total characters in one row */
#define CHARACTERS_PER_ROW 2
/* number of palettes */
#define PALETTE_MAX 4
/* height in pixels of one character */
#define CHARACTER_HEIGHT 8
/* width in pixels of one character */
#define CHARACTER_WIDTH 8
/* pixels per array element */
#define PIXEL_DENSITY 2
/* width of character in array elements */
#define CHARACTER_ROW_SIZE CHARACTER_WIDTH / PIXEL_DENSITY

// #undef ROW_MAX
// #define ROW_MAX 2

/* Take PALETTE_MAX bitArrays and join them into a single one, with width 8 * PALETTE_MAX for now */
void JoinToSingleArray(uint8_t** joinedArray, uint8_t** bitArrays, size_t arrayCount) {
    // size_t row;

    *joinedArray = malloc(PIXEL_DENSITY * PALETTE_MAX * arrayCount * sizeof(uint8_t));
    printf("mallocked 0x%zX bytes\n", PALETTE_MAX * arrayCount * sizeof(uint8_t));

    // {
    //     size_t row;
    //     for (row = 0; row < CHARACTER_HEIGHT * ROW_MAX; row++) {
    //         size_t column;
    //         for (column = 0; column < CHARACTER_WIDTH * CHARACTERS_PER_ROW; column++) {
    //             printf("%s", ( bitArrays[0][CHARACTER_WIDTH * CHARACTERS_PER_ROW * row + column] ?
    //             "\x1b[30;47m1,\x1b[0m" : "0," ));
    //         }
    //         puts("");
    //     }
    // }

    // {
    //     size_t row;
    //     for (row = 0; row < CHARACTER_HEIGHT * ROW_MAX; row++) {
    //         size_t charColumn;
    //         for (charColumn = 0; charColumn < CHARACTERS_PER_ROW; charColumn++) {
    //             size_t column;
    //             for (column = 0; column < CHARACTER_WIDTH; column++) {
    //                 size_t currentElement = CHARACTER_WIDTH * CHARACTERS_PER_ROW * row  + CHARACTER_WIDTH *
    //                 charColumn + column; printf("%s", ( bitArrays[0][currentElement] ? "\x1b[30;47m1,\x1b[0m" : "0,"
    //                 ));
    //             }
    //             printf("|");
    //         }
    //         puts("");
    //     }
    // }
    {
        size_t row;
        for (row = 0; row < CHARACTER_HEIGHT * ROW_MAX; row++) {
            // if (row % CHARACTER_HEIGHT == 0) {
            //     puts("+----------------+----------------+----------------+----------------+----------------+----------------+----------------+----------------+");
            // }
            size_t charColumn;
            for (charColumn = 0; charColumn < CHARACTERS_PER_ROW; charColumn++) {
                size_t palette;
                for (palette = 0; palette < PALETTE_MAX; palette++) {
                    size_t column;
                    // printf("|");
                    for (column = 0; column < CHARACTER_WIDTH; column++) {
                        size_t currentSingleElement =
                            CHARACTER_WIDTH * (CHARACTERS_PER_ROW * PALETTE_MAX * row + PALETTE_MAX * charColumn + palette) + column;
                        size_t currentBitElement =
                            CHARACTER_WIDTH * CHARACTERS_PER_ROW * row + CHARACTER_WIDTH * charColumn + column;
                        (*joinedArray)[currentSingleElement] = bitArrays[palette][currentBitElement];
                        // printf("%s", (bitArrays[palette][currentBitElement] ? "\x1b[30;47m1,\x1b[0m" : "0,"));
                        // printf("%s", (joinedArray[currentSingleElement] ? "\x1b[30;47m1,\x1b[0m" : "0,"));
                        // printf("%s", ((*joinedArray)[currentSingleElement] ? "\x1b[47m  \x1b[0m" : "  "));
                    }
                }
            }
            // puts("|");
        }
        // puts("+----------------+----------------+----------------+----------------+----------------+----------------+----------------+----------------+");
    }

    // {
    //     size_t row;
    //     for (row = 0; row < CHARACTER_HEIGHT * ROW_MAX; row++) {
    //         size_t col;
    //         for (col = 0; col < PALETTE_MAX * CHARACTERS_PER_ROW * CHARACTER_WIDTH; col++) {
    //             size_t currentSingleElement = PALETTE_MAX * CHARACTER_WIDTH * CHARACTERS_PER_ROW * row + col;
    //             printf("%s", (joinedArray[currentSingleElement] ? "\x1b[30;47m1,\x1b[0m" : "0,"));
    //         }
    //         printf("  0x%zX\n", PALETTE_MAX * CHARACTER_WIDTH * CHARACTERS_PER_ROW * row + col);
    //     }
    // }
}

void PrintSingleImage(uint8_t** bitArrays, size_t arrayCount) {
    uint8_t* joinedArray = NULL;

    JoinToSingleArray(&joinedArray, bitArrays, arrayCount);


    free(joinedArray);
}

void WriteSingle1bppPNG(FILE* outputFile, uint8_t** bitArrays, size_t arrayCount) {
    uint8_t* joinedArray = NULL;

    JoinToSingleArray(&joinedArray, bitArrays, arrayCount);

    Write1bppPNG(outputFile, joinedArray, PALETTE_MAX * CHARACTERS_PER_ROW * CHARACTER_WIDTH, CHARACTER_HEIGHT * ROW_MAX);

    free(joinedArray);
}

void WriteSingleBMPImage(FILE* outputFile, uint8_t** bitArrays, size_t arrayCount) {
    uint8_t* joinedArray = NULL;

    JoinToSingleArray(&joinedArray, bitArrays, arrayCount);

    WriteBMPFile(outputFile, joinedArray, PALETTE_MAX * CHARACTERS_PER_ROW * CHARACTER_WIDTH, CHARACTER_HEIGHT * ROW_MAX);

    free(joinedArray);
}

void WriteSingleGrayscalePNG(FILE* outputFile, uint8_t** bitArrays, size_t arrayCount) {
    uint8_t* joinedArray = NULL;

    JoinToSingleArray(&joinedArray, bitArrays, arrayCount);

    WriteGrayscalePNG(outputFile, joinedArray, PALETTE_MAX * CHARACTERS_PER_ROW * CHARACTER_WIDTH, CHARACTER_HEIGHT * ROW_MAX);

    free(joinedArray);
}
