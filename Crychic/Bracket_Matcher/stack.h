// =================================================================================
// stack.h - The Interface for a Simple Stack Data Structure
// =================================================================================
// This header file defines the "contract" for our stack. Any other C file that
// includes this header will know what a "Stack" is and which functions are
// available to create, modify, and use it.

// --- Header Guard ---
// This is a standard C practice to prevent the file from being included multiple
// times in the same compilation, which would cause errors. We discussed this
// during our Week 9 lesson.
#ifndef STACK_H
#define STACK_H

// --- Dependencies ---
// We need these standard libraries for certain features:
#include <stdio.h>  // For printf (useful for debugging)
#include <stdlib.h> // For malloc (to allocate memory for the stack)
#include <limits.h> // For INT_MIN (a very small number to return on error)

// --- Data Structure Definition ---
// This struct defines what a "Stack" is. It's a collection of data containing:
// 1. top: An integer that tracks the index of the top element in the stack.
// 2. capacity: The maximum number of elements the stack can hold.
// 3. array: A pointer to an integer array, which will store the elements.
typedef struct {
    int top;
    unsigned capacity;
    int* array;
} Stack;

// --- Function Declarations (The "Public" API) ---
// These are the functions that users of our stack can call.

/**
 * @brief Creates a new stack with a given capacity.
 * @param capacity The maximum number of elements the stack can hold.
 * @return A pointer to the newly created Stack.
 */
Stack* createStack(unsigned capacity);

/**
 * @brief Checks if the stack is full.
 * @param stack A pointer to the stack.
 * @return 1 if full, 0 otherwise.
 */
int isFull(Stack* stack);

/**
 * @brief Checks if the stack is empty.
 * @param stack A pointer to the stack.
 * @return 1 if empty, 0 otherwise.
 */
int isEmpty(Stack* stack);

/**
 * @brief Adds an item to the top of the stack.
 * @param stack A pointer to the stack.
 * @param item The integer item to add.
 */
void push(Stack* stack, int item);

/**
 * @brief Removes and returns the item from the top of the stack.
 * @param stack A pointer to the stack.
 * @return The popped item. Returns INT_MIN if the stack is empty.
 */
int pop(Stack* stack);

/**
 * @brief Returns the item at the top of the stack without removing it.
 * @param stack A pointer to the stack.
 * @return The top item. Returns INT_MIN if the stack is empty.
 */
int peek(Stack* stack);

#endif // STACK_H
