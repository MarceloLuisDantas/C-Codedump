#ifndef FORMAT_LINE_H
#define FORMAT_LINE_H

#include "linked_list.h"

typedef struct Line {
    char *line;
    int len;
} Line;

Line *format_line(char *line, int len);

#endif