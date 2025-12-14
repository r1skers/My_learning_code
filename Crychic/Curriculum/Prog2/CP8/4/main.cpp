#include<iostream>
#include"counter.h"
using namespace std;

int main(void){
    counter cnt;
    cnt.reset(5);
    
    counter cnt1=cnt++;
    counter cnt2=++cnt;
    counter cnt3=cnt--;
    counter cnt4=--cnt;

    cnt1.print();
    cnt2.print();
    cnt3.print();
    cnt4.print();
}