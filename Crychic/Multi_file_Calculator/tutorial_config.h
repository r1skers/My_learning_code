// --- tutorial_config.h ---

/*
 * CONCEPT 2: PRAGMA ONCE
 *
 * This is the modern, cleaner way to do header guards.
 * It is not part of the official C standard, but it is supported by virtually
 * every modern compiler (GCC, Clang, MSVC, etc.).
 *
 * How it works:
 * The compiler itself keeps track of which files it has already included.
 * When it sees `#pragma once`, it marks this file as "included" and will ignore
 * any subsequent attempts to include it during the same compilation.
 *
 * PROS:
 * - Simple and clean (1 line).
 * - No risk of macro name collisions.
 * CONS:
 * - Technically non-standard, so it might not work on very old or obscure compilers.
 *
 * For comparison, the traditional guard for this file would be:
 * #ifndef TUTORIAL_CONFIG_H
 * #define TUTORIAL_CONFIG_H
 * ... file content ...
 * #endif
 */
#pragma once

#include "tutorial_utils.h"

/*
 * CONCEPT 3: EXTERN KEYWORD
 *
 * `extern` is used to DECLARE a global variable that is DEFINED in another file.
 * It tells the compiler: "This variable exists somewhere else. Don't allocate memory
 * for it here, but allow me to use it. The linker will find it later."
 *
 * Here, we are declaring that a variable named `app_owner` exists. Its actual
 * definition and value are in `tutorial_config.c`.
 * This makes the variable accessible to any file that includes this header.
 */
extern const char* app_owner;


// Function declaration for the demo
void run_config_demo();
