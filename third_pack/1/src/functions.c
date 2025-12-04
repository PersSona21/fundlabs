#include "../include/main.h"


static int add(int a, int b){
    while (b != 0) {
        int temp = a & b;
        a = a ^ b;
        b = temp << 1;
    }
    return a;
}

static int neg(int a){
    return add(~a, 1);
}

static int sub(int a, int b){
    return add(a, neg(b));
}

char *convertToBase2r(int value, int r) {
    if (r < 1 || r > 5){
        return NULL;
    }

    int mask = sub((1 << r), 1);
    bool negative = false;

    if (value < 0) {
        negative = true;
        value = neg(value); // доп запись числа
    }

    char buffer[256];
    size_t pos = 0;

    if (value == 0){
        buffer[pos] = '0';
        pos = add(pos, 1);
    }

    while (value != 0){
        int digit = value & mask;
        char c;
        if ((0 <= digit) && (digit <= 9)){
            buffer[pos] = add('0', digit);
            pos = add(pos, 1);
        }
        else{
            buffer[pos] =  add('A', sub(digit, 10));
            pos = add(pos, 1);
        }
        value >>= r; // делим на 2^r
    }

    if (negative) {
        buffer[pos] = '-';
        pos = add(pos, 1);
    }

    buffer[pos] = '\0';
    
    char *ans = malloc(add(pos, 1));
    for (size_t i = 0; i < pos; i++)
        ans[i] = buffer[sub(sub(pos, 1), i)];
    ans[pos] = '\0';

    return ans;
}
