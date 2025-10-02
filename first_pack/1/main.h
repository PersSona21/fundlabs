#ifndef MAIN_H
#define MAIN_H

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
return_code multiplesOfX(int x);
return_code isPrime(int x);
return_code splitToHEX(int x);
return_code tableOfDegrees(int x);
return_code sumOfNaturalNumbers(int x);
return_code factorialOf(int x);


#endif