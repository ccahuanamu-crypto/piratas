#include "piratas.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PIRATES 1000

int CmpPrt(const void* x,const void* y){
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

void printPirate(Pirate pirates[], int n){
  for (int i = 0; i < n; i++){
    printf("%s %lld %d %s\n",
          pirates[i].name,
          pirates[i].bounty,
          pirates[i].age,
          pirates[i].crew);
  }
}

int main(){
  int lenPirates;
  scanf("%d", &lenPirates);

  Pirate pirates[MAX_PIRATES];

  for(int i = 0; i < lenPirates; i++ ){
    scanf("%s %lld %d %s",
          pirates[i].name,
          &pirates[i].bounty,
          &pirates[i].age,
          pirates[i].crew);
  }

  insertionSort(pirates, lenPirates, sizeof(Pirate), CmpPrt);
 
  printPirate(pirates, lenPirates);
  
  
  return 0;

}
