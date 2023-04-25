// #include "error.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum {

    DIAGNOSTIC_TYPE_ALWAYS,
    DIAGNOSTIC_TYPE_MAX,
} DiagnosticType;

typedef enum {
    DIAGNOSTIC_LEVEL_OFF,
    DIAGNOSTIC_LEVEL_NOTE,
    DIAGNOSTIC_LEVEL_WARN,
    DIAGNOSTIC_LEVEL_ERR,
    DIAGNOSTIC_LEVEL_FATAL,
} DiagnosticLevel;

typedef struct {
    char* name;
    DiagnosticType type;
    DiagnosticLevel defaultLevel;
    char* description;
} DiagnosticInfoInit;

/*
static const DiagnosticInfoInit diagnosticInfoInit = {
    NULL, (DiagnosticType)0, DIAGNOSTIC_LEVEL_OFF, NULL ,
};
*/

typedef struct {
    DiagnosticType type;
    char* name;
    DiagnosticLevel level;
    char* description;
} DiagnosticInfo;

// void DiagnosticHandler_Init(const char** warningList) {
//
// }
