#include "../include/validation.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

void printError(char *str){
    printf("Error: %s\n", str);
}

bool validateFlag(
    const char *flag,
    const char *allowed_chars,
    size_t chars_count,
    const char *allowed_prefixes,
    size_t prefix_count)
{
    if (!flag) return false;

    size_t len = strlen(flag);
    if (len < 2 || len > 3) return false;

    if (flag[0] != '-' && flag[0] != '/') return false;

    if (len == 2)
    {
        return memchr(allowed_chars, flag[1], chars_count) != NULL;
    }

    if (len == 3 && prefix_count > 0)
    {
        if (memchr(allowed_prefixes, flag[1], prefix_count) == NULL)
            return false;

        return memchr(allowed_chars, flag[2], chars_count) != NULL;
    }
    
    return false;
}

return_code validateInt(const char *str, int *value){
    char *end;
    long num = strtol(str, &end, 10);

    if(end == NULL && *end != '\0'){
        printError("Input must be <int> <flag>");
        return INPUT_ERROR;
    }

    if (num < INT_MIN || num > INT_MAX){
        printError("Must be int");
        return TYPE_ERROR;
    }

    *value = (int) num;

    return OK;
}

return_code validateDouble(const char *s, double *value) {
    char *end;
    double num = strtod(s, &end);

    if (s == NULL && *s == '\0') {
        printError("Input error");
        return INPUT_ERROR;
    }


    if (*end != '\0' && *end != '\n') {
        printError("Must be double");
        return TYPE_ERROR;
    }

    *value = num;
    return OK;
}

bool strValidation(const char *str){
    if (!str){
        return false;
    }
    for (size_t i = 0; i < strlen(str); ++i){
        char c = str[i];
        if (('0' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')){
            return true;
        }
    }
    return false;
}