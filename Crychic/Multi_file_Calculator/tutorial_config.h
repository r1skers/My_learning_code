// --- tutorial_config.h ---

/*
 * CONCEPT 2: PRAGMA ONCE
 * 概念2：PRAGMA ONCE
 *
 * This is the modern, cleaner way to do header guards.
 * 这是更现代、更简洁的实现头文件保护的方法。
 * It is not part of the official C standard, but it is supported by virtually
 * every modern compiler (GCC, Clang, MSVC, etc.).
 * 它不是C语言官方标准的一部分，但几乎所有现代编译器（GCC, Clang, MSVC等）都支持它。
 *
 * How it works:
 * 工作原理：
 * The compiler itself keeps track of which files it has already included.
 * 编译器自己会记录它已经包含过的文件。
 * When it sees `#pragma once`, it marks this file as "included" and will ignore
 * any subsequent attempts to include it during the same compilation.
 * 当它看到 `#pragma once` 时，它会把这个文件标记为“已包含”，并在同一次编译中忽略任何后续的包含请求。
 *
 * PROS:
 * 优点：
 * - Simple and clean (1 line).
 *   简单清晰（只需1行）。
 * - No risk of macro name collisions.
 *   没有宏名称冲突的风险。
 * CONS:
 * 缺点：
 * - Technically non-standard, so it might not work on very old or obscure compilers.
 *   技术上非标准，所以可能在非常古老或小众的编译器上无法工作。
 *
 * For comparison, the traditional guard for this file would be:
 * 作为对比，这个文件的传统保护宏写法是：
 * #ifndef TUTORIAL_CONFIG_H
 * #define TUTORIAL_CONFIG_H
 * ... file content ...
 * #endif
 */
#pragma once

#include "tutorial_utils.h"

/*
 * CONCEPT 3: EXTERN KEYWORD
 * 概念3：EXTERN 关键字
 *
 * `extern` is used to DECLARE a global variable that is DEFINED in another file.
 * `extern` 用于声明一个在其他文件中定义的全局变量。
 * It tells the compiler: "This variable exists somewhere else. Don't allocate memory
 * for it here, but allow me to use it. The linker will find it later."
 * 它告诉编译器：“这个变量存在于别处。不要在这里为它分配内存，但允许我使用它。链接器稍后会找到它。”
 *
 * Here, we are declaring that a variable named `app_owner` exists. Its actual
 * definition and value are in `tutorial_config.c`.
 * 在这里，我们声明存在一个名为 `app_owner` 的变量。它实际的定义和值在 `tutorial_config.c` 中。
 * This makes the variable accessible to any file that includes this header.
 * 这使得这个变量对于任何包含此头文件的文件都是可访问的。
 */
extern const char* app_owner;


// Function declaration for the demo
// 用于演示的函数声明
void run_config_demo();
