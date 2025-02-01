#ifndef FILES_H
#define FILES_H

#include <stdint.h>
#include "../Linked List/linked_list.h"

typedef struct File {
    LinkedList *lines;
    char *name;
    uint32_t len;
} File;

File *loadFile(const char *path);
void saveFile(File *file, const char *newFileName);
void addLine(File *file, char *value);
void insertLine(File *file, char *value, uint32_t index);
void appliedToLines(File *file, void (*map)(Node *));
void removeLine(File *file, uint32_t index);
void editLine(File *file, char *value, uint32_t index);
void freeFile(File *file);

#endif
