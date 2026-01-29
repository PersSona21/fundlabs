#include "../include/main.h"
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

const char* latin_alphabet = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
const char* ext_latin_alphabet = " 0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
const char* numbers = "0123456789";

static bool inString(char c, const char* allowed){
    if (allowed == NULL){
        return false;
    }
    return strchr(allowed, c) != NULL;
}

void funcA(FILE* input, FILE* output){
    int ch = 0;
    while ((ch = fgetc(input)) != EOF){
        if (!inString(ch, numbers)){
            fputc(ch, output);
        }
    }
}


void funcB(FILE* input, FILE* output)
{
    char* line = NULL;
    size_t len = 0;
    ssize_t num;

    while ((num = getline(&line, &len, input)) != -1)
    {
        size_t count = 0;
        for (size_t i = 0; i < (size_t)num; i++)
        {
            if (inString(line[i], latin_alphabet))
                count++;
        }
        fprintf(output, "%zu\n", count);
    }
    free(line);
}

void funcC(FILE* input, FILE* output){
    char* line = NULL;
    size_t len = 0;
    ssize_t num;

    while ((num = getline(&line, &len, input)) != -1){
        size_t count = 0;
        for(size_t i = 0; i < (size_t)num; ++i){
            unsigned char c = (unsigned char)line[i];
            if (c == '\n' || c == '\r') {
                continue;
            }
            if ((c & 0xC0) == 0x80) { // skip utf-8 second part of char
                continue;
            }
            if (!inString(c, ext_latin_alphabet)) {
                count++;
    }
        }
        fprintf(output, "%zu\n", count);
    }
    free(line);
}


void funcD(FILE* input, FILE* output){
    int ch = 0;
    while ((ch = fgetc(input)) != EOF){
        if (ch == '\n' || ch == '\r') {
            fputc(ch, output);
        }
        else if (inString(ch, numbers))
            fputc(ch, output);
        else
            fprintf(output, "%02X", (unsigned char)ch); // from int to hex
    }
}