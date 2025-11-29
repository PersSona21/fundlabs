#include "../include/main.h"


char *convertToBase2r(int value, int r) {
    if (r < 1 || r > 5){
        return NULL;
    }

    int mask = (1 << r) - 1;
    bool negative = false;

    if (value < 0) {
        negative = true;
        value = (~value + 1); // доп запись числа
    }

    char buffer[256];
    size_t pos = 0;

    if (value == 0){
        buffer[pos++] = '0';
    }

    while (value != 0){
        int digit = value & mask;
        char c;
        if ((0 <= digit) && (digit <= 9)){
            buffer[pos++] = '0' + digit;
        }
        else{
            buffer[pos++] =  'A' + (digit - 10);
        }
        value >>= r; // делим на 2^r
    }

    if (negative) {
        buffer[pos++] = '-';
    }

    buffer[pos] = '\0';
    
    char *ans = malloc(pos + 1);
    for (size_t i = 0; i < pos; i++)
        ans[i] = buffer[pos - 1 - i];
    ans[pos] = '\0';

    return ans;
}
