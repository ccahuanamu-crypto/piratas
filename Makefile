test: main.o sorting.o 
	gcc main.o sorting.o test
main.o: main.c sorting.h
	gcc -c main.c
sorting.o: sorting.c sorting.h
	gcc -c sorting.c
