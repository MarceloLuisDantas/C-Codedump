#include <stdio.h>
#include <stdlib.h>

int quadrado(int valor) { return valor * valor; }
int soma_2(int valor)   { return valor + 2; }

void map(int *lista, int len, int (*soma)(int)) {
    for (int i = 0; i < len; i++)
        lista[i] = soma(lista[i]);
}
 
int main() {
    int numeros[] = {1, 2, 3, 4, 5};
    print_array(numeros, 5); // 1 2 3 4 5

    map(numeros, 5, &quadrado);
    print_array(numeros, 5); // 1 4 9 16 25

    map(numeros, 5, &soma_2);
    print_array(numeros, 5); // 3 6 11 18 27 

    return 0;
}

void print_array(int *lista, int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", lista[i]);
    printf("\n");  
}