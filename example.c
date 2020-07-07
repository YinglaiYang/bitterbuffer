#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "debugging.h"

/**
 * This here assumes that bit 0 is a single "boolean" flag called Doo. And that bits 1..3 are a 3-bit field called Moo.
 * 
 **/

static uint32_t getDoo(uint32_t *buffer) {
    return (*buffer >> 0) & 1u;
}

static uint32_t getMoo(uint32_t *buffer) {
    return (*buffer >> 1) & 7u;
}

static bool setDoo(uint32_t *buffer, uint32_t val) {
    *buffer = (*buffer & 0xFFFFFFFE) | (val << 0u);

    return true;
}

static bool setMoo(uint32_t *buffer, uint32_t val) {
    *buffer = (*buffer & 0xFFFFFFF1) | (val << 1u);

    return true;
}

static uint32_t getKoo(uint32_t *buffer) {
    uint32_t fragment_low = (buffer[0] >> 31) & 1u;
    uint32_t fragment_hgh = (buffer[1] >>  0) & 3u;

    return pow(2u, 0u) * fragment_low + pow(2u, 1u) * fragment_hgh;
}

static bool setKoo(uint32_t *buffer, uint32_t val) {
    buffer[0] = (buffer[0] & 0x8FFFFFFF) | (((val >> 0u) & 0x1) << 31);
    buffer[1] = (buffer[1] & 0xFFFFFFFC) | (((val >> 1u) & 0x3) <<  0); // cycle the value by the number of bits of the low fragment

    return true;
}

uint32_t buffer[2];
uint32_t bufferSize_Byte = sizeof(buffer) / sizeof(buffer[0]);

int main() {
    /*const int number = 14;

    printUInt32AsBinary(number);
    printf("hw\n");*/

    // buffer = 0b1000 0000 0000 1101
    buffer[0] = 2147483661;
    buffer[1] = 3;
    printBufferAsBinary(buffer, bufferSize_Byte);

    printf("Doo is: %u\n", getDoo(&buffer[0]));
    printf("Moo is: %u\n", getMoo(&buffer[0]));

    printBufferAsBinary(buffer, bufferSize_Byte);

    bool success = setDoo(&buffer[0], 0u);
    if(success) {
        printf("Doo successfully set to 0.\n");
    }

    printBufferAsBinary(buffer, bufferSize_Byte);

    success = setMoo(&buffer[0], 5u);
    if(success) {
        printf("Moo successfully set to 5.\n");
    }

    printBufferAsBinary(buffer, bufferSize_Byte);

    printf("Koo is: %u\n", getKoo(buffer));

    success = setKoo(buffer, 3u);
    if(success) {
        printf("Koo successfully set to 3.\n");
    }

    printBufferAsBinary(buffer, bufferSize_Byte);

    return 0;
}