#include<stdio.h>
int main()
{
    int AAA[10];
    int *ptr=AAA;
    *ptr=6;
    ptr=ptr+1;
    *ptr=7;
    printf("\r\noutput=%d\r\n",AAA[0]);
    return 0;

}