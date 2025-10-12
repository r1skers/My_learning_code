#include "calculator.h"
#include <stdio.h> // 引入标准输入输出库，用于在除法函数中打印错误信息

// 加法实现
int add(int a, int b) {
    return a + b;
}

// 减法实现
int subtract(int a, int b) {
    return a - b;
}

// 乘法实现
int multiply(int a, int b) {
    return a * b;
}

// 除法实现
float divide(int a, int b) {
    // 检查除数是否为0，避免程序崩溃
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0.0f; // 返回一个0.0作为错误指示
    }
    // 将其中一个整数强制转换为浮点数，以执行浮点除法
    return (float)a / b;
}
