#pragma once

#include <getopt.h>

typedef struct {
    struct option longOpt;
    char* helpArg;
    char* helpMsg;
} OptInfo;
