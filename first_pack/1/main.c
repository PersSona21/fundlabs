#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"


void printError(char *str){
    printf("Error: %s\n", str);
}

char validateFlag(const char *flag){
    if ((flag[0] == '/' || flag[0] == '-') && flag[2] == '\0'){
        if (flag[1] == 'h' || flag[1] == 'p' || flag[1] == 's' || flag[1] == 'e' || flag[1] == 'a'|| flag[1] == 'f'){
            return 1;
        }
    }
    return 0;
}

void multiplesOfX(const int x){
    char flag = 0;
    if (x > 100){
        printf("No numbers multiples of %d\n", x);
        return;
    }
    for(int i = 1; i <= 100; ++i){
        if (i % x == 0){
            flag = 1;
            printf("%d multiple of %d\n", i, x);
        }
    }
    if (!flag){
        printf("No numbers multiples of %d\n", x);
    }
}

void isPrime(const int x){
    if (x == 2){
        printf("2 is prime\n");
        return;
    }
    else if (x < 2){
        printf("%d is composit\n", x);
        return;
    }
    char flag = 0;
    for (int i = 2; i <= floor(sqrt(x)) + 1; ++i){
        if (x % i == 0){
            flag = 1;
            printf("%d is composit\n", x);
            return;
        }
    }
    printf("%d is prime\n", x);
}

void splitToHEX(const int x){
    if (x == 0){
        printf("0\n");
        return;
    }

    unsigned ux = (unsigned) x;
    char buffer[32];
    int pos = 0;

    while(ux > 0){
        int num = ux % 16;
        buffer[pos++] = (num < 10) ? ('0' + num) : ('A' + num - 10);
        ux /= 16;
    }

    for (int i = pos - 1; i >= 0; --i){
        if (i == 0) printf("%c\n", buffer[i]);
        else printf("%c ", buffer[i]);
    }
}

void tableOfDegreese(const int x){
    if (x < 1){
        printError("x must bigger then 0");
        return;
    }
    else if (x > 10){
        printError("x must not bigger then 10");
        return;
    }
    
    for (int i = 1; i <= x; ++i){
        for (int j = 1; j <= 10; ++j){
            if (j == 10){
                printf("%10ld\n\n", (long) pow(j, i));
            }
            else if (j == 1){
                if (i == 10){
                    printf("POW %d: %9d", i, 1);
                }
                else printf("POW %d: %10d", i, 1);
            }
            else{
                printf("%10ld ", (long) pow(j, i));
            }
        }
    }
}

void sumOfNaturealNumbers(const int x){
    long sum = 0;
    for (int i = 1; i <= x; ++i){
        sum += i;
    }
    printf("sum of %d is %ld\n", x, sum);
}

void factorialOf(const int x){
    long long fac = 1;
    for (int i = 1; i <= x; ++i){
        fac *= i;
    }

    printf("factorial of %d is %lld\n", x, fac);
}

int main(int argc, char* argv[]){
    if (argc != 3){
        printError("should be number and flag\n");
        return ARGUMENT_ERROR;
    }

    const char *flag = argv[2];

    if (!validateFlag(flag)){
        printError("incorrect flag\n");
        return FLAG_ERROR;
    }
    const int x = atoi(argv[1]);
    switch (flag[1]) {
        case 'h': 
            multiplesOfX(x);
            break;
        case 'p': 
            isPrime(x);
            break;
        case 's':
            splitToHEX(x);
            break;
        case 'e':
            tableOfDegreese(x);
            break;
        case 'a':
            sumOfNaturealNumbers(x);
            break;
        case 'f':
            factorialOf(x);
            break;
        default:
            printError("incorrect flag");
            return FLAG_ERROR;
    }

    return OK;
}