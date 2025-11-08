#include "../include/main.h"

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// если все простые множители знаменателя q 
// содержатся среди простых множителей основания b, то представление существует
int hasRepresintation(double x, int base){
    // превращаю дробь в p/q
    int q = 1;
    while(fabs((x * q) - (int)(x * q)) > 1e-9 && q < MAXINT){
        q *= 10;
    }
    // переполнение int
    if (q == MAXINT && fabs((x * q) - (int)(x * q)) > 1e-9){
        return OWERFLOW_ERROR;
    }

    int num = (int)(x * q);
    int g = gcd(num,q);
    q /= g;

    // ищем простые множетели base
    int primes[32];
    int size = 0;
    for (int p = 2; p <= base; ++p){
        if (base % p == 0){
            primes[size++] = p;
            while (base % p == 0) {
                base /= p;
            }
        }
    }
    
    // смотрим есть ли другие множетели
    for (int i = 0; i < size; ++i){
        while (q % primes[i] == 0) {
            q /= primes[i];
        }
    }

    return q == 1;
}


FractionInfo* mainFunction(int base, int count, ...){
    if (count <= 0){
        return NULL;
    }
    va_list args;
    va_start(args, count);
    FractionInfo* results = malloc(count * sizeof(FractionInfo));
    if (!results) {
        return NULL;
    }
    for(int i = 0; i < count; ++i){
        double x = va_arg(args, double);
        results[i].value = x;
        results[i].hasRepr = (bool)(hasRepresintation(x, base) == 1);
    }
    va_end(args); // очищаем
    return results;
}
