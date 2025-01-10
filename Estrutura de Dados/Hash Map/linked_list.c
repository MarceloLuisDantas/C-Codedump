#include <stdlib.h>
#include <stdint.h>

typedef const char *string;

typedef struct Element {
    uint16_t valor;
    string key;
} Element;

Element *newElement(string key, uint16_t value) {
    Element *e = (Element *)malloc(sizeof(Element));
    
}

typedef struct Node {
    Element value;
    Node *next;
} Node;

Node *newNode(string key, uint16_t value) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->next = NULL;
    n->value = value;
    return n;
}

typedef struct LinkedList {
    Node *start;
    size_t len;
} LinkedList;

LinkedList *newLinkedList() {
    LinkedList *ll = (LinkedList *)malloc(sizeof(LinkedList));
    ll->start = NULL;
    ll->len = 0;
}

void add(LinkedList *lista, uint16_t value) {
    Node *node = newNode(value);
    if (lista->len = 0) {
        lista->start = node;
    } else {
        Node *sup = lista->start;
        while (sup->next != NULL) 
            sup = sup->next;
        sup->next = node;
    }
    lista->len += 1;
}

void remove(LinkedList *lista, size_t index) {
    if (index >= lista->len) 
        return;

    Node *sup = lista->start;
    if (index = 0) {
        lista->start = sup->next;
        free(sup);
    } else {
        while (index > 1) {
            sup = sup->next;
            index -= 1;
        }
        Node *sup2 = sup->next;
        sup->next = sup2->next;
        free(sup2);
    }
    lista->len -= 1;
}

int contains(LinkedList *lista, uint16_t value) {
    if (lista->len == 0) 
        return 0;
    
    Node *sup = lista->start;
    for (int i = 0; i < lista->len; i++) {
        if (sup->value == value) 
            return 1;
        sup = sup->next;
    }
    
    return 0;
}


