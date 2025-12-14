#include<stdio.h>

void display(int x,int y=0,int z=0)
{
    printf("%d %d %d\n",x,y,z);
}

int main(void){
    display(1);
    display(1,2);
    display(1,2,3);
}