#include "../include/main.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

const char* list = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

static int charToDigit(const char c){
    if ('0' <= c && c <= '9'){
        return c - '0';
    }
    else if ('A' <= c && c <= 'Z'){
        return c - 'A' + 10;
    }
    return -1;
}

static char digitToChar(int d) {
    if (d < 10) return '0' + d;
    return 'A' + (d - 10);
}

char* removeLeadingZeros(const char* str) {
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

int toDecimal(const char* str, const int n){
    if (str == NULL) {
        return -1;
    }
    long long result = 0;

    for (size_t i = 0; i < strlen(str); ++i){
        char c = str[i];
        int digit = charToDigit(c);
        if (digit < 0 || digit > n) {
            return -1;
        }
        result = result * n + digit;
    }

    if (result > INT_MAX || result < INT_MIN) {
        return OVERFLOW_ERROR;
    }

    return (int)result;
}

static char* intToBase(int num, int base) {
    if (base < 2 || base > 36) {
        return NULL;
    }

    if (num == 0){
        return "0";
    }

    char buf[32];
    int pos = 0;

    int temp = num;

    while (temp > 0) {
        int rem = temp % base;
        buf[pos++] = digitToChar(rem);
        temp /= base;
    }

    char* result = malloc(pos + 1);
    if (!result) return NULL;

    for (int i = 0; i < pos; ++i) {
        result[i] = buf[pos - 1 - i];
    }
    result[pos] = '\0';

    return result;
}

char* intToBase9(const int num){
    return intToBase(num, 9);
}
char* intToBase18(const int num){
    return intToBase(num, 18);
}
char* intToBase27(const int num){
    return intToBase(num, 27);
}
char* intToBase36(const int num){
    return intToBase(num, 36);
}