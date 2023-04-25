/**
 * Plan is to support conversion between
 * In:
 * - raw data file
 * - 4 BMP files
 * - 4 PNG files
 * - 4 XBM files
 * - folder of BMPs/PNGs/XBM (maybe from spec)
 *
 * Out:
 * - all input formats,
 * - comma-separated bytes for inclusion in C file, with or without array wrapper.
 *
 * Currently supported:
 * In: raw data, single BMP
 * Out: single BMP
 *
 *
 */

/**
 * Plan:
 * raw data -> bit arrays (4) -> BMP (4)
 * BMP (4) -> bit arrays (4)
 */

#define _GNU_SOURCE
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include <getopt.h>

#include "bmp.h"
#include "help.h"
#include "macros.h"
#include "mkdir.h"

#include "1bpp_png.h"
#include "single_image.h"

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

void ConstructPalettes(int* palettes, size_t number) {
    size_t i;
    // paletteArray = malloc(PALETTE_MAX * sizeof(int));
    // Either free this or malloc it elsewhere, or put it on the stack in main if it's going to always be size 4

    for (i = 0; i < number; i++) {
        palettes[i] = 0x11 << i;
    }
}

/* A lot of this assumes two pixels / element */
uint8_t* SetBitArray(uint8_t* array, uint8_t* fileBuffer, size_t count, int paletteMask) {
    size_t i;

    if (count & 1) {
        assert(!"SetBitArray: error: total size must be even");
    }

    for (i = 0; i < count; i++) {
        size_t subArrayIndex;
        for (subArrayIndex = 0; subArrayIndex < PIXEL_DENSITY; subArrayIndex++) {
            array[PIXEL_DENSITY * i + subArrayIndex] =
                ((fileBuffer[i] & paletteMask & (0xF0 >> (4 * subArrayIndex))) != 0);
            // printf("%d,", array[PIXEL_DENSITY * i + subArrayIndex]);
        }
    }

    return array;
}

/* Construct bit arrays from binary file. Do not forget to free(bitArrays[i]) later! */
size_t ReadBinaryFile(uint8_t** bitArrays, FILE* inputFile, size_t readStart, size_t readLength) {
    int i;
    int palettes[PALETTE_MAX];
    uint8_t* inFileBuffer;
    size_t numberRead;
    size_t endOfFile;

    fseek(inputFile, 0, SEEK_END);
    endOfFile = ftell(inputFile);
    if (endOfFile < readStart) {
        fprintf(stderr, "Starting offset 0x%zX is beyond end of file at 0x%zX\n", readStart, endOfFile);
    } else if (endOfFile < readStart + readLength) {
        fprintf(stderr, "Reading 0x%zX bytes starting at 0x%zX will pass end of file at 0x%zX\n", readLength, readStart,
                endOfFile);
    }

    /* If read length is not set, read to the end */
    if (readLength == 0) {
        readLength = ftell(inputFile) - readStart;
    }

    fseek(inputFile, readStart, SEEK_SET);
    // printf("File read start: 0x%zX\n", readStart);
    // printf("File read length: 0x%zX\n", readLength);

    inFileBuffer = malloc(readLength * sizeof(uint8_t));

    /* Read inputFile. Now finished with input, so close it. */
    numberRead = fread(inFileBuffer, sizeof(uint8_t), readLength / sizeof(uint8_t), inputFile);
    if (numberRead < readLength) {
        fprintf(stderr, "Reached end of file after reading 0x%zX / 0x%zX bytes\n", numberRead, readLength);
    }
    fclose(inputFile);

    ConstructPalettes(palettes, PALETTE_MAX);

    /* Construct the bit arrays */
    for (i = 0; i < PALETTE_MAX; i++) {
        bitArrays[i] = malloc(PIXEL_DENSITY * readLength * sizeof(uint8_t));
        SetBitArray(bitArrays[i], inFileBuffer, readLength, palettes[i]);
    }

    /* Finished with inFileBuffer now */
    free(inFileBuffer);

    return readLength;
}

