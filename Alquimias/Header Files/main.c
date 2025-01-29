#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main() {

    Stack *s = newStack(10);

    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);
    push(s, 10);

    for(int i = 0; i < s->len; i++)
        printf("%d\n", s->list[i]);

    return 0;
}