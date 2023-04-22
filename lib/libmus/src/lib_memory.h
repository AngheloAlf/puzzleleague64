#ifndef LIBMUS_LIB_MEMORY_H
#define LIBMUS_LIB_MEMORY_H

#include "ultra64.h"

void	__MusIntMemInit			(void *addr, int length);
ALHeap	*__MusIntMemGetHeapAddr	(void);
void	*__MusIntMemMalloc		(int length);
int 	__MusIntMemRemaining	(void);

void	__MusIntMemSet			(void *dest, unsigned char value, int length);
void	__MusIntMemMove			(void *dest, void *src, int length);

#endif