/* For writing a C file */

void WriteDefinitionHead(FILE* file, const char* extraPrefix, const char* cType, const char* varName) {
    assert(file != NULL);
    assert(cType != NULL);
    assert(varName != NULL);

    if (extraPrefix != NULL) {
        fprintf(file, "%s ", extraPrefix);
    }

    fprintf(file, "%s %s[] = {\n", cType, varName);
}

#define ARRAY_WIDTH 16
void WriteDefinitionBody(FILE* file, uint8_t* bodyArray, size_t size) {
    size_t currentByte;
    const char* indent = "   ";

    fprintf(file, "%s", indent);

    for (currentByte = 0; currentByte < size; currentByte++) {
        if (currentByte % ARRAY_WIDTH == 0) {
            fprintf(file, "%s", indent);
        }
        fprintf(file, " 0x%" PRIX8 ",", bodyArray[currentByte]);
        if ((currentByte + 1 % ARRAY_WIDTH) == 0) {
            fputs("", file);
        }
    }

    if ((currentByte + 1 % ARRAY_WIDTH) != 0) {
        fputs("", file);
    }
}

void WriteDefinitionTail(FILE* file) {
    assert(file != NULL);
    fputs("\n};", file);
}

void FreeBitArrays(uint8_t** bitArrays, size_t number) {
    size_t i;
    for (i = 0; i < PALETTE_MAX; i++) {
        free(bitArrays[i]);
    }
}

/* Options */
#define OPTSTR "I:L:O:l:i:o:s:hr"
#define USAGE_FMT ""

// clang-format off
static const OptInfo optInfo[] = {
    { { "input-mode", required_argument, NULL, 'I' }, "TYPE", "type of input file: one of B(inary), (Bit)M(ap images), C( file)" },
    { { "input-list", required_argument, NULL, 'L' }, "LIST", "For conversion of multiple files, pass the path of a list file" },
    { { "output-mode", required_argument, NULL, 'O' }, "TYPE", "type of output file: one of B(inary), (Bit)M(ap images), C( file)" },
    { { "input-path", required_argument, NULL, 'i' }, "FILE", "Read input from a single FILE, for B or C modes" },
    { { "read-length", required_argument, NULL, 'l' }, "0xNUM", "Read NUM bytes from file. NUM can be given as 0xHEX or DEC. If not specified, read entire file" },
    { { "output-path", required_argument, NULL, 'o' }, "FILE", "Write output to FILE, or stdout if not specified. In B mode, specifies a directory" },
    { { "read-start", required_argument, NULL, 's' }, "0xNUM", "Start reading at offset 0xNUM" },

    { { "help", no_argument, NULL, 'h' }, NULL, "Display this message and exit" },
    { { "raw-mode", no_argument, NULL, 'r' }, NULL, "Raw mode: in C output, print only array body, not head and tail" },

    { { NULL, 0, NULL, 0 }, NULL, NULL },
};

static const PositionalArgument positionalArguments[] = {};
// clang-format on

static size_t optCount = ARRAY_COUNT(optInfo);
static struct option longOptions[ARRAY_COUNT(optInfo)];

void ConstructLongOpts() {
    size_t i;

    for (i = 0; i < optCount; i++) {
        longOptions[i] = optInfo[i].longOpt;
    }
}

