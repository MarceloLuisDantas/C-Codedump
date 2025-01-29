#include <stdint.h>
#include <stdlib.h>

typedef struct Stack {
    uint16_t *list;
    size_t max_size;
    size_t len;
} Stack;

Stack *newStack(size_t len) {
    Stack *nStack = (Stack *)malloc(sizeof(Stack));
    nStack->list = (uint16_t *)malloc(sizeof(uint16_t) * len);
    nStack->max_size = len;
    nStack->len = 0;
}

uint16_t pop(Stack *s) {
    if (s->len == 0)
        return 0;
    s->len -= 1;
    return s->list[s->len + 1];
}

void push(Stack *s, uint16_t value) {
    if (s->len == s->max_size)
        return;
    s->list[s->len] = value;
    s->len += 1;
}
