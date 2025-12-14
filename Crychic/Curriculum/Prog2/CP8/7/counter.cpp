#include"counter.h"

void counter::reset(unsigned val_max){
    val=0;
    this->val_max=val_max;
}

void counter::increment(){
    val=(val<val_max)? val+1 : 0;
}

void counter::decrement(){
    val=(val>0)? val-1 : val_max;
}

void counter::print(){
    cout<<val<<endl;
}

counter counter::operator++(){
    increment();
    return (*this);
}

counter counter::operator++(int dummy){
    counter buf=*this;
    increment();
    return buf;
}

counter counter::operator--(){
    decrement();
    return (*this);
}

counter counter::operator--(int dummy){
    counter buf=*this;
    decrement();
    return buf;
}

counter counter::operator+(const counter& x){
    counter cnt;
    cnt.reset(this->val_max);
    cnt.val=(this->val + x.val) % (this->val_max + 1);
    return cnt;
}

counter counter::operator+=(const counter& x){
    this->val=(this->val + x.val) % (this->val_max + 1);
    return (*this);
}