#include <stdio.h>
#include "./stack.c"

void test_1() {
    Stack pilha = newStack(5);
    push(&pilha, 1);
    if (pilha.len != 1) {
        printf("Teste 1 - Err\n");
        return;
    }

    push(&pilha, 2);
    if (pilha.len != 2){
        printf("Teste 1 - Err\n");
        return;
    }
        
    push(&pilha, 3);
    push(&pilha, 4);
    push(&pilha, 5);
    if (pilha.len != 5){
        printf("Teste 1 - Err\n");
        return;
    }
        
    printf("Teste 1 - Ok\n");
}

void test_2() {
    Stack pilha = newStack(2);
    push(&pilha, 1);
    push(&pilha, 2);
    if (!(pilha.len == 2 && pilha.maxLen == 2)) {
        printf("Teste 2 - Erro, len ou maxLen diferente do esperado\n");
        return;
    }

    push(&pilha, 3);
    if (!(pilha.len == 3 && pilha.maxLen == 3)) {
        printf("Teste 2 - Erro ao almentar o tamanho da pilha\n");
        return;
    }

    push(&pilha, 4);
    if (!(pilha.len == 4 && pilha.maxLen == 4)) {
        printf("Teste 2 - Erro ao almentar o tamanho da pilha\n");
        return;
    }

    push(&pilha, 4);
    if (!(pilha.len == 5 && pilha.maxLen == 6)) {
        printf("Teste 2 - Erro ao almentar o tamanho da pilha\n");
        return;
    }
    
    printf("Teste 2 - Ok\n");
}

void test_3() {
    Stack pilha = newStack(10);
    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);
    push(&pilha, 4);
    push(&pilha, 5);
    push(&pilha, 6);
    push(&pilha, 7);
    push(&pilha, 8);
    push(&pilha, 9);
    push(&pilha, 10);
    if (pilha.len != 10) {
        printf("Teste 3 - Erro ao adicionar elementos\n");
        return;
    }

    int item = pop(&pilha);
    if (item != 10) {
        printf("Teste 3 - Erro ao tentar remover elemento\n");
        printf("          Elemento eseprado: 10\n");
        printf("          Elemento recebido: %d\n", item);
        return;
    }

    if (pilha.len != 9) {
        printf("Teste 3 - Erro ao alterar o valor de len\n");
        printf("          Valor eseprado: 9\n");
        printf("          Valor recebido: %d\n", pilha.len);
        return;
    }

    pop(&pilha);
    pop(&pilha);
    pop(&pilha);
    if (pilha.len != 6) {
        printf("Teste 3 - Erro ao alterar o valor de len\n");
        printf("          Valor eseprado: 6\n");
        printf("          Valor recebido: %d\n", pilha.len);
        return;
    }   

    printf("Teste 3 - Ok\n");
}

void test_4() {
    Stack pilha = newStack(10);
    int item = pop(&pilha);
    if (item != 0) {
        printf("Teste 4 - Erro ao realizar pop em lista vazia\n");
        return;
    }
    printf("Teste 4 - Ok\n");
}

void test_5() {
    Stack pilha = newStack(5);
    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);
    int valor = get(&pilha, 2);
    if (valor != 30) {
        printf("Teste 5 - Erro ao recuperar o indice 2\n");
        printf("          Valor eseprado: 30\n");
        printf("          Valor recebido: %d\n", valor);
        return;
    }

    push(&pilha, 40);
    push(&pilha, 50);
    push(&pilha, 60);
    push(&pilha, 70);
    push(&pilha, 80);
    push(&pilha, 90);
    push(&pilha, 100);
    push(&pilha, 110);
    push(&pilha, 120);
    push(&pilha, 130);
    push(&pilha, 140);
    push(&pilha, 150);
    valor = get(&pilha, 14);
    if (valor != 150) {
        printf("Teste 5 - Erro ao recuperar o indice 14\n");
        printf("          Valor eseprado: 30\n");
        printf("          Valor recebido: %d\n", valor);
        return;
    }

    printf("Teste 5 - Ok\n");
}

int main() {
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    return 0;
}