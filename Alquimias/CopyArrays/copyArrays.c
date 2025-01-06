#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
    int lista1[] = {1, 2, 3, 4, 5};
    int *lista2 = (int *)malloc(sizeof(int) * (5 * 1.5));
    memcpy(lista2, &lista1, sizeof(lista1));
    for (int i = 0; i < (5 * 1.5); i++) 
        printf("%d ", lista2[i]);
}