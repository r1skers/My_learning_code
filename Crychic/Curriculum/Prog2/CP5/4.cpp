#include<iostream>
using namespace std;

int& ref(void){
    static int x;
    return x;
}
int main()
{
    ref()=5;
    cout<<"ref()="<<ref()<<endl;
    return 0;
}