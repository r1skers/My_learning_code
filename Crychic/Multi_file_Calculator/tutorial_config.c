// --- tutorial_config.c ---

#include "tutorial_config.h"
#include <stdio.h>

// Definition of the `extern` variable declared in the .h file.
// 定义在 .h 文件中声明的 `extern` 变量。
// This is where the memory for the variable is actually allocated.
// 变量的内存实际上是在这里分配的。
const char* app_owner = "Riskerss";

/*
 * CONCEPT 4: STATIC (File Scope)
 * 概念4：STATIC (文件作用域)
 *
 * The `static` keyword, when used on a global variable or a function, limits its
 * visibility to the current file ONLY. It cannot be accessed from other files,
 * even with the `extern` keyword. This is extremely useful for creating "private"
 * helper functions or variables for a module, preventing namespace pollution.
 * 当 `static` 关键字用于全局变量或函数时，它将其可见性限制在当前文件中。这意味着它不能被其他文件访问，
 * 即使使用 `extern` 关键字也不行。这对于为一个模块创建“私有”的辅助函数或变量非常有用，可以防止污染全局命名空间。
 */

// This is a "private" variable for this module. It cannot be seen outside tutorial_config.c.
// 这是此模块的一个“私有”变量。在 tutorial_config.c 文件之外无法看到它。
static int module_init_count = 0;

// This is a "private" helper function. It cannot be called from tutorial_main.c.
// 这是一个“私有”的辅助函数。它不能从 tutorial_main.c 中调用。
static void print_log_level() {
    /*
     * CONCEPT 5: ADVANCED PREPROCESSING (#if, #elif, #else)
     * 概念5：高级预处理 (#if, #elif, #else)
     *
     * This is more powerful than `#ifdef`. It allows checking the actual VALUE of a macro.
     * 这比 `#ifdef` 更强大。它允许检查宏的实际值。
     * The Makefile can pass `-DLOG_LEVEL=2` to control this at compile time.
     * Makefile可以通过传递 `-DLOG_LEVEL=2` 在编译时控制它。
     */
    #if !defined(LOG_LEVEL) || LOG_LEVEL == 0
        printf("  - Log Level: [NONE]\n");
    #elif LOG_LEVEL == 1
        printf("  - Log Level: [ERROR]\n");
    #elif LOG_LEVEL == 2
        printf("  - Log Level: [INFO]\n");
    #elif LOG_LEVEL >= 3
        printf("  - Log Level: [DEBUG]\n");
    #else
        /*
         * CONCEPT 6: #error
         * 概念6：#error
         *
         * This directive will immediately stop the compilation and display an error message.
         * 这个指令会立即停止编译并显示一条错误信息。
         * It's useful for compile-time checks.
         * 它对于编译时检查很有用。
         */
        #error "Invalid LOG_LEVEL defined!"
    #endif
}


void run_config_demo() {
    printf("Running Configuration Demo...\n");

    module_init_count++;
    printf("  - This module has been initialized %d time(s).\n", module_init_count);

    // Demo for -D flag (conditional compilation)
    // -D 标志的演示（条件编译）
    #ifdef DEBUG
        printf("  - Build Mode: [DEBUG] (extra logs enabled)\n");
    #else
        printf("  - Build Mode: [RELEASE] (no extra logs)\n");
    #endif

    // Demo for -D flag with a value
    // 带值的 -D 标志的演示
    #ifdef VERSION
        printf("  - App Version: %s\n", VERSION);
    #else
        printf("  - App Version: Not specified\n");
    #endif

    // Demo for #if, #elif, #else
    // #if, #elif, #else 的演示
    print_log_level();
}
