#include<stdio.h>
#include "bm.h"
int main(){
    char code1[] = "int main() { int a = (1 + 2) * [3 - 4]; return 0; }";
    printf("--- Checking code1 ---\n%s\n", code1);
    check_entire_stack(code1);
    printf("------------------------\n\n");

    char code2[] = "{[()]}";
    printf("--- Checking code2 ---\n%s\n", code2);
    check_entire_stack(code2);
    printf("------------------------\n\n");

    char code3[] = "{[(])}";
    printf("--- Checking code3 ---\n%s\n", code3);
    check_entire_stack(code3);
    printf("------------------------\n\n");

    char code4[] = "{";
    printf("--- Checking code4 ---\n%s\n", code4);
    check_entire_stack(code4);
    printf("------------------------\n\n");

    char code5[] = ")";
    printf("--- Checking code5 ---\n%s\n", code5);
    check_entire_stack(code5);
    printf("------------------------\n\n");
}