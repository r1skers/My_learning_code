// =================================================================================
// main.c - Main program to test the Stack data structure
// =================================================================================

#include "stack.h" // Include our stack implementation

int main() {
    printf("--- Testing Stack Functionality ---\\n");
    
    // Create a stack of capacity 5
    Stack* stack = createStack(5);
    if (!stack) {
        printf("Failed to create stack.\\n");
        return 1; // Exit with an error code
    }

    printf("\\n--- Pushing items ---\\n");
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("\\n--- Peeking ---\\n");
    printf("Top item is %d\\n", peek(stack));

    printf("\\n--- Popping items ---\\n");
    printf("Popped %d\\n", pop(stack));
    printf("Popped %d\\n", pop(stack));

    printf("\\n--- Testing Stack Overflow ---\\n");
    push(stack, 40);
    push(stack, 50);
    push(stack, 60);
    push(stack, 70); // This should be the 5th item
    push(stack, 80); // This should cause a Stack Overflow

    printf("\\n--- Testing Stack Underflow ---\\n");
    // Pop all remaining items
    printf("Popped %d\\n", pop(stack));
    printf("Popped %d\\n", pop(stack));
    printf("Popped %d\\n", pop(stack));
    printf("Popped %d\\n", pop(stack));
    printf("Popped %d\\n", pop(stack)); // This should be the last valid item
    pop(stack); // This should cause a Stack Underflow

    // Final check to see if it's empty
    if (isEmpty(stack)) {
        printf("\\nStack is now empty.\\n");
    }

    // An important final step: free the allocated memory!
    free(stack->array);
    free(stack);
    
    printf("\\n--- Stack Test Complete ---\\n");

    return 0;
}
