#ifndef STACK_H
#define STACK_H
#include <stddef.h>

typedef struct {
    char *data;
    int index;
    size_t capacity;
} Stack;


Stack* createStack(size_t capacity);
void push(Stack *s, char value);
char pop(Stack *s);
char top(Stack *s);
int isEmpty(Stack *s);
void eraseStack(Stack *s);

#endif