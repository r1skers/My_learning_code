#ifndef COUNTER_H
#define COUNTER_H

#include<iostream>
using namespace std;

class counter
{
    private:
        unsigned val;
        unsigned val_max;
        
    public:
        void reset(unsigned val_max);
        void increment();
        counter operator++();
        counter operator++(int dummy);
        void decrement();
        counter operator--();
        counter operator--(int dummy);
        counter operator+(const counter& x);
        counter operator+=(const counter& x);
        void print();
};

#endif