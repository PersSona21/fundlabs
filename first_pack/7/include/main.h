#ifndef MAIN_H
#define MAIN_H
#include "validation.h"
#include <stdio.h>

int toDecimal(const char* str, const int base);
char* remove_leading_zeros(const char* str);
int minimumBasis(const char* str);

#endif