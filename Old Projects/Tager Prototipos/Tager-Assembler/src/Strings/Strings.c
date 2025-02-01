#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <math.h>
#include "../Linked List/linked_list.h"

char *newStr(int len) {
    return (char *)malloc(sizeof(char) * len);
}

int isEmptyStr(char *s) {
    for (int i = 0; i < strlen(s); i++)
        if (s[i] != ' ')
            return 0;
    return 1;
}

void reallocAndCopy(char **dest, char *src) {
    *dest = newStr(strlen(src) + 1);
    strcpy(*dest, src);
}

char *getSlice(const char *s, size_t from, size_t to) {
    char *ns = newStr(to - from + 1);
    size_t count = 0;
    for (int i = from; i <= to; i++) {
        ns[count] = s[i];
        count += 1;
    }
    ns[to - from] = '\0';
    return ns;
}

void trim(char **s) {
    size_t original_len = strlen(*s);
    if (original_len == 0)
       return;

    if ((*s)[0] == ' ') {
        int count = 0;
        for (int i = 0; i < original_len; i++) {
            if ((*s)[i] != ' ')
                break;
            count += 1;
        }

        char *trimLeft = newStr(original_len - count + 1);
        for (int i = count; i < original_len; i++)
            trimLeft[i - count] = (*s)[i];
        trimLeft[original_len - count] = '\0';

        reallocAndCopy(s, trimLeft);
        free(trimLeft);
    }    

    size_t len = strlen(*s);
    if (len == 0)
        return;
        
    if ((*s)[len - 1] == ' ') {
        int count = 0;
        for (int i = len - 1; i >= 0; i--) {
            if ((*s)[i] != ' ')
                break;
            count += 1;
        }

        char *trimLeft = newStr(len - count + 1);
        for (int i = 0; i < len - count; i++)
            trimLeft[i] = (*s)[i];
        trimLeft[len - count] = '\0';

        reallocAndCopy(s, trimLeft);
        free(trimLeft);
    }
}

// Remove all extra spaces in a string
// "   teste   foo bar   " -> "teste foo bar"
void removeExtraSpaces(char **s) {
    trim(s);

    size_t len = 0;
    int spaces = 0;
    for (int i = 0; i < strlen(*s); i++) {
        if ((*s)[i] == ' ') {
            if (spaces == 0) {
                spaces = 1;
                len += 1;
            }
        } else {
            len += 1;
            spaces = 0;
        }
    }

    char *sup = newStr(len + 1);
    int index = 0;
    for (int i = 0; i < strlen(*s); i++) {
        if ((*s)[i] == ' ') {
            if (spaces == 0) {
                spaces = 1;
                sup[index] = (*s)[i];
                index += 1;
            }
        } else {
            sup[index] = (*s)[i];
            index += 1;
            spaces = 0;
        }
    }
    sup[len] = '\0';

    reallocAndCopy(s, sup);
    free(sup);
}

char **split(const char *s, const char splitter) {
    LinkedList *l = newLinkedList();

    size_t from = 0;
    for (size_t i = 0; i <= strlen(s); i++) {
        if(s[i] == splitter || s[i] == '\0') {
            char *slice = getSlice(s, from, i);
            add(l, slice);
            from = i + 1;
        }
    }
    add(l, "\0");

    char **slices = toArray(l);
    return slices;
}

char *arrayToString(char **array) {
    int len = 0;
    for (int i = 0;; i++) {
        if (strcmp(array[i], "\0") == 0) {
            len += i;
            break;
        }
        len += strlen(array[i]);
    }

    char *s = newStr(len);
    int count = 0;
    for (int i = 0;; i++) {
        if (strcmp(array[i], "\0") == 0)
            break;

        for (int j = 0; j < strlen(array[i]); j++) {
            s[count] = array[i][j];
            count += 1;
        }
        s[count] = ' ';
        count += 1;
    }
    s[len - 1] = '\0';

    return s;
}

char *concat(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int nlen = len1 + len2 + 2;
    char *nStr = (char *)malloc(sizeof(char) * nlen);
    for (int i = 0; i < len1; i++)
        nStr[i] = str1[i];
    nStr[len1] = ' ';
    for (int i = 0; i < len2; i++)
        nStr[len1 + i + 1] = str2[i];
    nStr[nlen - 1] = '\0';
    return nStr;
}

void intToStr(char **s, int num) {
    *s = (char *)malloc(sizeof(char) * (int)(floor(log10(num))) + 2);
    sprintf(*s, "%d", num);
}
