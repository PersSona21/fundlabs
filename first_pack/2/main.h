#ifndef MAIN_H
#define MAIN_H

typedef enum return_code{
    OK = 0,
    LESS_THAN_1 = 1,
    INVALID_INPUT = 2,
    TYPE_ERROR = 3
} return_code;

void printError(char *str);
bool isPrime(long long x);
return_code validateInt(const char *str, int *value);
long long getPrime(int x);

#endif