#include<stdio.h>
#include"calculator.h"

int main()
{
    int a,b;
    char op;
    printf("Enter two numbers and an operator (+, -, *, /): ");
    scanf("%d %c %d", &a,&op,&b);
    
    switch(op) {
        case '+':
            printf("%d + %d = %d\n", a, b, add(a, b));
            break;
        case '-':
            printf("%d - %d = %d\n", a, b, sub(a, b));
            break;
        case '*':
            printf("%d * %d = %d\n", a, b, mul(a, b));
            break;
        case '/':
            if(b != 0) {
                printf("%d / %d = %.2f\n", a, b, div(a, b));
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
    }
    
    return 0;
}