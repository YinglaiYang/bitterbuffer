#ifndef DEBUGGING
#define DEBUGGING

#include <stdint.h>

void strreverse(char* begin, char* end);
void itoa(uint32_t value, char* str, uint32_t base);
void printUInt32AsBinary(uint32_t num);

#endif