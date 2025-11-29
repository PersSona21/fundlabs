#include "../include/main.h"


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printError("Usage: <number> <r>");
        return INPUT_ERROR;
    }

    int number = 0;
    int r = 0;

    if (validateInt(argv[1], &number) != OK) {
        return NUMBER_ERROR;
    }

    if (validateInt(argv[2], &r) != OK) {
        return NUMBER_ERROR;
    }

    if (r < 1 || r > 5) {
        printError("r must be 1..5");
        return INPUT_ERROR;
    }

    char *res = convertToBase2r(number, r);
    if (!res) {
        printError("Function error");
        return FUNCTION_ERROR;
    }

    printf("Result: %s\n", res);
    free(res);

    return OK;
}
