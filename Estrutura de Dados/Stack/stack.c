#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int *lista;
    int len;
    int maxLen;
} typedef Stack;

// Cria uma stack vazia do tamanho passado
Stack newStack(int size) {
    Stack s;
    s.lista = (int *)malloc(size * sizeof(int));
    if (s.lista == NULL) {
        fprintf(stderr, "Error\n");
        exit(1);  
    }
    s.maxLen = size;
    s.len = 0;
    return s;
}

// Adiciona no topo da stack o valor passado
void push(Stack *s, int value) {
    if (s->len >= s->maxLen) {
        printf("Tamanho maximo atingindo, criando um novo array maior\n");
        int newSize = (int)(s->maxLen * 1.5);
        int *sup    = (int *)malloc(newSize * sizeof(int));
        for(int i = 0; i < s->maxLen; i++) 
            sup[i] = s->lista[i];
        free(s->lista);
        s->lista = sup;
        s->maxLen = newSize;
    }
    s->lista[s->len] = value;
    s->len += 1;
}


// Remove o valor no topo da stack
// Retorna 0 se a lista for vazia
int pop(Stack *s) {
    if (s->len <= 0) 
        return 0;
    
    int retorno = s->lista[s->len - 1];
    s->len -= 1;

    return retorno;
}

// Retorna um valor
// Retorna 0 se a lista for vazia 
int get(const Stack *s, int index) {
    if (index >= s->len) {
        printf("Indexe fora dos limites");
        return 0;
    }

    return s->lista[index];
}

void printStack(Stack *s) {
    for(int i = 0; i < s->len; i++) {
        printf("%dº Item - ", i + 1);
        printf("%d\n", s->lista[i]);
    }
}
