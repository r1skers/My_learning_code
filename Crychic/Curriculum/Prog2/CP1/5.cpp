#include<stdio.h>

int main()
{
    int sum=0;
    for(int i=1;i<=100000;++i)
    {
        sum+=i;
        if(sum>10000)
        {
            printf("%d\n", i);
            break;
        }
    }
    
    return 0;
}