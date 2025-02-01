#ifndef FILE_H
#define FILE_H

#include <stdint.h>
#include "linked_list.h"

typedef struct File {
    char **lines;
    uint32_t len;
} File;

File *loadFile(const char *path);
void saveFile(File *file);
void addLine(File *file, char *value);
void insertLine(File *file, char *value, uint32_t index);
void appliedToLines(File *file, void (*map)(Node *));
void removeLine(File *file, uint32_t index);
void editLine(File *file, char *value, uint32_t index);

#endif