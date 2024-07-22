#include "0025C0.h"

#include "macros_defines.h"

bool D_800B3AC0_usa = false;
bool D_800B3AC4_usa = false;
bool D_800B3AC8_usa = false;
bool D_800B3ACC_usa = false;

void func_800019C0_usa(char *arg0) {
    const char *sub_strs[32];
    // Why this does start at index 1?
    s32 count = 1;
    const char **subs_p = sub_strs;

    if ((arg0 == NULL) || (*arg0 == '\0')) {
        return;
    }

    do {
        // Skip space
        while ((*arg0 != '\0') && (*arg0 == ' ')) {
            *arg0++ = '\0';
        }

        // Store substring if not empty
        if (*arg0 != '\0') {
            sub_strs[count++] = arg0;
        }

        // Advance to the non space character
        while ((*arg0 != '\0') && (*arg0 != ' ')) {
            arg0++;
        }
    } while (*arg0 != '\0');

    while (count > 1) {
        const char *c = subs_p[1];

        // Proccess all substrings until a non "short option"-like one is found
        if (c[0] != '-') {
            break;
        }

        switch (c[1]) {
            case 'd':
                D_800B3AC4_usa = true;
                break;

            case 'v':
                D_800B3AC0_usa = true;
                break;

            case 's':
                D_800B3AC8_usa = true;
                break;

            case 'l':
                D_800B3ACC_usa = true;
                break;
        }

        count--;
        subs_p++;
    }
}
