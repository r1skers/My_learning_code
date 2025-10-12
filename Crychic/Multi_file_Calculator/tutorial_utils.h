// --- tutorial_utils.h ---

/*
 * CONCEPT 1: TRADITIONAL HEADER GUARDS (#ifndef)
 *
 * This is the classic, most portable way to prevent a header file from being
 * included multiple times in the same .c file.
 *
 * How it works:
 * 1. The first time this header is included, the macro `TUTORIAL_UTILS_H` is not defined.
 * 2. `#ifndef` succeeds, so the preprocessor continues.
 * 3. `#define TUTORIAL_UTILS_H` then defines the macro.
 * 4. The rest of the file is processed.
 * 5. The next time this header is included in the same compilation, `#ifndef TUTORIAL_UTILS_H`
 *    will fail because the macro is now defined, and the preprocessor skips the entire
 *    file content down to `#endif`.
 *
 * PROS:
 * - 100% portable. Works on every C/C++ compiler in existence.
 * CONS:
 * - Verbose (requires 3 lines).
 * - You must invent a unique macro name. If two headers have the same guard macro name
 *   by accident, it will cause one of them to be ignored, leading to very strange bugs.
 *
 * This directly contrasts with `#pragma once` (see tutorial_config.h).
 */
#ifndef TUTORIAL_UTILS_H
#define TUTORIAL_UTILS_H

#include <stdio.h> // For printf

// A simple utility function declaration
void print_separator_line();

#endif // TUTORIAL_UTILS_H
