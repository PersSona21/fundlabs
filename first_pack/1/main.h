#ifndef MAIN_H
#define MAIN_H

typedef enum return_code{
    OK = 0,
    FLAG_ERROR = 1,
    NUMBER_ERROR = 2,
    ARGUMENT_ERROR = 3
} return_code;

void printError(char *str);
bool validateFlag(const char *flag);
void multiplesOfX(int x);
void isPrime(int x);
void splitToHEX(int x);
void tableOfDegrees(int x);
void sumOfNaturalNumbers(int x);
void factorialOf(int x);


#endif