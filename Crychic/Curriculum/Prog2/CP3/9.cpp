#include<iostream>
using namespace std;
int main(){
    unsigned int n=0b10101010;
    for(int i=7;i>=0;i--){
        cout<<(((n>>i)&1)?'a':'b');
    }
}