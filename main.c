#include "sorting.h"
#include <stdio.h>
/*
int CmpPrt(const void* x, void* y){
  const Pirate* p1 = (const Pirate*) x;
  const Pirate* p2 = (const Pirate*) y;

  if (p1 -> bounty != p2 -> bounty){
    return (p1 -> bounty > p2 -> bounty) ? -1 : 1;
  }

  if (p1 -> age != p2 -> age){
    return p1 -> age - p2 -> age;
  }

  int cmpName = strcmp(p1 -> name, p2 -> name);
  if (cmpName != 0)
    return cmpName;

  return strcmp(p1 -> crew, p2 -> crew);

}
*/ 
int compareInt(const void* x, const void* y){
  int a = *(const int*)x;
  int b = *(const int*)y;
  
  if(a < b) return -1;
  if(a > b) return 1;
  return 0;
}

int main(){
  int arr[] = {4, 2, 3, 1};

  insertionSort(arr, 4, sizeof(int), compareInt);
  
  for(int i = 0; i < 4; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
