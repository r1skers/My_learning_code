#include<stdio.h>
int main() {
    int a[5];
    printf("input 5 numbers: ");  // ������ʾ������
    
    // ��ȡ���벢��֤
    for(int i=0; i<5; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Error: Invalid input!\n");
            return 1;
        }
    }
    
    // ð�����򣨽���
    for(int i=0; i<4; i++) {
        for(int j=0; j<4-i; j++) {
            if(a[j] < a[j+1]) { 
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    
    // ������
    printf("\noutput: ");  // ���к����
    for(int i=0; i<5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}