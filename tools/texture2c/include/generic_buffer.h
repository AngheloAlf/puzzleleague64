#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum TypeBitWidth {
    TypeBitWidth_8,
    TypeBitWidth_16,
    TypeBitWidth_32,
    TypeBitWidth_64,
    TypeBitWidth_Max,
} TypeBitWidth;

typedef struct GenericBuffer {
    uint8_t* buffer;
    size_t bufferSize;   // Size of the allocated buffer
    size_t bufferLength; // Number of elements currently in the buffer
    bool hasData;
    bool isCompressed;
} GenericBuffer;

void GenericBuffer_Init(GenericBuffer* buffer);
void GenericBuffer_Destroy(GenericBuffer* buffer);

void GenericBuffer_WriteAsRawCArray(GenericBuffer* buffer, TypeBitWidth bitWidth, FILE* outFile);
void GenericBuffer_ReadBinary(GenericBuffer* buffer, FILE* inFile);

void GenericBuffer_Yaz0Compress(GenericBuffer* buffer);
void GenericBuffer_Yaz0Decompress(GenericBuffer* buffer);
