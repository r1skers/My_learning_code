// --- tutorial_main.c ---
// This is the main entry point for our tutorial.

#include <stdio.h>

// Include all the tutorial headers
#include "tutorial_config.h"
#include "tutorial_hardware.h"
#include "tutorial_utils.h" // Included here as well to test include guards

// This function is defined in tutorial_utils.c, which we will add to the Makefile
void print_separator_line() {
    printf("----------------------------------------\n");
}

int main() {
    printf("### C Language Advanced Concepts Tutorial ###\n");

    // Accessing the `extern` global variable from tutorial_config.c
    printf("This app is maintained by: %s\n", app_owner);

    print_separator_line();

    // Demo 1: Shows conditional compilation (-D), #pragma once, static, extern etc.
    run_config_demo();

    print_separator_line();

    // Demo 2: Shows the effect of the 'volatile' keyword
    run_volatile_demo();

    print_separator_line();

    printf("Tutorial finished.\n");

    return 0;
}

// In a real project, this function's implementation would be in its own
// tutorial_utils.c file. For simplicity, we define it here so we don't need
// to create another file.

