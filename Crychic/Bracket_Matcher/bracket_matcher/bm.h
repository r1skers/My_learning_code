#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct 
{
    int top;
    unsigned capacity;
    char* array;
}Stack;

Stack* createStack(unsigned capacity);
void push(Stack* stack, char bracket);
bool check_brackets(Stack* stack,char bracket);
char pop(Stack* stack);
bool is_opening_bracket(char c);
bool is_closing_bracket(char c);
bool isEmpty(Stack* stack);
bool matching_brackets(char opening, char closing);
bool check_entire_stack(char* input);
#endif