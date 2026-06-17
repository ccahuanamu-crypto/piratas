#include "platos.h"
#include "sorting.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_DISH 1000

int moreimportant(const char* dish){
  if(strcmp(dish, "MEAT") == 0) return 1;
  if(strcmp(dish, "FISH") == 0) return 2;
  if(strcmp(dish, "DESSERT")== 0) return 3;

  return 4;
}

int cmpOrders(const void* x, const void* y){
  const Order* a = (const Order *) x;
  const Order* b = (const Order *) y;

  int d1 = moreimportant(a -> dish);
  int d2 = moreimportant(b -> dish);

  if (d1 != d2)
    return d1 - d2;

  return a -> arrivalOrder - b -> arrivalOrder;
}

void printOrder(Order dishes[], int n){
  for (int i = 0; i < n; i++){
    printf("%s\n",
           dishes[i].customer);
  }
}
int main(){
  int lenDish;
  scanf("%d", &lenDish);

  Order dishes[MAX_DISH];

  for (int i = 0; i < lenDish; i++){
    scanf("%s %s",
          dishes[i].customer,
          dishes[i].dish);
    dishes[i].arrivalOrder = i;
  }

  insertionSort(dishes, lenDish, sizeof(Order), cmpOrders);

  printOrder(dishes, lenDish);

  return 0;
}

