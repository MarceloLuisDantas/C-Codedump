#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

typedef struct String {
    char *str;
    size_t len;
} String;

String *newString(const char *s);
void trimLeft(String *s);
void trimRight(String *s);
void trim(String *s);
void removeExtraSpaces(String *s);

#endif 