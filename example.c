#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
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

static uint32_t getKoo(uint32_t * buffer) {
    uint32_t fragment_low = (buffer[0u] >> 30) & 1u;
    uint32_t fragment_hgh = (buffer[1u] >>  0) & 1u;

    return pow(2u, 0u) * fragment_low + pow(2u, 1u) * fragment_hgh;
}

uint32_t buffer[2];

int main() {
    /*const int number = 14;

    printUInt32AsBinary(number);
    printf("hw\n");*/

    // buffer = 0b1000 0000 0000 1101
    buffer[0] = 2147483661;
    buffer[1] = 1;
    printUInt32AsBinary(buffer[0]);
    printUInt32AsBinary(buffer[1]);

    printf("Doo is: %u\n", getDoo(&buffer[0]));
    printf("Moo is: %u\n", getMoo(&buffer[0]));

    printUInt32AsBinary(buffer[0]);

    bool success = setDoo(&buffer[0], 0u);
    if(success) {
        printf("Doo successfully set to 0.\n");
    }

    printUInt32AsBinary(buffer[0]);

    success = setMoo(&buffer[0], 5u);
    if(success) {
        printf("Moo successfully set to 5.\n");
    }

    printUInt32AsBinary(buffer[0]);

    printf("Koo is: %u\n", getKoo(buffer));

    return 0;
}