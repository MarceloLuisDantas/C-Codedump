#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    struct Node *next;
    char *value;
} Node;

typedef struct LinkedList {
    Node *start;
    size_t len;
} LinkedList;

Node *newNode(char *value);
LinkedList *newLinkedList();

void add_next(Node *node, Node *nNode);
void add(LinkedList *lista, char *value, size_t len);
char **toArray(LinkedList *lista);

#endif