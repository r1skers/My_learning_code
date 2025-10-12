// --- tutorial_main.c ---
// 这是我们教程的主入口点。
// This is the main entry point for our tutorial.

#include <stdio.h>

// Include all the tutorial headers
// 包含所有的教程头文件
#include "tutorial_config.h"
#include "tutorial_hardware.h"
#include "tutorial_utils.h" // Included here as well to test include guards // 也在这里包含，用以测试头文件保护宏

// This function is defined in tutorial_utils.c, which we will add to the Makefile
// 这个函数在 tutorial_utils.c 中定义，我们会把它加到 Makefile 中
void print_separator_line() {
    printf("----------------------------------------\n");
}

int main() {
    printf("### C Language Advanced Concepts Tutorial ###\n");
    printf("### C语言高级概念教程 ###\n");

    // Accessing the `extern` global variable from tutorial_config.c
    // 访问来自 tutorial_config.c 的 `extern` 全局变量
    printf("This app is maintained by: %s\n", app_owner);

    print_separator_line();

    // Demo 1: Shows conditional compilation (-D), #pragma once, static, extern etc.
    // 演示1：展示条件编译 (-D), #pragma once, static, extern 等
    run_config_demo();

    print_separator_line();

    // Demo 2: Shows the effect of the 'volatile' keyword
    // 演示2：展示 'volatile' 关键字的效果
    run_volatile_demo();

    print_separator_line();

    printf("Tutorial finished.\n");
    printf("教程结束。\n");

    return 0;
}

// In a real project, this function's implementation would be in its own
// tutorial_utils.c file. For simplicity, we define it here so we don't need
// to create another file.
// 在真实项目中，这个函数的实现应该在它自己的 tutorial_utils.c 文件中。
// 为简单起见，我们在这里定义它，这样就不需要创建另一个文件了。

