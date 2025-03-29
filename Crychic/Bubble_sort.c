//输入五个数字，冒泡排序
#include<stdio.h>
int main() {
    int a[5];
    printf("输入5个数字: ");
    for(int i=0; i<5; i++) {
        scanf("%d", &a[i]);
    }
    
    // 冒泡排序
    for(int i=0; i<4; i++) {
        for(int j=0; j<4-i; j++) {
            if(a[j] < a[j+1]) { // 降序排序
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    // 输出结果
    printf("排序结果: ");
    for(int i=0; i<5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}