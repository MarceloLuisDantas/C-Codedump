#ifndef STRINGS_H
#define STRINGS_H

#include <stdlib.h>

typedef struct String {
    char *array;
    size_t len;
} String;

typedef struct ArrayString {
    String **array;
    size_t len;
    size_t capacity;
} ArrayString;

String *newString(size_t len);
String *CStringToString(char *src);
String *getSlice(String *s, size_t from, size_t to);
int StringCmp(String *s1, String *s2);

ArrayString *newArrayString(size_t capacity);
int ASPush(ArrayString *as, String *string);
String *arrayToString(ArrayString *as);

#endif