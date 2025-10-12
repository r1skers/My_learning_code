// --- tutorial_config.c ---

#include "tutorial_config.h"
#include <stdio.h>

// Definition of the `extern` variable declared in the .h file.
// This is where the memory for the variable is actually allocated.
const char* app_owner = "Riskerss";

/*
 * CONCEPT 4: STATIC (File Scope)
 *
 * The `static` keyword, when used on a global variable or a function, limits its
 * visibility to the current file ONLY. It cannot be accessed from other files,
 * even with the `extern` keyword. This is extremely useful for creating "private"
 * helper functions or variables for a module, preventing namespace pollution.
 */

// This is a "private" variable for this module. It cannot be seen outside tutorial_config.c.
static int module_init_count = 0;

// This is a "private" helper function. It cannot be called from tutorial_main.c.
static void print_log_level() {
    /*
     * CONCEPT 5: ADVANCED PREPROCESSING (#if, #elif, #else)
     *
     * This is more powerful than `#ifdef`. It allows checking the actual VALUE of a macro.
     * The Makefile can pass `-DLOG_LEVEL=2` to control this at compile time.
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
         * This directive will immediately stop the compilation and display an error message.
         * It's useful for compile-time checks.
         */
        #error "Invalid LOG_LEVEL defined!"
    #endif
}


void run_config_demo() {
    printf("Running Configuration Demo...\n");

    module_init_count++;
    printf("  - This module has been initialized %d time(s).\n", module_init_count);

    // Demo for -D flag (conditional compilation)
    #ifdef DEBUG
        printf("  - Build Mode: [DEBUG] (extra logs enabled)\n");
    #else
        printf("  - Build Mode: [RELEASE] (no extra logs)\n");
    #endif

    // Demo for -D flag with a value
    #ifdef VERSION
        printf("  - App Version: %s\n", VERSION);
    #else
        printf("  - App Version: Not specified\n");
    #endif

    // Demo for #if, #elif, #else
    print_log_level();
}
