#include "help.h"

#include <assert.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "macros.h"
#include "main.h"

/**
 * Options:
 *   -c, --c-type           C type to use as prefix for output array, defaults to value of -u
 *   -e, --extra-prefix     Add an extra prefix, e.g. an alignment macro
 *   -i, --image-format     input type (jpeg or png) (optional, should try to guess from file extension and ...)
 *   -p, --pixel-format     texture output format, one of rgba32,rgba16,ia16,ia8,ia4,i8,i4,ci8,ci4 (yuv or whatever not
 *                          supported) (default is rgba16)
 *   -o, --output-path      output file path (output to stdout if not specified)
 *   -u, --bit-group-size   bytes per array element, one of 8,16, (without, default is chosen per type, 32/16/8 for
 *                          32/16/(8 or 4))
 *
 * Flags:
 *   -h, --help
 *   -l, --palette          Rip the palette from a palettised PNG (should err if is not palettised) as rgba16; ignores
 *                          -f, print a warning
 *   -r, --raw              output only the raw bytes in specified -u
 *   -y, --yaz0             compress output
 *
 * Positional argument:
 *   input-file             input file path
 */

void PrintFlowAndIndent(const char* string, size_t initialColumn, size_t textWidth, size_t hangingIndent,
                        bool indentFirstLine) {
    size_t column = initialColumn;
    size_t index = 0;
    size_t inLength = strlen(string);
    size_t lookAhead;
    bool shouldBreak;

    assert(initialColumn < textWidth);
    assert(hangingIndent < textWidth);

    if (indentFirstLine) {
        printf("%*s", (int)initialColumn, "");
    }

    for (; index <= inLength; index++) {
        shouldBreak = 0;

        if (column == textWidth) {
            printf("%c\n%*s", string[index], (int)hangingIndent, "");
            column = hangingIndent;
            continue;
        }

        column++;

        switch (string[index]) {
            case '\0':
                return;

            case ' ':
                if (column == hangingIndent) {
                    continue;
                }

                for (lookAhead = 0; lookAhead <= textWidth - column; lookAhead++) {
                    // printf("%c\n", src[index + lookAhead]);
                    if (string[index + lookAhead + 1] == ' ' || string[index + lookAhead + 1] == '\0') {
                        putchar(' ');
                        shouldBreak = 1;
                        break;
                    }
                }
                if (shouldBreak) { /* Damn shared keywords. */
                    break;
                }
            case '\n':
                printf("\n%*s", (int)hangingIndent, "");
                column = hangingIndent;
                break;

            default:
                putchar(string[index]);
                break;
        }
    }
}

void PrintHelp(size_t optCount, OptInfo* optInfo) {
    size_t textWidth = 80;
    size_t dtIndent = 2;
    size_t ddIndent = 25;
    size_t i;
    size_t dtLength;
    int padding;
    static char prolog[] = "Help prolog";
    static char epilog[] = "Pithy closing remark";

    printf("%s", prolog);
    printf("\n");

    for (i = 0; i < optCount; i++) {
        if (optInfo[i].longOpt.val == 0) {
            break;
        }

        dtLength = dtIndent + 6 + strlen(optInfo[i].longOpt.name);

        if (optInfo[i].helpArg == NULL) {
            padding = ddIndent - dtLength - 2;
            printf("%*s-%c, --%s%*s  ", (int)dtIndent, "", optInfo[i].longOpt.val, optInfo[i].longOpt.name,
                   CLAMP_MIN(padding, 0), "");
        } else {
            dtLength += 1 + strlen(optInfo[i].helpArg);
            padding = ddIndent - dtLength - 2;
            printf("%*s-%c, --%s=%s%*s  ", (int)dtIndent, "", optInfo[i].longOpt.val, optInfo[i].longOpt.name,
                   optInfo[i].helpArg, CLAMP_MIN(padding, 0), "");
        }
        PrintFlowAndIndent(optInfo[i].helpMsg, CLAMP_MIN(dtLength + 2, ddIndent), textWidth, ddIndent, false);
        printf("\n");
    }

    printf("\n");
    printf("%s", epilog);
    printf("\n");
}
