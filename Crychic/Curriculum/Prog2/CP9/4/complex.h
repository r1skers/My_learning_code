#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;

class Complex {
    public:
        double re,im;
        void set(double re, double im);
        void set_r_theta(double r, double theta);
        double abs();
        Complex operator+(const Complex &x);
        Complex operator+=(const Complex &x);
        Complex operator-(const Complex &x);
        Complex operator-=(const Complex &x);
        Complex operator*(const Complex &x);
        Complex operator*=(const Complex &x);
        Complex operator/(const Complex &x);
        Complex operator/=(const Complex &x);
        void print();
        void print2();
};

#endif