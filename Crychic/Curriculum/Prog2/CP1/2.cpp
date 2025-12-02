#include<stdio.h>

int main()
{
    int sum=0;
    for(int i=1;i<=300;i++)
    {
        if(i%3==0)
        {
            sum+=i;
            if(i==180)
            {
                printf("HIT");
                break;
            }       
        }
       
    }
    printf("%d\n", sum);
    return 0;
}