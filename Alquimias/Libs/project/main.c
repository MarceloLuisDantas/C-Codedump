#include "my_math.h"
#include <stdio.h>
#include <stdint.h>

int main() {
    int16_t x = soma_i16(20, 40);
    printf("20 + 40 = %i\n", x);

    float y = mult_f(6.12, 1.64);
    printf("6.12 * 1.64 = %f\n", y);
}