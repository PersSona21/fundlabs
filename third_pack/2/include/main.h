#ifndef MAIN_H
#define MAIN_H
#include "validation.h"
#include "vector.h"
#include <stdarg.h>

void *copyInt(void *p);
void deleteInt(void *p);

// Вывод элементов вектора типа int
void printIntVector(const Vector *v);

#endif