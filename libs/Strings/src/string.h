#ifndef STRING_H
#define STRING_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// WARNING: This String was made to manipulate strings. 
// Trying to print the String->value may cause undefined behavior
typedef struct String {
    char* value;
    size_t len;
} String;

// Allocs a new String with the wanted size
// Can return NULL
String *newString(size_t len);

// Expected a C Strings, ended with a \0, and convert to a String
// Can return NULL
String *CStringToString(char *origin);

#endif