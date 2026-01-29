#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/main.h"


int main(int argc, char *argv[])
{
    if (argc != 3 && argc != 4) {
        fprintf(stderr, "usage: <flag> <input file> [output file]\n");
        return INPUT_ERROR;
    }

    const char *flag = argv[1];
    if (!validateFlag(flag, "disa", 4, "n", 1)){
        fprintf(stderr, "incorrect flag\n");
        return FLAG_ERROR;
    }

    const char *input_name = argv[2];
    const char *output_name = NULL;

    char mode = 0;
    bool need_create_flag = false;


    if (strlen(flag) == 2) {
        mode = flag[1];
    }
    else if (strlen(flag) == 3) {
        mode = flag[2];
        need_create_flag = true;
    }

    // determine the name of output file
    char auto_output[512] = {0};
    if (need_create_flag) {
        output_name = argv[3];
    } else {
        snprintf(auto_output, sizeof(auto_output), "out_%s", input_name);
        output_name = auto_output;
    }

    // open input file
    FILE *input = fopen(input_name, "r");
    if (!input) {
        perror("can't open input file");
        return FILE_OPEN_ERROR;
    }

    // open output file
    FILE *output = fopen(output_name, "w");
    if (!output) {
        perror("can't open/create output file");
        fclose(input);
        return 1;
    }

    
    switch (mode) {
        case 'd':
            funcA(input, output);     // exclude arabic numbers
            break;
        case 'i':
            funcB(input, output);     // counting latin alphabet chars in every string
            break;
        case 's':
            funcC(input, output);     // counting special chars in every string
            break;
        case 'a':
            funcD(input, output);     // hex every char without nums
            break;
        default:
            fprintf(stderr, "Unknown flag: %c\n", mode);
            fclose(input);
            fclose(output);
            return FLAG_ERROR;
    }

    fclose(input);
    fclose(output);
    
    return 0;
}