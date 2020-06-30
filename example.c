#include <stdio.h>
#include <stdint.h>
#include "debugging.h"

static void printUInt32AsBinary(int num) {
    char binaryString[32] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
    itoa(num, binaryString, 2);

    printf("%s\n", binaryString);
}

int main() {
    const int number = 14;

    printUInt32AsBinary(number);
    printf("hw\n");

    return 0;
}