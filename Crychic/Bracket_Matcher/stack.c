// =================================================================================
// stack.c - The Implementation of the Stack Data Structure
// =================================================================================
// This file provides the actual code for the functions declared in stack.h.
// It handles the "how" – the internal logic of the stack.

#include "stack.h" // We include our own header to get the declarations.

// --- Function Implementations ---

/**
 * @brief Creates a new stack with a given capacity.
 * @param capacity The maximum number of elements the stack can hold.
 * @return A pointer to the newly created Stack.
 */
Stack* createStack(unsigned capacity) {
    // 1. Allocate memory for the Stack structure itself.
    // sizeof(Stack) calculates the total bytes needed for the struct (top, capacity, array pointer).
    // malloc returns a void pointer, which we cast to (Stack*) to tell the compiler
    // that this memory will be used to store a Stack struct.
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) { // Always check if malloc failed (returned NULL)
        return NULL;
    }

    // 2. Initialize the properties of the stack.
    stack->capacity = capacity;
    stack->top = -1; // We initialize 'top' to -1 to indicate the stack is empty.

    // 3. Allocate memory for the array that will hold the stack's elements.
    // The size is the number of elements (capacity) multiplied by the size of each element (sizeof(int)).
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    if (!stack->array) { // Always check this malloc too
        free(stack); // If array allocation fails, we must free the stack struct to prevent a memory leak.
        return NULL;
    }

    // 4. Return the pointer to the fully initialized stack.
    return stack;
}

/**
 * @brief Checks if the stack is full.
 * @param stack A pointer to the stack.
 * @return 1 if full, 0 otherwise.
 */
int isFull(Stack* stack) {
    // The stack is full if the 'top' index is one less than the capacity.
    // For example, if capacity is 10, the valid indices are 0 through 9.
    // When top is 9, the stack is full.
    return stack->top == stack->capacity - 1;
}

/**
 * @brief Checks if the stack is empty.
 * @param stack A pointer to the stack.
 * @return 1 if empty, 0 otherwise.
 */
int isEmpty(Stack* stack) {
    // We initialized 'top' to -1, so if it's still -1, the stack is empty.
    return stack->top == -1;
}

/**
 * @brief Adds an item to the top of the stack.
 * @param stack A pointer to the stack.
 * @param item The integer item to add.
 */
void push(Stack* stack, int item) {
    // 1. Before adding, we must check if the stack is already full.
    if (isFull(stack)) {
        printf("Stack Overflow\n"); // Inform the user of the error.
        return; // And do nothing else.
    }
    // 2. If there's space, we first increment the 'top' index.
    // Then, we add the new item at the new 'top' position in the array.
    // The ++stack->top pre-increments top before it's used as an index.
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

/**
 * @brief Removes and returns the item from the top of the stack.
 * @param stack A pointer to the stack.
 * @return The popped item. Returns INT_MIN if the stack is empty.
 */
int pop(Stack* stack) {
    // 1. Before removing, we must check if the stack is empty.
    if (isEmpty(stack)) {
        printf("Stack Underflow\n"); // Inform the user of the error.
        return INT_MIN; // Return a special value to indicate an error.
    }
    // 2. If not empty, we return the item at the current 'top' index.
    // The stack->top-- post-decrements top after its value is used as an index.
    // This effectively "removes" the item by making it inaccessible.
    return stack->array[stack->top--];
}

/**
 * @brief Returns the item at the top of the stack without removing it.
 * @param stack A pointer to the stack.
 * @return The top item. Returns INT_MIN if the stack is empty.
 */
int peek(Stack* stack) {
    // 1. Check if the stack is empty.
    if (isEmpty(stack)) {
        return INT_MIN; // Return error value if empty.
    }
    // 2. If not empty, just return the item at the 'top' index without changing 'top'.
    return stack->array[stack->top];
}
