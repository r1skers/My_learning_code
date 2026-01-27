#include<iostream>
#include "complex.h"
using namespace std;

const double PI=3.14159265359;
int main()
{
    Complex c1;
    c1.set(3.0,4.0);

    for(int i=0;i<20;i++)
    {
        Complex c2;
        c2.set_r_theta(1.0,((double)i/20.0)*PI);
        Complex c12=c1*c2;
        c12.print2();
    }
}