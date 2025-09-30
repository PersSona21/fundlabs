#ifndef MAIN_H
#define MAIN_H

typedef enum return_code{
    OK = 0,
    FLAG_ERROR = 1,
    NUMBER_ERROR = 2,
    INPUT_ERROR = 3,
    DIVIDE_BY_ZERO = 4,
    FUNCTION_ERROR = 5
} return_code;

void printError(char *str);
bool validateFlag(const char *flag);
return_code solveQE(double eps, double a, double b, double c);
return_code multiplicityCheck(int a, int b);
return_code isTriangle(double eps, double a, double b, double c);

#endif