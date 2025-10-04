#include "../include/main.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int* divisors(int x, int *count){
    static int arr[100];
    int len = 0;
    if (x < 1 || x > 100){
        *count = 0;
        return arr;
    }
    for(int i = 1; i <= 100; ++i){
        if (i % x == 0){
            arr[len++] = i;
        }
    }
    *count = len;
    return arr;
}

bool isPrime(int x){
    if (x == 2){
        return true;
    }
    else if (x < 2){
        return false;
    }
    for (int i = 2; i * i < x + 1; i += 2){
        // printf("%d\t", i);
        if (x % i == 0){
            return false;
        }
    }
    return true;
}

char* splitToHEX(int x, int *count){
    static char arr[32];
    bool flag = false;
    int pos = 0;

    if (x == 0){
        arr[0] = '0';
        *count = 1;
        return arr;
    }

    if (x < 0) {
        flag = true;
        x = -x;
    }

    while(x > 0){
        int num = x % 16;
        if (num < 10) arr[pos++] = ('0' + num);
        else arr[pos++] = ('A' + num - 10);
        x /= 16;
    }
    if (flag){
        arr[pos++] = '-';
    }
    pos--;
    *count = pos;

    // for (int i = count; i >= 0; --i){ так выводить
    //     printf("%c ", arr[i]);
    // }

    return arr;
}

long (*tableOfDegrees(int x))[10]{
    static long arr[10][10];

    if (x < 1 || x > 10) {
        return NULL;
    }

    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= 10; ++j) {
            arr[i-1][j-1] = (long) pow(j, i);
        }
    }

    return arr;

}

long sumOfNaturalNumbers(int x){
    if (x < 1){
        return 0;
    }
    long sum = x * (1 + x) / 2;
    return sum;
}

long long factorialOf(int x){
    long long fac = 1;

    if (x > 20) return -1; // не вмещается в long long
    if (x < 0) return 0; // меньше 0
    for (int i = 1; i <= x; ++i){
        fac *= i;
    }

    return fac;
}
