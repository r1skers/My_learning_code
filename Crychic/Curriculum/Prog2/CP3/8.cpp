#include<iostream>
#include<bitset>
using namespace std;
int main(){
    unsigned int x=0b11010010;
    unsigned int reversed=0;
    for(int i=0;i<8;i++){
        reversed<<=1;
        reversed|=(x>>i)&1;
    }
    cout<<bitset<8>(reversed)<<endl;
}