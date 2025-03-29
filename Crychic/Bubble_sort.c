#include<stdio.h>
int main() {
    int a[5];
    printf("input 5 numbers: ");  // 输入提示不换行
    
    // 读取输入并验证
    for(int i=0; i<5; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Error: Invalid input!\n");
            return 1;
        }
    }
    
    // 冒泡排序（降序）
    for(int i=0; i<4; i++) {
        for(int j=0; j<4-i; j++) {
            if(a[j] < a[j+1]) { 
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    // 输出结果
    printf("\noutput: ");  // 换行后输出
    for(int i=0; i<5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}