#include <stdio.h>
#include "DoubleLinkedList.h"
#include "node/node.h"

int main() {
    DoubleLinkedList *list = newLinkedList();
    if (list == NULL) {
        printf("Error trying to alloc List\n");
        return 1;
    }

    if (list->len != 0) {
        printf("Len errado\n");
        return 1;
    }

    if (list->start != NULL) {
        printf("Start errado\n");
        return 1;
    }

    addNode(list, 10);
    addNode(list, 20);
    addNode(list, 30);
    addNode(list, 40);
    addNode(list, 50);
    addNode(list, 60);

    int count = 0;
    Node *sup = list->start;
    while (count < list->len) {
        printf("%ld -> ", sup->value);
        sup = sup->next;
        count += 1;
    }
    printf(" NULL\n");

    while (count >= 0) {
        printf("%ld <- ", sup->value);
        sup = sup->prev;
        count -= 1;
    }

    printf("Tudo ok\n");
    return 0;
}