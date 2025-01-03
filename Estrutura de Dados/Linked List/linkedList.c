#include <stdlib.h>
#include <stdio.h>

struct Node {
    struct Node *next;
    int  value; 
} typedef Node;

struct LinkedList {
    Node *start;
    size_t  len;
} typedef LinkedList;

Node *newNode(int valor) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = valor;
    node->next = NULL;
    return node;
}

LinkedList newLinkedList() {
    LinkedList lista = {NULL, 0};
    return lista;
}

void add(LinkedList *lista, int valor) {
    Node *node = newNode(valor);
    if (lista->start == NULL) {
        lista->start = node;
        lista->len += 1;
        return;
    } 
    
    Node *ponto = lista->start;
    while (ponto->next != NULL) 
        ponto = ponto->next;
    ponto->next = node;
    lista->len += 1;
}

int delete(LinkedList *lista, int index) {
    if (lista->len == 0) {
        printf("Lista vazia\n");
        return 0;
    }
    
    if (index >= lista->len) {
        printf("Index out of bounds, max index of %ld\n", lista->len);
        return 0;
    }

    if (index == 0) {
        int valor = lista->start->value;
        if (lista->len >= 2) {
            lista->start = lista->start->next;
        } else {
            free(lista->start);
            lista->start = NULL;
        }
        lista->len -= 1;
        return valor;
    }

    Node *pivot = lista->start;
    while (index != 1) {
        pivot = pivot->next;
        index -= 1;
    }

    int valor = pivot->next->value;
    // Proximo elemento é o ultimo da lista
    if (pivot->next->next == NULL) {
        free(pivot->next);
        pivot->next = NULL;
    } else { // Apos o proximo elemento ainda á elementos 
        Node *newNext = pivot->next->next;
        free(pivot->next);
        pivot->next = newNext;
    }

    lista->len -= 1;
    return valor;
}

int get(const LinkedList *lista, int index) {
    if (index >= lista->len) {
        printf("Index fora de alcace, limite %ld\n", lista->len);
        return 0;
    }

    if (lista->start == NULL) {
        printf("Lista vazia\n");
        return 0;
    }

    Node *node = lista->start;
    while (index != 0) {
        node = node->next;
        index -= 1;
    }

    return node->value;
}

void printLista(const LinkedList *lista) {
    printf("Tamanho da lista: %ld\n", lista->len);
    if (lista->len == 0) {
        printf("Lista vazia\n");
    } else {
        printf("Lista: ");
        for (int i = 0; i < lista->len; i++) {
            printf("%d ", get(lista, i));
        }
        printf("\n");
    }
}