int main(int argc, char** argv) {
    int opt;

    size_t readStart = 0;
    size_t readLength = 0;

    int palettes[PALETTE_MAX];
    FILE* inputFile;
    uint8_t* inFileBuffer;
    size_t inFileBufferCount;
    FILE* outputFile;
    uint8_t* bitArrays[PALETTE_MAX];

    char inputMode = '\0';
    char outputMode = '\0';
    char overflow = '\0';

    FILE* inputFileList;

    ConstructLongOpts();

    /* Process command line */

    if (argc < 2) {
        fprintf(stderr, "No input file specified\n");
        return EXIT_FAILURE;
    }

    while (true) {
        int optionIndex = 0;

        if ((opt = getopt_long(argc, argv, OPTSTR, longOptions, &optionIndex)) == -1) {
            break;
        }

        switch (opt) {
            case 'I':
                sscanf(optarg, "%c%c", &inputMode, &overflow);
                if (overflow != '\0' || (inputMode != 'B' && inputMode != 'M' && inputMode != 'C')) {
                    fprintf(stderr, "error: '%s' is not a valid input mode: should be one of B, M, C", optarg);
                    return EXIT_FAILURE;
                }
                printf("Using input mode: %c", inputMode);
                break;

            case 'L':
                inputFileList = fopen(optarg, "r");
                printf("Using input list: %s", optarg);
                break;

            case 'O':
                sscanf(optarg, "%c%c", &outputMode, &overflow);
                if (overflow != '\0' || (inputMode != 'B' && inputMode != 'M' && inputMode != 'C')) {
                    fprintf(stderr, "error: '%s' is not a valid output mode: should be one of B, M, C", optarg);
                    return EXIT_FAILURE;
                }
                printf("Using output mode: %c", inputMode);
                break;

            case 'i':
                printf("Passed argument '-i %s', but input files are not yet enabled.", optarg);
                break;

            case 'l':
                if (!sscanf(optarg, "0x%lX", &readLength) && !sscanf(optarg, "%ld", &readLength)) {
                    fprintf(stderr,
                            "warning: %s is not a valid argument for -s: it should be hex starting with '0x' or dec. "
                            "Defaulting to 0\n",
                            optarg);
                }
                printf("Will read 0x%lX bytes\n", readLength);
                break;

            case 'o':
                // printf("Passed argument '-o %s', but output files are not yet enabled.\n", optarg);
                outputFile = fopen(optarg, "wb");
                break;

            case 's':
                if (!sscanf(optarg, "0x%lX", &readStart) && !sscanf(optarg, "%ld", &readStart)) {
                    fprintf(stderr,
                            "warning: %s is not a valid argument for -s: it should be hex starting with '0x' or dec. "
                            "Defaulting to 0\n",
                            optarg);
                }
                printf("Start reading at: 0x%lX\n", readStart);
                break;

            case 'h':
                PrintHelp(optCount, optInfo);
                return EXIT_FAILURE;

            default:
                printf("?? getopt returned character code 0%o ??\n", opt);
                break;
        }
    }

    inputFile = fopen(argv[optind], "rb");

    if (inputFile == NULL) {
        return EXIT_FAILURE;
    }


    if (outputFile == NULL) {
        outputFile = stdout;
        fprintf(stderr, "No output file given, defaulting to stdout");
        // return EXIT_FAILURE;
    }

    // #if 0

    // ConstructPalettes(palettes);

    // /* If read length is not set, read to the end */
    // if (readLength == 0) {
    //     fseek(inputFile, readStart, SEEK_END);
    //     readLength = ftell(inputFile);
    //     fseek(inputFile, 0, SEEK_SET);
    //     // printf("File length: 0x%zX\n", readLength);
    // }

    // inFileBuffer = malloc(readLength * sizeof(uint8_t));
    // inFileBufferCount = readLength;

    // /* Read inputFile. Now finished with input, so close it. */
    // fread(inFileBuffer, sizeof(uint8_t), readLength / sizeof(uint8_t), inputFile);
    // fclose(inputFile);

    // /* Construct the bit arrays */
    // {
    //     size_t i;
    //     for (i = 0; i < PALETTE_MAX; i++) {
    //         bitArrays[i] = malloc(PIXEL_DENSITY * inFileBufferCount * sizeof(uint8_t));
    //         SetBitArray(bitArrays[i], inFileBuffer, inFileBufferCount, palettes[i]);
    //     }
    // }

    // /* Finished with inFileBuffer now */
    // free(inFileBuffer);

    readLength = ReadBinaryFile(bitArrays, inputFile, readStart, readLength);
    printf("Length read: 0x%zX\n", readLength);
    // for (i = 0; i < PALETTE_MAX; i++) {
    //     size_t pixel;
    //     for (pixel = 0; pixel < PIXEL_DENSITY * inFileBufferCount; pixel++) {
    //         if (!(pixel & 0xF)) {
    //             printf("\n");
    //         }
    //         fprintf(outputFile, "%s", (bitArrays[i][pixel] ? "X" : " "));
    //     }
    //     printf("\n");
    // }


    printf("Printing single image...\n");
    // PrintSingleImage(bitArrays, readLength);
    // WriteSingle1bppPNG(outputFile, bitArrays, readLength);
    // WriteSingleBMPImage(outputFile, bitArrays, readLength);
    WriteSingleGrayscalePNG(outputFile, bitArrays, readLength);
    printf("Done\n");

#if 0

#undef ROW_MAX
#define ROW_MAX 32
    // needs: outputPath, bitArrays, width, height
    {
        char* outputPath = "test";
        char* outputFileNames[4]; // [30]; // TODO: do not hardcode these, malloc them or something
        FILE* outputFiles[4];
        char* outputFileListName; // [30];
        FILE* outputFileList;
        int layer;
        ssize_t stringLength = snprintf(NULL, 0, "%s/filelist.txt", outputPath) + 1;

        outputFileListName = malloc(stringLength * sizeof(char));
        sprintf(outputFileListName, "%s/filelist.txt", outputPath);

        outputFileList = fopen_mkdir(outputFileListName, "a");
        free(outputFileListName);

        for (layer = 0; layer < PALETTE_MAX; layer++) {
            stringLength = snprintf(NULL, 0, "%s/layer_%d.bmp", outputPath, layer) + 1;
            outputFileNames[layer] = malloc(stringLength * sizeof(char));
            sprintf(outputFileNames[layer], "%s/layer_%d.bmp", outputPath, layer);

            fprintf(outputFileList, "%s\n", outputFileNames[layer]);
            printf("%s/layer_%d.bmp\n", outputPath, layer);
            outputFiles[layer] = fopen_mkdir(outputFileNames[layer], "wb");
            printf("Writing to %s\n", outputFileNames[layer]);

            WriteBMPFile(outputFiles[layer], bitArrays[layer], CHARACTERS_PER_ROW * CHARACTER_WIDTH,
                         ROW_MAX * CHARACTER_HEIGHT);

            free(outputFileNames[layer]);
            fclose(outputFiles[layer]);
        }
        fclose(outputFileList);

        // printf("\n");
    }
#endif

#if 0

    {
        BMPFile file;
        uint8_t* pixelsArray;
        size_t pixelsArraySize;
        size_t currentByte;
        uint8_t* binaryArray;
        FILE* fileList = fopen("test/filelist.txt", "r");
        char* line = NULL;
        size_t len = 0;
        ssize_t read;
        FILE* currentInputFile;
        int layer = 0;

        while ((read = getline(&line, &len, fileList)) != -1) {
            int c;
            for (c = 0; line[c] != '\0'; c++) {
                if (line[c] == '\n') {
                    line[c] = '\0';
                }
            }

            // printf("Retrieved line of length %zu:\n", read);
            // printf("%s", line);
            // printf("\n");
            currentInputFile = fopen(line, "rb");
            ReadBMPHeaders(&file, currentInputFile);

            // printf("Width: %d Height: %d\n", file.imageHeader.biWidth, file.imageHeader.biHeight);

            if (!CheckBMP(&file)) {
                return EXIT_FAILURE;
            }
            pixelsArraySize = file.imageHeader.biWidth * ABS(file.imageHeader.biHeight);
            // printf("Malloc array size: %zu\n\n", pixelsArraySize);
            pixelsArray = malloc(pixelsArraySize * sizeof(uint8_t));
            memset(pixelsArray, 0, pixelsArraySize);
            ExtractBMPPixels(pixelsArray, &file, currentInputFile);

            // printf("Binary array size: 0x%zX\n", pixelsArraySize / 2);
            assert(pixelsArraySize % 2 == 0);

            if (layer == 0) {
                binaryArray = malloc(pixelsArraySize / 2 * sizeof(uint8_t));
                memset(binaryArray, 0, pixelsArraySize / 2);
            }

            for (currentByte = 0; currentByte < pixelsArraySize / 2; currentByte++) {
                binaryArray[currentByte] |=
                    (pixelsArray[2 * currentByte] << (4 + layer)) | (pixelsArray[2 * currentByte + 1] << layer);
            }

            // printf("\nFile written\n");
            fclose(currentInputFile);
            layer++;
        }

        fwrite(binaryArray, pixelsArraySize / 2, 1, outputFile);
        free(pixelsArray);
        free(binaryArray);
        fclose(fileList);
        if (line) {
            free(line);
        }

        // ReadBMPHeaders(&file, inputFile);
        // if (!CheckBMP(&file)) {
        //     return EXIT_FAILURE;
        // }
        // pixelsArraySize = file.imageHeader.biWidth * ABS(file.imageHeader.biHeight);
        // // printf("Malloc array size: %zu\n\n", pixelsArraySize);
        // pixelsArray = malloc(pixelsArraySize * sizeof(uint8_t));
        // memset(pixelsArray, 0, pixelsArraySize);
        // ExtractBMPPixels(pixelsArray, &file, inputFile);

        // // printf("Binary array size: 0x%zX\n", pixelsArraySize / 2);
        // assert(pixelsArraySize % 2 == 0);

        // binaryArray = malloc(pixelsArraySize / 2 * sizeof(uint8_t));
        // memset(binaryArray, 0, pixelsArraySize / 2);

        // for (currentByte = 0; currentByte < pixelsArraySize / 2; currentByte++) {
        //     binaryArray[currentByte] |= (pixelsArray[2 * currentByte] << 4) | (pixelsArray[2 * currentByte + 1]);
        // }

        // fwrite(binaryArray, pixelsArraySize / 2, 1, outputFile);
        // // printf("\nFile written\n");

        // free(pixelsArray);
        // fclose(fileList);
    }

#endif

#if 0

    for (i = 0; i < readLength / sizeof(uint8_t); i++) {
        fprintf(outputFile, "%s", (inFileBuffer[i] & 0x10 ? "\x1b[47m \x1b[0m" : " "));
        fprintf(outputFile, "%s", (inFileBuffer[i] & 0x1 ? "\x1b[47m \x1b[0m" : " "));
        if (!((i + 1) & 0x7)) {
            printf("\n");
        }
    }

    {
        size_t row;
        for (row = 0; row < CHARACTER_HEIGHT * ROW_MAX; row++) {
            size_t charColumn;
            for (charColumn = 0; charColumn < CHARACTERS_PER_ROW; charColumn++) {
                size_t palette;
                for (palette = 0; palette < PALETTE_MAX; palette++) {
                    size_t column;
                    for (column = 0; column < CHARACTER_ROW_SIZE; column++) {
                        size_t currentElement =
                            CHARACTERS_PER_ROW * CHARACTER_ROW_SIZE * row + CHARACTER_ROW_SIZE * charColumn + column;
                        int pixel1 = inFileBuffer[currentElement] >> (PALETTE_MAX + palette) & 1;
                        int pixel2 = inFileBuffer[currentElement] >> palette & 1;
                        fprintf(outputFile, "%d,", pixel1);
                        fprintf(outputFile, "%d,", pixel2);
                    }
                }
            }
            printf("\n");
        }
    }

    free(inFileBuffer);
    fclose(inputFile);
#endif

    if (outputFile != stdout) {
        fclose(outputFile);
    }

    FreeBitArrays(bitArrays, PALETTE_MAX);

    return EXIT_SUCCESS;
}
