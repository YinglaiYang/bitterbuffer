buildrun:
	gcc -Wall -c debugging.c && gcc -Wall -c example.c && gcc -o example debugging.o example.o && ./example