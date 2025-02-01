#include <string.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *next;
    char *value;
} Node;

Node *newNode(char *value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

typedef struct LinkedList {
    Node *start;
    int len;
} LinkedList;

LinkedList *newLinkedList() {
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->len = 0;
    list->start = NULL;
    return list;
}

void add_next(Node *node, Node *nNode) {
    if (node->next == NULL)
        node->next = nNode;
    else 
        add_next(node->next, nNode);
}

void add(LinkedList *lista, char *value, int len) {
    if (len == 0)
        return;

    Node *node = newNode(value);
    if (lista->len == 0) 
        lista->start = node; 
    else 
        add_next(lista->start, node); 
    lista->len += 1;
}

char **toArray(LinkedList *lista) {
    char **linhas = (char **)malloc(sizeof(char *) * lista->len);
    Node *sup = lista->start;
    for (int i = 0; i < lista->len; i++) {
        linhas[i] = sup->value;
        sup = sup->next;
    }
    return linhas;
}