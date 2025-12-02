#include<iostream>
using namespace std;
int square(int x)
{
    return x*x;
}
int cube(int x)
{
    return x*x*x;
}
int pow4(int x)
{
    return x*x*x*x;
}
void transform(int *a,int n,int (*f)(int))
{
    for(int i=0;i<n;++i)
    {
        a[i]=f(a[i]);
    }
}

int main(){
    int a[]={1,2,3,4};
    transform(a,4,square);
    cout<<"square:";
    for(int v : a)
    {
        cout<<v<<' ';
    }
    cout<<endl;

    int b[]={1,2,3,4};
    transform(b,4,cube);
    cout<<"cube:";
    for(int v : b)
    {
        cout<<v<<' ';
    }
    cout<<endl;
    int c[]={1,2,3,4};
    transform(c,4,pow4);
    cout<<"4th power:";
    for(int v : c)
    {
        cout<<v<<' ';
    }
    cout<<endl;
}