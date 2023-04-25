/**
 * Docblock: Hello reader
 */

/* Includes */
#include "main.h"

#include <assert.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "generic_buffer.h"
#include "help.h"
#include "image_backend.h"
#include "macros.h"
#include "png_texture.h"
#include "jpeg_texture.h"

/* Defines */
#define OPTSRT "c:e:i:p:o:u:v:bhlry"

typedef enum {
    FORMAT_PNG,
    FORMAT_JPEG,
} ImageFileFormat;

typedef struct {
    FILE* inputFile;
    FILE* outputFile;
    ImageFileFormat inputFileFormat;
    TextureType pixelFormat;
    TypeBitWidth bitGroupSize; // Is this the right type to use here?
    char* extraPrefix;
    char* CType;
    char* varName;
    bool extractPalette;
    FILE* paletteFile;

    bool blobMode;
    bool rawOut;
    bool compress;

    bool verbose;
} State;

State gState = {
    .inputFile  = NULL,
    .outputFile = NULL,
    .inputFileFormat = -1,
    .pixelFormat = TextureType_rgba16,
    .bitGroupSize = -1, 
    .extraPrefix = NULL,
    .CType = NULL,
    .varName = NULL,
    .extractPalette = false,
    .paletteFile = NULL,
    .blobMode = false,
    .rawOut = false,
    .compress = false,
    .verbose = false,
};

void GuessInputFileFormat(void) {
}

typedef struct {
    const char* string;
    int eNum;
} PoorMansDict;

PoorMansDict textureTypeDict[] = {
    { "rgba16", TextureType_rgba16 }, { "rgba32", TextureType_rgba32 },
    { "i4", TextureType_i4 },         { "i8", TextureType_i8 },
    { "ia4", TextureType_ia4 },       { "ia8", TextureType_ia8 },
    { "ia16", TextureType_ia16 },     { "ci4", TextureType_ci4 },
    { "ci8", TextureType_ci8 },       { NULL, -1 },
};

PoorMansDict bitGroupSizeDict[] = {
    { "8", TypeBitWidth_8 },
    { "16", TypeBitWidth_16 },
    { "32", TypeBitWidth_32 },
    { "64", TypeBitWidth_64 },
    { NULL, -1 },
};

int BadDictLookup(const char* string, const PoorMansDict* dict) {
    size_t i;

    for (i = 0; dict[i].string != NULL; i++) {
        if (strcmp(dict[i].string, string) == 0) {
            return dict[i].eNum;
        }
    }
    fprintf(stderr, "String '%s' not found in dictionary", string);
    return -1;
}

char* BadDictReverseLookup(char* dest, int eNum, const PoorMansDict* dict) {
    size_t i;

    for (i = 0; dict[i].eNum != -1; i++) {
        if (dict[i].eNum == eNum) {
            // if (ARRAY_COUNT(dest) > strlen(dict[i].string)) {
            return strcpy(dest, dict[i].string);
            // } else {
            //     printf("error: value found, but destination string is too short to copy into");
            //     return NULL;
            // }
        }
    }
    fprintf(stderr, "error: numeric value '%d' not found in dictionary", eNum);
    return NULL;
}

void ReadPng(GenericBuffer* buf, GenericBuffer* paletteBuf, FILE* inFile, TextureType texType, bool extractPalette) {
    ImageBackend textureData;
    ImageBackend_Init(&textureData);

    ImageBackend_ReadPng(&textureData, inFile);

    if (extractPalette) {
        assert(texType == TextureType_ci8 || texType == TextureType_ci4);

        if (!textureData.isColorIndexed) {
            // printf("converting!\n");
            bool converted = ImageBackend_ConvertToColorIndexed(&textureData);
            if (!converted) {
                fprintf(stderr, "Error: Could not convert texture to color indexed format.\n");
                exit(EXIT_FAILURE);
            }
        }

        PngTexture_CopyPalette(paletteBuf, &textureData);

        switch (texType) {
            case TextureType_ci8:
                if (paletteBuf->bufferLength > 256) {
                    fprintf(stderr, "Error: Palette too big, can't fit on CI8 (256 colors). Palette size: %zu.\n",
                            paletteBuf->bufferLength);
                    exit(EXIT_FAILURE);
                }
                break;

            case TextureType_ci4:
                if (paletteBuf->bufferLength > 16) {
                    fprintf(stderr, "Error: Palette too big, can't fit on CI4 (16 colors). Palette size: %zu.\n",
                            paletteBuf->bufferLength);
                    exit(EXIT_FAILURE);
                }
                break;

            default:
                break;
        }
    }

    PngTexture_CopyPng(buf, &textureData, texType);

    ImageBackend_Destroy(&textureData);
}

