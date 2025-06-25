#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <stdint.h>
#include "node/node.h"

typedef struct {
    Node *start;
    uint16_t len;
} DoubleLinkedList;

DoubleLinkedList *newLinkedList();
int addNode(DoubleLinkedList *self, int64_t value);
int64_t get(DoubleLinkedList *self, int16_t index);
int set(DoubleLinkedList *self, int16_t index, int64_t value);

#endif