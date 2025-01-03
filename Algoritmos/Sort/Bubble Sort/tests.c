#include <stdio.h>
#include "./bubbleSort.c"

#define TRUE 1
#define FALSE 0

int isEqual(int lista1[], int lista2[], int len1, int len2) {
    if (len1 != len2) 
        return 0;

    if (len1 == 1) 
        return lista1[0] == lista2[0];
    
    for(int i = 0; i < len1; i++)   
        if (lista1[i] != lista2[i])
            return 0;
    return 1;
}

void printLista(int lista[], int len) {
    printf("Lista: ");
    for (int i = 0; i < len; i++) 
        printf("%d ", lista[i]);
    printf("\n");
}

void test_1() {
    int lista[] = {1, 2, 3, 4};
    int ordenado = isEqual(lista, lista, 4, 4);
    if (ordenado)
        printf("Teste 1 - Ok, Ordenado\n");
}

void test_2() {
    int list[] = {4, 3, 2, 1};
    int ord[] = {1, 2, 3, 4};
    boubleSort((int *)&list, 4);
    int isOrd = isEqual(list, ord, 4, 4);
    if (isOrd) 
        printf("Teste 2 - Ok, Ordenado\n");
    else 
        printf("Teste 2 - Err\n");
    printLista(list, 4);
}

void test_3() {
    int list[] = {1, 2, 4, 3};
    int ord[] = {1, 2, 3, 4};
    boubleSort((int *)&list, 4);
    int isOrd = isEqual(list, ord, 4, 4);
    if (isOrd) 
        printf("Teste 3 - Ok, Ordenado\n");
    else 
        printf("Teste 3 - Err\n");
    printLista(list, 4);
}

void test_4() {
    int list[] = {2, 1};
    int ord[] = {1, 2};
    boubleSort((int *)&list, 2);
    int isOrd = isEqual(list, ord, 2, 2);
    if (isOrd) 
        printf("Teste 4 - Ok, Ordenado\n");
    else 
        printf("Teste 4 - Err\n");
    printLista(list, 2);
}

void test_5() {
    int list[] = {1};
    int ord[] = {1};
    boubleSort((int *)&list, 1);
    int isOrd = isEqual(list, ord, 1, 1);
    printf("%d", isOrd);
    if (isOrd) 
        printf("Teste 5 - Ok, Ordenado\n");
    else 
        printf("Teste 5 - Err\n");
    printLista(list, 1);
}

void test_6() {
    int list[] = {};
    int ord[] = {};
    boubleSort((int *)&list, 0);
    int isOrd = isEqual(list, ord, 0, 0);
    if (isOrd) 
        printf("Teste 6 - Ok, Ordenado\n");
    else 
        printf("Teste 6 - Err\n");
    printLista(list, 0);
}

int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    test_6();
    return 0;
}