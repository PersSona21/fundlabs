#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/validation.h"
#include "../include/main.h"


int main()
{   
    int base;
    char buf[256];

    if (fgets(buf, sizeof(buf), stdin) == NULL) {
        printError("INPUT ERROR");
        return INPUT_ERROR;
    }
    
    if (validateInt(buf, &base) != OK){
        printError("TYPE ERROR");
    }

    if (base < 2 || base > 36) {
        printError("Base must be in range 2..36");
        return INPUT_ERROR;
    }

    long maxAbs = LONG_MIN;
    char* maxOriginal = NULL;
    bool isneg = false;

    while (true){
        if (fgets(buf, sizeof(buf), stdin) == NULL) {
            break;
        }

        buf[strcspn(buf, "\n\r")] = '\0'; // set end of line

        if (strcmp(buf, "Stop") == 0) {
            break;
        }

        // if (buf[0] == '-') printf("Helllooo\n");

        if (!strValidation(buf)) {
            printError("Must be num or Stop");
            return TYPE_ERROR;
        }

        bool negative = false;
        int dec = 0;
        if (buf[0] == '-'){
            negative = true;
            dec = toDecimal(buf+1, base);

        }
        else{
            dec = toDecimal(buf, base);
        }
        // printf("%d\n", dec);
        if (dec == -1) {
            return FUNCTION_ERROR;
        }
        if (negative) dec = -dec;

        long absValue = abs(dec);
        if (absValue > maxAbs) {
            maxAbs = absValue;
            if (maxOriginal){
                free(maxOriginal);
            }
            if (negative) maxOriginal = strdup(buf+1);
            else maxOriginal = strdup(buf);
            isneg = negative;
        }
    }

    char* s9  = intToBase9(maxAbs);
    char* s18 = intToBase18(maxAbs);
    char* s27 = intToBase27(maxAbs);
    char* s36 = intToBase36(maxAbs);
    if (isneg) printf("-%s: -%s -%s -%s -%s\n", removeLeadingZeros(maxOriginal), s9, s18, s27, s36);
    else printf("%s: %s %s %s %s\n", removeLeadingZeros(maxOriginal), s9, s18, s27, s36);

    free(maxOriginal);

    return 0;
}