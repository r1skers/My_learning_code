#include<stdio.h>

int main()
{
    int sum=0;
    for(int i=1;i<=100;i++)
    {
        sum+=i;
        if(i==37)
        {
            printf("HIT");
            break;
        }       
    }
    printf("%d", sum);
    return 0;
}