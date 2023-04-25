#pragma once

#include <getopt.h>
#include <unistd.h>

typedef struct {
    struct option longOpt;
    char* helpArg;
    char* helpMsg;
} OptInfo;

typedef struct {
    char* helpArg;
    char* helpMsg;
} PositionalArgument;

void PrintHelp(size_t optCount, const OptInfo* optInfo);
