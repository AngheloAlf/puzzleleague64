#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#include "generic_buffer.h"

void JpegTexture_ReadJpeg(GenericBuffer* dst, FILE* inFile, bool fillBuffer);

void JpegTexture_CheckValidJpeg(GenericBuffer* buf);
