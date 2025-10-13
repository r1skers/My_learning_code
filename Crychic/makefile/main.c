#include<stdio.h>
#include"power.h"
int main()
{
    double base;
    int exponent;
    printf("Enter base and exponent: ");
    scanf("%lf%d",&base,&exponent);
    printf("%g^%d=%g\n",base,exponent,power(base,exponent));
    return 0;
}
