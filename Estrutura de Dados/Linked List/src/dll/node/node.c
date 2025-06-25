#include <stdint.h>
#include <stdlib.h>

typedef struct {
    int64_t value;
    struct Node *next;
    struct Node *prev;
}Node;

// Can return NULL
Node *newNode(int64_t value) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL)
        return NULL;
    
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}