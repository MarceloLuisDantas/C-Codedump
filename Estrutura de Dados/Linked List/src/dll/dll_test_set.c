#include <stdio.h>
#include "DoubleLinkedList.h"
#include "node/node.h"

int main() {
    DoubleLinkedList *list = newLinkedList();
    if (list == NULL) {
        printf("Error trying to alloc List\n");
        return 1;
    }


    int out_bounds1 = set(list, 0, 0);
    if (out_bounds1 != NULL) {
        printf("Out of bounds errado errado, esperado: NULL, recebido: %d\n", out_bounds1);
        return 1;
    }

    addNode(list, 10);
    addNode(list, 20);
    addNode(list, 30);

    int out_bounds2 = set(list, 4, 0);
    if (out_bounds2 != NULL) {
        printf("Out of bounds errado errado, esperado: NULL, recebido: %d\n", out_bounds2);
        return 1;
    }

    set(list, 0, 11);
    int64_t e1 = get(list, 0);
    if (e1 != 11) {
        printf("1º Index errado, esperado: 10, recebido: %d\n", e1);
        return 1;
    }

    set(list, 1, 22);
    int64_t e2 = get(list, 1);
    if (e2 != 22) {
        printf("1º Index errado, esperado: 20, recebido: %d\n", e2);
        return 1;
    }

    set(list, 2, 33);
    int64_t e3 = get(list, 2);
    if (e3 != 33) {
        printf("1º Index errado, esperado: 30, recebido: %d\n", e3);
        return 1;
    }

    printf("Tudo OK\n");
    return 0;
}