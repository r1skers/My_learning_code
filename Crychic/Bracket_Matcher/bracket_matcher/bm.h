#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

extern char open_brackets[] = {'{','[','('};
typedef struct 
{
    int top;
    unsigned capacity;
    int* array;
}Stack;

char* filter(char* input);
Stack* createStack(unsigned capacity);
void push(Stack* stack, char bracket);
bool check_brackets(Stack* stack);
#endif // StA