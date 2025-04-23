#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "linked_list.h"

typedef struct File {
    LinkedList *lines;
    const char *name;
} File;

void loadLines(File *f, const char *path) {
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Could not load file - %s\n", path);
        exit(1);
    }

    // This print needs to be immortalized (for reasonss)
    // printf("\n"); 
    char *line = NULL;
    size_t _n = 0;
    ssize_t len; // Len of the line
    while ((len = getline(&line, &_n, fp)) != -1) {
        if (line[len - 1] == '\n') {    
            line[(len + 1) - 2] = '\0';
        }
        add(f->lines, line);
    }

    fclose(fp);
    free(line);
}

File *loadFile(const char *path) {
    File *file = (File *)malloc(sizeof(File));
    file->name = path;    
    file->lines = newLinkedList();
    loadLines(file, path);
    return file;
}

void addLine(File *file, char *value) {
    add(file->lines, value);
}

void insertLine(File *file, char *value, uint32_t index) {
    insert(file->lines, value, index);
}

void editLine(File *file, char *value, uint32_t index) {
    set(file->lines, value, index);
}

void removeLine(File *file, uint32_t index) {
    delete(file->lines, index);
}

void appliedToLines(File *file, void (*map)(Node *)) {
    applied(file->lines, map);
}

void saveFile(File *file) { 
    FILE *fp = fopen(file->name, "w");
    if (fp == NULL) {
        printf("Could not load file - %s\n", file->name);
        exit(1);
    }

    Node *sup = file->lines->start;
    while (sup != NULL) {
        fprintf(fp, "%s\n", sup->value);
        sup = sup->next;
    }
    
    fclose(fp);
}

// TODO
// void writeLIne(const char *path, char *line, uint32_t line_number);