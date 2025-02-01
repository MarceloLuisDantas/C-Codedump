#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "format_line.h"

typedef struct FileLines {
    char **lines;
    size_t len;
} FileLines;

FileLines *getLines(const char *file) {
    LinkedList *lines = newLinkedList();

    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        printf("Could load file - %s\n", file);
        exit(0);
    }

    char *line = NULL; 
    size_t _n = 0;    
    ssize_t len; // Len of the line
    while ((len = getline(&line, &_n, fp)) != -1) {
        Line *formated_line = format_line(line, len);
        add(lines, formated_line->line, formated_line->len);
    }

    fclose(fp);
    if (line)
        free(line);

    char **raw_lines = toArray(lines);
    
    FileLines *f = (FileLines *)malloc(sizeof(FileLines));
    f->lines = raw_lines;
    f->len = lines->len;

    return f;
}