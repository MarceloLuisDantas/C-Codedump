#ifndef FILE_H
#define FILE_H
#define _GNU_SOURCE

#include "linked_list.h"
#include "format_line.h"

typedef struct FileLines {
    char **lines;
    size_t len;
} FileLines;

FileLines *getLines(const char *file);

#endif