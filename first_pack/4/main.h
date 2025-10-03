#ifndef MAIN_H
#define MAIN_H

typedef enum return_code{
    OK = 0,
    FLAG_ERROR = 1,
    NUMBER_ERROR = 2,
    INPUT_ERROR = 3,
    DIVIDE_BY_ZERO = 4,
    FUNCTION_ERROR = 5,
    TYPE_ERROR = 6
} return_code;

typedef double (*Func)(double);


void printError(char *str);
return_code validateDouble(const char *s, double *value);
double trapezoid(Func f, double a, double b, int n);
double integrate(Func f, double a, double b, double eps);

#endif