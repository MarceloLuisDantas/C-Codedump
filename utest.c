// Funções simples que eu uso para fazer testes
#include <stdio.h>

void println(const char *msg) {
    printf("%s\n", msg);
}

void print_erro(const char *error, int esperado, int recebido) {
    printf("%s\n", error);
    printf("        Valor esperado: %d\n", esperado);
    printf("        Valor recebido: %d\n", recebido);   
}

void print_array_int(int *lista, int len) {
    for (int i = 0; i < len; i++) 
        printf("%d ", lista[i]);
}

// 1 = listas iguals
// 0 = listas diferentes
int compListas(int *lista1, int *lista2, int len) {
    for (int i = 0; i < len; i++) {
        int v1 = lista1[i];
        int v2 = lista2[i];
        // printf("Valor Lista 1 - %d\n", v1);
        // printf("Valor Lista 2 - %d\n", v2);
        if (v1 != v2) 
            return 0;
    }
        
    return 1;
}