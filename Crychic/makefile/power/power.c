#include"power.h"
double power(double base,int exponent)
{
    double result=1.0;
    for(int i=0;i<exponent;i++)
        result*=base;
    return result;
}