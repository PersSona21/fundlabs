#include "../include/main.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

const char* list = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static int charToDecimal(const char c){
    int num = 0;
    if ('0' <= c && c <= '9'){
        num = c - '0';
    }
    else if ('A' <= c && c <= 'Z'){
        num = c - 'A' + 10;
    }
    else return -1;
    return num;
}

char* remove_leading_zeros(const char* str) {
    if (str == NULL) {
        return strdup("0");
    }

    size_t i = 0;
    for (i = 0; i < strlen(str) - 1; ++i) {
        if (str[i] != '0') {
            break;
        }
    }

    return strdup(str + i);
}

int toDecimal(const char* str, const int base){
    // printf("%s\n", str);
    if (str == NULL) {
        return -1;
    }
    long long result = 0;

    for (size_t i = 0; i < strlen(str); ++i){
        char c = toupper(str[i]);
        int digit = charToDecimal(c);
        if (digit < 0 || digit > base) {
            return -1;
        }
        result = result * base + digit;
    }

    if (result > INT_MAX || result < INT_MIN) {
        return OVERFLOW_ERROR;
    }

    return (int) result;
}

int minimumBasis(const char *str){
    int max = 1;
    for (size_t i = 0; i < strlen(str); ++i){
        char c = toupper(str[i]);
        int num = charToDecimal(c);
        if (num == -1) return FUNCTION_ERROR;
        if (num > max) max = num;
    }
    return max + 1;
}

