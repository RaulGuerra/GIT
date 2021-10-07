#include <stdio.h>
#include <stddef.h>

typedef struct {
	long number;
	char *name;
	char *phone;
	double salary;
} Employee, *ptrToEmployee;

typedef const Employee *PtrToConstEmployee;