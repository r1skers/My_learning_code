#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;

double f_sin(double x)
{
    return sin(x);
}

double f_quad(double x)
{
    return 3*x*x+2*x+1;
}
double integrated_trap(double (*f)(double), double a, double b, int n)
{
    if(n<=0||a==b)
    {
        return 0.0;
    }
    double h=(b-a)/n;
    double s=0.5*(f(a)+f(b));
    for(int i=1;i<n;++i)
    {
        s+=f(a+i*h);
    }
    return s*h;
}

int main(){
    cout<<integrated_trap(f_sin,0.0,M_PI/4.0,1000)<<endl;
    cout<<integrated_trap(f_quad,0.0,1.5,1000)<<endl;
}