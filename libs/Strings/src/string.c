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
String *newString(size_t len) {
    String *ns = malloc(sizeof(String));
    if (ns == NULL)
        return NULL;

    ns->value = malloc(sizeof(char) * len); 
    if (ns->value == NULL)
        return NULL;

    ns->len = len;
    return ns;
}

// Expected a C Strings, ended with a \0, and convert to a String
// Can return NULL
String *CStringToString(char *origin) {
    size_t len = strlen(origin);
    String *ns = newString(len);
    if (ns == NULL)
        return NULL;

    for (int i = 0; i < len; i++)
        ns->value[i] = origin[i];

    return ns;
}

