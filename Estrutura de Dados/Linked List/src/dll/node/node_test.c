#include <stdio.h>
#include <stdint.h>
#include "node.h"

int main() {
    Node *node = newNode(10);
    if (node == NULL) {
        printf("Error trying to alloc the Node\n");
        return 1;
    }

    if (node->value != 10) {
        printf("Valor errado\n");
        return 1;
    }

    if (node->next != NULL) {
        printf("Proximo errado\n");
        return 1;
    }

    if (node->prev != NULL) {
        printf("Previo errado\n");
        return 1;
    }

    printf("Tudo OK\n");
    return 0;
}