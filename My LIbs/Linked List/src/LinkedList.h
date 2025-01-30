#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdint.h>
#include "Strings.h"

typedef struct Node {
    struct Node *next;
    String *value;
} Node;

typedef struct LinkedList {
    Node *start;
    uint32_t len;
} LinkedList;

LinkedList *newLinkedList();
void add(LinkedList *l, char *value);
String *getValue(LinkedList *l, uint32_t index);
String *getValueCopy(LinkedList *l, uint32_t idnex);
int delete(LinkedList *l, uint32_t index);
int set(LinkedList *l, char *value, uint32_t index);
int insert(LinkedList *l, char *value, uint32_t index);
ArrayString *toArray(LinkedList *l);

#endif