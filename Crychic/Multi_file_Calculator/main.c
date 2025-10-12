#include <stdio.h>
#include "calculator.h" // 包含我们自己的头文件，这样才能使用add, subtract等函数

int main() {
    int x = 20;
    int y = 10;

    printf("--- C Language Multi-File Project ---\n");
    printf("x = %d, y = %d\n\n", x, y);

    // 调用来自 calculator.c 的函数
    printf("Addition:       %d + %d = %d\n", x, y, add(x, y));
    printf("Subtraction:    %d - %d = %d\n", x, y, subtract(x, y));
    printf("Multiplication: %d * %d = %d\n", x, y, multiply(x, y));
    printf("Division:         %d / %d = %.2f\n", x, y, divide(x, y));

    printf("\n--- Trying division by zero ---\n");
    printf("Division by zero: %d / %d = %.2f\n", x, 0, divide(x, 0));

    return 0;
}
