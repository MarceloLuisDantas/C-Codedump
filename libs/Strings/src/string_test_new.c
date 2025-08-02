#include <stdio.h>
#include "string.h"

char *alloc_str(const char* value) {
    char *str = malloc(strlen(value));
    strcpy(str, value);
    return str;
}

int main() {
    char *cstr = alloc_str("hello world\n");
    String *s1 = CStringToString(cstr);

    printf("String: %s", s1->value);

    return 0;
}