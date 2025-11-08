#include "../include/main.h"



int main(int argc, char* argv[]){

    int base = 2;
    int count = 5;

    FractionInfo* results = mainFunction(base, count, 0.5, 0.25, 0.3, 0.125, 0.3111);
    for (int i = 0; i < count; ++i){
        printf("%f %d\n", results[i].value, results[i].hasRepr);
    }
    return OK;
}