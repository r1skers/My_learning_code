// --- tutorial_utils.h ---

/*
 * CONCEPT 1: TRADITIONAL HEADER GUARDS (#ifndef)
 * 概念1：传统的头文件保护宏 (#ifndef)
 *
 * This is the classic, most portable way to prevent a header file from being
 * included multiple times in the same .c file.
 * 这是最经典、最具移植性的方法，用来防止一个头文件在同一个.c文件中被多次包含。
 *
 * How it works:
 * 工作原理：
 * 1. The first time this header is included, the macro `TUTORIAL_UTILS_H` is not defined.
 *    第一次包含此头文件时，宏 `TUTORIAL_UTILS_H` 尚未被定义。
 * 2. `#ifndef` succeeds, so the preprocessor continues.
 *    `#ifndef` 条件成立，预处理器继续执行。
 * 3. `#define TUTORIAL_UTILS_H` then defines the macro.
 *    `#define TUTORIAL_UTILS_H` 接着定义了这个宏。
 * 4. The rest of the file is processed.
 *    文件的其余部分被正常处理。
 * 5. The next time this header is included in the same compilation, `#ifndef TUTORIAL_UTILS_H`
 *    will fail because the macro is now defined, and the preprocessor skips the entire
 *    file content down to `#endif`.
 *    在同一次编译中，当再次遇到此头文件的包含请求时，`#ifndef TUTORIAL_UTILS_H` 条件将失败，
 *    因为宏已经被定义，预处理器会跳过从这里到 `#endif` 之间的所有内容。
 *
 * PROS:
 * 优点：
 * - 100% portable. Works on every C/C++ compiler in existence.
 *   100%可移植。在现存的所有C/C++编译器上都能工作。
 * CONS:
 * 缺点：
 * - Verbose (requires 3 lines).
 *   代码冗长（需要3行）。
 * - You must invent a unique macro name. If two headers have the same guard macro name
 *   by accident, it will cause one of them to be ignored, leading to very strange bugs.
 *   你必须创造一个唯一的宏名称。如果两个不同的头文件意外使用了相同的宏名，会导致其中一个被忽略，
 *   从而引发非常奇怪的bug。
 *
 * This directly contrasts with `#pragma once` (see tutorial_config.h).
 * 这与 `#pragma once` 形成直接对比（详见 tutorial_config.h）。
 */
#ifndef TUTORIAL_UTILS_H
#define TUTORIAL_UTILS_H

#include <stdio.h> // For printf

// A simple utility function declaration
// 一个简单的工具函数声明
void print_separator_line();

#endif // TUTORIAL_UTILS_H
