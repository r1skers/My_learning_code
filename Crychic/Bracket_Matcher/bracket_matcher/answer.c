#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

// --- 1. ★★★ 新结构体：同时保存括号和它的位置 ★★★
typedef struct {
    char bracket;
    int index;
} BracketInfo;


// --- 2. ★★★ 栈结构升级 ★★★
typedef struct {
    int top;
    unsigned capacity;
    BracketInfo* array; // ★★★ 不再是 char*, 而是 BracketInfo*
} Stack;

// --- 3. 辅助函数 (括号定义) ---
// (这三个函数不需要改变)
bool is_opening_bracket(char c) {
    return c == '(' || c == '[' || c == '{';
}
bool is_closing_bracket(char c) {
    return c == ')' || c == ']' || c == '}';
}
bool is_matching_pair(char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '[' && close == ']') return true;
    if (open == '{' && close == '}') return true;
    return false;
}

// --- 4. ★★★ 栈操作函数升级 ★★★

Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) return NULL;
    stack->capacity = capacity;
    stack->top = -1; 
    // ★★★ 分配 BracketInfo 的空间 ★★★
    stack->array = (BracketInfo*)malloc(stack->capacity * sizeof(BracketInfo));
    if (!stack->array) {
        free(stack);
        return NULL;
    }
    return stack;
}

void freeStack(Stack* stack) {
    if (stack) {
        free(stack->array);
        free(stack);
    }
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

bool isFull(Stack* stack) {
    return stack->top == (int)stack->capacity - 1;
}

// ★★★ push 升级：现在需要同时传入 item 和 index ★★★
void push(Stack* stack, char item, int index) {
    if (isFull(stack)) {
        return;
    }
    stack->top++;
    stack->array[stack->top].bracket = item;
    stack->array[stack->top].index = index;
}

// ★★★ pop 升级：现在返回一个 BracketInfo 结构体 ★★★
BracketInfo pop(Stack* stack) {
    if (isEmpty(stack)) {
        BracketInfo empty = {'\0', -1}; // 返回一个"空"信息
        return empty;
    }
    // 返回栈顶的 BracketInfo，并 top--
    return stack->array[stack->top--]; 
}


// --- 5. ★★★ "员工"函数升级：接收 index ★★★
bool check_brackets(Stack* stack, char bracket, int index) 
{
    // --- 情况一：开括号 ---
    if (is_opening_bracket(bracket)) 
    {
        // ★★★ push 时带上 index ★★★
        push(stack, bracket, index);
        return true; 
    }
    // --- 情况二：闭括号 ---
    else if (is_closing_bracket(bracket)) 
    {
        // 2a. 检查栈是否为空
        if (isEmpty(stack)) 
        {
            // ★★★ 报错时使用 index ★★★
            printf("Error at index %d: Found closing bracket '%c' with no matching open bracket.\n", index, bracket);
            return false; 
        }
        
        // 2b. 弹出栈顶的 BracketInfo
        BracketInfo last_open = pop(stack);
        
        // 2c. 检查是否匹配
        if (is_matching_pair(last_open.bracket, bracket)) 
        {
            return true; // 匹配成功
        } 
        else 
        {
            // ★★★ 报错时使用两个 index，信息更详细！ ★★★
            printf("Error at index %d: Mismatch.\n", index);
            printf("    Found: '%c'\n", bracket);
            printf("    Expected match for: '%c' (which was at index %d)\n", last_open.bracket, last_open.index);
            return false; 
        }
    }
    
    // --- 情况三：非括号字符 ---
    return true; // 忽略，继续
}

// --- 6. ★★★ "主管"函数升级 ★★★
bool check_entire_string(char* input) 
{
    Stack* stack = createStack(strlen(input));
    if (!stack) {
        printf("Memory allocation failed!\n");
        return false;
    }

    for (int i = 0; input[i] != '\0'; i++) 
    {
        char c = input[i];
        
        // ★★★ 调用时传入 index 'i' ★★★
        bool result = check_brackets(stack, c, i);
        
        if (result == false) 
        {
            freeStack(stack); 
            return false;
        }
    }

    // --- ★★★ 遍历结束后的检查也升级了 ★★★
    if (isEmpty(stack)) 
    {
        printf("Success: All brackets are balanced.\n");
        freeStack(stack);
        return true; 
    } 
    else 
    {
        // 栈不为空，直接"查看"栈顶的元素 (不 pop)
        BracketInfo unclosed_bracket = stack->array[stack->top];
        
        // ★★★ 报错时使用栈中存的 index ★★★
        printf("Error: Reached end, but stack is not empty.\n");
        printf("    Unclosed bracket '%c' at index %d was left open.\n", unclosed_bracket.bracket, unclosed_bracket.index);
        
        freeStack(stack); 
        return false; 
    }
}


// --- 7. main 函数 (无需改动) ---
int main() {
    // 测试用例
    char code1[] = "int main() { int a = (1 + 2) * [3 - 4]; return 0; }";
    char code2[] = "void func(int a[);"; // 错误：] 丢失 (现在会报告 [ 的位置)
    char code3[] = "if (a > b) { a = b; )"; // 错误：) 多余 (现在会报告 ) 的位置)
    char code4[] = "while (a < [b + c]) { ... }"; // 错误：( 和 ] 错配 (现在会报告两个的位置)

    printf("--- Checking code1 ---\n%s\n", code1);
    check_entire_string(code1);
    printf("------------------------\n\n");

    printf("--- Checking code2 ---\n%s\n", code2);
    check_entire_string(code2);
    printf("------------------------\n\n");
    
    printf("--- Checking code3 ---\n%s\n", code3);
    check_entire_string(code3);
    printf("------------------------\n\n");

    printf("--- Checking code4 ---\n%s\n", code4);
    check_entire_string(code4);
    printf("------------------------\n\n");

    return 0;
}