#ifndef MAIN_H
#define MAIN_H

typedef enum return_code{
    OK = 0,
    LESS_THAN_1 = 1,
    INVALID_INPUT = 2,
} return_code;

bool isPrime(long long x);
long long getPrime(int x);

#endif