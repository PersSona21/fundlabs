#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/main.h"


int main(int argc, char* argv[]){
    if (argc != 3){
        printError("should be number and flag\n");
        return INPUT_ERROR;
    }
    const char *flag = argv[2];

    if (!validateFlag(flag)){
        printError("incorrect flag\n");
        return FLAG_ERROR;
    }

    const char *str = argv[1];
    int x;
    return_code code = validateInt(str, &x);
    if (code == INPUT_ERROR){
        return INPUT_ERROR;
    }
    else if (code == TYPE_ERROR){
        return TYPE_ERROR;
    }


    switch (flag[1]) {
        case 'h': {
            int count;
            int *arr = divisors(x, &count);
            printH(arr, count); // вывод
            break;
            }
        case 'p': {
            bool res = isPrime(x);
            printP(res, x); // вывод
            break;
            }
        case 's': {
            int count;
            char *arr = splitToHEX(x, &count);
            printS(arr, count); // вывод
            break;
            }
        case 'e': {
            long (*table)[10] = tableOfDegrees(x);
            printE(table, x);
            break;
            }
        case 'a': {
            long sum = sumOfNaturalNumbers(x);
            printA(sum); // вывод
            break;
            }
        case 'f':{
            long long res = factorialOf(x);
            printF(res); // вывод
            break;
            }
        default:
            printError("incorrect flag");
            return FLAG_ERROR;
    }

    return OK;
}