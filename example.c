#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "debugging.h"

/**
 * This here assumes that bit 0 is a single "boolean" flag called Doo. And that bits 1..3 are a 3-bit field called Moo.
 * 
 **/

static uint32_t getDoo(uint32_t * buffer) {
    return (*buffer >> 0) & 1u;
}

static uint32_t getMoo(uint32_t * buffer) {
    return (*buffer >> 1) & 7u;
}

static bool setDoo(uint32_t * buffer, uint32_t val) {
    *buffer = (*buffer & 0xFFFE) | (val << 0u);

    return true;
}

static bool setMoo(uint32_t * buffer, uint32_t val) {
    *buffer = (*buffer & 0xFFF1) | (val << 1u);

    return true;
}

uint32_t buffer;

int main() {
    /*const int number = 14;

    printUInt32AsBinary(number);
    printf("hw\n");*/

    // buffer = 0b0000 0000 0000 1101
    buffer = 13;
    printUInt32AsBinary(buffer);

    printf("Doo is: %u\n", getDoo(&buffer));
    printf("Moo is: %u\n", getMoo(&buffer));

    printUInt32AsBinary(buffer);

    bool success = setDoo(&buffer, 0u);
    if(success) {
        printf("Doo successfully set to 0.\n");
    }

    printUInt32AsBinary(buffer);

    success = setMoo(&buffer, 5u);
    if(success) {
        printf("Moo successfully set to 5.\n");
    }

    printUInt32AsBinary(buffer);

    return 0;
}