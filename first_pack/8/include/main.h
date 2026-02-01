#ifndef MAIN_H
#define MAIN_H
#include "validation.h"
#include <stdio.h>

int toDecimal(const char* str, const int n);
char* removeLeadingZeros(const char* str);
char* intToBase9(const int num);
char* intToBase18(const int num);
char* intToBase27(const int num);
char* intToBase36(const int num);

#endif