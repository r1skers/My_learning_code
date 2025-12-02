#ifndef COUNTER_H
#define COUNTER_H

#include<iostream>
using namespace std;

class counter{
    public:
        unsigned val;
        unsigned val_max;

        void reset(unsigned val_max);
        void increment();
        counter operator++();
        counter operator++(int dummy);
        void decrement();
        counter operator--();
        counter operator--(int dummy);
        void print();
};

#endif