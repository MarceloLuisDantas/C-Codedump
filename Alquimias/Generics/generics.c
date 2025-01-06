#include <stdio.h>

typedef enum Type {
    CHAR, INT, FLOAT
} Type;

void print_genrico(Type tipo, void *valor) {
    switch (tipo) {
    case INT:
        int *v = (int *)valor;
        printf("Valor do numerico: %d", v);
        break;
    
    default:
        break;
    }
}

int main() {
    int num = 10;

}

