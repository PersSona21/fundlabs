#ifndef MAIN_H
#define MAIN_H

typedef enum return_code{
    OK = 0,
    FLAG_ERROR = 1,
    NUMBER_ERROR = 2,
    INPUT_ERROR = 3
} return_code;

void printError(char *str);
bool validateFlag(const char *flag);
void solveQE(double eps, double a, double b, double c);
void multiplicityCheck(int a, int b);

#endif