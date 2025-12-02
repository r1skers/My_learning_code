#include<iostream>
using namespace std;
int main()
{
    int x;
    int& y=x;

    y=12;
    cout<<"x="<<x<<endl;
    cout<<"y="<<y<<endl;
    return 0;
}