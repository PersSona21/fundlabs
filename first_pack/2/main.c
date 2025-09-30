#include <stdio.h>
#include <stdbool.h>
#include "main.h"

bool isPrime(long long x){
    if (x == 2){
        return true;
    }
    else if (x < 2){
        return false;
    }
    for (long long i = 2; i * i < x + 1; ++i){
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

long long getPrime(int x){
    int counter = 0;
    long long i = 2;
    while (counter != x){
        if (isPrime(i)){
            counter += 1;
        }
        i++;
    }
    return i - 1;
}

int main(){
    int T, n;
    if (!scanf("%d", &T)){
        printf("Error: incorrect input\n");
        return INVALID_INPUT;
    }
    if (T <= 0){
        printf("Error: T must be more then 0\n");
        return LESS_THAN_1;
    }
    for(int i = 0; i < T; ++i){
        if (!scanf("%d", &n)){
            printf("Error: incorrect input\n");
            return INVALID_INPUT;
        }
        if (n < 1){
            printf("Error: n must be more then 0\n");
            return LESS_THAN_1;
        }
        printf("%lld\n", getPrime(n));
        
    }
    return OK;
}