#include "alumnos.h"
#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ALUM 100

int cmpCode(const void* x, const void* y){
  const Alumno* a = (const Alumno *)x;
  const Alumno* b = (const Alumno *)y; 
  
  return a -> code - b -> code;
}

int cmpName(const void* x, const void* y){
  const Alumno* a = (const Alumno *)x;
  const Alumno* b = (const Alumno *)y; 

  return(strcmp(a -> name, b -> name));

}
int cmpAge(const void* x, const void* y){
  const Alumno* a = (const Alumno *)x;
  const Alumno* b = (const Alumno *)y; 

  return a -> age - b -> age;

}
int cmpProm(const void* x, const void* y){
  const Alumno* a = (const Alumno *)x;
  const Alumno* b = (const Alumno *)y;
  
  if (a -> prom != b -> prom)
    return (a -> prom > b -> prom) ? -1 : 1;

  return(strcmp(a -> name, b -> name));

}

printAlum(Alumno alumnos, int n){
  for(int i = 0; i < n; i++){
    printf("%d %s %d %.2f\n", 
          alumnos[i].code,
          alumnos[i].name,
          alumnos[i].age,
          alumnos[i].prom);
  }
}

int main(){
  int lenAlum;
  scanf("%d", lenAlum);

  Alumno alumnos[MAX_ALUM];

  for(int i = 0; i < lenAlum; i++){
    scanf("%d %s %d %.2f",
          alumnos[i].code,
          alumnos[i].name,
          alumnos[i].age,
          alumnos[i].prom);
  }

  char criterio[20];
  scanf("%s", criterio);
  
  Comparator cmp;

  if (strcmp(criterio, "CODIGO") == 0)
    cmp = cmpCode;

  if (strcmp(criterio, "NOMBRE") == 0)
    cmp = cmpName;

  if (strcmp(criterio, "EDAD") == 0)
    cmp = cmpAge;
  
  if (strcmp(criterio, "PROMEDIO") == 0)
    cmp = cmpProm;

  insertionSort(alumnos, lenAlum, sizeof(Alumno), cmp);

  printAlum(alumnos, lenAlum);

  return 0;
}
