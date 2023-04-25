#define __STDC_WANT_LIB_EXT2__ 1

#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void rek_mkdir(char* path) {
    char* sep = strrchr(path, '/');
    if (sep != NULL) {
        *sep = 0;
        rek_mkdir(path);
        *sep = '/';
    }
    if (mkdir(path, 0777) && errno != EEXIST)
        printf("error while trying to create '%s'\n%m\n", path);
}

FILE* fopen_mkdir(char* path, char* mode) {
    char* sep = strrchr(path, '/');
    if (sep) {
        char* path0 = strdup(path);
        path0[sep - path] = 0;
        rek_mkdir(path0);
        free(path0);
    }
    return fopen(path, mode);
}
