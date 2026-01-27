#include<iostream>
#include"complex.h"
using namespace std;

int main(void)
{
    Complex c1,c2;
    c1.set(3.0,4.0);
    c2.set(2.0,-5.0);
    Complex c12 = c1+c2;
    c12.print();
    c12 = c1-c2;
    c12.print();
    c12 +=c1;
    c12.print();
    c12-=c1;
    c12.print();
}