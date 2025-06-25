#ifndef NODE_H
#define NODE_H

#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int64_t value;
    struct Node *next;
    struct Node *prev;
} Node;

Node *newNode(int64_t value);

#endif