#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct String {
    char *array;
    size_t len;
} String;

/*  Returns the pointer to a empty String with size of len
    Will returns a NULL Array if len = 0
*/
String *newString(size_t len) {
    String *s = (String *)malloc(sizeof(String));
    if (len != 0)
        s->array = (char *)malloc(sizeof(char) * len);
    else 
        s->array = NULL;
    s->len = len;
    return s;
}

typedef struct ArrayString {
    String **array;
    size_t len;
    size_t capacity;
} ArrayString;

/*  Create a new Array of Strings.
    if Capacity = 0, a NULL pointer is returned
*/
ArrayString *newArrayString(size_t capacity) {
    if (capacity == 0)
        return NULL;

    ArrayString *as = (ArrayString *)malloc(sizeof(ArrayString));
    as->array = (String **)malloc(sizeof(String *) * capacity);
    as->capacity = capacity;
    as->len = 0;

    return as;
}

// ==================================================
// ============== FUNCTIONS TO STRINGS ============== 
// ==================================================

size_t count(String *s, char item) {
    size_t total = 0;
    for (int i = 0; i < s->len; i++)
        if (s->array[i] == item)
            total += 1;
    return total;
}

// strlen from <strings.h> equivalent 
size_t cstrlen(char *s) {
    int i = 0;
    while (s[i] != '\0')
        i += 1;
    return i; 
}

// Checks if a range [form, to] is inside of a String's len 
int isInRange(String *s, int from, int to) {
    if (from > to) 
        return FALSE;

    if (from >= s->len || to >= s->len) 
        return FALSE;

    return TRUE;
}

/*  Receives a default C String ended with "\0", and convert to 
    a struct String. 
 */
String *CStringToString(char *src) {
    size_t len = cstrlen(src);
    String *ns = newString(len);
    for (int i = 0; i < len; i++)
        ns->array[i] = src[i];
    return ns; 
}

// Compare 2 diferent Strings
int StringCmp(String *s1, String *s2) {
    if (s1->len != s2->len)
        return FALSE;

    for (int i = 0; i < s1->len; i++)
        if (s1->array[i] != s2->array[i])
            return FALSE;
    
    return TRUE;
}

/*  Returns a new String, with the specific slice from the passed String 
    ['M', 'a', 'r', 'i', 's', 'a'], from 2 to 4 returns ['r', 'i', 's']
    From/To are bouth from 0 to Len.
    If the range is out of bounds, a NULL string will be returned.
*/
String *getSlice(String *s, size_t from, size_t to) {
    if (isInRange(s, from, to) == FALSE)
        return NULL;
  
    size_t len_n_string = to - from + 1;
    String *ns = newString(len_n_string);
    for (int i = 0; i < len_n_string; i++)
        ns->array[i] = s->array[i + from];
    
    return ns;
}

// TODO -
void trim() { }
void remove_white_space() { }
void split() { }

// ==================================================
// ========= FUNCTIONS TO ARRAYS OF STRINGS ========= 
// ==================================================


// Pushs the value in the Array, returns -1 if full
int ASPush(ArrayString *as, String *string) {
    if (as->len == as->capacity)
        return -1;

    as->array[as->len] = string;
    as->len += 1;

    return 1;
}

// Converts all Strings in a Array of Strings into a single String 
String *arrayToString(ArrayString *as) {
    if (as->len == 0)
        return NULL;

    size_t total_len = 0;
    for (int i = 0; i < as->len; i++) 
        total_len += as->array[i]->len + 1; // +1 for the space
    total_len -= 1; 


    String *s = newString(total_len);
    int i = 0;
    for (int j = 0; j < as->len; j++) {
        for (int k = 0; k < as->array[j]->len; k++) {
            s->array[i] = as->array[j]->array[k];
            i += 1;
        }
        s->array[i] = ' ';
        i += 1;
    }

    return s;
}