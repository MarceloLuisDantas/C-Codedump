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
void trim_left(String **s);
void trim_right(String **s);
void trim(String **s);
void remove_white_space(String **s);
ArrayString *split(String *s, const char spliter);

ArrayString *newArrayString(size_t capacity);
String *arrayToString(ArrayString *as);
int ASPush(ArrayString *as, String *string);

#endif