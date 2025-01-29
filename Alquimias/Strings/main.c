#include <stdio.h>
#include <stdlib.h>
#include "string.h"

int main() {
    // String *string = newString("      ");
    // trimLeft(string);
    // printf("%s-fim\n", string->str);

    // String *string2 = newString("      ");
    // trimRight(string2);
    // printf("%s-fim\n", string2->str);

    String *string3 = newString("      ");
    trim(string3);
    printf("-%s-fim\n", string3->str);

    removeExtraSpaces(string3);
    printf("-%s\n", string3->str);

    // String *string4 = newString("   Teste       foo   bar   ");
    // removeExtraSpaces(string4);
    // trim(string4);
    // printf("%s\n", string4->str);

    String *string5 = newString("      ");
    removeExtraSpaces(string5);
    printf("-%s-\n", string5->str);
}