#ifndef STACK_H
#define STACK_H

#include <stdint.h>

typedef struct Stack {
    uint16_t *list;
    size_t max_size;
    size_t len;
} Stack;

Stack *newStack(size_t len);
uint16_t pop(Stack *s);
void push(Stack *s, uint16_t value);

#endif