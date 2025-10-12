// --- tutorial_hardware.c ---

#include "tutorial_hardware.h"
#include <stdio.h>

/*
 * CONCEPT 7: VOLATILE KEYWORD
 *
 * Imagine this variable represents a hardware status register (e.g., a serial port's
 * "data ready" flag). Its value can be changed by the hardware at any moment,
 * completely outside of our program's control.
 *
 * `volatile` is a command to the compiler. It says:
 * "The value of this variable can change unexpectedly. Therefore, you are FORBIDDEN
 *  from making any optimizations that assume its value is stable."
 *
 * This means the compiler must:
 * 1. Not cache the variable's value in a CPU register. Every access must be a
 *    fresh read from or write to main memory.
 * 2. Not reorder accesses to this variable in relation to other volatile variables.
 */
volatile int mock_hardware_status = 0;

// This function simulates an external event (e.g., a button press or network packet arrival)
// In a real system, this would be an interrupt or a different thread.
void simulate_external_event() {
    printf("    (Simulation: An external event occurs! Hardware status is now 1)\n");
    mock_hardware_status = 1;
}

void run_volatile_demo() {
    printf("Running Volatile Demo...\n");
    printf("  - Waiting for device (volatile status = %d)...
", mock_hardware_status);

    // Because `mock_hardware_status` is volatile, the compiler will generate code
    // to genuinely re-read its value from memory in every iteration of this loop.
    // If it were NOT volatile, an optimizing compiler might see that the loop body
    // doesn't change the value, assume it's always 0, and optimize this into an
    // infinite loop `while(0 == 0)`.
    while (mock_hardware_status == 0) {
        // In a real system, this loop might be empty, just polling the hardware.
        // For this demo, we will call our simulation function inside the loop
        // to guarantee the loop terminates.
        simulate_external_event();
    }

    printf("  - Device is ready! (volatile status = %d)\n", mock_hardware_status);
}
