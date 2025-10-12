// --- tutorial_hardware.c ---

#include "tutorial_hardware.h"
#include <stdio.h>

/*
 * CONCEPT 7: VOLATILE KEYWORD
 * 概念7：VOLATILE 关键字
 *
 * Imagine this variable represents a hardware status register (e.g., a serial port's
 * "data ready" flag). Its value can be changed by the hardware at any moment,
 * completely outside of our program's control.
 * 想象一下，这个变量代表一个硬件状态寄存器（例如，一个串口的“数据就绪”标志）。它的值可以随时被硬件改变，
 * 完全超出我们程序的控制范围。
 *
 * `volatile` is a command to the compiler. It says:
 * `volatile` 是给编译器的一个命令。它说：
 * "The value of this variable can change unexpectedly. Therefore, you are FORBIDDEN
 *  from making any optimizations that assume its value is stable."
 * “这个变量的值可能会意外改变。因此，你被禁止进行任何假设其值稳定的优化。”
 *
 * This means the compiler must:
 * 这意味着编译器必须：
 * 1. Not cache the variable's value in a CPU register. Every access must be a
 *    fresh read from or write to main memory.
 *    不能将变量的值缓存在CPU寄存器中。每次访问都必须是从主内存中进行一次新的读取或写入。
 * 2. Not reorder accesses to this variable in relation to other volatile variables.
 *    不能相对于其他volatile变量重新排序对该变量的访问。
 */
volatile int mock_hardware_status = 0;

// This function simulates an external event (e.g., a button press or network packet arrival)
// 这个函数模拟一个外部事件（例如，按钮按下或网络数据包到达）
// In a real system, this would be an interrupt or a different thread.
// 在真实系统中，这可能是一个中断或一个不同的线程。
void simulate_external_event() {
    printf("    (Simulation: An external event occurs! Hardware status is now 1)\n");
    printf("    （模拟：一个外部事件发生！硬件状态现在变为1）\n");
    mock_hardware_status = 1;
}

void run_volatile_demo() {
    printf("Running Volatile Demo...\n");
    printf("  - Waiting for device (volatile status = %d)...
", mock_hardware_status);

    // Because `mock_hardware_status` is volatile, the compiler will generate code
    // to genuinely re-read its value from memory in every iteration of this loop.
    // 因为 `mock_hardware_status` 是 volatile 的，编译器将生成代码，在每次循环迭代中都真正地从内存中重新读取它的值。
    // If it were NOT volatile, an optimizing compiler might see that the loop body
    // doesn't change the value, assume it's always 0, and optimize this into an
    // infinite loop `while(0 == 0)`.
    // 如果它不是 volatile 的，一个优化的编译器可能会看到循环体没有改变这个值，就假设它总是0，
    // 然后把这个循环优化成一个无限循环 `while(0 == 0)`。
    while (mock_hardware_status == 0) {
        // In a real system, this loop might be empty, just polling the hardware.
        // 在真实系统中，这个循环可能为空，只是在轮询硬件。
        // For this demo, we will call our simulation function inside the loop
        // to guarantee the loop terminates.
        // 在这个演示中，我们将在循环内部调用我们的模拟函数，以保证循环能够终止。
        simulate_external_event();
    }

    printf("  - Device is ready! (volatile status = %d)\n", mock_hardware_status);
}
