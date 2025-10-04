#ifndef VALIDATION_H
#define VALIDATION_H
#include <stdbool.h>
#include <stdio.h>


typedef enum return_code{
    OK = 0,
    FLAG_ERROR = 1,
    NUMBER_ERROR = 2,
    INPUT_ERROR = 3,
    FUNCTION_ERROR = 4,
    TYPE_ERROR = 5
} return_code;


void printError(char *str);
bool validateFlag(const char *flag);
return_code validateInt(const char *str, int *value);

#endif