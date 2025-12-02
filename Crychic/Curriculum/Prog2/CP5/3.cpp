#include<iostream>
using namespace std;

void pswap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int x=10,y=20;
    pswap(&x,&y);
    cout<<x<<" "<<y<<endl;
    return 0;
}