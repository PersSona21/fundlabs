#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include "main.h"


void printError(char *str){
    printf("Error: %s\n", str);
}

return_code validateDouble(const char *s, double *value) {
    char *end;
    double num = strtod(s, &end);

    if (s == NULL || *s == '\0') {
        printError("Input error");
        return INPUT_ERROR;
    }


    if (*end != '\0') {
        printError("Must be double");
        return TYPE_ERROR;
    }
    
    if (num > DBL_MAX || num < DBL_MIN) {
        printError("Must be double");
        return TYPE_ERROR;
    }

    *value = num;
    return OK;
}

double trapezoid(Func f, double a, double b, int n){
    double h = (b - a) * n;
    double sum = 0.5 * (f(a) - f(b));
    for (int i = 1; i < n; ++i){
        sum += f(a + i * h);
    }
    return sum * h;
}

double integrate(Func f, double a, double b, double eps){
    int n = 1;
    double Tn = trapezoid(f, a, b, n);
    double T2n;

    while (1){
        n *= 2;
        T2n = trapezoid(f, a, b, n);
        double err = fabs(T2n - Tn) / 3.0;

        if (err < eps) {
            return (4 * T2n - Tn) / 3.0;
        }
        
        Tn = T2n;
    }
}

int main(int argc, char* argv[]){
    if (argc != 2){
        printError("Incorrect input");
        return INPUT_ERROR;
    }
    return OK;
}