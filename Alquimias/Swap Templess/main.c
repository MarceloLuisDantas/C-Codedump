/*  Objetivo:
    Comparar 2 funções que realizam a troca de duas posições de uma lista de Strings,
    uma utilizando o metodo padrão de criar uma variavel temporaria, e uma segunda
    utilizando xor.

    Motivação:
    São 3 da manha eu vi um shorts do ThePrimeage sobre, e eu pensei "com string isso
    funciona?".
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Não vale a pena usar isso com Strings com tamanhos diferentes
// E em todos os testes xor perdeu por muito comaprado a utilizar
// uma variavel temporaria no quesito tempo.
// Porem com o menor uso da heap e pipipi popopo.
void swapXor(char **lista, int i1, int i2) {
    for (int i = 0; i < strlen(lista[i1]); i++) {
        lista[i1][i] ^= lista[i2][i];
        lista[i2][i] ^= lista[i1][i];
        lista[i1][i] ^= lista[i2][i];
    }
}

// Sei que ta vazando memoria
void swapTemp(char **lista, int i1, int i2) {
    char *temp = malloc(sizeof(char) * strlen(lista[i1]) + 1);
    strcpy(temp, lista[i1]);
    free(lista[i1]);
    lista[i1] = lista[i2];
    lista[i2] = temp;
}


int main() {
    char **lista = malloc(sizeof(char *) * 4);
    lista[0] = malloc(sizeof(char) * sizeof("aaaaaa") + 1);
    strcpy(lista[0], "aaaaaa");
    lista[1] = malloc(sizeof(char) * sizeof("bbbbbb") + 1);
    strcpy(lista[1], "bbbbbb");
    lista[2] = malloc(sizeof(char) * sizeof("cccccc") + 1);
    strcpy(lista[2], "cccccc");
    lista[3] = malloc(sizeof(char) * sizeof("dddddd") + 1);
    strcpy(lista[3], "dddddd");

    int testes[] = {1000, 10000, 100000, 1000000};
    for (int i = 0; i < 4; i++) {
        clock_t begintemp = clock();
        for (int j = 0; j < testes[i]; j++)
            swapTemp(lista, 0, 2);
        clock_t endtemp = clock();
        double timetemp = (double)(endtemp - begintemp) / CLOCKS_PER_SEC;
        printf("To %d times, swapTemp takes %f\n", testes[i], timetemp);

        clock_t beginxor = clock();
        for (int j = 0; j < testes[i]; j++)
            swapXor(lista, 0, 2);
        clock_t endxor = clock();
        double timexor = (double)(endxor - beginxor) / CLOCKS_PER_SEC;
        printf("To %d times, swapXor takes %f\n", testes[i], timexor);

        if (timetemp > timexor) {
            printf("Temp perdeu com diferença de - %f\n", timetemp - timexor);
        } else {
            printf("Xor perdeu com diferença de - %f\n", timexor - timetemp);
        }

        printf("\n");
    }
    
    free(lista[0]);
    free(lista[1]);
    free(lista[2]);
    free(lista[3]);
    free(lista);
    return 0;
}