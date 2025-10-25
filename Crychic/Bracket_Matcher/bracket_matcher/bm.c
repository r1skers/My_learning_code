#include"bm.h"

//1遍历字符串提取括号，2区分括号，3根据括号字符串长度创建栈，4遍历，正括号压入,反括号字符串检查是否对应括号，同时6，pop出对应正括号
Stack* createStack(unsigned capacity)
{
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(!stack)
    {
        return NULL;
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    if(!stack->array)
    {
        free(stack);
        return NULL;
    }
    return stack;
}

bool isEmpty(Stack* stack)
{
    return stack->top == -1;
}

void push(Stack* stack, char bracket)
{
    stack->array[++stack->top] = bracket;
}

char pop(Stack* stack)
{
    if(!isEmpty(stack))
    {
        return stack->array[stack->top--];
    }
    return '\0';
}
bool is_opening_bracket(char c)
{
    if(c == '{' || c == '[' || c == '(')
    {
        return true;
    }
    return false;
}

bool is_closing_bracket(char c)
{
    if(c == '}' || c == ']' || c == ')')
    {
        return true;
    }
    return false;
}

bool matching_brackets(char opening, char closing)
{
    if((opening == '{' && closing == '}') ||
       (opening == '[' && closing == ']') ||
       (opening == '(' && closing == ')'))
    {
        return true;
    }
    return false;
}

bool check_brackets(Stack* stack,char bracket)
{
    if(is_opening_bracket(bracket))
    {
        push(stack,bracket);
        return true;
    }
    else if(is_closing_bracket(bracket))
    {
        if(isEmpty(stack))
        {
            printf("Unmatched closing bracket %c found with empty stack\n",bracket);
            return false;
        }
        char top_bracket = pop(stack);
        if(!matching_brackets(top_bracket,bracket))
        {
            printf("Mismatched brackets: opened with %c but closed with %c\n",top_bracket,bracket);
            return false;
        }
    }
    return true;
}

bool check_entire_stack(char* input)
{
    Stack* stack = createStack(strlen(input));
    if(!stack)
    {
        printf("Stack creation failed\n");
        return false;
    }
    for(int i = 0; input[i] != '\0'; i++)
    {
        char current_char = input[i];
        bool result = check_brackets(stack,current_char);
        if(!result)
        {
            free(stack->array);
            free(stack);
            return false;
        }
    }
    if(isEmpty(stack))
    {
        printf("All brackets matched successfully\n");
        free(stack->array);
        free(stack);
        return true;
    }
    else
    {
        printf("Unmatched opening brackets remain in stack\n");
        free(stack->array);
        free(stack);
        return false;
    } 
}  