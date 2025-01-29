#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct String {
    char *str;
    size_t len;
} String;

int isEmptyStr(String *s) {
    for (int i = 0; i < s->len; i++)
        if (s->str[i] != ' ')
            return 0;
    return 1;
}

void trimLeft(String *s) {
    if (s->len == 0)
        return;

    if (isEmptyStr(s) == 1) {
        char *new_str = (char *)malloc(sizeof(char));
        new_str[0] = ' ';
        
        free(s->str);
        s->str = new_str;
        s->len = 0;
        return;
    }
    
    if (s->str[0] != ' ')
        return;

    size_t total_white_spaces = 0;
    size_t count = 0;
    while (s->str[count] == ' ') {
        total_white_spaces += 1;
        count += 1;
    }
    
    size_t new_len = s->len - total_white_spaces;
    char *new_str = (char *)malloc(sizeof(char) * new_len);
    for (int i = 0; i < new_len; i++)
        new_str[i] = s->str[total_white_spaces + i];
    
    free(s->str);
    s->str = new_str;
    s->len = new_len;
}

void trimRight(String *s) {
    if (s->len == 0)
        return;
        
    if (isEmptyStr(s) == 1) {
        char *new_str = (char *)malloc(sizeof(char));
        new_str[0] = ' ';
        
        free(s->str);
        s->str = new_str;
        s->len = 0;
        return;
    }
    
    if (s->str[s->len - 1] != ' ')
        return;

    size_t total_white_spaces = 0;
    size_t count = s->len - 1;
    while (s->str[count] == ' ') {
        total_white_spaces += 1;
        count -= 1;
    }
    
    size_t new_len = s->len - total_white_spaces;
    char *new_str = (char *)malloc(sizeof(char) * new_len);
    for (int i = 0; i < new_len; i++)
        new_str[i] = s->str[i];
    
    free(s->str);
    s->str = new_str;
    s->len = new_len;
}

void trim(String *s) {
    if (s->len == 0)
        return;
    
    if (isEmptyStr(s) == 1) {
        char *new_str = (char *)malloc(sizeof(char));
        new_str[0] = ' ';
        
        free(s->str);
        s->str = new_str;
        s->len = 0;
        return;
    }
    
    if (s->str[s->len - 1] != ' ')
        return;

    size_t white_spaces_left = 0;
    size_t count = 0;
    while (s->str[count] == ' ') {
        white_spaces_left += 1;
        count += 1;
    } 

    size_t white_spaces_right = 0;
    size_t count2 = s->len - 1;
    while (s->str[count2] == ' ') {
        white_spaces_right += 1;
        count2 -= 1;
    }

    size_t total_white_spaces = white_spaces_left + white_spaces_right;
    
    size_t new_len = s->len - total_white_spaces;
    char *new_str = (char *)malloc(sizeof(char) * new_len);
    for (int i = 0; i < new_len; i++) 
        new_str[i] = s->str[white_spaces_left + i];
    
    free(s->str);
    s->str = new_str;
    s->len = new_len;
}

void removeExtraSpaces(String *s) {
    if (s->len == 0)
        return;

    trim(s);
    if (s->len == 0) {
        printf("======= -%s-\n", s->str);
        return;
    }

    char *supStr = (char *)malloc(sizeof(char) * s->len);
    uint16_t white_spaces = 0;
    uint8_t  correct_len  = 0;
    for (int i = 0; i < s->len; i++) {
        char ch = s->str[i];
        if (ch != ' ') {
            supStr[correct_len] = ch;
            correct_len += 1;
            white_spaces = 0;
        } else {
            if (white_spaces == 0) {
                supStr[correct_len] = ch;
                correct_len += 1;
                white_spaces = 1;
            }
        }
    }

    char *newStr = (char *)malloc(sizeof(char) * correct_len);
    for (int i = 0; i < correct_len; i++)
        newStr[i] = supStr[i];
    
    free(s->str);
    s->len = correct_len;
    s->str = newStr;
}


String *newString(const char *s) {
    size_t len = strlen(s);
    String *nString = (String *)malloc(sizeof(String));
    nString->str = (char *)malloc(sizeof(char) * len);
    memcpy(nString->str, s, len);
    nString->len = len;
    return nString;    
}