#ifndef SORTING_H
#define SORTING_H
typedef int (*Comparator)(const void*, const void*);
void insertionSort(void*, int, int, Comparator);
#endif
