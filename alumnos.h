#ifndef ALUMNOS_H
#define ALUMNOS_H
#define MAX_SIZE 40

typedef struct {
	int code;
	char name[MAX_SIZE];
	int age;
	double prom;
} Alumno;
#endif
