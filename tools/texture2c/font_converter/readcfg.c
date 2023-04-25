#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CONFIG_SEPERATOR "---"

typedef enum {
    CONFIG_FORMAT_ERR = -1,
    CONFIG_FORMAT_1BPP,
    CONFIG_FORMAT_I4,
    CONFIG_FORMAT_4LAYER1, /* 4 layers, each bitdepth 1 */
} ConfigFormat;

typedef struct {
    ConfigFormat format;
    size_t charWidth;
    size_t charHeight;
    size_t imageWidth;
    size_t imageHeight;
    size_t charsPerRow;
    size_t fileCount;
    const char** fileNames;
} ConfigFile;

bool startswith(const char* pre, const char* str) {
    return strncmp(pre, str, strlen(pre)) == 0;
}

int GetString(char* buffer, char* value) {
    char overflow;

    if (sscanf(buffer, "%s %c", value, &overflow) == 1) {
        return 0;
    } else {
        fprintf(stderr, "error: value %s is malformed", buffer);
        return -1;
    }
}

int GetSize(char* buffer, size_t* value) {
    char overflow;

    if (sscanf(buffer, "%zu %c", value, &overflow) == 1) {
        return 0;
    } else {
        fprintf(stderr, "error: value %s is malformed", buffer);
        return -1;
    }
}



ConfigFormat Config_GetFormat(char* str) {
    if (strcmp("1bpp", str) == 0) {
        return CONFIG_FORMAT_1BPP;
    } else if (strcmp("i4", str) == 0) {
        return CONFIG_FORMAT_I4;
    } else if (strcmp("4layer1", str) == 0) {
        return CONFIG_FORMAT_4LAYER1;
    } else {
        return CONFIG_FORMAT_ERR;
    }
}


ConfigFile* Config_Read(FILE* file, ConfigFile* config) {
    size_t fileLength;
    char* bigBuffer = malloc(0x1000);
    size_t lineNum = 0;

    config->format = CONFIG_FORMAT_ERR;
    config->charWidth = 0;
    config->charHeight = 0;
    config->imageWidth = 0;
    config->imageHeight = 0;
    config->charsPerRow = 0;
    config->fileCount = 0;

    fseek(file, 0, SEEK_END);
    fileLength = ftell(file);
    fseek(file, 0, SEEK_SET);

    /* Read header. */
    while (fgets(bigBuffer, 0x1000, file) != NULL) {
        char* colonPos;

        lineNum++;

        /*  */
        if (startswith(CONFIG_SEPERATOR, bigBuffer)) {
            break;
        }

        colonPos = strchr(bigBuffer, ':') + 1;

        if (colonPos == NULL) {
            fprintf(stderr, "Config file line %zu: error: header line missing colon\n", lineNum);
        }

        if (startswith("format:", bigBuffer)) {
            char value[0x10];

            if (GetString(colonPos, value) == 0) {
                config->format = Config_GetFormat(value);
            }
            if (config->format == CONFIG_FORMAT_ERR) {
                fprintf(stderr, "config file line %zu: error: incorrect format '%s' specified\n", lineNum, value);
                exit(EXIT_FAILURE);
            }
        } else if (startswith("charWidth:", bigBuffer)) {
            size_t value;

            if (GetSize(colonPos, &value) == 0) {
                config->charWidth = value;
            }
        } else if (startswith("charHeight:", bigBuffer)) {
            size_t value;

            if (GetSize(colonPos, &value) == 0) {
                config->charHeight = value;
            }
        } else if (startswith("imageWidth:", bigBuffer)) {
            size_t value;

            if (GetSize(colonPos, &value) == 0) {
                config->imageWidth = value;
            }
        } else if (startswith("imageHeight:", bigBuffer)) {
            size_t value;

            if (GetSize(colonPos, &value) == 0) {
                config->imageHeight = value;
            }
        } else if (startswith("charsPerRow:", bigBuffer)) {
            size_t value;

            if (GetSize(colonPos, &value) == 0) {
                config->charsPerRow = value;
            }
        } else {
            fprintf(stderr, "Config file line %zu: warning: unknown configuration option specified \"%s\"\n", lineNum, bigBuffer);
        }

    }

    printf("Format:           %d\n", config->format);
    printf("Character width:  %zu\n", config->charWidth);
    printf("Character height: %zu\n", config->charHeight);
    printf("Image width:      %zu\n", config->imageWidth);
    printf("Image height:     %zu\n", config->imageHeight);
    printf("Characters / Row: %zu\n", config->charsPerRow);


    // Read filenames.
    while (fgets(bigBuffer, 0x1000, file) != NULL) {
        size_t nameLength;
        char* curName;

        lineNum++;

        nameLength = strlen(bigBuffer) + 1;
        curName = malloc(nameLength);
        memcpy(curName, bigBuffer, nameLength);

        // Need to add the name to the file names list.
        
        config->fileCount++;
    }



    free(bigBuffer);
    return config;
}

Config_Free(ConfigFile* config) {
    size_t i;
    
    for (i = 0; i < config->fileCount; i++) {
        free(config->fileNames[i]);
    }
}

int main(int argc, char** argv) {
    FILE* file;
    ConfigFile config = { 0 };

    if (argc < 2) {
        printf("USAGE: %s CONFIG_FILE\n", argv[0]);
        return 1;
    }

    file = fopen(argv[1], "r");

    Config_Read(file, &config);



    fclose(file);
    return 0;
}
