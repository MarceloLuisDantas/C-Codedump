#include <stdlib.h>
#include <stdio.h>

struct Node {
    struct Node *prev;
    struct Node *next;
    int valor;
} typedef Node;

struct DoubleLinkedList {
    Node *start;
    Node *head;
    int len;
} typedef List;

Node *newNode(int valor) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Não foi possivel alocar memoria para Node");
        exit(1);
    }

    node->next = NULL;
    node->prev = NULL;
    node->valor = valor;
    return node;
}

List *newList() {
    List *list = (List *)malloc(sizeof(List));
    if (list == NULL) {
        printf("Não foi possivel alocar memoria para a Lista");
        exit(1);
    }

    list->start = NULL;
    list->head = NULL;
    list->len = 0;
    return list;
}

// Adiciona o elemento passado no final da lista
void addNode(List *lista, int valor) {
    Node *node = newNode(valor);

    // Caso o valor seja o primeiro da lista
    if (lista->len == 0) {
        lista->head = node;
        lista->start = node;
    } 

    // Caso o valor seja o segundo
    else if (lista->len == 1) {
        lista->start->next = node;
        node->prev = lista->start;
        lista->head = node;
    } 
    
    // Caso a lista já tenha 2 ou mais elementos
    else {
        node->prev = lista->head;
        lista->head->next = node;
        lista->head = node;
    }
    
    lista->len += 1;
    return;
}


/*  Insere um elemento no index especifico, os elementos são avançados em 1
 *  ex: 
 *  lista = [5] -> [1] -> [9] -> [0]
 *  insert(lista, 3, 2)
 *  lista = [5] -> [1] -> [3] -> [9] -> [0]
 *  Retorna 0 caso o index seja invalido, 1 caso a inserção de certo
 */ 
int insert(List *lista, int valor, int index) {
    if (index > lista->len || index < 0) {
        printf("Index out of bounds, len of %d\n", lista->len);
        return 0;
    }

    Node *node = newNode(valor);

    // Inserir a lista vazia no começo ou o final
    if (lista->len == 0 && index == 0) {
        lista->head = node;
        lista->start = node;
    }

    // Inserir no começo da lista
    else if (index == 0) {
        node->next = lista->start;
        lista->start->prev = node;
        lista->start = node;
    }

    // Inserir no final da lista
    else if (index == lista->len) {
        node->prev = lista->head;
        lista->head->next = node;
        lista->head = node;
    }

    // Inserir no meio da lista
    else {     
        Node *sup = lista->start;
        while (index > 0) {
            sup = sup->next;
            index -= 1;
        }
            
        node->prev = sup->prev;
        node->next = sup;
        sup->prev->next = node;
        sup->prev = node;
    }

    lista->len += 1;
    return 1;
}

/*  Retorna um index especifico da lista 
 *  Retorna 0 caso o index não seja valido 
 */
int get(List *lista, int index) {
    if (index >= lista->len || index < 0) {
        printf("Index out of bounds, len of %d\n", lista->len);
        return 0;
    }
    
    // Primeiro valor
    if (index == 0) 
        return lista->start->valor;

    // Ultimo valor
    if (index == lista->len - 1) 
        return lista->head->valor;

    Node *sup = lista->start;
    while (index > 0) {
        sup = sup->next;
        index -= 1;
    }

    return sup->valor;
}

// Remove o node do index especifico e retorna o valor do node removido
// Retorna 0 caso index out of bounds
int delete(List *lista, int index) {
    if (index >= lista->len || index < 0) {
        return 0;
    }

    // Lista so tem 1 item
    if (lista->len == 1) {
        int valor = lista->start->valor;
        free(lista->start);
        lista->start = NULL;
        lista->head = NULL;
        lista->len -= 1;
        return valor;
    }

    // Remover o primeiro elemento
    if (index == 0) {
        Node *sup = lista->start;
        int valor = sup->valor;

        lista->start = lista->start->next;
        lista->start->prev = NULL;
        
        free(sup);
        lista->len -= 1;
        return valor;
    } 

    // Remover o ultimo elemento
    if (index == lista->len - 1) {
        Node *sup = lista->head;
        int valor = sup->valor;
        lista->head = lista->head->prev;
        lista->head->next = NULL;
        free(sup);
        lista->len -= 1;
        return valor;
    }

    // Remover elemento no meio da lista
    Node *sup = lista->start;
    while (index > 0) {
        sup = sup->next;
        index -= 1;
    }
    int valor = sup->valor;
    sup->next->prev = sup->prev;
    sup->prev->next = sup->next;
    free(sup);

    lista->len -= 1;
    return valor;
}

// Retorna um array contendo os elementos da lista
int *toArray(List *lista) {
    int *array = (int *)malloc(lista->len * sizeof(int));
    if (lista->len == 0) 
        return array;
    
    Node *sup = lista->start;
    int count = 0;
    do {
        array[count] = sup->valor;
        sup = sup->next;
        count += 1;
    } while (sup->next != NULL);
    array[count] = sup->valor;

    return array;
}