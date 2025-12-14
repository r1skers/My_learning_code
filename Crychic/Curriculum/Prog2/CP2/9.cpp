#include<iostream>
using namespace std;
int main(){
    int num=5;
    int *ptr;
    ptr=&num;
    cout<<"num="<<num<<",&num="<<&num<<endl;
    cout<<"ptr="<<*ptr<<",ptr="<<ptr<<endl;
    *ptr=10;
    cout<<"num="<<num<<",&num="<<&num<<endl;
    cout<<"ptr="<<*ptr<<",ptr="<<ptr<<endl;
    return 0;
}