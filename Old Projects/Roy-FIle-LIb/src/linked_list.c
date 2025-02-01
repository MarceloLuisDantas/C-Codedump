#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef struct Node {
    struct Node *next;
    char *value;
} Node;

Node *newNode(char *value) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->next = NULL;
    n->value = (char *)malloc(sizeof(char) * (strlen(value) + 1));
    strcpy(n->value, value);
    return n;
}

typedef struct LinkedList {
    Node *start;
    uint32_t len;
} LinkedList;

LinkedList *newLinkedList() {
    LinkedList *l = (LinkedList *)malloc(sizeof(LinkedList));
    l->len = 0;
    l->start = NULL;
    return l;
}

void add(LinkedList *l, char *value) {
    Node *n = newNode(value);
    if (l->len == 0) {
        l->start = n;
    } else {
        Node *sup = l->start;
        while (sup->next != NULL) {
            sup = sup->next;
        }
        sup->next = n;
    }
    l->len += 1;
}

void insert(LinkedList *l, char *value, uint32_t index) {
    if (index >= l->len) {
        printf("Index out of bounds\n");
        return;
    }

    Node *n = newNode(value);
    if (index == 0) {
        n->next = l->start;
        l->start = n;
    } else {
        Node *sup = l->start;
        while (index > 1) {
            sup = sup->next;
            index -= 1;
        }
        n->next = sup->next;
        sup->next = n;
    }

    l->len += 1;
}

void set(LinkedList *l, char *value, uint32_t index) {
    if (index >= l->len) {
        printf("Index out of bounds\n");
        return;
    }
    
    Node *sup = l->start;
    while (index > 0) {
        sup = sup->next;
        index -= 1;
    }

    free(sup->value);
    sup->value = (char *)malloc(sizeof(char) * strlen(value) + 1);
    strcpy(sup->value, value);
}

void delete(LinkedList *l, uint32_t index) {
    if (index >= l->len) {
        printf("Index our of bounds\n");
        return;
    }

    if (index == 0) {
        if (l->len == 1) {
            free(l->start);
            l->start = NULL;
        } else {
            Node *sup= l->start;
            l->start = sup->next;
            free(sup);
        }
    } else {
        Node *sup= l->start;
        while (index > 1) {
            sup = sup->next;
            index -= 1;
        }
        Node *sup2 = sup->next;
        sup->next = sup->next->next;
        free(sup2);
    }

    l->len -= 1;
}

void applied(LinkedList *l, void (*map)(Node*)) {
    Node *sup = l->start;
    while (sup != NULL) {
        map(sup);
        sup = sup->next;
    }
}

char **toArray(LinkedList *l) {
    char **array = (char **)malloc(sizeof(char *) * l->len);

    Node *sup = l->start;
    int i = 0;
    while (sup != NULL) {
        array[i] = (char *)malloc(sizeof(char) * (strlen(sup->value) + 1));
        strcpy(array[i], sup->value);
        sup = sup->next;
        i += 1;
    }

    return array;
}