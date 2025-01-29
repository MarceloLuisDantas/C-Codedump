#include <stdio.h>
#include <stdint.h>
#include "teste.h"

int main() {
    uint16_t num1 = 10;
    uint16_t num2 = 20;
    uint16_t num3 = soma_numeros(num1, num2);
    printf("%d\n", num3);
}