void ReadJpeg(GenericBuffer* buf, FILE* inFile) {
    JpegTexture_ReadJpeg(buf, inFile, true);
    JpegTexture_CheckValidJpeg(buf);
}

/* Options */

// clang-format off
static OptInfo optInfo[] = {
    { { "c-type", required_argument, NULL, 'c' }, "TYPE", "Use TYPE as the type of the C array generated. Default is u8/u16/u32/u64, same as -u" },
    { { "extra-prefix", required_argument, NULL, 'e' }, "PREFIX", "Add PREFIX before the C declaration, e.g. for attributes" },
    { { "image-format", required_argument, NULL, 'i' }, "IMG", "Read image as of format IMG. One of 'jpg', 'png'" },
    { { "pixel-format", required_argument, NULL, 'p' }, "FMT", "Output pixel data in format FMT. One of rgba32, rgba16, ia16, ia8, ia4, i8, i4, ci8, ci4. Default: rgba16" },
    { { "output-path", required_argument, NULL, 'o' }, "FILE", "Write output to FILE, or stdout if not specified" },
    { { "bit-group-size", required_argument, NULL, 'u' }, "SIZE", "Number of bits in each array element of output. One of 8,16,32,64. Default is inferred from -p, 32 for rgba32, 16 for rgba16/ia16, 8 for the rest" },
    { { "var-name", required_argument, NULL, 'v' }, "NAME", "Use NAME as variable name of C array. Default: inputFileTex" },
    { { "palette", required_argument, NULL, 'l' }, "FILE", "Extract the palette a PNG uses instead of the image to FILE" },

    { { "help", no_argument, NULL, 'h' }, NULL, "Display this message and exit" },
    { { "blob", no_argument, NULL, 'b' }, NULL, "Treat file as a binary blob rather than a texture" },
    { { "raw", no_argument, NULL, 'r' }, NULL, "Output a raw array, i.e. only the contents of the {}. Ignores -c, -e, -v" },
    { { "yaz0", no_argument, NULL, 'y' }, NULL, "Compress the output using yaz0" },
    { { NULL, 0, NULL, 0 }, NULL, NULL },
};
// clang-format on

static size_t optCount = ARRAY_COUNT(optInfo);
static struct option longOptions[ARRAY_COUNT(optInfo)];

void ConstructLongOpts(void) {
    size_t i;

    for (i = 0; i < optCount; i++) {
        longOptions[i] = optInfo[i].longOpt;
    }
}

void PrintVariablePre(FILE* outFile, const char* extraPrefix, const char* cType, const char* varName) {
    assert(outFile != NULL);
    assert(cType != NULL);
    assert(varName != NULL);

    if (gState.extraPrefix != NULL) {
        fprintf(outFile, "%s ", extraPrefix);
    }

    assert(gState.varName != NULL);
    fprintf(outFile, "%s %s[] = {\n", cType, varName);
}

void PrintVariablePost(FILE* outFile) {
    assert(outFile != NULL);

    fprintf(outFile, "};\n");
}

