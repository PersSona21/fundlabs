#ifndef VALIDATION_H
#define VALIDATION_H

#include <stdbool.h>
#include <stdlib.h>


typedef enum return_code{
    OK = 0,
    FLAG_ERROR = 1,
    INPUT_ERROR = 2,
    FUNCTION_ERROR = 3,
    TYPE_ERROR = 4,
    FILE_OPEN_ERROR = 5,
    OVERFLOW_ERROR = -2
} return_code;

void printError(char *str);
bool validateFlag(
    const char *flag,
    const char *allowed_chars,
    size_t chars_count,
    const char *allowed_prefixes,
    size_t prefix_count);
return_code validateInt(const char *str, int *value);
bool strValidation(const char *str);

#endif