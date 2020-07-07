#include "debugging.h"

#include <stdio.h>

/**
	
 * Ansi C "itoa" based on Kernighan & Ritchie's "Ansi C":
	
 */
	
void strreverse(char* begin, char* end) {
	char aux;
	
	while(end>begin)
		aux=*end, *end--=*begin, *begin++=aux;
}
	
void itoa(uint32_t value, char* str, uint32_t base) {
	static char num[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	char* wstr=str;
	
	// Validate base
	if (base<2 || base>35){ *wstr='\0'; return; }

	// Conversion. Number is reversed.
	do *wstr++ = num[value%base]; while(value/=base);
	
	*wstr='\0';
	
	// Reverse string
	strreverse(str,wstr-1);
}


void printUInt32AsBinary(uint32_t num) {
    char binaryString[32] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
    itoa(num, binaryString, 2);

    printf("%s\n", binaryString);
}

void printBufferAsBinary(uint32_t *buffer, uint32_t bufferLength) {
	printf("\n");
	printf("===============================\n");
	printf("Buffer content per 4-Byte block\n");
	printf("-------------------------------\n");
	for(int n=0; n < bufferLength; n++) {
		printf("[%u]: ", n);
		printUInt32AsBinary(buffer[n]);
	}
	printf("\n");
}