void CheckValidProgramArguments(void) {
    if (!gState.rawOut) {
        if (gState.varName == NULL) {
            fprintf(stderr, "Error: Missing var-name\n");
            exit(EXIT_FAILURE);
        }
    }

    if (gState.extractPalette) {
        switch (gState.pixelFormat) {
            case TextureType_ci4:
            case TextureType_ci8:
                break;

            default:
                fprintf(stderr, "Error: Can't combine extraction with selected pixel format\n");
                exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char** argv) {
    int opt;

    if (argc < 2) {
        // TODO
        fprintf(stderr, "Usage: %s [options] inputFile \n"
               "Try %s --help for more information.\n",
               argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    ConstructLongOpts();

    while (true) {
        int optionIndex = 0;

        if ((opt = getopt_long(argc, argv, OPTSRT, longOptions, &optionIndex)) == -1) {
            break;
        }

        switch (opt) {
            /* Options */
            case 'c':
                if (gState.verbose) {
                    printf("Using type: %s\n", optarg);
                }
                gState.CType = optarg;
                break;

            case 'e':
                if (gState.verbose) {
                    printf("Adding extra prefix: %s\n", optarg);
                }
                gState.extraPrefix = optarg;
                break;

            case 'i':
                if (gState.verbose) {
                    printf("Input format: %s\n", optarg);
                }
                if ((strcmp(optarg, "png") == 0) || (strcmp(optarg, "PNG") == 0)) {
                    gState.inputFileFormat = FORMAT_PNG;
                } else if ((strcmp(optarg, "jpg") == 0) || (strcmp(optarg, "JPG") == 0) ||
                           (strcmp(optarg, "jpeg") == 0) || (strcmp(optarg, "JPEG") == 0)) {
                    gState.inputFileFormat = FORMAT_JPEG;
                }
                break;

            case 'p':
                if (gState.verbose) {
                    printf("Output pixel format: %s\n", optarg);
                }
                gState.pixelFormat = (TextureType)BadDictLookup(optarg, textureTypeDict);
                break;

            case 'o':
                if (gState.verbose) {
                    printf("Output path: %s\n", optarg);
                }
                gState.outputFile = fopen(optarg, "w");
                break;

            case 'u':
                if (gState.verbose) {
                    printf("Bit grouping size: %s\n", optarg);
                }
                gState.bitGroupSize = (TypeBitWidth)BadDictLookup(optarg, bitGroupSizeDict);
                break;

            case 'v':
                if (gState.verbose) {
                    printf("Output variable name: %s\n", optarg);
                }
                gState.varName = optarg;
                break;

            case 'l':
                if (gState.verbose) {
                    printf("Extracting palette from PNG: %s\n", optarg);
                }
                gState.extractPalette = true;
                gState.paletteFile = fopen(optarg, "w");
                break;

            /* Flags */
            case 'b':
                gState.blobMode = true;
                // assert(!"Not implemented");
                break;

            case 'h':
                PrintHelp(optCount, optInfo);
                return EXIT_FAILURE;

            case 'r':
                if (gState.verbose) {
                    printf("Raw mode selected.\n");
                }
                gState.rawOut = true;
                break;

            case 'y':
                if (gState.verbose) {
                    printf("Compressing output...\n");
                }
                gState.compress = true;
                break;

            default:
                fprintf(stderr, "?? getopt returned character code 0%o ??\n", opt);
                exit(EXIT_FAILURE);
                break;
        }
    }

    /* Check and set input file */
    if (argv[optind] == NULL) {
        fprintf(stderr, "Mandatory argument 'input-file' missing\n");
        return EXIT_FAILURE;
    } else {
        printf("Using input file: %s\n", argv[optind]);
        gState.inputFile = fopen(argv[optind], "rb"); // What if it doesn't exist?
    }

    /**
     * Set default output file.
     * Have to do this since stdout is not constant.
     */
    if (gState.outputFile == NULL) {
        gState.outputFile = stdout;
    }

    /* Option interaction verification */
    /**
     * Check for:
     *  C options passed in raw mode
     *  bitGroupSize disagreeing with C type
     */

    if (gState.rawOut) {
        if (gState.varName != NULL) {
            fprintf(stderr, "note: raw mode will not use var-name\n");
        }
        if (gState.CType != NULL) {
            fprintf(stderr, "note: raw mode will not use c-type\n");
        }
        if (gState.extraPrefix != NULL) {
            fprintf(stderr, "note: raw mode will not use extra-prefix\n");
        }
    }

    /* Natural types by default */
    if (gState.bitGroupSize == (TypeBitWidth)-1) {
        if (gState.blobMode) {
            gState.bitGroupSize = TypeBitWidth_8;
        } else {
            switch (gState.pixelFormat) {
                case TextureType_rgba32:
                    gState.bitGroupSize = TypeBitWidth_32;
                    break;

                case TextureType_rgba16:
                case TextureType_ia16:
                    gState.bitGroupSize = TypeBitWidth_16;
                    break;

                case TextureType_i8:
                case TextureType_ia8:
                case TextureType_ci8:
                case TextureType_i4:
                case TextureType_ia4:
                case TextureType_ci4:
                    gState.bitGroupSize = TypeBitWidth_8;
                    break;

                default:
                    fprintf(stderr, "error: unknown texture type specified\n");
                    return EXIT_FAILURE;
            }
        }
    }

    if (gState.CType != NULL) {
        int size = 0;
        if ((strcmp(gState.CType, "u64") == 0) && (gState.bitGroupSize != TypeBitWidth_64)) {
            size = 64;
        } else if ((strcmp(gState.CType, "u32") == 0) && (gState.bitGroupSize != TypeBitWidth_32)) {
            size = 32;
        } else if ((strcmp(gState.CType, "u16") == 0) && (gState.bitGroupSize != TypeBitWidth_16)) {
            size = 16;
        } else if ((strcmp(gState.CType, "u8") == 0) && (gState.bitGroupSize != TypeBitWidth_8)) {
            size = 8;
        }

        if (size != 0) {
            fprintf(stderr, "warning: c-type '%s' does not match bit-group-size %d\n", gState.CType,
                   1 << (gState.bitGroupSize + 3));
        }
    } else {
        /* Set default C type */
        switch (gState.bitGroupSize) {
            case TypeBitWidth_64:
                gState.CType = "u64";
                break;

            case TypeBitWidth_32:
                gState.CType = "u32";
                break;

            case TypeBitWidth_16:
                gState.CType = "u16";
                break;

            case TypeBitWidth_8:
                gState.CType = "u8";
                break;

            default:
                printf("error: unknown bit-group-size specified\n");
                return EXIT_FAILURE;
        }
    }

    CheckValidProgramArguments();

    assert(gState.inputFile != NULL);

    GenericBuffer genericBuf;
    GenericBuffer_Init(&genericBuf);

    GenericBuffer paletteBuf;
    GenericBuffer_Init(&paletteBuf);

    if (gState.blobMode) {
        GenericBuffer_ReadBinary(&genericBuf, gState.inputFile);
    } else {
        switch (gState.inputFileFormat) {
            default:
                printf("Assuming PNG...\n");
            case FORMAT_PNG:
                ReadPng(&genericBuf, &paletteBuf, gState.inputFile, gState.pixelFormat, gState.extractPalette);
                break;

            case FORMAT_JPEG:
                ReadJpeg(&genericBuf, gState.inputFile);
                break;
        }
    }

    if (gState.compress) {
        GenericBuffer_Yaz0Compress(&genericBuf);
    }

    assert(gState.outputFile != NULL);

    if (!gState.rawOut) {
        PrintVariablePre(gState.outputFile, gState.extraPrefix, gState.CType, gState.varName);
    }

    GenericBuffer_WriteAsRawCArray(&genericBuf, gState.bitGroupSize, gState.outputFile);

    if (!gState.rawOut) {
        PrintVariablePost(gState.outputFile);
    }

    if (paletteBuf.hasData) {
        GenericBuffer_WriteAsRawCArray(&paletteBuf, TypeBitWidth_16, gState.paletteFile);
    }

    GenericBuffer_Destroy(&paletteBuf);
    GenericBuffer_Destroy(&genericBuf);

    if (gState.inputFile != stdin) {
        fclose(gState.inputFile);
    }
    if (gState.outputFile != stdout) {
        fclose(gState.outputFile);
    }
    if (gState.paletteFile != NULL) {
        fclose(gState.paletteFile);
    }

    return EXIT_SUCCESS;
}
