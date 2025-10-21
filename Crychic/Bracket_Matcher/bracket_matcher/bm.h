#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

extern char open_brackets[] = {'{','[','('};
typedef struct 
{
    int top;
    unsigned capacity;
    int* array;
};

char* filter(char* input);
#endif // StA