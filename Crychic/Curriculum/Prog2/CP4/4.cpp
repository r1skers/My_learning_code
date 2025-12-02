#include<iostream>
using namespace std;
int main()
{
    int a=5;
    int*ptr=new int;
    *ptr=3;
    int sum=a+*ptr;
    cout<<sum<<endl;
    delete ptr;
    return 0;
}