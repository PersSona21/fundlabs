#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include "main.h"


void printError(char *str){
    printf("Error: %s\n", str);
}

bool validateFlag(const char *flag){
    if ((flag[0] == '/' || flag[0] == '-') && flag[2] == '\0'){
        if (flag[1] == 'q' || flag[1] == 'm' || flag[1] == 't'){
            return true;
        }
    }
    return false;
}

return_code validateInt(const char *str, int *value){
    char *end;
    long num = strtol(str, &end, 10);

    if(end == NULL || *end != '\0'){
        printError("Input must be <int> <flag>");
        return INPUT_ERROR;
    }

    if (num < INT_MIN || num > INT_MAX){
        printError("Must be int");
        return TYPE_ERROR;
    }

    *value = (int) num;

    return OK;
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

bool cmp(const double *arr1, const double *arr2, double eps){
    for (int i = 0; i < 3; ++i){
        if (fabs(arr1[i] - arr2[i]) > eps){
            return false;
        }
    }
    return true;
}

return_code solveQE(double eps, double a, double b, double c){
    printf("-----------------------------\n");
    printf("For eps = %f, a = %f, b = %f, c = %f\n", eps, a, b, c);
    if (fabs(a) <= eps){
        if (fabs(b) <= eps){
            if (fabs(c) <= eps){
                printf("Infinity of roots\n");
            }
            else{
                printf("No roots\n");
            }
        }
        else{
            if (fabs(c) <= eps){
                printf("x = 0\n");
            }
            else {
                double x = -c / b;
                printf("x = %f\n", x);
            }
        }
    }
    else{
        double d = b * b - 4 * a * c;
        if (d > eps){
            double sd = sqrt(d);
            double x1 = (-b + sd) / (2 * a);
            double x2 = (-b - sd) / (2 * a);
            printf("x1 = %f, x2 = %f\n", x1, x2);
        }
        else if (fabs(d) <= eps){
            double x = -b / (2 * a);
            printf("x = %f\n", x);
        }
        else{
            printf("No real roots\n");
        }
    }
    return OK;
}

return_code shuffle(double eps, double a, double b, double c){
    double perms[6][3] = {
        {a, b, c},
        {a, c, b},
        {b, a, c},
        {b, c, a},
        {c, a, b},
        {c, b, a}
    };

    for (int i = 0; i < 6; ++i){
        bool flag = true;
        for (int j = 0; j < i; ++j){
            if (cmp(perms[i], perms[j], eps)){
                flag = false;
                break;
            }
        }
        if (flag){
            solveQE(eps, perms[i][0], perms[i][1], perms[i][2]);
        }
    }
    return OK;
}

return_code multiplicityCheck(int a, int b){
    if (a == 0 || b == 0){
        return NUMBER_ERROR;
    }
    if (a % b == 0){
        printf("%d multiples of %d\n", a, b);
    }
    else{
        printf("%d is not a multiples of %d\n", a, b);
    }
    return OK;
}

return_code isTriangle(double eps, double a, double b, double c){
    if (a <= eps || b <= eps || c <= eps){
        printf("They can't be sides of a triangle\n");
        return OK;
    }
    if (fabs(a * a + b * b - c * c) <= eps 
    || fabs(a * a + c * c - b * b) <= eps 
    || fabs(c * c + b * b - a * a) <= eps){
        printf("They can be sides of a triangle\n");
    }
    else {
        printf("They can't be sides of a triangle\n");
    }
    return OK;
}

int main(int argc, char* argv[]){
    if (argc < 4){
        printError("Incorrect input");
        return INPUT_ERROR;
    }

    const char *flag = argv[1];

    if (!validateFlag(flag)){
        printError("incorrect flag\n");
        return FLAG_ERROR;
    }
    switch (flag[1]) {
        case 'q':
            if (argc != 6){
                printError("must be eps, a, b, c");
                return INPUT_ERROR;
            }
            double eps, a, b, c;
            return_code codeEps = validateDouble(argv[2], &eps);
            return_code codeA = validateDouble(argv[3], &a);
            return_code codeB = validateDouble(argv[4], &b);
            return_code codeC = validateDouble(argv[5], &c);
            if (codeA) return FUNCTION_ERROR;
            if (codeB) return FUNCTION_ERROR;
            if (codeC) return FUNCTION_ERROR;
            if (codeEps) return FUNCTION_ERROR;
            if (shuffle(eps, a, b, c)){
                return FUNCTION_ERROR;
            }
            break;
        case 'm':
            if (argc != 4){
                printError("must be a, b");
                return INPUT_ERROR;
            }
            int a1, b1;
            return_code codeA1 = validateInt(argv[2], &a1);
            return_code codeB1 = validateInt(argv[3], &b1);
            if (codeA1) return FUNCTION_ERROR;
            if (codeB1) return FUNCTION_ERROR;
            if(multiplicityCheck(a1, b1) == NUMBER_ERROR){
                printError("a or b can't equal 0");
            }
            break;
        case 't':
            if (argc != 6){
                printError("must be eps, a, b, c");
                return INPUT_ERROR;
            }
            double eps2, a2, b2, c2;
            return_code codeEps2 = validateDouble(argv[2], &eps2);
            return_code codeA2 = validateDouble(argv[3], &a2);
            return_code codeB2 = validateDouble(argv[4], &b2);
            return_code codeC2 = validateDouble(argv[5], &c2);
            if (codeA) return FUNCTION_ERROR;
            if (codeB) return FUNCTION_ERROR;
            if (codeC) return FUNCTION_ERROR;
            if (codeEps) return FUNCTION_ERROR;
            if (isTriangle(eps2, a2, b2, c2)){
                return FUNCTION_ERROR;
            }
            break;
        default:
            printError("incorrect flag");
            return FLAG_ERROR;
    }

    return OK;
}