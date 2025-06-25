#include <stdint.h>
#include <stdlib.h>
#include "node/node.h"

typedef struct {
    Node *start;
    uint16_t len;
} DoubleLinkedList;

// Can return NULL
DoubleLinkedList *newLinkedList() {
    DoubleLinkedList *list = malloc(sizeof(DoubleLinkedList));
    if (list == NULL)
        return NULL;

    list->len = 0;
    list->start = NULL;
    return list;
}

// If return 0, the node was not allocated
int addNode(DoubleLinkedList *self, int64_t value) {
    Node *nn = newNode(value);
    if (nn == NULL)
        return 0;

    if (self->len == 0) {
        self->start = nn;
        self->len += 1;
        return 1;
    }

    Node *sup = self->start;
    while (sup->next != NULL) 
        sup = sup->next;

    sup->next = nn;
    nn->prev = sup;    

    self->len += 1;
    return 1;
}

// Can return NULL if index out of bounds
int64_t get(DoubleLinkedList *self, int16_t index) {
    if (index >= self->len)
        return NULL;
    
    Node *sup = self->start;
    while (index != 0) {
        sup = sup->next;
        index -= 1;
    }

    return sup->value;
}

// Can return NULL if index out of bounds
int set(DoubleLinkedList *self, int16_t index, int64_t value) {
    if (index >= self->len)
        return NULL;
    
    Node *sup = self->start;
    while (index != 0) {
        sup = sup->next;
        index -= 1;
    }

    sup->value = value;
    return 1;
}

// int64_t delete(DoubleLinkedList)