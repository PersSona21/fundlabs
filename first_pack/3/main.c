#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"


void printError(char *str){
    printf("Error: %s\n", str);
}

bool validateFlag(const char *flag){
    if ((flag[0] == '/' || flag[0] == '-') && flag[2] == '\0'){
        if (flag[1] == 'q' || flag[1] == 'm' || flag[1] == 't'){
            return true;
        }
    }
    return false;
}


int main(int argc, char* argv[]){
    if (argc < 4){
        printError("Incorrect input");
        return INPUT_ERROR;
    }

    const char *flag = argv[1];

    if (!validateFlag(flag)){
        printError("incorrect flag\n");
        return FLAG_ERROR;
    }
    switch (flag[1]) {
        case 'q': 
            // solveQE
            break;
        case 'm': 
            // multiplicityCheck
            break;
        case 't':
            // isTriangle
            break;
        default:
            printError("incorrect flag");
            return FLAG_ERROR;
    }

    return OK;
}