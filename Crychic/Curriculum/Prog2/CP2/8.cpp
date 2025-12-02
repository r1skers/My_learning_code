#include<iostream>
using namespace std;

void PrintFunc(int i);

int main(void){
    PrintFunc(3);
}

void PrintFunc(int i){
    cout<<"PrintFunc:"<<i<<endl;
    if(1<i)
    {
        PrintFunc(i-1);
    }
}
