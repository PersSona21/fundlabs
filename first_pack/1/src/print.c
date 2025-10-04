#include "../include/print.h"


void printH(const int* arr, int count){
    if (count == 0) printf("No divisors\n");
    else{
        for (int i = 0; i < count; ++i){
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

void printP(bool res, int x){
    if (x > 1){
        if (res) printf("%d is prime number\n", x);
        else printf("%d is composite number\n", x);
    }
    else printf("%d is not composit and not prime\n", x);
}

void printS(char* arr, int count){
    for (int i = count; i >= 0; --i){
        printf("%c ", arr[i]);
    }
    printf("\n");
}

void printE(long (*table)[10], int x){
    if (table) {
        for (int i = 0; i < x; i++) {
            printf("POW of %d:\t", i+1);
            for (int j = 0; j < 10; j++) {
                printf("%10ld ", table[i][j]);
            }
            printf("\n");
        }
    }
    else printf("X must be not greater than 10 and not less than 1\n");
}

void printA(long sum){
    if (!sum){
        printError("x must be not less than 1\n");
        return;
    }
    printf("Sum is %ld\n", sum);
}
void printF(long long res){
    if (res == -1){
        printError("long long overflow\n");
        return;
    }
    else if (!res){
        printError("must be not less than 0");
        return;
    }
    else printf("%lld\n", res);
}