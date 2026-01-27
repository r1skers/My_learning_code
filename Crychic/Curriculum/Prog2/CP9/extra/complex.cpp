#include"complex.h"
#include<iomanip>
#include<cmath>

void Complex::set(double re, double im)
{
    this->re = re;
    this->im = im;
}

void Complex::set_r_theta(double r ,double theta)
{
    set(r*cos(theta),r*sin(theta));
} 

    double Complex::abs()
    {
        return sqrt(re*re+im+im);
    }

    Complex Complex::operator+(const Complex& x)
    {
        Complex c;
        c.set(this->re + x.re, this->im + x.im);
        return c;
    }

    Complex Complex::operator+=(const Complex& x)
    {
        this->set(this->re +x.re, this->im +x.im);
        return (*this);
    }

    Complex Complex::operator-(const Complex& x)
    {
        Complex c;
        c.set(this->re -x.re,this->im - x.im);
        return(*this);
    }

    Complex Complex::operator-=(const Complex& x)
    {
        this->set(this->re-x.re,this->im-x.im);
        return (*this);
    }

    Complex Complex::operator*(const Complex& x)
    {
        Complex comp;
        double a = this->re;
        double b =this->im;
        double c = x.re;
        double d = x.im;
        comp.set(a*c-b*d, a*d+b*c);
        return comp;
    }

    Complex Complex::operator*=(const Complex& x)
    {
        (*this)=(*this)*x;
        return(*this);
    }

void Complex::print()
{
    cout << fixed<< setprecision(3)<<re<<"+i"<<im<<endl;
}

void Complex::print2()
{
    cout<<fixed<<setprecision(3)<<re<<"\t"<<im<<endl;

}