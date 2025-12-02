#include<iostream>
#include"counter.h"
using namespace std;

int main(void){
    counter cnt1;
    cnt1.reset(5);
    cnt1++;
    cnt1++;
    cnt1++;
    cnt1++;
    cnt1.print();

    counter cnt2;
    cnt2.reset(5);
    cnt2++;
    cnt2++;
    cnt2++;
    cnt2.print();

    counter sum=cnt1+cnt2;
    sum.print();
    sum+=cnt1;
    sum.print();
}