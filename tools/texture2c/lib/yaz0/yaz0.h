#ifndef _YAZ0_H_
#define _YAZ0_H_

void yaz0_decode(uint8_t* src, uint8_t* dst, int uncompressedSize);

int yaz0_encode(uint8_t *src, uint8_t *dest, int srcSize);

#endif  // _YAZ0_H_
