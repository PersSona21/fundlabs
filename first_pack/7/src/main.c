#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/main.h"


int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "usage: <input file> <output file>\n");
        return INPUT_ERROR;
    }


    const char *input_name = argv[1];
    const char *output_name = argv[2];

    // open input file
    FILE *input = fopen(input_name, "r");
    if (!input) {
        perror("can't open input file");
        return FILE_OPEN_ERROR;
    }

    // open output file
    FILE *output = fopen(output_name, "w");
    if (!output) {
        perror("can't open output file");
        fclose(input);
        return 1;
    }

    char buf[256];

    while (fscanf(input, "%s", buf) == 1) {
        if (!strValidation(buf)){
            printf("ERROR: not a number in input file\n");
            return INPUT_ERROR;
        }
        char * str = remove_leading_zeros(buf);
        fprintf(output, "%s %d %d\n", str, minimumBasis(str), toDecimal(str, minimumBasis(str)));
        free(str);
    }

    fclose(input);
    fclose(output);
    
    return 0;
}