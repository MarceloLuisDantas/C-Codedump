#include <stdlib.h>
#include <stdio.h>

typedef struct Complex {
    long double real;
    long double imaginary;    
} Complex;

Complex *new_complex(long double real, long double imaginary) {
    Complex *c = malloc(sizeof(Complex));
    c->real = real;
    c->imaginary = imaginary;
    return c;
}

typedef struct Field {
    Complex **field;
} Field;

int start_field(Field *f, size_t x, size_t y) {
    if (x % 2 != 0 || y % 2 != 0) {
        printf("The field needs even dimensions\n");
        return 0;
    }

    Field *f = malloc(sizeof(Field));
    f->field = malloc(sizeof(Complex*) * x);
    for (int i = 0; i < x; i++)
        f->field[i] = malloc(sizeof(Complex) * y);
    return 1;
}



Complex z(Complex z, Complex c) {

}

int main() {
    
}