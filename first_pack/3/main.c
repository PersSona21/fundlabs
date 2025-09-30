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

void solveQE(double eps, double a, double b, double c){
    return;
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
            if (argc < 6){
                printError("must be eps, a, b, c");
                return INPUT_ERROR;
            }
            // solveQE
            break;
        case 'm':
            if (argc < 4){
                printError("must be a, b");
                return INPUT_ERROR;
            }
            // multiplicityCheck
            break;
        case 't':
            if (argc < 6){
                printError("must be eps, a, b, c");
                return INPUT_ERROR;
            }
            // isTriangle
            break;
        default:
            printError("incorrect flag");
            return FLAG_ERROR;
    }

    return OK;
}