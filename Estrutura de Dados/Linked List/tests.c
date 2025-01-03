#include <stdio.h>
#include "./linkedList.c"

// Teste de criação
void test_1() {
    LinkedList lista = newLinkedList();
    if (lista.len != 0) {
        printf("Teste 1 - Erro ao criar a lista\n");
        return;
    }

    printf("Teste 1 - Ok\n");
}

// Teste de adição de elemento em lista vazia
void test_2() {
    LinkedList lista = newLinkedList();
    add(&lista, 10);
    int item = get(&lista, 0);
    if (item != 10) {
        printf("Teste 2 - Erro ao adicionar elemento em lista vazia\n");
        printf("          Elemento esperado: 10\n");
        printf("          Elemento recebido: %d\n", item);
        return;
    }

    if (lista.len != 1) {
        printf("Teste 2 - Erro ao alterar len\n");
        printf("          Elemento esperado: 1\n");
        printf("          Elemento recebido: %ld\n", lista.len);
        return;
    }

    printf("Teste 2 - Ok\n");
}

void test_3() {
    LinkedList lista = newLinkedList();
    add(&lista, 10);
    add(&lista, 20);
    add(&lista, 30);

    int item = get(&lista, 2);
    if (item != 30) {
        printf("Teste 3 - Erro ao adicionar elemento\n");
        printf("          Elemento esperado: 30\n");
        printf("          Elemento recebido: %d\n", item);
        return;
    }

    if (lista.len != 3) {
        printf("Teste 3 - Erro ao alterar len\n");
        printf("          Elemento esperado: 3\n");
        printf("          Elemento recebido: %ld\n", lista.len);
        return;
    }

    item = get(&lista, 99);
    if (item != 0) {
        printf("Teste 3 - Erro ao recuperar elemento out of bounds\n");
        printf("          Elemento esperado: 0\n");
        printf("          Elemento recebido: %d\n", item);
        return;
    }

    item = get(&lista, 1);
    if (item != 20) {
        printf("Teste 3 - Erro ao resgatar elemento\n");
        printf("          Elemento esperado: 20\n");
        printf("          Elemento recebido: %d\n", item);
        return;
    }

    printf("Teste 3 - Ok\n");
}

void test_4() {
    LinkedList lista = newLinkedList();
    int item = delete(&lista, 2);
    if (item != 0) {
        printf("Teste 4 - Erro ao remover elemento\n");
        printf("          Elemento esperado: 0\n");
        printf("          Elemento recebido: %d\n", item);
        return;
    }

    add(&lista, 10);
    item = delete(&lista, 0);
    if (item != 10) {
        printf("Teste 4 - Erro ao remover o primeiro elemento da lista de len 1\n");
        printf("          Elemento esperado: 10\n");
        printf("          Elemento recebido: %d\n", item);
        return;
    }

    if (lista.len != 0) {
        printf("Teste 4 - Erro ao alterar o len da lista\n");
        printf("          Elemento esperado: 0\n");
        printf("          Elemento recebido: %ld\n", lista.len);
        return;
    }

    add(&lista, 10);
    add(&lista, 20);
    add(&lista, 30);
    add(&lista, 40);
    add(&lista, 50);
    add(&lista, 60);
    add(&lista, 70);
    item = delete(&lista, 6);
    if (item != 70) {
        printf("Teste 4 - Erro ao remover o ultimo elemento da lista\n");
        printf("          Elemento esperado: 70\n");
        printf("          Elemento recebido: %d\n", item);
        return;
    }

    if (lista.len != 6) {
        printf("Teste 4 - Erro ao alterar o len da lista\n");
        printf("          Elemento esperado: 6\n");
        printf("          Elemento recebido: %ld\n", lista.len);
        return;
    }

    item = delete(&lista, 3);
    if (item != 40) {
        printf("Teste 4 - Erro ao remover uma elemento do meio da lista\n");
        printf("          Elemento esperado: 40\n");
        printf("          Elemento recebido: %d\n", item);
        return;
    }

    printf("Teste 4 - Ok\n");
}

void test_5() {
    LinkedList lista = newLinkedList();
    add(&lista, 10);
    add(&lista, 20);
    add(&lista, 30);
    add(&lista, 40);
    add(&lista, 50);
    add(&lista, 60);
    add(&lista, 70);
    printLista(&lista);
    delete(&lista, 0);
    delete(&lista, 0);
    delete(&lista, 0);
    delete(&lista, 0);
    printLista(&lista);
    delete(&lista, 0);
    delete(&lista, 0);
    printLista(&lista);
    delete(&lista, 0);
    printLista(&lista);
    delete(&lista, 0);
    printLista(&lista);
    add(&lista, 10);
    add(&lista, 20);
    add(&lista, 30);
    add(&lista, 40);
    add(&lista, 50);
    add(&lista, 60);
    add(&lista, 70);
    printLista(&lista);
}

int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    return 0;
}