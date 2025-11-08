#include "../include/main.h"


int main(int argc, char* argv[]){
    const char *text = "Hello, world!";
    char *result = strchr(text, 'o');

    printf("%s\n", result);

    return 0;
}