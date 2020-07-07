#ifndef DEBUGGING
#define DEBUGGING

#include <stdint.h>

void strreverse(char* begin, char* end);
void itoa(uint32_t value, char* str, uint32_t base);
void printUInt32AsBinary(uint32_t num);
void printBufferAsBinary(uint32_t *buffer, uint32_t bufferLength);

#endif