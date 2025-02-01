#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>

typedef struct Node {
    struct Node *next;
    char *value;
} Node;

typedef struct LinkedList {
    Node *start;
    uint32_t len;
} LinkedList;

LinkedList *newLinkedList();
void add(LinkedList *l, char *value);
void delete(LinkedList *l, uint32_t index);
void applied(LinkedList *l, void (*map)(Node*));
void set(LinkedList *l, char *value, uint32_t index);
void insert(LinkedList *l, char *value, uint32_t index);
char **toArray(LinkedList *l);

#endif