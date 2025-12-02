#include<stdio.h>

int x=100;
int main(void){
    printf("x=%d,::x=%d\n",x,::x);
    int x=200;
    {
        int x=300;
        printf("x=%d,::x=%d\n",x,::x);
    }
    printf("x=%d,::x=%d\n",x,::x);
    return 0;
}