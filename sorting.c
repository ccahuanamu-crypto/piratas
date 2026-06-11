#include "sorting.h"
void swapBytes(void* x, void* y, int size){

  unsigned char* a = x;
  unsigned char* b = y;

  for(int i = 0; i < size; i++){
    unsigned char tmp = a[i];
    a[i] = b[i];
    b[i] = tmp;
  }
}

void insertionSort(void* base, int n, int size, Comparator cmp){
  unsigned char* a = base;

  for(int i = 1; i < n; i++){
    int j = i;
    while(j > 0 && cmp(a + j * size, a + (j - 1) * size) < 0){
      swapBytes(a + j * size, a + (j - 1) * size, size);
      j--;
    }
  }
}
