#ifndef MAIN_H
#define MAIN_H
#include "validation.h"
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#define MAXINT 1000000000

typedef struct {
    double value; 
    bool hasRepr;
} FractionInfo;

int gcd(int a, int b);
int hasRepresintation(double x, int base);
FractionInfo* mainFunction(int base, int count, ...);

#endif