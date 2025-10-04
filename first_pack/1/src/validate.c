#include "../include/validation.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

void printError(char *str){
    printf("Error: %s\n", str);
}

bool validateFlag(const char *flag){
    if ((flag[0] == '/' || flag[0] == '-') && flag[2] == '\0'){
        if (flag[1] == 'h' || flag[1] == 'p' || flag[1] == 's' || flag[1] == 'e' || flag[1] == 'a'|| flag[1] == 'f'){
            return true;
        }
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