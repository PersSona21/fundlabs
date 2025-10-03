#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
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

void printError(char *str){
    printf("Error: %s\n", str);
}

return_code validateInt(const char *str, int *value){
    char *end;
    long num = strtol(str, &end, 10);

    if(*end != '\0' && *end != '\n'){ // добавил проверку на '\n'
        printError("input problem");
        return INVALID_INPUT;
    }

    if (num < INT_MIN || num > INT_MAX){
        printError("must be int");
        return TYPE_ERROR;
    }

    *value = (int) num;

    return OK;
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
    char buffer[64];
    if (!fgets(buffer, sizeof(buffer), stdin)){
        printError("input problem");
        return INVALID_INPUT;
    }
    // buffer[strcspn(buffer, "\n")] = '\0'; раньше использовал но встроил проверку в validateInt
    return_code res = validateInt(buffer, &T);
    if (res == INVALID_INPUT){
        return INVALID_INPUT;
    }
    else if (res == TYPE_ERROR){
        return TYPE_ERROR;
    }
    if (T <= 0){
        printError("T must be more then 0");
        return LESS_THAN_1;
    }
    for(int i = 0; i < T; ++i){
        char buffer2[64];
        if (!fgets(buffer2, sizeof(buffer2), stdin)){
            printError("input problem");
            return INVALID_INPUT;
        }
        // buffer2[strcspn(buffer2, "\n")] = '\0'; раньше использовал но встроил проверку в validateInt
        return_code res2 = validateInt(buffer2, &n);
        if (res2 == INVALID_INPUT){
            return INVALID_INPUT;
        }
        else if (res2 == TYPE_ERROR){
            return TYPE_ERROR;
        }
        if (n < 1){
            printError("n must be more then 0");
            return LESS_THAN_1;
        }
        printf("%d prime number is %lld\n", n, getPrime(n));
        
    }
    return OK;
}