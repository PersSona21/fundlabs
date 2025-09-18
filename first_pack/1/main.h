#ifndef MAIN_H
#define MAIN_H

typedef enum return_code{
    OK = 0,
    FLAG_ERROR = 1,
    NUMBER_ERROR = 2,
    ARGUMENT_ERROR = 3
} return_code;

void printError(char *str);
char validateFlag(const char *flag);
void multiplesOfX(const int x);
void isPrime(const int x);
void splitToHEX(const int x);
void tableOfDegreese(const int x);
void sumOfNaturealNumbers(const int x);
void factorialOf(const int x);


#endif