#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    a^=b;
    b^=a;
    a^=b;
    cout<<"Swapped values: "<<a<<" "<<b<<endl;
}