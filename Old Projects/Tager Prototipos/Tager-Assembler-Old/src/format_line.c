/* 1º Stage - 
 * The first stage is responsible for cleaning the source code, 
 * removing blank lines, indentation, and comments. 
 * Only the parts important for the final result are kept.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "linked_list.h"

#define TRUE 1
#define FALSE 0

typedef struct Line {
    char *line;
    int len;
} Line;

int is_blank_line(char *line, int len) {
    while (len > 0) {
        if (line[len - 1] != ' ' && line[len - 1] != '\n')
            return FALSE;
        len -= 1;
    }
    return TRUE;
}

char *remove_extra_white_spaces (char *line, int len) {
    // Counts how many chars and single white spaces
    int non_white_spaces = 0;
    int spaces = 0;
    for (int i = 0; i < len; i++) {
        // in the line "test number 1", 2 spaces needs to be in count
        // but in the line "test  number  1". are 2 more spaces
        if (line[i] == ' ' && spaces == 0) {
            non_white_spaces += 1;
            spaces = 1;
        } else if (line[i] != ' ') {
            spaces = 0;
            non_white_spaces += 1;
        }
    }    

    char *newLine = (char *)malloc(sizeof(char) * non_white_spaces);
}

Line *format_line(char *line, int len) {
    Line *formated_line = (Line *)malloc(sizeof(Line));
    formated_line->len = 0;

    if (is_blank_line(line, len) == TRUE)
        return formated_line;

    formated_line->len = len;
    formated_line->line = line;
    return formated_line;
}



