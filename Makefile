test: main2.o sorting.o
	gcc main2.o sorting.o -o test2
main2.0: main2.c sorting.h
	gcc -c main2.c
sorting.o: sorting.c sorting.h
	gcc -c sorting.c
